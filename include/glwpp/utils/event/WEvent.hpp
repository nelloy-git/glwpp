#pragma once

#include "glwpp/utils/event/Event.hpp"

namespace glwpp {

template<class ... Args>
class WEvent final {
    template<class ... SArgs>
    friend class SEvent;

public:
    WEvent(wptr<Event<Args...>> event) :
        _event(event){
    }

    template<class F>
    bool push_back(wptr<Watcher> watcher, F cmd){
        auto event = _event.lock();
        if (!event) return false;

        return event->push_back(watcher, cmd);
    }

    template<class F>
    bool push_front(wptr<Watcher> watcher, F cmd){
        auto event = _event.lock();
        if (!event) return false;

        return event->push_front(watcher, cmd);
    }

    inline size_t size(){
        auto event = _event.lock();
        if (!event) return 0;

        return event->size();
    }

private:
    wptr<Event<Args...>> _event;
};

}