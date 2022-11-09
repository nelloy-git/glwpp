#pragma once

#include <atomic>
#include <functional>
#include <string>

#include "glwpp/glfw/Window.hpp"
#include "glwpp/utils/event/Event.hpp"

namespace glwpp {

class Context {
    sptr<thread_pool> _gl_thread;
public:
    struct Parameters {
        int gl_major_ver;
        int gl_minor_ver;

        int width;
        int height;
        int fps;
        std::string title;
    };

    Context(const Parameters &params);
    virtual ~Context();

    bool start();
    void wait();
    std::thread::id getThreadId() const;

    // gl thread
    Event<Context*, std::chrono::microseconds> onRun;
    Event<Context*> onDetsroy;

    // Non-gl thread
    Event<Context*> onRunEnd;
    Event<Context*, int, int> onWinMove;
    Event<Context*, int, int> onWinResize;
    Event<Context*> onWinClose;
    Event<Context*> onWinRefresh;
    Event<Context*, bool> onWinIconify;
    Event<Context*, bool> onWinMaximize;
    Event<Context*, float, float> onWinScale;
    Event<Context*, int, int> onFramebufferResize;

    Event<Context*, bool> onCursorFocus;
    Event<Context*, bool> onCursorEnter;
    Event<Context*, double, double> onCursorMove;
    Event<Context*, Button, Action, ModFlags> onCursorButton;
    Event<Context*, double, double> onCursorScroll;

    Event<Context*, Key, int, Action, ModFlags> onKey;
    Event<Context*, unsigned int, ModFlags> onChar;

    
private:
    Parameters _params;
    uptr<glfw::Window> _glfw_window;
    std::atomic<bool> _valid;
    std::thread::id _thread_id;
    std::chrono::steady_clock::time_point _last_start;

    void _initGlfwWindow();

    template<auto setter, class ... Args>
    void _bindGlfwCallback(Event<Context*, Args...> &event){
        std::function<void(glfw::Window*, Args...)> func = [this, &event](glfw::Window*, Args... args){
            event.emit(this, args...);
        };
        (this->_glfw_window.get()->*setter)(func);
    };
};



}