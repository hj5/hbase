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
package org.apache.hadoop.hbase.regionserver;

import java.io.IOException;

import org.apache.hadoop.hbase.CompatibilityFactory;
import org.apache.hadoop.hbase.HBaseConfiguration;
import org.apache.hadoop.hbase.test.MetricsAssertHelper;
import org.apache.hadoop.hbase.testclassification.SmallTests;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import org.junit.experimental.categories.Category;

@Category({SmallTests.class})
public class TestMetricsTableAggregate {

  public static MetricsAssertHelper HELPER =
      CompatibilityFactory.getInstance(MetricsAssertHelper.class);

  private String tableName = "testTableMetrics";
  private String pre = "Namespace_default_table_" + tableName + "_metric_";

  private MetricsTableWrapperStub tableWrapper;
  private MetricsTable mt;
  private MetricsRegionServerWrapper rsWrapper;
  private MetricsRegionServer rsm;
  private MetricsTableAggregateSource agg;

  @BeforeClass
  public static void classSetUp() {
    HELPER.init();
  }

  @Before
  public void setUp() {
    tableWrapper = new MetricsTableWrapperStub(tableName);
    mt = new MetricsTable(tableWrapper);
    rsWrapper = new MetricsRegionServerWrapperStub();
    rsm = new MetricsRegionServer(HBaseConfiguration.create(), rsWrapper, mt);
    agg = mt.getTableSourceAgg();
  }

  @Test
  public void testRequestMetrics() throws IOException {
    HELPER.assertCounter(pre + "readRequestCount", 10, agg);
    HELPER.assertCounter(pre + "writeRequestCount", 20, agg);
    HELPER.assertCounter(pre + "totalRequestCount", 30, agg);
  }

  @Test
  public void testRegionAndStoreMetrics() throws IOException {
    HELPER.assertGauge(pre + "memstoreSize", 1000, agg);
    HELPER.assertGauge(pre + "storeFileSize", 2000, agg);
    HELPER.assertGauge(pre + "tableSize", 3000, agg);

    HELPER.assertGauge(pre + "regionCount", 11, agg);
    HELPER.assertGauge(pre + "storeCount", 22, agg);
    HELPER.assertGauge(pre + "storeFileCount", 33, agg);
    HELPER.assertGauge(pre + "maxStoreFileAge", 44, agg);
    HELPER.assertGauge(pre + "minStoreFileAge", 55, agg);
    HELPER.assertGauge(pre + "avgStoreFileAge", 66, agg);
    HELPER.assertGauge(pre + "numReferenceFiles", 77, agg);
    HELPER.assertGauge(pre + "averageRegionSize", 88, agg);
  }

  @Test
  public void testFlush() {
    rsm.updateFlush(tableName, 1, 2, 3);
    HELPER.assertCounter(pre + "flushTime_num_ops", 1, agg);
    HELPER.assertCounter(pre + "flushMemstoreSize_num_ops", 1, agg);
    HELPER.assertCounter(pre + "flushOutputSize_num_ops", 1, agg);
    HELPER.assertCounter(pre + "flushedMemstoreBytes", 2, agg);
    HELPER.assertCounter(pre + "flushedOutputBytes", 3, agg);

    rsm.updateFlush(tableName, 10, 20, 30);
    HELPER.assertCounter(pre + "flushTime_num_ops", 2, agg);
    HELPER.assertCounter(pre + "flushMemstoreSize_num_ops", 2, agg);
    HELPER.assertCounter(pre + "flushOutputSize_num_ops", 2, agg);
    HELPER.assertCounter(pre + "flushedMemstoreBytes", 22, agg);
    HELPER.assertCounter(pre + "flushedOutputBytes", 33, agg);
  }

  @Test
  public void testCompaction() {
    rsm.updateCompaction(tableName, false, 1, 2, 3, 4, 5);
    HELPER.assertCounter(pre + "compactionTime_num_ops", 1, agg);
    HELPER.assertCounter(pre + "compactionInputFileCount_num_ops", 1, agg);
    HELPER.assertCounter(pre + "compactionInputSize_num_ops", 1, agg);
    HELPER.assertCounter(pre + "compactionOutputFileCount_num_ops", 1, agg);
    HELPER.assertCounter(pre + "compactedInputBytes", 4, agg);
    HELPER.assertCounter(pre + "compactedoutputBytes", 5, agg);

    rsm.updateCompaction(tableName, false, 10, 20, 30, 40, 50);
    HELPER.assertCounter(pre + "compactionTime_num_ops", 2, agg);
    HELPER.assertCounter(pre + "compactionInputFileCount_num_ops", 2, agg);
    HELPER.assertCounter(pre + "compactionInputSize_num_ops", 2, agg);
    HELPER.assertCounter(pre + "compactionOutputFileCount_num_ops", 2, agg);
    HELPER.assertCounter(pre + "compactedInputBytes", 44, agg);
    HELPER.assertCounter(pre + "compactedoutputBytes", 55, agg);

    // do major compaction
    rsm.updateCompaction(tableName, true, 100, 200, 300, 400, 500);

    HELPER.assertCounter(pre + "compactionTime_num_ops", 3, agg);
    HELPER.assertCounter(pre + "compactionInputFileCount_num_ops", 3, agg);
    HELPER.assertCounter(pre + "compactionInputSize_num_ops", 3, agg);
    HELPER.assertCounter(pre + "compactionOutputFileCount_num_ops", 3, agg);
    HELPER.assertCounter(pre + "compactedInputBytes", 444, agg);
    HELPER.assertCounter(pre + "compactedoutputBytes", 555, agg);

    HELPER.assertCounter(pre + "majorCompactionTime_num_ops", 1, agg);
    HELPER.assertCounter(pre + "majorCompactionInputFileCount_num_ops", 1, agg);
    HELPER.assertCounter(pre + "majorCompactionInputSize_num_ops", 1, agg);
    HELPER.assertCounter(pre + "majorCompactionOutputFileCount_num_ops", 1, agg);
    HELPER.assertCounter(pre + "majorCompactedInputBytes", 400, agg);
    HELPER.assertCounter(pre + "majorCompactedoutputBytes", 500, agg);
  }
}
