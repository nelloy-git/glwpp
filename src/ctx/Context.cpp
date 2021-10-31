#include "glwpp/ctx/Context.hpp"

#include <iostream>
#include <exception>

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

using namespace glwpp;

// Statics

// std::unordered_map<GLFWwindow*, Context*> Context::_glfw2win;

// Methods

Context::Context(const Params &params) :
    cmd_queue([this](){_cmdQueueInit();},
               [this](){_cmdQueueFinal();}),
    _params(params){
}

Context::~Context(){
    // _glfw2win.erase(_glfw_window);
    glfwDestroyWindow(_glfw_window);
}

// void Window::swapBuffers(){
//     _cmd_queue.push([this](){
//         glfwSwapBuffers(_glfw_window);
//     });
//     _cmd_queue.execute();
// }

void Context::_initEvents(){

    // glfwSetWindowCloseCallback(_glfw_window, [](GLFWwindow* glfw_win){
    //     std::cout << "Close" << std::endl;
    // });

    // glfwSetCursorEnterCallback(_glfw_window, [](GLFWwindow* glfw_win, int entered){
    //     auto win = _glfw2win[glfw_win];
    //     if (entered == GLFW_TRUE){
    //         win->mouse.onEnter.emit(win->mouse);
    //     } else {
    //         win->mouse.onLeave.emit(win->mouse);
    //     }
    // });

    // glfwSetCursorPosCallback(_glfw_window, [](GLFWwindow* glfw_win, double x, double y){
    //     auto win = _glfw2win[glfw_win];
    //     win->mouse.move(x, y);
    // });

    // glfwSetMouseButtonCallback(_glfw_window, [](GLFWwindow* glfw_win, int btn, int pressed, int mode){
    //     auto win = _glfw2win[glfw_win];
    //     if (pressed == GLFW_PRESS){
    //         win->mouse.press(static_cast<MouseBtn>(btn), mode);
    //     } else if (pressed == GLFW_RELEASE) {
    //         win->mouse.release(static_cast<MouseBtn>(btn), mode);
    //     } 
    // });
    
    // glfwSetKeyCallback(_glfw_window, [](GLFWwindow* glfw_win, int key, int scancode, int action, int mode){
    //     auto win = _glfw2win[glfw_win];
    //     if (action == GLFW_PRESS){
    //         win->keyboard.press(static_cast<Key>(key), mode);
    //     } else if (action == GLFW_RELEASE){
    //         win->keyboard.release(static_cast<Key>(key), mode);
    //     }
    // });
}

void Context::_cmdQueueInit(){
    if (glfwInit() == GL_FALSE){
        throw std::runtime_error("Failed to initialize GLFW.");
    }

    glfwWindowHint(GLFW_VERSION_MAJOR, _params.gl_major_ver);
    glfwWindowHint(GLFW_VERSION_MINOR, _params.gl_minor_ver);
    _glfw_window = glfwCreateWindow(_params.width,
                                    _params.height,
                                    _params.title.c_str(),
                                    NULL, NULL);
    // _glfw2win[_glfw_window] = this;

    glfwMakeContextCurrent(_glfw_window);
    auto ver = gladLoadGL(glfwGetProcAddress);
    if (ver == 0){
        throw std::runtime_error("Failed to initialize OpenGL context.");
    }

    _initEvents();
}

void Context::_cmdQueueFinal(){
    glfwTerminate();
}