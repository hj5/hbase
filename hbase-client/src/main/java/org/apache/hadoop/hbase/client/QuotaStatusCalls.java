/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to you under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package org.apache.hadoop.hbase.client;

import java.io.IOException;

import org.apache.hadoop.hbase.ServerName;
import org.apache.hadoop.hbase.classification.InterfaceAudience;
import org.apache.hadoop.hbase.ipc.RpcControllerFactory;
import org.apache.hadoop.hbase.protobuf.ProtobufUtil;
import org.apache.hadoop.hbase.protobuf.RequestConverter;
import org.apache.hadoop.hbase.protobuf.generated.AdminProtos.AdminService;
import org.apache.hadoop.hbase.protobuf.generated.QuotaProtos.GetSpaceQuotaEnforcementsResponse;
import org.apache.hadoop.hbase.protobuf.generated.QuotaProtos.GetSpaceQuotaRegionSizesResponse;
import org.apache.hadoop.hbase.protobuf.generated.QuotaProtos.GetSpaceQuotaSnapshotsResponse;

import com.google.protobuf.ServiceException;

/**
 * Client class to wrap RPCs to HBase servers for space quota status information.
 */
@InterfaceAudience.Private
public class QuotaStatusCalls {

  public static GetSpaceQuotaRegionSizesResponse getMasterRegionSizes(
      ClusterConnection clusterConn, int timeout) throws IOException {
    RpcControllerFactory rpcController = clusterConn.getRpcControllerFactory();
    RpcRetryingCallerFactory rpcCaller = clusterConn.getRpcRetryingCallerFactory();
    return getMasterRegionSizes(clusterConn, rpcController, rpcCaller, timeout);
  }

  public static GetSpaceQuotaRegionSizesResponse getMasterRegionSizes(
      ClusterConnection conn, final RpcControllerFactory factory,
      RpcRetryingCallerFactory rpcCaller, int timeout) throws IOException {
    MasterCallable<GetSpaceQuotaRegionSizesResponse> callable =
        new MasterCallable<GetSpaceQuotaRegionSizesResponse>(conn) {
      @Override
      public GetSpaceQuotaRegionSizesResponse call(int callTimeout) throws Exception {
        return master.getSpaceQuotaRegionSizes(
            factory.newController(), RequestConverter.buildGetSpaceQuotaRegionSizesRequest());
      }
    };
    RpcRetryingCaller<GetSpaceQuotaRegionSizesResponse> caller = rpcCaller.newCaller();
    try {
      return caller.callWithoutRetries(callable, timeout);
    } finally {
      callable.close();
    }
  }

  public static GetSpaceQuotaSnapshotsResponse getRegionServerQuotaSnapshot(
      ClusterConnection clusterConn, int timeout, ServerName sn) throws IOException {
    RpcControllerFactory rpcController = clusterConn.getRpcControllerFactory();
    return getRegionServerQuotaSnapshot(clusterConn, rpcController, timeout, sn);
  }

  public static GetSpaceQuotaSnapshotsResponse getRegionServerQuotaSnapshot(
      ClusterConnection conn, RpcControllerFactory factory,
      int timeout, ServerName sn) throws IOException {
    final AdminService.BlockingInterface admin = conn.getAdmin(sn);
    try {
      return admin.getSpaceQuotaSnapshots(
          factory.newController(), RequestConverter.buildGetSpaceQuotaSnapshotsRequest());
    } catch (ServiceException se) {
      throw ProtobufUtil.getRemoteException(se);
    }
  }

  public static GetSpaceQuotaEnforcementsResponse getRegionServerSpaceQuotaEnforcements(
      ClusterConnection clusterConn, int timeout, ServerName sn) throws IOException {
    RpcControllerFactory rpcController = clusterConn.getRpcControllerFactory();
    return getRegionServerSpaceQuotaEnforcements(clusterConn, rpcController, timeout, sn);
  }

  public static GetSpaceQuotaEnforcementsResponse getRegionServerSpaceQuotaEnforcements(
      ClusterConnection conn, RpcControllerFactory factory,
      int timeout, ServerName sn) throws IOException {
    final AdminService.BlockingInterface admin = conn.getAdmin(sn);
    try {
      return admin.getSpaceQuotaEnforcements(
          factory.newController(), RequestConverter.buildGetSpaceQuotaEnforcementsRequest());
    } catch (ServiceException se) {
      throw ProtobufUtil.getRemoteException(se);
    }
  }
}
