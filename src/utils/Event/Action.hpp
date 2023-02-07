#pragma once

#include <functional>
#include <stdint.h>

#include "utils/SrcLoc.hpp"

namespace glwpp::detail {

template<typename... Args>
class EventActionBase {
public:
    using ID = uint64_t;
    using Func = std::function<bool(Args...)>;

    EventActionBase(const ID& id, const SrcLoc& src_loc) :
        _id(id),
        _src_loc(src_loc){
    }
    EventActionBase(const EventActionBase&) = delete;
    EventActionBase(EventActionBase&&) = default;
    virtual ~EventActionBase(){};

    virtual const Func& func() const = 0;

    const ID& id() const {
        return _id;
    }

    const SrcLoc& src_loc() const {
        return _src_loc;
    };

private:
    const ID _id;
    const SrcLoc _src_loc;
};

template<auto F, typename... Args>
class EventAction : public EventActionBase<Args...> {
public:
    using ID = EventActionBase<Args...>::ID;
    using Func = EventActionBase<Args...>::Func;

private:
    static inline const Func _F = F;

public:
    EventAction(const ID& id, const SrcLoc& src_loc) :
        EventActionBase<Args...>(id, src_loc){
    }

    const Func& func() const override {
        return _F;
    }
};

template<typename... Args>
class EventAction<nullptr, Args...> : public EventActionBase<Args...>{
public:
    using ID = EventActionBase<Args...>::ID;
    using Func = EventActionBase<Args...>::Func;

    EventAction(const ID& id, Func&& action_func, const SrcLoc& src_loc) :
        EventActionBase<Args...>(id, src_loc),
        _func(std::forward<decltype(action_func)>(action_func)){
    }

    const Func& func() const override {
        return _func;
    }

private:
    const Func _func;
};

} // namespace glwpp