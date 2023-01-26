#pragma once

#include "Context.hpp"
#include "utils/TState.hpp"
#include "utils/Value.hpp"

namespace glwpp {

template<typename T>
class CtxObj : virtual public std::enable_shared_from_this<T> {
    template<TState IsCtx>
    class CtxPtr;

public:
    struct IsCtxTrue{};
    struct IsCtxFalse{};
    struct IsCtxUnknown{};

    template<TState IsCtx>
    using IsCtxFlag = std::conditional_t<(IsCtx == TState::True), IsCtxTrue,
                      std::conditional_t<(IsCtx == TState::False), IsCtxFalse,
                      IsCtxUnknown>>;

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
    virtual ~CtxObj() = 0;

    template<TState IsCtx>
    inline CtxPtr<IsCtx> ctx() const;

    template<TState IsCtx, typename F, typename... Args>
    inline auto call(F&& func, Args&&... args) const;
    
    template<TState IsCtx, auto T::*M, typename... Args>
    inline auto callMember(Args&&... args);

    template<TState IsCtx, auto T::*M, typename... Args>
    inline auto callMember(Args&&... args) const;

private:

    const std::thread::id _ctx_thread_id;
    const std::weak_ptr<Context> _wctx;
    Context* _p_ctx;

    template<typename F, typename... Args>
    inline auto _callDirect(F&& func, Args&&... args) const;

    template<typename F, typename... Args>
    inline auto _callIndirect(F&& func, Args&&... args) const;

    template<typename R, typename F, typename... Args>
    static inline void _FillPromise(std::promise<R>& promise, Context& ctx, F&& func, Args&&... args);

};



template<typename T>
template<TState IsCtx>
class CtxObj<T>::CtxPtr {
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



template<typename T>
inline CtxObj<T>::CtxObj(Context& ctx) :
    _ctx_thread_id(ctx.getGlThreadId()),
    _wctx(ctx.weak_from_this()),
    _p_ctx(&ctx){
}

template<typename T>
inline CtxObj<T>::~CtxObj(){
}

template<typename T>
template<TState IsCtx>
inline CtxObj<T>::CtxPtr<IsCtx> CtxObj<T>::ctx() const {
    if constexpr (IsCtx == TState::True){
        return CtxPtr<IsCtx>(_p_ctx);
    } else {
        auto ctx = _wctx.lock();
        if (!ctx){throw std::runtime_error("Context is destroyed");}
        return CtxPtr<IsCtx>(ctx);
    }
}

template<typename T>
template<TState IsCtx, typename F, typename... Args>
inline auto CtxObj<T>::call(F&& func, Args&&... args) const {
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
    
template<typename T>
template<TState IsCtx, auto T::*M, typename... Args>
inline auto CtxObj<T>::callMember(Args&&... args){
    static constexpr auto F = [](Context& ctx, const std::shared_ptr<T>& ctx_obj, auto&&... args){
        constexpr bool need_context = std::is_invocable_v<decltype(M), T&, Context&, decltype(GetValuable(std::forward<decltype(args)>(args)))...>;
        if constexpr (need_context){
            return (ctx_obj.get()->*M)(ctx, GetValuable(std::forward<decltype(args)>(args))...);
        } else {
            return (ctx_obj.get()->*M)(GetValuable(std::forward<decltype(args)>(args))...);
        }
    };
    return call<IsCtx>(F, this->shared_from_this(), std::forward<Args>(args)...);
}

template<typename T>
template<TState IsCtx, auto T::*M, typename... Args>
inline auto CtxObj<T>::callMember(Args&&... args) const {
    static constexpr auto F = [](Context& ctx, const std::shared_ptr<const T>& ctx_obj, auto&&... args){
        constexpr bool need_context = std::is_invocable_v<decltype(M), const T&, Context&, decltype(GetValuable(std::forward<decltype(args)>(args)))...>;
        if constexpr (need_context){
            return (ctx_obj.get()->*M)(ctx, GetValuable(std::forward<decltype(args)>(args))...);
        } else {
            return (ctx_obj.get()->*M)(GetValuable(std::forward<decltype(args)>(args))...);
        }
    };
    return call<IsCtx>(F, this->shared_from_this(), std::forward<Args>(args)...);
}

template<typename T>
template<typename F, typename... Args>
inline auto CtxObj<T>::_callDirect(F&& func, Args&&... args) const {
    return func(*_p_ctx, GetValuable(args)...);
}

template<typename T>
template<typename F, typename... Args>
inline auto CtxObj<T>::_callIndirect(F&& func, Args&&... args) const {
    auto ctx = _wctx.lock();
    if (!ctx){throw std::runtime_error("Context is destroyed");}

    if constexpr (WithCtx<F, Args...>){
        using R = ResWithCtx<F, Args...>;
        auto promise = std::make_shared<std::promise<R>>();
        auto future = promise->get_future();
        ctx->event_on_run_gl.add(Context::PRIORITY_DEFAULT,
            [promise, func, ...args = Value(std::forward<Args>(args))](Context& ctx, const Context::time&){
                _FillPromise(*promise, ctx, func, GetValuable(args)...);
                return false;
            }, SrcLoc{}
        );
        return Value(std::move(future));
    } else if constexpr(NoCtx<F, Args...>){
        using R = ResNoCtx<F, Args...>;
        auto promise = std::make_shared<std::promise<R>>();
        auto future = promise->get_future();
        ctx->event_on_run_gl.add(Context::PRIORITY_DEFAULT,
            [promise, func, ...args = Value(std::forward<Args>(args))](Context& ctx, const Context::time&){
                _FillPromise(*promise, ctx, func, GetValuable(args)...);
                return false;
            }, SrcLoc{}
        );
        return Value(std::move(future));
    } else {
        static_assert("Is not callable");
    }
}

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