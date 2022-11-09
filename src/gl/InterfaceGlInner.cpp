#include "gl/InterfaceGlInner.hpp"

#include "glad/gl.h"

using namespace glwpp;

template<typename T>
using sptr = std::shared_ptr<T>;

InterfaceGlInner::InterfaceGlInner(Context* ctx, const std::function<void(const SrcLoc&)> debug) :
    InterfaceGl(ctx, debug){
}

InterfaceGlInner::~InterfaceGlInner(){
}

void InterfaceGlInner::ActiveShaderProgram(GLuint pipeline, GLuint program, GLsrc src_loc){
    glActiveShaderProgram(*pipeline, *program);
    _debug(src_loc);
}

void InterfaceGlInner::ActiveTexture(GLenum texture, GLsrc src_loc){
    glActiveTexture(*texture);
    _debug(src_loc);
}

void InterfaceGlInner::AttachShader(GLuint program, GLuint shader, GLsrc src_loc){
    glAttachShader(*program, *shader);
    _debug(src_loc);
}

void InterfaceGlInner::BeginConditionalRender(GLuint id, GLenum mode, GLsrc src_loc){
    glBeginConditionalRender(*id, *mode);
    _debug(src_loc);
}

void InterfaceGlInner::BeginQuery(GLenum target, GLuint id, GLsrc src_loc){
    glBeginQuery(*target, *id);
    _debug(src_loc);
}

void InterfaceGlInner::BeginQueryIndexed(GLenum target, GLuint index, GLuint id, GLsrc src_loc){
    glBeginQueryIndexed(*target, *index, *id);
    _debug(src_loc);
}

void InterfaceGlInner::BeginTransformFeedback(GLenum primitiveMode, GLsrc src_loc){
    glBeginTransformFeedback(*primitiveMode);
    _debug(src_loc);
}

void InterfaceGlInner::BindAttribLocation(GLuint program, GLuint index, GLcharArr name, GLsrc src_loc){
    glBindAttribLocation(*program, *index, name.get());
    _debug(src_loc);
}

void InterfaceGlInner::BindBuffer(GLenum target, GLuint buffer, GLsrc src_loc){
    glBindBuffer(*target, *buffer);
    _debug(src_loc);
}

void InterfaceGlInner::BindBufferBase(GLenum target, GLuint index, GLuint buffer, GLsrc src_loc){
    glBindBufferBase(*target, *index, *buffer);
    _debug(src_loc);
}

void InterfaceGlInner::BindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr& offset, GLsizeiptr& size, GLsrc src_loc){
    glBindBufferRange(*target, *index, *buffer, *offset, *size);
    _debug(src_loc);
}

void InterfaceGlInner::BindBuffersBase(GLenum target, GLuint first, GLsizei count, GLuintArr buffers, GLsrc src_loc){
    glBindBuffersBase(*target, *first, *count, buffers.get());
    _debug(src_loc);
}

void InterfaceGlInner::BindBuffersRange(GLenum target, GLuint first, GLsizei count, GLuintArr buffers, GLintptrArr& offsets, GLsizeiptrArr& sizes, GLsrc src_loc){
    glBindBuffersRange(*target, *first, *count, buffers.get(), offsets.get(), sizes.get());
    _debug(src_loc);
}

void InterfaceGlInner::BindFragDataLocation(GLuint program, GLuint color, GLcharArr name, GLsrc src_loc){
    glBindFragDataLocation(*program, *color, name.get());
    _debug(src_loc);
}

void InterfaceGlInner::BindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, GLcharArr name, GLsrc src_loc){
    glBindFragDataLocationIndexed(*program, *colorNumber, *index, name.get());
    _debug(src_loc);
}

void InterfaceGlInner::BindFramebuffer(GLenum target, GLuint framebuffer, GLsrc src_loc){
    glBindFramebuffer(*target, *framebuffer);
    _debug(src_loc);
}

void InterfaceGlInner::BindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean& layered, GLint layer, GLenum access, GLenum format, GLsrc src_loc){
    glBindImageTexture(*unit, *texture, *level, *layered, *layer, *access, *format);
    _debug(src_loc);
}

void InterfaceGlInner::BindImageTextures(GLuint first, GLsizei count, GLuintArr textures, GLsrc src_loc){
    glBindImageTextures(*first, *count, textures.get());
    _debug(src_loc);
}

void InterfaceGlInner::BindProgramPipeline(GLuint pipeline, GLsrc src_loc){
    glBindProgramPipeline(*pipeline);
    _debug(src_loc);
}

void InterfaceGlInner::BindRenderbuffer(GLenum target, GLuint renderbuffer, GLsrc src_loc){
    glBindRenderbuffer(*target, *renderbuffer);
    _debug(src_loc);
}

void InterfaceGlInner::BindSampler(GLuint unit, GLuint sampler, GLsrc src_loc){
    glBindSampler(*unit, *sampler);
    _debug(src_loc);
}

void InterfaceGlInner::BindSamplers(GLuint first, GLsizei count, GLuintArr samplers, GLsrc src_loc){
    glBindSamplers(*first, *count, samplers.get());
    _debug(src_loc);
}

void InterfaceGlInner::BindTexture(GLenum target, GLuint texture, GLsrc src_loc){
    glBindTexture(*target, *texture);
    _debug(src_loc);
}

void InterfaceGlInner::BindTextureUnit(GLuint unit, GLuint texture, GLsrc src_loc){
    glBindTextureUnit(*unit, *texture);
    _debug(src_loc);
}

void InterfaceGlInner::BindTextures(GLuint first, GLsizei count, GLuintArr textures, GLsrc src_loc){
    glBindTextures(*first, *count, textures.get());
    _debug(src_loc);
}

void InterfaceGlInner::BindTransformFeedback(GLenum target, GLuint id, GLsrc src_loc){
    glBindTransformFeedback(*target, *id);
    _debug(src_loc);
}

void InterfaceGlInner::BindVertexArray(GLuint array, GLsrc src_loc){
    glBindVertexArray(*array);
    _debug(src_loc);
}

void InterfaceGlInner::BindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride, GLsrc src_loc){
    glBindVertexBuffer(*bindingindex, *buffer, *offset, *stride);
    _debug(src_loc);
}

void InterfaceGlInner::BindVertexBuffers(GLuint first, GLsizei count, GLuintArr buffers, GLintptrArr offsets, GLsizeiArr strides, GLsrc src_loc){
    glBindVertexBuffers(*first, *count, buffers.get(), offsets.get(), strides.get());
    _debug(src_loc);
}

void InterfaceGlInner::BlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, GLsrc src_loc){
    glBlendColor(*red, *green, *blue, *alpha);
    _debug(src_loc);
}

void InterfaceGlInner::BlendEquation(GLenum mode, GLsrc src_loc){
    glBlendEquation(*mode);
    _debug(src_loc);
}

void InterfaceGlInner::BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha, GLsrc src_loc){
    glBlendEquationSeparate(*modeRGB, *modeAlpha);
    _debug(src_loc);
}

void InterfaceGlInner::BlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha, GLsrc src_loc){
    glBlendEquationSeparatei(*buf, *modeRGB, *modeAlpha);
    _debug(src_loc);
}

void InterfaceGlInner::BlendEquationi(GLuint buf, GLenum mode, GLsrc src_loc){
    glBlendEquationi(*buf, *mode);
    _debug(src_loc);
}

void InterfaceGlInner::BlendFunc(GLenum sfactor, GLenum dfactor, GLsrc src_loc){
    glBlendFunc(*sfactor, *dfactor);
    _debug(src_loc);
}

void InterfaceGlInner::BlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha, GLsrc src_loc){
    glBlendFuncSeparate(*sfactorRGB, *dfactorRGB, *sfactorAlpha, *dfactorAlpha);
    _debug(src_loc);
}

void InterfaceGlInner::BlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha, GLenum modeAlpha, GLsrc src_loc){
    glBlendFuncSeparatei(*buf, *srcRGB, *dstRGB, *srcAlpha, *dstAlpha);
    _debug(src_loc);
}

void InterfaceGlInner::BlendFunci(GLuint buf, GLenum src, GLenum dst, GLsrc src_loc){
    glBlendFunci(*buf, *src, *dst);
    _debug(src_loc);
}

void InterfaceGlInner::BlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter, GLsrc src_loc){
    glBlitFramebuffer(*srcX0, *srcY0, *srcX1, *srcY1, *dstX0, *dstY0, *dstX1, *dstY1, *mask, *filter);
    _debug(src_loc);
}

void InterfaceGlInner::BlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter, GLsrc src_loc){
    glBlitNamedFramebuffer(*readFramebuffer, *drawFramebuffer, *srcX0, *srcY0, *srcX1, *srcY1, *dstX0, *dstY0, *dstX1, *dstY1, *mask, *filter);
    _debug(src_loc);
}

void InterfaceGlInner::BufferData(GLenum target, GLsizeiptr size, GLdata data, GLenum usage, GLsrc src_loc){
    glBufferData(*target, *size, data.get(), *usage);
    _debug(src_loc);
}

void InterfaceGlInner::BufferStorage(GLenum target, GLsizeiptr size, GLdata data, GLbitfield flags, GLsrc src_loc){
    glBufferStorage(*target, *size, data.get(), *flags);
    _debug(src_loc);
}

void InterfaceGlInner::BufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLdata data, GLsrc src_loc){
    glBufferSubData(*target, *offset, *size, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::CheckFramebufferStatus(GLenum target, GLsrc src_loc){
    glCheckFramebufferStatus(*target);
    _debug(src_loc);
}

void InterfaceGlInner::CheckNamedFramebufferStatus(GLuint framebuffer, GLenum target, GLsrc src_loc){
    glCheckNamedFramebufferStatus(*framebuffer, *target);
    _debug(src_loc);
}

void InterfaceGlInner::ClampColor(GLenum target, GLenum clamp, GLsrc src_loc){
    glClampColor(*target, *clamp);
    _debug(src_loc);
}

void InterfaceGlInner::Clear(GLbitfield mask, GLsrc src_loc){
    glClear(*mask);
    _debug(src_loc);
}

void InterfaceGlInner::ClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, GLdata data, GLsrc src_loc){
    glClearBufferData(*target, *internalformat, *format, *type, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::ClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, GLdata data, GLsrc src_loc){
    glClearBufferSubData(*target, *internalformat, *offset, *size, *format, *type, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::ClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil, GLsrc src_loc){
    glClearBufferfi(*buffer, *drawbuffer, *depth, *stencil);
    _debug(src_loc);
}

void InterfaceGlInner::ClearBufferfv(GLenum buffer, GLint drawbuffer, GLfloatArr value, GLsrc src_loc){
    glClearBufferfv(*buffer, *drawbuffer, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ClearBufferiv(GLenum buffer, GLint drawbuffer, GLintArr value, GLsrc src_loc){
    glClearBufferiv(*buffer, *drawbuffer, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ClearBufferuiv(GLenum buffer, GLint drawbuffer, GLuintArr value, GLsrc src_loc){
    glClearBufferuiv(*buffer, *drawbuffer, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, GLsrc src_loc){
    glClearColor(*red, *green, *blue, *alpha);
    _debug(src_loc);
}

void InterfaceGlInner::ClearDepth(GLdouble depth, GLsrc src_loc){
    glClearDepth(*depth);
    _debug(src_loc);
}

void InterfaceGlInner::ClearDepthf(GLfloat d, GLsrc src_loc){
    glClearDepthf(*d);
    _debug(src_loc);
}

void InterfaceGlInner::ClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, GLdata data, GLsrc src_loc){
    glClearNamedBufferData(*buffer, *internalformat, *format, *type, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::ClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, GLdata data, GLsrc src_loc){
    glClearNamedBufferSubData(*buffer, *internalformat, *offset, *size, *format, *type, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::ClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil, GLsrc src_loc){
    glClearNamedFramebufferfi(*framebuffer, *buffer, *drawbuffer, *depth, *stencil);
    _debug(src_loc);
}

void InterfaceGlInner::ClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloatArr value, GLsrc src_loc){
    glClearNamedFramebufferfv(*framebuffer, *buffer, *drawbuffer, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLintArr value, GLsrc src_loc){
    glClearNamedFramebufferiv(*framebuffer, *buffer, *drawbuffer, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLuintArr value, GLsrc src_loc){
    glClearNamedFramebufferuiv(*framebuffer, *buffer, *drawbuffer, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ClearStencil(GLint s, GLsrc src_loc){
    glClearStencil(*s);
    _debug(src_loc);
}

void InterfaceGlInner::ClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, GLdata data, GLsrc src_loc){
    glClearTexImage(*texture, *level, *format, *type, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::ClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLdata data, GLsrc src_loc){
    glClearTexSubImage(*texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *type, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::ClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, GLsrc src_loc){
    glClientWaitSync(*sync, *flags, *timeout);
    _debug(src_loc);
}

void InterfaceGlInner::ClipControl(GLenum origin, GLenum depth, GLsrc src_loc){
    glClipControl(*origin, *depth);
    _debug(src_loc);
}

void InterfaceGlInner::ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha, GLsrc src_loc){
    glColorMask(*red, *green, *blue, *alpha);
    _debug(src_loc);
}

void InterfaceGlInner::ColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a, GLsrc src_loc){
    glColorMaski(*index, *r, *g, *b, *a);
    _debug(src_loc);
}

void InterfaceGlInner::CompileShader(GLuint shader, GLsrc src_loc){
    glCompileShader(*shader);
    _debug(src_loc);
}

void InterfaceGlInner::CompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLdata data, GLsrc src_loc){
    glCompressedTexImage1D(*target, *level, *internalformat, *width, *border, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLdata data, GLsrc src_loc){
    glCompressedTexImage2D(*target, *level, *internalformat, *width, *height, *border, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::CompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLdata data, GLsrc src_loc){
    glCompressedTexImage3D(*target, *level, *internalformat, *width, *height, *depth, *border, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::CompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLdata data, GLsrc src_loc){
    glCompressedTexSubImage1D(*target, *level, *xoffset, *width, *format, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::CompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLdata data, GLsrc src_loc){
    glCompressedTexSubImage2D(*target, *level, *xoffset, *yoffset, *width, *height, *format, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::CompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLdata data, GLsrc src_loc){
    glCompressedTexSubImage3D(*target, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::CompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLdata data, GLsrc src_loc){
    glCompressedTextureSubImage1D(*texture, *level, *xoffset, *width, *format, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::CompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLdata data, GLsrc src_loc){
    glCompressedTextureSubImage2D(*texture, *level, *xoffset, *yoffset, *width, *height, *format, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::CompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLdata data, GLsrc src_loc){
    glCompressedTextureSubImage3D(*texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *imageSize, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::CopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, GLsrc src_loc){
    glCopyBufferSubData(*readTarget, *writeTarget, *readOffset, *writeOffset, *size);
    _debug(src_loc);
}

void InterfaceGlInner::CopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth, GLsrc src_loc){
    glCopyImageSubData(*srcName, *srcTarget, *srcLevel, *srcX, *srcY, *srcZ, *dstName, *dstTarget, *dstLevel, *dstX, *dstY, *dstZ, *srcWidth, *srcHeight, *srcDepth);
    _debug(src_loc);
}

void InterfaceGlInner::CopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, GLsrc src_loc){
    glCopyNamedBufferSubData(*readBuffer, *writeBuffer, *readOffset, *writeOffset, *size);
    _debug(src_loc);
}

void InterfaceGlInner::CopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border, GLsrc src_loc){
    glCopyTexImage1D(*target, *level, *internalformat, *x, *y, *width, *border);
    _debug(src_loc);
}

void InterfaceGlInner::CopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border, GLsrc src_loc){
    glCopyTexImage2D(*target, *level, *internalformat, *x, *y, *width, *height, *border);
    _debug(src_loc);
}

void InterfaceGlInner::CopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width, GLsrc src_loc){
    glCopyTexSubImage1D(*target, *level, *xoffset, *x, *y, *width);
    _debug(src_loc);
}

void InterfaceGlInner::CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height, GLsrc src_loc){
    glCopyTexSubImage2D(*target, *level, *xoffset, *yoffset, *x, *y, *width, *height);
    _debug(src_loc);
}

void InterfaceGlInner::CopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height, GLsrc src_loc){
    glCopyTexSubImage3D(*target, *level, *xoffset, *yoffset, *zoffset, *x, *y, *width, *height);
    _debug(src_loc);
}

void InterfaceGlInner::CopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width, GLsrc src_loc){
    glCopyTextureSubImage1D(*texture, *level, *xoffset, *x, *y, *width);
    _debug(src_loc);
}

void InterfaceGlInner::CopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height, GLsrc src_loc){
    glCopyTextureSubImage2D(*texture, *level, *xoffset, *yoffset, *x, *y, *width, *height);
    _debug(src_loc);
}

void InterfaceGlInner::CopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height, GLsrc src_loc){
    glCopyTextureSubImage3D(*texture, *level, *xoffset, *yoffset, *zoffset, *x, *y, *width, *height);
    _debug(src_loc);
}

void InterfaceGlInner::CreateBuffers(GLsizei n, GLuintArr dst, GLsrc src_loc){
    glCreateBuffers(*n, dst.get());
    _debug(src_loc);
}

void InterfaceGlInner::CreateFramebuffers(GLsizei n, GLuintArr framebuffers, GLsrc src_loc){
    glCreateFramebuffers(*n, framebuffers.get());
    _debug(src_loc);
}

InterfaceGlInner::GLuintRes InterfaceGlInner::CreateProgram(GLsrc src_loc){
    GLuintRes dst(new GLuintRes::element_type(glCreateProgram()));
    _debug(src_loc);
    return dst;
}

void InterfaceGlInner::CreateProgramPipelines(GLsizei n, GLuintArr pipelines, GLsrc src_loc){
    glCreateProgramPipelines(*n, pipelines.get());
    _debug(src_loc);
}

void InterfaceGlInner::CreateQueries(GLenum target, GLsizei n, GLuintArr ids, GLsrc src_loc){
    glCreateQueries(*target, *n, ids.get());
    _debug(src_loc);
}

void InterfaceGlInner::CreateRenderbuffers(GLsizei n, GLuintArr renderbuffers, GLsrc src_loc){
    glCreateRenderbuffers(*n, renderbuffers.get());
    _debug(src_loc);
}

void InterfaceGlInner::CreateSamplers(GLsizei n, GLuintArr samplers, GLsrc src_loc){
    glCreateSamplers(*n, samplers.get());
    _debug(src_loc);
}

InterfaceGlInner::GLuintRes InterfaceGlInner::CreateShader(GLenum type, GLsrc src_loc){
    GLuintRes dst(new GLuintRes::element_type(glCreateShader(*type)));
    _debug(src_loc);
    return dst;
}

void InterfaceGlInner::CreateTextures(GLenum target, GLsizei n, GLuintArr textures, GLsrc src_loc){
    glCreateTextures(*target, *n, textures.get());
    _debug(src_loc);
}

void InterfaceGlInner::CreateTransformFeedbacks(GLsizei n, GLuintArr ids, GLsrc src_loc){
    glCreateTransformFeedbacks(*n, ids.get());
    _debug(src_loc);
}

void InterfaceGlInner::CreateVertexArrays(GLsizei n, GLuintArr arrays, GLsrc src_loc){
    glCreateVertexArrays(*n, arrays.get());
    _debug(src_loc);
}

void InterfaceGlInner::CullFace(GLenum mode, GLsrc src_loc){
    glCullFace(*mode);
    _debug(src_loc);
}

// void InterfaceGlInner::DebugMessageCallback(GLDEBUGPROC callback, GLdata userParam, GLsrc src_loc){
//     glDebugMessageCallback(*callback, userParam.get());
//     _debug(src_loc);
// }

void InterfaceGlInner::DebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, GLuintArr ids, GLboolean enabled, GLsrc src_loc){
    glDebugMessageControl(*source, *type, *severity, *count, ids.get(), *enabled);
    _debug(src_loc);
}

void InterfaceGlInner::DebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLcharArr buf, GLsrc src_loc){
    glDebugMessageInsert(*source, *type, *id, *severity, *length, buf.get());
    _debug(src_loc);
}

void InterfaceGlInner::DeleteBuffers(GLsizei n, GLuintArr buffers, GLsrc src_loc){
    glDeleteBuffers(*n, buffers.get());
    _debug(src_loc);
}

void InterfaceGlInner::DeleteFramebuffers(GLsizei n, GLuintArr framebuffers, GLsrc src_loc){
    glDeleteFramebuffers(*n, framebuffers.get());
    _debug(src_loc);
}

void InterfaceGlInner::DeleteProgram(GLuint program, GLsrc src_loc){
    glDeleteProgram(*program);
    _debug(src_loc);
}

void InterfaceGlInner::DeleteProgramPipelines(GLsizei n, GLuintArr pipelines, GLsrc src_loc){
    glDeleteProgramPipelines(*n, pipelines.get());
    _debug(src_loc);
}

void InterfaceGlInner::DeleteQueries(GLsizei n, GLuintArr ids, GLsrc src_loc){
    glDeleteQueries(*n, ids.get());
    _debug(src_loc);
}

void InterfaceGlInner::DeleteRenderbuffers(GLsizei n, GLuintArr renderbuffers, GLsrc src_loc){
    glDeleteRenderbuffers(*n, renderbuffers.get());
    _debug(src_loc);
}

void InterfaceGlInner::DeleteSamplers(GLsizei count, GLuintArr samplers, GLsrc src_loc){
    glDeleteSamplers(*count, samplers.get());
    _debug(src_loc);
}

void InterfaceGlInner::DeleteShader(GLuint shader, GLsrc src_loc){
    glDeleteShader(*shader);
    _debug(src_loc);
}

void InterfaceGlInner::DeleteSync(GLsync sync, GLsrc src_loc){
    glDeleteSync(*sync);
    _debug(src_loc);
}

void InterfaceGlInner::DeleteTextures(GLsizei n, GLuintArr textures, GLsrc src_loc){
    glDeleteTextures(*n, textures.get());
    _debug(src_loc);
}

void InterfaceGlInner::DeleteTransformFeedbacks(GLsizei n, GLuintArr ids, GLsrc src_loc){
    glDeleteTransformFeedbacks(*n, ids.get());
    _debug(src_loc);
}

void InterfaceGlInner::DeleteVertexArrays(GLsizei n, GLuintArr arrays, GLsrc src_loc){
    glDeleteVertexArrays(*n, arrays.get());
    _debug(src_loc);
}

void InterfaceGlInner::DepthFunc(GLenum func, GLsrc src_loc){
    glDepthFunc(*func);
    _debug(src_loc);
}

void InterfaceGlInner::DepthMask(GLboolean flag, GLsrc src_loc){
    glDepthMask(*flag);
    _debug(src_loc);
}

void InterfaceGlInner::DepthRange(GLdouble n, GLdouble f, GLsrc src_loc){
    glDepthRange(*n, *f);
    _debug(src_loc);
}

void InterfaceGlInner::DepthRangeArrayv(GLuint first, GLsizei count, GLdoubleArr v, GLsrc src_loc){
    glDepthRangeArrayv(*first, *count, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::DepthRangeIndexed(GLuint index, GLdouble n, GLdouble f, GLsrc src_loc){
    glDepthRangeIndexed(*index, *n, *f);
    _debug(src_loc);
}

void InterfaceGlInner::DepthRangef(GLfloat n, GLfloat f, GLsrc src_loc){
    glDepthRangef(*n, *f);
    _debug(src_loc);
}

void InterfaceGlInner::DetachShader(GLuint program, GLuint shader, GLsrc src_loc){
    glDetachShader(*program, *shader);
    _debug(src_loc);
}

void InterfaceGlInner::Disable(GLenum cap, GLsrc src_loc){
    glDisable(*cap);
    _debug(src_loc);
}

void InterfaceGlInner::DisableVertexArrayAttrib(GLuint vaobj, GLuint index, GLsrc src_loc){
    glDisableVertexArrayAttrib(*vaobj, *index);
    _debug(src_loc);
}

void InterfaceGlInner::DisableVertexAttribArray(GLuint index, GLsrc src_loc){
    glDisableVertexAttribArray(*index);
    _debug(src_loc);
}

void InterfaceGlInner::Disablei(GLenum target, GLuint index, GLsrc src_loc){
    glDisablei(*target, *index);
    _debug(src_loc);
}

void InterfaceGlInner::DispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLsrc src_loc){
    glDispatchCompute(*num_groups_x, *num_groups_y, *num_groups_z);
    _debug(src_loc);
}

void InterfaceGlInner::DispatchComputeIndirect(GLintptr indirect, GLsrc src_loc){
    glDispatchComputeIndirect(*indirect);
    _debug(src_loc);
}

void InterfaceGlInner::DrawArrays(GLenum mode, GLint first, GLsizei count, GLsrc src_loc){
    glDrawArrays(*mode, *first, *count);
    _debug(src_loc);
}

void InterfaceGlInner::DrawArraysIndirect(GLenum mode, GLdata indirect, GLsrc src_loc){
    glDrawArraysIndirect(*mode, indirect.get());
    _debug(src_loc);
}

void InterfaceGlInner::DrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLsrc src_loc){
    glDrawArraysInstanced(*mode, *first, *count, *instancecount);
    _debug(src_loc);
}

void InterfaceGlInner::DrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance, GLsrc src_loc){
    glDrawArraysInstancedBaseInstance(*mode, *first, *count, *instancecount, *instancecount);
    _debug(src_loc);
}

void InterfaceGlInner::DrawBuffer(GLenum buf, GLsrc src_loc){
    glDrawBuffer(*buf);
    _debug(src_loc);
}

void InterfaceGlInner::DrawBuffers(GLsizei n, GLenumArr bufs, GLsrc src_loc){
    glDrawBuffers(*n, bufs.get());
    _debug(src_loc);
}

void InterfaceGlInner::DrawElements(GLenum mode, GLsizei count, GLenum type, GLdata indices, GLsrc src_loc){
    glDrawElements(*mode, *count, *type, indices.get());
    _debug(src_loc);
}

void InterfaceGlInner::DrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLdata indices, GLint basevertex, GLsrc src_loc){
    glDrawElementsBaseVertex(*mode, *count, *type, indices.get(), *basevertex);
    _debug(src_loc);
}

void InterfaceGlInner::DrawElementsIndirect(GLenum mode, GLenum type, GLdata indirect, GLsrc src_loc){
    glDrawElementsIndirect(*mode, *type, indirect.get());
    _debug(src_loc);
}

void InterfaceGlInner::DrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, GLdata indices, GLsizei instancecount, GLsrc src_loc){
    glDrawElementsInstanced(*mode, *count, *type, indices.get(), *instancecount);
    _debug(src_loc);
}

void InterfaceGlInner::DrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, GLdata indices, GLsizei instancecount, GLuint baseinstance, GLsrc src_loc){
    glDrawElementsInstancedBaseInstance(*mode, *count, *type, indices.get(), *instancecount, *baseinstance);
    _debug(src_loc);
}

void InterfaceGlInner::DrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, GLdata indices, GLsizei instancecount, GLint basevertex, GLsrc src_loc){
    glDrawElementsInstancedBaseVertex(*mode, *count, *type, indices.get(), *instancecount, *basevertex);
    _debug(src_loc);
}

void InterfaceGlInner::DrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, GLdata indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance, GLsrc src_loc){
    glDrawElementsInstancedBaseVertexBaseInstance(*mode, *count, *type, indices.get(), *instancecount, *basevertex, *baseinstance);
    _debug(src_loc);
}

void InterfaceGlInner::DrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLdata indices, GLsrc src_loc){
    glDrawRangeElements(*mode, *start, *end, *count, *type, indices.get());
    _debug(src_loc);
}

void InterfaceGlInner::DrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLdata indices, GLint basevertex, GLsrc src_loc){
    glDrawRangeElementsBaseVertex(*mode, *start, *end, *count, *type, indices.get(), *basevertex);
    _debug(src_loc);
}

void InterfaceGlInner::DrawTransformFeedback(GLenum mode, GLuint id, GLsrc src_loc){
    glDrawTransformFeedback(*mode, *id);
    _debug(src_loc);
}

void InterfaceGlInner::DrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount, GLsrc src_loc){
    glDrawTransformFeedbackInstanced(*mode, *id, *instancecount);
    _debug(src_loc);
}

void InterfaceGlInner::DrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream, GLsrc src_loc){
    glDrawTransformFeedbackStream(*mode, *id, *stream);
    _debug(src_loc);
}

void InterfaceGlInner::DrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount, GLsrc src_loc){
    glDrawTransformFeedbackStreamInstanced(*mode, *id, *stream, *instancecount);
    _debug(src_loc);
}

void InterfaceGlInner::Enable(GLenum cap, GLsrc src_loc){
    glEnable(*cap);
    _debug(src_loc);
}

void InterfaceGlInner::EnableVertexArrayAttrib(GLuint vaobj, GLuint index, GLsrc src_loc){
    glEnableVertexArrayAttrib(*vaobj, *index);
    _debug(src_loc);
}

void InterfaceGlInner::EnableVertexAttribArray(GLuint index, GLsrc src_loc){
    glEnableVertexAttribArray(*index);
    _debug(src_loc);
}

void InterfaceGlInner::Enablei(GLenum target, GLuint index, GLsrc src_loc){
    glEnablei(*target, *index);
    _debug(src_loc);
}

void InterfaceGlInner::EndConditionalRender(GLsrc src_loc){
    glEndConditionalRender();
    _debug(src_loc);
}

void InterfaceGlInner::EndQuery(GLenum target, GLsrc src_loc){
    glEndQuery(*target);
    _debug(src_loc);
}

void InterfaceGlInner::EndQueryIndexed(GLenum target, GLuint index, GLsrc src_loc){
    glEndQueryIndexed(*target, *index);
    _debug(src_loc);
}

void InterfaceGlInner::EndTransformFeedback(GLsrc src_loc){
    glEndTransformFeedback();
    _debug(src_loc);
}

InterfaceGlInner::GLsyncRes InterfaceGlInner::FenceSync(GLenum condition, GLbitfield flags, GLsrc src_loc){
    GLsyncRes dst(new GLsyncRes::element_type(glFenceSync(*condition, *flags)));
    _debug(src_loc);
    return dst;
}

void InterfaceGlInner::Finish(GLsrc src_loc){
    glFinish();
    _debug(src_loc);
}

void InterfaceGlInner::Flush(GLsrc src_loc){
    glFlush();
    _debug(src_loc);
}

void InterfaceGlInner::FlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLsrc src_loc){
    glFlushMappedBufferRange(*target, *offset, *length);
    _debug(src_loc);
}

void InterfaceGlInner::FlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLsrc src_loc){
    glFlushMappedNamedBufferRange(*buffer, *offset, *length);
    _debug(src_loc);
}

void InterfaceGlInner::FramebufferParameteri(GLenum target, GLenum pname, GLint param, GLsrc src_loc){
    glFramebufferParameteri(*target, *pname, *param);
    _debug(src_loc);
}

void InterfaceGlInner::FramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer, GLsrc src_loc){
    glFramebufferRenderbuffer(*target, *attachment, *renderbuffertarget, *renderbuffer);
    _debug(src_loc);
}

void InterfaceGlInner::FramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level, GLsrc src_loc){
    glFramebufferTexture(*target, *attachment, *texture, *level);
    _debug(src_loc);
}

void InterfaceGlInner::FramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLsrc src_loc){
    glFramebufferTexture1D(*target, *attachment, *textarget, *target, *level);
    _debug(src_loc);
}

void InterfaceGlInner::FramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLsrc src_loc){
    glFramebufferTexture2D(*target, *attachment, *textarget, *texture, *level);
    _debug(src_loc);
}

void InterfaceGlInner::FramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset, GLsrc src_loc){
    glFramebufferTexture3D(*target, *attachment, *textarget, *texture, *level, *zoffset);
    _debug(src_loc);
}

void InterfaceGlInner::FramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer, GLsrc src_loc){
    glFramebufferTextureLayer(*target, *attachment, *texture, *level, *layer);
    _debug(src_loc);
}

void InterfaceGlInner::FrontFace(GLenum mode, GLsrc src_loc){
    glFrontFace(*mode);
    _debug(src_loc);
}

void InterfaceGlInner::GenBuffers(GLsizei n, GLuintArr buffers, GLsrc src_loc){
    glGenBuffers(*n, buffers.get());
    _debug(src_loc);
}

void InterfaceGlInner::GenFramebuffers(GLsizei n, GLuintArr framebuffers, GLsrc src_loc){
    glGenFramebuffers(*n, framebuffers.get());
    _debug(src_loc);
}

void InterfaceGlInner::GenProgramPipelines(GLsizei n, GLuintArr pipelines, GLsrc src_loc){
    glGenProgramPipelines(*n, pipelines.get());
    _debug(src_loc);
}

void InterfaceGlInner::GenQueries(GLsizei n, GLuintArr ids, GLsrc src_loc){
    glGenQueries(*n, ids.get());
    _debug(src_loc);
}

void InterfaceGlInner::GenRenderbuffers(GLsizei n, GLuintArr renderbuffers, GLsrc src_loc){
    glGenRenderbuffers(*n, renderbuffers.get());
    _debug(src_loc);
}

void InterfaceGlInner::GenSamplers(GLsizei count, GLuintArr samplers, GLsrc src_loc){
    glGenSamplers(*count, samplers.get());
    _debug(src_loc);
}

void InterfaceGlInner::GenTextures(GLsizei n, GLuintArr textures, GLsrc src_loc){
    glGenTextures(*n, textures.get());
    _debug(src_loc);
}

void InterfaceGlInner::GenTransformFeedbacks(GLsizei n, GLuintArr ids, GLsrc src_loc){
    glGenTransformFeedbacks(*n, ids.get());
    _debug(src_loc);
}

void InterfaceGlInner::GenVertexArrays(GLsizei n, GLuintArr arrays, GLsrc src_loc){
    glGenVertexArrays(*n, arrays.get());
    _debug(src_loc);
}

void InterfaceGlInner::GenerateMipmap(GLenum target, GLsrc src_loc){
    glGenerateMipmap(*target);
    _debug(src_loc);
}

void InterfaceGlInner::GenerateTextureMipmap(GLuint texture, GLsrc src_loc){
    glGenerateTextureMipmap(*texture);
    _debug(src_loc);
}

void InterfaceGlInner::GetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetActiveAtomicCounterBufferiv(*program, *bufferIndex, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLint size, GLenum type, GLcharArr name, GLsrc src_loc){
    glGetActiveAttrib(*program, *index, *bufSize, length.get(), size.get(), type.get(), name.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei length, GLcharArr name, GLsrc src_loc){
    glGetActiveSubroutineName(*program, *shadertype, *index, *bufSize, length.get(), name.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei length, GLcharArr name, GLsrc src_loc){
    glGetActiveSubroutineUniformName(*program, *shadertype, *index, *bufSize, length.get(), name.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLintArr values, GLsrc src_loc){
    glGetActiveSubroutineUniformiv(*program, *shadertype, *index, *pname, values.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLint size, GLenum type, GLcharArr name, GLsrc src_loc){
    glGetActiveUniform(*program, *index, *bufSize, length.get(), size.get(), type.get(), name.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei length, GLcharArr uniformBlockName, GLsrc src_loc){
    glGetActiveUniformBlockName(*program, *uniformBlockIndex, *bufSize, length.get(), uniformBlockName.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetActiveUniformBlockiv(*program, *uniformBlockIndex, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei length, GLcharArr uniformName, GLsrc src_loc){
    glGetActiveUniformName(*program, *uniformIndex, *bufSize, length.get(), uniformName.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetActiveUniformsiv(GLuint program, GLsizei uniformCount, GLuintArr uniformIndices, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetActiveUniformsiv(*program, *uniformCount, uniformIndices.get(), *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetAttachedShaders(GLuint program, GLsizei maxCount, GLsizeiArr count, GLuintArr shaders, GLsrc src_loc){
    glGetAttachedShaders(*program, *maxCount, count.get(), shaders.get());
    _debug(src_loc);
}

InterfaceGlInner::GLintRes InterfaceGlInner::GetAttribLocation(GLuint program, GLcharArr name, GLsrc src_loc){
    GLintRes dst(new GLintRes::element_type(glGetAttribLocation(*program, name.get())));
    _debug(src_loc);
    return dst;
}

void InterfaceGlInner::GetBooleani_v(GLenum target, GLuint index, GLbooleanArr data, GLsrc src_loc){
    glGetBooleani_v(*target, *index, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetBooleanv(GLenum pname, GLbooleanArr data, GLsrc src_loc){
    glGetBooleanv(*pname, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetBufferParameteri64v(GLenum target, GLenum pname, GLint64Arr params, GLsrc src_loc){
    glGetBufferParameteri64v(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetBufferParameteriv(GLenum target, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetBufferParameteriv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetBufferPointerv(GLenum target, GLenum pname, GLdataPtr params, GLsrc src_loc){
    glGetBufferPointerv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLdata data, GLsrc src_loc){
    glGetBufferSubData(*target, *offset, *size, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetCompressedTexImage(GLenum target, GLint level, GLdata img, GLsrc src_loc){
    glGetCompressedTexImage(*target, *level, img.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, GLdata pixels, GLsrc src_loc){
    glGetCompressedTextureImage(*texture, *level, *bufSize, pixels.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, GLdata pixels, GLsrc src_loc){
    glGetCompressedTextureSubImage(*texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *bufSize, pixels.get());
    _debug(src_loc);
}

InterfaceGlInner::GLuintRes InterfaceGlInner::GetDebugMessageLog(GLuint count, GLsizei bufSize, GLenumArr sources, GLenumArr types, GLuintArr ids, GLenumArr severities, GLsizei lengths, GLcharArr messageLog, GLsrc src_loc){
    GLuintRes dst(new GLuintRes::element_type(glGetDebugMessageLog(*count, *bufSize, sources.get(), types.get(), ids.get(), severities.get(), lengths.get(), messageLog.get())));
    _debug(src_loc);
    return dst;
}

void InterfaceGlInner::GetDoublei_v(GLenum target, GLuint index, GLdoubleArr data, GLsrc src_loc){
    glGetDoublei_v(*target, *index, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetDoublev(GLenum pname, GLdoubleArr data, GLsrc src_loc){
    glGetDoublev(*pname, data.get());
    _debug(src_loc);
}

InterfaceGlInner::GLenumRes InterfaceGlInner::GetError(GLsrc src_loc){
    GLenumRes dst(new GLenumRes::element_type(glGetError()));
    _debug(src_loc);
    return dst;
}

void InterfaceGlInner::GetFloati_v(GLenum target, GLuint index, GLfloatArr data, GLsrc src_loc){
    glGetFloati_v(*target, *index, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetFloatv(GLenum pname, GLfloatArr data, GLsrc src_loc){
    glGetFloatv(*pname, data.get());
    _debug(src_loc);
}

InterfaceGlInner::GLintRes InterfaceGlInner::GetFragDataIndex(GLuint program, GLcharArr name, GLsrc src_loc){
    GLintRes dst(new GLintRes::element_type(glGetFragDataIndex(*program, name.get())));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLintRes InterfaceGlInner::GetFragDataLocation(GLuint program, GLcharArr name, GLsrc src_loc){
    GLintRes dst(new GLintRes::element_type(glGetFragDataLocation(*program, name.get())));
    _debug(src_loc);
    return dst;
}

void InterfaceGlInner::GetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetFramebufferAttachmentParameteriv(*target, *attachment, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetFramebufferParameteriv(GLenum target, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetFramebufferParameteriv(*target, *pname, params.get());
    _debug(src_loc);
}

InterfaceGlInner::GLenumRes InterfaceGlInner::GetGraphicsResetStatus(GLsrc src_loc){
    GLenumRes dst(new GLenumRes::element_type(glGetGraphicsResetStatus()));
    _debug(src_loc);
    return dst;
}

void InterfaceGlInner::GetInteger64i_v(GLenum target, GLuint index, GLint64Arr data, GLsrc src_loc){
    glGetInteger64i_v(*target, *index, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetInteger64v(GLenum pname, GLint64Arr data, GLsrc src_loc){
    glGetInteger64v(*pname, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetIntegeri_v(GLenum target, GLuint index, GLintArr data, GLsrc src_loc){
    glGetIntegeri_v(*target, *index, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetIntegerv(GLenum pname, GLintArr data, GLsrc src_loc){
    glGetIntegerv(*pname, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64Arr params, GLsrc src_loc){
    glGetInternalformati64v(*target, *internalformat, *pname, *count, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLintArr params, GLsrc src_loc){
    glGetInternalformativ(*target, *internalformat, *pname, *count, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetMultisamplefv(GLenum pname, GLuint index, GLfloatArr val, GLsrc src_loc){
    glGetMultisamplefv(*pname, *index, val.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64Arr params, GLsrc src_loc){
    glGetNamedBufferParameteri64v(*buffer, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetNamedBufferParameteriv(*buffer, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetNamedBufferPointerv(GLuint buffer, GLenum pname, GLdataPtr params, GLsrc src_loc){
    glGetNamedBufferPointerv(*buffer, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, GLdata data, GLsrc src_loc){
    glGetNamedBufferSubData(*buffer, *offset, *size, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetNamedFramebufferAttachmentParameteriv(*framebuffer, *attachment, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLintArr param, GLsrc src_loc){
    glGetNamedFramebufferParameteriv(*framebuffer, *pname, param.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetNamedRenderbufferParameteriv(*renderbuffer, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei length, GLcharArr label, GLsrc src_loc){
    glGetObjectLabel(*identifier, *name, *bufSize, length.get(), label.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetObjectPtrLabel(GLdata ptr, GLsizei bufSize, GLsizei length, GLcharArr label, GLsrc src_loc){
    glGetObjectPtrLabel(ptr.get(), *bufSize, length.get(), label.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetPointerv(GLenum pname, GLdataPtr params, GLsrc src_loc){
    glGetPointerv(*pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetProgramBinary(GLuint program, GLsizei bufSize, GLsizei length, GLenumArr binaryFormat, GLdata binary, GLsrc src_loc){
    glGetProgramBinary(*program, *bufSize, length.get(), binaryFormat.get(), binary.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei length, GLcharArr infoLog, GLsrc src_loc){
    glGetProgramInfoLog(*program, *bufSize, length.get(), infoLog.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetProgramInterfaceiv(*program, *programInterface, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei length, GLcharArr infoLog, GLsrc src_loc){
    glGetProgramPipelineInfoLog(*pipeline, *bufSize, length.get(), infoLog.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetProgramPipelineiv(GLuint pipeline, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetProgramPipelineiv(*pipeline, *pname, params.get());
    _debug(src_loc);
}

InterfaceGlInner::GLuintRes InterfaceGlInner::GetProgramResourceIndex(GLuint program, GLenum programInterface, GLcharArr name, GLsrc src_loc){
    GLuintRes dst(new GLuintRes::element_type(glGetProgramResourceIndex(*program, *programInterface, name.get())));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLintRes InterfaceGlInner::GetProgramResourceLocation(GLuint program, GLenum programInterface, GLcharArr name, GLsrc src_loc){
    GLintRes dst(new GLintRes::element_type(glGetProgramResourceLocation(*program, *programInterface, name.get())));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLintRes InterfaceGlInner::GetProgramResourceLocationIndex(GLuint program, GLenum programInterface, GLcharArr name, GLsrc src_loc){
    GLintRes dst(new GLintRes::element_type(glGetProgramResourceLocationIndex(*program, *programInterface, name.get())));
    _debug(src_loc);
    return dst;
}

void InterfaceGlInner::GetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei length, GLcharArr name, GLsrc src_loc){
    glGetProgramResourceName(*program, *programInterface, *index, *bufSize, length.get(), name.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, GLenumArr props, GLsizei count, GLsizei length, GLintArr params, GLsrc src_loc){
    glGetProgramResourceiv(*program, *programInterface, *index, *propCount, props.get(), *count, length.get(), params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLintArr values, GLsrc src_loc){
    glGetProgramStageiv(*program, *shadertype, *pname, values.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetProgramiv(GLuint program, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetProgramiv(*program, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, GLsrc src_loc){
    glGetQueryBufferObjecti64v(*id, *buffer, *pname, *offset);
    _debug(src_loc);
}

void InterfaceGlInner::GetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, GLsrc src_loc){
    glGetQueryBufferObjectiv(*id, *buffer, *pname, *offset);
    _debug(src_loc);
}

void InterfaceGlInner::GetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, GLsrc src_loc){
    glGetQueryBufferObjectui64v(*id, *buffer, *pname, *offset);
    _debug(src_loc);
}

void InterfaceGlInner::GetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, GLsrc src_loc){
    glGetQueryBufferObjectuiv(*id, *buffer, *pname, *offset);
    _debug(src_loc);
}

void InterfaceGlInner::GetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetQueryIndexediv(*target, *index, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetQueryObjecti64v(GLuint id, GLenum pname, GLint64Arr params, GLsrc src_loc){
    glGetQueryObjecti64v(*id, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetQueryObjectiv(GLuint id, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetQueryObjectiv(*id, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetQueryObjectui64v(GLuint id, GLenum pname, GLuint64Arr params, GLsrc src_loc){
    glGetQueryObjectui64v(*id, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetQueryObjectuiv(GLuint id, GLenum pname, GLuintArr params, GLsrc src_loc){
    glGetQueryObjectuiv(*id, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetQueryiv(GLenum target, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetQueryiv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetRenderbufferParameteriv(GLenum target, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetRenderbufferParameteriv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetSamplerParameterIiv(GLuint sampler, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetSamplerParameterIiv(*sampler, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuintArr params, GLsrc src_loc){
    glGetSamplerParameterIuiv(*sampler, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloatArr params, GLsrc src_loc){
    glGetSamplerParameterfv(*sampler, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetSamplerParameteriv(GLuint sampler, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetSamplerParameteriv(*sampler, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei length, GLcharArr infoLog, GLsrc src_loc){
    glGetShaderInfoLog(*shader, *bufSize, length.get(), infoLog.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLintArr range, GLintArr precision, GLsrc src_loc){
    glGetShaderPrecisionFormat(*shadertype, *precisiontype, range.get(), precision.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetShaderSource(GLuint shader, GLsizei bufSize, GLsizei length, GLcharArr source, GLsrc src_loc){
    glGetShaderSource(*shader, *bufSize, length.get(), source.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetShaderiv(GLuint shader, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetShaderiv(*shader, *pname, params.get());
    _debug(src_loc);
}

InterfaceGlInner::GLubyteArrRes InterfaceGlInner::GetString(GLenum name, GLsrc src_loc){
    auto res = glGetString(*name);
    auto len = strlen(reinterpret_cast<const char*>(res));
    GLubyteArrRes dst(new GLubyteArrRes::element_type[len]);
    strcpy_s(reinterpret_cast<char*>(dst.get()), len, reinterpret_cast<const char*>(res));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLubyteArrRes InterfaceGlInner::GetStringi(GLenum name, GLuint index, GLsrc src_loc){
    auto res = glGetStringi(*name, *index);
    auto len = strlen(reinterpret_cast<const char*>(res));
    GLubyteArrRes dst(new GLubyteArrRes::element_type[len]);
    strcpy_s(reinterpret_cast<char*>(dst.get()), len, reinterpret_cast<const char*>(res));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLuintRes InterfaceGlInner::GetSubroutineIndex(GLuint program, GLenum shadertype, GLcharArr name, GLsrc src_loc){
    GLuintRes dst(new GLuintRes::element_type(glGetSubroutineIndex(*program, *shadertype, name.get())));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLintRes InterfaceGlInner::GetSubroutineUniformLocation(GLuint program, GLenum shadertype, GLcharArr name, GLsrc src_loc){
    GLintRes dst(new GLintRes::element_type(glGetSubroutineUniformLocation(*program, *shadertype, name.get())));
    _debug(src_loc);
    return dst;
}

void InterfaceGlInner::GetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei length, GLintArr values, GLsrc src_loc){
    glGetSynciv(*sync, *pname, *count, length.get(), values.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLdata pixels, GLsrc src_loc){
    glGetTexImage(*target, *level, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloatArr params, GLsrc src_loc){
    glGetTexLevelParameterfv(*target, *level, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetTexLevelParameteriv(*target, *level, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTexParameterIiv(GLenum target, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetTexParameterIiv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTexParameterIuiv(GLenum target, GLenum pname, GLuintArr params, GLsrc src_loc){
    glGetTexParameterIuiv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTexParameterfv(GLenum target, GLenum pname, GLfloatArr params, GLsrc src_loc){
    glGetTexParameterfv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTexParameteriv(GLenum target, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetTexParameteriv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLdata pixels, GLsrc src_loc){
    glGetTextureImage(*texture, *level, *format, *type, *bufSize, pixels.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloatArr params, GLsrc src_loc){
    glGetTextureLevelParameterfv(*texture, *level, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetTextureLevelParameteriv(*texture, *level, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTextureParameterIiv(GLuint texture, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetTextureParameterIiv(*texture, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTextureParameterIuiv(GLuint texture, GLenum pname, GLuintArr params, GLsrc src_loc){
    glGetTextureParameterIuiv(*texture, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTextureParameterfv(GLuint texture, GLenum pname, GLfloatArr params, GLsrc src_loc){
    glGetTextureParameterfv(*texture, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTextureParameteriv(GLuint texture, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetTextureParameteriv(*texture, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, GLdata pixels, GLsrc src_loc){
    glGetTextureSubImage(*texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *type, *bufSize, pixels.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLsizeiArr size, GLenumArr type, GLcharArr name, GLsrc src_loc){
    glGetTransformFeedbackVarying(*program, *index, *bufSize, length.get(), size.get(), type.get(), name.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64Arr param, GLsrc src_loc){
    glGetTransformFeedbacki64_v(*xfb, *pname, *index, param.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLintArr param, GLsrc src_loc){
    glGetTransformFeedbacki_v(*xfb, *pname, *index, param.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetTransformFeedbackiv(GLuint xfb, GLenum pname, GLintArr param, GLsrc src_loc){
    glGetTransformFeedbackiv(*xfb, *pname, param.get());
    _debug(src_loc);
}

InterfaceGlInner::GLuintRes InterfaceGlInner::GetUniformBlockIndex(GLuint program, GLcharArr uniformBlockName, GLsrc src_loc){
    GLuintRes dst(new GLuintRes::element_type(glGetUniformBlockIndex(*program, uniformBlockName.get())));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLintRes InterfaceGlInner::GetUniformLocation(GLuint program, GLcharArr name, GLsrc src_loc){
    GLintRes dst(new GLintRes::element_type(glGetUniformLocation(*program, name.get())));
    _debug(src_loc);
    return dst;
}

void InterfaceGlInner::GetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuintArr params, GLsrc src_loc){
    glGetUniformSubroutineuiv(*shadertype, *location, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetUniformdv(GLuint program, GLint location, GLdoubleArr params, GLsrc src_loc){
    glGetUniformdv(*program, *location, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetUniformfv(GLuint program, GLint location, GLfloatArr params, GLsrc src_loc){
    glGetUniformfv(*program, *location, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetUniformiv(GLuint program, GLint location, GLintArr params, GLsrc src_loc){
    glGetUniformiv(*program, *location, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetUniformuiv(GLuint program, GLint location, GLuintArr params, GLsrc src_loc){
    glGetUniformuiv(*program, *location, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64Arr param, GLsrc src_loc){
    glGetVertexArrayIndexed64iv(*vaobj, *index, *pname, param.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLintArr param, GLsrc src_loc){
    glGetVertexArrayIndexediv(*vaobj, *index, *pname, param.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetVertexArrayiv(GLuint vaobj, GLenum pname, GLintArr param, GLsrc src_loc){
    glGetVertexArrayiv(*vaobj, *pname, param.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetVertexAttribIiv(GLuint index, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetVertexAttribIiv(*index, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetVertexAttribIuiv(GLuint index, GLenum pname, GLuintArr params, GLsrc src_loc){
    glGetVertexAttribIuiv(*index, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetVertexAttribLdv(GLuint index, GLenum pname, GLdoubleArr params, GLsrc src_loc){
    glGetVertexAttribLdv(*index, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetVertexAttribPointerv(GLuint index, GLenum pname, GLdataPtr pointer, GLsrc src_loc){
    glGetVertexAttribPointerv(*index, *pname, pointer.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetVertexAttribdv(GLuint index, GLenum pname, GLdoubleArr params, GLsrc src_loc){
    glGetVertexAttribdv(*index, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetVertexAttribfv(GLuint index, GLenum pname, GLfloatArr params, GLsrc src_loc){
    glGetVertexAttribfv(*index, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetVertexAttribiv(GLuint index, GLenum pname, GLintArr params, GLsrc src_loc){
    glGetVertexAttribiv(*index, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, GLdata pixels, GLsrc src_loc){
    glGetnCompressedTexImage(*target, *lod, *bufSize, pixels.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLdata pixels, GLsrc src_loc){
    glGetnTexImage(*target, *level, *format, *type, *bufSize, pixels.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdoubleArr params, GLsrc src_loc){
    glGetnUniformdv(*program, *location, *bufSize, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloatArr params, GLsrc src_loc){
    glGetnUniformfv(*program, *location, *bufSize, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLintArr params, GLsrc src_loc){
    glGetnUniformiv(*program, *location, *bufSize, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::GetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuintArr params, GLsrc src_loc){
    glGetnUniformuiv(*program, *location, *bufSize, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::Hint(GLenum target, GLenum mode, GLsrc src_loc){
    glHint(*target, *mode);
    _debug(src_loc);
}

void InterfaceGlInner::InvalidateBufferData(GLuint buffer, GLsrc src_loc){
    glInvalidateBufferData(*buffer);
    _debug(src_loc);
}

void InterfaceGlInner::InvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length, GLsrc src_loc){
    glInvalidateBufferSubData(*buffer, *offset, *length);
    _debug(src_loc);
}

void InterfaceGlInner::InvalidateFramebuffer(GLenum target, GLsizei numAttachments, GLenumArr attachments, GLsrc src_loc){
    glInvalidateFramebuffer(*target, *numAttachments, attachments.get());
    _debug(src_loc);
}

void InterfaceGlInner::InvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, GLenumArr attachments, GLsrc src_loc){
    glInvalidateNamedFramebufferData(*framebuffer, *numAttachments, attachments.get());
    _debug(src_loc);
}

void InterfaceGlInner::InvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, GLenumArr attachments, GLint x, GLint y, GLsizei width, GLsizei height, GLsrc src_loc){
    glInvalidateNamedFramebufferSubData(*framebuffer, *numAttachments, attachments.get(), *x, *y, *width, *height);
    _debug(src_loc);
}

void InterfaceGlInner::InvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, GLenumArr attachments, GLint x, GLint y, GLsizei width, GLsizei height, GLsrc src_loc){
    glInvalidateSubFramebuffer(*target, *numAttachments, attachments.get(), *x, *y, *width, *height);
    _debug(src_loc);
}

void InterfaceGlInner::InvalidateTexImage(GLuint texture, GLint level, GLsrc src_loc){
    glInvalidateTexImage(*texture, *level);
    _debug(src_loc);
}

void InterfaceGlInner::InvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsrc src_loc){
    glInvalidateTexSubImage(*texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth);
    _debug(src_loc);
}

InterfaceGlInner::GLbooleanRes InterfaceGlInner::IsBuffer(GLuint buffer, GLsrc src_loc){
    GLbooleanRes dst(new GLbooleanRes::element_type(glIsBuffer(*buffer)));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLbooleanRes InterfaceGlInner::IsEnabled(GLenum cap, GLsrc src_loc){
    GLbooleanRes dst(new GLbooleanRes::element_type(glIsEnabled(*cap)));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLbooleanRes InterfaceGlInner::IsEnabledi(GLenum target, GLuint index, GLsrc src_loc){
    GLbooleanRes dst(new GLbooleanRes::element_type(glIsEnabledi(*target, *index)));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLbooleanRes InterfaceGlInner::IsFramebuffer(GLuint framebuffer, GLsrc src_loc){
    GLbooleanRes dst(new GLbooleanRes::element_type(glIsFramebuffer(*framebuffer)));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLbooleanRes InterfaceGlInner::IsProgram(GLuint program, GLsrc src_loc){
    GLbooleanRes dst(new GLbooleanRes::element_type(glIsProgram(*program)));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLbooleanRes InterfaceGlInner::IsProgramPipeline(GLuint pipeline, GLsrc src_loc){
    GLbooleanRes dst(new GLbooleanRes::element_type(glIsProgramPipeline(*pipeline)));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLbooleanRes InterfaceGlInner::IsQuery(GLuint id, GLsrc src_loc){
    GLbooleanRes dst(new GLbooleanRes::element_type(glIsQuery(*id)));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLbooleanRes InterfaceGlInner::IsRenderbuffer(GLuint renderbuffer, GLsrc src_loc){
    GLbooleanRes dst(new GLbooleanRes::element_type(glIsRenderbuffer(*renderbuffer)));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLbooleanRes InterfaceGlInner::IsSampler(GLuint sampler, GLsrc src_loc){
    GLbooleanRes dst(new GLbooleanRes::element_type(glIsSampler(*sampler)));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLbooleanRes InterfaceGlInner::IsShader(GLuint shader, GLsrc src_loc){
    GLbooleanRes dst(new GLbooleanRes::element_type(glIsShader(*shader)));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLbooleanRes InterfaceGlInner::IsSync(GLsync sync, GLsrc src_loc){
    GLbooleanRes dst(new GLbooleanRes::element_type(glIsSync(*sync)));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLbooleanRes InterfaceGlInner::IsTexture(GLuint texture, GLsrc src_loc){
    GLbooleanRes dst(new GLbooleanRes::element_type(glIsTexture(*texture)));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLbooleanRes InterfaceGlInner::IsTransformFeedback(GLuint id, GLsrc src_loc){
    GLbooleanRes dst(new GLbooleanRes::element_type(glIsTransformFeedback(*id)));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLbooleanRes InterfaceGlInner::IsVertexArray(GLuint array, GLsrc src_loc){
    GLbooleanRes dst(new GLbooleanRes::element_type(glIsVertexArray(*array)));
    _debug(src_loc);
    return dst;
}

void InterfaceGlInner::LineWidth(GLfloat width, GLsrc src_loc){
    glLineWidth(*width);
    _debug(src_loc);
}

void InterfaceGlInner::LinkProgram(GLuint program, GLsrc src_loc){
    glLinkProgram(*program);
    _debug(src_loc);
}

void InterfaceGlInner::LogicOp(GLenum opcode, GLsrc src_loc){
    glLogicOp(*opcode);
    _debug(src_loc);
}

void InterfaceGlInner::MemoryBarrier(GLbitfield barriers, GLsrc src_loc){
    glMemoryBarrier(*barriers);
    _debug(src_loc);
}

void InterfaceGlInner::MemoryBarrierByRegion(GLbitfield barriers, GLsrc src_loc){
    glMemoryBarrierByRegion(*barriers);
    _debug(src_loc);
}

void InterfaceGlInner::MinSampleShading(GLfloat value, GLsrc src_loc){
    glMinSampleShading(*value);
    _debug(src_loc);
}

void InterfaceGlInner::MultiDrawArrays(GLenum mode, GLintArr first, GLsizeiArr count, GLsizei drawcount, GLsrc src_loc){
    glMultiDrawArrays(*mode, first.get(), count.get(), *drawcount);
    _debug(src_loc);
}

void InterfaceGlInner::MultiDrawArraysIndirect(GLenum mode, const GLdata indirect, GLsizei drawcount, GLsizei stride, GLsrc src_loc){
    glMultiDrawArraysIndirect(*mode, indirect.get(), *drawcount, *stride);
    _debug(src_loc);
}

void InterfaceGlInner::MultiDrawArraysIndirectCount(GLenum mode, const GLdata indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride, GLsrc src_loc){
    glMultiDrawArraysIndirectCount(*mode, indirect.get(), *drawcount, *maxdrawcount, *stride);
    _debug(src_loc);
}

void InterfaceGlInner::MultiDrawElements(GLenum mode, GLsizeiArr count, GLenum type, GLdataPtr indices, GLsizei drawcount, GLsrc src_loc){
    glMultiDrawElements(*mode, count.get(), *type, indices.get(), *drawcount);
    _debug(src_loc);
}

void InterfaceGlInner::MultiDrawElementsBaseVertex(GLenum mode, GLsizeiArr count, GLenum type, GLdataPtr indices, GLsizei drawcount, GLintArr basevertex, GLsrc src_loc){
    glMultiDrawElementsBaseVertex(*mode, count.get(), *type, indices.get(), *drawcount, basevertex.get());
    _debug(src_loc);
}

void InterfaceGlInner::MultiDrawElementsIndirect(GLenum mode, GLenum type, const GLdata indirect, GLsizei drawcount, GLsizei stride, GLsrc src_loc){
    glMultiDrawElementsIndirect(*mode, *type, indirect.get(), *drawcount, *stride);
    _debug(src_loc);
}

void InterfaceGlInner::MultiDrawElementsIndirectCount(GLenum mode, GLenum type, const GLdata indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride, GLsrc src_loc){
    glMultiDrawElementsIndirectCount(*mode, *type, indirect.get(), *drawcount, *maxdrawcount, *stride);
    _debug(src_loc);
}

void InterfaceGlInner::NamedBufferData(GLuint buffer, GLsizeiptr size, const GLdata data, GLenum usage, GLsrc src_loc){
    glNamedBufferData(*buffer, *size, data.get(), *usage);
    _debug(src_loc);
}

void InterfaceGlInner::NamedBufferStorage(GLuint buffer, GLsizeiptr size, const GLdata data, GLbitfield flags, GLsrc src_loc){
    glNamedBufferStorage(*buffer, *size, data.get(), *flags);
    _debug(src_loc);
}

void InterfaceGlInner::NamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const GLdata data, GLsrc src_loc){
    glNamedBufferSubData(*buffer, *offset, *size, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::NamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf, GLsrc src_loc){
    glNamedFramebufferDrawBuffer(*framebuffer, *buf);
    _debug(src_loc);
}

void InterfaceGlInner::NamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, GLenumArr bufs, GLsrc src_loc){
    glNamedFramebufferDrawBuffers(*framebuffer, *n, bufs.get());
    _debug(src_loc);
}

void InterfaceGlInner::NamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param, GLsrc src_loc){
    glNamedFramebufferParameteri(*framebuffer, *pname, *param);
    _debug(src_loc);
}

void InterfaceGlInner::NamedFramebufferReadBuffer(GLuint framebuffer, GLenum src, GLsrc src_loc){
    glNamedFramebufferReadBuffer(*framebuffer, *src);
    _debug(src_loc);
}

void InterfaceGlInner::NamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer, GLsrc src_loc){
    glNamedFramebufferRenderbuffer(*framebuffer, *attachment, *renderbuffertarget, *renderbuffer);
    _debug(src_loc);
}

void InterfaceGlInner::NamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLsrc src_loc){
    glNamedFramebufferTexture(*framebuffer, *attachment, *texture, *level);
    _debug(src_loc);
}

void InterfaceGlInner::NamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer, GLsrc src_loc){
    glNamedFramebufferTextureLayer(*framebuffer, *attachment, *texture, *level, *layer);
    _debug(src_loc);
}

void InterfaceGlInner::NamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height, GLsrc src_loc){
    glNamedRenderbufferStorage(*renderbuffer, *internalformat, *width, *height);
    _debug(src_loc);
}

void InterfaceGlInner::NamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsrc src_loc){
    glNamedRenderbufferStorageMultisample(*renderbuffer, *samples, *internalformat, *width, *height);
    _debug(src_loc);
}

void InterfaceGlInner::ObjectLabel(GLenum identifier, GLuint name, GLsizei length, GLcharArr label, GLsrc src_loc){
    glObjectLabel(*identifier, *name, *length, label.get());
    _debug(src_loc);
}

void InterfaceGlInner::ObjectPtrLabel(const GLdata ptr, GLsizei length, GLcharArr label, GLsrc src_loc){
    glObjectPtrLabel(ptr.get(), *length, label.get());
    _debug(src_loc);
}

void InterfaceGlInner::PatchParameterfv(GLenum pname, GLfloatArr values, GLsrc src_loc){
    glPatchParameterfv(*pname, values.get());
    _debug(src_loc);
}

void InterfaceGlInner::PatchParameteri(GLenum pname, GLint value, GLsrc src_loc){
    glPatchParameteri(*pname, *value);
    _debug(src_loc);
}

void InterfaceGlInner::PauseTransformFeedback(GLsrc src_loc){
    glPauseTransformFeedback();
    _debug(src_loc);
}

void InterfaceGlInner::PixelStoref(GLenum pname, GLfloat param, GLsrc src_loc){
    glPixelStoref(*pname, *param);
    _debug(src_loc);
}

void InterfaceGlInner::PixelStorei(GLenum pname, GLint param, GLsrc src_loc){
    glPixelStorei(*pname, *param);
    _debug(src_loc);
}

void InterfaceGlInner::PointParameterf(GLenum pname, GLfloat param, GLsrc src_loc){
    glPointParameterf(*pname, *param);
    _debug(src_loc);
}

void InterfaceGlInner::PointParameterfv(GLenum pname, GLfloatArr params, GLsrc src_loc){
    glPointParameterfv(*pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::PointParameteri(GLenum pname, GLint param, GLsrc src_loc){
    glPointParameteri(*pname, *param);
    _debug(src_loc);
}

void InterfaceGlInner::PointParameteriv(GLenum pname, GLintArr params, GLsrc src_loc){
    glPointParameteriv(*pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::PointSize(GLfloat size, GLsrc src_loc){
    glPointSize(*size);
    _debug(src_loc);
}

void InterfaceGlInner::PolygonMode(GLenum face, GLenum mode, GLsrc src_loc){
    glPolygonMode(*face, *mode);
    _debug(src_loc);
}

void InterfaceGlInner::PolygonOffset(GLfloat factor, GLfloat units, GLsrc src_loc){
    glPolygonOffset(*factor, *units);
    _debug(src_loc);
}

void InterfaceGlInner::PolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp, GLsrc src_loc){
    glPolygonOffsetClamp(*factor, *units, *clamp);
    _debug(src_loc);
}

void InterfaceGlInner::PopDebugGroup(GLsrc src_loc){
    glPopDebugGroup();
    _debug(src_loc);
}

void InterfaceGlInner::PrimitiveRestartIndex(GLuint index, GLsrc src_loc){
    glPrimitiveRestartIndex(*index);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramBinary(GLuint program, GLenum binaryFormat, const GLdata binary, GLsizei length, GLsrc src_loc){
    glProgramBinary(*program, *binaryFormat, binary.get(), *length);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramParameteri(GLuint program, GLenum pname, GLint value, GLsrc src_loc){
    glProgramParameteri(*program, *pname, *value);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform1d(GLuint program, GLint location, GLdouble v0, GLsrc src_loc){
    glProgramUniform1d(*program, *location, *v0);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform1dv(GLuint program, GLint location, GLsizei count, GLdoubleArr value, GLsrc src_loc){
    glProgramUniform1dv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform1f(GLuint program, GLint location, GLfloat v0, GLsrc src_loc){
    glProgramUniform1f(*program, *location, *v0);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform1fv(GLuint program, GLint location, GLsizei count, GLfloatArr value, GLsrc src_loc){
    glProgramUniform1fv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform1i(GLuint program, GLint location, GLint v0, GLsrc src_loc){
    glProgramUniform1i(*program, *location, *v0);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform1iv(GLuint program, GLint location, GLsizei count, GLintArr value, GLsrc src_loc){
    glProgramUniform1iv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform1ui(GLuint program, GLint location, GLuint v0, GLsrc src_loc){
    glProgramUniform1ui(*program, *location, *v0);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform1uiv(GLuint program, GLint location, GLsizei count, GLuintArr value, GLsrc src_loc){
    glProgramUniform1uiv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLsrc src_loc){
    glProgramUniform2d(*program, *location, *v0, *v1);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform2dv(GLuint program, GLint location, GLsizei count, GLdoubleArr value, GLsrc src_loc){
    glProgramUniform2dv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLsrc src_loc){
    glProgramUniform2f(*program, *location, *v0, *v1);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform2fv(GLuint program, GLint location, GLsizei count, GLfloatArr value, GLsrc src_loc){
    glProgramUniform2fv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1, GLsrc src_loc){
    glProgramUniform2i(*program, *location, *v0, *v1);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform2iv(GLuint program, GLint location, GLsizei count, GLintArr value, GLsrc src_loc){
    glProgramUniform2iv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLsrc src_loc){
    glProgramUniform2ui(*program, *location, *v0, *v1);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform2uiv(GLuint program, GLint location, GLsizei count, GLuintArr value, GLsrc src_loc){
    glProgramUniform2uiv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLsrc src_loc){
    glProgramUniform3d(*program, *location, *v0, *v1, *v2);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform3dv(GLuint program, GLint location, GLsizei count, GLdoubleArr value, GLsrc src_loc){
    glProgramUniform3dv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLsrc src_loc){
    glProgramUniform3f(*program, *location, *v0, *v1, *v2);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform3fv(GLuint program, GLint location, GLsizei count, GLfloatArr value, GLsrc src_loc){
    glProgramUniform3fv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLsrc src_loc){
    glProgramUniform3i(*program, *location, *v0, *v1, *v2);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform3iv(GLuint program, GLint location, GLsizei count, GLintArr value, GLsrc src_loc){
    glProgramUniform3iv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLsrc src_loc){
    glProgramUniform3ui(*program, *location, *v0, *v1, *v2);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform3uiv(GLuint program, GLint location, GLsizei count, GLuintArr value, GLsrc src_loc){
    glProgramUniform3uiv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3, GLsrc src_loc){
    glProgramUniform4d(*program, *location, *v0, *v1, *v2, *v3);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform4dv(GLuint program, GLint location, GLsizei count, GLdoubleArr value, GLsrc src_loc){
    glProgramUniform4dv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3, GLsrc src_loc){
    glProgramUniform4f(*program, *location, *v0, *v1, *v2, *v3);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform4fv(GLuint program, GLint location, GLsizei count, GLfloatArr value, GLsrc src_loc){
    glProgramUniform4fv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3, GLsrc src_loc){
    glProgramUniform4i(*program, *location, *v0, *v1, *v2, *v3);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform4iv(GLuint program, GLint location, GLsizei count, GLintArr value, GLsrc src_loc){
    glProgramUniform4iv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3, GLsrc src_loc){
    glProgramUniform4ui(*program, *location, *v0, *v1, *v2, *v3);
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniform4uiv(GLuint program, GLint location, GLsizei count, GLuintArr value, GLsrc src_loc){
    glProgramUniform4uiv(*program, *location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glProgramUniformMatrix2dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glProgramUniformMatrix2fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glProgramUniformMatrix2x3dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glProgramUniformMatrix2x3fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glProgramUniformMatrix2x4dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glProgramUniformMatrix2x4fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glProgramUniformMatrix3dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glProgramUniformMatrix3fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glProgramUniformMatrix3x2dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glProgramUniformMatrix3x2fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glProgramUniformMatrix3x4dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glProgramUniformMatrix3x4fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glProgramUniformMatrix4dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glProgramUniformMatrix4fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glProgramUniformMatrix4x2dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glProgramUniformMatrix4x2fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glProgramUniformMatrix4x3dv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glProgramUniformMatrix4x3fv(*program, *location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::ProvokingVertex(GLenum mode, GLsrc src_loc){
    glProvokingVertex(*mode);
    _debug(src_loc);
}

void InterfaceGlInner::PushDebugGroup(GLenum source, GLuint id, GLsizei length, GLcharArr message, GLsrc src_loc){
    glPushDebugGroup(*source, *id, *length, message.get());
    _debug(src_loc);
}

void InterfaceGlInner::QueryCounter(GLuint id, GLenum target, GLsrc src_loc){
    glQueryCounter(*id, *target);
    _debug(src_loc);
}

void InterfaceGlInner::ReadBuffer(GLenum src, GLsrc src_loc){
    glReadBuffer(*src);
    _debug(src_loc);
}

void InterfaceGlInner::ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLdata pixels, GLsrc src_loc){
    glReadPixels(*x, *y, *width, *height, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceGlInner::ReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLdata data, GLsrc src_loc){
    glReadnPixels(*x, *y, *width, *height, *format, *type, *bufSize, data.get());
    _debug(src_loc);
}

void InterfaceGlInner::ReleaseShaderCompiler(GLsrc src_loc){
    glReleaseShaderCompiler();
    _debug(src_loc);
}

void InterfaceGlInner::RenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLsrc src_loc){
    glRenderbufferStorage(*target, *internalformat, *width, *height);
    _debug(src_loc);
}

void InterfaceGlInner::RenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsrc src_loc){
    glRenderbufferStorageMultisample(*target, *samples, *internalformat, *width, *height);
    _debug(src_loc);
}

void InterfaceGlInner::ResumeTransformFeedback(GLsrc src_loc){
    glResumeTransformFeedback();
    _debug(src_loc);
}

void InterfaceGlInner::SampleCoverage(GLfloat value, GLboolean invert, GLsrc src_loc){
    glSampleCoverage(*value, *invert);
    _debug(src_loc);
}

void InterfaceGlInner::SampleMaski(GLuint maskNumber, GLbitfield mask, GLsrc src_loc){
    glSampleMaski(*maskNumber, *mask);
    _debug(src_loc);
}

void InterfaceGlInner::SamplerParameterIiv(GLuint sampler, GLenum pname, GLintArr param, GLsrc src_loc){
    glSamplerParameterIiv(*sampler, *pname, param.get());
    _debug(src_loc);
}

void InterfaceGlInner::SamplerParameterIuiv(GLuint sampler, GLenum pname, GLuintArr param, GLsrc src_loc){
    glSamplerParameterIuiv(*sampler, *pname, param.get());
    _debug(src_loc);
}

void InterfaceGlInner::SamplerParameterf(GLuint sampler, GLenum pname, GLfloat param, GLsrc src_loc){
    glSamplerParameterf(*sampler, *pname, *param);
    _debug(src_loc);
}

void InterfaceGlInner::SamplerParameterfv(GLuint sampler, GLenum pname, GLfloatArr param, GLsrc src_loc){
    glSamplerParameterfv(*sampler, *pname, param.get());
    _debug(src_loc);
}

void InterfaceGlInner::SamplerParameteri(GLuint sampler, GLenum pname, GLint param, GLsrc src_loc){
    glSamplerParameteri(*sampler, *pname, *param);
    _debug(src_loc);
}

void InterfaceGlInner::SamplerParameteriv(GLuint sampler, GLenum pname, GLintArr param, GLsrc src_loc){
    glSamplerParameteriv(*sampler, *pname, param.get());
    _debug(src_loc);
}

void InterfaceGlInner::Scissor(GLint x, GLint y, GLsizei width, GLsizei height, GLsrc src_loc){
    glScissor(*x, *y, *width, *height);
    _debug(src_loc);
}

void InterfaceGlInner::ScissorArrayv(GLuint first, GLsizei count, GLintArr v, GLsrc src_loc){
    glScissorArrayv(*first, *count, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::ScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height, GLsrc src_loc){
    glScissorIndexed(*index, *left, *bottom, *width, *height);
    _debug(src_loc);
}

void InterfaceGlInner::ScissorIndexedv(GLuint index, GLintArr v, GLsrc src_loc){
    glScissorIndexedv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::ShaderBinary(GLsizei count, GLuintArr shaders, GLenum binaryFormat, const GLdata binary, GLsizei length, GLsrc src_loc){
    glShaderBinary(*count, shaders.get(), *binaryFormat, binary.get(), *length);
    _debug(src_loc);
}

void InterfaceGlInner::ShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding, GLsrc src_loc){
    glShaderStorageBlockBinding(*program, *storageBlockIndex, *storageBlockBinding);
    _debug(src_loc);
}

void InterfaceGlInner::SpecializeShader(GLuint shader, GLcharArr pEntryPoint, GLuint numSpecializationConstants, GLuintArr pConstantIndex, GLuintArr pConstantValue, GLsrc src_loc){
    glSpecializeShader(*shader, pEntryPoint.get(), *numSpecializationConstants, pConstantIndex.get(), pConstantValue.get());
    _debug(src_loc);
}

void InterfaceGlInner::StencilFunc(GLenum func, GLint ref, GLuint mask, GLsrc src_loc){
    glStencilFunc(*func, *ref, *mask);
    _debug(src_loc);
}

void InterfaceGlInner::StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask, GLsrc src_loc){
    glStencilFuncSeparate(*face, *func, *ref, *mask);
    _debug(src_loc);
}

void InterfaceGlInner::StencilMask(GLuint mask, GLsrc src_loc){
    glStencilMask(*mask);
    _debug(src_loc);
}

void InterfaceGlInner::StencilMaskSeparate(GLenum face, GLuint mask, GLsrc src_loc){
    glStencilMaskSeparate(*face, *mask);
    _debug(src_loc);
}

void InterfaceGlInner::StencilOp(GLenum fail, GLenum zfail, GLenum zpass, GLsrc src_loc){
    glStencilOp(*fail, *zfail, *zpass);
    _debug(src_loc);
}

void InterfaceGlInner::StencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass, GLsrc src_loc){
    glStencilOpSeparate(*face, *sfail, *dpfail, *dppass);
    _debug(src_loc);
}

void InterfaceGlInner::TexBuffer(GLenum target, GLenum internalformat, GLuint buffer, GLsrc src_loc){
    glTexBuffer(*target, *internalformat, *buffer);
    _debug(src_loc);
}

void InterfaceGlInner::TexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size, GLsrc src_loc){
    glTexBufferRange(*target, *internalformat, *buffer, *offset, *size);
    _debug(src_loc);
}

void InterfaceGlInner::TexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
    glTexImage1D(*target, *level, *internalformat, *width, *border, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceGlInner::TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
    glTexImage2D(*target, *level, *internalformat, *width, *height, *border, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceGlInner::TexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, GLsrc src_loc){
    glTexImage2DMultisample(*target, *samples, *internalformat, *width, *height, *fixedsamplelocations);
    _debug(src_loc);
}

void InterfaceGlInner::TexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
    glTexImage3D(*target, *level, *internalformat, *width, *height, *depth, *border, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceGlInner::TexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, GLsrc src_loc){
    glTexImage3DMultisample(*target, *samples, *internalformat, *width, *height, *depth, *fixedsamplelocations);
    _debug(src_loc);
}

void InterfaceGlInner::TexParameterIiv(GLenum target, GLenum pname, GLintArr params, GLsrc src_loc){
    glTexParameterIiv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::TexParameterIuiv(GLenum target, GLenum pname, GLuintArr params, GLsrc src_loc){
    glTexParameterIuiv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::TexParameterf(GLenum target, GLenum pname, GLfloat param, GLsrc src_loc){
    glTexParameterf(*target, *pname, *param);
    _debug(src_loc);
}

void InterfaceGlInner::TexParameterfv(GLenum target, GLenum pname, GLfloatArr params, GLsrc src_loc){
    glTexParameterfv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::TexParameteri(GLenum target, GLenum pname, GLint param, GLsrc src_loc){
    glTexParameteri(*target, *pname, *param);
    _debug(src_loc);
}

void InterfaceGlInner::TexParameteriv(GLenum target, GLenum pname, GLintArr params, GLsrc src_loc){
    glTexParameteriv(*target, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::TexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsrc src_loc){
    glTexStorage1D(*target, *levels, *internalformat, *width);
    _debug(src_loc);
}

void InterfaceGlInner::TexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsrc src_loc){
    glTexStorage2D(*target, *levels, *internalformat, *width, *height);
    _debug(src_loc);
}

void InterfaceGlInner::TexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, GLsrc src_loc){
    glTexStorage2DMultisample(*target, *samples, *internalformat, *width, *height, *fixedsamplelocations);
    _debug(src_loc);
}

void InterfaceGlInner::TexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsrc src_loc){
    glTexStorage3D(*target, *levels, *internalformat, *width, *height, *depth);
    _debug(src_loc);
}

void InterfaceGlInner::TexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, GLsrc src_loc){
    glTexStorage3DMultisample(*target, *samples, *internalformat, *width, *height, *depth, *fixedsamplelocations);
    _debug(src_loc);
}

void InterfaceGlInner::TexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
    glTexSubImage1D(*target, *level, *xoffset, *width, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceGlInner::TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
    glTexSubImage2D(*target, *level, *xoffset, *yoffset, *width, *height, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceGlInner::TexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
    glTexSubImage3D(*target, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceGlInner::TextureBarrier(GLsrc src_loc){
    glTextureBarrier();
    _debug(src_loc);
}

void InterfaceGlInner::TextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer, GLsrc src_loc){
    glTextureBuffer(*texture, *internalformat, *buffer);
    _debug(src_loc);
}

void InterfaceGlInner::TextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size, GLsrc src_loc){
    glTextureBufferRange(*texture, *internalformat, *buffer, *offset, *size);
    _debug(src_loc);
}

void InterfaceGlInner::TextureParameterIiv(GLuint texture, GLenum pname, GLintArr params, GLsrc src_loc){
    glTextureParameterIiv(*texture, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::TextureParameterIuiv(GLuint texture, GLenum pname, GLuintArr params, GLsrc src_loc){
    glTextureParameterIuiv(*texture, *pname, params.get());
    _debug(src_loc);
}

void InterfaceGlInner::TextureParameterf(GLuint texture, GLenum pname, GLfloat param, GLsrc src_loc){
    glTextureParameterf(*texture, *pname, *param);
    _debug(src_loc);
}

void InterfaceGlInner::TextureParameterfv(GLuint texture, GLenum pname, GLfloatArr param, GLsrc src_loc){
    glTextureParameterfv(*texture, *pname, param.get());
    _debug(src_loc);
}

void InterfaceGlInner::TextureParameteri(GLuint texture, GLenum pname, GLint param, GLsrc src_loc){
    glTextureParameteri(*texture, *pname, *param);
    _debug(src_loc);
}

void InterfaceGlInner::TextureParameteriv(GLuint texture, GLenum pname, GLintArr param, GLsrc src_loc){
    glTextureParameteriv(*texture, *pname, param.get());
    _debug(src_loc);
}

void InterfaceGlInner::TextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsrc src_loc){
    glTextureStorage1D(*texture, *levels, *internalformat, *width);
    _debug(src_loc);
}

void InterfaceGlInner::TextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsrc src_loc){
    glTextureStorage2D(*texture, *levels, *internalformat, *width, *height);
    _debug(src_loc);
}

void InterfaceGlInner::TextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, GLsrc src_loc){
    glTextureStorage2DMultisample(*texture, *samples, *internalformat, *width, *height, *fixedsamplelocations);
    _debug(src_loc);
}

void InterfaceGlInner::TextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsrc src_loc){
    glTextureStorage3D(*texture, *levels, *internalformat, *width, *height, *depth);
    _debug(src_loc);
}

void InterfaceGlInner::TextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, GLsrc src_loc){
    glTextureStorage3DMultisample(*texture, *samples, *internalformat, *width, *height, *depth, *fixedsamplelocations);
    _debug(src_loc);
}

void InterfaceGlInner::TextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
    glTextureSubImage1D(*texture, *level, *xoffset, *width, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceGlInner::TextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
    glTextureSubImage2D(*texture, *level, *xoffset, *yoffset, *width, *height, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceGlInner::TextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
    glTextureSubImage3D(*texture, *level, *xoffset, *yoffset, *zoffset, *width, *height, *depth, *format, *type, pixels.get());
    _debug(src_loc);
}

void InterfaceGlInner::TextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers, GLsrc src_loc){
    glTextureView(*texture, *target, *origtexture, *internalformat, *minlevel, *numlevels, *minlayer, *numlayers);
    _debug(src_loc);
}

void InterfaceGlInner::TransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer, GLsrc src_loc){
    glTransformFeedbackBufferBase(*xfb, *index, *buffer);
    _debug(src_loc);
}

void InterfaceGlInner::TransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size, GLsrc src_loc){
    glTransformFeedbackBufferRange(*xfb, *index, *buffer, *offset, *size);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform1d(GLint location, GLdouble x, GLsrc src_loc){
    glUniform1d(*location, *x);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform1dv(GLint location, GLsizei count, GLdoubleArr value, GLsrc src_loc){
    glUniform1dv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::Uniform1f(GLint location, GLfloat v0, GLsrc src_loc){
    glUniform1f(*location, *v0);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform1fv(GLint location, GLsizei count, GLfloatArr value, GLsrc src_loc){
    glUniform1fv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::Uniform1i(GLint location, GLint v0, GLsrc src_loc){
    glUniform1i(*location, *v0);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform1iv(GLint location, GLsizei count, GLintArr value, GLsrc src_loc){
    glUniform1iv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::Uniform1ui(GLint location, GLuint v0, GLsrc src_loc){
    glUniform1ui(*location, *v0);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform1uiv(GLint location, GLsizei count, GLuintArr value, GLsrc src_loc){
    glUniform1uiv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::Uniform2d(GLint location, GLdouble x, GLdouble y, GLsrc src_loc){
    glUniform2d(*location, *x, *y);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform2dv(GLint location, GLsizei count, GLdoubleArr value, GLsrc src_loc){
    glUniform2dv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::Uniform2f(GLint location, GLfloat v0, GLfloat v1, GLsrc src_loc){
    glUniform2f(*location, *v0, *v1);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform2fv(GLint location, GLsizei count, GLfloatArr value, GLsrc src_loc){
    glUniform2fv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::Uniform2i(GLint location, GLint v0, GLint v1, GLsrc src_loc){
    glUniform2i(*location, *v0, *v1);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform2iv(GLint location, GLsizei count, GLintArr value, GLsrc src_loc){
    glUniform2iv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::Uniform2ui(GLint location, GLuint v0, GLuint v1, GLsrc src_loc){
    glUniform2ui(*location, *v0, *v1);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform2uiv(GLint location, GLsizei count, GLuintArr value, GLsrc src_loc){
    glUniform2uiv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::Uniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLsrc src_loc){
    glUniform3d(*location, *x, *y, *z);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform3dv(GLint location, GLsizei count, GLdoubleArr value, GLsrc src_loc){
    glUniform3dv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLsrc src_loc){
    glUniform3f(*location, *v0, *v1, *v2);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform3fv(GLint location, GLsizei count, GLfloatArr value, GLsrc src_loc){
    glUniform3fv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::Uniform3i(GLint location, GLint v0, GLint v1, GLint v2, GLsrc src_loc){
    glUniform3i(*location, *v0, *v1, *v2);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform3iv(GLint location, GLsizei count, GLintArr value, GLsrc src_loc){
    glUniform3iv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::Uniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLsrc src_loc){
    glUniform3ui(*location, *v0, *v1, *v2);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform3uiv(GLint location, GLsizei count, GLuintArr value, GLsrc src_loc){
    glUniform3uiv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::Uniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w, GLsrc src_loc){
    glUniform4d(*location, *x, *y, *z, *w);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform4dv(GLint location, GLsizei count, GLdoubleArr value, GLsrc src_loc){
    glUniform4dv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3, GLsrc src_loc){
    glUniform4f(*location, *v0, *v1, *v2, *v3);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform4fv(GLint location, GLsizei count, GLfloatArr value, GLsrc src_loc){
    glUniform4fv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::Uniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3, GLsrc src_loc){
    glUniform4i(*location, *v0, *v1, *v2, *v3);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform4iv(GLint location, GLsizei count, GLintArr value, GLsrc src_loc){
    glUniform4iv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::Uniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3, GLsrc src_loc){
    glUniform4ui(*location, *v0, *v1, *v2, *v3);
    _debug(src_loc);
}

void InterfaceGlInner::Uniform4uiv(GLint location, GLsizei count, GLuintArr value, GLsrc src_loc){
    glUniform4uiv(*location, *count, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding, GLsrc src_loc){
    glUniformBlockBinding(*program, *uniformBlockIndex, *uniformBlockBinding);
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glUniformMatrix2dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glUniformMatrix2fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glUniformMatrix2x3dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glUniformMatrix2x3fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glUniformMatrix2x4dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glUniformMatrix2x4fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glUniformMatrix3dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glUniformMatrix3fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glUniformMatrix3x2dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glUniformMatrix3x2fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glUniformMatrix3x4dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glUniformMatrix3x4fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glUniformMatrix4dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glUniformMatrix4fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glUniformMatrix4x2dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glUniformMatrix4x2fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
    glUniformMatrix4x3dv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
    glUniformMatrix4x3fv(*location, *count, *transpose, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::UniformSubroutinesuiv(GLenum shadertype, GLsizei count, GLuintArr indices, GLsrc src_loc){
    glUniformSubroutinesuiv(*shadertype, *count, indices.get());
    _debug(src_loc);
}

InterfaceGlInner::GLbooleanRes InterfaceGlInner::UnmapBuffer(GLenum target, GLsrc src_loc){
    GLbooleanRes dst(new GLbooleanRes::element_type(glUnmapBuffer(*target)));
    _debug(src_loc);
    return dst;
}

InterfaceGlInner::GLbooleanRes InterfaceGlInner::UnmapNamedBuffer(GLuint buffer, GLsrc src_loc){
    GLbooleanRes dst(new GLbooleanRes::element_type(glUnmapNamedBuffer(*buffer)));
    _debug(src_loc);
    return dst;
}

void InterfaceGlInner::UseProgram(GLuint program, GLsrc src_loc){
    glUseProgram(*program);
    _debug(src_loc);
}

void InterfaceGlInner::UseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program, GLsrc src_loc){
    glUseProgramStages(*pipeline, *stages, *program);
    _debug(src_loc);
}

void InterfaceGlInner::ValidateProgram(GLuint program, GLsrc src_loc){
    glValidateProgram(*program);
    _debug(src_loc);
}

void InterfaceGlInner::ValidateProgramPipeline(GLuint pipeline, GLsrc src_loc){
    glValidateProgramPipeline(*pipeline);
    _debug(src_loc);
}

void InterfaceGlInner::VertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex, GLsrc src_loc){
    glVertexArrayAttribBinding(*vaobj, *attribindex, *bindingindex);
    _debug(src_loc);
}

void InterfaceGlInner::VertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset, GLsrc src_loc){
    glVertexArrayAttribFormat(*vaobj, *attribindex, *size, *type, *normalized, *relativeoffset);
    _debug(src_loc);
}

void InterfaceGlInner::VertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, GLsrc src_loc){
    glVertexArrayAttribIFormat(*vaobj, *attribindex, *size, *type, *relativeoffset);
    _debug(src_loc);
}

void InterfaceGlInner::VertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, GLsrc src_loc){
    glVertexArrayAttribLFormat(*vaobj, *attribindex, *size, *type, *relativeoffset);
    _debug(src_loc);
}

void InterfaceGlInner::VertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor, GLsrc src_loc){
    glVertexArrayBindingDivisor(*vaobj, *bindingindex, *divisor);
    _debug(src_loc);
}

void InterfaceGlInner::VertexArrayElementBuffer(GLuint vaobj, GLuint buffer, GLsrc src_loc){
    glVertexArrayElementBuffer(*vaobj, *buffer);
    _debug(src_loc);
}

void InterfaceGlInner::VertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride, GLsrc src_loc){
    glVertexArrayVertexBuffer(*vaobj, *bindingindex, *buffer, *offset, *stride);
    _debug(src_loc);
}

void InterfaceGlInner::VertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, GLuintArr buffers, GLintptrArr offsets, GLsizeiArr strides, GLsrc src_loc){
    glVertexArrayVertexBuffers(*vaobj, *first, *count, buffers.get(), offsets.get(), strides.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib1d(GLuint index, GLdouble x, GLsrc src_loc){
    glVertexAttrib1d(*index, *x);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib1dv(GLuint index, GLdoubleArr v, GLsrc src_loc){
    glVertexAttrib1dv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib1f(GLuint index, GLfloat x, GLsrc src_loc){
    glVertexAttrib1f(*index, *x);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib1fv(GLuint index, GLfloatArr v, GLsrc src_loc){
    glVertexAttrib1fv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib1s(GLuint index, GLshort x, GLsrc src_loc){
    glVertexAttrib1s(*index, *x);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib1sv(GLuint index, GLshort v, GLsrc src_loc){
    glVertexAttrib1sv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib2d(GLuint index, GLdouble x, GLdouble y, GLsrc src_loc){
    glVertexAttrib2d(*index, *x, *y);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib2dv(GLuint index, GLdoubleArr v, GLsrc src_loc){
    glVertexAttrib2dv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib2f(GLuint index, GLfloat x, GLfloat y, GLsrc src_loc){
    glVertexAttrib2f(*index, *x, *y);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib2fv(GLuint index, GLfloatArr v, GLsrc src_loc){
    glVertexAttrib2fv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib2s(GLuint index, GLshort x, GLshort y, GLsrc src_loc){
    glVertexAttrib2s(*index, *x, *y);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib2sv(GLuint index, GLshort v, GLsrc src_loc){
    glVertexAttrib2sv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLsrc src_loc){
    glVertexAttrib3d(*index, *x, *y, *z);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib3dv(GLuint index, GLdoubleArr v, GLsrc src_loc){
    glVertexAttrib3dv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLsrc src_loc){
    glVertexAttrib3f(*index, *x, *y, *z);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib3fv(GLuint index, GLfloatArr v, GLsrc src_loc){
    glVertexAttrib3fv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z, GLsrc src_loc){
    glVertexAttrib3s(*index, *x, *y, *z);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib3sv(GLuint index, GLshort v, GLsrc src_loc){
    glVertexAttrib3sv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4Nbv(GLuint index, GLbyte v, GLsrc src_loc){
    glVertexAttrib4Nbv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4Niv(GLuint index, GLintArr v, GLsrc src_loc){
    glVertexAttrib4Niv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4Nsv(GLuint index, GLshort v, GLsrc src_loc){
    glVertexAttrib4Nsv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w, GLsrc src_loc){
    glVertexAttrib4Nub(*index, *x, *y, *z, *w);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4Nubv(GLuint index, GLubyte v, GLsrc src_loc){
    glVertexAttrib4Nubv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4Nuiv(GLuint index, GLuintArr v, GLsrc src_loc){
    glVertexAttrib4Nuiv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4Nusv(GLuint index, GLushort v, GLsrc src_loc){
    glVertexAttrib4Nusv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4bv(GLuint index, GLbyte v, GLsrc src_loc){
    glVertexAttrib4bv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w, GLsrc src_loc){
    glVertexAttrib4d(*index, *x, *y, *z, *w);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4dv(GLuint index, GLdoubleArr v, GLsrc src_loc){
    glVertexAttrib4dv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLsrc src_loc){
    glVertexAttrib4f(*index, *x, *y, *z, *w);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4fv(GLuint index, GLfloatArr v, GLsrc src_loc){
    glVertexAttrib4fv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4iv(GLuint index, GLintArr v, GLsrc src_loc){
    glVertexAttrib4iv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w, GLsrc src_loc){
    glVertexAttrib4s(*index, *x, *y, *z, *w);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4sv(GLuint index, GLshort v, GLsrc src_loc){
    glVertexAttrib4sv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4ubv(GLuint index, GLubyte v, GLsrc src_loc){
    glVertexAttrib4ubv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4uiv(GLuint index, GLuintArr v, GLsrc src_loc){
    glVertexAttrib4uiv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttrib4usv(GLuint index, GLushort v, GLsrc src_loc){
    glVertexAttrib4usv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribBinding(GLuint attribindex, GLuint bindingindex, GLsrc src_loc){
    glVertexAttribBinding(*attribindex, *bindingindex);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribDivisor(GLuint index, GLuint divisor, GLsrc src_loc){
    glVertexAttribDivisor(*index, *divisor);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset, GLsrc src_loc){
    glVertexAttribFormat(*attribindex, *size, *type, *normalized, *relativeoffset);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI1i(GLuint index, GLint x, GLsrc src_loc){
    glVertexAttribI1i(*index, *x);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI1iv(GLuint index, GLintArr v, GLsrc src_loc){
    glVertexAttribI1iv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI1ui(GLuint index, GLuint x, GLsrc src_loc){
    glVertexAttribI1ui(*index, *x);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI1uiv(GLuint index, GLuintArr v, GLsrc src_loc){
    glVertexAttribI1uiv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI2i(GLuint index, GLint x, GLint y, GLsrc src_loc){
    glVertexAttribI2i(*index, *x, *y);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI2iv(GLuint index, GLintArr v, GLsrc src_loc){
    glVertexAttribI2iv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI2ui(GLuint index, GLuint x, GLuint y, GLsrc src_loc){
    glVertexAttribI2ui(*index, *x, *y);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI2uiv(GLuint index, GLuintArr v, GLsrc src_loc){
    glVertexAttribI2uiv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI3i(GLuint index, GLint x, GLint y, GLint z, GLsrc src_loc){
    glVertexAttribI3i(*index, *x, *y, *z);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI3iv(GLuint index, GLintArr v, GLsrc src_loc){
    glVertexAttribI3iv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z, GLsrc src_loc){
    glVertexAttribI3ui(*index, *x, *y, *z);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI3uiv(GLuint index, GLuintArr v, GLsrc src_loc){
    glVertexAttribI3uiv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI4bv(GLuint index, GLbyte v, GLsrc src_loc){
    glVertexAttribI4bv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w, GLsrc src_loc){
    glVertexAttribI4i(*index, *x, *y, *z, *w);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI4iv(GLuint index, GLintArr v, GLsrc src_loc){
    glVertexAttribI4iv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI4sv(GLuint index, GLshort v, GLsrc src_loc){
    glVertexAttribI4sv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI4ubv(GLuint index, GLubyte v, GLsrc src_loc){
    glVertexAttribI4ubv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w, GLsrc src_loc){
    glVertexAttribI4ui(*index, *x, *y, *z, *w);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI4uiv(GLuint index, GLuintArr v, GLsrc src_loc){
    glVertexAttribI4uiv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribI4usv(GLuint index, GLushort v, GLsrc src_loc){
    glVertexAttribI4usv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, GLsrc src_loc){
    glVertexAttribIFormat(*attribindex, *size, *type, *relativeoffset);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLdata pointer, GLsrc src_loc){
    glVertexAttribIPointer(*index, *size, *type, *stride, pointer.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribL1d(GLuint index, GLdouble x, GLsrc src_loc){
    glVertexAttribL1d(*index, *x);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribL1dv(GLuint index, GLdoubleArr v, GLsrc src_loc){
    glVertexAttribL1dv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribL2d(GLuint index, GLdouble x, GLdouble y, GLsrc src_loc){
    glVertexAttribL2d(*index, *x, *y);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribL2dv(GLuint index, GLdoubleArr v, GLsrc src_loc){
    glVertexAttribL2dv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLsrc src_loc){
    glVertexAttribL3d(*index, *x, *y, *z);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribL3dv(GLuint index, GLdoubleArr v, GLsrc src_loc){
    glVertexAttribL3dv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w, GLsrc src_loc){
    glVertexAttribL4d(*index, *x, *y, *z, *w);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribL4dv(GLuint index, GLdoubleArr v, GLsrc src_loc){
    glVertexAttribL4dv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, GLsrc src_loc){
    glVertexAttribLFormat(*attribindex, *size, *type, *relativeoffset);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLdata pointer, GLsrc src_loc){
    glVertexAttribLPointer(*index, *size, *type, *stride, pointer.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, GLsrc src_loc){
    glVertexAttribP1ui(*index, *type, *normalized, *value);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, GLuintArr value, GLsrc src_loc){
    glVertexAttribP1uiv(*index, *type, *normalized, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, GLsrc src_loc){
    glVertexAttribP2ui(*index, *type, *normalized, *value);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, GLuintArr value, GLsrc src_loc){
    glVertexAttribP2uiv(*index, *type, *normalized, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, GLsrc src_loc){
    glVertexAttribP3ui(*index, *type, *normalized, *value);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, GLuintArr value, GLsrc src_loc){
    glVertexAttribP3uiv(*index, *type, *normalized, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, GLsrc src_loc){
    glVertexAttribP4ui(*index, *type, *normalized, *value);
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, GLuintArr value, GLsrc src_loc){
    glVertexAttribP4uiv(*index, *type, *normalized, value.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLdata pointer, GLsrc src_loc){
    glVertexAttribPointer(*index, *size, *type, *normalized, *stride, pointer.get());
    _debug(src_loc);
}

void InterfaceGlInner::VertexBindingDivisor(GLuint bindingindex, GLuint divisor, GLsrc src_loc){
    glVertexBindingDivisor(*bindingindex, *divisor);
    _debug(src_loc);
}

void InterfaceGlInner::Viewport(GLint x, GLint y, GLsizei width, GLsizei height, GLsrc src_loc){
    glViewport(*x, *y, *width, *height);
    _debug(src_loc);
}

void InterfaceGlInner::ViewportArrayv(GLuint first, GLsizei count, GLfloatArr v, GLsrc src_loc){
    glViewportArrayv(*first, *count, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::ViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h, GLsrc src_loc){
    glViewportIndexedf(*index, *x, *y, *w, *h);
    _debug(src_loc);
}

void InterfaceGlInner::ViewportIndexedfv(GLuint index, GLfloatArr v, GLsrc src_loc){
    glViewportIndexedfv(*index, v.get());
    _debug(src_loc);
}

void InterfaceGlInner::WaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, GLsrc src_loc){
    glWaitSync(*sync, *flags, *timeout);
    _debug(src_loc);
}
