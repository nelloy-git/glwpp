#pragma once

#include <any>
#include <atomic>
#include <functional>
#include <iostream>
#include <memory>
#include <optional>

#include "glwpp/utils/FuncWrapper.hpp"

namespace glwpp {

template<class R, class ... Args>
using Cmd = std::function<R(Args...)>;

class CmdWatcher {
    template<class R, class ... Args>
    friend class CmdRunner;
public:
    CmdWatcher() :
        _uses(0),
        _runs_done(0),
        _running_now(0),
        _idle(true){
    }
    CmdWatcher(const CmdWatcher&) = delete;
    CmdWatcher(CmdWatcher&&) = delete;
    CmdWatcher& operator=(const CmdWatcher&) = delete;
    CmdWatcher& operator=(CmdWatcher&&) = delete;
    ~CmdWatcher(){waitAll();}

    inline void waitOne() const {_runs_done.wait(_runs_done.load());}
    inline void waitAll() const {_idle.wait(false);}

    inline size_t getUses(){return _uses;}
    inline size_t getRunsDone(){return _runs_done;}
    inline size_t getRunningNow(){return _running_now;}
    inline bool isRunning(){return !_idle;}
protected:
    std::atomic<size_t> _uses;
    std::atomic<size_t> _runs_done;
    std::atomic<size_t> _running_now;
    std::atomic<bool> _idle;
};

template<class R, class ... Args>
class CmdRunner {
public:
    template<class ... ArgsW>
    CmdRunner(const std::weak_ptr<CmdWatcher> &watcher, Cmd<R, ArgsW...> cmd) :
        _watcher(watcher),
        _cmd(func_wrap<Args...>(cmd)){
        auto w = watcher.lock();
        if (w) ++w->_uses;
    };

    template<class F>
    CmdRunner(const std::weak_ptr<CmdWatcher> &watcher, F cmd) :
        _watcher(watcher),
        _cmd(func_wrap<Args...>(std::function(cmd))){
        auto w = watcher.lock();
        if (w) ++w->_uses;
    };

    virtual ~CmdRunner(){
        auto w = _watcher.lock();
        if (w) --w->_uses;
    }

    template<class ... ArgsR>
    std::optional<R> run(ArgsR&&... args){
        auto watcher = _watcher.lock();
        if (!watcher) return std::nullopt;

        ++watcher->_running_now;
        R res;
        try {
            res = _cmd(std::forward<ArgsR>(args)...);
        } catch (std::exception &e){
            --watcher->_running_now;
            watcher->_idle = watcher->_running_now == 0;
            watcher->_idle.notify_all();

            std::cout << e.what() << std::endl;

            return std::nullopt;
        }
        --watcher->_running_now;
        watcher->_idle = watcher->_running_now == 0;
        watcher->_idle.notify_all();

        watcher->_runs_done++;
        watcher->_runs_done.notify_all();
        return res;
    }

    std::weak_ptr<CmdWatcher> getWatcher(){
        return _watcher;
    }

private:
    std::weak_ptr<CmdWatcher> _watcher;
    Cmd<R, Args...> _cmd;
};

enum class CmdAct {
    Stop,
    Repeat,
};

}