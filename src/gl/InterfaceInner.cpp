#include "gl/InterfaceInner.hpp"

#include <string.h>
#include "glad/gl.h"

using namespace glwpp;
using namespace GL;

InterfaceInner::InterfaceInner(Context& ctx, const std::function<void(const SrcLoc&)> debug) :
    Interface(ctx, debug){
}

InterfaceInner::~InterfaceInner(){
}

void InterfaceInner::ActiveShaderProgram(const GLuint& pipeline, const GLuint& program, const SrcLoc& src_loc){
    glActiveShaderProgram(*pipeline, *program);
    _debug(src_loc);
}

void InterfaceInner::ActiveTexture(const GLenum& texture, const SrcLoc& src_loc){
    glActiveTexture(*texture);
    _debug(src_loc);
}

void InterfaceInner::AttachShader(const GLuint& program, const GLuint& shader, const SrcLoc& src_loc){
    glAttachShader(*program, *shader);
    _debug(src_loc);
}

void InterfaceInner::BeginConditionalRender(const GLuint& id, const GLenum& mode, const SrcLoc& src_loc){
    glBeginConditionalRender(*id, *mode);
    _debug(src_loc);
}

void InterfaceInner::BeginQuery(const GLenum& target, const GLuint& id, const SrcLoc& src_loc){
    glBeginQuery(*target, *id);
    _debug(src_loc);
}

void InterfaceInner::BeginQueryIndexed(const GLenum& target, const GLuint& index, const GLuint& id, const SrcLoc& src_loc){
    glBeginQueryIndexed(*target, *index, *id);
    _debug(src_loc);
}

void InterfaceInner::BeginTransformFeedback(const GLenum& primitiveMode, const SrcLoc& src_loc){
    glBeginTransformFeedback(*primitiveMode);
    _debug(src_loc);
}

void InterfaceInner::BindAttribLocation(const GLuint& program, const GLuint& index, const GLcharArr& name, const SrcLoc& src_loc){
    glBindAttribLocation(*program, *index, name.get());
    _debug(src_loc);
}

void InterfaceInner::BindBuffer(const GLenum& target, const GLuint& buffer, const SrcLoc& src_loc){
    glBindBuffer(*target, *buffer);
    _debug(src_loc);
}

void InterfaceInner::BindBufferBase(const GLenum& target, const GLuint& index, const GLuint& buffer, const SrcLoc& src_loc){
    glBindBufferBase(*target, *index, *buffer);
    _debug(src_loc);
}

void InterfaceInner::BindBufferRange(const GLenum& target, const GLuint& index, const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const SrcLoc& src_loc){
    glBindBufferRange(*target, *index, *buffer, *offset, *size);
    _debug(src_loc);
}

void InterfaceInner::BindBuffersBase(const GLenum& target, const GLuint& first, const GLsizei& count, const GLuintArr& buffers, const SrcLoc& src_loc){
    glBindBuffersBase(*target, *first, *count, buffers.get());
    _debug(src_loc);
}

void InterfaceInner::BindBuffersRange(const GLenum& target, const GLuint& first, const GLsizei& count, const GLuintArr& buffers, const GLintptrArr& offsets, const GLsizeiptrArr& sizes, const SrcLoc& src_loc){
    glBindBuffersRange(*target, *first, *count, buffers.get(), offsets.get(), sizes.get());
    _debug(src_loc);
}

void InterfaceInner::BindFragDataLocation(const GLuint& program, const GLuint& color, const GLcharArr& name, const SrcLoc& src_loc){
    glBindFragDataLocation(*program, *color, name.get());
    _debug(src_loc);
}

void InterfaceInner::BindFragDataLocationIndexed(const GLuint& program, const GLuint& colorNumber, const GLuint& index, const GLcharArr& name, const SrcLoc& src_loc){
    glBindFragDataLocationIndexed(*program, *colorNumber, *index, name.get());
    _debug(src_loc);
}

void InterfaceInner::BindFramebuffer(const GLenum& target, const GLuint& framebuffer, const SrcLoc& src_loc){
    glBindFramebuffer(*target, *framebuffer);
    _debug(src_loc);
}

void InterfaceInner::BindImageTexture(const GLuint& unit, const GLuint& texture, const GLint& level, const GLboolean& layered, const GLint& layer, const GLenum& access, const GLenum& format, const SrcLoc& src_loc){
    glBindImageTexture(*unit, *texture, *level, *layered, *layer, *access, *format);
    _debug(src_loc);
}

void InterfaceInner::BindImageTextures(const GLuint& first, const GLsizei& count, const GLuintArr& textures, const SrcLoc& src_loc){
    glBindImageTextures(*first, *count, textures.get());
    _debug(src_loc);
}

void InterfaceInner::BindProgramPipeline(const GLuint& pipeline, const SrcLoc& src_loc){
    glBindProgramPipeline(*pipeline);
    _debug(src_loc);
}

void InterfaceInner::BindRenderbuffer(const GLenum& target, const GLuint& renderbuffer, const SrcLoc& src_loc){
    glBindRenderbuffer(*target, *renderbuffer);
    _debug(src_loc);
}

void InterfaceInner::BindSampler(const GLuint& unit, const GLuint& sampler, const SrcLoc& src_loc){
    glBindSampler(*unit, *sampler);
    _debug(src_loc);
}

void InterfaceInner::BindSamplers(const GLuint& first, const GLsizei& count, const GLuintArr& samplers, const SrcLoc& src_loc){
    glBindSamplers(*first, *count, samplers.get());
    _debug(src_loc);
}

void InterfaceInner::BindTexture(const GLenum& target, const GLuint& texture, const SrcLoc& src_loc){
    glBindTexture(*target, *texture);
    _debug(src_loc);
}

void InterfaceInner::BindTextureUnit(const GLuint& unit, const GLuint& texture, const SrcLoc& src_loc){
    glBindTextureUnit(*unit, *texture);
    _debug(src_loc);
}

void InterfaceInner::BindTextures(const GLuint& first, const GLsizei& count, const GLuintArr& textures, const SrcLoc& src_loc){
    glBindTextures(*first, *count, textures.get());
    _debug(src_loc);
}

void InterfaceInner::BindTransformFeedback(const GLenum& target, const GLuint& id, const SrcLoc& src_loc){
    glBindTransformFeedback(*target, *id);
    _debug(src_loc);
}

void InterfaceInner::BindVertexArray(const GLuint& array, const SrcLoc& src_loc){
    glBindVertexArray(*array);
    _debug(src_loc);
}

void InterfaceInner::BindVertexBuffer(const GLuint& bindingindex, const GLuint& buffer, const GLintptr& offset, const GLsizei& stride, const SrcLoc& src_loc){
    glBindVertexBuffer(*bindingindex, *buffer, *offset, *stride);
    _debug(src_loc);
}

void InterfaceInner::BindVertexBuffers(const GLuint& first, const GLsizei& count, const GLuintArr& buffers, const GLintptrArr& offsets, const GLsizeiArr& strides, const SrcLoc& src_loc){
    glBindVertexBuffers(*first, *count, buffers.get(), offsets.get(), strides.get());
    _debug(src_loc);
}

void InterfaceInner::BlendColor(const GLfloat& red, const GLfloat& green, const GLfloat& blue, const GLfloat& alpha, const SrcLoc& src_loc){
    glBlendColor(*red, *green, *blue, *alpha);
    _debug(src_loc);
}

void InterfaceInner::BlendEquation(const GLenum& mode, const SrcLoc& src_loc){
    glBlendEquation(*mode);
    _debug(src_loc);
}

void InterfaceInner::BlendEquationSeparate(const GLenum& modeRGB, const GLenum& modeAlpha, const SrcLoc& src_loc){
    glBlendEquationSeparate(*modeRGB, *modeAlpha);
    _debug(src_loc);
}

void InterfaceInner::BlendEquationSeparatei(const GLuint& buf, const GLenum& modeRGB, const GLenum& modeAlpha, const SrcLoc& src_loc){
    glBlendEquationSeparatei(*buf, *modeRGB, *modeAlpha);
    _debug(src_loc);
}

void InterfaceInner::BlendEquationi(const GLuint& buf, const GLenum& mode, const SrcLoc& src_loc){
    glBlendEquationi(*buf, *mode);
    _debug(src_loc);
}

void InterfaceInner::BlendFunc(const GLenum& sfactor, const GLenum& dfactor, const SrcLoc& src_loc){
    glBlendFunc(*sfactor, *dfactor);
    _debug(src_loc);
}

void InterfaceInner::BlendFuncSeparate(const GLenum& sfactorRGB, const GLenum& dfactorRGB, const GLenum& sfactorAlpha, const GLenum& dfactorAlpha, const SrcLoc& src_loc){
    glBlendFuncSeparate(*sfactorRGB, *dfactorRGB, *sfactorAlpha, *dfactorAlpha);
    _debug(src_loc);
}

void InterfaceInner::BlendFuncSeparatei(const GLuint& buf, const GLenum& srcRGB, const GLenum& dstRGB, const GLenum& srcAlpha, const GLenum& dstAlpha, const GLenum& modeAlpha, const SrcLoc& src_loc){
    glBlendFuncSeparatei(*buf, *srcRGB, *dstRGB, *srcAlpha, *dstAlpha);
    _debug(src_loc);
}

void InterfaceInner::BlendFunci(const GLuint& buf, const GLenum& src, const GLenum& dst, const SrcLoc& src_loc){
    glBlendFunci(*buf, *src, *dst);
    _debug(src_loc);
}

void InterfaceInner::BlitFramebuffer(const GLint& srcX0, const GLint& srcY0, const GLint& srcX1, const GLint& srcY1, const GLint& dstX0, const GLint& dstY0, const GLint& dstX1, const GLint& dstY1, const GLbitfield& mask, const GLenum& filter, const SrcLoc& src_loc){
    glBlitFramebuffer(*srcX0, *srcY0, *srcX1, *srcY1, *dstX0, *dstY0, *dstX1, *dstY1, *mask, *filter);
    _debug(src_loc);
}

void InterfaceInner::BlitNamedFramebuffer(const GLuint& readFramebuffer, const GLuint& drawFramebuffer, const GLint& srcX0, const GLint& srcY0, const GLint& srcX1, const GLint& srcY1, const GLint& dstX0, const GLint& dstY0, const GLint& dstX1, const GLint& dstY1, const GLbitfield& mask, const GLenum& filter, const SrcLoc& src_loc){
    glBlitNamedFramebuffer(*readFramebuffer, *drawFramebuffer, *srcX0, *srcY0, *srcX1, *srcY1, *dstX0, *dstY0, *dstX1, *dstY1, *mask, *filter);
    _debug(src_loc);
}

void InterfaceInner::BufferData(const GLenum& target, const GLsizeiptr& size, const GLdata& data, const GLenum& usage, const SrcLoc& src_loc){
    glBufferData(*target, *size, data.get(), *usage);
    _debug(src_loc);
}

void InterfaceInner::BufferStorage(const GLenum& target, const GLsizeiptr& size, const GLdata& data, const GLbitfield& flags, const SrcLoc& src_loc){
    glBufferStorage(*target, *size, data.get(), *flags);
    _debug(src_loc);
}

void InterfaceInner::BufferSubData(const GLenum& target, const GLintptr& offset, const GLsizeiptr& size, const GLdata& data, const SrcLoc& src_loc){
    glBufferSubData(*target, *offset, *size, data.get());
    _debug(src_loc);
}

void InterfaceInner::CheckFramebufferStatus(const GLenum& target, const SrcLoc& src_loc){
    glCheckFramebufferStatus(*target);
    _debug(src_loc);
}

void InterfaceInner::CheckNamedFramebufferStatus(const GLuint& framebuffer, const GLenum& target, const SrcLoc& src_loc){
    glCheckNamedFramebufferStatus(*framebuffer, *target);
    _debug(src_loc);
}

void InterfaceInner::ClampColor(const GLenum& target, const GLenum& clamp, const SrcLoc& src_loc){
    glClampColor(*target, *clamp);
    _debug(src_loc);
}

void InterfaceInner::Clear(const GLbitfield& mask, const SrcLoc& src_loc){
    glClear(*mask);
    _debug(src_loc);
}

void InterfaceInner::ClearBufferData(const GLenum& target, const GLenum& internalformat, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    glClearBufferData(*target, *internalformat, *format, *type, data.get());
    _debug(src_loc);
}

void InterfaceInner::ClearBufferSubData(const GLenum& target, const GLenum& internalformat, const GLintptr& offset, const GLsizeiptr& size, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    glClearBufferSubData(*target, *internalformat, *offset, *size, *format, *type, data.get());
    _debug(src_loc);
}

void InterfaceInner::ClearBufferfi(const GLenum& buffer, const GLint& drawbuffer, const GLfloat& depth, const GLint& stencil, const SrcLoc& src_loc){
    glClearBufferfi(*buffer, *drawbuffer, *depth, *stencil);
    _debug(src_loc);
}

void InterfaceInner::ClearBufferfv(const GLenum& buffer, const GLint& drawbuffer, const GLfloatArr& value, const SrcLoc& src_loc){
    glClearBufferfv(*buffer, *drawbuffer, value.get());
    _debug(src_loc);
}

void InterfaceInner::ClearBufferiv(const GLenum& buffer, const GLint& drawbuffer, const GLintArr& value, const SrcLoc& src_loc){
    glClearBufferiv(*buffer, *drawbuffer, value.get());
    _debug(src_loc);
}

void InterfaceInner::ClearBufferuiv(const GLenum& buffer, const GLint& drawbuffer, const GLuintArr& value, const SrcLoc& src_loc){
    glClearBufferuiv(*buffer, *drawbuffer, value.get());
    _debug(src_loc);
}

void InterfaceInner::ClearColor(const GLfloat& red, const GLfloat& green, const GLfloat& blue, const GLfloat& alpha, const SrcLoc& src_loc){
    glClearColor(*red, *green, *blue, *alpha);
    _debug(src_loc);
}

void InterfaceInner::ClearDepth(const GLdouble& depth, const SrcLoc& src_loc){
    glClearDepth(*depth);
    _debug(src_loc);
}

void InterfaceInner::ClearDepthf(const GLfloat& d, const SrcLoc& src_loc){
    glClearDepthf(*d);
    _debug(src_loc);
}

void InterfaceInner::ClearNamedBufferData(const GLuint& buffer, const GLenum& internalformat, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    glClearNamedBufferData(*buffer, *internalformat, *format, *type, data.get());
    _debug(src_loc);
}

void InterfaceInner::ClearNamedBufferSubData(const GLuint& buffer, const GLenum& internalformat, const GLintptr& offset, const GLsizeiptr& size, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    glClearNamedBufferSubData(*buffer, *internalformat, *offset, *size, *format, *type, data.get());
    _debug(src_loc);
}

void InterfaceInner::ClearNamedFramebufferfi(const GLuint& framebuffer, const GLenum& buffer, const GLint& drawbuffer, const GLfloat& depth, const GLint& stencil, const SrcLoc& src_loc){
    glClearNamedFramebufferfi(*framebuffer, *buffer, *drawbuffer, *depth, *stencil);
    _debug(src_loc);
}

void InterfaceInner::ClearNamedFramebufferfv(const GLuint& framebuffer, const GLenum& buffer, const GLint& drawbuffer, const GLfloatArr& value, const SrcLoc& src_loc){
    glClearNamedFramebufferfv(*framebuffer, *buffer, *drawbuffer, value.get());
    _debug(src_loc);
}

void InterfaceInner::ClearNamedFramebufferiv(const GLuint& framebuffer, const GLenum& buffer, const GLint& drawbuffer, const GLintArr& value, const SrcLoc& src_loc){
    glClearNamedFramebufferiv(*framebuffer, *buffer, *drawbuffer, value.get());
    _debug(src_loc);
}

void InterfaceInner::ClearNamedFramebufferuiv(const GLuint& framebuffer, const GLenum& buffer, const GLint& drawbuffer, const GLuintArr& value, const SrcLoc& src_loc){
    glClearNamedFramebufferuiv(*framebuffer, *buffer, *drawbuffer, value.get());
    _debug(src_loc);
}

void InterfaceInner::ClearStencil(const GLint& s, const SrcLoc& src_loc){
    glClearStencil(*s);
    _debug(src_loc);
}

void InterfaceInner::ClearTexImage(const GLuint& texture, const GLint& level, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    glClearTexImage(*texture, *level, *format, *type, data.get());
    _debug(src_loc);
}

void InterfaceInner::ClearTexSubImage(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    glClearTexSubImage(*texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *type, data.get());
    _debug(src_loc);
}

void InterfaceInner::ClientWaitSync(const GLsync& sync, const GLbitfield& flags, const GLuint64& timeout, const SrcLoc& src_loc){
    glClientWaitSync(*sync, *flags, *timeout);
    _debug(src_loc);
}

void InterfaceInner::ClipControl(const GLenum& origin, const GLenum& depth, const SrcLoc& src_loc){
    glClipControl(*origin, *depth);
    _debug(src_loc);
}

void InterfaceInner::ColorMask(const GLboolean& red, const GLboolean& green, const GLboolean& blue, const GLboolean& alpha, const SrcLoc& src_loc){
    glColorMask(*red, *green, *blue, *alpha);
    _debug(src_loc);
}

void InterfaceInner::ColorMaski(const GLuint& index, const GLboolean& r, const GLboolean& g, const GLboolean& b, const GLboolean& a, const SrcLoc& src_loc){
    glColorMaski(*index, *r, *g, *b, *a);
    _debug(src_loc);
}

void InterfaceInner::CompileShader(const GLuint& shader, const SrcLoc& src_loc){
    glCompileShader(*shader);
    _debug(src_loc);
}

void InterfaceInner::CompressedTexImage1D(const GLenum& target, const GLint& level, const GLenum& internalformat, const GLsizei& width, const GLint& border, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    glCompressedTexImage1D(*target, *level, *internalformat, *width, *border, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceInner::CompressedTexImage2D(const GLenum& target, const GLint& level, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLint& border, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    glCompressedTexImage2D(*target, *level, *internalformat, *width, *height, *border, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceInner::CompressedTexImage3D(const GLenum& target, const GLint& level, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLint& border, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    glCompressedTexImage3D(*target, *level, *internalformat, *width, *height, *depth, *border, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceInner::CompressedTexSubImage1D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLsizei& width, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    glCompressedTexSubImage1D(*target, *level, *xoffset, *width, *format, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceInner::CompressedTexSubImage2D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    glCompressedTexSubImage2D(*target, *level, *xoffset, *yoffset, *width, *height, *format, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceInner::CompressedTexSubImage3D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    glCompressedTexSubImage3D(*target, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceInner::CompressedTextureSubImage1D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLsizei& width, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    glCompressedTextureSubImage1D(*texture, *level, *xoffset, *width, *format, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceInner::CompressedTextureSubImage2D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    glCompressedTextureSubImage2D(*texture, *level, *xoffset, *yoffset, *width, *height, *format, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceInner::CompressedTextureSubImage3D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLsizei& imageSize, const GLdata& data, const SrcLoc& src_loc){
    glCompressedTextureSubImage3D(*texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceInner::CopyBufferSubData(const GLenum& readTarget, const GLenum& writeTarget, const GLintptr& readOffset, const GLintptr& writeOffset, const GLsizeiptr& size, const SrcLoc& src_loc){
    glCopyBufferSubData(*readTarget, *writeTarget, *readOffset, *writeOffset, *size);
    _debug(src_loc);
}

void InterfaceInner::CopyImageSubData(const GLuint& srcName, const GLenum& srcTarget, const GLint& srcLevel, const GLint& srcX, const GLint& srcY, const GLint& srcZ, const GLuint& dstName, const GLenum& dstTarget, const GLint& dstLevel, const GLint& dstX, const GLint& dstY, const GLint& dstZ, const GLsizei& srcWidth, const GLsizei& srcHeight, const GLsizei& srcDepth, const SrcLoc& src_loc){
    glCopyImageSubData(*srcName, *srcTarget, *srcLevel, *srcX, *srcY, *srcZ, *dstName, *dstTarget, *dstLevel, *dstX, *dstY, *dstZ, *srcWidth, *srcHeight, *srcDepth);
    _debug(src_loc);
}

void InterfaceInner::CopyNamedBufferSubData(const GLuint& readBuffer, const GLuint& writeBuffer, const GLintptr& readOffset, const GLintptr& writeOffset, const GLsizeiptr& size, const SrcLoc& src_loc){
    glCopyNamedBufferSubData(*readBuffer, *writeBuffer, *readOffset, *writeOffset, *size);
    _debug(src_loc);
}

void InterfaceInner::CopyTexImage1D(const GLenum& target, const GLint& level, const GLenum& internalformat, const GLint& x, const GLint& y, const GLsizei& width, const GLint& border, const SrcLoc& src_loc){
    glCopyTexImage1D(*target, *level, *internalformat, *x, *y, *width, *border);
    _debug(src_loc);
}

void InterfaceInner::CopyTexImage2D(const GLenum& target, const GLint& level, const GLenum& internalformat, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const GLint& border, const SrcLoc& src_loc){
    glCopyTexImage2D(*target, *level, *internalformat, *x, *y, *width, *height, *border);
    _debug(src_loc);
}

void InterfaceInner::CopyTexSubImage1D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& x, const GLint& y, const GLsizei& width, const SrcLoc& src_loc){
    glCopyTexSubImage1D(*target, *level, *xoffset, *x, *y, *width);
    _debug(src_loc);
}

void InterfaceInner::CopyTexSubImage2D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    glCopyTexSubImage2D(*target, *level, *xoffset, *yoffset, *x, *y, *width, *height);
    _debug(src_loc);
}

void InterfaceInner::CopyTexSubImage3D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    glCopyTexSubImage3D(*target, *level, *xoffset, *yoffset, *zoffset, *x, *y, *width, *height);
    _debug(src_loc);
}

void InterfaceInner::CopyTextureSubImage1D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& x, const GLint& y, const GLsizei& width, const SrcLoc& src_loc){
    glCopyTextureSubImage1D(*texture, *level, *xoffset, *x, *y, *width);
    _debug(src_loc);
}

void InterfaceInner::CopyTextureSubImage2D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    glCopyTextureSubImage2D(*texture, *level, *xoffset, *yoffset, *x, *y, *width, *height);
    _debug(src_loc);
}

void InterfaceInner::CopyTextureSubImage3D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    glCopyTextureSubImage3D(*texture, *level, *xoffset, *yoffset, *zoffset, *x, *y, *width, *height);
    _debug(src_loc);
}

void InterfaceInner::CreateBuffers(const GLsizei& n, const GLuintArr& dst, const SrcLoc& src_loc){
    glCreateBuffers(*n, dst.get());
    _debug(src_loc);
}

void InterfaceInner::CreateFramebuffers(const GLsizei& n, const GLuintArr& framebuffers, const SrcLoc& src_loc){
    glCreateFramebuffers(*n, framebuffers.get());
    _debug(src_loc);
}

const GLuintRes& InterfaceInner::CreateProgram(const SrcLoc& src_loc){
    const GLuintRes& dst(new const GLuintRes&::element_type(glCreateProgram()));
    _debug(src_loc);
    return dst;
}

void InterfaceInner::CreateProgramPipelines(const GLsizei& n, const GLuintArr& pipelines, const SrcLoc& src_loc){
    glCreateProgramPipelines(*n, pipelines.get());
    _debug(src_loc);
}

void InterfaceInner::CreateQueries(const GLenum& target, const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    glCreateQueries(*target, *n, ids.get());
    _debug(src_loc);
}

void InterfaceInner::CreateRenderbuffers(const GLsizei& n, const GLuintArr& renderbuffers, const SrcLoc& src_loc){
    glCreateRenderbuffers(*n, renderbuffers.get());
    _debug(src_loc);
}

void InterfaceInner::CreateSamplers(const GLsizei& n, const GLuintArr& samplers, const SrcLoc& src_loc){
    glCreateSamplers(*n, samplers.get());
    _debug(src_loc);
}

const GLuintRes& InterfaceInner::CreateShader(const GLenum& type, const SrcLoc& src_loc){
    const GLuintRes& dst(new const GLuintRes&::element_type(glCreateShader(*type)));
    _debug(src_loc);
    return dst;
}

void InterfaceInner::CreateTextures(const GLenum& target, const GLsizei& n, const GLuintArr& textures, const SrcLoc& src_loc){
    glCreateTextures(*target, *n, textures.get());
    _debug(src_loc);
}

void InterfaceInner::CreateTransformFeedbacks(const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    glCreateTransformFeedbacks(*n, ids.get());
    _debug(src_loc);
}

void InterfaceInner::CreateVertexArrays(const GLsizei& n, const GLuintArr& arrays, const SrcLoc& src_loc){
    glCreateVertexArrays(*n, arrays.get());
    _debug(src_loc);
}

void InterfaceInner::CullFace(const GLenum& mode, const SrcLoc& src_loc){
    glCullFace(*mode);
    _debug(src_loc);
}

// void InterfaceGlInner::DebugMessageCallback(const GLDEBUGPROC& callback, const GLdata& userParam, const SrcLoc& src_loc){
//     glDebugMessageCallback(*callback, userParam.get());
//     _debug(src_loc);
// }

void InterfaceInner::DebugMessageControl(const GLenum& source, const GLenum& type, const GLenum& severity, const GLsizei& count, const GLuintArr& ids, const GLboolean& enabled, const SrcLoc& src_loc){
    glDebugMessageControl(*source, *type, *severity, *count, ids.get(), *enabled);
    _debug(src_loc);
}

void InterfaceInner::DebugMessageInsert(const GLenum& source, const GLenum& type, const GLuint& id, const GLenum& severity, const GLsizei& length, const GLcharArr& buf, const SrcLoc& src_loc){
    glDebugMessageInsert(*source, *type, *id, *severity, *length, buf.get());
    _debug(src_loc);
}

void InterfaceInner::DeleteBuffers(const GLsizei& n, const GLuintArr& buffers, const SrcLoc& src_loc){
    glDeleteBuffers(*n, buffers.get());
    _debug(src_loc);
}

void InterfaceInner::DeleteFramebuffers(const GLsizei& n, const GLuintArr& framebuffers, const SrcLoc& src_loc){
    glDeleteFramebuffers(*n, framebuffers.get());
    _debug(src_loc);
}

void InterfaceInner::DeleteProgram(const GLuint& program, const SrcLoc& src_loc){
    glDeleteProgram(*program);
    _debug(src_loc);
}

void InterfaceInner::DeleteProgramPipelines(const GLsizei& n, const GLuintArr& pipelines, const SrcLoc& src_loc){
    glDeleteProgramPipelines(*n, pipelines.get());
    _debug(src_loc);
}

void InterfaceInner::DeleteQueries(const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    glDeleteQueries(*n, ids.get());
    _debug(src_loc);
}

void InterfaceInner::DeleteRenderbuffers(const GLsizei& n, const GLuintArr& renderbuffers, const SrcLoc& src_loc){
    glDeleteRenderbuffers(*n, renderbuffers.get());
    _debug(src_loc);
}

void InterfaceInner::DeleteSamplers(const GLsizei& count, const GLuintArr& samplers, const SrcLoc& src_loc){
    glDeleteSamplers(*count, samplers.get());
    _debug(src_loc);
}

void InterfaceInner::DeleteShader(const GLuint& shader, const SrcLoc& src_loc){
    glDeleteShader(*shader);
    _debug(src_loc);
}

void InterfaceInner::DeleteSync(const GLsync& sync, const SrcLoc& src_loc){
    glDeleteSync(*sync);
    _debug(src_loc);
}

void InterfaceInner::DeleteTextures(const GLsizei& n, const GLuintArr& textures, const SrcLoc& src_loc){
    glDeleteTextures(*n, textures.get());
    _debug(src_loc);
}

void InterfaceInner::DeleteTransformFeedbacks(const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    glDeleteTransformFeedbacks(*n, ids.get());
    _debug(src_loc);
}

void InterfaceInner::DeleteVertexArrays(const GLsizei& n, const GLuintArr& arrays, const SrcLoc& src_loc){
    glDeleteVertexArrays(*n, arrays.get());
    _debug(src_loc);
}

void InterfaceInner::DepthFunc(const GLenum& func, const SrcLoc& src_loc){
    glDepthFunc(*func);
    _debug(src_loc);
}

void InterfaceInner::DepthMask(const GLboolean& flag, const SrcLoc& src_loc){
    glDepthMask(*flag);
    _debug(src_loc);
}

void InterfaceInner::DepthRange(const GLdouble& n, const GLdouble& f, const SrcLoc& src_loc){
    glDepthRange(*n, *f);
    _debug(src_loc);
}

void InterfaceInner::DepthRangeArrayv(const GLuint& first, const GLsizei& count, const GLdoubleArr& v, const SrcLoc& src_loc){
    glDepthRangeArrayv(*first, *count, v.get());
    _debug(src_loc);
}

void InterfaceInner::DepthRangeIndexed(const GLuint& index, const GLdouble& n, const GLdouble& f, const SrcLoc& src_loc){
    glDepthRangeIndexed(*index, *n, *f);
    _debug(src_loc);
}

void InterfaceInner::DepthRangef(const GLfloat& n, const GLfloat& f, const SrcLoc& src_loc){
    glDepthRangef(*n, *f);
    _debug(src_loc);
}

void InterfaceInner::DetachShader(const GLuint& program, const GLuint& shader, const SrcLoc& src_loc){
    glDetachShader(*program, *shader);
    _debug(src_loc);
}

void InterfaceInner::Disable(const GLenum& cap, const SrcLoc& src_loc){
    glDisable(*cap);
    _debug(src_loc);
}

void InterfaceInner::DisableVertexArrayAttrib(const GLuint& vaobj, const GLuint& index, const SrcLoc& src_loc){
    glDisableVertexArrayAttrib(*vaobj, *index);
    _debug(src_loc);
}

void InterfaceInner::DisableVertexAttribArray(const GLuint& index, const SrcLoc& src_loc){
    glDisableVertexAttribArray(*index);
    _debug(src_loc);
}

void InterfaceInner::Disablei(const GLenum& target, const GLuint& index, const SrcLoc& src_loc){
    glDisablei(*target, *index);
    _debug(src_loc);
}

void InterfaceInner::DispatchCompute(const GLuint& num_groups_x, const GLuint& num_groups_y, const GLuint& num_groups_z, const SrcLoc& src_loc){
    glDispatchCompute(*num_groups_x, *num_groups_y, *num_groups_z);
    _debug(src_loc);
}

void InterfaceInner::DispatchComputeIndirect(const GLintptr& indirect, const SrcLoc& src_loc){
    glDispatchComputeIndirect(*indirect);
    _debug(src_loc);
}

void InterfaceInner::DrawArrays(const GLenum& mode, const GLint& first, const GLsizei& count, const SrcLoc& src_loc){
    glDrawArrays(*mode, *first, *count);
    _debug(src_loc);
}

void InterfaceInner::DrawArraysIndirect(const GLenum& mode, const GLdata& indirect, const SrcLoc& src_loc){
    glDrawArraysIndirect(*mode, indirect.get());
    _debug(src_loc);
}

void InterfaceInner::DrawArraysInstanced(const GLenum& mode, const GLint& first, const GLsizei& count, const GLsizei& instancecount, const SrcLoc& src_loc){
    glDrawArraysInstanced(*mode, *first, *count, *instancecount);
    _debug(src_loc);
}

void InterfaceInner::DrawArraysInstancedBaseInstance(const GLenum& mode, const GLint& first, const GLsizei& count, const GLsizei& instancecount, const GLuint& baseinstance, const SrcLoc& src_loc){
    glDrawArraysInstancedBaseInstance(*mode, *first, *count, *instancecount, *instancecount);
    _debug(src_loc);
}

void InterfaceInner::DrawBuffer(const GLenum& buf, const SrcLoc& src_loc){
    glDrawBuffer(*buf);
    _debug(src_loc);
}

void InterfaceInner::DrawBuffers(const GLsizei& n, const GLenumArr& bufs, const SrcLoc& src_loc){
    glDrawBuffers(*n, bufs.get());
    _debug(src_loc);
}

void InterfaceInner::DrawElements(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const SrcLoc& src_loc){
    glDrawElements(*mode, *count, *type, indices.get());
    _debug(src_loc);
}

void InterfaceInner::DrawElementsBaseVertex(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLint& basevertex, const SrcLoc& src_loc){
    glDrawElementsBaseVertex(*mode, *count, *type, indices.get(), *basevertex);
    _debug(src_loc);
}

void InterfaceInner::DrawElementsIndirect(const GLenum& mode, const GLenum& type, const GLdata& indirect, const SrcLoc& src_loc){
    glDrawElementsIndirect(*mode, *type, indirect.get());
    _debug(src_loc);
}

void InterfaceInner::DrawElementsInstanced(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLsizei& instancecount, const SrcLoc& src_loc){
    glDrawElementsInstanced(*mode, *count, *type, indices.get(), *instancecount);
    _debug(src_loc);
}

void InterfaceInner::DrawElementsInstancedBaseInstance(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLsizei& instancecount, const GLuint& baseinstance, const SrcLoc& src_loc){
    glDrawElementsInstancedBaseInstance(*mode, *count, *type, indices.get(), *instancecount, *baseinstance);
    _debug(src_loc);
}

void InterfaceInner::DrawElementsInstancedBaseVertex(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLsizei& instancecount, const GLint& basevertex, const SrcLoc& src_loc){
    glDrawElementsInstancedBaseVertex(*mode, *count, *type, indices.get(), *instancecount, *basevertex);
    _debug(src_loc);
}

void InterfaceInner::DrawElementsInstancedBaseVertexBaseInstance(const GLenum& mode, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLsizei& instancecount, const GLint& basevertex, const GLuint& baseinstance, const SrcLoc& src_loc){
    glDrawElementsInstancedBaseVertexBaseInstance(*mode, *count, *type, indices.get(), *instancecount, *basevertex, *baseinstance);
    _debug(src_loc);
}

void InterfaceInner::DrawRangeElements(const GLenum& mode, const GLuint& start, const GLuint& end, const GLsizei& count, const GLenum& type, const GLdata& indices, const SrcLoc& src_loc){
    glDrawRangeElements(*mode, *start, *end, *count, *type, indices.get());
    _debug(src_loc);
}

void InterfaceInner::DrawRangeElementsBaseVertex(const GLenum& mode, const GLuint& start, const GLuint& end, const GLsizei& count, const GLenum& type, const GLdata& indices, const GLint& basevertex, const SrcLoc& src_loc){
    glDrawRangeElementsBaseVertex(*mode, *start, *end, *count, *type, indices.get(), *basevertex);
    _debug(src_loc);
}

void InterfaceInner::DrawTransformFeedback(const GLenum& mode, const GLuint& id, const SrcLoc& src_loc){
    glDrawTransformFeedback(*mode, *id);
    _debug(src_loc);
}

void InterfaceInner::DrawTransformFeedbackInstanced(const GLenum& mode, const GLuint& id, const GLsizei& instancecount, const SrcLoc& src_loc){
    glDrawTransformFeedbackInstanced(*mode, *id, *instancecount);
    _debug(src_loc);
}

void InterfaceInner::DrawTransformFeedbackStream(const GLenum& mode, const GLuint& id, const GLuint& stream, const SrcLoc& src_loc){
    glDrawTransformFeedbackStream(*mode, *id, *stream);
    _debug(src_loc);
}

void InterfaceInner::DrawTransformFeedbackStreamInstanced(const GLenum& mode, const GLuint& id, const GLuint& stream, const GLsizei& instancecount, const SrcLoc& src_loc){
    glDrawTransformFeedbackStreamInstanced(*mode, *id, *stream, *instancecount);
    _debug(src_loc);
}

void InterfaceInner::Enable(const GLenum& cap, const SrcLoc& src_loc){
    glEnable(*cap);
    _debug(src_loc);
}

void InterfaceInner::EnableVertexArrayAttrib(const GLuint& vaobj, const GLuint& index, const SrcLoc& src_loc){
    glEnableVertexArrayAttrib(*vaobj, *index);
    _debug(src_loc);
}

void InterfaceInner::EnableVertexAttribArray(const GLuint& index, const SrcLoc& src_loc){
    glEnableVertexAttribArray(*index);
    _debug(src_loc);
}

void InterfaceInner::Enablei(const GLenum& target, const GLuint& index, const SrcLoc& src_loc){
    glEnablei(*target, *index);
    _debug(src_loc);
}

void InterfaceInner::EndConditionalRender(const SrcLoc& src_loc){
    glEndConditionalRender();
    _debug(src_loc);
}

void InterfaceInner::EndQuery(const GLenum& target, const SrcLoc& src_loc){
    glEndQuery(*target);
    _debug(src_loc);
}

void InterfaceInner::EndQueryIndexed(const GLenum& target, const GLuint& index, const SrcLoc& src_loc){
    glEndQueryIndexed(*target, *index);
    _debug(src_loc);
}

void InterfaceInner::EndTransformFeedback(const SrcLoc& src_loc){
    glEndTransformFeedback();
    _debug(src_loc);
}

const GLsyncRes& InterfaceInner::FenceSync(const GLenum& condition, const GLbitfield& flags, const SrcLoc& src_loc){
    const GLsyncRes& dst(new const GLsyncRes&::element_type(glFenceSync(*condition, *flags)));
    _debug(src_loc);
    return dst;
}

void InterfaceInner::Finish(const SrcLoc& src_loc){
    glFinish();
    _debug(src_loc);
}

void InterfaceInner::Flush(const SrcLoc& src_loc){
    glFlush();
    _debug(src_loc);
}

void InterfaceInner::FlushMappedBufferRange(const GLenum& target, const GLintptr& offset, const GLsizeiptr& length, const SrcLoc& src_loc){
    glFlushMappedBufferRange(*target, *offset, *length);
    _debug(src_loc);
}

void InterfaceInner::FlushMappedNamedBufferRange(const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& length, const SrcLoc& src_loc){
    glFlushMappedNamedBufferRange(*buffer, *offset, *length);
    _debug(src_loc);
}

void InterfaceInner::FramebufferParameteri(const GLenum& target, const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    glFramebufferParameteri(*target, *pname, *param);
    _debug(src_loc);
}

void InterfaceInner::FramebufferRenderbuffer(const GLenum& target, const GLenum& attachment, const GLenum& renderbuffertarget, const GLuint& renderbuffer, const SrcLoc& src_loc){
    glFramebufferRenderbuffer(*target, *attachment, *renderbuffertarget, *renderbuffer);
    _debug(src_loc);
}

void InterfaceInner::FramebufferTexture(const GLenum& target, const GLenum& attachment, const GLuint& texture, const GLint& level, const SrcLoc& src_loc){
    glFramebufferTexture(*target, *attachment, *texture, *level);
    _debug(src_loc);
}

void InterfaceInner::FramebufferTexture1D(const GLenum& target, const GLenum& attachment, const GLenum& textarget, const GLuint& texture, const GLint& level, const SrcLoc& src_loc){
    glFramebufferTexture1D(*target, *attachment, *textarget, *target, *level);
    _debug(src_loc);
}

void InterfaceInner::FramebufferTexture2D(const GLenum& target, const GLenum& attachment, const GLenum& textarget, const GLuint& texture, const GLint& level, const SrcLoc& src_loc){
    glFramebufferTexture2D(*target, *attachment, *textarget, *texture, *level);
    _debug(src_loc);
}

void InterfaceInner::FramebufferTexture3D(const GLenum& target, const GLenum& attachment, const GLenum& textarget, const GLuint& texture, const GLint& level, const GLint& zoffset, const SrcLoc& src_loc){
    glFramebufferTexture3D(*target, *attachment, *textarget, *texture, *level, *zoffset);
    _debug(src_loc);
}

void InterfaceInner::FramebufferTextureLayer(const GLenum& target, const GLenum& attachment, const GLuint& texture, const GLint& level, const GLint& layer, const SrcLoc& src_loc){
    glFramebufferTextureLayer(*target, *attachment, *texture, *level, *layer);
    _debug(src_loc);
}

void InterfaceInner::FrontFace(const GLenum& mode, const SrcLoc& src_loc){
    glFrontFace(*mode);
    _debug(src_loc);
}

void InterfaceInner::GenBuffers(const GLsizei& n, const GLuintArr& buffers, const SrcLoc& src_loc){
    glGenBuffers(*n, buffers.get());
    _debug(src_loc);
}

void InterfaceInner::GenFramebuffers(const GLsizei& n, const GLuintArr& framebuffers, const SrcLoc& src_loc){
    glGenFramebuffers(*n, framebuffers.get());
    _debug(src_loc);
}

void InterfaceInner::GenProgramPipelines(const GLsizei& n, const GLuintArr& pipelines, const SrcLoc& src_loc){
    glGenProgramPipelines(*n, pipelines.get());
    _debug(src_loc);
}

void InterfaceInner::GenQueries(const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    glGenQueries(*n, ids.get());
    _debug(src_loc);
}

void InterfaceInner::GenRenderbuffers(const GLsizei& n, const GLuintArr& renderbuffers, const SrcLoc& src_loc){
    glGenRenderbuffers(*n, renderbuffers.get());
    _debug(src_loc);
}

void InterfaceInner::GenSamplers(const GLsizei& count, const GLuintArr& samplers, const SrcLoc& src_loc){
    glGenSamplers(*count, samplers.get());
    _debug(src_loc);
}

void InterfaceInner::GenTextures(const GLsizei& n, const GLuintArr& textures, const SrcLoc& src_loc){
    glGenTextures(*n, textures.get());
    _debug(src_loc);
}

void InterfaceInner::GenTransformFeedbacks(const GLsizei& n, const GLuintArr& ids, const SrcLoc& src_loc){
    glGenTransformFeedbacks(*n, ids.get());
    _debug(src_loc);
}

void InterfaceInner::GenVertexArrays(const GLsizei& n, const GLuintArr& arrays, const SrcLoc& src_loc){
    glGenVertexArrays(*n, arrays.get());
    _debug(src_loc);
}

void InterfaceInner::GenerateMipmap(const GLenum& target, const SrcLoc& src_loc){
    glGenerateMipmap(*target);
    _debug(src_loc);
}

void InterfaceInner::GenerateTextureMipmap(const GLuint& texture, const SrcLoc& src_loc){
    glGenerateTextureMipmap(*texture);
    _debug(src_loc);
}

void InterfaceInner::GetActiveAtomicCounterBufferiv(const GLuint& program, const GLuint& bufferIndex, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetActiveAtomicCounterBufferiv(*program, *bufferIndex, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetActiveAttrib(const GLuint& program, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLint& size, const GLenum& type, const GLcharArr& name, const SrcLoc& src_loc){
    glGetActiveAttrib(*program, *index, *bufSize, length.get(), size.get(), type.get(), name.get());
    _debug(src_loc);
}

void InterfaceInner::GetActiveSubroutineName(const GLuint& program, const GLenum& shadertype, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLcharArr& name, const SrcLoc& src_loc){
    glGetActiveSubroutineName(*program, *shadertype, *index, *bufSize, length.get(), name.get());
    _debug(src_loc);
}

void InterfaceInner::GetActiveSubroutineUniformName(const GLuint& program, const GLenum& shadertype, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLcharArr& name, const SrcLoc& src_loc){
    glGetActiveSubroutineUniformName(*program, *shadertype, *index, *bufSize, length.get(), name.get());
    _debug(src_loc);
}

void InterfaceInner::GetActiveSubroutineUniformiv(const GLuint& program, const GLenum& shadertype, const GLuint& index, const GLenum& pname, const GLintArr& values, const SrcLoc& src_loc){
    glGetActiveSubroutineUniformiv(*program, *shadertype, *index, *pname, values.get());
    _debug(src_loc);
}

void InterfaceInner::GetActiveUniform(const GLuint& program, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLint& size, const GLenum& type, const GLcharArr& name, const SrcLoc& src_loc){
    glGetActiveUniform(*program, *index, *bufSize, length.get(), size.get(), type.get(), name.get());
    _debug(src_loc);
}

void InterfaceInner::GetActiveUniformBlockName(const GLuint& program, const GLuint& uniformBlockIndex, const GLsizei& bufSize, const GLsizei& length, const GLcharArr& uniformBlockName, const SrcLoc& src_loc){
    glGetActiveUniformBlockName(*program, *uniformBlockIndex, *bufSize, length.get(), uniformBlockName.get());
    _debug(src_loc);
}

void InterfaceInner::GetActiveUniformBlockiv(const GLuint& program, const GLuint& uniformBlockIndex, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetActiveUniformBlockiv(*program, *uniformBlockIndex, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetActiveUniformName(const GLuint& program, const GLuint& uniformIndex, const GLsizei& bufSize, const GLsizei& length, const GLcharArr& uniformName, const SrcLoc& src_loc){
    glGetActiveUniformName(*program, *uniformIndex, *bufSize, length.get(), uniformName.get());
    _debug(src_loc);
}

void InterfaceInner::GetActiveUniformsiv(const GLuint& program, const GLsizei& uniformCount, const GLuintArr& uniformIndices, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetActiveUniformsiv(*program, *uniformCount, uniformIndices.get(), *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetAttachedShaders(const GLuint& program, const GLsizei& maxCount, const GLsizeiArr& count, const GLuintArr& shaders, const SrcLoc& src_loc){
    glGetAttachedShaders(*program, *maxCount, count.get(), shaders.get());
    _debug(src_loc);
}

const GLintRes& InterfaceInner::GetAttribLocation(const GLuint& program, const GLcharArr& name, const SrcLoc& src_loc){
    const GLintRes& dst(new const GLintRes&::element_type(glGetAttribLocation(*program, name.get())));
    _debug(src_loc);
    return dst;
}

void InterfaceInner::GetBooleani_v(const GLenum& target, const GLuint& index, const GLbooleanArr& data, const SrcLoc& src_loc){
    glGetBooleani_v(*target, *index, data.get());
    _debug(src_loc);
}

void InterfaceInner::GetBooleanv(const GLenum& pname, const GLbooleanArr& data, const SrcLoc& src_loc){
    glGetBooleanv(*pname, data.get());
    _debug(src_loc);
}

void InterfaceInner::GetBufferParameteri64v(const GLenum& target, const GLenum& pname, const GLint64Arr& params, const SrcLoc& src_loc){
    glGetBufferParameteri64v(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetBufferParameteriv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetBufferParameteriv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetBufferPointerv(const GLenum& target, const GLenum& pname, const GLdataPtr& params, const SrcLoc& src_loc){
    glGetBufferPointerv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetBufferSubData(const GLenum& target, const GLintptr& offset, const GLsizeiptr& size, const GLdata& data, const SrcLoc& src_loc){
    glGetBufferSubData(*target, *offset, *size, data.get());
    _debug(src_loc);
}

void InterfaceInner::GetCompressedTexImage(const GLenum& target, const GLint& level, const GLdata& img, const SrcLoc& src_loc){
    glGetCompressedTexImage(*target, *level, img.get());
    _debug(src_loc);
}

void InterfaceInner::GetCompressedTextureImage(const GLuint& texture, const GLint& level, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    glGetCompressedTextureImage(*texture, *level, *bufSize, pixels.get());
    _debug(src_loc);
}

void InterfaceInner::GetCompressedTextureSubImage(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    glGetCompressedTextureSubImage(*texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *bufSize, pixels.get());
    _debug(src_loc);
}

const GLuintRes& InterfaceInner::GetDebugMessageLog(const GLuint& count, const GLsizei& bufSize, const GLenumArr& sources, const GLenumArr& types, const GLuintArr& ids, const GLenumArr& severities, const GLsizei& lengths, const GLcharArr& messageLog, const SrcLoc& src_loc){
    const GLuintRes& dst(new const GLuintRes&::element_type(glGetDebugMessageLog(*count, *bufSize, sources.get(), types.get(), ids.get(), severities.get(), lengths.get(), messageLog.get())));
    _debug(src_loc);
    return dst;
}

void InterfaceInner::GetDoublei_v(const GLenum& target, const GLuint& index, const GLdoubleArr& data, const SrcLoc& src_loc){
    glGetDoublei_v(*target, *index, data.get());
    _debug(src_loc);
}

void InterfaceInner::GetDoublev(const GLenum& pname, const GLdoubleArr& data, const SrcLoc& src_loc){
    glGetDoublev(*pname, data.get());
    _debug(src_loc);
}

const GLenumRes& InterfaceInner::GetError(const SrcLoc& src_loc){
    const GLenumRes& dst(new const GLenumRes&::element_type(glGetError()));
    _debug(src_loc);
    return dst;
}

void InterfaceInner::GetFloati_v(const GLenum& target, const GLuint& index, const GLfloatArr& data, const SrcLoc& src_loc){
    glGetFloati_v(*target, *index, data.get());
    _debug(src_loc);
}

void InterfaceInner::GetFloatv(const GLenum& pname, const GLfloatArr& data, const SrcLoc& src_loc){
    glGetFloatv(*pname, data.get());
    _debug(src_loc);
}

const GLintRes& InterfaceInner::GetFragDataIndex(const GLuint& program, const GLcharArr& name, const SrcLoc& src_loc){
    const GLintRes& dst(new const GLintRes&::element_type(glGetFragDataIndex(*program, name.get())));
    _debug(src_loc);
    return dst;
}

const GLintRes& InterfaceInner::GetFragDataLocation(const GLuint& program, const GLcharArr& name, const SrcLoc& src_loc){
    const GLintRes& dst(new const GLintRes&::element_type(glGetFragDataLocation(*program, name.get())));
    _debug(src_loc);
    return dst;
}

void InterfaceInner::GetFramebufferAttachmentParameteriv(const GLenum& target, const GLenum& attachment, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetFramebufferAttachmentParameteriv(*target, *attachment, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetFramebufferParameteriv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetFramebufferParameteriv(*target, *pname, params.get());
    _debug(src_loc);
}

const GLenumRes& InterfaceInner::GetGraphicsResetStatus(const SrcLoc& src_loc){
    const GLenumRes& dst(new const GLenumRes&::element_type(glGetGraphicsResetStatus()));
    _debug(src_loc);
    return dst;
}

void InterfaceInner::GetInteger64i_v(const GLenum& target, const GLuint& index, const GLint64Arr& data, const SrcLoc& src_loc){
    glGetInteger64i_v(*target, *index, data.get());
    _debug(src_loc);
}

void InterfaceInner::GetInteger64v(const GLenum& pname, const GLint64Arr& data, const SrcLoc& src_loc){
    glGetInteger64v(*pname, data.get());
    _debug(src_loc);
}

void InterfaceInner::GetIntegeri_v(const GLenum& target, const GLuint& index, const GLintArr& data, const SrcLoc& src_loc){
    glGetIntegeri_v(*target, *index, data.get());
    _debug(src_loc);
}

void InterfaceInner::GetIntegerv(const GLenum& pname, const GLintArr& data, const SrcLoc& src_loc){
    glGetIntegerv(*pname, data.get());
    _debug(src_loc);
}

void InterfaceInner::GetInternalformati64v(const GLenum& target, const GLenum& internalformat, const GLenum& pname, const GLsizei& count, const GLint64Arr& params, const SrcLoc& src_loc){
    glGetInternalformati64v(*target, *internalformat, *pname, *count, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetInternalformativ(const GLenum& target, const GLenum& internalformat, const GLenum& pname, const GLsizei& count, const GLintArr& params, const SrcLoc& src_loc){
    glGetInternalformativ(*target, *internalformat, *pname, *count, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetMultisamplefv(const GLenum& pname, const GLuint& index, const GLfloatArr& val, const SrcLoc& src_loc){
    glGetMultisamplefv(*pname, *index, val.get());
    _debug(src_loc);
}

void InterfaceInner::GetNamedBufferParameteri64v(const GLuint& buffer, const GLenum& pname, const GLint64Arr& params, const SrcLoc& src_loc){
    glGetNamedBufferParameteri64v(*buffer, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetNamedBufferParameteriv(const GLuint& buffer, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetNamedBufferParameteriv(*buffer, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetNamedBufferPointerv(const GLuint& buffer, const GLenum& pname, const GLdataPtr& params, const SrcLoc& src_loc){
    glGetNamedBufferPointerv(*buffer, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetNamedBufferSubData(const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const GLdata& data, const SrcLoc& src_loc){
    glGetNamedBufferSubData(*buffer, *offset, *size, data.get());
    _debug(src_loc);
}

void InterfaceInner::GetNamedFramebufferAttachmentParameteriv(const GLuint& framebuffer, const GLenum& attachment, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetNamedFramebufferAttachmentParameteriv(*framebuffer, *attachment, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetNamedFramebufferParameteriv(const GLuint& framebuffer, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    glGetNamedFramebufferParameteriv(*framebuffer, *pname, param.get());
    _debug(src_loc);
}

void InterfaceInner::GetNamedRenderbufferParameteriv(const GLuint& renderbuffer, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetNamedRenderbufferParameteriv(*renderbuffer, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetObjectLabel(const GLenum& identifier, const GLuint& name, const GLsizei& bufSize, const GLsizei& length, const GLcharArr& label, const SrcLoc& src_loc){
    glGetObjectLabel(*identifier, *name, *bufSize, length.get(), label.get());
    _debug(src_loc);
}

void InterfaceInner::GetObjectPtrLabel(const GLdata& ptr, const GLsizei& bufSize, const GLsizei& length, const GLcharArr& label, const SrcLoc& src_loc){
    glGetObjectPtrLabel(ptr.get(), *bufSize, length.get(), label.get());
    _debug(src_loc);
}

void InterfaceInner::GetPointerv(const GLenum& pname, const GLdataPtr& params, const SrcLoc& src_loc){
    glGetPointerv(*pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetProgramBinary(const GLuint& program, const GLsizei& bufSize, const GLsizei& length, const GLenumArr& binaryFormat, const GLdata& binary, const SrcLoc& src_loc){
    glGetProgramBinary(*program, *bufSize, length.get(), binaryFormat.get(), binary.get());
    _debug(src_loc);
}

void InterfaceInner::GetProgramInfoLog(const GLuint& program, const GLsizei& bufSize, const GLsizei& length, const GLcharArr& infoLog, const SrcLoc& src_loc){
    glGetProgramInfoLog(*program, *bufSize, length.get(), infoLog.get());
    _debug(src_loc);
}

void InterfaceInner::GetProgramInterfaceiv(const GLuint& program, const GLenum& programInterface, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetProgramInterfaceiv(*program, *programInterface, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetProgramPipelineInfoLog(const GLuint& pipeline, const GLsizei& bufSize, const GLsizei& length, const GLcharArr& infoLog, const SrcLoc& src_loc){
    glGetProgramPipelineInfoLog(*pipeline, *bufSize, length.get(), infoLog.get());
    _debug(src_loc);
}

void InterfaceInner::GetProgramPipelineiv(const GLuint& pipeline, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetProgramPipelineiv(*pipeline, *pname, params.get());
    _debug(src_loc);
}

const GLuintRes& InterfaceInner::GetProgramResourceIndex(const GLuint& program, const GLenum& programInterface, const GLcharArr& name, const SrcLoc& src_loc){
    const GLuintRes& dst(new const GLuintRes&::element_type(glGetProgramResourceIndex(*program, *programInterface, name.get())));
    _debug(src_loc);
    return dst;
}

const GLintRes& InterfaceInner::GetProgramResourceLocation(const GLuint& program, const GLenum& programInterface, const GLcharArr& name, const SrcLoc& src_loc){
    const GLintRes& dst(new const GLintRes&::element_type(glGetProgramResourceLocation(*program, *programInterface, name.get())));
    _debug(src_loc);
    return dst;
}

const GLintRes& InterfaceInner::GetProgramResourceLocationIndex(const GLuint& program, const GLenum& programInterface, const GLcharArr& name, const SrcLoc& src_loc){
    const GLintRes& dst(new const GLintRes&::element_type(glGetProgramResourceLocationIndex(*program, *programInterface, name.get())));
    _debug(src_loc);
    return dst;
}

void InterfaceInner::GetProgramResourceName(const GLuint& program, const GLenum& programInterface, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLcharArr& name, const SrcLoc& src_loc){
    glGetProgramResourceName(*program, *programInterface, *index, *bufSize, length.get(), name.get());
    _debug(src_loc);
}

void InterfaceInner::GetProgramResourceiv(const GLuint& program, const GLenum& programInterface, const GLuint& index, const GLsizei& propCount, const GLenumArr& props, const GLsizei& count, const GLsizei& length, const GLintArr& params, const SrcLoc& src_loc){
    glGetProgramResourceiv(*program, *programInterface, *index, *propCount, props.get(), *count, length.get(), params.get());
    _debug(src_loc);
}

void InterfaceInner::GetProgramStageiv(const GLuint& program, const GLenum& shadertype, const GLenum& pname, const GLintArr& values, const SrcLoc& src_loc){
    glGetProgramStageiv(*program, *shadertype, *pname, values.get());
    _debug(src_loc);
}

void InterfaceInner::GetProgramiv(const GLuint& program, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetProgramiv(*program, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetQueryBufferObjecti64v(const GLuint& id, const GLuint& buffer, const GLenum& pname, const GLintptr& offset, const SrcLoc& src_loc){
    glGetQueryBufferObjecti64v(*id, *buffer, *pname, *offset);
    _debug(src_loc);
}

void InterfaceInner::GetQueryBufferObjectiv(const GLuint& id, const GLuint& buffer, const GLenum& pname, const GLintptr& offset, const SrcLoc& src_loc){
    glGetQueryBufferObjectiv(*id, *buffer, *pname, *offset);
    _debug(src_loc);
}

void InterfaceInner::GetQueryBufferObjectui64v(const GLuint& id, const GLuint& buffer, const GLenum& pname, const GLintptr& offset, const SrcLoc& src_loc){
    glGetQueryBufferObjectui64v(*id, *buffer, *pname, *offset);
    _debug(src_loc);
}

void InterfaceInner::GetQueryBufferObjectuiv(const GLuint& id, const GLuint& buffer, const GLenum& pname, const GLintptr& offset, const SrcLoc& src_loc){
    glGetQueryBufferObjectuiv(*id, *buffer, *pname, *offset);
    _debug(src_loc);
}

void InterfaceInner::GetQueryIndexediv(const GLenum& target, const GLuint& index, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetQueryIndexediv(*target, *index, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetQueryObjecti64v(const GLuint& id, const GLenum& pname, const GLint64Arr& params, const SrcLoc& src_loc){
    glGetQueryObjecti64v(*id, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetQueryObjectiv(const GLuint& id, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetQueryObjectiv(*id, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetQueryObjectui64v(const GLuint& id, const GLenum& pname, const GLuint64Arr& params, const SrcLoc& src_loc){
    glGetQueryObjectui64v(*id, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetQueryObjectuiv(const GLuint& id, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    glGetQueryObjectuiv(*id, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetQueryiv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetQueryiv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetRenderbufferParameteriv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetRenderbufferParameteriv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetSamplerParameterIiv(const GLuint& sampler, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetSamplerParameterIiv(*sampler, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetSamplerParameterIuiv(const GLuint& sampler, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    glGetSamplerParameterIuiv(*sampler, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetSamplerParameterfv(const GLuint& sampler, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    glGetSamplerParameterfv(*sampler, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetSamplerParameteriv(const GLuint& sampler, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetSamplerParameteriv(*sampler, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetShaderInfoLog(const GLuint& shader, const GLsizei& bufSize, const GLsizei& length, const GLcharArr& infoLog, const SrcLoc& src_loc){
    glGetShaderInfoLog(*shader, *bufSize, length.get(), infoLog.get());
    _debug(src_loc);
}

void InterfaceInner::GetShaderPrecisionFormat(const GLenum& shadertype, const GLenum& precisiontype, const GLintArr& range, const GLintArr& precision, const SrcLoc& src_loc){
    glGetShaderPrecisionFormat(*shadertype, *precisiontype, range.get(), precision.get());
    _debug(src_loc);
}

void InterfaceInner::GetShaderSource(const GLuint& shader, const GLsizei& bufSize, const GLsizei& length, const GLcharArr& source, const SrcLoc& src_loc){
    glGetShaderSource(*shader, *bufSize, length.get(), source.get());
    _debug(src_loc);
}

void InterfaceInner::GetShaderiv(const GLuint& shader, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetShaderiv(*shader, *pname, params.get());
    _debug(src_loc);
}

const GLubyteArrRes& InterfaceInner::GetString(const GLenum& name, const SrcLoc& src_loc){
    auto res = glGetString(*name);
    auto len = strlen(reinterpret_cast<const char*>(res)) + 1;
    const GLubyteArrRes& dst(new const GLubyteArrRes&::element_type[len]);
    memcpy(dst.get(), res, len - 1);
    dst[len - 1] = '\0';
    _debug(src_loc);
    return dst;
}

const GLubyteArrRes& InterfaceInner::GetStringi(const GLenum& name, const GLuint& index, const SrcLoc& src_loc){
    auto res = glGetStringi(*name, *index);
    auto len = strlen(reinterpret_cast<const char*>(res));
    const GLubyteArrRes& dst(new const GLubyteArrRes&::element_type[len]);
    memcpy(dst.get(), res, len - 1);
    dst[len - 1] = '\0';
    _debug(src_loc);
    return dst;
}

const GLuintRes& InterfaceInner::GetSubroutineIndex(const GLuint& program, const GLenum& shadertype, const GLcharArr& name, const SrcLoc& src_loc){
    const GLuintRes& dst(new const GLuintRes&::element_type(glGetSubroutineIndex(*program, *shadertype, name.get())));
    _debug(src_loc);
    return dst;
}

const GLintRes& InterfaceInner::GetSubroutineUniformLocation(const GLuint& program, const GLenum& shadertype, const GLcharArr& name, const SrcLoc& src_loc){
    const GLintRes& dst(new const GLintRes&::element_type(glGetSubroutineUniformLocation(*program, *shadertype, name.get())));
    _debug(src_loc);
    return dst;
}

void InterfaceInner::GetSynciv(const GLsync& sync, const GLenum& pname, const GLsizei& count, const GLsizei& length, const GLintArr& values, const SrcLoc& src_loc){
    glGetSynciv(*sync, *pname, *count, length.get(), values.get());
    _debug(src_loc);
}

void InterfaceInner::GetTexImage(const GLenum& target, const GLint& level, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    glGetTexImage(*target, *level, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceInner::GetTexLevelParameterfv(const GLenum& target, const GLint& level, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    glGetTexLevelParameterfv(*target, *level, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetTexLevelParameteriv(const GLenum& target, const GLint& level, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetTexLevelParameteriv(*target, *level, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetTexParameterIiv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetTexParameterIiv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetTexParameterIuiv(const GLenum& target, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    glGetTexParameterIuiv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetTexParameterfv(const GLenum& target, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    glGetTexParameterfv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetTexParameteriv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetTexParameteriv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetTextureImage(const GLuint& texture, const GLint& level, const GLenum& format, const GLenum& type, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    glGetTextureImage(*texture, *level, *format, *type, *bufSize, pixels.get());
    _debug(src_loc);
}

void InterfaceInner::GetTextureLevelParameterfv(const GLuint& texture, const GLint& level, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    glGetTextureLevelParameterfv(*texture, *level, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetTextureLevelParameteriv(const GLuint& texture, const GLint& level, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetTextureLevelParameteriv(*texture, *level, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetTextureParameterIiv(const GLuint& texture, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetTextureParameterIiv(*texture, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetTextureParameterIuiv(const GLuint& texture, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    glGetTextureParameterIuiv(*texture, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetTextureParameterfv(const GLuint& texture, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    glGetTextureParameterfv(*texture, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetTextureParameteriv(const GLuint& texture, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetTextureParameteriv(*texture, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetTextureSubImage(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLenum& type, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    glGetTextureSubImage(*texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *type, *bufSize, pixels.get());
    _debug(src_loc);
}

void InterfaceInner::GetTransformFeedbackVarying(const GLuint& program, const GLuint& index, const GLsizei& bufSize, const GLsizei& length, const GLsizeiArr& size, const GLenumArr& type, const GLcharArr& name, const SrcLoc& src_loc){
    glGetTransformFeedbackVarying(*program, *index, *bufSize, length.get(), size.get(), type.get(), name.get());
    _debug(src_loc);
}

void InterfaceInner::GetTransformFeedbacki64_v(const GLuint& xfb, const GLenum& pname, const GLuint& index, const GLint64Arr& param, const SrcLoc& src_loc){
    glGetTransformFeedbacki64_v(*xfb, *pname, *index, param.get());
    _debug(src_loc);
}

void InterfaceInner::GetTransformFeedbacki_v(const GLuint& xfb, const GLenum& pname, const GLuint& index, const GLintArr& param, const SrcLoc& src_loc){
    glGetTransformFeedbacki_v(*xfb, *pname, *index, param.get());
    _debug(src_loc);
}

void InterfaceInner::GetTransformFeedbackiv(const GLuint& xfb, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    glGetTransformFeedbackiv(*xfb, *pname, param.get());
    _debug(src_loc);
}

const GLuintRes& InterfaceInner::GetUniformBlockIndex(const GLuint& program, const GLcharArr& uniformBlockName, const SrcLoc& src_loc){
    const GLuintRes& dst(new const GLuintRes&::element_type(glGetUniformBlockIndex(*program, uniformBlockName.get())));
    _debug(src_loc);
    return dst;
}

const GLintRes& InterfaceInner::GetUniformLocation(const GLuint& program, const GLcharArr& name, const SrcLoc& src_loc){
    const GLintRes& dst(new const GLintRes&::element_type(glGetUniformLocation(*program, name.get())));
    _debug(src_loc);
    return dst;
}

void InterfaceInner::GetUniformSubroutineuiv(const GLenum& shadertype, const GLint& location, const GLuintArr& params, const SrcLoc& src_loc){
    glGetUniformSubroutineuiv(*shadertype, *location, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetUniformdv(const GLuint& program, const GLint& location, const GLdoubleArr& params, const SrcLoc& src_loc){
    glGetUniformdv(*program, *location, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetUniformfv(const GLuint& program, const GLint& location, const GLfloatArr& params, const SrcLoc& src_loc){
    glGetUniformfv(*program, *location, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetUniformiv(const GLuint& program, const GLint& location, const GLintArr& params, const SrcLoc& src_loc){
    glGetUniformiv(*program, *location, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetUniformuiv(const GLuint& program, const GLint& location, const GLuintArr& params, const SrcLoc& src_loc){
    glGetUniformuiv(*program, *location, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetVertexArrayIndexed64iv(const GLuint& vaobj, const GLuint& index, const GLenum& pname, const GLint64Arr& param, const SrcLoc& src_loc){
    glGetVertexArrayIndexed64iv(*vaobj, *index, *pname, param.get());
    _debug(src_loc);
}

void InterfaceInner::GetVertexArrayIndexediv(const GLuint& vaobj, const GLuint& index, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    glGetVertexArrayIndexediv(*vaobj, *index, *pname, param.get());
    _debug(src_loc);
}

void InterfaceInner::GetVertexArrayiv(const GLuint& vaobj, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    glGetVertexArrayiv(*vaobj, *pname, param.get());
    _debug(src_loc);
}

void InterfaceInner::GetVertexAttribIiv(const GLuint& index, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetVertexAttribIiv(*index, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetVertexAttribIuiv(const GLuint& index, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    glGetVertexAttribIuiv(*index, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetVertexAttribLdv(const GLuint& index, const GLenum& pname, const GLdoubleArr& params, const SrcLoc& src_loc){
    glGetVertexAttribLdv(*index, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetVertexAttribPointerv(const GLuint& index, const GLenum& pname, const GLdataPtr& pointer, const SrcLoc& src_loc){
    glGetVertexAttribPointerv(*index, *pname, pointer.get());
    _debug(src_loc);
}

void InterfaceInner::GetVertexAttribdv(const GLuint& index, const GLenum& pname, const GLdoubleArr& params, const SrcLoc& src_loc){
    glGetVertexAttribdv(*index, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetVertexAttribfv(const GLuint& index, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    glGetVertexAttribfv(*index, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetVertexAttribiv(const GLuint& index, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glGetVertexAttribiv(*index, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetnCompressedTexImage(const GLenum& target, const GLint& lod, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    glGetnCompressedTexImage(*target, *lod, *bufSize, pixels.get());
    _debug(src_loc);
}

void InterfaceInner::GetnTexImage(const GLenum& target, const GLint& level, const GLenum& format, const GLenum& type, const GLsizei& bufSize, const GLdata& pixels, const SrcLoc& src_loc){
    glGetnTexImage(*target, *level, *format, *type, *bufSize, pixels.get());
    _debug(src_loc);
}

void InterfaceInner::GetnUniformdv(const GLuint& program, const GLint& location, const GLsizei& bufSize, const GLdoubleArr& params, const SrcLoc& src_loc){
    glGetnUniformdv(*program, *location, *bufSize, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetnUniformfv(const GLuint& program, const GLint& location, const GLsizei& bufSize, const GLfloatArr& params, const SrcLoc& src_loc){
    glGetnUniformfv(*program, *location, *bufSize, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetnUniformiv(const GLuint& program, const GLint& location, const GLsizei& bufSize, const GLintArr& params, const SrcLoc& src_loc){
    glGetnUniformiv(*program, *location, *bufSize, params.get());
    _debug(src_loc);
}

void InterfaceInner::GetnUniformuiv(const GLuint& program, const GLint& location, const GLsizei& bufSize, const GLuintArr& params, const SrcLoc& src_loc){
    glGetnUniformuiv(*program, *location, *bufSize, params.get());
    _debug(src_loc);
}

void InterfaceInner::Hint(const GLenum& target, const GLenum& mode, const SrcLoc& src_loc){
    glHint(*target, *mode);
    _debug(src_loc);
}

void InterfaceInner::InvalidateBufferData(const GLuint& buffer, const SrcLoc& src_loc){
    glInvalidateBufferData(*buffer);
    _debug(src_loc);
}

void InterfaceInner::InvalidateBufferSubData(const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& length, const SrcLoc& src_loc){
    glInvalidateBufferSubData(*buffer, *offset, *length);
    _debug(src_loc);
}

void InterfaceInner::InvalidateFramebuffer(const GLenum& target, const GLsizei& numAttachments, const GLenumArr& attachments, const SrcLoc& src_loc){
    glInvalidateFramebuffer(*target, *numAttachments, attachments.get());
    _debug(src_loc);
}

void InterfaceInner::InvalidateNamedFramebufferData(const GLuint& framebuffer, const GLsizei& numAttachments, const GLenumArr& attachments, const SrcLoc& src_loc){
    glInvalidateNamedFramebufferData(*framebuffer, *numAttachments, attachments.get());
    _debug(src_loc);
}

void InterfaceInner::InvalidateNamedFramebufferSubData(const GLuint& framebuffer, const GLsizei& numAttachments, const GLenumArr& attachments, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    glInvalidateNamedFramebufferSubData(*framebuffer, *numAttachments, attachments.get(), *x, *y, *width, *height);
    _debug(src_loc);
}

void InterfaceInner::InvalidateSubFramebuffer(const GLenum& target, const GLsizei& numAttachments, const GLenumArr& attachments, const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    glInvalidateSubFramebuffer(*target, *numAttachments, attachments.get(), *x, *y, *width, *height);
    _debug(src_loc);
}

void InterfaceInner::InvalidateTexImage(const GLuint& texture, const GLint& level, const SrcLoc& src_loc){
    glInvalidateTexImage(*texture, *level);
    _debug(src_loc);
}

void InterfaceInner::InvalidateTexSubImage(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const SrcLoc& src_loc){
    glInvalidateTexSubImage(*texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth);
    _debug(src_loc);
}

const GLbooleanRes& InterfaceInner::IsBuffer(const GLuint& buffer, const SrcLoc& src_loc){
    const GLbooleanRes& dst(new const GLbooleanRes&::element_type(glIsBuffer(*buffer)));
    _debug(src_loc);
    return dst;
}

const GLbooleanRes& InterfaceInner::IsEnabled(const GLenum& cap, const SrcLoc& src_loc){
    const GLbooleanRes& dst(new const GLbooleanRes&::element_type(glIsEnabled(*cap)));
    _debug(src_loc);
    return dst;
}

const GLbooleanRes& InterfaceInner::IsEnabledi(const GLenum& target, const GLuint& index, const SrcLoc& src_loc){
    const GLbooleanRes& dst(new const GLbooleanRes&::element_type(glIsEnabledi(*target, *index)));
    _debug(src_loc);
    return dst;
}

const GLbooleanRes& InterfaceInner::IsFramebuffer(const GLuint& framebuffer, const SrcLoc& src_loc){
    const GLbooleanRes& dst(new const GLbooleanRes&::element_type(glIsFramebuffer(*framebuffer)));
    _debug(src_loc);
    return dst;
}

const GLbooleanRes& InterfaceInner::IsProgram(const GLuint& program, const SrcLoc& src_loc){
    const GLbooleanRes& dst(new const GLbooleanRes&::element_type(glIsProgram(*program)));
    _debug(src_loc);
    return dst;
}

const GLbooleanRes& InterfaceInner::IsProgramPipeline(const GLuint& pipeline, const SrcLoc& src_loc){
    const GLbooleanRes& dst(new const GLbooleanRes&::element_type(glIsProgramPipeline(*pipeline)));
    _debug(src_loc);
    return dst;
}

const GLbooleanRes& InterfaceInner::IsQuery(const GLuint& id, const SrcLoc& src_loc){
    const GLbooleanRes& dst(new const GLbooleanRes&::element_type(glIsQuery(*id)));
    _debug(src_loc);
    return dst;
}

const GLbooleanRes& InterfaceInner::IsRenderbuffer(const GLuint& renderbuffer, const SrcLoc& src_loc){
    const GLbooleanRes& dst(new const GLbooleanRes&::element_type(glIsRenderbuffer(*renderbuffer)));
    _debug(src_loc);
    return dst;
}

const GLbooleanRes& InterfaceInner::IsSampler(const GLuint& sampler, const SrcLoc& src_loc){
    const GLbooleanRes& dst(new const GLbooleanRes&::element_type(glIsSampler(*sampler)));
    _debug(src_loc);
    return dst;
}

const GLbooleanRes& InterfaceInner::IsShader(const GLuint& shader, const SrcLoc& src_loc){
    const GLbooleanRes& dst(new const GLbooleanRes&::element_type(glIsShader(*shader)));
    _debug(src_loc);
    return dst;
}

const GLbooleanRes& InterfaceInner::IsSync(const GLsync& sync, const SrcLoc& src_loc){
    const GLbooleanRes& dst(new const GLbooleanRes&::element_type(glIsSync(*sync)));
    _debug(src_loc);
    return dst;
}

const GLbooleanRes& InterfaceInner::IsTexture(const GLuint& texture, const SrcLoc& src_loc){
    const GLbooleanRes& dst(new const GLbooleanRes&::element_type(glIsTexture(*texture)));
    _debug(src_loc);
    return dst;
}

const GLbooleanRes& InterfaceInner::IsTransformFeedback(const GLuint& id, const SrcLoc& src_loc){
    const GLbooleanRes& dst(new const GLbooleanRes&::element_type(glIsTransformFeedback(*id)));
    _debug(src_loc);
    return dst;
}

const GLbooleanRes& InterfaceInner::IsVertexArray(const GLuint& array, const SrcLoc& src_loc){
    const GLbooleanRes& dst(new const GLbooleanRes&::element_type(glIsVertexArray(*array)));
    _debug(src_loc);
    return dst;
}

void InterfaceInner::LineWidth(const GLfloat& width, const SrcLoc& src_loc){
    glLineWidth(*width);
    _debug(src_loc);
}

void InterfaceInner::LinkProgram(const GLuint& program, const SrcLoc& src_loc){
    glLinkProgram(*program);
    _debug(src_loc);
}

void InterfaceInner::LogicOp(const GLenum& opcode, const SrcLoc& src_loc){
    glLogicOp(*opcode);
    _debug(src_loc);
}

void InterfaceInner::MemoryBarrier(const GLbitfield& barriers, const SrcLoc& src_loc){
    glMemoryBarrier(*barriers);
    _debug(src_loc);
}

void InterfaceInner::MemoryBarrierByRegion(const GLbitfield& barriers, const SrcLoc& src_loc){
    glMemoryBarrierByRegion(*barriers);
    _debug(src_loc);
}

void InterfaceInner::MinSampleShading(const GLfloat& value, const SrcLoc& src_loc){
    glMinSampleShading(*value);
    _debug(src_loc);
}

void InterfaceInner::MultiDrawArrays(const GLenum& mode, const GLintArr& first, const GLsizeiArr& count, const GLsizei& drawcount, const SrcLoc& src_loc){
    glMultiDrawArrays(*mode, first.get(), count.get(), *drawcount);
    _debug(src_loc);
}

void InterfaceInner::MultiDrawArraysIndirect(const GLenum& mode, const GLdata& indirect, const GLsizei& drawcount, const GLsizei& stride, const SrcLoc& src_loc){
    glMultiDrawArraysIndirect(*mode, indirect.get(), *drawcount, *stride);
    _debug(src_loc);
}

void InterfaceInner::MultiDrawArraysIndirectCount(const GLenum& mode, const GLdata& indirect, const GLintptr& drawcount, const GLsizei& maxdrawcount, const GLsizei& stride, const SrcLoc& src_loc){
    glMultiDrawArraysIndirectCount(*mode, indirect.get(), *drawcount, *maxdrawcount, *stride);
    _debug(src_loc);
}

void InterfaceInner::MultiDrawElements(const GLenum& mode, const GLsizeiArr& count, const GLenum& type, const GLdataPtr& indices, const GLsizei& drawcount, const SrcLoc& src_loc){
    glMultiDrawElements(*mode, count.get(), *type, indices.get(), *drawcount);
    _debug(src_loc);
}

void InterfaceInner::MultiDrawElementsBaseVertex(const GLenum& mode, const GLsizeiArr& count, const GLenum& type, const GLdataPtr& indices, const GLsizei& drawcount, const GLintArr& basevertex, const SrcLoc& src_loc){
    glMultiDrawElementsBaseVertex(*mode, count.get(), *type, indices.get(), *drawcount, basevertex.get());
    _debug(src_loc);
}

void InterfaceInner::MultiDrawElementsIndirect(const GLenum& mode, const GLenum& type, const GLdata& indirect, const GLsizei& drawcount, const GLsizei& stride, const SrcLoc& src_loc){
    glMultiDrawElementsIndirect(*mode, *type, indirect.get(), *drawcount, *stride);
    _debug(src_loc);
}

void InterfaceInner::MultiDrawElementsIndirectCount(const GLenum& mode, const GLenum& type, const GLdata& indirect, const GLintptr& drawcount, const GLsizei& maxdrawcount, const GLsizei& stride, const SrcLoc& src_loc){
    glMultiDrawElementsIndirectCount(*mode, *type, indirect.get(), *drawcount, *maxdrawcount, *stride);
    _debug(src_loc);
}

void InterfaceInner::NamedBufferData(const GLuint& buffer, const GLsizeiptr& size, const GLdata& data, const GLenum& usage, const SrcLoc& src_loc){
    glNamedBufferData(*buffer, *size, data.get(), *usage);
    _debug(src_loc);
}

void InterfaceInner::NamedBufferStorage(const GLuint& buffer, const GLsizeiptr& size, const GLdata& data, const GLbitfield& flags, const SrcLoc& src_loc){
    glNamedBufferStorage(*buffer, *size, data.get(), *flags);
    _debug(src_loc);
}

void InterfaceInner::NamedBufferSubData(const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const GLdata& data, const SrcLoc& src_loc){
    glNamedBufferSubData(*buffer, *offset, *size, data.get());
    _debug(src_loc);
}

void InterfaceInner::NamedFramebufferDrawBuffer(const GLuint& framebuffer, const GLenum& buf, const SrcLoc& src_loc){
    glNamedFramebufferDrawBuffer(*framebuffer, *buf);
    _debug(src_loc);
}

void InterfaceInner::NamedFramebufferDrawBuffers(const GLuint& framebuffer, const GLsizei& n, const GLenumArr& bufs, const SrcLoc& src_loc){
    glNamedFramebufferDrawBuffers(*framebuffer, *n, bufs.get());
    _debug(src_loc);
}

void InterfaceInner::NamedFramebufferParameteri(const GLuint& framebuffer, const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    glNamedFramebufferParameteri(*framebuffer, *pname, *param);
    _debug(src_loc);
}

void InterfaceInner::NamedFramebufferReadBuffer(const GLuint& framebuffer, const GLenum& src, const SrcLoc& src_loc){
    glNamedFramebufferReadBuffer(*framebuffer, *src);
    _debug(src_loc);
}

void InterfaceInner::NamedFramebufferRenderbuffer(const GLuint& framebuffer, const GLenum& attachment, const GLenum& renderbuffertarget, const GLuint& renderbuffer, const SrcLoc& src_loc){
    glNamedFramebufferRenderbuffer(*framebuffer, *attachment, *renderbuffertarget, *renderbuffer);
    _debug(src_loc);
}

void InterfaceInner::NamedFramebufferTexture(const GLuint& framebuffer, const GLenum& attachment, const GLuint& texture, const GLint& level, const SrcLoc& src_loc){
    glNamedFramebufferTexture(*framebuffer, *attachment, *texture, *level);
    _debug(src_loc);
}

void InterfaceInner::NamedFramebufferTextureLayer(const GLuint& framebuffer, const GLenum& attachment, const GLuint& texture, const GLint& level, const GLint& layer, const SrcLoc& src_loc){
    glNamedFramebufferTextureLayer(*framebuffer, *attachment, *texture, *level, *layer);
    _debug(src_loc);
}

void InterfaceInner::NamedRenderbufferStorage(const GLuint& renderbuffer, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    glNamedRenderbufferStorage(*renderbuffer, *internalformat, *width, *height);
    _debug(src_loc);
}

void InterfaceInner::NamedRenderbufferStorageMultisample(const GLuint& renderbuffer, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    glNamedRenderbufferStorageMultisample(*renderbuffer, *samples, *internalformat, *width, *height);
    _debug(src_loc);
}

void InterfaceInner::ObjectLabel(const GLenum& identifier, const GLuint& name, const GLsizei& length, const GLcharArr& label, const SrcLoc& src_loc){
    glObjectLabel(*identifier, *name, *length, label.get());
    _debug(src_loc);
}

void InterfaceInner::ObjectPtrLabel(const GLdata& ptr, const GLsizei& length, const GLcharArr& label, const SrcLoc& src_loc){
    glObjectPtrLabel(ptr.get(), *length, label.get());
    _debug(src_loc);
}

void InterfaceInner::PatchParameterfv(const GLenum& pname, const GLfloatArr& values, const SrcLoc& src_loc){
    glPatchParameterfv(*pname, values.get());
    _debug(src_loc);
}

void InterfaceInner::PatchParameteri(const GLenum& pname, const GLint& value, const SrcLoc& src_loc){
    glPatchParameteri(*pname, *value);
    _debug(src_loc);
}

void InterfaceInner::PauseTransformFeedback(const SrcLoc& src_loc){
    glPauseTransformFeedback();
    _debug(src_loc);
}

void InterfaceInner::PixelStoref(const GLenum& pname, const GLfloat& param, const SrcLoc& src_loc){
    glPixelStoref(*pname, *param);
    _debug(src_loc);
}

void InterfaceInner::PixelStorei(const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    glPixelStorei(*pname, *param);
    _debug(src_loc);
}

void InterfaceInner::PointParameterf(const GLenum& pname, const GLfloat& param, const SrcLoc& src_loc){
    glPointParameterf(*pname, *param);
    _debug(src_loc);
}

void InterfaceInner::PointParameterfv(const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    glPointParameterfv(*pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::PointParameteri(const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    glPointParameteri(*pname, *param);
    _debug(src_loc);
}

void InterfaceInner::PointParameteriv(const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glPointParameteriv(*pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::PointSize(const GLfloat& size, const SrcLoc& src_loc){
    glPointSize(*size);
    _debug(src_loc);
}

void InterfaceInner::PolygonMode(const GLenum& face, const GLenum& mode, const SrcLoc& src_loc){
    glPolygonMode(*face, *mode);
    _debug(src_loc);
}

void InterfaceInner::PolygonOffset(const GLfloat& factor, const GLfloat& units, const SrcLoc& src_loc){
    glPolygonOffset(*factor, *units);
    _debug(src_loc);
}

void InterfaceInner::PolygonOffsetClamp(const GLfloat& factor, const GLfloat& units, const GLfloat& clamp, const SrcLoc& src_loc){
    glPolygonOffsetClamp(*factor, *units, *clamp);
    _debug(src_loc);
}

void InterfaceInner::PopDebugGroup(const SrcLoc& src_loc){
    glPopDebugGroup();
    _debug(src_loc);
}

void InterfaceInner::PrimitiveRestartIndex(const GLuint& index, const SrcLoc& src_loc){
    glPrimitiveRestartIndex(*index);
    _debug(src_loc);
}

void InterfaceInner::ProgramBinary(const GLuint& program, const GLenum& binaryFormat, const GLdata& binary, const GLsizei& length, const SrcLoc& src_loc){
    glProgramBinary(*program, *binaryFormat, binary.get(), *length);
    _debug(src_loc);
}

void InterfaceInner::ProgramParameteri(const GLuint& program, const GLenum& pname, const GLint& value, const SrcLoc& src_loc){
    glProgramParameteri(*program, *pname, *value);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform1d(const GLuint& program, const GLint& location, const GLdouble& v0, const SrcLoc& src_loc){
    glProgramUniform1d(*program, *location, *v0);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform1dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    glProgramUniform1dv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform1f(const GLuint& program, const GLint& location, const GLfloat& v0, const SrcLoc& src_loc){
    glProgramUniform1f(*program, *location, *v0);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform1fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    glProgramUniform1fv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform1i(const GLuint& program, const GLint& location, const GLint& v0, const SrcLoc& src_loc){
    glProgramUniform1i(*program, *location, *v0);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform1iv(const GLuint& program, const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    glProgramUniform1iv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform1ui(const GLuint& program, const GLint& location, const GLuint& v0, const SrcLoc& src_loc){
    glProgramUniform1ui(*program, *location, *v0);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform1uiv(const GLuint& program, const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    glProgramUniform1uiv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform2d(const GLuint& program, const GLint& location, const GLdouble& v0, const GLdouble& v1, const SrcLoc& src_loc){
    glProgramUniform2d(*program, *location, *v0, *v1);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform2dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    glProgramUniform2dv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform2f(const GLuint& program, const GLint& location, const GLfloat& v0, const GLfloat& v1, const SrcLoc& src_loc){
    glProgramUniform2f(*program, *location, *v0, *v1);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform2fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    glProgramUniform2fv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform2i(const GLuint& program, const GLint& location, const GLint& v0, const GLint& v1, const SrcLoc& src_loc){
    glProgramUniform2i(*program, *location, *v0, *v1);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform2iv(const GLuint& program, const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    glProgramUniform2iv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform2ui(const GLuint& program, const GLint& location, const GLuint& v0, const GLuint& v1, const SrcLoc& src_loc){
    glProgramUniform2ui(*program, *location, *v0, *v1);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform2uiv(const GLuint& program, const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    glProgramUniform2uiv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform3d(const GLuint& program, const GLint& location, const GLdouble& v0, const GLdouble& v1, const GLdouble& v2, const SrcLoc& src_loc){
    glProgramUniform3d(*program, *location, *v0, *v1, *v2);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform3dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    glProgramUniform3dv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform3f(const GLuint& program, const GLint& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const SrcLoc& src_loc){
    glProgramUniform3f(*program, *location, *v0, *v1, *v2);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform3fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    glProgramUniform3fv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform3i(const GLuint& program, const GLint& location, const GLint& v0, const GLint& v1, const GLint& v2, const SrcLoc& src_loc){
    glProgramUniform3i(*program, *location, *v0, *v1, *v2);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform3iv(const GLuint& program, const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    glProgramUniform3iv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform3ui(const GLuint& program, const GLint& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const SrcLoc& src_loc){
    glProgramUniform3ui(*program, *location, *v0, *v1, *v2);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform3uiv(const GLuint& program, const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    glProgramUniform3uiv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform4d(const GLuint& program, const GLint& location, const GLdouble& v0, const GLdouble& v1, const GLdouble& v2, const GLdouble& v3, const SrcLoc& src_loc){
    glProgramUniform4d(*program, *location, *v0, *v1, *v2, *v3);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform4dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    glProgramUniform4dv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform4f(const GLuint& program, const GLint& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const GLfloat& v3, const SrcLoc& src_loc){
    glProgramUniform4f(*program, *location, *v0, *v1, *v2, *v3);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform4fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    glProgramUniform4fv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform4i(const GLuint& program, const GLint& location, const GLint& v0, const GLint& v1, const GLint& v2, const GLint& v3, const SrcLoc& src_loc){
    glProgramUniform4i(*program, *location, *v0, *v1, *v2, *v3);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform4iv(const GLuint& program, const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    glProgramUniform4iv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform4ui(const GLuint& program, const GLint& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const GLuint& v3, const SrcLoc& src_loc){
    glProgramUniform4ui(*program, *location, *v0, *v1, *v2, *v3);
    _debug(src_loc);
}

void InterfaceInner::ProgramUniform4uiv(const GLuint& program, const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    glProgramUniform4uiv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix2dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix2dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix2fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix2fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix2x3dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix2x3dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix2x3fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix2x3fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix2x4dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix2x4dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix2x4fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix2x4fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix3dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix3dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix3fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix3fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix3x2dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix3x2dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix3x2fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix3x2fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix3x4dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix3x4dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix3x4fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix3x4fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix4dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix4dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix4fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix4fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix4x2dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix4x2dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix4x2fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix4x2fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix4x3dv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix4x3dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProgramUniformMatrix4x3fv(const GLuint& program, const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glProgramUniformMatrix4x3fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::ProvokingVertex(const GLenum& mode, const SrcLoc& src_loc){
    glProvokingVertex(*mode);
    _debug(src_loc);
}

void InterfaceInner::PushDebugGroup(const GLenum& source, const GLuint& id, const GLsizei& length, const GLcharArr& message, const SrcLoc& src_loc){
    glPushDebugGroup(*source, *id, *length, message.get());
    _debug(src_loc);
}

void InterfaceInner::QueryCounter(const GLuint& id, const GLenum& target, const SrcLoc& src_loc){
    glQueryCounter(*id, *target);
    _debug(src_loc);
}

void InterfaceInner::ReadBuffer(const GLenum& src, const SrcLoc& src_loc){
    glReadBuffer(*src);
    _debug(src_loc);
}

void InterfaceInner::ReadPixels(const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    glReadPixels(*x, *y, *width, *height, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceInner::ReadnPixels(const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLenum& type, const GLsizei& bufSize, const GLdata& data, const SrcLoc& src_loc){
    glReadnPixels(*x, *y, *width, *height, *format, *type, *bufSize, data.get());
    _debug(src_loc);
}

void InterfaceInner::ReleaseShaderCompiler(const SrcLoc& src_loc){
    glReleaseShaderCompiler();
    _debug(src_loc);
}

void InterfaceInner::RenderbufferStorage(const GLenum& target, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    glRenderbufferStorage(*target, *internalformat, *width, *height);
    _debug(src_loc);
}

void InterfaceInner::RenderbufferStorageMultisample(const GLenum& target, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    glRenderbufferStorageMultisample(*target, *samples, *internalformat, *width, *height);
    _debug(src_loc);
}

void InterfaceInner::ResumeTransformFeedback(const SrcLoc& src_loc){
    glResumeTransformFeedback();
    _debug(src_loc);
}

void InterfaceInner::SampleCoverage(const GLfloat& value, const GLboolean& invert, const SrcLoc& src_loc){
    glSampleCoverage(*value, *invert);
    _debug(src_loc);
}

void InterfaceInner::SampleMaski(const GLuint& maskNumber, const GLbitfield& mask, const SrcLoc& src_loc){
    glSampleMaski(*maskNumber, *mask);
    _debug(src_loc);
}

void InterfaceInner::SamplerParameterIiv(const GLuint& sampler, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    glSamplerParameterIiv(*sampler, *pname, param.get());
    _debug(src_loc);
}

void InterfaceInner::SamplerParameterIuiv(const GLuint& sampler, const GLenum& pname, const GLuintArr& param, const SrcLoc& src_loc){
    glSamplerParameterIuiv(*sampler, *pname, param.get());
    _debug(src_loc);
}

void InterfaceInner::SamplerParameterf(const GLuint& sampler, const GLenum& pname, const GLfloat& param, const SrcLoc& src_loc){
    glSamplerParameterf(*sampler, *pname, *param);
    _debug(src_loc);
}

void InterfaceInner::SamplerParameterfv(const GLuint& sampler, const GLenum& pname, const GLfloatArr& param, const SrcLoc& src_loc){
    glSamplerParameterfv(*sampler, *pname, param.get());
    _debug(src_loc);
}

void InterfaceInner::SamplerParameteri(const GLuint& sampler, const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    glSamplerParameteri(*sampler, *pname, *param);
    _debug(src_loc);
}

void InterfaceInner::SamplerParameteriv(const GLuint& sampler, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    glSamplerParameteriv(*sampler, *pname, param.get());
    _debug(src_loc);
}

void InterfaceInner::Scissor(const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    glScissor(*x, *y, *width, *height);
    _debug(src_loc);
}

void InterfaceInner::ScissorArrayv(const GLuint& first, const GLsizei& count, const GLintArr& v, const SrcLoc& src_loc){
    glScissorArrayv(*first, *count, v.get());
    _debug(src_loc);
}

void InterfaceInner::ScissorIndexed(const GLuint& index, const GLint& left, const GLint& bottom, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    glScissorIndexed(*index, *left, *bottom, *width, *height);
    _debug(src_loc);
}

void InterfaceInner::ScissorIndexedv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    glScissorIndexedv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::ShaderBinary(const GLsizei& count, const GLuintArr& shaders, const GLenum& binaryFormat, const GLdata& binary, const GLsizei& length, const SrcLoc& src_loc){
    glShaderBinary(*count, shaders.get(), *binaryFormat, binary.get(), *length);
    _debug(src_loc);
}

void InterfaceInner::ShaderStorageBlockBinding(const GLuint& program, const GLuint& storageBlockIndex, const GLuint& storageBlockBinding, const SrcLoc& src_loc){
    glShaderStorageBlockBinding(*program, *storageBlockIndex, *storageBlockBinding);
    _debug(src_loc);
}

void InterfaceInner::SpecializeShader(const GLuint& shader, const GLcharArr& pEntryPoint, const GLuint& numSpecializationConstants, const GLuintArr& pConstantIndex, const GLuintArr& pConstantValue, const SrcLoc& src_loc){
    glSpecializeShader(*shader, pEntryPoint.get(), *numSpecializationConstants, pConstantIndex.get(), pConstantValue.get());
    _debug(src_loc);
}

void InterfaceInner::StencilFunc(const GLenum& func, const GLint& ref, const GLuint& mask, const SrcLoc& src_loc){
    glStencilFunc(*func, *ref, *mask);
    _debug(src_loc);
}

void InterfaceInner::StencilFuncSeparate(const GLenum& face, const GLenum& func, const GLint& ref, const GLuint& mask, const SrcLoc& src_loc){
    glStencilFuncSeparate(*face, *func, *ref, *mask);
    _debug(src_loc);
}

void InterfaceInner::StencilMask(const GLuint& mask, const SrcLoc& src_loc){
    glStencilMask(*mask);
    _debug(src_loc);
}

void InterfaceInner::StencilMaskSeparate(const GLenum& face, const GLuint& mask, const SrcLoc& src_loc){
    glStencilMaskSeparate(*face, *mask);
    _debug(src_loc);
}

void InterfaceInner::StencilOp(const GLenum& fail, const GLenum& zfail, const GLenum& zpass, const SrcLoc& src_loc){
    glStencilOp(*fail, *zfail, *zpass);
    _debug(src_loc);
}

void InterfaceInner::StencilOpSeparate(const GLenum& face, const GLenum& sfail, const GLenum& dpfail, const GLenum& dppass, const SrcLoc& src_loc){
    glStencilOpSeparate(*face, *sfail, *dpfail, *dppass);
    _debug(src_loc);
}

void InterfaceInner::TexBuffer(const GLenum& target, const GLenum& internalformat, const GLuint& buffer, const SrcLoc& src_loc){
    glTexBuffer(*target, *internalformat, *buffer);
    _debug(src_loc);
}

void InterfaceInner::TexBufferRange(const GLenum& target, const GLenum& internalformat, const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const SrcLoc& src_loc){
    glTexBufferRange(*target, *internalformat, *buffer, *offset, *size);
    _debug(src_loc);
}

void InterfaceInner::TexImage1D(const GLenum& target, const GLint& level, const GLint& internalformat, const GLsizei& width, const GLint& border, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    glTexImage1D(*target, *level, *internalformat, *width, *border, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceInner::TexImage2D(const GLenum& target, const GLint& level, const GLint& internalformat, const GLsizei& width, const GLsizei& height, const GLint& border, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    glTexImage2D(*target, *level, *internalformat, *width, *height, *border, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceInner::TexImage2DMultisample(const GLenum& target, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    glTexImage2DMultisample(*target, *samples, *internalformat, *width, *height, *fixedsamplelocations);
    _debug(src_loc);
}

void InterfaceInner::TexImage3D(const GLenum& target, const GLint& level, const GLint& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLint& border, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    glTexImage3D(*target, *level, *internalformat, *width, *height, *depth, *border, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceInner::TexImage3DMultisample(const GLenum& target, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    glTexImage3DMultisample(*target, *samples, *internalformat, *width, *height, *depth, *fixedsamplelocations);
    _debug(src_loc);
}

void InterfaceInner::TexParameterIiv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glTexParameterIiv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::TexParameterIuiv(const GLenum& target, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    glTexParameterIuiv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::TexParameterf(const GLenum& target, const GLenum& pname, const GLfloat& param, const SrcLoc& src_loc){
    glTexParameterf(*target, *pname, *param);
    _debug(src_loc);
}

void InterfaceInner::TexParameterfv(const GLenum& target, const GLenum& pname, const GLfloatArr& params, const SrcLoc& src_loc){
    glTexParameterfv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::TexParameteri(const GLenum& target, const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    glTexParameteri(*target, *pname, *param);
    _debug(src_loc);
}

void InterfaceInner::TexParameteriv(const GLenum& target, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glTexParameteriv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::TexStorage1D(const GLenum& target, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const SrcLoc& src_loc){
    glTexStorage1D(*target, *levels, *internalformat, *width);
    _debug(src_loc);
}

void InterfaceInner::TexStorage2D(const GLenum& target, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    glTexStorage2D(*target, *levels, *internalformat, *width, *height);
    _debug(src_loc);
}

void InterfaceInner::TexStorage2DMultisample(const GLenum& target, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    glTexStorage2DMultisample(*target, *samples, *internalformat, *width, *height, *fixedsamplelocations);
    _debug(src_loc);
}

void InterfaceInner::TexStorage3D(const GLenum& target, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const SrcLoc& src_loc){
    glTexStorage3D(*target, *levels, *internalformat, *width, *height, *depth);
    _debug(src_loc);
}

void InterfaceInner::TexStorage3DMultisample(const GLenum& target, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    glTexStorage3DMultisample(*target, *samples, *internalformat, *width, *height, *depth, *fixedsamplelocations);
    _debug(src_loc);
}

void InterfaceInner::TexSubImage1D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLsizei& width, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    glTexSubImage1D(*target, *level, *xoffset, *width, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceInner::TexSubImage2D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    glTexSubImage2D(*target, *level, *xoffset, *yoffset, *width, *height, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceInner::TexSubImage3D(const GLenum& target, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    glTexSubImage3D(*target, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceInner::TextureBarrier(const SrcLoc& src_loc){
    glTextureBarrier();
    _debug(src_loc);
}

void InterfaceInner::TextureBuffer(const GLuint& texture, const GLenum& internalformat, const GLuint& buffer, const SrcLoc& src_loc){
    glTextureBuffer(*texture, *internalformat, *buffer);
    _debug(src_loc);
}

void InterfaceInner::TextureBufferRange(const GLuint& texture, const GLenum& internalformat, const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const SrcLoc& src_loc){
    glTextureBufferRange(*texture, *internalformat, *buffer, *offset, *size);
    _debug(src_loc);
}

void InterfaceInner::TextureParameterIiv(const GLuint& texture, const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    glTextureParameterIiv(*texture, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::TextureParameterIuiv(const GLuint& texture, const GLenum& pname, const GLuintArr& params, const SrcLoc& src_loc){
    glTextureParameterIuiv(*texture, *pname, params.get());
    _debug(src_loc);
}

void InterfaceInner::TextureParameterf(const GLuint& texture, const GLenum& pname, const GLfloat& param, const SrcLoc& src_loc){
    glTextureParameterf(*texture, *pname, *param);
    _debug(src_loc);
}

void InterfaceInner::TextureParameterfv(const GLuint& texture, const GLenum& pname, const GLfloatArr& param, const SrcLoc& src_loc){
    glTextureParameterfv(*texture, *pname, param.get());
    _debug(src_loc);
}

void InterfaceInner::TextureParameteri(const GLuint& texture, const GLenum& pname, const GLint& param, const SrcLoc& src_loc){
    glTextureParameteri(*texture, *pname, *param);
    _debug(src_loc);
}

void InterfaceInner::TextureParameteriv(const GLuint& texture, const GLenum& pname, const GLintArr& param, const SrcLoc& src_loc){
    glTextureParameteriv(*texture, *pname, param.get());
    _debug(src_loc);
}

void InterfaceInner::TextureStorage1D(const GLuint& texture, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const SrcLoc& src_loc){
    glTextureStorage1D(*texture, *levels, *internalformat, *width);
    _debug(src_loc);
}

void InterfaceInner::TextureStorage2D(const GLuint& texture, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    glTextureStorage2D(*texture, *levels, *internalformat, *width, *height);
    _debug(src_loc);
}

void InterfaceInner::TextureStorage2DMultisample(const GLuint& texture, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    glTextureStorage2DMultisample(*texture, *samples, *internalformat, *width, *height, *fixedsamplelocations);
    _debug(src_loc);
}

void InterfaceInner::TextureStorage3D(const GLuint& texture, const GLsizei& levels, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const SrcLoc& src_loc){
    glTextureStorage3D(*texture, *levels, *internalformat, *width, *height, *depth);
    _debug(src_loc);
}

void InterfaceInner::TextureStorage3DMultisample(const GLuint& texture, const GLsizei& samples, const GLenum& internalformat, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLboolean& fixedsamplelocations, const SrcLoc& src_loc){
    glTextureStorage3DMultisample(*texture, *samples, *internalformat, *width, *height, *depth, *fixedsamplelocations);
    _debug(src_loc);
}

void InterfaceInner::TextureSubImage1D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLsizei& width, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    glTextureSubImage1D(*texture, *level, *xoffset, *width, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceInner::TextureSubImage2D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLsizei& width, const GLsizei& height, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    glTextureSubImage2D(*texture, *level, *xoffset, *yoffset, *width, *height, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceInner::TextureSubImage3D(const GLuint& texture, const GLint& level, const GLint& xoffset, const GLint& yoffset, const GLint& zoffset, const GLsizei& width, const GLsizei& height, const GLsizei& depth, const GLenum& format, const GLenum& type, const GLdata& pixels, const SrcLoc& src_loc){
    glTextureSubImage3D(*texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceInner::TextureView(const GLuint& texture, const GLenum& target, const GLuint& origtexture, const GLenum& internalformat, const GLuint& minlevel, const GLuint& numlevels, const GLuint& minlayer, const GLuint& numlayers, const SrcLoc& src_loc){
    glTextureView(*texture, *target, *origtexture, *internalformat, *minlevel, *numlevels, *minlayer, *numlayers);
    _debug(src_loc);
}

void InterfaceInner::TransformFeedbackBufferBase(const GLuint& xfb, const GLuint& index, const GLuint& buffer, const SrcLoc& src_loc){
    glTransformFeedbackBufferBase(*xfb, *index, *buffer);
    _debug(src_loc);
}

void InterfaceInner::TransformFeedbackBufferRange(const GLuint& xfb, const GLuint& index, const GLuint& buffer, const GLintptr& offset, const GLsizeiptr& size, const SrcLoc& src_loc){
    glTransformFeedbackBufferRange(*xfb, *index, *buffer, *offset, *size);
    _debug(src_loc);
}

void InterfaceInner::Uniform1d(const GLint& location, const GLdouble& x, const SrcLoc& src_loc){
    glUniform1d(*location, *x);
    _debug(src_loc);
}

void InterfaceInner::Uniform1dv(const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    glUniform1dv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::Uniform1f(const GLint& location, const GLfloat& v0, const SrcLoc& src_loc){
    glUniform1f(*location, *v0);
    _debug(src_loc);
}

void InterfaceInner::Uniform1fv(const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    glUniform1fv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::Uniform1i(const GLint& location, const GLint& v0, const SrcLoc& src_loc){
    glUniform1i(*location, *v0);
    _debug(src_loc);
}

void InterfaceInner::Uniform1iv(const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    glUniform1iv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::Uniform1ui(const GLint& location, const GLuint& v0, const SrcLoc& src_loc){
    glUniform1ui(*location, *v0);
    _debug(src_loc);
}

void InterfaceInner::Uniform1uiv(const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    glUniform1uiv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::Uniform2d(const GLint& location, const GLdouble& x, const GLdouble& y, const SrcLoc& src_loc){
    glUniform2d(*location, *x, *y);
    _debug(src_loc);
}

void InterfaceInner::Uniform2dv(const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    glUniform2dv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::Uniform2f(const GLint& location, const GLfloat& v0, const GLfloat& v1, const SrcLoc& src_loc){
    glUniform2f(*location, *v0, *v1);
    _debug(src_loc);
}

void InterfaceInner::Uniform2fv(const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    glUniform2fv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::Uniform2i(const GLint& location, const GLint& v0, const GLint& v1, const SrcLoc& src_loc){
    glUniform2i(*location, *v0, *v1);
    _debug(src_loc);
}

void InterfaceInner::Uniform2iv(const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    glUniform2iv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::Uniform2ui(const GLint& location, const GLuint& v0, const GLuint& v1, const SrcLoc& src_loc){
    glUniform2ui(*location, *v0, *v1);
    _debug(src_loc);
}

void InterfaceInner::Uniform2uiv(const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    glUniform2uiv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::Uniform3d(const GLint& location, const GLdouble& x, const GLdouble& y, const GLdouble& z, const SrcLoc& src_loc){
    glUniform3d(*location, *x, *y, *z);
    _debug(src_loc);
}

void InterfaceInner::Uniform3dv(const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    glUniform3dv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::Uniform3f(const GLint& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const SrcLoc& src_loc){
    glUniform3f(*location, *v0, *v1, *v2);
    _debug(src_loc);
}

void InterfaceInner::Uniform3fv(const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    glUniform3fv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::Uniform3i(const GLint& location, const GLint& v0, const GLint& v1, const GLint& v2, const SrcLoc& src_loc){
    glUniform3i(*location, *v0, *v1, *v2);
    _debug(src_loc);
}

void InterfaceInner::Uniform3iv(const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    glUniform3iv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::Uniform3ui(const GLint& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const SrcLoc& src_loc){
    glUniform3ui(*location, *v0, *v1, *v2);
    _debug(src_loc);
}

void InterfaceInner::Uniform3uiv(const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    glUniform3uiv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::Uniform4d(const GLint& location, const GLdouble& x, const GLdouble& y, const GLdouble& z, const GLdouble& w, const SrcLoc& src_loc){
    glUniform4d(*location, *x, *y, *z, *w);
    _debug(src_loc);
}

void InterfaceInner::Uniform4dv(const GLint& location, const GLsizei& count, const GLdoubleArr& value, const SrcLoc& src_loc){
    glUniform4dv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::Uniform4f(const GLint& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const GLfloat& v3, const SrcLoc& src_loc){
    glUniform4f(*location, *v0, *v1, *v2, *v3);
    _debug(src_loc);
}

void InterfaceInner::Uniform4fv(const GLint& location, const GLsizei& count, const GLfloatArr& value, const SrcLoc& src_loc){
    glUniform4fv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::Uniform4i(const GLint& location, const GLint& v0, const GLint& v1, const GLint& v2, const GLint& v3, const SrcLoc& src_loc){
    glUniform4i(*location, *v0, *v1, *v2, *v3);
    _debug(src_loc);
}

void InterfaceInner::Uniform4iv(const GLint& location, const GLsizei& count, const GLintArr& value, const SrcLoc& src_loc){
    glUniform4iv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::Uniform4ui(const GLint& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const GLuint& v3, const SrcLoc& src_loc){
    glUniform4ui(*location, *v0, *v1, *v2, *v3);
    _debug(src_loc);
}

void InterfaceInner::Uniform4uiv(const GLint& location, const GLsizei& count, const GLuintArr& value, const SrcLoc& src_loc){
    glUniform4uiv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformBlockBinding(const GLuint& program, const GLuint& uniformBlockIndex, const GLuint& uniformBlockBinding, const SrcLoc& src_loc){
    glUniformBlockBinding(*program, *uniformBlockIndex, *uniformBlockBinding);
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix2dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glUniformMatrix2dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix2fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glUniformMatrix2fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix2x3dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glUniformMatrix2x3dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix2x3fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glUniformMatrix2x3fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix2x4dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glUniformMatrix2x4dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix2x4fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glUniformMatrix2x4fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix3dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glUniformMatrix3dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix3fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glUniformMatrix3fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix3x2dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glUniformMatrix3x2dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix3x2fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glUniformMatrix3x2fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix3x4dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glUniformMatrix3x4dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix3x4fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glUniformMatrix3x4fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix4dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glUniformMatrix4dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix4fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glUniformMatrix4fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix4x2dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glUniformMatrix4x2dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix4x2fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glUniformMatrix4x2fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix4x3dv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLdoubleArr& value, const SrcLoc& src_loc){
    glUniformMatrix4x3dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformMatrix4x3fv(const GLint& location, const GLsizei& count, const GLboolean& transpose, const GLfloatArr& value, const SrcLoc& src_loc){
    glUniformMatrix4x3fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceInner::UniformSubroutinesuiv(const GLenum& shadertype, const GLsizei& count, const GLuintArr& indices, const SrcLoc& src_loc){
    glUniformSubroutinesuiv(*shadertype, *count, indices.get());
    _debug(src_loc);
}

const GLbooleanRes& InterfaceInner::UnmapBuffer(const GLenum& target, const SrcLoc& src_loc){
    const GLbooleanRes& dst(new const GLbooleanRes&::element_type(glUnmapBuffer(*target)));
    _debug(src_loc);
    return dst;
}

const GLbooleanRes& InterfaceInner::UnmapNamedBuffer(const GLuint& buffer, const SrcLoc& src_loc){
    const GLbooleanRes& dst(new const GLbooleanRes&::element_type(glUnmapNamedBuffer(*buffer)));
    _debug(src_loc);
    return dst;
}

void InterfaceInner::UseProgram(const GLuint& program, const SrcLoc& src_loc){
    glUseProgram(*program);
    _debug(src_loc);
}

void InterfaceInner::UseProgramStages(const GLuint& pipeline, const GLbitfield& stages, const GLuint& program, const SrcLoc& src_loc){
    glUseProgramStages(*pipeline, *stages, *program);
    _debug(src_loc);
}

void InterfaceInner::ValidateProgram(const GLuint& program, const SrcLoc& src_loc){
    glValidateProgram(*program);
    _debug(src_loc);
}

void InterfaceInner::ValidateProgramPipeline(const GLuint& pipeline, const SrcLoc& src_loc){
    glValidateProgramPipeline(*pipeline);
    _debug(src_loc);
}

void InterfaceInner::VertexArrayAttribBinding(const GLuint& vaobj, const GLuint& attribindex, const GLuint& bindingindex, const SrcLoc& src_loc){
    glVertexArrayAttribBinding(*vaobj, *attribindex, *bindingindex);
    _debug(src_loc);
}

void InterfaceInner::VertexArrayAttribFormat(const GLuint& vaobj, const GLuint& attribindex, const GLint& size, const GLenum& type, const GLboolean& normalized, const GLuint& relativeoffset, const SrcLoc& src_loc){
    glVertexArrayAttribFormat(*vaobj, *attribindex, *size, *type, *normalized, *relativeoffset);
    _debug(src_loc);
}

void InterfaceInner::VertexArrayAttribIFormat(const GLuint& vaobj, const GLuint& attribindex, const GLint& size, const GLenum& type, const GLuint& relativeoffset, const SrcLoc& src_loc){
    glVertexArrayAttribIFormat(*vaobj, *attribindex, *size, *type, *relativeoffset);
    _debug(src_loc);
}

void InterfaceInner::VertexArrayAttribLFormat(const GLuint& vaobj, const GLuint& attribindex, const GLint& size, const GLenum& type, const GLuint& relativeoffset, const SrcLoc& src_loc){
    glVertexArrayAttribLFormat(*vaobj, *attribindex, *size, *type, *relativeoffset);
    _debug(src_loc);
}

void InterfaceInner::VertexArrayBindingDivisor(const GLuint& vaobj, const GLuint& bindingindex, const GLuint& divisor, const SrcLoc& src_loc){
    glVertexArrayBindingDivisor(*vaobj, *bindingindex, *divisor);
    _debug(src_loc);
}

void InterfaceInner::VertexArrayElementBuffer(const GLuint& vaobj, const GLuint& buffer, const SrcLoc& src_loc){
    glVertexArrayElementBuffer(*vaobj, *buffer);
    _debug(src_loc);
}

void InterfaceInner::VertexArrayVertexBuffer(const GLuint& vaobj, const GLuint& bindingindex, const GLuint& buffer, const GLintptr& offset, const GLsizei& stride, const SrcLoc& src_loc){
    glVertexArrayVertexBuffer(*vaobj, *bindingindex, *buffer, *offset, *stride);
    _debug(src_loc);
}

void InterfaceInner::VertexArrayVertexBuffers(const GLuint& vaobj, const GLuint& first, const GLsizei& count, const GLuintArr& buffers, const GLintptrArr& offsets, const GLsizeiArr& strides, const SrcLoc& src_loc){
    glVertexArrayVertexBuffers(*vaobj, *first, *count, buffers.get(), offsets.get(), strides.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib1d(const GLuint& index, const GLdouble& x, const SrcLoc& src_loc){
    glVertexAttrib1d(*index, *x);
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib1dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    glVertexAttrib1dv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib1f(const GLuint& index, const GLfloat& x, const SrcLoc& src_loc){
    glVertexAttrib1f(*index, *x);
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib1fv(const GLuint& index, const GLfloatArr& v, const SrcLoc& src_loc){
    glVertexAttrib1fv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib1s(const GLuint& index, const GLshort& x, const SrcLoc& src_loc){
    glVertexAttrib1s(*index, *x);
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib1sv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    glVertexAttrib1sv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib2d(const GLuint& index, const GLdouble& x, const GLdouble& y, const SrcLoc& src_loc){
    glVertexAttrib2d(*index, *x, *y);
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib2dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    glVertexAttrib2dv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib2f(const GLuint& index, const GLfloat& x, const GLfloat& y, const SrcLoc& src_loc){
    glVertexAttrib2f(*index, *x, *y);
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib2fv(const GLuint& index, const GLfloatArr& v, const SrcLoc& src_loc){
    glVertexAttrib2fv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib2s(const GLuint& index, const GLshort& x, const GLshort& y, const SrcLoc& src_loc){
    glVertexAttrib2s(*index, *x, *y);
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib2sv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    glVertexAttrib2sv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib3d(const GLuint& index, const GLdouble& x, const GLdouble& y, const GLdouble& z, const SrcLoc& src_loc){
    glVertexAttrib3d(*index, *x, *y, *z);
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib3dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    glVertexAttrib3dv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib3f(const GLuint& index, const GLfloat& x, const GLfloat& y, const GLfloat& z, const SrcLoc& src_loc){
    glVertexAttrib3f(*index, *x, *y, *z);
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib3fv(const GLuint& index, const GLfloatArr& v, const SrcLoc& src_loc){
    glVertexAttrib3fv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib3s(const GLuint& index, const GLshort& x, const GLshort& y, const GLshort& z, const SrcLoc& src_loc){
    glVertexAttrib3s(*index, *x, *y, *z);
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib3sv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    glVertexAttrib3sv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4Nbv(const GLuint& index, const GLbyte& v, const SrcLoc& src_loc){
    glVertexAttrib4Nbv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4Niv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    glVertexAttrib4Niv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4Nsv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    glVertexAttrib4Nsv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4Nub(const GLuint& index, const GLubyte& x, const GLubyte& y, const GLubyte& z, const GLubyte& w, const SrcLoc& src_loc){
    glVertexAttrib4Nub(*index, *x, *y, *z, *w);
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4Nubv(const GLuint& index, const GLubyte& v, const SrcLoc& src_loc){
    glVertexAttrib4Nubv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4Nuiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    glVertexAttrib4Nuiv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4Nusv(const GLuint& index, const GLushort& v, const SrcLoc& src_loc){
    glVertexAttrib4Nusv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4bv(const GLuint& index, const GLbyte& v, const SrcLoc& src_loc){
    glVertexAttrib4bv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4d(const GLuint& index, const GLdouble& x, const GLdouble& y, const GLdouble& z, const GLdouble& w, const SrcLoc& src_loc){
    glVertexAttrib4d(*index, *x, *y, *z, *w);
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    glVertexAttrib4dv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4f(const GLuint& index, const GLfloat& x, const GLfloat& y, const GLfloat& z, const GLfloat& w, const SrcLoc& src_loc){
    glVertexAttrib4f(*index, *x, *y, *z, *w);
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4fv(const GLuint& index, const GLfloatArr& v, const SrcLoc& src_loc){
    glVertexAttrib4fv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4iv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    glVertexAttrib4iv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4s(const GLuint& index, const GLshort& x, const GLshort& y, const GLshort& z, const GLshort& w, const SrcLoc& src_loc){
    glVertexAttrib4s(*index, *x, *y, *z, *w);
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4sv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    glVertexAttrib4sv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4ubv(const GLuint& index, const GLubyte& v, const SrcLoc& src_loc){
    glVertexAttrib4ubv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4uiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    glVertexAttrib4uiv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttrib4usv(const GLuint& index, const GLushort& v, const SrcLoc& src_loc){
    glVertexAttrib4usv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribBinding(const GLuint& attribindex, const GLuint& bindingindex, const SrcLoc& src_loc){
    glVertexAttribBinding(*attribindex, *bindingindex);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribDivisor(const GLuint& index, const GLuint& divisor, const SrcLoc& src_loc){
    glVertexAttribDivisor(*index, *divisor);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribFormat(const GLuint& attribindex, const GLint& size, const GLenum& type, const GLboolean& normalized, const GLuint& relativeoffset, const SrcLoc& src_loc){
    glVertexAttribFormat(*attribindex, *size, *type, *normalized, *relativeoffset);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI1i(const GLuint& index, const GLint& x, const SrcLoc& src_loc){
    glVertexAttribI1i(*index, *x);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI1iv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    glVertexAttribI1iv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI1ui(const GLuint& index, const GLuint& x, const SrcLoc& src_loc){
    glVertexAttribI1ui(*index, *x);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI1uiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    glVertexAttribI1uiv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI2i(const GLuint& index, const GLint& x, const GLint& y, const SrcLoc& src_loc){
    glVertexAttribI2i(*index, *x, *y);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI2iv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    glVertexAttribI2iv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI2ui(const GLuint& index, const GLuint& x, const GLuint& y, const SrcLoc& src_loc){
    glVertexAttribI2ui(*index, *x, *y);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI2uiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    glVertexAttribI2uiv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI3i(const GLuint& index, const GLint& x, const GLint& y, const GLint& z, const SrcLoc& src_loc){
    glVertexAttribI3i(*index, *x, *y, *z);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI3iv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    glVertexAttribI3iv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI3ui(const GLuint& index, const GLuint& x, const GLuint& y, const GLuint& z, const SrcLoc& src_loc){
    glVertexAttribI3ui(*index, *x, *y, *z);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI3uiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    glVertexAttribI3uiv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI4bv(const GLuint& index, const GLbyte& v, const SrcLoc& src_loc){
    glVertexAttribI4bv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI4i(const GLuint& index, const GLint& x, const GLint& y, const GLint& z, const GLint& w, const SrcLoc& src_loc){
    glVertexAttribI4i(*index, *x, *y, *z, *w);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI4iv(const GLuint& index, const GLintArr& v, const SrcLoc& src_loc){
    glVertexAttribI4iv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI4sv(const GLuint& index, const GLshort& v, const SrcLoc& src_loc){
    glVertexAttribI4sv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI4ubv(const GLuint& index, const GLubyte& v, const SrcLoc& src_loc){
    glVertexAttribI4ubv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI4ui(const GLuint& index, const GLuint& x, const GLuint& y, const GLuint& z, const GLuint& w, const SrcLoc& src_loc){
    glVertexAttribI4ui(*index, *x, *y, *z, *w);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI4uiv(const GLuint& index, const GLuintArr& v, const SrcLoc& src_loc){
    glVertexAttribI4uiv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribI4usv(const GLuint& index, const GLushort& v, const SrcLoc& src_loc){
    glVertexAttribI4usv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribIFormat(const GLuint& attribindex, const GLint& size, const GLenum& type, const GLuint& relativeoffset, const SrcLoc& src_loc){
    glVertexAttribIFormat(*attribindex, *size, *type, *relativeoffset);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribIPointer(const GLuint& index, const GLint& size, const GLenum& type, const GLsizei& stride, const GLdata& pointer, const SrcLoc& src_loc){
    glVertexAttribIPointer(*index, *size, *type, *stride, pointer.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribL1d(const GLuint& index, const GLdouble& x, const SrcLoc& src_loc){
    glVertexAttribL1d(*index, *x);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribL1dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    glVertexAttribL1dv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribL2d(const GLuint& index, const GLdouble& x, const GLdouble& y, const SrcLoc& src_loc){
    glVertexAttribL2d(*index, *x, *y);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribL2dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    glVertexAttribL2dv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribL3d(const GLuint& index, const GLdouble& x, const GLdouble& y, const GLdouble& z, const SrcLoc& src_loc){
    glVertexAttribL3d(*index, *x, *y, *z);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribL3dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    glVertexAttribL3dv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribL4d(const GLuint& index, const GLdouble& x, const GLdouble& y, const GLdouble& z, const GLdouble& w, const SrcLoc& src_loc){
    glVertexAttribL4d(*index, *x, *y, *z, *w);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribL4dv(const GLuint& index, const GLdoubleArr& v, const SrcLoc& src_loc){
    glVertexAttribL4dv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribLFormat(const GLuint& attribindex, const GLint& size, const GLenum& type, const GLuint& relativeoffset, const SrcLoc& src_loc){
    glVertexAttribLFormat(*attribindex, *size, *type, *relativeoffset);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribLPointer(const GLuint& index, const GLint& size, const GLenum& type, const GLsizei& stride, const GLdata& pointer, const SrcLoc& src_loc){
    glVertexAttribLPointer(*index, *size, *type, *stride, pointer.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribP1ui(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuint& value, const SrcLoc& src_loc){
    glVertexAttribP1ui(*index, *type, *normalized, *value);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribP1uiv(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuintArr& value, const SrcLoc& src_loc){
    glVertexAttribP1uiv(*index, *type, *normalized, value.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribP2ui(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuint& value, const SrcLoc& src_loc){
    glVertexAttribP2ui(*index, *type, *normalized, *value);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribP2uiv(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuintArr& value, const SrcLoc& src_loc){
    glVertexAttribP2uiv(*index, *type, *normalized, value.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribP3ui(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuint& value, const SrcLoc& src_loc){
    glVertexAttribP3ui(*index, *type, *normalized, *value);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribP3uiv(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuintArr& value, const SrcLoc& src_loc){
    glVertexAttribP3uiv(*index, *type, *normalized, value.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribP4ui(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuint& value, const SrcLoc& src_loc){
    glVertexAttribP4ui(*index, *type, *normalized, *value);
    _debug(src_loc);
}

void InterfaceInner::VertexAttribP4uiv(const GLuint& index, const GLenum& type, const GLboolean& normalized, const GLuintArr& value, const SrcLoc& src_loc){
    glVertexAttribP4uiv(*index, *type, *normalized, value.get());
    _debug(src_loc);
}

void InterfaceInner::VertexAttribPointer(const GLuint& index, const GLint& size, const GLenum& type, const GLboolean& normalized, const GLsizei& stride, const GLdata& pointer, const SrcLoc& src_loc){
    glVertexAttribPointer(*index, *size, *type, *normalized, *stride, pointer.get());
    _debug(src_loc);
}

void InterfaceInner::VertexBindingDivisor(const GLuint& bindingindex, const GLuint& divisor, const SrcLoc& src_loc){
    glVertexBindingDivisor(*bindingindex, *divisor);
    _debug(src_loc);
}

void InterfaceInner::Viewport(const GLint& x, const GLint& y, const GLsizei& width, const GLsizei& height, const SrcLoc& src_loc){
    glViewport(*x, *y, *width, *height);
    _debug(src_loc);
}

void InterfaceInner::ViewportArrayv(const GLuint& first, const GLsizei& count, const GLfloatArr& v, const SrcLoc& src_loc){
    glViewportArrayv(*first, *count, v.get());
    _debug(src_loc);
}

void InterfaceInner::ViewportIndexedf(const GLuint& index, const GLfloat& x, const GLfloat& y, const GLfloat& w, const GLfloat& h, const SrcLoc& src_loc){
    glViewportIndexedf(*index, *x, *y, *w, *h);
    _debug(src_loc);
}

void InterfaceInner::ViewportIndexedfv(const GLuint& index, const GLfloatArr& v, const SrcLoc& src_loc){
    glViewportIndexedfv(*index, v.get());
    _debug(src_loc);
}

void InterfaceInner::WaitSync(const GLsync& sync, const GLbitfield& flags, const GLuint64& timeout, const SrcLoc& src_loc){
    glWaitSync(*sync, *flags, *timeout);
    _debug(src_loc);
}
