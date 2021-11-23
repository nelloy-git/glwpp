#pragma once

#include <deque>
#include <functional>
#include <mutex>

#include "glwpp/utils/event/Runner.hpp"

namespace glwpp {

enum class EventAction {
    Stop,
    Continue
};

template<class ... Args>
class Event final {
public:
    Event() : 
        _emits_count(0){
        _callbacks = make_uptr<Deque>();
        _swap = make_uptr<Deque>();
    }

    ~Event(){
    }

    template<class F>
    bool push_back(wptr<Watcher> watcher, F cmd){
        if (watcher.expired()) return false;

        auto runner = make_sptr<Runner<EventAction(Event<Args...>&, Args...)>>(watcher, cmd);
        std::lock_guard<std::mutex> lg(_lock_changes);
        _back_changes.push_back(runner);
        return true;
    }

    template<class F>
    bool push_front(wptr<Watcher> watcher, F cmd){
        if (watcher.expired()) return false;

        auto runner = make_sptr<Runner<EventAction(Event<Args...>&, Args...)>>(watcher, cmd);
        std::lock_guard<std::mutex> lg(_lock_changes);
        _front_changes.push_back(runner);
        return true;
    }

    bool emit(bool wait, Args&&... args){
        if (!wait){
            if (!_lock_emit.try_lock()) return false;
        } else {
            _lock_emit.lock();
        }

        _swap->clear();
        _applyChanges();
        for (auto &cmd_runner : *_callbacks){
            auto var_res = cmd_runner->run(*this, std::forward<Args>(args)...);
            bool is_err = std::holds_alternative<std::exception_ptr>(var_res);

            if (is_err){
                _errors.push_back(std::get<std::exception_ptr>(var_res));
            } else {
                if (std::get<EventAction>(var_res) == EventAction::Continue){
                    _swap->push_back(cmd_runner);
                }
            }
        }
        _swap.swap(_callbacks);
        
        ++_emits_count;
        _emits_count.notify_all();

        _lock_emit.unlock();
        return true;
    }

    void wait_emit(){
        _emits_count.wait(_emits_count);
    }

    size_t size(){
        std::lock_guard<std::mutex> lg(_lock_changes);
        return _front_changes.size() + _back_changes.size() + _callbacks->size();
    }

private:
    using Deque = std::deque<sptr<Runner<EventAction(Event<Args...>&, Args...)>>>;

    std::mutex _lock_emit;
    std::atomic<size_t> _emits_count;

    std::mutex _lock_changes;
    uptr<Deque> _callbacks;
    uptr<Deque> _swap;
    Deque _front_changes;
    Deque _back_changes;

    std::vector<std::exception_ptr> _errors;

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