#pragma once
#include "glwpp/gl/api/gl_11.hpp"

namespace glwpp::gl {

bool LoadGl_12(LoadFunc func);
    
extern void (*CopyTexSubImage3D)(Enum target, Int level, Int xoffset, Int yoffset, Int zoffset, Int x, Int y, Sizei width, Sizei height);
extern void (*DrawRangeElements)(Enum mode, UInt start, UInt end, Sizei count, Enum type, const void * indices);
extern void (*TexImage3D)(Enum target, Int level, Int internalformat, Sizei width, Sizei height, Sizei depth, Int border, Enum format, Enum type, const void * pixels);
extern void (*TexSubImage3D)(Enum target, Int level, Int xoffset, Int yoffset, Int zoffset, Sizei width, Sizei height, Sizei depth, Enum format, Enum type, const void * pixels);

}