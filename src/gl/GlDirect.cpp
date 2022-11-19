#include "gl/GlDirect.hpp"

#include <iostream>
#include <string.h>
#include "glad/gl.h"

using namespace glwpp;
using namespace GL;

template<auto F, typename ... Args>
inline auto GlDirect::_callGL(const SrcLoc& src_loc, Args... args){
#ifdef GLWPP_DEBUG
    using R = std::invoke_result_t<decltype(*F), decltype(args)...>;
    if constexpr (std::is_same_v<R, void>){
            (*F)(args...);
            _debug(src_loc);
        } else {
            R dst((*F)(args...));
            _debug(src_loc);
            return dst;
        }
#else
    return F(std::forward<decltype(args)>(args)...);
#endif
}

GlDirect::GlDirect(const std::function<void(const SrcLoc&)>& debug) :
    Gl(debug){
}

GlDirect::~GlDirect(){
}

void GlDirect::debug(const SrcLoc& src_loc){
#ifdef GLWPP_DEBUG
    _debug(src_loc);
#endif
}

void GlDirect::callSimple(const std::function<void(Gl&)>& func){
    func(*this);
}

void GlDirect::ActiveShaderProgram(const Uint& pipeline, const Uint& program, const SrcLoc& src_loc){
    return _callGL<&glActiveShaderProgram>(src_loc, *pipeline, *program);
}

void GlDirect::ActiveTexture(const Enum& texture, const SrcLoc& src_loc){
    return _callGL<&glActiveTexture>(src_loc, *texture);
}

void GlDirect::AttachShader(const Uint& program, const Uint& shader, const SrcLoc& src_loc){
    return _callGL<&glAttachShader>(src_loc, *program, *shader);
}

void GlDirect::BeginConditionalRender(const Uint& id, const Enum& mode, const SrcLoc& src_loc){
    return _callGL<&glBeginConditionalRender>(src_loc, *id, *mode);
}

void GlDirect::BeginQuery(const Enum& target, const Uint& id, const SrcLoc& src_loc){
    return _callGL<&glBeginQuery>(src_loc, *target, *id);
}

void GlDirect::BeginQueryIndexed(const Enum& target, const Uint& index, const Uint& id, const SrcLoc& src_loc){
    return _callGL<&glBeginQueryIndexed>(src_loc, *target, *index, *id);
}

void GlDirect::BeginTransformFeedback(const Enum& primitiveMode, const SrcLoc& src_loc){
    return _callGL<&glBeginTransformFeedback>(src_loc, *primitiveMode);
}

void GlDirect::BindAttribLocation(const Uint& program, const Uint& index, const String& name, const SrcLoc& src_loc){
    return _callGL<&glBindAttribLocation>(src_loc, *program, *index, name->c_str());
}

void GlDirect::BindBuffer(const Enum& target, const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&glBindBuffer>(src_loc, *target, *buffer);
}

void GlDirect::BindBufferBase(const Enum& target, const Uint& index, const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&glBindBufferBase>(src_loc, *target, *index, *buffer);
}

void GlDirect::BindBufferRange(const Enum& target, const Uint& index, const Uint& buffer, const Intptr& offset, const Sizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&glBindBufferRange>(src_loc, *target, *index, *buffer, *offset, *size);
}

void GlDirect::BindBuffersBase(const Enum& target, const Uint& first, const Sizei& count, const UintArr& buffers, const SrcLoc& src_loc){
    return _callGL<&glBindBuffersBase>(src_loc, *target, *first, *count, buffers.get());
}

void GlDirect::BindBuffersRange(const Enum& target, const Uint& first, const Sizei& count, const UintArr& buffers, const IntptrArr& offsets, const SizeiptrArr& sizes, const SrcLoc& src_loc){
    return _callGL<&glBindBuffersRange>(src_loc, *target, *first, *count, buffers.get(), offsets.get(), sizes.get());
}

void GlDirect::BindFragDataLocation(const Uint& program, const Uint& color, const String& name, const SrcLoc& src_loc){
    return _callGL<&glBindFragDataLocation>(src_loc, *program, *color, name->c_str());
}

void GlDirect::BindFragDataLocationIndexed(const Uint& program, const Uint& colorNumber, const Uint& index, const String& name, const SrcLoc& src_loc){
    return _callGL<&glBindFragDataLocationIndexed>(src_loc, *program, *colorNumber, *index, name->c_str());
}

void GlDirect::BindFramebuffer(const Enum& target, const Uint& framebuffer, const SrcLoc& src_loc){
    return _callGL<&glBindFramebuffer>(src_loc, *target, *framebuffer);
}

void GlDirect::BindImageTexture(const Uint& unit, const Uint& texture, const Int& level, const Boolean& layered, const Int& layer, const Enum& access, const Enum& format, const SrcLoc& src_loc){
    return _callGL<&glBindImageTexture>(src_loc, *unit, *texture, *level, *layered, *layer, *access, *format);
}

void GlDirect::BindImageTextures(const Uint& first, const Sizei& count, const UintArr& textures, const SrcLoc& src_loc){
    return _callGL<&glBindImageTextures>(src_loc, *first, *count, textures.get());
}

void GlDirect::BindProgramPipeline(const Uint& pipeline, const SrcLoc& src_loc){
    return _callGL<&glBindProgramPipeline>(src_loc, *pipeline);
}

void GlDirect::BindRenderbuffer(const Enum& target, const Uint& renderbuffer, const SrcLoc& src_loc){
    return _callGL<&glBindRenderbuffer>(src_loc, *target, *renderbuffer);
}

void GlDirect::BindSampler(const Uint& unit, const Uint& sampler, const SrcLoc& src_loc){
    return _callGL<&glBindSampler>(src_loc, *unit, *sampler);
}

void GlDirect::BindSamplers(const Uint& first, const Sizei& count, const UintArr& samplers, const SrcLoc& src_loc){
    return _callGL<&glBindSamplers>(src_loc, *first, *count, samplers.get());
}

void GlDirect::BindTexture(const Enum& target, const Uint& texture, const SrcLoc& src_loc){
    return _callGL<&glBindTexture>(src_loc, *target, *texture);
}

void GlDirect::BindTextureUnit(const Uint& unit, const Uint& texture, const SrcLoc& src_loc){
    return _callGL<&glBindTextureUnit>(src_loc, *unit, *texture);
}

void GlDirect::BindTextures(const Uint& first, const Sizei& count, const UintArr& textures, const SrcLoc& src_loc){
    return _callGL<&glBindTextures>(src_loc, *first, *count, textures.get());
}

void GlDirect::BindTransformFeedback(const Enum& target, const Uint& id, const SrcLoc& src_loc){
    return _callGL<&glBindTransformFeedback>(src_loc, *target, *id);
}

void GlDirect::BindVertexArray(const Uint& array, const SrcLoc& src_loc){
    return _callGL<&glBindVertexArray>(src_loc, *array);
}

void GlDirect::BindVertexBuffer(const Uint& bindingindex, const Uint& buffer, const Intptr& offset, const Sizei& stride, const SrcLoc& src_loc){
    return _callGL<&glBindVertexBuffer>(src_loc, *bindingindex, *buffer, *offset, *stride);
}

void GlDirect::BindVertexBuffers(const Uint& first, const Sizei& count, const UintArr& buffers, const IntptrArr& offsets, const SizeiArr& strides, const SrcLoc& src_loc){
    return _callGL<&glBindVertexBuffers>(src_loc, *first, *count, buffers.get(), offsets.get(), strides.get());
}

void GlDirect::BlendColor(const Float& red, const Float& green, const Float& blue, const Float& alpha, const SrcLoc& src_loc){
    return _callGL<&glBlendColor>(src_loc, *red, *green, *blue, *alpha);
}

void GlDirect::BlendEquation(const Enum& mode, const SrcLoc& src_loc){
    return _callGL<&glBlendEquation>(src_loc, *mode);
}

void GlDirect::BlendEquationSeparate(const Enum& modeRGB, const Enum& modeAlpha, const SrcLoc& src_loc){
    return _callGL<&glBlendEquationSeparate>(src_loc, *modeRGB, *modeAlpha);
}

void GlDirect::BlendEquationSeparatei(const Uint& buf, const Enum& modeRGB, const Enum& modeAlpha, const SrcLoc& src_loc){
    return _callGL<&glBlendEquationSeparatei>(src_loc, *buf, *modeRGB, *modeAlpha);
}

void GlDirect::BlendEquationi(const Uint& buf, const Enum& mode, const SrcLoc& src_loc){
    return _callGL<&glBlendEquationi>(src_loc, *buf, *mode);
}

void GlDirect::BlendFunc(const Enum& sfactor, const Enum& dfactor, const SrcLoc& src_loc){
    return _callGL<&glBlendFunc>(src_loc, *sfactor, *dfactor);
}

void GlDirect::BlendFuncSeparate(const Enum& sfactorRGB, const Enum& dfactorRGB, const Enum& sfactorAlpha, const Enum& dfactorAlpha, const SrcLoc& src_loc){
    return _callGL<&glBlendFuncSeparate>(src_loc, *sfactorRGB, *dfactorRGB, *sfactorAlpha, *dfactorAlpha);
}

void GlDirect::BlendFuncSeparatei(const Uint& buf, const Enum& srcRGB, const Enum& dstRGB, const Enum& srcAlpha, const Enum& dstAlpha, const Enum& modeAlpha, const SrcLoc& src_loc){
    return _callGL<&glBlendFuncSeparatei>(src_loc, *buf, *srcRGB, *dstRGB, *srcAlpha, *dstAlpha);
}

void GlDirect::BlendFunci(const Uint& buf, const Enum& src, const Enum& dst, const SrcLoc& src_loc){
    return _callGL<&glBlendFunci>(src_loc, *buf, *src, *dst);
}

void GlDirect::BlitFramebuffer(const Int& srcX0, const Int& srcY0, const Int& srcX1, const Int& srcY1, const Int& dstX0, const Int& dstY0, const Int& dstX1, const Int& dstY1, const Bitfield& mask, const Enum& filter, const SrcLoc& src_loc){
    return _callGL<&glBlitFramebuffer>(src_loc, *srcX0, *srcY0, *srcX1, *srcY1, *dstX0, *dstY0, *dstX1, *dstY1, *mask, *filter);
}

void GlDirect::BlitNamedFramebuffer(const Uint& readFramebuffer, const Uint& drawFramebuffer, const Int& srcX0, const Int& srcY0, const Int& srcX1, const Int& srcY1, const Int& dstX0, const Int& dstY0, const Int& dstX1, const Int& dstY1, const Bitfield& mask, const Enum& filter, const SrcLoc& src_loc){
    return _callGL<&glBlitNamedFramebuffer>(src_loc, *readFramebuffer, *drawFramebuffer, *srcX0, *srcY0, *srcX1, *srcY1, *dstX0, *dstY0, *dstX1, *dstY1, *mask, *filter);
}

void GlDirect::BufferData(const Enum& target, const Sizeiptr& size, const Data& data, const Enum& usage, const SrcLoc& src_loc){
    return _callGL<&glBufferData>(src_loc, *target, *size, data.get(), *usage);
}

void GlDirect::BufferStorage(const Enum& target, const Sizeiptr& size, const Data& data, const Bitfield& flags, const SrcLoc& src_loc){
    return _callGL<&glBufferStorage>(src_loc, *target, *size, data.get(), *flags);
}

void GlDirect::BufferSubData(const Enum& target, const Intptr& offset, const Sizeiptr& size, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glBufferSubData>(src_loc, *target, *offset, *size, data.get());
}

GL::Enum GlDirect::CheckFramebufferStatus(const Enum& target, const SrcLoc& src_loc){
    return _callGL<&glCheckFramebufferStatus>(src_loc, *target);
}

GL::Enum GlDirect::CheckNamedFramebufferStatus(const Uint& framebuffer, const Enum& target, const SrcLoc& src_loc){
    return _callGL<&glCheckNamedFramebufferStatus>(src_loc, *framebuffer, *target);
}

void GlDirect::ClampColor(const Enum& target, const Enum& clamp, const SrcLoc& src_loc){
    return _callGL<&glClampColor>(src_loc, *target, *clamp);
}

void GlDirect::Clear(const Bitfield& mask, const SrcLoc& src_loc){
    return _callGL<&glClear>(src_loc, *mask);
}

void GlDirect::ClearBufferData(const Enum& target, const Enum& internalformat, const Enum& format, const Enum& type, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glClearBufferData>(src_loc, *target, *internalformat, *format, *type, data.get());
}

void GlDirect::ClearBufferSubData(const Enum& target, const Enum& internalformat, const Intptr& offset, const Sizeiptr& size, const Enum& format, const Enum& type, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glClearBufferSubData>(src_loc, *target, *internalformat, *offset, *size, *format, *type, data.get());
}

void GlDirect::ClearBufferfi(const Enum& buffer, const Int& drawbuffer, const Float& depth, const Int& stencil, const SrcLoc& src_loc){
    return _callGL<&glClearBufferfi>(src_loc, *buffer, *drawbuffer, *depth, *stencil);
}

void GlDirect::ClearBufferfv(const Enum& buffer, const Int& drawbuffer, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glClearBufferfv>(src_loc, *buffer, *drawbuffer, value.get());
}

void GlDirect::ClearBufferiv(const Enum& buffer, const Int& drawbuffer, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&glClearBufferiv>(src_loc, *buffer, *drawbuffer, value.get());
}

void GlDirect::ClearBufferuiv(const Enum& buffer, const Int& drawbuffer, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&glClearBufferuiv>(src_loc, *buffer, *drawbuffer, value.get());
}

void GlDirect::ClearColor(const Float& red, const Float& green, const Float& blue, const Float& alpha, const SrcLoc& src_loc){
    return _callGL<&glClearColor>(src_loc, *red, *green, *blue, *alpha);
}

void GlDirect::ClearDepth(const Double& depth, const SrcLoc& src_loc){
    return _callGL<&glClearDepth>(src_loc, *depth);
}

void GlDirect::ClearDepthf(const Float& d, const SrcLoc& src_loc){
    return _callGL<&glClearDepthf>(src_loc, *d);
}

void GlDirect::ClearNamedBufferData(const Uint& buffer, const Enum& internalformat, const Enum& format, const Enum& type, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glClearNamedBufferData>(src_loc, *buffer, *internalformat, *format, *type, data.get());
}

void GlDirect::ClearNamedBufferSubData(const Uint& buffer, const Enum& internalformat, const Intptr& offset, const Sizeiptr& size, const Enum& format, const Enum& type, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glClearNamedBufferSubData>(src_loc, *buffer, *internalformat, *offset, *size, *format, *type, data.get());
}

void GlDirect::ClearNamedFramebufferfi(const Uint& framebuffer, const Enum& buffer, const Int& drawbuffer, const Float& depth, const Int& stencil, const SrcLoc& src_loc){
    return _callGL<&glClearNamedFramebufferfi>(src_loc, *framebuffer, *buffer, *drawbuffer, *depth, *stencil);
}

void GlDirect::ClearNamedFramebufferfv(const Uint& framebuffer, const Enum& buffer, const Int& drawbuffer, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glClearNamedFramebufferfv>(src_loc, *framebuffer, *buffer, *drawbuffer, value.get());
}

void GlDirect::ClearNamedFramebufferiv(const Uint& framebuffer, const Enum& buffer, const Int& drawbuffer, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&glClearNamedFramebufferiv>(src_loc, *framebuffer, *buffer, *drawbuffer, value.get());
}

void GlDirect::ClearNamedFramebufferuiv(const Uint& framebuffer, const Enum& buffer, const Int& drawbuffer, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&glClearNamedFramebufferuiv>(src_loc, *framebuffer, *buffer, *drawbuffer, value.get());
}

void GlDirect::ClearStencil(const Int& s, const SrcLoc& src_loc){
    return _callGL<&glClearStencil>(src_loc, *s);
}

void GlDirect::ClearTexImage(const Uint& texture, const Int& level, const Enum& format, const Enum& type, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glClearTexImage>(src_loc, *texture, *level, *format, *type, data.get());
}

void GlDirect::ClearTexSubImage(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& width, const Sizei& height, const Sizei& depth, const Enum& format, const Enum& type, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glClearTexSubImage>(src_loc, *texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *type, data.get());
}

GL::Enum GlDirect::ClientWaitSync(const Sync& sync, const Bitfield& flags, const Uint64& timeout, const SrcLoc& src_loc){
    return _callGL<&glClientWaitSync>(src_loc, *sync, *flags, *timeout);
}

void GlDirect::ClipControl(const Enum& origin, const Enum& depth, const SrcLoc& src_loc){
    return _callGL<&glClipControl>(src_loc, *origin, *depth);
}

void GlDirect::ColorMask(const Boolean& red, const Boolean& green, const Boolean& blue, const Boolean& alpha, const SrcLoc& src_loc){
    return _callGL<&glColorMask>(src_loc, *red, *green, *blue, *alpha);
}

void GlDirect::ColorMaski(const Uint& index, const Boolean& r, const Boolean& g, const Boolean& b, const Boolean& a, const SrcLoc& src_loc){
    return _callGL<&glColorMaski>(src_loc, *index, *r, *g, *b, *a);
}

void GlDirect::CompileShader(const Uint& shader, const SrcLoc& src_loc){
    return _callGL<&glCompileShader>(src_loc, *shader);
}

void GlDirect::CompressedTexImage1D(const Enum& target, const Int& level, const Enum& internalformat, const Sizei& width, const Int& border, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTexImage1D>(src_loc, *target, *level, *internalformat, *width, *border, *imageSize, data.get());
}

void GlDirect::CompressedTexImage2D(const Enum& target, const Int& level, const Enum& internalformat, const Sizei& width, const Sizei& height, const Int& border, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTexImage2D>(src_loc, *target, *level, *internalformat, *width, *height, *border, *imageSize, data.get());
}

void GlDirect::CompressedTexImage3D(const Enum& target, const Int& level, const Enum& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const Int& border, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTexImage3D>(src_loc, *target, *level, *internalformat, *width, *height, *depth, *border, *imageSize, data.get());
}

void GlDirect::CompressedTexSubImage1D(const Enum& target, const Int& level, const Int& xoffset, const Sizei& width, const Enum& format, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTexSubImage1D>(src_loc, *target, *level, *xoffset, *width, *format, *imageSize, data.get());
}

void GlDirect::CompressedTexSubImage2D(const Enum& target, const Int& level, const Int& xoffset, const Int& yoffset, const Sizei& width, const Sizei& height, const Enum& format, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTexSubImage2D>(src_loc, *target, *level, *xoffset, *yoffset, *width, *height, *format, *imageSize, data.get());
}

void GlDirect::CompressedTexSubImage3D(const Enum& target, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& width, const Sizei& height, const Sizei& depth, const Enum& format, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTexSubImage3D>(src_loc, *target, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *imageSize, data.get());
}

void GlDirect::CompressedTextureSubImage1D(const Uint& texture, const Int& level, const Int& xoffset, const Sizei& width, const Enum& format, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTextureSubImage1D>(src_loc, *texture, *level, *xoffset, *width, *format, *imageSize, data.get());
}

void GlDirect::CompressedTextureSubImage2D(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Sizei& width, const Sizei& height, const Enum& format, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTextureSubImage2D>(src_loc, *texture, *level, *xoffset, *yoffset, *width, *height, *format, *imageSize, data.get());
}

void GlDirect::CompressedTextureSubImage3D(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& width, const Sizei& height, const Sizei& depth, const Enum& format, const Sizei& imageSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTextureSubImage3D>(src_loc, *texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *imageSize, data.get());
}

void GlDirect::CopyBufferSubData(const Enum& readTarget, const Enum& writeTarget, const Intptr& readOffset, const Intptr& writeOffset, const Sizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&glCopyBufferSubData>(src_loc, *readTarget, *writeTarget, *readOffset, *writeOffset, *size);
}

void GlDirect::CopyImageSubData(const Uint& srcName, const Enum& srcTarget, const Int& srcLevel, const Int& srcX, const Int& srcY, const Int& srcZ, const Uint& dstName, const Enum& dstTarget, const Int& dstLevel, const Int& dstX, const Int& dstY, const Int& dstZ, const Sizei& srcWidth, const Sizei& srcHeight, const Sizei& srcDepth, const SrcLoc& src_loc){
    return _callGL<&glCopyImageSubData>(src_loc, *srcName, *srcTarget, *srcLevel, *srcX, *srcY, *srcZ, *dstName, *dstTarget, *dstLevel, *dstX, *dstY, *dstZ, *srcWidth, *srcHeight, *srcDepth);
}

void GlDirect::CopyNamedBufferSubData(const Uint& readBuffer, const Uint& writeBuffer, const Intptr& readOffset, const Intptr& writeOffset, const Sizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&glCopyNamedBufferSubData>(src_loc, *readBuffer, *writeBuffer, *readOffset, *writeOffset, *size);
}

void GlDirect::CopyTexImage1D(const Enum& target, const Int& level, const Enum& internalformat, const Int& x, const Int& y, const Sizei& width, const Int& border, const SrcLoc& src_loc){
    return _callGL<&glCopyTexImage1D>(src_loc, *target, *level, *internalformat, *x, *y, *width, *border);
}

void GlDirect::CopyTexImage2D(const Enum& target, const Int& level, const Enum& internalformat, const Int& x, const Int& y, const Sizei& width, const Sizei& height, const Int& border, const SrcLoc& src_loc){
    return _callGL<&glCopyTexImage2D>(src_loc, *target, *level, *internalformat, *x, *y, *width, *height, *border);
}

void GlDirect::CopyTexSubImage1D(const Enum& target, const Int& level, const Int& xoffset, const Int& x, const Int& y, const Sizei& width, const SrcLoc& src_loc){
    return _callGL<&glCopyTexSubImage1D>(src_loc, *target, *level, *xoffset, *x, *y, *width);
}

void GlDirect::CopyTexSubImage2D(const Enum& target, const Int& level, const Int& xoffset, const Int& yoffset, const Int& x, const Int& y, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&glCopyTexSubImage2D>(src_loc, *target, *level, *xoffset, *yoffset, *x, *y, *width, *height);
}

void GlDirect::CopyTexSubImage3D(const Enum& target, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Int& x, const Int& y, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&glCopyTexSubImage3D>(src_loc, *target, *level, *xoffset, *yoffset, *zoffset, *x, *y, *width, *height);
}

void GlDirect::CopyTextureSubImage1D(const Uint& texture, const Int& level, const Int& xoffset, const Int& x, const Int& y, const Sizei& width, const SrcLoc& src_loc){
    return _callGL<&glCopyTextureSubImage1D>(src_loc, *texture, *level, *xoffset, *x, *y, *width);
}

void GlDirect::CopyTextureSubImage2D(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Int& x, const Int& y, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&glCopyTextureSubImage2D>(src_loc, *texture, *level, *xoffset, *yoffset, *x, *y, *width, *height);
}

void GlDirect::CopyTextureSubImage3D(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Int& x, const Int& y, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&glCopyTextureSubImage3D>(src_loc, *texture, *level, *xoffset, *yoffset, *zoffset, *x, *y, *width, *height);
}

void GlDirect::CreateBuffers(const Sizei& n, const UintArr& dst, const SrcLoc& src_loc){
    return _callGL<&glCreateBuffers>(src_loc, *n, dst.get());
}

void GlDirect::CreateFramebuffers(const Sizei& n, const UintArr& framebuffers, const SrcLoc& src_loc){
    return _callGL<&glCreateFramebuffers>(src_loc, *n, framebuffers.get());
}

GL::Uint GlDirect::CreateProgram(const SrcLoc& src_loc){
    return _callGL<&glCreateProgram>(src_loc);
}

void GlDirect::CreateProgramPipelines(const Sizei& n, const UintArr& pipelines, const SrcLoc& src_loc){
    return _callGL<&glCreateProgramPipelines>(src_loc, *n, pipelines.get());
}

void GlDirect::CreateQueries(const Enum& target, const Sizei& n, const UintArr& ids, const SrcLoc& src_loc){
    return _callGL<&glCreateQueries>(src_loc, *target, *n, ids.get());
}

void GlDirect::CreateRenderbuffers(const Sizei& n, const UintArr& renderbuffers, const SrcLoc& src_loc){
    return _callGL<&glCreateRenderbuffers>(src_loc, *n, renderbuffers.get());
}

void GlDirect::CreateSamplers(const Sizei& n, const UintArr& samplers, const SrcLoc& src_loc){
    return _callGL<&glCreateSamplers>(src_loc, *n, samplers.get());
}

GL::Uint GlDirect::CreateShader(const Enum& type, const SrcLoc& src_loc){
    return _callGL<&glCreateShader>(src_loc, *type);
}

GL::Uint GlDirect::CreateShaderProgramv(const Enum& type, const Sizei& count, const StringArr& strings, const SrcLoc& src_loc){
    const char** ptrs = new const char*[*count];
    for (size_t i = 0; i < *count; ++i){
        ptrs[i] = (strings.get())[i].c_str();
    }
    auto res = _callGL<&glCreateShaderProgramv>(src_loc, *type, *count, ptrs);
    delete[] ptrs;
    return res;
}

void GlDirect::CreateTextures(const Enum& target, const Sizei& n, const UintArr& textures, const SrcLoc& src_loc){
    return _callGL<&glCreateTextures>(src_loc, *target, *n, textures.get());
}

void GlDirect::CreateTransformFeedbacks(const Sizei& n, const UintArr& ids, const SrcLoc& src_loc){
    return _callGL<&glCreateTransformFeedbacks>(src_loc, *n, ids.get());
}

void GlDirect::CreateVertexArrays(const Sizei& n, const UintArr& arrays, const SrcLoc& src_loc){
    return _callGL<&glCreateVertexArrays>(src_loc, *n, arrays.get());
}

void GlDirect::CullFace(const Enum& mode, const SrcLoc& src_loc){
    return _callGL<&glCullFace>(src_loc, *mode);
}

// void InterfaceGlInner::DebugMessageCallback(const GLDEBUGPROC& callback, const Data& userParam, const SrcLoc& src_loc){
// &    _callGL<glDebugMessageCallback>(src_loc, *callback, userParam.get());
//     _debug(src_loc);
// }

void GlDirect::DebugMessageControl(const Enum& source, const Enum& type, const Enum& severity, const Sizei& count, const UintArr& ids, const Boolean& enabled, const SrcLoc& src_loc){
    return _callGL<&glDebugMessageControl>(src_loc, *source, *type, *severity, *count, ids.get(), *enabled);
}

void GlDirect::DebugMessageInsert(const Enum& source, const Enum& type, const Uint& id, const Enum& severity, const Sizei& length, const String& buf, const SrcLoc& src_loc){
    return _callGL<&glDebugMessageInsert>(src_loc, *source, *type, *id, *severity, *length, buf->c_str());
}

void GlDirect::DeleteBuffers(const Sizei& n, const UintArr& buffers, const SrcLoc& src_loc){
    return _callGL<&glDeleteBuffers>(src_loc, *n, buffers.get());
}

void GlDirect::DeleteFramebuffers(const Sizei& n, const UintArr& framebuffers, const SrcLoc& src_loc){
    return _callGL<&glDeleteFramebuffers>(src_loc, *n, framebuffers.get());
}

void GlDirect::DeleteProgram(const Uint& program, const SrcLoc& src_loc){
    return _callGL<&glDeleteProgram>(src_loc, *program);
}

void GlDirect::DeleteProgramPipelines(const Sizei& n, const UintArr& pipelines, const SrcLoc& src_loc){
    return _callGL<&glDeleteProgramPipelines>(src_loc, *n, pipelines.get());
}

void GlDirect::DeleteQueries(const Sizei& n, const UintArr& ids, const SrcLoc& src_loc){
    return _callGL<&glDeleteQueries>(src_loc, *n, ids.get());
}

void GlDirect::DeleteRenderbuffers(const Sizei& n, const UintArr& renderbuffers, const SrcLoc& src_loc){
    return _callGL<&glDeleteRenderbuffers>(src_loc, *n, renderbuffers.get());
}

void GlDirect::DeleteSamplers(const Sizei& count, const UintArr& samplers, const SrcLoc& src_loc){
    return _callGL<&glDeleteSamplers>(src_loc, *count, samplers.get());
}

void GlDirect::DeleteShader(const Uint& shader, const SrcLoc& src_loc){
    return _callGL<&glDeleteShader>(src_loc, *shader);
}

void GlDirect::DeleteSync(const Sync& sync, const SrcLoc& src_loc){
    return _callGL<&glDeleteSync>(src_loc, *sync);
}

void GlDirect::DeleteTextures(const Sizei& n, const UintArr& textures, const SrcLoc& src_loc){
    return _callGL<&glDeleteTextures>(src_loc, *n, textures.get());
}

void GlDirect::DeleteTransformFeedbacks(const Sizei& n, const UintArr& ids, const SrcLoc& src_loc){
    return _callGL<&glDeleteTransformFeedbacks>(src_loc, *n, ids.get());
}

void GlDirect::DeleteVertexArrays(const Sizei& n, const UintArr& arrays, const SrcLoc& src_loc){
    return _callGL<&glDeleteVertexArrays>(src_loc, *n, arrays.get());
}

void GlDirect::DepthFunc(const Enum& func, const SrcLoc& src_loc){
    return _callGL<&glDepthFunc>(src_loc, *func);
}

void GlDirect::DepthMask(const Boolean& flag, const SrcLoc& src_loc){
    return _callGL<&glDepthMask>(src_loc, *flag);
}

void GlDirect::DepthRange(const Double& n, const Double& f, const SrcLoc& src_loc){
    return _callGL<&glDepthRange>(src_loc, *n, *f);
}

void GlDirect::DepthRangeArrayv(const Uint& first, const Sizei& count, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glDepthRangeArrayv>(src_loc, *first, *count, v.get());
}

void GlDirect::DepthRangeIndexed(const Uint& index, const Double& n, const Double& f, const SrcLoc& src_loc){
    return _callGL<&glDepthRangeIndexed>(src_loc, *index, *n, *f);
}

void GlDirect::DepthRangef(const Float& n, const Float& f, const SrcLoc& src_loc){
    return _callGL<&glDepthRangef>(src_loc, *n, *f);
}

void GlDirect::DetachShader(const Uint& program, const Uint& shader, const SrcLoc& src_loc){
    return _callGL<&glDetachShader>(src_loc, *program, *shader);
}

void GlDirect::Disable(const Enum& cap, const SrcLoc& src_loc){
    return _callGL<&glDisable>(src_loc, *cap);
}

void GlDirect::DisableVertexArrayAttrib(const Uint& vaobj, const Uint& index, const SrcLoc& src_loc){
    return _callGL<&glDisableVertexArrayAttrib>(src_loc, *vaobj, *index);
}

void GlDirect::DisableVertexAttribArray(const Uint& index, const SrcLoc& src_loc){
    return _callGL<&glDisableVertexAttribArray>(src_loc, *index);
}

void GlDirect::Disablei(const Enum& target, const Uint& index, const SrcLoc& src_loc){
    return _callGL<&glDisablei>(src_loc, *target, *index);
}

void GlDirect::DispatchCompute(const Uint& num_groups_x, const Uint& num_groups_y, const Uint& num_groups_z, const SrcLoc& src_loc){
    return _callGL<&glDispatchCompute>(src_loc, *num_groups_x, *num_groups_y, *num_groups_z);
}

void GlDirect::DispatchComputeIndirect(const Intptr& indirect, const SrcLoc& src_loc){
    return _callGL<&glDispatchComputeIndirect>(src_loc, *indirect);
}

void GlDirect::DrawArrays(const Enum& mode, const Int& first, const Sizei& count, const SrcLoc& src_loc){
    return _callGL<&glDrawArrays>(src_loc, *mode, *first, *count);
}

void GlDirect::DrawArraysIndirect(const Enum& mode, const Data& indirect, const SrcLoc& src_loc){
    return _callGL<&glDrawArraysIndirect>(src_loc, *mode, indirect.get());
}

void GlDirect::DrawArraysInstanced(const Enum& mode, const Int& first, const Sizei& count, const Sizei& instancecount, const SrcLoc& src_loc){
    return _callGL<&glDrawArraysInstanced>(src_loc, *mode, *first, *count, *instancecount);
}

void GlDirect::DrawArraysInstancedBaseInstance(const Enum& mode, const Int& first, const Sizei& count, const Sizei& instancecount, const Uint& baseinstance, const SrcLoc& src_loc){
    return _callGL<&glDrawArraysInstancedBaseInstance>(src_loc, *mode, *first, *count, *instancecount, *instancecount);
}

void GlDirect::DrawBuffer(const Enum& buf, const SrcLoc& src_loc){
    return _callGL<&glDrawBuffer>(src_loc, *buf);
}

void GlDirect::DrawBuffers(const Sizei& n, const EnumArr& bufs, const SrcLoc& src_loc){
    return _callGL<&glDrawBuffers>(src_loc, *n, bufs.get());
}

void GlDirect::DrawElements(const Enum& mode, const Sizei& count, const Enum& type, const Data& indices, const SrcLoc& src_loc){
    return _callGL<&glDrawElements>(src_loc, *mode, *count, *type, indices.get());
}

void GlDirect::DrawElementsBaseVertex(const Enum& mode, const Sizei& count, const Enum& type, const Data& indices, const Int& basevertex, const SrcLoc& src_loc){
    return _callGL<&glDrawElementsBaseVertex>(src_loc, *mode, *count, *type, indices.get(), *basevertex);
}

void GlDirect::DrawElementsIndirect(const Enum& mode, const Enum& type, const Data& indirect, const SrcLoc& src_loc){
    return _callGL<&glDrawElementsIndirect>(src_loc, *mode, *type, indirect.get());
}

void GlDirect::DrawElementsInstanced(const Enum& mode, const Sizei& count, const Enum& type, const Data& indices, const Sizei& instancecount, const SrcLoc& src_loc){
    return _callGL<&glDrawElementsInstanced>(src_loc, *mode, *count, *type, indices.get(), *instancecount);
}

void GlDirect::DrawElementsInstancedBaseInstance(const Enum& mode, const Sizei& count, const Enum& type, const Data& indices, const Sizei& instancecount, const Uint& baseinstance, const SrcLoc& src_loc){
    return _callGL<&glDrawElementsInstancedBaseInstance>(src_loc, *mode, *count, *type, indices.get(), *instancecount, *baseinstance);
}

void GlDirect::DrawElementsInstancedBaseVertex(const Enum& mode, const Sizei& count, const Enum& type, const Data& indices, const Sizei& instancecount, const Int& basevertex, const SrcLoc& src_loc){
    return _callGL<&glDrawElementsInstancedBaseVertex>(src_loc, *mode, *count, *type, indices.get(), *instancecount, *basevertex);
}

void GlDirect::DrawElementsInstancedBaseVertexBaseInstance(const Enum& mode, const Sizei& count, const Enum& type, const Data& indices, const Sizei& instancecount, const Int& basevertex, const Uint& baseinstance, const SrcLoc& src_loc){
    return _callGL<&glDrawElementsInstancedBaseVertexBaseInstance>(src_loc, *mode, *count, *type, indices.get(), *instancecount, *basevertex, *baseinstance);
}

void GlDirect::DrawRangeElements(const Enum& mode, const Uint& start, const Uint& end, const Sizei& count, const Enum& type, const Data& indices, const SrcLoc& src_loc){
    return _callGL<&glDrawRangeElements>(src_loc, *mode, *start, *end, *count, *type, indices.get());
}

void GlDirect::DrawRangeElementsBaseVertex(const Enum& mode, const Uint& start, const Uint& end, const Sizei& count, const Enum& type, const Data& indices, const Int& basevertex, const SrcLoc& src_loc){
    return _callGL<&glDrawRangeElementsBaseVertex>(src_loc, *mode, *start, *end, *count, *type, indices.get(), *basevertex);
}

void GlDirect::DrawTransformFeedback(const Enum& mode, const Uint& id, const SrcLoc& src_loc){
    return _callGL<&glDrawTransformFeedback>(src_loc, *mode, *id);
}

void GlDirect::DrawTransformFeedbackInstanced(const Enum& mode, const Uint& id, const Sizei& instancecount, const SrcLoc& src_loc){
    return _callGL<&glDrawTransformFeedbackInstanced>(src_loc, *mode, *id, *instancecount);
}

void GlDirect::DrawTransformFeedbackStream(const Enum& mode, const Uint& id, const Uint& stream, const SrcLoc& src_loc){
    return _callGL<&glDrawTransformFeedbackStream>(src_loc, *mode, *id, *stream);
}

void GlDirect::DrawTransformFeedbackStreamInstanced(const Enum& mode, const Uint& id, const Uint& stream, const Sizei& instancecount, const SrcLoc& src_loc){
    return _callGL<&glDrawTransformFeedbackStreamInstanced>(src_loc, *mode, *id, *stream, *instancecount);
}

void GlDirect::Enable(const Enum& cap, const SrcLoc& src_loc){
    return _callGL<&glEnable>(src_loc, *cap);
}

void GlDirect::EnableVertexArrayAttrib(const Uint& vaobj, const Uint& index, const SrcLoc& src_loc){
    return _callGL<&glEnableVertexArrayAttrib>(src_loc, *vaobj, *index);
}

void GlDirect::EnableVertexAttribArray(const Uint& index, const SrcLoc& src_loc){
    return _callGL<&glEnableVertexAttribArray>(src_loc, *index);
}

void GlDirect::Enablei(const Enum& target, const Uint& index, const SrcLoc& src_loc){
    return _callGL<&glEnablei>(src_loc, *target, *index);
}

void GlDirect::EndConditionalRender(const SrcLoc& src_loc){
    return _callGL<&glEndConditionalRender>(src_loc);
}

void GlDirect::EndQuery(const Enum& target, const SrcLoc& src_loc){
    return _callGL<&glEndQuery>(src_loc, *target);
}

void GlDirect::EndQueryIndexed(const Enum& target, const Uint& index, const SrcLoc& src_loc){
    return _callGL<&glEndQueryIndexed>(src_loc, *target, *index);
}

void GlDirect::EndTransformFeedback(const SrcLoc& src_loc){
    return _callGL<&glEndTransformFeedback>(src_loc);
}

GL::Sync GlDirect::FenceSync(const Enum& condition, const Bitfield& flags, const SrcLoc& src_loc){
    return _callGL<&glFenceSync>(src_loc, *condition, *flags);
}

void GlDirect::Finish(const SrcLoc& src_loc){
    return _callGL<&glFinish>(src_loc);
}

void GlDirect::Flush(const SrcLoc& src_loc){
    return _callGL<&glFlush>(src_loc);
}

void GlDirect::FlushMappedBufferRange(const Enum& target, const Intptr& offset, const Sizeiptr& length, const SrcLoc& src_loc){
    return _callGL<&glFlushMappedBufferRange>(src_loc, *target, *offset, *length);
}

void GlDirect::FlushMappedNamedBufferRange(const Uint& buffer, const Intptr& offset, const Sizeiptr& length, const SrcLoc& src_loc){
    return _callGL<&glFlushMappedNamedBufferRange>(src_loc, *buffer, *offset, *length);
}

void GlDirect::FramebufferParameteri(const Enum& target, const Enum& pname, const Int& param, const SrcLoc& src_loc){
    return _callGL<&glFramebufferParameteri>(src_loc, *target, *pname, *param);
}

void GlDirect::FramebufferRenderbuffer(const Enum& target, const Enum& attachment, const Enum& renderbuffertarget, const Uint& renderbuffer, const SrcLoc& src_loc){
    return _callGL<&glFramebufferRenderbuffer>(src_loc, *target, *attachment, *renderbuffertarget, *renderbuffer);
}

void GlDirect::FramebufferTexture(const Enum& target, const Enum& attachment, const Uint& texture, const Int& level, const SrcLoc& src_loc){
    return _callGL<&glFramebufferTexture>(src_loc, *target, *attachment, *texture, *level);
}

void GlDirect::FramebufferTexture1D(const Enum& target, const Enum& attachment, const Enum& textarget, const Uint& texture, const Int& level, const SrcLoc& src_loc){
    return _callGL<&glFramebufferTexture1D>(src_loc, *target, *attachment, *textarget, *target, *level);
}

void GlDirect::FramebufferTexture2D(const Enum& target, const Enum& attachment, const Enum& textarget, const Uint& texture, const Int& level, const SrcLoc& src_loc){
    return _callGL<&glFramebufferTexture2D>(src_loc, *target, *attachment, *textarget, *texture, *level);
}

void GlDirect::FramebufferTexture3D(const Enum& target, const Enum& attachment, const Enum& textarget, const Uint& texture, const Int& level, const Int& zoffset, const SrcLoc& src_loc){
    return _callGL<&glFramebufferTexture3D>(src_loc, *target, *attachment, *textarget, *texture, *level, *zoffset);
}

void GlDirect::FramebufferTextureLayer(const Enum& target, const Enum& attachment, const Uint& texture, const Int& level, const Int& layer, const SrcLoc& src_loc){
    return _callGL<&glFramebufferTextureLayer>(src_loc, *target, *attachment, *texture, *level, *layer);
}

void GlDirect::FrontFace(const Enum& mode, const SrcLoc& src_loc){
    return _callGL<&glFrontFace>(src_loc, *mode);
}

void GlDirect::GenBuffers(const Sizei& n, const UintArr& buffers, const SrcLoc& src_loc){
    return _callGL<&glGenBuffers>(src_loc, *n, buffers.get());
}

void GlDirect::GenFramebuffers(const Sizei& n, const UintArr& framebuffers, const SrcLoc& src_loc){
    return _callGL<&glGenFramebuffers>(src_loc, *n, framebuffers.get());
}

void GlDirect::GenProgramPipelines(const Sizei& n, const UintArr& pipelines, const SrcLoc& src_loc){
    return _callGL<&glGenProgramPipelines>(src_loc, *n, pipelines.get());
}

void GlDirect::GenQueries(const Sizei& n, const UintArr& ids, const SrcLoc& src_loc){
    return _callGL<&glGenQueries>(src_loc, *n, ids.get());
}

void GlDirect::GenRenderbuffers(const Sizei& n, const UintArr& renderbuffers, const SrcLoc& src_loc){
    return _callGL<&glGenRenderbuffers>(src_loc, *n, renderbuffers.get());
}

void GlDirect::GenSamplers(const Sizei& count, const UintArr& samplers, const SrcLoc& src_loc){
    return _callGL<&glGenSamplers>(src_loc, *count, samplers.get());
}

void GlDirect::GenTextures(const Sizei& n, const UintArr& textures, const SrcLoc& src_loc){
    return _callGL<&glGenTextures>(src_loc, *n, textures.get());
}

void GlDirect::GenTransformFeedbacks(const Sizei& n, const UintArr& ids, const SrcLoc& src_loc){
    return _callGL<&glGenTransformFeedbacks>(src_loc, *n, ids.get());
}

void GlDirect::GenVertexArrays(const Sizei& n, const UintArr& arrays, const SrcLoc& src_loc){
    return _callGL<&glGenVertexArrays>(src_loc, *n, arrays.get());
}

void GlDirect::GenerateMipmap(const Enum& target, const SrcLoc& src_loc){
    return _callGL<&glGenerateMipmap>(src_loc, *target);
}

void GlDirect::GenerateTextureMipmap(const Uint& texture, const SrcLoc& src_loc){
    return _callGL<&glGenerateTextureMipmap>(src_loc, *texture);
}

void GlDirect::GetActiveAtomicCounterBufferiv(const Uint& program, const Uint& bufferIndex, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetActiveAtomicCounterBufferiv>(src_loc, *program, *bufferIndex, *pname, params.get());
}

void GlDirect::GetActiveAttrib(const Uint& program, const Uint& index, const Sizei& bufSize, const Sizei& length, const Int& size, const Enum& type, const String& name, const SrcLoc& src_loc){
    return _callGL<&glGetActiveAttrib>(src_loc, *program, *index, *bufSize, length.get(), size.get(), type.get(), name->data());
}

void GlDirect::GetActiveSubroutineName(const Uint& program, const Enum& shadertype, const Uint& index, const Sizei& bufSize, const Sizei& length, const String& name, const SrcLoc& src_loc){
    return _callGL<&glGetActiveSubroutineName>(src_loc, *program, *shadertype, *index, *bufSize, length.get(), name->data());
}

void GlDirect::GetActiveSubroutineUniformName(const Uint& program, const Enum& shadertype, const Uint& index, const Sizei& bufSize, const Sizei& length, const String& name, const SrcLoc& src_loc){
    return _callGL<&glGetActiveSubroutineUniformName>(src_loc, *program, *shadertype, *index, *bufSize, length.get(), name->data());
}

void GlDirect::GetActiveSubroutineUniformiv(const Uint& program, const Enum& shadertype, const Uint& index, const Enum& pname, const IntArr& values, const SrcLoc& src_loc){
    return _callGL<&glGetActiveSubroutineUniformiv>(src_loc, *program, *shadertype, *index, *pname, values.get());
}

void GlDirect::GetActiveUniform(const Uint& program, const Uint& index, const Sizei& bufSize, const Sizei& length, const Int& size, const Enum& type, const String& name, const SrcLoc& src_loc){
    return _callGL<&glGetActiveUniform>(src_loc, *program, *index, *bufSize, length.get(), size.get(), type.get(), name->data());
}

void GlDirect::GetActiveUniformBlockName(const Uint& program, const Uint& uniformBlockIndex, const Sizei& bufSize, const Sizei& length, const String& uniformBlockName, const SrcLoc& src_loc){
    return _callGL<&glGetActiveUniformBlockName>(src_loc, *program, *uniformBlockIndex, *bufSize, length.get(), uniformBlockName->data());
}

void GlDirect::GetActiveUniformBlockiv(const Uint& program, const Uint& uniformBlockIndex, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetActiveUniformBlockiv>(src_loc, *program, *uniformBlockIndex, *pname, params.get());
}

void GlDirect::GetActiveUniformName(const Uint& program, const Uint& uniformIndex, const Sizei& bufSize, const Sizei& length, const String& uniformName, const SrcLoc& src_loc){
    return _callGL<&glGetActiveUniformName>(src_loc, *program, *uniformIndex, *bufSize, length.get(), uniformName->data());
}

void GlDirect::GetActiveUniformsiv(const Uint& program, const Sizei& uniformCount, const UintArr& uniformIndices, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetActiveUniformsiv>(src_loc, *program, *uniformCount, uniformIndices.get(), *pname, params.get());
}

void GlDirect::GetAttachedShaders(const Uint& program, const Sizei& maxCount, const SizeiArr& count, const UintArr& shaders, const SrcLoc& src_loc){
    return _callGL<&glGetAttachedShaders>(src_loc, *program, *maxCount, count.get(), shaders.get());
}

GL::Int GlDirect::GetAttribLocation(const Uint& program, const String& name, const SrcLoc& src_loc){
    return _callGL<&glGetAttribLocation>(src_loc, *program, name->c_str());
}

void GlDirect::GetBooleani_v(const Enum& target, const Uint& index, const BooleanArr& data, const SrcLoc& src_loc){
    return _callGL<&glGetBooleani_v>(src_loc, *target, *index, data.get());
}

void GlDirect::GetBooleanv(const Enum& pname, const BooleanArr& data, const SrcLoc& src_loc){
    return _callGL<&glGetBooleanv>(src_loc, *pname, data.get());
}

void GlDirect::GetBufferParameteri64v(const Enum& target, const Enum& pname, const Int64Arr& params, const SrcLoc& src_loc){
    return _callGL<&glGetBufferParameteri64v>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetBufferParameteriv(const Enum& target, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetBufferParameteriv>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetBufferPointerv(const Enum& target, const Enum& pname, const DataPtr& params, const SrcLoc& src_loc){
    return _callGL<&glGetBufferPointerv>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetBufferSubData(const Enum& target, const Intptr& offset, const Sizeiptr& size, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glGetBufferSubData>(src_loc, *target, *offset, *size, data.get());
}

void GlDirect::GetCompressedTexImage(const Enum& target, const Int& level, const Data& img, const SrcLoc& src_loc){
    return _callGL<&glGetCompressedTexImage>(src_loc, *target, *level, img.get());
}

void GlDirect::GetCompressedTextureImage(const Uint& texture, const Int& level, const Sizei& bufSize, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glGetCompressedTextureImage>(src_loc, *texture, *level, *bufSize, pixels.get());
}

void GlDirect::GetCompressedTextureSubImage(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& width, const Sizei& height, const Sizei& depth, const Sizei& bufSize, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glGetCompressedTextureSubImage>(src_loc, *texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *bufSize, pixels.get());
}

GL::Uint GlDirect::GetDebugMessageLog(const Uint& count, const Sizei& bufSize, const EnumArr& sources, const EnumArr& types, const UintArr& ids, const EnumArr& severities, const Sizei& lengths, const String& messageLog, const SrcLoc& src_loc){
    return _callGL<&glGetDebugMessageLog>(src_loc, *count, *bufSize, sources.get(), types.get(), ids.get(), severities.get(), lengths.get(), messageLog->data());
}

void GlDirect::GetDoublei_v(const Enum& target, const Uint& index, const DoubleArr& data, const SrcLoc& src_loc){
    return _callGL<&glGetDoublei_v>(src_loc, *target, *index, data.get());
}

void GlDirect::GetDoublev(const Enum& pname, const DoubleArr& data, const SrcLoc& src_loc){
    return _callGL<&glGetDoublev>(src_loc, *pname, data.get());
}

GL::Enum GlDirect::GetError(const SrcLoc& src_loc){
    return _callGL<&glGetError>(src_loc);
}

void GlDirect::GetFloati_v(const Enum& target, const Uint& index, const FloatArr& data, const SrcLoc& src_loc){
    return _callGL<&glGetFloati_v>(src_loc, *target, *index, data.get());
}

void GlDirect::GetFloatv(const Enum& pname, const FloatArr& data, const SrcLoc& src_loc){
    return _callGL<&glGetFloatv>(src_loc, *pname, data.get());
}

GL::Int GlDirect::GetFragDataIndex(const Uint& program, const String& name, const SrcLoc& src_loc){
    return _callGL<&glGetFragDataIndex>(src_loc, *program, name->c_str());
}

GL::Int GlDirect::GetFragDataLocation(const Uint& program, const String& name, const SrcLoc& src_loc){
    return _callGL<&glGetFragDataLocation>(src_loc, *program, name->c_str());
}

void GlDirect::GetFramebufferAttachmentParameteriv(const Enum& target, const Enum& attachment, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetFramebufferAttachmentParameteriv>(src_loc, *target, *attachment, *pname, params.get());
}

void GlDirect::GetFramebufferParameteriv(const Enum& target, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetFramebufferParameteriv>(src_loc, *target, *pname, params.get());
}

GL::Enum GlDirect::GetGraphicsResetStatus(const SrcLoc& src_loc){
    return _callGL<&glGetGraphicsResetStatus>(src_loc);
}

void GlDirect::GetInteger64i_v(const Enum& target, const Uint& index, const Int64Arr& data, const SrcLoc& src_loc){
    return _callGL<&glGetInteger64i_v>(src_loc, *target, *index, data.get());
}

void GlDirect::GetInteger64v(const Enum& pname, const Int64Arr& data, const SrcLoc& src_loc){
    return _callGL<&glGetInteger64v>(src_loc, *pname, data.get());
}

void GlDirect::GetIntegeri_v(const Enum& target, const Uint& index, const IntArr& data, const SrcLoc& src_loc){
    return _callGL<&glGetIntegeri_v>(src_loc, *target, *index, data.get());
}

void GlDirect::GetIntegerv(const Enum& pname, const IntArr& data, const SrcLoc& src_loc){
    return _callGL<&glGetIntegerv>(src_loc, *pname, data.get());
}

void GlDirect::GetInternalformati64v(const Enum& target, const Enum& internalformat, const Enum& pname, const Sizei& count, const Int64Arr& params, const SrcLoc& src_loc){
    return _callGL<&glGetInternalformati64v>(src_loc, *target, *internalformat, *pname, *count, params.get());
}

void GlDirect::GetInternalformativ(const Enum& target, const Enum& internalformat, const Enum& pname, const Sizei& count, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetInternalformativ>(src_loc, *target, *internalformat, *pname, *count, params.get());
}

void GlDirect::GetMultisamplefv(const Enum& pname, const Uint& index, const FloatArr& val, const SrcLoc& src_loc){
    return _callGL<&glGetMultisamplefv>(src_loc, *pname, *index, val.get());
}

void GlDirect::GetNamedBufferParameteri64v(const Uint& buffer, const Enum& pname, const Int64Arr& params, const SrcLoc& src_loc){
    return _callGL<&glGetNamedBufferParameteri64v>(src_loc, *buffer, *pname, params.get());
}

void GlDirect::GetNamedBufferParameteriv(const Uint& buffer, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetNamedBufferParameteriv>(src_loc, *buffer, *pname, params.get());
}

void GlDirect::GetNamedBufferPointerv(const Uint& buffer, const Enum& pname, const DataPtr& params, const SrcLoc& src_loc){
    return _callGL<&glGetNamedBufferPointerv>(src_loc, *buffer, *pname, params.get());
}

void GlDirect::GetNamedBufferSubData(const Uint& buffer, const Intptr& offset, const Sizeiptr& size, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glGetNamedBufferSubData>(src_loc, *buffer, *offset, *size, data.get());
}

void GlDirect::GetNamedFramebufferAttachmentParameteriv(const Uint& framebuffer, const Enum& attachment, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetNamedFramebufferAttachmentParameteriv>(src_loc, *framebuffer, *attachment, *pname, params.get());
}

void GlDirect::GetNamedFramebufferParameteriv(const Uint& framebuffer, const Enum& pname, const IntArr& param, const SrcLoc& src_loc){
    return _callGL<&glGetNamedFramebufferParameteriv>(src_loc, *framebuffer, *pname, param.get());
}

void GlDirect::GetNamedRenderbufferParameteriv(const Uint& renderbuffer, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetNamedRenderbufferParameteriv>(src_loc, *renderbuffer, *pname, params.get());
}

void GlDirect::GetObjectLabel(const Enum& identifier, const Uint& name, const Sizei& bufSize, const Sizei& length, const String& label, const SrcLoc& src_loc){
    return _callGL<&glGetObjectLabel>(src_loc, *identifier, *name, *bufSize, length.get(), label->data());
}

void GlDirect::GetObjectPtrLabel(const Data& ptr, const Sizei& bufSize, const Sizei& length, const String& label, const SrcLoc& src_loc){
    return _callGL<&glGetObjectPtrLabel>(src_loc, ptr.get(), *bufSize, length.get(), label->data());
}

void GlDirect::GetPointerv(const Enum& pname, const DataPtr& params, const SrcLoc& src_loc){
    return _callGL<&glGetPointerv>(src_loc, *pname, params.get());
}

void GlDirect::GetProgramBinary(const Uint& program, const Sizei& bufSize, const Sizei& length, const EnumArr& binaryFormat, const Data& binary, const SrcLoc& src_loc){
    return _callGL<&glGetProgramBinary>(src_loc, *program, *bufSize, length.get(), binaryFormat.get(), binary.get());
}

void GlDirect::GetProgramInfoLog(const Uint& program, const Sizei& bufSize, const Sizei& length, const String& infoLog, const SrcLoc& src_loc){
    return _callGL<&glGetProgramInfoLog>(src_loc, *program, *bufSize, length.get(), infoLog->data());
}

void GlDirect::GetProgramInterfaceiv(const Uint& program, const Enum& programInterface, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetProgramInterfaceiv>(src_loc, *program, *programInterface, *pname, params.get());
}

void GlDirect::GetProgramPipelineInfoLog(const Uint& pipeline, const Sizei& bufSize, const Sizei& length, const String& infoLog, const SrcLoc& src_loc){
    return _callGL<&glGetProgramPipelineInfoLog>(src_loc, *pipeline, *bufSize, length.get(), infoLog->data());
}

void GlDirect::GetProgramPipelineiv(const Uint& pipeline, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetProgramPipelineiv>(src_loc, *pipeline, *pname, params.get());
}

GL::Uint GlDirect::GetProgramResourceIndex(const Uint& program, const Enum& programInterface, const String& name, const SrcLoc& src_loc){
    return _callGL<&glGetProgramResourceIndex>(src_loc, *program, *programInterface, name->c_str());
}

GL::Int GlDirect::GetProgramResourceLocation(const Uint& program, const Enum& programInterface, const String& name, const SrcLoc& src_loc){
    return _callGL<&glGetProgramResourceLocation>(src_loc, *program, *programInterface, name->c_str());
}

GL::Int GlDirect::GetProgramResourceLocationIndex(const Uint& program, const Enum& programInterface, const String& name, const SrcLoc& src_loc){
    return _callGL<&glGetProgramResourceLocationIndex>(src_loc, *program, *programInterface, name->c_str());
}

void GlDirect::GetProgramResourceName(const Uint& program, const Enum& programInterface, const Uint& index, const Sizei& bufSize, const Sizei& length, const String& name, const SrcLoc& src_loc){
    return _callGL<&glGetProgramResourceName>(src_loc, *program, *programInterface, *index, *bufSize, length.get(), name->data());
}

void GlDirect::GetProgramResourceiv(const Uint& program, const Enum& programInterface, const Uint& index, const Sizei& propCount, const EnumArr& props, const Sizei& count, const Sizei& length, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetProgramResourceiv>(src_loc, *program, *programInterface, *index, *propCount, props.get(), *count, length.get(), params.get());
}

void GlDirect::GetProgramStageiv(const Uint& program, const Enum& shadertype, const Enum& pname, const IntArr& values, const SrcLoc& src_loc){
    return _callGL<&glGetProgramStageiv>(src_loc, *program, *shadertype, *pname, values.get());
}

void GlDirect::GetProgramiv(const Uint& program, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetProgramiv>(src_loc, *program, *pname, params.get());
}

void GlDirect::GetQueryBufferObjecti64v(const Uint& id, const Uint& buffer, const Enum& pname, const Intptr& offset, const SrcLoc& src_loc){
    return _callGL<&glGetQueryBufferObjecti64v>(src_loc, *id, *buffer, *pname, *offset);
}

void GlDirect::GetQueryBufferObjectiv(const Uint& id, const Uint& buffer, const Enum& pname, const Intptr& offset, const SrcLoc& src_loc){
    return _callGL<&glGetQueryBufferObjectiv>(src_loc, *id, *buffer, *pname, *offset);
}

void GlDirect::GetQueryBufferObjectui64v(const Uint& id, const Uint& buffer, const Enum& pname, const Intptr& offset, const SrcLoc& src_loc){
    return _callGL<&glGetQueryBufferObjectui64v>(src_loc, *id, *buffer, *pname, *offset);
}

void GlDirect::GetQueryBufferObjectuiv(const Uint& id, const Uint& buffer, const Enum& pname, const Intptr& offset, const SrcLoc& src_loc){
    return _callGL<&glGetQueryBufferObjectuiv>(src_loc, *id, *buffer, *pname, *offset);
}

void GlDirect::GetQueryIndexediv(const Enum& target, const Uint& index, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetQueryIndexediv>(src_loc, *target, *index, *pname, params.get());
}

void GlDirect::GetQueryObjecti64v(const Uint& id, const Enum& pname, const Int64Arr& params, const SrcLoc& src_loc){
    return _callGL<&glGetQueryObjecti64v>(src_loc, *id, *pname, params.get());
}

void GlDirect::GetQueryObjectiv(const Uint& id, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetQueryObjectiv>(src_loc, *id, *pname, params.get());
}

void GlDirect::GetQueryObjectui64v(const Uint& id, const Enum& pname, const Uint64Arr& params, const SrcLoc& src_loc){
    return _callGL<&glGetQueryObjectui64v>(src_loc, *id, *pname, params.get());
}

void GlDirect::GetQueryObjectuiv(const Uint& id, const Enum& pname, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetQueryObjectuiv>(src_loc, *id, *pname, params.get());
}

void GlDirect::GetQueryiv(const Enum& target, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetQueryiv>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetRenderbufferParameteriv(const Enum& target, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetRenderbufferParameteriv>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetSamplerParameterIiv(const Uint& sampler, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetSamplerParameterIiv>(src_loc, *sampler, *pname, params.get());
}

void GlDirect::GetSamplerParameterIuiv(const Uint& sampler, const Enum& pname, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetSamplerParameterIuiv>(src_loc, *sampler, *pname, params.get());
}

void GlDirect::GetSamplerParameterfv(const Uint& sampler, const Enum& pname, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetSamplerParameterfv>(src_loc, *sampler, *pname, params.get());
}

void GlDirect::GetSamplerParameteriv(const Uint& sampler, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetSamplerParameteriv>(src_loc, *sampler, *pname, params.get());
}

void GlDirect::GetShaderInfoLog(const Uint& shader, const Sizei& bufSize, const Sizei& length, const String& infoLog, const SrcLoc& src_loc){
    return _callGL<&glGetShaderInfoLog>(src_loc, *shader, *bufSize, length.get(), infoLog->data());
}

void GlDirect::GetShaderPrecisionFormat(const Enum& shadertype, const Enum& precisiontype, const IntArr& range, const IntArr& precision, const SrcLoc& src_loc){
    return _callGL<&glGetShaderPrecisionFormat>(src_loc, *shadertype, *precisiontype, range.get(), precision.get());
}

void GlDirect::GetShaderSource(const Uint& shader, const Sizei& bufSize, const Sizei& length, const String& source, const SrcLoc& src_loc){
    return _callGL<&glGetShaderSource>(src_loc, *shader, *bufSize, length.get(), source->data());
}

void GlDirect::GetShaderiv(const Uint& shader, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetShaderiv>(src_loc, *shader, *pname, params.get());
}

String GlDirect::GetString(const Enum& name, const SrcLoc& src_loc){
    auto gl_res = glGetString(*name);
    auto len = strlen(reinterpret_cast<const char*>(gl_res));
    String dst;
    dst->resize(len);
    memcpy(dst->data(), gl_res, len);
    return dst;
}

String GlDirect::GetStringi(const Enum& name, const Uint& index, const SrcLoc& src_loc){
    auto gl_res = glGetStringi(*name, *index);
    auto len = strlen(reinterpret_cast<const char*>(gl_res));
    String dst;
    dst->resize(len);
    memcpy(dst->data(), gl_res, len);
    return dst;
}

GL::Uint GlDirect::GetSubroutineIndex(const Uint& program, const Enum& shadertype, const String& name, const SrcLoc& src_loc){
    return _callGL<&glGetSubroutineIndex>(src_loc, *program, *shadertype, name->c_str());
}

GL::Int GlDirect::GetSubroutineUniformLocation(const Uint& program, const Enum& shadertype, const String& name, const SrcLoc& src_loc){
    return _callGL<&glGetSubroutineUniformLocation>(src_loc, *program, *shadertype, name->c_str());
}

void GlDirect::GetSynciv(const Sync& sync, const Enum& pname, const Sizei& count, const Sizei& length, const IntArr& values, const SrcLoc& src_loc){
    return _callGL<&glGetSynciv>(src_loc, *sync, *pname, *count, length.get(), values.get());
}

void GlDirect::GetTexImage(const Enum& target, const Int& level, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glGetTexImage>(src_loc, *target, *level, *format, *type, pixels.get());
}

void GlDirect::GetTexLevelParameterfv(const Enum& target, const Int& level, const Enum& pname, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTexLevelParameterfv>(src_loc, *target, *level, *pname, params.get());
}

void GlDirect::GetTexLevelParameteriv(const Enum& target, const Int& level, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTexLevelParameteriv>(src_loc, *target, *level, *pname, params.get());
}

void GlDirect::GetTexParameterIiv(const Enum& target, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTexParameterIiv>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetTexParameterIuiv(const Enum& target, const Enum& pname, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTexParameterIuiv>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetTexParameterfv(const Enum& target, const Enum& pname, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTexParameterfv>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetTexParameteriv(const Enum& target, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTexParameteriv>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetTextureImage(const Uint& texture, const Int& level, const Enum& format, const Enum& type, const Sizei& bufSize, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glGetTextureImage>(src_loc, *texture, *level, *format, *type, *bufSize, pixels.get());
}

void GlDirect::GetTextureLevelParameterfv(const Uint& texture, const Int& level, const Enum& pname, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTextureLevelParameterfv>(src_loc, *texture, *level, *pname, params.get());
}

void GlDirect::GetTextureLevelParameteriv(const Uint& texture, const Int& level, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTextureLevelParameteriv>(src_loc, *texture, *level, *pname, params.get());
}

void GlDirect::GetTextureParameterIiv(const Uint& texture, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTextureParameterIiv>(src_loc, *texture, *pname, params.get());
}

void GlDirect::GetTextureParameterIuiv(const Uint& texture, const Enum& pname, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTextureParameterIuiv>(src_loc, *texture, *pname, params.get());
}

void GlDirect::GetTextureParameterfv(const Uint& texture, const Enum& pname, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTextureParameterfv>(src_loc, *texture, *pname, params.get());
}

void GlDirect::GetTextureParameteriv(const Uint& texture, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTextureParameteriv>(src_loc, *texture, *pname, params.get());
}

void GlDirect::GetTextureSubImage(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& width, const Sizei& height, const Sizei& depth, const Enum& format, const Enum& type, const Sizei& bufSize, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glGetTextureSubImage>(src_loc, *texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *type, *bufSize, pixels.get());
}

void GlDirect::GetTransformFeedbackVarying(const Uint& program, const Uint& index, const Sizei& bufSize, const Sizei& length, const SizeiArr& size, const EnumArr& type, const String& name, const SrcLoc& src_loc){
    return _callGL<&glGetTransformFeedbackVarying>(src_loc, *program, *index, *bufSize, length.get(), size.get(), type.get(), name->data());
}

void GlDirect::GetTransformFeedbacki64_v(const Uint& xfb, const Enum& pname, const Uint& index, const Int64Arr& param, const SrcLoc& src_loc){
    return _callGL<&glGetTransformFeedbacki64_v>(src_loc, *xfb, *pname, *index, param.get());
}

void GlDirect::GetTransformFeedbacki_v(const Uint& xfb, const Enum& pname, const Uint& index, const IntArr& param, const SrcLoc& src_loc){
    return _callGL<&glGetTransformFeedbacki_v>(src_loc, *xfb, *pname, *index, param.get());
}

void GlDirect::GetTransformFeedbackiv(const Uint& xfb, const Enum& pname, const IntArr& param, const SrcLoc& src_loc){
    return _callGL<&glGetTransformFeedbackiv>(src_loc, *xfb, *pname, param.get());
}

GL::Uint GlDirect::GetUniformBlockIndex(const Uint& program, const String& uniformBlockName, const SrcLoc& src_loc){
    return _callGL<&glGetUniformBlockIndex>(src_loc, *program, uniformBlockName->c_str());
}

GL::Int GlDirect::GetUniformLocation(const Uint& program, const String& name, const SrcLoc& src_loc){
    return _callGL<&glGetUniformLocation>(src_loc, *program, name->c_str());
}

void GlDirect::GetUniformSubroutineuiv(const Enum& shadertype, const Int& location, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetUniformSubroutineuiv>(src_loc, *shadertype, *location, params.get());
}

void GlDirect::GetUniformdv(const Uint& program, const Int& location, const DoubleArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetUniformdv>(src_loc, *program, *location, params.get());
}

void GlDirect::GetUniformfv(const Uint& program, const Int& location, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetUniformfv>(src_loc, *program, *location, params.get());
}

void GlDirect::GetUniformiv(const Uint& program, const Int& location, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetUniformiv>(src_loc, *program, *location, params.get());
}

void GlDirect::GetUniformuiv(const Uint& program, const Int& location, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetUniformuiv>(src_loc, *program, *location, params.get());
}

void GlDirect::GetVertexArrayIndexed64iv(const Uint& vaobj, const Uint& index, const Enum& pname, const Int64Arr& param, const SrcLoc& src_loc){
    return _callGL<&glGetVertexArrayIndexed64iv>(src_loc, *vaobj, *index, *pname, param.get());
}

void GlDirect::GetVertexArrayIndexediv(const Uint& vaobj, const Uint& index, const Enum& pname, const IntArr& param, const SrcLoc& src_loc){
    return _callGL<&glGetVertexArrayIndexediv>(src_loc, *vaobj, *index, *pname, param.get());
}

void GlDirect::GetVertexArrayiv(const Uint& vaobj, const Enum& pname, const IntArr& param, const SrcLoc& src_loc){
    return _callGL<&glGetVertexArrayiv>(src_loc, *vaobj, *pname, param.get());
}

void GlDirect::GetVertexAttribIiv(const Uint& index, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetVertexAttribIiv>(src_loc, *index, *pname, params.get());
}

void GlDirect::GetVertexAttribIuiv(const Uint& index, const Enum& pname, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetVertexAttribIuiv>(src_loc, *index, *pname, params.get());
}

void GlDirect::GetVertexAttribLdv(const Uint& index, const Enum& pname, const DoubleArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetVertexAttribLdv>(src_loc, *index, *pname, params.get());
}

void GlDirect::GetVertexAttribPointerv(const Uint& index, const Enum& pname, const DataPtr& pointer, const SrcLoc& src_loc){
    return _callGL<&glGetVertexAttribPointerv>(src_loc, *index, *pname, pointer.get());
}

void GlDirect::GetVertexAttribdv(const Uint& index, const Enum& pname, const DoubleArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetVertexAttribdv>(src_loc, *index, *pname, params.get());
}

void GlDirect::GetVertexAttribfv(const Uint& index, const Enum& pname, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetVertexAttribfv>(src_loc, *index, *pname, params.get());
}

void GlDirect::GetVertexAttribiv(const Uint& index, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetVertexAttribiv>(src_loc, *index, *pname, params.get());
}

void GlDirect::GetnCompressedTexImage(const Enum& target, const Int& lod, const Sizei& bufSize, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glGetnCompressedTexImage>(src_loc, *target, *lod, *bufSize, pixels.get());
}

void GlDirect::GetnTexImage(const Enum& target, const Int& level, const Enum& format, const Enum& type, const Sizei& bufSize, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glGetnTexImage>(src_loc, *target, *level, *format, *type, *bufSize, pixels.get());
}

void GlDirect::GetnUniformdv(const Uint& program, const Int& location, const Sizei& bufSize, const DoubleArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetnUniformdv>(src_loc, *program, *location, *bufSize, params.get());
}

void GlDirect::GetnUniformfv(const Uint& program, const Int& location, const Sizei& bufSize, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetnUniformfv>(src_loc, *program, *location, *bufSize, params.get());
}

void GlDirect::GetnUniformiv(const Uint& program, const Int& location, const Sizei& bufSize, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetnUniformiv>(src_loc, *program, *location, *bufSize, params.get());
}

void GlDirect::GetnUniformuiv(const Uint& program, const Int& location, const Sizei& bufSize, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetnUniformuiv>(src_loc, *program, *location, *bufSize, params.get());
}

void GlDirect::Hint(const Enum& target, const Enum& mode, const SrcLoc& src_loc){
    return _callGL<&glHint>(src_loc, *target, *mode);
}

void GlDirect::InvalidateBufferData(const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&glInvalidateBufferData>(src_loc, *buffer);
}

void GlDirect::InvalidateBufferSubData(const Uint& buffer, const Intptr& offset, const Sizeiptr& length, const SrcLoc& src_loc){
    return _callGL<&glInvalidateBufferSubData>(src_loc, *buffer, *offset, *length);
}

void GlDirect::InvalidateFramebuffer(const Enum& target, const Sizei& numAttachments, const EnumArr& attachments, const SrcLoc& src_loc){
    return _callGL<&glInvalidateFramebuffer>(src_loc, *target, *numAttachments, attachments.get());
}

void GlDirect::InvalidateNamedFramebufferData(const Uint& framebuffer, const Sizei& numAttachments, const EnumArr& attachments, const SrcLoc& src_loc){
    return _callGL<&glInvalidateNamedFramebufferData>(src_loc, *framebuffer, *numAttachments, attachments.get());
}

void GlDirect::InvalidateNamedFramebufferSubData(const Uint& framebuffer, const Sizei& numAttachments, const EnumArr& attachments, const Int& x, const Int& y, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&glInvalidateNamedFramebufferSubData>(src_loc, *framebuffer, *numAttachments, attachments.get(), *x, *y, *width, *height);
}

void GlDirect::InvalidateSubFramebuffer(const Enum& target, const Sizei& numAttachments, const EnumArr& attachments, const Int& x, const Int& y, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&glInvalidateSubFramebuffer>(src_loc, *target, *numAttachments, attachments.get(), *x, *y, *width, *height);
}

void GlDirect::InvalidateTexImage(const Uint& texture, const Int& level, const SrcLoc& src_loc){
    return _callGL<&glInvalidateTexImage>(src_loc, *texture, *level);
}

void GlDirect::InvalidateTexSubImage(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& width, const Sizei& height, const Sizei& depth, const SrcLoc& src_loc){
    return _callGL<&glInvalidateTexSubImage>(src_loc, *texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth);
}

GL::Boolean GlDirect::IsBuffer(const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&glIsBuffer>(src_loc, *buffer);
}

GL::Boolean GlDirect::IsEnabled(const Enum& cap, const SrcLoc& src_loc){
    return _callGL<&glIsEnabled>(src_loc, *cap);
}

GL::Boolean GlDirect::IsEnabledi(const Enum& target, const Uint& index, const SrcLoc& src_loc){
    return _callGL<&glIsEnabledi>(src_loc, *target, *index);
}

GL::Boolean GlDirect::IsFramebuffer(const Uint& framebuffer, const SrcLoc& src_loc){
    return _callGL<&glIsFramebuffer>(src_loc, *framebuffer);
}

GL::Boolean GlDirect::IsProgram(const Uint& program, const SrcLoc& src_loc){
    return _callGL<&glIsProgram>(src_loc, *program);
}

GL::Boolean GlDirect::IsProgramPipeline(const Uint& pipeline, const SrcLoc& src_loc){
    return _callGL<&glIsProgramPipeline>(src_loc, *pipeline);
}

GL::Boolean GlDirect::IsQuery(const Uint& id, const SrcLoc& src_loc){
    return _callGL<&glIsQuery>(src_loc, *id);
}

GL::Boolean GlDirect::IsRenderbuffer(const Uint& renderbuffer, const SrcLoc& src_loc){
    return _callGL<&glIsRenderbuffer>(src_loc, *renderbuffer);
}

GL::Boolean GlDirect::IsSampler(const Uint& sampler, const SrcLoc& src_loc){
    return _callGL<&glIsSampler>(src_loc, *sampler);
}

GL::Boolean GlDirect::IsShader(const Uint& shader, const SrcLoc& src_loc){
    return _callGL<&glIsShader>(src_loc, *shader);
}

GL::Boolean GlDirect::IsSync(const Sync& sync, const SrcLoc& src_loc){
    return _callGL<&glIsSync>(src_loc, *sync);
}

GL::Boolean GlDirect::IsTexture(const Uint& texture, const SrcLoc& src_loc){
    return _callGL<&glIsTexture>(src_loc, *texture);
}

GL::Boolean GlDirect::IsTransformFeedback(const Uint& id, const SrcLoc& src_loc){
    return _callGL<&glIsTransformFeedback>(src_loc, *id);
}

GL::Boolean GlDirect::IsVertexArray(const Uint& array, const SrcLoc& src_loc){
    return _callGL<&glIsVertexArray>(src_loc, *array);
}

void GlDirect::LineWidth(const Float& width, const SrcLoc& src_loc){
    return _callGL<&glLineWidth>(src_loc, *width);
}

void GlDirect::LinkProgram(const Uint& program, const SrcLoc& src_loc){
    return _callGL<&glLinkProgram>(src_loc, *program);
}

void GlDirect::LogicOp(const Enum& opcode, const SrcLoc& src_loc){
    return _callGL<&glLogicOp>(src_loc, *opcode);
}

GL::DataPtr GlDirect::MapBuffer(const Enum& target, const Enum& access, const SrcLoc& src_loc){
    return _callGL<&glMapBuffer>(src_loc, *target, *access);
}

GL::DataPtr GlDirect::MapBufferRange(const Enum& target, const Intptr& offset, const Sizeiptr& length, const Bitfield& access, const SrcLoc& src_loc){
    return _callGL<&glMapBufferRange>(src_loc, *target, *offset, *length, *access);
}

DataPtr GlDirect::MapNamedBuffer(const Uint& buffer, const Enum& access, const SrcLoc& src_loc){
    return _callGL<&glMapNamedBuffer>(src_loc, *buffer, *access);
}

DataPtr GlDirect::MapNamedBufferRange(const Uint& buffer, const Intptr& offset, const Sizeiptr& length, const Bitfield& access, const SrcLoc& src_loc){
    return _callGL<&glMapBufferRange>(src_loc, *buffer, *offset, *length, *access);
}

void GlDirect::MemoryBarrier(const Bitfield& barriers, const SrcLoc& src_loc){
    return _callGL<&glMemoryBarrier>(src_loc, *barriers);
}

void GlDirect::MemoryBarrierByRegion(const Bitfield& barriers, const SrcLoc& src_loc){
    return _callGL<&glMemoryBarrierByRegion>(src_loc, *barriers);
}

void GlDirect::MinSampleShading(const Float& value, const SrcLoc& src_loc){
    return _callGL<&glMinSampleShading>(src_loc, *value);
}

void GlDirect::MultiDrawArrays(const Enum& mode, const IntArr& first, const SizeiArr& count, const Sizei& drawcount, const SrcLoc& src_loc){
    return _callGL<&glMultiDrawArrays>(src_loc, *mode, first.get(), count.get(), *drawcount);
}

void GlDirect::MultiDrawArraysIndirect(const Enum& mode, const Data& indirect, const Sizei& drawcount, const Sizei& stride, const SrcLoc& src_loc){
    return _callGL<&glMultiDrawArraysIndirect>(src_loc, *mode, indirect.get(), *drawcount, *stride);
}

void GlDirect::MultiDrawArraysIndirectCount(const Enum& mode, const Data& indirect, const Intptr& drawcount, const Sizei& maxdrawcount, const Sizei& stride, const SrcLoc& src_loc){
    return _callGL<&glMultiDrawArraysIndirectCount>(src_loc, *mode, indirect.get(), *drawcount, *maxdrawcount, *stride);
}

void GlDirect::MultiDrawElements(const Enum& mode, const SizeiArr& count, const Enum& type, const DataPtr& indices, const Sizei& drawcount, const SrcLoc& src_loc){
    return _callGL<&glMultiDrawElements>(src_loc, *mode, count.get(), *type, indices.get(), *drawcount);
}

void GlDirect::MultiDrawElementsBaseVertex(const Enum& mode, const SizeiArr& count, const Enum& type, const DataPtr& indices, const Sizei& drawcount, const IntArr& basevertex, const SrcLoc& src_loc){
    return _callGL<&glMultiDrawElementsBaseVertex>(src_loc, *mode, count.get(), *type, indices.get(), *drawcount, basevertex.get());
}

void GlDirect::MultiDrawElementsIndirect(const Enum& mode, const Enum& type, const Data& indirect, const Sizei& drawcount, const Sizei& stride, const SrcLoc& src_loc){
    return _callGL<&glMultiDrawElementsIndirect>(src_loc, *mode, *type, indirect.get(), *drawcount, *stride);
}

void GlDirect::MultiDrawElementsIndirectCount(const Enum& mode, const Enum& type, const Data& indirect, const Intptr& drawcount, const Sizei& maxdrawcount, const Sizei& stride, const SrcLoc& src_loc){
    return _callGL<&glMultiDrawElementsIndirectCount>(src_loc, *mode, *type, indirect.get(), *drawcount, *maxdrawcount, *stride);
}

void GlDirect::NamedBufferData(const Uint& buffer, const Sizeiptr& size, const Data& data, const Enum& usage, const SrcLoc& src_loc){
    return _callGL<&glNamedBufferData>(src_loc, *buffer, *size, data.get(), *usage);
}

void GlDirect::NamedBufferStorage(const Uint& buffer, const Sizeiptr& size, const Data& data, const Bitfield& flags, const SrcLoc& src_loc){
    return _callGL<&glNamedBufferStorage>(src_loc, *buffer, *size, data.get(), *flags);
}

void GlDirect::NamedBufferSubData(const Uint& buffer, const Intptr& offset, const Sizeiptr& size, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glNamedBufferSubData>(src_loc, *buffer, *offset, *size, data.get());
}

void GlDirect::NamedFramebufferDrawBuffer(const Uint& framebuffer, const Enum& buf, const SrcLoc& src_loc){
    return _callGL<&glNamedFramebufferDrawBuffer>(src_loc, *framebuffer, *buf);
}

void GlDirect::NamedFramebufferDrawBuffers(const Uint& framebuffer, const Sizei& n, const EnumArr& bufs, const SrcLoc& src_loc){
    return _callGL<&glNamedFramebufferDrawBuffers>(src_loc, *framebuffer, *n, bufs.get());
}

void GlDirect::NamedFramebufferParameteri(const Uint& framebuffer, const Enum& pname, const Int& param, const SrcLoc& src_loc){
    return _callGL<&glNamedFramebufferParameteri>(src_loc, *framebuffer, *pname, *param);
}

void GlDirect::NamedFramebufferReadBuffer(const Uint& framebuffer, const Enum& src, const SrcLoc& src_loc){
    return _callGL<&glNamedFramebufferReadBuffer>(src_loc, *framebuffer, *src);
}

void GlDirect::NamedFramebufferRenderbuffer(const Uint& framebuffer, const Enum& attachment, const Enum& renderbuffertarget, const Uint& renderbuffer, const SrcLoc& src_loc){
    return _callGL<&glNamedFramebufferRenderbuffer>(src_loc, *framebuffer, *attachment, *renderbuffertarget, *renderbuffer);
}

void GlDirect::NamedFramebufferTexture(const Uint& framebuffer, const Enum& attachment, const Uint& texture, const Int& level, const SrcLoc& src_loc){
    return _callGL<&glNamedFramebufferTexture>(src_loc, *framebuffer, *attachment, *texture, *level);
}

void GlDirect::NamedFramebufferTextureLayer(const Uint& framebuffer, const Enum& attachment, const Uint& texture, const Int& level, const Int& layer, const SrcLoc& src_loc){
    return _callGL<&glNamedFramebufferTextureLayer>(src_loc, *framebuffer, *attachment, *texture, *level, *layer);
}

void GlDirect::NamedRenderbufferStorage(const Uint& renderbuffer, const Enum& internalformat, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&glNamedRenderbufferStorage>(src_loc, *renderbuffer, *internalformat, *width, *height);
}

void GlDirect::NamedRenderbufferStorageMultisample(const Uint& renderbuffer, const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&glNamedRenderbufferStorageMultisample>(src_loc, *renderbuffer, *samples, *internalformat, *width, *height);
}

void GlDirect::ObjectLabel(const Enum& identifier, const Uint& name, const Sizei& length, const String& label, const SrcLoc& src_loc){
    return _callGL<&glObjectLabel>(src_loc, *identifier, *name, *length, label->c_str());
}

void GlDirect::ObjectPtrLabel(const Data& ptr, const Sizei& length, const String& label, const SrcLoc& src_loc){
    return _callGL<&glObjectPtrLabel>(src_loc, ptr.get(), *length, label->c_str());
}

void GlDirect::PatchParameterfv(const Enum& pname, const FloatArr& values, const SrcLoc& src_loc){
    return _callGL<&glPatchParameterfv>(src_loc, *pname, values.get());
}

void GlDirect::PatchParameteri(const Enum& pname, const Int& value, const SrcLoc& src_loc){
    return _callGL<&glPatchParameteri>(src_loc, *pname, *value);
}

void GlDirect::PauseTransformFeedback(const SrcLoc& src_loc){
    return _callGL<&glPauseTransformFeedback>(src_loc);
}

void GlDirect::PixelStoref(const Enum& pname, const Float& param, const SrcLoc& src_loc){
    return _callGL<&glPixelStoref>(src_loc, *pname, *param);
}

void GlDirect::PixelStorei(const Enum& pname, const Int& param, const SrcLoc& src_loc){
    return _callGL<&glPixelStorei>(src_loc, *pname, *param);
}

void GlDirect::PointParameterf(const Enum& pname, const Float& param, const SrcLoc& src_loc){
    return _callGL<&glPointParameterf>(src_loc, *pname, *param);
}

void GlDirect::PointParameterfv(const Enum& pname, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glPointParameterfv>(src_loc, *pname, params.get());
}

void GlDirect::PointParameteri(const Enum& pname, const Int& param, const SrcLoc& src_loc){
    return _callGL<&glPointParameteri>(src_loc, *pname, *param);
}

void GlDirect::PointParameteriv(const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glPointParameteriv>(src_loc, *pname, params.get());
}

void GlDirect::PointSize(const Float& size, const SrcLoc& src_loc){
    return _callGL<&glPointSize>(src_loc, *size);
}

void GlDirect::PolygonMode(const Enum& face, const Enum& mode, const SrcLoc& src_loc){
    return _callGL<&glPolygonMode>(src_loc, *face, *mode);
}

void GlDirect::PolygonOffset(const Float& factor, const Float& units, const SrcLoc& src_loc){
    return _callGL<&glPolygonOffset>(src_loc, *factor, *units);
}

void GlDirect::PolygonOffsetClamp(const Float& factor, const Float& units, const Float& clamp, const SrcLoc& src_loc){
    return _callGL<&glPolygonOffsetClamp>(src_loc, *factor, *units, *clamp);
}

void GlDirect::PopDebugGroup(const SrcLoc& src_loc){
    return _callGL<&glPopDebugGroup>(src_loc);
}

void GlDirect::PrimitiveRestartIndex(const Uint& index, const SrcLoc& src_loc){
    return _callGL<&glPrimitiveRestartIndex>(src_loc, *index);
}

void GlDirect::ProgramBinary(const Uint& program, const Enum& binaryFormat, const Data& binary, const Sizei& length, const SrcLoc& src_loc){
    return _callGL<&glProgramBinary>(src_loc, *program, *binaryFormat, binary.get(), *length);
}

void GlDirect::ProgramParameteri(const Uint& program, const Enum& pname, const Int& value, const SrcLoc& src_loc){
    return _callGL<&glProgramParameteri>(src_loc, *program, *pname, *value);
}

void GlDirect::ProgramUniform1d(const Uint& program, const Int& location, const Double& v0, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform1d>(src_loc, *program, *location, *v0);
}

void GlDirect::ProgramUniform1dv(const Uint& program, const Int& location, const Sizei& count, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform1dv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform1f(const Uint& program, const Int& location, const Float& v0, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform1f>(src_loc, *program, *location, *v0);
}

void GlDirect::ProgramUniform1fv(const Uint& program, const Int& location, const Sizei& count, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform1fv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform1i(const Uint& program, const Int& location, const Int& v0, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform1i>(src_loc, *program, *location, *v0);
}

void GlDirect::ProgramUniform1iv(const Uint& program, const Int& location, const Sizei& count, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform1iv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform1ui(const Uint& program, const Int& location, const Uint& v0, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform1ui>(src_loc, *program, *location, *v0);
}

void GlDirect::ProgramUniform1uiv(const Uint& program, const Int& location, const Sizei& count, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform1uiv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform2d(const Uint& program, const Int& location, const Double& v0, const Double& v1, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform2d>(src_loc, *program, *location, *v0, *v1);
}

void GlDirect::ProgramUniform2dv(const Uint& program, const Int& location, const Sizei& count, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform2dv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform2f(const Uint& program, const Int& location, const Float& v0, const Float& v1, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform2f>(src_loc, *program, *location, *v0, *v1);
}

void GlDirect::ProgramUniform2fv(const Uint& program, const Int& location, const Sizei& count, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform2fv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform2i(const Uint& program, const Int& location, const Int& v0, const Int& v1, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform2i>(src_loc, *program, *location, *v0, *v1);
}

void GlDirect::ProgramUniform2iv(const Uint& program, const Int& location, const Sizei& count, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform2iv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform2ui(const Uint& program, const Int& location, const Uint& v0, const Uint& v1, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform2ui>(src_loc, *program, *location, *v0, *v1);
}

void GlDirect::ProgramUniform2uiv(const Uint& program, const Int& location, const Sizei& count, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform2uiv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform3d(const Uint& program, const Int& location, const Double& v0, const Double& v1, const Double& v2, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform3d>(src_loc, *program, *location, *v0, *v1, *v2);
}

void GlDirect::ProgramUniform3dv(const Uint& program, const Int& location, const Sizei& count, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform3dv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform3f(const Uint& program, const Int& location, const Float& v0, const Float& v1, const Float& v2, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform3f>(src_loc, *program, *location, *v0, *v1, *v2);
}

void GlDirect::ProgramUniform3fv(const Uint& program, const Int& location, const Sizei& count, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform3fv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform3i(const Uint& program, const Int& location, const Int& v0, const Int& v1, const Int& v2, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform3i>(src_loc, *program, *location, *v0, *v1, *v2);
}

void GlDirect::ProgramUniform3iv(const Uint& program, const Int& location, const Sizei& count, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform3iv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform3ui(const Uint& program, const Int& location, const Uint& v0, const Uint& v1, const Uint& v2, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform3ui>(src_loc, *program, *location, *v0, *v1, *v2);
}

void GlDirect::ProgramUniform3uiv(const Uint& program, const Int& location, const Sizei& count, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform3uiv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform4d(const Uint& program, const Int& location, const Double& v0, const Double& v1, const Double& v2, const Double& v3, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform4d>(src_loc, *program, *location, *v0, *v1, *v2, *v3);
}

void GlDirect::ProgramUniform4dv(const Uint& program, const Int& location, const Sizei& count, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform4dv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform4f(const Uint& program, const Int& location, const Float& v0, const Float& v1, const Float& v2, const Float& v3, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform4f>(src_loc, *program, *location, *v0, *v1, *v2, *v3);
}

void GlDirect::ProgramUniform4fv(const Uint& program, const Int& location, const Sizei& count, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform4fv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform4i(const Uint& program, const Int& location, const Int& v0, const Int& v1, const Int& v2, const Int& v3, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform4i>(src_loc, *program, *location, *v0, *v1, *v2, *v3);
}

void GlDirect::ProgramUniform4iv(const Uint& program, const Int& location, const Sizei& count, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform4iv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform4ui(const Uint& program, const Int& location, const Uint& v0, const Uint& v1, const Uint& v2, const Uint& v3, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform4ui>(src_loc, *program, *location, *v0, *v1, *v2, *v3);
}

void GlDirect::ProgramUniform4uiv(const Uint& program, const Int& location, const Sizei& count, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform4uiv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniformMatrix2dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix2dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix2fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix2fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix2x3dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix2x3dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix2x3fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix2x3fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix2x4dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix2x4dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix2x4fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix2x4fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix3dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix3dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix3fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix3fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix3x2dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix3x2dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix3x2fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix3x2fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix3x4dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix3x4dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix3x4fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix3x4fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix4dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix4dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix4fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix4fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix4x2dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix4x2dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix4x2fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix4x2fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix4x3dv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix4x3dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix4x3fv(const Uint& program, const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix4x3fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProvokingVertex(const Enum& mode, const SrcLoc& src_loc){
    return _callGL<&glProvokingVertex>(src_loc, *mode);
}

void GlDirect::PushDebugGroup(const Enum& source, const Uint& id, const Sizei& length, const String& message, const SrcLoc& src_loc){
    return _callGL<&glPushDebugGroup>(src_loc, *source, *id, *length, message->c_str());
}

void GlDirect::QueryCounter(const Uint& id, const Enum& target, const SrcLoc& src_loc){
    return _callGL<&glQueryCounter>(src_loc, *id, *target);
}

void GlDirect::ReadBuffer(const Enum& src, const SrcLoc& src_loc){
    return _callGL<&glReadBuffer>(src_loc, *src);
}

void GlDirect::ReadPixels(const Int& x, const Int& y, const Sizei& width, const Sizei& height, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glReadPixels>(src_loc, *x, *y, *width, *height, *format, *type, pixels.get());
}

void GlDirect::ReadnPixels(const Int& x, const Int& y, const Sizei& width, const Sizei& height, const Enum& format, const Enum& type, const Sizei& bufSize, const Data& data, const SrcLoc& src_loc){
    return _callGL<&glReadnPixels>(src_loc, *x, *y, *width, *height, *format, *type, *bufSize, data.get());
}

void GlDirect::ReleaseShaderCompiler(const SrcLoc& src_loc){
    return _callGL<&glReleaseShaderCompiler>(src_loc);
}

void GlDirect::RenderbufferStorage(const Enum& target, const Enum& internalformat, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&glRenderbufferStorage>(src_loc, *target, *internalformat, *width, *height);
}

void GlDirect::RenderbufferStorageMultisample(const Enum& target, const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&glRenderbufferStorageMultisample>(src_loc, *target, *samples, *internalformat, *width, *height);
}

void GlDirect::ResumeTransformFeedback(const SrcLoc& src_loc){
    return _callGL<&glResumeTransformFeedback>(src_loc);
}

void GlDirect::SampleCoverage(const Float& value, const Boolean& invert, const SrcLoc& src_loc){
    return _callGL<&glSampleCoverage>(src_loc, *value, *invert);
}

void GlDirect::SampleMaski(const Uint& maskNumber, const Bitfield& mask, const SrcLoc& src_loc){
    return _callGL<&glSampleMaski>(src_loc, *maskNumber, *mask);
}

void GlDirect::SamplerParameterIiv(const Uint& sampler, const Enum& pname, const IntArr& param, const SrcLoc& src_loc){
    return _callGL<&glSamplerParameterIiv>(src_loc, *sampler, *pname, param.get());
}

void GlDirect::SamplerParameterIuiv(const Uint& sampler, const Enum& pname, const UintArr& param, const SrcLoc& src_loc){
    return _callGL<&glSamplerParameterIuiv>(src_loc, *sampler, *pname, param.get());
}

void GlDirect::SamplerParameterf(const Uint& sampler, const Enum& pname, const Float& param, const SrcLoc& src_loc){
    return _callGL<&glSamplerParameterf>(src_loc, *sampler, *pname, *param);
}

void GlDirect::SamplerParameterfv(const Uint& sampler, const Enum& pname, const FloatArr& param, const SrcLoc& src_loc){
    return _callGL<&glSamplerParameterfv>(src_loc, *sampler, *pname, param.get());
}

void GlDirect::SamplerParameteri(const Uint& sampler, const Enum& pname, const Int& param, const SrcLoc& src_loc){
    return _callGL<&glSamplerParameteri>(src_loc, *sampler, *pname, *param);
}

void GlDirect::SamplerParameteriv(const Uint& sampler, const Enum& pname, const IntArr& param, const SrcLoc& src_loc){
    return _callGL<&glSamplerParameteriv>(src_loc, *sampler, *pname, param.get());
}

void GlDirect::Scissor(const Int& x, const Int& y, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&glScissor>(src_loc, *x, *y, *width, *height);
}

void GlDirect::ScissorArrayv(const Uint& first, const Sizei& count, const IntArr& v, const SrcLoc& src_loc){
    return _callGL<&glScissorArrayv>(src_loc, *first, *count, v.get());
}

void GlDirect::ScissorIndexed(const Uint& index, const Int& left, const Int& bottom, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&glScissorIndexed>(src_loc, *index, *left, *bottom, *width, *height);
}

void GlDirect::ScissorIndexedv(const Uint& index, const IntArr& v, const SrcLoc& src_loc){
    return _callGL<&glScissorIndexedv>(src_loc, *index, v.get());
}

void GlDirect::ShaderBinary(const Sizei& count, const UintArr& shaders, const Enum& binaryFormat, const Data& binary, const Sizei& length, const SrcLoc& src_loc){
    return _callGL<&glShaderBinary>(src_loc, *count, shaders.get(), *binaryFormat, binary.get(), *length);
}

void GlDirect::ShaderSource(const Uint& shader, const Sizei& count, const StringArr& strings, const IntArr& lengths, const SrcLoc& src_loc){
    const char** ptrs = new const char*[*count];
    for (size_t i = 0; i < *count; ++i){
        ptrs[i] = (strings.get())[i].c_str();
    }
    _callGL<&glShaderSource>(src_loc, *shader, *count, ptrs, lengths.get());
    delete[] ptrs;
}

void GlDirect::ShaderStorageBlockBinding(const Uint& program, const Uint& storageBlockIndex, const Uint& storageBlockBinding, const SrcLoc& src_loc){
    return _callGL<&glShaderStorageBlockBinding>(src_loc, *program, *storageBlockIndex, *storageBlockBinding);
}

void GlDirect::SpecializeShader(const Uint& shader, const String& pEntryPoint, const Uint& numSpecializationConstants, const UintArr& pConstantIndex, const UintArr& pConstantValue, const SrcLoc& src_loc){
    return _callGL<&glSpecializeShader>(src_loc, *shader, pEntryPoint->c_str(), *numSpecializationConstants, pConstantIndex.get(), pConstantValue.get());
}

void GlDirect::StencilFunc(const Enum& func, const Int& ref, const Uint& mask, const SrcLoc& src_loc){
    return _callGL<&glStencilFunc>(src_loc, *func, *ref, *mask);
}

void GlDirect::StencilFuncSeparate(const Enum& face, const Enum& func, const Int& ref, const Uint& mask, const SrcLoc& src_loc){
    return _callGL<&glStencilFuncSeparate>(src_loc, *face, *func, *ref, *mask);
}

void GlDirect::StencilMask(const Uint& mask, const SrcLoc& src_loc){
    return _callGL<&glStencilMask>(src_loc, *mask);
}

void GlDirect::StencilMaskSeparate(const Enum& face, const Uint& mask, const SrcLoc& src_loc){
    return _callGL<&glStencilMaskSeparate>(src_loc, *face, *mask);
}

void GlDirect::StencilOp(const Enum& fail, const Enum& zfail, const Enum& zpass, const SrcLoc& src_loc){
    return _callGL<&glStencilOp>(src_loc, *fail, *zfail, *zpass);
}

void GlDirect::StencilOpSeparate(const Enum& face, const Enum& sfail, const Enum& dpfail, const Enum& dppass, const SrcLoc& src_loc){
    return _callGL<&glStencilOpSeparate>(src_loc, *face, *sfail, *dpfail, *dppass);
}

void GlDirect::TexBuffer(const Enum& target, const Enum& internalformat, const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&glTexBuffer>(src_loc, *target, *internalformat, *buffer);
}

void GlDirect::TexBufferRange(const Enum& target, const Enum& internalformat, const Uint& buffer, const Intptr& offset, const Sizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&glTexBufferRange>(src_loc, *target, *internalformat, *buffer, *offset, *size);
}

void GlDirect::TexImage1D(const Enum& target, const Int& level, const Int& internalformat, const Sizei& width, const Int& border, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glTexImage1D>(src_loc, *target, *level, *internalformat, *width, *border, *format, *type, pixels.get());
}

void GlDirect::TexImage2D(const Enum& target, const Int& level, const Int& internalformat, const Sizei& width, const Sizei& height, const Int& border, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glTexImage2D>(src_loc, *target, *level, *internalformat, *width, *height, *border, *format, *type, pixels.get());
}

void GlDirect::TexImage2DMultisample(const Enum& target, const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const Boolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&glTexImage2DMultisample>(src_loc, *target, *samples, *internalformat, *width, *height, *fixedsamplelocations);
}

void GlDirect::TexImage3D(const Enum& target, const Int& level, const Int& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const Int& border, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glTexImage3D>(src_loc, *target, *level, *internalformat, *width, *height, *depth, *border, *format, *type, pixels.get());
}

void GlDirect::TexImage3DMultisample(const Enum& target, const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const Boolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&glTexImage3DMultisample>(src_loc, *target, *samples, *internalformat, *width, *height, *depth, *fixedsamplelocations);
}

void GlDirect::TexParameterIiv(const Enum& target, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glTexParameterIiv>(src_loc, *target, *pname, params.get());
}

void GlDirect::TexParameterIuiv(const Enum& target, const Enum& pname, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&glTexParameterIuiv>(src_loc, *target, *pname, params.get());
}

void GlDirect::TexParameterf(const Enum& target, const Enum& pname, const Float& param, const SrcLoc& src_loc){
    return _callGL<&glTexParameterf>(src_loc, *target, *pname, *param);
}

void GlDirect::TexParameterfv(const Enum& target, const Enum& pname, const FloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glTexParameterfv>(src_loc, *target, *pname, params.get());
}

void GlDirect::TexParameteri(const Enum& target, const Enum& pname, const Int& param, const SrcLoc& src_loc){
    return _callGL<&glTexParameteri>(src_loc, *target, *pname, *param);
}

void GlDirect::TexParameteriv(const Enum& target, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glTexParameteriv>(src_loc, *target, *pname, params.get());
}

void GlDirect::TexStorage1D(const Enum& target, const Sizei& levels, const Enum& internalformat, const Sizei& width, const SrcLoc& src_loc){
    return _callGL<&glTexStorage1D>(src_loc, *target, *levels, *internalformat, *width);
}

void GlDirect::TexStorage2D(const Enum& target, const Sizei& levels, const Enum& internalformat, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&glTexStorage2D>(src_loc, *target, *levels, *internalformat, *width, *height);
}

void GlDirect::TexStorage2DMultisample(const Enum& target, const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const Boolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&glTexStorage2DMultisample>(src_loc, *target, *samples, *internalformat, *width, *height, *fixedsamplelocations);
}

void GlDirect::TexStorage3D(const Enum& target, const Sizei& levels, const Enum& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const SrcLoc& src_loc){
    return _callGL<&glTexStorage3D>(src_loc, *target, *levels, *internalformat, *width, *height, *depth);
}

void GlDirect::TexStorage3DMultisample(const Enum& target, const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const Boolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&glTexStorage3DMultisample>(src_loc, *target, *samples, *internalformat, *width, *height, *depth, *fixedsamplelocations);
}

void GlDirect::TexSubImage1D(const Enum& target, const Int& level, const Int& xoffset, const Sizei& width, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glTexSubImage1D>(src_loc, *target, *level, *xoffset, *width, *format, *type, pixels.get());
}

void GlDirect::TexSubImage2D(const Enum& target, const Int& level, const Int& xoffset, const Int& yoffset, const Sizei& width, const Sizei& height, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glTexSubImage2D>(src_loc, *target, *level, *xoffset, *yoffset, *width, *height, *format, *type, pixels.get());
}

void GlDirect::TexSubImage3D(const Enum& target, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& width, const Sizei& height, const Sizei& depth, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glTexSubImage3D>(src_loc, *target, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *type, pixels.get());
}

void GlDirect::TextureBarrier(const SrcLoc& src_loc){
    return _callGL<&glTextureBarrier>(src_loc);
}

void GlDirect::TextureBuffer(const Uint& texture, const Enum& internalformat, const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&glTextureBuffer>(src_loc, *texture, *internalformat, *buffer);
}

void GlDirect::TextureBufferRange(const Uint& texture, const Enum& internalformat, const Uint& buffer, const Intptr& offset, const Sizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&glTextureBufferRange>(src_loc, *texture, *internalformat, *buffer, *offset, *size);
}

void GlDirect::TextureParameterIiv(const Uint& texture, const Enum& pname, const IntArr& params, const SrcLoc& src_loc){
    return _callGL<&glTextureParameterIiv>(src_loc, *texture, *pname, params.get());
}

void GlDirect::TextureParameterIuiv(const Uint& texture, const Enum& pname, const UintArr& params, const SrcLoc& src_loc){
    return _callGL<&glTextureParameterIuiv>(src_loc, *texture, *pname, params.get());
}

void GlDirect::TextureParameterf(const Uint& texture, const Enum& pname, const Float& param, const SrcLoc& src_loc){
    return _callGL<&glTextureParameterf>(src_loc, *texture, *pname, *param);
}

void GlDirect::TextureParameterfv(const Uint& texture, const Enum& pname, const FloatArr& param, const SrcLoc& src_loc){
    return _callGL<&glTextureParameterfv>(src_loc, *texture, *pname, param.get());
}

void GlDirect::TextureParameteri(const Uint& texture, const Enum& pname, const Int& param, const SrcLoc& src_loc){
    return _callGL<&glTextureParameteri>(src_loc, *texture, *pname, *param);
}

void GlDirect::TextureParameteriv(const Uint& texture, const Enum& pname, const IntArr& param, const SrcLoc& src_loc){
    return _callGL<&glTextureParameteriv>(src_loc, *texture, *pname, param.get());
}

void GlDirect::TextureStorage1D(const Uint& texture, const Sizei& levels, const Enum& internalformat, const Sizei& width, const SrcLoc& src_loc){
    return _callGL<&glTextureStorage1D>(src_loc, *texture, *levels, *internalformat, *width);
}

void GlDirect::TextureStorage2D(const Uint& texture, const Sizei& levels, const Enum& internalformat, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&glTextureStorage2D>(src_loc, *texture, *levels, *internalformat, *width, *height);
}

void GlDirect::TextureStorage2DMultisample(const Uint& texture, const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const Boolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&glTextureStorage2DMultisample>(src_loc, *texture, *samples, *internalformat, *width, *height, *fixedsamplelocations);
}

void GlDirect::TextureStorage3D(const Uint& texture, const Sizei& levels, const Enum& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const SrcLoc& src_loc){
    return _callGL<&glTextureStorage3D>(src_loc, *texture, *levels, *internalformat, *width, *height, *depth);
}

void GlDirect::TextureStorage3DMultisample(const Uint& texture, const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const Boolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&glTextureStorage3DMultisample>(src_loc, *texture, *samples, *internalformat, *width, *height, *depth, *fixedsamplelocations);
}

void GlDirect::TextureSubImage1D(const Uint& texture, const Int& level, const Int& xoffset, const Sizei& width, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glTextureSubImage1D>(src_loc, *texture, *level, *xoffset, *width, *format, *type, pixels.get());
}

void GlDirect::TextureSubImage2D(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Sizei& width, const Sizei& height, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glTextureSubImage2D>(src_loc, *texture, *level, *xoffset, *yoffset, *width, *height, *format, *type, pixels.get());
}

void GlDirect::TextureSubImage3D(const Uint& texture, const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& width, const Sizei& height, const Sizei& depth, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
    return _callGL<&glTextureSubImage3D>(src_loc, *texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *type, pixels.get());
}

void GlDirect::TextureView(const Uint& texture, const Enum& target, const Uint& origtexture, const Enum& internalformat, const Uint& minlevel, const Uint& numlevels, const Uint& minlayer, const Uint& numlayers, const SrcLoc& src_loc){
    return _callGL<&glTextureView>(src_loc, *texture, *target, *origtexture, *internalformat, *minlevel, *numlevels, *minlayer, *numlayers);
}

void GlDirect::TransformFeedbackBufferBase(const Uint& xfb, const Uint& index, const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&glTransformFeedbackBufferBase>(src_loc, *xfb, *index, *buffer);
}

void GlDirect::TransformFeedbackBufferRange(const Uint& xfb, const Uint& index, const Uint& buffer, const Intptr& offset, const Sizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&glTransformFeedbackBufferRange>(src_loc, *xfb, *index, *buffer, *offset, *size);
}

void GlDirect::Uniform1d(const Int& location, const Double& x, const SrcLoc& src_loc){
    return _callGL<&glUniform1d>(src_loc, *location, *x);
}

void GlDirect::Uniform1dv(const Int& location, const Sizei& count, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform1dv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform1f(const Int& location, const Float& v0, const SrcLoc& src_loc){
    return _callGL<&glUniform1f>(src_loc, *location, *v0);
}

void GlDirect::Uniform1fv(const Int& location, const Sizei& count, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform1fv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform1i(const Int& location, const Int& v0, const SrcLoc& src_loc){
    return _callGL<&glUniform1i>(src_loc, *location, *v0);
}

void GlDirect::Uniform1iv(const Int& location, const Sizei& count, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform1iv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform1ui(const Int& location, const Uint& v0, const SrcLoc& src_loc){
    return _callGL<&glUniform1ui>(src_loc, *location, *v0);
}

void GlDirect::Uniform1uiv(const Int& location, const Sizei& count, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform1uiv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform2d(const Int& location, const Double& x, const Double& y, const SrcLoc& src_loc){
    return _callGL<&glUniform2d>(src_loc, *location, *x, *y);
}

void GlDirect::Uniform2dv(const Int& location, const Sizei& count, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform2dv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform2f(const Int& location, const Float& v0, const Float& v1, const SrcLoc& src_loc){
    return _callGL<&glUniform2f>(src_loc, *location, *v0, *v1);
}

void GlDirect::Uniform2fv(const Int& location, const Sizei& count, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform2fv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform2i(const Int& location, const Int& v0, const Int& v1, const SrcLoc& src_loc){
    return _callGL<&glUniform2i>(src_loc, *location, *v0, *v1);
}

void GlDirect::Uniform2iv(const Int& location, const Sizei& count, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform2iv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform2ui(const Int& location, const Uint& v0, const Uint& v1, const SrcLoc& src_loc){
    return _callGL<&glUniform2ui>(src_loc, *location, *v0, *v1);
}

void GlDirect::Uniform2uiv(const Int& location, const Sizei& count, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform2uiv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform3d(const Int& location, const Double& x, const Double& y, const Double& z, const SrcLoc& src_loc){
    return _callGL<&glUniform3d>(src_loc, *location, *x, *y, *z);
}

void GlDirect::Uniform3dv(const Int& location, const Sizei& count, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform3dv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform3f(const Int& location, const Float& v0, const Float& v1, const Float& v2, const SrcLoc& src_loc){
    return _callGL<&glUniform3f>(src_loc, *location, *v0, *v1, *v2);
}

void GlDirect::Uniform3fv(const Int& location, const Sizei& count, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform3fv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform3i(const Int& location, const Int& v0, const Int& v1, const Int& v2, const SrcLoc& src_loc){
    return _callGL<&glUniform3i>(src_loc, *location, *v0, *v1, *v2);
}

void GlDirect::Uniform3iv(const Int& location, const Sizei& count, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform3iv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform3ui(const Int& location, const Uint& v0, const Uint& v1, const Uint& v2, const SrcLoc& src_loc){
    return _callGL<&glUniform3ui>(src_loc, *location, *v0, *v1, *v2);
}

void GlDirect::Uniform3uiv(const Int& location, const Sizei& count, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform3uiv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform4d(const Int& location, const Double& x, const Double& y, const Double& z, const Double& w, const SrcLoc& src_loc){
    return _callGL<&glUniform4d>(src_loc, *location, *x, *y, *z, *w);
}

void GlDirect::Uniform4dv(const Int& location, const Sizei& count, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform4dv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform4f(const Int& location, const Float& v0, const Float& v1, const Float& v2, const Float& v3, const SrcLoc& src_loc){
    return _callGL<&glUniform4f>(src_loc, *location, *v0, *v1, *v2, *v3);
}

void GlDirect::Uniform4fv(const Int& location, const Sizei& count, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform4fv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform4i(const Int& location, const Int& v0, const Int& v1, const Int& v2, const Int& v3, const SrcLoc& src_loc){
    return _callGL<&glUniform4i>(src_loc, *location, *v0, *v1, *v2, *v3);
}

void GlDirect::Uniform4iv(const Int& location, const Sizei& count, const IntArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform4iv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform4ui(const Int& location, const Uint& v0, const Uint& v1, const Uint& v2, const Uint& v3, const SrcLoc& src_loc){
    return _callGL<&glUniform4ui>(src_loc, *location, *v0, *v1, *v2, *v3);
}

void GlDirect::Uniform4uiv(const Int& location, const Sizei& count, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform4uiv>(src_loc, *location, *count, value.get());
}

void GlDirect::UniformBlockBinding(const Uint& program, const Uint& uniformBlockIndex, const Uint& uniformBlockBinding, const SrcLoc& src_loc){
    return _callGL<&glUniformBlockBinding>(src_loc, *program, *uniformBlockIndex, *uniformBlockBinding);
}

void GlDirect::UniformMatrix2dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix2dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix2fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix2fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix2x3dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix2x3dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix2x3fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix2x3fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix2x4dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix2x4dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix2x4fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix2x4fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix3dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix3dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix3fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix3fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix3x2dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix3x2dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix3x2fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix3x2fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix3x4dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix3x4dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix3x4fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix3x4fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix4dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix4dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix4fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix4fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix4x2dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix4x2dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix4x2fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix4x2fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix4x3dv(const Int& location, const Sizei& count, const Boolean& transpose, const DoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix4x3dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix4x3fv(const Int& location, const Sizei& count, const Boolean& transpose, const FloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix4x3fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformSubroutinesuiv(const Enum& shadertype, const Sizei& count, const UintArr& indices, const SrcLoc& src_loc){
    return _callGL<&glUniformSubroutinesuiv>(src_loc, *shadertype, *count, indices.get());
}

GL::Boolean GlDirect::UnmapBuffer(const Enum& target, const SrcLoc& src_loc){
    return _callGL<&glUnmapBuffer>(src_loc, *target);
}

GL::Boolean GlDirect::UnmapNamedBuffer(const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&glUnmapNamedBuffer>(src_loc, *buffer);
}

void GlDirect::UseProgram(const Uint& program, const SrcLoc& src_loc){
    return _callGL<&glUseProgram>(src_loc, *program);
}

void GlDirect::UseProgramStages(const Uint& pipeline, const Bitfield& stages, const Uint& program, const SrcLoc& src_loc){
    return _callGL<&glUseProgramStages>(src_loc, *pipeline, *stages, *program);
}

void GlDirect::ValidateProgram(const Uint& program, const SrcLoc& src_loc){
    return _callGL<&glValidateProgram>(src_loc, *program);
}

void GlDirect::ValidateProgramPipeline(const Uint& pipeline, const SrcLoc& src_loc){
    return _callGL<&glValidateProgramPipeline>(src_loc, *pipeline);
}

void GlDirect::VertexArrayAttribBinding(const Uint& vaobj, const Uint& attribindex, const Uint& bindingindex, const SrcLoc& src_loc){
    return _callGL<&glVertexArrayAttribBinding>(src_loc, *vaobj, *attribindex, *bindingindex);
}

void GlDirect::VertexArrayAttribFormat(const Uint& vaobj, const Uint& attribindex, const Int& size, const Enum& type, const Boolean& normalized, const Uint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&glVertexArrayAttribFormat>(src_loc, *vaobj, *attribindex, *size, *type, *normalized, *relativeoffset);
}

void GlDirect::VertexArrayAttribIFormat(const Uint& vaobj, const Uint& attribindex, const Int& size, const Enum& type, const Uint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&glVertexArrayAttribIFormat>(src_loc, *vaobj, *attribindex, *size, *type, *relativeoffset);
}

void GlDirect::VertexArrayAttribLFormat(const Uint& vaobj, const Uint& attribindex, const Int& size, const Enum& type, const Uint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&glVertexArrayAttribLFormat>(src_loc, *vaobj, *attribindex, *size, *type, *relativeoffset);
}

void GlDirect::VertexArrayBindingDivisor(const Uint& vaobj, const Uint& bindingindex, const Uint& divisor, const SrcLoc& src_loc){
    return _callGL<&glVertexArrayBindingDivisor>(src_loc, *vaobj, *bindingindex, *divisor);
}

void GlDirect::VertexArrayElementBuffer(const Uint& vaobj, const Uint& buffer, const SrcLoc& src_loc){
    return _callGL<&glVertexArrayElementBuffer>(src_loc, *vaobj, *buffer);
}

void GlDirect::VertexArrayVertexBuffer(const Uint& vaobj, const Uint& bindingindex, const Uint& buffer, const Intptr& offset, const Sizei& stride, const SrcLoc& src_loc){
    return _callGL<&glVertexArrayVertexBuffer>(src_loc, *vaobj, *bindingindex, *buffer, *offset, *stride);
}

void GlDirect::VertexArrayVertexBuffers(const Uint& vaobj, const Uint& first, const Sizei& count, const UintArr& buffers, const IntptrArr& offsets, const SizeiArr& strides, const SrcLoc& src_loc){
    return _callGL<&glVertexArrayVertexBuffers>(src_loc, *vaobj, *first, *count, buffers.get(), offsets.get(), strides.get());
}

void GlDirect::VertexAttrib1d(const Uint& index, const Double& x, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib1d>(src_loc, *index, *x);
}

void GlDirect::VertexAttrib1dv(const Uint& index, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib1dv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib1f(const Uint& index, const Float& x, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib1f>(src_loc, *index, *x);
}

void GlDirect::VertexAttrib1fv(const Uint& index, const FloatArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib1fv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib1s(const Uint& index, const Short& x, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib1s>(src_loc, *index, *x);
}

void GlDirect::VertexAttrib1sv(const Uint& index, const Short& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib1sv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib2d(const Uint& index, const Double& x, const Double& y, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib2d>(src_loc, *index, *x, *y);
}

void GlDirect::VertexAttrib2dv(const Uint& index, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib2dv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib2f(const Uint& index, const Float& x, const Float& y, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib2f>(src_loc, *index, *x, *y);
}

void GlDirect::VertexAttrib2fv(const Uint& index, const FloatArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib2fv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib2s(const Uint& index, const Short& x, const Short& y, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib2s>(src_loc, *index, *x, *y);
}

void GlDirect::VertexAttrib2sv(const Uint& index, const Short& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib2sv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib3d(const Uint& index, const Double& x, const Double& y, const Double& z, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib3d>(src_loc, *index, *x, *y, *z);
}

void GlDirect::VertexAttrib3dv(const Uint& index, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib3dv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib3f(const Uint& index, const Float& x, const Float& y, const Float& z, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib3f>(src_loc, *index, *x, *y, *z);
}

void GlDirect::VertexAttrib3fv(const Uint& index, const FloatArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib3fv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib3s(const Uint& index, const Short& x, const Short& y, const Short& z, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib3s>(src_loc, *index, *x, *y, *z);
}

void GlDirect::VertexAttrib3sv(const Uint& index, const Short& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib3sv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4Nbv(const Uint& index, const Byte& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4Nbv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4Niv(const Uint& index, const IntArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4Niv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4Nsv(const Uint& index, const Short& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4Nsv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4Nub(const Uint& index, const Ubyte& x, const Ubyte& y, const Ubyte& z, const Ubyte& w, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4Nub>(src_loc, *index, *x, *y, *z, *w);
}

void GlDirect::VertexAttrib4Nubv(const Uint& index, const Ubyte& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4Nubv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4Nuiv(const Uint& index, const UintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4Nuiv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4Nusv(const Uint& index, const Ushort& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4Nusv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4bv(const Uint& index, const Byte& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4bv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4d(const Uint& index, const Double& x, const Double& y, const Double& z, const Double& w, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4d>(src_loc, *index, *x, *y, *z, *w);
}

void GlDirect::VertexAttrib4dv(const Uint& index, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4dv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4f(const Uint& index, const Float& x, const Float& y, const Float& z, const Float& w, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4f>(src_loc, *index, *x, *y, *z, *w);
}

void GlDirect::VertexAttrib4fv(const Uint& index, const FloatArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4fv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4iv(const Uint& index, const IntArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4iv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4s(const Uint& index, const Short& x, const Short& y, const Short& z, const Short& w, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4s>(src_loc, *index, *x, *y, *z, *w);
}

void GlDirect::VertexAttrib4sv(const Uint& index, const Short& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4sv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4ubv(const Uint& index, const Ubyte& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4ubv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4uiv(const Uint& index, const UintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4uiv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4usv(const Uint& index, const Ushort& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4usv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribBinding(const Uint& attribindex, const Uint& bindingindex, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribBinding>(src_loc, *attribindex, *bindingindex);
}

void GlDirect::VertexAttribDivisor(const Uint& index, const Uint& divisor, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribDivisor>(src_loc, *index, *divisor);
}

void GlDirect::VertexAttribFormat(const Uint& attribindex, const Int& size, const Enum& type, const Boolean& normalized, const Uint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribFormat>(src_loc, *attribindex, *size, *type, *normalized, *relativeoffset);
}

void GlDirect::VertexAttribI1i(const Uint& index, const Int& x, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI1i>(src_loc, *index, *x);
}

void GlDirect::VertexAttribI1iv(const Uint& index, const IntArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI1iv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI1ui(const Uint& index, const Uint& x, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI1ui>(src_loc, *index, *x);
}

void GlDirect::VertexAttribI1uiv(const Uint& index, const UintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI1uiv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI2i(const Uint& index, const Int& x, const Int& y, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI2i>(src_loc, *index, *x, *y);
}

void GlDirect::VertexAttribI2iv(const Uint& index, const IntArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI2iv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI2ui(const Uint& index, const Uint& x, const Uint& y, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI2ui>(src_loc, *index, *x, *y);
}

void GlDirect::VertexAttribI2uiv(const Uint& index, const UintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI2uiv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI3i(const Uint& index, const Int& x, const Int& y, const Int& z, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI3i>(src_loc, *index, *x, *y, *z);
}

void GlDirect::VertexAttribI3iv(const Uint& index, const IntArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI3iv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI3ui(const Uint& index, const Uint& x, const Uint& y, const Uint& z, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI3ui>(src_loc, *index, *x, *y, *z);
}

void GlDirect::VertexAttribI3uiv(const Uint& index, const UintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI3uiv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI4bv(const Uint& index, const Byte& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI4bv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI4i(const Uint& index, const Int& x, const Int& y, const Int& z, const Int& w, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI4i>(src_loc, *index, *x, *y, *z, *w);
}

void GlDirect::VertexAttribI4iv(const Uint& index, const IntArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI4iv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI4sv(const Uint& index, const Short& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI4sv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI4ubv(const Uint& index, const Ubyte& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI4ubv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI4ui(const Uint& index, const Uint& x, const Uint& y, const Uint& z, const Uint& w, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI4ui>(src_loc, *index, *x, *y, *z, *w);
}

void GlDirect::VertexAttribI4uiv(const Uint& index, const UintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI4uiv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI4usv(const Uint& index, const Ushort& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI4usv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribIFormat(const Uint& attribindex, const Int& size, const Enum& type, const Uint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribIFormat>(src_loc, *attribindex, *size, *type, *relativeoffset);
}

void GlDirect::VertexAttribIPointer(const Uint& index, const Int& size, const Enum& type, const Sizei& stride, const Data& pointer, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribIPointer>(src_loc, *index, *size, *type, *stride, pointer.get());
}

void GlDirect::VertexAttribL1d(const Uint& index, const Double& x, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribL1d>(src_loc, *index, *x);
}

void GlDirect::VertexAttribL1dv(const Uint& index, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribL1dv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribL2d(const Uint& index, const Double& x, const Double& y, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribL2d>(src_loc, *index, *x, *y);
}

void GlDirect::VertexAttribL2dv(const Uint& index, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribL2dv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribL3d(const Uint& index, const Double& x, const Double& y, const Double& z, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribL3d>(src_loc, *index, *x, *y, *z);
}

void GlDirect::VertexAttribL3dv(const Uint& index, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribL3dv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribL4d(const Uint& index, const Double& x, const Double& y, const Double& z, const Double& w, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribL4d>(src_loc, *index, *x, *y, *z, *w);
}

void GlDirect::VertexAttribL4dv(const Uint& index, const DoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribL4dv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribLFormat(const Uint& attribindex, const Int& size, const Enum& type, const Uint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribLFormat>(src_loc, *attribindex, *size, *type, *relativeoffset);
}

void GlDirect::VertexAttribLPointer(const Uint& index, const Int& size, const Enum& type, const Sizei& stride, const Data& pointer, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribLPointer>(src_loc, *index, *size, *type, *stride, pointer.get());
}

void GlDirect::VertexAttribP1ui(const Uint& index, const Enum& type, const Boolean& normalized, const Uint& value, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribP1ui>(src_loc, *index, *type, *normalized, *value);
}

void GlDirect::VertexAttribP1uiv(const Uint& index, const Enum& type, const Boolean& normalized, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribP1uiv>(src_loc, *index, *type, *normalized, value.get());
}

void GlDirect::VertexAttribP2ui(const Uint& index, const Enum& type, const Boolean& normalized, const Uint& value, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribP2ui>(src_loc, *index, *type, *normalized, *value);
}

void GlDirect::VertexAttribP2uiv(const Uint& index, const Enum& type, const Boolean& normalized, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribP2uiv>(src_loc, *index, *type, *normalized, value.get());
}

void GlDirect::VertexAttribP3ui(const Uint& index, const Enum& type, const Boolean& normalized, const Uint& value, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribP3ui>(src_loc, *index, *type, *normalized, *value);
}

void GlDirect::VertexAttribP3uiv(const Uint& index, const Enum& type, const Boolean& normalized, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribP3uiv>(src_loc, *index, *type, *normalized, value.get());
}

void GlDirect::VertexAttribP4ui(const Uint& index, const Enum& type, const Boolean& normalized, const Uint& value, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribP4ui>(src_loc, *index, *type, *normalized, *value);
}

void GlDirect::VertexAttribP4uiv(const Uint& index, const Enum& type, const Boolean& normalized, const UintArr& value, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribP4uiv>(src_loc, *index, *type, *normalized, value.get());
}

void GlDirect::VertexAttribPointer(const Uint& index, const Int& size, const Enum& type, const Boolean& normalized, const Sizei& stride, const Data& pointer, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribPointer>(src_loc, *index, *size, *type, *normalized, *stride, pointer.get());
}

void GlDirect::VertexBindingDivisor(const Uint& bindingindex, const Uint& divisor, const SrcLoc& src_loc){
    return _callGL<&glVertexBindingDivisor>(src_loc, *bindingindex, *divisor);
}

void GlDirect::Viewport(const Int& x, const Int& y, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
    return _callGL<&glViewport>(src_loc, *x, *y, *width, *height);
}

void GlDirect::ViewportArrayv(const Uint& first, const Sizei& count, const FloatArr& v, const SrcLoc& src_loc){
    return _callGL<&glViewportArrayv>(src_loc, *first, *count, v.get());
}

void GlDirect::ViewportIndexedf(const Uint& index, const Float& x, const Float& y, const Float& w, const Float& h, const SrcLoc& src_loc){
    return _callGL<&glViewportIndexedf>(src_loc, *index, *x, *y, *w, *h);
}

void GlDirect::ViewportIndexedfv(const Uint& index, const FloatArr& v, const SrcLoc& src_loc){
    return _callGL<&glViewportIndexedfv>(src_loc, *index, v.get());
}

void GlDirect::WaitSync(const Sync& sync, const Bitfield& flags, const Uint64& timeout, const SrcLoc& src_loc){
    return _callGL<&glWaitSync>(src_loc, *sync, *flags, *timeout);
}