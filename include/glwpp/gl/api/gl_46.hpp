#pragma once
#include "glwpp/gl/api/gl_45.hpp"

namespace glwpp::gl {

bool LoadGl_46(LoadFunc func);

extern void (*MultiDrawArraysIndirectCount)(Enum mode, const void * indirect, IntPtr drawcount, Sizei maxdrawcount, Sizei stride);
extern void (*MultiDrawElementsIndirectCount)(Enum mode, Enum type, const void * indirect, IntPtr drawcount, Sizei maxdrawcount, Sizei stride);
extern void (*PolygonOffsetClamp)(Float factor, Float units, Float clamp);
extern void (*SpecializeShader)(UInt shader, const Char * pEntryPoint, UInt numSpecializationConstants, const UInt * pConstantIndex, const UInt * pConstantValue);

}