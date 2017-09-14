/* Copyright 2016 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_CORE_DISTRIBUTED_RUNTIME_RPC_RPC_RENDEZVOUS_MGR_H_
#define TENSORFLOW_CORE_DISTRIBUTED_RUNTIME_RPC_RPC_RENDEZVOUS_MGR_H_

#include "tensorflow/core/distributed_runtime/base_rendezvous_mgr.h"
#include "tensorflow/core/distributed_runtime/worker_cache.h"
#include "tensorflow/core/distributed_runtime/worker_env.h"
#include "tensorflow/core/platform/macros.h"

namespace tensorflow {

class ZrpcRemoteRendezvous : public BaseRemoteRendezvous
{
public:
    ZrpcRemoteRendezvous(const WorkerEnv *env, WorkerCacheInterface *cache, int64 step_id)
        : BaseRemoteRendezvous(env, step_id, false)
        , cache_(cache)
    {
    }

    // Forwards to local_, where the Tensor "val" will be buffered and
    // any waiting callback stored.
    Status Send(const ParsedKey& key, const Rendezvous::Args& args,
                const Tensor& val, const bool is_dead) override;

    // This method is called only by the RecvOp.  It tests to see
    // whether the value will be produced by a local or remote device
    // and handles accordingly.  In the local case it forwards to
    // local_, in the remote case it initiates an RPC request.
    void RecvAsync(const ParsedKey& key, const Rendezvous::Args& args,
                    DoneCallback done) override;

    bool FindTensor(const std::string &key, Tensor &t);

protected:
    void RecvFromRemoteAsync(const Rendezvous::ParsedKey &parsed, const Rendezvous::Args &args,
                             DoneCallback done) override;

    void SameWorkerRecvDone(const Rendezvous::ParsedKey &parsed, const Rendezvous::Args &in_args,
                            const Rendezvous::Args &out_args, const Tensor &in, Tensor *out,
                            StatusCallback done) override;

private:
    ~ZrpcRemoteRendezvous() override
    {
    }

    mutex mu;
    std::unordered_map<std::string, Tensor> tensors;

    WorkerCacheInterface *cache_; // Not owned.
    TF_DISALLOW_COPY_AND_ASSIGN(ZrpcRemoteRendezvous);
};

// RendezvousMgr keeps track of a set of local rendezvous instances.
// All tensors sent by this worker are buffered in a RendezvousMgr
// until the tensor is received.  Each global unique "step_id"
// corresponds to one local rendezvous instance managed by a
// RendezvousMgr.
//
// E.g.,
//   Rendezvous* rendez = worker_env->rendezvous_mgr->Find(0x8935);
//   fork execution of an graph executor using "rendez"  on thread 1;
//   fork execution of another graph executor using "rendez" on thread 2;
//   ...
//   join threads 1 and 2;
//
// In the example above, execution in thread 1 and 2 communicates with
// each other by send/recv operations through the "rend".
//
// Tensors sent and recved through rendezvous managed by this
// RendezvousMgr must have keys generated by Rendezvous::CreateKey.
class ZrpcRendezvousMgr : public BaseRendezvousMgr
{
public:
    explicit ZrpcRendezvousMgr(const WorkerEnv *env);

protected:
    BaseRemoteRendezvous *Create(int64 step_id, const WorkerEnv *worker_env) override;

private:
    // Private cache_ that allows us to reuse WorkerInterface objects.
    std::unique_ptr<WorkerCacheInterface> cache_;

    TF_DISALLOW_COPY_AND_ASSIGN(ZrpcRendezvousMgr);
};

} // end namespace tensorflow

#endif // TENSORFLOW_CORE_DISTRIBUTED_RUNTIME_RPC_RPC_RENDEZVOUS_MGR_H_