#pragma once

#include <queue>

#include "utils/Event/Action.hpp"

namespace glwpp::detail {

template<typename ... Args>
class EventActionQueue {
public:
    using ActionBase = EventActionBase<Args...>;
    template<auto F>
    using ActionConstexpr = EventAction<F, Args...>;
    using ActionRuntime = EventAction<nullptr, Args...>;
    
    using ID = ActionBase::ID;

    EventActionQueue(){};
    virtual ~EventActionQueue(){};

    template<auto F>
    void add(const int& priority, const ID& id, const SrcLoc& src_loc){
        auto it = _map.find(priority);
        if (it == _map.end()){
            it = _map.emplace(std::piecewise_construct,
                              std::forward_as_tuple(priority),
                              std::forward_as_tuple()).first;
        }
        it->second.emplace_back(new ActionConstexpr<F>(id, src_loc));
    }
    
    void add(const int& priority, const ID& id, std::function<bool(Args...)>&& action_func, const SrcLoc& src_loc){
        auto it = _map.find(priority);
        if (it == _map.end()){
            it = _map.emplace(std::piecewise_construct,
                              std::forward_as_tuple(priority),
                              std::forward_as_tuple()).first;
        }
        it->second.emplace_back(new ActionRuntime(id, std::forward<decltype(action_func)>(action_func), src_loc));
    }

    bool remove(const ID& id){
        for (auto priority = _map.begin(); priority != _map.end();){
            auto& actions = priority->second;
            for (auto it = actions.begin(); it != actions.end(); ++it){
                if (it->id() == id){
                    actions.erase(it);
                    return true;
                }
            }
        }
        return false;
    }
    
    void emit(Args&&... args){
        for (auto priority = _map.begin(); priority != _map.end();){
            auto& actions = priority->second;
            for (auto it = actions.begin(); it != actions.end();){
                auto& ptr = *it;
                if (!ptr->func()(std::forward<Args>(args)...)){
                    it = actions.erase(it);
                } else {
                    ++it;
                }
            }

            if (actions.size() == 0)
                priority = _map.erase(priority);
            else
                ++priority;
        }
    }

private:
    using PriorityElem = std::deque<std::unique_ptr<ActionBase>>;
    using PriorityMap = std::map<int, PriorityElem, std::greater<int>>;

    PriorityMap _map;
};

} // namespace glwpp