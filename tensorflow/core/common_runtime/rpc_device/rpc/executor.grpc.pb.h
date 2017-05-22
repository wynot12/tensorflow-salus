// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: executor.proto
#ifndef GRPC_executor_2eproto__INCLUDED
#define GRPC_executor_2eproto__INCLUDED

#include "executor.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/proto_utils.h>
#include <grpc++/impl/codegen/rpc_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/status.h>
#include <grpc++/impl/codegen/stub_options.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace executor {

class IExecEngine final {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status run(::grpc::ClientContext* context, const ::executor::RunRequest& request, ::executor::RunResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::executor::RunResponse>> Asyncrun(::grpc::ClientContext* context, const ::executor::RunRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::executor::RunResponse>>(AsyncrunRaw(context, request, cq));
    }
    virtual ::grpc::Status allocate(::grpc::ClientContext* context, const ::executor::AllocRequest& request, ::executor::AllocResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::executor::AllocResponse>> Asyncallocate(::grpc::ClientContext* context, const ::executor::AllocRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::executor::AllocResponse>>(AsyncallocateRaw(context, request, cq));
    }
    virtual ::grpc::Status deallocate(::grpc::ClientContext* context, const ::executor::DeallocRequest& request, ::executor::DeallocResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::executor::DeallocResponse>> Asyncdeallocate(::grpc::ClientContext* context, const ::executor::DeallocRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::executor::DeallocResponse>>(AsyncdeallocateRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::executor::RunResponse>* AsyncrunRaw(::grpc::ClientContext* context, const ::executor::RunRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::executor::AllocResponse>* AsyncallocateRaw(::grpc::ClientContext* context, const ::executor::AllocRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::executor::DeallocResponse>* AsyncdeallocateRaw(::grpc::ClientContext* context, const ::executor::DeallocRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status run(::grpc::ClientContext* context, const ::executor::RunRequest& request, ::executor::RunResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::executor::RunResponse>> Asyncrun(::grpc::ClientContext* context, const ::executor::RunRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::executor::RunResponse>>(AsyncrunRaw(context, request, cq));
    }
    ::grpc::Status allocate(::grpc::ClientContext* context, const ::executor::AllocRequest& request, ::executor::AllocResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::executor::AllocResponse>> Asyncallocate(::grpc::ClientContext* context, const ::executor::AllocRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::executor::AllocResponse>>(AsyncallocateRaw(context, request, cq));
    }
    ::grpc::Status deallocate(::grpc::ClientContext* context, const ::executor::DeallocRequest& request, ::executor::DeallocResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::executor::DeallocResponse>> Asyncdeallocate(::grpc::ClientContext* context, const ::executor::DeallocRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::executor::DeallocResponse>>(AsyncdeallocateRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< ::executor::RunResponse>* AsyncrunRaw(::grpc::ClientContext* context, const ::executor::RunRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::executor::AllocResponse>* AsyncallocateRaw(::grpc::ClientContext* context, const ::executor::AllocRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::executor::DeallocResponse>* AsyncdeallocateRaw(::grpc::ClientContext* context, const ::executor::DeallocRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::RpcMethod rpcmethod_run_;
    const ::grpc::RpcMethod rpcmethod_allocate_;
    const ::grpc::RpcMethod rpcmethod_deallocate_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status run(::grpc::ServerContext* context, const ::executor::RunRequest* request, ::executor::RunResponse* response);
    virtual ::grpc::Status allocate(::grpc::ServerContext* context, const ::executor::AllocRequest* request, ::executor::AllocResponse* response);
    virtual ::grpc::Status deallocate(::grpc::ServerContext* context, const ::executor::DeallocRequest* request, ::executor::DeallocResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_run : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_run() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_run() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status run(::grpc::ServerContext* context, const ::executor::RunRequest* request, ::executor::RunResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestrun(::grpc::ServerContext* context, ::executor::RunRequest* request, ::grpc::ServerAsyncResponseWriter< ::executor::RunResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_allocate : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_allocate() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_allocate() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status allocate(::grpc::ServerContext* context, const ::executor::AllocRequest* request, ::executor::AllocResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestallocate(::grpc::ServerContext* context, ::executor::AllocRequest* request, ::grpc::ServerAsyncResponseWriter< ::executor::AllocResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_deallocate : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_deallocate() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_deallocate() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status deallocate(::grpc::ServerContext* context, const ::executor::DeallocRequest* request, ::executor::DeallocResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestdeallocate(::grpc::ServerContext* context, ::executor::DeallocRequest* request, ::grpc::ServerAsyncResponseWriter< ::executor::DeallocResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_run<WithAsyncMethod_allocate<WithAsyncMethod_deallocate<Service > > > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_run : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_run() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_run() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status run(::grpc::ServerContext* context, const ::executor::RunRequest* request, ::executor::RunResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_allocate : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_allocate() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_allocate() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status allocate(::grpc::ServerContext* context, const ::executor::AllocRequest* request, ::executor::AllocResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_deallocate : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_deallocate() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_deallocate() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status deallocate(::grpc::ServerContext* context, const ::executor::DeallocRequest* request, ::executor::DeallocResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_run : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_run() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::StreamedUnaryHandler< ::executor::RunRequest, ::executor::RunResponse>(std::bind(&WithStreamedUnaryMethod_run<BaseClass>::Streamedrun, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_run() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status run(::grpc::ServerContext* context, const ::executor::RunRequest* request, ::executor::RunResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status Streamedrun(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::executor::RunRequest,::executor::RunResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_allocate : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_allocate() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::StreamedUnaryHandler< ::executor::AllocRequest, ::executor::AllocResponse>(std::bind(&WithStreamedUnaryMethod_allocate<BaseClass>::Streamedallocate, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_allocate() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status allocate(::grpc::ServerContext* context, const ::executor::AllocRequest* request, ::executor::AllocResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status Streamedallocate(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::executor::AllocRequest,::executor::AllocResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_deallocate : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_deallocate() {
      ::grpc::Service::MarkMethodStreamed(2,
        new ::grpc::StreamedUnaryHandler< ::executor::DeallocRequest, ::executor::DeallocResponse>(std::bind(&WithStreamedUnaryMethod_deallocate<BaseClass>::Streameddeallocate, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_deallocate() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status deallocate(::grpc::ServerContext* context, const ::executor::DeallocRequest* request, ::executor::DeallocResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status Streameddeallocate(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::executor::DeallocRequest,::executor::DeallocResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_run<WithStreamedUnaryMethod_allocate<WithStreamedUnaryMethod_deallocate<Service > > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_run<WithStreamedUnaryMethod_allocate<WithStreamedUnaryMethod_deallocate<Service > > > StreamedService;
};

}  // namespace executor


#endif  // GRPC_executor_2eproto__INCLUDED
