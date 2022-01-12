#pragma once
#include "glwpp/gl/api/gl_12.hpp"

namespace glwpp::gl {

bool LoadGl_13(LoadFunc func);
 
extern void (*ActiveTexture)(Enum texture);
extern void (*CompressedTexImage1D)(Enum target, Int level, Enum internalformat, Sizei width, Int border, Sizei imageSize, const void * data);
extern void (*CompressedTexImage2D)(Enum target, Int level, Enum internalformat, Sizei width, Sizei height, Int border, Sizei imageSize, const void * data);
extern void (*CompressedTexImage3D)(Enum target, Int level, Enum internalformat, Sizei width, Sizei height, Sizei depth, Int border, Sizei imageSize, const void * data);
extern void (*CompressedTexSubImage1D)(Enum target, Int level, Int xoffset, Sizei width, Enum format, Sizei imageSize, const void * data);
extern void (*CompressedTexSubImage2D)(Enum target, Int level, Int xoffset, Int yoffset, Sizei width, Sizei height, Enum format, Sizei imageSize, const void * data);
extern void (*CompressedTexSubImage3D)(Enum target, Int level, Int xoffset, Int yoffset, Int zoffset, Sizei width, Sizei height, Sizei depth, Enum format, Sizei imageSize, const void * data);
extern void (*GetCompressedTexImage)(Enum target, Int level, void * img);
extern void (*SampleCoverage)(Float value, Bool invert);

}