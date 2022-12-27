#include "GLapi.hpp"

#include <iostream>
#include <typeinfo>

using namespace glwpp;

template<auto M>
auto GLapi::_call(const SrcLoc& src_loc, const std::string_view& name, auto&&... args) const {
    *_last_src_loc = src_loc;
    if (_metrics){
        (*_metrics)[name.data()]++;
    }

    // if (name != "Viewport" && name != "Clear"){
    //     std::cout << name.data();
    //     ((std::cout << ',' << args), ...);
    //     std::cout << std::endl;
    // }

    return (_glad_context.get()->*M)(std::forward<decltype(args)>(args)...);
}

GLapi::GLapi() :
    _glad_context(new GladGLContext),
    _last_src_loc(new SrcLoc{}){
}

GLapi::~GLapi(){
}

int GLapi::loadGladGLContext(GLADloadfunc load){
    return gladLoadGLContext(_glad_context.get(), load);
}

const SrcLoc& GLapi::getLastSrcLoc() const {
    return *_last_src_loc;
}

void GLapi::setMetricsCategory(const std::shared_ptr<Metrics::Category>& category){
    _metrics = category;
}

void GLapi::ActiveShaderProgram(GLuint pipeline, GLuint program, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ActiveShaderProgram>(src_loc, "ActiveShaderProgram", pipeline, program);
}

void GLapi::ActiveTexture(GLenum texture, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ActiveTexture>(src_loc, "ActiveTexture", texture);
}

void GLapi::AttachShader(GLuint program, GLuint shader, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::AttachShader>(src_loc, "AttachShader", program, shader);
}

void GLapi::BeginConditionalRender(GLuint id, GLenum mode, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BeginConditionalRender>(src_loc, "BeginConditionalRender", id, mode);
}

void GLapi::BeginQuery(GLenum target, GLuint id, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BeginQuery>(src_loc, "BeginQuery", target, id);
}

void GLapi::BeginQueryIndexed(GLenum target, GLuint index, GLuint id, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BeginQueryIndexed>(src_loc, "BeginQueryIndexed", target, index, id);
}

void GLapi::BeginTransformFeedback(GLenum primitiveMode, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BeginTransformFeedback>(src_loc, "BeginTransformFeedback", primitiveMode);
}

void GLapi::BindAttribLocation(GLuint program, GLuint index, const GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindAttribLocation>(src_loc, "BindAttribLocation", program, index, name);
}

void GLapi::BindBuffer(GLenum target, GLuint buffer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindBuffer>(src_loc, "BindBuffer", target, buffer);
}

void GLapi::BindBufferBase(GLenum target, GLuint index, GLuint buffer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindBufferBase>(src_loc, "BindBufferBase", target, index, buffer);
}

void GLapi::BindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindBufferRange>(src_loc, "BindBufferRange", target, index, buffer, offset, size);
}

void GLapi::BindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindBuffersBase>(src_loc, "BindBuffersBase", target, first, count, buffers);
}

void GLapi::BindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindBuffersRange>(src_loc, "BindBuffersRange", target, first, count, buffers, offsets, sizes);
}

void GLapi::BindFragDataLocation(GLuint program, GLuint color, const GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindFragDataLocation>(src_loc, "BindFragDataLocation", program, color, name);
}

void GLapi::BindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindFragDataLocationIndexed>(src_loc, "BindFragDataLocationIndexed", program, colorNumber, index, name);
}

void GLapi::BindFramebuffer(GLenum target, GLuint framebuffer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindFramebuffer>(src_loc, "BindFramebuffer", target, framebuffer);
}

void GLapi::BindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindImageTexture>(src_loc, "BindImageTexture", unit, texture, level, layered, layer, access, format);
}

void GLapi::BindImageTextures(GLuint first, GLsizei count, const GLuint* textures, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindImageTextures>(src_loc, "BindImageTextures", first, count, textures);
}

void GLapi::BindProgramPipeline(GLuint pipeline, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindProgramPipeline>(src_loc, "BindProgramPipeline", pipeline);
}

void GLapi::BindRenderbuffer(GLenum target, GLuint renderbuffer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindRenderbuffer>(src_loc, "BindRenderbuffer", target, renderbuffer);
}

void GLapi::BindSampler(GLuint unit, GLuint sampler, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindSampler>(src_loc, "BindSampler", unit, sampler);
}

void GLapi::BindSamplers(GLuint first, GLsizei count, const GLuint* samplers, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindSamplers>(src_loc, "BindSamplers", first, count, samplers);
}

void GLapi::BindTexture(GLenum target, GLuint texture, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindTexture>(src_loc, "BindTexture", target, texture);
}

void GLapi::BindTextureUnit(GLuint unit, GLuint texture, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindTextureUnit>(src_loc, "BindTextureUnit", unit, texture);
}

void GLapi::BindTextures(GLuint first, GLsizei count, const GLuint* textures, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindTextures>(src_loc, "BindTextures", first, count, textures);
}

void GLapi::BindTransformFeedback(GLenum target, GLuint id, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindTransformFeedback>(src_loc, "BindTransformFeedback", target, id);
}

void GLapi::BindVertexArray(GLuint array, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindVertexArray>(src_loc, "BindVertexArray", array);
}

void GLapi::BindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindVertexBuffer>(src_loc, "BindVertexBuffer", bindingindex, buffer, offset, stride);
}

void GLapi::BindVertexBuffers(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BindVertexBuffers>(src_loc, "BindVertexBuffers", first, count, buffers, offsets, strides);
}

void GLapi::BlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BlendColor>(src_loc, "BlendColor", red, green, blue, alpha);
}

void GLapi::BlendEquation(GLenum mode, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BlendEquation>(src_loc, "BlendEquation", mode);
}

void GLapi::BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BlendEquationSeparate>(src_loc, "BlendEquationSeparate", modeRGB, modeAlpha);
}

void GLapi::BlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BlendEquationSeparatei>(src_loc, "BlendEquationSeparatei", buf, modeRGB, modeAlpha);
}

void GLapi::BlendEquationi(GLuint buf, GLenum mode, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BlendEquationi>(src_loc, "BlendEquationi", buf, mode);
}

void GLapi::BlendFunc(GLenum sfactor, GLenum dfactor, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BlendFunc>(src_loc, "BlendFunc", sfactor, dfactor);
}

void GLapi::BlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BlendFuncSeparate>(src_loc, "BlendFuncSeparate", sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}

void GLapi::BlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BlendFuncSeparatei>(src_loc, "BlendFuncSeparatei", buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void GLapi::BlendFunci(GLuint buf, GLenum src, GLenum dst, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BlendFunci>(src_loc, "BlendFunci", buf, src, dst);
}

void GLapi::BlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BlitFramebuffer>(src_loc, "BlitFramebuffer", srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void GLapi::BlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BlitNamedFramebuffer>(src_loc, "BlitNamedFramebuffer", readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void GLapi::BufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BufferData>(src_loc, "BufferData", target, size, data, usage);
}

void GLapi::BufferStorage(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BufferStorage>(src_loc, "BufferStorage", target, size, data, flags);
}

void GLapi::BufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::BufferSubData>(src_loc, "BufferSubData", target, offset, size, data);
}

GLenum GLapi::CheckFramebufferStatus(GLenum target, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CheckFramebufferStatus>(src_loc, "CheckFramebufferStatus", target);
}

GLenum GLapi::CheckNamedFramebufferStatus(GLuint framebuffer, GLenum target, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CheckNamedFramebufferStatus>(src_loc, "CheckNamedFramebufferStatus", framebuffer, target);
}

void GLapi::ClampColor(GLenum target, GLenum clamp, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClampColor>(src_loc, "ClampColor", target, clamp);
}

void GLapi::Clear(GLbitfield mask, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Clear>(src_loc, "Clear", mask);
}

void GLapi::ClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearBufferData>(src_loc, "ClearBufferData", target, internalformat, format, type, data);
}

void GLapi::ClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearBufferSubData>(src_loc, "ClearBufferSubData", target, internalformat, offset, size, format, type, data);
}

void GLapi::ClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearBufferfi>(src_loc, "ClearBufferfi", buffer, drawbuffer, depth, stencil);
}

void GLapi::ClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearBufferfv>(src_loc, "ClearBufferfv", buffer, drawbuffer, value);
}

void GLapi::ClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearBufferiv>(src_loc, "ClearBufferiv", buffer, drawbuffer, value);
}

void GLapi::ClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearBufferuiv>(src_loc, "ClearBufferuiv", buffer, drawbuffer, value);
}

void GLapi::ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearColor>(src_loc, "ClearColor", red, green, blue, alpha);
}

void GLapi::ClearDepth(GLdouble depth, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearDepth>(src_loc, "ClearDepth", depth);
}

void GLapi::ClearDepthf(GLfloat d, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearDepthf>(src_loc, "ClearDepthf", d);
}

void GLapi::ClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearNamedBufferData>(src_loc, "ClearNamedBufferData", buffer, internalformat, format, type, data);
}

void GLapi::ClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearNamedBufferSubData>(src_loc, "ClearNamedBufferSubData", buffer, internalformat, offset, size, format, type, data);
}

void GLapi::ClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearNamedFramebufferfi>(src_loc, "ClearNamedFramebufferfi", framebuffer, buffer, drawbuffer, depth, stencil);
}

void GLapi::ClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearNamedFramebufferfv>(src_loc, "ClearNamedFramebufferfv", framebuffer, buffer, drawbuffer, value);
}

void GLapi::ClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearNamedFramebufferiv>(src_loc, "ClearNamedFramebufferiv", framebuffer, buffer, drawbuffer, value);
}

void GLapi::ClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearNamedFramebufferuiv>(src_loc, "ClearNamedFramebufferuiv", framebuffer, buffer, drawbuffer, value);
}

void GLapi::ClearStencil(GLint s, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearStencil>(src_loc, "ClearStencil", s);
}

void GLapi::ClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearTexImage>(src_loc, "ClearTexImage", texture, level, format, type, data);
}

void GLapi::ClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClearTexSubImage>(src_loc, "ClearTexSubImage", texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
}

GLenum GLapi::ClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClientWaitSync>(src_loc, "ClientWaitSync", sync, flags, timeout);
}

void GLapi::ClipControl(GLenum origin, GLenum depth, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ClipControl>(src_loc, "ClipControl", origin, depth);
}

void GLapi::ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ColorMask>(src_loc, "ColorMask", red, green, blue, alpha);
}

void GLapi::ColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ColorMaski>(src_loc, "ColorMaski", index, r, g, b, a);
}

void GLapi::CompileShader(GLuint shader, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CompileShader>(src_loc, "CompileShader", shader);
}

void GLapi::CompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CompressedTexImage1D>(src_loc, "CompressedTexImage1D", target, level, internalformat, width, border, imageSize, data);
}

void GLapi::CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CompressedTexImage2D>(src_loc, "CompressedTexImage2D", target, level, internalformat, width, height, border, imageSize, data);
}

void GLapi::CompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CompressedTexImage3D>(src_loc, "CompressedTexImage3D", target, level, internalformat, width, height, depth, border, imageSize, data);
}

void GLapi::CompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CompressedTexSubImage1D>(src_loc, "CompressedTexSubImage1D", target, level, xoffset, width, format, imageSize, data);
}

void GLapi::CompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CompressedTexSubImage2D>(src_loc, "CompressedTexSubImage2D", target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void GLapi::CompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CompressedTexSubImage3D>(src_loc, "CompressedTexSubImage3D", target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

void GLapi::CompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CompressedTextureSubImage1D>(src_loc, "CompressedTextureSubImage1D", texture, level, xoffset, width, format, imageSize, data);
}

void GLapi::CompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CompressedTextureSubImage2D>(src_loc, "CompressedTextureSubImage2D", texture, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void GLapi::CompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CompressedTextureSubImage3D>(src_loc, "CompressedTextureSubImage3D", texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

void GLapi::CopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CopyBufferSubData>(src_loc, "CopyBufferSubData", readTarget, writeTarget, readOffset, writeOffset, size);
}

void GLapi::CopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CopyImageSubData>(src_loc, "CopyImageSubData", srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}

void GLapi::CopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CopyNamedBufferSubData>(src_loc, "CopyNamedBufferSubData", readBuffer, writeBuffer, readOffset, writeOffset, size);
}

void GLapi::CopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CopyTexImage1D>(src_loc, "CopyTexImage1D", target, level, internalformat, x, y, width, border);
}

void GLapi::CopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CopyTexImage2D>(src_loc, "CopyTexImage2D", target, level, internalformat, x, y, width, height, border);
}

void GLapi::CopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CopyTexSubImage1D>(src_loc, "CopyTexSubImage1D", target, level, xoffset, x, y, width);
}

void GLapi::CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CopyTexSubImage2D>(src_loc, "CopyTexSubImage2D", target, level, xoffset, yoffset, x, y, width, height);
}

void GLapi::CopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CopyTexSubImage3D>(src_loc, "CopyTexSubImage3D", target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void GLapi::CopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CopyTextureSubImage1D>(src_loc, "CopyTextureSubImage1D", texture, level, xoffset, x, y, width);
}

void GLapi::CopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CopyTextureSubImage2D>(src_loc, "CopyTextureSubImage2D", texture, level, xoffset, yoffset, x, y, width, height);
}

void GLapi::CopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CopyTextureSubImage3D>(src_loc, "CopyTextureSubImage3D", texture, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void GLapi::CreateBuffers(GLsizei n, GLuint* dst, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CreateBuffers>(src_loc, "CreateBuffers", n, dst);
}

void GLapi::CreateFramebuffers(GLsizei n, GLuint* framebuffers, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CreateFramebuffers>(src_loc, "CreateFramebuffers", n, framebuffers);
}

GLuint GLapi::CreateProgram(const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CreateProgram>(src_loc, "CreateProgram");
}

void GLapi::CreateProgramPipelines(GLsizei n, GLuint* pipelines, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CreateProgramPipelines>(src_loc, "CreateProgramPipelines", n, pipelines);
}

void GLapi::CreateQueries(GLenum target, GLsizei n, GLuint* ids, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CreateQueries>(src_loc, "CreateQueries", target, n, ids);
}

void GLapi::CreateRenderbuffers(GLsizei n, GLuint* renderbuffers, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CreateRenderbuffers>(src_loc, "CreateRenderbuffers", n, renderbuffers);
}

void GLapi::CreateSamplers(GLsizei n, GLuint* samplers, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CreateSamplers>(src_loc, "CreateSamplers", n, samplers);
}

GLuint GLapi::CreateShader(GLenum type, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CreateShader>(src_loc, "CreateShader", type);
}

void GLapi::CreateTextures(GLenum target, GLsizei n, GLuint* textures, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CreateTextures>(src_loc, "CreateTextures", target, n, textures);
}

void GLapi::CreateTransformFeedbacks(GLsizei n, GLuint* ids, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CreateTransformFeedbacks>(src_loc, "CreateTransformFeedbacks", n, ids);
}

void GLapi::CreateVertexArrays(GLsizei n, GLuint* arrays, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CreateVertexArrays>(src_loc, "CreateVertexArrays", n, arrays);
}

void GLapi::CullFace(GLenum mode, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::CullFace>(src_loc, "CullFace", mode);
}

void GLapi::DebugMessageCallback(GLDEBUGPROC callback, const void* userParam, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DebugMessageCallback>(src_loc, "DebugMessageCallback", callback, userParam);
}

void GLapi::DebugMessageControl(GLenum sResource, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DebugMessageControl>(src_loc, "DebugMessageControl", sResource, type, severity, count, ids, enabled);
}

void GLapi::DebugMessageInsert(GLenum sResource, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DebugMessageInsert>(src_loc, "DebugMessageInsert", sResource, type, id, severity, length, buf);
}

void GLapi::DeleteBuffers(GLsizei n, const GLuint* buffers, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DeleteBuffers>(src_loc, "DeleteBuffers", n, buffers);
}

void GLapi::DeleteFramebuffers(GLsizei n, const GLuint* framebuffers, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DeleteFramebuffers>(src_loc, "DeleteFramebuffers", n, framebuffers);
}

void GLapi::DeleteProgram(GLuint program, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DeleteProgram>(src_loc, "DeleteProgram", program);
}

void GLapi::DeleteProgramPipelines(GLsizei n, const GLuint* pipelines, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DeleteProgramPipelines>(src_loc, "DeleteProgramPipelines", n, pipelines);
}

void GLapi::DeleteQueries(GLsizei n, const GLuint* ids, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DeleteQueries>(src_loc, "DeleteQueries", n, ids);
}

void GLapi::DeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DeleteRenderbuffers>(src_loc, "DeleteRenderbuffers", n, renderbuffers);
}

void GLapi::DeleteSamplers(GLsizei count, const GLuint* samplers, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DeleteSamplers>(src_loc, "DeleteSamplers", count, samplers);
}

void GLapi::DeleteShader(GLuint shader, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DeleteShader>(src_loc, "DeleteShader", shader);
}

void GLapi::DeleteSync(GLsync sync, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DeleteSync>(src_loc, "DeleteSync", sync);
}

void GLapi::DeleteTextures(GLsizei n, const GLuint* textures, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DeleteTextures>(src_loc, "DeleteTextures", n, textures);
}

void GLapi::DeleteTransformFeedbacks(GLsizei n, const GLuint* ids, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DeleteTransformFeedbacks>(src_loc, "DeleteTransformFeedbacks", n, ids);
}

void GLapi::DeleteVertexArrays(GLsizei n, const GLuint* arrays, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DeleteVertexArrays>(src_loc, "DeleteVertexArrays", n, arrays);
}

void GLapi::DepthFunc(GLenum func, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DepthFunc>(src_loc, "DepthFunc", func);
}

void GLapi::DepthMask(GLboolean flag, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DepthMask>(src_loc, "DepthMask", flag);
}

void GLapi::DepthRange(GLdouble n, GLdouble f, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DepthRange>(src_loc, "DepthRange", n, f);
}

void GLapi::DepthRangeArrayv(GLuint first, GLsizei count, const GLdouble* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DepthRangeArrayv>(src_loc, "DepthRangeArrayv", first, count, v);
}

void GLapi::DepthRangeIndexed(GLuint index, GLdouble n, GLdouble f, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DepthRangeIndexed>(src_loc, "DepthRangeIndexed", index, n, f);
}

void GLapi::DepthRangef(GLfloat n, GLfloat f, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DepthRangef>(src_loc, "DepthRangef", n, f);
}

void GLapi::DetachShader(GLuint program, GLuint shader, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DetachShader>(src_loc, "DetachShader", program, shader);
}

void GLapi::Disable(GLenum cap, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Disable>(src_loc, "Disable", cap);
}

void GLapi::DisableVertexArrayAttrib(GLuint vaobj, GLuint index, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DisableVertexArrayAttrib>(src_loc, "DisableVertexArrayAttrib", vaobj, index);
}

void GLapi::DisableVertexAttribArray(GLuint index, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DisableVertexAttribArray>(src_loc, "DisableVertexAttribArray", index);
}

void GLapi::Disablei(GLenum target, GLuint index, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Disablei>(src_loc, "Disablei", target, index);
}

void GLapi::DispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DispatchCompute>(src_loc, "DispatchCompute", num_groups_x, num_groups_y, num_groups_z);
}

void GLapi::DispatchComputeIndirect(GLintptr indirect, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DispatchComputeIndirect>(src_loc, "DispatchComputeIndirect", indirect);
}

void GLapi::DrawArrays(GLenum mode, GLint first, GLsizei count, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawArrays>(src_loc, "DrawArrays", mode, first, count);
}

void GLapi::DrawArraysIndirect(GLenum mode, const void* indirect, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawArraysIndirect>(src_loc, "DrawArraysIndirect", mode, indirect);
}

void GLapi::DrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawArraysInstanced>(src_loc, "DrawArraysInstanced", mode, first, count, instancecount);
}

void GLapi::DrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawArraysInstancedBaseInstance>(src_loc, "DrawArraysInstancedBaseInstance", mode, first, count, instancecount, instancecount);
}

void GLapi::DrawBuffer(GLenum buf, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawBuffer>(src_loc, "DrawBuffer", buf);
}

void GLapi::DrawBuffers(GLsizei n, const GLenum* bufs, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawBuffers>(src_loc, "DrawBuffers", n, bufs);
}

void GLapi::DrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawElements>(src_loc, "DrawElements", mode, count, type, indices);
}

void GLapi::DrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawElementsBaseVertex>(src_loc, "DrawElementsBaseVertex", mode, count, type, indices, basevertex);
}

void GLapi::DrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawElementsIndirect>(src_loc, "DrawElementsIndirect", mode, type, indirect);
}

void GLapi::DrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawElementsInstanced>(src_loc, "DrawElementsInstanced", mode, count, type, indices, instancecount);
}

void GLapi::DrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawElementsInstancedBaseInstance>(src_loc, "DrawElementsInstancedBaseInstance", mode, count, type, indices, instancecount, baseinstance);
}

void GLapi::DrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawElementsInstancedBaseVertex>(src_loc, "DrawElementsInstancedBaseVertex", mode, count, type, indices, instancecount, basevertex);
}

void GLapi::DrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawElementsInstancedBaseVertexBaseInstance>(src_loc, "DrawElementsInstancedBaseVertexBaseInstance", mode, count, type, indices, instancecount, basevertex, baseinstance);
}

void GLapi::DrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawRangeElements>(src_loc, "DrawRangeElements", mode, start, end, count, type, indices);
}

void GLapi::DrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawRangeElementsBaseVertex>(src_loc, "DrawRangeElementsBaseVertex", mode, start, end, count, type, indices, basevertex);
}

void GLapi::DrawTransformFeedback(GLenum mode, GLuint id, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawTransformFeedback>(src_loc, "DrawTransformFeedback", mode, id);
}

void GLapi::DrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawTransformFeedbackInstanced>(src_loc, "DrawTransformFeedbackInstanced", mode, id, instancecount);
}

void GLapi::DrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawTransformFeedbackStream>(src_loc, "DrawTransformFeedbackStream", mode, id, stream);
}

void GLapi::DrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::DrawTransformFeedbackStreamInstanced>(src_loc, "DrawTransformFeedbackStreamInstanced", mode, id, stream, instancecount);
}

void GLapi::Enable(GLenum cap, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Enable>(src_loc, "Enable", cap);
}

void GLapi::EnableVertexArrayAttrib(GLuint vaobj, GLuint index, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::EnableVertexArrayAttrib>(src_loc, "EnableVertexArrayAttrib", vaobj, index);
}

void GLapi::EnableVertexAttribArray(GLuint index, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::EnableVertexAttribArray>(src_loc, "EnableVertexAttribArray", index);
}

void GLapi::Enablei(GLenum target, GLuint index, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Enablei>(src_loc, "Enablei", target, index);
}

void GLapi::EndConditionalRender(const SrcLoc& src_loc) const {
    return _call<&GladGLContext::EndConditionalRender>(src_loc, "EndConditionalRender");
}

void GLapi::EndQuery(GLenum target, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::EndQuery>(src_loc, "EndQuery", target);
}

void GLapi::EndQueryIndexed(GLenum target, GLuint index, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::EndQueryIndexed>(src_loc, "EndQueryIndexed", target, index);
}

void GLapi::EndTransformFeedback(const SrcLoc& src_loc) const {
    return _call<&GladGLContext::EndTransformFeedback>(src_loc, "EndTransformFeedback");
}

GLsync GLapi::FenceSync(GLenum condition, GLbitfield flags, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::FenceSync>(src_loc, "FenceSync", condition, flags);
}

void GLapi::Finish(const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Finish>(src_loc, "Finish");
}

void GLapi::Flush(const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Flush>(src_loc, "Flush");
}

void GLapi::FlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::FlushMappedBufferRange>(src_loc, "FlushMappedBufferRange", target, offset, length);
}

void GLapi::FlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::FlushMappedNamedBufferRange>(src_loc, "FlushMappedNamedBufferRange", buffer, offset, length);
}

void GLapi::FramebufferParameteri(GLenum target, GLenum pname, GLint param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::FramebufferParameteri>(src_loc, "FramebufferParameteri", target, pname, param);
}

void GLapi::FramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::FramebufferRenderbuffer>(src_loc, "FramebufferRenderbuffer", target, attachment, renderbuffertarget, renderbuffer);
}

void GLapi::FramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::FramebufferTexture>(src_loc, "FramebufferTexture", target, attachment, texture, level);
}

void GLapi::FramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::FramebufferTexture1D>(src_loc, "FramebufferTexture1D", target, attachment, textarget, target, level);
}

void GLapi::FramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::FramebufferTexture2D>(src_loc, "FramebufferTexture2D", target, attachment, textarget, texture, level);
}

void GLapi::FramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::FramebufferTexture3D>(src_loc, "FramebufferTexture3D", target, attachment, textarget, texture, level, zoffset);
}

void GLapi::FramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::FramebufferTextureLayer>(src_loc, "FramebufferTextureLayer", target, attachment, texture, level, layer);
}

void GLapi::FrontFace(GLenum mode, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::FrontFace>(src_loc, "FrontFace", mode);
}

void GLapi::GenBuffers(GLsizei n, GLuint* buffers, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GenBuffers>(src_loc, "GenBuffers", n, buffers);
}

void GLapi::GenFramebuffers(GLsizei n, GLuint* framebuffers, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GenFramebuffers>(src_loc, "GenFramebuffers", n, framebuffers);
}

void GLapi::GenProgramPipelines(GLsizei n, GLuint* pipelines, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GenProgramPipelines>(src_loc, "GenProgramPipelines", n, pipelines);
}

void GLapi::GenQueries(GLsizei n, GLuint* ids, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GenQueries>(src_loc, "GenQueries", n, ids);
}

void GLapi::GenRenderbuffers(GLsizei n, GLuint* renderbuffers, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GenRenderbuffers>(src_loc, "GenRenderbuffers", n, renderbuffers);
}

void GLapi::GenSamplers(GLsizei count, GLuint* samplers, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GenSamplers>(src_loc, "GenSamplers", count, samplers);
}

void GLapi::GenTextures(GLsizei n, GLuint* textures, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GenTextures>(src_loc, "GenTextures", n, textures);
}

void GLapi::GenTransformFeedbacks(GLsizei n, GLuint* ids, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GenTransformFeedbacks>(src_loc, "GenTransformFeedbacks", n, ids);
}

void GLapi::GenVertexArrays(GLsizei n, GLuint* arrays, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GenVertexArrays>(src_loc, "GenVertexArrays", n, arrays);
}

void GLapi::GenerateMipmap(GLenum target, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GenerateMipmap>(src_loc, "GenerateMipmap", target);
}

void GLapi::GenerateTextureMipmap(GLuint texture, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GenerateTextureMipmap>(src_loc, "GenerateTextureMipmap", texture);
}

void GLapi::GetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetActiveAtomicCounterBufferiv>(src_loc, "GetActiveAtomicCounterBufferiv", program, bufferIndex, pname, params);
}

void GLapi::GetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetActiveAttrib>(src_loc, "GetActiveAttrib", program, index, bufSize, length, size, type, name);
}

void GLapi::GetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetActiveSubroutineName>(src_loc, "GetActiveSubroutineName", program, shadertype, index, bufSize, length, name);
}

void GLapi::GetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetActiveSubroutineUniformName>(src_loc, "GetActiveSubroutineUniformName", program, shadertype, index, bufSize, length, name);
}

void GLapi::GetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetActiveSubroutineUniformiv>(src_loc, "GetActiveSubroutineUniformiv", program, shadertype, index, pname, values);
}

void GLapi::GetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetActiveUniform>(src_loc, "GetActiveUniform", program, index, bufSize, length, size, type, name);
}

void GLapi::GetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetActiveUniformBlockName>(src_loc, "GetActiveUniformBlockName", program, uniformBlockIndex, bufSize, length, uniformBlockName);
}

void GLapi::GetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetActiveUniformBlockiv>(src_loc, "GetActiveUniformBlockiv", program, uniformBlockIndex, pname, params);
}

void GLapi::GetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetActiveUniformName>(src_loc, "GetActiveUniformName", program, uniformIndex, bufSize, length, uniformName);
}

void GLapi::GetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetActiveUniformsiv>(src_loc, "GetActiveUniformsiv", program, uniformCount, uniformIndices, pname, params);
}

void GLapi::GetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetAttachedShaders>(src_loc, "GetAttachedShaders", program, maxCount, count, shaders);
}

GLint GLapi::GetAttribLocation(GLuint program, const GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetAttribLocation>(src_loc, "GetAttribLocation", program, name);
}

void GLapi::GetBooleani_v(GLenum target, GLuint index, GLboolean* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetBooleani_v>(src_loc, "GetBooleani_v", target, index, data);
}

void GLapi::GetBooleanv(GLenum pname, GLboolean* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetBooleanv>(src_loc, "GetBooleanv", pname, data);
}

void GLapi::GetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetBufferParameteri64v>(src_loc, "GetBufferParameteri64v", target, pname, params);
}

void GLapi::GetBufferParameteriv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetBufferParameteriv>(src_loc, "GetBufferParameteriv", target, pname, params);
}

void GLapi::GetBufferPointerv(GLenum target, GLenum pname, void** params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetBufferPointerv>(src_loc, "GetBufferPointerv", target, pname, params);
}

void GLapi::GetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetBufferSubData>(src_loc, "GetBufferSubData", target, offset, size, data);
}

void GLapi::GetCompressedTexImage(GLenum target, GLint level, void* img, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetCompressedTexImage>(src_loc, "GetCompressedTexImage", target, level, img);
}

void GLapi::GetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetCompressedTextureImage>(src_loc, "GetCompressedTextureImage", texture, level, bufSize, pixels);
}

void GLapi::GetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetCompressedTextureSubImage>(src_loc, "GetCompressedTextureSubImage", texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
}

GLuint GLapi::GetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum* sResources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetDebugMessageLog>(src_loc, "GetDebugMessageLog", count, bufSize, sResources, types, ids, severities, lengths, messageLog);
}

void GLapi::GetDoublei_v(GLenum target, GLuint index, GLdouble* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetDoublei_v>(src_loc, "GetDoublei_v", target, index, data);
}

void GLapi::GetDoublev(GLenum pname, GLdouble* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetDoublev>(src_loc, "GetDoublev", pname, data);
}

GLenum GLapi::GetError(const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetError>(src_loc, "GetError");
}

void GLapi::GetFloati_v(GLenum target, GLuint index, GLfloat* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetFloati_v>(src_loc, "GetFloati_v", target, index, data);
}

void GLapi::GetFloatv(GLenum pname, GLfloat* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetFloatv>(src_loc, "GetFloatv", pname, data);
}

GLint GLapi::GetFragDataIndex(GLuint program, const GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetFragDataIndex>(src_loc, "GetFragDataIndex", program, name);
}

GLint GLapi::GetFragDataLocation(GLuint program, const GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetFragDataLocation>(src_loc, "GetFragDataLocation", program, name);
}

void GLapi::GetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetFramebufferAttachmentParameteriv>(src_loc, "GetFramebufferAttachmentParameteriv", target, attachment, pname, params);
}

void GLapi::GetFramebufferParameteriv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetFramebufferParameteriv>(src_loc, "GetFramebufferParameteriv", target, pname, params);
}
void GLapi::GetInteger64i_v(GLenum target, GLuint index, GLint64* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetInteger64i_v>(src_loc, "GetInteger64i_v", target, index, data);
}

void GLapi::GetInteger64v(GLenum pname, GLint64* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetInteger64v>(src_loc, "GetInteger64v", pname, data);
}

void GLapi::GetIntegeri_v(GLenum target, GLuint index, GLint* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetIntegeri_v>(src_loc, "GetIntegeri_v", target, index, data);
}

void GLapi::GetIntegerv(GLenum pname, GLint* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetIntegerv>(src_loc, "GetIntegerv", pname, data);
}

void GLapi::GetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetInternalformati64v>(src_loc, "GetInternalformati64v", target, internalformat, pname, count, params);
}

void GLapi::GetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetInternalformativ>(src_loc, "GetInternalformativ", target, internalformat, pname, count, params);
}

void GLapi::GetMultisamplefv(GLenum pname, GLuint index, GLfloat* val, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetMultisamplefv>(src_loc, "GetMultisamplefv", pname, index, val);
}

void GLapi::GetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetNamedBufferParameteri64v>(src_loc, "GetNamedBufferParameteri64v", buffer, pname, params);
}

void GLapi::GetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetNamedBufferParameteriv>(src_loc, "GetNamedBufferParameteriv", buffer, pname, params);
}

void GLapi::GetNamedBufferPointerv(GLuint buffer, GLenum pname, void** params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetNamedBufferPointerv>(src_loc, "GetNamedBufferPointerv", buffer, pname, params);
}

void GLapi::GetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetNamedBufferSubData>(src_loc, "GetNamedBufferSubData", buffer, offset, size, data);
}

void GLapi::GetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetNamedFramebufferAttachmentParameteriv>(src_loc, "GetNamedFramebufferAttachmentParameteriv", framebuffer, attachment, pname, params);
}

void GLapi::GetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint* param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetNamedFramebufferParameteriv>(src_loc, "GetNamedFramebufferParameteriv", framebuffer, pname, param);
}

void GLapi::GetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetNamedRenderbufferParameteriv>(src_loc, "GetNamedRenderbufferParameteriv", renderbuffer, pname, params);
}

void GLapi::GetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetObjectLabel>(src_loc, "GetObjectLabel", identifier, name, bufSize, length, label);
}

void GLapi::GetObjectPtrLabel(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetObjectPtrLabel>(src_loc, "GetObjectPtrLabel", ptr, bufSize, length, label);
}

void GLapi::GetPointerv(GLenum pname, void** params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetPointerv>(src_loc, "GetPointerv", pname, params);
}

void GLapi::GetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetProgramBinary>(src_loc, "GetProgramBinary", program, bufSize, length, binaryFormat, binary);
}

void GLapi::GetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetProgramInfoLog>(src_loc, "GetProgramInfoLog", program, bufSize, length, infoLog);
}

void GLapi::GetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetProgramInterfaceiv>(src_loc, "GetProgramInterfaceiv", program, programInterface, pname, params);
}

void GLapi::GetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetProgramPipelineInfoLog>(src_loc, "GetProgramPipelineInfoLog", pipeline, bufSize, length, infoLog);
}

void GLapi::GetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetProgramPipelineiv>(src_loc, "GetProgramPipelineiv", pipeline, pname, params);
}

GLuint GLapi::GetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetProgramResourceIndex>(src_loc, "GetProgramResourceIndex", program, programInterface, name);
}

GLint GLapi::GetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetProgramResourceLocation>(src_loc, "GetProgramResourceLocation", program, programInterface, name);
}

GLint GLapi::GetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetProgramResourceLocationIndex>(src_loc, "GetProgramResourceLocationIndex", program, programInterface, name);
}

void GLapi::GetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetProgramResourceName>(src_loc, "GetProgramResourceName", program, programInterface, index, bufSize, length, name);
}

void GLapi::GetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei count, GLsizei* length, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetProgramResourceiv>(src_loc, "GetProgramResourceiv", program, programInterface, index, propCount, props, count, length, params);
}

void GLapi::GetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint* values, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetProgramStageiv>(src_loc, "GetProgramStageiv", program, shadertype, pname, values);
}

void GLapi::GetProgramiv(GLuint program, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetProgramiv>(src_loc, "GetProgramiv", program, pname, params);
}

void GLapi::GetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetQueryBufferObjecti64v>(src_loc, "GetQueryBufferObjecti64v", id, buffer, pname, offset);
}

void GLapi::GetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetQueryBufferObjectiv>(src_loc, "GetQueryBufferObjectiv", id, buffer, pname, offset);
}

void GLapi::GetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetQueryBufferObjectui64v>(src_loc, "GetQueryBufferObjectui64v", id, buffer, pname, offset);
}

void GLapi::GetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetQueryBufferObjectuiv>(src_loc, "GetQueryBufferObjectuiv", id, buffer, pname, offset);
}

void GLapi::GetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetQueryIndexediv>(src_loc, "GetQueryIndexediv", target, index, pname, params);
}

void GLapi::GetQueryObjecti64v(GLuint id, GLenum pname, GLint64* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetQueryObjecti64v>(src_loc, "GetQueryObjecti64v", id, pname, params);
}

void GLapi::GetQueryObjectiv(GLuint id, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetQueryObjectiv>(src_loc, "GetQueryObjectiv", id, pname, params);
}

void GLapi::GetQueryObjectui64v(GLuint id, GLenum pname, GLuint64* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetQueryObjectui64v>(src_loc, "GetQueryObjectui64v", id, pname, params);
}

void GLapi::GetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetQueryObjectuiv>(src_loc, "GetQueryObjectuiv", id, pname, params);
}

void GLapi::GetQueryiv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetQueryiv>(src_loc, "GetQueryiv", target, pname, params);
}

void GLapi::GetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetRenderbufferParameteriv>(src_loc, "GetRenderbufferParameteriv", target, pname, params);
}

void GLapi::GetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetSamplerParameterIiv>(src_loc, "GetSamplerParameterIiv", sampler, pname, params);
}

void GLapi::GetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetSamplerParameterIuiv>(src_loc, "GetSamplerParameterIuiv", sampler, pname, params);
}

void GLapi::GetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetSamplerParameterfv>(src_loc, "GetSamplerParameterfv", sampler, pname, params);
}

void GLapi::GetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetSamplerParameteriv>(src_loc, "GetSamplerParameteriv", sampler, pname, params);
}

void GLapi::GetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetShaderInfoLog>(src_loc, "GetShaderInfoLog", shader, bufSize, length, infoLog);
}

void GLapi::GetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetShaderPrecisionFormat>(src_loc, "GetShaderPrecisionFormat", shadertype, precisiontype, range, precision);
}

void GLapi::GetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* sResource, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetShaderSource>(src_loc, "GetShaderSource", shader, bufSize, length, sResource);
}

void GLapi::GetShaderiv(GLuint shader, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetShaderiv>(src_loc, "GetShaderiv", shader, pname, params);
}

const GLubyte* GLapi::GetString(GLenum name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetString>(src_loc, "GetString", name);
}

const GLubyte* GLapi::GetStringi(GLenum name, GLuint index, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetStringi>(src_loc, "GetStringi", name, index);
}

GLuint GLapi::GetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetSubroutineIndex>(src_loc, "GetSubroutineIndex", program, shadertype, name);
}

GLint GLapi::GetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetSubroutineUniformLocation>(src_loc, "GetSubroutineUniformLocation", program, shadertype, name);
}

void GLapi::GetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetSynciv>(src_loc, "GetSynciv", sync, pname, count, length, values);
}

void GLapi::GetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTexImage>(src_loc, "GetTexImage", target, level, format, type, pixels);
}

void GLapi::GetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTexLevelParameterfv>(src_loc, "GetTexLevelParameterfv", target, level, pname, params);
}

void GLapi::GetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTexLevelParameteriv>(src_loc, "GetTexLevelParameteriv", target, level, pname, params);
}

void GLapi::GetTexParameterIiv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTexParameterIiv>(src_loc, "GetTexParameterIiv", target, pname, params);
}

void GLapi::GetTexParameterIuiv(GLenum target, GLenum pname, GLuint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTexParameterIuiv>(src_loc, "GetTexParameterIuiv", target, pname, params);
}

void GLapi::GetTexParameterfv(GLenum target, GLenum pname, GLfloat* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTexParameterfv>(src_loc, "GetTexParameterfv", target, pname, params);
}

void GLapi::GetTexParameteriv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTexParameteriv>(src_loc, "GetTexParameteriv", target, pname, params);
}

void GLapi::GetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTextureImage>(src_loc, "GetTextureImage", texture, level, format, type, bufSize, pixels);
}

void GLapi::GetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTextureLevelParameterfv>(src_loc, "GetTextureLevelParameterfv", texture, level, pname, params);
}

void GLapi::GetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTextureLevelParameteriv>(src_loc, "GetTextureLevelParameteriv", texture, level, pname, params);
}

void GLapi::GetTextureParameterIiv(GLuint texture, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTextureParameterIiv>(src_loc, "GetTextureParameterIiv", texture, pname, params);
}

void GLapi::GetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTextureParameterIuiv>(src_loc, "GetTextureParameterIuiv", texture, pname, params);
}

void GLapi::GetTextureParameterfv(GLuint texture, GLenum pname, GLfloat* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTextureParameterfv>(src_loc, "GetTextureParameterfv", texture, pname, params);
}

void GLapi::GetTextureParameteriv(GLuint texture, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTextureParameteriv>(src_loc, "GetTextureParameteriv", texture, pname, params);
}

void GLapi::GetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTextureSubImage>(src_loc, "GetTextureSubImage", texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels);
}

void GLapi::GetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTransformFeedbackVarying>(src_loc, "GetTransformFeedbackVarying", program, index, bufSize, length, size, type, name);
}

void GLapi::GetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64* param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTransformFeedbacki64_v>(src_loc, "GetTransformFeedbacki64_v", xfb, pname, index, param);
}

void GLapi::GetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint* param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTransformFeedbacki_v>(src_loc, "GetTransformFeedbacki_v", xfb, pname, index, param);
}

void GLapi::GetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint* param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetTransformFeedbackiv>(src_loc, "GetTransformFeedbackiv", xfb, pname, param);
}

GLuint GLapi::GetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetUniformBlockIndex>(src_loc, "GetUniformBlockIndex", program, uniformBlockName);
}

GLint GLapi::GetUniformLocation(GLuint program, const GLchar* name, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetUniformLocation>(src_loc, "GetUniformLocation", program, name);
}

void GLapi::GetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetUniformSubroutineuiv>(src_loc, "GetUniformSubroutineuiv", shadertype, location, params);
}

void GLapi::GetUniformdv(GLuint program, GLint location, GLdouble* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetUniformdv>(src_loc, "GetUniformdv", program, location, params);
}

void GLapi::GetUniformfv(GLuint program, GLint location, GLfloat* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetUniformfv>(src_loc, "GetUniformfv", program, location, params);
}

void GLapi::GetUniformiv(GLuint program, GLint location,  GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetUniformiv>(src_loc, "GetUniformiv", program, location, params);
}

void GLapi::GetUniformuiv(GLuint program, GLint location, GLuint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetUniformuiv>(src_loc, "GetUniformuiv", program, location, params);
}

void GLapi::GetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64* param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetVertexArrayIndexed64iv>(src_loc, "GetVertexArrayIndexed64iv", vaobj, index, pname, param);
}

void GLapi::GetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint* param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetVertexArrayIndexediv>(src_loc, "GetVertexArrayIndexediv", vaobj, index, pname, param);
}

void GLapi::GetVertexArrayiv(GLuint vaobj, GLenum pname, GLint* param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetVertexArrayiv>(src_loc, "GetVertexArrayiv", vaobj, pname, param);
}

void GLapi::GetVertexAttribIiv(GLuint index, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetVertexAttribIiv>(src_loc, "GetVertexAttribIiv", index, pname, params);
}

void GLapi::GetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetVertexAttribIuiv>(src_loc, "GetVertexAttribIuiv", index, pname, params);
}

void GLapi::GetVertexAttribLdv(GLuint index, GLenum pname, GLdouble* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetVertexAttribLdv>(src_loc, "GetVertexAttribLdv", index, pname, params);
}

void GLapi::GetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetVertexAttribPointerv>(src_loc, "GetVertexAttribPointerv", index, pname, pointer);
}

void GLapi::GetVertexAttribdv(GLuint index, GLenum pname, GLdouble* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetVertexAttribdv>(src_loc, "GetVertexAttribdv", index, pname, params);
}

void GLapi::GetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetVertexAttribfv>(src_loc, "GetVertexAttribfv", index, pname, params);
}

void GLapi::GetVertexAttribiv(GLuint index, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetVertexAttribiv>(src_loc, "GetVertexAttribiv", index, pname, params);
}

void GLapi::GetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetnCompressedTexImage>(src_loc, "GetnCompressedTexImage", target, lod, bufSize, pixels);
}

void GLapi::GetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetnTexImage>(src_loc, "GetnTexImage", target, level, format, type, bufSize, pixels);
}

void GLapi::GetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetnUniformdv>(src_loc, "GetnUniformdv", program, location, bufSize, params);
}

void GLapi::GetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetnUniformfv>(src_loc, "GetnUniformfv", program, location, bufSize, params);
}

void GLapi::GetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetnUniformiv>(src_loc, "GetnUniformiv", program, location, bufSize, params);
}

void GLapi::GetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::GetnUniformuiv>(src_loc, "GetnUniformuiv", program, location, bufSize, params);
}

void GLapi::Hint(GLenum target, GLenum mode, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Hint>(src_loc, "Hint", target, mode);
}

void GLapi::InvalidateBufferData(GLuint buffer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::InvalidateBufferData>(src_loc, "InvalidateBufferData", buffer);
}

void GLapi::InvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::InvalidateBufferSubData>(src_loc, "InvalidateBufferSubData", buffer, offset, length);
}

void GLapi::InvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::InvalidateFramebuffer>(src_loc, "InvalidateFramebuffer", target, numAttachments, attachments);
}

void GLapi::InvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::InvalidateNamedFramebufferData>(src_loc, "InvalidateNamedFramebufferData", framebuffer, numAttachments, attachments);
}

void GLapi::InvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::InvalidateNamedFramebufferSubData>(src_loc, "InvalidateNamedFramebufferSubData", framebuffer, numAttachments, attachments, x, y, width, height);
}

void GLapi::InvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::InvalidateSubFramebuffer>(src_loc, "InvalidateSubFramebuffer", target, numAttachments, attachments, x, y, width, height);
}

void GLapi::InvalidateTexImage(GLuint texture, GLint level, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::InvalidateTexImage>(src_loc, "InvalidateTexImage", texture, level);
}

void GLapi::InvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::InvalidateTexSubImage>(src_loc, "InvalidateTexSubImage", texture, level, xoffset, yoffset, zoffset, width, height, depth);
}

GLboolean GLapi::IsBuffer(GLuint buffer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::IsBuffer>(src_loc, "IsBuffer", buffer);
}

GLboolean GLapi::IsEnabled(GLenum cap, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::IsEnabled>(src_loc, "IsEnabled", cap);
}

GLboolean GLapi::IsEnabledi(GLenum target, GLuint index, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::IsEnabledi>(src_loc, "IsEnabledi", target, index);
}

GLboolean GLapi::IsFramebuffer(GLuint framebuffer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::IsFramebuffer>(src_loc, "IsFramebuffer", framebuffer);
}

GLboolean GLapi::IsProgram(GLuint program, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::IsProgram>(src_loc, "IsProgram", program);
}

GLboolean GLapi::IsProgramPipeline(GLuint pipeline, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::IsProgramPipeline>(src_loc, "IsProgramPipeline", pipeline);
}

GLboolean GLapi::IsQuery(GLuint id, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::IsQuery>(src_loc, "IsQuery", id);
}

GLboolean GLapi::IsRenderbuffer(GLuint renderbuffer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::IsRenderbuffer>(src_loc, "IsRenderbuffer", renderbuffer);
}

GLboolean GLapi::IsSampler(GLuint sampler, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::IsSampler>(src_loc, "IsSampler", sampler);
}

GLboolean GLapi::IsShader(GLuint shader, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::IsShader>(src_loc, "IsShader", shader);
}

GLboolean GLapi::IsSync(GLsync sync, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::IsSync>(src_loc, "IsSync", sync);
}

GLboolean GLapi::IsTexture(GLuint texture, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::IsTexture>(src_loc, "IsTexture", texture);
}

GLboolean GLapi::IsTransformFeedback(GLuint id, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::IsTransformFeedback>(src_loc, "IsTransformFeedback", id);
}

GLboolean GLapi::IsVertexArray(GLuint array, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::IsVertexArray>(src_loc, "IsVertexArray", array);
}

void GLapi::LineWidth(GLfloat width, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::LineWidth>(src_loc, "LineWidth", width);
}

void GLapi::LinkProgram(GLuint program, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::LinkProgram>(src_loc, "LinkProgram", program);
}

void GLapi::LogicOp(GLenum opcode, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::LogicOp>(src_loc, "LogicOp", opcode);
}

void* GLapi::MapNamedBuffer(GLuint buffer, GLenum access, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::MapNamedBuffer>(src_loc, "MapNamedBuffer", buffer, access);
}

void GLapi::MemoryBarrier(GLbitfield barriers, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::MemoryBarrier>(src_loc, "MemoryBarrier", barriers);
}

void GLapi::MemoryBarrierByRegion(GLbitfield barriers, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::MemoryBarrierByRegion>(src_loc, "MemoryBarrierByRegion", barriers);
}

void GLapi::MinSampleShading(GLfloat value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::MinSampleShading>(src_loc, "MinSampleShading", value);
}

void GLapi::MultiDrawArrays(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::MultiDrawArrays>(src_loc, "MultiDrawArrays", mode, first, count, drawcount);
}

void GLapi::MultiDrawArraysIndirect(GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::MultiDrawArraysIndirect>(src_loc, "MultiDrawArraysIndirect", mode, indirect, drawcount, stride);
}

void GLapi::MultiDrawArraysIndirectCount(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::MultiDrawArraysIndirectCount>(src_loc, "MultiDrawArraysIndirectCount", mode, indirect, drawcount, maxdrawcount, stride);
}

void GLapi::MultiDrawElements(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::MultiDrawElements>(src_loc, "MultiDrawElements", mode, count, type, indices, drawcount);
}

void GLapi::MultiDrawElementsBaseVertex(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::MultiDrawElementsBaseVertex>(src_loc, "MultiDrawElementsBaseVertex", mode, count, type, indices, drawcount, basevertex);
}

void GLapi::MultiDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::MultiDrawElementsIndirect>(src_loc, "MultiDrawElementsIndirect", mode, type, indirect, drawcount, stride);
}

void GLapi::MultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::MultiDrawElementsIndirectCount>(src_loc, "MultiDrawElementsIndirectCount", mode, type, indirect, drawcount, maxdrawcount, stride);
}

void GLapi::NamedBufferData(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::NamedBufferData>(src_loc, "NamedBufferData", buffer, size, data, usage);
}

void GLapi::NamedBufferStorage(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::NamedBufferStorage>(src_loc, "NamedBufferStorage", buffer, size, data, flags);
}

void GLapi::NamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::NamedBufferSubData>(src_loc, "NamedBufferSubData", buffer, offset, size, data);
}

void GLapi::NamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::NamedFramebufferDrawBuffer>(src_loc, "NamedFramebufferDrawBuffer", framebuffer, buf);
}

void GLapi::NamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum* bufs, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::NamedFramebufferDrawBuffers>(src_loc, "NamedFramebufferDrawBuffers", framebuffer, n, bufs);
}

void GLapi::NamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::NamedFramebufferParameteri>(src_loc, "NamedFramebufferParameteri", framebuffer, pname, param);
}

void GLapi::NamedFramebufferReadBuffer(GLuint framebuffer, GLenum src, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::NamedFramebufferReadBuffer>(src_loc, "NamedFramebufferReadBuffer", framebuffer, src);
}

void GLapi::NamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::NamedFramebufferRenderbuffer>(src_loc, "NamedFramebufferRenderbuffer", framebuffer, attachment, renderbuffertarget, renderbuffer);
}

void GLapi::NamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::NamedFramebufferTexture>(src_loc, "NamedFramebufferTexture", framebuffer, attachment, texture, level);
}

void GLapi::NamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::NamedFramebufferTextureLayer>(src_loc, "NamedFramebufferTextureLayer", framebuffer, attachment, texture, level, layer);
}

void GLapi::NamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::NamedRenderbufferStorage>(src_loc, "NamedRenderbufferStorage", renderbuffer, internalformat, width, height);
}

void GLapi::NamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::NamedRenderbufferStorageMultisample>(src_loc, "NamedRenderbufferStorageMultisample", renderbuffer, samples, internalformat, width, height);
}

void GLapi::ObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar* label, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ObjectLabel>(src_loc, "ObjectLabel", identifier, name, length, label);
}

void GLapi::ObjectPtrLabel(const void* ptr, GLsizei length, const GLchar* label, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ObjectPtrLabel>(src_loc, "ObjectPtrLabel", ptr, length, label);
}

void GLapi::PatchParameterfv(GLenum pname, const GLfloat* values, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::PatchParameterfv>(src_loc, "PatchParameterfv", pname, values);
}

void GLapi::PatchParameteri(GLenum pname, GLint value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::PatchParameteri>(src_loc, "PatchParameteri", pname, value);
}

void GLapi::PauseTransformFeedback(const SrcLoc& src_loc) const {
    return _call<&GladGLContext::PauseTransformFeedback>(src_loc, "PauseTransformFeedback");
}

void GLapi::PixelStoref(GLenum pname, GLfloat param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::PixelStoref>(src_loc, "PixelStoref", pname, param);
}

void GLapi::PixelStorei(GLenum pname, GLint param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::PixelStorei>(src_loc, "PixelStorei", pname, param);
}

void GLapi::PointParameterf(GLenum pname, GLfloat param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::PointParameterf>(src_loc, "PointParameterf", pname, param);
}

void GLapi::PointParameterfv(GLenum pname, const GLfloat* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::PointParameterfv>(src_loc, "PointParameterfv", pname, params);
}

void GLapi::PointParameteri(GLenum pname, GLint param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::PointParameteri>(src_loc, "PointParameteri", pname, param);
}

void GLapi::PointParameteriv(GLenum pname, const GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::PointParameteriv>(src_loc, "PointParameteriv", pname, params);
}

void GLapi::PointSize(GLfloat size, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::PointSize>(src_loc, "PointSize", size);
}

void GLapi::PolygonMode(GLenum face, GLenum mode, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::PolygonMode>(src_loc, "PolygonMode", face, mode);
}

void GLapi::PolygonOffset(GLfloat factor, GLfloat units, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::PolygonOffset>(src_loc, "PolygonOffset", factor, units);
}

void GLapi::PolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::PolygonOffsetClamp>(src_loc, "PolygonOffsetClamp", factor, units, clamp);
}

void GLapi::PopDebugGroup(const SrcLoc& src_loc) const {
    return _call<&GladGLContext::PopDebugGroup>(src_loc, "PopDebugGroup");
}

void GLapi::PrimitiveRestartIndex(GLuint index, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::PrimitiveRestartIndex>(src_loc, "PrimitiveRestartIndex", index);
}

void GLapi::ProgramBinary(GLuint program, GLenum binaryFormat, const void* binary, GLsizei length, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramBinary>(src_loc, "ProgramBinary", program, binaryFormat, binary, length);
}

void GLapi::ProgramParameteri(GLuint program, GLenum pname, GLint value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramParameteri>(src_loc, "ProgramParameteri", program, pname, value);
}

void GLapi::ProgramUniform1d(GLuint program, GLint location, GLdouble v0, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform1d>(src_loc, "ProgramUniform1d", program, location, v0);
}

void GLapi::ProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform1dv>(src_loc, "ProgramUniform1dv", program, location, count, value);
}

void GLapi::ProgramUniform1f(GLuint program, GLint location, GLfloat v0, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform1f>(src_loc, "ProgramUniform1f", program, location, v0);
}

void GLapi::ProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform1fv>(src_loc, "ProgramUniform1fv", program, location, count, value);
}

void GLapi::ProgramUniform1i(GLuint program, GLint location, GLint v0, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform1i>(src_loc, "ProgramUniform1i", program, location, v0);
}

void GLapi::ProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform1iv>(src_loc, "ProgramUniform1iv", program, location, count, value);
}

void GLapi::ProgramUniform1ui(GLuint program, GLint location, GLuint v0, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform1ui>(src_loc, "ProgramUniform1ui", program, location, v0);
}

void GLapi::ProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform1uiv>(src_loc, "ProgramUniform1uiv", program, location, count, value);
}

void GLapi::ProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform2d>(src_loc, "ProgramUniform2d", program, location, v0, v1);
}

void GLapi::ProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform2dv>(src_loc, "ProgramUniform2dv", program, location, count, value);
}

void GLapi::ProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform2f>(src_loc, "ProgramUniform2f", program, location, v0, v1);
}

void GLapi::ProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform2fv>(src_loc, "ProgramUniform2fv", program, location, count, value);
}

void GLapi::ProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform2i>(src_loc, "ProgramUniform2i", program, location, v0, v1);
}

void GLapi::ProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform2iv>(src_loc, "ProgramUniform2iv", program, location, count, value);
}

void GLapi::ProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform2ui>(src_loc, "ProgramUniform2ui", program, location, v0, v1);
}

void GLapi::ProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform2uiv>(src_loc, "ProgramUniform2uiv", program, location, count, value);
}

void GLapi::ProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform3d>(src_loc, "ProgramUniform3d", program, location, v0, v1, v2);
}

void GLapi::ProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform3dv>(src_loc, "ProgramUniform3dv", program, location, count, value);
}

void GLapi::ProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform3f>(src_loc, "ProgramUniform3f", program, location, v0, v1, v2);
}

void GLapi::ProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform3fv>(src_loc, "ProgramUniform3fv", program, location, count, value);
}

void GLapi::ProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform3i>(src_loc, "ProgramUniform3i", program, location, v0, v1, v2);
}

void GLapi::ProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform3iv>(src_loc, "ProgramUniform3iv", program, location, count, value);
}

void GLapi::ProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform3ui>(src_loc, "ProgramUniform3ui", program, location, v0, v1, v2);
}

void GLapi::ProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform3uiv>(src_loc, "ProgramUniform3uiv", program, location, count, value);
}

void GLapi::ProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform4d>(src_loc, "ProgramUniform4d", program, location, v0, v1, v2, v3);
}

void GLapi::ProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform4dv>(src_loc, "ProgramUniform4dv", program, location, count, value);
}

void GLapi::ProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform4f>(src_loc, "ProgramUniform4f", program, location, v0, v1, v2, v3);
}

void GLapi::ProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform4fv>(src_loc, "ProgramUniform4fv", program, location, count, value);
}

void GLapi::ProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform4i>(src_loc, "ProgramUniform4i", program, location, v0, v1, v2, v3);
}

void GLapi::ProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform4iv>(src_loc, "ProgramUniform4iv", program, location, count, value);
}

void GLapi::ProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform4ui>(src_loc, "ProgramUniform4ui", program, location, v0, v1, v2, v3);
}

void GLapi::ProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniform4uiv>(src_loc, "ProgramUniform4uiv", program, location, count, value);
}

void GLapi::ProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix2dv>(src_loc, "ProgramUniformMatrix2dv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix2fv>(src_loc, "ProgramUniformMatrix2fv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix2x3dv>(src_loc, "ProgramUniformMatrix2x3dv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix2x3fv>(src_loc, "ProgramUniformMatrix2x3fv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix2x4dv>(src_loc, "ProgramUniformMatrix2x4dv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix2x4fv>(src_loc, "ProgramUniformMatrix2x4fv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix3dv>(src_loc, "ProgramUniformMatrix3dv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix3fv>(src_loc, "ProgramUniformMatrix3fv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix3x2dv>(src_loc, "ProgramUniformMatrix3x2dv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix3x2fv>(src_loc, "ProgramUniformMatrix3x2fv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix3x4dv>(src_loc, "ProgramUniformMatrix3x4dv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix3x4fv>(src_loc, "ProgramUniformMatrix3x4fv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix4dv>(src_loc, "ProgramUniformMatrix4dv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix4fv>(src_loc, "ProgramUniformMatrix4fv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix4x2dv>(src_loc, "ProgramUniformMatrix4x2dv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix4x2fv>(src_loc, "ProgramUniformMatrix4x2fv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix4x3dv>(src_loc, "ProgramUniformMatrix4x3dv", program, location, count, transpose, value);
}

void GLapi::ProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProgramUniformMatrix4x3fv>(src_loc, "ProgramUniformMatrix4x3fv", program, location, count, transpose, value);
}

void GLapi::ProvokingVertex(GLenum mode, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ProvokingVertex>(src_loc, "ProvokingVertex", mode);
}

void GLapi::PushDebugGroup(GLenum sResource, GLuint id, GLsizei length, const GLchar* message, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::PushDebugGroup>(src_loc, "PushDebugGroup", sResource, id, length, message);
}

void GLapi::QueryCounter(GLuint id, GLenum target, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::QueryCounter>(src_loc, "QueryCounter", id, target);
}

void GLapi::ReadBuffer(GLenum src, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ReadBuffer>(src_loc, "ReadBuffer", src);
}

void GLapi::ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ReadPixels>(src_loc, "ReadPixels", x, y, width, height, format, type, pixels);
}

void GLapi::ReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ReadnPixels>(src_loc, "ReadnPixels", x, y, width, height, format, type, bufSize, data);
}

void GLapi::ReleaseShaderCompiler(const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ReleaseShaderCompiler>(src_loc, "ReleaseShaderCompiler");
}

void GLapi::RenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::RenderbufferStorage>(src_loc, "RenderbufferStorage", target, internalformat, width, height);
}

void GLapi::RenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::RenderbufferStorageMultisample>(src_loc, "RenderbufferStorageMultisample", target, samples, internalformat, width, height);
}

void GLapi::ResumeTransformFeedback(const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ResumeTransformFeedback>(src_loc, "ResumeTransformFeedback");
}

void GLapi::SampleCoverage(GLfloat value, GLboolean invert, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::SampleCoverage>(src_loc, "SampleCoverage", value, invert);
}

void GLapi::SampleMaski(GLuint maskNumber, GLbitfield mask, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::SampleMaski>(src_loc, "SampleMaski", maskNumber, mask);
}

void GLapi::SamplerParameterIiv(GLuint sampler, GLenum pname, const GLint* param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::SamplerParameterIiv>(src_loc, "SamplerParameterIiv", sampler, pname, param);
}

void GLapi::SamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint* param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::SamplerParameterIuiv>(src_loc, "SamplerParameterIuiv", sampler, pname, param);
}

void GLapi::SamplerParameterf(GLuint sampler, GLenum pname, GLfloat param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::SamplerParameterf>(src_loc, "SamplerParameterf", sampler, pname, param);
}

void GLapi::SamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat* param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::SamplerParameterfv>(src_loc, "SamplerParameterfv", sampler, pname, param);
}

void GLapi::SamplerParameteri(GLuint sampler, GLenum pname, GLint param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::SamplerParameteri>(src_loc, "SamplerParameteri", sampler, pname, param);
}

void GLapi::SamplerParameteriv(GLuint sampler, GLenum pname, const GLint* param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::SamplerParameteriv>(src_loc, "SamplerParameteriv", sampler, pname, param);
}

void GLapi::Scissor(GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Scissor>(src_loc, "Scissor", x, y, width, height);
}

void GLapi::ScissorArrayv(GLuint first, GLsizei count, const GLint* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ScissorArrayv>(src_loc, "ScissorArrayv", first, count, v);
}

void GLapi::ScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ScissorIndexed>(src_loc, "ScissorIndexed", index, left, bottom, width, height);
}

void GLapi::ScissorIndexedv(GLuint index, const GLint* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ScissorIndexedv>(src_loc, "ScissorIndexedv", index, v);
}

void GLapi::ShaderSource(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ShaderSource>(src_loc, "ShaderSource", shader, count, string, length);
}

void GLapi::ShaderBinary(GLsizei count, const GLuint* shaders, GLenum binaryFormat, const void* binary, GLsizei length, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ShaderBinary>(src_loc, "ShaderBinary", count, shaders, binaryFormat, binary, length);
}

void GLapi::ShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ShaderStorageBlockBinding>(src_loc, "ShaderStorageBlockBinding", program, storageBlockIndex, storageBlockBinding);
}

void GLapi::SpecializeShader(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::SpecializeShader>(src_loc, "SpecializeShader", shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}

void GLapi::StencilFunc(GLenum func, GLint ref, GLuint mask, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::StencilFunc>(src_loc, "StencilFunc", func, ref, mask);
}

void GLapi::StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::StencilFuncSeparate>(src_loc, "StencilFuncSeparate", face, func, ref, mask);
}

void GLapi::StencilMask(GLuint mask, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::StencilMask>(src_loc, "StencilMask", mask);
}

void GLapi::StencilMaskSeparate(GLenum face, GLuint mask, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::StencilMaskSeparate>(src_loc, "StencilMaskSeparate", face, mask);
}

void GLapi::StencilOp(GLenum fail, GLenum zfail, GLenum zpass, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::StencilOp>(src_loc, "StencilOp", fail, zfail, zpass);
}

void GLapi::StencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::StencilOpSeparate>(src_loc, "StencilOpSeparate", face, sfail, dpfail, dppass);
}

void GLapi::TexBuffer(GLenum target, GLenum internalformat, GLuint buffer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexBuffer>(src_loc, "TexBuffer", target, internalformat, buffer);
}

void GLapi::TexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexBufferRange>(src_loc, "TexBufferRange", target, internalformat, buffer, offset, size);
}

void GLapi::TexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexImage1D>(src_loc, "TexImage1D", target, level, internalformat, width, border, format, type, pixels);
}

void GLapi::TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexImage2D>(src_loc, "TexImage2D", target, level, internalformat, width, height, border, format, type, pixels);
}

void GLapi::TexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexImage2DMultisample>(src_loc, "TexImage2DMultisample", target, samples, internalformat, width, height, fixedsamplelocations);
}

void GLapi::TexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexImage3D>(src_loc, "TexImage3D", target, level, internalformat, width, height, depth, border, format, type, pixels);
}

void GLapi::TexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexImage3DMultisample>(src_loc, "TexImage3DMultisample", target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void GLapi::TexParameterIiv(GLenum target, GLenum pname, const GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexParameterIiv>(src_loc, "TexParameterIiv", target, pname, params);
}

void GLapi::TexParameterIuiv(GLenum target, GLenum pname, const GLuint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexParameterIuiv>(src_loc, "TexParameterIuiv", target, pname, params);
}

void GLapi::TexParameterf(GLenum target, GLenum pname, GLfloat param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexParameterf>(src_loc, "TexParameterf", target, pname, param);
}

void GLapi::TexParameterfv(GLenum target, GLenum pname, const GLfloat* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexParameterfv>(src_loc, "TexParameterfv", target, pname, params);
}

void GLapi::TexParameteri(GLenum target, GLenum pname, GLint param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexParameteri>(src_loc, "TexParameteri", target, pname, param);
}

void GLapi::TexParameteriv(GLenum target, GLenum pname, const GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexParameteriv>(src_loc, "TexParameteriv", target, pname, params);
}

void GLapi::TexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexStorage1D>(src_loc, "TexStorage1D", target, levels, internalformat, width);
}

void GLapi::TexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexStorage2D>(src_loc, "TexStorage2D", target, levels, internalformat, width, height);
}

void GLapi::TexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexStorage2DMultisample>(src_loc, "TexStorage2DMultisample", target, samples, internalformat, width, height, fixedsamplelocations);
}

void GLapi::TexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexStorage3D>(src_loc, "TexStorage3D", target, levels, internalformat, width, height, depth);
}

void GLapi::TexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexStorage3DMultisample>(src_loc, "TexStorage3DMultisample", target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void GLapi::TexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexSubImage1D>(src_loc, "TexSubImage1D", target, level, xoffset, width, format, type, pixels);
}

void GLapi::TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexSubImage2D>(src_loc, "TexSubImage2D", target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void GLapi::TexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TexSubImage3D>(src_loc, "TexSubImage3D", target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void GLapi::TextureBarrier(const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureBarrier>(src_loc, "TextureBarrier");
}

void GLapi::TextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureBuffer>(src_loc, "TextureBuffer", texture, internalformat, buffer);
}

void GLapi::TextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureBufferRange>(src_loc, "TextureBufferRange", texture, internalformat, buffer, offset, size);
}

void GLapi::TextureParameterIiv(GLuint texture, GLenum pname, const GLint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureParameterIiv>(src_loc, "TextureParameterIiv", texture, pname, params);
}

void GLapi::TextureParameterIuiv(GLuint texture, GLenum pname, const GLuint* params, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureParameterIuiv>(src_loc, "TextureParameterIuiv", texture, pname, params);
}

void GLapi::TextureParameterf(GLuint texture, GLenum pname, GLfloat param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureParameterf>(src_loc, "TextureParameterf", texture, pname, param);
}

void GLapi::TextureParameterfv(GLuint texture, GLenum pname, const GLfloat* param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureParameterfv>(src_loc, "TextureParameterfv", texture, pname, param);
}

void GLapi::TextureParameteri(GLuint texture, GLenum pname, GLint param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureParameteri>(src_loc, "TextureParameteri", texture, pname, param);
}

void GLapi::TextureParameteriv(GLuint texture, GLenum pname, const GLint* param, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureParameteriv>(src_loc, "TextureParameteriv", texture, pname, param);
}

void GLapi::TextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureStorage1D>(src_loc, "TextureStorage1D", texture, levels, internalformat, width);
}

void GLapi::TextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureStorage2D>(src_loc, "TextureStorage2D", texture, levels, internalformat, width, height);
}

void GLapi::TextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureStorage2DMultisample>(src_loc, "TextureStorage2DMultisample", texture, samples, internalformat, width, height, fixedsamplelocations);
}

void GLapi::TextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureStorage3D>(src_loc, "TextureStorage3D", texture, levels, internalformat, width, height, depth);
}

void GLapi::TextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureStorage3DMultisample>(src_loc, "TextureStorage3DMultisample", texture, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void GLapi::TextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureSubImage1D>(src_loc, "TextureSubImage1D", texture, level, xoffset, width, format, type, pixels);
}

void GLapi::TextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureSubImage2D>(src_loc, "TextureSubImage2D", texture, level, xoffset, yoffset, width, height, format, type, pixels);
}

void GLapi::TextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureSubImage3D>(src_loc, "TextureSubImage3D", texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void GLapi::TextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TextureView>(src_loc, "TextureView", texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
}

void GLapi::TransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TransformFeedbackBufferBase>(src_loc, "TransformFeedbackBufferBase", xfb, index, buffer);
}

void GLapi::TransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::TransformFeedbackBufferRange>(src_loc, "TransformFeedbackBufferRange", xfb, index, buffer, offset, size);
}

void GLapi::Uniform1d(GLint location, GLdouble x, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform1d>(src_loc, "Uniform1d", location, x);
}

void GLapi::Uniform1dv(GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform1dv>(src_loc, "Uniform1dv", location, count, value);
}

void GLapi::Uniform1f(GLint location, GLfloat v0, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform1f>(src_loc, "Uniform1f", location, v0);
}

void GLapi::Uniform1fv(GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform1fv>(src_loc, "Uniform1fv", location, count, value);
}

void GLapi::Uniform1i(GLint location, GLint v0, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform1i>(src_loc, "Uniform1i", location, v0);
}

void GLapi::Uniform1iv(GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform1iv>(src_loc, "Uniform1iv", location, count, value);
}

void GLapi::Uniform1ui(GLint location, GLuint v0, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform1ui>(src_loc, "Uniform1ui", location, v0);
}

void GLapi::Uniform1uiv(GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform1uiv>(src_loc, "Uniform1uiv", location, count, value);
}

void GLapi::Uniform2d(GLint location, GLdouble x, GLdouble y, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform2d>(src_loc, "Uniform2d", location, x, y);
}

void GLapi::Uniform2dv(GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform2dv>(src_loc, "Uniform2dv", location, count, value);
}

void GLapi::Uniform2f(GLint location, GLfloat v0, GLfloat v1, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform2f>(src_loc, "Uniform2f", location, v0, v1);
}

void GLapi::Uniform2fv(GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform2fv>(src_loc, "Uniform2fv", location, count, value);
}

void GLapi::Uniform2i(GLint location, GLint v0, GLint v1, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform2i>(src_loc, "Uniform2i", location, v0, v1);
}

void GLapi::Uniform2iv(GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform2iv>(src_loc, "Uniform2iv", location, count, value);
}

void GLapi::Uniform2ui(GLint location, GLuint v0, GLuint v1, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform2ui>(src_loc, "Uniform2ui", location, v0, v1);
}

void GLapi::Uniform2uiv(GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform2uiv>(src_loc, "Uniform2uiv", location, count, value);
}

void GLapi::Uniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform3d>(src_loc, "Uniform3d", location, x, y, z);
}

void GLapi::Uniform3dv(GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform3dv>(src_loc, "Uniform3dv", location, count, value);
}

void GLapi::Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform3f>(src_loc, "Uniform3f", location, v0, v1, v2);
}

void GLapi::Uniform3fv(GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform3fv>(src_loc, "Uniform3fv", location, count, value);
}

void GLapi::Uniform3i(GLint location, GLint v0, GLint v1, GLint v2, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform3i>(src_loc, "Uniform3i", location, v0, v1, v2);
}

void GLapi::Uniform3iv(GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform3iv>(src_loc, "Uniform3iv", location, count, value);
}

void GLapi::Uniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform3ui>(src_loc, "Uniform3ui", location, v0, v1, v2);
}

void GLapi::Uniform3uiv(GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform3uiv>(src_loc, "Uniform3uiv", location, count, value);
}

void GLapi::Uniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform4d>(src_loc, "Uniform4d", location, x, y, z, w);
}

void GLapi::Uniform4dv(GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform4dv>(src_loc, "Uniform4dv", location, count, value);
}

void GLapi::Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform4f>(src_loc, "Uniform4f", location, v0, v1, v2, v3);
}

void GLapi::Uniform4fv(GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform4fv>(src_loc, "Uniform4fv", location, count, value);
}

void GLapi::Uniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform4i>(src_loc, "Uniform4i", location, v0, v1, v2, v3);
}

void GLapi::Uniform4iv(GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform4iv>(src_loc, "Uniform4iv", location, count, value);
}

void GLapi::Uniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform4ui>(src_loc, "Uniform4ui", location, v0, v1, v2, v3);
}

void GLapi::Uniform4uiv(GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Uniform4uiv>(src_loc, "Uniform4uiv", location, count, value);
}

void GLapi::UniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformBlockBinding>(src_loc, "UniformBlockBinding", program, uniformBlockIndex, uniformBlockBinding);
}

void GLapi::UniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix2dv>(src_loc, "UniformMatrix2dv", location, count, transpose, value);
}

void GLapi::UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix2fv>(src_loc, "UniformMatrix2fv", location, count, transpose, value);
}

void GLapi::UniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix2x3dv>(src_loc, "UniformMatrix2x3dv", location, count, transpose, value);
}

void GLapi::UniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix2x3fv>(src_loc, "UniformMatrix2x3fv", location, count, transpose, value);
}

void GLapi::UniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix2x4dv>(src_loc, "UniformMatrix2x4dv", location, count, transpose, value);
}

void GLapi::UniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix2x4fv>(src_loc, "UniformMatrix2x4fv", location, count, transpose, value);
}

void GLapi::UniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix3dv>(src_loc, "UniformMatrix3dv", location, count, transpose, value);
}

void GLapi::UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix3fv>(src_loc, "UniformMatrix3fv", location, count, transpose, value);
}

void GLapi::UniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix3x2dv>(src_loc, "UniformMatrix3x2dv", location, count, transpose, value);
}

void GLapi::UniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix3x2fv>(src_loc, "UniformMatrix3x2fv", location, count, transpose, value);
}

void GLapi::UniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix3x4dv>(src_loc, "UniformMatrix3x4dv", location, count, transpose, value);
}

void GLapi::UniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix3x4fv>(src_loc, "UniformMatrix3x4fv", location, count, transpose, value);
}

void GLapi::UniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix4dv>(src_loc, "UniformMatrix4dv", location, count, transpose, value);
}

void GLapi::UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix4fv>(src_loc, "UniformMatrix4fv", location, count, transpose, value);
}

void GLapi::UniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix4x2dv>(src_loc, "UniformMatrix4x2dv", location, count, transpose, value);
}

void GLapi::UniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix4x2fv>(src_loc, "UniformMatrix4x2fv", location, count, transpose, value);
}

void GLapi::UniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix4x3dv>(src_loc, "UniformMatrix4x3dv", location, count, transpose, value);
}

void GLapi::UniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformMatrix4x3fv>(src_loc, "UniformMatrix4x3fv", location, count, transpose, value);
}

void GLapi::UniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint* indices, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UniformSubroutinesuiv>(src_loc, "UniformSubroutinesuiv", shadertype, count, indices);
}

GLboolean GLapi::UnmapBuffer(GLenum target, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UnmapBuffer>(src_loc, "UnmapBuffer", target);
}

GLboolean GLapi::UnmapNamedBuffer(GLuint buffer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UnmapNamedBuffer>(src_loc, "UnmapNamedBuffer", buffer);
}

void GLapi::UseProgram(GLuint program, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UseProgram>(src_loc, "UseProgram", program);
}

void GLapi::UseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::UseProgramStages>(src_loc, "UseProgramStages", pipeline, stages, program);
}

void GLapi::ValidateProgram(GLuint program, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ValidateProgram>(src_loc, "ValidateProgram", program);
}

void GLapi::ValidateProgramPipeline(GLuint pipeline, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ValidateProgramPipeline>(src_loc, "ValidateProgramPipeline", pipeline);
}

void GLapi::VertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexArrayAttribBinding>(src_loc, "VertexArrayAttribBinding", vaobj, attribindex, bindingindex);
}

void GLapi::VertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexArrayAttribFormat>(src_loc, "VertexArrayAttribFormat", vaobj, attribindex, size, type, normalized, relativeoffset);
}

void GLapi::VertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexArrayAttribIFormat>(src_loc, "VertexArrayAttribIFormat", vaobj, attribindex, size, type, relativeoffset);
}

void GLapi::VertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexArrayAttribLFormat>(src_loc, "VertexArrayAttribLFormat", vaobj, attribindex, size, type, relativeoffset);
}

void GLapi::VertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexArrayBindingDivisor>(src_loc, "VertexArrayBindingDivisor", vaobj, bindingindex, divisor);
}

void GLapi::VertexArrayElementBuffer(GLuint vaobj, GLuint buffer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexArrayElementBuffer>(src_loc, "VertexArrayElementBuffer", vaobj, buffer);
}

void GLapi::VertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexArrayVertexBuffer>(src_loc, "VertexArrayVertexBuffer", vaobj, bindingindex, buffer, offset, stride);
}

void GLapi::VertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexArrayVertexBuffers>(src_loc, "VertexArrayVertexBuffers", vaobj, first, count, buffers, offsets, strides);
}

void GLapi::VertexAttrib1d(GLuint index, GLdouble x, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib1d>(src_loc, "VertexAttrib1d", index, x);
}

void GLapi::VertexAttrib1dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib1dv>(src_loc, "VertexAttrib1dv", index, v);
}

void GLapi::VertexAttrib1f(GLuint index, GLfloat x, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib1f>(src_loc, "VertexAttrib1f", index, x);
}

void GLapi::VertexAttrib1fv(GLuint index, const GLfloat* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib1fv>(src_loc, "VertexAttrib1fv", index, v);
}

void GLapi::VertexAttrib1s(GLuint index, GLshort x, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib1s>(src_loc, "VertexAttrib1s", index, x);
}

void GLapi::VertexAttrib1sv(GLuint index, const GLshort* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib1sv>(src_loc, "VertexAttrib1sv", index, v);
}

void GLapi::VertexAttrib2d(GLuint index, GLdouble x, GLdouble y, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib2d>(src_loc, "VertexAttrib2d", index, x, y);
}

void GLapi::VertexAttrib2dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib2dv>(src_loc, "VertexAttrib2dv", index, v);
}

void GLapi::VertexAttrib2f(GLuint index, GLfloat x, GLfloat y, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib2f>(src_loc, "VertexAttrib2f", index, x, y);
}

void GLapi::VertexAttrib2fv(GLuint index, const GLfloat* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib2fv>(src_loc, "VertexAttrib2fv", index, v);
}

void GLapi::VertexAttrib2s(GLuint index, GLshort x, GLshort y, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib2s>(src_loc, "VertexAttrib2s", index, x, y);
}

void GLapi::VertexAttrib2sv(GLuint index, const GLshort* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib2sv>(src_loc, "VertexAttrib2sv", index, v);
}

void GLapi::VertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib3d>(src_loc, "VertexAttrib3d", index, x, y, z);
}

void GLapi::VertexAttrib3dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib3dv>(src_loc, "VertexAttrib3dv", index, v);
}

void GLapi::VertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib3f>(src_loc, "VertexAttrib3f", index, x, y, z);
}

void GLapi::VertexAttrib3fv(GLuint index, const GLfloat* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib3fv>(src_loc, "VertexAttrib3fv", index, v);
}

void GLapi::VertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib3s>(src_loc, "VertexAttrib3s", index, x, y, z);
}

void GLapi::VertexAttrib3sv(GLuint index, const GLshort* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib3sv>(src_loc, "VertexAttrib3sv", index, v);
}

void GLapi::VertexAttrib4Nbv(GLuint index, const GLbyte* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4Nbv>(src_loc, "VertexAttrib4Nbv", index, v);
}

void GLapi::VertexAttrib4Niv(GLuint index, const GLint* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4Niv>(src_loc, "VertexAttrib4Niv", index, v);
}

void GLapi::VertexAttrib4Nsv(GLuint index, const GLshort* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4Nsv>(src_loc, "VertexAttrib4Nsv", index, v);
}

void GLapi::VertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4Nub>(src_loc, "VertexAttrib4Nub", index, x, y, z, w);
}

void GLapi::VertexAttrib4Nubv(GLuint index, const GLubyte* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4Nubv>(src_loc, "VertexAttrib4Nubv", index, v);
}

void GLapi::VertexAttrib4Nuiv(GLuint index, const GLuint* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4Nuiv>(src_loc, "VertexAttrib4Nuiv", index, v);
}

void GLapi::VertexAttrib4Nusv(GLuint index, const GLushort* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4Nusv>(src_loc, "VertexAttrib4Nusv", index, v);
}

void GLapi::VertexAttrib4bv(GLuint index, const GLbyte* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4bv>(src_loc, "VertexAttrib4bv", index, v);
}

void GLapi::VertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4d>(src_loc, "VertexAttrib4d", index, x, y, z, w);
}

void GLapi::VertexAttrib4dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4dv>(src_loc, "VertexAttrib4dv", index, v);
}

void GLapi::VertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4f>(src_loc, "VertexAttrib4f", index, x, y, z, w);
}

void GLapi::VertexAttrib4fv(GLuint index, const GLfloat* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4fv>(src_loc, "VertexAttrib4fv", index, v);
}

void GLapi::VertexAttrib4iv(GLuint index, const GLint* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4iv>(src_loc, "VertexAttrib4iv", index, v);
}

void GLapi::VertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4s>(src_loc, "VertexAttrib4s", index, x, y, z, w);
}

void GLapi::VertexAttrib4sv(GLuint index, const GLshort* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4sv>(src_loc, "VertexAttrib4sv", index, v);
}

void GLapi::VertexAttrib4ubv(GLuint index, const GLubyte* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4ubv>(src_loc, "VertexAttrib4ubv", index, v);
}

void GLapi::VertexAttrib4uiv(GLuint index, const GLuint* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4uiv>(src_loc, "VertexAttrib4uiv", index, v);
}

void GLapi::VertexAttrib4usv(GLuint index, const GLushort* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttrib4usv>(src_loc, "VertexAttrib4usv", index, v);
}

void GLapi::VertexAttribBinding(GLuint attribindex, GLuint bindingindex, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribBinding>(src_loc, "VertexAttribBinding", attribindex, bindingindex);
}

void GLapi::VertexAttribDivisor(GLuint index, GLuint divisor, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribDivisor>(src_loc, "VertexAttribDivisor", index, divisor);
}

void GLapi::VertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribFormat>(src_loc, "VertexAttribFormat", attribindex, size, type, normalized, relativeoffset);
}

void GLapi::VertexAttribI1i(GLuint index, GLint x, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI1i>(src_loc, "VertexAttribI1i", index, x);
}

void GLapi::VertexAttribI1iv(GLuint index, const GLint* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI1iv>(src_loc, "VertexAttribI1iv", index, v);
}

void GLapi::VertexAttribI1ui(GLuint index, GLuint x, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI1ui>(src_loc, "VertexAttribI1ui", index, x);
}

void GLapi::VertexAttribI1uiv(GLuint index, const GLuint* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI1uiv>(src_loc, "VertexAttribI1uiv", index, v);
}

void GLapi::VertexAttribI2i(GLuint index, GLint x, GLint y, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI2i>(src_loc, "VertexAttribI2i", index, x, y);
}

void GLapi::VertexAttribI2iv(GLuint index, const GLint* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI2iv>(src_loc, "VertexAttribI2iv", index, v);
}

void GLapi::VertexAttribI2ui(GLuint index, GLuint x, GLuint y, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI2ui>(src_loc, "VertexAttribI2ui", index, x, y);
}

void GLapi::VertexAttribI2uiv(GLuint index, const GLuint* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI2uiv>(src_loc, "VertexAttribI2uiv", index, v);
}

void GLapi::VertexAttribI3i(GLuint index, GLint x, GLint y, GLint z, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI3i>(src_loc, "VertexAttribI3i", index, x, y, z);
}

void GLapi::VertexAttribI3iv(GLuint index, const GLint* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI3iv>(src_loc, "VertexAttribI3iv", index, v);
}

void GLapi::VertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI3ui>(src_loc, "VertexAttribI3ui", index, x, y, z);
}

void GLapi::VertexAttribI3uiv(GLuint index, const GLuint* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI3uiv>(src_loc, "VertexAttribI3uiv", index, v);
}

void GLapi::VertexAttribI4bv(GLuint index, const GLbyte* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI4bv>(src_loc, "VertexAttribI4bv", index, v);
}

void GLapi::VertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI4i>(src_loc, "VertexAttribI4i", index, x, y, z, w);
}

void GLapi::VertexAttribI4iv(GLuint index, const GLint* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI4iv>(src_loc, "VertexAttribI4iv", index, v);
}

void GLapi::VertexAttribI4sv(GLuint index, const GLshort* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI4sv>(src_loc, "VertexAttribI4sv", index, v);
}

void GLapi::VertexAttribI4ubv(GLuint index, const GLubyte* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI4ubv>(src_loc, "VertexAttribI4ubv", index, v);
}

void GLapi::VertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI4ui>(src_loc, "VertexAttribI4ui", index, x, y, z, w);
}

void GLapi::VertexAttribI4uiv(GLuint index, const GLuint* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI4uiv>(src_loc, "VertexAttribI4uiv", index, v);
}

void GLapi::VertexAttribI4usv(GLuint index, const GLushort* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribI4usv>(src_loc, "VertexAttribI4usv", index, v);
}

void GLapi::VertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribIFormat>(src_loc, "VertexAttribIFormat", attribindex, size, type, relativeoffset);
}

void GLapi::VertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribIPointer>(src_loc, "VertexAttribIPointer", index, size, type, stride, pointer);
}

void GLapi::VertexAttribL1d(GLuint index, GLdouble x, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribL1d>(src_loc, "VertexAttribL1d", index, x);
}

void GLapi::VertexAttribL1dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribL1dv>(src_loc, "VertexAttribL1dv", index, v);
}

void GLapi::VertexAttribL2d(GLuint index, GLdouble x, GLdouble y, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribL2d>(src_loc, "VertexAttribL2d", index, x, y);
}

void GLapi::VertexAttribL2dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribL2dv>(src_loc, "VertexAttribL2dv", index, v);
}

void GLapi::VertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribL3d>(src_loc, "VertexAttribL3d", index, x, y, z);
}

void GLapi::VertexAttribL3dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribL3dv>(src_loc, "VertexAttribL3dv", index, v);
}

void GLapi::VertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribL4d>(src_loc, "VertexAttribL4d", index, x, y, z, w);
}

void GLapi::VertexAttribL4dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribL4dv>(src_loc, "VertexAttribL4dv", index, v);
}

void GLapi::VertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribLFormat>(src_loc, "VertexAttribLFormat", attribindex, size, type, relativeoffset);
}

void GLapi::VertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribLPointer>(src_loc, "VertexAttribLPointer", index, size, type, stride, pointer);
}

void GLapi::VertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribP1ui>(src_loc, "VertexAttribP1ui", index, type, normalized, value);
}

void GLapi::VertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribP1uiv>(src_loc, "VertexAttribP1uiv", index, type, normalized, value);
}

void GLapi::VertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribP2ui>(src_loc, "VertexAttribP2ui", index, type, normalized, value);
}

void GLapi::VertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribP2uiv>(src_loc, "VertexAttribP2uiv", index, type, normalized, value);
}

void GLapi::VertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribP3ui>(src_loc, "VertexAttribP3ui", index, type, normalized, value);
}

void GLapi::VertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribP3uiv>(src_loc, "VertexAttribP3uiv", index, type, normalized, value);
}

void GLapi::VertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribP4ui>(src_loc, "VertexAttribP4ui", index, type, normalized, value);
}

void GLapi::VertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribP4uiv>(src_loc, "VertexAttribP4uiv", index, type, normalized, value);
}

void GLapi::VertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexAttribPointer>(src_loc, "VertexAttribPointer", index, size, type, normalized, stride, pointer);
}

void GLapi::VertexBindingDivisor(GLuint bindingindex, GLuint divisor, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::VertexBindingDivisor>(src_loc, "VertexBindingDivisor", bindingindex, divisor);
}

void GLapi::Viewport(GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::Viewport>(src_loc, "Viewport", x, y, width, height);
}

void GLapi::ViewportArrayv(GLuint first, GLsizei count, const GLfloat* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ViewportArrayv>(src_loc, "ViewportArrayv", first, count, v);
}

void GLapi::ViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ViewportIndexedf>(src_loc, "ViewportIndexedf", index, x, y, w, h);
}

void GLapi::ViewportIndexedfv(GLuint index, const GLfloat* v, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::ViewportIndexedfv>(src_loc, "ViewportIndexedfv", index, v);
}

void GLapi::WaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, const SrcLoc& src_loc) const {
    return _call<&GladGLContext::WaitSync>(src_loc, "WaitSync", sync, flags, timeout);
}