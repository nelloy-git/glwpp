#include "glwpp/gl/api/gl_43.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::BindVertexBuffer)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) = nullptr;
void (*gl::ClearBufferData)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data) = nullptr;
void (*gl::ClearBufferSubData)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data) = nullptr;
void (*gl::CopyImageSubData)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) = nullptr;
void (*gl::DebugMessageCallback)(GLdebugProc callback, const void * userParam) = nullptr;
void (*gl::DebugMessageControl)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled) = nullptr;
void (*gl::DebugMessageInsert)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf) = nullptr;
void (*gl::DispatchCompute)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) = nullptr;
void (*gl::DispatchComputeIndirect)(GLintptr indirect) = nullptr;
void (*gl::FramebufferParameteri)(GLenum target, GLenum pname, GLint param) = nullptr;
GLuint (*gl::GetDebugMessageLog)(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog) = nullptr;
void (*gl::GetFramebufferParameteriv)(GLenum target, GLenum pname, GLint * params) = nullptr;
void (*gl::GetInternalformati64v)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 * params) = nullptr;
void (*gl::GetObjectLabel)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label) = nullptr;
void (*gl::GetObjectPtrLabel)(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label) = nullptr;
void (*gl::GetProgramInterfaceiv)(GLuint program, GLenum programInterface, GLenum pname, GLint * params) = nullptr;
GLuint (*gl::GetProgramResourceIndex)(GLuint program, GLenum programInterface, const GLchar * name) = nullptr;
GLint (*gl::GetProgramResourceLocation)(GLuint program, GLenum programInterface, const GLchar * name) = nullptr;
GLint (*gl::GetProgramResourceLocationIndex)(GLuint program, GLenum programInterface, const GLchar * name) = nullptr;
void (*gl::GetProgramResourceName)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name) = nullptr;
void (*gl::GetProgramResourceiv)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei count, GLsizei * length, GLint * params) = nullptr;
void (*gl::InvalidateBufferData)(GLuint buffer) = nullptr;
void (*gl::InvalidateBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr length) = nullptr;
void (*gl::InvalidateFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum * attachments) = nullptr;
void (*gl::InvalidateSubFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;
void (*gl::InvalidateTexImage)(GLuint texture, GLint level) = nullptr;
void (*gl::InvalidateTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) = nullptr;
void (*gl::MultiDrawArraysIndirect)(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride) = nullptr;
void (*gl::MultiDrawElementsIndirect)(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride) = nullptr;
void (*gl::ObjectLabel)(GLenum identifier, GLuint name, GLsizei length, const GLchar * label) = nullptr;
void (*gl::ObjectPtrLabel)(const void * ptr, GLsizei length, const GLchar * label) = nullptr;
void (*gl::PopDebugGroup)() = nullptr;
void (*gl::PushDebugGroup)(GLenum source, GLuint id, GLsizei length, const GLchar * message) = nullptr;
void (*gl::ShaderStorageBlockBinding)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) = nullptr;
void (*gl::TexBufferRange)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) = nullptr;
void (*gl::TexStorage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) = nullptr;
void (*gl::TexStorage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) = nullptr;
void (*gl::TextureView)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) = nullptr;
void (*gl::VertexAttribBinding)(GLuint attribindex, GLuint bindingindex) = nullptr;
void (*gl::VertexAttribFormat)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) = nullptr;
void (*gl::VertexAttribIFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) = nullptr;
void (*gl::VertexAttribLFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) = nullptr;
void (*gl::VertexBindingDivisor)(GLuint bindingindex, GLuint divisor) = nullptr;

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