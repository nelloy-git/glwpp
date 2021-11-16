#pragma once

#include "glwpp/utils/event/EventBase.hpp"

namespace glwpp {

template<class ... Args>
class WEvent final {
public:
    WEvent(std::weak_ptr<EventBase<Args...>> event,
           std::weak_ptr<CmdWatcher> watcher) :
        _event(event),
        _watcher(watcher){
    };

    template<class F>
    bool pushBack(std::weak_ptr<CmdWatcher> watcher, F cmd){
        auto e = _event.lock();
        if (!e) return false;

        return _event->pushBack(watcher, cmd);
    }

    template<class F>
    bool pushFront(std::weak_ptr<CmdWatcher> watcher, F cmd){
        auto event = _event.lock();
        if (!event) return false;

        return _event->pushFront(watcher, cmd);
    }

    template<class ... Other>
    bool captureBack(const WEvent<Other...> &other, bool once){
        auto event = _event.lock();
        if (!event) return false;

        auto other_event = other._event.lock();
        if (!other_event) return false;

        return other_event->pushBack(_watcher, once ? _capture_once : _capture_repeatly);
    }

    template<class ... Other>
    bool captureFront(const WEvent<Other...> &other, bool once){
        auto event = _event.lock();
        if (!event) return false;

        auto other_event = other._event.lock();
        if (!other_event) return false;

        return other_event->pushFront(_watcher, once ? _capture_once : _capture_repeatly);
    }

private:
    std::weak_ptr<EventBase<Args...>> _event;
    std::weak_ptr<CmdWatcher> _watcher;

    std::function<CmdAct(Args&&...)> _capture_once = [this](Args&&... args){
        auto event = _event.lock();
        if (!event) return CmdAct::Stop;

        event->emit(std::forward<Args>(args)...);
        return CmdAct::Stop;
    };
    
    std::function<CmdAct(Args&&...)> _capture_repeatly = [this](Args&&... args){
        auto event = _event.lock();
        if (!event) return CmdAct::Stop;

        event->emit(std::forward<Args>(args)...);
        return CmdAct::Repeat;
    };
};

}