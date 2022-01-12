#include "glwpp/gl/api/gl_46.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::MultiDrawArraysIndirectCount)(Enum mode, const void * indirect, IntPtr drawcount, Sizei maxdrawcount, Sizei stride) = nullptr;
void (*gl::MultiDrawElementsIndirectCount)(Enum mode, Enum type, const void * indirect, IntPtr drawcount, Sizei maxdrawcount, Sizei stride) = nullptr;
void (*gl::PolygonOffsetClamp)(Float factor, Float units, Float clamp) = nullptr;
void (*gl::SpecializeShader)(UInt shader, const Char * pEntryPoint, UInt numSpecializationConstants, const UInt * pConstantIndex, const UInt * pConstantValue) = nullptr;

bool gl::LoadGl_46(LoadFunc func){
    if (!LoadGl_45(func)){
        return false;
    }
 
    gl::MultiDrawArraysIndirectCount = glMultiDrawArraysIndirectCount;
    gl::MultiDrawElementsIndirectCount = glMultiDrawElementsIndirectCount;
    gl::PolygonOffsetClamp = glPolygonOffsetClamp;
    gl::SpecializeShader = glSpecializeShader;

    return true;
}