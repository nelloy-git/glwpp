#include "glwpp/Window.hpp"

#include "glwpp/input/Keyboard.hpp"
#include "glwpp/input/Mouse.hpp"
#include "glwpp/input/System.hpp"

using namespace glwpp;

Window::Window(const Context::Params &win_params){
    _context = std::make_unique<Context>(win_params);
    _keyboard = std::make_unique<input::Keyboard>();
    _mouse = std::make_unique<input::Mouse>();
    _sys_call = std::make_unique<input::SystemCall>();
    
    _keyboard->capture(*_context, true);
    _mouse->capture(*_context, true);
    _sys_call->capture(*_context, true);
}

Context& Window::context(){
    return *_context;
}

input::Keyboard& Window::keyboard(){
    return *_keyboard;
};

input::Mouse& Window::mouse(){
    return *_mouse;
};

input::SystemCall& Window::sys_call(){
    return *_sys_call;
};