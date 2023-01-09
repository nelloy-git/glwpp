#pragma once

#include "Context.hpp"
#include "context/Value.hpp"

namespace glwpp {

template<typename T>
class CtxObj : virtual public std::enable_shared_from_this<T> {
public:
    CtxObj(Context& ctx);
    CtxObj(const CtxObj&) = delete;
    CtxObj(CtxObj&&) = delete;
    virtual ~CtxObj();

    template<auto F, IsGlThread is_gl>
    auto call(auto&&... args) const;
    
    template<auto GLapi::*M, IsGlThread is_gl>
    auto callGLapi(auto&&... args) const;

    template<auto T::*M, IsGlThread is_gl>
    auto callMember(auto&&... args);

    template<auto T::*M, IsGlThread is_gl>
    auto callMember(auto&&... args) const;

private:
    const std::thread::id _ctx_thread_id;
    const std::weak_ptr<Context> _wctx;
    Context* _p_ctx;

    template<auto F, IsGlThread is_gl, typename R>
    inline Value<std::future<R>> _callKnownResult(auto&&... args) const;
    
    template<auto F, typename R>
    inline auto _callDirect(auto&&... args) const;
    
    template<auto F, typename R>
    inline auto _callIndirect(auto&&... args) const;

    template<auto F, typename R>
    inline auto _callWithRunEvent(Context& ctx, auto&&... args) const;

    template<auto F, typename R>
    static inline void _FillPromise(std::promise<R>& promise, Context& ctx, auto&&... args);

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
template<auto F, IsGlThread is_gl>
auto CtxObj<T>::call(auto&&... args) const {
    constexpr bool need_context = std::is_invocable_v<decltype(F), Context&, decltype(GetValuable(std::forward<decltype(args)>(args)))...>;
    constexpr bool do_not_need_context = std::is_invocable_v<decltype(F), decltype(GetValuable(std::forward<decltype(args)>(args)))...>;
    static_assert(need_context || do_not_need_context, "R F(Context&, Args&&... args) || R F(Args&&... args)");

    if constexpr (need_context){
        using R = std::invoke_result_t<decltype(F), Context&, decltype(GetValuable(std::forward<decltype(args)>(args)))...>;
        return _callKnownResult<F, is_gl, R>(std::forward<decltype(args)>(args)...);
    } else {
        using R = std::invoke_result_t<decltype(F), decltype(GetValuable(std::forward<decltype(args)>(args)))...>;
        return _callKnownResult<F, is_gl, R>(std::forward<decltype(args)>(args)...);
    }
}

template<typename T>
template<auto GLapi::*M, IsGlThread is_gl>
auto CtxObj<T>::callGLapi(auto&&... args) const {
    static constexpr auto F = [](Context& ctx, auto&&... args){
        return (ctx.gl.*M)(GetValuable(std::forward<decltype(args)>(args))...);
    };
    return call<F, is_gl>(std::forward<decltype(args)>(args)...);
}

template<typename T>
template<auto T::*M, IsGlThread is_gl>
auto CtxObj<T>::callMember(auto&&... args){
    static constexpr auto F = [](Context& ctx, const std::shared_ptr<T>& ctx_obj, auto&&... args){
        constexpr bool need_context = std::is_invocable_v<decltype(M), T&, Context&, decltype(GetValuable(std::forward<decltype(args)>(args)))...>;
        if constexpr (need_context){
            return (ctx_obj.get()->*M)(ctx, GetValuable(std::forward<decltype(args)>(args))...);
        } else {
            return (ctx_obj.get()->*M)(GetValuable(std::forward<decltype(args)>(args))...);
        }
    };
    return call<F, is_gl>(this->shared_from_this(), std::forward<decltype(args)>(args)...);
}

template<typename T>
template<auto T::*M, IsGlThread is_gl>
auto CtxObj<T>::callMember(auto&&... args) const {
    static constexpr auto F = [](Context& ctx, const std::shared_ptr<const T>& ctx_obj, auto&&... args){
        constexpr bool need_context = std::is_invocable_v<decltype(M), const T&, Context&, decltype(GetValuable(std::forward<decltype(args)>(args)))...>;
        if constexpr (need_context){
            return (ctx_obj.get()->*M)(ctx, GetValuable(std::forward<decltype(args)>(args))...);
        } else {
            return (ctx_obj.get()->*M)(GetValuable(std::forward<decltype(args)>(args))...);
        }
    };
    return call<F, is_gl>(this->shared_from_this(), std::forward<decltype(args)>(args)...);
}

template<typename T>
template<auto F, IsGlThread is_gl, typename R>
inline Value<std::future<R>> CtxObj<T>::_callKnownResult(auto&&... args) const {
    if constexpr (is_gl == IsGlThread::True){
        return _callDirect<F, R>(std::forward<decltype(args)>(args)...);
    }
    
    if constexpr (is_gl == IsGlThread::False){
        return _callIndirect<F, R>(std::forward<decltype(args)>(args)...);
    }
    
    if constexpr (is_gl == IsGlThread::Unknown){
        if (std::this_thread::get_id() == _ctx_thread_id){
            return _callDirect<F, R>(std::forward<decltype(args)>(args)...);
        } else {
            return _callIndirect<F, R>(std::forward<decltype(args)>(args)...);
        }
    }
}

template<typename T>
template<auto F, typename R>
inline auto CtxObj<T>::_callDirect(auto&&... args) const {
    std::promise<R> promise;
    _FillPromise<F>(promise, *_p_ctx, std::forward<decltype(args)>(args)...);
    return Value(std::move(promise.get_future()));
}

template<typename T>
template<auto F, typename R>
inline auto CtxObj<T>::_callIndirect(auto&&... args) const {
    auto ctx = _wctx.lock();
    if (!ctx){
        throw std::runtime_error("Conetext is destroyed");
    }
    return _callWithRunEvent<F, R>(*ctx, Value(std::forward<decltype(args)>(args))...);
}

template<typename T>
template<auto F, typename R>
inline auto CtxObj<T>::_callWithRunEvent(Context& ctx, auto&&... args) const {
    static_assert((detail::is_instance_v<decltype(args), Value> && ...), "all arguments must be glwpp::Value<T>");

    auto promise = std::make_shared<std::promise<R>>();
    ctx.event_on_run_gl.add(Context::PRIORITY_DEFAULT,
        [promise, args...](Context& ctx, const Context::ms&){
            _FillPromise<F, R>(*promise, ctx, GetValuable(args)...);
            return false;
        }
    );
    return Value(promise->get_future());
}

template<typename T>
template<auto F, typename R>
inline void CtxObj<T>::_FillPromise(std::promise<R>& promise, Context& ctx, auto&&... args){
    constexpr bool need_context = std::is_invocable_v<decltype(F), Context&, decltype(GetValuable(args))...>;

    if constexpr (need_context){
        if constexpr (std::is_same_v<R, void>){
            F(ctx, GetValuable(args)...);
            promise.set_value();
        } else {
            promise.set_value(F(ctx, GetValuable(args)...));
        }
    } else {
        if constexpr (std::is_same_v<R, void>){
            F(GetValuable(args)...);
            promise.set_value();
        } else {
            promise.set_value(F(GetValuable(args)...));
        }
    }
}

template<typename T>
class CtxObjRef {
public:
    // static_assert(detail::is_instance_v<T, CtxObj>, "CtxObjRef is usable with CtxObj only.");

    CtxObjRef(auto&&... args) :
        _obj(new T(std::forward<decltype(args)>(args)...)){
        
    }

    CtxObjRef(const CtxObjRef& other) = default;
    CtxObjRef(CtxObjRef&& other) = default;
    virtual ~CtxObjRef(){};
    
    inline T* operator->(){return _obj.get();};
    inline const T* operator->() const {return _obj.get();};

protected:
    std::shared_ptr<T> _obj;
};

} // namespace glwpp