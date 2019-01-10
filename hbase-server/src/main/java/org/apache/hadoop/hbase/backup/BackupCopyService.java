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

import java.io.IOException;

import org.apache.hadoop.conf.Configurable;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.hbase.backup.impl.BackupManager;
import org.apache.hadoop.hbase.classification.InterfaceAudience;
import org.apache.hadoop.hbase.classification.InterfaceStability;

@InterfaceAudience.Private
@InterfaceStability.Evolving
public interface BackupCopyService extends Configurable {
  static enum Type {
    FULL, INCREMENTAL
  }

  /**
   * Copy backup data
   * @param backupContext - context
   * @param backupManager  - manager
   * @param conf - configuration
   * @param copyType - copy type
   * @param options - array of options (implementation-specific)
   * @return result (0 - success)
   * @throws IOException
   */
  public int copy(BackupInfo backupContext, BackupManager backupManager, Configuration conf,
      BackupCopyService.Type copyType, String[] options) throws IOException;
  

   /**
    * Cancel copy job
    * @param jobHandler - copy job handler
    * @throws IOException
    */
   public void cancelCopyJob(String jobHandler) throws IOException;  
}
