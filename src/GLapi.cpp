#include "GLapi.hpp"

#include <iostream>

#include "glad/gl.h"

using namespace glwpp;

struct glwpp::GLapi::GLapiImpl : public GladGLContext {};

template<auto M>
auto GLapi::_implCall(const SrcLoc& src_loc, const std::string_view& name, auto&&... args) const {
    *_last_src_loc = src_loc;
    if (_metrics){
        (*_metrics)[name.data()]++;
    }

    // if (name != "Viewport" && name != "Clear"){
    //     std::cout << name.data();
    //     ((std::cout << ',' << args), ...);
    //     std::cout << std::endl;
    // }

    if (_impl.get()->*M == nullptr){
        std::string err(name);
        err += std::string(": is not available\n") + src_loc.to_string_full() + std::string("\n");
        
        std::cout << err.c_str() << std::endl;
        throw std::runtime_error(err);
    } else {
        return (_impl.get()->*M)(std::forward<decltype(args)>(args)...);
    }    
}

GLapi::GLapi(Context& ctx) :
    CtxObj(ctx),
    _impl(new GLapiImpl{}),
    _last_src_loc(new SrcLoc{}){
}

GLapi::~GLapi(){
}

int GLapi::_loadGladGLContext(GLADloadfunc load){
    auto ver = gladLoadGLContext(_impl.get(), load);
    _version_major = ver / 10000;
    _version_minor = ver - _version_major * 10000;
    return ver;
}

const SrcLoc& GLapi::getLastSrcLoc() const {
    return *_last_src_loc;
}

void GLapi::setMetricsCategory(const std::shared_ptr<Metrics::Category>& category){
    _metrics = category;
}

void GLapi::_ActiveShaderProgram(GLuint pipeline, GLuint program, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ActiveShaderProgram>(src_loc, "ActiveShaderProgram", pipeline, program);
}

void GLapi::_ActiveTexture(GLenum texture, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ActiveTexture>(src_loc, "ActiveTexture", texture);
}

void GLapi::_AttachShader(GLuint program, GLuint shader, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::AttachShader>(src_loc, "AttachShader", program, shader);
}

void GLapi::_BeginConditionalRender(GLuint id, GLenum mode, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BeginConditionalRender>(src_loc, "BeginConditionalRender", id, mode);
}

void GLapi::_BeginQuery(GLenum target, GLuint id, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BeginQuery>(src_loc, "BeginQuery", target, id);
}

void GLapi::_BeginQueryIndexed(GLenum target, GLuint index, GLuint id, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BeginQueryIndexed>(src_loc, "BeginQueryIndexed", target, index, id);
}

void GLapi::_BeginTransformFeedback(GLenum primitiveMode, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BeginTransformFeedback>(src_loc, "BeginTransformFeedback", primitiveMode);
}

void GLapi::_BindAttribLocation(GLuint program, GLuint index, const GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindAttribLocation>(src_loc, "BindAttribLocation", program, index, name);
}

void GLapi::_BindBuffer(GLenum target, GLuint buffer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindBuffer>(src_loc, "BindBuffer", target, buffer);
}

void GLapi::_BindBufferBase(GLenum target, GLuint index, GLuint buffer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindBufferBase>(src_loc, "BindBufferBase", target, index, buffer);
}

void GLapi::_BindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindBufferRange>(src_loc, "BindBufferRange", target, index, buffer, offset, size);
}

void GLapi::_BindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindBuffersBase>(src_loc, "BindBuffersBase", target, first, count, buffers);
}

void GLapi::_BindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindBuffersRange>(src_loc, "BindBuffersRange", target, first, count, buffers, offsets, sizes);
}

void GLapi::_BindFragDataLocation(GLuint program, GLuint color, const GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindFragDataLocation>(src_loc, "BindFragDataLocation", program, color, name);
}

void GLapi::_BindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindFragDataLocationIndexed>(src_loc, "BindFragDataLocationIndexed", program, colorNumber, index, name);
}

void GLapi::_BindFramebuffer(GLenum target, GLuint framebuffer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindFramebuffer>(src_loc, "BindFramebuffer", target, framebuffer);
}

void GLapi::_BindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindImageTexture>(src_loc, "BindImageTexture", unit, texture, level, layered, layer, access, format);
}

void GLapi::_BindImageTextures(GLuint first, GLsizei count, const GLuint* textures, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindImageTextures>(src_loc, "BindImageTextures", first, count, textures);
}

void GLapi::_BindProgramPipeline(GLuint pipeline, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindProgramPipeline>(src_loc, "BindProgramPipeline", pipeline);
}

void GLapi::_BindRenderbuffer(GLenum target, GLuint renderbuffer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindRenderbuffer>(src_loc, "BindRenderbuffer", target, renderbuffer);
}

void GLapi::_BindSampler(GLuint unit, GLuint sampler, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindSampler>(src_loc, "BindSampler", unit, sampler);
}

void GLapi::_BindSamplers(GLuint first, GLsizei count, const GLuint* samplers, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindSamplers>(src_loc, "BindSamplers", first, count, samplers);
}

void GLapi::_BindTexture(GLenum target, GLuint texture, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindTexture>(src_loc, "BindTexture", target, texture);
}

void GLapi::_BindTextureUnit(GLuint unit, GLuint texture, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindTextureUnit>(src_loc, "BindTextureUnit", unit, texture);
}

void GLapi::_BindTextures(GLuint first, GLsizei count, const GLuint* textures, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindTextures>(src_loc, "BindTextures", first, count, textures);
}

void GLapi::_BindTransformFeedback(GLenum target, GLuint id, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindTransformFeedback>(src_loc, "BindTransformFeedback", target, id);
}

void GLapi::_BindVertexArray(GLuint array, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindVertexArray>(src_loc, "BindVertexArray", array);
}

void GLapi::_BindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindVertexBuffer>(src_loc, "BindVertexBuffer", bindingindex, buffer, offset, stride);
}

void GLapi::_BindVertexBuffers(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BindVertexBuffers>(src_loc, "BindVertexBuffers", first, count, buffers, offsets, strides);
}

void GLapi::_BlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BlendColor>(src_loc, "BlendColor", red, green, blue, alpha);
}

void GLapi::_BlendEquation(GLenum mode, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BlendEquation>(src_loc, "BlendEquation", mode);
}

void GLapi::_BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BlendEquationSeparate>(src_loc, "BlendEquationSeparate", modeRGB, modeAlpha);
}

void GLapi::_BlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BlendEquationSeparatei>(src_loc, "BlendEquationSeparatei", buf, modeRGB, modeAlpha);
}

void GLapi::_BlendEquationi(GLuint buf, GLenum mode, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BlendEquationi>(src_loc, "BlendEquationi", buf, mode);
}

void GLapi::_BlendFunc(GLenum sfactor, GLenum dfactor, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BlendFunc>(src_loc, "BlendFunc", sfactor, dfactor);
}

void GLapi::_BlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BlendFuncSeparate>(src_loc, "BlendFuncSeparate", sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}

void GLapi::_BlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BlendFuncSeparatei>(src_loc, "BlendFuncSeparatei", buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void GLapi::_BlendFunci(GLuint buf, GLenum src, GLenum dst, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BlendFunci>(src_loc, "BlendFunci", buf, src, dst);
}

void GLapi::_BlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BlitFramebuffer>(src_loc, "BlitFramebuffer", srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void GLapi::_BlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BlitNamedFramebuffer>(src_loc, "BlitNamedFramebuffer", readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void GLapi::_BufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BufferData>(src_loc, "BufferData", target, size, data, usage);
}

void GLapi::_BufferStorage(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BufferStorage>(src_loc, "BufferStorage", target, size, data, flags);
}

void GLapi::_BufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::BufferSubData>(src_loc, "BufferSubData", target, offset, size, data);
}

GLenum GLapi::_CheckFramebufferStatus(GLenum target, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CheckFramebufferStatus>(src_loc, "CheckFramebufferStatus", target);
}

GLenum GLapi::_CheckNamedFramebufferStatus(GLuint framebuffer, GLenum target, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CheckNamedFramebufferStatus>(src_loc, "CheckNamedFramebufferStatus", framebuffer, target);
}

void GLapi::_ClampColor(GLenum target, GLenum clamp, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClampColor>(src_loc, "ClampColor", target, clamp);
}

void GLapi::_Clear(GLbitfield mask, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Clear>(src_loc, "Clear", mask);
}

void GLapi::_ClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearBufferData>(src_loc, "ClearBufferData", target, internalformat, format, type, data);
}

void GLapi::_ClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearBufferSubData>(src_loc, "ClearBufferSubData", target, internalformat, offset, size, format, type, data);
}

void GLapi::_ClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearBufferfi>(src_loc, "ClearBufferfi", buffer, drawbuffer, depth, stencil);
}

void GLapi::_ClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearBufferfv>(src_loc, "ClearBufferfv", buffer, drawbuffer, value);
}

void GLapi::_ClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearBufferiv>(src_loc, "ClearBufferiv", buffer, drawbuffer, value);
}

void GLapi::_ClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearBufferuiv>(src_loc, "ClearBufferuiv", buffer, drawbuffer, value);
}

void GLapi::_ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearColor>(src_loc, "ClearColor", red, green, blue, alpha);
}

void GLapi::_ClearDepth(GLdouble depth, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearDepth>(src_loc, "ClearDepth", depth);
}

void GLapi::_ClearDepthf(GLfloat d, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearDepthf>(src_loc, "ClearDepthf", d);
}

void GLapi::_ClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearNamedBufferData>(src_loc, "ClearNamedBufferData", buffer, internalformat, format, type, data);
}

void GLapi::_ClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearNamedBufferSubData>(src_loc, "ClearNamedBufferSubData", buffer, internalformat, offset, size, format, type, data);
}

void GLapi::_ClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearNamedFramebufferfi>(src_loc, "ClearNamedFramebufferfi", framebuffer, buffer, drawbuffer, depth, stencil);
}

void GLapi::_ClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearNamedFramebufferfv>(src_loc, "ClearNamedFramebufferfv", framebuffer, buffer, drawbuffer, value);
}

void GLapi::_ClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearNamedFramebufferiv>(src_loc, "ClearNamedFramebufferiv", framebuffer, buffer, drawbuffer, value);
}

void GLapi::_ClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearNamedFramebufferuiv>(src_loc, "ClearNamedFramebufferuiv", framebuffer, buffer, drawbuffer, value);
}

void GLapi::_ClearStencil(GLint s, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearStencil>(src_loc, "ClearStencil", s);
}

void GLapi::_ClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearTexImage>(src_loc, "ClearTexImage", texture, level, format, type, data);
}

void GLapi::_ClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClearTexSubImage>(src_loc, "ClearTexSubImage", texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
}

GLenum GLapi::_ClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClientWaitSync>(src_loc, "ClientWaitSync", sync, flags, timeout);
}

void GLapi::_ClipControl(GLenum origin, GLenum depth, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ClipControl>(src_loc, "ClipControl", origin, depth);
}

void GLapi::_ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ColorMask>(src_loc, "ColorMask", red, green, blue, alpha);
}

void GLapi::_ColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ColorMaski>(src_loc, "ColorMaski", index, r, g, b, a);
}

void GLapi::_CompileShader(GLuint shader, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CompileShader>(src_loc, "CompileShader", shader);
}

void GLapi::_CompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CompressedTexImage1D>(src_loc, "CompressedTexImage1D", target, level, internalformat, width, border, imageSize, data);
}

void GLapi::_CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CompressedTexImage2D>(src_loc, "CompressedTexImage2D", target, level, internalformat, width, height, border, imageSize, data);
}

void GLapi::_CompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CompressedTexImage3D>(src_loc, "CompressedTexImage3D", target, level, internalformat, width, height, depth, border, imageSize, data);
}

void GLapi::_CompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CompressedTexSubImage1D>(src_loc, "CompressedTexSubImage1D", target, level, xoffset, width, format, imageSize, data);
}

void GLapi::_CompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CompressedTexSubImage2D>(src_loc, "CompressedTexSubImage2D", target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void GLapi::_CompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CompressedTexSubImage3D>(src_loc, "CompressedTexSubImage3D", target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

void GLapi::_CompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CompressedTextureSubImage1D>(src_loc, "CompressedTextureSubImage1D", texture, level, xoffset, width, format, imageSize, data);
}

void GLapi::_CompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CompressedTextureSubImage2D>(src_loc, "CompressedTextureSubImage2D", texture, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void GLapi::_CompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CompressedTextureSubImage3D>(src_loc, "CompressedTextureSubImage3D", texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

void GLapi::_CopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CopyBufferSubData>(src_loc, "CopyBufferSubData", readTarget, writeTarget, readOffset, writeOffset, size);
}

void GLapi::_CopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CopyImageSubData>(src_loc, "CopyImageSubData", srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}

void GLapi::_CopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CopyNamedBufferSubData>(src_loc, "CopyNamedBufferSubData", readBuffer, writeBuffer, readOffset, writeOffset, size);
}

void GLapi::_CopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CopyTexImage1D>(src_loc, "CopyTexImage1D", target, level, internalformat, x, y, width, border);
}

void GLapi::_CopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CopyTexImage2D>(src_loc, "CopyTexImage2D", target, level, internalformat, x, y, width, height, border);
}

void GLapi::_CopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CopyTexSubImage1D>(src_loc, "CopyTexSubImage1D", target, level, xoffset, x, y, width);
}

void GLapi::_CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CopyTexSubImage2D>(src_loc, "CopyTexSubImage2D", target, level, xoffset, yoffset, x, y, width, height);
}

void GLapi::_CopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CopyTexSubImage3D>(src_loc, "CopyTexSubImage3D", target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void GLapi::_CopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CopyTextureSubImage1D>(src_loc, "CopyTextureSubImage1D", texture, level, xoffset, x, y, width);
}

void GLapi::_CopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CopyTextureSubImage2D>(src_loc, "CopyTextureSubImage2D", texture, level, xoffset, yoffset, x, y, width, height);
}

void GLapi::_CopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CopyTextureSubImage3D>(src_loc, "CopyTextureSubImage3D", texture, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void GLapi::_CreateBuffers(GLsizei n, GLuint* dst, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CreateBuffers>(src_loc, "CreateBuffers", n, dst);
}

void GLapi::_CreateFramebuffers(GLsizei n, GLuint* framebuffers, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CreateFramebuffers>(src_loc, "CreateFramebuffers", n, framebuffers);
}

GLuint GLapi::_CreateProgram(const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CreateProgram>(src_loc, "CreateProgram");
}

void GLapi::_CreateProgramPipelines(GLsizei n, GLuint* pipelines, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CreateProgramPipelines>(src_loc, "CreateProgramPipelines", n, pipelines);
}

void GLapi::_CreateQueries(GLenum target, GLsizei n, GLuint* ids, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CreateQueries>(src_loc, "CreateQueries", target, n, ids);
}

void GLapi::_CreateRenderbuffers(GLsizei n, GLuint* renderbuffers, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CreateRenderbuffers>(src_loc, "CreateRenderbuffers", n, renderbuffers);
}

void GLapi::_CreateSamplers(GLsizei n, GLuint* samplers, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CreateSamplers>(src_loc, "CreateSamplers", n, samplers);
}

GLuint GLapi::_CreateShader(GLenum type, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CreateShader>(src_loc, "CreateShader", type);
}

void GLapi::_CreateTextures(GLenum target, GLsizei n, GLuint* textures, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CreateTextures>(src_loc, "CreateTextures", target, n, textures);
}

void GLapi::_CreateTransformFeedbacks(GLsizei n, GLuint* ids, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CreateTransformFeedbacks>(src_loc, "CreateTransformFeedbacks", n, ids);
}

void GLapi::_CreateVertexArrays(GLsizei n, GLuint* arrays, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CreateVertexArrays>(src_loc, "CreateVertexArrays", n, arrays);
}

void GLapi::_CullFace(GLenum mode, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::CullFace>(src_loc, "CullFace", mode);
}

void GLapi::_DebugMessageCallback(GLDEBUGPROC callback, const void* userParam, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DebugMessageCallback>(src_loc, "DebugMessageCallback", callback, userParam);
}

void GLapi::_DebugMessageControl(GLenum sResource, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DebugMessageControl>(src_loc, "DebugMessageControl", sResource, type, severity, count, ids, enabled);
}

void GLapi::_DebugMessageInsert(GLenum sResource, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DebugMessageInsert>(src_loc, "DebugMessageInsert", sResource, type, id, severity, length, buf);
}

void GLapi::_DeleteBuffers(GLsizei n, const GLuint* buffers, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DeleteBuffers>(src_loc, "DeleteBuffers", n, buffers);
}

void GLapi::_DeleteFramebuffers(GLsizei n, const GLuint* framebuffers, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DeleteFramebuffers>(src_loc, "DeleteFramebuffers", n, framebuffers);
}

void GLapi::_DeleteProgram(GLuint program, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DeleteProgram>(src_loc, "DeleteProgram", program);
}

void GLapi::_DeleteProgramPipelines(GLsizei n, const GLuint* pipelines, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DeleteProgramPipelines>(src_loc, "DeleteProgramPipelines", n, pipelines);
}

void GLapi::_DeleteQueries(GLsizei n, const GLuint* ids, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DeleteQueries>(src_loc, "DeleteQueries", n, ids);
}

void GLapi::_DeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DeleteRenderbuffers>(src_loc, "DeleteRenderbuffers", n, renderbuffers);
}

void GLapi::_DeleteSamplers(GLsizei count, const GLuint* samplers, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DeleteSamplers>(src_loc, "DeleteSamplers", count, samplers);
}

void GLapi::_DeleteShader(GLuint shader, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DeleteShader>(src_loc, "DeleteShader", shader);
}

void GLapi::_DeleteSync(GLsync sync, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DeleteSync>(src_loc, "DeleteSync", sync);
}

void GLapi::_DeleteTextures(GLsizei n, const GLuint* textures, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DeleteTextures>(src_loc, "DeleteTextures", n, textures);
}

void GLapi::_DeleteTransformFeedbacks(GLsizei n, const GLuint* ids, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DeleteTransformFeedbacks>(src_loc, "DeleteTransformFeedbacks", n, ids);
}

void GLapi::_DeleteVertexArrays(GLsizei n, const GLuint* arrays, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DeleteVertexArrays>(src_loc, "DeleteVertexArrays", n, arrays);
}

void GLapi::_DepthFunc(GLenum func, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DepthFunc>(src_loc, "DepthFunc", func);
}

void GLapi::_DepthMask(GLboolean flag, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DepthMask>(src_loc, "DepthMask", flag);
}

void GLapi::_DepthRange(GLdouble n, GLdouble f, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DepthRange>(src_loc, "DepthRange", n, f);
}

void GLapi::_DepthRangeArrayv(GLuint first, GLsizei count, const GLdouble* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DepthRangeArrayv>(src_loc, "DepthRangeArrayv", first, count, v);
}

void GLapi::_DepthRangeIndexed(GLuint index, GLdouble n, GLdouble f, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DepthRangeIndexed>(src_loc, "DepthRangeIndexed", index, n, f);
}

void GLapi::_DepthRangef(GLfloat n, GLfloat f, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DepthRangef>(src_loc, "DepthRangef", n, f);
}

void GLapi::_DetachShader(GLuint program, GLuint shader, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DetachShader>(src_loc, "DetachShader", program, shader);
}

void GLapi::_Disable(GLenum cap, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Disable>(src_loc, "Disable", cap);
}

void GLapi::_DisableVertexArrayAttrib(GLuint vaobj, GLuint index, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DisableVertexArrayAttrib>(src_loc, "DisableVertexArrayAttrib", vaobj, index);
}

void GLapi::_DisableVertexAttribArray(GLuint index, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DisableVertexAttribArray>(src_loc, "DisableVertexAttribArray", index);
}

void GLapi::_Disablei(GLenum target, GLuint index, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Disablei>(src_loc, "Disablei", target, index);
}

void GLapi::_DispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DispatchCompute>(src_loc, "DispatchCompute", num_groups_x, num_groups_y, num_groups_z);
}

void GLapi::_DispatchComputeIndirect(GLintptr indirect, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DispatchComputeIndirect>(src_loc, "DispatchComputeIndirect", indirect);
}

void GLapi::_DrawArrays(GLenum mode, GLint first, GLsizei count, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawArrays>(src_loc, "DrawArrays", mode, first, count);
}

void GLapi::_DrawArraysIndirect(GLenum mode, const void* indirect, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawArraysIndirect>(src_loc, "DrawArraysIndirect", mode, indirect);
}

void GLapi::_DrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawArraysInstanced>(src_loc, "DrawArraysInstanced", mode, first, count, instancecount);
}

void GLapi::_DrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawArraysInstancedBaseInstance>(src_loc, "DrawArraysInstancedBaseInstance", mode, first, count, instancecount, instancecount);
}

void GLapi::_DrawBuffer(GLenum buf, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawBuffer>(src_loc, "DrawBuffer", buf);
}

void GLapi::_DrawBuffers(GLsizei n, const GLenum* bufs, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawBuffers>(src_loc, "DrawBuffers", n, bufs);
}

void GLapi::_DrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawElements>(src_loc, "DrawElements", mode, count, type, indices);
}

void GLapi::_DrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawElementsBaseVertex>(src_loc, "DrawElementsBaseVertex", mode, count, type, indices, basevertex);
}

void GLapi::_DrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawElementsIndirect>(src_loc, "DrawElementsIndirect", mode, type, indirect);
}

void GLapi::_DrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawElementsInstanced>(src_loc, "DrawElementsInstanced", mode, count, type, indices, instancecount);
}

void GLapi::_DrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawElementsInstancedBaseInstance>(src_loc, "DrawElementsInstancedBaseInstance", mode, count, type, indices, instancecount, baseinstance);
}

void GLapi::_DrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawElementsInstancedBaseVertex>(src_loc, "DrawElementsInstancedBaseVertex", mode, count, type, indices, instancecount, basevertex);
}

void GLapi::_DrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawElementsInstancedBaseVertexBaseInstance>(src_loc, "DrawElementsInstancedBaseVertexBaseInstance", mode, count, type, indices, instancecount, basevertex, baseinstance);
}

void GLapi::_DrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawRangeElements>(src_loc, "DrawRangeElements", mode, start, end, count, type, indices);
}

void GLapi::_DrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawRangeElementsBaseVertex>(src_loc, "DrawRangeElementsBaseVertex", mode, start, end, count, type, indices, basevertex);
}

void GLapi::_DrawTransformFeedback(GLenum mode, GLuint id, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawTransformFeedback>(src_loc, "DrawTransformFeedback", mode, id);
}

void GLapi::_DrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawTransformFeedbackInstanced>(src_loc, "DrawTransformFeedbackInstanced", mode, id, instancecount);
}

void GLapi::_DrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawTransformFeedbackStream>(src_loc, "DrawTransformFeedbackStream", mode, id, stream);
}

void GLapi::_DrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::DrawTransformFeedbackStreamInstanced>(src_loc, "DrawTransformFeedbackStreamInstanced", mode, id, stream, instancecount);
}

void GLapi::_Enable(GLenum cap, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Enable>(src_loc, "Enable", cap);
}

void GLapi::_EnableVertexArrayAttrib(GLuint vaobj, GLuint index, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::EnableVertexArrayAttrib>(src_loc, "EnableVertexArrayAttrib", vaobj, index);
}

void GLapi::_EnableVertexAttribArray(GLuint index, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::EnableVertexAttribArray>(src_loc, "EnableVertexAttribArray", index);
}

void GLapi::_Enablei(GLenum target, GLuint index, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Enablei>(src_loc, "Enablei", target, index);
}

void GLapi::_EndConditionalRender(const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::EndConditionalRender>(src_loc, "EndConditionalRender");
}

void GLapi::_EndQuery(GLenum target, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::EndQuery>(src_loc, "EndQuery", target);
}

void GLapi::_EndQueryIndexed(GLenum target, GLuint index, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::EndQueryIndexed>(src_loc, "EndQueryIndexed", target, index);
}

void GLapi::_EndTransformFeedback(const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::EndTransformFeedback>(src_loc, "EndTransformFeedback");
}

GLsync GLapi::_FenceSync(GLenum condition, GLbitfield flags, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::FenceSync>(src_loc, "FenceSync", condition, flags);
}

void GLapi::_Finish(const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Finish>(src_loc, "Finish");
}

void GLapi::_Flush(const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Flush>(src_loc, "Flush");
}

void GLapi::_FlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::FlushMappedBufferRange>(src_loc, "FlushMappedBufferRange", target, offset, length);
}

void GLapi::_FlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::FlushMappedNamedBufferRange>(src_loc, "FlushMappedNamedBufferRange", buffer, offset, length);
}

void GLapi::_FramebufferParameteri(GLenum target, GLenum pname, GLint param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::FramebufferParameteri>(src_loc, "FramebufferParameteri", target, pname, param);
}

void GLapi::_FramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::FramebufferRenderbuffer>(src_loc, "FramebufferRenderbuffer", target, attachment, renderbuffertarget, renderbuffer);
}

void GLapi::_FramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::FramebufferTexture>(src_loc, "FramebufferTexture", target, attachment, texture, level);
}

void GLapi::_FramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::FramebufferTexture1D>(src_loc, "FramebufferTexture1D", target, attachment, textarget, target, level);
}

void GLapi::_FramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::FramebufferTexture2D>(src_loc, "FramebufferTexture2D", target, attachment, textarget, texture, level);
}

void GLapi::_FramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::FramebufferTexture3D>(src_loc, "FramebufferTexture3D", target, attachment, textarget, texture, level, zoffset);
}

void GLapi::_FramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::FramebufferTextureLayer>(src_loc, "FramebufferTextureLayer", target, attachment, texture, level, layer);
}

void GLapi::_FrontFace(GLenum mode, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::FrontFace>(src_loc, "FrontFace", mode);
}

void GLapi::_GenBuffers(GLsizei n, GLuint* buffers, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GenBuffers>(src_loc, "GenBuffers", n, buffers);
}

void GLapi::_GenFramebuffers(GLsizei n, GLuint* framebuffers, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GenFramebuffers>(src_loc, "GenFramebuffers", n, framebuffers);
}

void GLapi::_GenProgramPipelines(GLsizei n, GLuint* pipelines, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GenProgramPipelines>(src_loc, "GenProgramPipelines", n, pipelines);
}

void GLapi::_GenQueries(GLsizei n, GLuint* ids, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GenQueries>(src_loc, "GenQueries", n, ids);
}

void GLapi::_GenRenderbuffers(GLsizei n, GLuint* renderbuffers, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GenRenderbuffers>(src_loc, "GenRenderbuffers", n, renderbuffers);
}

void GLapi::_GenSamplers(GLsizei count, GLuint* samplers, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GenSamplers>(src_loc, "GenSamplers", count, samplers);
}

void GLapi::_GenTextures(GLsizei n, GLuint* textures, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GenTextures>(src_loc, "GenTextures", n, textures);
}

void GLapi::_GenTransformFeedbacks(GLsizei n, GLuint* ids, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GenTransformFeedbacks>(src_loc, "GenTransformFeedbacks", n, ids);
}

void GLapi::_GenVertexArrays(GLsizei n, GLuint* arrays, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GenVertexArrays>(src_loc, "GenVertexArrays", n, arrays);
}

void GLapi::_GenerateMipmap(GLenum target, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GenerateMipmap>(src_loc, "GenerateMipmap", target);
}

void GLapi::_GenerateTextureMipmap(GLuint texture, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GenerateTextureMipmap>(src_loc, "GenerateTextureMipmap", texture);
}

void GLapi::_GetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetActiveAtomicCounterBufferiv>(src_loc, "GetActiveAtomicCounterBufferiv", program, bufferIndex, pname, params);
}

void GLapi::_GetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetActiveAttrib>(src_loc, "GetActiveAttrib", program, index, bufSize, length, size, type, name);
}

void GLapi::_GetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetActiveSubroutineName>(src_loc, "GetActiveSubroutineName", program, shadertype, index, bufSize, length, name);
}

void GLapi::_GetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetActiveSubroutineUniformName>(src_loc, "GetActiveSubroutineUniformName", program, shadertype, index, bufSize, length, name);
}

void GLapi::_GetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetActiveSubroutineUniformiv>(src_loc, "GetActiveSubroutineUniformiv", program, shadertype, index, pname, values);
}

void GLapi::_GetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetActiveUniform>(src_loc, "GetActiveUniform", program, index, bufSize, length, size, type, name);
}

void GLapi::_GetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetActiveUniformBlockName>(src_loc, "GetActiveUniformBlockName", program, uniformBlockIndex, bufSize, length, uniformBlockName);
}

void GLapi::_GetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetActiveUniformBlockiv>(src_loc, "GetActiveUniformBlockiv", program, uniformBlockIndex, pname, params);
}

void GLapi::_GetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetActiveUniformName>(src_loc, "GetActiveUniformName", program, uniformIndex, bufSize, length, uniformName);
}

void GLapi::_GetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetActiveUniformsiv>(src_loc, "GetActiveUniformsiv", program, uniformCount, uniformIndices, pname, params);
}

void GLapi::_GetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetAttachedShaders>(src_loc, "GetAttachedShaders", program, maxCount, count, shaders);
}

GLint GLapi::_GetAttribLocation(GLuint program, const GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetAttribLocation>(src_loc, "GetAttribLocation", program, name);
}

void GLapi::_GetBooleani_v(GLenum target, GLuint index, GLboolean* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetBooleani_v>(src_loc, "GetBooleani_v", target, index, data);
}

void GLapi::_GetBooleanv(GLenum pname, GLboolean* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetBooleanv>(src_loc, "GetBooleanv", pname, data);
}

void GLapi::_GetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetBufferParameteri64v>(src_loc, "GetBufferParameteri64v", target, pname, params);
}

void GLapi::_GetBufferParameteriv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetBufferParameteriv>(src_loc, "GetBufferParameteriv", target, pname, params);
}

void GLapi::_GetBufferPointerv(GLenum target, GLenum pname, void** params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetBufferPointerv>(src_loc, "GetBufferPointerv", target, pname, params);
}

void GLapi::_GetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetBufferSubData>(src_loc, "GetBufferSubData", target, offset, size, data);
}

void GLapi::_GetCompressedTexImage(GLenum target, GLint level, void* img, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetCompressedTexImage>(src_loc, "GetCompressedTexImage", target, level, img);
}

void GLapi::_GetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetCompressedTextureImage>(src_loc, "GetCompressedTextureImage", texture, level, bufSize, pixels);
}

void GLapi::_GetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetCompressedTextureSubImage>(src_loc, "GetCompressedTextureSubImage", texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
}

GLuint GLapi::_GetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum* sResources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetDebugMessageLog>(src_loc, "GetDebugMessageLog", count, bufSize, sResources, types, ids, severities, lengths, messageLog);
}

void GLapi::_GetDoublei_v(GLenum target, GLuint index, GLdouble* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetDoublei_v>(src_loc, "GetDoublei_v", target, index, data);
}

void GLapi::_GetDoublev(GLenum pname, GLdouble* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetDoublev>(src_loc, "GetDoublev", pname, data);
}

GLenum GLapi::_GetError(const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetError>(src_loc, "GetError");
}

void GLapi::_GetFloati_v(GLenum target, GLuint index, GLfloat* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetFloati_v>(src_loc, "GetFloati_v", target, index, data);
}

void GLapi::_GetFloatv(GLenum pname, GLfloat* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetFloatv>(src_loc, "GetFloatv", pname, data);
}

GLint GLapi::_GetFragDataIndex(GLuint program, const GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetFragDataIndex>(src_loc, "GetFragDataIndex", program, name);
}

GLint GLapi::_GetFragDataLocation(GLuint program, const GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetFragDataLocation>(src_loc, "GetFragDataLocation", program, name);
}

void GLapi::_GetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetFramebufferAttachmentParameteriv>(src_loc, "GetFramebufferAttachmentParameteriv", target, attachment, pname, params);
}

void GLapi::_GetFramebufferParameteriv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetFramebufferParameteriv>(src_loc, "GetFramebufferParameteriv", target, pname, params);
}
void GLapi::_GetInteger64i_v(GLenum target, GLuint index, GLint64* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetInteger64i_v>(src_loc, "GetInteger64i_v", target, index, data);
}

void GLapi::_GetInteger64v(GLenum pname, GLint64* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetInteger64v>(src_loc, "GetInteger64v", pname, data);
}

void GLapi::_GetIntegeri_v(GLenum target, GLuint index, GLint* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetIntegeri_v>(src_loc, "GetIntegeri_v", target, index, data);
}

void GLapi::_GetIntegerv(GLenum pname, GLint* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetIntegerv>(src_loc, "GetIntegerv", pname, data);
}

void GLapi::_GetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetInternalformati64v>(src_loc, "GetInternalformati64v", target, internalformat, pname, count, params);
}

void GLapi::_GetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetInternalformativ>(src_loc, "GetInternalformativ", target, internalformat, pname, count, params);
}

void GLapi::_GetMultisamplefv(GLenum pname, GLuint index, GLfloat* val, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetMultisamplefv>(src_loc, "GetMultisamplefv", pname, index, val);
}

void GLapi::_GetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetNamedBufferParameteri64v>(src_loc, "GetNamedBufferParameteri64v", buffer, pname, params);
}

void GLapi::_GetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetNamedBufferParameteriv>(src_loc, "GetNamedBufferParameteriv", buffer, pname, params);
}

void GLapi::_GetNamedBufferPointerv(GLuint buffer, GLenum pname, void** params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetNamedBufferPointerv>(src_loc, "GetNamedBufferPointerv", buffer, pname, params);
}

void GLapi::_GetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetNamedBufferSubData>(src_loc, "GetNamedBufferSubData", buffer, offset, size, data);
}

void GLapi::_GetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetNamedFramebufferAttachmentParameteriv>(src_loc, "GetNamedFramebufferAttachmentParameteriv", framebuffer, attachment, pname, params);
}

void GLapi::_GetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint* param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetNamedFramebufferParameteriv>(src_loc, "GetNamedFramebufferParameteriv", framebuffer, pname, param);
}

void GLapi::_GetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetNamedRenderbufferParameteriv>(src_loc, "GetNamedRenderbufferParameteriv", renderbuffer, pname, params);
}

void GLapi::_GetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetObjectLabel>(src_loc, "GetObjectLabel", identifier, name, bufSize, length, label);
}

void GLapi::_GetObjectPtrLabel(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetObjectPtrLabel>(src_loc, "GetObjectPtrLabel", ptr, bufSize, length, label);
}

void GLapi::_GetPointerv(GLenum pname, void** params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetPointerv>(src_loc, "GetPointerv", pname, params);
}

void GLapi::_GetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetProgramBinary>(src_loc, "GetProgramBinary", program, bufSize, length, binaryFormat, binary);
}

void GLapi::_GetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetProgramInfoLog>(src_loc, "GetProgramInfoLog", program, bufSize, length, infoLog);
}

void GLapi::_GetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetProgramInterfaceiv>(src_loc, "GetProgramInterfaceiv", program, programInterface, pname, params);
}

void GLapi::_GetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetProgramPipelineInfoLog>(src_loc, "GetProgramPipelineInfoLog", pipeline, bufSize, length, infoLog);
}

void GLapi::_GetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetProgramPipelineiv>(src_loc, "GetProgramPipelineiv", pipeline, pname, params);
}

GLuint GLapi::_GetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetProgramResourceIndex>(src_loc, "GetProgramResourceIndex", program, programInterface, name);
}

GLint GLapi::_GetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetProgramResourceLocation>(src_loc, "GetProgramResourceLocation", program, programInterface, name);
}

GLint GLapi::_GetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetProgramResourceLocationIndex>(src_loc, "GetProgramResourceLocationIndex", program, programInterface, name);
}

void GLapi::_GetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetProgramResourceName>(src_loc, "GetProgramResourceName", program, programInterface, index, bufSize, length, name);
}

void GLapi::_GetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei count, GLsizei* length, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetProgramResourceiv>(src_loc, "GetProgramResourceiv", program, programInterface, index, propCount, props, count, length, params);
}

void GLapi::_GetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint* values, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetProgramStageiv>(src_loc, "GetProgramStageiv", program, shadertype, pname, values);
}

void GLapi::_GetProgramiv(GLuint program, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetProgramiv>(src_loc, "GetProgramiv", program, pname, params);
}

void GLapi::_GetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetQueryBufferObjecti64v>(src_loc, "GetQueryBufferObjecti64v", id, buffer, pname, offset);
}

void GLapi::_GetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetQueryBufferObjectiv>(src_loc, "GetQueryBufferObjectiv", id, buffer, pname, offset);
}

void GLapi::_GetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetQueryBufferObjectui64v>(src_loc, "GetQueryBufferObjectui64v", id, buffer, pname, offset);
}

void GLapi::_GetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetQueryBufferObjectuiv>(src_loc, "GetQueryBufferObjectuiv", id, buffer, pname, offset);
}

void GLapi::_GetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetQueryIndexediv>(src_loc, "GetQueryIndexediv", target, index, pname, params);
}

void GLapi::_GetQueryObjecti64v(GLuint id, GLenum pname, GLint64* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetQueryObjecti64v>(src_loc, "GetQueryObjecti64v", id, pname, params);
}

void GLapi::_GetQueryObjectiv(GLuint id, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetQueryObjectiv>(src_loc, "GetQueryObjectiv", id, pname, params);
}

void GLapi::_GetQueryObjectui64v(GLuint id, GLenum pname, GLuint64* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetQueryObjectui64v>(src_loc, "GetQueryObjectui64v", id, pname, params);
}

void GLapi::_GetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetQueryObjectuiv>(src_loc, "GetQueryObjectuiv", id, pname, params);
}

void GLapi::_GetQueryiv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetQueryiv>(src_loc, "GetQueryiv", target, pname, params);
}

void GLapi::_GetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetRenderbufferParameteriv>(src_loc, "GetRenderbufferParameteriv", target, pname, params);
}

void GLapi::_GetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetSamplerParameterIiv>(src_loc, "GetSamplerParameterIiv", sampler, pname, params);
}

void GLapi::_GetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetSamplerParameterIuiv>(src_loc, "GetSamplerParameterIuiv", sampler, pname, params);
}

void GLapi::_GetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetSamplerParameterfv>(src_loc, "GetSamplerParameterfv", sampler, pname, params);
}

void GLapi::_GetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetSamplerParameteriv>(src_loc, "GetSamplerParameteriv", sampler, pname, params);
}

void GLapi::_GetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetShaderInfoLog>(src_loc, "GetShaderInfoLog", shader, bufSize, length, infoLog);
}

void GLapi::_GetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetShaderPrecisionFormat>(src_loc, "GetShaderPrecisionFormat", shadertype, precisiontype, range, precision);
}

void GLapi::_GetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* sResource, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetShaderSource>(src_loc, "GetShaderSource", shader, bufSize, length, sResource);
}

void GLapi::_GetShaderiv(GLuint shader, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetShaderiv>(src_loc, "GetShaderiv", shader, pname, params);
}

const GLubyte* GLapi::_GetString(GLenum name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetString>(src_loc, "GetString", name);
}

const GLubyte* GLapi::_GetStringi(GLenum name, GLuint index, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetStringi>(src_loc, "GetStringi", name, index);
}

GLuint GLapi::_GetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetSubroutineIndex>(src_loc, "GetSubroutineIndex", program, shadertype, name);
}

GLint GLapi::_GetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetSubroutineUniformLocation>(src_loc, "GetSubroutineUniformLocation", program, shadertype, name);
}

void GLapi::_GetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetSynciv>(src_loc, "GetSynciv", sync, pname, count, length, values);
}

void GLapi::_GetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTexImage>(src_loc, "GetTexImage", target, level, format, type, pixels);
}

void GLapi::_GetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTexLevelParameterfv>(src_loc, "GetTexLevelParameterfv", target, level, pname, params);
}

void GLapi::_GetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTexLevelParameteriv>(src_loc, "GetTexLevelParameteriv", target, level, pname, params);
}

void GLapi::_GetTexParameterIiv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTexParameterIiv>(src_loc, "GetTexParameterIiv", target, pname, params);
}

void GLapi::_GetTexParameterIuiv(GLenum target, GLenum pname, GLuint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTexParameterIuiv>(src_loc, "GetTexParameterIuiv", target, pname, params);
}

void GLapi::_GetTexParameterfv(GLenum target, GLenum pname, GLfloat* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTexParameterfv>(src_loc, "GetTexParameterfv", target, pname, params);
}

void GLapi::_GetTexParameteriv(GLenum target, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTexParameteriv>(src_loc, "GetTexParameteriv", target, pname, params);
}

void GLapi::_GetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTextureImage>(src_loc, "GetTextureImage", texture, level, format, type, bufSize, pixels);
}

void GLapi::_GetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTextureLevelParameterfv>(src_loc, "GetTextureLevelParameterfv", texture, level, pname, params);
}

void GLapi::_GetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTextureLevelParameteriv>(src_loc, "GetTextureLevelParameteriv", texture, level, pname, params);
}

void GLapi::_GetTextureParameterIiv(GLuint texture, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTextureParameterIiv>(src_loc, "GetTextureParameterIiv", texture, pname, params);
}

void GLapi::_GetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTextureParameterIuiv>(src_loc, "GetTextureParameterIuiv", texture, pname, params);
}

void GLapi::_GetTextureParameterfv(GLuint texture, GLenum pname, GLfloat* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTextureParameterfv>(src_loc, "GetTextureParameterfv", texture, pname, params);
}

void GLapi::_GetTextureParameteriv(GLuint texture, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTextureParameteriv>(src_loc, "GetTextureParameteriv", texture, pname, params);
}

void GLapi::_GetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTextureSubImage>(src_loc, "GetTextureSubImage", texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels);
}

void GLapi::_GetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTransformFeedbackVarying>(src_loc, "GetTransformFeedbackVarying", program, index, bufSize, length, size, type, name);
}

void GLapi::_GetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64* param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTransformFeedbacki64_v>(src_loc, "GetTransformFeedbacki64_v", xfb, pname, index, param);
}

void GLapi::_GetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint* param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTransformFeedbacki_v>(src_loc, "GetTransformFeedbacki_v", xfb, pname, index, param);
}

void GLapi::_GetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint* param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetTransformFeedbackiv>(src_loc, "GetTransformFeedbackiv", xfb, pname, param);
}

GLuint GLapi::_GetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetUniformBlockIndex>(src_loc, "GetUniformBlockIndex", program, uniformBlockName);
}

GLint GLapi::_GetUniformLocation(GLuint program, const GLchar* name, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetUniformLocation>(src_loc, "GetUniformLocation", program, name);
}

void GLapi::_GetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetUniformSubroutineuiv>(src_loc, "GetUniformSubroutineuiv", shadertype, location, params);
}

void GLapi::_GetUniformdv(GLuint program, GLint location, GLdouble* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetUniformdv>(src_loc, "GetUniformdv", program, location, params);
}

void GLapi::_GetUniformfv(GLuint program, GLint location, GLfloat* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetUniformfv>(src_loc, "GetUniformfv", program, location, params);
}

void GLapi::_GetUniformiv(GLuint program, GLint location,  GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetUniformiv>(src_loc, "GetUniformiv", program, location, params);
}

void GLapi::_GetUniformuiv(GLuint program, GLint location, GLuint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetUniformuiv>(src_loc, "GetUniformuiv", program, location, params);
}

void GLapi::_GetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64* param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetVertexArrayIndexed64iv>(src_loc, "GetVertexArrayIndexed64iv", vaobj, index, pname, param);
}

void GLapi::_GetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint* param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetVertexArrayIndexediv>(src_loc, "GetVertexArrayIndexediv", vaobj, index, pname, param);
}

void GLapi::_GetVertexArrayiv(GLuint vaobj, GLenum pname, GLint* param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetVertexArrayiv>(src_loc, "GetVertexArrayiv", vaobj, pname, param);
}

void GLapi::_GetVertexAttribIiv(GLuint index, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetVertexAttribIiv>(src_loc, "GetVertexAttribIiv", index, pname, params);
}

void GLapi::_GetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetVertexAttribIuiv>(src_loc, "GetVertexAttribIuiv", index, pname, params);
}

void GLapi::_GetVertexAttribLdv(GLuint index, GLenum pname, GLdouble* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetVertexAttribLdv>(src_loc, "GetVertexAttribLdv", index, pname, params);
}

void GLapi::_GetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetVertexAttribPointerv>(src_loc, "GetVertexAttribPointerv", index, pname, pointer);
}

void GLapi::_GetVertexAttribdv(GLuint index, GLenum pname, GLdouble* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetVertexAttribdv>(src_loc, "GetVertexAttribdv", index, pname, params);
}

void GLapi::_GetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetVertexAttribfv>(src_loc, "GetVertexAttribfv", index, pname, params);
}

void GLapi::_GetVertexAttribiv(GLuint index, GLenum pname, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetVertexAttribiv>(src_loc, "GetVertexAttribiv", index, pname, params);
}

void GLapi::_GetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetnCompressedTexImage>(src_loc, "GetnCompressedTexImage", target, lod, bufSize, pixels);
}

void GLapi::_GetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetnTexImage>(src_loc, "GetnTexImage", target, level, format, type, bufSize, pixels);
}

void GLapi::_GetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetnUniformdv>(src_loc, "GetnUniformdv", program, location, bufSize, params);
}

void GLapi::_GetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetnUniformfv>(src_loc, "GetnUniformfv", program, location, bufSize, params);
}

void GLapi::_GetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetnUniformiv>(src_loc, "GetnUniformiv", program, location, bufSize, params);
}

void GLapi::_GetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::GetnUniformuiv>(src_loc, "GetnUniformuiv", program, location, bufSize, params);
}

void GLapi::_Hint(GLenum target, GLenum mode, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Hint>(src_loc, "Hint", target, mode);
}

void GLapi::_InvalidateBufferData(GLuint buffer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::InvalidateBufferData>(src_loc, "InvalidateBufferData", buffer);
}

void GLapi::_InvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::InvalidateBufferSubData>(src_loc, "InvalidateBufferSubData", buffer, offset, length);
}

void GLapi::_InvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::InvalidateFramebuffer>(src_loc, "InvalidateFramebuffer", target, numAttachments, attachments);
}

void GLapi::_InvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::InvalidateNamedFramebufferData>(src_loc, "InvalidateNamedFramebufferData", framebuffer, numAttachments, attachments);
}

void GLapi::_InvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::InvalidateNamedFramebufferSubData>(src_loc, "InvalidateNamedFramebufferSubData", framebuffer, numAttachments, attachments, x, y, width, height);
}

void GLapi::_InvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::InvalidateSubFramebuffer>(src_loc, "InvalidateSubFramebuffer", target, numAttachments, attachments, x, y, width, height);
}

void GLapi::_InvalidateTexImage(GLuint texture, GLint level, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::InvalidateTexImage>(src_loc, "InvalidateTexImage", texture, level);
}

void GLapi::_InvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::InvalidateTexSubImage>(src_loc, "InvalidateTexSubImage", texture, level, xoffset, yoffset, zoffset, width, height, depth);
}

GLboolean GLapi::_IsBuffer(GLuint buffer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::IsBuffer>(src_loc, "IsBuffer", buffer);
}

GLboolean GLapi::_IsEnabled(GLenum cap, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::IsEnabled>(src_loc, "IsEnabled", cap);
}

GLboolean GLapi::_IsEnabledi(GLenum target, GLuint index, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::IsEnabledi>(src_loc, "IsEnabledi", target, index);
}

GLboolean GLapi::_IsFramebuffer(GLuint framebuffer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::IsFramebuffer>(src_loc, "IsFramebuffer", framebuffer);
}

GLboolean GLapi::_IsProgram(GLuint program, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::IsProgram>(src_loc, "IsProgram", program);
}

GLboolean GLapi::_IsProgramPipeline(GLuint pipeline, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::IsProgramPipeline>(src_loc, "IsProgramPipeline", pipeline);
}

GLboolean GLapi::_IsQuery(GLuint id, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::IsQuery>(src_loc, "IsQuery", id);
}

GLboolean GLapi::_IsRenderbuffer(GLuint renderbuffer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::IsRenderbuffer>(src_loc, "IsRenderbuffer", renderbuffer);
}

GLboolean GLapi::_IsSampler(GLuint sampler, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::IsSampler>(src_loc, "IsSampler", sampler);
}

GLboolean GLapi::_IsShader(GLuint shader, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::IsShader>(src_loc, "IsShader", shader);
}

GLboolean GLapi::_IsSync(GLsync sync, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::IsSync>(src_loc, "IsSync", sync);
}

GLboolean GLapi::_IsTexture(GLuint texture, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::IsTexture>(src_loc, "IsTexture", texture);
}

GLboolean GLapi::_IsTransformFeedback(GLuint id, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::IsTransformFeedback>(src_loc, "IsTransformFeedback", id);
}

GLboolean GLapi::_IsVertexArray(GLuint array, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::IsVertexArray>(src_loc, "IsVertexArray", array);
}

void GLapi::_LineWidth(GLfloat width, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::LineWidth>(src_loc, "LineWidth", width);
}

void GLapi::_LinkProgram(GLuint program, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::LinkProgram>(src_loc, "LinkProgram", program);
}

void GLapi::_LogicOp(GLenum opcode, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::LogicOp>(src_loc, "LogicOp", opcode);
}

void* GLapi::_MapNamedBuffer(GLuint buffer, GLenum access, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::MapNamedBuffer>(src_loc, "MapNamedBuffer", buffer, access);
}

void GLapi::_MemoryBarrier(GLbitfield barriers, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::MemoryBarrier>(src_loc, "MemoryBarrier", barriers);
}

void GLapi::_MemoryBarrierByRegion(GLbitfield barriers, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::MemoryBarrierByRegion>(src_loc, "MemoryBarrierByRegion", barriers);
}

void GLapi::_MinSampleShading(GLfloat value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::MinSampleShading>(src_loc, "MinSampleShading", value);
}

void GLapi::_MultiDrawArrays(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::MultiDrawArrays>(src_loc, "MultiDrawArrays", mode, first, count, drawcount);
}

void GLapi::_MultiDrawArraysIndirect(GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::MultiDrawArraysIndirect>(src_loc, "MultiDrawArraysIndirect", mode, indirect, drawcount, stride);
}

void GLapi::_MultiDrawArraysIndirectCount(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::MultiDrawArraysIndirectCount>(src_loc, "MultiDrawArraysIndirectCount", mode, indirect, drawcount, maxdrawcount, stride);
}

void GLapi::_MultiDrawElements(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::MultiDrawElements>(src_loc, "MultiDrawElements", mode, count, type, indices, drawcount);
}

void GLapi::_MultiDrawElementsBaseVertex(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::MultiDrawElementsBaseVertex>(src_loc, "MultiDrawElementsBaseVertex", mode, count, type, indices, drawcount, basevertex);
}

void GLapi::_MultiDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::MultiDrawElementsIndirect>(src_loc, "MultiDrawElementsIndirect", mode, type, indirect, drawcount, stride);
}

void GLapi::_MultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::MultiDrawElementsIndirectCount>(src_loc, "MultiDrawElementsIndirectCount", mode, type, indirect, drawcount, maxdrawcount, stride);
}

void GLapi::_NamedBufferData(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::NamedBufferData>(src_loc, "NamedBufferData", buffer, size, data, usage);
}

void GLapi::_NamedBufferStorage(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::NamedBufferStorage>(src_loc, "NamedBufferStorage", buffer, size, data, flags);
}

void GLapi::_NamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::NamedBufferSubData>(src_loc, "NamedBufferSubData", buffer, offset, size, data);
}

void GLapi::_NamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::NamedFramebufferDrawBuffer>(src_loc, "NamedFramebufferDrawBuffer", framebuffer, buf);
}

void GLapi::_NamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum* bufs, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::NamedFramebufferDrawBuffers>(src_loc, "NamedFramebufferDrawBuffers", framebuffer, n, bufs);
}

void GLapi::_NamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::NamedFramebufferParameteri>(src_loc, "NamedFramebufferParameteri", framebuffer, pname, param);
}

void GLapi::_NamedFramebufferReadBuffer(GLuint framebuffer, GLenum src, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::NamedFramebufferReadBuffer>(src_loc, "NamedFramebufferReadBuffer", framebuffer, src);
}

void GLapi::_NamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::NamedFramebufferRenderbuffer>(src_loc, "NamedFramebufferRenderbuffer", framebuffer, attachment, renderbuffertarget, renderbuffer);
}

void GLapi::_NamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::NamedFramebufferTexture>(src_loc, "NamedFramebufferTexture", framebuffer, attachment, texture, level);
}

void GLapi::_NamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::NamedFramebufferTextureLayer>(src_loc, "NamedFramebufferTextureLayer", framebuffer, attachment, texture, level, layer);
}

void GLapi::_NamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::NamedRenderbufferStorage>(src_loc, "NamedRenderbufferStorage", renderbuffer, internalformat, width, height);
}

void GLapi::_NamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::NamedRenderbufferStorageMultisample>(src_loc, "NamedRenderbufferStorageMultisample", renderbuffer, samples, internalformat, width, height);
}

void GLapi::_ObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar* label, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ObjectLabel>(src_loc, "ObjectLabel", identifier, name, length, label);
}

void GLapi::_ObjectPtrLabel(const void* ptr, GLsizei length, const GLchar* label, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ObjectPtrLabel>(src_loc, "ObjectPtrLabel", ptr, length, label);
}

void GLapi::_PatchParameterfv(GLenum pname, const GLfloat* values, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::PatchParameterfv>(src_loc, "PatchParameterfv", pname, values);
}

void GLapi::_PatchParameteri(GLenum pname, GLint value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::PatchParameteri>(src_loc, "PatchParameteri", pname, value);
}

void GLapi::_PauseTransformFeedback(const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::PauseTransformFeedback>(src_loc, "PauseTransformFeedback");
}

void GLapi::_PixelStoref(GLenum pname, GLfloat param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::PixelStoref>(src_loc, "PixelStoref", pname, param);
}

void GLapi::_PixelStorei(GLenum pname, GLint param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::PixelStorei>(src_loc, "PixelStorei", pname, param);
}

void GLapi::_PointParameterf(GLenum pname, GLfloat param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::PointParameterf>(src_loc, "PointParameterf", pname, param);
}

void GLapi::_PointParameterfv(GLenum pname, const GLfloat* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::PointParameterfv>(src_loc, "PointParameterfv", pname, params);
}

void GLapi::_PointParameteri(GLenum pname, GLint param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::PointParameteri>(src_loc, "PointParameteri", pname, param);
}

void GLapi::_PointParameteriv(GLenum pname, const GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::PointParameteriv>(src_loc, "PointParameteriv", pname, params);
}

void GLapi::_PointSize(GLfloat size, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::PointSize>(src_loc, "PointSize", size);
}

void GLapi::_PolygonMode(GLenum face, GLenum mode, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::PolygonMode>(src_loc, "PolygonMode", face, mode);
}

void GLapi::_PolygonOffset(GLfloat factor, GLfloat units, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::PolygonOffset>(src_loc, "PolygonOffset", factor, units);
}

void GLapi::_PolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::PolygonOffsetClamp>(src_loc, "PolygonOffsetClamp", factor, units, clamp);
}

void GLapi::_PopDebugGroup(const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::PopDebugGroup>(src_loc, "PopDebugGroup");
}

void GLapi::_PrimitiveRestartIndex(GLuint index, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::PrimitiveRestartIndex>(src_loc, "PrimitiveRestartIndex", index);
}

void GLapi::_ProgramBinary(GLuint program, GLenum binaryFormat, const void* binary, GLsizei length, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramBinary>(src_loc, "ProgramBinary", program, binaryFormat, binary, length);
}

void GLapi::_ProgramParameteri(GLuint program, GLenum pname, GLint value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramParameteri>(src_loc, "ProgramParameteri", program, pname, value);
}

void GLapi::_ProgramUniform1d(GLuint program, GLint location, GLdouble v0, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform1d>(src_loc, "ProgramUniform1d", program, location, v0);
}

void GLapi::_ProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform1dv>(src_loc, "ProgramUniform1dv", program, location, count, value);
}

void GLapi::_ProgramUniform1f(GLuint program, GLint location, GLfloat v0, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform1f>(src_loc, "ProgramUniform1f", program, location, v0);
}

void GLapi::_ProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform1fv>(src_loc, "ProgramUniform1fv", program, location, count, value);
}

void GLapi::_ProgramUniform1i(GLuint program, GLint location, GLint v0, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform1i>(src_loc, "ProgramUniform1i", program, location, v0);
}

void GLapi::_ProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform1iv>(src_loc, "ProgramUniform1iv", program, location, count, value);
}

void GLapi::_ProgramUniform1ui(GLuint program, GLint location, GLuint v0, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform1ui>(src_loc, "ProgramUniform1ui", program, location, v0);
}

void GLapi::_ProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform1uiv>(src_loc, "ProgramUniform1uiv", program, location, count, value);
}

void GLapi::_ProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform2d>(src_loc, "ProgramUniform2d", program, location, v0, v1);
}

void GLapi::_ProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform2dv>(src_loc, "ProgramUniform2dv", program, location, count, value);
}

void GLapi::_ProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform2f>(src_loc, "ProgramUniform2f", program, location, v0, v1);
}

void GLapi::_ProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform2fv>(src_loc, "ProgramUniform2fv", program, location, count, value);
}

void GLapi::_ProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform2i>(src_loc, "ProgramUniform2i", program, location, v0, v1);
}

void GLapi::_ProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform2iv>(src_loc, "ProgramUniform2iv", program, location, count, value);
}

void GLapi::_ProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform2ui>(src_loc, "ProgramUniform2ui", program, location, v0, v1);
}

void GLapi::_ProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform2uiv>(src_loc, "ProgramUniform2uiv", program, location, count, value);
}

void GLapi::_ProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform3d>(src_loc, "ProgramUniform3d", program, location, v0, v1, v2);
}

void GLapi::_ProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform3dv>(src_loc, "ProgramUniform3dv", program, location, count, value);
}

void GLapi::_ProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform3f>(src_loc, "ProgramUniform3f", program, location, v0, v1, v2);
}

void GLapi::_ProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform3fv>(src_loc, "ProgramUniform3fv", program, location, count, value);
}

void GLapi::_ProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform3i>(src_loc, "ProgramUniform3i", program, location, v0, v1, v2);
}

void GLapi::_ProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform3iv>(src_loc, "ProgramUniform3iv", program, location, count, value);
}

void GLapi::_ProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform3ui>(src_loc, "ProgramUniform3ui", program, location, v0, v1, v2);
}

void GLapi::_ProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform3uiv>(src_loc, "ProgramUniform3uiv", program, location, count, value);
}

void GLapi::_ProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform4d>(src_loc, "ProgramUniform4d", program, location, v0, v1, v2, v3);
}

void GLapi::_ProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform4dv>(src_loc, "ProgramUniform4dv", program, location, count, value);
}

void GLapi::_ProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform4f>(src_loc, "ProgramUniform4f", program, location, v0, v1, v2, v3);
}

void GLapi::_ProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform4fv>(src_loc, "ProgramUniform4fv", program, location, count, value);
}

void GLapi::_ProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform4i>(src_loc, "ProgramUniform4i", program, location, v0, v1, v2, v3);
}

void GLapi::_ProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform4iv>(src_loc, "ProgramUniform4iv", program, location, count, value);
}

void GLapi::_ProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform4ui>(src_loc, "ProgramUniform4ui", program, location, v0, v1, v2, v3);
}

void GLapi::_ProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniform4uiv>(src_loc, "ProgramUniform4uiv", program, location, count, value);
}

void GLapi::_ProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix2dv>(src_loc, "ProgramUniformMatrix2dv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix2fv>(src_loc, "ProgramUniformMatrix2fv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix2x3dv>(src_loc, "ProgramUniformMatrix2x3dv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix2x3fv>(src_loc, "ProgramUniformMatrix2x3fv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix2x4dv>(src_loc, "ProgramUniformMatrix2x4dv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix2x4fv>(src_loc, "ProgramUniformMatrix2x4fv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix3dv>(src_loc, "ProgramUniformMatrix3dv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix3fv>(src_loc, "ProgramUniformMatrix3fv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix3x2dv>(src_loc, "ProgramUniformMatrix3x2dv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix3x2fv>(src_loc, "ProgramUniformMatrix3x2fv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix3x4dv>(src_loc, "ProgramUniformMatrix3x4dv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix3x4fv>(src_loc, "ProgramUniformMatrix3x4fv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix4dv>(src_loc, "ProgramUniformMatrix4dv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix4fv>(src_loc, "ProgramUniformMatrix4fv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix4x2dv>(src_loc, "ProgramUniformMatrix4x2dv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix4x2fv>(src_loc, "ProgramUniformMatrix4x2fv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix4x3dv>(src_loc, "ProgramUniformMatrix4x3dv", program, location, count, transpose, value);
}

void GLapi::_ProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProgramUniformMatrix4x3fv>(src_loc, "ProgramUniformMatrix4x3fv", program, location, count, transpose, value);
}

void GLapi::_ProvokingVertex(GLenum mode, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ProvokingVertex>(src_loc, "ProvokingVertex", mode);
}

void GLapi::_PushDebugGroup(GLenum sResource, GLuint id, GLsizei length, const GLchar* message, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::PushDebugGroup>(src_loc, "PushDebugGroup", sResource, id, length, message);
}

void GLapi::_QueryCounter(GLuint id, GLenum target, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::QueryCounter>(src_loc, "QueryCounter", id, target);
}

void GLapi::_ReadBuffer(GLenum src, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ReadBuffer>(src_loc, "ReadBuffer", src);
}

void GLapi::_ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ReadPixels>(src_loc, "ReadPixels", x, y, width, height, format, type, pixels);
}

void GLapi::_ReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ReadnPixels>(src_loc, "ReadnPixels", x, y, width, height, format, type, bufSize, data);
}

void GLapi::_ReleaseShaderCompiler(const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ReleaseShaderCompiler>(src_loc, "ReleaseShaderCompiler");
}

void GLapi::_RenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::RenderbufferStorage>(src_loc, "RenderbufferStorage", target, internalformat, width, height);
}

void GLapi::_RenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::RenderbufferStorageMultisample>(src_loc, "RenderbufferStorageMultisample", target, samples, internalformat, width, height);
}

void GLapi::_ResumeTransformFeedback(const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ResumeTransformFeedback>(src_loc, "ResumeTransformFeedback");
}

void GLapi::_SampleCoverage(GLfloat value, GLboolean invert, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::SampleCoverage>(src_loc, "SampleCoverage", value, invert);
}

void GLapi::_SampleMaski(GLuint maskNumber, GLbitfield mask, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::SampleMaski>(src_loc, "SampleMaski", maskNumber, mask);
}

void GLapi::_SamplerParameterIiv(GLuint sampler, GLenum pname, const GLint* param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::SamplerParameterIiv>(src_loc, "SamplerParameterIiv", sampler, pname, param);
}

void GLapi::_SamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint* param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::SamplerParameterIuiv>(src_loc, "SamplerParameterIuiv", sampler, pname, param);
}

void GLapi::_SamplerParameterf(GLuint sampler, GLenum pname, GLfloat param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::SamplerParameterf>(src_loc, "SamplerParameterf", sampler, pname, param);
}

void GLapi::_SamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat* param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::SamplerParameterfv>(src_loc, "SamplerParameterfv", sampler, pname, param);
}

void GLapi::_SamplerParameteri(GLuint sampler, GLenum pname, GLint param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::SamplerParameteri>(src_loc, "SamplerParameteri", sampler, pname, param);
}

void GLapi::_SamplerParameteriv(GLuint sampler, GLenum pname, const GLint* param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::SamplerParameteriv>(src_loc, "SamplerParameteriv", sampler, pname, param);
}

void GLapi::_Scissor(GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Scissor>(src_loc, "Scissor", x, y, width, height);
}

void GLapi::_ScissorArrayv(GLuint first, GLsizei count, const GLint* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ScissorArrayv>(src_loc, "ScissorArrayv", first, count, v);
}

void GLapi::_ScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ScissorIndexed>(src_loc, "ScissorIndexed", index, left, bottom, width, height);
}

void GLapi::_ScissorIndexedv(GLuint index, const GLint* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ScissorIndexedv>(src_loc, "ScissorIndexedv", index, v);
}

void GLapi::_ShaderSource(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ShaderSource>(src_loc, "ShaderSource", shader, count, string, length);
}

void GLapi::_ShaderBinary(GLsizei count, const GLuint* shaders, GLenum binaryFormat, const void* binary, GLsizei length, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ShaderBinary>(src_loc, "ShaderBinary", count, shaders, binaryFormat, binary, length);
}

void GLapi::_ShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ShaderStorageBlockBinding>(src_loc, "ShaderStorageBlockBinding", program, storageBlockIndex, storageBlockBinding);
}

void GLapi::_SpecializeShader(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::SpecializeShader>(src_loc, "SpecializeShader", shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}

void GLapi::_StencilFunc(GLenum func, GLint ref, GLuint mask, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::StencilFunc>(src_loc, "StencilFunc", func, ref, mask);
}

void GLapi::_StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::StencilFuncSeparate>(src_loc, "StencilFuncSeparate", face, func, ref, mask);
}

void GLapi::_StencilMask(GLuint mask, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::StencilMask>(src_loc, "StencilMask", mask);
}

void GLapi::_StencilMaskSeparate(GLenum face, GLuint mask, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::StencilMaskSeparate>(src_loc, "StencilMaskSeparate", face, mask);
}

void GLapi::_StencilOp(GLenum fail, GLenum zfail, GLenum zpass, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::StencilOp>(src_loc, "StencilOp", fail, zfail, zpass);
}

void GLapi::_StencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::StencilOpSeparate>(src_loc, "StencilOpSeparate", face, sfail, dpfail, dppass);
}

void GLapi::_TexBuffer(GLenum target, GLenum internalformat, GLuint buffer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexBuffer>(src_loc, "TexBuffer", target, internalformat, buffer);
}

void GLapi::_TexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexBufferRange>(src_loc, "TexBufferRange", target, internalformat, buffer, offset, size);
}

void GLapi::_TexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexImage1D>(src_loc, "TexImage1D", target, level, internalformat, width, border, format, type, pixels);
}

void GLapi::_TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexImage2D>(src_loc, "TexImage2D", target, level, internalformat, width, height, border, format, type, pixels);
}

void GLapi::_TexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexImage2DMultisample>(src_loc, "TexImage2DMultisample", target, samples, internalformat, width, height, fixedsamplelocations);
}

void GLapi::_TexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexImage3D>(src_loc, "TexImage3D", target, level, internalformat, width, height, depth, border, format, type, pixels);
}

void GLapi::_TexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexImage3DMultisample>(src_loc, "TexImage3DMultisample", target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void GLapi::_TexParameterIiv(GLenum target, GLenum pname, const GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexParameterIiv>(src_loc, "TexParameterIiv", target, pname, params);
}

void GLapi::_TexParameterIuiv(GLenum target, GLenum pname, const GLuint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexParameterIuiv>(src_loc, "TexParameterIuiv", target, pname, params);
}

void GLapi::_TexParameterf(GLenum target, GLenum pname, GLfloat param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexParameterf>(src_loc, "TexParameterf", target, pname, param);
}

void GLapi::_TexParameterfv(GLenum target, GLenum pname, const GLfloat* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexParameterfv>(src_loc, "TexParameterfv", target, pname, params);
}

void GLapi::_TexParameteri(GLenum target, GLenum pname, GLint param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexParameteri>(src_loc, "TexParameteri", target, pname, param);
}

void GLapi::_TexParameteriv(GLenum target, GLenum pname, const GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexParameteriv>(src_loc, "TexParameteriv", target, pname, params);
}

void GLapi::_TexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexStorage1D>(src_loc, "TexStorage1D", target, levels, internalformat, width);
}

void GLapi::_TexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexStorage2D>(src_loc, "TexStorage2D", target, levels, internalformat, width, height);
}

void GLapi::_TexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexStorage2DMultisample>(src_loc, "TexStorage2DMultisample", target, samples, internalformat, width, height, fixedsamplelocations);
}

void GLapi::_TexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexStorage3D>(src_loc, "TexStorage3D", target, levels, internalformat, width, height, depth);
}

void GLapi::_TexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexStorage3DMultisample>(src_loc, "TexStorage3DMultisample", target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void GLapi::_TexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexSubImage1D>(src_loc, "TexSubImage1D", target, level, xoffset, width, format, type, pixels);
}

void GLapi::_TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexSubImage2D>(src_loc, "TexSubImage2D", target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void GLapi::_TexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TexSubImage3D>(src_loc, "TexSubImage3D", target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void GLapi::_TextureBarrier(const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureBarrier>(src_loc, "TextureBarrier");
}

void GLapi::_TextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureBuffer>(src_loc, "TextureBuffer", texture, internalformat, buffer);
}

void GLapi::_TextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureBufferRange>(src_loc, "TextureBufferRange", texture, internalformat, buffer, offset, size);
}

void GLapi::_TextureParameterIiv(GLuint texture, GLenum pname, const GLint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureParameterIiv>(src_loc, "TextureParameterIiv", texture, pname, params);
}

void GLapi::_TextureParameterIuiv(GLuint texture, GLenum pname, const GLuint* params, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureParameterIuiv>(src_loc, "TextureParameterIuiv", texture, pname, params);
}

void GLapi::_TextureParameterf(GLuint texture, GLenum pname, GLfloat param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureParameterf>(src_loc, "TextureParameterf", texture, pname, param);
}

void GLapi::_TextureParameterfv(GLuint texture, GLenum pname, const GLfloat* param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureParameterfv>(src_loc, "TextureParameterfv", texture, pname, param);
}

void GLapi::_TextureParameteri(GLuint texture, GLenum pname, GLint param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureParameteri>(src_loc, "TextureParameteri", texture, pname, param);
}

void GLapi::_TextureParameteriv(GLuint texture, GLenum pname, const GLint* param, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureParameteriv>(src_loc, "TextureParameteriv", texture, pname, param);
}

void GLapi::_TextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureStorage1D>(src_loc, "TextureStorage1D", texture, levels, internalformat, width);
}

void GLapi::_TextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureStorage2D>(src_loc, "TextureStorage2D", texture, levels, internalformat, width, height);
}

void GLapi::_TextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureStorage2DMultisample>(src_loc, "TextureStorage2DMultisample", texture, samples, internalformat, width, height, fixedsamplelocations);
}

void GLapi::_TextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureStorage3D>(src_loc, "TextureStorage3D", texture, levels, internalformat, width, height, depth);
}

void GLapi::_TextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureStorage3DMultisample>(src_loc, "TextureStorage3DMultisample", texture, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void GLapi::_TextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureSubImage1D>(src_loc, "TextureSubImage1D", texture, level, xoffset, width, format, type, pixels);
}

void GLapi::_TextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureSubImage2D>(src_loc, "TextureSubImage2D", texture, level, xoffset, yoffset, width, height, format, type, pixels);
}

void GLapi::_TextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureSubImage3D>(src_loc, "TextureSubImage3D", texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void GLapi::_TextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TextureView>(src_loc, "TextureView", texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
}

void GLapi::_TransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TransformFeedbackBufferBase>(src_loc, "TransformFeedbackBufferBase", xfb, index, buffer);
}

void GLapi::_TransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::TransformFeedbackBufferRange>(src_loc, "TransformFeedbackBufferRange", xfb, index, buffer, offset, size);
}

void GLapi::_Uniform1d(GLint location, GLdouble x, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform1d>(src_loc, "Uniform1d", location, x);
}

void GLapi::_Uniform1dv(GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform1dv>(src_loc, "Uniform1dv", location, count, value);
}

void GLapi::_Uniform1f(GLint location, GLfloat v0, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform1f>(src_loc, "Uniform1f", location, v0);
}

void GLapi::_Uniform1fv(GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform1fv>(src_loc, "Uniform1fv", location, count, value);
}

void GLapi::_Uniform1i(GLint location, GLint v0, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform1i>(src_loc, "Uniform1i", location, v0);
}

void GLapi::_Uniform1iv(GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform1iv>(src_loc, "Uniform1iv", location, count, value);
}

void GLapi::_Uniform1ui(GLint location, GLuint v0, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform1ui>(src_loc, "Uniform1ui", location, v0);
}

void GLapi::_Uniform1uiv(GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform1uiv>(src_loc, "Uniform1uiv", location, count, value);
}

void GLapi::_Uniform2d(GLint location, GLdouble x, GLdouble y, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform2d>(src_loc, "Uniform2d", location, x, y);
}

void GLapi::_Uniform2dv(GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform2dv>(src_loc, "Uniform2dv", location, count, value);
}

void GLapi::_Uniform2f(GLint location, GLfloat v0, GLfloat v1, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform2f>(src_loc, "Uniform2f", location, v0, v1);
}

void GLapi::_Uniform2fv(GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform2fv>(src_loc, "Uniform2fv", location, count, value);
}

void GLapi::_Uniform2i(GLint location, GLint v0, GLint v1, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform2i>(src_loc, "Uniform2i", location, v0, v1);
}

void GLapi::_Uniform2iv(GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform2iv>(src_loc, "Uniform2iv", location, count, value);
}

void GLapi::_Uniform2ui(GLint location, GLuint v0, GLuint v1, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform2ui>(src_loc, "Uniform2ui", location, v0, v1);
}

void GLapi::_Uniform2uiv(GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform2uiv>(src_loc, "Uniform2uiv", location, count, value);
}

void GLapi::_Uniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform3d>(src_loc, "Uniform3d", location, x, y, z);
}

void GLapi::_Uniform3dv(GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform3dv>(src_loc, "Uniform3dv", location, count, value);
}

void GLapi::_Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform3f>(src_loc, "Uniform3f", location, v0, v1, v2);
}

void GLapi::_Uniform3fv(GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform3fv>(src_loc, "Uniform3fv", location, count, value);
}

void GLapi::_Uniform3i(GLint location, GLint v0, GLint v1, GLint v2, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform3i>(src_loc, "Uniform3i", location, v0, v1, v2);
}

void GLapi::_Uniform3iv(GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform3iv>(src_loc, "Uniform3iv", location, count, value);
}

void GLapi::_Uniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform3ui>(src_loc, "Uniform3ui", location, v0, v1, v2);
}

void GLapi::_Uniform3uiv(GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform3uiv>(src_loc, "Uniform3uiv", location, count, value);
}

void GLapi::_Uniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform4d>(src_loc, "Uniform4d", location, x, y, z, w);
}

void GLapi::_Uniform4dv(GLint location, GLsizei count, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform4dv>(src_loc, "Uniform4dv", location, count, value);
}

void GLapi::_Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform4f>(src_loc, "Uniform4f", location, v0, v1, v2, v3);
}

void GLapi::_Uniform4fv(GLint location, GLsizei count, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform4fv>(src_loc, "Uniform4fv", location, count, value);
}

void GLapi::_Uniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform4i>(src_loc, "Uniform4i", location, v0, v1, v2, v3);
}

void GLapi::_Uniform4iv(GLint location, GLsizei count, const GLint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform4iv>(src_loc, "Uniform4iv", location, count, value);
}

void GLapi::_Uniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform4ui>(src_loc, "Uniform4ui", location, v0, v1, v2, v3);
}

void GLapi::_Uniform4uiv(GLint location, GLsizei count, const GLuint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Uniform4uiv>(src_loc, "Uniform4uiv", location, count, value);
}

void GLapi::_UniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformBlockBinding>(src_loc, "UniformBlockBinding", program, uniformBlockIndex, uniformBlockBinding);
}

void GLapi::_UniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix2dv>(src_loc, "UniformMatrix2dv", location, count, transpose, value);
}

void GLapi::_UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix2fv>(src_loc, "UniformMatrix2fv", location, count, transpose, value);
}

void GLapi::_UniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix2x3dv>(src_loc, "UniformMatrix2x3dv", location, count, transpose, value);
}

void GLapi::_UniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix2x3fv>(src_loc, "UniformMatrix2x3fv", location, count, transpose, value);
}

void GLapi::_UniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix2x4dv>(src_loc, "UniformMatrix2x4dv", location, count, transpose, value);
}

void GLapi::_UniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix2x4fv>(src_loc, "UniformMatrix2x4fv", location, count, transpose, value);
}

void GLapi::_UniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix3dv>(src_loc, "UniformMatrix3dv", location, count, transpose, value);
}

void GLapi::_UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix3fv>(src_loc, "UniformMatrix3fv", location, count, transpose, value);
}

void GLapi::_UniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix3x2dv>(src_loc, "UniformMatrix3x2dv", location, count, transpose, value);
}

void GLapi::_UniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix3x2fv>(src_loc, "UniformMatrix3x2fv", location, count, transpose, value);
}

void GLapi::_UniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix3x4dv>(src_loc, "UniformMatrix3x4dv", location, count, transpose, value);
}

void GLapi::_UniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix3x4fv>(src_loc, "UniformMatrix3x4fv", location, count, transpose, value);
}

void GLapi::_UniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix4dv>(src_loc, "UniformMatrix4dv", location, count, transpose, value);
}

void GLapi::_UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix4fv>(src_loc, "UniformMatrix4fv", location, count, transpose, value);
}

void GLapi::_UniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix4x2dv>(src_loc, "UniformMatrix4x2dv", location, count, transpose, value);
}

void GLapi::_UniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix4x2fv>(src_loc, "UniformMatrix4x2fv", location, count, transpose, value);
}

void GLapi::_UniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix4x3dv>(src_loc, "UniformMatrix4x3dv", location, count, transpose, value);
}

void GLapi::_UniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformMatrix4x3fv>(src_loc, "UniformMatrix4x3fv", location, count, transpose, value);
}

void GLapi::_UniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint* indices, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UniformSubroutinesuiv>(src_loc, "UniformSubroutinesuiv", shadertype, count, indices);
}

GLboolean GLapi::_UnmapBuffer(GLenum target, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UnmapBuffer>(src_loc, "UnmapBuffer", target);
}

GLboolean GLapi::_UnmapNamedBuffer(GLuint buffer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UnmapNamedBuffer>(src_loc, "UnmapNamedBuffer", buffer);
}

void GLapi::_UseProgram(GLuint program, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UseProgram>(src_loc, "UseProgram", program);
}

void GLapi::_UseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::UseProgramStages>(src_loc, "UseProgramStages", pipeline, stages, program);
}

void GLapi::_ValidateProgram(GLuint program, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ValidateProgram>(src_loc, "ValidateProgram", program);
}

void GLapi::_ValidateProgramPipeline(GLuint pipeline, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ValidateProgramPipeline>(src_loc, "ValidateProgramPipeline", pipeline);
}

void GLapi::_VertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexArrayAttribBinding>(src_loc, "VertexArrayAttribBinding", vaobj, attribindex, bindingindex);
}

void GLapi::_VertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexArrayAttribFormat>(src_loc, "VertexArrayAttribFormat", vaobj, attribindex, size, type, normalized, relativeoffset);
}

void GLapi::_VertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexArrayAttribIFormat>(src_loc, "VertexArrayAttribIFormat", vaobj, attribindex, size, type, relativeoffset);
}

void GLapi::_VertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexArrayAttribLFormat>(src_loc, "VertexArrayAttribLFormat", vaobj, attribindex, size, type, relativeoffset);
}

void GLapi::_VertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexArrayBindingDivisor>(src_loc, "VertexArrayBindingDivisor", vaobj, bindingindex, divisor);
}

void GLapi::_VertexArrayElementBuffer(GLuint vaobj, GLuint buffer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexArrayElementBuffer>(src_loc, "VertexArrayElementBuffer", vaobj, buffer);
}

void GLapi::_VertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexArrayVertexBuffer>(src_loc, "VertexArrayVertexBuffer", vaobj, bindingindex, buffer, offset, stride);
}

void GLapi::_VertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexArrayVertexBuffers>(src_loc, "VertexArrayVertexBuffers", vaobj, first, count, buffers, offsets, strides);
}

void GLapi::_VertexAttrib1d(GLuint index, GLdouble x, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib1d>(src_loc, "VertexAttrib1d", index, x);
}

void GLapi::_VertexAttrib1dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib1dv>(src_loc, "VertexAttrib1dv", index, v);
}

void GLapi::_VertexAttrib1f(GLuint index, GLfloat x, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib1f>(src_loc, "VertexAttrib1f", index, x);
}

void GLapi::_VertexAttrib1fv(GLuint index, const GLfloat* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib1fv>(src_loc, "VertexAttrib1fv", index, v);
}

void GLapi::_VertexAttrib1s(GLuint index, GLshort x, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib1s>(src_loc, "VertexAttrib1s", index, x);
}

void GLapi::_VertexAttrib1sv(GLuint index, const GLshort* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib1sv>(src_loc, "VertexAttrib1sv", index, v);
}

void GLapi::_VertexAttrib2d(GLuint index, GLdouble x, GLdouble y, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib2d>(src_loc, "VertexAttrib2d", index, x, y);
}

void GLapi::_VertexAttrib2dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib2dv>(src_loc, "VertexAttrib2dv", index, v);
}

void GLapi::_VertexAttrib2f(GLuint index, GLfloat x, GLfloat y, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib2f>(src_loc, "VertexAttrib2f", index, x, y);
}

void GLapi::_VertexAttrib2fv(GLuint index, const GLfloat* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib2fv>(src_loc, "VertexAttrib2fv", index, v);
}

void GLapi::_VertexAttrib2s(GLuint index, GLshort x, GLshort y, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib2s>(src_loc, "VertexAttrib2s", index, x, y);
}

void GLapi::_VertexAttrib2sv(GLuint index, const GLshort* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib2sv>(src_loc, "VertexAttrib2sv", index, v);
}

void GLapi::_VertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib3d>(src_loc, "VertexAttrib3d", index, x, y, z);
}

void GLapi::_VertexAttrib3dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib3dv>(src_loc, "VertexAttrib3dv", index, v);
}

void GLapi::_VertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib3f>(src_loc, "VertexAttrib3f", index, x, y, z);
}

void GLapi::_VertexAttrib3fv(GLuint index, const GLfloat* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib3fv>(src_loc, "VertexAttrib3fv", index, v);
}

void GLapi::_VertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib3s>(src_loc, "VertexAttrib3s", index, x, y, z);
}

void GLapi::_VertexAttrib3sv(GLuint index, const GLshort* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib3sv>(src_loc, "VertexAttrib3sv", index, v);
}

void GLapi::_VertexAttrib4Nbv(GLuint index, const GLbyte* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4Nbv>(src_loc, "VertexAttrib4Nbv", index, v);
}

void GLapi::_VertexAttrib4Niv(GLuint index, const GLint* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4Niv>(src_loc, "VertexAttrib4Niv", index, v);
}

void GLapi::_VertexAttrib4Nsv(GLuint index, const GLshort* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4Nsv>(src_loc, "VertexAttrib4Nsv", index, v);
}

void GLapi::_VertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4Nub>(src_loc, "VertexAttrib4Nub", index, x, y, z, w);
}

void GLapi::_VertexAttrib4Nubv(GLuint index, const GLubyte* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4Nubv>(src_loc, "VertexAttrib4Nubv", index, v);
}

void GLapi::_VertexAttrib4Nuiv(GLuint index, const GLuint* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4Nuiv>(src_loc, "VertexAttrib4Nuiv", index, v);
}

void GLapi::_VertexAttrib4Nusv(GLuint index, const GLushort* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4Nusv>(src_loc, "VertexAttrib4Nusv", index, v);
}

void GLapi::_VertexAttrib4bv(GLuint index, const GLbyte* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4bv>(src_loc, "VertexAttrib4bv", index, v);
}

void GLapi::_VertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4d>(src_loc, "VertexAttrib4d", index, x, y, z, w);
}

void GLapi::_VertexAttrib4dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4dv>(src_loc, "VertexAttrib4dv", index, v);
}

void GLapi::_VertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4f>(src_loc, "VertexAttrib4f", index, x, y, z, w);
}

void GLapi::_VertexAttrib4fv(GLuint index, const GLfloat* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4fv>(src_loc, "VertexAttrib4fv", index, v);
}

void GLapi::_VertexAttrib4iv(GLuint index, const GLint* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4iv>(src_loc, "VertexAttrib4iv", index, v);
}

void GLapi::_VertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4s>(src_loc, "VertexAttrib4s", index, x, y, z, w);
}

void GLapi::_VertexAttrib4sv(GLuint index, const GLshort* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4sv>(src_loc, "VertexAttrib4sv", index, v);
}

void GLapi::_VertexAttrib4ubv(GLuint index, const GLubyte* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4ubv>(src_loc, "VertexAttrib4ubv", index, v);
}

void GLapi::_VertexAttrib4uiv(GLuint index, const GLuint* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4uiv>(src_loc, "VertexAttrib4uiv", index, v);
}

void GLapi::_VertexAttrib4usv(GLuint index, const GLushort* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttrib4usv>(src_loc, "VertexAttrib4usv", index, v);
}

void GLapi::_VertexAttribBinding(GLuint attribindex, GLuint bindingindex, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribBinding>(src_loc, "VertexAttribBinding", attribindex, bindingindex);
}

void GLapi::_VertexAttribDivisor(GLuint index, GLuint divisor, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribDivisor>(src_loc, "VertexAttribDivisor", index, divisor);
}

void GLapi::_VertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribFormat>(src_loc, "VertexAttribFormat", attribindex, size, type, normalized, relativeoffset);
}

void GLapi::_VertexAttribI1i(GLuint index, GLint x, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI1i>(src_loc, "VertexAttribI1i", index, x);
}

void GLapi::_VertexAttribI1iv(GLuint index, const GLint* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI1iv>(src_loc, "VertexAttribI1iv", index, v);
}

void GLapi::_VertexAttribI1ui(GLuint index, GLuint x, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI1ui>(src_loc, "VertexAttribI1ui", index, x);
}

void GLapi::_VertexAttribI1uiv(GLuint index, const GLuint* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI1uiv>(src_loc, "VertexAttribI1uiv", index, v);
}

void GLapi::_VertexAttribI2i(GLuint index, GLint x, GLint y, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI2i>(src_loc, "VertexAttribI2i", index, x, y);
}

void GLapi::_VertexAttribI2iv(GLuint index, const GLint* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI2iv>(src_loc, "VertexAttribI2iv", index, v);
}

void GLapi::_VertexAttribI2ui(GLuint index, GLuint x, GLuint y, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI2ui>(src_loc, "VertexAttribI2ui", index, x, y);
}

void GLapi::_VertexAttribI2uiv(GLuint index, const GLuint* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI2uiv>(src_loc, "VertexAttribI2uiv", index, v);
}

void GLapi::_VertexAttribI3i(GLuint index, GLint x, GLint y, GLint z, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI3i>(src_loc, "VertexAttribI3i", index, x, y, z);
}

void GLapi::_VertexAttribI3iv(GLuint index, const GLint* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI3iv>(src_loc, "VertexAttribI3iv", index, v);
}

void GLapi::_VertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI3ui>(src_loc, "VertexAttribI3ui", index, x, y, z);
}

void GLapi::_VertexAttribI3uiv(GLuint index, const GLuint* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI3uiv>(src_loc, "VertexAttribI3uiv", index, v);
}

void GLapi::_VertexAttribI4bv(GLuint index, const GLbyte* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI4bv>(src_loc, "VertexAttribI4bv", index, v);
}

void GLapi::_VertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI4i>(src_loc, "VertexAttribI4i", index, x, y, z, w);
}

void GLapi::_VertexAttribI4iv(GLuint index, const GLint* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI4iv>(src_loc, "VertexAttribI4iv", index, v);
}

void GLapi::_VertexAttribI4sv(GLuint index, const GLshort* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI4sv>(src_loc, "VertexAttribI4sv", index, v);
}

void GLapi::_VertexAttribI4ubv(GLuint index, const GLubyte* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI4ubv>(src_loc, "VertexAttribI4ubv", index, v);
}

void GLapi::_VertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI4ui>(src_loc, "VertexAttribI4ui", index, x, y, z, w);
}

void GLapi::_VertexAttribI4uiv(GLuint index, const GLuint* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI4uiv>(src_loc, "VertexAttribI4uiv", index, v);
}

void GLapi::_VertexAttribI4usv(GLuint index, const GLushort* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribI4usv>(src_loc, "VertexAttribI4usv", index, v);
}

void GLapi::_VertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribIFormat>(src_loc, "VertexAttribIFormat", attribindex, size, type, relativeoffset);
}

void GLapi::_VertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribIPointer>(src_loc, "VertexAttribIPointer", index, size, type, stride, pointer);
}

void GLapi::_VertexAttribL1d(GLuint index, GLdouble x, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribL1d>(src_loc, "VertexAttribL1d", index, x);
}

void GLapi::_VertexAttribL1dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribL1dv>(src_loc, "VertexAttribL1dv", index, v);
}

void GLapi::_VertexAttribL2d(GLuint index, GLdouble x, GLdouble y, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribL2d>(src_loc, "VertexAttribL2d", index, x, y);
}

void GLapi::_VertexAttribL2dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribL2dv>(src_loc, "VertexAttribL2dv", index, v);
}

void GLapi::_VertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribL3d>(src_loc, "VertexAttribL3d", index, x, y, z);
}

void GLapi::_VertexAttribL3dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribL3dv>(src_loc, "VertexAttribL3dv", index, v);
}

void GLapi::_VertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribL4d>(src_loc, "VertexAttribL4d", index, x, y, z, w);
}

void GLapi::_VertexAttribL4dv(GLuint index, const GLdouble* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribL4dv>(src_loc, "VertexAttribL4dv", index, v);
}

void GLapi::_VertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribLFormat>(src_loc, "VertexAttribLFormat", attribindex, size, type, relativeoffset);
}

void GLapi::_VertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribLPointer>(src_loc, "VertexAttribLPointer", index, size, type, stride, pointer);
}

void GLapi::_VertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribP1ui>(src_loc, "VertexAttribP1ui", index, type, normalized, value);
}

void GLapi::_VertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribP1uiv>(src_loc, "VertexAttribP1uiv", index, type, normalized, value);
}

void GLapi::_VertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribP2ui>(src_loc, "VertexAttribP2ui", index, type, normalized, value);
}

void GLapi::_VertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribP2uiv>(src_loc, "VertexAttribP2uiv", index, type, normalized, value);
}

void GLapi::_VertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribP3ui>(src_loc, "VertexAttribP3ui", index, type, normalized, value);
}

void GLapi::_VertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribP3uiv>(src_loc, "VertexAttribP3uiv", index, type, normalized, value);
}

void GLapi::_VertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribP4ui>(src_loc, "VertexAttribP4ui", index, type, normalized, value);
}

void GLapi::_VertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribP4uiv>(src_loc, "VertexAttribP4uiv", index, type, normalized, value);
}

void GLapi::_VertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexAttribPointer>(src_loc, "VertexAttribPointer", index, size, type, normalized, stride, pointer);
}

void GLapi::_VertexBindingDivisor(GLuint bindingindex, GLuint divisor, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::VertexBindingDivisor>(src_loc, "VertexBindingDivisor", bindingindex, divisor);
}

void GLapi::_Viewport(GLint x, GLint y, GLsizei width, GLsizei height, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::Viewport>(src_loc, "Viewport", x, y, width, height);
}

void GLapi::_ViewportArrayv(GLuint first, GLsizei count, const GLfloat* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ViewportArrayv>(src_loc, "ViewportArrayv", first, count, v);
}

void GLapi::_ViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ViewportIndexedf>(src_loc, "ViewportIndexedf", index, x, y, w, h);
}

void GLapi::_ViewportIndexedfv(GLuint index, const GLfloat* v, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::ViewportIndexedfv>(src_loc, "ViewportIndexedfv", index, v);
}

void GLapi::_WaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, const SrcLoc& src_loc) const {
    return _implCall<&GLapiImpl::WaitSync>(src_loc, "WaitSync", sync, flags, timeout);
}