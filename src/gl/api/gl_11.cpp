#include "glwpp/gl/api/gl_11.hpp"

#include "glad/gl.h"

using namespace glwpp;
   
void (*gl::BindTexture)(Enum target, UInt texture) = nullptr;
void (*gl::CopyTexImage1D)(Enum target, Int level, Enum internalformat, Int x, Int y, Sizei width, Int border) = nullptr;
void (*gl::CopyTexImage2D)(Enum target, Int level, Enum internalformat, Int x, Int y, Sizei width, Sizei height, Int border) = nullptr;
void (*gl::CopyTexSubImage1D)(Enum target, Int level, Int xoffset, Int x, Int y, Sizei width) = nullptr;
void (*gl::CopyTexSubImage2D)(Enum target, Int level, Int xoffset, Int yoffset, Int x, Int y, Sizei width, Sizei height) = nullptr;
void (*gl::DeleteTextures)(Sizei n, const UInt *textures) = nullptr;
void (*gl::DrawArrays)(Enum mode, Int first, Sizei count) = nullptr;
void (*gl::DrawElements)(Enum mode, Sizei count, Enum type, const void *indices) = nullptr;
void (*gl::GenTextures)(Sizei n, UInt *textures) = nullptr;
void (*gl::GetPointerv)(Enum pname, void **params) = nullptr;
GLboolean (*gl::IsTexture)(UInt texture) = nullptr;
void (*gl::PolygonOffset)(Float factor, Float units) = nullptr;
void (*gl::TexSubImage1D)(Enum target, Int level, Int xoffset, Sizei width, Enum format, Enum type, const void *pixels) = nullptr;
void (*gl::TexSubImage2D)(Enum target, Int level, Int xoffset, Int yoffset, Sizei width, Sizei height, Enum format, Enum type, const void *pixels) = nullptr;

bool gl::LoadGl_11(LoadFunc func){
    if (!gl::LoadGl_10(func)){
        return false;
    }
 
    gl::BindTexture = glBindTexture;
    gl::CopyTexImage1D = glCopyTexImage1D;
    gl::CopyTexImage2D = glCopyTexImage2D;
    gl::CopyTexSubImage1D = glCopyTexSubImage1D;
    gl::CopyTexSubImage2D = glCopyTexSubImage2D;
    gl::DeleteTextures = glDeleteTextures;
    gl::DrawArrays = glDrawArrays;
    gl::DrawElements = glDrawElements;
    gl::GenTextures = glGenTextures;
    gl::GetPointerv = glGetPointerv;
    gl::IsTexture = glIsTexture;
    gl::PolygonOffset = glPolygonOffset;
    gl::TexSubImage1D = glTexSubImage1D;
    gl::TexSubImage2D = glTexSubImage2D;

    return true;
}