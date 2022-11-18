#include "gl/GlIndirect.hpp"

#include <iostream>
#include "glad/gl.h"

#include "Context.hpp"

using namespace glwpp;
using namespace GL;

template<auto F, typename ... Args>
auto GlIndirect::_callGL(Args... args){
    using R = std::invoke_result_t<decltype(F), Gl, Args...>;

    if constexpr (std::is_same_v<R, void>){
        _ctx->getOnRunEvent().addActionQueued([args...](Context* ctx, const Context::ms&){
            (ctx->gl<Context::IsGlThread::True>().*F)(args...);
            return false;
        });
    } else {
        R result;
        _ctx->getOnRunEvent().addActionQueued([result, args...](Context* ctx, const Context::ms&){
            *result = *(ctx->gl<Context::IsGlThread::True>().*F)(args...);
            return false;
        });
        return result;
    }
}

GlIndirect::GlIndirect(Context& ctx, const std::function<void(const SrcLoc&)>& debug) :
    Gl(debug),
    _ctx(&ctx){
}

GlIndirect::~GlIndirect(){
}

void GlIndirect::debug(const SrcLoc& src_loc){
#ifdef GLWPP_DEBUG
    _callGL<&Gl::debug>(src_loc);
#endif
}

void GlIndirect::callSimple(const std::function<void(Gl&)>& func){
    _ctx->getOnRunEvent().addActionQueued([func](Context* ctx){
        func(ctx->gl<Context::IsGlThread::True>());
        return false;
    });
}

void GlIndirect::ActiveShaderProgram(const GLuint& pipeline, const GLuint& program, const SrcLoc& src_loc){
    return _callGL<&Gl::ActiveShaderProgram>(pipeline, program, src_loc);
}

void GlIndirect::ActiveTexture(const GLenum& texture, const SrcLoc& src_loc){
    return _callGL<&Gl::ActiveTexture>(texture, src_loc);
}

void GlIndirect::AttachShader(const GLuint& program, const GLuint& shader, const SrcLoc& src_loc){
    return _callGL<&Gl::AttachShader>(program, shader, src_loc);
}

void GlIndirect::BeginConditionalRender(const GLuint& id, const GLenum& mode, const SrcLoc& src_loc){
    return _callGL<&Gl::BeginConditionalRender>(id, mode, src_loc);
}

void GlIndirect::BeginQuery(const GLenum& target, const GLuint& id, const SrcLoc& src_loc){
    return _callGL<&Gl::BeginQuery>(target, id, src_loc);
}

void GlIndirect::BeginQueryIndexed(const GLenum& target, const GLuint& index, const GLuint& id, const SrcLoc& src_loc){
    return _callGL<&Gl::BeginQueryIndexed>(target, index, id, src_loc);
}

void GlIndirect::BeginTransformFeedback(const GLenum& primitiveMode, const SrcLoc& src_loc){
    return _callGL<&Gl::BeginTransformFeedback>(primitiveMode, src_loc);
}

void GlIndirect::BindAttribLocation(const GLuint& program, const GLuint& index, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::BindAttribLocation>(program, index, name, src_loc);
}

void GlIndirect::BindBuffer(const GLenum& target, const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::BindBuffer>(target, buffer, src_loc);
}

void GlIndirect::BindBufferBase(const GLenum& target, const GLuint& index, const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::BindBufferBase>(target, index, buffer, src_loc);
}

void GlIndirect::BindBufferRange(const GLenum& target, const GLuint& index, const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&Gl::BindBufferRange>(target, index, buffer, offset, size, src_loc);
}

void GlIndirect::BindBuffersBase(const GLenum& target, const GLuint& first, const GLsizei& count, const GLuintArr& buffers, const SrcLoc& src_loc){
    return _callGL<&Gl::BindBuffersBase>(target, first, count, buffers, src_loc);
}

void GlIndirect::BindBuffersRange(const GLenum& target, const GLuint& first, const GLsizei& count, const GLuintArr& buffers, const GLintptrArr& offsets, const GLsizeiptrArr& sizes, const SrcLoc& src_loc){
    return _callGL<&Gl::BindBuffersRange>(target, first, count, buffers, offsets, sizes, src_loc);
}

void GlIndirect::BindFragDataLocation(const GLuint& program, const GLuint& color, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::BindFragDataLocation>(program, color, name, src_loc);
}

void GlIndirect::BindFragDataLocationIndexed(const GLuint& program, const GLuint& colorNumber, const GLuint& index, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::BindFragDataLocationIndexed>(program, colorNumber, index, name, src_loc);
}

void GlIndirect::BindFramebuffer(const GLenum& target, const GLuint& framebuffer, const SrcLoc& src_loc){
    return _callGL<&Gl::BindFramebuffer>(target, framebuffer, src_loc);
}

void GlIndirect::BindImageTexture(const GLuint& unit, const GLuint& texture, const GLint& level, const GLboolean& layered, const GLint& layer, const GLenum& access, const GLenum& format, const SrcLoc& src_loc){
    return _callGL<&Gl::BindImageTexture>(unit, texture, level, layered, layer, access, format, src_loc);
}

void GlIndirect::BindImageTextures(const GLuint& first, const GLsizei& count, const GLuintArr& textures, const SrcLoc& src_loc){
    return _callGL<&Gl::BindImageTextures>(first, count, textures, src_loc);
}

void GlIndirect::BindProgramPipeline(const GLuint& pipeline, const SrcLoc& src_loc){
    return _callGL<&Gl::BindProgramPipeline>(pipeline, src_loc);
}

void GlIndirect::BindRenderbuffer(const GLenum& target, const GLuint& renderbuffer, const SrcLoc& src_loc){
    return _callGL<&Gl::BindRenderbuffer>(target, renderbuffer, src_loc);
}

void GlIndirect::BindSampler(const GLuint& unit, const GLuint& sampler, const SrcLoc& src_loc){
    return _callGL<&Gl::BindSampler>(unit, sampler, src_loc);
}

void GlIndirect::BindSamplers(const GLuint& first, const GLsizei& count, const GLuintArr& samplers, const SrcLoc& src_loc){
    return _callGL<&Gl::BindSamplers>(first, count, samplers, src_loc);
}

void GlIndirect::BindTexture(const GLenum& target, const GLuint& texture, const SrcLoc& src_loc){
    return _callGL<&Gl::BindTexture>(target, texture, src_loc);
}

void GlIndirect::BindTextureUnit(const GLuint& unit, const GLuint& texture, const SrcLoc& src_loc){
    return _callGL<&Gl::BindTextureUnit>(unit, texture, src_loc);
}

void GlIndirect::BindTextures(const GLuint& first, const GLsizei& count, const GLuintArr& textures, const SrcLoc& src_loc){
    return _callGL<&Gl::BindTextures>(first, count, textures, src_loc);
}

void GlIndirect::BindTransformFeedback(const GLenum& target, const GLuint& id, const SrcLoc& src_loc){
    return _callGL<&Gl::BindTransformFeedback>(target, id, src_loc);
}

void GlIndirect::BindVertexArray(const GLuint& array, const SrcLoc& src_loc){
    return _callGL<&Gl::BindVertexArray>(array, src_loc);
}

void GlIndirect::BindVertexBuffer(const GLuint& bindingindex, const GLuint& buffer, const GLintptr& offset, const GLsizei& stride, const SrcLoc& src_loc){
    return _callGL<&Gl::BindVertexBuffer>(bindingindex, buffer, offset, stride, src_loc);
}

void GlIndirect::BindVertexBuffers(const GLuint& first, const GLsizei& count, const GLuintArr& buffers, const GLintptrArr& offsets, const GLsizeiArr& strides, const SrcLoc& src_loc){
    return _callGL<&Gl::BindVertexBuffers>(first, count, buffers, offsets, strides, src_loc);
}

void GlIndirect::BlendColor(const GLfloat& red, const GLfloat& green, const GLfloat& blue, const GLfloat& alpha, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendColor>(red, green, blue, alpha, src_loc);
}

void GlIndirect::BlendEquation(const GLenum& mode, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendEquation>(mode, src_loc);
}

void GlIndirect::BlendEquationSeparate(const GLenum& modeRGB, const GLenum& modeAlpha, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendEquationSeparate>(modeRGB, modeAlpha, src_loc);
}

void GlIndirect::BlendEquationSeparatei(const GLuint& buf, const GLenum& modeRGB, const GLenum& modeAlpha, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendEquationSeparatei>(buf, modeRGB, modeAlpha, src_loc);
}

void GlIndirect::BlendEquationi(const GLuint& buf, const GLenum& mode, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendEquationi>(buf, mode, src_loc);
}

void GlIndirect::BlendFunc(const GLenum& sfactor, const GLenum& dfactor, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendFunc>(sfactor, dfactor, src_loc);
}

void GlIndirect::BlendFuncSeparate(const GLenum& sfactorRGB, const GLenum& dfactorRGB, const GLenum& sfactorAlpha, const GLenum& dfactorAlpha, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendFuncSeparate>(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha, src_loc);
}

void GlIndirect::BlendFuncSeparatei(const GLuint& buf, const GLenum& srcRGB, const GLenum& dstRGB, const GLenum& srcAlpha, const GLenum& dstAlpha, const GLenum& modeAlpha, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendFuncSeparatei>(buf, srcRGB, dstRGB, srcAlpha, dstAlpha, modeAlpha, src_loc);
}

void GlIndirect::BlendFunci(const GLuint& buf, const GLenum& src, const GLenum& dst, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendFunci>(buf, src, dst, src_loc);
}

void GlIndirect::BlitFramebuffer(const GLint& srcX0, const GLint& srcY0, const GLint& srcX1, const GLint& srcY1, const GLint& dstX0, const GLint& dstY0, const GLint& dstX1, const GLint& dstY1, const GLbitfield& mask, const GLenum& filter, const SrcLoc& src_loc){
    return _callGL<&Gl::BlitFramebuffer>(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter, src_loc);
}

void GlIndirect::BlitNamedFramebuffer(const GLuint& readFramebuffer, const GLuint& drawFramebuffer, const GLint& srcX0, const GLint& srcY0, const GLint& srcX1, const GLint& srcY1, const GLint& dstX0, const GLint& dstY0, const GLint& dstX1, const GLint& dstY1, const GLbitfield& mask, const GLenum& filter, const SrcLoc& src_loc){
    return _callGL<&Gl::BlitNamedFramebuffer>(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter, src_loc);
}

void GlIndirect::BufferData(const GLenum& target, const GLsizeiptr& size, const GLdata& data, const GLenum& usage, const SrcLoc& src_loc){
    return _callGL<&Gl::BufferData>(target, size, data, usage, src_loc);
}

void GlIndirect::BufferStorage(const GLenum& target, const GLsizeiptr& size, const GLdata& data, const GLbitfield& flags, const SrcLoc& src_loc){
    return _callGL<&Gl::BufferStorage>(target, size, data, flags, src_loc);
}

void GlIndirect::BufferSubData(const GLenum& target, const GLintptr& offset, const GLsizeiptr& size, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::BufferSubData>(target, offset, size, data, src_loc);
}

GL::GLenum GlIndirect::CheckFramebufferStatus(const GLenum& target, const SrcLoc& src_loc){
    return _callGL<&Gl::CheckFramebufferStatus>(target, src_loc);
}

GL::GLenum GlIndirect::CheckNamedFramebufferStatus(const GLuint& framebuffer, const GLenum& target, const SrcLoc& src_loc){
    return _callGL<&Gl::CheckNamedFramebufferStatus>(framebuffer, target, src_loc);
}

void GlIndirect::ClampColor(const GLenum& target, const GLenum& clamp, const SrcLoc& src_loc){
    return _callGL<&Gl::ClampColor>(target, clamp, src_loc);
}

void GlIndirect::Clear(const GLbitfield& mask, const SrcLoc& src_loc){
    return _callGL<&Gl::Clear>(mask, src_loc);
}

void GlIndirect::ClearBufferData(const GLenum& target, const GLenum& internalformat, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearBufferData>(target, internalformat, format, type, data, src_loc);
}

void GlIndirect::ClearBufferSubData(const GLenum& target, const GLenum& internalformat, const GLintptr& offset, const GLsizeiptr& size, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearBufferSubData>(target, internalformat, offset, size, format, type, data, src_loc);
}

void GlIndirect::ClearBufferfi(const GLenum& buffer, const GLint& drawbuffer, const GLfloat& depth, const GLint& stencil, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearBufferfi>(buffer, drawbuffer, depth, stencil, src_loc);
}

void GlIndirect::ClearBufferfv(const GLenum& buffer, const GLint& drawbuffer, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearBufferfv>(buffer, drawbuffer, value, src_loc);
}

void GlIndirect::ClearBufferiv(const GLenum& buffer, const GLint& drawbuffer, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearBufferiv>(buffer, drawbuffer, value, src_loc);
}

void GlIndirect::ClearBufferuiv(const GLenum& buffer, const GLint& drawbuffer, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearBufferuiv>(buffer, drawbuffer, value, src_loc);
}

void GlIndirect::ClearColor(const GLfloat& red, const GLfloat& green, const GLfloat& blue, const GLfloat& alpha, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearColor>(red, green, blue, alpha, src_loc);
}

void GlIndirect::ClearDepth(const GLdouble& depth, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearDepth>(depth, src_loc);
}

void GlIndirect::ClearDepthf(const GLfloat& d, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearDepthf>(d, src_loc);
}

void GlIndirect::ClearNamedBufferData(const GLuint& buffer, const GLenum& internalformat, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearNamedBufferData>(buffer, internalformat, format, type, data, src_loc);
}

void GlIndirect::ClearNamedBufferSubData(const GLuint& buffer, const GLenum& internalformat, const GLintptr& offset, const GLsizeiptr& size, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearNamedBufferSubData>(buffer, internalformat, offset, size, format, type, data, src_loc);
}

void GlIndirect::ClearNamedFramebufferfi(const GLuint& framebuffer, const GLenum& buffer, const GLint& drawbuffer, const GLfloat& depth, const GLint& stencil, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearNamedFramebufferfi>(framebuffer, buffer, drawbuffer, depth, stencil, src_loc);
}

void GlIndirect::ClearNamedFramebufferfv(const GLuint& framebuffer, const GLenum& buffer, const GLint& drawbuffer, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearNamedFramebufferfv>(framebuffer, buffer, drawbuffer, value, src_loc);
}

void GlIndirect::ClearNamedFramebufferiv(const GLuint& framebuffer, const GLenum& buffer, const GLint& drawbuffer, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearNamedFramebufferiv>(framebuffer, buffer, drawbuffer, value, src_loc);
}

void GlIndirect::ClearNamedFramebufferuiv(const GLuint& framebuffer, const GLenum& buffer, const GLint& drawbuffer, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearNamedFramebufferuiv>(framebuffer, buffer, drawbuffer, value, src_loc);
}

void GlIndirect::ClearStencil(const GLint& s, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearStencil>(s, src_loc);
}

void GlIndirect::ClearTexImage(const GLuint& texture, const GLint& level, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearTexImage>(texture, level, format, type, data, src_loc);
}

void GlIndirect::ClearTexSubImage(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearTexSubImage>(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data, src_loc);
}

GL::GLenum GlIndirect::ClientWaitSync(const GLsync& sync, const GLbitfield& flags, const GLuint64& timeout, const SrcLoc& src_loc){
    return _callGL<&Gl::ClientWaitSync>(sync, flags, timeout, src_loc);
}

void GlIndirect::ClipControl(const GLenum& origin, const GLenum& depth, const SrcLoc& src_loc){
    return _callGL<&Gl::ClipControl>(origin, depth, src_loc);
}

void GlIndirect::ColorMask(const GLboolean& red, const GLboolean& green, const GLboolean& blue, const GLboolean& alpha, const SrcLoc& src_loc){
    return _callGL<&Gl::ColorMask>(red, green, blue, alpha, src_loc);
}

void GlIndirect::ColorMaski(const GLuint& index, const GLboolean& r, const GLboolean& g, const GLboolean& b, const GLboolean& a, const SrcLoc& src_loc){
    return _callGL<&Gl::ColorMaski>(index, r, g, b, a, src_loc);
}

void GlIndirect::CompileShader(const GLuint& shader, const SrcLoc& src_loc){
    return _callGL<&Gl::CompileShader>(shader, src_loc);
}

void GlIndirect::CompressedTexImage1D(const GLenum& target, const GLint& level, const GLenum& internalformat, const GLsizei& width, const GLint& border, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTexImage1D>(target, level, internalformat, width, border, imageSize, data, src_loc);
}

void GlIndirect::CompressedTexImage2D(const GLenum& target, const GLint& level, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLint& border, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTexImage2D>(target, level, internalformat, width, height, border, imageSize, data, src_loc);
}

void GlIndirect::CompressedTexImage3D(const GLenum& target, const GLint& level, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLint& border, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTexImage3D>(target, level, internalformat, width, height, depth, border, imageSize, data, src_loc);
}

void GlIndirect::CompressedTexSubImage1D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLsizei& width, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTexSubImage1D>(target, level, xoffset, width, format, imageSize, data, src_loc);
}

void GlIndirect::CompressedTexSubImage2D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTexSubImage2D>(target, level, xoffset, yoffset, width, height, format, imageSize, data, src_loc);
}

void GlIndirect::CompressedTexSubImage3D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTexSubImage3D>(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data, src_loc);
}

void GlIndirect::CompressedTextureSubImage1D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLsizei& width, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTextureSubImage1D>(texture, level, xoffset, width, format, imageSize, data, src_loc);
}

void GlIndirect::CompressedTextureSubImage2D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTextureSubImage2D>(texture, level, xoffset, yoffset, width, height, format, imageSize, data, src_loc);
}

void GlIndirect::CompressedTextureSubImage3D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTextureSubImage3D>(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data, src_loc);
}

void GlIndirect::CopyBufferSubData(const GLenum& readTarget, const GLenum& writeTarget, const GLintptr& readOffset, const GLintptr& writeOffset, const GLsizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyBufferSubData>(readTarget, writeTarget, readOffset, writeOffset, size, src_loc);
}

void GlIndirect::CopyImageSubData(const GLuint& srcName, const GLenum& srcTarget, const GLint& srcLevel, const GLint& srcX, const GLint& srcY, const GLint& srcZ, const GLuint& dstName, const GLenum& dstTarget, const GLint& dstLevel, const GLint& dstX, const GLint& dstY, const GLint& dstZ, const GLsizei& srcWidth, const GLsizei& srcHeight, const GLsizei& srcDepth, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyImageSubData>(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth, src_loc);
}

void GlIndirect::CopyNamedBufferSubData(const GLuint& readBuffer, const GLuint& writeBuffer, const GLintptr& readOffset, const GLintptr& writeOffset, const GLsizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyNamedBufferSubData>(readBuffer, writeBuffer, readOffset, writeOffset, size, src_loc);
}

void GlIndirect::CopyTexImage1D(const GLenum& target, const GLint& level, const GLenum& internalformat, const GLint& x, const GLint& y, const GLsizei& width, const GLint& border, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyTexImage1D>(target, level, internalformat, x, y, width, border, src_loc);
}

void GlIndirect::CopyTexImage2D(const GLenum& target, const GLint& level, const GLenum& internalformat, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const GLint& border, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyTexImage2D>(target, level, internalformat, x, y, width, height, border, src_loc);
}

void GlIndirect::CopyTexSubImage1D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& x, const GLint& y, const GLsizei& width, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyTexSubImage1D>(target, level, xoffset, x, y, width, src_loc);
}

void GlIndirect::CopyTexSubImage2D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyTexSubImage2D>(target, level, xoffset, yoffset, x, y, width, height, src_loc);
}

void GlIndirect::CopyTexSubImage3D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyTexSubImage3D>(target, level, xoffset, yoffset, zoffset, x, y, width, height, src_loc);
}

void GlIndirect::CopyTextureSubImage1D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& x, const GLint& y, const GLsizei& width, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyTextureSubImage1D>(texture, level, xoffset, x, y, width, src_loc);
}

void GlIndirect::CopyTextureSubImage2D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyTextureSubImage2D>(texture, level, xoffset, yoffset, x, y, width, height, src_loc);
}

void GlIndirect::CopyTextureSubImage3D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyTextureSubImage3D>(texture, level, xoffset, yoffset, zoffset, x, y, width, height, src_loc);
}

void GlIndirect::CreateBuffers(const GLsizei& n, const GLuintArr& dst, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateBuffers>(n, dst, src_loc);
}

void GlIndirect::CreateFramebuffers(const GLsizei& n, const GLuintArr& framebuffers, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateFramebuffers>(n, framebuffers, src_loc);
}

GL::GLuint GlIndirect::CreateProgram(const SrcLoc& src_loc){
    return _callGL<&Gl::CreateProgram>(src_loc);
}

void GlIndirect::CreateProgramPipelines(const GLsizei& n, const GLuintArr& pipelines, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateProgramPipelines>(n, pipelines, src_loc);
}

void GlIndirect::CreateQueries(const GLenum& target, const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateQueries>(target, n, ids, src_loc);
}

void GlIndirect::CreateRenderbuffers(const GLsizei& n, const GLuintArr& renderbuffers, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateRenderbuffers>(n, renderbuffers, src_loc);
}

void GlIndirect::CreateSamplers(const GLsizei& n, const GLuintArr& samplers, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateSamplers>(n, samplers, src_loc);
}

GL::GLuint GlIndirect::CreateShader(const GLenum& type, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateShader>(type, src_loc);
}

GL::GLuint GlIndirect::CreateShaderProgramv(const GLenum& type, const GLsizei& count, const GLstringArr& strings, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateShaderProgramv>(type, count, strings, src_loc);
}

void GlIndirect::CreateTextures(const GLenum& target, const GLsizei& n, const GLuintArr& textures, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateTextures>(target, n, textures, src_loc);
}

void GlIndirect::CreateTransformFeedbacks(const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateTransformFeedbacks>(n, ids, src_loc);
}

void GlIndirect::CreateVertexArrays(const GLsizei& n, const GLuintArr& arrays, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateVertexArrays>(n, arrays, src_loc);
}

void GlIndirect::CullFace(const GLenum& mode, const SrcLoc& src_loc){
    return _callGL<&Gl::CullFace>(mode, src_loc);
}

void GlIndirect::DebugMessageControl(const GLenum& source, const GLenum& type, const GLenum& severity, const GLsizei& count, const GLuintArr& ids, const GLboolean& enabled, const SrcLoc& src_loc){
    return _callGL<&Gl::DebugMessageControl>(source, type, severity, count, ids, enabled, src_loc);
}

void GlIndirect::DebugMessageInsert(const GLenum& source, const GLenum& type, const GLuint& id, const GLenum& severity, const GLsizei& length, const GLstring& buf, const SrcLoc& src_loc){
    return _callGL<&Gl::DebugMessageInsert>(source, type, id, severity, length, buf, src_loc);
}

void GlIndirect::DeleteBuffers(const GLsizei& n, const GLuintArr& buffers, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteBuffers>(n, buffers, src_loc);
}

void GlIndirect::DeleteFramebuffers(const GLsizei& n, const GLuintArr& framebuffers, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteFramebuffers>(n, framebuffers, src_loc);
}

void GlIndirect::DeleteProgram(const GLuint& program, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteProgram>(program, src_loc);
}

void GlIndirect::DeleteProgramPipelines(const GLsizei& n, const GLuintArr& pipelines, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteProgramPipelines>(n, pipelines, src_loc);
}

void GlIndirect::DeleteQueries(const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteQueries>(n, ids, src_loc);
}

void GlIndirect::DeleteRenderbuffers(const GLsizei& n, const GLuintArr& renderbuffers, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteRenderbuffers>(n, renderbuffers, src_loc);
}

void GlIndirect::DeleteSamplers(const GLsizei& count, const GLuintArr& samplers, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteSamplers>(count, samplers, src_loc);
}

void GlIndirect::DeleteShader(const GLuint& shader, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteShader>(shader, src_loc);
}

void GlIndirect::DeleteSync(const GLsync& sync, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteSync>(sync, src_loc);
}

void GlIndirect::DeleteTextures(const GLsizei& n, const GLuintArr& textures, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteTextures>(n, textures, src_loc);
}

void GlIndirect::DeleteTransformFeedbacks(const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteTransformFeedbacks>(n, ids, src_loc);
}

void GlIndirect::DeleteVertexArrays(const GLsizei& n, const GLuintArr& arrays, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteVertexArrays>(n, arrays, src_loc);
}

void GlIndirect::DepthFunc(const GLenum& func, const SrcLoc& src_loc){
    return _callGL<&Gl::DepthFunc>(func, src_loc);
}

void GlIndirect::DepthMask(const GLboolean& flag, const SrcLoc& src_loc){
    return _callGL<&Gl::DepthMask>(flag, src_loc);
}

void GlIndirect::DepthRange(const GLdouble& n, const GLdouble& f, const SrcLoc& src_loc){
    return _callGL<&Gl::DepthRange>(n, f, src_loc);
}

void GlIndirect::DepthRangeArrayv(const GLuint& first, const GLsizei& count, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::DepthRangeArrayv>(first, count, v, src_loc);
}

void GlIndirect::DepthRangeIndexed(const GLuint& index, const GLdouble& n, const GLdouble& f, const SrcLoc& src_loc){
    return _callGL<&Gl::DepthRangeIndexed>(index, n, f, src_loc);
}

void GlIndirect::DepthRangef(const GLfloat& n, const GLfloat& f, const SrcLoc& src_loc){
    return _callGL<&Gl::DepthRangef>(n, f, src_loc);
}

void GlIndirect::DetachShader(const GLuint& program, const GLuint& shader, const SrcLoc& src_loc){
    return _callGL<&Gl::DetachShader>(program, shader, src_loc);
}

void GlIndirect::Disable(const GLenum& cap, const SrcLoc& src_loc){
    return _callGL<&Gl::Disable>(cap, src_loc);
}

void GlIndirect::DisableVertexArrayAttrib(const GLuint& vaobj, const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::DisableVertexArrayAttrib>(vaobj, index, src_loc);
}

void GlIndirect::DisableVertexAttribArray(const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::DisableVertexAttribArray>(index, src_loc);
}

void GlIndirect::Disablei(const GLenum& target, const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::Disablei>(target, index, src_loc);
}

void GlIndirect::DispatchCompute(const GLuint& num_groups_x, const GLuint& num_groups_y, const GLuint& num_groups_z, const SrcLoc& src_loc){
    return _callGL<&Gl::DispatchCompute>(num_groups_x, num_groups_y, num_groups_z, src_loc);
}

void GlIndirect::DispatchComputeIndirect(const GLintptr& indirect, const SrcLoc& src_loc){
    return _callGL<&Gl::DispatchComputeIndirect>(indirect, src_loc);
}

void GlIndirect::DrawArrays(const GLenum& mode, const GLint& first, const GLsizei& count, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawArrays>(mode, first, count, src_loc);
}

void GlIndirect::DrawArraysIndirect(const GLenum& mode, const GLdata& indirect, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawArraysIndirect>(mode, indirect, src_loc);
}

void GlIndirect::DrawArraysInstanced(const GLenum& mode, const GLint& first, const GLsizei& count, const GLsizei& instancecount, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawArraysInstanced>(mode, first, count, instancecount, src_loc);
}

void GlIndirect::DrawArraysInstancedBaseInstance(const GLenum& mode, const GLint& first, const GLsizei& count, const GLsizei& instancecount, const GLuint& baseinstance, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawArraysInstancedBaseInstance>(mode, first, count, instancecount, baseinstance, src_loc);
}

void GlIndirect::DrawBuffer(const GLenum& buf, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawBuffer>(buf, src_loc);
}

void GlIndirect::DrawBuffers(const GLsizei& n, const GLenumArr& bufs, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawBuffers>(n, bufs, src_loc);
}

void GlIndirect::DrawElements(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawElements>(mode, count, type, indices, src_loc);
}

void GlIndirect::DrawElementsBaseVertex(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLint& basevertex, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawElementsBaseVertex>(mode, count, type, indices, basevertex, src_loc);
}

void GlIndirect::DrawElementsIndirect(const GLenum& mode, const GLenum& type, const GLdata& indirect, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawElementsIndirect>(mode, type, indirect, src_loc);
}

void GlIndirect::DrawElementsInstanced(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLsizei& instancecount, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawElementsInstanced>(mode, count, type, indices, instancecount, src_loc);
}

void GlIndirect::DrawElementsInstancedBaseInstance(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLsizei& instancecount, const GLuint& baseinstance, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawElementsInstancedBaseInstance>(mode, count, type, indices, instancecount, baseinstance, src_loc);
}

void GlIndirect::DrawElementsInstancedBaseVertex(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLsizei& instancecount, const GLint& basevertex, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawElementsInstancedBaseVertex>(mode, count, type, indices, instancecount, basevertex, src_loc);
}

void GlIndirect::DrawElementsInstancedBaseVertexBaseInstance(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLsizei& instancecount, const GLint& basevertex, const GLuint& baseinstance, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawElementsInstancedBaseVertexBaseInstance>(mode, count, type, indices, instancecount, basevertex, baseinstance, src_loc);
}

void GlIndirect::DrawRangeElements(const GLenum& mode, const GLuint& start, const GLuint& end, const GLsizei& count, const GLenum& type, const GLdata& indices, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawRangeElements>(mode, start, end, count, type, indices, src_loc);
}

void GlIndirect::DrawRangeElementsBaseVertex(const GLenum& mode, const GLuint& start, const GLuint& end, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLint& basevertex, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawRangeElementsBaseVertex>(mode, start, end, count, type, indices, basevertex, src_loc);
}

void GlIndirect::DrawTransformFeedback(const GLenum& mode, const GLuint& id, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawTransformFeedback>(mode, id, src_loc);
}

void GlIndirect::DrawTransformFeedbackInstanced(const GLenum& mode, const GLuint& id, const GLsizei& instancecount, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawTransformFeedbackInstanced>(mode, id, instancecount, src_loc);
}

void GlIndirect::DrawTransformFeedbackStream(const GLenum& mode, const GLuint& id, const GLuint& stream, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawTransformFeedbackStream>(mode, id, stream, src_loc);
}

void GlIndirect::DrawTransformFeedbackStreamInstanced(const GLenum& mode, const GLuint& id, const GLuint& stream, const GLsizei& instancecount, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawTransformFeedbackStreamInstanced>(mode, id, stream, instancecount, src_loc);
}

void GlIndirect::Enable(const GLenum& cap, const SrcLoc& src_loc){
    return _callGL<&Gl::Enable>(cap, src_loc);
}

void GlIndirect::EnableVertexArrayAttrib(const GLuint& vaobj, const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::EnableVertexArrayAttrib>(vaobj, index, src_loc);
}

void GlIndirect::EnableVertexAttribArray(const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::EnableVertexAttribArray>(index, src_loc);
}

void GlIndirect::Enablei(const GLenum& target, const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::Enablei>(target, index, src_loc);
}

void GlIndirect::EndConditionalRender(const SrcLoc& src_loc){
    return _callGL<&Gl::EndConditionalRender>(src_loc);
}

void GlIndirect::EndQuery(const GLenum& target, const SrcLoc& src_loc){
    return _callGL<&Gl::EndQuery>(target, src_loc);
}

void GlIndirect::EndQueryIndexed(const GLenum& target, const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::EndQueryIndexed>(target, index, src_loc);
}

void GlIndirect::EndTransformFeedback(const SrcLoc& src_loc){
    return _callGL<&Gl::EndTransformFeedback>(src_loc);
}

GL::GLsync GlIndirect::FenceSync(const GLenum& condition, const GLbitfield& flags, const SrcLoc& src_loc){
    return _callGL<&Gl::FenceSync>(condition, flags, src_loc);
}

void GlIndirect::Finish(const SrcLoc& src_loc){
    return _callGL<&Gl::Finish>(src_loc);
}

void GlIndirect::Flush(const SrcLoc& src_loc){
    return _callGL<&Gl::Flush>(src_loc);
}

void GlIndirect::FlushMappedBufferRange(const GLenum& target, const GLintptr& offset, const GLsizeiptr& length, const SrcLoc& src_loc){
    return _callGL<&Gl::FlushMappedBufferRange>(target, offset, length, src_loc);
}

void GlIndirect::FlushMappedNamedBufferRange(const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& length, const SrcLoc& src_loc){
    return _callGL<&Gl::FlushMappedNamedBufferRange>(buffer, offset, length, src_loc);
}

void GlIndirect::FramebufferParameteri(const GLenum& target, const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    return _callGL<&Gl::FramebufferParameteri>(target, pname, param, src_loc);
}

void GlIndirect::FramebufferRenderbuffer(const GLenum& target, const GLenum& attachment, const GLenum& renderbuffertarget, const GLuint& renderbuffer, const SrcLoc& src_loc){
    return _callGL<&Gl::FramebufferRenderbuffer>(target, attachment, renderbuffertarget, renderbuffer, src_loc);
}

void GlIndirect::FramebufferTexture(const GLenum& target, const GLenum& attachment, const GLuint& texture, const GLint& level, const SrcLoc& src_loc){
    return _callGL<&Gl::FramebufferTexture>(target, attachment, texture, level, src_loc);
}

void GlIndirect::FramebufferTexture1D(const GLenum& target, const GLenum& attachment, const GLenum& textarget, const GLuint& texture, const GLint& level, const SrcLoc& src_loc){
    return _callGL<&Gl::FramebufferTexture1D>(target, attachment, textarget, texture, level, src_loc);
}

void GlIndirect::FramebufferTexture2D(const GLenum& target, const GLenum& attachment, const GLenum& textarget, const GLuint& texture, const GLint& level, const SrcLoc& src_loc){
    return _callGL<&Gl::FramebufferTexture2D>(target, attachment, textarget, texture, level, src_loc);
}

void GlIndirect::FramebufferTexture3D(const GLenum& target, const GLenum& attachment, const GLenum& textarget, const GLuint& texture, const GLint& level, const GLint& zoffset, const SrcLoc& src_loc){
    return _callGL<&Gl::FramebufferTexture3D>(target, attachment, textarget, texture, level, zoffset, src_loc);
}

void GlIndirect::FramebufferTextureLayer(const GLenum& target, const GLenum& attachment, const GLuint& texture, const GLint& level, const GLint& layer, const SrcLoc& src_loc){
    return _callGL<&Gl::FramebufferTextureLayer>(target, attachment, texture, level, layer, src_loc);
}

void GlIndirect::FrontFace(const GLenum& mode, const SrcLoc& src_loc){
    return _callGL<&Gl::FrontFace>(mode, src_loc);
}

void GlIndirect::GenBuffers(const GLsizei& n, const GLuintArr& buffers, const SrcLoc& src_loc){
    return _callGL<&Gl::GenBuffers>(n, buffers, src_loc);
}

void GlIndirect::GenFramebuffers(const GLsizei& n, const GLuintArr& framebuffers, const SrcLoc& src_loc){
    return _callGL<&Gl::GenFramebuffers>(n, framebuffers, src_loc);
}

void GlIndirect::GenProgramPipelines(const GLsizei& n, const GLuintArr& pipelines, const SrcLoc& src_loc){
    return _callGL<&Gl::GenProgramPipelines>(n, pipelines, src_loc);
}

void GlIndirect::GenQueries(const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    return _callGL<&Gl::GenQueries>(n, ids, src_loc);
}

void GlIndirect::GenRenderbuffers(const GLsizei& n, const GLuintArr& renderbuffers, const SrcLoc& src_loc){
    return _callGL<&Gl::GenRenderbuffers>(n, renderbuffers, src_loc);
}

void GlIndirect::GenSamplers(const GLsizei& count, const GLuintArr& samplers, const SrcLoc& src_loc){
    return _callGL<&Gl::GenSamplers>(count, samplers, src_loc);
}

void GlIndirect::GenTextures(const GLsizei& n, const GLuintArr& textures, const SrcLoc& src_loc){
    return _callGL<&Gl::GenTextures>(n, textures, src_loc);
}

void GlIndirect::GenTransformFeedbacks(const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    return _callGL<&Gl::GenTransformFeedbacks>(n, ids, src_loc);
}

void GlIndirect::GenVertexArrays(const GLsizei& n, const GLuintArr& arrays, const SrcLoc& src_loc){
    return _callGL<&Gl::GenVertexArrays>(n, arrays, src_loc);
}

void GlIndirect::GenerateMipmap(const GLenum& target, const SrcLoc& src_loc){
    return _callGL<&Gl::GenerateMipmap>(target, src_loc);
}

void GlIndirect::GenerateTextureMipmap(const GLuint& texture, const SrcLoc& src_loc){
    return _callGL<&Gl::GenerateTextureMipmap>(texture, src_loc);
}

void GlIndirect::GetActiveAtomicCounterBufferiv(const GLuint& program, const GLuint& bufferIndex, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveAtomicCounterBufferiv>(program, bufferIndex, pname, params, src_loc);
}

void GlIndirect::GetActiveAttrib(const GLuint& program, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLint& size, const GLenum& type, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveAttrib>(program, index, bufSize, length, size, type, name, src_loc);
}

void GlIndirect::GetActiveSubroutineName(const GLuint& program, const GLenum& shadertype, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveSubroutineName>(program, shadertype, index, bufSize, length, name, src_loc);
}

void GlIndirect::GetActiveSubroutineUniformName(const GLuint& program, const GLenum& shadertype, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveSubroutineUniformName>(program, shadertype, index, bufSize, length, name, src_loc);
}

void GlIndirect::GetActiveSubroutineUniformiv(const GLuint& program, const GLenum& shadertype, const GLuint& index, const GLenum& pname, const GLintArr& values, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveSubroutineUniformiv>(program, shadertype, index, pname, values, src_loc);
}

void GlIndirect::GetActiveUniform(const GLuint& program, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLint& size, const GLenum& type, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveUniform>(program, index, bufSize, length, size, type, name, src_loc);
}

void GlIndirect::GetActiveUniformBlockName(const GLuint& program, const GLuint& uniformBlockIndex, const GLsizei& bufSize, const GLsizei& length, const GLstring& uniformBlockName, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveUniformBlockName>(program, uniformBlockIndex, bufSize, length, uniformBlockName, src_loc);
}

void GlIndirect::GetActiveUniformBlockiv(const GLuint& program, const GLuint& uniformBlockIndex, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveUniformBlockiv>(program, uniformBlockIndex, pname, params, src_loc);
}

void GlIndirect::GetActiveUniformName(const GLuint& program, const GLuint& uniformIndex, const GLsizei& bufSize, const GLsizei& length, const GLstring& uniformName, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveUniformName>(program, uniformIndex, bufSize, length, uniformName, src_loc);
}

void GlIndirect::GetActiveUniformsiv(const GLuint& program, const GLsizei& uniformCount, const GLuintArr& uniformIndices, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveUniformsiv>(program, uniformCount, uniformIndices, pname, params, src_loc);
}

void GlIndirect::GetAttachedShaders(const GLuint& program, const GLsizei& maxCount, const GLsizeiArr& count, const GLuintArr& shaders, const SrcLoc& src_loc){
    return _callGL<&Gl::GetAttachedShaders>(program, maxCount, count, shaders, src_loc);
}

GL::GLint GlIndirect::GetAttribLocation(const GLuint& program, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetAttribLocation>(program, name, src_loc);
}

void GlIndirect::GetBooleani_v(const GLenum& target, const GLuint& index, const GLbooleanArr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetBooleani_v>(target, index, data, src_loc);
}

void GlIndirect::GetBooleanv(const GLenum& pname, const GLbooleanArr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetBooleanv>(pname, data, src_loc);
}

void GlIndirect::GetBufferParameteri64v(const GLenum& target, const GLenum& pname, const GLint64Arr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetBufferParameteri64v>(target, pname, params, src_loc);
}

void GlIndirect::GetBufferParameteriv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetBufferParameteriv>(target, pname, params, src_loc);
}

void GlIndirect::GetBufferPointerv(const GLenum& target, const GLenum& pname, const GLdataPtr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetBufferPointerv>(target, pname, params, src_loc);
}

void GlIndirect::GetBufferSubData(const GLenum& target, const GLintptr& offset, const GLsizeiptr& size, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetBufferSubData>(target, offset, size, data, src_loc);
}

void GlIndirect::GetCompressedTexImage(const GLenum& target, const GLint& level, const GLdata& img, const SrcLoc& src_loc){
    return _callGL<&Gl::GetCompressedTexImage>(target, level, img, src_loc);
}

void GlIndirect::GetCompressedTextureImage(const GLuint& texture, const GLint& level, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::GetCompressedTextureImage>(texture, level, bufSize, pixels, src_loc);
}

void GlIndirect::GetCompressedTextureSubImage(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::GetCompressedTextureSubImage>(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels, src_loc);
}

GL::GLuint GlIndirect::GetDebugMessageLog(const GLuint& count, const GLsizei& bufSize, const GLenumArr& sources, const GLenumArr& types, const GLuintArr& ids, const GLenumArr& severities, const GLsizei& lengths, const GLstring& messageLog, const SrcLoc& src_loc){
    return _callGL<&Gl::GetDebugMessageLog>(count, bufSize, sources, types, ids, severities, lengths, messageLog, src_loc);
}

void GlIndirect::GetDoublei_v(const GLenum& target, const GLuint& index, const GLdoubleArr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetDoublei_v>(target, index, data, src_loc);
}

void GlIndirect::GetDoublev(const GLenum& pname, const GLdoubleArr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetDoublev>(pname, data, src_loc);
}

GL::GLenum GlIndirect::GetError(const SrcLoc& src_loc){
    return _callGL<&Gl::GetError>(src_loc);
}

void GlIndirect::GetFloati_v(const GLenum& target, const GLuint& index, const GLfloatArr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetFloati_v>(target, index, data, src_loc);
}

void GlIndirect::GetFloatv(const GLenum& pname, const GLfloatArr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetFloatv>(pname, data, src_loc);
}

GL::GLint GlIndirect::GetFragDataIndex(const GLuint& program, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetFragDataIndex>(program, name, src_loc);
}

GL::GLint GlIndirect::GetFragDataLocation(const GLuint& program, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetFragDataLocation>(program, name, src_loc);
}

void GlIndirect::GetFramebufferAttachmentParameteriv(const GLenum& target, const GLenum& attachment, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetFramebufferAttachmentParameteriv>(target, attachment, pname, params, src_loc);
}

void GlIndirect::GetFramebufferParameteriv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetFramebufferParameteriv>(target, pname, params, src_loc);
}

GL::GLenum GlIndirect::GetGraphicsResetStatus(const SrcLoc& src_loc){
    return _callGL<&Gl::GetGraphicsResetStatus>(src_loc);
}

void GlIndirect::GetInteger64i_v(const GLenum& target, const GLuint& index, const GLint64Arr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetInteger64i_v>(target, index, data, src_loc);
}

void GlIndirect::GetInteger64v(const GLenum& pname, const GLint64Arr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetInteger64v>(pname, data, src_loc);
}

void GlIndirect::GetIntegeri_v(const GLenum& target, const GLuint& index, const GLintArr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetIntegeri_v>(target, index, data, src_loc);
}

void GlIndirect::GetIntegerv(const GLenum& pname, const GLintArr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetIntegerv>(pname, data, src_loc);
}

void GlIndirect::GetInternalformati64v(const GLenum& target, const GLenum& internalformat, const GLenum& pname, const GLsizei& count, const GLint64Arr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetInternalformati64v>(target, internalformat, pname, count, params, src_loc);
}

void GlIndirect::GetInternalformativ(const GLenum& target, const GLenum& internalformat, const GLenum& pname, const GLsizei& count, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetInternalformativ>(target, internalformat, pname, count, params, src_loc);
}

void GlIndirect::GetMultisamplefv(const GLenum& pname, const GLuint& index, const GLfloatArr& val, const SrcLoc& src_loc){
    return _callGL<&Gl::GetMultisamplefv>(pname, index, val, src_loc);
}

void GlIndirect::GetNamedBufferParameteri64v(const GLuint& buffer, const GLenum& pname, const GLint64Arr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetNamedBufferParameteri64v>(buffer, pname, params, src_loc);
}

void GlIndirect::GetNamedBufferParameteriv(const GLuint& buffer, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetNamedBufferParameteriv>(buffer, pname, params, src_loc);
}

void GlIndirect::GetNamedBufferPointerv(const GLuint& buffer, const GLenum& pname, const GLdataPtr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetNamedBufferPointerv>(buffer, pname, params, src_loc);
}

void GlIndirect::GetNamedBufferSubData(const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetNamedBufferSubData>(buffer, offset, size, data, src_loc);
}

void GlIndirect::GetNamedFramebufferAttachmentParameteriv(const GLuint& framebuffer, const GLenum& attachment, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetNamedFramebufferAttachmentParameteriv>(framebuffer, attachment, pname, params, src_loc);
}

void GlIndirect::GetNamedFramebufferParameteriv(const GLuint& framebuffer, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::GetNamedFramebufferParameteriv>(framebuffer, pname, param, src_loc);
}

void GlIndirect::GetNamedRenderbufferParameteriv(const GLuint& renderbuffer, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetNamedRenderbufferParameteriv>(renderbuffer, pname, params, src_loc);
}

void GlIndirect::GetObjectLabel(const GLenum& identifier, const GLuint& name, const GLsizei& bufSize, const GLsizei& length, const GLstring& label, const SrcLoc& src_loc){
    return _callGL<&Gl::GetObjectLabel>(identifier, name, bufSize, length, label, src_loc);
}

void GlIndirect::GetObjectPtrLabel(const GLdata& ptr, const GLsizei& bufSize, const GLsizei& length, const GLstring& label, const SrcLoc& src_loc){
    return _callGL<&Gl::GetObjectPtrLabel>(ptr, bufSize, length, label, src_loc);
}

void GlIndirect::GetPointerv(const GLenum& pname, const GLdataPtr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetPointerv>(pname, params, src_loc);
}

void GlIndirect::GetProgramBinary(const GLuint& program, const GLsizei& bufSize, const GLsizei& length, const GLenumArr& binaryFormat, const GLdata& binary, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramBinary>(program, bufSize, length, binaryFormat, binary, src_loc);
}

void GlIndirect::GetProgramInfoLog(const GLuint& program, const GLsizei& bufSize, const GLsizei& length, const GLstring& infoLog, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramInfoLog>(program, bufSize, length, infoLog, src_loc);
}

void GlIndirect::GetProgramInterfaceiv(const GLuint& program, const GLenum& programInterface, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramInterfaceiv>(program, programInterface, pname, params, src_loc);
}

void GlIndirect::GetProgramPipelineInfoLog(const GLuint& pipeline, const GLsizei& bufSize, const GLsizei& length, const GLstring& infoLog, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramPipelineInfoLog>(pipeline, bufSize, length, infoLog, src_loc);
}

void GlIndirect::GetProgramPipelineiv(const GLuint& pipeline, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramPipelineiv>(pipeline, pname, params, src_loc);
}

GL::GLuint GlIndirect::GetProgramResourceIndex(const GLuint& program, const GLenum& programInterface, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramResourceIndex>(program, programInterface, name, src_loc);
}

GL::GLint GlIndirect::GetProgramResourceLocation(const GLuint& program, const GLenum& programInterface, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramResourceLocation>(program, programInterface, name, src_loc);
}

GL::GLint GlIndirect::GetProgramResourceLocationIndex(const GLuint& program, const GLenum& programInterface, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramResourceLocationIndex>(program, programInterface, name, src_loc);
}

void GlIndirect::GetProgramResourceName(const GLuint& program, const GLenum& programInterface, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramResourceName>(program, programInterface, index, bufSize, length, name, src_loc);
}

void GlIndirect::GetProgramResourceiv(const GLuint& program, const GLenum& programInterface, const GLuint& index, const GLsizei& propCount, const GLenumArr& props, const GLsizei& count, const GLsizei& length, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramResourceiv>(program, programInterface, index, propCount, props, count, length, params, src_loc);
}

void GlIndirect::GetProgramStageiv(const GLuint& program, const GLenum& shadertype, const GLenum& pname, const GLintArr& values, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramStageiv>(program, shadertype, pname, values, src_loc);
}

void GlIndirect::GetProgramiv(const GLuint& program, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramiv>(program, pname, params, src_loc);
}

void GlIndirect::GetQueryBufferObjecti64v(const GLuint& id, const GLuint& buffer, const GLenum& pname, const GLintptr& offset, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryBufferObjecti64v>(id, buffer, pname, offset, src_loc);
}

void GlIndirect::GetQueryBufferObjectiv(const GLuint& id, const GLuint& buffer, const GLenum& pname, const GLintptr& offset, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryBufferObjectiv>(id, buffer, pname, offset, src_loc);
}

void GlIndirect::GetQueryBufferObjectui64v(const GLuint& id, const GLuint& buffer, const GLenum& pname, const GLintptr& offset, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryBufferObjectui64v>(id, buffer, pname, offset, src_loc);
}

void GlIndirect::GetQueryBufferObjectuiv(const GLuint& id, const GLuint& buffer, const GLenum& pname, const GLintptr& offset, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryBufferObjectuiv>(id, buffer, pname, offset, src_loc);
}

void GlIndirect::GetQueryIndexediv(const GLenum& target, const GLuint& index, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryIndexediv>(target, index, pname, params, src_loc);
}

void GlIndirect::GetQueryObjecti64v(const GLuint& id, const GLenum& pname, const GLint64Arr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryObjecti64v>(id, pname, params, src_loc);
}

void GlIndirect::GetQueryObjectiv(const GLuint& id, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryObjectiv>(id, pname, params, src_loc);
}

void GlIndirect::GetQueryObjectui64v(const GLuint& id, const GLenum& pname, const GLuint64Arr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryObjectui64v>(id, pname, params, src_loc);
}

void GlIndirect::GetQueryObjectuiv(const GLuint& id, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryObjectuiv>(id, pname, params, src_loc);
}

void GlIndirect::GetQueryiv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryiv>(target, pname, params, src_loc);
}

void GlIndirect::GetRenderbufferParameteriv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetRenderbufferParameteriv>(target, pname, params, src_loc);
}

void GlIndirect::GetSamplerParameterIiv(const GLuint& sampler, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetSamplerParameterIiv>(sampler, pname, params, src_loc);
}

void GlIndirect::GetSamplerParameterIuiv(const GLuint& sampler, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetSamplerParameterIuiv>(sampler, pname, params, src_loc);
}

void GlIndirect::GetSamplerParameterfv(const GLuint& sampler, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetSamplerParameterfv>(sampler, pname, params, src_loc);
}

void GlIndirect::GetSamplerParameteriv(const GLuint& sampler, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetSamplerParameteriv>(sampler, pname, params, src_loc);
}

void GlIndirect::GetShaderInfoLog(const GLuint& shader, const GLsizei& bufSize, const GLsizei& length, const GLstring& infoLog, const SrcLoc& src_loc){
    return _callGL<&Gl::GetShaderInfoLog>(shader, bufSize, length, infoLog, src_loc);
}

void GlIndirect::GetShaderPrecisionFormat(const GLenum& shadertype, const GLenum& precisiontype, const GLintArr& range, const GLintArr& precision, const SrcLoc& src_loc){
    return _callGL<&Gl::GetShaderPrecisionFormat>(shadertype, precisiontype, range, precision, src_loc);
}

void GlIndirect::GetShaderSource(const GLuint& shader, const GLsizei& bufSize, const GLsizei& length, const GLstring& source, const SrcLoc& src_loc){
    return _callGL<&Gl::GetShaderSource>(shader, bufSize, length, source, src_loc);
}

void GlIndirect::GetShaderiv(const GLuint& shader, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetShaderiv>(shader, pname, params, src_loc);
}

GL::GLstring GlIndirect::GetString(const GLenum& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetString>(name, src_loc);
}

GL::GLstring GlIndirect::GetStringi(const GLenum& name, const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::GetStringi>(name, index, src_loc);
}

GL::GLuint GlIndirect::GetSubroutineIndex(const GLuint& program, const GLenum& shadertype, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetSubroutineIndex>(program, shadertype, name, src_loc);
}

GL::GLint GlIndirect::GetSubroutineUniformLocation(const GLuint& program, const GLenum& shadertype, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetSubroutineUniformLocation>(program, shadertype, name, src_loc);
}

void GlIndirect::GetSynciv(const GLsync& sync, const GLenum& pname, const GLsizei& count, const GLsizei& length, const GLintArr& values, const SrcLoc& src_loc){
    return _callGL<&Gl::GetSynciv>(sync, pname, count, length, values, src_loc);
}

void GlIndirect::GetTexImage(const GLenum& target, const GLint& level, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTexImage>(target, level, format, type, pixels, src_loc);
}

void GlIndirect::GetTexLevelParameterfv(const GLenum& target, const GLint& level, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTexLevelParameterfv>(target, level, pname, params, src_loc);
}

void GlIndirect::GetTexLevelParameteriv(const GLenum& target, const GLint& level, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTexLevelParameteriv>(target, level, pname, params, src_loc);
}

void GlIndirect::GetTexParameterIiv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTexParameterIiv>(target, pname, params, src_loc);
}

void GlIndirect::GetTexParameterIuiv(const GLenum& target, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTexParameterIuiv>(target, pname, params, src_loc);
}

void GlIndirect::GetTexParameterfv(const GLenum& target, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTexParameterfv>(target, pname, params, src_loc);
}

void GlIndirect::GetTexParameteriv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTexParameteriv>(target, pname, params, src_loc);
}

void GlIndirect::GetTextureImage(const GLuint& texture, const GLint& level, const GLenum& format, const GLenum& type, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTextureImage>(texture, level, format, type, bufSize, pixels, src_loc);
}

void GlIndirect::GetTextureLevelParameterfv(const GLuint& texture, const GLint& level, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTextureLevelParameterfv>(texture, level, pname, params, src_loc);
}

void GlIndirect::GetTextureLevelParameteriv(const GLuint& texture, const GLint& level, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTextureLevelParameteriv>(texture, level, pname, params, src_loc);
}

void GlIndirect::GetTextureParameterIiv(const GLuint& texture, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTextureParameterIiv>(texture, pname, params, src_loc);
}

void GlIndirect::GetTextureParameterIuiv(const GLuint& texture, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTextureParameterIuiv>(texture, pname, params, src_loc);
}

void GlIndirect::GetTextureParameterfv(const GLuint& texture, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTextureParameterfv>(texture, pname, params, src_loc);
}

void GlIndirect::GetTextureParameteriv(const GLuint& texture, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTextureParameteriv>(texture, pname, params, src_loc);
}

void GlIndirect::GetTextureSubImage(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLenum& type, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTextureSubImage>(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels, src_loc);
}

void GlIndirect::GetTransformFeedbackVarying(const GLuint& program, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLsizeiArr& size, const GLenumArr& type, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTransformFeedbackVarying>(program, index, bufSize, length, size, type, name, src_loc);
}

void GlIndirect::GetTransformFeedbacki64_v(const GLuint& xfb, const GLenum& pname, const GLuint& index, const GLint64Arr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTransformFeedbacki64_v>(xfb, pname, index, param, src_loc);
}

void GlIndirect::GetTransformFeedbacki_v(const GLuint& xfb, const GLenum& pname, const GLuint& index, const GLintArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTransformFeedbacki_v>(xfb, pname, index, param, src_loc);
}

void GlIndirect::GetTransformFeedbackiv(const GLuint& xfb, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTransformFeedbackiv>(xfb, pname, param, src_loc);
}

GL::GLuint GlIndirect::GetUniformBlockIndex(const GLuint& program, const GLstring& uniformBlockName, const SrcLoc& src_loc){
    return _callGL<&Gl::GetUniformBlockIndex>(program, uniformBlockName, src_loc);
}

GL::GLint GlIndirect::GetUniformLocation(const GLuint& program, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetUniformLocation>(program, name, src_loc);
}

void GlIndirect::GetUniformSubroutineuiv(const GLenum& shadertype, const GLint& location, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetUniformSubroutineuiv>(shadertype, location, params, src_loc);
}

void GlIndirect::GetUniformdv(const GLuint& program, const GLint& location, const GLdoubleArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetUniformdv>(program, location, params, src_loc);
}

void GlIndirect::GetUniformfv(const GLuint& program, const GLint& location, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetUniformfv>(program, location, params, src_loc);
}

void GlIndirect::GetUniformiv(const GLuint& program, const GLint& location, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetUniformiv>(program, location, params, src_loc);
}

void GlIndirect::GetUniformuiv(const GLuint& program, const GLint& location, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetUniformuiv>(program, location, params, src_loc);
}

void GlIndirect::GetVertexArrayIndexed64iv(const GLuint& vaobj, const GLuint& index, const GLenum& pname, const GLint64Arr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexArrayIndexed64iv>(vaobj, index, pname, param, src_loc);
}

void GlIndirect::GetVertexArrayIndexediv(const GLuint& vaobj, const GLuint& index, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexArrayIndexediv>(vaobj, index, pname, param, src_loc);
}

void GlIndirect::GetVertexArrayiv(const GLuint& vaobj, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexArrayiv>(vaobj, pname, param, src_loc);
}

void GlIndirect::GetVertexAttribIiv(const GLuint& index, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexAttribIiv>(index, pname, params, src_loc);
}

void GlIndirect::GetVertexAttribIuiv(const GLuint& index, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexAttribIuiv>(index, pname, params, src_loc);
}

void GlIndirect::GetVertexAttribLdv(const GLuint& index, const GLenum& pname, const GLdoubleArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexAttribLdv>(index, pname, params, src_loc);
}

void GlIndirect::GetVertexAttribPointerv(const GLuint& index, const GLenum& pname, const GLdataPtr& pointer, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexAttribPointerv>(index, pname, pointer, src_loc);
}

void GlIndirect::GetVertexAttribdv(const GLuint& index, const GLenum& pname, const GLdoubleArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexAttribdv>(index, pname, params, src_loc);
}

void GlIndirect::GetVertexAttribfv(const GLuint& index, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexAttribfv>(index, pname, params, src_loc);
}

void GlIndirect::GetVertexAttribiv(const GLuint& index, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexAttribiv>(index, pname, params, src_loc);
}

void GlIndirect::GetnCompressedTexImage(const GLenum& target, const GLint& lod, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::GetnCompressedTexImage>(target, lod, bufSize, pixels, src_loc);
}

void GlIndirect::GetnTexImage(const GLenum& target, const GLint& level, const GLenum& format, const GLenum& type, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::GetnTexImage>(target, level, format, type, bufSize, pixels, src_loc);
}

void GlIndirect::GetnUniformdv(const GLuint& program, const GLint& location, const GLsizei& bufSize, const GLdoubleArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetnUniformdv>(program, location, bufSize, params, src_loc);
}

void GlIndirect::GetnUniformfv(const GLuint& program, const GLint& location, const GLsizei& bufSize, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetnUniformfv>(program, location, bufSize, params, src_loc);
}

void GlIndirect::GetnUniformiv(const GLuint& program, const GLint& location, const GLsizei& bufSize, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetnUniformiv>(program, location, bufSize, params, src_loc);
}

void GlIndirect::GetnUniformuiv(const GLuint& program, const GLint& location, const GLsizei& bufSize, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetnUniformuiv>(program, location, bufSize, params, src_loc);
}

void GlIndirect::Hint(const GLenum& target, const GLenum& mode, const SrcLoc& src_loc){
    return _callGL<&Gl::Hint>(target, mode, src_loc);
}

void GlIndirect::InvalidateBufferData(const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::InvalidateBufferData>(buffer, src_loc);
}

void GlIndirect::InvalidateBufferSubData(const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& length, const SrcLoc& src_loc){
    return _callGL<&Gl::InvalidateBufferSubData>(buffer, offset, length, src_loc);
}

void GlIndirect::InvalidateFramebuffer(const GLenum& target, const GLsizei& numAttachments, const GLenumArr& attachments, const SrcLoc& src_loc){
    return _callGL<&Gl::InvalidateFramebuffer>(target, numAttachments, attachments, src_loc);
}

void GlIndirect::InvalidateNamedFramebufferData(const GLuint& framebuffer, const GLsizei& numAttachments, const GLenumArr& attachments, const SrcLoc& src_loc){
    return _callGL<&Gl::InvalidateNamedFramebufferData>(framebuffer, numAttachments, attachments, src_loc);
}

void GlIndirect::InvalidateNamedFramebufferSubData(const GLuint& framebuffer, const GLsizei& numAttachments, const GLenumArr& attachments, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::InvalidateNamedFramebufferSubData>(framebuffer, numAttachments, attachments, x, y, width, height, src_loc);
}

void GlIndirect::InvalidateSubFramebuffer(const GLenum& target, const GLsizei& numAttachments, const GLenumArr& attachments, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::InvalidateSubFramebuffer>(target, numAttachments, attachments, x, y, width, height, src_loc);
}

void GlIndirect::InvalidateTexImage(const GLuint& texture, const GLint& level, const SrcLoc& src_loc){
    return _callGL<&Gl::InvalidateTexImage>(texture, level, src_loc);
}

void GlIndirect::InvalidateTexSubImage(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const SrcLoc& src_loc){
    return _callGL<&Gl::InvalidateTexSubImage>(texture, level, xoffset, yoffset, zoffset, width, height, depth, src_loc);
}

GL::GLboolean GlIndirect::IsBuffer(const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::IsBuffer>(buffer, src_loc);
}

GL::GLboolean GlIndirect::IsEnabled(const GLenum& cap, const SrcLoc& src_loc){
    return _callGL<&Gl::IsEnabled>(cap, src_loc);
}

GL::GLboolean GlIndirect::IsEnabledi(const GLenum& target, const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::IsEnabledi>(target, index, src_loc);
}

GL::GLboolean GlIndirect::IsFramebuffer(const GLuint& framebuffer, const SrcLoc& src_loc){
    return _callGL<&Gl::IsFramebuffer>(framebuffer, src_loc);
}

GL::GLboolean GlIndirect::IsProgram(const GLuint& program, const SrcLoc& src_loc){
    return _callGL<&Gl::IsProgram>(program, src_loc);
}

GL::GLboolean GlIndirect::IsProgramPipeline(const GLuint& pipeline, const SrcLoc& src_loc){
    return _callGL<&Gl::IsProgramPipeline>(pipeline, src_loc);
}

GL::GLboolean GlIndirect::IsQuery(const GLuint& id, const SrcLoc& src_loc){
    return _callGL<&Gl::IsQuery>(id, src_loc);
}

GL::GLboolean GlIndirect::IsRenderbuffer(const GLuint& renderbuffer, const SrcLoc& src_loc){
    return _callGL<&Gl::IsRenderbuffer>(renderbuffer, src_loc);
}

GL::GLboolean GlIndirect::IsSampler(const GLuint& sampler, const SrcLoc& src_loc){
    return _callGL<&Gl::IsSampler>(sampler, src_loc);
}

GL::GLboolean GlIndirect::IsShader(const GLuint& shader, const SrcLoc& src_loc){
    return _callGL<&Gl::IsShader>(shader, src_loc);
}

GL::GLboolean GlIndirect::IsSync(const GLsync& sync, const SrcLoc& src_loc){
    return _callGL<&Gl::IsSync>(sync, src_loc);
}

GL::GLboolean GlIndirect::IsTexture(const GLuint& texture, const SrcLoc& src_loc){
    return _callGL<&Gl::IsTexture>(texture, src_loc);
}

GL::GLboolean GlIndirect::IsTransformFeedback(const GLuint& id, const SrcLoc& src_loc){
    return _callGL<&Gl::IsTransformFeedback>(id, src_loc);
}

GL::GLboolean GlIndirect::IsVertexArray(const GLuint& array, const SrcLoc& src_loc){
    return _callGL<&Gl::IsVertexArray>(array, src_loc);
}

void GlIndirect::LineWidth(const GLfloat& width, const SrcLoc& src_loc){
    return _callGL<&Gl::LineWidth>(width, src_loc);
}

void GlIndirect::LinkProgram(const GLuint& program, const SrcLoc& src_loc){
    return _callGL<&Gl::LinkProgram>(program, src_loc);
}

void GlIndirect::LogicOp(const GLenum& opcode, const SrcLoc& src_loc){
    return _callGL<&Gl::LogicOp>(opcode, src_loc);
}

GL::GLdataPtr GlIndirect::MapBuffer(const GLenum& target, const GLenum& access, const SrcLoc& src_loc){
    return _callGL<&Gl::MapBuffer>(target, access, src_loc);
}

GL::GLdataPtr GlIndirect::MapBufferRange(const GLenum& target, const GLintptr& offset, const GLsizeiptr& length, const GLbitfield& access, const SrcLoc& src_loc){
    return _callGL<&Gl::MapBufferRange>(target, offset, length, access, src_loc);
}

GL::GLdataPtr GlIndirect::MapNamedBuffer(const GLuint& buffer, const GLenum& access, const SrcLoc& src_loc){
    return _callGL<&Gl::MapNamedBuffer>(buffer, access, src_loc);
}

GL::GLdataPtr GlIndirect::MapNamedBufferRange(const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& length, const GLbitfield& access, const SrcLoc& src_loc){
    return _callGL<&Gl::MapNamedBufferRange>(buffer, offset, length, access, src_loc);
}

void GlIndirect::MemoryBarrier(const GLbitfield& barriers, const SrcLoc& src_loc){
    return _callGL<&Gl::MemoryBarrier>(barriers, src_loc);
}

void GlIndirect::MemoryBarrierByRegion(const GLbitfield& barriers, const SrcLoc& src_loc){
    return _callGL<&Gl::MemoryBarrierByRegion>(barriers, src_loc);
}

void GlIndirect::MinSampleShading(const GLfloat& value, const SrcLoc& src_loc){
    return _callGL<&Gl::MinSampleShading>(value, src_loc);
}

void GlIndirect::MultiDrawArrays(const GLenum& mode, const GLintArr& first, const GLsizeiArr& count, const GLsizei& drawcount, const SrcLoc& src_loc){
    return _callGL<&Gl::MultiDrawArrays>(mode, first, count, drawcount, src_loc);
}

void GlIndirect::MultiDrawArraysIndirect(const GLenum& mode, const GLdata& indirect, const GLsizei& drawcount, const GLsizei& stride, const SrcLoc& src_loc){
    return _callGL<&Gl::MultiDrawArraysIndirect>(mode, indirect, drawcount, stride, src_loc);
}

void GlIndirect::MultiDrawArraysIndirectCount(const GLenum& mode, const GLdata& indirect, const GLintptr& drawcount, const GLsizei& maxdrawcount, const GLsizei& stride, const SrcLoc& src_loc){
    return _callGL<&Gl::MultiDrawArraysIndirectCount>(mode, indirect, drawcount, maxdrawcount, stride, src_loc);
}

void GlIndirect::MultiDrawElements(const GLenum& mode, const GLsizeiArr& count, const GLenum& type, const GLdataPtr& indices, const GLsizei& drawcount, const SrcLoc& src_loc){
    return _callGL<&Gl::MultiDrawElements>(mode, count, type, indices, drawcount, src_loc);
}

void GlIndirect::MultiDrawElementsBaseVertex(const GLenum& mode, const GLsizeiArr& count, const GLenum& type, const GLdataPtr& indices, const GLsizei& drawcount, const GLintArr& basevertex, const SrcLoc& src_loc){
    return _callGL<&Gl::MultiDrawElementsBaseVertex>(mode, count, type, indices, drawcount, basevertex, src_loc);
}

void GlIndirect::MultiDrawElementsIndirect(const GLenum& mode, const GLenum& type, const GLdata& indirect, const GLsizei& drawcount, const GLsizei& stride, const SrcLoc& src_loc){
    return _callGL<&Gl::MultiDrawElementsIndirect>(mode, type, indirect, drawcount, stride, src_loc);
}

void GlIndirect::MultiDrawElementsIndirectCount(const GLenum& mode, const GLenum& type, const GLdata& indirect, const GLintptr& drawcount, const GLsizei& maxdrawcount, const GLsizei& stride, const SrcLoc& src_loc){
    return _callGL<&Gl::MultiDrawElementsIndirectCount>(mode, type, indirect, drawcount, maxdrawcount, stride, src_loc);
}

void GlIndirect::NamedBufferData(const GLuint& buffer, const GLsizeiptr& size, const GLdata& data, const GLenum& usage, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedBufferData>(buffer, size, data, usage, src_loc);
}

void GlIndirect::NamedBufferStorage(const GLuint& buffer, const GLsizeiptr& size, const GLdata& data, const GLbitfield& flags, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedBufferStorage>(buffer, size, data, flags, src_loc);
}

void GlIndirect::NamedBufferSubData(const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedBufferSubData>(buffer, offset, size, data, src_loc);
}

void GlIndirect::NamedFramebufferDrawBuffer(const GLuint& framebuffer, const GLenum& buf, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedFramebufferDrawBuffer>(framebuffer, buf, src_loc);
}

void GlIndirect::NamedFramebufferDrawBuffers(const GLuint& framebuffer, const GLsizei& n, const GLenumArr& bufs, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedFramebufferDrawBuffers>(framebuffer, n, bufs, src_loc);
}

void GlIndirect::NamedFramebufferParameteri(const GLuint& framebuffer, const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedFramebufferParameteri>(framebuffer, pname, param, src_loc);
}

void GlIndirect::NamedFramebufferReadBuffer(const GLuint& framebuffer, const GLenum& src, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedFramebufferReadBuffer>(framebuffer, src, src_loc);
}

void GlIndirect::NamedFramebufferRenderbuffer(const GLuint& framebuffer, const GLenum& attachment, const GLenum& renderbuffertarget, const GLuint& renderbuffer, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedFramebufferRenderbuffer>(framebuffer, attachment, renderbuffertarget, renderbuffer, src_loc);
}

void GlIndirect::NamedFramebufferTexture(const GLuint& framebuffer, const GLenum& attachment, const GLuint& texture, const GLint& level, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedFramebufferTexture>(framebuffer, attachment, texture, level, src_loc);
}

void GlIndirect::NamedFramebufferTextureLayer(const GLuint& framebuffer, const GLenum& attachment, const GLuint& texture, const GLint& level, const GLint& layer, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedFramebufferTextureLayer>(framebuffer, attachment, texture, level, layer, src_loc);
}

void GlIndirect::NamedRenderbufferStorage(const GLuint& renderbuffer, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedRenderbufferStorage>(renderbuffer, internalformat, width, height, src_loc);
}

void GlIndirect::NamedRenderbufferStorageMultisample(const GLuint& renderbuffer, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedRenderbufferStorageMultisample>(renderbuffer, samples, internalformat, width, height, src_loc);
}

void GlIndirect::ObjectLabel(const GLenum& identifier, const GLuint& name, const GLsizei& length, const GLstring& label, const SrcLoc& src_loc){
    return _callGL<&Gl::ObjectLabel>(identifier, name, length, label, src_loc);
}

void GlIndirect::ObjectPtrLabel(const GLdata& ptr, const GLsizei& length, const GLstring& label, const SrcLoc& src_loc){
    return _callGL<&Gl::ObjectPtrLabel>(ptr, length, label, src_loc);
}

void GlIndirect::PatchParameterfv(const GLenum& pname, const GLfloatArr& values, const SrcLoc& src_loc){
    return _callGL<&Gl::PatchParameterfv>(pname, values, src_loc);
}

void GlIndirect::PatchParameteri(const GLenum& pname, const GLint& value, const SrcLoc& src_loc){
    return _callGL<&Gl::PatchParameteri>(pname, value, src_loc);
}

void GlIndirect::PauseTransformFeedback(const SrcLoc& src_loc){
    return _callGL<&Gl::PauseTransformFeedback>(src_loc);
}

void GlIndirect::PixelStoref(const GLenum& pname, const GLfloat& param, const SrcLoc& src_loc){
    return _callGL<&Gl::PixelStoref>(pname, param, src_loc);
}

void GlIndirect::PixelStorei(const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    return _callGL<&Gl::PixelStorei>(pname, param, src_loc);
}

void GlIndirect::PointParameterf(const GLenum& pname, const GLfloat& param, const SrcLoc& src_loc){
    return _callGL<&Gl::PointParameterf>(pname, param, src_loc);
}

void GlIndirect::PointParameterfv(const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::PointParameterfv>(pname, params, src_loc);
}

void GlIndirect::PointParameteri(const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    return _callGL<&Gl::PointParameteri>(pname, param, src_loc);
}

void GlIndirect::PointParameteriv(const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::PointParameteriv>(pname, params, src_loc);
}

void GlIndirect::PointSize(const GLfloat& size, const SrcLoc& src_loc){
    return _callGL<&Gl::PointSize>(size, src_loc);
}

void GlIndirect::PolygonMode(const GLenum& face, const GLenum& mode, const SrcLoc& src_loc){
    return _callGL<&Gl::PolygonMode>(face, mode, src_loc);
}

void GlIndirect::PolygonOffset(const GLfloat& factor, const GLfloat& units, const SrcLoc& src_loc){
    return _callGL<&Gl::PolygonOffset>(factor, units, src_loc);
}

void GlIndirect::PolygonOffsetClamp(const GLfloat& factor, const GLfloat& units, const GLfloat& clamp, const SrcLoc& src_loc){
    return _callGL<&Gl::PolygonOffsetClamp>(factor, units, clamp, src_loc);
}

void GlIndirect::PopDebugGroup(const SrcLoc& src_loc){
    return _callGL<&Gl::PopDebugGroup>(src_loc);
}

void GlIndirect::PrimitiveRestartIndex(const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::PrimitiveRestartIndex>(index, src_loc);
}

void GlIndirect::ProgramBinary(const GLuint& program, const GLenum& binaryFormat, const GLdata& binary, const GLsizei& length, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramBinary>(program, binaryFormat, binary, length, src_loc);
}

void GlIndirect::ProgramParameteri(const GLuint& program, const GLenum& pname, const GLint& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramParameteri>(program, pname, value, src_loc);
}

void GlIndirect::ProgramUniform1d(const GLuint& program, const GLint& location, const GLdouble& v0, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform1d>(program, location, v0, src_loc);
}

void GlIndirect::ProgramUniform1dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform1dv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform1f(const GLuint& program, const GLint& location, const GLfloat& v0, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform1f>(program, location, v0, src_loc);
}

void GlIndirect::ProgramUniform1fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform1fv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform1i(const GLuint& program, const GLint& location, const GLint& v0, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform1i>(program, location, v0, src_loc);
}

void GlIndirect::ProgramUniform1iv(const GLuint& program, const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform1iv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform1ui(const GLuint& program, const GLint& location, const GLuint& v0, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform1ui>(program, location, v0, src_loc);
}

void GlIndirect::ProgramUniform1uiv(const GLuint& program, const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform1uiv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform2d(const GLuint& program, const GLint& location, const GLdouble& v0, const GLdouble& v1, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform2d>(program, location, v0, v1, src_loc);
}

void GlIndirect::ProgramUniform2dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform2dv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform2f(const GLuint& program, const GLint& location, const GLfloat& v0, const GLfloat& v1, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform2f>(program, location, v0, v1, src_loc);
}

void GlIndirect::ProgramUniform2fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform2fv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform2i(const GLuint& program, const GLint& location, const GLint& v0, const GLint& v1, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform2i>(program, location, v0, v1, src_loc);
}

void GlIndirect::ProgramUniform2iv(const GLuint& program, const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform2iv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform2ui(const GLuint& program, const GLint& location, const GLuint& v0, const GLuint& v1, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform2ui>(program, location, v0, v1, src_loc);
}

void GlIndirect::ProgramUniform2uiv(const GLuint& program, const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform2uiv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform3d(const GLuint& program, const GLint& location, const GLdouble& v0, const GLdouble& v1, const GLdouble& v2, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform3d>(program, location, v0, v1, v2, src_loc);
}

void GlIndirect::ProgramUniform3dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform3dv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform3f(const GLuint& program, const GLint& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform3f>(program, location, v0, v1, v2, src_loc);
}

void GlIndirect::ProgramUniform3fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform3fv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform3i(const GLuint& program, const GLint& location, const GLint& v0, const GLint& v1, const GLint& v2, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform3i>(program, location, v0, v1, v2, src_loc);
}

void GlIndirect::ProgramUniform3iv(const GLuint& program, const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform3iv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform3ui(const GLuint& program, const GLint& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform3ui>(program, location, v0, v1, v2, src_loc);
}

void GlIndirect::ProgramUniform3uiv(const GLuint& program, const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform3uiv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform4d(const GLuint& program, const GLint& location, const GLdouble& v0, const GLdouble& v1, const GLdouble& v2, const GLdouble& v3, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform4d>(program, location, v0, v1, v2, v3, src_loc);
}

void GlIndirect::ProgramUniform4dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform4dv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform4f(const GLuint& program, const GLint& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const GLfloat& v3, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform4f>(program, location, v0, v1, v2, v3, src_loc);
}

void GlIndirect::ProgramUniform4fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform4fv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform4i(const GLuint& program, const GLint& location, const GLint& v0, const GLint& v1, const GLint& v2, const GLint& v3, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform4i>(program, location, v0, v1, v2, v3, src_loc);
}

void GlIndirect::ProgramUniform4iv(const GLuint& program, const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform4iv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform4ui(const GLuint& program, const GLint& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const GLuint& v3, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform4ui>(program, location, v0, v1, v2, v3, src_loc);
}

void GlIndirect::ProgramUniform4uiv(const GLuint& program, const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform4uiv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix2dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix2dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix2fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix2fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix2x3dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix2x3dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix2x3fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix2x3fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix2x4dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix2x4dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix2x4fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix2x4fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix3dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix3dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix3fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix3fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix3x2dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix3x2dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix3x2fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix3x2fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix3x4dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix3x4dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix3x4fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix3x4fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix4dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix4dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix4fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix4fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix4x2dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix4x2dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix4x2fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix4x2fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix4x3dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix4x3dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix4x3fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix4x3fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProvokingVertex(const GLenum& mode, const SrcLoc& src_loc){
    return _callGL<&Gl::ProvokingVertex>(mode, src_loc);
}

void GlIndirect::PushDebugGroup(const GLenum& source, const GLuint& id, const GLsizei& length, const GLstring& message, const SrcLoc& src_loc){
    return _callGL<&Gl::PushDebugGroup>(source, id, length, message, src_loc);
}

void GlIndirect::QueryCounter(const GLuint& id, const GLenum& target, const SrcLoc& src_loc){
    return _callGL<&Gl::QueryCounter>(id, target, src_loc);
}

void GlIndirect::ReadBuffer(const GLenum& src, const SrcLoc& src_loc){
    return _callGL<&Gl::ReadBuffer>(src, src_loc);
}

void GlIndirect::ReadPixels(const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::ReadPixels>(x, y, width, height, format, type, pixels, src_loc);
}

void GlIndirect::ReadnPixels(const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLenum& type, const GLsizei& bufSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&Gl::ReadnPixels>(x, y, width, height, format, type, bufSize, data, src_loc);
}

void GlIndirect::ReleaseShaderCompiler(const SrcLoc& src_loc){
    return _callGL<&Gl::ReleaseShaderCompiler>(src_loc);
}

void GlIndirect::RenderbufferStorage(const GLenum& target, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::RenderbufferStorage>(target, internalformat, width, height, src_loc);
}

void GlIndirect::RenderbufferStorageMultisample(const GLenum& target, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::RenderbufferStorageMultisample>(target, samples, internalformat, width, height, src_loc);
}

void GlIndirect::ResumeTransformFeedback(const SrcLoc& src_loc){
    return _callGL<&Gl::ResumeTransformFeedback>(src_loc);
}

void GlIndirect::SampleCoverage(const GLfloat& value, const GLboolean& invert, const SrcLoc& src_loc){
    return _callGL<&Gl::SampleCoverage>(value, invert, src_loc);
}

void GlIndirect::SampleMaski(const GLuint& maskNumber, const GLbitfield& mask, const SrcLoc& src_loc){
    return _callGL<&Gl::SampleMaski>(maskNumber, mask, src_loc);
}

void GlIndirect::SamplerParameterIiv(const GLuint& sampler, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::SamplerParameterIiv>(sampler, pname, param, src_loc);
}

void GlIndirect::SamplerParameterIuiv(const GLuint& sampler, const GLenum& pname, const GLuintArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::SamplerParameterIuiv>(sampler, pname, param, src_loc);
}

void GlIndirect::SamplerParameterf(const GLuint& sampler, const GLenum& pname, const GLfloat& param, const SrcLoc& src_loc){
    return _callGL<&Gl::SamplerParameterf>(sampler, pname, param, src_loc);
}

void GlIndirect::SamplerParameterfv(const GLuint& sampler, const GLenum& pname, const GLfloatArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::SamplerParameterfv>(sampler, pname, param, src_loc);
}

void GlIndirect::SamplerParameteri(const GLuint& sampler, const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    return _callGL<&Gl::SamplerParameteri>(sampler, pname, param, src_loc);
}

void GlIndirect::SamplerParameteriv(const GLuint& sampler, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::SamplerParameteriv>(sampler, pname, param, src_loc);
}

void GlIndirect::Scissor(const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::Scissor>(x, y, width, height, src_loc);
}

void GlIndirect::ScissorArrayv(const GLuint& first, const GLsizei& count, const GLintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::ScissorArrayv>(first, count, v, src_loc);
}

void GlIndirect::ScissorIndexed(const GLuint& index, const GLint& left, const GLint& bottom, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::ScissorIndexed>(index, left, bottom, width, height, src_loc);
}

void GlIndirect::ScissorIndexedv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::ScissorIndexedv>(index, v, src_loc);
}

void GlIndirect::ShaderBinary(const GLsizei& count, const GLuintArr& shaders, const GLenum& binaryFormat, const GLdata& binary, const GLsizei& length, const SrcLoc& src_loc){
    return _callGL<&Gl::ShaderBinary>(count, shaders, binaryFormat, binary, length, src_loc);
}

void GlIndirect::ShaderSource(const GLuint& shader, const GLsizei& count, const GLstringArr& strings, const GLintArr& lengths, const SrcLoc& src_loc){
    return _callGL<&Gl::ShaderSource>(shader, count, strings, lengths, src_loc);
}

void GlIndirect::ShaderStorageBlockBinding(const GLuint& program, const GLuint& storageBlockIndex, const GLuint& storageBlockBinding, const SrcLoc& src_loc){
    return _callGL<&Gl::ShaderStorageBlockBinding>(program, storageBlockIndex, storageBlockBinding, src_loc);
}

void GlIndirect::SpecializeShader(const GLuint& shader, const GLstring& pEntryPoint, const GLuint& numSpecializationConstants, const GLuintArr& pConstantIndex, const GLuintArr& pConstantValue, const SrcLoc& src_loc){
    return _callGL<&Gl::SpecializeShader>(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue, src_loc);
}

void GlIndirect::StencilFunc(const GLenum& func, const GLint& ref, const GLuint& mask, const SrcLoc& src_loc){
    return _callGL<&Gl::StencilFunc>(func, ref, mask, src_loc);
}

void GlIndirect::StencilFuncSeparate(const GLenum& face, const GLenum& func, const GLint& ref, const GLuint& mask, const SrcLoc& src_loc){
    return _callGL<&Gl::StencilFuncSeparate>(face, func, ref, mask, src_loc);
}

void GlIndirect::StencilMask(const GLuint& mask, const SrcLoc& src_loc){
    return _callGL<&Gl::StencilMask>(mask, src_loc);
}

void GlIndirect::StencilMaskSeparate(const GLenum& face, const GLuint& mask, const SrcLoc& src_loc){
    return _callGL<&Gl::StencilMaskSeparate>(face, mask, src_loc);
}

void GlIndirect::StencilOp(const GLenum& fail, const GLenum& zfail, const GLenum& zpass, const SrcLoc& src_loc){
    return _callGL<&Gl::StencilOp>(fail, zfail, zpass, src_loc);
}

void GlIndirect::StencilOpSeparate(const GLenum& face, const GLenum& sfail, const GLenum& dpfail, const GLenum& dppass, const SrcLoc& src_loc){
    return _callGL<&Gl::StencilOpSeparate>(face, sfail, dpfail, dppass, src_loc);
}

void GlIndirect::TexBuffer(const GLenum& target, const GLenum& internalformat, const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::TexBuffer>(target, internalformat, buffer, src_loc);
}

void GlIndirect::TexBufferRange(const GLenum& target, const GLenum& internalformat, const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&Gl::TexBufferRange>(target, internalformat, buffer, offset, size, src_loc);
}

void GlIndirect::TexImage1D(const GLenum& target, const GLint& level, const GLint& internalformat, const GLsizei& width, const GLint& border, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TexImage1D>(target, level, internalformat, width, border, format, type, pixels, src_loc);
}

void GlIndirect::TexImage2D(const GLenum& target, const GLint& level, const GLint& internalformat, const GLsizei& width, const GLsizei& height, const GLint& border, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TexImage2D>(target, level, internalformat, width, height, border, format, type, pixels, src_loc);
}

void GlIndirect::TexImage2DMultisample(const GLenum& target, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&Gl::TexImage2DMultisample>(target, samples, internalformat, width, height, fixedsamplelocations, src_loc);
}

void GlIndirect::TexImage3D(const GLenum& target, const GLint& level, const GLint& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLint& border, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TexImage3D>(target, level, internalformat, width, height, depth, border, format, type, pixels, src_loc);
}

void GlIndirect::TexImage3DMultisample(const GLenum& target, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&Gl::TexImage3DMultisample>(target, samples, internalformat, width, height, depth, fixedsamplelocations, src_loc);
}

void GlIndirect::TexParameterIiv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::TexParameterIiv>(target, pname, params, src_loc);
}

void GlIndirect::TexParameterIuiv(const GLenum& target, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::TexParameterIuiv>(target, pname, params, src_loc);
}

void GlIndirect::TexParameterf(const GLenum& target, const GLenum& pname, const GLfloat& param, const SrcLoc& src_loc){
    return _callGL<&Gl::TexParameterf>(target, pname, param, src_loc);
}

void GlIndirect::TexParameterfv(const GLenum& target, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::TexParameterfv>(target, pname, params, src_loc);
}

void GlIndirect::TexParameteri(const GLenum& target, const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    return _callGL<&Gl::TexParameteri>(target, pname, param, src_loc);
}

void GlIndirect::TexParameteriv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::TexParameteriv>(target, pname, params, src_loc);
}

void GlIndirect::TexStorage1D(const GLenum& target, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const SrcLoc& src_loc){
    return _callGL<&Gl::TexStorage1D>(target, levels, internalformat, width, src_loc);
}

void GlIndirect::TexStorage2D(const GLenum& target, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::TexStorage2D>(target, levels, internalformat, width, height, src_loc);
}

void GlIndirect::TexStorage2DMultisample(const GLenum& target, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&Gl::TexStorage2DMultisample>(target, samples, internalformat, width, height, fixedsamplelocations, src_loc);
}

void GlIndirect::TexStorage3D(const GLenum& target, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const SrcLoc& src_loc){
    return _callGL<&Gl::TexStorage3D>(target, levels, internalformat, width, height, depth, src_loc);
}

void GlIndirect::TexStorage3DMultisample(const GLenum& target, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&Gl::TexStorage3DMultisample>(target, samples, internalformat, width, height, depth, fixedsamplelocations, src_loc);
}

void GlIndirect::TexSubImage1D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLsizei& width, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TexSubImage1D>(target, level, xoffset, width, format, type, pixels, src_loc);
}

void GlIndirect::TexSubImage2D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TexSubImage2D>(target, level, xoffset, yoffset, width, height, format, type, pixels, src_loc);
}

void GlIndirect::TexSubImage3D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TexSubImage3D>(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels, src_loc);
}

void GlIndirect::TextureBarrier(const SrcLoc& src_loc){
    return _callGL<&Gl::TextureBarrier>(src_loc);
}

void GlIndirect::TextureBuffer(const GLuint& texture, const GLenum& internalformat, const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureBuffer>(texture, internalformat, buffer, src_loc);
}

void GlIndirect::TextureBufferRange(const GLuint& texture, const GLenum& internalformat, const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureBufferRange>(texture, internalformat, buffer, offset, size, src_loc);
}

void GlIndirect::TextureParameterIiv(const GLuint& texture, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureParameterIiv>(texture, pname, params, src_loc);
}

void GlIndirect::TextureParameterIuiv(const GLuint& texture, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureParameterIuiv>(texture, pname, params, src_loc);
}

void GlIndirect::TextureParameterf(const GLuint& texture, const GLenum& pname, const GLfloat& param, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureParameterf>(texture, pname, param, src_loc);
}

void GlIndirect::TextureParameterfv(const GLuint& texture, const GLenum& pname, const GLfloatArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureParameterfv>(texture, pname, param, src_loc);
}

void GlIndirect::TextureParameteri(const GLuint& texture, const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureParameteri>(texture, pname, param, src_loc);
}

void GlIndirect::TextureParameteriv(const GLuint& texture, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureParameteriv>(texture, pname, param, src_loc);
}

void GlIndirect::TextureStorage1D(const GLuint& texture, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureStorage1D>(texture, levels, internalformat, width, src_loc);
}

void GlIndirect::TextureStorage2D(const GLuint& texture, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureStorage2D>(texture, levels, internalformat, width, height, src_loc);
}

void GlIndirect::TextureStorage2DMultisample(const GLuint& texture, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureStorage2DMultisample>(texture, samples, internalformat, width, height, fixedsamplelocations, src_loc);
}

void GlIndirect::TextureStorage3D(const GLuint& texture, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureStorage3D>(texture, levels, internalformat, width, height, depth, src_loc);
}

void GlIndirect::TextureStorage3DMultisample(const GLuint& texture, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureStorage3DMultisample>(texture, samples, internalformat, width, height, depth, fixedsamplelocations, src_loc);
}

void GlIndirect::TextureSubImage1D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLsizei& width, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureSubImage1D>(texture, level, xoffset, width, format, type, pixels, src_loc);
}

void GlIndirect::TextureSubImage2D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureSubImage2D>(texture, level, xoffset, yoffset, width, height, format, type, pixels, src_loc);
}

void GlIndirect::TextureSubImage3D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureSubImage3D>(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels, src_loc);
}

void GlIndirect::TextureView(const GLuint& texture, const GLenum& target, const GLuint& origtexture, const GLenum& internalformat, const GLuint& minlevel, const GLuint& numlevels, const GLuint& minlayer, const GLuint& numlayers, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureView>(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers, src_loc);
}

void GlIndirect::TransformFeedbackBufferBase(const GLuint& xfb, const GLuint& index, const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::TransformFeedbackBufferBase>(xfb, index, buffer, src_loc);
}

void GlIndirect::TransformFeedbackBufferRange(const GLuint& xfb, const GLuint& index, const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&Gl::TransformFeedbackBufferRange>(xfb, index, buffer, offset, size, src_loc);
}

void GlIndirect::Uniform1d(const GLint& location, const GLdouble& x, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform1d>(location, x, src_loc);
}

void GlIndirect::Uniform1dv(const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform1dv>(location, count, value, src_loc);
}

void GlIndirect::Uniform1f(const GLint& location, const GLfloat& v0, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform1f>(location, v0, src_loc);
}

void GlIndirect::Uniform1fv(const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform1fv>(location, count, value, src_loc);
}

void GlIndirect::Uniform1i(const GLint& location, const GLint& v0, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform1i>(location, v0, src_loc);
}

void GlIndirect::Uniform1iv(const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform1iv>(location, count, value, src_loc);
}

void GlIndirect::Uniform1ui(const GLint& location, const GLuint& v0, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform1ui>(location, v0, src_loc);
}

void GlIndirect::Uniform1uiv(const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform1uiv>(location, count, value, src_loc);
}

void GlIndirect::Uniform2d(const GLint& location, const GLdouble& x, const GLdouble& y, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform2d>(location, x, y, src_loc);
}

void GlIndirect::Uniform2dv(const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform2dv>(location, count, value, src_loc);
}

void GlIndirect::Uniform2f(const GLint& location, const GLfloat& v0, const GLfloat& v1, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform2f>(location, v0, v1, src_loc);
}

void GlIndirect::Uniform2fv(const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform2fv>(location, count, value, src_loc);
}

void GlIndirect::Uniform2i(const GLint& location, const GLint& v0, const GLint& v1, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform2i>(location, v0, v1, src_loc);
}

void GlIndirect::Uniform2iv(const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform2iv>(location, count, value, src_loc);
}

void GlIndirect::Uniform2ui(const GLint& location, const GLuint& v0, const GLuint& v1, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform2ui>(location, v0, v1, src_loc);
}

void GlIndirect::Uniform2uiv(const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform2uiv>(location, count, value, src_loc);
}

void GlIndirect::Uniform3d(const GLint& location, const GLdouble& x, const GLdouble& y, const GLdouble& z, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform3d>(location, x, y, z, src_loc);
}

void GlIndirect::Uniform3dv(const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform3dv>(location, count, value, src_loc);
}

void GlIndirect::Uniform3f(const GLint& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform3f>(location, v0, v1, v2, src_loc);
}

void GlIndirect::Uniform3fv(const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform3fv>(location, count, value, src_loc);
}

void GlIndirect::Uniform3i(const GLint& location, const GLint& v0, const GLint& v1, const GLint& v2, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform3i>(location, v0, v1, v2, src_loc);
}

void GlIndirect::Uniform3iv(const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform3iv>(location, count, value, src_loc);
}

void GlIndirect::Uniform3ui(const GLint& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform3ui>(location, v0, v1, v2, src_loc);
}

void GlIndirect::Uniform3uiv(const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform3uiv>(location, count, value, src_loc);
}

void GlIndirect::Uniform4d(const GLint& location, const GLdouble& x, const GLdouble& y, const GLdouble& z, const GLdouble& w, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform4d>(location, x, y, z, w, src_loc);
}

void GlIndirect::Uniform4dv(const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform4dv>(location, count, value, src_loc);
}

void GlIndirect::Uniform4f(const GLint& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const GLfloat& v3, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform4f>(location, v0, v1, v2, v3, src_loc);
}

void GlIndirect::Uniform4fv(const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform4fv>(location, count, value, src_loc);
}

void GlIndirect::Uniform4i(const GLint& location, const GLint& v0, const GLint& v1, const GLint& v2, const GLint& v3, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform4i>(location, v0, v1, v2, v3, src_loc);
}

void GlIndirect::Uniform4iv(const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform4iv>(location, count, value, src_loc);
}

void GlIndirect::Uniform4ui(const GLint& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const GLuint& v3, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform4ui>(location, v0, v1, v2, v3, src_loc);
}

void GlIndirect::Uniform4uiv(const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform4uiv>(location, count, value, src_loc);
}

void GlIndirect::UniformBlockBinding(const GLuint& program, const GLuint& uniformBlockIndex, const GLuint& uniformBlockBinding, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformBlockBinding>(program, uniformBlockIndex, uniformBlockBinding, src_loc);
}

void GlIndirect::UniformMatrix2dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix2dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix2fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix2fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix2x3dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix2x3dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix2x3fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix2x3fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix2x4dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix2x4dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix2x4fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix2x4fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix3dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix3dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix3fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix3fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix3x2dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix3x2dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix3x2fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix3x2fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix3x4dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix3x4dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix3x4fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix3x4fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix4dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix4dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix4fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix4fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix4x2dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix4x2dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix4x2fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix4x2fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix4x3dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix4x3dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix4x3fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix4x3fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformSubroutinesuiv(const GLenum& shadertype, const GLsizei& count, const GLuintArr& indices, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformSubroutinesuiv>(shadertype, count, indices, src_loc);
}

GL::GLboolean GlIndirect::UnmapBuffer(const GLenum& target, const SrcLoc& src_loc){
    return _callGL<&Gl::UnmapBuffer>(target, src_loc);
}

GL::GLboolean GlIndirect::UnmapNamedBuffer(const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::UnmapNamedBuffer>(buffer, src_loc);
}

void GlIndirect::UseProgram(const GLuint& program, const SrcLoc& src_loc){
    return _callGL<&Gl::UseProgram>(program, src_loc);
}

void GlIndirect::UseProgramStages(const GLuint& pipeline, const GLbitfield& stages, const GLuint& program, const SrcLoc& src_loc){
    return _callGL<&Gl::UseProgramStages>(pipeline, stages, program, src_loc);
}

void GlIndirect::ValidateProgram(const GLuint& program, const SrcLoc& src_loc){
    return _callGL<&Gl::ValidateProgram>(program, src_loc);
}

void GlIndirect::ValidateProgramPipeline(const GLuint& pipeline, const SrcLoc& src_loc){
    return _callGL<&Gl::ValidateProgramPipeline>(pipeline, src_loc);
}

void GlIndirect::VertexArrayAttribBinding(const GLuint& vaobj, const GLuint& attribindex, const GLuint& bindingindex, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexArrayAttribBinding>(vaobj, attribindex, bindingindex, src_loc);
}

void GlIndirect::VertexArrayAttribFormat(const GLuint& vaobj, const GLuint& attribindex, const GLint& size, const GLenum& type, const GLboolean& normalized, const GLuint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexArrayAttribFormat>(vaobj, attribindex, size, type, normalized, relativeoffset, src_loc);
}

void GlIndirect::VertexArrayAttribIFormat(const GLuint& vaobj, const GLuint& attribindex, const GLint& size, const GLenum& type, const GLuint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexArrayAttribIFormat>(vaobj, attribindex, size, type, relativeoffset, src_loc);
}

void GlIndirect::VertexArrayAttribLFormat(const GLuint& vaobj, const GLuint& attribindex, const GLint& size, const GLenum& type, const GLuint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexArrayAttribLFormat>(vaobj, attribindex, size, type, relativeoffset, src_loc);
}

void GlIndirect::VertexArrayBindingDivisor(const GLuint& vaobj, const GLuint& bindingindex, const GLuint& divisor, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexArrayBindingDivisor>(vaobj, bindingindex, divisor, src_loc);
}

void GlIndirect::VertexArrayElementBuffer(const GLuint& vaobj, const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexArrayElementBuffer>(vaobj, buffer, src_loc);
}

void GlIndirect::VertexArrayVertexBuffer(const GLuint& vaobj, const GLuint& bindingindex, const GLuint& buffer, const GLintptr& offset, const GLsizei& stride, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexArrayVertexBuffer>(vaobj, bindingindex, buffer, offset, stride, src_loc);
}

void GlIndirect::VertexArrayVertexBuffers(const GLuint& vaobj, const GLuint& first, const GLsizei& count, const GLuintArr& buffers, const GLintptrArr& offsets, const GLsizeiArr& strides, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexArrayVertexBuffers>(vaobj, first, count, buffers, offsets, strides, src_loc);
}

void GlIndirect::VertexAttrib1d(const GLuint& index, const GLdouble& x, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib1d>(index, x, src_loc);
}

void GlIndirect::VertexAttrib1dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib1dv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib1f(const GLuint& index, const GLfloat& x, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib1f>(index, x, src_loc);
}

void GlIndirect::VertexAttrib1fv(const GLuint& index, const GLfloatArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib1fv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib1s(const GLuint& index, const GLshort& x, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib1s>(index, x, src_loc);
}

void GlIndirect::VertexAttrib1sv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib1sv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib2d(const GLuint& index, const GLdouble& x, const GLdouble& y, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib2d>(index, x, y, src_loc);
}

void GlIndirect::VertexAttrib2dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib2dv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib2f(const GLuint& index, const GLfloat& x, const GLfloat& y, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib2f>(index, x, y, src_loc);
}

void GlIndirect::VertexAttrib2fv(const GLuint& index, const GLfloatArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib2fv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib2s(const GLuint& index, const GLshort& x, const GLshort& y, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib2s>(index, x, y, src_loc);
}

void GlIndirect::VertexAttrib2sv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib2sv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib3d(const GLuint& index, const GLdouble& x, const GLdouble& y, const GLdouble& z, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib3d>(index, x, y, z, src_loc);
}

void GlIndirect::VertexAttrib3dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib3dv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib3f(const GLuint& index, const GLfloat& x, const GLfloat& y, const GLfloat& z, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib3f>(index, x, y, z, src_loc);
}

void GlIndirect::VertexAttrib3fv(const GLuint& index, const GLfloatArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib3fv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib3s(const GLuint& index, const GLshort& x, const GLshort& y, const GLshort& z, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib3s>(index, x, y, z, src_loc);
}

void GlIndirect::VertexAttrib3sv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib3sv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4Nbv(const GLuint& index, const GLbyte& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4Nbv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4Niv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4Niv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4Nsv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4Nsv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4Nub(const GLuint& index, const GLubyte& x, const GLubyte& y, const GLubyte& z, const GLubyte& w, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4Nub>(index, x, y, z, w, src_loc);
}

void GlIndirect::VertexAttrib4Nubv(const GLuint& index, const GLubyte& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4Nubv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4Nuiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4Nuiv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4Nusv(const GLuint& index, const GLushort& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4Nusv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4bv(const GLuint& index, const GLbyte& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4bv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4d(const GLuint& index, const GLdouble& x, const GLdouble& y, const GLdouble& z, const GLdouble& w, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4d>(index, x, y, z, w, src_loc);
}

void GlIndirect::VertexAttrib4dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4dv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4f(const GLuint& index, const GLfloat& x, const GLfloat& y, const GLfloat& z, const GLfloat& w, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4f>(index, x, y, z, w, src_loc);
}

void GlIndirect::VertexAttrib4fv(const GLuint& index, const GLfloatArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4fv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4iv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4iv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4s(const GLuint& index, const GLshort& x, const GLshort& y, const GLshort& z, const GLshort& w, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4s>(index, x, y, z, w, src_loc);
}

void GlIndirect::VertexAttrib4sv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4sv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4ubv(const GLuint& index, const GLubyte& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4ubv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4uiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4uiv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4usv(const GLuint& index, const GLushort& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4usv>(index, v, src_loc);
}

void GlIndirect::VertexAttribBinding(const GLuint& attribindex, const GLuint& bindingindex, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribBinding>(attribindex, bindingindex, src_loc);
}

void GlIndirect::VertexAttribDivisor(const GLuint& index, const GLuint& divisor, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribDivisor>(index, divisor, src_loc);
}

void GlIndirect::VertexAttribFormat(const GLuint& attribindex, const GLint& size, const GLenum& type, const GLboolean& normalized, const GLuint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribFormat>(attribindex, size, type, normalized, relativeoffset, src_loc);
}

void GlIndirect::VertexAttribI1i(const GLuint& index, const GLint& x, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI1i>(index, x, src_loc);
}

void GlIndirect::VertexAttribI1iv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI1iv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI1ui(const GLuint& index, const GLuint& x, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI1ui>(index, x, src_loc);
}

void GlIndirect::VertexAttribI1uiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI1uiv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI2i(const GLuint& index, const GLint& x, const GLint& y, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI2i>(index, x, y, src_loc);
}

void GlIndirect::VertexAttribI2iv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI2iv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI2ui(const GLuint& index, const GLuint& x, const GLuint& y, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI2ui>(index, x, y, src_loc);
}

void GlIndirect::VertexAttribI2uiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI2uiv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI3i(const GLuint& index, const GLint& x, const GLint& y, const GLint& z, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI3i>(index, x, y, z, src_loc);
}

void GlIndirect::VertexAttribI3iv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI3iv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI3ui(const GLuint& index, const GLuint& x, const GLuint& y, const GLuint& z, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI3ui>(index, x, y, z, src_loc);
}

void GlIndirect::VertexAttribI3uiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI3uiv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI4bv(const GLuint& index, const GLbyte& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI4bv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI4i(const GLuint& index, const GLint& x, const GLint& y, const GLint& z, const GLint& w, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI4i>(index, x, y, z, w, src_loc);
}

void GlIndirect::VertexAttribI4iv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI4iv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI4sv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI4sv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI4ubv(const GLuint& index, const GLubyte& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI4ubv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI4ui(const GLuint& index, const GLuint& x, const GLuint& y, const GLuint& z, const GLuint& w, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI4ui>(index, x, y, z, w, src_loc);
}

void GlIndirect::VertexAttribI4uiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI4uiv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI4usv(const GLuint& index, const GLushort& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI4usv>(index, v, src_loc);
}

void GlIndirect::VertexAttribIFormat(const GLuint& attribindex, const GLint& size, const GLenum& type, const GLuint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribIFormat>(attribindex, size, type, relativeoffset, src_loc);
}

void GlIndirect::VertexAttribIPointer(const GLuint& index, const GLint& size, const GLenum& type, const GLsizei& stride, const GLdata& pointer, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribIPointer>(index, size, type, stride, pointer, src_loc);
}

void GlIndirect::VertexAttribL1d(const GLuint& index, const GLdouble& x, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribL1d>(index, x, src_loc);
}

void GlIndirect::VertexAttribL1dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribL1dv>(index, v, src_loc);
}

void GlIndirect::VertexAttribL2d(const GLuint& index, const GLdouble& x, const GLdouble& y, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribL2d>(index, x, y, src_loc);
}

void GlIndirect::VertexAttribL2dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribL2dv>(index, v, src_loc);
}

void GlIndirect::VertexAttribL3d(const GLuint& index, const GLdouble& x, const GLdouble& y, const GLdouble& z, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribL3d>(index, x, y, z, src_loc);
}

void GlIndirect::VertexAttribL3dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribL3dv>(index, v, src_loc);
}

void GlIndirect::VertexAttribL4d(const GLuint& index, const GLdouble& x, const GLdouble& y, const GLdouble& z, const GLdouble& w, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribL4d>(index, x, y, z, w, src_loc);
}

void GlIndirect::VertexAttribL4dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribL4dv>(index, v, src_loc);
}

void GlIndirect::VertexAttribLFormat(const GLuint& attribindex, const GLint& size, const GLenum& type, const GLuint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribLFormat>(attribindex, size, type, relativeoffset, src_loc);
}

void GlIndirect::VertexAttribLPointer(const GLuint& index, const GLint& size, const GLenum& type, const GLsizei& stride, const GLdata& pointer, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribLPointer>(index, size, type, stride, pointer, src_loc);
}

void GlIndirect::VertexAttribP1ui(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuint& value, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribP1ui>(index, type, normalized, value, src_loc);
}

void GlIndirect::VertexAttribP1uiv(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribP1uiv>(index, type, normalized, value, src_loc);
}

void GlIndirect::VertexAttribP2ui(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuint& value, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribP2ui>(index, type, normalized, value, src_loc);
}

void GlIndirect::VertexAttribP2uiv(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribP2uiv>(index, type, normalized, value, src_loc);
}

void GlIndirect::VertexAttribP3ui(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuint& value, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribP3ui>(index, type, normalized, value, src_loc);
}

void GlIndirect::VertexAttribP3uiv(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribP3uiv>(index, type, normalized, value, src_loc);
}

void GlIndirect::VertexAttribP4ui(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuint& value, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribP4ui>(index, type, normalized, value, src_loc);
}

void GlIndirect::VertexAttribP4uiv(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribP4uiv>(index, type, normalized, value, src_loc);
}

void GlIndirect::VertexAttribPointer(const GLuint& index, const GLint& size, const GLenum& type, const GLboolean& normalized, const GLsizei& stride, const GLdata& pointer, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribPointer>(index, size, type, normalized, stride, pointer, src_loc);
}

void GlIndirect::VertexBindingDivisor(const GLuint& bindingindex, const GLuint& divisor, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexBindingDivisor>(bindingindex, divisor, src_loc);
}

void GlIndirect::Viewport(const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::Viewport>(x, y, width, height, src_loc);
}

void GlIndirect::ViewportArrayv(const GLuint& first, const GLsizei& count, const GLfloatArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::ViewportArrayv>(first, count, v, src_loc);
}

void GlIndirect::ViewportIndexedf(const GLuint& index, const GLfloat& x, const GLfloat& y, const GLfloat& w, const GLfloat& h, const SrcLoc& src_loc){
    return _callGL<&Gl::ViewportIndexedf>(index, x, y, w, h, src_loc);
}

void GlIndirect::ViewportIndexedfv(const GLuint& index, const GLfloatArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::ViewportIndexedfv>(index, v, src_loc);
}

void GlIndirect::WaitSync(const GLsync& sync, const GLbitfield& flags, const GLuint64& timeout, const SrcLoc& src_loc){
    return _callGL<&Gl::WaitSync>(sync, flags, timeout, src_loc);
}
