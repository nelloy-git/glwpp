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
    onRun(_gl_thread),
    onDetsroy(_gl_thread){

    _gl_thread->submit([this](){
        _initGlfwWindow();
    });
    _gl_thread->paused = false;
    _gl_thread->wait_for_tasks();
    _gl_thread->paused = true;
}

Context::~Context(){
    static std::function<void()> event = [this](){
        onDetsroy.emit(this);
    };

    _valid = false;
    _gl_thread->paused = false;
    _gl_thread->wait_for_tasks();
    _gl_thread->submit(event);
    _gl_thread->wait_for_tasks();
}

bool Context::start(){
    static std::function<void(std::chrono::microseconds)> event = [this](std::chrono::microseconds dt){
        glfwPollEvents();
        _glfw_window->swapBuffers();
        _gl_thread->paused = true;
    };
    static std::function<void()> clear = [this](){
        onRunEnd.emit(this);
    };

    if (!_valid || !_gl_thread->paused){
        return false;
    }

    auto now = std::chrono::steady_clock::now();
    auto dt = std::chrono::duration_cast<std::chrono::microseconds>(now - _last_start);
    _last_start = now;

    _gl_thread->submit(clear);
    onRun.emit(this, dt);
    _gl_thread->submit(event, dt);
    _gl_thread->paused = false;
    return true;
}

void Context::wait(){
    _gl_thread->wait_for_tasks();
}

std::thread::id Context::getThreadId() const {
    return _thread_id;
}

void Context::_initGlfwWindow(){
    _thread_id = std::this_thread::get_id();

    std::vector<std::pair<int, int>> hints = {
        {GLFW_VERSION_MAJOR, _params.gl_major_ver},
        {GLFW_VERSION_MINOR, _params.gl_minor_ver},
        {GLFW_CONTEXT_VERSION_MAJOR, _params.gl_major_ver},
        {GLFW_CONTEXT_VERSION_MINOR, _params.gl_minor_ver},
        {GLFW_REFRESH_RATE, _params.fps},
    };

    _glfw_window = std::make_unique<glfw::Window>(
        _params.width, _params.height, _params.title.c_str(), hints
    );
    printf("%s\n", glGetString(GL_VERSION));
    
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