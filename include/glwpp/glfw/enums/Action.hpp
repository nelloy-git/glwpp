#pragma once

namespace glwpp::glfw {

enum class Action {
    Release,
    Press,
    Repeat,
    Unknown
};

Action toAction(int glfw_action);
    
} // namespace glwpp::glfw
