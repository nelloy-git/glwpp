#pragma once

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace glwpp::glfw {

enum class KeyMode {
    SHIFT = GLFW_MOD_SHIFT,
    CONTROL = GLFW_MOD_CONTROL,
    ALT = GLFW_MOD_ALT,
    SUPER = GLFW_MOD_SUPER,
    CAPS_LOCK = GLFW_MOD_CAPS_LOCK,
    NUM_LOCK = GLFW_MOD_NUM_LOCK,
};

struct KeyModFlags {
    KeyModFlags(int f) :
        flags(f){}

    int flags = 0;

    inline bool isMod(int bitflags, KeyMode mod){
        return bitflags & static_cast<int>(mod);
    };  
};

}