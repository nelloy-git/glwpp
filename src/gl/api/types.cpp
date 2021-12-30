#include "glwpp/gl/api/types.hpp"

#include "glad/gl.h"

using namespace glwpp;

bool gl::LoadGl_glad(gl::LoadFunc func){
    if (!gladLoadGL(func)){
        return false;
    }
    return true;
}