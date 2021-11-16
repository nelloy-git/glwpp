#pragma once

#include "glwpp/utils/event/WEvent.hpp"

namespace glwpp {

template<class ... Args>
class SEvent final {
public:
    SEvent(){
        _event = std::make_shared<EventBase<Args...>>();
        _watcher = std::make_shared<CmdWatcher>();
    };

    operator WEvent<Args...>(){
        return WEvent<Args...>(_event, _watcher);
    };

    template<class F>
    inline bool pushBack(std::weak_ptr<CmdWatcher> watcher, F cmd){
        return _event->pushBack(watcher, cmd);
    }

    template<class F>
    inline bool pushFront(std::weak_ptr<CmdWatcher> watcher, F cmd){
        return _event->pushFront(watcher, cmd);
    }

    template<class ... Other>
    inline bool captureBack(const WEvent<Other...> &other, bool once){
        auto event = _event.lock();
        if (!event) return false;

        auto other_event = other._event.lock();
        if (!other_event) return false;

        return other_event->pushBack(_watcher, once ? _capture_once : _capture_repeatly);
    }

    template<class ... Other>
    inline bool captureFront(const WEvent<Other...> &other, bool once){
        auto other_event = other._event.lock();
        if (!other_event) return false;

        return other_event->pushFront(_watcher, once ? _capture_once : _capture_repeatly);
    }

private:
    std::shared_ptr<EventBase<Args...>> _event;
    std::shared_ptr<CmdWatcher> _watcher;

    std::function<CmdAct(Args&&...)> _capture_once = [this](Args&&... args){
        emit(std::forward<Args>(args)...);
        return CmdAct::Stop;
    };
    
    std::function<CmdAct(Args&&...)> _capture_repeatly = [this](Args&&... args){
        emit(std::forward<Args>(args)...);
        return CmdAct::Repeat;
    };
};

}