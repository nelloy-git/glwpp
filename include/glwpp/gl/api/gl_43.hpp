#pragma once
#include "glwpp/gl/api/gl_42.hpp"

namespace glwpp::gl {

bool LoadGl_43(LoadFunc func);

extern void (*BindVertexBuffer)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
extern void (*ClearBufferData)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data);
extern void (*ClearBufferSubData)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
extern void (*CopyImageSubData)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
extern void (*DebugMessageCallback)(GLdebugProc callback, const void * userParam);
extern void (*DebugMessageControl)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled);
extern void (*DebugMessageInsert)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf);
extern void (*DispatchCompute)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
extern void (*DispatchComputeIndirect)(GLintptr indirect);
extern void (*FramebufferParameteri)(GLenum target, GLenum pname, GLint param);
extern GLuint (*GetDebugMessageLog)(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog);
extern void (*GetFramebufferParameteriv)(GLenum target, GLenum pname, GLint * params);
extern void (*GetInternalformati64v)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 * params);
extern void (*GetObjectLabel)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label);
extern void (*GetObjectPtrLabel)(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label);
extern void (*GetProgramInterfaceiv)(GLuint program, GLenum programInterface, GLenum pname, GLint * params);
extern GLuint (*GetProgramResourceIndex)(GLuint program, GLenum programInterface, const GLchar * name);
extern GLint (*GetProgramResourceLocation)(GLuint program, GLenum programInterface, const GLchar * name);
extern GLint (*GetProgramResourceLocationIndex)(GLuint program, GLenum programInterface, const GLchar * name);
extern void (*GetProgramResourceName)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
extern void (*GetProgramResourceiv)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei count, GLsizei * length, GLint * params);
extern void (*InvalidateBufferData)(GLuint buffer);
extern void (*InvalidateBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr length);
extern void (*InvalidateFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum * attachments);
extern void (*InvalidateSubFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (*InvalidateTexImage)(GLuint texture, GLint level);
extern void (*InvalidateTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
extern void (*MultiDrawArraysIndirect)(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride);
extern void (*MultiDrawElementsIndirect)(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride);
extern void (*ObjectLabel)(GLenum identifier, GLuint name, GLsizei length, const GLchar * label);
extern void (*ObjectPtrLabel)(const void * ptr, GLsizei length, const GLchar * label);
extern void (*PopDebugGroup)();
extern void (*PushDebugGroup)(GLenum source, GLuint id, GLsizei length, const GLchar * message);
extern void (*ShaderStorageBlockBinding)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
extern void (*TexBufferRange)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern void (*TexStorage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
extern void (*TexStorage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
extern void (*TextureView)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
extern void (*VertexAttribBinding)(GLuint attribindex, GLuint bindingindex);
extern void (*VertexAttribFormat)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
extern void (*VertexAttribIFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
extern void (*VertexAttribLFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
extern void (*VertexBindingDivisor)(GLuint bindingindex, GLuint divisor);

}