#pragma once

#include "glwpp/input/System.hpp"
#include "glwpp/Window.hpp"

namespace glwpp {
 
class WindowData {
public:
    WindowData(std::weak_ptr<Window> window) :
        _window(window){

        auto lock_ptr = window.lock();
        if (window.expired() || !_isValidPtr(window)){
            throw "Empty pointer";
        }
        
        // Init gl data
        lock_ptr->context().cmd_queue.push([this](){
            _valid = _initialize();
        });

        // Free gl data
        auto &event = lock_ptr->sys_call().onClose;
        _on_close_cb = event.prepare([this](){_finalize();});
        event.push_back(_on_close_cb);
    }

    ~WindowData(){
        auto lock_ptr = _window.lock();
        if (_window.expired() || !_valid){
            return;
        }

        // Destroy gl data
        lock_ptr->context().cmd_queue.push([this](){
            _finalize();
            _valid = false;
        });
    }

    std::weak_ptr<Window> owner(){
        return _window;
    }

protected:
    template <typename T>
    bool _isValidPtr(std::weak_ptr<T> const& weak) {
        using wt = std::weak_ptr<T>;
        return !weak.owner_before(wt{}) && !wt{}.owner_before(weak);
    }

    virtual bool _initialize() = 0;
    virtual void _finalize() = 0;

private:
    std::weak_ptr<Window> _window;
    bool _valid = false;
    
    // Data lifetime ends with context or with destructor.
    decltype(input::SystemCall::onClose)::Watcher _on_close_cb;


};


}