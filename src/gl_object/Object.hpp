#pragma once

#include "Context.hpp"

namespace glwpp {

namespace GL {

class Object {
public:
    Object(const std::shared_ptr<Context>& ctx, const Uint& id) :
        _wctx(ctx),
        _p_ctx(ctx.get()),
        _ctx_thread_id(ctx->getGlThreadId()),
        _id(id){
    }
    Object(const Object&) = delete;
    Object(const Object&&) = delete;
    ~Object(){};

    const Uint& id() const {
        return _id;
    }

protected:
    template<auto F, typename ... Args>
    auto _callGL(Args... args){
        if (std::this_thread::get_id() == _ctx_thread_id){
            return (_p_ctx->gl<Context::IsGlThread::True>().*F)(args...);
        } else {
            auto ctx = _wctx.lock();
            if (!ctx){
                throw "Context destroyed";
            }
            return (ctx->gl<Context::IsGlThread::False>().*F)(args...);
        }
    }

    auto _callGLCustom(auto func, auto&&... args){
        std::shared_ptr<Context> ctx;
        Gl* gl;

        if (std::this_thread::get_id() == _ctx_thread_id){
            gl = &_p_ctx->gl<Context::IsGlThread::True>();
        } else {
            ctx = _wctx.lock();
            if (!ctx){
                throw "Context destroyed";
            }
            gl = &ctx->gl<Context::IsGlThread::False>();
        }

        return gl->call(func, args...);
    }

private:
    std::weak_ptr<Context> _wctx;
    Context* _p_ctx;
    std::thread::id _ctx_thread_id;
    Uint _id;

};

} // namespace GL

} // namespace glwpp