#include "glwpp/ctx/Keyboard.hpp"

using namespace glwpp;

Keyboard::Keyboard(){
}

Keyboard::~Keyboard(){
}

void Keyboard::press(Key key, KeyModeFlags mods){
    _down[key] = true;
    onPress.emit(*this, key, mods);
}

void Keyboard::release(Key key, KeyModeFlags mods){
    _down[key] = false;
    onRelease.emit(*this, key, mods);
}

bool Keyboard::isDown(Key key) const {
    auto it = _down.find(key);
    if (it == _down.end()){
        return false;
    }
    return it->second;
}

// bool Keyboard::isDown(KeyboardKey key) const{
//     return const_cast<Keyboard *>(this)->isDown(key);
// }