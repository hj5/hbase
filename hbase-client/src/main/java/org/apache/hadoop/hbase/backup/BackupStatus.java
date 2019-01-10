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

package org.apache.hadoop.hbase.backup;

import java.io.Serializable;

import org.apache.hadoop.hbase.TableName;
import org.apache.hadoop.hbase.backup.util.BackupClientUtil;
import org.apache.hadoop.hbase.classification.InterfaceAudience;
import org.apache.hadoop.hbase.classification.InterfaceStability;
import org.apache.hadoop.hbase.protobuf.ProtobufUtil;
import org.apache.hadoop.hbase.protobuf.generated.BackupProtos;

/**
 * Backup status and related information encapsulated for a table.
 * At this moment only TargetDir and SnapshotName is encapsulated here.
 */

@InterfaceAudience.Private
@InterfaceStability.Evolving
public class BackupStatus implements Serializable {

  private static final long serialVersionUID = -5968397963548535982L;

  // table name for backup
  private TableName table;

  // target directory of the backup image for this table
  private String targetDir;

  // snapshot name for offline/online snapshot
  private String snapshotName = null;

  public BackupStatus() {

  }

  public BackupStatus(TableName table, String targetRootDir, String backupId) {
    this.table = table;
    this.targetDir = BackupClientUtil.getTableBackupDir(targetRootDir, backupId, table);
  }

  public String getSnapshotName() {
    return snapshotName;
  }

  public void setSnapshotName(String snapshotName) {
    this.snapshotName = snapshotName;
  }

  public String getTargetDir() {
    return targetDir;
  }

  public TableName getTable() {
    return table;
  }

  public void setTable(TableName table) {
    this.table = table;
  }

  public void setTargetDir(String targetDir) {
    this.targetDir = targetDir;
  }

  public static BackupStatus convert(BackupProtos.TableBackupStatus proto)
  {
    BackupStatus bs = new BackupStatus();
    bs.setTable(ProtobufUtil.toTableName(proto.getTable()));
    bs.setTargetDir(proto.getTargetDir());
    if(proto.hasSnapshot()){
      bs.setSnapshotName(proto.getSnapshot());
    }
    return bs;
  }

  public BackupProtos.TableBackupStatus toProto() {
    BackupProtos.TableBackupStatus.Builder builder =
        BackupProtos.TableBackupStatus.newBuilder();
    if(snapshotName != null) {
      builder.setSnapshot(snapshotName);
    }
    builder.setTable(ProtobufUtil.toProtoTableName(table));
    builder.setTargetDir(targetDir);
    return builder.build();
  }
}
