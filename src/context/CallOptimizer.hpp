#pragma once

#include <memory>

#include "Context.hpp"
#include "context/Value.hpp"

namespace glwpp {

namespace detail {
template <typename T>
concept CanMakeSharedFromThis = requires(std::remove_reference_t<T>* a){
    { a->shared_from_this() } -> std::convertible_to<std::shared_ptr<std::remove_reference_t<T>>>;
};
} // namespace detail


class CallOptimizer {
public:
    CallOptimizer(Context& ctx);
    virtual ~CallOptimizer() = 0;

    std::shared_ptr<Context> lockCtx() const;

    template<auto F, IsGlThread is_gl_thread>
    auto call(auto&&... args) const;

    template<auto F, IsGlThread is_gl_thread>
    auto callWithoutCtx(auto&&... args) const;
    
    template<auto GLapi::*M, IsGlThread is_gl_thread>
    auto callGLapi(auto&&... args) const;

    template<auto M, IsGlThread is_gl_thread, detail::CanMakeSharedFromThis T>
    auto callMember(T&& obj, auto&&... args) const {
        using Unref_T = std::remove_reference_t<T>;
        static constexpr auto F = [](Context& ctx, const std::shared_ptr<Unref_T>& obj, auto&&... args){
            return (obj.get()->*M)(GetValuable(std::forward<decltype(args)>(args))...);
        };
        return call<F, is_gl_thread>(obj.shared_from_this(), std::forward<decltype(args)>(args)...);
    }

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


inline CallOptimizer::CallOptimizer(Context& ctx) :
    _ctx_thread_id(ctx.getGlThreadId()),
    _wctx(ctx.weak_from_this()),
    _p_ctx(&ctx){
}

inline CallOptimizer::~CallOptimizer(){
}

inline std::shared_ptr<Context> CallOptimizer::lockCtx() const {
    return _wctx.lock();
}

template<auto F, IsGlThread is_gl_thread>
auto CallOptimizer::call(auto&&... args) const {
    static_assert(std::is_invocable_v<decltype(F), Context&, decltype(GetValuable(args))...>, "R F(Context&, Args&&... args)");

    if constexpr (is_gl_thread == IsGlThread::True){
        return _callDirect<F>(std::forward<decltype(args)>(args)...);
    }
    
    if constexpr (is_gl_thread == IsGlThread::False){
        return _callIndirect<F>(std::forward<decltype(args)>(args)...);
    }
    
    if constexpr (is_gl_thread == IsGlThread::Unknown){
        if (std::this_thread::get_id() == _ctx_thread_id){
            return _callDirect<F>(std::forward<decltype(args)>(args)...);
        } else {
            return _callIndirect<F>(std::forward<decltype(args)>(args)...);
        }
    }
}

template<auto GLapi::*M, IsGlThread is_gl_thread>
auto CallOptimizer::callGLapi(auto&&... args) const {
    static constexpr auto F = [](Context& ctx, auto&&... args){
        return (ctx.gl.*M)(GetValuable(std::forward<decltype(args)>(args))...);
    };
    return call<F, is_gl_thread>(std::forward<decltype(args)>(args)...);
}

template<auto F, IsGlThread is_gl_thread>
auto CallOptimizer::callWithoutCtx(auto&&... args) const {
    static constexpr auto Wrapped = [](Context& ctx, auto&&... args){
        return F(GetValuable(std::forward<decltype(args)>(args))...);
    };
    return call<Wrapped, is_gl_thread>(std::forward<decltype(args)>(args)...);
}

template<auto F>
auto CallOptimizer::_callDirect(auto&&... args) const {
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

template<auto F>
auto CallOptimizer::_callIndirect(auto&&... args) const {
    auto ctx = _wctx.lock();
    if (!ctx){
        throw std::runtime_error("Conetext is destroyed");
    }
    return _callWithRunEvent<F>(*ctx, Value(std::forward<decltype(args)>(args))...);
}

template<auto F>
auto CallOptimizer::_callWithRunEvent(Context& ctx, auto&&... args) const {
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