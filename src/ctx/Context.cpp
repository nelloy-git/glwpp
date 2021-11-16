#include "glwpp/ctx/Context.hpp"

#include <iostream>
#include <exception>

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

using namespace glwpp;

Context::Context(const Parameters &params) :
    _params(params),
    _init_gl_thread([this](CmdLoop&){_glInit();}),
    _final_gl_thread([this](CmdLoop&){_glFinal();}),
    _loop(_init_gl_thread, _final_gl_thread){
}

void Context::_glInit(){
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
    glfwDestroyWindow(_glfw_window);
}