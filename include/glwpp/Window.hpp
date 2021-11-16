#pragma once

#include <memory>

#include "glwpp/ctx/Context.hpp"

// #include "glwpp/Model.hpp"

namespace glwpp::input {
    class Keyboard;
    class Mouse;
    class SystemCall;
}

namespace glwpp {

class Window {
public:
    struct Params {
        Params(){};
        bool with_keyboard = true;
        bool with_mouse = true;
        bool with_syscalls = true;
    };

    Window(const Context::Parameters &ctx_params,
           const Window::Params &win_params = Params{});

    const Window::Params params;

    std::weak_ptr<Context> getContext();
    std::weak_ptr<input::Keyboard> getKeyboard();
    std::weak_ptr<input::Mouse> getMouse();
    std::weak_ptr<input::SystemCall> getSysCall();

private:
    std::shared_ptr<Context> _context;
    std::shared_ptr<input::Keyboard> _keyboard;
    std::shared_ptr<input::Mouse> _mouse;
    std::shared_ptr<input::SystemCall> _sys_call;

};


}