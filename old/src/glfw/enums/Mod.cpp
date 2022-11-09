#include "glwpp/glfw/enums/Mod.hpp"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace {
    int toGlfw(glwpp::Mod mod){
        switch (mod){
            case glwpp::Mod::Shift: return GLFW_MOD_SHIFT;
            case glwpp::Mod::Control: return GLFW_MOD_CONTROL;
            case glwpp::Mod::Alt: return GLFW_MOD_ALT;
            case glwpp::Mod::Super: return GLFW_MOD_SUPER;
            case glwpp::Mod::CapsLock: return GLFW_MOD_CAPS_LOCK;
            case glwpp::Mod::NumLock: return GLFW_MOD_NUM_LOCK;
            default: return 0;
        }
    }
};

glwpp::ModFlags::ModFlags(int glfw_mods) :
    flags(glfw_mods){
}

bool glwpp::ModFlags::isMod(glwpp::Mod mod){
    return flags & toGlfw(mod);
}

glwpp::ModFlags glwpp::toModFlags(int glfw_mods){
    return glwpp::ModFlags(glfw_mods);
}