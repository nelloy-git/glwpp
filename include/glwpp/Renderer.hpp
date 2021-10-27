#pragma once

#include "glwpp/ctx/Window.hpp"

namespace glwpp {

class Renderer {
public:
    Renderer(const ctx::Window::Params &win_params) : 
        window(win_params){
        
    };



    ctx::Window window;

private:
    std::queue<std::function<void()>> _init_queue;

};


}