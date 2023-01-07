#pragma once

#include "Context.hpp"
#include "context/Value.hpp"

namespace glwpp {

namespace detail {
/* Trick to allow multiple inheritance of objects
 * inheriting shared_from_this.
 * cf. https://stackoverflow.com/a/12793989/587407
 */

/* First a common base class
 * of course, one should always virtually inherit from it.
 */
class MultipleInheritableEnableSharedFromThis
: public std::enable_shared_from_this<MultipleInheritableEnableSharedFromThis> {
public:
  virtual ~MultipleInheritableEnableSharedFromThis()
  {}
};

template <class T>
class inheritable_enable_shared_from_this
: virtual public MultipleInheritableEnableSharedFromThis {
public:
  std::shared_ptr<T> shared_from_this() {
    return std::dynamic_pointer_cast<T>(
        MultipleInheritableEnableSharedFromThis::shared_from_this()
    );
  }
  /* Utility method to easily downcast.
   * Useful when a child doesn't inherit directly from enable_shared_from_this
   * but wants to use the feature.
   */
  template <class Down>
  std::shared_ptr<Down> downcasted_shared_from_this() {
    return std::dynamic_pointer_cast<Down>(
       MultipleInheritableEnableSharedFromThis::shared_from_this()
    );
  }
};

} // namespace detail

template<typename T>
class CtxObj : virtual public std::enable_shared_from_this<T> {
public:
    CtxObj(Context& ctx);
    CtxObj(const CtxObj&) = delete;
    CtxObj(CtxObj&&) = delete;
    virtual ~CtxObj();

    template<auto F, IsGlThread is_gl>
    auto call(auto&&... args) const;
    
    template<auto GLapi::*M, IsGlThread is_gl_thread>
    auto callGLapi(auto&&... args) const;

    template<auto T::*M, IsGlThread is_gl>
    auto callMember(auto&&... args);

    template<auto T::*M, IsGlThread is_gl>
    auto callMember(auto&&... args) const;

private:
    const std::thread::id _ctx_thread_id;
    const std::weak_ptr<Context> _wctx;
    Context* _p_ctx;
    
    template<auto F>
    auto _callDirect(auto&&... args) const;
    
    template<auto F>
    auto _callIndirect(auto&&... args) const;

    template<auto F>
    auto _callWithRunEvent(Context& ctx, auto&&... args) const;

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
    static_assert(std::is_invocable_v<decltype(F), Context&, decltype(GetValuable(args))...>, "R F(Context&, Args&&... args)");

    if constexpr (is_gl == IsGlThread::True){
        return _callDirect<F>(std::forward<decltype(args)>(args)...);
    }
    
    if constexpr (is_gl == IsGlThread::False){
        return _callIndirect<F>(std::forward<decltype(args)>(args)...);
    }
    
    if constexpr (is_gl == IsGlThread::Unknown){
        if (std::this_thread::get_id() == _ctx_thread_id){
            return _callDirect<F>(std::forward<decltype(args)>(args)...);
        } else {
            return _callIndirect<F>(std::forward<decltype(args)>(args)...);
        }
    }
}

template<typename T>
template<auto GLapi::*M, IsGlThread is_gl_thread>
auto CtxObj<T>::callGLapi(auto&&... args) const {
    static constexpr auto F = [](Context& ctx, auto&&... args){
        return (ctx.gl.*M)(GetValuable(std::forward<decltype(args)>(args))...);
    };
    return call<F, is_gl_thread>(std::forward<decltype(args)>(args)...);
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
template<auto F>
auto CtxObj<T>::_callDirect(auto&&... args) const {
    using R = std::invoke_result_t<decltype(F), Context&, decltype(GetValuable(args))...>;

    std::promise<R> promise;
    if constexpr (std::is_same_v<R, void>){
        F(*_p_ctx, GetValuable(args)...);
        promise.set_value();
    } else {
        promise.set_value(F(*_p_ctx, GetValuable(args)...));
    }

    return Value(std::move(promise.get_future()));
}

template<typename T>
template<auto F>
auto CtxObj<T>::_callIndirect(auto&&... args) const {
    auto ctx = _wctx.lock();
    if (!ctx){
        throw std::runtime_error("Conetext is destroyed");
    }
    return _callWithRunEvent<F>(*ctx, Value(std::forward<decltype(args)>(args))...);
}

template<typename T>
template<auto F>
auto CtxObj<T>::_callWithRunEvent(Context& ctx, auto&&... args) const {
    static_assert((detail::is_instance_v<decltype(args), Value> && ...), "all arguments must be glwpp::Value<T>");

    using R = std::invoke_result_t<decltype(F), Context&, decltype(GetValuable(args))...>;
    auto promise = std::make_shared<std::promise<R>>();
    ctx.event_on_run_gl.add(Context::PRIORITY_DEFAULT,
        [promise, args...](Context& ctx, const Context::ms&){
            if constexpr (std::is_same_v<R, void>){
                F(ctx, GetValuable(args)...);
                promise->set_value();
            } else {
                promise->set_value(F(ctx, GetValuable(args)...));
            }
            return false;
        }
    );
    return Value(promise->get_future());
}

} // namespace glwpp