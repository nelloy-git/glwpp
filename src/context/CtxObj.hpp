#pragma once

#include "Context.hpp"
#include "utils/TState.hpp"
#include "utils/Value.hpp"

namespace glwpp {

class Context;

template<typename T>
class CtxObjRef {
public:
    CtxObjRef(auto&&... args) :
        _obj(new T(std::forward<decltype(args)>(args)...)){
    }
    
    CtxObjRef(const std::shared_ptr<T>& sp) :
        _obj(sp){
    }

    CtxObjRef(const CtxObjRef& other) = default;
    CtxObjRef(CtxObjRef&& other) = default;
    virtual ~CtxObjRef(){};
    
    inline T* operator->(){return _obj.get();};
    inline const T* operator->() const {return _obj.get();};

protected:
    std::shared_ptr<T> _obj;
};

template<typename T>
class CtxObj : virtual public std::enable_shared_from_this<T> {
public:
    template<typename F, typename... Args>
    static constexpr bool WithCtx = std::is_invocable_v<F, Context&, std::invoke_result_t<decltype(&GetValuable<Args>), Args>...>;
    template<typename F, typename... Args>
    static constexpr bool NoCtx = std::is_invocable_v<F, std::invoke_result_t<decltype(&GetValuable<Args>), Args>...>;

    template<typename F, typename... Args>
    using ResWithCtx = std::invoke_result_t<F, Context&, std::invoke_result_t<decltype(&GetValuable<Args>), Args>...>;
    template<typename F, typename... Args>
    using ResNoCtx = std::invoke_result_t<F, std::invoke_result_t<decltype(&GetValuable<Args>), Args>...>;
    template<TState IsCtx, typename F, typename... Args>
    using CallResWithCtx = std::conditional_t<(IsCtx == TState::True), ResWithCtx<F, Args...>, Value<std::future<ResWithCtx<F, Args...>>>>;
    template<TState IsCtx, typename F, typename... Args>
    using CallResNoCtx = std::conditional_t<(IsCtx == TState::True), ResNoCtx<F, Args...>, Value<std::future<ResNoCtx<F, Args...>>>>;

    CtxObj(Context& ctx);
    CtxObj(const CtxObj&) = delete;
    CtxObj(CtxObj&&) = delete;
    virtual ~CtxObj();

    template<TState IsCtx>
    inline auto ctx() const {
        if constexpr (IsCtx == TState::True){
            return CtxPtr<IsCtx>(_p_ctx);
        } else {
            auto ctx = _wctx.lock();
            if (!ctx){throw std::runtime_error("Context is destroyed");}
            return CtxPtr<IsCtx>(ctx);
        }
    }

    template<TState IsCtx, typename F, typename... Args>
    inline auto call(F&& func, Args&&... args) const {
        if constexpr (IsCtx == TState::True){
            return _callDirect(std::forward<F>(func), std::forward<Args>(args)...);
        }
        
        if constexpr (IsCtx == TState::False){
            return _callIndirect(std::forward<F>(func), std::forward<Args>(args)...);
        }

        if constexpr (IsCtx == TState::Unknown){
            using R = ResWithCtx<F, Args...>;

            if (std::this_thread::get_id() == _ctx_thread_id){
                std::promise<R> promise;
                _FillPromise(promise, *_p_ctx, std::forward<F>(func), std::forward<Args>(args)...);
                return Value(std::move(promise.get_future()));
            } else {
                return _callIndirect(std::forward<F>(func), std::forward<Args>(args)...);
            }
        }
    }
    
    // template<auto GLapi::*M, IsGlThread is_gl>
    // auto callGLapi(auto&&... args) const;

    template<TState IsCtx, auto T::*M>
    auto callMember(auto&&... args){
        static constexpr auto F = [](Context& ctx, const std::shared_ptr<T>& ctx_obj, auto&&... args){
            constexpr bool need_context = std::is_invocable_v<decltype(M), T&, Context&, decltype(GetValuable(std::forward<decltype(args)>(args)))...>;
            if constexpr (need_context){
                return (ctx_obj.get()->*M)(ctx, GetValuable(std::forward<decltype(args)>(args))...);
            } else {
                return (ctx_obj.get()->*M)(GetValuable(std::forward<decltype(args)>(args))...);
            }
        };
        return call<IsCtx>(F, this->shared_from_this(), std::forward<decltype(args)>(args)...);
    }

    template<TState IsCtx, auto T::*M>
    auto callMember(auto&&... args) const {
        static constexpr auto F = [](Context& ctx, const std::shared_ptr<const T>& ctx_obj, auto&&... args){
            constexpr bool need_context = std::is_invocable_v<decltype(M), const T&, Context&, decltype(GetValuable(std::forward<decltype(args)>(args)))...>;
            if constexpr (need_context){
                return (ctx_obj.get()->*M)(ctx, GetValuable(std::forward<decltype(args)>(args))...);
            } else {
                return (ctx_obj.get()->*M)(GetValuable(std::forward<decltype(args)>(args))...);
            }
        };
        return call<IsCtx>(F, this->shared_from_this(), std::forward<decltype(args)>(args)...);
    }

private:
    template<TState IsCtx>
    class CtxPtr {
        using Ptr = std::conditional_t<(IsCtx == TState::True), Context*, std::shared_ptr<Context>>;
    public:
        CtxPtr(Ptr p_ctx) : _ptr(p_ctx){};
        ~CtxPtr(){};

        Context* operator->(){
            if constexpr (IsCtx == TState::True){return _ptr;}
            else {return _ptr.get();}
        }

    private:
        Ptr _ptr;
    };

    const std::thread::id _ctx_thread_id;
    const std::weak_ptr<Context> _wctx;
    Context* _p_ctx;

    template<typename F, typename... Args>
    inline auto _callDirect(F&& func, Args&&... args) const {
        return func(*_p_ctx, GetValuable(args)...);
    }

    template<typename F, typename... Args>
    inline auto _callIndirect(F&& func, Args&&... args) const {
        auto ctx = _wctx.lock();
        if (!ctx){throw std::runtime_error("Context is destroyed");}

        if constexpr (WithCtx<F, Args...>){
            using R = ResWithCtx<F, Args...>;
            auto promise = new std::promise<R>();
            auto future = promise->get_future();
            ctx->event_on_run_gl.add(Context::PRIORITY_DEFAULT,
                [promise, func, ...args = Value(std::forward<Args>(args))](Context& ctx, const Context::time&){
                    _FillPromise(*promise, ctx, func, GetValuable(args)...);
                    delete promise;
                    return false;
                }, SrcLoc{}
            );
            return Value(std::move(future));
        } else if constexpr(NoCtx<F, Args...>){
            using R = ResNoCtx<F, Args...>;
            auto promise = new std::promise<R>();
            auto future = promise->get_future();
            ctx->event_on_run_gl.add(Context::PRIORITY_DEFAULT,
                [promise, func, ...args = Value(std::forward<Args>(args))](Context& ctx, const Context::time&){
                    _FillPromise(*promise, ctx, func, GetValuable(args)...);
                    delete promise;
                    return false;
                }, SrcLoc{}
            );
            return Value(std::move(future));
        } else {
            static_assert("Is not callable");
        }

    }

    // template<auto F, IsGlThread is_gl, typename R>
    // inline auto _callKnownResult(auto&&... args) const;
    
    // template<auto F, typename R>
    // inline auto _callDirect(auto&&... args) const;
    
    // template<auto F, typename R>
    // inline auto _callIndirect(auto&&... args) const;

    // template<auto F, typename R>
    // inline auto _callWithRunEvent(Context& ctx, auto&&... args) const;

    template<typename R, typename F, typename... Args>
    static inline void _FillPromise(std::promise<R>& promise, Context& ctx, F&& func, Args&&... args);

};

template<typename T>
inline CtxObj<T>::CtxObj(Context& ctx) :
    _ctx_thread_id(ctx.getGlThreadId()),
    _wctx(ctx.weak_from_this()),
    _p_ctx(&ctx){
}

template<typename T>
inline CtxObj<T>::~CtxObj(){
}

// template<typename T>
// template<IsGlThread is_gl, typename F, typename... Args, std::enable_if_t<CtxObj<T>::WithCtx<F, Args...>, bool>>
// auto CtxObj<T>::call(auto&& F, Args&&... args) const {
//     constexpr bool need_context = std::is_invocable<decltype(F), Context&, decltype(GetValuable(std::forward<decltype(args)>(args)))...>;
//     constexpr bool do_not_need_context = std::is_invocable_v<decltype(F), decltype(GetValuable(std::forward<decltype(args)>(args)))...>;
//     static_assert(need_context || do_not_need_context, "R F(Context&, Args&&... args) || R F(Args&&... args)");

//     if constexpr (need_context){
//         using R = std::invoke_result_t<decltype(F), Context&, decltype(GetValuable(std::forward<decltype(args)>(args)))...>;
//         return _callKnownResult<F, is_gl, R>(std::forward<decltype(args)>(args)...);
//     } else {
//         using R = std::invoke_result_t<decltype(F), decltype(GetValuable(std::forward<decltype(args)>(args)))...>;
//         return _callKnownResult<F, is_gl, R>(std::forward<decltype(args)>(args)...);
//     }
// }

// template<typename T>
// template<auto GLapi::*M, IsGlThread is_gl>
// auto CtxObj<T>::callGLapi(auto&&... args) const {
//     static constexpr auto F = [](Context& ctx, auto&&... args){
//         return (ctx.gl.*M)(GetValuable(std::forward<decltype(args)>(args))...);
//     };
//     return call<F, is_gl>(std::forward<decltype(args)>(args)...);
// }

// template<typename T>
// template<auto T::*M, TState IsCtx>
// auto CtxObj<T>::callMember(auto&&... args){
//     if constexpr (is_gl){

//     }

//     static constexpr auto F = [](Context& ctx, const std::shared_ptr<T>& ctx_obj, auto&&... args){
//         constexpr bool need_context = std::is_invocable_v<decltype(M), T&, Context&, decltype(GetValuable(std::forward<decltype(args)>(args)))...>;
//         if constexpr (need_context){
//             return (ctx_obj.get()->*M)(ctx, GetValuable(std::forward<decltype(args)>(args))...);
//         } else {
//             return (ctx_obj.get()->*M)(GetValuable(std::forward<decltype(args)>(args))...);
//         }
//     };
//     return call<F, is_gl>(this->shared_from_this(), std::forward<decltype(args)>(args)...);
// }

// template<typename T>
// template<auto T::*M, IsGlThread is_gl>
// auto CtxObj<T>::callMember(auto&&... args) const {
//     static constexpr auto F = [](Context& ctx, const std::shared_ptr<const T>& ctx_obj, auto&&... args){
//         constexpr bool need_context = std::is_invocable_v<decltype(M), const T&, Context&, decltype(GetValuable(std::forward<decltype(args)>(args)))...>;
//         if constexpr (need_context){
//             return (ctx_obj.get()->*M)(ctx, GetValuable(std::forward<decltype(args)>(args))...);
//         } else {
//             return (ctx_obj.get()->*M)(GetValuable(std::forward<decltype(args)>(args))...);
//         }
//     };
//     return call<F, is_gl>(this->shared_from_this(), std::forward<decltype(args)>(args)...);
// }

// template<typename T>
// template<auto F, IsGlThread is_gl, typename R>
// inline Value<std::future<R>> CtxObj<T>::_callKnownResult(auto&&... args) const {
//     if constexpr (is_gl == IsGlThread::True){
//         return _callDirect<F, R>(std::forward<decltype(args)>(args)...);
//     }
    
//     if constexpr (is_gl == IsGlThread::False){
//         return _callIndirect<F, R>(std::forward<decltype(args)>(args)...);
//     }
    
//     if constexpr (is_gl == IsGlThread::Unknown){
//         if (std::this_thread::get_id() == _ctx_thread_id){
//             return _callDirect<F, R>(std::forward<decltype(args)>(args)...);
//         } else {
//             return _callIndirect<F, R>(std::forward<decltype(args)>(args)...);
//         }
//     }
// }

// template<typename T>
// template<auto F, typename R>
// inline auto CtxObj<T>::_callDirect(auto&&... args) const {
//     std::promise<R> promise;
//     _FillPromise<F>(promise, *_p_ctx, std::forward<decltype(args)>(args)...);
//     return Value(std::move(promise.get_future()));
// }

// template<typename T>
// template<auto F, typename R>
// inline auto CtxObj<T>::_callIndirect(auto&&... args) const {
//     auto ctx = _wctx.lock();
//     if (!ctx){
//         throw std::runtime_error("Conetext is destroyed");
//     }
//     return _callWithRunEvent<F, R>(*ctx, Value(std::forward<decltype(args)>(args))...);
// }

// template<typename T>
// template<auto F, typename R>
// inline auto CtxObj<T>::_callWithRunEvent(Context& ctx, auto&&... args) const {
//     static_assert((detail::is_instance_v<decltype(args), Value> && ...), "all arguments must be glwpp::Value<T>");

//     auto promise = std::make_shared<std::promise<R>>();
//     ctx.event_on_run_gl.add(Context::PRIORITY_DEFAULT,
//         [promise, args...](Context& ctx, const Context::ms&){
//             _FillPromise<F, R>(*promise, ctx, GetValuable(args)...);
//             return false;
//         }
//     );
//     return Value(promise->get_future());
// }

template<typename T>
template<typename R, typename F, typename... Args>
inline void CtxObj<T>::_FillPromise(std::promise<R>& promise, Context& ctx, F&& func, Args&&... args){
    if constexpr (WithCtx<F, Args...>){
        if constexpr (std::is_same_v<R, void>){
            func(ctx, GetValuable(args)...);
            promise.set_value();
        } else {
            promise.set_value(func(ctx, GetValuable(args)...));
        }
    } else if constexpr(NoCtx<F, Args...>){
        if constexpr (std::is_same_v<R, void>){
            func(GetValuable(args)...);
            promise.set_value();
        } else {
            promise.set_value(func(GetValuable(args)...));
        }
    } else {
        static_assert("Is not callable");
    }
}

} // namespace glwpp