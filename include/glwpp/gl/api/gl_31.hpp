#pragma once
#include "glwpp/gl/api/gl_30.hpp"

namespace glwpp::gl {

bool LoadGl_31(LoadFunc func);

extern void (*CopyBufferSubData)(Enum readTarget, Enum writeTarget, IntPtr readOffset, IntPtr writeOffset, SizeiPtr size);
extern void (*DrawArraysInstanced)(Enum mode, Int first, Sizei count, Sizei instancecount);
extern void (*DrawElementsInstanced)(Enum mode, Sizei count, Enum type, const void * indices, Sizei instancecount);
extern void (*GetActiveUniformBlockName)(UInt program, UInt uniformBlockIndex, Sizei bufSize, Sizei * length, Char * uniformBlockName);
extern void (*GetActiveUniformBlockiv)(UInt program, UInt uniformBlockIndex, Enum pname, Int * params);
extern void (*GetActiveUniformName)(UInt program, UInt uniformIndex, Sizei bufSize, Sizei * length, Char * uniformName);
extern void (*GetActiveUniformsiv)(UInt program, Sizei uniformCount, const UInt * uniformIndices, Enum pname, Int * params);
extern UInt (*GetUniformBlockIndex)(UInt program, const Char * uniformBlockName);
extern void (*GetUniformIndices)(UInt program, Sizei uniformCount, const Char *const* uniformNames, UInt * uniformIndices);
extern void (*PrimitiveRestartIndex)(UInt index);
extern void (*TexBuffer)(Enum target, Enum internalformat, UInt buffer);
extern void (*UniformBlockBinding)(UInt program, UInt uniformBlockIndex, UInt uniformBlockBinding);

}