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
    void getId(Ptr<gl::UInt> dst) const;
    wptr<Context> getContext() const;

protected:
    template<class I, class ... Args>
    Object(const wptr<Context>& ctx, const I& init, const Vop<Args>&... args) :
        _ctx(ctx){
        using T = std::invoke_result_t<I, Args...>;
        _gl = make_sptr<T>(Dummy{});
        _execute<&Object::_init<I, Args...>>(ctx, Ptr<gl::CtxObject>(_gl), Vop<I>(init), args...);
    };
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

    template<auto F, class ... Args>
    static inline bool _execute(wptr<Context> weak_ctx, const Args&... args){
        auto ctx = weak_ctx.lock();
        if (!ctx) return false;

        if (ctx->getThreadId() == std::this_thread::get_id()){
            std::apply(F, _unpackArgs(std::make_tuple(args...)));
        } else {
            ctx->onRun.push([packed = std::make_tuple(args...)](){
                std::apply(F, _unpackArgs(packed));
            });
        }
        return true;
    }

    template<class T, auto M, class ... Args>
    inline bool _executeMethod(const Args&... args){
        static constexpr auto F = [](T* instance, auto&&... args){
            (instance->*M)(args...);
        };
        return _execute<F>(_ctx, _getPtr<T>(), args...);
    }

    template<class T, auto M, class ... Args>
    inline bool _executeMethod(const Args&... args) const {
        static constexpr auto F = [](const T* instance, auto&&... args){
            (instance->*M)(args...);
        };
        return _execute<F>(_ctx, _getPtr<T>(), args...);
    }

    template<class T, auto M, class R, class ... Args>
    inline bool _executeGetter(Ptr<R>& dst, const Args&... args){
        static constexpr auto F = []<class ... ArgsM>(T* instance, R* dst, ArgsM&& ... args){
            *dst = (instance->*M)(std::forward<ArgsM>(args)...);
        };
        return _execute<F>(_ctx, _getPtr<T>(), dst, args...);
    }

    template<class T, auto M, class R, class ... Args>
    inline bool _executeGetter(Ptr<R>& dst, const Args&... args) const {
        static constexpr auto F = []<class ... ArgsM>(const T* instance, R* dst, ArgsM&& ... args){
            *dst = (instance->*M)(std::forward<ArgsM>(args)...);
        };
        return _execute<F>(_ctx, _getPtr<T>(), dst, args...);
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
        return std::apply([](auto... args){return std::make_tuple(f(args)...);} , args);
    }

private:
    sptr<gl::CtxObject> _gl;
    wptr<Context> _ctx;

    template<class F, class ... Args>
    static void _init(gl::CtxObject* dst, const F& init, const Args&... args){
        *dst = init(args...);
    }
};

inline Object::~Object(){
    auto locked_ctx = _ctx.lock();

    if (locked_ctx && locked_ctx->getThreadId() != std::this_thread::get_id()){
        locked_ctx->onRun.push([gl = std::move(_gl)](){});
    }
};

} // namespace glwpp