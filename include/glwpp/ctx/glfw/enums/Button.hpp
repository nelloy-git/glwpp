#pragma once

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace glwpp::input {

enum class MouseBtn {
    BUTTON_1 = GLFW_MOUSE_BUTTON_1,
    BUTTON_2 = GLFW_MOUSE_BUTTON_2,
    BUTTON_3 = GLFW_MOUSE_BUTTON_3,
    BUTTON_4 = GLFW_MOUSE_BUTTON_4,
    BUTTON_5 = GLFW_MOUSE_BUTTON_5,
    BUTTON_6 = GLFW_MOUSE_BUTTON_6,
    BUTTON_7 = GLFW_MOUSE_BUTTON_7,
    BUTTON_8 = GLFW_MOUSE_BUTTON_8,
    BUTTON_LAST = GLFW_MOUSE_BUTTON_LAST,
    BUTTON_LEFT = GLFW_MOUSE_BUTTON_LEFT,
    BUTTON_RIGHT = GLFW_MOUSE_BUTTON_RIGHT,
    BUTTON_MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE,
};

}