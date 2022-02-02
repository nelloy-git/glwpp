#pragma once

#include <atomic>
#include <iostream>

#include "glwpp/ctx/Context.hpp"
#include "glwpp/gl/types.hpp"
#include "glwpp/utils/Ptr.hpp"

namespace glwpp {

class ContextData {
public:
    template<class N, class D, class ... Args>
    ContextData(wptr<Context> ctx, const N& init, const D& del, const Args&... args) :
        _id(new gl::UInt, del),
        _ctx(ctx){
        _lockCtx()->onRun.push([id = _id, init, args...](){
            *id = init(args...);
        });
    };
    ContextData(const ContextData&) = delete;
    ContextData(const ContextData&& other) : _id(other._id), _ctx(other._ctx){};
    virtual ~ContextData(){
        auto id = _id;
        _id.reset();
        _lockCtx()->onRun.push([id](){});
    };

    gl::UInt id() const {return *_id;}
    wptr<Context> ctx() const {return _ctx;}

protected:
    // Do not save ptr outside of gl context. 
    sptr<const gl::UInt> _idPtr() const {return _id;}

    static sptr<Context> _lockCtx(wptr<Context> ctx){
        auto locked_ctx = ctx.lock();
        if (!locked_ctx){
            throw std::runtime_error("Context do not exist");
        }
        return locked_ctx;
    }

    sptr<Context> _lockCtx() const {
        return _lockCtx(_ctx);
    }

    template<class ... Args>
    static void _clear(wptr<Context> ctx, const sptr<Args>&... args){
        _lockCtx(ctx)->onRunEnd.push([args...](){});
    }

    template<class ... Args>
    void _clear(const sptr<Args>&... args) const {
        _clear(_ctx, args...);
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

} // namespace glwpp