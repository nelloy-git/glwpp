#pragma once

#include <memory>

#include "glwpp/ctx/Context.hpp"

namespace glwpp::ctx {

template<class T>
class ContextData {
public:

    template<class ... OutArgs>
    bool init(std::weak_ptr<Context> wctx, OutArgs&& ... args){
        auto ctx = wctx.lock();
        if (!ctx) return false;
        _wctx = wctx;

        auto queue = ctx->getCmdQueue().lock();
        if (!queue) return false;

        auto cmd_init = Context::CmdQueue::newCmd([this, &args...](CmdThread&){
            data = std::make_unique<T>(std::forward<OutArgs>(args)...);
        });
        queue->pushOnceWait(cmd_init);

        _cmd_destroy = ctx->onDestroy.pushBackFunc([this](Context&){
            data.reset();
        });
        return true;
    };

    template<class ... OutArgs>
    bool initFunc(std::weak_ptr<Context> wctx,
                  std::function<std::unique_ptr<T>(OutArgs...)> init_func,
                  OutArgs ... args){
        
        auto ctx = wctx.lock();
        if (!ctx) return false;
        _wctx = wctx;

        auto queue = ctx->getCmdQueue().lock();
        if (!queue) return false;

        auto cmd_init = CmdThread::newCmd([this, init_func, &args...](CmdThread&){
            data = init_func(args...);
        });
        queue->pushOnceWait(cmd_init);

        _cmd_destroy = ctx->onDestroy.pushBackFunc([this](Context&){
            data.reset();
        });
        return true;
    }

    virtual ~ContextData(){
        _cmd_destroy.reset();

        auto ctx = _wctx.lock();
        if (!ctx) return;

        auto queue = ctx->getCmdQueue().lock();
        if (!queue) return;
        
        auto cmd = CmdThread::newCmd([this](CmdThread&){
            data.reset();
        });
        queue->pushOnceWait(cmd);
    }

    std::weak_ptr<Context> getContext(){
        return _wctx;
    }

    template<class C, class R, class ... OutArgs>
    bool executeIgnoreResult(R (C::*method)(OutArgs...), OutArgs ... args){
        static_assert(std::is_invocable_v<decltype(method), T*, OutArgs...>);

        if (!data) return false;

        auto ctx = _wctx.lock();
        if (!ctx) return false;

        auto queue = ctx->getCmdQueue().lock();
        if (!queue) return false;

        auto cmd = Context::CmdQueue::newCmd([this, method, args...](CmdThread&){
            (data.get()->*method)(args...);
        });
        queue->pushOnceWait(cmd);

        return true;
    }

    template<class C, class R, class ... OutArgs>
    bool executeIgnoreResult(R (C::*method)(OutArgs...) const, OutArgs ... args){
        static_assert(std::is_invocable_v<decltype(method), T*, OutArgs...>);

        if (!data) return false;

        auto ctx = _wctx.lock();
        if (!ctx) return false;

        auto queue = ctx->getCmdQueue().lock();
        if (!queue) return false;

        auto cmd = Context::CmdQueue::newCmd([this, method, args...](CmdThread&){
            (data.get()->*method)(args...);
        });
        queue->pushOnceWait(cmd);

        return true;
    }

    std::unique_ptr<T> data;

private:
    std::weak_ptr<Context> _wctx;
    decltype(Context::onDestroy)::Cmd _cmd_destroy;

};

}