#pragma once
#include "glwpp/gl/api/gl_10.hpp"

namespace glwpp::gl {

bool LoadGl_11(LoadFunc func);
    
extern void (*BindTexture)(Enum target, UInt texture);
extern void (*CopyTexImage1D)(Enum target, Int level, Enum internalformat, Int x, Int y, Sizei width, Int border);
extern void (*CopyTexImage2D)(Enum target, Int level, Enum internalformat, Int x, Int y, Sizei width, Sizei height, Int border);
extern void (*CopyTexSubImage1D)(Enum target, Int level, Int xoffset, Int x, Int y, Sizei width);
extern void (*CopyTexSubImage2D)(Enum target, Int level, Int xoffset, Int yoffset, Int x, Int y, Sizei width, Sizei height);
extern void (*DeleteTextures)(Sizei n, const UInt *textures);
extern void (*DrawArrays)(Enum mode, Int first, Sizei count);
extern void (*DrawElements)(Enum mode, Sizei count, Enum type, const void *indices);
extern void (*GenTextures)(Sizei n, UInt *textures);
extern void (*GetPointerv)(Enum pname, void **params);
extern Bool (*IsTexture)(UInt texture);
extern void (*PolygonOffset)(Float factor, Float units);
extern void (*TexSubImage1D)(Enum target, Int level, Int xoffset, Sizei width, Enum format, Enum type, const void *pixels);
extern void (*TexSubImage2D)(Enum target, Int level, Int xoffset, Int yoffset, Sizei width, Sizei height, Enum format, Enum type, const void *pixels);

}