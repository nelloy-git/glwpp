#pragma once

#include <atomic>
#include <deque>
#include <functional>
#include <mutex>

#include "glwpp/utils/FuncWrapper.hpp"
#include "glwpp/utils/event/EventStatus.hpp"
#include "glwpp/utils/event/EventThreadPool.hpp"

namespace glwpp {

template<class ... Args>
class Event final {

    template <typename T>
    struct Signature;

    template <typename R, typename... Args>
    struct Signature<std::function<R(Args...)>> {
        using type = R(Args...);
    };
    
public:
    Event(sptr<thread_pool> th_pool = EventThreadPool::get()) :
        _pool(th_pool),
        _valid(true){
        _todo_list = make_sptr<std::deque<std::function<void(Args...)>>>();
        _checker_list = make_sptr<std::deque<std::function<bool(const std::chrono::microseconds&)>>>();
    }
    Event(Event&) = delete;
    Event(Event&&) = delete;
    Event(const Event&) = delete;
    Event(const Event&&) = delete;

    ~Event(){
        _valid = false;
        std::lock_guard lg(_lock);
        auto todo_list = _todo_list;
        auto checker_list = _checker_list;

        _todo_list.reset();
        _checker_list.reset();

        _pool->push_task([todo_list, checker_list](){});
    }

    template<class F>
    auto push(const F& callback){
        using S = Signature<decltype(std::function{callback})>;
        return _push(callback, S{});
    }

    EventStatus emit(const Args&... args){
        std::lock_guard lg(_lock);
        if (!_valid) return EventStatus(false);

        auto todo_list = make_sptr<std::deque<std::function<void(Args...)>>>();
        auto checker_list = make_sptr<std::deque<std::function<bool(const std::chrono::microseconds&)>>>();

        todo_list.swap(_todo_list);
        checker_list.swap(_checker_list);

        while (!todo_list->empty()){
            _pool->push_task(todo_list->front(), args...);
            todo_list->pop_front();
        }

        return EventStatus(checker_list);
    }

    size_t size(){
        return _todo_list->size();
    }

private:
    sptr<thread_pool> _pool;

    std::atomic<bool> _valid;
    std::mutex _lock;
    sptr<std::deque<std::function<void(Args...)>>> _todo_list;
    sptr<std::deque<std::function<bool(const std::chrono::microseconds&)>>> _checker_list;
    
    template<class R>
    std::function<bool(const std::chrono::microseconds&)> _getChecker(const std::shared_future<R> &future){
        return [future](const std::chrono::microseconds &time){
            return future.wait_for(time) == std::future_status::ready;
        };
    };
    

    template<class F, class R, class ... FArgs, class FR = std::conditional_t<(std::is_void_v<R>), bool, R>>
    inline std::shared_future<FR> _push(const F& callback, Signature<std::function<R(FArgs...)>> signature){
        auto promise = make_sptr<std::promise<FR>>();
        std::shared_future<FR> future = promise->get_future();

        auto cb = [promise, func = func_wrap<Args...>(std::function(callback))](const Args&... args){
            try {
                if constexpr (std::is_same_v<R, void>){
                    func(args...);
                    promise->set_value(true);
                } else {
                    promise->set_value(func(args...));
                }
                
            } catch (...) {
                try {
                    promise->set_exception(std::current_exception());
                } catch (...) {
                }
            }
        };
        auto checker = _getChecker(future);

        std::lock_guard lg(_lock);
        _todo_list->push_back(cb);
        _checker_list->push_back(checker);
        
        return future;
    }
};

}