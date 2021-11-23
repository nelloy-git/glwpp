#pragma once

#include "glwpp/utils/event/WEvent.hpp"

namespace glwpp {

template<class ... Args>
class SEvent final {
public:
    SEvent(){
        _event = make_sptr<Event<Args...>>();
    };

    operator WEvent<Args...>(){
        return WEvent<Args...>(_event);
    };

    template<class F>
    inline bool push_back(wptr<Watcher> watcher, F cmd){
        return _event->pushBack(watcher, cmd);
    }

    template<class F>
    inline bool push_front(wptr<Watcher> watcher, F cmd){
        return _event->pushFront(watcher, cmd);
    }

    inline bool emit(bool wait, Args&&... args){
        return _event->emit(wait, std::forward<Args>(args)...);
    }

    inline size_t size(){
        return _event->size();
    }

private:
    sptr<Event<Args...>> _event;

    std::function<EventAction(Args&&...)> _capture_once = [this](Args&&... args){
        _event->emit(true, std::forward<Args>(args)...);
        return EventAction::Stop;
    };
    
    std::function<EventAction(Args&&...)> _capture_repeatly = [this](Args&&... args){
        _event->emit(true, std::forward<Args>(args)...);
        return EventAction::Continue;
    };
};

}