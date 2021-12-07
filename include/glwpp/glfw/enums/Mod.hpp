#pragma once

namespace glwpp::glfw {

enum class Mod {
    Shift,
    Control,
    Alt,
    Super,
    CapsLock,
    NumLock,
    Unknown
};

struct ModFlags {
    ModFlags(int f);
    bool isMod(Mod mod);

private:
    int flags = 0;
};

ModFlags toModFlags(int glfw_mods);

}