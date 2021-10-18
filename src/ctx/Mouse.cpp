#include "glwpp/ctx/Mouse.hpp"

using namespace glwpp;

Mouse::Mouse(){
}

Mouse::~Mouse(){
}

void Mouse::press(MouseBtn btn, KeyModeFlags modes){
    _down[btn] = true;
    onPress.emit(*this, btn, modes);
}

void Mouse::release(MouseBtn btn, KeyModeFlags modes){
    _down[btn] = false;
    onRelease.emit(*this, btn, modes);
}

void Mouse::move(double x, double y){
    _x = x;
    _y = y;
    onMove.emit(*this, x, y);
}

// bool Mouse::isDown(Key key) const {
//     auto it = _down.find(key);
//     if (it == _down.end()){
//         return false;
//     }
//     return it->second;
// }