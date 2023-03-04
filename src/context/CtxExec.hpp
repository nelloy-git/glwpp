#pragma once

#include "Context.hpp"
#include "utils/Ref.hpp"

namespace glwpp {

class CtxExec {
    template<bool IsCtx>
    class CtxPtr;

public:
    CtxExec(Context& ctx);
    virtual ~CtxExec();

    template<typename F, typename ... Args>
    static decltype(auto) CallDirect(Context& ctx, F&& func, Args&&... args);

    template<typename F, typename ... Args>
    static decltype(auto) CallIndirect(Context& ctx, F&& func, Args&&... args);

    template<bool IsCtx>
    inline CtxPtr<IsCtx> ctx() const;

    template<bool IsCtx, typename F, typename ... Args>
    inline decltype(auto) call(F&& func, Args&&... args) const;

private:
    const std::thread::id _ctx_thread_id;
    const std::weak_ptr<Context> _wctx;
    Context* _p_ctx;

};

template<bool IsCtx>
class CtxExec::CtxPtr {
    using Ptr = std::conditional_t<IsCtx, Context*, std::shared_ptr<Context>>;
public:
    CtxPtr(const Ptr& p_ctx) : _ptr(p_ctx){};
    ~CtxPtr(){};

    Context* operator->(){
        if constexpr (IsCtx){
            return _ptr;
        } else {
            return _ptr.get();
        }
    }

    Context& operator*(){
        if constexpr (IsCtx){
            return *_ptr;
        } else {
            return *_ptr.get();
        }
    }

private:
    Ptr _ptr;
};


inline CtxExec::CtxExec(Context& ctx) :
    _ctx_thread_id(ctx.getGlThreadId()),
    _wctx(ctx.weak_from_this()),
    _p_ctx(&ctx){
}


inline CtxExec::~CtxExec(){
}


template<typename F, typename ... Args>
inline decltype(auto) CtxExec::CallDirect(Context& ctx, F&& func, Args&&... args){
    if constexpr (std::is_invocable_v<F, Args...>){
        return (std::forward<F>(func))(std::forward<Args>(args)...);
    } else if constexpr (std::is_invocable_v<F, Context&, Args...>){
        return (std::forward<F>(func))(ctx, std::forward<Args>(args)...);
    } else {
        []<bool B = false>(){
            static_assert(B, "Wrong arguments");
        };
    }
}


template<typename F, typename ... Args>
inline decltype(auto) CtxExec::CallIndirect(Context& ctx, F&& func, Args&&... args){
    using ResT = std::invoke_result_t<decltype(CallDirect<F, Args...>), Context&, F, Args...>;

    auto promise = std::make_shared<std::promise<ResT>>();
    ctx.event_on_run_gl.add(Context::PRIORITY_DEFAULT,
        [promise = promise, func, ...args = Ref(std::forward<Args>(args))](Context& ctx, const Context::time&){
            if constexpr (std::is_same_v<ResT, void>){
                CallDirect(ctx, func, args...);
                promise->set_value();
            } else {
                promise->set_value(CallDirect(func, args...));
            }
            return false;
        }, SrcLoc{}
    );
    return Ref(std::move(promise->get_future()));
}


template<bool IsCtx>
inline CtxExec::CtxPtr<IsCtx> CtxExec::ctx() const {
    if constexpr (IsCtx){
        return CtxPtr<IsCtx>(_p_ctx);
    } else {
        auto ctx = _wctx.lock();
        if (!ctx){throw std::runtime_error("Context is destroyed");}
        return CtxPtr<IsCtx>(ctx);
    }
}


template<bool IsCtx, typename F, typename ... Args>
inline decltype(auto) CtxExec::call(F&& func, Args&&... args) const {
    if constexpr (IsCtx){
        return CallDirect(*ctx<IsCtx>(), std::forward<F>(func), std::forward<Args>(args)...);
    }

    if (std::this_thread::get_id() != _ctx_thread_id){
        return CallIndirect(*ctx<IsCtx>(), std::forward<F>(func), std::forward<Args>(args)...);
    }

    using ResT = std::invoke_result_t<decltype(CallDirect<F, Args...>), Context&, F, Args...>;
    std::promise<ResT> promise;
    if constexpr (std::is_same_v<ResT, void>){
        CallDirect(*ctx<IsCtx>(), std::forward<F>(func), std::forward<Args>(args)...);
        promise.set_value();
    } else {
        promise.set_value(CallDirect(*ctx<IsCtx>(), std::forward<F>(func), std::forward<Args>(args)...));
    }
    return Ref(std::move(promise.get_future()));
}

} // namespace glwpp