#pragma once

#include <atomic>
#include <iostream>
#include <source_location>

#include "glwpp/ctx/Context.hpp"
#include "glwpp/gl/types.hpp"
#include "glwpp/utils/Ptr.hpp"

namespace glwpp::gl {
    class CtxObject;
}

namespace glwpp {

class Object {
public:
    template<class I, class ... Args>
    Object(const wptr<Context>& ctx, const I& init, const Vop<Args>&... args) :
        _ctx(ctx){
        _gl = make_sptr<sptr<gl::CtxObject>>(nullptr);
        _execute(Object::_init<I, Args...>, init, _gl, args...);
    };
    Object(const Object& other):
        _ctx(other._ctx),
        _gl(other._gl){
    }
    virtual ~Object() = 0;

    std::shared_future<bool> getId(Ptr<gl::UInt> dst) const;
    wptr<Context> getCtx() const;

protected:
    template<class T>
    Ptr<sptr<T>> _getPtr(){
        return std::reinterpret_pointer_cast<sptr<T>>(_gl);
    };

    template<class T>
    Ptr<const sptr<const T>> _getPtr() const {
        return std::reinterpret_pointer_cast<const sptr<const T>>(_gl);
    };
    
    static sptr<Context> _lockCtx(const wptr<Context>& ctx);
    sptr<Context> _lockCtx() const;

    template<class F, class ... Args>
    std::shared_future<bool> _execute(const F& func, const Args&... args) const {
        auto locked = _lockCtx();
        auto packed = std::make_tuple(args...);

        if (std::this_thread::get_id() == locked->getThreadId()){
            std::promise<bool> p;
            auto f = p.get_future();
            p.set_value(true);

            std::apply(func, _unpackArgs(packed));
            return f;
        } else {
            return locked->onRun.push([func, packed](){
                std::apply(func, _unpackArgs(packed));
            });
        }
    }

    template<class T, auto M, class R, class ... Args>
    std::shared_future<bool> _getFromMethod(Ptr<R> dst, const Args&... args){
        static auto func = [](sptr<T>* gl, Ptr<R> dst, auto... args){
            auto raw = gl->get();
            *getPtrValue(dst) = (raw->*M)(args...);
        };
        return _execute(func, _getPtr<T>(), dst, args...);
    }

    template<class T, auto M, class R, class ... Args>
    std::shared_future<bool> _getFromMethod(Ptr<R> dst, const Args&... args) const {
        static auto func = [](const sptr<const T>* gl, Ptr<R> dst, auto... args){
            auto raw = gl->get();
            *getPtrValue(dst) = (raw->*M)(args...);
        };
        return _execute(func, _getPtr<T>(), dst, args...);
    }

    template<class T, auto M, class ... Args>
    std::shared_future<bool> _callMethod(const Args&... args){
        static auto func = [](sptr<T>* gl, auto... args){
            auto raw = gl->get();
            (raw->*M)(args...);
        };
        return _execute(func, _getPtr<T>(), args...);
    }

    template<class T, auto M, class ... Args>
    std::shared_future<bool> _callMethod(const Args&... args) const {
        static auto func = [](const sptr<const T>* gl, auto... args){
            auto raw = gl->get();
            (raw->*M)(args...);
        };
        return _execute(func, _getPtr<T>(), args...);
    }
    
    template<class ... ArgsIn>
    static auto _unpackArgs(const std::tuple<ArgsIn...>& args){
        static auto f = [](auto arg){
            using full_type = decltype(arg);

            if constexpr (is_vop<full_type>::value){
                return getVopValue(arg);
            } else if constexpr (is_ptr<full_type>::value){
                return getPtrValue(arg);
            } else {
                return arg;
            }
        };
        return std::apply([](auto... x){return std::make_tuple(f(x)...);} , args);
    }

private:
    sptr<sptr<gl::CtxObject>> _gl;
    wptr<Context> _ctx;

    template<class F, class ... Args>
    static void _init(const F& init, sptr<sptr<gl::CtxObject>> dst, Args... args){
        *dst = init(args...);
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