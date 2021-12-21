#pragma once

#include <list>
#include <functional>
#include <mutex>

#include "glwpp/utils/container/CounterList.hpp"
#include "glwpp/utils/event/EventThreadPool.hpp"

namespace glwpp {

template<class ... Args>
class Event final {
public:
    using Callback = std::function<void(Args...)>;

    Event(sptr<thread_pool> th_pool = EventThreadPool::get()) :
        _pool(th_pool){
    }
    Event(Event&) = delete;
    Event(Event&&) = delete;
    Event(const Event&) = delete;
    Event(const Event&&) = delete;

    ~Event(){
    }

    const CounterList<wptr<Callback>>& list(){
        return _list;
    }

    std::future<bool> emit(const Args&... args){
        _list.clear(_isExpired);
        auto slist = std::make_shared<CounterList<wptr<Callback>>>(_list);
        return _pool->submit(_execute, slist, args...);
    }

private:
    sptr<thread_pool> _pool;
    CounterList<wptr<Callback>> _list;

    static bool _isExpired(const wptr<Callback> &weak_cb){
        return weak_cb.expired();
    };

    static bool _execute(sptr<CounterList<wptr<Callback>>> slist, Args ... args){
        for (auto iter = slist->begin(); iter != slist->end(); ++iter){
            auto cb = iter->first.lock();
            if (!cb) continue;
            (*cb)(args...);
        }
        return true;
    };
    
};

}