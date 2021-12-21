#pragma once

namespace glwpp {

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
    int flags;
};

ModFlags toModFlags(int glfw_mods);

}