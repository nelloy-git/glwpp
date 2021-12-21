#pragma once

namespace glwpp {

enum class Action {
    Release,
    Press,
    Repeat,
    Unknown
};

Action toAction(int glfw_action);
    
} // namespace glwpp
