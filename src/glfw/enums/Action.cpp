#include "glwpp/glfw/enums/Action.hpp"

#define GLFW_INCLUDE_NONE
#include "glfw/glfw3.h"

using namespace glwpp;

glfw::Action glfw::toAction(int glfw_action){
    switch (glfw_action){
        case GLFW_PRESS: return glfw::Action::Press;
        case GLFW_RELEASE: return glfw::Action::Release;
        case GLFW_REPEAT: return glfw::Action::Repeat;
        default: return glfw::Action::Unknown;
    }
}