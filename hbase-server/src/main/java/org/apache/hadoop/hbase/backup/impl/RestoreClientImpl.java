/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.apache.hadoop.hbase.backup.impl;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.TreeSet;

import org.apache.commons.lang.StringUtils;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.hbase.TableName;
import org.apache.hadoop.hbase.backup.BackupType;
import org.apache.hadoop.hbase.backup.HBackupFileSystem;
import org.apache.hadoop.hbase.backup.RestoreClient;
import org.apache.hadoop.hbase.backup.impl.BackupManifest.BackupImage;
import org.apache.hadoop.hbase.backup.mapreduce.MapReduceRestoreService;
import org.apache.hadoop.hbase.backup.util.BackupClientUtil;
import org.apache.hadoop.hbase.backup.util.RestoreServerUtil;
import org.apache.hadoop.hbase.classification.InterfaceAudience;
import org.apache.hadoop.hbase.classification.InterfaceStability;
import org.apache.hadoop.hbase.client.Admin;
import org.apache.hadoop.hbase.client.Connection;
import org.apache.hadoop.hbase.client.ConnectionFactory;
import org.apache.hadoop.hbase.mapreduce.LoadIncrementalHFiles;
import org.apache.hadoop.hbase.mapreduce.LoadIncrementalHFiles.LoadQueueItem;

/**
 * The main class which interprets the given arguments and trigger restore operation.
 */
@InterfaceAudience.Public
@InterfaceStability.Evolving
public final class RestoreClientImpl implements RestoreClient {

  private static final Log LOG = LogFactory.getLog(RestoreClientImpl.class);
  private Configuration conf;
  private String fullBackupId;

  public RestoreClientImpl() {
  }

  @Override
  public void setConf(Configuration conf) {
    this.conf = conf;
  }



  /**
   * Restore operation. Stage 1: validate backupManifest, and check target tables
   * @param backupRootDir The root dir for backup image
   * @param backupId The backup id for image to be restored
   * @param check True if only do dependency check
   * @param sTableArray The array of tables to be restored
   * @param tTableArray The array of mapping tables to restore to
   * @param isOverwrite True then do restore overwrite if target table exists, otherwise fail the
   *          request if target table exists
   * @throws IOException if any failure during restore
   */
  @Override
  public void restore(String backupRootDir,
      String backupId, boolean check, TableName[] sTableArray,
      TableName[] tTableArray, boolean isOverwrite) throws IOException {

    HashMap<TableName, BackupManifest> backupManifestMap = new HashMap<>();
    // check and load backup image manifest for the tables
    Path rootPath = new Path(backupRootDir);
    HBackupFileSystem.checkImageManifestExist(backupManifestMap, sTableArray, conf, rootPath,
      backupId);
    try {
      // Check and validate the backup image and its dependencies
      if (check) {
        if (validate(backupManifestMap)) {
          LOG.info("Checking backup images: ok");
        } else {
          String errMsg = "Some dependencies are missing for restore";
          LOG.error(errMsg);
          throw new IOException(errMsg);
        }
      }

      if (tTableArray == null) {
        tTableArray = sTableArray;
      }
      // check the target tables
      checkTargetTables(tTableArray, isOverwrite);
      // start restore process
      restoreStage(backupId, backupManifestMap, sTableArray, tTableArray, isOverwrite);
      LOG.info("Restore for " + Arrays.asList(sTableArray) + " are successful!");
    } catch (IOException e) {
      LOG.error("ERROR: restore failed with error: " + e.getMessage());
      throw e;
    }

  }

  private  boolean validate(HashMap<TableName, BackupManifest> backupManifestMap)
      throws IOException {
    boolean isValid = true;

    for (Entry<TableName, BackupManifest> manifestEntry : backupManifestMap.entrySet()) {
      TableName table = manifestEntry.getKey();
      TreeSet<BackupImage> imageSet = new TreeSet<BackupImage>();

      ArrayList<BackupImage> depList = manifestEntry.getValue().getDependentListByTable(table);
      if (depList != null && !depList.isEmpty()) {
        imageSet.addAll(depList);
      }

      LOG.info("Dependent image(s) from old to new:");
      for (BackupImage image : imageSet) {
        String imageDir =
            HBackupFileSystem.getTableBackupDir(image.getRootDir(), image.getBackupId(), table);
        if (!BackupClientUtil.checkPathExist(imageDir, conf)) {
          LOG.error("ERROR: backup image does not exist: " + imageDir);
          isValid = false;
          break;
        }
        // TODO More validation?
        LOG.info("Backup image: " + image.getBackupId() + " for '" + table + "' is available");
      }
    }

    return isValid;
  }

  /**
   * Validate target Tables
   * @param tTableArray: target tables
   * @param isOverwrite overwrite existing table
   * @throws IOException exception
   */
  private  void checkTargetTables(TableName[] tTableArray, boolean isOverwrite)
      throws IOException {
    ArrayList<TableName> existTableList = new ArrayList<>();
    ArrayList<TableName> disabledTableList = new ArrayList<>();

    // check if the tables already exist
    try(Connection conn = ConnectionFactory.createConnection(conf);
        Admin admin = conn.getAdmin()) {
      for (TableName tableName : tTableArray) {
        if (admin.tableExists(tableName)) {
          existTableList.add(tableName);
          if (admin.isTableDisabled(tableName)) {
            disabledTableList.add(tableName);
          }
        } else {
          LOG.info("HBase table " + tableName
              + " does not exist. It will be created during restore process");
        }
      }
    }

    if (existTableList.size() > 0) {
      if (!isOverwrite) {
        LOG.error("Existing table found in the restore target, please add \"-overwrite\" "
            + "option in the command if you mean to restore to these existing tables");
        LOG.info("Existing table list in restore target: " + existTableList);
        throw new IOException("Existing table found in target while no \"-overwrite\" "
            + "option found");
      } else {
        if (disabledTableList.size() > 0) {
          LOG.error("Found offline table in the restore target, "
              + "please enable them before restore with \"-overwrite\" option");
          LOG.info("Offline table list in restore target: " + disabledTableList);
          throw new IOException(
              "Found offline table in the target when restore with \"-overwrite\" option");
        }
      }
    }
  }

  /**
   * Restore operation. Stage 2: resolved Backup Image dependency
   * @param backupManifestMap : tableName,  Manifest
   * @param sTableArray The array of tables to be restored
   * @param tTableArray The array of mapping tables to restore to
   * @return set of BackupImages restored
   * @throws IOException exception
   */
  private void restoreStage(String backupId, HashMap<TableName, BackupManifest> backupManifestMap,
      TableName[] sTableArray, TableName[] tTableArray, boolean isOverwrite) throws IOException {
    TreeSet<BackupImage> restoreImageSet = new TreeSet<BackupImage>();
    boolean truncateIfExists = isOverwrite;
    try {
      Set<String> backupIdSet = new HashSet<>();
      for (int i = 0; i < sTableArray.length; i++) {
        TableName table = sTableArray[i];
        BackupManifest manifest = backupManifestMap.get(table);
        // Get the image list of this backup for restore in time order from old
        // to new.
        List<BackupImage> list = new ArrayList<BackupImage>();
        list.add(manifest.getBackupImage());
        List<BackupImage> depList = manifest.getDependentListByTable(table);
        list.addAll(depList);
        TreeSet<BackupImage> restoreList = new TreeSet<BackupImage>(list);
        LOG.debug("need to clear merged Image. to be implemented in future jira");
        restoreImages(restoreList.iterator(), table, tTableArray[i], truncateIfExists);
        restoreImageSet.addAll(restoreList);

        if (restoreImageSet != null && !restoreImageSet.isEmpty()) {
          LOG.info("Restore includes the following image(s):");
          for (BackupImage image : restoreImageSet) {
            LOG.info("Backup: "
                + image.getBackupId()
                + " "
                + HBackupFileSystem.getTableBackupDir(image.getRootDir(), image.getBackupId(),
                  table));
            if (image.getType() == BackupType.INCREMENTAL) {
              backupIdSet.add(image.getBackupId());
              LOG.debug("adding " + image.getBackupId() + " for bulk load");
            }
          }
        }
      }
      try (Connection conn = ConnectionFactory.createConnection(conf);
          BackupSystemTable table = new BackupSystemTable(conn)) {
        List<TableName> sTableList = Arrays.asList(sTableArray);
        for (String id : backupIdSet) {
          LOG.debug("restoring bulk load for " + id);
          Map<byte[], List<Path>>[] mapForSrc = table.readBulkLoadedFiles(id, sTableList);
          Map<LoadQueueItem, ByteBuffer> loaderResult;
          conf.setBoolean(LoadIncrementalHFiles.ALWAYS_COPY_FILES, true);
          LoadIncrementalHFiles loader = MapReduceRestoreService.createLoader(conf);
          for (int i = 0; i < sTableList.size(); i++) {
            if (mapForSrc[i] != null && !mapForSrc[i].isEmpty()) {
              loaderResult = loader.run(null, mapForSrc[i], tTableArray[i]);
              LOG.debug("bulk loading " + sTableList.get(i) + " to " + tTableArray[i]);
              if (loaderResult.isEmpty()) {
                String msg = "Couldn't bulk load for " + sTableList.get(i) + " to " +tTableArray[i];
                LOG.error(msg);
                throw new IOException(msg);
              }
            }
          }
        }
      }
    } catch (Exception e) {
      LOG.error("Failed", e);
      if (e instanceof IOException) {
        throw (IOException)e;
      }
      throw new IOException(e);
    }
    LOG.debug("restoreStage finished");
  }

  static long getTsFromBackupId(String backupId) {
    if (backupId == null) {
      return 0;
    }
    return Long.valueOf(backupId.substring(backupId.lastIndexOf("_")+1));
  }

  static boolean withinRange(long a, long lower, long upper) {
    if (a < lower || a > upper) {
      return false;
    }
    return true;
  }

  int getIndex(TableName tbl, List<TableName> sTableList) {
    for (int i = 0; i < sTableList.size(); i++) {
      if (tbl.equals(sTableList.get(i))) {
        return i;
      }
    }
    return -1;
  }

  /**
   * Restore operation handle each backupImage in iterator
   * @param it: backupImage iterator - ascending
   * @param sTable: table to be restored
   * @param tTable: table to be restored to
   * @throws IOException exception
   */
  private void restoreImages(Iterator<BackupImage> it, TableName sTable,
      TableName tTable, boolean truncateIfExists)
      throws IOException {

    // First image MUST be image of a FULL backup
    BackupImage image = it.next();

    String rootDir = image.getRootDir();
    String backupId = image.getBackupId();
    Path backupRoot = new Path(rootDir);

    // We need hFS only for full restore (see the code)
    RestoreServerUtil restoreTool = new RestoreServerUtil(conf, backupRoot, backupId);
    BackupManifest manifest = HBackupFileSystem.getManifest(sTable, conf, backupRoot, backupId);

    Path tableBackupPath = HBackupFileSystem.getTableBackupPath(sTable, backupRoot, backupId);

    // TODO: convert feature will be provided in a future JIRA
    boolean converted = false;

    if (manifest.getType() == BackupType.FULL || converted) {
      if (manifest.getType() == BackupType.FULL) {
        fullBackupId = manifest.getBackupImage().getBackupId();
      }
      LOG.info("Restoring '" + sTable + "' to '" + tTable + "' from "
          + (converted ? "converted" : "full") + " backup image " + tableBackupPath.toString());
      restoreTool.fullRestoreTable(tableBackupPath, sTable, tTable,
        converted, truncateIfExists);

    } else { // incremental Backup
      throw new IOException("Unexpected backup type " + image.getType());
    }

    // The rest one are incremental
    if (it.hasNext()) {
      List<String> fileDirList = new ArrayList<String>();
      while (it.hasNext()) {
        BackupImage im = it.next();
        String fileBackupDir = HBackupFileSystem.getTableBackupDir(im.getRootDir(),
          im.getBackupId(), sTable)+ Path.SEPARATOR+"data";
        fileDirList.add(fileBackupDir);
      }
      String logDirs = StringUtils.join(fileDirList, ",");
      LOG.info("Restoring '" + sTable + "' to '" + tTable
          + "' from file dirs: " + logDirs);
      String[] sarr = new String[fileDirList.size()];
      fileDirList.toArray(sarr);
      Path[] paths = org.apache.hadoop.util.StringUtils.stringToPath(sarr);
      restoreTool.incrementalRestoreTable(paths, new TableName[] { sTable },
        new TableName[] { tTable });
    }
    LOG.info(sTable + " has been successfully restored to " + tTable);
  }

}
