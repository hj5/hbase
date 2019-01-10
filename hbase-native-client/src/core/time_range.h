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

class TimeRange {

public:

	/**
	 * Default constructor.
	 * Represents interval [0, Long.MAX_VALUE) (allTime)
	 */
  TimeRange();
	/**
	 * Represents interval [minStamp, Long.MAX_VALUE)
	 * @param minStamp the minimum timestamp value, inclusive
	 */
  TimeRange(const long &minTimeStamp);
	/**
	 * Represents interval [minStamp, maxStamp)
	 * @param minStamp the minimum timestamp, inclusive
	 * @param maxStamp the maximum timestamp, exclusive
	 * @throws IllegalArgumentException
	 */
  TimeRange(const long &minTimeStamp, const long &maxTimeStamp);
  const long& GetMin() const ;
  const long& GetMax() const;
  const bool& GetAllTime() const;
  virtual ~TimeRange();

 private:
  long minTimeStamp_;
  long maxTimeStamp_;
  bool allTime_;
};
