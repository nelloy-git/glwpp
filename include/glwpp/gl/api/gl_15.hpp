#pragma once
#include "glwpp/gl/api/gl_14.hpp"

namespace glwpp::gl {

bool LoadGl_15(LoadFunc func);
 
extern void (*BeginQuery)(Enum target, UInt id);
extern void (*BindBuffer)(Enum target, UInt buffer);
extern void (*BufferData)(Enum target, SizeiPtr size, const void * data, Enum usage);
extern void (*BufferSubData)(Enum target, IntPtr offset, SizeiPtr size, const void * data);
extern void (*DeleteBuffers)(Sizei n, const UInt * buffers);
extern void (*DeleteQueries)(Sizei n, const UInt * ids);
extern void (*EndQuery)(Enum target);
extern void (*GenBuffers)(Sizei n, UInt * buffers);
extern void (*GenQueries)(Sizei n, UInt * ids);
extern void (*GetBufferParameteriv)(Enum target, Enum pname, Int * params);
extern void (*GetBufferPointerv)(Enum target, Enum pname, void ** params);
extern void (*GetBufferSubData)(Enum target, IntPtr offset, SizeiPtr size, void * data);
extern void (*GetQueryObjectiv)(UInt id, Enum pname, Int * params);
extern void (*GetQueryObjectuiv)(UInt id, Enum pname, UInt * params);
extern void (*GetQueryiv)(Enum target, Enum pname, Int * params);
extern Bool (*IsBuffer)(UInt buffer);
extern Bool (*IsQuery)(UInt id);
extern void* (*MapBuffer)(Enum target, Enum access);
extern Bool (*UnmapBuffer)(Enum target);

}