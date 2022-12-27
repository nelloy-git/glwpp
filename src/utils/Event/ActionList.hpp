#pragma once

#include "utils/Event/Action.hpp"

namespace glwpp::detail {

template<typename ... Args>
class EventActionList {
public:
    using ActionBase = typename EventActionBase<Args...>;
    template<auto F>
    using ActionConstexpr = EventAction<F, Args...>;
    using ActionRuntime = typename EventAction<nullptr, Args...>;
    
    using ID = ActionBase::ID;

    EventActionList(){};
    virtual ~EventActionList(){};

    template<auto F>
    void add(const ID& id, const SrcLoc& src_loc){
        _actions.emplace_back(new ActionConstexpr<F>(id, src_loc));
    }
    
    void add(const ID& id, std::function<bool(Args...)>&& action_func, const SrcLoc& src_loc){
        _actions.emplace_back(new ActionRuntime(id, std::forward<decltype(action_func)>(action_func), src_loc));
    }

    bool remove(const ID& id){
        for (auto it = _actions.begin(); it != _actions.end(); ++it){
            if (it->id() == id){
                _actions.erase(it);
                return true;
            }
        }
        return false;
    }
    
    void emit(Args&&... args){
        for (auto it = _actions.begin(); it != _actions.end();){
            auto& ptr = *it;
            if (!ptr->func()(std::forward<Args>(args)...))
                it = _actions.erase(it);
            else
                ++it;
        }
    }

private:
    std::deque<std::unique_ptr<EventActionBase<Args...>>> _actions;
};

} // namespace glwpp