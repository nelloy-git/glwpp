#pragma once
#include "glwpp/gl/api/gl_42.hpp"

namespace glwpp::gl {

bool LoadGl_43(LoadFunc func);

extern void (*BindVertexBuffer)(UInt bindingindex, UInt buffer, IntPtr offset, Sizei stride);
extern void (*ClearBufferData)(Enum target, Enum internalformat, Enum format, Enum type, const void * data);
extern void (*ClearBufferSubData)(Enum target, Enum internalformat, IntPtr offset, SizeiPtr size, Enum format, Enum type, const void * data);
extern void (*CopyImageSubData)(UInt srcName, Enum srcTarget, Int srcLevel, Int srcX, Int srcY, Int srcZ, UInt dstName, Enum dstTarget, Int dstLevel, Int dstX, Int dstY, Int dstZ, Sizei srcWidth, Sizei srcHeight, Sizei srcDepth);
extern void (*DebugMessageCallback)(GLdebugProc callback, const void * userParam);
extern void (*DebugMessageControl)(Enum source, Enum type, Enum severity, Sizei count, const UInt * ids, Bool enabled);
extern void (*DebugMessageInsert)(Enum source, Enum type, UInt id, Enum severity, Sizei length, const Char * buf);
extern void (*DispatchCompute)(UInt num_groups_x, UInt num_groups_y, UInt num_groups_z);
extern void (*DispatchComputeIndirect)(IntPtr indirect);
extern void (*FramebufferParameteri)(Enum target, Enum pname, Int param);
extern UInt (*GetDebugMessageLog)(UInt count, Sizei bufSize, Enum * sources, Enum * types, UInt * ids, Enum * severities, Sizei * lengths, Char * messageLog);
extern void (*GetFramebufferParameteriv)(Enum target, Enum pname, Int * params);
extern void (*GetInternalformati64v)(Enum target, Enum internalformat, Enum pname, Sizei count, GLint64 * params);
extern void (*GetObjectLabel)(Enum identifier, UInt name, Sizei bufSize, Sizei * length, Char * label);
extern void (*GetObjectPtrLabel)(const void * ptr, Sizei bufSize, Sizei * length, Char * label);
extern void (*GetProgramInterfaceiv)(UInt program, Enum programInterface, Enum pname, Int * params);
extern UInt (*GetProgramResourceIndex)(UInt program, Enum programInterface, const Char * name);
extern Int (*GetProgramResourceLocation)(UInt program, Enum programInterface, const Char * name);
extern Int (*GetProgramResourceLocationIndex)(UInt program, Enum programInterface, const Char * name);
extern void (*GetProgramResourceName)(UInt program, Enum programInterface, UInt index, Sizei bufSize, Sizei * length, Char * name);
extern void (*GetProgramResourceiv)(UInt program, Enum programInterface, UInt index, Sizei propCount, const Enum * props, Sizei count, Sizei * length, Int * params);
extern void (*InvalidateBufferData)(UInt buffer);
extern void (*InvalidateBufferSubData)(UInt buffer, IntPtr offset, SizeiPtr length);
extern void (*InvalidateFramebuffer)(Enum target, Sizei numAttachments, const Enum * attachments);
extern void (*InvalidateSubFramebuffer)(Enum target, Sizei numAttachments, const Enum * attachments, Int x, Int y, Sizei width, Sizei height);
extern void (*InvalidateTexImage)(UInt texture, Int level);
extern void (*InvalidateTexSubImage)(UInt texture, Int level, Int xoffset, Int yoffset, Int zoffset, Sizei width, Sizei height, Sizei depth);
extern void (*MultiDrawArraysIndirect)(Enum mode, const void * indirect, Sizei drawcount, Sizei stride);
extern void (*MultiDrawElementsIndirect)(Enum mode, Enum type, const void * indirect, Sizei drawcount, Sizei stride);
extern void (*ObjectLabel)(Enum identifier, UInt name, Sizei length, const Char * label);
extern void (*ObjectPtrLabel)(const void * ptr, Sizei length, const Char * label);
extern void (*PopDebugGroup)();
extern void (*PushDebugGroup)(Enum source, UInt id, Sizei length, const Char * message);
extern void (*ShaderStorageBlockBinding)(UInt program, UInt storageBlockIndex, UInt storageBlockBinding);
extern void (*TexBufferRange)(Enum target, Enum internalformat, UInt buffer, IntPtr offset, SizeiPtr size);
extern void (*TexStorage2DMultisample)(Enum target, Sizei samples, Enum internalformat, Sizei width, Sizei height, Bool fixedsamplelocations);
extern void (*TexStorage3DMultisample)(Enum target, Sizei samples, Enum internalformat, Sizei width, Sizei height, Sizei depth, Bool fixedsamplelocations);
extern void (*TextureView)(UInt texture, Enum target, UInt origtexture, Enum internalformat, UInt minlevel, UInt numlevels, UInt minlayer, UInt numlayers);
extern void (*VertexAttribBinding)(UInt attribindex, UInt bindingindex);
extern void (*VertexAttribFormat)(UInt attribindex, Int size, Enum type, Bool normalized, UInt relativeoffset);
extern void (*VertexAttribIFormat)(UInt attribindex, Int size, Enum type, UInt relativeoffset);
extern void (*VertexAttribLFormat)(UInt attribindex, Int size, Enum type, UInt relativeoffset);
extern void (*VertexBindingDivisor)(UInt bindingindex, UInt divisor);

}