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
package org.apache.hadoop.hbase.ipc;

import java.io.IOException;
import java.io.InputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.nio.channels.ReadableByteChannel;
import java.nio.channels.SocketChannel;
import java.util.Arrays;
import java.util.concurrent.ConcurrentLinkedDeque;
import java.util.concurrent.atomic.LongAdder;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

import org.apache.hadoop.hbase.CellScanner;
import org.apache.hadoop.hbase.DoNotRetryIOException;
import org.apache.hadoop.hbase.HConstants;
import org.apache.hadoop.hbase.classification.InterfaceAudience;
import org.apache.hadoop.hbase.client.VersionInfoUtil;
import org.apache.hadoop.hbase.exceptions.RequestTooBigException;
import org.apache.hadoop.hbase.ipc.RpcServer.CallCleanup;
import org.apache.hadoop.hbase.nio.ByteBuff;
import org.apache.hadoop.hbase.nio.SingleByteBuff;
import org.apache.hadoop.hbase.security.AccessDeniedException;
import org.apache.hadoop.hbase.security.AuthMethod;
import org.apache.hadoop.hbase.security.SaslStatus;
import org.apache.hadoop.hbase.security.SaslUtil;
import org.apache.hadoop.hbase.shaded.com.google.protobuf.BlockingService;
import org.apache.hadoop.hbase.shaded.com.google.protobuf.CodedInputStream;
import org.apache.hadoop.hbase.shaded.com.google.protobuf.Message;
import org.apache.hadoop.hbase.shaded.com.google.protobuf.Descriptors.MethodDescriptor;
import org.apache.hadoop.hbase.shaded.protobuf.ProtobufUtil;
import org.apache.hadoop.hbase.shaded.protobuf.generated.RPCProtos.RequestHeader;
import org.apache.hadoop.hbase.util.Bytes;
import org.apache.hadoop.hbase.util.Pair;
import org.apache.hadoop.io.IntWritable;
import org.apache.htrace.TraceInfo;

/** Reads calls from a connection and queues them for handling. */
@edu.umd.cs.findbugs.annotations.SuppressWarnings(value = "VO_VOLATILE_INCREMENT",
    justification = "False positive according to http://sourceforge.net/p/findbugs/bugs/1032/")
@InterfaceAudience.Private
class SimpleServerRpcConnection extends ServerRpcConnection {

  final SocketChannel channel;
  private ByteBuff data;
  private ByteBuffer dataLengthBuffer;
  protected final ConcurrentLinkedDeque<SimpleServerCall> responseQueue =
      new ConcurrentLinkedDeque<>();
  final Lock responseWriteLock = new ReentrantLock();
  private final LongAdder rpcCount = new LongAdder(); // number of outstanding rpcs
  private long lastContact;
  private final Socket socket;
  private final SimpleRpcServerResponder responder;

  public SimpleServerRpcConnection(SimpleRpcServer rpcServer, SocketChannel channel,
      long lastContact) {
    super(rpcServer);
    this.channel = channel;
    this.lastContact = lastContact;
    this.data = null;
    this.dataLengthBuffer = ByteBuffer.allocate(4);
    this.socket = channel.socket();
    this.addr = socket.getInetAddress();
    if (addr == null) {
      this.hostAddress = "*Unknown*";
    } else {
      this.hostAddress = addr.getHostAddress();
    }
    this.remotePort = socket.getPort();
    if (rpcServer.socketSendBufferSize != 0) {
      try {
        socket.setSendBufferSize(rpcServer.socketSendBufferSize);
      } catch (IOException e) {
        SimpleRpcServer.LOG.warn(
          "Connection: unable to set socket send buffer size to " + rpcServer.socketSendBufferSize);
      }
    }
    this.saslCall = new SimpleServerCall(SASL_CALLID, null, null, null, null, null, this, 0, null,
        null, System.currentTimeMillis(), 0, rpcServer.reservoir, rpcServer.cellBlockBuilder, null,
        rpcServer.responder);
    this.setConnectionHeaderResponseCall = new SimpleServerCall(CONNECTION_HEADER_RESPONSE_CALLID,
        null, null, null, null, null, this, 0, null, null, System.currentTimeMillis(), 0,
        rpcServer.reservoir, rpcServer.cellBlockBuilder, null, rpcServer.responder);
    this.authFailedCall = new SimpleServerCall(AUTHORIZATION_FAILED_CALLID, null, null, null, null,
        null, this, 0, null, null, System.currentTimeMillis(), 0, rpcServer.reservoir,
        rpcServer.cellBlockBuilder, null, rpcServer.responder);
    this.responder = rpcServer.responder;
  }

  public void setLastContact(long lastContact) {
    this.lastContact = lastContact;
  }

  public long getLastContact() {
    return lastContact;
  }

  /* Return true if the connection has no outstanding rpc */
  boolean isIdle() {
    return rpcCount.sum() == 0;
  }

  /* Decrement the outstanding RPC count */
  protected void decRpcCount() {
    rpcCount.decrement();
  }

  /* Increment the outstanding RPC count */
  protected void incRpcCount() {
    rpcCount.increment();
  }

  private int readPreamble() throws IOException {
    int count;
    // Check for 'HBas' magic.
    this.dataLengthBuffer.flip();
    if (!Arrays.equals(HConstants.RPC_HEADER, dataLengthBuffer.array())) {
      return doBadPreambleHandling(
        "Expected HEADER=" + Bytes.toStringBinary(HConstants.RPC_HEADER) + " but received HEADER=" +
            Bytes.toStringBinary(dataLengthBuffer.array()) + " from " + toString());
    }
    // Now read the next two bytes, the version and the auth to use.
    ByteBuffer versionAndAuthBytes = ByteBuffer.allocate(2);
    count = this.rpcServer.channelRead(channel, versionAndAuthBytes);
    if (count < 0 || versionAndAuthBytes.remaining() > 0) {
      return count;
    }
    int version = versionAndAuthBytes.get(0);
    byte authbyte = versionAndAuthBytes.get(1);
    this.authMethod = AuthMethod.valueOf(authbyte);
    if (version != SimpleRpcServer.CURRENT_VERSION) {
      String msg = getFatalConnectionString(version, authbyte);
      return doBadPreambleHandling(msg, new WrongVersionException(msg));
    }
    if (authMethod == null) {
      String msg = getFatalConnectionString(version, authbyte);
      return doBadPreambleHandling(msg, new BadAuthException(msg));
    }
    if (this.rpcServer.isSecurityEnabled && authMethod == AuthMethod.SIMPLE) {
      if (this.rpcServer.allowFallbackToSimpleAuth) {
        this.rpcServer.metrics.authenticationFallback();
        authenticatedWithFallback = true;
      } else {
        AccessDeniedException ae = new AccessDeniedException("Authentication is required");
        this.rpcServer.setupResponse(authFailedResponse, authFailedCall, ae, ae.getMessage());
        authFailedCall.sendResponseIfReady();
        throw ae;
      }
    }
    if (!this.rpcServer.isSecurityEnabled && authMethod != AuthMethod.SIMPLE) {
      doRawSaslReply(SaslStatus.SUCCESS, new IntWritable(SaslUtil.SWITCH_TO_SIMPLE_AUTH), null,
        null);
      authMethod = AuthMethod.SIMPLE;
      // client has already sent the initial Sasl message and we
      // should ignore it. Both client and server should fall back
      // to simple auth from now on.
      skipInitialSaslHandshake = true;
    }
    if (authMethod != AuthMethod.SIMPLE) {
      useSasl = true;
    }

    dataLengthBuffer.clear();
    connectionPreambleRead = true;
    return count;
  }

  private int read4Bytes() throws IOException {
    if (this.dataLengthBuffer.remaining() > 0) {
      return this.rpcServer.channelRead(channel, this.dataLengthBuffer);
    } else {
      return 0;
    }
  }

  /**
   * Read off the wire. If there is not enough data to read, update the connection state with what
   * we have and returns.
   * @return Returns -1 if failure (and caller will close connection), else zero or more.
   * @throws IOException
   * @throws InterruptedException
   */
  public int readAndProcess() throws IOException, InterruptedException {
    // Try and read in an int. If new connection, the int will hold the 'HBas' HEADER. If it
    // does, read in the rest of the connection preamble, the version and the auth method.
    // Else it will be length of the data to read (or -1 if a ping). We catch the integer
    // length into the 4-byte this.dataLengthBuffer.
    int count = read4Bytes();
    if (count < 0 || dataLengthBuffer.remaining() > 0) {
      return count;
    }

    // If we have not read the connection setup preamble, look to see if that is on the wire.
    if (!connectionPreambleRead) {
      count = readPreamble();
      if (!connectionPreambleRead) {
        return count;
      }

      count = read4Bytes();
      if (count < 0 || dataLengthBuffer.remaining() > 0) {
        return count;
      }
    }

    // We have read a length and we have read the preamble. It is either the connection header
    // or it is a request.
    if (data == null) {
      dataLengthBuffer.flip();
      int dataLength = dataLengthBuffer.getInt();
      if (dataLength == RpcClient.PING_CALL_ID) {
        if (!useWrap) { // covers the !useSasl too
          dataLengthBuffer.clear();
          return 0; // ping message
        }
      }
      if (dataLength < 0) { // A data length of zero is legal.
        throw new DoNotRetryIOException(
            "Unexpected data length " + dataLength + "!! from " + getHostAddress());
      }

      if (dataLength > this.rpcServer.maxRequestSize) {
        String msg = "RPC data length of " + dataLength + " received from " + getHostAddress() +
            " is greater than max allowed " + this.rpcServer.maxRequestSize + ". Set \"" +
            SimpleRpcServer.MAX_REQUEST_SIZE +
            "\" on server to override this limit (not recommended)";
        SimpleRpcServer.LOG.warn(msg);

        if (connectionHeaderRead && connectionPreambleRead) {
          incRpcCount();
          // Construct InputStream for the non-blocking SocketChannel
          // We need the InputStream because we want to read only the request header
          // instead of the whole rpc.
          ByteBuffer buf = ByteBuffer.allocate(1);
          InputStream is = new InputStream() {
            @Override
            public int read() throws IOException {
              SimpleServerRpcConnection.this.rpcServer.channelRead(channel, buf);
              buf.flip();
              int x = buf.get();
              buf.flip();
              return x;
            }
          };
          CodedInputStream cis = CodedInputStream.newInstance(is);
          int headerSize = cis.readRawVarint32();
          Message.Builder builder = RequestHeader.newBuilder();
          ProtobufUtil.mergeFrom(builder, cis, headerSize);
          RequestHeader header = (RequestHeader) builder.build();

          // Notify the client about the offending request
          SimpleServerCall reqTooBig = new SimpleServerCall(header.getCallId(), this.service, null,
              null, null, null, this, 0, null, this.addr, System.currentTimeMillis(), 0,
              this.rpcServer.reservoir, this.rpcServer.cellBlockBuilder, null, responder);
          this.rpcServer.metrics.exception(SimpleRpcServer.REQUEST_TOO_BIG_EXCEPTION);
          // Make sure the client recognizes the underlying exception
          // Otherwise, throw a DoNotRetryIOException.
          if (VersionInfoUtil.hasMinimumVersion(connectionHeader.getVersionInfo(),
            RequestTooBigException.MAJOR_VERSION, RequestTooBigException.MINOR_VERSION)) {
            this.rpcServer.setupResponse(null, reqTooBig, SimpleRpcServer.REQUEST_TOO_BIG_EXCEPTION,
              msg);
          } else {
            this.rpcServer.setupResponse(null, reqTooBig, new DoNotRetryIOException(), msg);
          }
          // We are going to close the connection, make sure we process the response
          // before that. In rare case when this fails, we still close the connection.
          responseWriteLock.lock();
          try {
            this.responder.processResponse(reqTooBig);
          } finally {
            responseWriteLock.unlock();
          }
        }
        // Close the connection
        return -1;
      }

      // Initialize this.data with a ByteBuff.
      // This call will allocate a ByteBuff to read request into and assign to this.data
      // Also when we use some buffer(s) from pool, it will create a CallCleanup instance also and
      // assign to this.callCleanup
      initByteBuffToReadInto(dataLength);

      // Increment the rpc count. This counter will be decreased when we write
      // the response. If we want the connection to be detected as idle properly, we
      // need to keep the inc / dec correct.
      incRpcCount();
    }

    count = channelDataRead(channel, data);

    if (count >= 0 && data.remaining() == 0) { // count==0 if dataLength == 0
      process();
    }

    return count;
  }

  // It creates the ByteBuff and CallCleanup and assign to Connection instance.
  private void initByteBuffToReadInto(int length) {
    // We create random on heap buffers are read into those when
    // 1. ByteBufferPool is not there.
    // 2. When the size of the req is very small. Using a large sized (64 KB) buffer from pool is
    // waste then. Also if all the reqs are of this size, we will be creating larger sized
    // buffers and pool them permanently. This include Scan/Get request and DDL kind of reqs like
    // RegionOpen.
    // 3. If it is an initial handshake signal or initial connection request. Any way then
    // condition 2 itself will match
    // 4. When SASL use is ON.
    if (this.rpcServer.reservoir == null || skipInitialSaslHandshake || !connectionHeaderRead ||
        useSasl || length < this.rpcServer.minSizeForReservoirUse) {
      this.data = new SingleByteBuff(ByteBuffer.allocate(length));
    } else {
      Pair<ByteBuff, CallCleanup> pair = RpcServer.allocateByteBuffToReadInto(
        this.rpcServer.reservoir, this.rpcServer.minSizeForReservoirUse, length);
      this.data = pair.getFirst();
      this.callCleanup = pair.getSecond();
    }
  }

  protected int channelDataRead(ReadableByteChannel channel, ByteBuff buf) throws IOException {
    int count = buf.read(channel);
    if (count > 0) {
      this.rpcServer.metrics.receivedBytes(count);
    }
    return count;
  }

  /**
   * Process the data buffer and clean the connection state for the next call.
   */
  private void process() throws IOException, InterruptedException {
    data.rewind();
    try {
      if (skipInitialSaslHandshake) {
        skipInitialSaslHandshake = false;
        return;
      }

      if (useSasl) {
        saslReadAndProcess(data);
      } else {
        processOneRpc(data);
      }

    } finally {
      dataLengthBuffer.clear(); // Clean for the next call
      data = null; // For the GC
      this.callCleanup = null;
    }
  }

  private int doBadPreambleHandling(final String msg) throws IOException {
    return doBadPreambleHandling(msg, new FatalConnectionException(msg));
  }

  private int doBadPreambleHandling(final String msg, final Exception e) throws IOException {
    SimpleRpcServer.LOG.warn(msg);
    SimpleServerCall fakeCall = new SimpleServerCall(-1, null, null, null, null, null, this, -1,
        null, null, System.currentTimeMillis(), 0, this.rpcServer.reservoir,
        this.rpcServer.cellBlockBuilder, null, responder);
    this.rpcServer.setupResponse(null, fakeCall, e, msg);
    this.responder.doRespond(fakeCall);
    // Returning -1 closes out the connection.
    return -1;
  }

  @Override
  public synchronized void close() {
    disposeSasl();
    data = null;
    callCleanup = null;
    if (!channel.isOpen()) return;
    try {
      socket.shutdownOutput();
    } catch (Exception ignored) {
      if (SimpleRpcServer.LOG.isTraceEnabled()) {
        SimpleRpcServer.LOG.trace("Ignored exception", ignored);
      }
    }
    if (channel.isOpen()) {
      try {
        channel.close();
      } catch (Exception ignored) {
      }
    }
    try {
      socket.close();
    } catch (Exception ignored) {
      if (SimpleRpcServer.LOG.isTraceEnabled()) {
        SimpleRpcServer.LOG.trace("Ignored exception", ignored);
      }
    }
  }

  @Override
  public boolean isConnectionOpen() {
    return channel.isOpen();
  }

  @Override
  public SimpleServerCall createCall(int id, BlockingService service, MethodDescriptor md,
      RequestHeader header, Message param, CellScanner cellScanner, long size, TraceInfo tinfo,
      InetAddress remoteAddress, int timeout, CallCleanup reqCleanup) {
    return new SimpleServerCall(id, service, md, header, param, cellScanner, this, size, tinfo,
        remoteAddress, System.currentTimeMillis(), timeout, this.rpcServer.reservoir,
        this.rpcServer.cellBlockBuilder, reqCleanup, this.responder);
  }
}