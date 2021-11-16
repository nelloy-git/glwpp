#pragma once

#include <deque>
#include <functional>
#include <memory>
#include <mutex>

#include "glwpp/utils/container/Cmd.hpp"
#include "glwpp/utils/FuncWrapper.hpp"

namespace glwpp {

template<class ... Args>
class EventBase final {
public:
    using CmdRunner = glwpp::CmdRunner<CmdAct, EventBase&, Args...>;
    using Deque = std::deque<std::shared_ptr<CmdRunner>>;

    EventBase() :
        _emiting(false){
        _watcher = std::make_shared<CmdWatcher>();
        _callbacks = std::make_unique<Deque>();
        _swap = std::make_unique<Deque>();
    }

    ~EventBase(){
        wait();
    }

    template<class F>
    bool pushBack(std::weak_ptr<CmdWatcher> watcher, F cmd){
        if (watcher.expired()) return false;

        std::lock_guard<std::mutex> lg(_lock_changes);
        auto wrapped = func_wrap<EventBase<Args&&...>&, Args&&...>(std::function(cmd));
        _back_changes.push_back(std::make_shared<CmdRunner>(watcher, wrapped));
        return true;
    }

    template<class F>
    bool pushFront(std::weak_ptr<CmdWatcher> watcher, F cmd){
        if (watcher.expired()) return false;

        std::lock_guard<std::mutex> lg(_lock_changes);
        auto wrapped = func_wrap<EventBase<Args&&...>&, Args&&...>(std::function(cmd));
        _front_changes.push_back(std::make_shared<CmdRunner>(watcher, wrapped));
        return true;
    }

    bool emit(Args&&... args){
        if (_emiting) return false;
        _emiting = true;

        _swap->clear();
        _applyChanges();
        for (auto &cmd_runner : *_callbacks){
            auto opt_res = cmd_runner->run(*this, std::forward<Args>(args)...);
            auto res = opt_res.value_or(CmdAct::Stop);

            switch (res){
            case CmdAct::Repeat:
                _swap->push_back(cmd_runner);
                break;
            case CmdAct::Stop:            
            default:
                break;
            }
        }
        _swap.swap(_callbacks);

        _emiting = false;
        _emiting.notify_one();
    }

    void wait(){
        _emiting.wait(true);
    }

private:
    std::atomic<bool>   _emiting;
    std::shared_ptr<CmdWatcher> _watcher;

    std::mutex _lock_changes;
    std::unique_ptr<Deque> _callbacks;
    std::unique_ptr<Deque> _swap;
    Deque _front_changes;
    Deque _back_changes;

    void _applyChanges(){
        std::lock_guard<std::mutex> lg(_lock_changes);

        for (auto it = _front_changes.begin(); it != _front_changes.end(); ++it){
            _callbacks->push_front(*it);
        }

        for (auto it = _back_changes.begin(); it != _back_changes.end(); ++it){
            _callbacks->push_back(*it);
        }

        _front_changes.clear();
        _back_changes.clear();
    }
};

}