#pragma once

#include <string>
#include <unordered_map>
#include <atomic>
#include <thread>
#include <mutex>

#include "glwpp/utils/CmdQueue.hpp"

#include "glwpp/ctx/Keyboard.hpp"
#include "glwpp/ctx/Mouse.hpp"
// #include "Context/Mouse.h"

// #include "Context/Event.h"

class GLFWwindow;

namespace glwpp {

struct WindowParams {
    int gl_major_ver;
    int gl_minor_ver;

    size_t width;
    size_t height;
    std::string title;
};

class Window {
public:
    Window(const WindowParams &params);
    virtual ~Window();

    void swapBuffers();
    inline void pushCmd(CmdQueue::Cmd cmd){
        _cmd_queue.push(cmd);
    };
    inline void wait(){
        _cmd_queue.wait();
    };

    Event<const Window&> onClose;
    using onCloseCB = decltype(onClose)::Func;

    Keyboard keyboard;
    Mouse mouse;

private:
    void _initEvents();
    void _cmdQueueInit();
    void _cmdQueueFinal();

    CmdQueue _cmd_queue;
    GLFWwindow *_glfw_window;
    WindowParams _params;
    
    static std::unordered_map<GLFWwindow*, Window*> _glfw2win;
};

}