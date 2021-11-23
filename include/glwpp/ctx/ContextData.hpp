#pragma once

#include <memory>

#include "glwpp/ctx/Context.hpp"

namespace glwpp::ctx {

template<class T>
class ContextData {
public:
    template<class ... Args>
    ContextData(std::weak_ptr<Context> ctx) :
        _initing(false),
        _ctx(ctx){
        _watcher = std::make_shared<CmdWatcher>();
    }

    virtual ~ContextData(){
        auto ctx = _ctx.lock();
        if (!ctx) return;

        _watcher.reset();

        auto destr_watcher = std::make_shared<CmdWatcher>();
        ctx->onLoopEnd().pushBack(destr_watcher, [this](){
            _data.reset();
            return CmdAct::Stop;
        });
        destr_watcher->waitOne();
    }

    // Blocking function
    template<class R, class ... Args>
    std::optional<R> execute(const std::function<R(std::weak_ptr<T>, Args&&...)> &func, Args&& ... args){
        if (!isValid()) return std::nullopt;

        auto ctx = _ctx.lock();
        if (!ctx) return std::nullopt;

        std::optional<R> res;
        
        auto result_watcher = std::make_shared<CmdWatcher>();
        std::weak_ptr<T> wdata = _data;
        ctx->onLoopRun().pushBack(result_watcher, [wdata, &res, func, &args...](){
            res = func(wdata, std::forward<Args>(args)...);
            return CmdAct::Stop;
        });
        result_watcher->waitOne();

        return res;
    }
    
    // Nonblocking function
    template<class ... Args>
    bool execute(const std::function<void(std::weak_ptr<T>, Args&&...)> &func, Args&& ... args){
        if (!isValid()) return false;

        auto ctx = _ctx.lock();
        if (!ctx) return false;

        std::weak_ptr<T> wdata = _data;
        ctx->onLoopRun().pushBack(_watcher, [wdata, func, &args...](){
            func(wdata, std::forward<Args>(args)...);
            return CmdAct::Stop;
        });
        return true;
    }

    bool isValid(){
        return _data != nullptr;
    }

    std::weak_ptr<Context> getContext(){
        return _ctx;
    }

    std::weak_ptr<T> getData(){
        return _data;
    }

protected:
    // Blocking function
    template<class ... Args>
    bool _initSimply(Args&& ... args){
        return _init(std::make_shared<T, Args...>, std::forward<Args>(args)...);
    };

    // Blocking function
    template<class ... Args>
    bool _init(std::function<std::shared_ptr<T>(Args&&...)> initializer,
              Args&& ... args){
        if (_initing || isValid()) return false;
        _initing = true;

        auto ctx = _ctx.lock();
        if (!ctx) return false;

        auto construct_watcher = std::make_shared<CmdWatcher>();
        ctx->onLoopStart().pushBack(construct_watcher, [this, initializer, &args...](){
            _data = initializer(std::forward<Args>(args)...);
            return CmdAct::Stop;
        });
        construct_watcher->waitOne();

        if (!_data){
            _initing = false;
            return false;
        }

        ctx->onDestroy().pushBack(_watcher, [this](){
            _data.reset();
            return CmdAct::Stop;
        });

        _initing = false;
        return true;
    };

private:
    std::atomic<bool> _initing;
    std::shared_ptr<CmdWatcher> _watcher;
    std::shared_ptr<T> _data;
    std::weak_ptr<Context> _ctx;
};

}