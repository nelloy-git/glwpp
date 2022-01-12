#include "glwpp/gl/api/gl_43.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::BindVertexBuffer)(UInt bindingindex, UInt buffer, IntPtr offset, Sizei stride) = nullptr;
void (*gl::ClearBufferData)(Enum target, Enum internalformat, Enum format, Enum type, const void * data) = nullptr;
void (*gl::ClearBufferSubData)(Enum target, Enum internalformat, IntPtr offset, SizeiPtr size, Enum format, Enum type, const void * data) = nullptr;
void (*gl::CopyImageSubData)(UInt srcName, Enum srcTarget, Int srcLevel, Int srcX, Int srcY, Int srcZ, UInt dstName, Enum dstTarget, Int dstLevel, Int dstX, Int dstY, Int dstZ, Sizei srcWidth, Sizei srcHeight, Sizei srcDepth) = nullptr;
void (*gl::DebugMessageCallback)(GLdebugProc callback, const void * userParam) = nullptr;
void (*gl::DebugMessageControl)(Enum source, Enum type, Enum severity, Sizei count, const UInt * ids, Bool enabled) = nullptr;
void (*gl::DebugMessageInsert)(Enum source, Enum type, UInt id, Enum severity, Sizei length, const Char * buf) = nullptr;
void (*gl::DispatchCompute)(UInt num_groups_x, UInt num_groups_y, UInt num_groups_z) = nullptr;
void (*gl::DispatchComputeIndirect)(IntPtr indirect) = nullptr;
void (*gl::FramebufferParameteri)(Enum target, Enum pname, Int param) = nullptr;
GLuint (*gl::GetDebugMessageLog)(UInt count, Sizei bufSize, Enum * sources, Enum * types, UInt * ids, Enum * severities, Sizei * lengths, Char * messageLog) = nullptr;
void (*gl::GetFramebufferParameteriv)(Enum target, Enum pname, Int * params) = nullptr;
void (*gl::GetInternalformati64v)(Enum target, Enum internalformat, Enum pname, Sizei count, GLint64 * params) = nullptr;
void (*gl::GetObjectLabel)(Enum identifier, UInt name, Sizei bufSize, Sizei * length, Char * label) = nullptr;
void (*gl::GetObjectPtrLabel)(const void * ptr, Sizei bufSize, Sizei * length, Char * label) = nullptr;
void (*gl::GetProgramInterfaceiv)(UInt program, Enum programInterface, Enum pname, Int * params) = nullptr;
GLuint (*gl::GetProgramResourceIndex)(UInt program, Enum programInterface, const Char * name) = nullptr;
GLint (*gl::GetProgramResourceLocation)(UInt program, Enum programInterface, const Char * name) = nullptr;
GLint (*gl::GetProgramResourceLocationIndex)(UInt program, Enum programInterface, const Char * name) = nullptr;
void (*gl::GetProgramResourceName)(UInt program, Enum programInterface, UInt index, Sizei bufSize, Sizei * length, Char * name) = nullptr;
void (*gl::GetProgramResourceiv)(UInt program, Enum programInterface, UInt index, Sizei propCount, const Enum * props, Sizei count, Sizei * length, Int * params) = nullptr;
void (*gl::InvalidateBufferData)(UInt buffer) = nullptr;
void (*gl::InvalidateBufferSubData)(UInt buffer, IntPtr offset, SizeiPtr length) = nullptr;
void (*gl::InvalidateFramebuffer)(Enum target, Sizei numAttachments, const Enum * attachments) = nullptr;
void (*gl::InvalidateSubFramebuffer)(Enum target, Sizei numAttachments, const Enum * attachments, Int x, Int y, Sizei width, Sizei height) = nullptr;
void (*gl::InvalidateTexImage)(UInt texture, Int level) = nullptr;
void (*gl::InvalidateTexSubImage)(UInt texture, Int level, Int xoffset, Int yoffset, Int zoffset, Sizei width, Sizei height, Sizei depth) = nullptr;
void (*gl::MultiDrawArraysIndirect)(Enum mode, const void * indirect, Sizei drawcount, Sizei stride) = nullptr;
void (*gl::MultiDrawElementsIndirect)(Enum mode, Enum type, const void * indirect, Sizei drawcount, Sizei stride) = nullptr;
void (*gl::ObjectLabel)(Enum identifier, UInt name, Sizei length, const Char * label) = nullptr;
void (*gl::ObjectPtrLabel)(const void * ptr, Sizei length, const Char * label) = nullptr;
void (*gl::PopDebugGroup)() = nullptr;
void (*gl::PushDebugGroup)(Enum source, UInt id, Sizei length, const Char * message) = nullptr;
void (*gl::ShaderStorageBlockBinding)(UInt program, UInt storageBlockIndex, UInt storageBlockBinding) = nullptr;
void (*gl::TexBufferRange)(Enum target, Enum internalformat, UInt buffer, IntPtr offset, SizeiPtr size) = nullptr;
void (*gl::TexStorage2DMultisample)(Enum target, Sizei samples, Enum internalformat, Sizei width, Sizei height, Bool fixedsamplelocations) = nullptr;
void (*gl::TexStorage3DMultisample)(Enum target, Sizei samples, Enum internalformat, Sizei width, Sizei height, Sizei depth, Bool fixedsamplelocations) = nullptr;
void (*gl::TextureView)(UInt texture, Enum target, UInt origtexture, Enum internalformat, UInt minlevel, UInt numlevels, UInt minlayer, UInt numlayers) = nullptr;
void (*gl::VertexAttribBinding)(UInt attribindex, UInt bindingindex) = nullptr;
void (*gl::VertexAttribFormat)(UInt attribindex, Int size, Enum type, Bool normalized, UInt relativeoffset) = nullptr;
void (*gl::VertexAttribIFormat)(UInt attribindex, Int size, Enum type, UInt relativeoffset) = nullptr;
void (*gl::VertexAttribLFormat)(UInt attribindex, Int size, Enum type, UInt relativeoffset) = nullptr;
void (*gl::VertexBindingDivisor)(UInt bindingindex, UInt divisor) = nullptr;

bool gl::LoadGl_43(LoadFunc func){
    if (!LoadGl_42(func)){
        return false;
    }
 
    gl::BindVertexBuffer = glBindVertexBuffer;
    gl::ClearBufferData = glClearBufferData;
    gl::ClearBufferSubData = glClearBufferSubData;
    gl::CopyImageSubData = glCopyImageSubData;
    gl::DebugMessageCallback = glDebugMessageCallback;
    gl::DebugMessageControl = glDebugMessageControl;
    gl::DebugMessageInsert = glDebugMessageInsert;
    gl::DispatchCompute = glDispatchCompute;
    gl::DispatchComputeIndirect = glDispatchComputeIndirect;
    gl::FramebufferParameteri = glFramebufferParameteri;
    gl::GetDebugMessageLog = glGetDebugMessageLog;
    gl::GetFramebufferParameteriv = glGetFramebufferParameteriv;
    gl::GetInternalformati64v = glGetInternalformati64v;
    gl::GetObjectLabel = glGetObjectLabel;
    gl::GetObjectPtrLabel = glGetObjectPtrLabel;
    gl::GetPointerv = glGetPointerv;
    gl::GetProgramInterfaceiv = glGetProgramInterfaceiv;
    gl::GetProgramResourceIndex = glGetProgramResourceIndex;
    gl::GetProgramResourceLocation = glGetProgramResourceLocation;
    gl::GetProgramResourceLocationIndex = glGetProgramResourceLocationIndex;
    gl::GetProgramResourceName = glGetProgramResourceName;
    gl::GetProgramResourceiv = glGetProgramResourceiv;
    gl::InvalidateBufferData = glInvalidateBufferData;
    gl::InvalidateBufferSubData = glInvalidateBufferSubData;
    gl::InvalidateFramebuffer = glInvalidateFramebuffer;
    gl::InvalidateSubFramebuffer = glInvalidateSubFramebuffer;
    gl::InvalidateTexImage = glInvalidateTexImage;
    gl::InvalidateTexSubImage = glInvalidateTexSubImage;
    gl::MultiDrawArraysIndirect = glMultiDrawArraysIndirect;
    gl::MultiDrawElementsIndirect = glMultiDrawElementsIndirect;
    gl::ObjectLabel = glObjectLabel;
    gl::ObjectPtrLabel = glObjectPtrLabel;
    gl::PopDebugGroup = glPopDebugGroup;
    gl::PushDebugGroup = glPushDebugGroup;
    gl::ShaderStorageBlockBinding = glShaderStorageBlockBinding;
    gl::TexBufferRange = glTexBufferRange;
    gl::TexStorage2DMultisample = glTexStorage2DMultisample;
    gl::TexStorage3DMultisample = glTexStorage3DMultisample;
    gl::TextureView = glTextureView;
    gl::VertexAttribBinding = glVertexAttribBinding;
    gl::VertexAttribFormat = glVertexAttribFormat;
    gl::VertexAttribIFormat = glVertexAttribIFormat;
    gl::VertexAttribLFormat = glVertexAttribLFormat;
    gl::VertexBindingDivisor = glVertexBindingDivisor;

    return true;
}