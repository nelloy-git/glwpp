#include "glwpp/gl/api/gl_14.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::BlendColor)(Float red, Float green, Float blue, Float alpha) = nullptr;
void (*gl::BlendEquation)(Enum mode) = nullptr;
void (*gl::BlendFuncSeparate)(Enum sfactorRGB, Enum dfactorRGB, Enum sfactorAlpha, Enum dfactorAlpha) = nullptr;
void (*gl::MultiDrawArrays)(Enum mode, const Int * first, const Sizei * count, Sizei drawcount) = nullptr;
void (*gl::MultiDrawElements)(Enum mode, const Sizei * count, Enum type, const void *const* indices, Sizei drawcount) = nullptr;
void (*gl::PointParameterf)(Enum pname, Float param) = nullptr;
void (*gl::PointParameterfv)(Enum pname, const Float * params) = nullptr;
void (*gl::PointParameteri)(Enum pname, Int param) = nullptr;
void (*gl::PointParameteriv)(Enum pname, const Int * params) = nullptr;

bool gl::LoadGl_14(LoadFunc func){
    if (!LoadGl_13(func)){
        return false;
    }
 
    gl::BlendColor = glBlendColor;
    gl::BlendEquation = glBlendEquation;
    gl::BlendFuncSeparate = glBlendFuncSeparate;
    gl::MultiDrawArrays = glMultiDrawArrays;
    gl::MultiDrawElements = glMultiDrawElements;
    gl::PointParameterf = glPointParameterf;
    gl::PointParameterfv = glPointParameterfv;
    gl::PointParameteri = glPointParameteri;
    gl::PointParameteriv = glPointParameteriv;

    return true;
}