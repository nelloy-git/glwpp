#pragma once

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace glwpp::glfw {

enum class Action {
    PRESS = GLFW_PRESS,
    RELEASE = GLFW_RELEASE,
    REPEAT = GLFW_REPEAT,
};
    
} // namespace glwpp::glfw
