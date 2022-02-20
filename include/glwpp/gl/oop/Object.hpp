#pragma once

#include <atomic>
#include <iostream>

#include "glwpp/ctx/Context.hpp"
#include "glwpp/gl/types.hpp"
#include "glwpp/utils/Vop.hpp"
#include "glwpp/utils/Ptr.hpp"

namespace glwpp::gl {
    class CtxObject;
}

namespace glwpp {

class Object {
public:
    std::shared_future<bool> getId(Ptr<gl::UInt> dst) const;
    wptr<Context> getContext() const;

protected:
    template<class I, class ... Args>
    Object(const wptr<Context>& ctx, const I& init, const Vop<Args>&... args) :
        _ctx(ctx){
        _execute(ctx, &Object::_init<I, Args...>, Ptr<gl::CtxObject>(_gl), Vop<I>(init), args...);
    };
    Object(const Object& other):
        _ctx(other._ctx),
        _gl(other._gl){
    }
    virtual ~Object() = 0;

    template<class T>
    Ptr<T> _getPtr(){
        return std::dynamic_pointer_cast<T>(_gl);
    };

    template<class T>
    const Ptr<T> _getPtr() const {
        return std::dynamic_pointer_cast<T>(_gl);
    };

    template<class T>
    Vop<T> _getVop(){
        return std::dynamic_pointer_cast<T>(_gl);
    };

    template<class T>
    const Vop<T> _getVop() const {
        return std::dynamic_pointer_cast<T>(_gl);
    };

    template<class F, class ... Args>
    static std::shared_future<bool> _execute(wptr<Context> weak_ctx,
                                             const F& func, const Args&... args){
        auto ctx = weak_ctx.lock();
        if (!ctx){
            return _getFalseFuture();
        }

        if (std::this_thread::get_id() == ctx->getThreadId()){
            std::apply(func, _unpackArgs(std::make_tuple(args...)));
            return _getTrueFuture();
        } else {
            return ctx->onRun.push([func, packed = std::make_tuple(args...)](){
                std::apply(func, _unpackArgs(packed));
            });
        }
    }

    template<class T, auto M, class R, class ... Args>
    std::shared_future<bool> _getFromMethod(Ptr<R> dst, const Args&... args){
        static auto func = [](T* gl, R* dst, auto... args){
            *dst = (gl->*M)(args...);
        };
        return _execute(_ctx, func, _getPtr<T>(), dst, args...);
    }

    template<class T, auto M, class R, class ... Args>
    std::shared_future<bool> _getFromMethod(Ptr<R> dst, const Args&... args) const {
        static auto func = [](const T* gl, R* dst, auto... args){
            *dst = (gl->*M)(args...);
        };
        return _execute(_ctx, func, _getPtr<T>(), dst, args...);
    }

    template<class T, auto M, class ... Args>
    std::shared_future<bool> _callMethod(const Args&... args){
        static auto func = [](T* gl, auto... args){
            (gl->*M)(args...);
        };
        return _execute(_ctx, func, _getPtr<T>(), args...);
    }

    template<class T, auto M, class ... Args>
    std::shared_future<bool> _callMethod(const Args&... args) const {
        static auto func = [](const T* gl, auto... args){
            (gl->*M)(args...);
        };
        return _execute(_ctx, func, _getPtr<T>(), args...);
    }
    
    template<class ... ArgsIn>
    static auto _unpackArgs(const std::tuple<ArgsIn...>& args){
        static auto f = [](auto arg){
            using full_type = decltype(arg);

            if constexpr (is_vop<full_type>::value){
                return arg.getVal();
            } else if constexpr (is_ptr<full_type>::value){
                return arg.getPtr();
            } else {
                return arg;
            }
        };
        return std::apply([](auto... x){return std::make_tuple(f(x)...);} , args);
    }

private:
    sptr<gl::CtxObject> _gl;
    wptr<Context> _ctx;

    template<class F, class ... Args>
    static void _init(gl::CtxObject* dst, const F& init, const Args&... args){
        *dst = init(args...);
    }

    static std::future<bool> _getTrueFuture(){
        std::promise<bool> p;
        auto f = p.get_future();
        p.set_value(true);
        return f;
    }

    static std::future<bool> _getFalseFuture(){
        std::promise<bool> p;
        auto f = p.get_future();
        p.set_value(false);
        return f;
    }
};

inline Object::~Object(){
    auto locked_ctx = _ctx.lock();
    if (locked_ctx && std::this_thread::get_id() != locked_ctx->getThreadId() && _gl.use_count() <= 1){
        auto gl = _gl;
        _gl.reset();
        locked_ctx->onRun.push([gl](){});
    }
};

} // namespace glwpp