#pragma once

#include "glad/gl.h"

#include "Context.hpp"
#include "context/Value.hpp"

#define WRAP_GL_TYPE(name, new_name) \
typedef Value<name> ##new_name; \
typedef Value<const name> Const##new_name; \
typedef Value<name[]>  Arr##new_name; \
typedef Value<const name[]> ConstArr##new_name

namespace glwpp {
    
template<typename T, typename Req>
constexpr bool IsValuable(){
    if constexpr (std::is_convertible_v<T, Req>){
        return true;
    } else {
        if constexpr (is_instance<std::remove_const_t<std::remove_reference_t<T>>, Value>::value){
            using R = decltype(std::declval<T>().value());
            return std::is_convertible_v<R, Req>;
        } else {
            return false;
        }
    }
}

template<typename T, typename Req>
concept Valuable = IsValuable<T, Req>();

static inline decltype(auto) GetValuable(auto&& val){
    using T = std::remove_const_t<std::remove_reference_t<decltype(val)>>;

    if constexpr (is_instance<T, Value>::value){
        return val.value();
    } else {
        return std::forward<decltype(val)>(val);
    }
}

class CallOptimizer {
public:
    CallOptimizer(Context& ctx);
    virtual ~CallOptimizer() = 0;

    std::shared_ptr<Context> lockCtx() const;

    template<auto F, IsGlThread is_gl_thread>
    auto call(auto&&... args) const;
    
    template<auto GLapi::*M, IsGlThread is_gl_thread>
    auto callGLapi(auto&&... args) const;

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
    
    template<typename ... Ts>
    static constexpr bool _IsValues(){
        return std::conjunction_v<is_instance<std::remove_const_t<std::remove_reference_t<Ts>>, Value>...>;
    }
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
    call<F, is_gl_thread>(std::forward<decltype(args)>(args)...);
}

template<auto F>
auto CallOptimizer::_callDirect(auto&&... args) const {
    using R = std::invoke_result_t<decltype(F), Context&, decltype(GetValuable(args))...>;
    if constexpr (std::is_same_v<R, void>){
        F(*_p_ctx, GetValuable(std::forward<decltype(args)>(args))...);
    } else {
        return Value(*_p_ctx, F(*_p_ctx, GetValuable(std::forward<decltype(args)>(args))...));
    }
}

template<auto F>
auto CallOptimizer::_callIndirect(auto&&... args) const {
    auto ctx = _wctx.lock();
    if (!ctx){
        throw std::runtime_error("Conetext is destroyed");
    }
    return _callWithRunEvent<F>(*ctx, Value(*ctx, std::forward<decltype(args)>(args))...);
}

template<auto F>
auto CallOptimizer::_callWithRunEvent(Context& ctx, auto&&... args) const {
    static_assert(_IsValues<decltype(args)...>(), "all arguments must be glwpp::Value<T>");

    using R = std::invoke_result_t<decltype(F), Context&, decltype(GetValuable(args))...>;
    if constexpr (std::is_same_v<R, void>){
        ctx.getOnRunEvent().addActionQueued([args...](Context* ctx, const Context::ms&){
            F(*ctx, args.value()...);
            return false;
        });
    } else {
        Value<std::remove_const_t<R>> result;
        ctx.getOnRunEvent().addActionQueued([result, args...](Context* ctx, const Context::ms&){
            *result = F(*ctx, args.value()...);
            return false;
        });
        return Value<R>(result);
    }
}

} // namespace glwpp