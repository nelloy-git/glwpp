#include "glwpp/ctx/Context.hpp"

#include <iostream>
#include <exception>

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include <iostream>
using namespace glwpp;

Context::Context(const Parameters &params) :
    _gl_thread(std::make_shared<thread_pool>(1)),
    _params(params),
    _valid(true),
    _last_start(std::chrono::steady_clock::now()),
    onFrame(_gl_thread),
    onDetsroy(_gl_thread){

    auto future = _gl_thread->submit([this](){
        _initGlfwWindow();
    });
    _gl_thread->wait_for_tasks();
    _gl_thread->paused = true;
}

Context::~Context(){
    _valid = false;
    wait();
}

bool Context::start(){
    static std::function<void(std::chrono::microseconds)> event = [this](std::chrono::microseconds dt){
        onFrame.emit(this, dt);
    };

    if (!_valid || !_gl_thread->paused){
        return false;
    }

    auto now = std::chrono::steady_clock::now();
    auto dt = std::chrono::duration_cast<std::chrono::microseconds>(now - _last_start);
    _last_start = now;

    _gl_thread->submit(event, dt);
    _gl_thread->paused = false;
    return true;
}

void Context::wait(){
    _gl_thread->wait_for_tasks();
}

void Context::_initGlfwWindow(){
    std::vector<std::pair<int, int>> hints = {
        {GLFW_VERSION_MAJOR, _params.gl_major_ver},
        {GLFW_VERSION_MINOR, _params.gl_minor_ver},
    };

    _glfw_window = std::make_unique<glfw::Window>(
        _params.width, _params.height, _params.title.c_str(), hints
    );
    
    _bindGlfwCallback<&glfw::Window::setMoveCallback>(onWinMove);
    _bindGlfwCallback<&glfw::Window::setResizeCallback>(onWinResize);
    _bindGlfwCallback<&glfw::Window::setCloseCallback>(onWinClose);
    _bindGlfwCallback<&glfw::Window::setRefreshCallback>(onWinRefresh);
    _bindGlfwCallback<&glfw::Window::setIconifyCallback>(onWinIconify);
    _bindGlfwCallback<&glfw::Window::setMaximizeCallback>(onWinMaximize);
    _bindGlfwCallback<&glfw::Window::setScaleCallback>(onWinScale);
    _bindGlfwCallback<&glfw::Window::setFramebufferResizeCallback>(onFramebufferResize);

    _bindGlfwCallback<&glfw::Window::setCursorFocusCallback>(onCursorFocus);
    _bindGlfwCallback<&glfw::Window::setCursorMoveCallback>(onCursorMove);
    _bindGlfwCallback<&glfw::Window::setCursorEnterCallback>(onCursorEnter);
    _bindGlfwCallback<&glfw::Window::setCursorButtonCallback>(onCursorButton);
    _bindGlfwCallback<&glfw::Window::setCursorScrollCallback>(onCursorScroll);
    _bindGlfwCallback<&glfw::Window::setKeyCallback>(onKey);
    _bindGlfwCallback<&glfw::Window::setCharCallback>(onChar);
}

// template<auto setter, class ... Args>
// void _bindGlfwCallback(Event<Context*, Args...> &event){
//     std::function<void(glfw::Window*, Args...)> func = [this, &event](glfw::Window*, Args... args){
//         event.emit(this, args...);
//     };
//     (this->_glfw_window->*setter)(func);
// }