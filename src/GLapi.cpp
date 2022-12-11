#include "GLapi.hpp"

using namespace glwpp;

void GLapi::ActiveShaderProgram(GLuint pipeline, GLuint program, const SrcLoc& src_loc){
    return _glad_context->ActiveShaderProgram(pipeline, program);
}

void GLapi::ActiveTexture(GLenum texture, const SrcLoc& src_loc){
    return _glad_context->ActiveTexture(texture);
}

void GLapi::AttachShader(GLuint program, GLuint shader, const SrcLoc& src_loc){
    return _glad_context->AttachShader(program, shader);
}

void GLapi::BeginConditionalRender(GLuint id, GLenum mode, const SrcLoc& src_loc){
    return _glad_context->BeginConditionalRender(id, mode);
}

void GLapi::BeginQuery(GLenum target, GLuint id, const SrcLoc& src_loc){
    return _glad_context->BeginQuery(target, id);
}

void GLapi::BeginQueryIndexed(GLenum target, GLuint index, GLuint id, const SrcLoc& src_loc){
    return _glad_context->BeginQueryIndexed(target, index, id);
}

void GLapi::BeginTransformFeedback(GLenum primitiveMode, const SrcLoc& src_loc){
    return _glad_context->BeginTransformFeedback(primitiveMode);
}

void GLapi::BindAttribLocation(GLuint program, GLuint index, const GLchar* name, const SrcLoc& src_loc){
    return _glad_context->BindAttribLocation(program, index, name);
}

void GLapi::BindBuffer(GLenum target, GLuint buffer, const SrcLoc& src_loc){
    return _glad_context->BindBuffer(target, buffer);
}

void GLapi::BindBufferBase(GLenum target, GLuint index, GLuint buffer, const SrcLoc& src_loc){
    return _glad_context->BindBufferBase(target, index, buffer);
}

void GLapi::BindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size, const SrcLoc& src_loc){
    return _glad_context->BindBufferRange(target, index, buffer, offset, size);
}

void GLapi::BindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const SrcLoc& src_loc){
    return _glad_context->BindBuffersBase(target, first, count, buffers);
}

void GLapi::BindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes, const SrcLoc& src_loc){
    return _glad_context->BindBuffersRange(target, first, count, buffers, offsets, sizes);
}

void GLapi::BindFragDataLocation(GLuint program, GLuint color, const GLchar* name, const SrcLoc& src_loc){
    return _glad_context->BindFragDataLocation(program, color, name);
}

void GLapi::BindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name, const SrcLoc& src_loc){
    return _glad_context->BindFragDataLocationIndexed(program, colorNumber, index, name);
}

void GLapi::BindFramebuffer(GLenum target, GLuint framebuffer, const SrcLoc& src_loc){
    return _glad_context->BindFramebuffer(target, framebuffer);
}

void GLapi::BindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format, const SrcLoc& src_loc){
    return _glad_context->BindImageTexture(unit, texture, level, layered, layer, access, format);
}

void GLapi::BindImageTextures(GLuint first, GLsizei count, const GLuint* textures, const SrcLoc& src_loc){
    return _glad_context->BindImageTextures(first, count, textures);
}

void GLapi::BindProgramPipeline(GLuint pipeline, const SrcLoc& src_loc){
    return _glad_context->BindProgramPipeline(pipeline);
}

void GLapi::BindRenderbuffer(GLenum target, GLuint renderbuffer, const SrcLoc& src_loc){
    return _glad_context->BindRenderbuffer(target, renderbuffer);
}

void GLapi::BindSampler(GLuint unit, GLuint sampler, const SrcLoc& src_loc){
    return _glad_context->BindSampler(unit, sampler);
}

void GLapi::BindSamplers(GLuint first, GLsizei count, const GLuint* samplers, const SrcLoc& src_loc){
    return _glad_context->BindSamplers(first, count, samplers);
}

void GLapi::BindTexture(GLenum target, GLuint texture, const SrcLoc& src_loc){
    return _glad_context->BindTexture(target, texture);
}

void GLapi::BindTextureUnit(GLuint unit, GLuint texture, const SrcLoc& src_loc){
    return _glad_context->BindTextureUnit(unit, texture);
}

void GLapi::BindTextures(GLuint first, GLsizei count, const GLuint* textures, const SrcLoc& src_loc){
    return _glad_context->BindTextures(first, count, textures);
}

void GLapi::BindTransformFeedback(GLenum target, GLuint id, const SrcLoc& src_loc){
    return _glad_context->BindTransformFeedback(target, id);
}

void GLapi::BindVertexArray(GLuint array, const SrcLoc& src_loc){
    return _glad_context->BindVertexArray(array);
}

void GLapi::BindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride, const SrcLoc& src_loc){
    return _glad_context->BindVertexBuffer(bindingindex, buffer, offset, stride);
}

void GLapi::BindVertexBuffers(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides, const SrcLoc& src_loc){
    return _glad_context->BindVertexBuffers(first, count, buffers, offsets, strides);
}

void GLapi::BlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, const SrcLoc& src_loc){
    return _glad_context->BlendColor(red, green, blue, alpha);
}

void GLapi::BlendEquation(GLenum mode, const SrcLoc& src_loc){
    return _glad_context->BlendEquation(mode);
}

void GLapi::BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha, const SrcLoc& src_loc){
    return _glad_context->BlendEquationSeparate(modeRGB, modeAlpha);
}

void GLapi::BlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha, const SrcLoc& src_loc){
    return _glad_context->BlendEquationSeparatei(buf, modeRGB, modeAlpha);
}

void GLapi::BlendEquationi(GLuint buf, GLenum mode, const SrcLoc& src_loc){
    return _glad_context->BlendEquationi(buf, mode);
}

void GLapi::BlendFunc(GLenum sfactor, GLenum dfactor, const SrcLoc& src_loc){
    return _glad_context->BlendFunc(sfactor, dfactor);
}

void GLapi::BlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha, const SrcLoc& src_loc){
    return _glad_context->BlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}

void GLapi::BlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha, const SrcLoc& src_loc){
    return _glad_context->BlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void GLapi::BlendFunci(GLuint buf, GLenum src, GLenum dst, const SrcLoc& src_loc){
    return _glad_context->BlendFunci(buf, src, dst);
}

void GLapi::BlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter, const SrcLoc& src_loc){
    return _glad_context->BlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void GLapi::BlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter, const SrcLoc& src_loc){
    return _glad_context->BlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void GLapi::BufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage, const SrcLoc& src_loc){
    return _glad_context->BufferData(target, size, data, usage);
}

void GLapi::BufferStorage(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags, const SrcLoc& src_loc){
    return _glad_context->BufferStorage(target, size, data, flags);
}

void GLapi::BufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data, const SrcLoc& src_loc){
    return _glad_context->BufferSubData(target, offset, size, data);
}

GLenum GLapi::CheckFramebufferStatus(GLenum target, const SrcLoc& src_loc){
    return _glad_context->CheckFramebufferStatus(target);
}

GLenum GLapi::CheckNamedFramebufferStatus(GLuint framebuffer, GLenum target, const SrcLoc& src_loc){
    return _glad_context->CheckNamedFramebufferStatus(framebuffer, target);
}

void GLapi::ClampColor(GLenum target, GLenum clamp, const SrcLoc& src_loc){
    return _glad_context->ClampColor(target, clamp);
}

void GLapi::Clear(GLbitfield mask, const SrcLoc& src_loc){
    return _glad_context->Clear(mask);
}

void GLapi::ClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc){
    return _glad_context->ClearBufferData(target, internalformat, format, type, data);
}

void GLapi::ClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc){
    return _glad_context->ClearBufferSubData(target, internalformat, offset, size, format, type, data);
}

void GLapi::ClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil, const SrcLoc& src_loc){
    return _glad_context->ClearBufferfi(buffer, drawbuffer, depth, stencil);
}

void GLapi::ClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->ClearBufferfv(buffer, drawbuffer, value);
}

void GLapi::ClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint* value, const SrcLoc& src_loc){
    return _glad_context->ClearBufferiv(buffer, drawbuffer, value);
}

void GLapi::ClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint* value, const SrcLoc& src_loc){
    return _glad_context->ClearBufferuiv(buffer, drawbuffer, value);
}

void GLapi::ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, const SrcLoc& src_loc){
    return _glad_context->ClearColor(red, green, blue, alpha);
}

void GLapi::ClearDepth(GLdouble depth, const SrcLoc& src_loc){
    return _glad_context->ClearDepth(depth);
}

void GLapi::ClearDepthf(GLfloat d, const SrcLoc& src_loc){
    return _glad_context->ClearDepthf(d);
}

void GLapi::ClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc){
    return _glad_context->ClearNamedBufferData(buffer, internalformat, format, type, data);
}

void GLapi::ClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc){
    return _glad_context->ClearNamedBufferSubData(buffer, internalformat, offset, size, format, type, data);
}

void GLapi::ClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil, const SrcLoc& src_loc){
    return _glad_context->ClearNamedFramebufferfi(framebuffer, buffer, drawbuffer, depth, stencil);
}

void GLapi::ClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->ClearNamedFramebufferfv(framebuffer, buffer, drawbuffer, value);
}

void GLapi::ClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value, const SrcLoc& src_loc){
    return _glad_context->ClearNamedFramebufferiv(framebuffer, buffer, drawbuffer, value);
}

void GLapi::ClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value, const SrcLoc& src_loc){
    return _glad_context->ClearNamedFramebufferuiv(framebuffer, buffer, drawbuffer, value);
}

void GLapi::ClearStencil(GLint s, const SrcLoc& src_loc){
    return _glad_context->ClearStencil(s);
}

void GLapi::ClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc){
    return _glad_context->ClearTexImage(texture, level, format, type, data);
}

void GLapi::ClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc){
    return _glad_context->ClearTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
}

GLenum GLapi::ClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, const SrcLoc& src_loc){
    return _glad_context->ClientWaitSync(sync, flags, timeout);
}

void GLapi::ClipControl(GLenum origin, GLenum depth, const SrcLoc& src_loc){
    return _glad_context->ClipControl(origin, depth);
}

void GLapi::ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha, const SrcLoc& src_loc){
    return _glad_context->ColorMask(red, green, blue, alpha);
}

void GLapi::ColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a, const SrcLoc& src_loc){
    return _glad_context->ColorMaski(index, r, g, b, a);
}

void GLapi::CompileShader(GLuint shader, const SrcLoc& src_loc){
    return _glad_context->CompileShader(shader);
}

void GLapi::CompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data, const SrcLoc& src_loc){
    return _glad_context->CompressedTexImage1D(target, level, internalformat, width, border, imageSize, data);
}

void GLapi::CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data, const SrcLoc& src_loc){
    return _glad_context->CompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}

void GLapi::CompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data, const SrcLoc& src_loc){
    return _glad_context->CompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);
}

void GLapi::CompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc){
    return _glad_context->CompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data);
}

void GLapi::CompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc){
    return _glad_context->CompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void GLapi::CompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc){
    return _glad_context->CompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

void GLapi::CompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc){
    return _glad_context->CompressedTextureSubImage1D(texture, level, xoffset, width, format, imageSize, data);
}

void GLapi::CompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc){
    return _glad_context->CompressedTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void GLapi::CompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc){
    return _glad_context->CompressedTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

void GLapi::CopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, const SrcLoc& src_loc){
    return _glad_context->CopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size);
}

void GLapi::CopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth, const SrcLoc& src_loc){
    return _glad_context->CopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}

void GLapi::CopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, const SrcLoc& src_loc){
    return _glad_context->CopyNamedBufferSubData(readBuffer, writeBuffer, readOffset, writeOffset, size);
}

void GLapi::CopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border, const SrcLoc& src_loc){
    return _glad_context->CopyTexImage1D(target, level, internalformat, x, y, width, border);
}

void GLapi::CopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border, const SrcLoc& src_loc){
    return _glad_context->CopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}

void GLapi::CopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width, const SrcLoc& src_loc){
    return _glad_context->CopyTexSubImage1D(target, level, xoffset, x, y, width);
}

void GLapi::CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc){
    return _glad_context->CopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}

void GLapi::CopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc){
    return _glad_context->CopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void GLapi::CopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width, const SrcLoc& src_loc){
    return _glad_context->CopyTextureSubImage1D(texture, level, xoffset, x, y, width);
}

void GLapi::CopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc){
    return _glad_context->CopyTextureSubImage2D(texture, level, xoffset, yoffset, x, y, width, height);
}

void GLapi::CopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc){
    return _glad_context->CopyTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void GLapi::CreateBuffers(GLsizei n, GLuint* dst, const SrcLoc& src_loc){
    return _glad_context->CreateBuffers(n, dst);
}

void GLapi::CreateFramebuffers(GLsizei n, GLuint* framebuffers, const SrcLoc& src_loc){
    return _glad_context->CreateFramebuffers(n, framebuffers);
}

GLuint GLapi::CreateProgram(const SrcLoc& src_loc){
    return _glad_context->CreateProgram();
}

void GLapi::CreateProgramPipelines(GLsizei n, GLuint* pipelines, const SrcLoc& src_loc){
    return _glad_context->CreateProgramPipelines(n, pipelines);
}

void GLapi::CreateQueries(GLenum target, GLsizei n, GLuint* ids, const SrcLoc& src_loc){
    return _glad_context->CreateQueries(target, n, ids);
}

void GLapi::CreateRenderbuffers(GLsizei n, GLuint* renderbuffers, const SrcLoc& src_loc){
    return _glad_context->CreateRenderbuffers(n, renderbuffers);
}

void GLapi::CreateSamplers(GLsizei n, GLuint* samplers, const SrcLoc& src_loc){
    return _glad_context->CreateSamplers(n, samplers);
}

GLuint GLapi::CreateShader(GLenum type, const SrcLoc& src_loc){
    return _glad_context->CreateShader(type);
}

void GLapi::CreateTextures(GLenum target, GLsizei n, GLuint* textures, const SrcLoc& src_loc){
    return _glad_context->CreateTextures(target, n, textures);
}

void GLapi::CreateTransformFeedbacks(GLsizei n, GLuint* ids, const SrcLoc& src_loc){
    return _glad_context->CreateTransformFeedbacks(n, ids);
}

void GLapi::CreateVertexArrays(GLsizei n, GLuint* arrays, const SrcLoc& src_loc){
    return _glad_context->CreateVertexArrays(n, arrays);
}

void GLapi::CullFace(GLenum mode, const SrcLoc& src_loc){
    return _glad_context->CullFace(mode);
}

// void GLapi::DebugMessageCallback(GLDEBUGPROC callback, const void* userParam, const SrcLoc& src_loc){
//     return _glad_context->DebugMessageCallback(callback, userParam);
//     _debug(src_loc);
// }

void GLapi::DebugMessageControl(GLenum sResource, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled, const SrcLoc& src_loc){
    return _glad_context->DebugMessageControl(sResource, type, severity, count, ids, enabled);
}

void GLapi::DebugMessageInsert(GLenum sResource, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf, const SrcLoc& src_loc){
    return _glad_context->DebugMessageInsert(sResource, type, id, severity, length, buf);
}

void GLapi::DeleteBuffers(GLsizei n, const GLuint* buffers, const SrcLoc& src_loc){
    return _glad_context->DeleteBuffers(n, buffers);
}

void GLapi::DeleteFramebuffers(GLsizei n, const GLuint* framebuffers, const SrcLoc& src_loc){
    return _glad_context->DeleteFramebuffers(n, framebuffers);
}

void GLapi::DeleteProgram(GLuint program, const SrcLoc& src_loc){
    return _glad_context->DeleteProgram(program);
}

void GLapi::DeleteProgramPipelines(GLsizei n, const GLuint* pipelines, const SrcLoc& src_loc){
    return _glad_context->DeleteProgramPipelines(n, pipelines);
}

void GLapi::DeleteQueries(GLsizei n, const GLuint* ids, const SrcLoc& src_loc){
    return _glad_context->DeleteQueries(n, ids);
}

void GLapi::DeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers, const SrcLoc& src_loc){
    return _glad_context->DeleteRenderbuffers(n, renderbuffers);
}

void GLapi::DeleteSamplers(GLsizei count, const GLuint* samplers, const SrcLoc& src_loc){
    return _glad_context->DeleteSamplers(count, samplers);
}

void GLapi::DeleteShader(GLuint shader, const SrcLoc& src_loc){
    return _glad_context->DeleteShader(shader);
}

void GLapi::DeleteSync(GLsync sync, const SrcLoc& src_loc){
    return _glad_context->DeleteSync(sync);
}

void GLapi::DeleteTextures(GLsizei n, const GLuint* textures, const SrcLoc& src_loc){
    return _glad_context->DeleteTextures(n, textures);
}

void GLapi::DeleteTransformFeedbacks(GLsizei n, const GLuint* ids, const SrcLoc& src_loc){
    return _glad_context->DeleteTransformFeedbacks(n, ids);
}

void GLapi::DeleteVertexArrays(GLsizei n, const GLuint* arrays, const SrcLoc& src_loc){
    return _glad_context->DeleteVertexArrays(n, arrays);
}

void GLapi::DepthFunc(GLenum func, const SrcLoc& src_loc){
    return _glad_context->DepthFunc(func);
}

void GLapi::DepthMask(GLboolean flag, const SrcLoc& src_loc){
    return _glad_context->DepthMask(flag);
}

void GLapi::DepthRange(GLdouble n, GLdouble f, const SrcLoc& src_loc){
    return _glad_context->DepthRange(n, f);
}

void GLapi::DepthRangeArrayv(GLuint first, GLsizei count, const GLdouble* v, const SrcLoc& src_loc){
    return _glad_context->DepthRangeArrayv(first, count, v);
}

void GLapi::DepthRangeIndexed(GLuint index, GLdouble n, GLdouble f, const SrcLoc& src_loc){
    return _glad_context->DepthRangeIndexed(index, n, f);
}

void GLapi::DepthRangef(GLfloat n, GLfloat f, const SrcLoc& src_loc){
    return _glad_context->DepthRangef(n, f);
}

void GLapi::DetachShader(GLuint program, GLuint shader, const SrcLoc& src_loc){
    return _glad_context->DetachShader(program, shader);
}

void GLapi::Disable(GLenum cap, const SrcLoc& src_loc){
    return _glad_context->Disable(cap);
}

void GLapi::DisableVertexArrayAttrib(GLuint vaobj, GLuint index, const SrcLoc& src_loc){
    return _glad_context->DisableVertexArrayAttrib(vaobj, index);
}

void GLapi::DisableVertexAttribArray(GLuint index, const SrcLoc& src_loc){
    return _glad_context->DisableVertexAttribArray(index);
}

void GLapi::Disablei(GLenum target, GLuint index, const SrcLoc& src_loc){
    return _glad_context->Disablei(target, index);
}

void GLapi::DispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, const SrcLoc& src_loc){
    return _glad_context->DispatchCompute(num_groups_x, num_groups_y, num_groups_z);
}

void GLapi::DispatchComputeIndirect(GLintptr indirect, const SrcLoc& src_loc){
    return _glad_context->DispatchComputeIndirect(indirect);
}

void GLapi::DrawArrays(GLenum mode, GLint first, GLsizei count, const SrcLoc& src_loc){
    return _glad_context->DrawArrays(mode, first, count);
}

void GLapi::DrawArraysIndirect(GLenum mode, const void* indirect, const SrcLoc& src_loc){
    return _glad_context->DrawArraysIndirect(mode, indirect);
}

void GLapi::DrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, const SrcLoc& src_loc){
    return _glad_context->DrawArraysInstanced(mode, first, count, instancecount);
}

void GLapi::DrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance, const SrcLoc& src_loc){
    return _glad_context->DrawArraysInstancedBaseInstance(mode, first, count, instancecount, instancecount);
}

void GLapi::DrawBuffer(GLenum buf, const SrcLoc& src_loc){
    return _glad_context->DrawBuffer(buf);
}

void GLapi::DrawBuffers(GLsizei n, const GLenum* bufs, const SrcLoc& src_loc){
    return _glad_context->DrawBuffers(n, bufs);
}

void GLapi::DrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices, const SrcLoc& src_loc){
    return _glad_context->DrawElements(mode, count, type, indices);
}

void GLapi::DrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex, const SrcLoc& src_loc){
    return _glad_context->DrawElementsBaseVertex(mode, count, type, indices, basevertex);
}

void GLapi::DrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, const SrcLoc& src_loc){
    return _glad_context->DrawElementsIndirect(mode, type, indirect);
}

void GLapi::DrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, const SrcLoc& src_loc){
    return _glad_context->DrawElementsInstanced(mode, count, type, indices, instancecount);
}

void GLapi::DrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance, const SrcLoc& src_loc){
    return _glad_context->DrawElementsInstancedBaseInstance(mode, count, type, indices, instancecount, baseinstance);
}

void GLapi::DrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, const SrcLoc& src_loc){
    return _glad_context->DrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex);
}

void GLapi::DrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance, const SrcLoc& src_loc){
    return _glad_context->DrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, instancecount, basevertex, baseinstance);
}

void GLapi::DrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, const SrcLoc& src_loc){
    return _glad_context->DrawRangeElements(mode, start, end, count, type, indices);
}

void GLapi::DrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex, const SrcLoc& src_loc){
    return _glad_context->DrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex);
}

void GLapi::DrawTransformFeedback(GLenum mode, GLuint id, const SrcLoc& src_loc){
    return _glad_context->DrawTransformFeedback(mode, id);
}

void GLapi::DrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount, const SrcLoc& src_loc){
    return _glad_context->DrawTransformFeedbackInstanced(mode, id, instancecount);
}

void GLapi::DrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream, const SrcLoc& src_loc){
    return _glad_context->DrawTransformFeedbackStream(mode, id, stream);
}

void GLapi::DrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount, const SrcLoc& src_loc){
    return _glad_context->DrawTransformFeedbackStreamInstanced(mode, id, stream, instancecount);
}

void GLapi::Enable(GLenum cap, const SrcLoc& src_loc){
    return _glad_context->Enable(cap);
}

void GLapi::EnableVertexArrayAttrib(GLuint vaobj, GLuint index, const SrcLoc& src_loc){
    return _glad_context->EnableVertexArrayAttrib(vaobj, index);
}

void GLapi::EnableVertexAttribArray(GLuint index, const SrcLoc& src_loc){
    return _glad_context->EnableVertexAttribArray(index);
}

void GLapi::Enablei(GLenum target, GLuint index, const SrcLoc& src_loc){
    return _glad_context->Enablei(target, index);
}

void GLapi::EndConditionalRender(const SrcLoc& src_loc){
    return _glad_context->EndConditionalRender();
}

void GLapi::EndQuery(GLenum target, const SrcLoc& src_loc){
    return _glad_context->EndQuery(target);
}

void GLapi::EndQueryIndexed(GLenum target, GLuint index, const SrcLoc& src_loc){
    return _glad_context->EndQueryIndexed(target, index);
}

void GLapi::EndTransformFeedback(const SrcLoc& src_loc){
    return _glad_context->EndTransformFeedback();
}

GLsync GLapi::FenceSync(GLenum condition, GLbitfield flags, const SrcLoc& src_loc){
    return _glad_context->FenceSync(condition, flags);
}

void GLapi::Finish(const SrcLoc& src_loc){
    return _glad_context->Finish();
}

void GLapi::Flush(const SrcLoc& src_loc){
    return _glad_context->Flush();
}

void GLapi::FlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, const SrcLoc& src_loc){
    return _glad_context->FlushMappedBufferRange(target, offset, length);
}

void GLapi::FlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, const SrcLoc& src_loc){
    return _glad_context->FlushMappedNamedBufferRange(buffer, offset, length);
}

void GLapi::FramebufferParameteri(GLenum target, GLenum pname, GLint param, const SrcLoc& src_loc){
    return _glad_context->FramebufferParameteri(target, pname, param);
}

void GLapi::FramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer, const SrcLoc& src_loc){
    return _glad_context->FramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}

void GLapi::FramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level, const SrcLoc& src_loc){
    return _glad_context->FramebufferTexture(target, attachment, texture, level);
}

void GLapi::FramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, const SrcLoc& src_loc){
    return _glad_context->FramebufferTexture1D(target, attachment, textarget, target, level);
}

void GLapi::FramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, const SrcLoc& src_loc){
    return _glad_context->FramebufferTexture2D(target, attachment, textarget, texture, level);
}

void GLapi::FramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset, const SrcLoc& src_loc){
    return _glad_context->FramebufferTexture3D(target, attachment, textarget, texture, level, zoffset);
}

void GLapi::FramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer, const SrcLoc& src_loc){
    return _glad_context->FramebufferTextureLayer(target, attachment, texture, level, layer);
}

void GLapi::FrontFace(GLenum mode, const SrcLoc& src_loc){
    return _glad_context->FrontFace(mode);
}

void GLapi::GenBuffers(GLsizei n, GLuint* buffers, const SrcLoc& src_loc){
    return _glad_context->GenBuffers(n, buffers);
}

void GLapi::GenFramebuffers(GLsizei n, GLuint* framebuffers, const SrcLoc& src_loc){
    return _glad_context->GenFramebuffers(n, framebuffers);
}

void GLapi::GenProgramPipelines(GLsizei n, GLuint* pipelines, const SrcLoc& src_loc){
    return _glad_context->GenProgramPipelines(n, pipelines);
}

void GLapi::GenQueries(GLsizei n, GLuint* ids, const SrcLoc& src_loc){
    return _glad_context->GenQueries(n, ids);
}

void GLapi::GenRenderbuffers(GLsizei n, GLuint* renderbuffers, const SrcLoc& src_loc){
    return _glad_context->GenRenderbuffers(n, renderbuffers);
}

void GLapi::GenSamplers(GLsizei count, GLuint* samplers, const SrcLoc& src_loc){
    return _glad_context->GenSamplers(count, samplers);
}

void GLapi::GenTextures(GLsizei n, GLuint* textures, const SrcLoc& src_loc){
    return _glad_context->GenTextures(n, textures);
}

void GLapi::GenTransformFeedbacks(GLsizei n, GLuint* ids, const SrcLoc& src_loc){
    return _glad_context->GenTransformFeedbacks(n, ids);
}

void GLapi::GenVertexArrays(GLsizei n, GLuint* arrays, const SrcLoc& src_loc){
    return _glad_context->GenVertexArrays(n, arrays);
}

void GLapi::GenerateMipmap(GLenum target, const SrcLoc& src_loc){
    return _glad_context->GenerateMipmap(target);
}

void GLapi::GenerateTextureMipmap(GLuint texture, const SrcLoc& src_loc){
    return _glad_context->GenerateTextureMipmap(texture);
}

void GLapi::GetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetActiveAtomicCounterBufferiv(program, bufferIndex, pname, params);
}

void GLapi::GetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name, const SrcLoc& src_loc){
    return _glad_context->GetActiveAttrib(program, index, bufSize, length, size, type, name);
}

void GLapi::GetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name, const SrcLoc& src_loc){
    return _glad_context->GetActiveSubroutineName(program, shadertype, index, bufSize, length, name);
}

void GLapi::GetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name, const SrcLoc& src_loc){
    return _glad_context->GetActiveSubroutineUniformName(program, shadertype, index, bufSize, length, name);
}

void GLapi::GetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values, const SrcLoc& src_loc){
    return _glad_context->GetActiveSubroutineUniformiv(program, shadertype, index, pname, values);
}

void GLapi::GetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name, const SrcLoc& src_loc){
    return _glad_context->GetActiveUniform(program, index, bufSize, length, size, type, name);
}

void GLapi::GetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName, const SrcLoc& src_loc){
    return _glad_context->GetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}

void GLapi::GetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetActiveUniformBlockiv(program, uniformBlockIndex, pname, params);
}

void GLapi::GetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName, const SrcLoc& src_loc){
    return _glad_context->GetActiveUniformName(program, uniformIndex, bufSize, length, uniformName);
}

void GLapi::GetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params);
}

void GLapi::GetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders, const SrcLoc& src_loc){
    return _glad_context->GetAttachedShaders(program, maxCount, count, shaders);
}

GLint GLapi::GetAttribLocation(GLuint program, const GLchar* name, const SrcLoc& src_loc){
    return _glad_context->GetAttribLocation(program, name);
}

void GLapi::GetBooleani_v(GLenum target, GLuint index, GLboolean* data, const SrcLoc& src_loc){
    return _glad_context->GetBooleani_v(target, index, data);
}

void GLapi::GetBooleanv(GLenum pname, GLboolean* data, const SrcLoc& src_loc){
    return _glad_context->GetBooleanv(pname, data);
}

void GLapi::GetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params, const SrcLoc& src_loc){
    return _glad_context->GetBufferParameteri64v(target, pname, params);
}

void GLapi::GetBufferParameteriv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetBufferParameteriv(target, pname, params);
}

void GLapi::GetBufferPointerv(GLenum target, GLenum pname, void** params, const SrcLoc& src_loc){
    return _glad_context->GetBufferPointerv(target, pname, params);
}

void GLapi::GetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void* data, const SrcLoc& src_loc){
    return _glad_context->GetBufferSubData(target, offset, size, data);
}

void GLapi::GetCompressedTexImage(GLenum target, GLint level, void* img, const SrcLoc& src_loc){
    return _glad_context->GetCompressedTexImage(target, level, img);
}

void GLapi::GetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void* pixels, const SrcLoc& src_loc){
    return _glad_context->GetCompressedTextureImage(texture, level, bufSize, pixels);
}

void GLapi::GetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels, const SrcLoc& src_loc){
    return _glad_context->GetCompressedTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
}

GLuint GLapi::GetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum* sResources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog, const SrcLoc& src_loc){
    return _glad_context->GetDebugMessageLog(count, bufSize, sResources, types, ids, severities, lengths, messageLog);
}

void GLapi::GetDoublei_v(GLenum target, GLuint index, GLdouble* data, const SrcLoc& src_loc){
    return _glad_context->GetDoublei_v(target, index, data);
}

void GLapi::GetDoublev(GLenum pname, GLdouble* data, const SrcLoc& src_loc){
    return _glad_context->GetDoublev(pname, data);
}

GLenum GLapi::GetError(const SrcLoc& src_loc){
    return _glad_context->GetError();
}

void GLapi::GetFloati_v(GLenum target, GLuint index, GLfloat* data, const SrcLoc& src_loc){
    return _glad_context->GetFloati_v(target, index, data);
}

void GLapi::GetFloatv(GLenum pname, GLfloat* data, const SrcLoc& src_loc){
    return _glad_context->GetFloatv(pname, data);
}

GLint GLapi::GetFragDataIndex(GLuint program, const GLchar* name, const SrcLoc& src_loc){
    return _glad_context->GetFragDataIndex(program, name);
}

GLint GLapi::GetFragDataLocation(GLuint program, const GLchar* name, const SrcLoc& src_loc){
    return _glad_context->GetFragDataLocation(program, name);
}

void GLapi::GetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}

void GLapi::GetFramebufferParameteriv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetFramebufferParameteriv(target, pname, params);
}
void GLapi::GetInteger64i_v(GLenum target, GLuint index, GLint64* data, const SrcLoc& src_loc){
    return _glad_context->GetInteger64i_v(target, index, data);
}

void GLapi::GetInteger64v(GLenum pname, GLint64* data, const SrcLoc& src_loc){
    return _glad_context->GetInteger64v(pname, data);
}

void GLapi::GetIntegeri_v(GLenum target, GLuint index, GLint* data, const SrcLoc& src_loc){
    return _glad_context->GetIntegeri_v(target, index, data);
}

void GLapi::GetIntegerv(GLenum pname, GLint* data, const SrcLoc& src_loc){
    return _glad_context->GetIntegerv(pname, data);
}

void GLapi::GetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64* params, const SrcLoc& src_loc){
    return _glad_context->GetInternalformati64v(target, internalformat, pname, count, params);
}

void GLapi::GetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetInternalformativ(target, internalformat, pname, count, params);
}

void GLapi::GetMultisamplefv(GLenum pname, GLuint index, GLfloat* val, const SrcLoc& src_loc){
    return _glad_context->GetMultisamplefv(pname, index, val);
}

void GLapi::GetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64* params, const SrcLoc& src_loc){
    return _glad_context->GetNamedBufferParameteri64v(buffer, pname, params);
}

void GLapi::GetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetNamedBufferParameteriv(buffer, pname, params);
}

void GLapi::GetNamedBufferPointerv(GLuint buffer, GLenum pname, void** params, const SrcLoc& src_loc){
    return _glad_context->GetNamedBufferPointerv(buffer, pname, params);
}

void GLapi::GetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data, const SrcLoc& src_loc){
    return _glad_context->GetNamedBufferSubData(buffer, offset, size, data);
}

void GLapi::GetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetNamedFramebufferAttachmentParameteriv(framebuffer, attachment, pname, params);
}

void GLapi::GetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint* param, const SrcLoc& src_loc){
    return _glad_context->GetNamedFramebufferParameteriv(framebuffer, pname, param);
}

void GLapi::GetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetNamedRenderbufferParameteriv(renderbuffer, pname, params);
}

void GLapi::GetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label, const SrcLoc& src_loc){
    return _glad_context->GetObjectLabel(identifier, name, bufSize, length, label);
}

void GLapi::GetObjectPtrLabel(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label, const SrcLoc& src_loc){
    return _glad_context->GetObjectPtrLabel(ptr, bufSize, length, label);
}

void GLapi::GetPointerv(GLenum pname, void** params, const SrcLoc& src_loc){
    return _glad_context->GetPointerv(pname, params);
}

void GLapi::GetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary, const SrcLoc& src_loc){
    return _glad_context->GetProgramBinary(program, bufSize, length, binaryFormat, binary);
}

void GLapi::GetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog, const SrcLoc& src_loc){
    return _glad_context->GetProgramInfoLog(program, bufSize, length, infoLog);
}

void GLapi::GetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetProgramInterfaceiv(program, programInterface, pname, params);
}

void GLapi::GetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog, const SrcLoc& src_loc){
    return _glad_context->GetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog);
}

void GLapi::GetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetProgramPipelineiv(pipeline, pname, params);
}

GLuint GLapi::GetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar* name, const SrcLoc& src_loc){
    return _glad_context->GetProgramResourceIndex(program, programInterface, name);
}

GLint GLapi::GetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar* name, const SrcLoc& src_loc){
    return _glad_context->GetProgramResourceLocation(program, programInterface, name);
}

GLint GLapi::GetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar* name, const SrcLoc& src_loc){
    return _glad_context->GetProgramResourceLocationIndex(program, programInterface, name);
}

void GLapi::GetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name, const SrcLoc& src_loc){
    return _glad_context->GetProgramResourceName(program, programInterface, index, bufSize, length, name);
}

void GLapi::GetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei count, GLsizei* length, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetProgramResourceiv(program, programInterface, index, propCount, props, count, length, params);
}

void GLapi::GetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint* values, const SrcLoc& src_loc){
    return _glad_context->GetProgramStageiv(program, shadertype, pname, values);
}

void GLapi::GetProgramiv(GLuint program, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetProgramiv(program, pname, params);
}

void GLapi::GetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, const SrcLoc& src_loc){
    return _glad_context->GetQueryBufferObjecti64v(id, buffer, pname, offset);
}

void GLapi::GetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, const SrcLoc& src_loc){
    return _glad_context->GetQueryBufferObjectiv(id, buffer, pname, offset);
}

void GLapi::GetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, const SrcLoc& src_loc){
    return _glad_context->GetQueryBufferObjectui64v(id, buffer, pname, offset);
}

void GLapi::GetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, const SrcLoc& src_loc){
    return _glad_context->GetQueryBufferObjectuiv(id, buffer, pname, offset);
}

void GLapi::GetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetQueryIndexediv(target, index, pname, params);
}

void GLapi::GetQueryObjecti64v(GLuint id, GLenum pname, GLint64* params, const SrcLoc& src_loc){
    return _glad_context->GetQueryObjecti64v(id, pname, params);
}

void GLapi::GetQueryObjectiv(GLuint id, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetQueryObjectiv(id, pname, params);
}

void GLapi::GetQueryObjectui64v(GLuint id, GLenum pname, GLuint64* params, const SrcLoc& src_loc){
    return _glad_context->GetQueryObjectui64v(id, pname, params);
}

void GLapi::GetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params, const SrcLoc& src_loc){
    return _glad_context->GetQueryObjectuiv(id, pname, params);
}

void GLapi::GetQueryiv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetQueryiv(target, pname, params);
}

void GLapi::GetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetRenderbufferParameteriv(target, pname, params);
}

void GLapi::GetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetSamplerParameterIiv(sampler, pname, params);
}

void GLapi::GetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* params, const SrcLoc& src_loc){
    return _glad_context->GetSamplerParameterIuiv(sampler, pname, params);
}

void GLapi::GetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params, const SrcLoc& src_loc){
    return _glad_context->GetSamplerParameterfv(sampler, pname, params);
}

void GLapi::GetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetSamplerParameteriv(sampler, pname, params);
}

void GLapi::GetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog, const SrcLoc& src_loc){
    return _glad_context->GetShaderInfoLog(shader, bufSize, length, infoLog);
}

void GLapi::GetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision, const SrcLoc& src_loc){
    return _glad_context->GetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}

void GLapi::GetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* sResource, const SrcLoc& src_loc){
    return _glad_context->GetShaderSource(shader, bufSize, length, sResource);
}

void GLapi::GetShaderiv(GLuint shader, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetShaderiv(shader, pname, params);
}

const GLubyte* GLapi::GetString(GLenum name, const SrcLoc& src_loc){
    return _glad_context->GetString(name);
}

const GLubyte* GLapi::GetStringi(GLenum name, GLuint index, const SrcLoc& src_loc){
    return _glad_context->GetStringi(name, index);
}

GLuint GLapi::GetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar* name, const SrcLoc& src_loc){
    return _glad_context->GetSubroutineIndex(program, shadertype, name);
}

GLint GLapi::GetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar* name, const SrcLoc& src_loc){
    return _glad_context->GetSubroutineUniformLocation(program, shadertype, name);
}

void GLapi::GetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values, const SrcLoc& src_loc){
    return _glad_context->GetSynciv(sync, pname, count, length, values);
}

void GLapi::GetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void* pixels, const SrcLoc& src_loc){
    return _glad_context->GetTexImage(target, level, format, type, pixels);
}

void GLapi::GetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params, const SrcLoc& src_loc){
    return _glad_context->GetTexLevelParameterfv(target, level, pname, params);
}

void GLapi::GetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetTexLevelParameteriv(target, level, pname, params);
}

void GLapi::GetTexParameterIiv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetTexParameterIiv(target, pname, params);
}

void GLapi::GetTexParameterIuiv(GLenum target, GLenum pname, GLuint* params, const SrcLoc& src_loc){
    return _glad_context->GetTexParameterIuiv(target, pname, params);
}

void GLapi::GetTexParameterfv(GLenum target, GLenum pname, GLfloat* params, const SrcLoc& src_loc){
    return _glad_context->GetTexParameterfv(target, pname, params);
}

void GLapi::GetTexParameteriv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetTexParameteriv(target, pname, params);
}

void GLapi::GetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels, const SrcLoc& src_loc){
    return _glad_context->GetTextureImage(texture, level, format, type, bufSize, pixels);
}

void GLapi::GetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat* params, const SrcLoc& src_loc){
    return _glad_context->GetTextureLevelParameterfv(texture, level, pname, params);
}

void GLapi::GetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetTextureLevelParameteriv(texture, level, pname, params);
}

void GLapi::GetTextureParameterIiv(GLuint texture, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetTextureParameterIiv(texture, pname, params);
}

void GLapi::GetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint* params, const SrcLoc& src_loc){
    return _glad_context->GetTextureParameterIuiv(texture, pname, params);
}

void GLapi::GetTextureParameterfv(GLuint texture, GLenum pname, GLfloat* params, const SrcLoc& src_loc){
    return _glad_context->GetTextureParameterfv(texture, pname, params);
}

void GLapi::GetTextureParameteriv(GLuint texture, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetTextureParameteriv(texture, pname, params);
}

void GLapi::GetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels, const SrcLoc& src_loc){
    return _glad_context->GetTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels);
}

void GLapi::GetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name, const SrcLoc& src_loc){
    return _glad_context->GetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
}

void GLapi::GetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64* param, const SrcLoc& src_loc){
    return _glad_context->GetTransformFeedbacki64_v(xfb, pname, index, param);
}

void GLapi::GetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint* param, const SrcLoc& src_loc){
    return _glad_context->GetTransformFeedbacki_v(xfb, pname, index, param);
}

void GLapi::GetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint* param, const SrcLoc& src_loc){
    return _glad_context->GetTransformFeedbackiv(xfb, pname, param);
}

GLuint GLapi::GetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName, const SrcLoc& src_loc){
    return _glad_context->GetUniformBlockIndex(program, uniformBlockName);
}

GLint GLapi::GetUniformLocation(GLuint program, const GLchar* name, const SrcLoc& src_loc){
    return _glad_context->GetUniformLocation(program, name);
}

void GLapi::GetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params, const SrcLoc& src_loc){
    return _glad_context->GetUniformSubroutineuiv(shadertype, location, params);
}

void GLapi::GetUniformdv(GLuint program, GLint location, GLdouble* params, const SrcLoc& src_loc){
    return _glad_context->GetUniformdv(program, location, params);
}

void GLapi::GetUniformfv(GLuint program, GLint location, GLfloat* params, const SrcLoc& src_loc){
    return _glad_context->GetUniformfv(program, location, params);
}

void GLapi::GetUniformiv(GLuint program, GLint location,  GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetUniformiv(program, location, params);
}

void GLapi::GetUniformuiv(GLuint program, GLint location, GLuint* params, const SrcLoc& src_loc){
    return _glad_context->GetUniformuiv(program, location, params);
}

void GLapi::GetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64* param, const SrcLoc& src_loc){
    return _glad_context->GetVertexArrayIndexed64iv(vaobj, index, pname, param);
}

void GLapi::GetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint* param, const SrcLoc& src_loc){
    return _glad_context->GetVertexArrayIndexediv(vaobj, index, pname, param);
}

void GLapi::GetVertexArrayiv(GLuint vaobj, GLenum pname, GLint* param, const SrcLoc& src_loc){
    return _glad_context->GetVertexArrayiv(vaobj, pname, param);
}

void GLapi::GetVertexAttribIiv(GLuint index, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetVertexAttribIiv(index, pname, params);
}

void GLapi::GetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params, const SrcLoc& src_loc){
    return _glad_context->GetVertexAttribIuiv(index, pname, params);
}

void GLapi::GetVertexAttribLdv(GLuint index, GLenum pname, GLdouble* params, const SrcLoc& src_loc){
    return _glad_context->GetVertexAttribLdv(index, pname, params);
}

void GLapi::GetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer, const SrcLoc& src_loc){
    return _glad_context->GetVertexAttribPointerv(index, pname, pointer);
}

void GLapi::GetVertexAttribdv(GLuint index, GLenum pname, GLdouble* params, const SrcLoc& src_loc){
    return _glad_context->GetVertexAttribdv(index, pname, params);
}

void GLapi::GetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params, const SrcLoc& src_loc){
    return _glad_context->GetVertexAttribfv(index, pname, params);
}

void GLapi::GetVertexAttribiv(GLuint index, GLenum pname, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetVertexAttribiv(index, pname, params);
}

void GLapi::GetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void* pixels, const SrcLoc& src_loc){
    return _glad_context->GetnCompressedTexImage(target, lod, bufSize, pixels);
}

void GLapi::GetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels, const SrcLoc& src_loc){
    return _glad_context->GetnTexImage(target, level, format, type, bufSize, pixels);
}

void GLapi::GetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble* params, const SrcLoc& src_loc){
    return _glad_context->GetnUniformdv(program, location, bufSize, params);
}

void GLapi::GetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat* params, const SrcLoc& src_loc){
    return _glad_context->GetnUniformfv(program, location, bufSize, params);
}

void GLapi::GetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint* params, const SrcLoc& src_loc){
    return _glad_context->GetnUniformiv(program, location, bufSize, params);
}

void GLapi::GetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint* params, const SrcLoc& src_loc){
    return _glad_context->GetnUniformuiv(program, location, bufSize, params);
}

void GLapi::Hint(GLenum target, GLenum mode, const SrcLoc& src_loc){
    return _glad_context->Hint(target, mode);
}

void GLapi::InvalidateBufferData(GLuint buffer, const SrcLoc& src_loc){
    return _glad_context->InvalidateBufferData(buffer);
}

void GLapi::InvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length, const SrcLoc& src_loc){
    return _glad_context->InvalidateBufferSubData(buffer, offset, length);
}

void GLapi::InvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments, const SrcLoc& src_loc){
    return _glad_context->InvalidateFramebuffer(target, numAttachments, attachments);
}

void GLapi::InvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, const SrcLoc& src_loc){
    return _glad_context->InvalidateNamedFramebufferData(framebuffer, numAttachments, attachments);
}

void GLapi::InvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc){
    return _glad_context->InvalidateNamedFramebufferSubData(framebuffer, numAttachments, attachments, x, y, width, height);
}

void GLapi::InvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc){
    return _glad_context->InvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height);
}

void GLapi::InvalidateTexImage(GLuint texture, GLint level, const SrcLoc& src_loc){
    return _glad_context->InvalidateTexImage(texture, level);
}

void GLapi::InvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, const SrcLoc& src_loc){
    return _glad_context->InvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth);
}

GLboolean GLapi::IsBuffer(GLuint buffer, const SrcLoc& src_loc){
    return _glad_context->IsBuffer(buffer);
}

GLboolean GLapi::IsEnabled(GLenum cap, const SrcLoc& src_loc){
    return _glad_context->IsEnabled(cap);
}

GLboolean GLapi::IsEnabledi(GLenum target, GLuint index, const SrcLoc& src_loc){
    return _glad_context->IsEnabledi(target, index);
}

GLboolean GLapi::IsFramebuffer(GLuint framebuffer, const SrcLoc& src_loc){
    return _glad_context->IsFramebuffer(framebuffer);
}

GLboolean GLapi::IsProgram(GLuint program, const SrcLoc& src_loc){
    return _glad_context->IsProgram(program);
}

GLboolean GLapi::IsProgramPipeline(GLuint pipeline, const SrcLoc& src_loc){
    return _glad_context->IsProgramPipeline(pipeline);
}

GLboolean GLapi::IsQuery(GLuint id, const SrcLoc& src_loc){
    return _glad_context->IsQuery(id);
}

GLboolean GLapi::IsRenderbuffer(GLuint renderbuffer, const SrcLoc& src_loc){
    return _glad_context->IsRenderbuffer(renderbuffer);
}

GLboolean GLapi::IsSampler(GLuint sampler, const SrcLoc& src_loc){
    return _glad_context->IsSampler(sampler);
}

GLboolean GLapi::IsShader(GLuint shader, const SrcLoc& src_loc){
    return _glad_context->IsShader(shader);
}

GLboolean GLapi::IsSync(GLsync sync, const SrcLoc& src_loc){
    return _glad_context->IsSync(sync);
}

GLboolean GLapi::IsTexture(GLuint texture, const SrcLoc& src_loc){
    return _glad_context->IsTexture(texture);
}

GLboolean GLapi::IsTransformFeedback(GLuint id, const SrcLoc& src_loc){
    return _glad_context->IsTransformFeedback(id);
}

GLboolean GLapi::IsVertexArray(GLuint array, const SrcLoc& src_loc){
    return _glad_context->IsVertexArray(array);
}

void GLapi::LineWidth(GLfloat width, const SrcLoc& src_loc){
    return _glad_context->LineWidth(width);
}

void GLapi::LinkProgram(GLuint program, const SrcLoc& src_loc){
    return _glad_context->LinkProgram(program);
}

void GLapi::LogicOp(GLenum opcode, const SrcLoc& src_loc){
    return _glad_context->LogicOp(opcode);
}

void GLapi::MemoryBarrier(GLbitfield barriers, const SrcLoc& src_loc){
    return _glad_context->MemoryBarrier(barriers);
}

void GLapi::MemoryBarrierByRegion(GLbitfield barriers, const SrcLoc& src_loc){
    return _glad_context->MemoryBarrierByRegion(barriers);
}

void GLapi::MinSampleShading(GLfloat value, const SrcLoc& src_loc){
    return _glad_context->MinSampleShading(value);
}

void GLapi::MultiDrawArrays(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount, const SrcLoc& src_loc){
    return _glad_context->MultiDrawArrays(mode, first, count, drawcount);
}

void GLapi::MultiDrawArraysIndirect(GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride, const SrcLoc& src_loc){
    return _glad_context->MultiDrawArraysIndirect(mode, indirect, drawcount, stride);
}

void GLapi::MultiDrawArraysIndirectCount(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride, const SrcLoc& src_loc){
    return _glad_context->MultiDrawArraysIndirectCount(mode, indirect, drawcount, maxdrawcount, stride);
}

void GLapi::MultiDrawElements(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const SrcLoc& src_loc){
    return _glad_context->MultiDrawElements(mode, count, type, indices, drawcount);
}

void GLapi::MultiDrawElementsBaseVertex(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex, const SrcLoc& src_loc){
    return _glad_context->MultiDrawElementsBaseVertex(mode, count, type, indices, drawcount, basevertex);
}

void GLapi::MultiDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride, const SrcLoc& src_loc){
    return _glad_context->MultiDrawElementsIndirect(mode, type, indirect, drawcount, stride);
}

void GLapi::MultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride, const SrcLoc& src_loc){
    return _glad_context->MultiDrawElementsIndirectCount(mode, type, indirect, drawcount, maxdrawcount, stride);
}

void GLapi::NamedBufferData(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage, const SrcLoc& src_loc){
    return _glad_context->NamedBufferData(buffer, size, data, usage);
}

void GLapi::NamedBufferStorage(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags, const SrcLoc& src_loc){
    return _glad_context->NamedBufferStorage(buffer, size, data, flags);
}

void GLapi::NamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data, const SrcLoc& src_loc){
    return _glad_context->NamedBufferSubData(buffer, offset, size, data);
}

void GLapi::NamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf, const SrcLoc& src_loc){
    return _glad_context->NamedFramebufferDrawBuffer(framebuffer, buf);
}

void GLapi::NamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum* bufs, const SrcLoc& src_loc){
    return _glad_context->NamedFramebufferDrawBuffers(framebuffer, n, bufs);
}

void GLapi::NamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param, const SrcLoc& src_loc){
    return _glad_context->NamedFramebufferParameteri(framebuffer, pname, param);
}

void GLapi::NamedFramebufferReadBuffer(GLuint framebuffer, GLenum src, const SrcLoc& src_loc){
    return _glad_context->NamedFramebufferReadBuffer(framebuffer, src);
}

void GLapi::NamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer, const SrcLoc& src_loc){
    return _glad_context->NamedFramebufferRenderbuffer(framebuffer, attachment, renderbuffertarget, renderbuffer);
}

void GLapi::NamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, const SrcLoc& src_loc){
    return _glad_context->NamedFramebufferTexture(framebuffer, attachment, texture, level);
}

void GLapi::NamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer, const SrcLoc& src_loc){
    return _glad_context->NamedFramebufferTextureLayer(framebuffer, attachment, texture, level, layer);
}

void GLapi::NamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc){
    return _glad_context->NamedRenderbufferStorage(renderbuffer, internalformat, width, height);
}

void GLapi::NamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc){
    return _glad_context->NamedRenderbufferStorageMultisample(renderbuffer, samples, internalformat, width, height);
}

void GLapi::ObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar* label, const SrcLoc& src_loc){
    return _glad_context->ObjectLabel(identifier, name, length, label);
}

void GLapi::ObjectPtrLabel(const void* ptr, GLsizei length, const GLchar* label, const SrcLoc& src_loc){
    return _glad_context->ObjectPtrLabel(ptr, length, label);
}

void GLapi::PatchParameterfv(GLenum pname, const GLfloat* values, const SrcLoc& src_loc){
    return _glad_context->PatchParameterfv(pname, values);
}

void GLapi::PatchParameteri(GLenum pname, GLint value, const SrcLoc& src_loc){
    return _glad_context->PatchParameteri(pname, value);
}

void GLapi::PauseTransformFeedback(const SrcLoc& src_loc){
    return _glad_context->PauseTransformFeedback();
}

void GLapi::PixelStoref(GLenum pname, GLfloat param, const SrcLoc& src_loc){
    return _glad_context->PixelStoref(pname, param);
}

void GLapi::PixelStorei(GLenum pname, GLint param, const SrcLoc& src_loc){
    return _glad_context->PixelStorei(pname, param);
}

void GLapi::PointParameterf(GLenum pname, GLfloat param, const SrcLoc& src_loc){
    return _glad_context->PointParameterf(pname, param);
}

void GLapi::PointParameterfv(GLenum pname, const GLfloat* params, const SrcLoc& src_loc){
    return _glad_context->PointParameterfv(pname, params);
}

void GLapi::PointParameteri(GLenum pname, GLint param, const SrcLoc& src_loc){
    return _glad_context->PointParameteri(pname, param);
}

void GLapi::PointParameteriv(GLenum pname, const GLint* params, const SrcLoc& src_loc){
    return _glad_context->PointParameteriv(pname, params);
}

void GLapi::PointSize(GLfloat size, const SrcLoc& src_loc){
    return _glad_context->PointSize(size);
}

void GLapi::PolygonMode(GLenum face, GLenum mode, const SrcLoc& src_loc){
    return _glad_context->PolygonMode(face, mode);
}

void GLapi::PolygonOffset(GLfloat factor, GLfloat units, const SrcLoc& src_loc){
    return _glad_context->PolygonOffset(factor, units);
}

void GLapi::PolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp, const SrcLoc& src_loc){
    return _glad_context->PolygonOffsetClamp(factor, units, clamp);
}

void GLapi::PopDebugGroup(const SrcLoc& src_loc){
    return _glad_context->PopDebugGroup();
}

void GLapi::PrimitiveRestartIndex(GLuint index, const SrcLoc& src_loc){
    return _glad_context->PrimitiveRestartIndex(index);
}

void GLapi::ProgramBinary(GLuint program, GLenum binaryFormat, const void* binary, GLsizei length, const SrcLoc& src_loc){
    return _glad_context->ProgramBinary(program, binaryFormat, binary, length);
}

void GLapi::ProgramParameteri(GLuint program, GLenum pname, GLint value, const SrcLoc& src_loc){
    return _glad_context->ProgramParameteri(program, pname, value);
}

void GLapi::ProgramUniform1d(GLuint program, GLint location, GLdouble v0, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform1d(program, location, v0);
}

void GLapi::ProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform1dv(program, location, count, value);
}

void GLapi::ProgramUniform1f(GLuint program, GLint location, GLfloat v0, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform1f(program, location, v0);
}

void GLapi::ProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform1fv(program, location, count, value);
}

void GLapi::ProgramUniform1i(GLuint program, GLint location, GLint v0, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform1i(program, location, v0);
}

void GLapi::ProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform1iv(program, location, count, value);
}

void GLapi::ProgramUniform1ui(GLuint program, GLint location, GLuint v0, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform1ui(program, location, v0);
}

void GLapi::ProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform1uiv(program, location, count, value);
}

void GLapi::ProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform2d(program, location, v0, v1);
}

void GLapi::ProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform2dv(program, location, count, value);
}

void GLapi::ProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform2f(program, location, v0, v1);
}

void GLapi::ProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform2fv(program, location, count, value);
}

void GLapi::ProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform2i(program, location, v0, v1);
}

void GLapi::ProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform2iv(program, location, count, value);
}

void GLapi::ProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform2ui(program, location, v0, v1);
}

void GLapi::ProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform2uiv(program, location, count, value);
}

void GLapi::ProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform3d(program, location, v0, v1, v2);
}

void GLapi::ProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform3dv(program, location, count, value);
}

void GLapi::ProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform3f(program, location, v0, v1, v2);
}

void GLapi::ProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform3fv(program, location, count, value);
}

void GLapi::ProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform3i(program, location, v0, v1, v2);
}

void GLapi::ProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform3iv(program, location, count, value);
}

void GLapi::ProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform3ui(program, location, v0, v1, v2);
}

void GLapi::ProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform3uiv(program, location, count, value);
}

void GLapi::ProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform4d(program, location, v0, v1, v2, v3);
}

void GLapi::ProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform4dv(program, location, count, value);
}

void GLapi::ProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform4f(program, location, v0, v1, v2, v3);
}

void GLapi::ProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform4fv(program, location, count, value);
}

void GLapi::ProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform4i(program, location, v0, v1, v2, v3);
}

void GLapi::ProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform4iv(program, location, count, value);
}

void GLapi::ProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform4ui(program, location, v0, v1, v2, v3);
}

void GLapi::ProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniform4uiv(program, location, count, value);
}

void GLapi::ProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix2dv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix2fv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix2x3dv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix2x3fv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix2x4dv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix2x4fv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix3dv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix3fv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix3x2dv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix3x2fv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix3x4dv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix3x4fv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix4dv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix4fv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix4x2dv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix4x2fv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix4x3dv(program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->ProgramUniformMatrix4x3fv(program, location, count, transpose, value);
}

void GLapi::ProvokingVertex(GLenum mode, const SrcLoc& src_loc){
    return _glad_context->ProvokingVertex(mode);
}

void GLapi::PushDebugGroup(GLenum sResource, GLuint id, GLsizei length, const GLchar* message, const SrcLoc& src_loc){
    return _glad_context->PushDebugGroup(sResource, id, length, message);
}

void GLapi::QueryCounter(GLuint id, GLenum target, const SrcLoc& src_loc){
    return _glad_context->QueryCounter(id, target);
}

void GLapi::ReadBuffer(GLenum src, const SrcLoc& src_loc){
    return _glad_context->ReadBuffer(src);
}

void GLapi::ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels, const SrcLoc& src_loc){
    return _glad_context->ReadPixels(x, y, width, height, format, type, pixels);
}

void GLapi::ReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data, const SrcLoc& src_loc){
    return _glad_context->ReadnPixels(x, y, width, height, format, type, bufSize, data);
}

void GLapi::ReleaseShaderCompiler(const SrcLoc& src_loc){
    return _glad_context->ReleaseShaderCompiler();
}

void GLapi::RenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc){
    return _glad_context->RenderbufferStorage(target, internalformat, width, height);
}

void GLapi::RenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc){
    return _glad_context->RenderbufferStorageMultisample(target, samples, internalformat, width, height);
}

void GLapi::ResumeTransformFeedback(const SrcLoc& src_loc){
    return _glad_context->ResumeTransformFeedback();
}

void GLapi::SampleCoverage(GLfloat value, GLboolean invert, const SrcLoc& src_loc){
    return _glad_context->SampleCoverage(value, invert);
}

void GLapi::SampleMaski(GLuint maskNumber, GLbitfield mask, const SrcLoc& src_loc){
    return _glad_context->SampleMaski(maskNumber, mask);
}

void GLapi::SamplerParameterIiv(GLuint sampler, GLenum pname, const GLint* param, const SrcLoc& src_loc){
    return _glad_context->SamplerParameterIiv(sampler, pname, param);
}

void GLapi::SamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint* param, const SrcLoc& src_loc){
    return _glad_context->SamplerParameterIuiv(sampler, pname, param);
}

void GLapi::SamplerParameterf(GLuint sampler, GLenum pname, GLfloat param, const SrcLoc& src_loc){
    return _glad_context->SamplerParameterf(sampler, pname, param);
}

void GLapi::SamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat* param, const SrcLoc& src_loc){
    return _glad_context->SamplerParameterfv(sampler, pname, param);
}

void GLapi::SamplerParameteri(GLuint sampler, GLenum pname, GLint param, const SrcLoc& src_loc){
    return _glad_context->SamplerParameteri(sampler, pname, param);
}

void GLapi::SamplerParameteriv(GLuint sampler, GLenum pname, const GLint* param, const SrcLoc& src_loc){
    return _glad_context->SamplerParameteriv(sampler, pname, param);
}

void GLapi::Scissor(GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc){
    return _glad_context->Scissor(x, y, width, height);
}

void GLapi::ScissorArrayv(GLuint first, GLsizei count, const GLint* v, const SrcLoc& src_loc){
    return _glad_context->ScissorArrayv(first, count, v);
}

void GLapi::ScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height, const SrcLoc& src_loc){
    return _glad_context->ScissorIndexed(index, left, bottom, width, height);
}

void GLapi::ScissorIndexedv(GLuint index, const GLint* v, const SrcLoc& src_loc){
    return _glad_context->ScissorIndexedv(index, v);
}

void GLapi::ShaderBinary(GLsizei count, const GLuint* shaders, GLenum binaryFormat, const void* binary, GLsizei length, const SrcLoc& src_loc){
    return _glad_context->ShaderBinary(count, shaders, binaryFormat, binary, length);
}

void GLapi::ShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding, const SrcLoc& src_loc){
    return _glad_context->ShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding);
}

void GLapi::SpecializeShader(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue, const SrcLoc& src_loc){
    return _glad_context->SpecializeShader(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}

void GLapi::StencilFunc(GLenum func, GLint ref, GLuint mask, const SrcLoc& src_loc){
    return _glad_context->StencilFunc(func, ref, mask);
}

void GLapi::StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask, const SrcLoc& src_loc){
    return _glad_context->StencilFuncSeparate(face, func, ref, mask);
}

void GLapi::StencilMask(GLuint mask, const SrcLoc& src_loc){
    return _glad_context->StencilMask(mask);
}

void GLapi::StencilMaskSeparate(GLenum face, GLuint mask, const SrcLoc& src_loc){
    return _glad_context->StencilMaskSeparate(face, mask);
}

void GLapi::StencilOp(GLenum fail, GLenum zfail, GLenum zpass, const SrcLoc& src_loc){
    return _glad_context->StencilOp(fail, zfail, zpass);
}

void GLapi::StencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass, const SrcLoc& src_loc){
    return _glad_context->StencilOpSeparate(face, sfail, dpfail, dppass);
}

void GLapi::TexBuffer(GLenum target, GLenum internalformat, GLuint buffer, const SrcLoc& src_loc){
    return _glad_context->TexBuffer(target, internalformat, buffer);
}

void GLapi::TexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size, const SrcLoc& src_loc){
    return _glad_context->TexBufferRange(target, internalformat, buffer, offset, size);
}

void GLapi::TexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc){
    return _glad_context->TexImage1D(target, level, internalformat, width, border, format, type, pixels);
}

void GLapi::TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc){
    return _glad_context->TexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}

void GLapi::TexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, const SrcLoc& src_loc){
    return _glad_context->TexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
}

void GLapi::TexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc){
    return _glad_context->TexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
}

void GLapi::TexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, const SrcLoc& src_loc){
    return _glad_context->TexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void GLapi::TexParameterIiv(GLenum target, GLenum pname, const GLint* params, const SrcLoc& src_loc){
    return _glad_context->TexParameterIiv(target, pname, params);
}

void GLapi::TexParameterIuiv(GLenum target, GLenum pname, const GLuint* params, const SrcLoc& src_loc){
    return _glad_context->TexParameterIuiv(target, pname, params);
}

void GLapi::TexParameterf(GLenum target, GLenum pname, GLfloat param, const SrcLoc& src_loc){
    return _glad_context->TexParameterf(target, pname, param);
}

void GLapi::TexParameterfv(GLenum target, GLenum pname, const GLfloat* params, const SrcLoc& src_loc){
    return _glad_context->TexParameterfv(target, pname, params);
}

void GLapi::TexParameteri(GLenum target, GLenum pname, GLint param, const SrcLoc& src_loc){
    return _glad_context->TexParameteri(target, pname, param);
}

void GLapi::TexParameteriv(GLenum target, GLenum pname, const GLint* params, const SrcLoc& src_loc){
    return _glad_context->TexParameteriv(target, pname, params);
}

void GLapi::TexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, const SrcLoc& src_loc){
    return _glad_context->TexStorage1D(target, levels, internalformat, width);
}

void GLapi::TexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc){
    return _glad_context->TexStorage2D(target, levels, internalformat, width, height);
}

void GLapi::TexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, const SrcLoc& src_loc){
    return _glad_context->TexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
}

void GLapi::TexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, const SrcLoc& src_loc){
    return _glad_context->TexStorage3D(target, levels, internalformat, width, height, depth);
}

void GLapi::TexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, const SrcLoc& src_loc){
    return _glad_context->TexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void GLapi::TexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc){
    return _glad_context->TexSubImage1D(target, level, xoffset, width, format, type, pixels);
}

void GLapi::TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc){
    return _glad_context->TexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void GLapi::TexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc){
    return _glad_context->TexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void GLapi::TextureBarrier(const SrcLoc& src_loc){
    return _glad_context->TextureBarrier();
}

void GLapi::TextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer, const SrcLoc& src_loc){
    return _glad_context->TextureBuffer(texture, internalformat, buffer);
}

void GLapi::TextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size, const SrcLoc& src_loc){
    return _glad_context->TextureBufferRange(texture, internalformat, buffer, offset, size);
}

void GLapi::TextureParameterIiv(GLuint texture, GLenum pname, const GLint* params, const SrcLoc& src_loc){
    return _glad_context->TextureParameterIiv(texture, pname, params);
}

void GLapi::TextureParameterIuiv(GLuint texture, GLenum pname, const GLuint* params, const SrcLoc& src_loc){
    return _glad_context->TextureParameterIuiv(texture, pname, params);
}

void GLapi::TextureParameterf(GLuint texture, GLenum pname, GLfloat param, const SrcLoc& src_loc){
    return _glad_context->TextureParameterf(texture, pname, param);
}

void GLapi::TextureParameterfv(GLuint texture, GLenum pname, const GLfloat* param, const SrcLoc& src_loc){
    return _glad_context->TextureParameterfv(texture, pname, param);
}

void GLapi::TextureParameteri(GLuint texture, GLenum pname, GLint param, const SrcLoc& src_loc){
    return _glad_context->TextureParameteri(texture, pname, param);
}

void GLapi::TextureParameteriv(GLuint texture, GLenum pname, const GLint* param, const SrcLoc& src_loc){
    return _glad_context->TextureParameteriv(texture, pname, param);
}

void GLapi::TextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, const SrcLoc& src_loc){
    return _glad_context->TextureStorage1D(texture, levels, internalformat, width);
}

void GLapi::TextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc){
    return _glad_context->TextureStorage2D(texture, levels, internalformat, width, height);
}

void GLapi::TextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, const SrcLoc& src_loc){
    return _glad_context->TextureStorage2DMultisample(texture, samples, internalformat, width, height, fixedsamplelocations);
}

void GLapi::TextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, const SrcLoc& src_loc){
    return _glad_context->TextureStorage3D(texture, levels, internalformat, width, height, depth);
}

void GLapi::TextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, const SrcLoc& src_loc){
    return _glad_context->TextureStorage3DMultisample(texture, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void GLapi::TextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc){
    return _glad_context->TextureSubImage1D(texture, level, xoffset, width, format, type, pixels);
}

void GLapi::TextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc){
    return _glad_context->TextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, type, pixels);
}

void GLapi::TextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc){
    return _glad_context->TextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void GLapi::TextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers, const SrcLoc& src_loc){
    return _glad_context->TextureView(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
}

void GLapi::TransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer, const SrcLoc& src_loc){
    return _glad_context->TransformFeedbackBufferBase(xfb, index, buffer);
}

void GLapi::TransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size, const SrcLoc& src_loc){
    return _glad_context->TransformFeedbackBufferRange(xfb, index, buffer, offset, size);
}

void GLapi::Uniform1d(GLint location, GLdouble x, const SrcLoc& src_loc){
    return _glad_context->Uniform1d(location, x);
}

void GLapi::Uniform1dv(GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->Uniform1dv(location, count, value);
}

void GLapi::Uniform1f(GLint location, GLfloat v0, const SrcLoc& src_loc){
    return _glad_context->Uniform1f(location, v0);
}

void GLapi::Uniform1fv(GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->Uniform1fv(location, count, value);
}

void GLapi::Uniform1i(GLint location, GLint v0, const SrcLoc& src_loc){
    return _glad_context->Uniform1i(location, v0);
}

void GLapi::Uniform1iv(GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc){
    return _glad_context->Uniform1iv(location, count, value);
}

void GLapi::Uniform1ui(GLint location, GLuint v0, const SrcLoc& src_loc){
    return _glad_context->Uniform1ui(location, v0);
}

void GLapi::Uniform1uiv(GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc){
    return _glad_context->Uniform1uiv(location, count, value);
}

void GLapi::Uniform2d(GLint location, GLdouble x, GLdouble y, const SrcLoc& src_loc){
    return _glad_context->Uniform2d(location, x, y);
}

void GLapi::Uniform2dv(GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->Uniform2dv(location, count, value);
}

void GLapi::Uniform2f(GLint location, GLfloat v0, GLfloat v1, const SrcLoc& src_loc){
    return _glad_context->Uniform2f(location, v0, v1);
}

void GLapi::Uniform2fv(GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->Uniform2fv(location, count, value);
}

void GLapi::Uniform2i(GLint location, GLint v0, GLint v1, const SrcLoc& src_loc){
    return _glad_context->Uniform2i(location, v0, v1);
}

void GLapi::Uniform2iv(GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc){
    return _glad_context->Uniform2iv(location, count, value);
}

void GLapi::Uniform2ui(GLint location, GLuint v0, GLuint v1, const SrcLoc& src_loc){
    return _glad_context->Uniform2ui(location, v0, v1);
}

void GLapi::Uniform2uiv(GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc){
    return _glad_context->Uniform2uiv(location, count, value);
}

void GLapi::Uniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc){
    return _glad_context->Uniform3d(location, x, y, z);
}

void GLapi::Uniform3dv(GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->Uniform3dv(location, count, value);
}

void GLapi::Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, const SrcLoc& src_loc){
    return _glad_context->Uniform3f(location, v0, v1, v2);
}

void GLapi::Uniform3fv(GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->Uniform3fv(location, count, value);
}

void GLapi::Uniform3i(GLint location, GLint v0, GLint v1, GLint v2, const SrcLoc& src_loc){
    return _glad_context->Uniform3i(location, v0, v1, v2);
}

void GLapi::Uniform3iv(GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc){
    return _glad_context->Uniform3iv(location, count, value);
}

void GLapi::Uniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2, const SrcLoc& src_loc){
    return _glad_context->Uniform3ui(location, v0, v1, v2);
}

void GLapi::Uniform3uiv(GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc){
    return _glad_context->Uniform3uiv(location, count, value);
}

void GLapi::Uniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w, const SrcLoc& src_loc){
    return _glad_context->Uniform4d(location, x, y, z, w);
}

void GLapi::Uniform4dv(GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->Uniform4dv(location, count, value);
}

void GLapi::Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3, const SrcLoc& src_loc){
    return _glad_context->Uniform4f(location, v0, v1, v2, v3);
}

void GLapi::Uniform4fv(GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->Uniform4fv(location, count, value);
}

void GLapi::Uniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3, const SrcLoc& src_loc){
    return _glad_context->Uniform4i(location, v0, v1, v2, v3);
}

void GLapi::Uniform4iv(GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc){
    return _glad_context->Uniform4iv(location, count, value);
}

void GLapi::Uniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3, const SrcLoc& src_loc){
    return _glad_context->Uniform4ui(location, v0, v1, v2, v3);
}

void GLapi::Uniform4uiv(GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc){
    return _glad_context->Uniform4uiv(location, count, value);
}

void GLapi::UniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding, const SrcLoc& src_loc){
    return _glad_context->UniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
}

void GLapi::UniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix2dv(location, count, transpose, value);
}

void GLapi::UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix2fv(location, count, transpose, value);
}

void GLapi::UniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix2x3dv(location, count, transpose, value);
}

void GLapi::UniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix2x3fv(location, count, transpose, value);
}

void GLapi::UniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix2x4dv(location, count, transpose, value);
}

void GLapi::UniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix2x4fv(location, count, transpose, value);
}

void GLapi::UniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix3dv(location, count, transpose, value);
}

void GLapi::UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix3fv(location, count, transpose, value);
}

void GLapi::UniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix3x2dv(location, count, transpose, value);
}

void GLapi::UniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix3x2fv(location, count, transpose, value);
}

void GLapi::UniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix3x4dv(location, count, transpose, value);
}

void GLapi::UniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix3x4fv(location, count, transpose, value);
}

void GLapi::UniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix4dv(location, count, transpose, value);
}

void GLapi::UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix4fv(location, count, transpose, value);
}

void GLapi::UniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix4x2dv(location, count, transpose, value);
}

void GLapi::UniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix4x2fv(location, count, transpose, value);
}

void GLapi::UniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix4x3dv(location, count, transpose, value);
}

void GLapi::UniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc){
    return _glad_context->UniformMatrix4x3fv(location, count, transpose, value);
}

void GLapi::UniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint* indices, const SrcLoc& src_loc){
    return _glad_context->UniformSubroutinesuiv(shadertype, count, indices);
}

GLboolean GLapi::UnmapBuffer(GLenum target, const SrcLoc& src_loc){
    return _glad_context->UnmapBuffer(target);
}

GLboolean GLapi::UnmapNamedBuffer(GLuint buffer, const SrcLoc& src_loc){
    return _glad_context->UnmapNamedBuffer(buffer);
}

void GLapi::UseProgram(GLuint program, const SrcLoc& src_loc){
    return _glad_context->UseProgram(program);
}

void GLapi::UseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program, const SrcLoc& src_loc){
    return _glad_context->UseProgramStages(pipeline, stages, program);
}

void GLapi::ValidateProgram(GLuint program, const SrcLoc& src_loc){
    return _glad_context->ValidateProgram(program);
}

void GLapi::ValidateProgramPipeline(GLuint pipeline, const SrcLoc& src_loc){
    return _glad_context->ValidateProgramPipeline(pipeline);
}

void GLapi::VertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex, const SrcLoc& src_loc){
    return _glad_context->VertexArrayAttribBinding(vaobj, attribindex, bindingindex);
}

void GLapi::VertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset, const SrcLoc& src_loc){
    return _glad_context->VertexArrayAttribFormat(vaobj, attribindex, size, type, normalized, relativeoffset);
}

void GLapi::VertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, const SrcLoc& src_loc){
    return _glad_context->VertexArrayAttribIFormat(vaobj, attribindex, size, type, relativeoffset);
}

void GLapi::VertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, const SrcLoc& src_loc){
    return _glad_context->VertexArrayAttribLFormat(vaobj, attribindex, size, type, relativeoffset);
}

void GLapi::VertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor, const SrcLoc& src_loc){
    return _glad_context->VertexArrayBindingDivisor(vaobj, bindingindex, divisor);
}

void GLapi::VertexArrayElementBuffer(GLuint vaobj, GLuint buffer, const SrcLoc& src_loc){
    return _glad_context->VertexArrayElementBuffer(vaobj, buffer);
}

void GLapi::VertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride, const SrcLoc& src_loc){
    return _glad_context->VertexArrayVertexBuffer(vaobj, bindingindex, buffer, offset, stride);
}

void GLapi::VertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides, const SrcLoc& src_loc){
    return _glad_context->VertexArrayVertexBuffers(vaobj, first, count, buffers, offsets, strides);
}

void GLapi::VertexAttrib1d(GLuint index, GLdouble x, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib1d(index, x);
}

void GLapi::VertexAttrib1dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib1dv(index, v);
}

void GLapi::VertexAttrib1f(GLuint index, GLfloat x, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib1f(index, x);
}

void GLapi::VertexAttrib1fv(GLuint index, const GLfloat* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib1fv(index, v);
}

void GLapi::VertexAttrib1s(GLuint index, GLshort x, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib1s(index, x);
}

void GLapi::VertexAttrib1sv(GLuint index, const GLshort* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib1sv(index, v);
}

void GLapi::VertexAttrib2d(GLuint index, GLdouble x, GLdouble y, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib2d(index, x, y);
}

void GLapi::VertexAttrib2dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib2dv(index, v);
}

void GLapi::VertexAttrib2f(GLuint index, GLfloat x, GLfloat y, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib2f(index, x, y);
}

void GLapi::VertexAttrib2fv(GLuint index, const GLfloat* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib2fv(index, v);
}

void GLapi::VertexAttrib2s(GLuint index, GLshort x, GLshort y, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib2s(index, x, y);
}

void GLapi::VertexAttrib2sv(GLuint index, const GLshort* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib2sv(index, v);
}

void GLapi::VertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib3d(index, x, y, z);
}

void GLapi::VertexAttrib3dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib3dv(index, v);
}

void GLapi::VertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib3f(index, x, y, z);
}

void GLapi::VertexAttrib3fv(GLuint index, const GLfloat* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib3fv(index, v);
}

void GLapi::VertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib3s(index, x, y, z);
}

void GLapi::VertexAttrib3sv(GLuint index, const GLshort* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib3sv(index, v);
}

void GLapi::VertexAttrib4Nbv(GLuint index, const GLbyte* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4Nbv(index, v);
}

void GLapi::VertexAttrib4Niv(GLuint index, const GLint* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4Niv(index, v);
}

void GLapi::VertexAttrib4Nsv(GLuint index, const GLshort* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4Nsv(index, v);
}

void GLapi::VertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4Nub(index, x, y, z, w);
}

void GLapi::VertexAttrib4Nubv(GLuint index, const GLubyte* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4Nubv(index, v);
}

void GLapi::VertexAttrib4Nuiv(GLuint index, const const GLuint* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4Nuiv(index, v);
}

void GLapi::VertexAttrib4Nusv(GLuint index, const GLushort* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4Nusv(index, v);
}

void GLapi::VertexAttrib4bv(GLuint index, const GLbyte* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4bv(index, v);
}

void GLapi::VertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4d(index, x, y, z, w);
}

void GLapi::VertexAttrib4dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4dv(index, v);
}

void GLapi::VertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4f(index, x, y, z, w);
}

void GLapi::VertexAttrib4fv(GLuint index, const GLfloat* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4fv(index, v);
}

void GLapi::VertexAttrib4iv(GLuint index, const GLint* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4iv(index, v);
}

void GLapi::VertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4s(index, x, y, z, w);
}

void GLapi::VertexAttrib4sv(GLuint index, const GLshort* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4sv(index, v);
}

void GLapi::VertexAttrib4ubv(GLuint index, const GLubyte* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4ubv(index, v);
}

void GLapi::VertexAttrib4uiv(GLuint index, const GLuint* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4uiv(index, v);
}

void GLapi::VertexAttrib4usv(GLuint index, const GLushort* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttrib4usv(index, v);
}

void GLapi::VertexAttribBinding(GLuint attribindex, GLuint bindingindex, const SrcLoc& src_loc){
    return _glad_context->VertexAttribBinding(attribindex, bindingindex);
}

void GLapi::VertexAttribDivisor(GLuint index, GLuint divisor, const SrcLoc& src_loc){
    return _glad_context->VertexAttribDivisor(index, divisor);
}

void GLapi::VertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset, const SrcLoc& src_loc){
    return _glad_context->VertexAttribFormat(attribindex, size, type, normalized, relativeoffset);
}

void GLapi::VertexAttribI1i(GLuint index, GLint x, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI1i(index, x);
}

void GLapi::VertexAttribI1iv(GLuint index, const GLint* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI1iv(index, v);
}

void GLapi::VertexAttribI1ui(GLuint index, GLuint x, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI1ui(index, x);
}

void GLapi::VertexAttribI1uiv(GLuint index, const GLuint* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI1uiv(index, v);
}

void GLapi::VertexAttribI2i(GLuint index, GLint x, GLint y, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI2i(index, x, y);
}

void GLapi::VertexAttribI2iv(GLuint index, const GLint* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI2iv(index, v);
}

void GLapi::VertexAttribI2ui(GLuint index, GLuint x, GLuint y, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI2ui(index, x, y);
}

void GLapi::VertexAttribI2uiv(GLuint index, const GLuint* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI2uiv(index, v);
}

void GLapi::VertexAttribI3i(GLuint index, GLint x, GLint y, GLint z, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI3i(index, x, y, z);
}

void GLapi::VertexAttribI3iv(GLuint index, const GLint* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI3iv(index, v);
}

void GLapi::VertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI3ui(index, x, y, z);
}

void GLapi::VertexAttribI3uiv(GLuint index, const GLuint* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI3uiv(index, v);
}

void GLapi::VertexAttribI4bv(GLuint index, const GLbyte* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI4bv(index, v);
}

void GLapi::VertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI4i(index, x, y, z, w);
}

void GLapi::VertexAttribI4iv(GLuint index, const GLint* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI4iv(index, v);
}

void GLapi::VertexAttribI4sv(GLuint index, const GLshort* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI4sv(index, v);
}

void GLapi::VertexAttribI4ubv(GLuint index, const GLubyte* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI4ubv(index, v);
}

void GLapi::VertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI4ui(index, x, y, z, w);
}

void GLapi::VertexAttribI4uiv(GLuint index, const GLuint* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI4uiv(index, v);
}

void GLapi::VertexAttribI4usv(GLuint index, const GLushort* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttribI4usv(index, v);
}

void GLapi::VertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, const SrcLoc& src_loc){
    return _glad_context->VertexAttribIFormat(attribindex, size, type, relativeoffset);
}

void GLapi::VertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer, const SrcLoc& src_loc){
    return _glad_context->VertexAttribIPointer(index, size, type, stride, pointer);
}

void GLapi::VertexAttribL1d(GLuint index, GLdouble x, const SrcLoc& src_loc){
    return _glad_context->VertexAttribL1d(index, x);
}

void GLapi::VertexAttribL1dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttribL1dv(index, v);
}

void GLapi::VertexAttribL2d(GLuint index, GLdouble x, GLdouble y, const SrcLoc& src_loc){
    return _glad_context->VertexAttribL2d(index, x, y);
}

void GLapi::VertexAttribL2dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttribL2dv(index, v);
}

void GLapi::VertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc){
    return _glad_context->VertexAttribL3d(index, x, y, z);
}

void GLapi::VertexAttribL3dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttribL3dv(index, v);
}

void GLapi::VertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w, const SrcLoc& src_loc){
    return _glad_context->VertexAttribL4d(index, x, y, z, w);
}

void GLapi::VertexAttribL4dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc){
    return _glad_context->VertexAttribL4dv(index, v);
}

void GLapi::VertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, const SrcLoc& src_loc){
    return _glad_context->VertexAttribLFormat(attribindex, size, type, relativeoffset);
}

void GLapi::VertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer, const SrcLoc& src_loc){
    return _glad_context->VertexAttribLPointer(index, size, type, stride, pointer);
}

void GLapi::VertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, const SrcLoc& src_loc){
    return _glad_context->VertexAttribP1ui(index, type, normalized, value);
}

void GLapi::VertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value, const SrcLoc& src_loc){
    return _glad_context->VertexAttribP1uiv(index, type, normalized, value);
}

void GLapi::VertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, const SrcLoc& src_loc){
    return _glad_context->VertexAttribP2ui(index, type, normalized, value);
}

void GLapi::VertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value, const SrcLoc& src_loc){
    return _glad_context->VertexAttribP2uiv(index, type, normalized, value);
}

void GLapi::VertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, const SrcLoc& src_loc){
    return _glad_context->VertexAttribP3ui(index, type, normalized, value);
}

void GLapi::VertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value, const SrcLoc& src_loc){
    return _glad_context->VertexAttribP3uiv(index, type, normalized, value);
}

void GLapi::VertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, const SrcLoc& src_loc){
    return _glad_context->VertexAttribP4ui(index, type, normalized, value);
}

void GLapi::VertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value, const SrcLoc& src_loc){
    return _glad_context->VertexAttribP4uiv(index, type, normalized, value);
}

void GLapi::VertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer, const SrcLoc& src_loc){
    return _glad_context->VertexAttribPointer(index, size, type, normalized, stride, pointer);
}

void GLapi::VertexBindingDivisor(GLuint bindingindex, GLuint divisor, const SrcLoc& src_loc){
    return _glad_context->VertexBindingDivisor(bindingindex, divisor);
}

void GLapi::Viewport(GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc){
    return _glad_context->Viewport(x, y, width, height);
}

void GLapi::ViewportArrayv(GLuint first, GLsizei count, const GLfloat* v, const SrcLoc& src_loc){
    return _glad_context->ViewportArrayv(first, count, v);
}

void GLapi::ViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h, const SrcLoc& src_loc){
    return _glad_context->ViewportIndexedf(index, x, y, w, h);
}

void GLapi::ViewportIndexedfv(GLuint index, const GLfloat* v, const SrcLoc& src_loc){
    return _glad_context->ViewportIndexedfv(index, v);
}

void GLapi::WaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, const SrcLoc& src_loc){
    return _glad_context->WaitSync(sync, flags, timeout);
}