/*
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
 *
 */
#pragma once

#include <glog/logging.h>
#include <mutex>
#include <string>
#include "core/configuration.h"

namespace hbase {
namespace security {
static constexpr const char* kKerberos = "kerberos";
class User {
 public:
  explicit User(const std::string& user_name) : user_name_(user_name) {}
  virtual ~User() = default;

  std::string user_name() { return user_name_; }

  static std::shared_ptr<User> defaultUser() { return std::make_shared<User>("__drwho"); }

  static bool IsSecurityEnabled(const Configuration& conf) {
    return conf.Get("hbase.security.authentication", "").compare(kKerberos) == 0;
  }

 private:
  std::string user_name_;
};
}
}
