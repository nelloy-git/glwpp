#pragma once

#include <atomic>

#include "glwpp/ctx/Context.hpp"
#include "glwpp/gl/api/types.hpp"
#include "glwpp/utils/Ptr.hpp"

namespace glwpp {

class ContextData {
public:
    template<class N, class D, class ... Args>
    ContextData(wptr<Context> ctx, const N& init, const D& del, const Args&... args) :
        _id(new gl::UInt, del),
        _ctx(ctx){
        _execute(&_initInContext<N, Args...>, _id, init, args...);
    };
    ContextData(const ContextData&) = delete;
    ContextData(const ContextData&& other) : _id(other._id), _ctx(other._ctx){};
    virtual ~ContextData(){
        auto id = _id;
        _id.reset();
        _execute(&_resetPtr, id);
    };

    gl::UInt id() const {return *_id;}
    const sptr<gl::UInt> idPtr() const {return _id;}
    wptr<Context> ctx() const {return _ctx;}

protected:
    template<class F, class ... Args>
    static auto _execute(wptr<Context> ctx, const F& f, const Args&... args){
        auto locked_ctx = ctx.lock();
        if (!locked_ctx){
            throw std::runtime_error("Context do not exist");
        }
        return locked_ctx->onRun.push([f, args...](){
            return f(args...);
        });
    };

    template<class F, class ... Args>
    auto _execute(const F& f, const Args&... args) const {
        return _execute(_ctx, f, args...);
    };

private:
    sptr<gl::UInt> _id;
    wptr<Context> _ctx;

    template<class N, class ... Args>
    static void _initInContext(sptr<gl::UInt> id, const N& init, const Args&... args){
        *id = init(args...);
    }

    static void _resetPtr(sptr<gl::UInt> id){
        id.reset();
    }
};

}