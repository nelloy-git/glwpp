#include "glwpp/Window.hpp"

#include "glwpp/input/Keyboard.hpp"
#include "glwpp/input/Mouse.hpp"
#include "glwpp/input/System.hpp"

using namespace glwpp;

Window::Window(const Context::Parameters &ctx_params,
               const Window::Params &win_params) :
    params(win_params){
    _context = std::make_shared<Context>(ctx_params);

    if (params.with_keyboard){
        _keyboard = std::make_shared<input::Keyboard>();
        _keyboard->capture(_context, true);
    }

    if (params.with_mouse){
        _mouse = std::make_unique<input::Mouse>();
        _mouse->capture(_context, true);
    }

    if (params.with_syscalls){
        _sys_call = std::make_shared<input::SystemCall>();    
        _sys_call->capture(_context, true);
    }
}

std::weak_ptr<Context> Window::getContext(){
    return _context;
}

std::weak_ptr<input::Keyboard> Window::getKeyboard(){
    return _keyboard;
};

std::weak_ptr<input::Mouse> Window::getMouse(){
    return _mouse;
};

std::weak_ptr<input::SystemCall> Window::getSysCall(){
    return _sys_call;
};