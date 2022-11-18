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

void GlDirect::ActiveShaderProgram(const GLuint& pipeline, const GLuint& program, const SrcLoc& src_loc){
    return _callGL<&glActiveShaderProgram>(src_loc, *pipeline, *program);
}

void GlDirect::ActiveTexture(const GLenum& texture, const SrcLoc& src_loc){
    return _callGL<&glActiveTexture>(src_loc, *texture);
}

void GlDirect::AttachShader(const GLuint& program, const GLuint& shader, const SrcLoc& src_loc){
    return _callGL<&glAttachShader>(src_loc, *program, *shader);
}

void GlDirect::BeginConditionalRender(const GLuint& id, const GLenum& mode, const SrcLoc& src_loc){
    return _callGL<&glBeginConditionalRender>(src_loc, *id, *mode);
}

void GlDirect::BeginQuery(const GLenum& target, const GLuint& id, const SrcLoc& src_loc){
    return _callGL<&glBeginQuery>(src_loc, *target, *id);
}

void GlDirect::BeginQueryIndexed(const GLenum& target, const GLuint& index, const GLuint& id, const SrcLoc& src_loc){
    return _callGL<&glBeginQueryIndexed>(src_loc, *target, *index, *id);
}

void GlDirect::BeginTransformFeedback(const GLenum& primitiveMode, const SrcLoc& src_loc){
    return _callGL<&glBeginTransformFeedback>(src_loc, *primitiveMode);
}

void GlDirect::BindAttribLocation(const GLuint& program, const GLuint& index, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glBindAttribLocation>(src_loc, *program, *index, name->c_str());
}

void GlDirect::BindBuffer(const GLenum& target, const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&glBindBuffer>(src_loc, *target, *buffer);
}

void GlDirect::BindBufferBase(const GLenum& target, const GLuint& index, const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&glBindBufferBase>(src_loc, *target, *index, *buffer);
}

void GlDirect::BindBufferRange(const GLenum& target, const GLuint& index, const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&glBindBufferRange>(src_loc, *target, *index, *buffer, *offset, *size);
}

void GlDirect::BindBuffersBase(const GLenum& target, const GLuint& first, const GLsizei& count, const GLuintArr& buffers, const SrcLoc& src_loc){
    return _callGL<&glBindBuffersBase>(src_loc, *target, *first, *count, buffers.get());
}

void GlDirect::BindBuffersRange(const GLenum& target, const GLuint& first, const GLsizei& count, const GLuintArr& buffers, const GLintptrArr& offsets, const GLsizeiptrArr& sizes, const SrcLoc& src_loc){
    return _callGL<&glBindBuffersRange>(src_loc, *target, *first, *count, buffers.get(), offsets.get(), sizes.get());
}

void GlDirect::BindFragDataLocation(const GLuint& program, const GLuint& color, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glBindFragDataLocation>(src_loc, *program, *color, name->c_str());
}

void GlDirect::BindFragDataLocationIndexed(const GLuint& program, const GLuint& colorNumber, const GLuint& index, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glBindFragDataLocationIndexed>(src_loc, *program, *colorNumber, *index, name->c_str());
}

void GlDirect::BindFramebuffer(const GLenum& target, const GLuint& framebuffer, const SrcLoc& src_loc){
    return _callGL<&glBindFramebuffer>(src_loc, *target, *framebuffer);
}

void GlDirect::BindImageTexture(const GLuint& unit, const GLuint& texture, const GLint& level, const GLboolean& layered, const GLint& layer, const GLenum& access, const GLenum& format, const SrcLoc& src_loc){
    return _callGL<&glBindImageTexture>(src_loc, *unit, *texture, *level, *layered, *layer, *access, *format);
}

void GlDirect::BindImageTextures(const GLuint& first, const GLsizei& count, const GLuintArr& textures, const SrcLoc& src_loc){
    return _callGL<&glBindImageTextures>(src_loc, *first, *count, textures.get());
}

void GlDirect::BindProgramPipeline(const GLuint& pipeline, const SrcLoc& src_loc){
    return _callGL<&glBindProgramPipeline>(src_loc, *pipeline);
}

void GlDirect::BindRenderbuffer(const GLenum& target, const GLuint& renderbuffer, const SrcLoc& src_loc){
    return _callGL<&glBindRenderbuffer>(src_loc, *target, *renderbuffer);
}

void GlDirect::BindSampler(const GLuint& unit, const GLuint& sampler, const SrcLoc& src_loc){
    return _callGL<&glBindSampler>(src_loc, *unit, *sampler);
}

void GlDirect::BindSamplers(const GLuint& first, const GLsizei& count, const GLuintArr& samplers, const SrcLoc& src_loc){
    return _callGL<&glBindSamplers>(src_loc, *first, *count, samplers.get());
}

void GlDirect::BindTexture(const GLenum& target, const GLuint& texture, const SrcLoc& src_loc){
    return _callGL<&glBindTexture>(src_loc, *target, *texture);
}

void GlDirect::BindTextureUnit(const GLuint& unit, const GLuint& texture, const SrcLoc& src_loc){
    return _callGL<&glBindTextureUnit>(src_loc, *unit, *texture);
}

void GlDirect::BindTextures(const GLuint& first, const GLsizei& count, const GLuintArr& textures, const SrcLoc& src_loc){
    return _callGL<&glBindTextures>(src_loc, *first, *count, textures.get());
}

void GlDirect::BindTransformFeedback(const GLenum& target, const GLuint& id, const SrcLoc& src_loc){
    return _callGL<&glBindTransformFeedback>(src_loc, *target, *id);
}

void GlDirect::BindVertexArray(const GLuint& array, const SrcLoc& src_loc){
    return _callGL<&glBindVertexArray>(src_loc, *array);
}

void GlDirect::BindVertexBuffer(const GLuint& bindingindex, const GLuint& buffer, const GLintptr& offset, const GLsizei& stride, const SrcLoc& src_loc){
    return _callGL<&glBindVertexBuffer>(src_loc, *bindingindex, *buffer, *offset, *stride);
}

void GlDirect::BindVertexBuffers(const GLuint& first, const GLsizei& count, const GLuintArr& buffers, const GLintptrArr& offsets, const GLsizeiArr& strides, const SrcLoc& src_loc){
    return _callGL<&glBindVertexBuffers>(src_loc, *first, *count, buffers.get(), offsets.get(), strides.get());
}

void GlDirect::BlendColor(const GLfloat& red, const GLfloat& green, const GLfloat& blue, const GLfloat& alpha, const SrcLoc& src_loc){
    return _callGL<&glBlendColor>(src_loc, *red, *green, *blue, *alpha);
}

void GlDirect::BlendEquation(const GLenum& mode, const SrcLoc& src_loc){
    return _callGL<&glBlendEquation>(src_loc, *mode);
}

void GlDirect::BlendEquationSeparate(const GLenum& modeRGB, const GLenum& modeAlpha, const SrcLoc& src_loc){
    return _callGL<&glBlendEquationSeparate>(src_loc, *modeRGB, *modeAlpha);
}

void GlDirect::BlendEquationSeparatei(const GLuint& buf, const GLenum& modeRGB, const GLenum& modeAlpha, const SrcLoc& src_loc){
    return _callGL<&glBlendEquationSeparatei>(src_loc, *buf, *modeRGB, *modeAlpha);
}

void GlDirect::BlendEquationi(const GLuint& buf, const GLenum& mode, const SrcLoc& src_loc){
    return _callGL<&glBlendEquationi>(src_loc, *buf, *mode);
}

void GlDirect::BlendFunc(const GLenum& sfactor, const GLenum& dfactor, const SrcLoc& src_loc){
    return _callGL<&glBlendFunc>(src_loc, *sfactor, *dfactor);
}

void GlDirect::BlendFuncSeparate(const GLenum& sfactorRGB, const GLenum& dfactorRGB, const GLenum& sfactorAlpha, const GLenum& dfactorAlpha, const SrcLoc& src_loc){
    return _callGL<&glBlendFuncSeparate>(src_loc, *sfactorRGB, *dfactorRGB, *sfactorAlpha, *dfactorAlpha);
}

void GlDirect::BlendFuncSeparatei(const GLuint& buf, const GLenum& srcRGB, const GLenum& dstRGB, const GLenum& srcAlpha, const GLenum& dstAlpha, const GLenum& modeAlpha, const SrcLoc& src_loc){
    return _callGL<&glBlendFuncSeparatei>(src_loc, *buf, *srcRGB, *dstRGB, *srcAlpha, *dstAlpha);
}

void GlDirect::BlendFunci(const GLuint& buf, const GLenum& src, const GLenum& dst, const SrcLoc& src_loc){
    return _callGL<&glBlendFunci>(src_loc, *buf, *src, *dst);
}

void GlDirect::BlitFramebuffer(const GLint& srcX0, const GLint& srcY0, const GLint& srcX1, const GLint& srcY1, const GLint& dstX0, const GLint& dstY0, const GLint& dstX1, const GLint& dstY1, const GLbitfield& mask, const GLenum& filter, const SrcLoc& src_loc){
    return _callGL<&glBlitFramebuffer>(src_loc, *srcX0, *srcY0, *srcX1, *srcY1, *dstX0, *dstY0, *dstX1, *dstY1, *mask, *filter);
}

void GlDirect::BlitNamedFramebuffer(const GLuint& readFramebuffer, const GLuint& drawFramebuffer, const GLint& srcX0, const GLint& srcY0, const GLint& srcX1, const GLint& srcY1, const GLint& dstX0, const GLint& dstY0, const GLint& dstX1, const GLint& dstY1, const GLbitfield& mask, const GLenum& filter, const SrcLoc& src_loc){
    return _callGL<&glBlitNamedFramebuffer>(src_loc, *readFramebuffer, *drawFramebuffer, *srcX0, *srcY0, *srcX1, *srcY1, *dstX0, *dstY0, *dstX1, *dstY1, *mask, *filter);
}

void GlDirect::BufferData(const GLenum& target, const GLsizeiptr& size, const GLdata& data, const GLenum& usage, const SrcLoc& src_loc){
    return _callGL<&glBufferData>(src_loc, *target, *size, data.get(), *usage);
}

void GlDirect::BufferStorage(const GLenum& target, const GLsizeiptr& size, const GLdata& data, const GLbitfield& flags, const SrcLoc& src_loc){
    return _callGL<&glBufferStorage>(src_loc, *target, *size, data.get(), *flags);
}

void GlDirect::BufferSubData(const GLenum& target, const GLintptr& offset, const GLsizeiptr& size, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glBufferSubData>(src_loc, *target, *offset, *size, data.get());
}

GL::GLenum GlDirect::CheckFramebufferStatus(const GLenum& target, const SrcLoc& src_loc){
    return _callGL<&glCheckFramebufferStatus>(src_loc, *target);
}

GL::GLenum GlDirect::CheckNamedFramebufferStatus(const GLuint& framebuffer, const GLenum& target, const SrcLoc& src_loc){
    return _callGL<&glCheckNamedFramebufferStatus>(src_loc, *framebuffer, *target);
}

void GlDirect::ClampColor(const GLenum& target, const GLenum& clamp, const SrcLoc& src_loc){
    return _callGL<&glClampColor>(src_loc, *target, *clamp);
}

void GlDirect::Clear(const GLbitfield& mask, const SrcLoc& src_loc){
    return _callGL<&glClear>(src_loc, *mask);
}

void GlDirect::ClearBufferData(const GLenum& target, const GLenum& internalformat, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glClearBufferData>(src_loc, *target, *internalformat, *format, *type, data.get());
}

void GlDirect::ClearBufferSubData(const GLenum& target, const GLenum& internalformat, const GLintptr& offset, const GLsizeiptr& size, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glClearBufferSubData>(src_loc, *target, *internalformat, *offset, *size, *format, *type, data.get());
}

void GlDirect::ClearBufferfi(const GLenum& buffer, const GLint& drawbuffer, const GLfloat& depth, const GLint& stencil, const SrcLoc& src_loc){
    return _callGL<&glClearBufferfi>(src_loc, *buffer, *drawbuffer, *depth, *stencil);
}

void GlDirect::ClearBufferfv(const GLenum& buffer, const GLint& drawbuffer, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glClearBufferfv>(src_loc, *buffer, *drawbuffer, value.get());
}

void GlDirect::ClearBufferiv(const GLenum& buffer, const GLint& drawbuffer, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&glClearBufferiv>(src_loc, *buffer, *drawbuffer, value.get());
}

void GlDirect::ClearBufferuiv(const GLenum& buffer, const GLint& drawbuffer, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&glClearBufferuiv>(src_loc, *buffer, *drawbuffer, value.get());
}

void GlDirect::ClearColor(const GLfloat& red, const GLfloat& green, const GLfloat& blue, const GLfloat& alpha, const SrcLoc& src_loc){
    return _callGL<&glClearColor>(src_loc, *red, *green, *blue, *alpha);
}

void GlDirect::ClearDepth(const GLdouble& depth, const SrcLoc& src_loc){
    return _callGL<&glClearDepth>(src_loc, *depth);
}

void GlDirect::ClearDepthf(const GLfloat& d, const SrcLoc& src_loc){
    return _callGL<&glClearDepthf>(src_loc, *d);
}

void GlDirect::ClearNamedBufferData(const GLuint& buffer, const GLenum& internalformat, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glClearNamedBufferData>(src_loc, *buffer, *internalformat, *format, *type, data.get());
}

void GlDirect::ClearNamedBufferSubData(const GLuint& buffer, const GLenum& internalformat, const GLintptr& offset, const GLsizeiptr& size, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glClearNamedBufferSubData>(src_loc, *buffer, *internalformat, *offset, *size, *format, *type, data.get());
}

void GlDirect::ClearNamedFramebufferfi(const GLuint& framebuffer, const GLenum& buffer, const GLint& drawbuffer, const GLfloat& depth, const GLint& stencil, const SrcLoc& src_loc){
    return _callGL<&glClearNamedFramebufferfi>(src_loc, *framebuffer, *buffer, *drawbuffer, *depth, *stencil);
}

void GlDirect::ClearNamedFramebufferfv(const GLuint& framebuffer, const GLenum& buffer, const GLint& drawbuffer, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glClearNamedFramebufferfv>(src_loc, *framebuffer, *buffer, *drawbuffer, value.get());
}

void GlDirect::ClearNamedFramebufferiv(const GLuint& framebuffer, const GLenum& buffer, const GLint& drawbuffer, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&glClearNamedFramebufferiv>(src_loc, *framebuffer, *buffer, *drawbuffer, value.get());
}

void GlDirect::ClearNamedFramebufferuiv(const GLuint& framebuffer, const GLenum& buffer, const GLint& drawbuffer, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&glClearNamedFramebufferuiv>(src_loc, *framebuffer, *buffer, *drawbuffer, value.get());
}

void GlDirect::ClearStencil(const GLint& s, const SrcLoc& src_loc){
    return _callGL<&glClearStencil>(src_loc, *s);
}

void GlDirect::ClearTexImage(const GLuint& texture, const GLint& level, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glClearTexImage>(src_loc, *texture, *level, *format, *type, data.get());
}

void GlDirect::ClearTexSubImage(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glClearTexSubImage>(src_loc, *texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *type, data.get());
}

GL::GLenum GlDirect::ClientWaitSync(const GLsync& sync, const GLbitfield& flags, const GLuint64& timeout, const SrcLoc& src_loc){
    return _callGL<&glClientWaitSync>(src_loc, *sync, *flags, *timeout);
}

void GlDirect::ClipControl(const GLenum& origin, const GLenum& depth, const SrcLoc& src_loc){
    return _callGL<&glClipControl>(src_loc, *origin, *depth);
}

void GlDirect::ColorMask(const GLboolean& red, const GLboolean& green, const GLboolean& blue, const GLboolean& alpha, const SrcLoc& src_loc){
    return _callGL<&glColorMask>(src_loc, *red, *green, *blue, *alpha);
}

void GlDirect::ColorMaski(const GLuint& index, const GLboolean& r, const GLboolean& g, const GLboolean& b, const GLboolean& a, const SrcLoc& src_loc){
    return _callGL<&glColorMaski>(src_loc, *index, *r, *g, *b, *a);
}

void GlDirect::CompileShader(const GLuint& shader, const SrcLoc& src_loc){
    return _callGL<&glCompileShader>(src_loc, *shader);
}

void GlDirect::CompressedTexImage1D(const GLenum& target, const GLint& level, const GLenum& internalformat, const GLsizei& width, const GLint& border, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTexImage1D>(src_loc, *target, *level, *internalformat, *width, *border, *imageSize, data.get());
}

void GlDirect::CompressedTexImage2D(const GLenum& target, const GLint& level, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLint& border, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTexImage2D>(src_loc, *target, *level, *internalformat, *width, *height, *border, *imageSize, data.get());
}

void GlDirect::CompressedTexImage3D(const GLenum& target, const GLint& level, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLint& border, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTexImage3D>(src_loc, *target, *level, *internalformat, *width, *height, *depth, *border, *imageSize, data.get());
}

void GlDirect::CompressedTexSubImage1D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLsizei& width, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTexSubImage1D>(src_loc, *target, *level, *xoffset, *width, *format, *imageSize, data.get());
}

void GlDirect::CompressedTexSubImage2D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTexSubImage2D>(src_loc, *target, *level, *xoffset, *yoffset, *width, *height, *format, *imageSize, data.get());
}

void GlDirect::CompressedTexSubImage3D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTexSubImage3D>(src_loc, *target, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *imageSize, data.get());
}

void GlDirect::CompressedTextureSubImage1D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLsizei& width, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTextureSubImage1D>(src_loc, *texture, *level, *xoffset, *width, *format, *imageSize, data.get());
}

void GlDirect::CompressedTextureSubImage2D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTextureSubImage2D>(src_loc, *texture, *level, *xoffset, *yoffset, *width, *height, *format, *imageSize, data.get());
}

void GlDirect::CompressedTextureSubImage3D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glCompressedTextureSubImage3D>(src_loc, *texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *imageSize, data.get());
}

void GlDirect::CopyBufferSubData(const GLenum& readTarget, const GLenum& writeTarget, const GLintptr& readOffset, const GLintptr& writeOffset, const GLsizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&glCopyBufferSubData>(src_loc, *readTarget, *writeTarget, *readOffset, *writeOffset, *size);
}

void GlDirect::CopyImageSubData(const GLuint& srcName, const GLenum& srcTarget, const GLint& srcLevel, const GLint& srcX, const GLint& srcY, const GLint& srcZ, const GLuint& dstName, const GLenum& dstTarget, const GLint& dstLevel, const GLint& dstX, const GLint& dstY, const GLint& dstZ, const GLsizei& srcWidth, const GLsizei& srcHeight, const GLsizei& srcDepth, const SrcLoc& src_loc){
    return _callGL<&glCopyImageSubData>(src_loc, *srcName, *srcTarget, *srcLevel, *srcX, *srcY, *srcZ, *dstName, *dstTarget, *dstLevel, *dstX, *dstY, *dstZ, *srcWidth, *srcHeight, *srcDepth);
}

void GlDirect::CopyNamedBufferSubData(const GLuint& readBuffer, const GLuint& writeBuffer, const GLintptr& readOffset, const GLintptr& writeOffset, const GLsizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&glCopyNamedBufferSubData>(src_loc, *readBuffer, *writeBuffer, *readOffset, *writeOffset, *size);
}

void GlDirect::CopyTexImage1D(const GLenum& target, const GLint& level, const GLenum& internalformat, const GLint& x, const GLint& y, const GLsizei& width, const GLint& border, const SrcLoc& src_loc){
    return _callGL<&glCopyTexImage1D>(src_loc, *target, *level, *internalformat, *x, *y, *width, *border);
}

void GlDirect::CopyTexImage2D(const GLenum& target, const GLint& level, const GLenum& internalformat, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const GLint& border, const SrcLoc& src_loc){
    return _callGL<&glCopyTexImage2D>(src_loc, *target, *level, *internalformat, *x, *y, *width, *height, *border);
}

void GlDirect::CopyTexSubImage1D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& x, const GLint& y, const GLsizei& width, const SrcLoc& src_loc){
    return _callGL<&glCopyTexSubImage1D>(src_loc, *target, *level, *xoffset, *x, *y, *width);
}

void GlDirect::CopyTexSubImage2D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&glCopyTexSubImage2D>(src_loc, *target, *level, *xoffset, *yoffset, *x, *y, *width, *height);
}

void GlDirect::CopyTexSubImage3D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&glCopyTexSubImage3D>(src_loc, *target, *level, *xoffset, *yoffset, *zoffset, *x, *y, *width, *height);
}

void GlDirect::CopyTextureSubImage1D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& x, const GLint& y, const GLsizei& width, const SrcLoc& src_loc){
    return _callGL<&glCopyTextureSubImage1D>(src_loc, *texture, *level, *xoffset, *x, *y, *width);
}

void GlDirect::CopyTextureSubImage2D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&glCopyTextureSubImage2D>(src_loc, *texture, *level, *xoffset, *yoffset, *x, *y, *width, *height);
}

void GlDirect::CopyTextureSubImage3D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&glCopyTextureSubImage3D>(src_loc, *texture, *level, *xoffset, *yoffset, *zoffset, *x, *y, *width, *height);
}

void GlDirect::CreateBuffers(const GLsizei& n, const GLuintArr& dst, const SrcLoc& src_loc){
    return _callGL<&glCreateBuffers>(src_loc, *n, dst.get());
}

void GlDirect::CreateFramebuffers(const GLsizei& n, const GLuintArr& framebuffers, const SrcLoc& src_loc){
    return _callGL<&glCreateFramebuffers>(src_loc, *n, framebuffers.get());
}

GL::GLuint GlDirect::CreateProgram(const SrcLoc& src_loc){
    return _callGL<&glCreateProgram>(src_loc);
}

void GlDirect::CreateProgramPipelines(const GLsizei& n, const GLuintArr& pipelines, const SrcLoc& src_loc){
    return _callGL<&glCreateProgramPipelines>(src_loc, *n, pipelines.get());
}

void GlDirect::CreateQueries(const GLenum& target, const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    return _callGL<&glCreateQueries>(src_loc, *target, *n, ids.get());
}

void GlDirect::CreateRenderbuffers(const GLsizei& n, const GLuintArr& renderbuffers, const SrcLoc& src_loc){
    return _callGL<&glCreateRenderbuffers>(src_loc, *n, renderbuffers.get());
}

void GlDirect::CreateSamplers(const GLsizei& n, const GLuintArr& samplers, const SrcLoc& src_loc){
    return _callGL<&glCreateSamplers>(src_loc, *n, samplers.get());
}

GL::GLuint GlDirect::CreateShader(const GLenum& type, const SrcLoc& src_loc){
    return _callGL<&glCreateShader>(src_loc, *type);
}

GL::GLuint GlDirect::CreateShaderProgramv(const GLenum& type, const GLsizei& count, const GLstringArr& strings, const SrcLoc& src_loc){
    const char** ptrs = new const char*[*count];
    for (size_t i = 0; i < *count; ++i){
        ptrs[i] = (strings.get())[i].c_str();
    }
    auto res = _callGL<&glCreateShaderProgramv>(src_loc, *type, *count, ptrs);
    delete[] ptrs;
    return res;
}

void GlDirect::CreateTextures(const GLenum& target, const GLsizei& n, const GLuintArr& textures, const SrcLoc& src_loc){
    return _callGL<&glCreateTextures>(src_loc, *target, *n, textures.get());
}

void GlDirect::CreateTransformFeedbacks(const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    return _callGL<&glCreateTransformFeedbacks>(src_loc, *n, ids.get());
}

void GlDirect::CreateVertexArrays(const GLsizei& n, const GLuintArr& arrays, const SrcLoc& src_loc){
    return _callGL<&glCreateVertexArrays>(src_loc, *n, arrays.get());
}

void GlDirect::CullFace(const GLenum& mode, const SrcLoc& src_loc){
    return _callGL<&glCullFace>(src_loc, *mode);
}

// void InterfaceGlInner::DebugMessageCallback(const GLDEBUGPROC& callback, const GLdata& userParam, const SrcLoc& src_loc){
// &    _callGL<glDebugMessageCallback>(src_loc, *callback, userParam.get());
//     _debug(src_loc);
// }

void GlDirect::DebugMessageControl(const GLenum& source, const GLenum& type, const GLenum& severity, const GLsizei& count, const GLuintArr& ids, const GLboolean& enabled, const SrcLoc& src_loc){
    return _callGL<&glDebugMessageControl>(src_loc, *source, *type, *severity, *count, ids.get(), *enabled);
}

void GlDirect::DebugMessageInsert(const GLenum& source, const GLenum& type, const GLuint& id, const GLenum& severity, const GLsizei& length, const GLstring& buf, const SrcLoc& src_loc){
    return _callGL<&glDebugMessageInsert>(src_loc, *source, *type, *id, *severity, *length, buf->c_str());
}

void GlDirect::DeleteBuffers(const GLsizei& n, const GLuintArr& buffers, const SrcLoc& src_loc){
    return _callGL<&glDeleteBuffers>(src_loc, *n, buffers.get());
}

void GlDirect::DeleteFramebuffers(const GLsizei& n, const GLuintArr& framebuffers, const SrcLoc& src_loc){
    return _callGL<&glDeleteFramebuffers>(src_loc, *n, framebuffers.get());
}

void GlDirect::DeleteProgram(const GLuint& program, const SrcLoc& src_loc){
    return _callGL<&glDeleteProgram>(src_loc, *program);
}

void GlDirect::DeleteProgramPipelines(const GLsizei& n, const GLuintArr& pipelines, const SrcLoc& src_loc){
    return _callGL<&glDeleteProgramPipelines>(src_loc, *n, pipelines.get());
}

void GlDirect::DeleteQueries(const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    return _callGL<&glDeleteQueries>(src_loc, *n, ids.get());
}

void GlDirect::DeleteRenderbuffers(const GLsizei& n, const GLuintArr& renderbuffers, const SrcLoc& src_loc){
    return _callGL<&glDeleteRenderbuffers>(src_loc, *n, renderbuffers.get());
}

void GlDirect::DeleteSamplers(const GLsizei& count, const GLuintArr& samplers, const SrcLoc& src_loc){
    return _callGL<&glDeleteSamplers>(src_loc, *count, samplers.get());
}

void GlDirect::DeleteShader(const GLuint& shader, const SrcLoc& src_loc){
    return _callGL<&glDeleteShader>(src_loc, *shader);
}

void GlDirect::DeleteSync(const GLsync& sync, const SrcLoc& src_loc){
    return _callGL<&glDeleteSync>(src_loc, *sync);
}

void GlDirect::DeleteTextures(const GLsizei& n, const GLuintArr& textures, const SrcLoc& src_loc){
    return _callGL<&glDeleteTextures>(src_loc, *n, textures.get());
}

void GlDirect::DeleteTransformFeedbacks(const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    return _callGL<&glDeleteTransformFeedbacks>(src_loc, *n, ids.get());
}

void GlDirect::DeleteVertexArrays(const GLsizei& n, const GLuintArr& arrays, const SrcLoc& src_loc){
    return _callGL<&glDeleteVertexArrays>(src_loc, *n, arrays.get());
}

void GlDirect::DepthFunc(const GLenum& func, const SrcLoc& src_loc){
    return _callGL<&glDepthFunc>(src_loc, *func);
}

void GlDirect::DepthMask(const GLboolean& flag, const SrcLoc& src_loc){
    return _callGL<&glDepthMask>(src_loc, *flag);
}

void GlDirect::DepthRange(const GLdouble& n, const GLdouble& f, const SrcLoc& src_loc){
    return _callGL<&glDepthRange>(src_loc, *n, *f);
}

void GlDirect::DepthRangeArrayv(const GLuint& first, const GLsizei& count, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glDepthRangeArrayv>(src_loc, *first, *count, v.get());
}

void GlDirect::DepthRangeIndexed(const GLuint& index, const GLdouble& n, const GLdouble& f, const SrcLoc& src_loc){
    return _callGL<&glDepthRangeIndexed>(src_loc, *index, *n, *f);
}

void GlDirect::DepthRangef(const GLfloat& n, const GLfloat& f, const SrcLoc& src_loc){
    return _callGL<&glDepthRangef>(src_loc, *n, *f);
}

void GlDirect::DetachShader(const GLuint& program, const GLuint& shader, const SrcLoc& src_loc){
    return _callGL<&glDetachShader>(src_loc, *program, *shader);
}

void GlDirect::Disable(const GLenum& cap, const SrcLoc& src_loc){
    return _callGL<&glDisable>(src_loc, *cap);
}

void GlDirect::DisableVertexArrayAttrib(const GLuint& vaobj, const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&glDisableVertexArrayAttrib>(src_loc, *vaobj, *index);
}

void GlDirect::DisableVertexAttribArray(const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&glDisableVertexAttribArray>(src_loc, *index);
}

void GlDirect::Disablei(const GLenum& target, const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&glDisablei>(src_loc, *target, *index);
}

void GlDirect::DispatchCompute(const GLuint& num_groups_x, const GLuint& num_groups_y, const GLuint& num_groups_z, const SrcLoc& src_loc){
    return _callGL<&glDispatchCompute>(src_loc, *num_groups_x, *num_groups_y, *num_groups_z);
}

void GlDirect::DispatchComputeIndirect(const GLintptr& indirect, const SrcLoc& src_loc){
    return _callGL<&glDispatchComputeIndirect>(src_loc, *indirect);
}

void GlDirect::DrawArrays(const GLenum& mode, const GLint& first, const GLsizei& count, const SrcLoc& src_loc){
    return _callGL<&glDrawArrays>(src_loc, *mode, *first, *count);
}

void GlDirect::DrawArraysIndirect(const GLenum& mode, const GLdata& indirect, const SrcLoc& src_loc){
    return _callGL<&glDrawArraysIndirect>(src_loc, *mode, indirect.get());
}

void GlDirect::DrawArraysInstanced(const GLenum& mode, const GLint& first, const GLsizei& count, const GLsizei& instancecount, const SrcLoc& src_loc){
    return _callGL<&glDrawArraysInstanced>(src_loc, *mode, *first, *count, *instancecount);
}

void GlDirect::DrawArraysInstancedBaseInstance(const GLenum& mode, const GLint& first, const GLsizei& count, const GLsizei& instancecount, const GLuint& baseinstance, const SrcLoc& src_loc){
    return _callGL<&glDrawArraysInstancedBaseInstance>(src_loc, *mode, *first, *count, *instancecount, *instancecount);
}

void GlDirect::DrawBuffer(const GLenum& buf, const SrcLoc& src_loc){
    return _callGL<&glDrawBuffer>(src_loc, *buf);
}

void GlDirect::DrawBuffers(const GLsizei& n, const GLenumArr& bufs, const SrcLoc& src_loc){
    return _callGL<&glDrawBuffers>(src_loc, *n, bufs.get());
}

void GlDirect::DrawElements(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const SrcLoc& src_loc){
    return _callGL<&glDrawElements>(src_loc, *mode, *count, *type, indices.get());
}

void GlDirect::DrawElementsBaseVertex(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLint& basevertex, const SrcLoc& src_loc){
    return _callGL<&glDrawElementsBaseVertex>(src_loc, *mode, *count, *type, indices.get(), *basevertex);
}

void GlDirect::DrawElementsIndirect(const GLenum& mode, const GLenum& type, const GLdata& indirect, const SrcLoc& src_loc){
    return _callGL<&glDrawElementsIndirect>(src_loc, *mode, *type, indirect.get());
}

void GlDirect::DrawElementsInstanced(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLsizei& instancecount, const SrcLoc& src_loc){
    return _callGL<&glDrawElementsInstanced>(src_loc, *mode, *count, *type, indices.get(), *instancecount);
}

void GlDirect::DrawElementsInstancedBaseInstance(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLsizei& instancecount, const GLuint& baseinstance, const SrcLoc& src_loc){
    return _callGL<&glDrawElementsInstancedBaseInstance>(src_loc, *mode, *count, *type, indices.get(), *instancecount, *baseinstance);
}

void GlDirect::DrawElementsInstancedBaseVertex(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLsizei& instancecount, const GLint& basevertex, const SrcLoc& src_loc){
    return _callGL<&glDrawElementsInstancedBaseVertex>(src_loc, *mode, *count, *type, indices.get(), *instancecount, *basevertex);
}

void GlDirect::DrawElementsInstancedBaseVertexBaseInstance(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLsizei& instancecount, const GLint& basevertex, const GLuint& baseinstance, const SrcLoc& src_loc){
    return _callGL<&glDrawElementsInstancedBaseVertexBaseInstance>(src_loc, *mode, *count, *type, indices.get(), *instancecount, *basevertex, *baseinstance);
}

void GlDirect::DrawRangeElements(const GLenum& mode, const GLuint& start, const GLuint& end, const GLsizei& count, const GLenum& type, const GLdata& indices, const SrcLoc& src_loc){
    return _callGL<&glDrawRangeElements>(src_loc, *mode, *start, *end, *count, *type, indices.get());
}

void GlDirect::DrawRangeElementsBaseVertex(const GLenum& mode, const GLuint& start, const GLuint& end, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLint& basevertex, const SrcLoc& src_loc){
    return _callGL<&glDrawRangeElementsBaseVertex>(src_loc, *mode, *start, *end, *count, *type, indices.get(), *basevertex);
}

void GlDirect::DrawTransformFeedback(const GLenum& mode, const GLuint& id, const SrcLoc& src_loc){
    return _callGL<&glDrawTransformFeedback>(src_loc, *mode, *id);
}

void GlDirect::DrawTransformFeedbackInstanced(const GLenum& mode, const GLuint& id, const GLsizei& instancecount, const SrcLoc& src_loc){
    return _callGL<&glDrawTransformFeedbackInstanced>(src_loc, *mode, *id, *instancecount);
}

void GlDirect::DrawTransformFeedbackStream(const GLenum& mode, const GLuint& id, const GLuint& stream, const SrcLoc& src_loc){
    return _callGL<&glDrawTransformFeedbackStream>(src_loc, *mode, *id, *stream);
}

void GlDirect::DrawTransformFeedbackStreamInstanced(const GLenum& mode, const GLuint& id, const GLuint& stream, const GLsizei& instancecount, const SrcLoc& src_loc){
    return _callGL<&glDrawTransformFeedbackStreamInstanced>(src_loc, *mode, *id, *stream, *instancecount);
}

void GlDirect::Enable(const GLenum& cap, const SrcLoc& src_loc){
    return _callGL<&glEnable>(src_loc, *cap);
}

void GlDirect::EnableVertexArrayAttrib(const GLuint& vaobj, const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&glEnableVertexArrayAttrib>(src_loc, *vaobj, *index);
}

void GlDirect::EnableVertexAttribArray(const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&glEnableVertexAttribArray>(src_loc, *index);
}

void GlDirect::Enablei(const GLenum& target, const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&glEnablei>(src_loc, *target, *index);
}

void GlDirect::EndConditionalRender(const SrcLoc& src_loc){
    return _callGL<&glEndConditionalRender>(src_loc);
}

void GlDirect::EndQuery(const GLenum& target, const SrcLoc& src_loc){
    return _callGL<&glEndQuery>(src_loc, *target);
}

void GlDirect::EndQueryIndexed(const GLenum& target, const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&glEndQueryIndexed>(src_loc, *target, *index);
}

void GlDirect::EndTransformFeedback(const SrcLoc& src_loc){
    return _callGL<&glEndTransformFeedback>(src_loc);
}

GL::GLsync GlDirect::FenceSync(const GLenum& condition, const GLbitfield& flags, const SrcLoc& src_loc){
    return _callGL<&glFenceSync>(src_loc, *condition, *flags);
}

void GlDirect::Finish(const SrcLoc& src_loc){
    return _callGL<&glFinish>(src_loc);
}

void GlDirect::Flush(const SrcLoc& src_loc){
    return _callGL<&glFlush>(src_loc);
}

void GlDirect::FlushMappedBufferRange(const GLenum& target, const GLintptr& offset, const GLsizeiptr& length, const SrcLoc& src_loc){
    return _callGL<&glFlushMappedBufferRange>(src_loc, *target, *offset, *length);
}

void GlDirect::FlushMappedNamedBufferRange(const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& length, const SrcLoc& src_loc){
    return _callGL<&glFlushMappedNamedBufferRange>(src_loc, *buffer, *offset, *length);
}

void GlDirect::FramebufferParameteri(const GLenum& target, const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    return _callGL<&glFramebufferParameteri>(src_loc, *target, *pname, *param);
}

void GlDirect::FramebufferRenderbuffer(const GLenum& target, const GLenum& attachment, const GLenum& renderbuffertarget, const GLuint& renderbuffer, const SrcLoc& src_loc){
    return _callGL<&glFramebufferRenderbuffer>(src_loc, *target, *attachment, *renderbuffertarget, *renderbuffer);
}

void GlDirect::FramebufferTexture(const GLenum& target, const GLenum& attachment, const GLuint& texture, const GLint& level, const SrcLoc& src_loc){
    return _callGL<&glFramebufferTexture>(src_loc, *target, *attachment, *texture, *level);
}

void GlDirect::FramebufferTexture1D(const GLenum& target, const GLenum& attachment, const GLenum& textarget, const GLuint& texture, const GLint& level, const SrcLoc& src_loc){
    return _callGL<&glFramebufferTexture1D>(src_loc, *target, *attachment, *textarget, *target, *level);
}

void GlDirect::FramebufferTexture2D(const GLenum& target, const GLenum& attachment, const GLenum& textarget, const GLuint& texture, const GLint& level, const SrcLoc& src_loc){
    return _callGL<&glFramebufferTexture2D>(src_loc, *target, *attachment, *textarget, *texture, *level);
}

void GlDirect::FramebufferTexture3D(const GLenum& target, const GLenum& attachment, const GLenum& textarget, const GLuint& texture, const GLint& level, const GLint& zoffset, const SrcLoc& src_loc){
    return _callGL<&glFramebufferTexture3D>(src_loc, *target, *attachment, *textarget, *texture, *level, *zoffset);
}

void GlDirect::FramebufferTextureLayer(const GLenum& target, const GLenum& attachment, const GLuint& texture, const GLint& level, const GLint& layer, const SrcLoc& src_loc){
    return _callGL<&glFramebufferTextureLayer>(src_loc, *target, *attachment, *texture, *level, *layer);
}

void GlDirect::FrontFace(const GLenum& mode, const SrcLoc& src_loc){
    return _callGL<&glFrontFace>(src_loc, *mode);
}

void GlDirect::GenBuffers(const GLsizei& n, const GLuintArr& buffers, const SrcLoc& src_loc){
    return _callGL<&glGenBuffers>(src_loc, *n, buffers.get());
}

void GlDirect::GenFramebuffers(const GLsizei& n, const GLuintArr& framebuffers, const SrcLoc& src_loc){
    return _callGL<&glGenFramebuffers>(src_loc, *n, framebuffers.get());
}

void GlDirect::GenProgramPipelines(const GLsizei& n, const GLuintArr& pipelines, const SrcLoc& src_loc){
    return _callGL<&glGenProgramPipelines>(src_loc, *n, pipelines.get());
}

void GlDirect::GenQueries(const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    return _callGL<&glGenQueries>(src_loc, *n, ids.get());
}

void GlDirect::GenRenderbuffers(const GLsizei& n, const GLuintArr& renderbuffers, const SrcLoc& src_loc){
    return _callGL<&glGenRenderbuffers>(src_loc, *n, renderbuffers.get());
}

void GlDirect::GenSamplers(const GLsizei& count, const GLuintArr& samplers, const SrcLoc& src_loc){
    return _callGL<&glGenSamplers>(src_loc, *count, samplers.get());
}

void GlDirect::GenTextures(const GLsizei& n, const GLuintArr& textures, const SrcLoc& src_loc){
    return _callGL<&glGenTextures>(src_loc, *n, textures.get());
}

void GlDirect::GenTransformFeedbacks(const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    return _callGL<&glGenTransformFeedbacks>(src_loc, *n, ids.get());
}

void GlDirect::GenVertexArrays(const GLsizei& n, const GLuintArr& arrays, const SrcLoc& src_loc){
    return _callGL<&glGenVertexArrays>(src_loc, *n, arrays.get());
}

void GlDirect::GenerateMipmap(const GLenum& target, const SrcLoc& src_loc){
    return _callGL<&glGenerateMipmap>(src_loc, *target);
}

void GlDirect::GenerateTextureMipmap(const GLuint& texture, const SrcLoc& src_loc){
    return _callGL<&glGenerateTextureMipmap>(src_loc, *texture);
}

void GlDirect::GetActiveAtomicCounterBufferiv(const GLuint& program, const GLuint& bufferIndex, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetActiveAtomicCounterBufferiv>(src_loc, *program, *bufferIndex, *pname, params.get());
}

void GlDirect::GetActiveAttrib(const GLuint& program, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLint& size, const GLenum& type, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glGetActiveAttrib>(src_loc, *program, *index, *bufSize, length.get(), size.get(), type.get(), name->data());
}

void GlDirect::GetActiveSubroutineName(const GLuint& program, const GLenum& shadertype, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glGetActiveSubroutineName>(src_loc, *program, *shadertype, *index, *bufSize, length.get(), name->data());
}

void GlDirect::GetActiveSubroutineUniformName(const GLuint& program, const GLenum& shadertype, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glGetActiveSubroutineUniformName>(src_loc, *program, *shadertype, *index, *bufSize, length.get(), name->data());
}

void GlDirect::GetActiveSubroutineUniformiv(const GLuint& program, const GLenum& shadertype, const GLuint& index, const GLenum& pname, const GLintArr& values, const SrcLoc& src_loc){
    return _callGL<&glGetActiveSubroutineUniformiv>(src_loc, *program, *shadertype, *index, *pname, values.get());
}

void GlDirect::GetActiveUniform(const GLuint& program, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLint& size, const GLenum& type, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glGetActiveUniform>(src_loc, *program, *index, *bufSize, length.get(), size.get(), type.get(), name->data());
}

void GlDirect::GetActiveUniformBlockName(const GLuint& program, const GLuint& uniformBlockIndex, const GLsizei& bufSize, const GLsizei& length, const GLstring& uniformBlockName, const SrcLoc& src_loc){
    return _callGL<&glGetActiveUniformBlockName>(src_loc, *program, *uniformBlockIndex, *bufSize, length.get(), uniformBlockName->data());
}

void GlDirect::GetActiveUniformBlockiv(const GLuint& program, const GLuint& uniformBlockIndex, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetActiveUniformBlockiv>(src_loc, *program, *uniformBlockIndex, *pname, params.get());
}

void GlDirect::GetActiveUniformName(const GLuint& program, const GLuint& uniformIndex, const GLsizei& bufSize, const GLsizei& length, const GLstring& uniformName, const SrcLoc& src_loc){
    return _callGL<&glGetActiveUniformName>(src_loc, *program, *uniformIndex, *bufSize, length.get(), uniformName->data());
}

void GlDirect::GetActiveUniformsiv(const GLuint& program, const GLsizei& uniformCount, const GLuintArr& uniformIndices, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetActiveUniformsiv>(src_loc, *program, *uniformCount, uniformIndices.get(), *pname, params.get());
}

void GlDirect::GetAttachedShaders(const GLuint& program, const GLsizei& maxCount, const GLsizeiArr& count, const GLuintArr& shaders, const SrcLoc& src_loc){
    return _callGL<&glGetAttachedShaders>(src_loc, *program, *maxCount, count.get(), shaders.get());
}

GL::GLint GlDirect::GetAttribLocation(const GLuint& program, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glGetAttribLocation>(src_loc, *program, name->c_str());
}

void GlDirect::GetBooleani_v(const GLenum& target, const GLuint& index, const GLbooleanArr& data, const SrcLoc& src_loc){
    return _callGL<&glGetBooleani_v>(src_loc, *target, *index, data.get());
}

void GlDirect::GetBooleanv(const GLenum& pname, const GLbooleanArr& data, const SrcLoc& src_loc){
    return _callGL<&glGetBooleanv>(src_loc, *pname, data.get());
}

void GlDirect::GetBufferParameteri64v(const GLenum& target, const GLenum& pname, const GLint64Arr& params, const SrcLoc& src_loc){
    return _callGL<&glGetBufferParameteri64v>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetBufferParameteriv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetBufferParameteriv>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetBufferPointerv(const GLenum& target, const GLenum& pname, const GLdataPtr& params, const SrcLoc& src_loc){
    return _callGL<&glGetBufferPointerv>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetBufferSubData(const GLenum& target, const GLintptr& offset, const GLsizeiptr& size, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glGetBufferSubData>(src_loc, *target, *offset, *size, data.get());
}

void GlDirect::GetCompressedTexImage(const GLenum& target, const GLint& level, const GLdata& img, const SrcLoc& src_loc){
    return _callGL<&glGetCompressedTexImage>(src_loc, *target, *level, img.get());
}

void GlDirect::GetCompressedTextureImage(const GLuint& texture, const GLint& level, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glGetCompressedTextureImage>(src_loc, *texture, *level, *bufSize, pixels.get());
}

void GlDirect::GetCompressedTextureSubImage(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glGetCompressedTextureSubImage>(src_loc, *texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *bufSize, pixels.get());
}

GL::GLuint GlDirect::GetDebugMessageLog(const GLuint& count, const GLsizei& bufSize, const GLenumArr& sources, const GLenumArr& types, const GLuintArr& ids, const GLenumArr& severities, const GLsizei& lengths, const GLstring& messageLog, const SrcLoc& src_loc){
    return _callGL<&glGetDebugMessageLog>(src_loc, *count, *bufSize, sources.get(), types.get(), ids.get(), severities.get(), lengths.get(), messageLog->data());
}

void GlDirect::GetDoublei_v(const GLenum& target, const GLuint& index, const GLdoubleArr& data, const SrcLoc& src_loc){
    return _callGL<&glGetDoublei_v>(src_loc, *target, *index, data.get());
}

void GlDirect::GetDoublev(const GLenum& pname, const GLdoubleArr& data, const SrcLoc& src_loc){
    return _callGL<&glGetDoublev>(src_loc, *pname, data.get());
}

GL::GLenum GlDirect::GetError(const SrcLoc& src_loc){
    return _callGL<&glGetError>(src_loc);
}

void GlDirect::GetFloati_v(const GLenum& target, const GLuint& index, const GLfloatArr& data, const SrcLoc& src_loc){
    return _callGL<&glGetFloati_v>(src_loc, *target, *index, data.get());
}

void GlDirect::GetFloatv(const GLenum& pname, const GLfloatArr& data, const SrcLoc& src_loc){
    return _callGL<&glGetFloatv>(src_loc, *pname, data.get());
}

GL::GLint GlDirect::GetFragDataIndex(const GLuint& program, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glGetFragDataIndex>(src_loc, *program, name->c_str());
}

GL::GLint GlDirect::GetFragDataLocation(const GLuint& program, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glGetFragDataLocation>(src_loc, *program, name->c_str());
}

void GlDirect::GetFramebufferAttachmentParameteriv(const GLenum& target, const GLenum& attachment, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetFramebufferAttachmentParameteriv>(src_loc, *target, *attachment, *pname, params.get());
}

void GlDirect::GetFramebufferParameteriv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetFramebufferParameteriv>(src_loc, *target, *pname, params.get());
}

GL::GLenum GlDirect::GetGraphicsResetStatus(const SrcLoc& src_loc){
    return _callGL<&glGetGraphicsResetStatus>(src_loc);
}

void GlDirect::GetInteger64i_v(const GLenum& target, const GLuint& index, const GLint64Arr& data, const SrcLoc& src_loc){
    return _callGL<&glGetInteger64i_v>(src_loc, *target, *index, data.get());
}

void GlDirect::GetInteger64v(const GLenum& pname, const GLint64Arr& data, const SrcLoc& src_loc){
    return _callGL<&glGetInteger64v>(src_loc, *pname, data.get());
}

void GlDirect::GetIntegeri_v(const GLenum& target, const GLuint& index, const GLintArr& data, const SrcLoc& src_loc){
    return _callGL<&glGetIntegeri_v>(src_loc, *target, *index, data.get());
}

void GlDirect::GetIntegerv(const GLenum& pname, const GLintArr& data, const SrcLoc& src_loc){
    return _callGL<&glGetIntegerv>(src_loc, *pname, data.get());
}

void GlDirect::GetInternalformati64v(const GLenum& target, const GLenum& internalformat, const GLenum& pname, const GLsizei& count, const GLint64Arr& params, const SrcLoc& src_loc){
    return _callGL<&glGetInternalformati64v>(src_loc, *target, *internalformat, *pname, *count, params.get());
}

void GlDirect::GetInternalformativ(const GLenum& target, const GLenum& internalformat, const GLenum& pname, const GLsizei& count, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetInternalformativ>(src_loc, *target, *internalformat, *pname, *count, params.get());
}

void GlDirect::GetMultisamplefv(const GLenum& pname, const GLuint& index, const GLfloatArr& val, const SrcLoc& src_loc){
    return _callGL<&glGetMultisamplefv>(src_loc, *pname, *index, val.get());
}

void GlDirect::GetNamedBufferParameteri64v(const GLuint& buffer, const GLenum& pname, const GLint64Arr& params, const SrcLoc& src_loc){
    return _callGL<&glGetNamedBufferParameteri64v>(src_loc, *buffer, *pname, params.get());
}

void GlDirect::GetNamedBufferParameteriv(const GLuint& buffer, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetNamedBufferParameteriv>(src_loc, *buffer, *pname, params.get());
}

void GlDirect::GetNamedBufferPointerv(const GLuint& buffer, const GLenum& pname, const GLdataPtr& params, const SrcLoc& src_loc){
    return _callGL<&glGetNamedBufferPointerv>(src_loc, *buffer, *pname, params.get());
}

void GlDirect::GetNamedBufferSubData(const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glGetNamedBufferSubData>(src_loc, *buffer, *offset, *size, data.get());
}

void GlDirect::GetNamedFramebufferAttachmentParameteriv(const GLuint& framebuffer, const GLenum& attachment, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetNamedFramebufferAttachmentParameteriv>(src_loc, *framebuffer, *attachment, *pname, params.get());
}

void GlDirect::GetNamedFramebufferParameteriv(const GLuint& framebuffer, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    return _callGL<&glGetNamedFramebufferParameteriv>(src_loc, *framebuffer, *pname, param.get());
}

void GlDirect::GetNamedRenderbufferParameteriv(const GLuint& renderbuffer, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetNamedRenderbufferParameteriv>(src_loc, *renderbuffer, *pname, params.get());
}

void GlDirect::GetObjectLabel(const GLenum& identifier, const GLuint& name, const GLsizei& bufSize, const GLsizei& length, const GLstring& label, const SrcLoc& src_loc){
    return _callGL<&glGetObjectLabel>(src_loc, *identifier, *name, *bufSize, length.get(), label->data());
}

void GlDirect::GetObjectPtrLabel(const GLdata& ptr, const GLsizei& bufSize, const GLsizei& length, const GLstring& label, const SrcLoc& src_loc){
    return _callGL<&glGetObjectPtrLabel>(src_loc, ptr.get(), *bufSize, length.get(), label->data());
}

void GlDirect::GetPointerv(const GLenum& pname, const GLdataPtr& params, const SrcLoc& src_loc){
    return _callGL<&glGetPointerv>(src_loc, *pname, params.get());
}

void GlDirect::GetProgramBinary(const GLuint& program, const GLsizei& bufSize, const GLsizei& length, const GLenumArr& binaryFormat, const GLdata& binary, const SrcLoc& src_loc){
    return _callGL<&glGetProgramBinary>(src_loc, *program, *bufSize, length.get(), binaryFormat.get(), binary.get());
}

void GlDirect::GetProgramInfoLog(const GLuint& program, const GLsizei& bufSize, const GLsizei& length, const GLstring& infoLog, const SrcLoc& src_loc){
    return _callGL<&glGetProgramInfoLog>(src_loc, *program, *bufSize, length.get(), infoLog->data());
}

void GlDirect::GetProgramInterfaceiv(const GLuint& program, const GLenum& programInterface, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetProgramInterfaceiv>(src_loc, *program, *programInterface, *pname, params.get());
}

void GlDirect::GetProgramPipelineInfoLog(const GLuint& pipeline, const GLsizei& bufSize, const GLsizei& length, const GLstring& infoLog, const SrcLoc& src_loc){
    return _callGL<&glGetProgramPipelineInfoLog>(src_loc, *pipeline, *bufSize, length.get(), infoLog->data());
}

void GlDirect::GetProgramPipelineiv(const GLuint& pipeline, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetProgramPipelineiv>(src_loc, *pipeline, *pname, params.get());
}

GL::GLuint GlDirect::GetProgramResourceIndex(const GLuint& program, const GLenum& programInterface, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glGetProgramResourceIndex>(src_loc, *program, *programInterface, name->c_str());
}

GL::GLint GlDirect::GetProgramResourceLocation(const GLuint& program, const GLenum& programInterface, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glGetProgramResourceLocation>(src_loc, *program, *programInterface, name->c_str());
}

GL::GLint GlDirect::GetProgramResourceLocationIndex(const GLuint& program, const GLenum& programInterface, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glGetProgramResourceLocationIndex>(src_loc, *program, *programInterface, name->c_str());
}

void GlDirect::GetProgramResourceName(const GLuint& program, const GLenum& programInterface, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glGetProgramResourceName>(src_loc, *program, *programInterface, *index, *bufSize, length.get(), name->data());
}

void GlDirect::GetProgramResourceiv(const GLuint& program, const GLenum& programInterface, const GLuint& index, const GLsizei& propCount, const GLenumArr& props, const GLsizei& count, const GLsizei& length, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetProgramResourceiv>(src_loc, *program, *programInterface, *index, *propCount, props.get(), *count, length.get(), params.get());
}

void GlDirect::GetProgramStageiv(const GLuint& program, const GLenum& shadertype, const GLenum& pname, const GLintArr& values, const SrcLoc& src_loc){
    return _callGL<&glGetProgramStageiv>(src_loc, *program, *shadertype, *pname, values.get());
}

void GlDirect::GetProgramiv(const GLuint& program, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetProgramiv>(src_loc, *program, *pname, params.get());
}

void GlDirect::GetQueryBufferObjecti64v(const GLuint& id, const GLuint& buffer, const GLenum& pname, const GLintptr& offset, const SrcLoc& src_loc){
    return _callGL<&glGetQueryBufferObjecti64v>(src_loc, *id, *buffer, *pname, *offset);
}

void GlDirect::GetQueryBufferObjectiv(const GLuint& id, const GLuint& buffer, const GLenum& pname, const GLintptr& offset, const SrcLoc& src_loc){
    return _callGL<&glGetQueryBufferObjectiv>(src_loc, *id, *buffer, *pname, *offset);
}

void GlDirect::GetQueryBufferObjectui64v(const GLuint& id, const GLuint& buffer, const GLenum& pname, const GLintptr& offset, const SrcLoc& src_loc){
    return _callGL<&glGetQueryBufferObjectui64v>(src_loc, *id, *buffer, *pname, *offset);
}

void GlDirect::GetQueryBufferObjectuiv(const GLuint& id, const GLuint& buffer, const GLenum& pname, const GLintptr& offset, const SrcLoc& src_loc){
    return _callGL<&glGetQueryBufferObjectuiv>(src_loc, *id, *buffer, *pname, *offset);
}

void GlDirect::GetQueryIndexediv(const GLenum& target, const GLuint& index, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetQueryIndexediv>(src_loc, *target, *index, *pname, params.get());
}

void GlDirect::GetQueryObjecti64v(const GLuint& id, const GLenum& pname, const GLint64Arr& params, const SrcLoc& src_loc){
    return _callGL<&glGetQueryObjecti64v>(src_loc, *id, *pname, params.get());
}

void GlDirect::GetQueryObjectiv(const GLuint& id, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetQueryObjectiv>(src_loc, *id, *pname, params.get());
}

void GlDirect::GetQueryObjectui64v(const GLuint& id, const GLenum& pname, const GLuint64Arr& params, const SrcLoc& src_loc){
    return _callGL<&glGetQueryObjectui64v>(src_loc, *id, *pname, params.get());
}

void GlDirect::GetQueryObjectuiv(const GLuint& id, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetQueryObjectuiv>(src_loc, *id, *pname, params.get());
}

void GlDirect::GetQueryiv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetQueryiv>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetRenderbufferParameteriv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetRenderbufferParameteriv>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetSamplerParameterIiv(const GLuint& sampler, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetSamplerParameterIiv>(src_loc, *sampler, *pname, params.get());
}

void GlDirect::GetSamplerParameterIuiv(const GLuint& sampler, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetSamplerParameterIuiv>(src_loc, *sampler, *pname, params.get());
}

void GlDirect::GetSamplerParameterfv(const GLuint& sampler, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetSamplerParameterfv>(src_loc, *sampler, *pname, params.get());
}

void GlDirect::GetSamplerParameteriv(const GLuint& sampler, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetSamplerParameteriv>(src_loc, *sampler, *pname, params.get());
}

void GlDirect::GetShaderInfoLog(const GLuint& shader, const GLsizei& bufSize, const GLsizei& length, const GLstring& infoLog, const SrcLoc& src_loc){
    return _callGL<&glGetShaderInfoLog>(src_loc, *shader, *bufSize, length.get(), infoLog->data());
}

void GlDirect::GetShaderPrecisionFormat(const GLenum& shadertype, const GLenum& precisiontype, const GLintArr& range, const GLintArr& precision, const SrcLoc& src_loc){
    return _callGL<&glGetShaderPrecisionFormat>(src_loc, *shadertype, *precisiontype, range.get(), precision.get());
}

void GlDirect::GetShaderSource(const GLuint& shader, const GLsizei& bufSize, const GLsizei& length, const GLstring& source, const SrcLoc& src_loc){
    return _callGL<&glGetShaderSource>(src_loc, *shader, *bufSize, length.get(), source->data());
}

void GlDirect::GetShaderiv(const GLuint& shader, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetShaderiv>(src_loc, *shader, *pname, params.get());
}

GLstring GlDirect::GetString(const GLenum& name, const SrcLoc& src_loc){
    auto gl_res = glGetString(*name);
    auto len = strlen(reinterpret_cast<const char*>(gl_res));
    GLstring dst("");
    dst->resize(len);
    memcpy(dst->data(), gl_res, len);
    return dst;
}

GLstring GlDirect::GetStringi(const GLenum& name, const GLuint& index, const SrcLoc& src_loc){
    auto gl_res = glGetStringi(*name, *index);
    auto len = strlen(reinterpret_cast<const char*>(gl_res));
    GLstring dst("");
    dst->resize(len);
    memcpy(dst->data(), gl_res, len);
    return dst;
}

GL::GLuint GlDirect::GetSubroutineIndex(const GLuint& program, const GLenum& shadertype, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glGetSubroutineIndex>(src_loc, *program, *shadertype, name->c_str());
}

GL::GLint GlDirect::GetSubroutineUniformLocation(const GLuint& program, const GLenum& shadertype, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glGetSubroutineUniformLocation>(src_loc, *program, *shadertype, name->c_str());
}

void GlDirect::GetSynciv(const GLsync& sync, const GLenum& pname, const GLsizei& count, const GLsizei& length, const GLintArr& values, const SrcLoc& src_loc){
    return _callGL<&glGetSynciv>(src_loc, *sync, *pname, *count, length.get(), values.get());
}

void GlDirect::GetTexImage(const GLenum& target, const GLint& level, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glGetTexImage>(src_loc, *target, *level, *format, *type, pixels.get());
}

void GlDirect::GetTexLevelParameterfv(const GLenum& target, const GLint& level, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTexLevelParameterfv>(src_loc, *target, *level, *pname, params.get());
}

void GlDirect::GetTexLevelParameteriv(const GLenum& target, const GLint& level, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTexLevelParameteriv>(src_loc, *target, *level, *pname, params.get());
}

void GlDirect::GetTexParameterIiv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTexParameterIiv>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetTexParameterIuiv(const GLenum& target, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTexParameterIuiv>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetTexParameterfv(const GLenum& target, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTexParameterfv>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetTexParameteriv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTexParameteriv>(src_loc, *target, *pname, params.get());
}

void GlDirect::GetTextureImage(const GLuint& texture, const GLint& level, const GLenum& format, const GLenum& type, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glGetTextureImage>(src_loc, *texture, *level, *format, *type, *bufSize, pixels.get());
}

void GlDirect::GetTextureLevelParameterfv(const GLuint& texture, const GLint& level, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTextureLevelParameterfv>(src_loc, *texture, *level, *pname, params.get());
}

void GlDirect::GetTextureLevelParameteriv(const GLuint& texture, const GLint& level, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTextureLevelParameteriv>(src_loc, *texture, *level, *pname, params.get());
}

void GlDirect::GetTextureParameterIiv(const GLuint& texture, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTextureParameterIiv>(src_loc, *texture, *pname, params.get());
}

void GlDirect::GetTextureParameterIuiv(const GLuint& texture, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTextureParameterIuiv>(src_loc, *texture, *pname, params.get());
}

void GlDirect::GetTextureParameterfv(const GLuint& texture, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTextureParameterfv>(src_loc, *texture, *pname, params.get());
}

void GlDirect::GetTextureParameteriv(const GLuint& texture, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetTextureParameteriv>(src_loc, *texture, *pname, params.get());
}

void GlDirect::GetTextureSubImage(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLenum& type, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glGetTextureSubImage>(src_loc, *texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *type, *bufSize, pixels.get());
}

void GlDirect::GetTransformFeedbackVarying(const GLuint& program, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLsizeiArr& size, const GLenumArr& type, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glGetTransformFeedbackVarying>(src_loc, *program, *index, *bufSize, length.get(), size.get(), type.get(), name->data());
}

void GlDirect::GetTransformFeedbacki64_v(const GLuint& xfb, const GLenum& pname, const GLuint& index, const GLint64Arr& param, const SrcLoc& src_loc){
    return _callGL<&glGetTransformFeedbacki64_v>(src_loc, *xfb, *pname, *index, param.get());
}

void GlDirect::GetTransformFeedbacki_v(const GLuint& xfb, const GLenum& pname, const GLuint& index, const GLintArr& param, const SrcLoc& src_loc){
    return _callGL<&glGetTransformFeedbacki_v>(src_loc, *xfb, *pname, *index, param.get());
}

void GlDirect::GetTransformFeedbackiv(const GLuint& xfb, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    return _callGL<&glGetTransformFeedbackiv>(src_loc, *xfb, *pname, param.get());
}

GL::GLuint GlDirect::GetUniformBlockIndex(const GLuint& program, const GLstring& uniformBlockName, const SrcLoc& src_loc){
    return _callGL<&glGetUniformBlockIndex>(src_loc, *program, uniformBlockName->c_str());
}

GL::GLint GlDirect::GetUniformLocation(const GLuint& program, const GLstring& name, const SrcLoc& src_loc){
    return _callGL<&glGetUniformLocation>(src_loc, *program, name->c_str());
}

void GlDirect::GetUniformSubroutineuiv(const GLenum& shadertype, const GLint& location, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetUniformSubroutineuiv>(src_loc, *shadertype, *location, params.get());
}

void GlDirect::GetUniformdv(const GLuint& program, const GLint& location, const GLdoubleArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetUniformdv>(src_loc, *program, *location, params.get());
}

void GlDirect::GetUniformfv(const GLuint& program, const GLint& location, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetUniformfv>(src_loc, *program, *location, params.get());
}

void GlDirect::GetUniformiv(const GLuint& program, const GLint& location, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetUniformiv>(src_loc, *program, *location, params.get());
}

void GlDirect::GetUniformuiv(const GLuint& program, const GLint& location, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetUniformuiv>(src_loc, *program, *location, params.get());
}

void GlDirect::GetVertexArrayIndexed64iv(const GLuint& vaobj, const GLuint& index, const GLenum& pname, const GLint64Arr& param, const SrcLoc& src_loc){
    return _callGL<&glGetVertexArrayIndexed64iv>(src_loc, *vaobj, *index, *pname, param.get());
}

void GlDirect::GetVertexArrayIndexediv(const GLuint& vaobj, const GLuint& index, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    return _callGL<&glGetVertexArrayIndexediv>(src_loc, *vaobj, *index, *pname, param.get());
}

void GlDirect::GetVertexArrayiv(const GLuint& vaobj, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    return _callGL<&glGetVertexArrayiv>(src_loc, *vaobj, *pname, param.get());
}

void GlDirect::GetVertexAttribIiv(const GLuint& index, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetVertexAttribIiv>(src_loc, *index, *pname, params.get());
}

void GlDirect::GetVertexAttribIuiv(const GLuint& index, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetVertexAttribIuiv>(src_loc, *index, *pname, params.get());
}

void GlDirect::GetVertexAttribLdv(const GLuint& index, const GLenum& pname, const GLdoubleArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetVertexAttribLdv>(src_loc, *index, *pname, params.get());
}

void GlDirect::GetVertexAttribPointerv(const GLuint& index, const GLenum& pname, const GLdataPtr& pointer, const SrcLoc& src_loc){
    return _callGL<&glGetVertexAttribPointerv>(src_loc, *index, *pname, pointer.get());
}

void GlDirect::GetVertexAttribdv(const GLuint& index, const GLenum& pname, const GLdoubleArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetVertexAttribdv>(src_loc, *index, *pname, params.get());
}

void GlDirect::GetVertexAttribfv(const GLuint& index, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetVertexAttribfv>(src_loc, *index, *pname, params.get());
}

void GlDirect::GetVertexAttribiv(const GLuint& index, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetVertexAttribiv>(src_loc, *index, *pname, params.get());
}

void GlDirect::GetnCompressedTexImage(const GLenum& target, const GLint& lod, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glGetnCompressedTexImage>(src_loc, *target, *lod, *bufSize, pixels.get());
}

void GlDirect::GetnTexImage(const GLenum& target, const GLint& level, const GLenum& format, const GLenum& type, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glGetnTexImage>(src_loc, *target, *level, *format, *type, *bufSize, pixels.get());
}

void GlDirect::GetnUniformdv(const GLuint& program, const GLint& location, const GLsizei& bufSize, const GLdoubleArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetnUniformdv>(src_loc, *program, *location, *bufSize, params.get());
}

void GlDirect::GetnUniformfv(const GLuint& program, const GLint& location, const GLsizei& bufSize, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetnUniformfv>(src_loc, *program, *location, *bufSize, params.get());
}

void GlDirect::GetnUniformiv(const GLuint& program, const GLint& location, const GLsizei& bufSize, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetnUniformiv>(src_loc, *program, *location, *bufSize, params.get());
}

void GlDirect::GetnUniformuiv(const GLuint& program, const GLint& location, const GLsizei& bufSize, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&glGetnUniformuiv>(src_loc, *program, *location, *bufSize, params.get());
}

void GlDirect::Hint(const GLenum& target, const GLenum& mode, const SrcLoc& src_loc){
    return _callGL<&glHint>(src_loc, *target, *mode);
}

void GlDirect::InvalidateBufferData(const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&glInvalidateBufferData>(src_loc, *buffer);
}

void GlDirect::InvalidateBufferSubData(const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& length, const SrcLoc& src_loc){
    return _callGL<&glInvalidateBufferSubData>(src_loc, *buffer, *offset, *length);
}

void GlDirect::InvalidateFramebuffer(const GLenum& target, const GLsizei& numAttachments, const GLenumArr& attachments, const SrcLoc& src_loc){
    return _callGL<&glInvalidateFramebuffer>(src_loc, *target, *numAttachments, attachments.get());
}

void GlDirect::InvalidateNamedFramebufferData(const GLuint& framebuffer, const GLsizei& numAttachments, const GLenumArr& attachments, const SrcLoc& src_loc){
    return _callGL<&glInvalidateNamedFramebufferData>(src_loc, *framebuffer, *numAttachments, attachments.get());
}

void GlDirect::InvalidateNamedFramebufferSubData(const GLuint& framebuffer, const GLsizei& numAttachments, const GLenumArr& attachments, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&glInvalidateNamedFramebufferSubData>(src_loc, *framebuffer, *numAttachments, attachments.get(), *x, *y, *width, *height);
}

void GlDirect::InvalidateSubFramebuffer(const GLenum& target, const GLsizei& numAttachments, const GLenumArr& attachments, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&glInvalidateSubFramebuffer>(src_loc, *target, *numAttachments, attachments.get(), *x, *y, *width, *height);
}

void GlDirect::InvalidateTexImage(const GLuint& texture, const GLint& level, const SrcLoc& src_loc){
    return _callGL<&glInvalidateTexImage>(src_loc, *texture, *level);
}

void GlDirect::InvalidateTexSubImage(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const SrcLoc& src_loc){
    return _callGL<&glInvalidateTexSubImage>(src_loc, *texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth);
}

GL::GLboolean GlDirect::IsBuffer(const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&glIsBuffer>(src_loc, *buffer);
}

GL::GLboolean GlDirect::IsEnabled(const GLenum& cap, const SrcLoc& src_loc){
    return _callGL<&glIsEnabled>(src_loc, *cap);
}

GL::GLboolean GlDirect::IsEnabledi(const GLenum& target, const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&glIsEnabledi>(src_loc, *target, *index);
}

GL::GLboolean GlDirect::IsFramebuffer(const GLuint& framebuffer, const SrcLoc& src_loc){
    return _callGL<&glIsFramebuffer>(src_loc, *framebuffer);
}

GL::GLboolean GlDirect::IsProgram(const GLuint& program, const SrcLoc& src_loc){
    return _callGL<&glIsProgram>(src_loc, *program);
}

GL::GLboolean GlDirect::IsProgramPipeline(const GLuint& pipeline, const SrcLoc& src_loc){
    return _callGL<&glIsProgramPipeline>(src_loc, *pipeline);
}

GL::GLboolean GlDirect::IsQuery(const GLuint& id, const SrcLoc& src_loc){
    return _callGL<&glIsQuery>(src_loc, *id);
}

GL::GLboolean GlDirect::IsRenderbuffer(const GLuint& renderbuffer, const SrcLoc& src_loc){
    return _callGL<&glIsRenderbuffer>(src_loc, *renderbuffer);
}

GL::GLboolean GlDirect::IsSampler(const GLuint& sampler, const SrcLoc& src_loc){
    return _callGL<&glIsSampler>(src_loc, *sampler);
}

GL::GLboolean GlDirect::IsShader(const GLuint& shader, const SrcLoc& src_loc){
    return _callGL<&glIsShader>(src_loc, *shader);
}

GL::GLboolean GlDirect::IsSync(const GLsync& sync, const SrcLoc& src_loc){
    return _callGL<&glIsSync>(src_loc, *sync);
}

GL::GLboolean GlDirect::IsTexture(const GLuint& texture, const SrcLoc& src_loc){
    return _callGL<&glIsTexture>(src_loc, *texture);
}

GL::GLboolean GlDirect::IsTransformFeedback(const GLuint& id, const SrcLoc& src_loc){
    return _callGL<&glIsTransformFeedback>(src_loc, *id);
}

GL::GLboolean GlDirect::IsVertexArray(const GLuint& array, const SrcLoc& src_loc){
    return _callGL<&glIsVertexArray>(src_loc, *array);
}

void GlDirect::LineWidth(const GLfloat& width, const SrcLoc& src_loc){
    return _callGL<&glLineWidth>(src_loc, *width);
}

void GlDirect::LinkProgram(const GLuint& program, const SrcLoc& src_loc){
    return _callGL<&glLinkProgram>(src_loc, *program);
}

void GlDirect::LogicOp(const GLenum& opcode, const SrcLoc& src_loc){
    return _callGL<&glLogicOp>(src_loc, *opcode);
}

GL::GLdataPtr GlDirect::MapBuffer(const GLenum& target, const GLenum& access, const SrcLoc& src_loc){
    return _callGL<&glMapBuffer>(src_loc, *target, *access);
}

GL::GLdataPtr GlDirect::MapBufferRange(const GLenum& target, const GLintptr& offset, const GLsizeiptr& length, const GLbitfield& access, const SrcLoc& src_loc){
    return _callGL<&glMapBufferRange>(src_loc, *target, *offset, *length, *access);
}

GLdataPtr GlDirect::MapNamedBuffer(const GLuint& buffer, const GLenum& access, const SrcLoc& src_loc){
    return _callGL<&glMapNamedBuffer>(src_loc, *buffer, *access);
}

GLdataPtr GlDirect::MapNamedBufferRange(const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& length, const GLbitfield& access, const SrcLoc& src_loc){
    return _callGL<&glMapBufferRange>(src_loc, *buffer, *offset, *length, *access);
}

void GlDirect::MemoryBarrier(const GLbitfield& barriers, const SrcLoc& src_loc){
    return _callGL<&glMemoryBarrier>(src_loc, *barriers);
}

void GlDirect::MemoryBarrierByRegion(const GLbitfield& barriers, const SrcLoc& src_loc){
    return _callGL<&glMemoryBarrierByRegion>(src_loc, *barriers);
}

void GlDirect::MinSampleShading(const GLfloat& value, const SrcLoc& src_loc){
    return _callGL<&glMinSampleShading>(src_loc, *value);
}

void GlDirect::MultiDrawArrays(const GLenum& mode, const GLintArr& first, const GLsizeiArr& count, const GLsizei& drawcount, const SrcLoc& src_loc){
    return _callGL<&glMultiDrawArrays>(src_loc, *mode, first.get(), count.get(), *drawcount);
}

void GlDirect::MultiDrawArraysIndirect(const GLenum& mode, const GLdata& indirect, const GLsizei& drawcount, const GLsizei& stride, const SrcLoc& src_loc){
    return _callGL<&glMultiDrawArraysIndirect>(src_loc, *mode, indirect.get(), *drawcount, *stride);
}

void GlDirect::MultiDrawArraysIndirectCount(const GLenum& mode, const GLdata& indirect, const GLintptr& drawcount, const GLsizei& maxdrawcount, const GLsizei& stride, const SrcLoc& src_loc){
    return _callGL<&glMultiDrawArraysIndirectCount>(src_loc, *mode, indirect.get(), *drawcount, *maxdrawcount, *stride);
}

void GlDirect::MultiDrawElements(const GLenum& mode, const GLsizeiArr& count, const GLenum& type, const GLdataPtr& indices, const GLsizei& drawcount, const SrcLoc& src_loc){
    return _callGL<&glMultiDrawElements>(src_loc, *mode, count.get(), *type, indices.get(), *drawcount);
}

void GlDirect::MultiDrawElementsBaseVertex(const GLenum& mode, const GLsizeiArr& count, const GLenum& type, const GLdataPtr& indices, const GLsizei& drawcount, const GLintArr& basevertex, const SrcLoc& src_loc){
    return _callGL<&glMultiDrawElementsBaseVertex>(src_loc, *mode, count.get(), *type, indices.get(), *drawcount, basevertex.get());
}

void GlDirect::MultiDrawElementsIndirect(const GLenum& mode, const GLenum& type, const GLdata& indirect, const GLsizei& drawcount, const GLsizei& stride, const SrcLoc& src_loc){
    return _callGL<&glMultiDrawElementsIndirect>(src_loc, *mode, *type, indirect.get(), *drawcount, *stride);
}

void GlDirect::MultiDrawElementsIndirectCount(const GLenum& mode, const GLenum& type, const GLdata& indirect, const GLintptr& drawcount, const GLsizei& maxdrawcount, const GLsizei& stride, const SrcLoc& src_loc){
    return _callGL<&glMultiDrawElementsIndirectCount>(src_loc, *mode, *type, indirect.get(), *drawcount, *maxdrawcount, *stride);
}

void GlDirect::NamedBufferData(const GLuint& buffer, const GLsizeiptr& size, const GLdata& data, const GLenum& usage, const SrcLoc& src_loc){
    return _callGL<&glNamedBufferData>(src_loc, *buffer, *size, data.get(), *usage);
}

void GlDirect::NamedBufferStorage(const GLuint& buffer, const GLsizeiptr& size, const GLdata& data, const GLbitfield& flags, const SrcLoc& src_loc){
    return _callGL<&glNamedBufferStorage>(src_loc, *buffer, *size, data.get(), *flags);
}

void GlDirect::NamedBufferSubData(const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glNamedBufferSubData>(src_loc, *buffer, *offset, *size, data.get());
}

void GlDirect::NamedFramebufferDrawBuffer(const GLuint& framebuffer, const GLenum& buf, const SrcLoc& src_loc){
    return _callGL<&glNamedFramebufferDrawBuffer>(src_loc, *framebuffer, *buf);
}

void GlDirect::NamedFramebufferDrawBuffers(const GLuint& framebuffer, const GLsizei& n, const GLenumArr& bufs, const SrcLoc& src_loc){
    return _callGL<&glNamedFramebufferDrawBuffers>(src_loc, *framebuffer, *n, bufs.get());
}

void GlDirect::NamedFramebufferParameteri(const GLuint& framebuffer, const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    return _callGL<&glNamedFramebufferParameteri>(src_loc, *framebuffer, *pname, *param);
}

void GlDirect::NamedFramebufferReadBuffer(const GLuint& framebuffer, const GLenum& src, const SrcLoc& src_loc){
    return _callGL<&glNamedFramebufferReadBuffer>(src_loc, *framebuffer, *src);
}

void GlDirect::NamedFramebufferRenderbuffer(const GLuint& framebuffer, const GLenum& attachment, const GLenum& renderbuffertarget, const GLuint& renderbuffer, const SrcLoc& src_loc){
    return _callGL<&glNamedFramebufferRenderbuffer>(src_loc, *framebuffer, *attachment, *renderbuffertarget, *renderbuffer);
}

void GlDirect::NamedFramebufferTexture(const GLuint& framebuffer, const GLenum& attachment, const GLuint& texture, const GLint& level, const SrcLoc& src_loc){
    return _callGL<&glNamedFramebufferTexture>(src_loc, *framebuffer, *attachment, *texture, *level);
}

void GlDirect::NamedFramebufferTextureLayer(const GLuint& framebuffer, const GLenum& attachment, const GLuint& texture, const GLint& level, const GLint& layer, const SrcLoc& src_loc){
    return _callGL<&glNamedFramebufferTextureLayer>(src_loc, *framebuffer, *attachment, *texture, *level, *layer);
}

void GlDirect::NamedRenderbufferStorage(const GLuint& renderbuffer, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&glNamedRenderbufferStorage>(src_loc, *renderbuffer, *internalformat, *width, *height);
}

void GlDirect::NamedRenderbufferStorageMultisample(const GLuint& renderbuffer, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&glNamedRenderbufferStorageMultisample>(src_loc, *renderbuffer, *samples, *internalformat, *width, *height);
}

void GlDirect::ObjectLabel(const GLenum& identifier, const GLuint& name, const GLsizei& length, const GLstring& label, const SrcLoc& src_loc){
    return _callGL<&glObjectLabel>(src_loc, *identifier, *name, *length, label->c_str());
}

void GlDirect::ObjectPtrLabel(const GLdata& ptr, const GLsizei& length, const GLstring& label, const SrcLoc& src_loc){
    return _callGL<&glObjectPtrLabel>(src_loc, ptr.get(), *length, label->c_str());
}

void GlDirect::PatchParameterfv(const GLenum& pname, const GLfloatArr& values, const SrcLoc& src_loc){
    return _callGL<&glPatchParameterfv>(src_loc, *pname, values.get());
}

void GlDirect::PatchParameteri(const GLenum& pname, const GLint& value, const SrcLoc& src_loc){
    return _callGL<&glPatchParameteri>(src_loc, *pname, *value);
}

void GlDirect::PauseTransformFeedback(const SrcLoc& src_loc){
    return _callGL<&glPauseTransformFeedback>(src_loc);
}

void GlDirect::PixelStoref(const GLenum& pname, const GLfloat& param, const SrcLoc& src_loc){
    return _callGL<&glPixelStoref>(src_loc, *pname, *param);
}

void GlDirect::PixelStorei(const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    return _callGL<&glPixelStorei>(src_loc, *pname, *param);
}

void GlDirect::PointParameterf(const GLenum& pname, const GLfloat& param, const SrcLoc& src_loc){
    return _callGL<&glPointParameterf>(src_loc, *pname, *param);
}

void GlDirect::PointParameterfv(const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glPointParameterfv>(src_loc, *pname, params.get());
}

void GlDirect::PointParameteri(const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    return _callGL<&glPointParameteri>(src_loc, *pname, *param);
}

void GlDirect::PointParameteriv(const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glPointParameteriv>(src_loc, *pname, params.get());
}

void GlDirect::PointSize(const GLfloat& size, const SrcLoc& src_loc){
    return _callGL<&glPointSize>(src_loc, *size);
}

void GlDirect::PolygonMode(const GLenum& face, const GLenum& mode, const SrcLoc& src_loc){
    return _callGL<&glPolygonMode>(src_loc, *face, *mode);
}

void GlDirect::PolygonOffset(const GLfloat& factor, const GLfloat& units, const SrcLoc& src_loc){
    return _callGL<&glPolygonOffset>(src_loc, *factor, *units);
}

void GlDirect::PolygonOffsetClamp(const GLfloat& factor, const GLfloat& units, const GLfloat& clamp, const SrcLoc& src_loc){
    return _callGL<&glPolygonOffsetClamp>(src_loc, *factor, *units, *clamp);
}

void GlDirect::PopDebugGroup(const SrcLoc& src_loc){
    return _callGL<&glPopDebugGroup>(src_loc);
}

void GlDirect::PrimitiveRestartIndex(const GLuint& index, const SrcLoc& src_loc){
    return _callGL<&glPrimitiveRestartIndex>(src_loc, *index);
}

void GlDirect::ProgramBinary(const GLuint& program, const GLenum& binaryFormat, const GLdata& binary, const GLsizei& length, const SrcLoc& src_loc){
    return _callGL<&glProgramBinary>(src_loc, *program, *binaryFormat, binary.get(), *length);
}

void GlDirect::ProgramParameteri(const GLuint& program, const GLenum& pname, const GLint& value, const SrcLoc& src_loc){
    return _callGL<&glProgramParameteri>(src_loc, *program, *pname, *value);
}

void GlDirect::ProgramUniform1d(const GLuint& program, const GLint& location, const GLdouble& v0, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform1d>(src_loc, *program, *location, *v0);
}

void GlDirect::ProgramUniform1dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform1dv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform1f(const GLuint& program, const GLint& location, const GLfloat& v0, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform1f>(src_loc, *program, *location, *v0);
}

void GlDirect::ProgramUniform1fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform1fv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform1i(const GLuint& program, const GLint& location, const GLint& v0, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform1i>(src_loc, *program, *location, *v0);
}

void GlDirect::ProgramUniform1iv(const GLuint& program, const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform1iv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform1ui(const GLuint& program, const GLint& location, const GLuint& v0, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform1ui>(src_loc, *program, *location, *v0);
}

void GlDirect::ProgramUniform1uiv(const GLuint& program, const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform1uiv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform2d(const GLuint& program, const GLint& location, const GLdouble& v0, const GLdouble& v1, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform2d>(src_loc, *program, *location, *v0, *v1);
}

void GlDirect::ProgramUniform2dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform2dv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform2f(const GLuint& program, const GLint& location, const GLfloat& v0, const GLfloat& v1, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform2f>(src_loc, *program, *location, *v0, *v1);
}

void GlDirect::ProgramUniform2fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform2fv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform2i(const GLuint& program, const GLint& location, const GLint& v0, const GLint& v1, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform2i>(src_loc, *program, *location, *v0, *v1);
}

void GlDirect::ProgramUniform2iv(const GLuint& program, const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform2iv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform2ui(const GLuint& program, const GLint& location, const GLuint& v0, const GLuint& v1, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform2ui>(src_loc, *program, *location, *v0, *v1);
}

void GlDirect::ProgramUniform2uiv(const GLuint& program, const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform2uiv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform3d(const GLuint& program, const GLint& location, const GLdouble& v0, const GLdouble& v1, const GLdouble& v2, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform3d>(src_loc, *program, *location, *v0, *v1, *v2);
}

void GlDirect::ProgramUniform3dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform3dv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform3f(const GLuint& program, const GLint& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform3f>(src_loc, *program, *location, *v0, *v1, *v2);
}

void GlDirect::ProgramUniform3fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform3fv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform3i(const GLuint& program, const GLint& location, const GLint& v0, const GLint& v1, const GLint& v2, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform3i>(src_loc, *program, *location, *v0, *v1, *v2);
}

void GlDirect::ProgramUniform3iv(const GLuint& program, const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform3iv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform3ui(const GLuint& program, const GLint& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform3ui>(src_loc, *program, *location, *v0, *v1, *v2);
}

void GlDirect::ProgramUniform3uiv(const GLuint& program, const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform3uiv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform4d(const GLuint& program, const GLint& location, const GLdouble& v0, const GLdouble& v1, const GLdouble& v2, const GLdouble& v3, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform4d>(src_loc, *program, *location, *v0, *v1, *v2, *v3);
}

void GlDirect::ProgramUniform4dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform4dv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform4f(const GLuint& program, const GLint& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const GLfloat& v3, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform4f>(src_loc, *program, *location, *v0, *v1, *v2, *v3);
}

void GlDirect::ProgramUniform4fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform4fv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform4i(const GLuint& program, const GLint& location, const GLint& v0, const GLint& v1, const GLint& v2, const GLint& v3, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform4i>(src_loc, *program, *location, *v0, *v1, *v2, *v3);
}

void GlDirect::ProgramUniform4iv(const GLuint& program, const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform4iv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniform4ui(const GLuint& program, const GLint& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const GLuint& v3, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform4ui>(src_loc, *program, *location, *v0, *v1, *v2, *v3);
}

void GlDirect::ProgramUniform4uiv(const GLuint& program, const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniform4uiv>(src_loc, *program, *location, *count, value.get());
}

void GlDirect::ProgramUniformMatrix2dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix2dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix2fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix2fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix2x3dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix2x3dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix2x3fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix2x3fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix2x4dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix2x4dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix2x4fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix2x4fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix3dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix3dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix3fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix3fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix3x2dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix3x2dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix3x2fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix3x2fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix3x4dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix3x4dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix3x4fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix3x4fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix4dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix4dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix4fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix4fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix4x2dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix4x2dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix4x2fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix4x2fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix4x3dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix4x3dv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProgramUniformMatrix4x3fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glProgramUniformMatrix4x3fv>(src_loc, *program, *location, *count, *transpose, value.get());
}

void GlDirect::ProvokingVertex(const GLenum& mode, const SrcLoc& src_loc){
    return _callGL<&glProvokingVertex>(src_loc, *mode);
}

void GlDirect::PushDebugGroup(const GLenum& source, const GLuint& id, const GLsizei& length, const GLstring& message, const SrcLoc& src_loc){
    return _callGL<&glPushDebugGroup>(src_loc, *source, *id, *length, message->c_str());
}

void GlDirect::QueryCounter(const GLuint& id, const GLenum& target, const SrcLoc& src_loc){
    return _callGL<&glQueryCounter>(src_loc, *id, *target);
}

void GlDirect::ReadBuffer(const GLenum& src, const SrcLoc& src_loc){
    return _callGL<&glReadBuffer>(src_loc, *src);
}

void GlDirect::ReadPixels(const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glReadPixels>(src_loc, *x, *y, *width, *height, *format, *type, pixels.get());
}

void GlDirect::ReadnPixels(const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLenum& type, const GLsizei& bufSize, const GLdata& data, const SrcLoc& src_loc){
    return _callGL<&glReadnPixels>(src_loc, *x, *y, *width, *height, *format, *type, *bufSize, data.get());
}

void GlDirect::ReleaseShaderCompiler(const SrcLoc& src_loc){
    return _callGL<&glReleaseShaderCompiler>(src_loc);
}

void GlDirect::RenderbufferStorage(const GLenum& target, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&glRenderbufferStorage>(src_loc, *target, *internalformat, *width, *height);
}

void GlDirect::RenderbufferStorageMultisample(const GLenum& target, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&glRenderbufferStorageMultisample>(src_loc, *target, *samples, *internalformat, *width, *height);
}

void GlDirect::ResumeTransformFeedback(const SrcLoc& src_loc){
    return _callGL<&glResumeTransformFeedback>(src_loc);
}

void GlDirect::SampleCoverage(const GLfloat& value, const GLboolean& invert, const SrcLoc& src_loc){
    return _callGL<&glSampleCoverage>(src_loc, *value, *invert);
}

void GlDirect::SampleMaski(const GLuint& maskNumber, const GLbitfield& mask, const SrcLoc& src_loc){
    return _callGL<&glSampleMaski>(src_loc, *maskNumber, *mask);
}

void GlDirect::SamplerParameterIiv(const GLuint& sampler, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    return _callGL<&glSamplerParameterIiv>(src_loc, *sampler, *pname, param.get());
}

void GlDirect::SamplerParameterIuiv(const GLuint& sampler, const GLenum& pname, const GLuintArr& param, const SrcLoc& src_loc){
    return _callGL<&glSamplerParameterIuiv>(src_loc, *sampler, *pname, param.get());
}

void GlDirect::SamplerParameterf(const GLuint& sampler, const GLenum& pname, const GLfloat& param, const SrcLoc& src_loc){
    return _callGL<&glSamplerParameterf>(src_loc, *sampler, *pname, *param);
}

void GlDirect::SamplerParameterfv(const GLuint& sampler, const GLenum& pname, const GLfloatArr& param, const SrcLoc& src_loc){
    return _callGL<&glSamplerParameterfv>(src_loc, *sampler, *pname, param.get());
}

void GlDirect::SamplerParameteri(const GLuint& sampler, const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    return _callGL<&glSamplerParameteri>(src_loc, *sampler, *pname, *param);
}

void GlDirect::SamplerParameteriv(const GLuint& sampler, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    return _callGL<&glSamplerParameteriv>(src_loc, *sampler, *pname, param.get());
}

void GlDirect::Scissor(const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&glScissor>(src_loc, *x, *y, *width, *height);
}

void GlDirect::ScissorArrayv(const GLuint& first, const GLsizei& count, const GLintArr& v, const SrcLoc& src_loc){
    return _callGL<&glScissorArrayv>(src_loc, *first, *count, v.get());
}

void GlDirect::ScissorIndexed(const GLuint& index, const GLint& left, const GLint& bottom, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&glScissorIndexed>(src_loc, *index, *left, *bottom, *width, *height);
}

void GlDirect::ScissorIndexedv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    return _callGL<&glScissorIndexedv>(src_loc, *index, v.get());
}

void GlDirect::ShaderBinary(const GLsizei& count, const GLuintArr& shaders, const GLenum& binaryFormat, const GLdata& binary, const GLsizei& length, const SrcLoc& src_loc){
    return _callGL<&glShaderBinary>(src_loc, *count, shaders.get(), *binaryFormat, binary.get(), *length);
}

void GlDirect::ShaderSource(const GLuint& shader, const GLsizei& count, const GLstringArr& strings, const GLintArr& lengths, const SrcLoc& src_loc){
    const char** ptrs = new const char*[*count];
    for (size_t i = 0; i < *count; ++i){
        ptrs[i] = (strings.get())[i].c_str();
    }
    _callGL<&glShaderSource>(src_loc, *shader, *count, ptrs, lengths.get());
    delete[] ptrs;
}

void GlDirect::ShaderStorageBlockBinding(const GLuint& program, const GLuint& storageBlockIndex, const GLuint& storageBlockBinding, const SrcLoc& src_loc){
    return _callGL<&glShaderStorageBlockBinding>(src_loc, *program, *storageBlockIndex, *storageBlockBinding);
}

void GlDirect::SpecializeShader(const GLuint& shader, const GLstring& pEntryPoint, const GLuint& numSpecializationConstants, const GLuintArr& pConstantIndex, const GLuintArr& pConstantValue, const SrcLoc& src_loc){
    return _callGL<&glSpecializeShader>(src_loc, *shader, pEntryPoint->c_str(), *numSpecializationConstants, pConstantIndex.get(), pConstantValue.get());
}

void GlDirect::StencilFunc(const GLenum& func, const GLint& ref, const GLuint& mask, const SrcLoc& src_loc){
    return _callGL<&glStencilFunc>(src_loc, *func, *ref, *mask);
}

void GlDirect::StencilFuncSeparate(const GLenum& face, const GLenum& func, const GLint& ref, const GLuint& mask, const SrcLoc& src_loc){
    return _callGL<&glStencilFuncSeparate>(src_loc, *face, *func, *ref, *mask);
}

void GlDirect::StencilMask(const GLuint& mask, const SrcLoc& src_loc){
    return _callGL<&glStencilMask>(src_loc, *mask);
}

void GlDirect::StencilMaskSeparate(const GLenum& face, const GLuint& mask, const SrcLoc& src_loc){
    return _callGL<&glStencilMaskSeparate>(src_loc, *face, *mask);
}

void GlDirect::StencilOp(const GLenum& fail, const GLenum& zfail, const GLenum& zpass, const SrcLoc& src_loc){
    return _callGL<&glStencilOp>(src_loc, *fail, *zfail, *zpass);
}

void GlDirect::StencilOpSeparate(const GLenum& face, const GLenum& sfail, const GLenum& dpfail, const GLenum& dppass, const SrcLoc& src_loc){
    return _callGL<&glStencilOpSeparate>(src_loc, *face, *sfail, *dpfail, *dppass);
}

void GlDirect::TexBuffer(const GLenum& target, const GLenum& internalformat, const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&glTexBuffer>(src_loc, *target, *internalformat, *buffer);
}

void GlDirect::TexBufferRange(const GLenum& target, const GLenum& internalformat, const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&glTexBufferRange>(src_loc, *target, *internalformat, *buffer, *offset, *size);
}

void GlDirect::TexImage1D(const GLenum& target, const GLint& level, const GLint& internalformat, const GLsizei& width, const GLint& border, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glTexImage1D>(src_loc, *target, *level, *internalformat, *width, *border, *format, *type, pixels.get());
}

void GlDirect::TexImage2D(const GLenum& target, const GLint& level, const GLint& internalformat, const GLsizei& width, const GLsizei& height, const GLint& border, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glTexImage2D>(src_loc, *target, *level, *internalformat, *width, *height, *border, *format, *type, pixels.get());
}

void GlDirect::TexImage2DMultisample(const GLenum& target, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&glTexImage2DMultisample>(src_loc, *target, *samples, *internalformat, *width, *height, *fixedsamplelocations);
}

void GlDirect::TexImage3D(const GLenum& target, const GLint& level, const GLint& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLint& border, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glTexImage3D>(src_loc, *target, *level, *internalformat, *width, *height, *depth, *border, *format, *type, pixels.get());
}

void GlDirect::TexImage3DMultisample(const GLenum& target, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&glTexImage3DMultisample>(src_loc, *target, *samples, *internalformat, *width, *height, *depth, *fixedsamplelocations);
}

void GlDirect::TexParameterIiv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glTexParameterIiv>(src_loc, *target, *pname, params.get());
}

void GlDirect::TexParameterIuiv(const GLenum& target, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&glTexParameterIuiv>(src_loc, *target, *pname, params.get());
}

void GlDirect::TexParameterf(const GLenum& target, const GLenum& pname, const GLfloat& param, const SrcLoc& src_loc){
    return _callGL<&glTexParameterf>(src_loc, *target, *pname, *param);
}

void GlDirect::TexParameterfv(const GLenum& target, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    return _callGL<&glTexParameterfv>(src_loc, *target, *pname, params.get());
}

void GlDirect::TexParameteri(const GLenum& target, const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    return _callGL<&glTexParameteri>(src_loc, *target, *pname, *param);
}

void GlDirect::TexParameteriv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glTexParameteriv>(src_loc, *target, *pname, params.get());
}

void GlDirect::TexStorage1D(const GLenum& target, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const SrcLoc& src_loc){
    return _callGL<&glTexStorage1D>(src_loc, *target, *levels, *internalformat, *width);
}

void GlDirect::TexStorage2D(const GLenum& target, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&glTexStorage2D>(src_loc, *target, *levels, *internalformat, *width, *height);
}

void GlDirect::TexStorage2DMultisample(const GLenum& target, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&glTexStorage2DMultisample>(src_loc, *target, *samples, *internalformat, *width, *height, *fixedsamplelocations);
}

void GlDirect::TexStorage3D(const GLenum& target, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const SrcLoc& src_loc){
    return _callGL<&glTexStorage3D>(src_loc, *target, *levels, *internalformat, *width, *height, *depth);
}

void GlDirect::TexStorage3DMultisample(const GLenum& target, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&glTexStorage3DMultisample>(src_loc, *target, *samples, *internalformat, *width, *height, *depth, *fixedsamplelocations);
}

void GlDirect::TexSubImage1D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLsizei& width, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glTexSubImage1D>(src_loc, *target, *level, *xoffset, *width, *format, *type, pixels.get());
}

void GlDirect::TexSubImage2D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glTexSubImage2D>(src_loc, *target, *level, *xoffset, *yoffset, *width, *height, *format, *type, pixels.get());
}

void GlDirect::TexSubImage3D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glTexSubImage3D>(src_loc, *target, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *type, pixels.get());
}

void GlDirect::TextureBarrier(const SrcLoc& src_loc){
    return _callGL<&glTextureBarrier>(src_loc);
}

void GlDirect::TextureBuffer(const GLuint& texture, const GLenum& internalformat, const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&glTextureBuffer>(src_loc, *texture, *internalformat, *buffer);
}

void GlDirect::TextureBufferRange(const GLuint& texture, const GLenum& internalformat, const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&glTextureBufferRange>(src_loc, *texture, *internalformat, *buffer, *offset, *size);
}

void GlDirect::TextureParameterIiv(const GLuint& texture, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    return _callGL<&glTextureParameterIiv>(src_loc, *texture, *pname, params.get());
}

void GlDirect::TextureParameterIuiv(const GLuint& texture, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    return _callGL<&glTextureParameterIuiv>(src_loc, *texture, *pname, params.get());
}

void GlDirect::TextureParameterf(const GLuint& texture, const GLenum& pname, const GLfloat& param, const SrcLoc& src_loc){
    return _callGL<&glTextureParameterf>(src_loc, *texture, *pname, *param);
}

void GlDirect::TextureParameterfv(const GLuint& texture, const GLenum& pname, const GLfloatArr& param, const SrcLoc& src_loc){
    return _callGL<&glTextureParameterfv>(src_loc, *texture, *pname, param.get());
}

void GlDirect::TextureParameteri(const GLuint& texture, const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    return _callGL<&glTextureParameteri>(src_loc, *texture, *pname, *param);
}

void GlDirect::TextureParameteriv(const GLuint& texture, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    return _callGL<&glTextureParameteriv>(src_loc, *texture, *pname, param.get());
}

void GlDirect::TextureStorage1D(const GLuint& texture, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const SrcLoc& src_loc){
    return _callGL<&glTextureStorage1D>(src_loc, *texture, *levels, *internalformat, *width);
}

void GlDirect::TextureStorage2D(const GLuint& texture, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&glTextureStorage2D>(src_loc, *texture, *levels, *internalformat, *width, *height);
}

void GlDirect::TextureStorage2DMultisample(const GLuint& texture, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&glTextureStorage2DMultisample>(src_loc, *texture, *samples, *internalformat, *width, *height, *fixedsamplelocations);
}

void GlDirect::TextureStorage3D(const GLuint& texture, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const SrcLoc& src_loc){
    return _callGL<&glTextureStorage3D>(src_loc, *texture, *levels, *internalformat, *width, *height, *depth);
}

void GlDirect::TextureStorage3DMultisample(const GLuint& texture, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    return _callGL<&glTextureStorage3DMultisample>(src_loc, *texture, *samples, *internalformat, *width, *height, *depth, *fixedsamplelocations);
}

void GlDirect::TextureSubImage1D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLsizei& width, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glTextureSubImage1D>(src_loc, *texture, *level, *xoffset, *width, *format, *type, pixels.get());
}

void GlDirect::TextureSubImage2D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glTextureSubImage2D>(src_loc, *texture, *level, *xoffset, *yoffset, *width, *height, *format, *type, pixels.get());
}

void GlDirect::TextureSubImage3D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    return _callGL<&glTextureSubImage3D>(src_loc, *texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *type, pixels.get());
}

void GlDirect::TextureView(const GLuint& texture, const GLenum& target, const GLuint& origtexture, const GLenum& internalformat, const GLuint& minlevel, const GLuint& numlevels, const GLuint& minlayer, const GLuint& numlayers, const SrcLoc& src_loc){
    return _callGL<&glTextureView>(src_loc, *texture, *target, *origtexture, *internalformat, *minlevel, *numlevels, *minlayer, *numlayers);
}

void GlDirect::TransformFeedbackBufferBase(const GLuint& xfb, const GLuint& index, const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&glTransformFeedbackBufferBase>(src_loc, *xfb, *index, *buffer);
}

void GlDirect::TransformFeedbackBufferRange(const GLuint& xfb, const GLuint& index, const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const SrcLoc& src_loc){
    return _callGL<&glTransformFeedbackBufferRange>(src_loc, *xfb, *index, *buffer, *offset, *size);
}

void GlDirect::Uniform1d(const GLint& location, const GLdouble& x, const SrcLoc& src_loc){
    return _callGL<&glUniform1d>(src_loc, *location, *x);
}

void GlDirect::Uniform1dv(const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform1dv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform1f(const GLint& location, const GLfloat& v0, const SrcLoc& src_loc){
    return _callGL<&glUniform1f>(src_loc, *location, *v0);
}

void GlDirect::Uniform1fv(const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform1fv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform1i(const GLint& location, const GLint& v0, const SrcLoc& src_loc){
    return _callGL<&glUniform1i>(src_loc, *location, *v0);
}

void GlDirect::Uniform1iv(const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform1iv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform1ui(const GLint& location, const GLuint& v0, const SrcLoc& src_loc){
    return _callGL<&glUniform1ui>(src_loc, *location, *v0);
}

void GlDirect::Uniform1uiv(const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform1uiv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform2d(const GLint& location, const GLdouble& x, const GLdouble& y, const SrcLoc& src_loc){
    return _callGL<&glUniform2d>(src_loc, *location, *x, *y);
}

void GlDirect::Uniform2dv(const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform2dv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform2f(const GLint& location, const GLfloat& v0, const GLfloat& v1, const SrcLoc& src_loc){
    return _callGL<&glUniform2f>(src_loc, *location, *v0, *v1);
}

void GlDirect::Uniform2fv(const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform2fv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform2i(const GLint& location, const GLint& v0, const GLint& v1, const SrcLoc& src_loc){
    return _callGL<&glUniform2i>(src_loc, *location, *v0, *v1);
}

void GlDirect::Uniform2iv(const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform2iv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform2ui(const GLint& location, const GLuint& v0, const GLuint& v1, const SrcLoc& src_loc){
    return _callGL<&glUniform2ui>(src_loc, *location, *v0, *v1);
}

void GlDirect::Uniform2uiv(const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform2uiv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform3d(const GLint& location, const GLdouble& x, const GLdouble& y, const GLdouble& z, const SrcLoc& src_loc){
    return _callGL<&glUniform3d>(src_loc, *location, *x, *y, *z);
}

void GlDirect::Uniform3dv(const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform3dv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform3f(const GLint& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const SrcLoc& src_loc){
    return _callGL<&glUniform3f>(src_loc, *location, *v0, *v1, *v2);
}

void GlDirect::Uniform3fv(const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform3fv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform3i(const GLint& location, const GLint& v0, const GLint& v1, const GLint& v2, const SrcLoc& src_loc){
    return _callGL<&glUniform3i>(src_loc, *location, *v0, *v1, *v2);
}

void GlDirect::Uniform3iv(const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform3iv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform3ui(const GLint& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const SrcLoc& src_loc){
    return _callGL<&glUniform3ui>(src_loc, *location, *v0, *v1, *v2);
}

void GlDirect::Uniform3uiv(const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform3uiv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform4d(const GLint& location, const GLdouble& x, const GLdouble& y, const GLdouble& z, const GLdouble& w, const SrcLoc& src_loc){
    return _callGL<&glUniform4d>(src_loc, *location, *x, *y, *z, *w);
}

void GlDirect::Uniform4dv(const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform4dv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform4f(const GLint& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const GLfloat& v3, const SrcLoc& src_loc){
    return _callGL<&glUniform4f>(src_loc, *location, *v0, *v1, *v2, *v3);
}

void GlDirect::Uniform4fv(const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform4fv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform4i(const GLint& location, const GLint& v0, const GLint& v1, const GLint& v2, const GLint& v3, const SrcLoc& src_loc){
    return _callGL<&glUniform4i>(src_loc, *location, *v0, *v1, *v2, *v3);
}

void GlDirect::Uniform4iv(const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform4iv>(src_loc, *location, *count, value.get());
}

void GlDirect::Uniform4ui(const GLint& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const GLuint& v3, const SrcLoc& src_loc){
    return _callGL<&glUniform4ui>(src_loc, *location, *v0, *v1, *v2, *v3);
}

void GlDirect::Uniform4uiv(const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniform4uiv>(src_loc, *location, *count, value.get());
}

void GlDirect::UniformBlockBinding(const GLuint& program, const GLuint& uniformBlockIndex, const GLuint& uniformBlockBinding, const SrcLoc& src_loc){
    return _callGL<&glUniformBlockBinding>(src_loc, *program, *uniformBlockIndex, *uniformBlockBinding);
}

void GlDirect::UniformMatrix2dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix2dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix2fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix2fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix2x3dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix2x3dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix2x3fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix2x3fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix2x4dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix2x4dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix2x4fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix2x4fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix3dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix3dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix3fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix3fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix3x2dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix3x2dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix3x2fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix3x2fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix3x4dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix3x4dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix3x4fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix3x4fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix4dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix4dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix4fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix4fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix4x2dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix4x2dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix4x2fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix4x2fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix4x3dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix4x3dv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformMatrix4x3fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    return _callGL<&glUniformMatrix4x3fv>(src_loc, *location, *count, *transpose, value.get());
}

void GlDirect::UniformSubroutinesuiv(const GLenum& shadertype, const GLsizei& count, const GLuintArr& indices, const SrcLoc& src_loc){
    return _callGL<&glUniformSubroutinesuiv>(src_loc, *shadertype, *count, indices.get());
}

GL::GLboolean GlDirect::UnmapBuffer(const GLenum& target, const SrcLoc& src_loc){
    return _callGL<&glUnmapBuffer>(src_loc, *target);
}

GL::GLboolean GlDirect::UnmapNamedBuffer(const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&glUnmapNamedBuffer>(src_loc, *buffer);
}

void GlDirect::UseProgram(const GLuint& program, const SrcLoc& src_loc){
    return _callGL<&glUseProgram>(src_loc, *program);
}

void GlDirect::UseProgramStages(const GLuint& pipeline, const GLbitfield& stages, const GLuint& program, const SrcLoc& src_loc){
    return _callGL<&glUseProgramStages>(src_loc, *pipeline, *stages, *program);
}

void GlDirect::ValidateProgram(const GLuint& program, const SrcLoc& src_loc){
    return _callGL<&glValidateProgram>(src_loc, *program);
}

void GlDirect::ValidateProgramPipeline(const GLuint& pipeline, const SrcLoc& src_loc){
    return _callGL<&glValidateProgramPipeline>(src_loc, *pipeline);
}

void GlDirect::VertexArrayAttribBinding(const GLuint& vaobj, const GLuint& attribindex, const GLuint& bindingindex, const SrcLoc& src_loc){
    return _callGL<&glVertexArrayAttribBinding>(src_loc, *vaobj, *attribindex, *bindingindex);
}

void GlDirect::VertexArrayAttribFormat(const GLuint& vaobj, const GLuint& attribindex, const GLint& size, const GLenum& type, const GLboolean& normalized, const GLuint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&glVertexArrayAttribFormat>(src_loc, *vaobj, *attribindex, *size, *type, *normalized, *relativeoffset);
}

void GlDirect::VertexArrayAttribIFormat(const GLuint& vaobj, const GLuint& attribindex, const GLint& size, const GLenum& type, const GLuint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&glVertexArrayAttribIFormat>(src_loc, *vaobj, *attribindex, *size, *type, *relativeoffset);
}

void GlDirect::VertexArrayAttribLFormat(const GLuint& vaobj, const GLuint& attribindex, const GLint& size, const GLenum& type, const GLuint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&glVertexArrayAttribLFormat>(src_loc, *vaobj, *attribindex, *size, *type, *relativeoffset);
}

void GlDirect::VertexArrayBindingDivisor(const GLuint& vaobj, const GLuint& bindingindex, const GLuint& divisor, const SrcLoc& src_loc){
    return _callGL<&glVertexArrayBindingDivisor>(src_loc, *vaobj, *bindingindex, *divisor);
}

void GlDirect::VertexArrayElementBuffer(const GLuint& vaobj, const GLuint& buffer, const SrcLoc& src_loc){
    return _callGL<&glVertexArrayElementBuffer>(src_loc, *vaobj, *buffer);
}

void GlDirect::VertexArrayVertexBuffer(const GLuint& vaobj, const GLuint& bindingindex, const GLuint& buffer, const GLintptr& offset, const GLsizei& stride, const SrcLoc& src_loc){
    return _callGL<&glVertexArrayVertexBuffer>(src_loc, *vaobj, *bindingindex, *buffer, *offset, *stride);
}

void GlDirect::VertexArrayVertexBuffers(const GLuint& vaobj, const GLuint& first, const GLsizei& count, const GLuintArr& buffers, const GLintptrArr& offsets, const GLsizeiArr& strides, const SrcLoc& src_loc){
    return _callGL<&glVertexArrayVertexBuffers>(src_loc, *vaobj, *first, *count, buffers.get(), offsets.get(), strides.get());
}

void GlDirect::VertexAttrib1d(const GLuint& index, const GLdouble& x, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib1d>(src_loc, *index, *x);
}

void GlDirect::VertexAttrib1dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib1dv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib1f(const GLuint& index, const GLfloat& x, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib1f>(src_loc, *index, *x);
}

void GlDirect::VertexAttrib1fv(const GLuint& index, const GLfloatArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib1fv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib1s(const GLuint& index, const GLshort& x, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib1s>(src_loc, *index, *x);
}

void GlDirect::VertexAttrib1sv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib1sv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib2d(const GLuint& index, const GLdouble& x, const GLdouble& y, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib2d>(src_loc, *index, *x, *y);
}

void GlDirect::VertexAttrib2dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib2dv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib2f(const GLuint& index, const GLfloat& x, const GLfloat& y, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib2f>(src_loc, *index, *x, *y);
}

void GlDirect::VertexAttrib2fv(const GLuint& index, const GLfloatArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib2fv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib2s(const GLuint& index, const GLshort& x, const GLshort& y, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib2s>(src_loc, *index, *x, *y);
}

void GlDirect::VertexAttrib2sv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib2sv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib3d(const GLuint& index, const GLdouble& x, const GLdouble& y, const GLdouble& z, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib3d>(src_loc, *index, *x, *y, *z);
}

void GlDirect::VertexAttrib3dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib3dv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib3f(const GLuint& index, const GLfloat& x, const GLfloat& y, const GLfloat& z, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib3f>(src_loc, *index, *x, *y, *z);
}

void GlDirect::VertexAttrib3fv(const GLuint& index, const GLfloatArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib3fv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib3s(const GLuint& index, const GLshort& x, const GLshort& y, const GLshort& z, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib3s>(src_loc, *index, *x, *y, *z);
}

void GlDirect::VertexAttrib3sv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib3sv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4Nbv(const GLuint& index, const GLbyte& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4Nbv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4Niv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4Niv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4Nsv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4Nsv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4Nub(const GLuint& index, const GLubyte& x, const GLubyte& y, const GLubyte& z, const GLubyte& w, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4Nub>(src_loc, *index, *x, *y, *z, *w);
}

void GlDirect::VertexAttrib4Nubv(const GLuint& index, const GLubyte& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4Nubv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4Nuiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4Nuiv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4Nusv(const GLuint& index, const GLushort& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4Nusv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4bv(const GLuint& index, const GLbyte& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4bv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4d(const GLuint& index, const GLdouble& x, const GLdouble& y, const GLdouble& z, const GLdouble& w, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4d>(src_loc, *index, *x, *y, *z, *w);
}

void GlDirect::VertexAttrib4dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4dv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4f(const GLuint& index, const GLfloat& x, const GLfloat& y, const GLfloat& z, const GLfloat& w, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4f>(src_loc, *index, *x, *y, *z, *w);
}

void GlDirect::VertexAttrib4fv(const GLuint& index, const GLfloatArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4fv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4iv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4iv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4s(const GLuint& index, const GLshort& x, const GLshort& y, const GLshort& z, const GLshort& w, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4s>(src_loc, *index, *x, *y, *z, *w);
}

void GlDirect::VertexAttrib4sv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4sv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4ubv(const GLuint& index, const GLubyte& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4ubv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4uiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4uiv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttrib4usv(const GLuint& index, const GLushort& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttrib4usv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribBinding(const GLuint& attribindex, const GLuint& bindingindex, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribBinding>(src_loc, *attribindex, *bindingindex);
}

void GlDirect::VertexAttribDivisor(const GLuint& index, const GLuint& divisor, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribDivisor>(src_loc, *index, *divisor);
}

void GlDirect::VertexAttribFormat(const GLuint& attribindex, const GLint& size, const GLenum& type, const GLboolean& normalized, const GLuint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribFormat>(src_loc, *attribindex, *size, *type, *normalized, *relativeoffset);
}

void GlDirect::VertexAttribI1i(const GLuint& index, const GLint& x, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI1i>(src_loc, *index, *x);
}

void GlDirect::VertexAttribI1iv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI1iv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI1ui(const GLuint& index, const GLuint& x, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI1ui>(src_loc, *index, *x);
}

void GlDirect::VertexAttribI1uiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI1uiv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI2i(const GLuint& index, const GLint& x, const GLint& y, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI2i>(src_loc, *index, *x, *y);
}

void GlDirect::VertexAttribI2iv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI2iv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI2ui(const GLuint& index, const GLuint& x, const GLuint& y, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI2ui>(src_loc, *index, *x, *y);
}

void GlDirect::VertexAttribI2uiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI2uiv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI3i(const GLuint& index, const GLint& x, const GLint& y, const GLint& z, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI3i>(src_loc, *index, *x, *y, *z);
}

void GlDirect::VertexAttribI3iv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI3iv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI3ui(const GLuint& index, const GLuint& x, const GLuint& y, const GLuint& z, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI3ui>(src_loc, *index, *x, *y, *z);
}

void GlDirect::VertexAttribI3uiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI3uiv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI4bv(const GLuint& index, const GLbyte& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI4bv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI4i(const GLuint& index, const GLint& x, const GLint& y, const GLint& z, const GLint& w, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI4i>(src_loc, *index, *x, *y, *z, *w);
}

void GlDirect::VertexAttribI4iv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI4iv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI4sv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI4sv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI4ubv(const GLuint& index, const GLubyte& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI4ubv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI4ui(const GLuint& index, const GLuint& x, const GLuint& y, const GLuint& z, const GLuint& w, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI4ui>(src_loc, *index, *x, *y, *z, *w);
}

void GlDirect::VertexAttribI4uiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI4uiv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribI4usv(const GLuint& index, const GLushort& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribI4usv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribIFormat(const GLuint& attribindex, const GLint& size, const GLenum& type, const GLuint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribIFormat>(src_loc, *attribindex, *size, *type, *relativeoffset);
}

void GlDirect::VertexAttribIPointer(const GLuint& index, const GLint& size, const GLenum& type, const GLsizei& stride, const GLdata& pointer, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribIPointer>(src_loc, *index, *size, *type, *stride, pointer.get());
}

void GlDirect::VertexAttribL1d(const GLuint& index, const GLdouble& x, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribL1d>(src_loc, *index, *x);
}

void GlDirect::VertexAttribL1dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribL1dv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribL2d(const GLuint& index, const GLdouble& x, const GLdouble& y, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribL2d>(src_loc, *index, *x, *y);
}

void GlDirect::VertexAttribL2dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribL2dv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribL3d(const GLuint& index, const GLdouble& x, const GLdouble& y, const GLdouble& z, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribL3d>(src_loc, *index, *x, *y, *z);
}

void GlDirect::VertexAttribL3dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribL3dv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribL4d(const GLuint& index, const GLdouble& x, const GLdouble& y, const GLdouble& z, const GLdouble& w, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribL4d>(src_loc, *index, *x, *y, *z, *w);
}

void GlDirect::VertexAttribL4dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribL4dv>(src_loc, *index, v.get());
}

void GlDirect::VertexAttribLFormat(const GLuint& attribindex, const GLint& size, const GLenum& type, const GLuint& relativeoffset, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribLFormat>(src_loc, *attribindex, *size, *type, *relativeoffset);
}

void GlDirect::VertexAttribLPointer(const GLuint& index, const GLint& size, const GLenum& type, const GLsizei& stride, const GLdata& pointer, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribLPointer>(src_loc, *index, *size, *type, *stride, pointer.get());
}

void GlDirect::VertexAttribP1ui(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuint& value, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribP1ui>(src_loc, *index, *type, *normalized, *value);
}

void GlDirect::VertexAttribP1uiv(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribP1uiv>(src_loc, *index, *type, *normalized, value.get());
}

void GlDirect::VertexAttribP2ui(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuint& value, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribP2ui>(src_loc, *index, *type, *normalized, *value);
}

void GlDirect::VertexAttribP2uiv(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribP2uiv>(src_loc, *index, *type, *normalized, value.get());
}

void GlDirect::VertexAttribP3ui(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuint& value, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribP3ui>(src_loc, *index, *type, *normalized, *value);
}

void GlDirect::VertexAttribP3uiv(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribP3uiv>(src_loc, *index, *type, *normalized, value.get());
}

void GlDirect::VertexAttribP4ui(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuint& value, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribP4ui>(src_loc, *index, *type, *normalized, *value);
}

void GlDirect::VertexAttribP4uiv(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuintArr& value, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribP4uiv>(src_loc, *index, *type, *normalized, value.get());
}

void GlDirect::VertexAttribPointer(const GLuint& index, const GLint& size, const GLenum& type, const GLboolean& normalized, const GLsizei& stride, const GLdata& pointer, const SrcLoc& src_loc){
    return _callGL<&glVertexAttribPointer>(src_loc, *index, *size, *type, *normalized, *stride, pointer.get());
}

void GlDirect::VertexBindingDivisor(const GLuint& bindingindex, const GLuint& divisor, const SrcLoc& src_loc){
    return _callGL<&glVertexBindingDivisor>(src_loc, *bindingindex, *divisor);
}

void GlDirect::Viewport(const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    return _callGL<&glViewport>(src_loc, *x, *y, *width, *height);
}

void GlDirect::ViewportArrayv(const GLuint& first, const GLsizei& count, const GLfloatArr& v, const SrcLoc& src_loc){
    return _callGL<&glViewportArrayv>(src_loc, *first, *count, v.get());
}

void GlDirect::ViewportIndexedf(const GLuint& index, const GLfloat& x, const GLfloat& y, const GLfloat& w, const GLfloat& h, const SrcLoc& src_loc){
    return _callGL<&glViewportIndexedf>(src_loc, *index, *x, *y, *w, *h);
}

void GlDirect::ViewportIndexedfv(const GLuint& index, const GLfloatArr& v, const SrcLoc& src_loc){
    return _callGL<&glViewportIndexedfv>(src_loc, *index, v.get());
}

void GlDirect::WaitSync(const GLsync& sync, const GLbitfield& flags, const GLuint64& timeout, const SrcLoc& src_loc){
    return _callGL<&glWaitSync>(src_loc, *sync, *flags, *timeout);
}