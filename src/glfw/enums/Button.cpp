#include "glwpp/glfw/enums/Button.hpp"

#define GLFW_INCLUDE_NONE
#include "glfw/glfw3.h"

using namespace glwpp;

glfw::Button glfw::toButton(int glfw_button){
    switch (glfw_button){
        case GLFW_MOUSE_BUTTON_LEFT: return glfw::Button::Left;
        case GLFW_MOUSE_BUTTON_RIGHT: return glfw::Button::Right;
        case GLFW_MOUSE_BUTTON_MIDDLE: return glfw::Button::Middle;
        case GLFW_MOUSE_BUTTON_4: return glfw::Button::Button_4;
        case GLFW_MOUSE_BUTTON_5: return glfw::Button::Button_5;
        case GLFW_MOUSE_BUTTON_6: return glfw::Button::Button_6;
        case GLFW_MOUSE_BUTTON_7: return glfw::Button::Button_7;
        case GLFW_MOUSE_BUTTON_8: return glfw::Button::Button_8;
        default: return glfw::Button::Unknown;
    }
}