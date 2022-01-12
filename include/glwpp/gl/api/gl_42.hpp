#pragma once
#include "glwpp/gl/api/gl_41.hpp"

namespace glwpp::gl {

bool LoadGl_42(LoadFunc func);

extern void (*BindImageTexture)(UInt unit, UInt texture, Int level, Bool layered, Int layer, Enum access, Enum format);
extern void (*DrawArraysInstancedBaseInstance)(Enum mode, Int first, Sizei count, Sizei instancecount, UInt baseinstance);
extern void (*DrawElementsInstancedBaseInstance)(Enum mode, Sizei count, Enum type, const void * indices, Sizei instancecount, UInt baseinstance);
extern void (*DrawElementsInstancedBaseVertexBaseInstance)(Enum mode, Sizei count, Enum type, const void * indices, Sizei instancecount, Int basevertex, UInt baseinstance);
extern void (*DrawTransformFeedbackInstanced)(Enum mode, UInt id, Sizei instancecount);
extern void (*DrawTransformFeedbackStreamInstanced)(Enum mode, UInt id, UInt stream, Sizei instancecount);
extern void (*GetActiveAtomicCounterBufferiv)(UInt program, UInt bufferIndex, Enum pname, Int * params);
extern void (*GetInternalformativ)(Enum target, Enum internalformat, Enum pname, Sizei count, Int * params);
extern void (*MemoryBarrier)(BitField barriers);
extern void (*TexStorage1D)(Enum target, Sizei levels, Enum internalformat, Sizei width);
extern void (*TexStorage2D)(Enum target, Sizei levels, Enum internalformat, Sizei width, Sizei height);
extern void (*TexStorage3D)(Enum target, Sizei levels, Enum internalformat, Sizei width, Sizei height, Sizei depth);

}