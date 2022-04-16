#include "glwpp/Drawer.hpp"

using namespace glwpp;

Drawer::Drawer(const Program& program) :
    _program(program){
    _camera_loc = make_sptr<gl::Int>(0);
}

Drawer::~Drawer(){
}

#include <iostream>
void Drawer::setCameraMatLocation(const std::string& name){
    _program.getUniformLocation(_camera_loc, name);
}

void Drawer::setCameraMatLocation(const gl::Int& unif_loc){
    *_camera_loc = unif_loc;
}

void Drawer::updateCamera(){
    _program.setUniformMat4x4F(_camera_loc, 
                               std::reinterpret_pointer_cast<gl::Float>(camera.getMatPtr()),
                               false);
}