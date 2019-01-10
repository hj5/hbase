/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.apache.hadoop.hbase.backup;

import static org.junit.Assert.assertTrue;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Map;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.hadoop.hbase.TableName;
import org.apache.hadoop.hbase.backup.impl.BackupSystemTable;
import org.apache.hadoop.hbase.client.BackupAdmin;
import org.apache.hadoop.hbase.client.Connection;
import org.apache.hadoop.hbase.client.ConnectionFactory;
import org.apache.hadoop.hbase.client.HBaseAdmin;
import org.apache.hadoop.hbase.client.HTable;
import org.apache.hadoop.hbase.client.Put;
import org.apache.hadoop.hbase.mapreduce.TestLoadIncrementalHFiles;
import org.apache.hadoop.hbase.testclassification.LargeTests;
import org.apache.hadoop.hbase.util.Bytes;
import org.apache.hadoop.hbase.util.Pair;
import org.hamcrest.CoreMatchers;
import org.junit.Assert;
import org.junit.Test;
import org.junit.experimental.categories.Category;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;

import com.google.common.collect.Lists;

/**
 * 
 *  1. Create table t1, t2
 *  2. Load data to t1, t2
 *  3  Full backup t1, t2
 *  4  Delete t2
 *  5  Load data to t1
 *  6  Incremental backup t1
 */
@Category(LargeTests.class)
@RunWith(Parameterized.class)
public class TestIncrementalBackupDeleteTable extends TestBackupBase {
  private static final Log LOG = LogFactory.getLog(TestIncrementalBackupDeleteTable.class);

  @Parameterized.Parameters
  public static Collection<Object[]> data() {
    secure = true;
    List<Object[]> params = new ArrayList<Object[]>();
    params.add(new Object[] {Boolean.TRUE});
    return params;
  }

  public TestIncrementalBackupDeleteTable(Boolean b) {
  }

  @Test
  public void TestIncBackupDeleteTable() throws Exception {
    String testName = "TestIncBackupDeleteTable";
    // #1 - create full backup for all tables
    LOG.info("create full backup image for all tables");

    List<TableName> tables = Lists.newArrayList(table1, table2);
    HBaseAdmin admin = null;
    Connection conn = ConnectionFactory.createConnection(conf1);
    admin = (HBaseAdmin) conn.getAdmin();

    BackupRequest request = new BackupRequest();
    request.setBackupType(BackupType.FULL).setTableList(tables).setTargetRootDir(BACKUP_ROOT_DIR);
    String backupIdFull = admin.getBackupAdmin().backupTables(request);

    assertTrue(checkSucceeded(backupIdFull));

    // #2 - insert some data to table table1
    HTable t1 = (HTable) conn.getTable(table1);
    Put p1;
    for (int i = 0; i < NB_ROWS_IN_BATCH; i++) {
      p1 = new Put(Bytes.toBytes("row-t1" + i));
      p1.addColumn(famName, qualName, Bytes.toBytes("val" + i));
      t1.put(p1);
    }

    Assert.assertThat(TEST_UTIL.countRows(t1), CoreMatchers.equalTo(NB_ROWS_IN_BATCH * 2));
    t1.close();

    // Delete table table2
    admin.disableTable(table2);
    admin.deleteTable(table2);

    int NB_ROWS2 = 20;
    LOG.debug("bulk loading into " + testName);
    int actual = TestLoadIncrementalHFiles.loadHFiles(testName, table1Desc, TEST_UTIL, famName,
        qualName, false, null, new byte[][][] {
      new byte[][]{ Bytes.toBytes("aaaa"), Bytes.toBytes("cccc") },
      new byte[][]{ Bytes.toBytes("ddd"), Bytes.toBytes("ooo") },
    }, true, false, true, NB_ROWS_IN_BATCH*2, NB_ROWS2, false);

    // #3 - incremental backup for table1
    tables = Lists.newArrayList(table1);
    request = new BackupRequest();
    request.setBackupType(BackupType.INCREMENTAL).setTableList(tables)
    .setTargetRootDir(BACKUP_ROOT_DIR);
    String backupIdIncMultiple = admin.getBackupAdmin().backupTables(request);
    assertTrue(checkSucceeded(backupIdIncMultiple));

    BackupAdmin client = getBackupAdmin();
    /*   // #4 - restore full backup for all tables, without overwrite
    TableName[] tablesRestoreFull =
        new TableName[] { table1, table2};

    TableName[] tablesMapFull =
        new TableName[] { table1_restore, table2_restore };

    client.restore(createRestoreRequest(BACKUP_ROOT_DIR, backupIdFull, false,
        tablesRestoreFull,
        tablesMapFull, false));

    // #5.1 - check tables for full restore
    HBaseAdmin hAdmin = TEST_UTIL.getHBaseAdmin();
    assertTrue(hAdmin.tableExists(table1_restore));
    assertTrue(hAdmin.tableExists(table2_restore));


    hAdmin.close();

    // #5.2 - checking row count of tables for full restore
    HTable hTable = (HTable) conn.getTable(table1_restore);
    Assert.assertThat(TEST_UTIL.countRows(hTable), CoreMatchers.equalTo(NB_ROWS_IN_BATCH));
    hTable.close();

    hTable = (HTable) conn.getTable(table2_restore);
    Assert.assertThat(TEST_UTIL.countRows(hTable), CoreMatchers.equalTo(NB_ROWS_IN_BATCH));
    hTable.close();
     */
    // #6 - restore incremental backup for table1
    TableName[] tablesRestoreIncMultiple =
        new TableName[] { table1 };
    TableName[] tablesMapIncMultiple =
        new TableName[] { table1_restore };
    client.restore(createRestoreRequest(BACKUP_ROOT_DIR, backupIdIncMultiple, false,
      tablesRestoreIncMultiple, tablesMapIncMultiple, true));

    HTable hTable = (HTable) conn.getTable(table1_restore);
    Assert.assertThat(TEST_UTIL.countRows(hTable), CoreMatchers.equalTo(NB_ROWS_IN_BATCH * 2 +
        actual));

    request.setBackupType(BackupType.FULL).setTableList(tables).setTargetRootDir(BACKUP_ROOT_DIR);
    backupIdFull = client.backupTables(request);
    try (final BackupSystemTable table = new BackupSystemTable(conn)) {
      Pair<Map<TableName, Map<String, Map<String, List<Pair<String, Boolean>>>>>, List<byte[]>> pair
      =table.readOrigBulkloadRows(tables);
      assertTrue("map still has " + pair.getSecond().size() + " entries",
          pair.getSecond().isEmpty());
    }
    assertTrue(checkSucceeded(backupIdFull));

    hTable.close();
    admin.close();
    conn.close();
  }

}
