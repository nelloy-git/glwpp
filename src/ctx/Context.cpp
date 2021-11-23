#include "glwpp/ctx/Context.hpp"

#include <iostream>
#include <exception>

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include <iostream>
using namespace glwpp;

Context::Context(const Parameters &params) :
    _params(params),
    _init_gl_thread([this](CmdLoop&){_glInit();}),
    _final_gl_thread([this](CmdLoop&){_glFinal();}),
    _loop(_init_gl_thread, _final_gl_thread){
    _watcher = make_sptr<Watcher>();

    // Links CmdLoop and Context events
    auto done = _loop.onLoopStart().push_back(_watcher, [this](){
        _onLoopStart.emit(true, *this);
        return EventAction::Continue;
    });
    std::cout << done << std::endl;
    std::cout << _loop.onLoopStart().size() << std::endl;

    _loop.onLoopRun().push_back(_watcher, [this](){
        _onLoopRun.emit(true, *this);
        return EventAction::Continue;
    });
    _loop.onLoopEnd().push_back(_watcher, [this](){
        _onLoopEnd.emit(true, *this);
        return EventAction::Continue;
    });
}

Context::~Context(){
}

void Context::_glInit(){
    std::cout << "Starting OpenGL init" << std::endl;

    if (glfwInit() == GL_FALSE){
        throw std::runtime_error("Failed to initialize GLFW.");
    }

    glfwWindowHint(GLFW_VERSION_MAJOR, _params.gl_major_ver);
    glfwWindowHint(GLFW_VERSION_MINOR, _params.gl_minor_ver);
    _glfw_window = glfwCreateWindow(_params.width,
                                    _params.height,
                                    _params.title.c_str(),
                                    NULL, NULL);

    glfwMakeContextCurrent(_glfw_window);
    auto ver = gladLoadGL(glfwGetProcAddress);
    if (ver == 0){
        throw std::runtime_error("Failed to initialize OpenGL context.");
    }

    std::cout << "OpenGL inited. Thread: " << std::this_thread::get_id() << std::endl;
}

void Context::_glFinal(){
    _onDestroy.emit(true, *this);
    glfwDestroyWindow(_glfw_window);
}

WEvent<Context&> Context::onLoopStart(){
    return _onLoopStart;
}

WEvent<Context&> Context::onLoopRun(){
    return _onLoopRun;
}

WEvent<Context&> Context::onLoopEnd(){
    return _onLoopEnd;
}

WEvent<Context&> Context::onDestroy(){
    return _onDestroy;
}