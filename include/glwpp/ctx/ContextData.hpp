#pragma once

#include <optional>

#include "glwpp/ctx/Context.hpp"

namespace glwpp::ctx {

template<class T>
class ContextData {
public:
    // template<class ... Args>
    // ContextData(std::weak_ptr<Context> ctx,
    //             Args&& ... args) :
    //     _initialized(false) {
    //     _watcher = std::make_shared<Watcher>();
    //     _init(std::make_shared<T, Args...>, std::forward<Args>(args)...);
    // }

    template<class ... Args>
    ContextData(std::weak_ptr<Context> ctx,
                std::function<sptr<T>(Args&&...)> initializer = make_sptr<T>,
                Args&& ... args) :
        _initialized(false){
        _watcher = std::make_shared<Watcher>();
        _init(initializer, std::forward<Args>(args)...);
    }

    bool isInitialized(){
        return _initialized;
    }

    virtual ~ContextData(){
        auto ctx = _ctx.lock();
        if (!ctx) return;

        _watcher.reset();

        auto destr_watcher = make_sptr<Watcher>();
        ctx->onLoopEnd().push_back(destr_watcher, [this](){
            _data.reset();
            return EventAction::Stop;
        });
        destr_watcher->wait_for_done();
    }

    wptr<T> get(){
        if (_ctx_thread != std::this_thread::get_id()){
            return wptr<T>();
        }
        return _data;
    }

    // Blocking function
    template<class R, class ... Args>
    std::optional<R> getResult(const std::function<R(std::weak_ptr<T>, Args&&...)> &func,
                               Args&& ... args){
        if (!_initialized) return std::nullopt;

        auto ctx = _ctx.lock();
        if (!ctx) return std::nullopt;

        std::optional<R> res;
        auto result_watcher = make_sptr<Watcher>();
        std::weak_ptr<T> wdata = _data;
        ctx->onLoopRun().push_back(result_watcher, [wdata, &res, func, &args...](){
            res = func(wdata, std::forward<Args>(args)...);
            return EventAction::Stop;
        });
        result_watcher->wait_for_done();

        return res;
    }
    
    // Nonblocking function
    template<class ... Args>
    bool execute(const std::function<void(std::weak_ptr<T>, Args&&...)> &func,
                 Args&& ... args){
        if (!_initialized) return false;

        auto ctx = _ctx.lock();
        if (!ctx) return false;

        std::weak_ptr<T> wdata = _data;
        ctx->onLoopRun().push_back(_watcher, [wdata, func, &args...](){
            func(wdata, std::forward<Args>(args)...);
            return EventAction::Stop;
        });
        return true;
    }

private:
    std::weak_ptr<Context> _ctx;
    std::thread::id _ctx_thread;
    std::shared_ptr<Watcher> _watcher;

    std::atomic<bool> _initialized;
    std::shared_ptr<T> _data;

    // Blocking function
    template<class ... Args>
    bool _init(std::function<sptr<T>(Args&&...)> initializer, Args&& ... args){
        auto ctx = _ctx.lock();
        if (!ctx) return false;

        ctx->onLoopStart().push_back(_watcher, [this, initializer, &args...](){
            _data = initializer(std::forward<Args>(args)...);
            _ctx_thread = std::this_thread::get_id();
            _initialized = _data != nullptr;
            return EventAction::Stop;
        });

        ctx->onDestroy().push_back(_watcher, [this](){
            _data.reset();
            return EventAction::Stop;
        });

        return true;
    };
};

}