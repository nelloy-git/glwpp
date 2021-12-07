#include "glwpp/glfw/enums/Mod.hpp"

#define GLFW_INCLUDE_NONE
#include "glfw/glfw3.h"

using namespace glwpp;

glfw::ModFlags::ModFlags(int glfw_mods) :
    flags(glfw_mods){
}

namespace {
    int toGlfw(glfw::Mod mod){
        switch (mod){
            case glfw::Mod::Shift: return GLFW_MOD_SHIFT;
            case glfw::Mod::Control: return GLFW_MOD_CONTROL;
            case glfw::Mod::Alt: return GLFW_MOD_ALT;
            case glfw::Mod::Super: return GLFW_MOD_SUPER;
            case glfw::Mod::CapsLock: return GLFW_MOD_CAPS_LOCK;
            case glfw::Mod::NumLock: return GLFW_MOD_NUM_LOCK;
            default: return 0;
        }
    }
};

bool glfw::ModFlags::isMod(glfw::Mod mod){
    return flags & toGlfw(mod);
}

glfw::ModFlags convert(int glfw_mods){
    return glfw::ModFlags(glfw_mods);
}