#include "glwpp/glfw/enums/Button.hpp"

#define GLFW_INCLUDE_NONE
#include "glfw/glfw3.h"

glwpp::Button glwpp::toButton(int glfw_button){
    switch (glfw_button){
        case GLFW_MOUSE_BUTTON_LEFT: return glwpp::Button::Left;
        case GLFW_MOUSE_BUTTON_RIGHT: return glwpp::Button::Right;
        case GLFW_MOUSE_BUTTON_MIDDLE: return glwpp::Button::Middle;
        case GLFW_MOUSE_BUTTON_4: return glwpp::Button::Button_4;
        case GLFW_MOUSE_BUTTON_5: return glwpp::Button::Button_5;
        case GLFW_MOUSE_BUTTON_6: return glwpp::Button::Button_6;
        case GLFW_MOUSE_BUTTON_7: return glwpp::Button::Button_7;
        case GLFW_MOUSE_BUTTON_8: return glwpp::Button::Button_8;
        default: return glwpp::Button::Unknown;
    }
}