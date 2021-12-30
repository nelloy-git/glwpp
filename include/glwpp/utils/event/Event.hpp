#pragma once

#include <list>
#include <functional>
#include <mutex>

#include "glwpp/utils/FuncWrapper.hpp"
#include "glwpp/utils/container/CounterList.hpp"
#include "glwpp/utils/event/EventThreadPool.hpp"

namespace glwpp {

template<class ... Args>
class Event final {
public:
    using Callback = std::function<void(Args...)>;

    Event(sptr<thread_pool> th_pool = EventThreadPool::get()) :
        _pool(th_pool){
        _undone = make_sptr<std::atomic<size_t>>(0);
    }
    Event(Event&) = delete;
    Event(Event&&) = delete;
    Event(const Event&) = delete;
    Event(const Event&&) = delete;

    ~Event(){
        while (*_undone != 0){
            _undone->wait(1);
        }
    }

    void insertPtr(int i, wptr<Callback> wcb, int emits = -1){
        std::lock_guard lg(_lock);
        _list.insert(i, wcb, emits);
    }

    void pushPtr(wptr<Callback> wcb, int emits = -1){
        std::lock_guard lg(_lock);
        _list.insert(_list.size(), wcb, emits);
    }

    template<class F>
    sptr<Callback> push(const F& callback, int emits = -1){
        auto cb = func_wrap<Args...>(std::function(callback));
        auto watcher = make_sptr<Callback>(cb);
        pushPtr(watcher, emits);
        return watcher;
    }

    void changeEmits(int i, int emits){
        std::lock_guard lg(_lock);
        _list.changeCounter(i, emits);
    }

    void changeEmits(wptr<Callback> wcb, int emits){
        std::lock_guard lg(_lock);
        
        for (auto iter = _list->begin(); iter != _list->end(); ++iter){
            if (!wcb.owner_before(iter->first) && !iter->first.owner_before(wcb)){
                iter->second = emits;
            }
        }
    }

    void remove(int i){
        std::lock_guard lg(_lock);
        _list.remove(i);
    }

    void clear(){
        std::lock_guard lg(_lock);
        _list.clear();
    }

    template<class Cond>
    void clear(const Cond &remove_condition){
        std::lock_guard lg(_lock);
        _list.clear(remove_condition);
    }

    std::vector<std::future<bool>> emit(const Args&... args){
        sptr<CounterList<wptr<Callback>>> slist;
        {
            std::lock_guard lg(_lock);
            _list.reduceAll(_isExpired);
            slist = make_sptr<CounterList<wptr<Callback>>>(_list);
            *_undone = *_undone + slist->size();
        }
        
        std::vector<std::future<bool>> results;
        for (auto iter = slist->begin(); iter != slist->end(); ++iter){
            results.push_back(_pool->submit(_execute, iter->first, _undone, args...));
        }
        return results;
    }

    size_t undone(){
        return *_undone;
    }

private:
    sptr<thread_pool> _pool;

    std::mutex _lock;
    CounterList<wptr<Callback>> _list;
    sptr<std::atomic<size_t>> _undone;

    static bool _isExpired(const std::pair<wptr<Callback>, int> &pair){
        return pair.first.expired() || pair.second == 0;
    };

    static bool _execute(wptr<Callback> wcb,
                         sptr<std::atomic<size_t>> undone,
                         Args ... args){
        auto cb = wcb.lock();

        bool is_valid = cb ? true : false;
        if (is_valid){
            try {
                (*cb)(args...);
            } catch (...){
                --(*undone);
                undone->notify_all();
                throw;
            }
        }
        --(*undone);
        undone->notify_all();
        return is_valid;
    };
    
};

}