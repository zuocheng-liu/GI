/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef FASTCGI_PROCESSOR_H
#define FASTCGI_PROCESSOR_H

#include <boost/shared_ptr.hpp>
#include <transport/TTransport.h>
#include <transport/TTransportException.h>
#include <protocol/TProtocol.h>
#include <TProcessor.h>

#include "FastCGI.h"

namespace FastCGI {

/*
 * Class for keeping track of function call statistics and printing them if desired
 *
 */
class FastCGIProcessor : public apache::thrift::TProcessor {
public:
  virtual bool process(boost::shared_ptr<apache::thrift::protocol::TProtocol> in, boost::shared_ptr<apache::thrift::protocol::TProtocol> out);
};

} // end namespace FastCGI 

#endif
