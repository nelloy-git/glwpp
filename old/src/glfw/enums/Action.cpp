#include "glwpp/glfw/enums/Action.hpp"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

glwpp::Action glwpp::toAction(int glfw_action){
    switch (glfw_action){
        case GLFW_PRESS: return glwpp::Action::Press;
        case GLFW_RELEASE: return glwpp::Action::Release;
        case GLFW_REPEAT: return glwpp::Action::Repeat;
        default: return glwpp::Action::Unknown;
    }
}