#pragma once

#include <atomic>
#include <iostream>

#include "glwpp/ctx/Context.hpp"
#include "glwpp/gl/types.hpp"
#include "glwpp/utils/Val.hpp"
#include "glwpp/utils/Ptr.hpp"

namespace glwpp::gl {
    class CtxObject;
}

namespace glwpp {

class Object {
public:
    void getId(Ptr<gl::UInt> dst) const;
    wptr<Context> getWCtx() const;

    template<auto F, typename ... Args>
    bool executeCustomCode(const Args&... args){
        return _execute<F>(_ctx, args...);
    };

protected:
    template<typename I, typename ... Args>
    Object(const wptr<Context>& ctx, const I& init, const Val<Args>&... args) :
        _ctx(ctx){
        using T = std::invoke_result_t<I, Args...>;
        _gl = make_sptr<T>(EmptyObj{});
        _execute<&Object::_init<I, Args...>>(ctx, Ptr<gl::CtxObject>(_gl), Val<I>(init), args...);
    };
    virtual ~Object() = 0;

    template<typename T>
    Ptr<T> _getPtr(){
        return std::dynamic_pointer_cast<T>(_gl);
    };

    template<typename T>
    const Ptr<T> _getPtr() const {
        return std::dynamic_pointer_cast<T>(_gl);
    };

    template<typename T>
    Val<T> _getVop(){
        return Val<T>(std::dynamic_pointer_cast<T>(_gl));
    };

    template<typename T>
    const Val<T> _getVop() const {
        return Val<T>(std::dynamic_pointer_cast<T>(_gl));
    };

    template<auto F, typename ... Args>
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

    template<typename T, auto M, typename ... Args>
    inline bool _executeMethod(const Args&... args){
        static constexpr auto F = [](T* instance, auto&&... args){
            (instance->*M)(args...);
        };
        return _execute<F>(_ctx, _getPtr<T>(), args...);
    }

    template<typename T, auto M, typename ... Args>
    inline bool _executeMethod(const Args&... args) const {
        static constexpr auto F = [](const T* instance, auto&&... args){
            (instance->*M)(args...);
        };
        return _execute<F>(_ctx, _getPtr<T>(), args...);
    }

    template<typename T, auto M, typename R, typename ... Args>
    inline bool _executeGetter(Ptr<R>& dst, const Args&... args){
        static constexpr auto F = []<typename ... ArgsM>(T* instance, R* dst, ArgsM&& ... args){
            *dst = (instance->*M)(std::forward<ArgsM>(args)...);
        };
        return _execute<F>(_ctx, _getPtr<T>(), dst, args...);
    }

    template<typename T, auto M, typename R, typename ... Args>
    inline bool _executeGetter(Ptr<R>& dst, const Args&... args) const {
        static constexpr auto F = []<typename ... ArgsM>(const T* instance, R* dst, ArgsM&& ... args){
            *dst = (instance->*M)(std::forward<ArgsM>(args)...);
        };
        return _execute<F>(_ctx, _getPtr<T>(), dst, args...);
    }
    
    template<typename ... ArgsIn>
    static auto _unpackArgs(const std::tuple<ArgsIn...>& args){
        static auto f = [](auto arg){
            using full_type = decltype(arg);

            if constexpr (is_val<full_type>::value){
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

    template<typename F, typename ... Args>
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