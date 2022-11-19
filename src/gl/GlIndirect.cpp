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

void GlIndirect::ActiveShaderProgram(const Uint& pipeline, const Uint& program, const SrcLoc& src_loc){
    return _callGL<&Gl::ActiveShaderProgram>(pipeline, program, src_loc);
}

void GlIndirect::ActiveTexture(const Enum& texture, const SrcLoc& src_loc){
    return _callGL<&Gl::ActiveTexture>(texture, src_loc);
}

void GlIndirect::AttachShader(const Uint& program, const Uint& shader, const SrcLoc& src_loc){
    return _callGL<&Gl::AttachShader>(program, shader, src_loc);
}

void GlIndirect::BeginConditionalRender(const Uint& id, const Enum& mode, const SrcLoc& src_loc){
    return _callGL<&Gl::BeginConditionalRender>(id, mode, src_loc);
}

void GlIndirect::BeginQuery(const Enum& target, const Uint& id, const SrcLoc& src_loc){
    return _callGL<&Gl::BeginQuery>(target, id, src_loc);
}

void GlIndirect::BeginQueryIndexed(const Enum& target, const Uint& index, const Uint& id, const SrcLoc& src_loc){
    return _callGL<&Gl::BeginQueryIndexed>(target, index, id, src_loc);
}

void GlIndirect::BeginTransformFeedback(const Enum& primitiveMode, const SrcLoc& src_loc){
    return _callGL<&Gl::BeginTransformFeedback>(primitiveMode, src_loc);
}

void GlIndirect::BindAttribLocation(const Uint& program, const Uint& index, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::BindAttribLocation>(program, index, name, src_loc);
}

void GlIndirect::BindBuffer(const Enum& target, const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::BindBuffer>(target, buffer, src_loc);
}

void GlIndirect::BindBufferBase(const Enum& target, const Uint& index, const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::BindBufferBase>(target, index, buffer, src_loc);
}

void GlIndirect::BindBufferRange(const Enum& target, const Uint& index, const Uint& buffer, const Intptr& offset, const Sizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&Gl::BindBufferRange>(target, index, buffer, offset, size, src_loc);
}

void GlIndirect::BindBuffersBase(const Enum& target, const Uint& first, const Sizei& count, const UintArr& buffers, const SrcLoc& src_loc){
    return _callGL<&Gl::BindBuffersBase>(target, first, count, buffers, src_loc);
}

void GlIndirect::BindBuffersRange(const Enum& target, const Uint& first, const Sizei& count, const UintArr& buffers, const IntptrArr& offsets, const SizeiptrArr& sizes, const SrcLoc& src_loc){
    return _callGL<&Gl::BindBuffersRange>(target, first, count, buffers, offsets, sizes, src_loc);
}

void GlIndirect::BindFragDataLocation(const Uint& program, const Uint& color, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::BindFragDataLocation>(program, color, name, src_loc);
}

void GlIndirect::BindFragDataLocationIndexed(const Uint& program, const Uint& colorNumber, const Uint& index, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::BindFragDataLocationIndexed>(program, colorNumber, index, name, src_loc);
}

void GlIndirect::BindFramebuffer(const Enum& target, const Uint& framebuffer, const SrcLoc& src_loc){
    return _callGL<&Gl::BindFramebuffer>(target, framebuffer, src_loc);
}

void GlIndirect::BindImageTexture(const Uint& unit, const Uint& texture, const Int& level, const Boolean& layered, const Int& layer, const Enum& access, const Enum& format, const SrcLoc& src_loc){
    return _callGL<&Gl::BindImageTexture>(unit, texture, level, layered, layer, access, format, src_loc);
}

void GlIndirect::BindImageTextures(const Uint& first, const Sizei& count, const UintArr& textures, const SrcLoc& src_loc){
    return _callGL<&Gl::BindImageTextures>(first, count, textures, src_loc);
}

void GlIndirect::BindProgramPipeline(const Uint& pipeline, const SrcLoc& src_loc){
    return _callGL<&Gl::BindProgramPipeline>(pipeline, src_loc);
}

void GlIndirect::BindRenderbuffer(const Enum& target, const Uint& renderbuffer, const SrcLoc& src_loc){
    return _callGL<&Gl::BindRenderbuffer>(target, renderbuffer, src_loc);
}

void GlIndirect::BindSampler(const Uint& unit, const Uint& sampler, const SrcLoc& src_loc){
    return _callGL<&Gl::BindSampler>(unit, sampler, src_loc);
}

void GlIndirect::BindSamplers(const Uint& first, const Sizei& count, const UintArr& samplers, const SrcLoc& src_loc){
    return _callGL<&Gl::BindSamplers>(first, count, samplers, src_loc);
}

void GlIndirect::BindTexture(const Enum& target, const Uint& texture, const SrcLoc& src_loc){
    return _callGL<&Gl::BindTexture>(target, texture, src_loc);
}

void GlIndirect::BindTextureUnit(const Uint& unit, const Uint& texture, const SrcLoc& src_loc){
    return _callGL<&Gl::BindTextureUnit>(unit, texture, src_loc);
}

void GlIndirect::BindTextures(const Uint& first, const Sizei& count, const UintArr& textures, const SrcLoc& src_loc){
    return _callGL<&Gl::BindTextures>(first, count, textures, src_loc);
}

void GlIndirect::BindTransformFeedback(const Enum& target, const Uint& id, const SrcLoc& src_loc){
    return _callGL<&Gl::BindTransformFeedback>(target, id, src_loc);
}

void GlIndirect::BindVertexArray(const Uint& array, const SrcLoc& src_loc){
    return _callGL<&Gl::BindVertexArray>(array, src_loc);
}

void GlIndirect::BindVertexBuffer(const Uint& bindingindex, const Uint& buffer, const Intptr& offset, const Sizei& stride, const SrcLoc& src_loc){
    return _callGL<&Gl::BindVertexBuffer>(bindingindex, buffer, offset, stride, src_loc);
}

void GlIndirect::BindVertexBuffers(const Uint& first, const Sizei& count, const UintArr& buffers, const IntptrArr& offsets, const SizeiArr& strides, const SrcLoc& src_loc){
    return _callGL<&Gl::BindVertexBuffers>(first, count, buffers, offsets, strides, src_loc);
}

void GlIndirect::BlendColor(const Float& red, const Float& green, const Float& blue, const Float& alpha, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendColor>(red, green, blue, alpha, src_loc);
}

void GlIndirect::BlendEquation(const Enum& mode, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendEquation>(mode, src_loc);
}

void GlIndirect::BlendEquationSeparate(const Enum& modeRGB, const Enum& modeAlpha, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendEquationSeparate>(modeRGB, modeAlpha, src_loc);
}

void GlIndirect::BlendEquationSeparatei(const Uint& buf, const Enum& modeRGB, const Enum& modeAlpha, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendEquationSeparatei>(buf, modeRGB, modeAlpha, src_loc);
}

void GlIndirect::BlendEquationi(const Uint& buf, const Enum& mode, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendEquationi>(buf, mode, src_loc);
}

void GlIndirect::BlendFunc(const Enum& sfactor, const Enum& dfactor, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendFunc>(sfactor, dfactor, src_loc);
}

void GlIndirect::BlendFuncSeparate(const Enum& sfactorRGB, const Enum& dfactorRGB, const Enum& sfactorAlpha, const Enum& dfactorAlpha, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendFuncSeparate>(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha, src_loc);
}

void GlIndirect::BlendFuncSeparatei(const Uint& buf, const Enum& srcRGB, const Enum& dstRGB, const Enum& srcAlpha, const Enum& dstAlpha, const Enum& modeAlpha, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendFuncSeparatei>(buf, srcRGB, dstRGB, srcAlpha, dstAlpha, modeAlpha, src_loc);
}

void GlIndirect::BlendFunci(const Uint& buf, const Enum& src, const Enum& dst, const SrcLoc& src_loc){
    return _callGL<&Gl::BlendFunci>(buf, src, dst, src_loc);
}

void GlIndirect::BlitFramebuffer(const Int& srcX0, const Int& srcY0, const Int& srcX1, const Int& srcY1, const Int& dstX0, const Int& dstY0, const Int& dstX1, const Int& dstY1, const Bitfield& mask, const Enum& filter, const SrcLoc& src_loc){
    return _callGL<&Gl::BlitFramebuffer>(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter, src_loc);
}

void GlIndirect::BlitNamedFramebuffer(const Uint& readFramebuffer, const Uint& drawFramebuffer, const Int& srcX0, const Int& srcY0, const Int& srcX1, const Int& srcY1, const Int& dstX0, const Int& dstY0, const Int& dstX1, const Int& dstY1, const Bitfield& mask, const Enum& filter, const SrcLoc& src_loc){
    return _callGL<&Gl::BlitNamedFramebuffer>(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter, src_loc);
}

void GlIndirect::BufferData(const Enum& target, const Sizeiptr& size, const Data& data, const Enum& usage, const SrcLoc& src_loc){
    return _callGL<&Gl::BufferData>(target, size, data, usage, src_loc);
}

void GlIndirect::BufferStorage(const Enum& target, const Sizeiptr& size, const Data& data, const Bitfield& flags, const SrcLoc& src_loc){
    return _callGL<&Gl::BufferStorage>(target, size, data, flags, src_loc);
}

void GlIndirect::BufferSubData(const Enum& target, const Intptr& offset, const Sizeiptr& size, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::BufferSubData>(target, offset, size, data, src_loc);
}

GL::Enum GlIndirect::CheckFramebufferStatus(const Enum& target, const SrcLoc& src_loc){
    return _callGL<&Gl::CheckFramebufferStatus>(target, src_loc);
}

GL::Enum GlIndirect::CheckNamedFramebufferStatus(const Uint& framebuffer, const Enum& target, const SrcLoc& src_loc){
    return _callGL<&Gl::CheckNamedFramebufferStatus>(framebuffer, target, src_loc);
}

void GlIndirect::ClampColor(const Enum& target, const Enum& clamp, const SrcLoc& src_loc){
    return _callGL<&Gl::ClampColor>(target, clamp, src_loc);
}

void GlIndirect::Clear(const Bitfield& mask, const SrcLoc& src_loc){
    return _callGL<&Gl::Clear>(mask, src_loc);
}

void GlIndirect::ClearBufferData(const Enum& target, const Enum& internalformat, const Enum& format, const Enum& type, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearBufferData>(target, internalformat, format, type, data, src_loc);
}

void GlIndirect::ClearBufferSubData(const Enum& target, const Enum& internalformat, const Intptr& offset, const Sizeiptr& size, const Enum& format, const Enum& type, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearBufferSubData>(target, internalformat, offset, size, format, type, data, src_loc);
}

void GlIndirect::ClearBufferfi(const Enum& buffer, const Int& drawbuffer, const Float& depth, const Int& stencil, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearBufferfi>(buffer, drawbuffer, depth, stencil, src_loc);
}

void GlIndirect::ClearBufferfv(const Enum& buffer, const Int& drawbuffer, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearBufferfv>(buffer, drawbuffer, value, src_loc);
}

void GlIndirect::ClearBufferiv(const Enum& buffer, const Int& drawbuffer, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearBufferiv>(buffer, drawbuffer, value, src_loc);
}

void GlIndirect::ClearBufferuiv(const Enum& buffer, const Int& drawbuffer, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearBufferuiv>(buffer, drawbuffer, value, src_loc);
}

void GlIndirect::ClearColor(const Float& red, const Float& green, const Float& blue, const Float& alpha, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearColor>(red, green, blue, alpha, src_loc);
}

void GlIndirect::ClearDepth(const Double& depth, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearDepth>(depth, src_loc);
}

void GlIndirect::ClearDepthf(const Float& d, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearDepthf>(d, src_loc);
}

void GlIndirect::ClearNamedBufferData(const Uint& buffer, const Enum& internalformat, const Enum& format, const Enum& type, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearNamedBufferData>(buffer, internalformat, format, type, data, src_loc);
}

void GlIndirect::ClearNamedBufferSubData(const Uint& buffer, const Enum& internalformat, const Intptr& offset, const Sizeiptr& size, const Enum& format, const Enum& type, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearNamedBufferSubData>(buffer, internalformat, offset, size, format, type, data, src_loc);
}

void GlIndirect::ClearNamedFramebufferfi(const Uint& framebuffer, const Enum& buffer, const Int& drawbuffer, const Float& depth, const Int& stencil, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearNamedFramebufferfi>(framebuffer, buffer, drawbuffer, depth, stencil, src_loc);
}

void GlIndirect::ClearNamedFramebufferfv(const Uint& framebuffer, const Enum& buffer, const Int& drawbuffer, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearNamedFramebufferfv>(framebuffer, buffer, drawbuffer, value, src_loc);
}

void GlIndirect::ClearNamedFramebufferiv(const Uint& framebuffer, const Enum& buffer, const Int& drawbuffer, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearNamedFramebufferiv>(framebuffer, buffer, drawbuffer, value, src_loc);
}

void GlIndirect::ClearNamedFramebufferuiv(const Uint& framebuffer, const Enum& buffer, const Int& drawbuffer, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearNamedFramebufferuiv>(framebuffer, buffer, drawbuffer, value, src_loc);
}

void GlIndirect::ClearStencil(const Int& s, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearStencil>(s, src_loc);
}

void GlIndirect::ClearTexImage(const Uint& texture, const Int& level, const Enum& format, const Enum& type, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearTexImage>(texture, level, format, type, data, src_loc);
}

void GlIndirect::ClearTexSubImage(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& width, const Sizei& height, const Sizei& depth, const Enum& format, const Enum& type, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::ClearTexSubImage>(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data, src_loc);
}

GL::Enum GlIndirect::ClientWaitSync(const Sync& sync, const Bitfield& flags, const Uint64& timeout, const SrcLoc& src_loc){
    return _callGL<&Gl::ClientWaitSync>(sync, flags, timeout, src_loc);
}

void GlIndirect::ClipControl(const Enum& origin, const Enum& depth, const SrcLoc& src_loc){
    return _callGL<&Gl::ClipControl>(origin, depth, src_loc);
}

void GlIndirect::ColorMask(const Boolean& red, const Boolean& green, const Boolean& blue, const Boolean& alpha, const SrcLoc& src_loc){
    return _callGL<&Gl::ColorMask>(red, green, blue, alpha, src_loc);
}

void GlIndirect::ColorMaski(const Uint& index, const Boolean& r, const Boolean& g, const Boolean& b, const Boolean& a, const SrcLoc& src_loc){
    return _callGL<&Gl::ColorMaski>(index, r, g, b, a, src_loc);
}

void GlIndirect::CompileShader(const Uint& shader, const SrcLoc& src_loc){
    return _callGL<&Gl::CompileShader>(shader, src_loc);
}

void GlIndirect::CompressedTexImage1D(const Enum& target, const Int& level, const Enum& internalformat, const Sizei& width, const Int& border, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTexImage1D>(target, level, internalformat, width, border, imageSize, data, src_loc);
}

void GlIndirect::CompressedTexImage2D(const Enum& target, const Int& level, const Enum& internalformat, const Sizei& width, const Sizei& height, const Int& border, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTexImage2D>(target, level, internalformat, width, height, border, imageSize, data, src_loc);
}

void GlIndirect::CompressedTexImage3D(const Enum& target, const Int& level, const Enum& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const Int& border, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTexImage3D>(target, level, internalformat, width, height, depth, border, imageSize, data, src_loc);
}

void GlIndirect::CompressedTexSubImage1D(const Enum& target, const Int& level, const Int& xoffset, const Sizei& width, const Enum& format, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTexSubImage1D>(target, level, xoffset, width, format, imageSize, data, src_loc);
}

void GlIndirect::CompressedTexSubImage2D(const Enum& target, const Int& level, const Int& xoffset, const Int& yoffset, const Sizei& width, const Sizei& height, const Enum& format, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTexSubImage2D>(target, level, xoffset, yoffset, width, height, format, imageSize, data, src_loc);
}

void GlIndirect::CompressedTexSubImage3D(const Enum& target, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& width, const Sizei& height, const Sizei& depth, const Enum& format, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTexSubImage3D>(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data, src_loc);
}

void GlIndirect::CompressedTextureSubImage1D(const Uint& texture, const Int& level, const Int& xoffset, const Sizei& width, const Enum& format, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTextureSubImage1D>(texture, level, xoffset, width, format, imageSize, data, src_loc);
}

void GlIndirect::CompressedTextureSubImage2D(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Sizei& width, const Sizei& height, const Enum& format, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTextureSubImage2D>(texture, level, xoffset, yoffset, width, height, format, imageSize, data, src_loc);
}

void GlIndirect::CompressedTextureSubImage3D(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& width, const Sizei& height, const Sizei& depth, const Enum& format, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::CompressedTextureSubImage3D>(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data, src_loc);
}

void GlIndirect::CopyBufferSubData(const Enum& readTarget, const Enum& writeTarget, const Intptr& readOffset, const Intptr& writeOffset, const Sizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyBufferSubData>(readTarget, writeTarget, readOffset, writeOffset, size, src_loc);
}

void GlIndirect::CopyImageSubData(const Uint& srcName, const Enum& srcTarget, const Int& srcLevel, const Int& srcX, const Int& srcY, const Int& srcZ, const Uint& dstName, const Enum& dstTarget, const Int& dstLevel, const Int& dstX, const Int& dstY, const Int& dstZ, const Sizei& srcWidth, const Sizei& srcHeight, const Sizei& srcDepth, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyImageSubData>(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth, src_loc);
}

void GlIndirect::CopyNamedBufferSubData(const Uint& readBuffer, const Uint& writeBuffer, const Intptr& readOffset, const Intptr& writeOffset, const Sizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyNamedBufferSubData>(readBuffer, writeBuffer, readOffset, writeOffset, size, src_loc);
}

void GlIndirect::CopyTexImage1D(const Enum& target, const Int& level, const Enum& internalformat, const Int& x, const Int& y, const Sizei& width, const Int& border, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyTexImage1D>(target, level, internalformat, x, y, width, border, src_loc);
}

void GlIndirect::CopyTexImage2D(const Enum& target, const Int& level, const Enum& internalformat, const Int& x, const Int& y, const Sizei& width, const Sizei& height, const Int& border, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyTexImage2D>(target, level, internalformat, x, y, width, height, border, src_loc);
}

void GlIndirect::CopyTexSubImage1D(const Enum& target, const Int& level, const Int& xoffset, const Int& x, const Int& y, const Sizei& width, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyTexSubImage1D>(target, level, xoffset, x, y, width, src_loc);
}

void GlIndirect::CopyTexSubImage2D(const Enum& target, const Int& level, const Int& xoffset, const Int& yoffset, const Int& x, const Int& y, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyTexSubImage2D>(target, level, xoffset, yoffset, x, y, width, height, src_loc);
}

void GlIndirect::CopyTexSubImage3D(const Enum& target, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Int& x, const Int& y, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyTexSubImage3D>(target, level, xoffset, yoffset, zoffset, x, y, width, height, src_loc);
}

void GlIndirect::CopyTextureSubImage1D(const Uint& texture, const Int& level, const Int& xoffset, const Int& x, const Int& y, const Sizei& width, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyTextureSubImage1D>(texture, level, xoffset, x, y, width, src_loc);
}

void GlIndirect::CopyTextureSubImage2D(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Int& x, const Int& y, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyTextureSubImage2D>(texture, level, xoffset, yoffset, x, y, width, height, src_loc);
}

void GlIndirect::CopyTextureSubImage3D(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Int& x, const Int& y, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::CopyTextureSubImage3D>(texture, level, xoffset, yoffset, zoffset, x, y, width, height, src_loc);
}

void GlIndirect::CreateBuffers(const Sizei& n, const UintArr& dst, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateBuffers>(n, dst, src_loc);
}

void GlIndirect::CreateFramebuffers(const Sizei& n, const UintArr& framebuffers, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateFramebuffers>(n, framebuffers, src_loc);
}

GL::Uint GlIndirect::CreateProgram(const SrcLoc& src_loc){
    return _callGL<&Gl::CreateProgram>(src_loc);
}

void GlIndirect::CreateProgramPipelines(const Sizei& n, const UintArr& pipelines, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateProgramPipelines>(n, pipelines, src_loc);
}

void GlIndirect::CreateQueries(const Enum& target, const Sizei& n, const UintArr& ids, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateQueries>(target, n, ids, src_loc);
}

void GlIndirect::CreateRenderbuffers(const Sizei& n, const UintArr& renderbuffers, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateRenderbuffers>(n, renderbuffers, src_loc);
}

void GlIndirect::CreateSamplers(const Sizei& n, const UintArr& samplers, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateSamplers>(n, samplers, src_loc);
}

GL::Uint GlIndirect::CreateShader(const Enum& type, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateShader>(type, src_loc);
}

GL::Uint GlIndirect::CreateShaderProgramv(const Enum& type, const Sizei& count, const StringArr& strings, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateShaderProgramv>(type, count, strings, src_loc);
}

void GlIndirect::CreateTextures(const Enum& target, const Sizei& n, const UintArr& textures, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateTextures>(target, n, textures, src_loc);
}

void GlIndirect::CreateTransformFeedbacks(const Sizei& n, const UintArr& ids, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateTransformFeedbacks>(n, ids, src_loc);
}

void GlIndirect::CreateVertexArrays(const Sizei& n, const UintArr& arrays, const SrcLoc& src_loc){
    return _callGL<&Gl::CreateVertexArrays>(n, arrays, src_loc);
}

void GlIndirect::CullFace(const Enum& mode, const SrcLoc& src_loc){
    return _callGL<&Gl::CullFace>(mode, src_loc);
}

void GlIndirect::DebugMessageControl(const Enum& source, const Enum& type, const Enum& severity, const Sizei& count, const UintArr& ids, const Boolean& enabled, const SrcLoc& src_loc){
    return _callGL<&Gl::DebugMessageControl>(source, type, severity, count, ids, enabled, src_loc);
}

void GlIndirect::DebugMessageInsert(const Enum& source, const Enum& type, const Uint& id, const Enum& severity, const Sizei& length, const String& buf, const SrcLoc& src_loc){
    return _callGL<&Gl::DebugMessageInsert>(source, type, id, severity, length, buf, src_loc);
}

void GlIndirect::DeleteBuffers(const Sizei& n, const UintArr& buffers, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteBuffers>(n, buffers, src_loc);
}

void GlIndirect::DeleteFramebuffers(const Sizei& n, const UintArr& framebuffers, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteFramebuffers>(n, framebuffers, src_loc);
}

void GlIndirect::DeleteProgram(const Uint& program, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteProgram>(program, src_loc);
}

void GlIndirect::DeleteProgramPipelines(const Sizei& n, const UintArr& pipelines, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteProgramPipelines>(n, pipelines, src_loc);
}

void GlIndirect::DeleteQueries(const Sizei& n, const UintArr& ids, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteQueries>(n, ids, src_loc);
}

void GlIndirect::DeleteRenderbuffers(const Sizei& n, const UintArr& renderbuffers, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteRenderbuffers>(n, renderbuffers, src_loc);
}

void GlIndirect::DeleteSamplers(const Sizei& count, const UintArr& samplers, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteSamplers>(count, samplers, src_loc);
}

void GlIndirect::DeleteShader(const Uint& shader, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteShader>(shader, src_loc);
}

void GlIndirect::DeleteSync(const Sync& sync, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteSync>(sync, src_loc);
}

void GlIndirect::DeleteTextures(const Sizei& n, const UintArr& textures, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteTextures>(n, textures, src_loc);
}

void GlIndirect::DeleteTransformFeedbacks(const Sizei& n, const UintArr& ids, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteTransformFeedbacks>(n, ids, src_loc);
}

void GlIndirect::DeleteVertexArrays(const Sizei& n, const UintArr& arrays, const SrcLoc& src_loc){
    return _callGL<&Gl::DeleteVertexArrays>(n, arrays, src_loc);
}

void GlIndirect::DepthFunc(const Enum& func, const SrcLoc& src_loc){
    return _callGL<&Gl::DepthFunc>(func, src_loc);
}

void GlIndirect::DepthMask(const Boolean& flag, const SrcLoc& src_loc){
    return _callGL<&Gl::DepthMask>(flag, src_loc);
}

void GlIndirect::DepthRange(const Double& n, const Double& f, const SrcLoc& src_loc){
    return _callGL<&Gl::DepthRange>(n, f, src_loc);
}

void GlIndirect::DepthRangeArrayv(const Uint& first, const Sizei& count, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::DepthRangeArrayv>(first, count, v, src_loc);
}

void GlIndirect::DepthRangeIndexed(const Uint& index, const Double& n, const Double& f, const SrcLoc& src_loc){
    return _callGL<&Gl::DepthRangeIndexed>(index, n, f, src_loc);
}

void GlIndirect::DepthRangef(const Float& n, const Float& f, const SrcLoc& src_loc){
    return _callGL<&Gl::DepthRangef>(n, f, src_loc);
}

void GlIndirect::DetachShader(const Uint& program, const Uint& shader, const SrcLoc& src_loc){
    return _callGL<&Gl::DetachShader>(program, shader, src_loc);
}

void GlIndirect::Disable(const Enum& cap, const SrcLoc& src_loc){
    return _callGL<&Gl::Disable>(cap, src_loc);
}

void GlIndirect::DisableVertexArrayAttrib(const Uint& vaobj, const Uint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::DisableVertexArrayAttrib>(vaobj, index, src_loc);
}

void GlIndirect::DisableVertexAttribArray(const Uint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::DisableVertexAttribArray>(index, src_loc);
}

void GlIndirect::Disablei(const Enum& target, const Uint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::Disablei>(target, index, src_loc);
}

void GlIndirect::DispatchCompute(const Uint& num_groups_x, const Uint& num_groups_y, const Uint& num_groups_z, const SrcLoc& src_loc){
    return _callGL<&Gl::DispatchCompute>(num_groups_x, num_groups_y, num_groups_z, src_loc);
}

void GlIndirect::DispatchComputeIndirect(const Intptr& indirect, const SrcLoc& src_loc){
    return _callGL<&Gl::DispatchComputeIndirect>(indirect, src_loc);
}

void GlIndirect::DrawArrays(const Enum& mode, const Int& first, const Sizei& count, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawArrays>(mode, first, count, src_loc);
}

void GlIndirect::DrawArraysIndirect(const Enum& mode, const Data& indirect, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawArraysIndirect>(mode, indirect, src_loc);
}

void GlIndirect::DrawArraysInstanced(const Enum& mode, const Int& first, const Sizei& count, const Sizei& instancecount, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawArraysInstanced>(mode, first, count, instancecount, src_loc);
}

void GlIndirect::DrawArraysInstancedBaseInstance(const Enum& mode, const Int& first, const Sizei& count, const Sizei& instancecount, const Uint& baseinstance, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawArraysInstancedBaseInstance>(mode, first, count, instancecount, baseinstance, src_loc);
}

void GlIndirect::DrawBuffer(const Enum& buf, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawBuffer>(buf, src_loc);
}

void GlIndirect::DrawBuffers(const Sizei& n, const EnumArr& bufs, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawBuffers>(n, bufs, src_loc);
}

void GlIndirect::DrawElements(const Enum& mode, const Sizei& count, const Enum& type, const Data& indices, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawElements>(mode, count, type, indices, src_loc);
}

void GlIndirect::DrawElementsBaseVertex(const Enum& mode, const Sizei& count, const Enum& type, const Data& indices, const Int& basevertex, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawElementsBaseVertex>(mode, count, type, indices, basevertex, src_loc);
}

void GlIndirect::DrawElementsIndirect(const Enum& mode, const Enum& type, const Data& indirect, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawElementsIndirect>(mode, type, indirect, src_loc);
}

void GlIndirect::DrawElementsInstanced(const Enum& mode, const Sizei& count, const Enum& type, const Data& indices, const Sizei& instancecount, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawElementsInstanced>(mode, count, type, indices, instancecount, src_loc);
}

void GlIndirect::DrawElementsInstancedBaseInstance(const Enum& mode, const Sizei& count, const Enum& type, const Data& indices, const Sizei& instancecount, const Uint& baseinstance, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawElementsInstancedBaseInstance>(mode, count, type, indices, instancecount, baseinstance, src_loc);
}

void GlIndirect::DrawElementsInstancedBaseVertex(const Enum& mode, const Sizei& count, const Enum& type, const Data& indices, const Sizei& instancecount, const Int& basevertex, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawElementsInstancedBaseVertex>(mode, count, type, indices, instancecount, basevertex, src_loc);
}

void GlIndirect::DrawElementsInstancedBaseVertexBaseInstance(const Enum& mode, const Sizei& count, const Enum& type, const Data& indices, const Sizei& instancecount, const Int& basevertex, const Uint& baseinstance, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawElementsInstancedBaseVertexBaseInstance>(mode, count, type, indices, instancecount, basevertex, baseinstance, src_loc);
}

void GlIndirect::DrawRangeElements(const Enum& mode, const Uint& start, const Uint& end, const Sizei& count, const Enum& type, const Data& indices, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawRangeElements>(mode, start, end, count, type, indices, src_loc);
}

void GlIndirect::DrawRangeElementsBaseVertex(const Enum& mode, const Uint& start, const Uint& end, const Sizei& count, const Enum& type, const Data& indices, const Int& basevertex, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawRangeElementsBaseVertex>(mode, start, end, count, type, indices, basevertex, src_loc);
}

void GlIndirect::DrawTransformFeedback(const Enum& mode, const Uint& id, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawTransformFeedback>(mode, id, src_loc);
}

void GlIndirect::DrawTransformFeedbackInstanced(const Enum& mode, const Uint& id, const Sizei& instancecount, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawTransformFeedbackInstanced>(mode, id, instancecount, src_loc);
}

void GlIndirect::DrawTransformFeedbackStream(const Enum& mode, const Uint& id, const Uint& stream, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawTransformFeedbackStream>(mode, id, stream, src_loc);
}

void GlIndirect::DrawTransformFeedbackStreamInstanced(const Enum& mode, const Uint& id, const Uint& stream, const Sizei& instancecount, const SrcLoc& src_loc){
    return _callGL<&Gl::DrawTransformFeedbackStreamInstanced>(mode, id, stream, instancecount, src_loc);
}

void GlIndirect::Enable(const Enum& cap, const SrcLoc& src_loc){
    return _callGL<&Gl::Enable>(cap, src_loc);
}

void GlIndirect::EnableVertexArrayAttrib(const Uint& vaobj, const Uint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::EnableVertexArrayAttrib>(vaobj, index, src_loc);
}

void GlIndirect::EnableVertexAttribArray(const Uint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::EnableVertexAttribArray>(index, src_loc);
}

void GlIndirect::Enablei(const Enum& target, const Uint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::Enablei>(target, index, src_loc);
}

void GlIndirect::EndConditionalRender(const SrcLoc& src_loc){
    return _callGL<&Gl::EndConditionalRender>(src_loc);
}

void GlIndirect::EndQuery(const Enum& target, const SrcLoc& src_loc){
    return _callGL<&Gl::EndQuery>(target, src_loc);
}

void GlIndirect::EndQueryIndexed(const Enum& target, const Uint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::EndQueryIndexed>(target, index, src_loc);
}

void GlIndirect::EndTransformFeedback(const SrcLoc& src_loc){
    return _callGL<&Gl::EndTransformFeedback>(src_loc);
}

GL::Sync GlIndirect::FenceSync(const Enum& condition, const Bitfield& flags, const SrcLoc& src_loc){
    return _callGL<&Gl::FenceSync>(condition, flags, src_loc);
}

void GlIndirect::Finish(const SrcLoc& src_loc){
    return _callGL<&Gl::Finish>(src_loc);
}

void GlIndirect::Flush(const SrcLoc& src_loc){
    return _callGL<&Gl::Flush>(src_loc);
}

void GlIndirect::FlushMappedBufferRange(const Enum& target, const Intptr& offset, const Sizeiptr& length, const SrcLoc& src_loc){
    return _callGL<&Gl::FlushMappedBufferRange>(target, offset, length, src_loc);
}

void GlIndirect::FlushMappedNamedBufferRange(const Uint& buffer, const Intptr& offset, const Sizeiptr& length, const SrcLoc& src_loc){
    return _callGL<&Gl::FlushMappedNamedBufferRange>(buffer, offset, length, src_loc);
}

void GlIndirect::FramebufferParameteri(const Enum& target, const Enum& pname, const Int& param, const SrcLoc& src_loc){
    return _callGL<&Gl::FramebufferParameteri>(target, pname, param, src_loc);
}

void GlIndirect::FramebufferRenderbuffer(const Enum& target, const Enum& attachment, const Enum& renderbuffertarget, const Uint& renderbuffer, const SrcLoc& src_loc){
    return _callGL<&Gl::FramebufferRenderbuffer>(target, attachment, renderbuffertarget, renderbuffer, src_loc);
}

void GlIndirect::FramebufferTexture(const Enum& target, const Enum& attachment, const Uint& texture, const Int& level, const SrcLoc& src_loc){
    return _callGL<&Gl::FramebufferTexture>(target, attachment, texture, level, src_loc);
}

void GlIndirect::FramebufferTexture1D(const Enum& target, const Enum& attachment, const Enum& textarget, const Uint& texture, const Int& level, const SrcLoc& src_loc){
    return _callGL<&Gl::FramebufferTexture1D>(target, attachment, textarget, texture, level, src_loc);
}

void GlIndirect::FramebufferTexture2D(const Enum& target, const Enum& attachment, const Enum& textarget, const Uint& texture, const Int& level, const SrcLoc& src_loc){
    return _callGL<&Gl::FramebufferTexture2D>(target, attachment, textarget, texture, level, src_loc);
}

void GlIndirect::FramebufferTexture3D(const Enum& target, const Enum& attachment, const Enum& textarget, const Uint& texture, const Int& level, const Int& zoffset, const SrcLoc& src_loc){
    return _callGL<&Gl::FramebufferTexture3D>(target, attachment, textarget, texture, level, zoffset, src_loc);
}

void GlIndirect::FramebufferTextureLayer(const Enum& target, const Enum& attachment, const Uint& texture, const Int& level, const Int& layer, const SrcLoc& src_loc){
    return _callGL<&Gl::FramebufferTextureLayer>(target, attachment, texture, level, layer, src_loc);
}

void GlIndirect::FrontFace(const Enum& mode, const SrcLoc& src_loc){
    return _callGL<&Gl::FrontFace>(mode, src_loc);
}

void GlIndirect::GenBuffers(const Sizei& n, const UintArr& buffers, const SrcLoc& src_loc){
    return _callGL<&Gl::GenBuffers>(n, buffers, src_loc);
}

void GlIndirect::GenFramebuffers(const Sizei& n, const UintArr& framebuffers, const SrcLoc& src_loc){
    return _callGL<&Gl::GenFramebuffers>(n, framebuffers, src_loc);
}

void GlIndirect::GenProgramPipelines(const Sizei& n, const UintArr& pipelines, const SrcLoc& src_loc){
    return _callGL<&Gl::GenProgramPipelines>(n, pipelines, src_loc);
}

void GlIndirect::GenQueries(const Sizei& n, const UintArr& ids, const SrcLoc& src_loc){
    return _callGL<&Gl::GenQueries>(n, ids, src_loc);
}

void GlIndirect::GenRenderbuffers(const Sizei& n, const UintArr& renderbuffers, const SrcLoc& src_loc){
    return _callGL<&Gl::GenRenderbuffers>(n, renderbuffers, src_loc);
}

void GlIndirect::GenSamplers(const Sizei& count, const UintArr& samplers, const SrcLoc& src_loc){
    return _callGL<&Gl::GenSamplers>(count, samplers, src_loc);
}

void GlIndirect::GenTextures(const Sizei& n, const UintArr& textures, const SrcLoc& src_loc){
    return _callGL<&Gl::GenTextures>(n, textures, src_loc);
}

void GlIndirect::GenTransformFeedbacks(const Sizei& n, const UintArr& ids, const SrcLoc& src_loc){
    return _callGL<&Gl::GenTransformFeedbacks>(n, ids, src_loc);
}

void GlIndirect::GenVertexArrays(const Sizei& n, const UintArr& arrays, const SrcLoc& src_loc){
    return _callGL<&Gl::GenVertexArrays>(n, arrays, src_loc);
}

void GlIndirect::GenerateMipmap(const Enum& target, const SrcLoc& src_loc){
    return _callGL<&Gl::GenerateMipmap>(target, src_loc);
}

void GlIndirect::GenerateTextureMipmap(const Uint& texture, const SrcLoc& src_loc){
    return _callGL<&Gl::GenerateTextureMipmap>(texture, src_loc);
}

void GlIndirect::GetActiveAtomicCounterBufferiv(const Uint& program, const Uint& bufferIndex, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveAtomicCounterBufferiv>(program, bufferIndex, pname, params, src_loc);
}

void GlIndirect::GetActiveAttrib(const Uint& program, const Uint& index, const Sizei& bufSize, const Sizei& length, const Int& size, const Enum& type, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveAttrib>(program, index, bufSize, length, size, type, name, src_loc);
}

void GlIndirect::GetActiveSubroutineName(const Uint& program, const Enum& shadertype, const Uint& index, const Sizei& bufSize, const Sizei& length, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveSubroutineName>(program, shadertype, index, bufSize, length, name, src_loc);
}

void GlIndirect::GetActiveSubroutineUniformName(const Uint& program, const Enum& shadertype, const Uint& index, const Sizei& bufSize, const Sizei& length, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveSubroutineUniformName>(program, shadertype, index, bufSize, length, name, src_loc);
}

void GlIndirect::GetActiveSubroutineUniformiv(const Uint& program, const Enum& shadertype, const Uint& index, const Enum& pname, const IntArr& values, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveSubroutineUniformiv>(program, shadertype, index, pname, values, src_loc);
}

void GlIndirect::GetActiveUniform(const Uint& program, const Uint& index, const Sizei& bufSize, const Sizei& length, const Int& size, const Enum& type, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveUniform>(program, index, bufSize, length, size, type, name, src_loc);
}

void GlIndirect::GetActiveUniformBlockName(const Uint& program, const Uint& uniformBlockIndex, const Sizei& bufSize, const Sizei& length, const String& uniformBlockName, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveUniformBlockName>(program, uniformBlockIndex, bufSize, length, uniformBlockName, src_loc);
}

void GlIndirect::GetActiveUniformBlockiv(const Uint& program, const Uint& uniformBlockIndex, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveUniformBlockiv>(program, uniformBlockIndex, pname, params, src_loc);
}

void GlIndirect::GetActiveUniformName(const Uint& program, const Uint& uniformIndex, const Sizei& bufSize, const Sizei& length, const String& uniformName, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveUniformName>(program, uniformIndex, bufSize, length, uniformName, src_loc);
}

void GlIndirect::GetActiveUniformsiv(const Uint& program, const Sizei& uniformCount, const UintArr& uniformIndices, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetActiveUniformsiv>(program, uniformCount, uniformIndices, pname, params, src_loc);
}

void GlIndirect::GetAttachedShaders(const Uint& program, const Sizei& maxCount, const SizeiArr& count, const UintArr& shaders, const SrcLoc& src_loc){
    return _callGL<&Gl::GetAttachedShaders>(program, maxCount, count, shaders, src_loc);
}

GL::Int GlIndirect::GetAttribLocation(const Uint& program, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetAttribLocation>(program, name, src_loc);
}

void GlIndirect::GetBooleani_v(const Enum& target, const Uint& index, const BooleanArr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetBooleani_v>(target, index, data, src_loc);
}

void GlIndirect::GetBooleanv(const Enum& pname, const BooleanArr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetBooleanv>(pname, data, src_loc);
}

void GlIndirect::GetBufferParameteri64v(const Enum& target, const Enum& pname, const Int64Arr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetBufferParameteri64v>(target, pname, params, src_loc);
}

void GlIndirect::GetBufferParameteriv(const Enum& target, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetBufferParameteriv>(target, pname, params, src_loc);
}

void GlIndirect::GetBufferPointerv(const Enum& target, const Enum& pname, const DataPtr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetBufferPointerv>(target, pname, params, src_loc);
}

void GlIndirect::GetBufferSubData(const Enum& target, const Intptr& offset, const Sizeiptr& size, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetBufferSubData>(target, offset, size, data, src_loc);
}

void GlIndirect::GetCompressedTexImage(const Enum& target, const Int& level, const Data& img, const SrcLoc& src_loc){
    return _callGL<&Gl::GetCompressedTexImage>(target, level, img, src_loc);
}

void GlIndirect::GetCompressedTextureImage(const Uint& texture, const Int& level, const Sizei& bufSize, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::GetCompressedTextureImage>(texture, level, bufSize, pixels, src_loc);
}

void GlIndirect::GetCompressedTextureSubImage(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& width, const Sizei& height, const Sizei& depth, const Sizei& bufSize, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::GetCompressedTextureSubImage>(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels, src_loc);
}

GL::Uint GlIndirect::GetDebugMessageLog(const Uint& count, const Sizei& bufSize, const EnumArr& sources, const EnumArr& types, const UintArr& ids, const EnumArr& severities, const Sizei& lengths, const String& messageLog, const SrcLoc& src_loc){
    return _callGL<&Gl::GetDebugMessageLog>(count, bufSize, sources, types, ids, severities, lengths, messageLog, src_loc);
}

void GlIndirect::GetDoublei_v(const Enum& target, const Uint& index, const DoubleArr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetDoublei_v>(target, index, data, src_loc);
}

void GlIndirect::GetDoublev(const Enum& pname, const DoubleArr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetDoublev>(pname, data, src_loc);
}

GL::Enum GlIndirect::GetError(const SrcLoc& src_loc){
    return _callGL<&Gl::GetError>(src_loc);
}

void GlIndirect::GetFloati_v(const Enum& target, const Uint& index, const FloatArr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetFloati_v>(target, index, data, src_loc);
}

void GlIndirect::GetFloatv(const Enum& pname, const FloatArr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetFloatv>(pname, data, src_loc);
}

GL::Int GlIndirect::GetFragDataIndex(const Uint& program, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetFragDataIndex>(program, name, src_loc);
}

GL::Int GlIndirect::GetFragDataLocation(const Uint& program, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetFragDataLocation>(program, name, src_loc);
}

void GlIndirect::GetFramebufferAttachmentParameteriv(const Enum& target, const Enum& attachment, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetFramebufferAttachmentParameteriv>(target, attachment, pname, params, src_loc);
}

void GlIndirect::GetFramebufferParameteriv(const Enum& target, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetFramebufferParameteriv>(target, pname, params, src_loc);
}

GL::Enum GlIndirect::GetGraphicsResetStatus(const SrcLoc& src_loc){
    return _callGL<&Gl::GetGraphicsResetStatus>(src_loc);
}

void GlIndirect::GetInteger64i_v(const Enum& target, const Uint& index, const Int64Arr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetInteger64i_v>(target, index, data, src_loc);
}

void GlIndirect::GetInteger64v(const Enum& pname, const Int64Arr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetInteger64v>(pname, data, src_loc);
}

void GlIndirect::GetIntegeri_v(const Enum& target, const Uint& index, const IntArr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetIntegeri_v>(target, index, data, src_loc);
}

void GlIndirect::GetIntegerv(const Enum& pname, const IntArr& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetIntegerv>(pname, data, src_loc);
}

void GlIndirect::GetInternalformati64v(const Enum& target, const Enum& internalformat, const Enum& pname, const Sizei& count, const Int64Arr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetInternalformati64v>(target, internalformat, pname, count, params, src_loc);
}

void GlIndirect::GetInternalformativ(const Enum& target, const Enum& internalformat, const Enum& pname, const Sizei& count, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetInternalformativ>(target, internalformat, pname, count, params, src_loc);
}

void GlIndirect::GetMultisamplefv(const Enum& pname, const Uint& index, const FloatArr& val, const SrcLoc& src_loc){
    return _callGL<&Gl::GetMultisamplefv>(pname, index, val, src_loc);
}

void GlIndirect::GetNamedBufferParameteri64v(const Uint& buffer, const Enum& pname, const Int64Arr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetNamedBufferParameteri64v>(buffer, pname, params, src_loc);
}

void GlIndirect::GetNamedBufferParameteriv(const Uint& buffer, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetNamedBufferParameteriv>(buffer, pname, params, src_loc);
}

void GlIndirect::GetNamedBufferPointerv(const Uint& buffer, const Enum& pname, const DataPtr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetNamedBufferPointerv>(buffer, pname, params, src_loc);
}

void GlIndirect::GetNamedBufferSubData(const Uint& buffer, const Intptr& offset, const Sizeiptr& size, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::GetNamedBufferSubData>(buffer, offset, size, data, src_loc);
}

void GlIndirect::GetNamedFramebufferAttachmentParameteriv(const Uint& framebuffer, const Enum& attachment, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetNamedFramebufferAttachmentParameteriv>(framebuffer, attachment, pname, params, src_loc);
}

void GlIndirect::GetNamedFramebufferParameteriv(const Uint& framebuffer, const Enum& pname, const IntArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::GetNamedFramebufferParameteriv>(framebuffer, pname, param, src_loc);
}

void GlIndirect::GetNamedRenderbufferParameteriv(const Uint& renderbuffer, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetNamedRenderbufferParameteriv>(renderbuffer, pname, params, src_loc);
}

void GlIndirect::GetObjectLabel(const Enum& identifier, const Uint& name, const Sizei& bufSize, const Sizei& length, const String& label, const SrcLoc& src_loc){
    return _callGL<&Gl::GetObjectLabel>(identifier, name, bufSize, length, label, src_loc);
}

void GlIndirect::GetObjectPtrLabel(const Data& ptr, const Sizei& bufSize, const Sizei& length, const String& label, const SrcLoc& src_loc){
    return _callGL<&Gl::GetObjectPtrLabel>(ptr, bufSize, length, label, src_loc);
}

void GlIndirect::GetPointerv(const Enum& pname, const DataPtr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetPointerv>(pname, params, src_loc);
}

void GlIndirect::GetProgramBinary(const Uint& program, const Sizei& bufSize, const Sizei& length, const EnumArr& binaryFormat, const Data& binary, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramBinary>(program, bufSize, length, binaryFormat, binary, src_loc);
}

void GlIndirect::GetProgramInfoLog(const Uint& program, const Sizei& bufSize, const Sizei& length, const String& infoLog, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramInfoLog>(program, bufSize, length, infoLog, src_loc);
}

void GlIndirect::GetProgramInterfaceiv(const Uint& program, const Enum& programInterface, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramInterfaceiv>(program, programInterface, pname, params, src_loc);
}

void GlIndirect::GetProgramPipelineInfoLog(const Uint& pipeline, const Sizei& bufSize, const Sizei& length, const String& infoLog, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramPipelineInfoLog>(pipeline, bufSize, length, infoLog, src_loc);
}

void GlIndirect::GetProgramPipelineiv(const Uint& pipeline, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramPipelineiv>(pipeline, pname, params, src_loc);
}

GL::Uint GlIndirect::GetProgramResourceIndex(const Uint& program, const Enum& programInterface, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramResourceIndex>(program, programInterface, name, src_loc);
}

GL::Int GlIndirect::GetProgramResourceLocation(const Uint& program, const Enum& programInterface, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramResourceLocation>(program, programInterface, name, src_loc);
}

GL::Int GlIndirect::GetProgramResourceLocationIndex(const Uint& program, const Enum& programInterface, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramResourceLocationIndex>(program, programInterface, name, src_loc);
}

void GlIndirect::GetProgramResourceName(const Uint& program, const Enum& programInterface, const Uint& index, const Sizei& bufSize, const Sizei& length, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramResourceName>(program, programInterface, index, bufSize, length, name, src_loc);
}

void GlIndirect::GetProgramResourceiv(const Uint& program, const Enum& programInterface, const Uint& index, const Sizei& propCount, const EnumArr& props, const Sizei& count, const Sizei& length, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramResourceiv>(program, programInterface, index, propCount, props, count, length, params, src_loc);
}

void GlIndirect::GetProgramStageiv(const Uint& program, const Enum& shadertype, const Enum& pname, const IntArr& values, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramStageiv>(program, shadertype, pname, values, src_loc);
}

void GlIndirect::GetProgramiv(const Uint& program, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetProgramiv>(program, pname, params, src_loc);
}

void GlIndirect::GetQueryBufferObjecti64v(const Uint& id, const Uint& buffer, const Enum& pname, const Intptr& offset, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryBufferObjecti64v>(id, buffer, pname, offset, src_loc);
}

void GlIndirect::GetQueryBufferObjectiv(const Uint& id, const Uint& buffer, const Enum& pname, const Intptr& offset, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryBufferObjectiv>(id, buffer, pname, offset, src_loc);
}

void GlIndirect::GetQueryBufferObjectui64v(const Uint& id, const Uint& buffer, const Enum& pname, const Intptr& offset, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryBufferObjectui64v>(id, buffer, pname, offset, src_loc);
}

void GlIndirect::GetQueryBufferObjectuiv(const Uint& id, const Uint& buffer, const Enum& pname, const Intptr& offset, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryBufferObjectuiv>(id, buffer, pname, offset, src_loc);
}

void GlIndirect::GetQueryIndexediv(const Enum& target, const Uint& index, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryIndexediv>(target, index, pname, params, src_loc);
}

void GlIndirect::GetQueryObjecti64v(const Uint& id, const Enum& pname, const Int64Arr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryObjecti64v>(id, pname, params, src_loc);
}

void GlIndirect::GetQueryObjectiv(const Uint& id, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryObjectiv>(id, pname, params, src_loc);
}

void GlIndirect::GetQueryObjectui64v(const Uint& id, const Enum& pname, const Uint64Arr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryObjectui64v>(id, pname, params, src_loc);
}

void GlIndirect::GetQueryObjectuiv(const Uint& id, const Enum& pname, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryObjectuiv>(id, pname, params, src_loc);
}

void GlIndirect::GetQueryiv(const Enum& target, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetQueryiv>(target, pname, params, src_loc);
}

void GlIndirect::GetRenderbufferParameteriv(const Enum& target, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetRenderbufferParameteriv>(target, pname, params, src_loc);
}

void GlIndirect::GetSamplerParameterIiv(const Uint& sampler, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetSamplerParameterIiv>(sampler, pname, params, src_loc);
}

void GlIndirect::GetSamplerParameterIuiv(const Uint& sampler, const Enum& pname, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetSamplerParameterIuiv>(sampler, pname, params, src_loc);
}

void GlIndirect::GetSamplerParameterfv(const Uint& sampler, const Enum& pname, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetSamplerParameterfv>(sampler, pname, params, src_loc);
}

void GlIndirect::GetSamplerParameteriv(const Uint& sampler, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetSamplerParameteriv>(sampler, pname, params, src_loc);
}

void GlIndirect::GetShaderInfoLog(const Uint& shader, const Sizei& bufSize, const Sizei& length, const String& infoLog, const SrcLoc& src_loc){
    return _callGL<&Gl::GetShaderInfoLog>(shader, bufSize, length, infoLog, src_loc);
}

void GlIndirect::GetShaderPrecisionFormat(const Enum& shadertype, const Enum& precisiontype, const IntArr& range, const IntArr& precision, const SrcLoc& src_loc){
    return _callGL<&Gl::GetShaderPrecisionFormat>(shadertype, precisiontype, range, precision, src_loc);
}

void GlIndirect::GetShaderSource(const Uint& shader, const Sizei& bufSize, const Sizei& length, const String& source, const SrcLoc& src_loc){
    return _callGL<&Gl::GetShaderSource>(shader, bufSize, length, source, src_loc);
}

void GlIndirect::GetShaderiv(const Uint& shader, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetShaderiv>(shader, pname, params, src_loc);
}

GL::String GlIndirect::GetString(const Enum& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetString>(name, src_loc);
}

GL::String GlIndirect::GetStringi(const Enum& name, const Uint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::GetStringi>(name, index, src_loc);
}

GL::Uint GlIndirect::GetSubroutineIndex(const Uint& program, const Enum& shadertype, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetSubroutineIndex>(program, shadertype, name, src_loc);
}

GL::Int GlIndirect::GetSubroutineUniformLocation(const Uint& program, const Enum& shadertype, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetSubroutineUniformLocation>(program, shadertype, name, src_loc);
}

void GlIndirect::GetSynciv(const Sync& sync, const Enum& pname, const Sizei& count, const Sizei& length, const IntArr& values, const SrcLoc& src_loc){
    return _callGL<&Gl::GetSynciv>(sync, pname, count, length, values, src_loc);
}

void GlIndirect::GetTexImage(const Enum& target, const Int& level, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTexImage>(target, level, format, type, pixels, src_loc);
}

void GlIndirect::GetTexLevelParameterfv(const Enum& target, const Int& level, const Enum& pname, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTexLevelParameterfv>(target, level, pname, params, src_loc);
}

void GlIndirect::GetTexLevelParameteriv(const Enum& target, const Int& level, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTexLevelParameteriv>(target, level, pname, params, src_loc);
}

void GlIndirect::GetTexParameterIiv(const Enum& target, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTexParameterIiv>(target, pname, params, src_loc);
}

void GlIndirect::GetTexParameterIuiv(const Enum& target, const Enum& pname, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTexParameterIuiv>(target, pname, params, src_loc);
}

void GlIndirect::GetTexParameterfv(const Enum& target, const Enum& pname, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTexParameterfv>(target, pname, params, src_loc);
}

void GlIndirect::GetTexParameteriv(const Enum& target, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTexParameteriv>(target, pname, params, src_loc);
}

void GlIndirect::GetTextureImage(const Uint& texture, const Int& level, const Enum& format, const Enum& type, const Sizei& bufSize, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTextureImage>(texture, level, format, type, bufSize, pixels, src_loc);
}

void GlIndirect::GetTextureLevelParameterfv(const Uint& texture, const Int& level, const Enum& pname, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTextureLevelParameterfv>(texture, level, pname, params, src_loc);
}

void GlIndirect::GetTextureLevelParameteriv(const Uint& texture, const Int& level, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTextureLevelParameteriv>(texture, level, pname, params, src_loc);
}

void GlIndirect::GetTextureParameterIiv(const Uint& texture, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTextureParameterIiv>(texture, pname, params, src_loc);
}

void GlIndirect::GetTextureParameterIuiv(const Uint& texture, const Enum& pname, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTextureParameterIuiv>(texture, pname, params, src_loc);
}

void GlIndirect::GetTextureParameterfv(const Uint& texture, const Enum& pname, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTextureParameterfv>(texture, pname, params, src_loc);
}

void GlIndirect::GetTextureParameteriv(const Uint& texture, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTextureParameteriv>(texture, pname, params, src_loc);
}

void GlIndirect::GetTextureSubImage(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& width, const Sizei& height, const Sizei& depth, const Enum& format, const Enum& type, const Sizei& bufSize, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTextureSubImage>(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels, src_loc);
}

void GlIndirect::GetTransformFeedbackVarying(const Uint& program, const Uint& index, const Sizei& bufSize, const Sizei& length, const SizeiArr& size, const EnumArr& type, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTransformFeedbackVarying>(program, index, bufSize, length, size, type, name, src_loc);
}

void GlIndirect::GetTransformFeedbacki64_v(const Uint& xfb, const Enum& pname, const Uint& index, const Int64Arr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTransformFeedbacki64_v>(xfb, pname, index, param, src_loc);
}

void GlIndirect::GetTransformFeedbacki_v(const Uint& xfb, const Enum& pname, const Uint& index, const IntArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTransformFeedbacki_v>(xfb, pname, index, param, src_loc);
}

void GlIndirect::GetTransformFeedbackiv(const Uint& xfb, const Enum& pname, const IntArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::GetTransformFeedbackiv>(xfb, pname, param, src_loc);
}

GL::Uint GlIndirect::GetUniformBlockIndex(const Uint& program, const String& uniformBlockName, const SrcLoc& src_loc){
    return _callGL<&Gl::GetUniformBlockIndex>(program, uniformBlockName, src_loc);
}

GL::Int GlIndirect::GetUniformLocation(const Uint& program, const String& name, const SrcLoc& src_loc){
    return _callGL<&Gl::GetUniformLocation>(program, name, src_loc);
}

void GlIndirect::GetUniformSubroutineuiv(const Enum& shadertype, const Int& location, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetUniformSubroutineuiv>(shadertype, location, params, src_loc);
}

void GlIndirect::GetUniformdv(const Uint& program, const Int& location, const DoubleArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetUniformdv>(program, location, params, src_loc);
}

void GlIndirect::GetUniformfv(const Uint& program, const Int& location, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetUniformfv>(program, location, params, src_loc);
}

void GlIndirect::GetUniformiv(const Uint& program, const Int& location, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetUniformiv>(program, location, params, src_loc);
}

void GlIndirect::GetUniformuiv(const Uint& program, const Int& location, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetUniformuiv>(program, location, params, src_loc);
}

void GlIndirect::GetVertexArrayIndexed64iv(const Uint& vaobj, const Uint& index, const Enum& pname, const Int64Arr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexArrayIndexed64iv>(vaobj, index, pname, param, src_loc);
}

void GlIndirect::GetVertexArrayIndexediv(const Uint& vaobj, const Uint& index, const Enum& pname, const IntArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexArrayIndexediv>(vaobj, index, pname, param, src_loc);
}

void GlIndirect::GetVertexArrayiv(const Uint& vaobj, const Enum& pname, const IntArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexArrayiv>(vaobj, pname, param, src_loc);
}

void GlIndirect::GetVertexAttribIiv(const Uint& index, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexAttribIiv>(index, pname, params, src_loc);
}

void GlIndirect::GetVertexAttribIuiv(const Uint& index, const Enum& pname, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexAttribIuiv>(index, pname, params, src_loc);
}

void GlIndirect::GetVertexAttribLdv(const Uint& index, const Enum& pname, const DoubleArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexAttribLdv>(index, pname, params, src_loc);
}

void GlIndirect::GetVertexAttribPointerv(const Uint& index, const Enum& pname, const DataPtr& pointer, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexAttribPointerv>(index, pname, pointer, src_loc);
}

void GlIndirect::GetVertexAttribdv(const Uint& index, const Enum& pname, const DoubleArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexAttribdv>(index, pname, params, src_loc);
}

void GlIndirect::GetVertexAttribfv(const Uint& index, const Enum& pname, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexAttribfv>(index, pname, params, src_loc);
}

void GlIndirect::GetVertexAttribiv(const Uint& index, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetVertexAttribiv>(index, pname, params, src_loc);
}

void GlIndirect::GetnCompressedTexImage(const Enum& target, const Int& lod, const Sizei& bufSize, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::GetnCompressedTexImage>(target, lod, bufSize, pixels, src_loc);
}

void GlIndirect::GetnTexImage(const Enum& target, const Int& level, const Enum& format, const Enum& type, const Sizei& bufSize, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::GetnTexImage>(target, level, format, type, bufSize, pixels, src_loc);
}

void GlIndirect::GetnUniformdv(const Uint& program, const Int& location, const Sizei& bufSize, const DoubleArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetnUniformdv>(program, location, bufSize, params, src_loc);
}

void GlIndirect::GetnUniformfv(const Uint& program, const Int& location, const Sizei& bufSize, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetnUniformfv>(program, location, bufSize, params, src_loc);
}

void GlIndirect::GetnUniformiv(const Uint& program, const Int& location, const Sizei& bufSize, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetnUniformiv>(program, location, bufSize, params, src_loc);
}

void GlIndirect::GetnUniformuiv(const Uint& program, const Int& location, const Sizei& bufSize, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::GetnUniformuiv>(program, location, bufSize, params, src_loc);
}

void GlIndirect::Hint(const Enum& target, const Enum& mode, const SrcLoc& src_loc){
    return _callGL<&Gl::Hint>(target, mode, src_loc);
}

void GlIndirect::InvalidateBufferData(const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::InvalidateBufferData>(buffer, src_loc);
}

void GlIndirect::InvalidateBufferSubData(const Uint& buffer, const Intptr& offset, const Sizeiptr& length, const SrcLoc& src_loc){
    return _callGL<&Gl::InvalidateBufferSubData>(buffer, offset, length, src_loc);
}

void GlIndirect::InvalidateFramebuffer(const Enum& target, const Sizei& numAttachments, const EnumArr& attachments, const SrcLoc& src_loc){
    return _callGL<&Gl::InvalidateFramebuffer>(target, numAttachments, attachments, src_loc);
}

void GlIndirect::InvalidateNamedFramebufferData(const Uint& framebuffer, const Sizei& numAttachments, const EnumArr& attachments, const SrcLoc& src_loc){
    return _callGL<&Gl::InvalidateNamedFramebufferData>(framebuffer, numAttachments, attachments, src_loc);
}

void GlIndirect::InvalidateNamedFramebufferSubData(const Uint& framebuffer, const Sizei& numAttachments, const EnumArr& attachments, const Int& x, const Int& y, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::InvalidateNamedFramebufferSubData>(framebuffer, numAttachments, attachments, x, y, width, height, src_loc);
}

void GlIndirect::InvalidateSubFramebuffer(const Enum& target, const Sizei& numAttachments, const EnumArr& attachments, const Int& x, const Int& y, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::InvalidateSubFramebuffer>(target, numAttachments, attachments, x, y, width, height, src_loc);
}

void GlIndirect::InvalidateTexImage(const Uint& texture, const Int& level, const SrcLoc& src_loc){
    return _callGL<&Gl::InvalidateTexImage>(texture, level, src_loc);
}

void GlIndirect::InvalidateTexSubImage(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& width, const Sizei& height, const Sizei& depth, const SrcLoc& src_loc){
    return _callGL<&Gl::InvalidateTexSubImage>(texture, level, xoffset, yoffset, zoffset, width, height, depth, src_loc);
}

GL::Boolean GlIndirect::IsBuffer(const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::IsBuffer>(buffer, src_loc);
}

GL::Boolean GlIndirect::IsEnabled(const Enum& cap, const SrcLoc& src_loc){
    return _callGL<&Gl::IsEnabled>(cap, src_loc);
}

GL::Boolean GlIndirect::IsEnabledi(const Enum& target, const Uint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::IsEnabledi>(target, index, src_loc);
}

GL::Boolean GlIndirect::IsFramebuffer(const Uint& framebuffer, const SrcLoc& src_loc){
    return _callGL<&Gl::IsFramebuffer>(framebuffer, src_loc);
}

GL::Boolean GlIndirect::IsProgram(const Uint& program, const SrcLoc& src_loc){
    return _callGL<&Gl::IsProgram>(program, src_loc);
}

GL::Boolean GlIndirect::IsProgramPipeline(const Uint& pipeline, const SrcLoc& src_loc){
    return _callGL<&Gl::IsProgramPipeline>(pipeline, src_loc);
}

GL::Boolean GlIndirect::IsQuery(const Uint& id, const SrcLoc& src_loc){
    return _callGL<&Gl::IsQuery>(id, src_loc);
}

GL::Boolean GlIndirect::IsRenderbuffer(const Uint& renderbuffer, const SrcLoc& src_loc){
    return _callGL<&Gl::IsRenderbuffer>(renderbuffer, src_loc);
}

GL::Boolean GlIndirect::IsSampler(const Uint& sampler, const SrcLoc& src_loc){
    return _callGL<&Gl::IsSampler>(sampler, src_loc);
}

GL::Boolean GlIndirect::IsShader(const Uint& shader, const SrcLoc& src_loc){
    return _callGL<&Gl::IsShader>(shader, src_loc);
}

GL::Boolean GlIndirect::IsSync(const Sync& sync, const SrcLoc& src_loc){
    return _callGL<&Gl::IsSync>(sync, src_loc);
}

GL::Boolean GlIndirect::IsTexture(const Uint& texture, const SrcLoc& src_loc){
    return _callGL<&Gl::IsTexture>(texture, src_loc);
}

GL::Boolean GlIndirect::IsTransformFeedback(const Uint& id, const SrcLoc& src_loc){
    return _callGL<&Gl::IsTransformFeedback>(id, src_loc);
}

GL::Boolean GlIndirect::IsVertexArray(const Uint& array, const SrcLoc& src_loc){
    return _callGL<&Gl::IsVertexArray>(array, src_loc);
}

void GlIndirect::LineWidth(const Float& width, const SrcLoc& src_loc){
    return _callGL<&Gl::LineWidth>(width, src_loc);
}

void GlIndirect::LinkProgram(const Uint& program, const SrcLoc& src_loc){
    return _callGL<&Gl::LinkProgram>(program, src_loc);
}

void GlIndirect::LogicOp(const Enum& opcode, const SrcLoc& src_loc){
    return _callGL<&Gl::LogicOp>(opcode, src_loc);
}

GL::DataPtr GlIndirect::MapBuffer(const Enum& target, const Enum& access, const SrcLoc& src_loc){
    return _callGL<&Gl::MapBuffer>(target, access, src_loc);
}

GL::DataPtr GlIndirect::MapBufferRange(const Enum& target, const Intptr& offset, const Sizeiptr& length, const Bitfield& access, const SrcLoc& src_loc){
    return _callGL<&Gl::MapBufferRange>(target, offset, length, access, src_loc);
}

GL::DataPtr GlIndirect::MapNamedBuffer(const Uint& buffer, const Enum& access, const SrcLoc& src_loc){
    return _callGL<&Gl::MapNamedBuffer>(buffer, access, src_loc);
}

GL::DataPtr GlIndirect::MapNamedBufferRange(const Uint& buffer, const Intptr& offset, const Sizeiptr& length, const Bitfield& access, const SrcLoc& src_loc){
    return _callGL<&Gl::MapNamedBufferRange>(buffer, offset, length, access, src_loc);
}

void GlIndirect::MemoryBarrier(const Bitfield& barriers, const SrcLoc& src_loc){
    return _callGL<&Gl::MemoryBarrier>(barriers, src_loc);
}

void GlIndirect::MemoryBarrierByRegion(const Bitfield& barriers, const SrcLoc& src_loc){
    return _callGL<&Gl::MemoryBarrierByRegion>(barriers, src_loc);
}

void GlIndirect::MinSampleShading(const Float& value, const SrcLoc& src_loc){
    return _callGL<&Gl::MinSampleShading>(value, src_loc);
}

void GlIndirect::MultiDrawArrays(const Enum& mode, const IntArr& first, const SizeiArr& count, const Sizei& drawcount, const SrcLoc& src_loc){
    return _callGL<&Gl::MultiDrawArrays>(mode, first, count, drawcount, src_loc);
}

void GlIndirect::MultiDrawArraysIndirect(const Enum& mode, const Data& indirect, const Sizei& drawcount, const Sizei& stride, const SrcLoc& src_loc){
    return _callGL<&Gl::MultiDrawArraysIndirect>(mode, indirect, drawcount, stride, src_loc);
}

void GlIndirect::MultiDrawArraysIndirectCount(const Enum& mode, const Data& indirect, const Intptr& drawcount, const Sizei& maxdrawcount, const Sizei& stride, const SrcLoc& src_loc){
    return _callGL<&Gl::MultiDrawArraysIndirectCount>(mode, indirect, drawcount, maxdrawcount, stride, src_loc);
}

void GlIndirect::MultiDrawElements(const Enum& mode, const SizeiArr& count, const Enum& type, const DataPtr& indices, const Sizei& drawcount, const SrcLoc& src_loc){
    return _callGL<&Gl::MultiDrawElements>(mode, count, type, indices, drawcount, src_loc);
}

void GlIndirect::MultiDrawElementsBaseVertex(const Enum& mode, const SizeiArr& count, const Enum& type, const DataPtr& indices, const Sizei& drawcount, const IntArr& basevertex, const SrcLoc& src_loc){
    return _callGL<&Gl::MultiDrawElementsBaseVertex>(mode, count, type, indices, drawcount, basevertex, src_loc);
}

void GlIndirect::MultiDrawElementsIndirect(const Enum& mode, const Enum& type, const Data& indirect, const Sizei& drawcount, const Sizei& stride, const SrcLoc& src_loc){
    return _callGL<&Gl::MultiDrawElementsIndirect>(mode, type, indirect, drawcount, stride, src_loc);
}

void GlIndirect::MultiDrawElementsIndirectCount(const Enum& mode, const Enum& type, const Data& indirect, const Intptr& drawcount, const Sizei& maxdrawcount, const Sizei& stride, const SrcLoc& src_loc){
    return _callGL<&Gl::MultiDrawElementsIndirectCount>(mode, type, indirect, drawcount, maxdrawcount, stride, src_loc);
}

void GlIndirect::NamedBufferData(const Uint& buffer, const Sizeiptr& size, const Data& data, const Enum& usage, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedBufferData>(buffer, size, data, usage, src_loc);
}

void GlIndirect::NamedBufferStorage(const Uint& buffer, const Sizeiptr& size, const Data& data, const Bitfield& flags, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedBufferStorage>(buffer, size, data, flags, src_loc);
}

void GlIndirect::NamedBufferSubData(const Uint& buffer, const Intptr& offset, const Sizeiptr& size, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedBufferSubData>(buffer, offset, size, data, src_loc);
}

void GlIndirect::NamedFramebufferDrawBuffer(const Uint& framebuffer, const Enum& buf, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedFramebufferDrawBuffer>(framebuffer, buf, src_loc);
}

void GlIndirect::NamedFramebufferDrawBuffers(const Uint& framebuffer, const Sizei& n, const EnumArr& bufs, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedFramebufferDrawBuffers>(framebuffer, n, bufs, src_loc);
}

void GlIndirect::NamedFramebufferParameteri(const Uint& framebuffer, const Enum& pname, const Int& param, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedFramebufferParameteri>(framebuffer, pname, param, src_loc);
}

void GlIndirect::NamedFramebufferReadBuffer(const Uint& framebuffer, const Enum& src, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedFramebufferReadBuffer>(framebuffer, src, src_loc);
}

void GlIndirect::NamedFramebufferRenderbuffer(const Uint& framebuffer, const Enum& attachment, const Enum& renderbuffertarget, const Uint& renderbuffer, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedFramebufferRenderbuffer>(framebuffer, attachment, renderbuffertarget, renderbuffer, src_loc);
}

void GlIndirect::NamedFramebufferTexture(const Uint& framebuffer, const Enum& attachment, const Uint& texture, const Int& level, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedFramebufferTexture>(framebuffer, attachment, texture, level, src_loc);
}

void GlIndirect::NamedFramebufferTextureLayer(const Uint& framebuffer, const Enum& attachment, const Uint& texture, const Int& level, const Int& layer, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedFramebufferTextureLayer>(framebuffer, attachment, texture, level, layer, src_loc);
}

void GlIndirect::NamedRenderbufferStorage(const Uint& renderbuffer, const Enum& internalformat, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedRenderbufferStorage>(renderbuffer, internalformat, width, height, src_loc);
}

void GlIndirect::NamedRenderbufferStorageMultisample(const Uint& renderbuffer, const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::NamedRenderbufferStorageMultisample>(renderbuffer, samples, internalformat, width, height, src_loc);
}

void GlIndirect::ObjectLabel(const Enum& identifier, const Uint& name, const Sizei& length, const String& label, const SrcLoc& src_loc){
    return _callGL<&Gl::ObjectLabel>(identifier, name, length, label, src_loc);
}

void GlIndirect::ObjectPtrLabel(const Data& ptr, const Sizei& length, const String& label, const SrcLoc& src_loc){
    return _callGL<&Gl::ObjectPtrLabel>(ptr, length, label, src_loc);
}

void GlIndirect::PatchParameterfv(const Enum& pname, const FloatArr& values, const SrcLoc& src_loc){
    return _callGL<&Gl::PatchParameterfv>(pname, values, src_loc);
}

void GlIndirect::PatchParameteri(const Enum& pname, const Int& value, const SrcLoc& src_loc){
    return _callGL<&Gl::PatchParameteri>(pname, value, src_loc);
}

void GlIndirect::PauseTransformFeedback(const SrcLoc& src_loc){
    return _callGL<&Gl::PauseTransformFeedback>(src_loc);
}

void GlIndirect::PixelStoref(const Enum& pname, const Float& param, const SrcLoc& src_loc){
    return _callGL<&Gl::PixelStoref>(pname, param, src_loc);
}

void GlIndirect::PixelStorei(const Enum& pname, const Int& param, const SrcLoc& src_loc){
    return _callGL<&Gl::PixelStorei>(pname, param, src_loc);
}

void GlIndirect::PointParameterf(const Enum& pname, const Float& param, const SrcLoc& src_loc){
    return _callGL<&Gl::PointParameterf>(pname, param, src_loc);
}

void GlIndirect::PointParameterfv(const Enum& pname, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::PointParameterfv>(pname, params, src_loc);
}

void GlIndirect::PointParameteri(const Enum& pname, const Int& param, const SrcLoc& src_loc){
    return _callGL<&Gl::PointParameteri>(pname, param, src_loc);
}

void GlIndirect::PointParameteriv(const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::PointParameteriv>(pname, params, src_loc);
}

void GlIndirect::PointSize(const Float& size, const SrcLoc& src_loc){
    return _callGL<&Gl::PointSize>(size, src_loc);
}

void GlIndirect::PolygonMode(const Enum& face, const Enum& mode, const SrcLoc& src_loc){
    return _callGL<&Gl::PolygonMode>(face, mode, src_loc);
}

void GlIndirect::PolygonOffset(const Float& factor, const Float& units, const SrcLoc& src_loc){
    return _callGL<&Gl::PolygonOffset>(factor, units, src_loc);
}

void GlIndirect::PolygonOffsetClamp(const Float& factor, const Float& units, const Float& clamp, const SrcLoc& src_loc){
    return _callGL<&Gl::PolygonOffsetClamp>(factor, units, clamp, src_loc);
}

void GlIndirect::PopDebugGroup(const SrcLoc& src_loc){
    return _callGL<&Gl::PopDebugGroup>(src_loc);
}

void GlIndirect::PrimitiveRestartIndex(const Uint& index, const SrcLoc& src_loc){
    return _callGL<&Gl::PrimitiveRestartIndex>(index, src_loc);
}

void GlIndirect::ProgramBinary(const Uint& program, const Enum& binaryFormat, const Data& binary, const Sizei& length, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramBinary>(program, binaryFormat, binary, length, src_loc);
}

void GlIndirect::ProgramParameteri(const Uint& program, const Enum& pname, const Int& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramParameteri>(program, pname, value, src_loc);
}

void GlIndirect::ProgramUniform1d(const Uint& program, const Int& location, const Double& v0, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform1d>(program, location, v0, src_loc);
}

void GlIndirect::ProgramUniform1dv(const Uint& program, const Int& location, const Sizei& count, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform1dv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform1f(const Uint& program, const Int& location, const Float& v0, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform1f>(program, location, v0, src_loc);
}

void GlIndirect::ProgramUniform1fv(const Uint& program, const Int& location, const Sizei& count, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform1fv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform1i(const Uint& program, const Int& location, const Int& v0, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform1i>(program, location, v0, src_loc);
}

void GlIndirect::ProgramUniform1iv(const Uint& program, const Int& location, const Sizei& count, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform1iv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform1ui(const Uint& program, const Int& location, const Uint& v0, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform1ui>(program, location, v0, src_loc);
}

void GlIndirect::ProgramUniform1uiv(const Uint& program, const Int& location, const Sizei& count, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform1uiv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform2d(const Uint& program, const Int& location, const Double& v0, const Double& v1, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform2d>(program, location, v0, v1, src_loc);
}

void GlIndirect::ProgramUniform2dv(const Uint& program, const Int& location, const Sizei& count, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform2dv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform2f(const Uint& program, const Int& location, const Float& v0, const Float& v1, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform2f>(program, location, v0, v1, src_loc);
}

void GlIndirect::ProgramUniform2fv(const Uint& program, const Int& location, const Sizei& count, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform2fv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform2i(const Uint& program, const Int& location, const Int& v0, const Int& v1, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform2i>(program, location, v0, v1, src_loc);
}

void GlIndirect::ProgramUniform2iv(const Uint& program, const Int& location, const Sizei& count, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform2iv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform2ui(const Uint& program, const Int& location, const Uint& v0, const Uint& v1, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform2ui>(program, location, v0, v1, src_loc);
}

void GlIndirect::ProgramUniform2uiv(const Uint& program, const Int& location, const Sizei& count, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform2uiv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform3d(const Uint& program, const Int& location, const Double& v0, const Double& v1, const Double& v2, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform3d>(program, location, v0, v1, v2, src_loc);
}

void GlIndirect::ProgramUniform3dv(const Uint& program, const Int& location, const Sizei& count, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform3dv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform3f(const Uint& program, const Int& location, const Float& v0, const Float& v1, const Float& v2, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform3f>(program, location, v0, v1, v2, src_loc);
}

void GlIndirect::ProgramUniform3fv(const Uint& program, const Int& location, const Sizei& count, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform3fv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform3i(const Uint& program, const Int& location, const Int& v0, const Int& v1, const Int& v2, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform3i>(program, location, v0, v1, v2, src_loc);
}

void GlIndirect::ProgramUniform3iv(const Uint& program, const Int& location, const Sizei& count, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform3iv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform3ui(const Uint& program, const Int& location, const Uint& v0, const Uint& v1, const Uint& v2, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform3ui>(program, location, v0, v1, v2, src_loc);
}

void GlIndirect::ProgramUniform3uiv(const Uint& program, const Int& location, const Sizei& count, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform3uiv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform4d(const Uint& program, const Int& location, const Double& v0, const Double& v1, const Double& v2, const Double& v3, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform4d>(program, location, v0, v1, v2, v3, src_loc);
}

void GlIndirect::ProgramUniform4dv(const Uint& program, const Int& location, const Sizei& count, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform4dv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform4f(const Uint& program, const Int& location, const Float& v0, const Float& v1, const Float& v2, const Float& v3, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform4f>(program, location, v0, v1, v2, v3, src_loc);
}

void GlIndirect::ProgramUniform4fv(const Uint& program, const Int& location, const Sizei& count, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform4fv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform4i(const Uint& program, const Int& location, const Int& v0, const Int& v1, const Int& v2, const Int& v3, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform4i>(program, location, v0, v1, v2, v3, src_loc);
}

void GlIndirect::ProgramUniform4iv(const Uint& program, const Int& location, const Sizei& count, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform4iv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniform4ui(const Uint& program, const Int& location, const Uint& v0, const Uint& v1, const Uint& v2, const Uint& v3, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform4ui>(program, location, v0, v1, v2, v3, src_loc);
}

void GlIndirect::ProgramUniform4uiv(const Uint& program, const Int& location, const Sizei& count, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniform4uiv>(program, location, count, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix2dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix2dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix2fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix2fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix2x3dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix2x3dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix2x3fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix2x3fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix2x4dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix2x4dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix2x4fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix2x4fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix3dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix3dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix3fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix3fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix3x2dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix3x2dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix3x2fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix3x2fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix3x4dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix3x4dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix3x4fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix3x4fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix4dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix4dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix4fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix4fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix4x2dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix4x2dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix4x2fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix4x2fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix4x3dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix4x3dv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProgramUniformMatrix4x3fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::ProgramUniformMatrix4x3fv>(program, location, count, transpose, value, src_loc);
}

void GlIndirect::ProvokingVertex(const Enum& mode, const SrcLoc& src_loc){
    return _callGL<&Gl::ProvokingVertex>(mode, src_loc);
}

void GlIndirect::PushDebugGroup(const Enum& source, const Uint& id, const Sizei& length, const String& message, const SrcLoc& src_loc){
    return _callGL<&Gl::PushDebugGroup>(source, id, length, message, src_loc);
}

void GlIndirect::QueryCounter(const Uint& id, const Enum& target, const SrcLoc& src_loc){
    return _callGL<&Gl::QueryCounter>(id, target, src_loc);
}

void GlIndirect::ReadBuffer(const Enum& src, const SrcLoc& src_loc){
    return _callGL<&Gl::ReadBuffer>(src, src_loc);
}

void GlIndirect::ReadPixels(const Int& x, const Int& y, const Sizei& width, const Sizei& height, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::ReadPixels>(x, y, width, height, format, type, pixels, src_loc);
}

void GlIndirect::ReadnPixels(const Int& x, const Int& y, const Sizei& width, const Sizei& height, const Enum& format, const Enum& type, const Sizei& bufSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&Gl::ReadnPixels>(x, y, width, height, format, type, bufSize, data, src_loc);
}

void GlIndirect::ReleaseShaderCompiler(const SrcLoc& src_loc){
    return _callGL<&Gl::ReleaseShaderCompiler>(src_loc);
}

void GlIndirect::RenderbufferStorage(const Enum& target, const Enum& internalformat, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::RenderbufferStorage>(target, internalformat, width, height, src_loc);
}

void GlIndirect::RenderbufferStorageMultisample(const Enum& target, const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::RenderbufferStorageMultisample>(target, samples, internalformat, width, height, src_loc);
}

void GlIndirect::ResumeTransformFeedback(const SrcLoc& src_loc){
    return _callGL<&Gl::ResumeTransformFeedback>(src_loc);
}

void GlIndirect::SampleCoverage(const Float& value, const Boolean& invert, const SrcLoc& src_loc){
    return _callGL<&Gl::SampleCoverage>(value, invert, src_loc);
}

void GlIndirect::SampleMaski(const Uint& maskNumber, const Bitfield& mask, const SrcLoc& src_loc){
    return _callGL<&Gl::SampleMaski>(maskNumber, mask, src_loc);
}

void GlIndirect::SamplerParameterIiv(const Uint& sampler, const Enum& pname, const IntArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::SamplerParameterIiv>(sampler, pname, param, src_loc);
}

void GlIndirect::SamplerParameterIuiv(const Uint& sampler, const Enum& pname, const UintArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::SamplerParameterIuiv>(sampler, pname, param, src_loc);
}

void GlIndirect::SamplerParameterf(const Uint& sampler, const Enum& pname, const Float& param, const SrcLoc& src_loc){
    return _callGL<&Gl::SamplerParameterf>(sampler, pname, param, src_loc);
}

void GlIndirect::SamplerParameterfv(const Uint& sampler, const Enum& pname, const FloatArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::SamplerParameterfv>(sampler, pname, param, src_loc);
}

void GlIndirect::SamplerParameteri(const Uint& sampler, const Enum& pname, const Int& param, const SrcLoc& src_loc){
    return _callGL<&Gl::SamplerParameteri>(sampler, pname, param, src_loc);
}

void GlIndirect::SamplerParameteriv(const Uint& sampler, const Enum& pname, const IntArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::SamplerParameteriv>(sampler, pname, param, src_loc);
}

void GlIndirect::Scissor(const Int& x, const Int& y, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::Scissor>(x, y, width, height, src_loc);
}

void GlIndirect::ScissorArrayv(const Uint& first, const Sizei& count, const IntArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::ScissorArrayv>(first, count, v, src_loc);
}

void GlIndirect::ScissorIndexed(const Uint& index, const Int& left, const Int& bottom, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::ScissorIndexed>(index, left, bottom, width, height, src_loc);
}

void GlIndirect::ScissorIndexedv(const Uint& index, const IntArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::ScissorIndexedv>(index, v, src_loc);
}

void GlIndirect::ShaderBinary(const Sizei& count, const UintArr& shaders, const Enum& binaryFormat, const Data& binary, const Sizei& length, const SrcLoc& src_loc){
    return _callGL<&Gl::ShaderBinary>(count, shaders, binaryFormat, binary, length, src_loc);
}

void GlIndirect::ShaderSource(const Uint& shader, const Sizei& count, const StringArr& strings, const IntArr& lengths, const SrcLoc& src_loc){
    return _callGL<&Gl::ShaderSource>(shader, count, strings, lengths, src_loc);
}

void GlIndirect::ShaderStorageBlockBinding(const Uint& program, const Uint& storageBlockIndex, const Uint& storageBlockBinding, const SrcLoc& src_loc){
    return _callGL<&Gl::ShaderStorageBlockBinding>(program, storageBlockIndex, storageBlockBinding, src_loc);
}

void GlIndirect::SpecializeShader(const Uint& shader, const String& pEntryPoint, const Uint& numSpecializationConstants, const UintArr& pConstantIndex, const UintArr& pConstantValue, const SrcLoc& src_loc){
    return _callGL<&Gl::SpecializeShader>(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue, src_loc);
}

void GlIndirect::StencilFunc(const Enum& func, const Int& ref, const Uint& mask, const SrcLoc& src_loc){
    return _callGL<&Gl::StencilFunc>(func, ref, mask, src_loc);
}

void GlIndirect::StencilFuncSeparate(const Enum& face, const Enum& func, const Int& ref, const Uint& mask, const SrcLoc& src_loc){
    return _callGL<&Gl::StencilFuncSeparate>(face, func, ref, mask, src_loc);
}

void GlIndirect::StencilMask(const Uint& mask, const SrcLoc& src_loc){
    return _callGL<&Gl::StencilMask>(mask, src_loc);
}

void GlIndirect::StencilMaskSeparate(const Enum& face, const Uint& mask, const SrcLoc& src_loc){
    return _callGL<&Gl::StencilMaskSeparate>(face, mask, src_loc);
}

void GlIndirect::StencilOp(const Enum& fail, const Enum& zfail, const Enum& zpass, const SrcLoc& src_loc){
    return _callGL<&Gl::StencilOp>(fail, zfail, zpass, src_loc);
}

void GlIndirect::StencilOpSeparate(const Enum& face, const Enum& sfail, const Enum& dpfail, const Enum& dppass, const SrcLoc& src_loc){
    return _callGL<&Gl::StencilOpSeparate>(face, sfail, dpfail, dppass, src_loc);
}

void GlIndirect::TexBuffer(const Enum& target, const Enum& internalformat, const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::TexBuffer>(target, internalformat, buffer, src_loc);
}

void GlIndirect::TexBufferRange(const Enum& target, const Enum& internalformat, const Uint& buffer, const Intptr& offset, const Sizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&Gl::TexBufferRange>(target, internalformat, buffer, offset, size, src_loc);
}

void GlIndirect::TexImage1D(const Enum& target, const Int& level, const Int& internalformat, const Sizei& width, const Int& border, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TexImage1D>(target, level, internalformat, width, border, format, type, pixels, src_loc);
}

void GlIndirect::TexImage2D(const Enum& target, const Int& level, const Int& internalformat, const Sizei& width, const Sizei& height, const Int& border, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TexImage2D>(target, level, internalformat, width, height, border, format, type, pixels, src_loc);
}

void GlIndirect::TexImage2DMultisample(const Enum& target, const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const Boolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&Gl::TexImage2DMultisample>(target, samples, internalformat, width, height, fixedsamplelocations, src_loc);
}

void GlIndirect::TexImage3D(const Enum& target, const Int& level, const Int& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const Int& border, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TexImage3D>(target, level, internalformat, width, height, depth, border, format, type, pixels, src_loc);
}

void GlIndirect::TexImage3DMultisample(const Enum& target, const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const Boolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&Gl::TexImage3DMultisample>(target, samples, internalformat, width, height, depth, fixedsamplelocations, src_loc);
}

void GlIndirect::TexParameterIiv(const Enum& target, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::TexParameterIiv>(target, pname, params, src_loc);
}

void GlIndirect::TexParameterIuiv(const Enum& target, const Enum& pname, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::TexParameterIuiv>(target, pname, params, src_loc);
}

void GlIndirect::TexParameterf(const Enum& target, const Enum& pname, const Float& param, const SrcLoc& src_loc){
    return _callGL<&Gl::TexParameterf>(target, pname, param, src_loc);
}

void GlIndirect::TexParameterfv(const Enum& target, const Enum& pname, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::TexParameterfv>(target, pname, params, src_loc);
}

void GlIndirect::TexParameteri(const Enum& target, const Enum& pname, const Int& param, const SrcLoc& src_loc){
    return _callGL<&Gl::TexParameteri>(target, pname, param, src_loc);
}

void GlIndirect::TexParameteriv(const Enum& target, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::TexParameteriv>(target, pname, params, src_loc);
}

void GlIndirect::TexStorage1D(const Enum& target, const Sizei& levels, const Enum& internalformat, const Sizei& width, const SrcLoc& src_loc){
    return _callGL<&Gl::TexStorage1D>(target, levels, internalformat, width, src_loc);
}

void GlIndirect::TexStorage2D(const Enum& target, const Sizei& levels, const Enum& internalformat, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::TexStorage2D>(target, levels, internalformat, width, height, src_loc);
}

void GlIndirect::TexStorage2DMultisample(const Enum& target, const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const Boolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&Gl::TexStorage2DMultisample>(target, samples, internalformat, width, height, fixedsamplelocations, src_loc);
}

void GlIndirect::TexStorage3D(const Enum& target, const Sizei& levels, const Enum& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const SrcLoc& src_loc){
    return _callGL<&Gl::TexStorage3D>(target, levels, internalformat, width, height, depth, src_loc);
}

void GlIndirect::TexStorage3DMultisample(const Enum& target, const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const Boolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&Gl::TexStorage3DMultisample>(target, samples, internalformat, width, height, depth, fixedsamplelocations, src_loc);
}

void GlIndirect::TexSubImage1D(const Enum& target, const Int& level, const Int& xoffset, const Sizei& width, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TexSubImage1D>(target, level, xoffset, width, format, type, pixels, src_loc);
}

void GlIndirect::TexSubImage2D(const Enum& target, const Int& level, const Int& xoffset, const Int& yoffset, const Sizei& width, const Sizei& height, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TexSubImage2D>(target, level, xoffset, yoffset, width, height, format, type, pixels, src_loc);
}

void GlIndirect::TexSubImage3D(const Enum& target, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& width, const Sizei& height, const Sizei& depth, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TexSubImage3D>(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels, src_loc);
}

void GlIndirect::TextureBarrier(const SrcLoc& src_loc){
    return _callGL<&Gl::TextureBarrier>(src_loc);
}

void GlIndirect::TextureBuffer(const Uint& texture, const Enum& internalformat, const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureBuffer>(texture, internalformat, buffer, src_loc);
}

void GlIndirect::TextureBufferRange(const Uint& texture, const Enum& internalformat, const Uint& buffer, const Intptr& offset, const Sizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureBufferRange>(texture, internalformat, buffer, offset, size, src_loc);
}

void GlIndirect::TextureParameterIiv(const Uint& texture, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureParameterIiv>(texture, pname, params, src_loc);
}

void GlIndirect::TextureParameterIuiv(const Uint& texture, const Enum& pname, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureParameterIuiv>(texture, pname, params, src_loc);
}

void GlIndirect::TextureParameterf(const Uint& texture, const Enum& pname, const Float& param, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureParameterf>(texture, pname, param, src_loc);
}

void GlIndirect::TextureParameterfv(const Uint& texture, const Enum& pname, const FloatArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureParameterfv>(texture, pname, param, src_loc);
}

void GlIndirect::TextureParameteri(const Uint& texture, const Enum& pname, const Int& param, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureParameteri>(texture, pname, param, src_loc);
}

void GlIndirect::TextureParameteriv(const Uint& texture, const Enum& pname, const IntArr& param, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureParameteriv>(texture, pname, param, src_loc);
}

void GlIndirect::TextureStorage1D(const Uint& texture, const Sizei& levels, const Enum& internalformat, const Sizei& width, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureStorage1D>(texture, levels, internalformat, width, src_loc);
}

void GlIndirect::TextureStorage2D(const Uint& texture, const Sizei& levels, const Enum& internalformat, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureStorage2D>(texture, levels, internalformat, width, height, src_loc);
}

void GlIndirect::TextureStorage2DMultisample(const Uint& texture, const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const Boolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureStorage2DMultisample>(texture, samples, internalformat, width, height, fixedsamplelocations, src_loc);
}

void GlIndirect::TextureStorage3D(const Uint& texture, const Sizei& levels, const Enum& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureStorage3D>(texture, levels, internalformat, width, height, depth, src_loc);
}

void GlIndirect::TextureStorage3DMultisample(const Uint& texture, const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const Boolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureStorage3DMultisample>(texture, samples, internalformat, width, height, depth, fixedsamplelocations, src_loc);
}

void GlIndirect::TextureSubImage1D(const Uint& texture, const Int& level, const Int& xoffset, const Sizei& width, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureSubImage1D>(texture, level, xoffset, width, format, type, pixels, src_loc);
}

void GlIndirect::TextureSubImage2D(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Sizei& width, const Sizei& height, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureSubImage2D>(texture, level, xoffset, yoffset, width, height, format, type, pixels, src_loc);
}

void GlIndirect::TextureSubImage3D(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& width, const Sizei& height, const Sizei& depth, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureSubImage3D>(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels, src_loc);
}

void GlIndirect::TextureView(const Uint& texture, const Enum& target, const Uint& origtexture, const Enum& internalformat, const Uint& minlevel, const Uint& numlevels, const Uint& minlayer, const Uint& numlayers, const SrcLoc& src_loc){
    return _callGL<&Gl::TextureView>(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers, src_loc);
}

void GlIndirect::TransformFeedbackBufferBase(const Uint& xfb, const Uint& index, const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::TransformFeedbackBufferBase>(xfb, index, buffer, src_loc);
}

void GlIndirect::TransformFeedbackBufferRange(const Uint& xfb, const Uint& index, const Uint& buffer, const Intptr& offset, const Sizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&Gl::TransformFeedbackBufferRange>(xfb, index, buffer, offset, size, src_loc);
}

void GlIndirect::Uniform1d(const Int& location, const Double& x, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform1d>(location, x, src_loc);
}

void GlIndirect::Uniform1dv(const Int& location, const Sizei& count, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform1dv>(location, count, value, src_loc);
}

void GlIndirect::Uniform1f(const Int& location, const Float& v0, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform1f>(location, v0, src_loc);
}

void GlIndirect::Uniform1fv(const Int& location, const Sizei& count, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform1fv>(location, count, value, src_loc);
}

void GlIndirect::Uniform1i(const Int& location, const Int& v0, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform1i>(location, v0, src_loc);
}

void GlIndirect::Uniform1iv(const Int& location, const Sizei& count, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform1iv>(location, count, value, src_loc);
}

void GlIndirect::Uniform1ui(const Int& location, const Uint& v0, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform1ui>(location, v0, src_loc);
}

void GlIndirect::Uniform1uiv(const Int& location, const Sizei& count, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform1uiv>(location, count, value, src_loc);
}

void GlIndirect::Uniform2d(const Int& location, const Double& x, const Double& y, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform2d>(location, x, y, src_loc);
}

void GlIndirect::Uniform2dv(const Int& location, const Sizei& count, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform2dv>(location, count, value, src_loc);
}

void GlIndirect::Uniform2f(const Int& location, const Float& v0, const Float& v1, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform2f>(location, v0, v1, src_loc);
}

void GlIndirect::Uniform2fv(const Int& location, const Sizei& count, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform2fv>(location, count, value, src_loc);
}

void GlIndirect::Uniform2i(const Int& location, const Int& v0, const Int& v1, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform2i>(location, v0, v1, src_loc);
}

void GlIndirect::Uniform2iv(const Int& location, const Sizei& count, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform2iv>(location, count, value, src_loc);
}

void GlIndirect::Uniform2ui(const Int& location, const Uint& v0, const Uint& v1, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform2ui>(location, v0, v1, src_loc);
}

void GlIndirect::Uniform2uiv(const Int& location, const Sizei& count, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform2uiv>(location, count, value, src_loc);
}

void GlIndirect::Uniform3d(const Int& location, const Double& x, const Double& y, const Double& z, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform3d>(location, x, y, z, src_loc);
}

void GlIndirect::Uniform3dv(const Int& location, const Sizei& count, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform3dv>(location, count, value, src_loc);
}

void GlIndirect::Uniform3f(const Int& location, const Float& v0, const Float& v1, const Float& v2, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform3f>(location, v0, v1, v2, src_loc);
}

void GlIndirect::Uniform3fv(const Int& location, const Sizei& count, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform3fv>(location, count, value, src_loc);
}

void GlIndirect::Uniform3i(const Int& location, const Int& v0, const Int& v1, const Int& v2, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform3i>(location, v0, v1, v2, src_loc);
}

void GlIndirect::Uniform3iv(const Int& location, const Sizei& count, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform3iv>(location, count, value, src_loc);
}

void GlIndirect::Uniform3ui(const Int& location, const Uint& v0, const Uint& v1, const Uint& v2, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform3ui>(location, v0, v1, v2, src_loc);
}

void GlIndirect::Uniform3uiv(const Int& location, const Sizei& count, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform3uiv>(location, count, value, src_loc);
}

void GlIndirect::Uniform4d(const Int& location, const Double& x, const Double& y, const Double& z, const Double& w, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform4d>(location, x, y, z, w, src_loc);
}

void GlIndirect::Uniform4dv(const Int& location, const Sizei& count, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform4dv>(location, count, value, src_loc);
}

void GlIndirect::Uniform4f(const Int& location, const Float& v0, const Float& v1, const Float& v2, const Float& v3, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform4f>(location, v0, v1, v2, v3, src_loc);
}

void GlIndirect::Uniform4fv(const Int& location, const Sizei& count, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform4fv>(location, count, value, src_loc);
}

void GlIndirect::Uniform4i(const Int& location, const Int& v0, const Int& v1, const Int& v2, const Int& v3, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform4i>(location, v0, v1, v2, v3, src_loc);
}

void GlIndirect::Uniform4iv(const Int& location, const Sizei& count, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform4iv>(location, count, value, src_loc);
}

void GlIndirect::Uniform4ui(const Int& location, const Uint& v0, const Uint& v1, const Uint& v2, const Uint& v3, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform4ui>(location, v0, v1, v2, v3, src_loc);
}

void GlIndirect::Uniform4uiv(const Int& location, const Sizei& count, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::Uniform4uiv>(location, count, value, src_loc);
}

void GlIndirect::UniformBlockBinding(const Uint& program, const Uint& uniformBlockIndex, const Uint& uniformBlockBinding, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformBlockBinding>(program, uniformBlockIndex, uniformBlockBinding, src_loc);
}

void GlIndirect::UniformMatrix2dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix2dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix2fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix2fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix2x3dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix2x3dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix2x3fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix2x3fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix2x4dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix2x4dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix2x4fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix2x4fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix3dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix3dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix3fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix3fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix3x2dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix3x2dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix3x2fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix3x2fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix3x4dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix3x4dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix3x4fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix3x4fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix4dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix4dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix4fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix4fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix4x2dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix4x2dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix4x2fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix4x2fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix4x3dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix4x3dv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformMatrix4x3fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformMatrix4x3fv>(location, count, transpose, value, src_loc);
}

void GlIndirect::UniformSubroutinesuiv(const Enum& shadertype, const Sizei& count, const UintArr& indices, const SrcLoc& src_loc){
    return _callGL<&Gl::UniformSubroutinesuiv>(shadertype, count, indices, src_loc);
}

GL::Boolean GlIndirect::UnmapBuffer(const Enum& target, const SrcLoc& src_loc){
    return _callGL<&Gl::UnmapBuffer>(target, src_loc);
}

GL::Boolean GlIndirect::UnmapNamedBuffer(const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::UnmapNamedBuffer>(buffer, src_loc);
}

void GlIndirect::UseProgram(const Uint& program, const SrcLoc& src_loc){
    return _callGL<&Gl::UseProgram>(program, src_loc);
}

void GlIndirect::UseProgramStages(const Uint& pipeline, const Bitfield& stages, const Uint& program, const SrcLoc& src_loc){
    return _callGL<&Gl::UseProgramStages>(pipeline, stages, program, src_loc);
}

void GlIndirect::ValidateProgram(const Uint& program, const SrcLoc& src_loc){
    return _callGL<&Gl::ValidateProgram>(program, src_loc);
}

void GlIndirect::ValidateProgramPipeline(const Uint& pipeline, const SrcLoc& src_loc){
    return _callGL<&Gl::ValidateProgramPipeline>(pipeline, src_loc);
}

void GlIndirect::VertexArrayAttribBinding(const Uint& vaobj, const Uint& attribindex, const Uint& bindingindex, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexArrayAttribBinding>(vaobj, attribindex, bindingindex, src_loc);
}

void GlIndirect::VertexArrayAttribFormat(const Uint& vaobj, const Uint& attribindex, const Int& size, const Enum& type, const Boolean& normalized, const Uint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexArrayAttribFormat>(vaobj, attribindex, size, type, normalized, relativeoffset, src_loc);
}

void GlIndirect::VertexArrayAttribIFormat(const Uint& vaobj, const Uint& attribindex, const Int& size, const Enum& type, const Uint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexArrayAttribIFormat>(vaobj, attribindex, size, type, relativeoffset, src_loc);
}

void GlIndirect::VertexArrayAttribLFormat(const Uint& vaobj, const Uint& attribindex, const Int& size, const Enum& type, const Uint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexArrayAttribLFormat>(vaobj, attribindex, size, type, relativeoffset, src_loc);
}

void GlIndirect::VertexArrayBindingDivisor(const Uint& vaobj, const Uint& bindingindex, const Uint& divisor, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexArrayBindingDivisor>(vaobj, bindingindex, divisor, src_loc);
}

void GlIndirect::VertexArrayElementBuffer(const Uint& vaobj, const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexArrayElementBuffer>(vaobj, buffer, src_loc);
}

void GlIndirect::VertexArrayVertexBuffer(const Uint& vaobj, const Uint& bindingindex, const Uint& buffer, const Intptr& offset, const Sizei& stride, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexArrayVertexBuffer>(vaobj, bindingindex, buffer, offset, stride, src_loc);
}

void GlIndirect::VertexArrayVertexBuffers(const Uint& vaobj, const Uint& first, const Sizei& count, const UintArr& buffers, const IntptrArr& offsets, const SizeiArr& strides, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexArrayVertexBuffers>(vaobj, first, count, buffers, offsets, strides, src_loc);
}

void GlIndirect::VertexAttrib1d(const Uint& index, const Double& x, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib1d>(index, x, src_loc);
}

void GlIndirect::VertexAttrib1dv(const Uint& index, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib1dv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib1f(const Uint& index, const Float& x, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib1f>(index, x, src_loc);
}

void GlIndirect::VertexAttrib1fv(const Uint& index, const FloatArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib1fv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib1s(const Uint& index, const Short& x, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib1s>(index, x, src_loc);
}

void GlIndirect::VertexAttrib1sv(const Uint& index, const Short& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib1sv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib2d(const Uint& index, const Double& x, const Double& y, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib2d>(index, x, y, src_loc);
}

void GlIndirect::VertexAttrib2dv(const Uint& index, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib2dv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib2f(const Uint& index, const Float& x, const Float& y, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib2f>(index, x, y, src_loc);
}

void GlIndirect::VertexAttrib2fv(const Uint& index, const FloatArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib2fv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib2s(const Uint& index, const Short& x, const Short& y, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib2s>(index, x, y, src_loc);
}

void GlIndirect::VertexAttrib2sv(const Uint& index, const Short& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib2sv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib3d(const Uint& index, const Double& x, const Double& y, const Double& z, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib3d>(index, x, y, z, src_loc);
}

void GlIndirect::VertexAttrib3dv(const Uint& index, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib3dv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib3f(const Uint& index, const Float& x, const Float& y, const Float& z, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib3f>(index, x, y, z, src_loc);
}

void GlIndirect::VertexAttrib3fv(const Uint& index, const FloatArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib3fv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib3s(const Uint& index, const Short& x, const Short& y, const Short& z, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib3s>(index, x, y, z, src_loc);
}

void GlIndirect::VertexAttrib3sv(const Uint& index, const Short& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib3sv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4Nbv(const Uint& index, const Byte& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4Nbv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4Niv(const Uint& index, const IntArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4Niv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4Nsv(const Uint& index, const Short& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4Nsv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4Nub(const Uint& index, const Ubyte& x, const Ubyte& y, const Ubyte& z, const Ubyte& w, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4Nub>(index, x, y, z, w, src_loc);
}

void GlIndirect::VertexAttrib4Nubv(const Uint& index, const Ubyte& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4Nubv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4Nuiv(const Uint& index, const UintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4Nuiv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4Nusv(const Uint& index, const Ushort& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4Nusv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4bv(const Uint& index, const Byte& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4bv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4d(const Uint& index, const Double& x, const Double& y, const Double& z, const Double& w, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4d>(index, x, y, z, w, src_loc);
}

void GlIndirect::VertexAttrib4dv(const Uint& index, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4dv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4f(const Uint& index, const Float& x, const Float& y, const Float& z, const Float& w, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4f>(index, x, y, z, w, src_loc);
}

void GlIndirect::VertexAttrib4fv(const Uint& index, const FloatArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4fv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4iv(const Uint& index, const IntArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4iv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4s(const Uint& index, const Short& x, const Short& y, const Short& z, const Short& w, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4s>(index, x, y, z, w, src_loc);
}

void GlIndirect::VertexAttrib4sv(const Uint& index, const Short& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4sv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4ubv(const Uint& index, const Ubyte& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4ubv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4uiv(const Uint& index, const UintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4uiv>(index, v, src_loc);
}

void GlIndirect::VertexAttrib4usv(const Uint& index, const Ushort& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttrib4usv>(index, v, src_loc);
}

void GlIndirect::VertexAttribBinding(const Uint& attribindex, const Uint& bindingindex, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribBinding>(attribindex, bindingindex, src_loc);
}

void GlIndirect::VertexAttribDivisor(const Uint& index, const Uint& divisor, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribDivisor>(index, divisor, src_loc);
}

void GlIndirect::VertexAttribFormat(const Uint& attribindex, const Int& size, const Enum& type, const Boolean& normalized, const Uint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribFormat>(attribindex, size, type, normalized, relativeoffset, src_loc);
}

void GlIndirect::VertexAttribI1i(const Uint& index, const Int& x, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI1i>(index, x, src_loc);
}

void GlIndirect::VertexAttribI1iv(const Uint& index, const IntArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI1iv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI1ui(const Uint& index, const Uint& x, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI1ui>(index, x, src_loc);
}

void GlIndirect::VertexAttribI1uiv(const Uint& index, const UintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI1uiv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI2i(const Uint& index, const Int& x, const Int& y, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI2i>(index, x, y, src_loc);
}

void GlIndirect::VertexAttribI2iv(const Uint& index, const IntArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI2iv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI2ui(const Uint& index, const Uint& x, const Uint& y, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI2ui>(index, x, y, src_loc);
}

void GlIndirect::VertexAttribI2uiv(const Uint& index, const UintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI2uiv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI3i(const Uint& index, const Int& x, const Int& y, const Int& z, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI3i>(index, x, y, z, src_loc);
}

void GlIndirect::VertexAttribI3iv(const Uint& index, const IntArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI3iv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI3ui(const Uint& index, const Uint& x, const Uint& y, const Uint& z, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI3ui>(index, x, y, z, src_loc);
}

void GlIndirect::VertexAttribI3uiv(const Uint& index, const UintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI3uiv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI4bv(const Uint& index, const Byte& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI4bv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI4i(const Uint& index, const Int& x, const Int& y, const Int& z, const Int& w, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI4i>(index, x, y, z, w, src_loc);
}

void GlIndirect::VertexAttribI4iv(const Uint& index, const IntArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI4iv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI4sv(const Uint& index, const Short& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI4sv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI4ubv(const Uint& index, const Ubyte& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI4ubv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI4ui(const Uint& index, const Uint& x, const Uint& y, const Uint& z, const Uint& w, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI4ui>(index, x, y, z, w, src_loc);
}

void GlIndirect::VertexAttribI4uiv(const Uint& index, const UintArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI4uiv>(index, v, src_loc);
}

void GlIndirect::VertexAttribI4usv(const Uint& index, const Ushort& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribI4usv>(index, v, src_loc);
}

void GlIndirect::VertexAttribIFormat(const Uint& attribindex, const Int& size, const Enum& type, const Uint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribIFormat>(attribindex, size, type, relativeoffset, src_loc);
}

void GlIndirect::VertexAttribIPointer(const Uint& index, const Int& size, const Enum& type, const Sizei& stride, const Data& pointer, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribIPointer>(index, size, type, stride, pointer, src_loc);
}

void GlIndirect::VertexAttribL1d(const Uint& index, const Double& x, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribL1d>(index, x, src_loc);
}

void GlIndirect::VertexAttribL1dv(const Uint& index, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribL1dv>(index, v, src_loc);
}

void GlIndirect::VertexAttribL2d(const Uint& index, const Double& x, const Double& y, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribL2d>(index, x, y, src_loc);
}

void GlIndirect::VertexAttribL2dv(const Uint& index, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribL2dv>(index, v, src_loc);
}

void GlIndirect::VertexAttribL3d(const Uint& index, const Double& x, const Double& y, const Double& z, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribL3d>(index, x, y, z, src_loc);
}

void GlIndirect::VertexAttribL3dv(const Uint& index, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribL3dv>(index, v, src_loc);
}

void GlIndirect::VertexAttribL4d(const Uint& index, const Double& x, const Double& y, const Double& z, const Double& w, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribL4d>(index, x, y, z, w, src_loc);
}

void GlIndirect::VertexAttribL4dv(const Uint& index, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribL4dv>(index, v, src_loc);
}

void GlIndirect::VertexAttribLFormat(const Uint& attribindex, const Int& size, const Enum& type, const Uint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribLFormat>(attribindex, size, type, relativeoffset, src_loc);
}

void GlIndirect::VertexAttribLPointer(const Uint& index, const Int& size, const Enum& type, const Sizei& stride, const Data& pointer, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribLPointer>(index, size, type, stride, pointer, src_loc);
}

void GlIndirect::VertexAttribP1ui(const Uint& index, const Enum& type, const Boolean& normalized, const Uint& value, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribP1ui>(index, type, normalized, value, src_loc);
}

void GlIndirect::VertexAttribP1uiv(const Uint& index, const Enum& type, const Boolean& normalized, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribP1uiv>(index, type, normalized, value, src_loc);
}

void GlIndirect::VertexAttribP2ui(const Uint& index, const Enum& type, const Boolean& normalized, const Uint& value, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribP2ui>(index, type, normalized, value, src_loc);
}

void GlIndirect::VertexAttribP2uiv(const Uint& index, const Enum& type, const Boolean& normalized, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribP2uiv>(index, type, normalized, value, src_loc);
}

void GlIndirect::VertexAttribP3ui(const Uint& index, const Enum& type, const Boolean& normalized, const Uint& value, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribP3ui>(index, type, normalized, value, src_loc);
}

void GlIndirect::VertexAttribP3uiv(const Uint& index, const Enum& type, const Boolean& normalized, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribP3uiv>(index, type, normalized, value, src_loc);
}

void GlIndirect::VertexAttribP4ui(const Uint& index, const Enum& type, const Boolean& normalized, const Uint& value, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribP4ui>(index, type, normalized, value, src_loc);
}

void GlIndirect::VertexAttribP4uiv(const Uint& index, const Enum& type, const Boolean& normalized, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribP4uiv>(index, type, normalized, value, src_loc);
}

void GlIndirect::VertexAttribPointer(const Uint& index, const Int& size, const Enum& type, const Boolean& normalized, const Sizei& stride, const Data& pointer, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexAttribPointer>(index, size, type, normalized, stride, pointer, src_loc);
}

void GlIndirect::VertexBindingDivisor(const Uint& bindingindex, const Uint& divisor, const SrcLoc& src_loc){
    return _callGL<&Gl::VertexBindingDivisor>(bindingindex, divisor, src_loc);
}

void GlIndirect::Viewport(const Int& x, const Int& y, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&Gl::Viewport>(x, y, width, height, src_loc);
}

void GlIndirect::ViewportArrayv(const Uint& first, const Sizei& count, const FloatArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::ViewportArrayv>(first, count, v, src_loc);
}

void GlIndirect::ViewportIndexedf(const Uint& index, const Float& x, const Float& y, const Float& w, const Float& h, const SrcLoc& src_loc){
    return _callGL<&Gl::ViewportIndexedf>(index, x, y, w, h, src_loc);
}

void GlIndirect::ViewportIndexedfv(const Uint& index, const FloatArr& v, const SrcLoc& src_loc){
    return _callGL<&Gl::ViewportIndexedfv>(index, v, src_loc);
}

void GlIndirect::WaitSync(const Sync& sync, const Bitfield& flags, const Uint64& timeout, const SrcLoc& src_loc){
    return _callGL<&Gl::WaitSync>(sync, flags, timeout, src_loc);
}
