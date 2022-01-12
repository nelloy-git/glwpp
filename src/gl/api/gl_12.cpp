#include "glwpp/gl/api/gl_12.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::CopyTexSubImage3D)(Enum target, Int level, Int xoffset, Int yoffset, Int zoffset, Int x, Int y, Sizei width, Sizei height) = nullptr;
void (*gl::DrawRangeElements)(Enum mode, UInt start, UInt end, Sizei count, Enum type, const void * indices) = nullptr;
void (*gl::TexImage3D)(Enum target, Int level, Int internalformat, Sizei width, Sizei height, Sizei depth, Int border, Enum format, Enum type, const void * pixels) = nullptr;
void (*gl::TexSubImage3D)(Enum target, Int level, Int xoffset, Int yoffset, Int zoffset, Sizei width, Sizei height, Sizei depth, Enum format, Enum type, const void * pixels) = nullptr;

bool gl::LoadGl_12(LoadFunc func){
    if (!gl::LoadGl_11(func)){
        return false;
    }
 
    gl::CopyTexSubImage3D = glCopyTexSubImage3D;
    gl::DrawRangeElements = glDrawRangeElements;
    gl::TexImage3D = glTexImage3D;
    gl::TexSubImage3D = glTexSubImage3D;

    return true;
}