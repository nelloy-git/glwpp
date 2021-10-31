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
    Window(const Context::Params &win_params);

    Context& context();
    input::Keyboard& keyboard();
    input::Mouse& mouse();
    input::SystemCall& sys_call();

private:
    std::unique_ptr<Context> _context;
    std::unique_ptr<input::Keyboard> _keyboard;
    std::unique_ptr<input::Mouse> _mouse;
    std::unique_ptr<input::SystemCall> _sys_call;

};


}