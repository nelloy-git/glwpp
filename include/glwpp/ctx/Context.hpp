#pragma once

#include <string>
#include <unordered_map>
#include <atomic>
#include <thread>
#include <mutex>

#include "glwpp/utils/CmdQueue.hpp"

class GLFWwindow;

namespace glwpp {

class Context {
public:
    struct Params {
        int gl_major_ver;
        int gl_minor_ver;

        size_t width;
        size_t height;
        std::string title;
    };

    Context(const Params &params);
    virtual ~Context();

    inline operator GLFWwindow*() const {
        return _glfw_window;
    }

    // Event<const Context&> onClose;
    // using onCloseCB = decltype(onClose)::Func;

    CmdQueue cmd_queue;
    // Keyboard keyboard;
    // Mouse mouse;
    
    GLFWwindow *_glfw_window;

private:
    void _initEvents();
    void _cmdQueueInit();
    void _cmdQueueFinal();
    Params _params;
    
    static std::unordered_map<GLFWwindow*, Context*> _glfw2win;
};

}