#pragma once
#include "glwpp/gl/api/gl_43.hpp"

namespace glwpp::gl {

bool LoadGl_44(LoadFunc func);

extern void (*BindBuffersBase)(Enum target, UInt first, Sizei count, const UInt * buffers);
extern void (*BindBuffersRange)(Enum target, UInt first, Sizei count, const UInt * buffers, const IntPtr * offsets, const SizeiPtr * sizes);
extern void (*BindImageTextures)(UInt first, Sizei count, const UInt * textures);
extern void (*BindSamplers)(UInt first, Sizei count, const UInt * samplers);
extern void (*BindTextures)(UInt first, Sizei count, const UInt * textures);
extern void (*BindVertexBuffers)(UInt first, Sizei count, const UInt * buffers, const IntPtr * offsets, const Sizei * strides);
extern void (*BufferStorage)(Enum target, SizeiPtr size, const void * data, BitField flags);
extern void (*ClearTexImage)(UInt texture, Int level, Enum format, Enum type, const void * data);
extern void (*ClearTexSubImage)(UInt texture, Int level, Int xoffset, Int yoffset, Int zoffset, Sizei width, Sizei height, Sizei depth, Enum format, Enum type, const void * data);

}