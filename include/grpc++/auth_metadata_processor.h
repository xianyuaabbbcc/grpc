/*
 *
 * Copyright 2015, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef GRPCXX_AUTH_METADATA_PROCESSOR_H_
#define GRPCXX_AUTH_METADATA_PROCESSOR_H_

#include <map>
#include <string>

#include <grpc++/auth_context.h>

namespace grpc {

class AuthMetadataProcessor {
 public:
  virtual ~AuthMetadataProcessor() {}

  // If this method returns true, the Process function will be scheduled in
  // a different thread as the one processing the call.
  virtual bool IsBlocking() const { return true; }

  // context is read/write: it contains the properties of the channel peer and
  // it is the job of the Process method to augment it with properties derived
  // from the passed-in auth_metadata.
  virtual bool Process(
      std::multimap<grpc::string, grpc::string>& auth_metadata,
      AuthContext* context,
      std::multimap<grpc::string, grpc::string>* consumed_auth_metadata) = 0;
};

}  // namespace grpc

#endif  // GRPCXX_AUTH_METADATA_PROCESSOR_H_

