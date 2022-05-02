#pragma once

#include <atomic>
#include <deque>
#include <functional>
#include <mutex>

#include "glwpp/utils/FuncWrapper.hpp"
#include "glwpp/utils/SrcLoc.hpp"
#include "glwpp/utils/event/EventThreadPool.hpp"

namespace glwpp {

template<class ... Args>
class Event final {
    using Action = std::function<void(Args...)>;
    using Condition = std::function<bool(Args...)>;
    using ActionData = std::tuple<sptr<Condition>, sptr<Action>, sptr<SrcLoc>>;

public:
    Event(const sptr<thread_pool>& th_pool = EventThreadPool::get()) :
        _pool(th_pool){
        _list = make_sptr<std::deque<ActionData>>();
    }
    Event(const Event&) = delete;
    Event(const Event&&) = delete;

    ~Event(){}

    // Both action and condition are constexpr
    template<auto F, auto C = nullptr>
    void push(const SrcLoc loc = SrcLoc()){
        static constexpr auto expanded_condition = _expandCondition<C>();
        static constexpr auto expanded_action = expand_func<F, Args...>();
        
        sptr<Condition> condition;
        if constexpr (C != nullptr){
            condition = make_sptr<Condition>(expanded_condition);
        }
        auto action = make_sptr<Action>(expanded_action);
        auto ploc = make_sptr<SrcLoc>(loc);

        _push(condition, action, ploc);
    }

    // Condition is constexpr, emit once by default
    template<auto C = nullptr, class F>
    void push(const F& event_action, const SrcLoc loc = SrcLoc()){
        static constexpr auto expanded_condition = _expandCondition<C>();
        auto expanded_action = expand_func<Args...>(event_action);
        
        sptr<Condition> condition;
        if constexpr (C != nullptr){
            condition = make_sptr<Condition>(expanded_condition);
        }
        auto action = make_sptr<Action>(expanded_action);
        auto ploc = make_sptr<SrcLoc>(loc);

        _push(condition, action, ploc);
    }

    // Everything is runtime
    template<class F, class C>
    void push(const F& event_action, const C& alive_condition, const SrcLoc loc = SrcLoc()){
        auto expanded_condition = expand_func<Args...>(alive_condition);
        auto expanded_action = expand_func<Args...>(event_action);

        auto condition = make_sptr<Condition>(expanded_condition);
        auto action = make_sptr<Action>(expanded_action);
        auto ploc = make_sptr<SrcLoc>(loc);

        _push(condition, action, ploc);
    }

    std::future<bool> emit(const Args&... args){
        auto divided = _divideList(args...);
        return _pool->submit([divided](const Args&... args){
            for (auto& data : *divided.to_do){
                try {
                    (*std::get<1>(data))(args...);
                } catch (const std::exception& e){
                    std::cout << e.what() << std::endl;
                }
            }
        }, args...);
    }

    size_t size(){
        std::lock_guard lg(_lock);
        return _list->size();
    }

private:
    sptr<thread_pool> _pool;

    std::mutex _lock;
    sptr<std::deque<ActionData>> _list;

    void _push(const sptr<std::function<bool(Args...)>>& condition,
               const sptr<std::function<void(Args...)>>& action,
               const sptr<SrcLoc>& loc){
        std::lock_guard lg(_lock);
        _list->push_back(std::make_tuple(condition, action, loc));
    }

    struct DividedList {
        sptr<std::deque<ActionData>> to_do;
        sptr<std::deque<ActionData>> to_clear;
    };

    DividedList _divideList(const Args&... args){
        DividedList divided;
        divided.to_do = make_sptr<std::deque<ActionData>>();
        divided.to_clear = make_sptr<std::deque<ActionData>>();

        std::lock_guard lg(_lock);
        auto iter = _list->begin();
        while(iter != _list->end()){
            auto &data = *iter;
            auto cond = std::get<0>(data);
            // No condition => execute once
            if (!cond){
                divided.to_do->push_back(*iter);
                iter = _list->erase(iter);
                continue;
            } else {
                bool alive = (*cond)(args...);
                if (alive){
                    divided.to_do->push_back(*iter);
                    ++iter;
                } else {
                    divided.to_clear->push_back(*iter);
                    iter = _list->erase(iter);
                }
            }
        }

        return divided;
    }

    template<auto C>
    static constexpr auto _expandCondition(){
        if constexpr (C != nullptr){
            return expand_func<C, Args...>();
        } else {
            return nullptr;
        }
    }
};

}