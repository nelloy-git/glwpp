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

namespace glwpp::ctx {



class Window {
public:
    struct Params {
        int gl_major_ver;
        int gl_minor_ver;

        size_t width;
        size_t height;
        std::string title;
    };

    Window(const Params &params);
    virtual ~Window();

    inline operator GLFWwindow*(){
        return _glfw_window;
    }

    Event<const Window&> onClose;
    using onCloseCB = decltype(onClose)::Func;

    CmdQueue gl_context;
    Keyboard keyboard;
    Mouse mouse;

private:
    void _initEvents();
    void _cmdQueueInit();
    void _cmdQueueFinal();
    GLFWwindow *_glfw_window;
    Params _params;
    
    static std::unordered_map<GLFWwindow*, Window*> _glfw2win;
};

}