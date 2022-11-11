#include "gl/InterfaceOuter.hpp"

#include "glad/gl.h"

#include "Context.hpp"

using namespace glwpp;
using namespace GL;

template<typename T>
using sptr = std::shared_ptr<T>;

    // _ctx->getOnRunEvent().addActionQueued([](){});
InterfaceOuter::InterfaceOuter(Context& ctx, std::function<void(SrcLoc)> debug) :
    InterfaceInner(ctx, debug){
}

InterfaceOuter::~InterfaceOuter(){
}

template<auto F, typename ... Args>
auto InterfaceOuter::_call(Args... args){
    using R = std::invoke_result_t<decltype(F), InterfaceOuter, Args...>;
    if constexpr (std::is_same_v<R, void>){
        _ctx->getOnRunEvent().addActionQueued([this, args...](Context*, const Context::ms&){
            (this->*F)(args...);
            return false;
        });
    } else {
        R result;
        _ctx->getOnRunEvent().addActionQueued([this, result, args...](Context*, const Context::ms&){
            *result = *(this->*F)(args...);
            return false;
        });
        return result;
    }
}

void InterfaceOuter::ActiveShaderProgram(GLuint pipeline, GLuint program, SrcLoc src_loc){
    return _call<&InterfaceInner::ActiveShaderProgram>(pipeline, program, src_loc);
}

void InterfaceOuter::ActiveTexture(GLenum texture, SrcLoc src_loc){
    return _call<&InterfaceInner::ActiveTexture>(texture, src_loc);
}

void InterfaceOuter::AttachShader(GLuint program, GLuint shader, SrcLoc src_loc){
    return _call<&InterfaceInner::AttachShader>(program, shader, src_loc);
}

void InterfaceOuter::BeginConditionalRender(GLuint id, GLenum mode, SrcLoc src_loc){
    return _call<&InterfaceInner::BeginConditionalRender>(id, mode, src_loc);
}

void InterfaceOuter::BeginQuery(GLenum target, GLuint id, SrcLoc src_loc){
    return _call<&InterfaceInner::BeginQuery>(target, id, src_loc);
}

void InterfaceOuter::BeginQueryIndexed(GLenum target, GLuint index, GLuint id, SrcLoc src_loc){
    return _call<&InterfaceInner::BeginQueryIndexed>(target, index, id, src_loc);
}

void InterfaceOuter::BeginTransformFeedback(GLenum primitiveMode, SrcLoc src_loc){
    return _call<&InterfaceInner::BeginTransformFeedback>(primitiveMode, src_loc);
}

void InterfaceOuter::BindAttribLocation(GLuint program, GLuint index, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::BindAttribLocation>(program, index, name, src_loc);
}

void InterfaceOuter::BindBuffer(GLenum target, GLuint buffer, SrcLoc src_loc){
    return _call<&InterfaceInner::BindBuffer>(target, buffer, src_loc);
}

void InterfaceOuter::BindBufferBase(GLenum target, GLuint index, GLuint buffer, SrcLoc src_loc){
    return _call<&InterfaceInner::BindBufferBase>(target, index, buffer, src_loc);
}

void InterfaceOuter::BindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size, SrcLoc src_loc){
    return _call<&InterfaceInner::BindBufferRange>(target, index, buffer, offset, size, src_loc);
}

void InterfaceOuter::BindBuffersBase(GLenum target, GLuint first, csr_GLsizei count, GLuintArr buffers, SrcLoc src_loc){
    return _call<&InterfaceInner::BindBuffersBase>(target, first, count, buffers, src_loc);
}

void InterfaceOuter::BindBuffersRange(GLenum target, GLuint first, csr_GLsizei count, GLuintArr buffers, GLintptrArr offsets, GLsizeiptrArr sizes, SrcLoc src_loc){
    return _call<&InterfaceInner::BindBuffersRange>(target, first, count, buffers, offsets, sizes, src_loc);
}

void InterfaceOuter::BindFragDataLocation(GLuint program, GLuint color, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::BindFragDataLocation>(program, color, name, src_loc);
}

void InterfaceOuter::BindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::BindFragDataLocationIndexed>(program, colorNumber, index, name, src_loc);
}

void InterfaceOuter::BindFramebuffer(GLenum target, GLuint framebuffer, SrcLoc src_loc){
    return _call<&InterfaceInner::BindFramebuffer>(target, framebuffer, src_loc);
}

void InterfaceOuter::BindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format, SrcLoc src_loc){
    return _call<&InterfaceInner::BindImageTexture>(unit, texture, level, layered, layer, access, format, src_loc);
}

void InterfaceOuter::BindImageTextures(GLuint first, csr_GLsizei count, GLuintArr textures, SrcLoc src_loc){
    return _call<&InterfaceInner::BindImageTextures>(first, count, textures, src_loc);
}

void InterfaceOuter::BindProgramPipeline(GLuint pipeline, SrcLoc src_loc){
    return _call<&InterfaceInner::BindProgramPipeline>(pipeline, src_loc);
}

void InterfaceOuter::BindRenderbuffer(GLenum target, GLuint renderbuffer, SrcLoc src_loc){
    return _call<&InterfaceInner::BindRenderbuffer>(target, renderbuffer, src_loc);
}

void InterfaceOuter::BindSampler(GLuint unit, GLuint sampler, SrcLoc src_loc){
    return _call<&InterfaceInner::BindSampler>(unit, sampler, src_loc);
}

void InterfaceOuter::BindSamplers(GLuint first, csr_GLsizei count, GLuintArr samplers, SrcLoc src_loc){
    return _call<&InterfaceInner::BindSamplers>(first, count, samplers, src_loc);
}

void InterfaceOuter::BindTexture(GLenum target, GLuint texture, SrcLoc src_loc){
    return _call<&InterfaceInner::BindTexture>(target, texture, src_loc);
}

void InterfaceOuter::BindTextureUnit(GLuint unit, GLuint texture, SrcLoc src_loc){
    return _call<&InterfaceInner::BindTextureUnit>(unit, texture, src_loc);
}

void InterfaceOuter::BindTextures(GLuint first, csr_GLsizei count, GLuintArr textures, SrcLoc src_loc){
    return _call<&InterfaceInner::BindTextures>(first, count, textures, src_loc);
}

void InterfaceOuter::BindTransformFeedback(GLenum target, GLuint id, SrcLoc src_loc){
    return _call<&InterfaceInner::BindTransformFeedback>(target, id, src_loc);
}

void InterfaceOuter::BindVertexArray(GLuint array, SrcLoc src_loc){
    return _call<&InterfaceInner::BindVertexArray>(array, src_loc);
}

void InterfaceOuter::BindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, csr_GLsizei stride, SrcLoc src_loc){
    return _call<&InterfaceInner::BindVertexBuffer>(bindingindex, buffer, offset, stride, src_loc);
}

void InterfaceOuter::BindVertexBuffers(GLuint first, csr_GLsizei count, GLuintArr buffers, GLintptrArr offsets, csra_GLsizeiArr strides, SrcLoc src_loc){
    return _call<&InterfaceInner::BindVertexBuffers>(first, count, buffers, offsets, strides, src_loc);
}

void InterfaceOuter::BlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, SrcLoc src_loc){
    return _call<&InterfaceInner::BlendColor>(red, green, blue, alpha, src_loc);
}

void InterfaceOuter::BlendEquation(GLenum mode, SrcLoc src_loc){
    return _call<&InterfaceInner::BlendEquation>(mode, src_loc);
}

void InterfaceOuter::BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha, SrcLoc src_loc){
    return _call<&InterfaceInner::BlendEquationSeparate>(modeRGB, modeAlpha, src_loc);
}

void InterfaceOuter::BlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha, SrcLoc src_loc){
    return _call<&InterfaceInner::BlendEquationSeparatei>(buf, modeRGB, modeAlpha, src_loc);
}

void InterfaceOuter::BlendEquationi(GLuint buf, GLenum mode, SrcLoc src_loc){
    return _call<&InterfaceInner::BlendEquationi>(buf, mode, src_loc);
}

void InterfaceOuter::BlendFunc(GLenum sfactor, GLenum dfactor, SrcLoc src_loc){
    return _call<&InterfaceInner::BlendFunc>(sfactor, dfactor, src_loc);
}

void InterfaceOuter::BlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha, SrcLoc src_loc){
    return _call<&InterfaceInner::BlendFuncSeparate>(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha, src_loc);
}

void InterfaceOuter::BlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha, GLenum modeAlpha, SrcLoc src_loc){
    return _call<&InterfaceInner::BlendFuncSeparatei>(buf, srcRGB, dstRGB, srcAlpha, dstAlpha, modeAlpha, src_loc);
}

void InterfaceOuter::BlendFunci(GLuint buf, GLenum src, GLenum dst, SrcLoc src_loc){
    return _call<&InterfaceInner::BlendFunci>(buf, src, dst, src_loc);
}

void InterfaceOuter::BlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter, SrcLoc src_loc){
    return _call<&InterfaceInner::BlitFramebuffer>(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter, src_loc);
}

void InterfaceOuter::BlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter, SrcLoc src_loc){
    return _call<&InterfaceInner::BlitNamedFramebuffer>(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter, src_loc);
}

void InterfaceOuter::BufferData(GLenum target, GLsizeiptr size, GLdata data, GLenum usage, SrcLoc src_loc){
    return _call<&InterfaceInner::BufferData>(target, size, data, usage, src_loc);
}

void InterfaceOuter::BufferStorage(GLenum target, GLsizeiptr size, GLdata data, GLbitfield flags, SrcLoc src_loc){
    return _call<&InterfaceInner::BufferStorage>(target, size, data, flags, src_loc);
}

void InterfaceOuter::BufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::BufferSubData>(target, offset, size, data, src_loc);
}

void InterfaceOuter::CheckFramebufferStatus(GLenum target, SrcLoc src_loc){
    return _call<&InterfaceInner::CheckFramebufferStatus>(target, src_loc);
}

void InterfaceOuter::CheckNamedFramebufferStatus(GLuint framebuffer, GLenum target, SrcLoc src_loc){
    return _call<&InterfaceInner::CheckNamedFramebufferStatus>(framebuffer, target, src_loc);
}

void InterfaceOuter::ClampColor(GLenum target, GLenum clamp, SrcLoc src_loc){
    return _call<&InterfaceInner::ClampColor>(target, clamp, src_loc);
}

void InterfaceOuter::Clear(GLbitfield mask, SrcLoc src_loc){
    return _call<&InterfaceInner::Clear>(mask, src_loc);
}

void InterfaceOuter::ClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearBufferData>(target, internalformat, format, type, data, src_loc);
}

void InterfaceOuter::ClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearBufferSubData>(target, internalformat, offset, size, format, type, data, src_loc);
}

void InterfaceOuter::ClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearBufferfi>(buffer, drawbuffer, depth, stencil, src_loc);
}

void InterfaceOuter::ClearBufferfv(GLenum buffer, GLint drawbuffer, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearBufferfv>(buffer, drawbuffer, value, src_loc);
}

void InterfaceOuter::ClearBufferiv(GLenum buffer, GLint drawbuffer, GLintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearBufferiv>(buffer, drawbuffer, value, src_loc);
}

void InterfaceOuter::ClearBufferuiv(GLenum buffer, GLint drawbuffer, GLuintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearBufferuiv>(buffer, drawbuffer, value, src_loc);
}

void InterfaceOuter::ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearColor>(red, green, blue, alpha, src_loc);
}

void InterfaceOuter::ClearDepth(GLdouble depth, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearDepth>(depth, src_loc);
}

void InterfaceOuter::ClearDepthf(GLfloat d, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearDepthf>(d, src_loc);
}

void InterfaceOuter::ClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearNamedBufferData>(buffer, internalformat, format, type, data, src_loc);
}

void InterfaceOuter::ClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearNamedBufferSubData>(buffer, internalformat, offset, size, format, type, data, src_loc);
}

void InterfaceOuter::ClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearNamedFramebufferfi>(framebuffer, buffer, drawbuffer, depth, stencil, src_loc);
}

void InterfaceOuter::ClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearNamedFramebufferfv>(framebuffer, buffer, drawbuffer, value, src_loc);
}

void InterfaceOuter::ClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearNamedFramebufferiv>(framebuffer, buffer, drawbuffer, value, src_loc);
}

void InterfaceOuter::ClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLuintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearNamedFramebufferuiv>(framebuffer, buffer, drawbuffer, value, src_loc);
}

void InterfaceOuter::ClearStencil(GLint s, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearStencil>(s, src_loc);
}

void InterfaceOuter::ClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearTexImage>(texture, level, format, type, data, src_loc);
}

void InterfaceOuter::ClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, csr_GLsizei width, csr_GLsizei height, csr_GLsizei depth, GLenum format, GLenum type, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::ClearTexSubImage>(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data, src_loc);
}

void InterfaceOuter::ClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, SrcLoc src_loc){
    return _call<&InterfaceInner::ClientWaitSync>(sync, flags, timeout, src_loc);
}

void InterfaceOuter::ClipControl(GLenum origin, GLenum depth, SrcLoc src_loc){
    return _call<&InterfaceInner::ClipControl>(origin, depth, src_loc);
}

void InterfaceOuter::ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha, SrcLoc src_loc){
    return _call<&InterfaceInner::ColorMask>(red, green, blue, alpha, src_loc);
}

void InterfaceOuter::ColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a, SrcLoc src_loc){
    return _call<&InterfaceInner::ColorMaski>(index, r, g, b, a, src_loc);
}

void InterfaceOuter::CompileShader(GLuint shader, SrcLoc src_loc){
    return _call<&InterfaceInner::CompileShader>(shader, src_loc);
}

void InterfaceOuter::CompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, csr_GLsizei width, GLint border, csr_GLsizei imageSize, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::CompressedTexImage1D>(target, level, internalformat, width, border, imageSize, data, src_loc);
}

void InterfaceOuter::CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, csr_GLsizei width, csr_GLsizei height, GLint border, csr_GLsizei imageSize, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::CompressedTexImage2D>(target, level, internalformat, width, height, border, imageSize, data, src_loc);
}

void InterfaceOuter::CompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, csr_GLsizei width, csr_GLsizei height, csr_GLsizei depth, GLint border, csr_GLsizei imageSize, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::CompressedTexImage3D>(target, level, internalformat, width, height, depth, border, imageSize, data, src_loc);
}

void InterfaceOuter::CompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, csr_GLsizei width, GLenum format, csr_GLsizei imageSize, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::CompressedTexSubImage1D>(target, level, xoffset, width, format, imageSize, data, src_loc);
}

void InterfaceOuter::CompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, csr_GLsizei width, csr_GLsizei height, GLenum format, csr_GLsizei imageSize, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::CompressedTexSubImage2D>(target, level, xoffset, yoffset, width, height, format, imageSize, data, src_loc);
}

void InterfaceOuter::CompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, csr_GLsizei width, csr_GLsizei height, csr_GLsizei depth, GLenum format, csr_GLsizei imageSize, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::CompressedTexSubImage3D>(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data, src_loc);
}

void InterfaceOuter::CompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, csr_GLsizei width, GLenum format, csr_GLsizei imageSize, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::CompressedTextureSubImage1D>(texture, level, xoffset, width, format, imageSize, data, src_loc);
}

void InterfaceOuter::CompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, csr_GLsizei width, csr_GLsizei height, GLenum format, csr_GLsizei imageSize, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::CompressedTextureSubImage2D>(texture, level, xoffset, yoffset, width, height, format, imageSize, data, src_loc);
}

void InterfaceOuter::CompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, csr_GLsizei width, csr_GLsizei height, csr_GLsizei depth, GLenum format, csr_GLsizei imageSize, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::CompressedTextureSubImage3D>(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data, src_loc);
}

void InterfaceOuter::CopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, SrcLoc src_loc){
    return _call<&InterfaceInner::CopyBufferSubData>(readTarget, writeTarget, readOffset, writeOffset, size, src_loc);
}

void InterfaceOuter::CopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, csr_GLsizei srcWidth, csr_GLsizei srcHeight, csr_GLsizei srcDepth, SrcLoc src_loc){
    return _call<&InterfaceInner::CopyImageSubData>(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth, src_loc);
}

void InterfaceOuter::CopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, SrcLoc src_loc){
    return _call<&InterfaceInner::CopyNamedBufferSubData>(readBuffer, writeBuffer, readOffset, writeOffset, size, src_loc);
}

void InterfaceOuter::CopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, csr_GLsizei width, GLint border, SrcLoc src_loc){
    return _call<&InterfaceInner::CopyTexImage1D>(target, level, internalformat, x, y, width, border, src_loc);
}

void InterfaceOuter::CopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, csr_GLsizei width, csr_GLsizei height, GLint border, SrcLoc src_loc){
    return _call<&InterfaceInner::CopyTexImage2D>(target, level, internalformat, x, y, width, height, border, src_loc);
}

void InterfaceOuter::CopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, csr_GLsizei width, SrcLoc src_loc){
    return _call<&InterfaceInner::CopyTexSubImage1D>(target, level, xoffset, x, y, width, src_loc);
}

void InterfaceOuter::CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, csr_GLsizei width, csr_GLsizei height, SrcLoc src_loc){
    return _call<&InterfaceInner::CopyTexSubImage2D>(target, level, xoffset, yoffset, x, y, width, height, src_loc);
}

void InterfaceOuter::CopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, csr_GLsizei width, csr_GLsizei height, SrcLoc src_loc){
    return _call<&InterfaceInner::CopyTexSubImage3D>(target, level, xoffset, yoffset, zoffset, x, y, width, height, src_loc);
}

void InterfaceOuter::CopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, csr_GLsizei width, SrcLoc src_loc){
    return _call<&InterfaceInner::CopyTextureSubImage1D>(texture, level, xoffset, x, y, width, src_loc);
}

void InterfaceOuter::CopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, csr_GLsizei width, csr_GLsizei height, SrcLoc src_loc){
    return _call<&InterfaceInner::CopyTextureSubImage2D>(texture, level, xoffset, yoffset, x, y, width, height, src_loc);
}

void InterfaceOuter::CopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, csr_GLsizei width, csr_GLsizei height, SrcLoc src_loc){
    return _call<&InterfaceInner::CopyTextureSubImage3D>(texture, level, xoffset, yoffset, zoffset, x, y, width, height, src_loc);
}

void InterfaceOuter::CreateBuffers(csr_GLsizei n, GLuintArr dst, SrcLoc src_loc){
    return _call<&InterfaceInner::CreateBuffers>(n, dst, src_loc);
}

void InterfaceOuter::CreateFramebuffers(csr_GLsizei n, GLuintArr framebuffers, SrcLoc src_loc){
    return _call<&InterfaceInner::CreateFramebuffers>(n, framebuffers, src_loc);
}

GLuintRes InterfaceOuter::CreateProgram(SrcLoc src_loc){
    return _call<&InterfaceInner::CreateProgram>(src_loc);
}

void InterfaceOuter::CreateProgramPipelines(csr_GLsizei n, GLuintArr pipelines, SrcLoc src_loc){
    return _call<&InterfaceInner::CreateProgramPipelines>(n, pipelines, src_loc);
}

void InterfaceOuter::CreateQueries(GLenum target, csr_GLsizei n, GLuintArr ids, SrcLoc src_loc){
    return _call<&InterfaceInner::CreateQueries>(target, n, ids, src_loc);
}

void InterfaceOuter::CreateRenderbuffers(csr_GLsizei n, GLuintArr renderbuffers, SrcLoc src_loc){
    return _call<&InterfaceInner::CreateRenderbuffers>(n, renderbuffers, src_loc);
}

void InterfaceOuter::CreateSamplers(csr_GLsizei n, GLuintArr samplers, SrcLoc src_loc){
    return _call<&InterfaceInner::CreateSamplers>(n, samplers, src_loc);
}

GLuintRes InterfaceOuter::CreateShader(GLenum type, SrcLoc src_loc){
    return _call<&InterfaceInner::CreateShader>(type, src_loc);
}

void InterfaceOuter::CreateTextures(GLenum target, csr_GLsizei n, GLuintArr textures, SrcLoc src_loc){
    return _call<&InterfaceInner::CreateTextures>(target, n, textures, src_loc);
}

void InterfaceOuter::CreateTransformFeedbacks(csr_GLsizei n, GLuintArr ids, SrcLoc src_loc){
    return _call<&InterfaceInner::CreateTransformFeedbacks>(n, ids, src_loc);
}

void InterfaceOuter::CreateVertexArrays(csr_GLsizei n, GLuintArr arrays, SrcLoc src_loc){
    return _call<&InterfaceInner::CreateVertexArrays>(n, arrays, src_loc);
}

void InterfaceOuter::CullFace(GLenum mode, SrcLoc src_loc){
    return _call<&InterfaceInner::CullFace>(mode, src_loc);
}

void InterfaceOuter::DebugMessageControl(GLenum source, GLenum type, GLenum severity, csr_GLsizei count, GLuintArr ids, GLboolean enabled, SrcLoc src_loc){
    return _call<&InterfaceInner::DebugMessageControl>(source, type, severity, count, ids, enabled, src_loc);
}

void InterfaceOuter::DebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, csr_GLsizei length, GLcharArr buf, SrcLoc src_loc){
    return _call<&InterfaceInner::DebugMessageInsert>(source, type, id, severity, length, buf, src_loc);
}

void InterfaceOuter::DeleteBuffers(csr_GLsizei n, GLuintArr buffers, SrcLoc src_loc){
    return _call<&InterfaceInner::DeleteBuffers>(n, buffers, src_loc);
}

void InterfaceOuter::DeleteFramebuffers(csr_GLsizei n, GLuintArr framebuffers, SrcLoc src_loc){
    return _call<&InterfaceInner::DeleteFramebuffers>(n, framebuffers, src_loc);
}

void InterfaceOuter::DeleteProgram(GLuint program, SrcLoc src_loc){
    return _call<&InterfaceInner::DeleteProgram>(program, src_loc);
}

void InterfaceOuter::DeleteProgramPipelines(csr_GLsizei n, GLuintArr pipelines, SrcLoc src_loc){
    return _call<&InterfaceInner::DeleteProgramPipelines>(n, pipelines, src_loc);
}

void InterfaceOuter::DeleteQueries(csr_GLsizei n, GLuintArr ids, SrcLoc src_loc){
    return _call<&InterfaceInner::DeleteQueries>(n, ids, src_loc);
}

void InterfaceOuter::DeleteRenderbuffers(csr_GLsizei n, GLuintArr renderbuffers, SrcLoc src_loc){
    return _call<&InterfaceInner::DeleteRenderbuffers>(n, renderbuffers, src_loc);
}

void InterfaceOuter::DeleteSamplers(csr_GLsizei count, GLuintArr samplers, SrcLoc src_loc){
    return _call<&InterfaceInner::DeleteSamplers>(count, samplers, src_loc);
}

void InterfaceOuter::DeleteShader(GLuint shader, SrcLoc src_loc){
    return _call<&InterfaceInner::DeleteShader>(shader, src_loc);
}

void InterfaceOuter::DeleteSync(GLsync sync, SrcLoc src_loc){
    return _call<&InterfaceInner::DeleteSync>(sync, src_loc);
}

void InterfaceOuter::DeleteTextures(csr_GLsizei n, GLuintArr textures, SrcLoc src_loc){
    return _call<&InterfaceInner::DeleteTextures>(n, textures, src_loc);
}

void InterfaceOuter::DeleteTransformFeedbacks(csr_GLsizei n, GLuintArr ids, SrcLoc src_loc){
    return _call<&InterfaceInner::DeleteTransformFeedbacks>(n, ids, src_loc);
}

void InterfaceOuter::DeleteVertexArrays(csr_GLsizei n, GLuintArr arrays, SrcLoc src_loc){
    return _call<&InterfaceInner::DeleteVertexArrays>(n, arrays, src_loc);
}

void InterfaceOuter::DepthFunc(GLenum func, SrcLoc src_loc){
    return _call<&InterfaceInner::DepthFunc>(func, src_loc);
}

void InterfaceOuter::DepthMask(GLboolean flag, SrcLoc src_loc){
    return _call<&InterfaceInner::DepthMask>(flag, src_loc);
}

void InterfaceOuter::DepthRange(GLdouble n, GLdouble f, SrcLoc src_loc){
    return _call<&InterfaceInner::DepthRange>(n, f, src_loc);
}

void InterfaceOuter::DepthRangeArrayv(GLuint first, csr_GLsizei count, GLdoubleArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::DepthRangeArrayv>(first, count, v, src_loc);
}

void InterfaceOuter::DepthRangeIndexed(GLuint index, GLdouble n, GLdouble f, SrcLoc src_loc){
    return _call<&InterfaceInner::DepthRangeIndexed>(index, n, f, src_loc);
}

void InterfaceOuter::DepthRangef(GLfloat n, GLfloat f, SrcLoc src_loc){
    return _call<&InterfaceInner::DepthRangef>(n, f, src_loc);
}

void InterfaceOuter::DetachShader(GLuint program, GLuint shader, SrcLoc src_loc){
    return _call<&InterfaceInner::DetachShader>(program, shader, src_loc);
}

void InterfaceOuter::Disable(GLenum cap, SrcLoc src_loc){
    return _call<&InterfaceInner::Disable>(cap, src_loc);
}

void InterfaceOuter::DisableVertexArrayAttrib(GLuint vaobj, GLuint index, SrcLoc src_loc){
    return _call<&InterfaceInner::DisableVertexArrayAttrib>(vaobj, index, src_loc);
}

void InterfaceOuter::DisableVertexAttribArray(GLuint index, SrcLoc src_loc){
    return _call<&InterfaceInner::DisableVertexAttribArray>(index, src_loc);
}

void InterfaceOuter::Disablei(GLenum target, GLuint index, SrcLoc src_loc){
    return _call<&InterfaceInner::Disablei>(target, index, src_loc);
}

void InterfaceOuter::DispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, SrcLoc src_loc){
    return _call<&InterfaceInner::DispatchCompute>(num_groups_x, num_groups_y, num_groups_z, src_loc);
}

void InterfaceOuter::DispatchComputeIndirect(GLintptr indirect, SrcLoc src_loc){
    return _call<&InterfaceInner::DispatchComputeIndirect>(indirect, src_loc);
}

void InterfaceOuter::DrawArrays(GLenum mode, GLint first, csr_GLsizei count, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawArrays>(mode, first, count, src_loc);
}

void InterfaceOuter::DrawArraysIndirect(GLenum mode, GLdata indirect, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawArraysIndirect>(mode, indirect, src_loc);
}

void InterfaceOuter::DrawArraysInstanced(GLenum mode, GLint first, csr_GLsizei count, csr_GLsizei instancecount, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawArraysInstanced>(mode, first, count, instancecount, src_loc);
}

void InterfaceOuter::DrawArraysInstancedBaseInstance(GLenum mode, GLint first, csr_GLsizei count, csr_GLsizei instancecount, GLuint baseinstance, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawArraysInstancedBaseInstance>(mode, first, count, instancecount, baseinstance, src_loc);
}

void InterfaceOuter::DrawBuffer(GLenum buf, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawBuffer>(buf, src_loc);
}

void InterfaceOuter::DrawBuffers(csr_GLsizei n, GLenumArr bufs, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawBuffers>(n, bufs, src_loc);
}

void InterfaceOuter::DrawElements(GLenum mode, csr_GLsizei count, GLenum type, GLdata indices, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawElements>(mode, count, type, indices, src_loc);
}

void InterfaceOuter::DrawElementsBaseVertex(GLenum mode, csr_GLsizei count, GLenum type, GLdata indices, GLint basevertex, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawElementsBaseVertex>(mode, count, type, indices, basevertex, src_loc);
}

void InterfaceOuter::DrawElementsIndirect(GLenum mode, GLenum type, GLdata indirect, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawElementsIndirect>(mode, type, indirect, src_loc);
}

void InterfaceOuter::DrawElementsInstanced(GLenum mode, csr_GLsizei count, GLenum type, GLdata indices, csr_GLsizei instancecount, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawElementsInstanced>(mode, count, type, indices, instancecount, src_loc);
}

void InterfaceOuter::DrawElementsInstancedBaseInstance(GLenum mode, csr_GLsizei count, GLenum type, GLdata indices, csr_GLsizei instancecount, GLuint baseinstance, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawElementsInstancedBaseInstance>(mode, count, type, indices, instancecount, baseinstance, src_loc);
}

void InterfaceOuter::DrawElementsInstancedBaseVertex(GLenum mode, csr_GLsizei count, GLenum type, GLdata indices, csr_GLsizei instancecount, GLint basevertex, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawElementsInstancedBaseVertex>(mode, count, type, indices, instancecount, basevertex, src_loc);
}

void InterfaceOuter::DrawElementsInstancedBaseVertexBaseInstance(GLenum mode, csr_GLsizei count, GLenum type, GLdata indices, csr_GLsizei instancecount, GLint basevertex, GLuint baseinstance, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawElementsInstancedBaseVertexBaseInstance>(mode, count, type, indices, instancecount, basevertex, baseinstance, src_loc);
}

void InterfaceOuter::DrawRangeElements(GLenum mode, GLuint start, GLuint end, csr_GLsizei count, GLenum type, GLdata indices, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawRangeElements>(mode, start, end, count, type, indices, src_loc);
}

void InterfaceOuter::DrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, csr_GLsizei count, GLenum type, GLdata indices, GLint basevertex, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawRangeElementsBaseVertex>(mode, start, end, count, type, indices, basevertex, src_loc);
}

void InterfaceOuter::DrawTransformFeedback(GLenum mode, GLuint id, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawTransformFeedback>(mode, id, src_loc);
}

void InterfaceOuter::DrawTransformFeedbackInstanced(GLenum mode, GLuint id, csr_GLsizei instancecount, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawTransformFeedbackInstanced>(mode, id, instancecount, src_loc);
}

void InterfaceOuter::DrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawTransformFeedbackStream>(mode, id, stream, src_loc);
}

void InterfaceOuter::DrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, csr_GLsizei instancecount, SrcLoc src_loc){
    return _call<&InterfaceInner::DrawTransformFeedbackStreamInstanced>(mode, id, stream, instancecount, src_loc);
}

void InterfaceOuter::Enable(GLenum cap, SrcLoc src_loc){
    return _call<&InterfaceInner::Enable>(cap, src_loc);
}

void InterfaceOuter::EnableVertexArrayAttrib(GLuint vaobj, GLuint index, SrcLoc src_loc){
    return _call<&InterfaceInner::EnableVertexArrayAttrib>(vaobj, index, src_loc);
}

void InterfaceOuter::EnableVertexAttribArray(GLuint index, SrcLoc src_loc){
    return _call<&InterfaceInner::EnableVertexAttribArray>(index, src_loc);
}

void InterfaceOuter::Enablei(GLenum target, GLuint index, SrcLoc src_loc){
    return _call<&InterfaceInner::Enablei>(target, index, src_loc);
}

void InterfaceOuter::EndConditionalRender(SrcLoc src_loc){
    return _call<&InterfaceInner::EndConditionalRender>(src_loc);
}

void InterfaceOuter::EndQuery(GLenum target, SrcLoc src_loc){
    return _call<&InterfaceInner::EndQuery>(target, src_loc);
}

void InterfaceOuter::EndQueryIndexed(GLenum target, GLuint index, SrcLoc src_loc){
    return _call<&InterfaceInner::EndQueryIndexed>(target, index, src_loc);
}

void InterfaceOuter::EndTransformFeedback(SrcLoc src_loc){
    return _call<&InterfaceInner::EndTransformFeedback>(src_loc);
}

GLsyncRes InterfaceOuter::FenceSync(GLenum condition, GLbitfield flags, SrcLoc src_loc){
    return _call<&InterfaceInner::FenceSync>(condition, flags, src_loc);
}

void InterfaceOuter::Finish(SrcLoc src_loc){
    return _call<&InterfaceInner::Finish>(src_loc);
}

void InterfaceOuter::Flush(SrcLoc src_loc){
    return _call<&InterfaceInner::Flush>(src_loc);
}

void InterfaceOuter::FlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, SrcLoc src_loc){
    return _call<&InterfaceInner::FlushMappedBufferRange>(target, offset, length, src_loc);
}

void InterfaceOuter::FlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, SrcLoc src_loc){
    return _call<&InterfaceInner::FlushMappedNamedBufferRange>(buffer, offset, length, src_loc);
}

void InterfaceOuter::FramebufferParameteri(GLenum target, GLenum pname, GLint param, SrcLoc src_loc){
    return _call<&InterfaceInner::FramebufferParameteri>(target, pname, param, src_loc);
}

void InterfaceOuter::FramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer, SrcLoc src_loc){
    return _call<&InterfaceInner::FramebufferRenderbuffer>(target, attachment, renderbuffertarget, renderbuffer, src_loc);
}

void InterfaceOuter::FramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level, SrcLoc src_loc){
    return _call<&InterfaceInner::FramebufferTexture>(target, attachment, texture, level, src_loc);
}

void InterfaceOuter::FramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, SrcLoc src_loc){
    return _call<&InterfaceInner::FramebufferTexture1D>(target, attachment, textarget, texture, level, src_loc);
}

void InterfaceOuter::FramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, SrcLoc src_loc){
    return _call<&InterfaceInner::FramebufferTexture2D>(target, attachment, textarget, texture, level, src_loc);
}

void InterfaceOuter::FramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset, SrcLoc src_loc){
    return _call<&InterfaceInner::FramebufferTexture3D>(target, attachment, textarget, texture, level, zoffset, src_loc);
}

void InterfaceOuter::FramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer, SrcLoc src_loc){
    return _call<&InterfaceInner::FramebufferTextureLayer>(target, attachment, texture, level, layer, src_loc);
}

void InterfaceOuter::FrontFace(GLenum mode, SrcLoc src_loc){
    return _call<&InterfaceInner::FrontFace>(mode, src_loc);
}

void InterfaceOuter::GenBuffers(csr_GLsizei n, GLuintArr buffers, SrcLoc src_loc){
    return _call<&InterfaceInner::GenBuffers>(n, buffers, src_loc);
}

void InterfaceOuter::GenFramebuffers(csr_GLsizei n, GLuintArr framebuffers, SrcLoc src_loc){
    return _call<&InterfaceInner::GenFramebuffers>(n, framebuffers, src_loc);
}

void InterfaceOuter::GenProgramPipelines(csr_GLsizei n, GLuintArr pipelines, SrcLoc src_loc){
    return _call<&InterfaceInner::GenProgramPipelines>(n, pipelines, src_loc);
}

void InterfaceOuter::GenQueries(csr_GLsizei n, GLuintArr ids, SrcLoc src_loc){
    return _call<&InterfaceInner::GenQueries>(n, ids, src_loc);
}

void InterfaceOuter::GenRenderbuffers(csr_GLsizei n, GLuintArr renderbuffers, SrcLoc src_loc){
    return _call<&InterfaceInner::GenRenderbuffers>(n, renderbuffers, src_loc);
}

void InterfaceOuter::GenSamplers(csr_GLsizei count, GLuintArr samplers, SrcLoc src_loc){
    return _call<&InterfaceInner::GenSamplers>(count, samplers, src_loc);
}

void InterfaceOuter::GenTextures(csr_GLsizei n, GLuintArr textures, SrcLoc src_loc){
    return _call<&InterfaceInner::GenTextures>(n, textures, src_loc);
}

void InterfaceOuter::GenTransformFeedbacks(csr_GLsizei n, GLuintArr ids, SrcLoc src_loc){
    return _call<&InterfaceInner::GenTransformFeedbacks>(n, ids, src_loc);
}

void InterfaceOuter::GenVertexArrays(csr_GLsizei n, GLuintArr arrays, SrcLoc src_loc){
    return _call<&InterfaceInner::GenVertexArrays>(n, arrays, src_loc);
}

void InterfaceOuter::GenerateMipmap(GLenum target, SrcLoc src_loc){
    return _call<&InterfaceInner::GenerateMipmap>(target, src_loc);
}

void InterfaceOuter::GenerateTextureMipmap(GLuint texture, SrcLoc src_loc){
    return _call<&InterfaceInner::GenerateTextureMipmap>(texture, src_loc);
}

void InterfaceOuter::GetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetActiveAtomicCounterBufferiv>(program, bufferIndex, pname, params, src_loc);
}

void InterfaceOuter::GetActiveAttrib(GLuint program, GLuint index, csr_GLsizei bufSize, csr_GLsizei length, GLint size, GLenum type, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::GetActiveAttrib>(program, index, bufSize, length, size, type, name, src_loc);
}

void InterfaceOuter::GetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, csr_GLsizei bufSize, csr_GLsizei length, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::GetActiveSubroutineName>(program, shadertype, index, bufSize, length, name, src_loc);
}

void InterfaceOuter::GetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, csr_GLsizei bufSize, csr_GLsizei length, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::GetActiveSubroutineUniformName>(program, shadertype, index, bufSize, length, name, src_loc);
}

void InterfaceOuter::GetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLintArr values, SrcLoc src_loc){
    return _call<&InterfaceInner::GetActiveSubroutineUniformiv>(program, shadertype, index, pname, values, src_loc);
}

void InterfaceOuter::GetActiveUniform(GLuint program, GLuint index, csr_GLsizei bufSize, csr_GLsizei length, GLint size, GLenum type, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::GetActiveUniform>(program, index, bufSize, length, size, type, name, src_loc);
}

void InterfaceOuter::GetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, csr_GLsizei bufSize, csr_GLsizei length, GLcharArr uniformBlockName, SrcLoc src_loc){
    return _call<&InterfaceInner::GetActiveUniformBlockName>(program, uniformBlockIndex, bufSize, length, uniformBlockName, src_loc);
}

void InterfaceOuter::GetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetActiveUniformBlockiv>(program, uniformBlockIndex, pname, params, src_loc);
}

void InterfaceOuter::GetActiveUniformName(GLuint program, GLuint uniformIndex, csr_GLsizei bufSize, csr_GLsizei length, GLcharArr uniformName, SrcLoc src_loc){
    return _call<&InterfaceInner::GetActiveUniformName>(program, uniformIndex, bufSize, length, uniformName, src_loc);
}

void InterfaceOuter::GetActiveUniformsiv(GLuint program, csr_GLsizei uniformCount, GLuintArr uniformIndices, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetActiveUniformsiv>(program, uniformCount, uniformIndices, pname, params, src_loc);
}

void InterfaceOuter::GetAttachedShaders(GLuint program, csr_GLsizei maxCount, csra_GLsizeiArr count, GLuintArr shaders, SrcLoc src_loc){
    return _call<&InterfaceInner::GetAttachedShaders>(program, maxCount, count, shaders, src_loc);
}

GLintRes InterfaceOuter::GetAttribLocation(GLuint program, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::GetAttribLocation>(program, name, src_loc);
}

void InterfaceOuter::GetBooleani_v(GLenum target, GLuint index, GLbooleanArr data, SrcLoc src_loc){
    return _call<&InterfaceInner::GetBooleani_v>(target, index, data, src_loc);
}

void InterfaceOuter::GetBooleanv(GLenum pname, GLbooleanArr data, SrcLoc src_loc){
    return _call<&InterfaceInner::GetBooleanv>(pname, data, src_loc);
}

void InterfaceOuter::GetBufferParameteri64v(GLenum target, GLenum pname, GLint64Arr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetBufferParameteri64v>(target, pname, params, src_loc);
}

void InterfaceOuter::GetBufferParameteriv(GLenum target, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetBufferParameteriv>(target, pname, params, src_loc);
}

void InterfaceOuter::GetBufferPointerv(GLenum target, GLenum pname, GLdataPtr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetBufferPointerv>(target, pname, params, src_loc);
}

void InterfaceOuter::GetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::GetBufferSubData>(target, offset, size, data, src_loc);
}

void InterfaceOuter::GetCompressedTexImage(GLenum target, GLint level, GLdata img, SrcLoc src_loc){
    return _call<&InterfaceInner::GetCompressedTexImage>(target, level, img, src_loc);
}

void InterfaceOuter::GetCompressedTextureImage(GLuint texture, GLint level, csr_GLsizei bufSize, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::GetCompressedTextureImage>(texture, level, bufSize, pixels, src_loc);
}

void InterfaceOuter::GetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, csr_GLsizei width, csr_GLsizei height, csr_GLsizei depth, csr_GLsizei bufSize, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::GetCompressedTextureSubImage>(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels, src_loc);
}

GLuintRes InterfaceOuter::GetDebugMessageLog(GLuint count, csr_GLsizei bufSize, GLenumArr sources, GLenumArr types, GLuintArr ids, GLenumArr severities, csr_GLsizei lengths, GLcharArr messageLog, SrcLoc src_loc){
    return _call<&InterfaceInner::GetDebugMessageLog>(count, bufSize, sources, types, ids, severities, lengths, messageLog, src_loc);
}

void InterfaceOuter::GetDoublei_v(GLenum target, GLuint index, GLdoubleArr data, SrcLoc src_loc){
    return _call<&InterfaceInner::GetDoublei_v>(target, index, data, src_loc);
}

void InterfaceOuter::GetDoublev(GLenum pname, GLdoubleArr data, SrcLoc src_loc){
    return _call<&InterfaceInner::GetDoublev>(pname, data, src_loc);
}

GLenumRes InterfaceOuter::GetError(SrcLoc src_loc){
    return _call<&InterfaceInner::GetError>(src_loc);
}

void InterfaceOuter::GetFloati_v(GLenum target, GLuint index, GLfloatArr data, SrcLoc src_loc){
    return _call<&InterfaceInner::GetFloati_v>(target, index, data, src_loc);
}

void InterfaceOuter::GetFloatv(GLenum pname, GLfloatArr data, SrcLoc src_loc){
    return _call<&InterfaceInner::GetFloatv>(pname, data, src_loc);
}

GLintRes InterfaceOuter::GetFragDataIndex(GLuint program, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::GetFragDataIndex>(program, name, src_loc);
}

GLintRes InterfaceOuter::GetFragDataLocation(GLuint program, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::GetFragDataLocation>(program, name, src_loc);
}

void InterfaceOuter::GetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetFramebufferAttachmentParameteriv>(target, attachment, pname, params, src_loc);
}

void InterfaceOuter::GetFramebufferParameteriv(GLenum target, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetFramebufferParameteriv>(target, pname, params, src_loc);
}

GLenumRes InterfaceOuter::GetGraphicsResetStatus(SrcLoc src_loc){
    return _call<&InterfaceInner::GetGraphicsResetStatus>(src_loc);
}

void InterfaceOuter::GetInteger64i_v(GLenum target, GLuint index, GLint64Arr data, SrcLoc src_loc){
    return _call<&InterfaceInner::GetInteger64i_v>(target, index, data, src_loc);
}

void InterfaceOuter::GetInteger64v(GLenum pname, GLint64Arr data, SrcLoc src_loc){
    return _call<&InterfaceInner::GetInteger64v>(pname, data, src_loc);
}

void InterfaceOuter::GetIntegeri_v(GLenum target, GLuint index, GLintArr data, SrcLoc src_loc){
    return _call<&InterfaceInner::GetIntegeri_v>(target, index, data, src_loc);
}

void InterfaceOuter::GetIntegerv(GLenum pname, GLintArr data, SrcLoc src_loc){
    return _call<&InterfaceInner::GetIntegerv>(pname, data, src_loc);
}

void InterfaceOuter::GetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, csr_GLsizei count, GLint64Arr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetInternalformati64v>(target, internalformat, pname, count, params, src_loc);
}

void InterfaceOuter::GetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, csr_GLsizei count, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetInternalformativ>(target, internalformat, pname, count, params, src_loc);
}

void InterfaceOuter::GetMultisamplefv(GLenum pname, GLuint index, GLfloatArr val, SrcLoc src_loc){
    return _call<&InterfaceInner::GetMultisamplefv>(pname, index, val, src_loc);
}

void InterfaceOuter::GetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64Arr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetNamedBufferParameteri64v>(buffer, pname, params, src_loc);
}

void InterfaceOuter::GetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetNamedBufferParameteriv>(buffer, pname, params, src_loc);
}

void InterfaceOuter::GetNamedBufferPointerv(GLuint buffer, GLenum pname, GLdataPtr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetNamedBufferPointerv>(buffer, pname, params, src_loc);
}

void InterfaceOuter::GetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::GetNamedBufferSubData>(buffer, offset, size, data, src_loc);
}

void InterfaceOuter::GetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetNamedFramebufferAttachmentParameteriv>(framebuffer, attachment, pname, params, src_loc);
}

void InterfaceOuter::GetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLintArr param, SrcLoc src_loc){
    return _call<&InterfaceInner::GetNamedFramebufferParameteriv>(framebuffer, pname, param, src_loc);
}

void InterfaceOuter::GetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetNamedRenderbufferParameteriv>(renderbuffer, pname, params, src_loc);
}

void InterfaceOuter::GetObjectLabel(GLenum identifier, GLuint name, csr_GLsizei bufSize, csr_GLsizei length, GLcharArr label, SrcLoc src_loc){
    return _call<&InterfaceInner::GetObjectLabel>(identifier, name, bufSize, length, label, src_loc);
}

void InterfaceOuter::GetObjectPtrLabel(GLdata ptr, csr_GLsizei bufSize, csr_GLsizei length, GLcharArr label, SrcLoc src_loc){
    return _call<&InterfaceInner::GetObjectPtrLabel>(ptr, bufSize, length, label, src_loc);
}

void InterfaceOuter::GetPointerv(GLenum pname, GLdataPtr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetPointerv>(pname, params, src_loc);
}

void InterfaceOuter::GetProgramBinary(GLuint program, csr_GLsizei bufSize, csr_GLsizei length, GLenumArr binaryFormat, GLdata binary, SrcLoc src_loc){
    return _call<&InterfaceInner::GetProgramBinary>(program, bufSize, length, binaryFormat, binary, src_loc);
}

void InterfaceOuter::GetProgramInfoLog(GLuint program, csr_GLsizei bufSize, csr_GLsizei length, GLcharArr infoLog, SrcLoc src_loc){
    return _call<&InterfaceInner::GetProgramInfoLog>(program, bufSize, length, infoLog, src_loc);
}

void InterfaceOuter::GetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetProgramInterfaceiv>(program, programInterface, pname, params, src_loc);
}

void InterfaceOuter::GetProgramPipelineInfoLog(GLuint pipeline, csr_GLsizei bufSize, csr_GLsizei length, GLcharArr infoLog, SrcLoc src_loc){
    return _call<&InterfaceInner::GetProgramPipelineInfoLog>(pipeline, bufSize, length, infoLog, src_loc);
}

void InterfaceOuter::GetProgramPipelineiv(GLuint pipeline, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetProgramPipelineiv>(pipeline, pname, params, src_loc);
}

GLuintRes InterfaceOuter::GetProgramResourceIndex(GLuint program, GLenum programInterface, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::GetProgramResourceIndex>(program, programInterface, name, src_loc);
}

GLintRes InterfaceOuter::GetProgramResourceLocation(GLuint program, GLenum programInterface, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::GetProgramResourceLocation>(program, programInterface, name, src_loc);
}

GLintRes InterfaceOuter::GetProgramResourceLocationIndex(GLuint program, GLenum programInterface, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::GetProgramResourceLocationIndex>(program, programInterface, name, src_loc);
}

void InterfaceOuter::GetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, csr_GLsizei bufSize, csr_GLsizei length, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::GetProgramResourceName>(program, programInterface, index, bufSize, length, name, src_loc);
}

void InterfaceOuter::GetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, csr_GLsizei propCount, GLenumArr props, csr_GLsizei count, csr_GLsizei length, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetProgramResourceiv>(program, programInterface, index, propCount, props, count, length, params, src_loc);
}

void InterfaceOuter::GetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLintArr values, SrcLoc src_loc){
    return _call<&InterfaceInner::GetProgramStageiv>(program, shadertype, pname, values, src_loc);
}

void InterfaceOuter::GetProgramiv(GLuint program, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetProgramiv>(program, pname, params, src_loc);
}

void InterfaceOuter::GetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, SrcLoc src_loc){
    return _call<&InterfaceInner::GetQueryBufferObjecti64v>(id, buffer, pname, offset, src_loc);
}

void InterfaceOuter::GetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, SrcLoc src_loc){
    return _call<&InterfaceInner::GetQueryBufferObjectiv>(id, buffer, pname, offset, src_loc);
}

void InterfaceOuter::GetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, SrcLoc src_loc){
    return _call<&InterfaceInner::GetQueryBufferObjectui64v>(id, buffer, pname, offset, src_loc);
}

void InterfaceOuter::GetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, SrcLoc src_loc){
    return _call<&InterfaceInner::GetQueryBufferObjectuiv>(id, buffer, pname, offset, src_loc);
}

void InterfaceOuter::GetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetQueryIndexediv>(target, index, pname, params, src_loc);
}

void InterfaceOuter::GetQueryObjecti64v(GLuint id, GLenum pname, GLint64Arr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetQueryObjecti64v>(id, pname, params, src_loc);
}

void InterfaceOuter::GetQueryObjectiv(GLuint id, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetQueryObjectiv>(id, pname, params, src_loc);
}

void InterfaceOuter::GetQueryObjectui64v(GLuint id, GLenum pname, GLuint64Arr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetQueryObjectui64v>(id, pname, params, src_loc);
}

void InterfaceOuter::GetQueryObjectuiv(GLuint id, GLenum pname, GLuintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetQueryObjectuiv>(id, pname, params, src_loc);
}

void InterfaceOuter::GetQueryiv(GLenum target, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetQueryiv>(target, pname, params, src_loc);
}

void InterfaceOuter::GetRenderbufferParameteriv(GLenum target, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetRenderbufferParameteriv>(target, pname, params, src_loc);
}

void InterfaceOuter::GetSamplerParameterIiv(GLuint sampler, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetSamplerParameterIiv>(sampler, pname, params, src_loc);
}

void InterfaceOuter::GetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetSamplerParameterIuiv>(sampler, pname, params, src_loc);
}

void InterfaceOuter::GetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloatArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetSamplerParameterfv>(sampler, pname, params, src_loc);
}

void InterfaceOuter::GetSamplerParameteriv(GLuint sampler, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetSamplerParameteriv>(sampler, pname, params, src_loc);
}

void InterfaceOuter::GetShaderInfoLog(GLuint shader, csr_GLsizei bufSize, csr_GLsizei length, GLcharArr infoLog, SrcLoc src_loc){
    return _call<&InterfaceInner::GetShaderInfoLog>(shader, bufSize, length, infoLog, src_loc);
}

void InterfaceOuter::GetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLintArr range, GLintArr precision, SrcLoc src_loc){
    return _call<&InterfaceInner::GetShaderPrecisionFormat>(shadertype, precisiontype, range, precision, src_loc);
}

void InterfaceOuter::GetShaderSource(GLuint shader, csr_GLsizei bufSize, csr_GLsizei length, GLcharArr source, SrcLoc src_loc){
    return _call<&InterfaceInner::GetShaderSource>(shader, bufSize, length, source, src_loc);
}

void InterfaceOuter::GetShaderiv(GLuint shader, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetShaderiv>(shader, pname, params, src_loc);
}

GLubyteArrRes InterfaceOuter::GetString(GLenum name, SrcLoc src_loc){
    // return _call<&InterfaceGlInner::GetString>(name, src_loc);
}

GLubyteArrRes InterfaceOuter::GetStringi(GLenum name, GLuint index, SrcLoc src_loc){
    // return _call<&InterfaceGlInner::GetStringi>(name, index, src_loc);
}

GLuintRes InterfaceOuter::GetSubroutineIndex(GLuint program, GLenum shadertype, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::GetSubroutineIndex>(program, shadertype, name, src_loc);
}

GLintRes InterfaceOuter::GetSubroutineUniformLocation(GLuint program, GLenum shadertype, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::GetSubroutineUniformLocation>(program, shadertype, name, src_loc);
}

void InterfaceOuter::GetSynciv(GLsync sync, GLenum pname, csr_GLsizei count, csr_GLsizei length, GLintArr values, SrcLoc src_loc){
    return _call<&InterfaceInner::GetSynciv>(sync, pname, count, length, values, src_loc);
}

void InterfaceOuter::GetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTexImage>(target, level, format, type, pixels, src_loc);
}

void InterfaceOuter::GetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloatArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTexLevelParameterfv>(target, level, pname, params, src_loc);
}

void InterfaceOuter::GetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTexLevelParameteriv>(target, level, pname, params, src_loc);
}

void InterfaceOuter::GetTexParameterIiv(GLenum target, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTexParameterIiv>(target, pname, params, src_loc);
}

void InterfaceOuter::GetTexParameterIuiv(GLenum target, GLenum pname, GLuintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTexParameterIuiv>(target, pname, params, src_loc);
}

void InterfaceOuter::GetTexParameterfv(GLenum target, GLenum pname, GLfloatArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTexParameterfv>(target, pname, params, src_loc);
}

void InterfaceOuter::GetTexParameteriv(GLenum target, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTexParameteriv>(target, pname, params, src_loc);
}

void InterfaceOuter::GetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, csr_GLsizei bufSize, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTextureImage>(texture, level, format, type, bufSize, pixels, src_loc);
}

void InterfaceOuter::GetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloatArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTextureLevelParameterfv>(texture, level, pname, params, src_loc);
}

void InterfaceOuter::GetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTextureLevelParameteriv>(texture, level, pname, params, src_loc);
}

void InterfaceOuter::GetTextureParameterIiv(GLuint texture, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTextureParameterIiv>(texture, pname, params, src_loc);
}

void InterfaceOuter::GetTextureParameterIuiv(GLuint texture, GLenum pname, GLuintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTextureParameterIuiv>(texture, pname, params, src_loc);
}

void InterfaceOuter::GetTextureParameterfv(GLuint texture, GLenum pname, GLfloatArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTextureParameterfv>(texture, pname, params, src_loc);
}

void InterfaceOuter::GetTextureParameteriv(GLuint texture, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTextureParameteriv>(texture, pname, params, src_loc);
}

void InterfaceOuter::GetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, csr_GLsizei width, csr_GLsizei height, csr_GLsizei depth, GLenum format, GLenum type, csr_GLsizei bufSize, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTextureSubImage>(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels, src_loc);
}

void InterfaceOuter::GetTransformFeedbackVarying(GLuint program, GLuint index, csr_GLsizei bufSize, csr_GLsizei length, csra_GLsizeiArr size, GLenumArr type, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTransformFeedbackVarying>(program, index, bufSize, length, size, type, name, src_loc);
}

void InterfaceOuter::GetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64Arr param, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTransformFeedbacki64_v>(xfb, pname, index, param, src_loc);
}

void InterfaceOuter::GetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLintArr param, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTransformFeedbacki_v>(xfb, pname, index, param, src_loc);
}

void InterfaceOuter::GetTransformFeedbackiv(GLuint xfb, GLenum pname, GLintArr param, SrcLoc src_loc){
    return _call<&InterfaceInner::GetTransformFeedbackiv>(xfb, pname, param, src_loc);
}

GLuintRes InterfaceOuter::GetUniformBlockIndex(GLuint program, GLcharArr uniformBlockName, SrcLoc src_loc){
    return _call<&InterfaceInner::GetUniformBlockIndex>(program, uniformBlockName, src_loc);
}

GLintRes InterfaceOuter::GetUniformLocation(GLuint program, GLcharArr name, SrcLoc src_loc){
    return _call<&InterfaceInner::GetUniformLocation>(program, name, src_loc);
}

void InterfaceOuter::GetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetUniformSubroutineuiv>(shadertype, location, params, src_loc);
}

void InterfaceOuter::GetUniformdv(GLuint program, GLint location, GLdoubleArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetUniformdv>(program, location, params, src_loc);
}

void InterfaceOuter::GetUniformfv(GLuint program, GLint location, GLfloatArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetUniformfv>(program, location, params, src_loc);
}

void InterfaceOuter::GetUniformiv(GLuint program, GLint location, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetUniformiv>(program, location, params, src_loc);
}

void InterfaceOuter::GetUniformuiv(GLuint program, GLint location, GLuintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetUniformuiv>(program, location, params, src_loc);
}

void InterfaceOuter::GetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64Arr param, SrcLoc src_loc){
    return _call<&InterfaceInner::GetVertexArrayIndexed64iv>(vaobj, index, pname, param, src_loc);
}

void InterfaceOuter::GetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLintArr param, SrcLoc src_loc){
    return _call<&InterfaceInner::GetVertexArrayIndexediv>(vaobj, index, pname, param, src_loc);
}

void InterfaceOuter::GetVertexArrayiv(GLuint vaobj, GLenum pname, GLintArr param, SrcLoc src_loc){
    return _call<&InterfaceInner::GetVertexArrayiv>(vaobj, pname, param, src_loc);
}

void InterfaceOuter::GetVertexAttribIiv(GLuint index, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetVertexAttribIiv>(index, pname, params, src_loc);
}

void InterfaceOuter::GetVertexAttribIuiv(GLuint index, GLenum pname, GLuintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetVertexAttribIuiv>(index, pname, params, src_loc);
}

void InterfaceOuter::GetVertexAttribLdv(GLuint index, GLenum pname, GLdoubleArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetVertexAttribLdv>(index, pname, params, src_loc);
}

void InterfaceOuter::GetVertexAttribPointerv(GLuint index, GLenum pname, GLdataPtr pointer, SrcLoc src_loc){
    return _call<&InterfaceInner::GetVertexAttribPointerv>(index, pname, pointer, src_loc);
}

void InterfaceOuter::GetVertexAttribdv(GLuint index, GLenum pname, GLdoubleArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetVertexAttribdv>(index, pname, params, src_loc);
}

void InterfaceOuter::GetVertexAttribfv(GLuint index, GLenum pname, GLfloatArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetVertexAttribfv>(index, pname, params, src_loc);
}

void InterfaceOuter::GetVertexAttribiv(GLuint index, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetVertexAttribiv>(index, pname, params, src_loc);
}

void InterfaceOuter::GetnCompressedTexImage(GLenum target, GLint lod, csr_GLsizei bufSize, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::GetnCompressedTexImage>(target, lod, bufSize, pixels, src_loc);
}

void InterfaceOuter::GetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, csr_GLsizei bufSize, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::GetnTexImage>(target, level, format, type, bufSize, pixels, src_loc);
}

void InterfaceOuter::GetnUniformdv(GLuint program, GLint location, csr_GLsizei bufSize, GLdoubleArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetnUniformdv>(program, location, bufSize, params, src_loc);
}

void InterfaceOuter::GetnUniformfv(GLuint program, GLint location, csr_GLsizei bufSize, GLfloatArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetnUniformfv>(program, location, bufSize, params, src_loc);
}

void InterfaceOuter::GetnUniformiv(GLuint program, GLint location, csr_GLsizei bufSize, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetnUniformiv>(program, location, bufSize, params, src_loc);
}

void InterfaceOuter::GetnUniformuiv(GLuint program, GLint location, csr_GLsizei bufSize, GLuintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::GetnUniformuiv>(program, location, bufSize, params, src_loc);
}

void InterfaceOuter::Hint(GLenum target, GLenum mode, SrcLoc src_loc){
    return _call<&InterfaceInner::Hint>(target, mode, src_loc);
}

void InterfaceOuter::InvalidateBufferData(GLuint buffer, SrcLoc src_loc){
    return _call<&InterfaceInner::InvalidateBufferData>(buffer, src_loc);
}

void InterfaceOuter::InvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length, SrcLoc src_loc){
    return _call<&InterfaceInner::InvalidateBufferSubData>(buffer, offset, length, src_loc);
}

void InterfaceOuter::InvalidateFramebuffer(GLenum target, csr_GLsizei numAttachments, GLenumArr attachments, SrcLoc src_loc){
    return _call<&InterfaceInner::InvalidateFramebuffer>(target, numAttachments, attachments, src_loc);
}

void InterfaceOuter::InvalidateNamedFramebufferData(GLuint framebuffer, csr_GLsizei numAttachments, GLenumArr attachments, SrcLoc src_loc){
    return _call<&InterfaceInner::InvalidateNamedFramebufferData>(framebuffer, numAttachments, attachments, src_loc);
}

void InterfaceOuter::InvalidateNamedFramebufferSubData(GLuint framebuffer, csr_GLsizei numAttachments, GLenumArr attachments, GLint x, GLint y, csr_GLsizei width, csr_GLsizei height, SrcLoc src_loc){
    return _call<&InterfaceInner::InvalidateNamedFramebufferSubData>(framebuffer, numAttachments, attachments, x, y, width, height, src_loc);
}

void InterfaceOuter::InvalidateSubFramebuffer(GLenum target, csr_GLsizei numAttachments, GLenumArr attachments, GLint x, GLint y, csr_GLsizei width, csr_GLsizei height, SrcLoc src_loc){
    return _call<&InterfaceInner::InvalidateSubFramebuffer>(target, numAttachments, attachments, x, y, width, height, src_loc);
}

void InterfaceOuter::InvalidateTexImage(GLuint texture, GLint level, SrcLoc src_loc){
    return _call<&InterfaceInner::InvalidateTexImage>(texture, level, src_loc);
}

void InterfaceOuter::InvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, csr_GLsizei width, csr_GLsizei height, csr_GLsizei depth, SrcLoc src_loc){
    return _call<&InterfaceInner::InvalidateTexSubImage>(texture, level, xoffset, yoffset, zoffset, width, height, depth, src_loc);
}

GLbooleanRes InterfaceOuter::IsBuffer(GLuint buffer, SrcLoc src_loc){
    return _call<&InterfaceInner::IsBuffer>(buffer, src_loc);
}

GLbooleanRes InterfaceOuter::IsEnabled(GLenum cap, SrcLoc src_loc){
    return _call<&InterfaceInner::IsEnabled>(cap, src_loc);
}

GLbooleanRes InterfaceOuter::IsEnabledi(GLenum target, GLuint index, SrcLoc src_loc){
    return _call<&InterfaceInner::IsEnabledi>(target, index, src_loc);
}

GLbooleanRes InterfaceOuter::IsFramebuffer(GLuint framebuffer, SrcLoc src_loc){
    return _call<&InterfaceInner::IsFramebuffer>(framebuffer, src_loc);
}

GLbooleanRes InterfaceOuter::IsProgram(GLuint program, SrcLoc src_loc){
    return _call<&InterfaceInner::IsProgram>(program, src_loc);
}

GLbooleanRes InterfaceOuter::IsProgramPipeline(GLuint pipeline, SrcLoc src_loc){
    return _call<&InterfaceInner::IsProgramPipeline>(pipeline, src_loc);
}

GLbooleanRes InterfaceOuter::IsQuery(GLuint id, SrcLoc src_loc){
    return _call<&InterfaceInner::IsQuery>(id, src_loc);
}

GLbooleanRes InterfaceOuter::IsRenderbuffer(GLuint renderbuffer, SrcLoc src_loc){
    return _call<&InterfaceInner::IsRenderbuffer>(renderbuffer, src_loc);
}

GLbooleanRes InterfaceOuter::IsSampler(GLuint sampler, SrcLoc src_loc){
    return _call<&InterfaceInner::IsSampler>(sampler, src_loc);
}

GLbooleanRes InterfaceOuter::IsShader(GLuint shader, SrcLoc src_loc){
    return _call<&InterfaceInner::IsShader>(shader, src_loc);
}

GLbooleanRes InterfaceOuter::IsSync(GLsync sync, SrcLoc src_loc){
    return _call<&InterfaceInner::IsSync>(sync, src_loc);
}

GLbooleanRes InterfaceOuter::IsTexture(GLuint texture, SrcLoc src_loc){
    return _call<&InterfaceInner::IsTexture>(texture, src_loc);
}

GLbooleanRes InterfaceOuter::IsTransformFeedback(GLuint id, SrcLoc src_loc){
    return _call<&InterfaceInner::IsTransformFeedback>(id, src_loc);
}

GLbooleanRes InterfaceOuter::IsVertexArray(GLuint array, SrcLoc src_loc){
    return _call<&InterfaceInner::IsVertexArray>(array, src_loc);
}

void InterfaceOuter::LineWidth(GLfloat width, SrcLoc src_loc){
    return _call<&InterfaceInner::LineWidth>(width, src_loc);
}

void InterfaceOuter::LinkProgram(GLuint program, SrcLoc src_loc){
    return _call<&InterfaceInner::LinkProgram>(program, src_loc);
}

void InterfaceOuter::LogicOp(GLenum opcode, SrcLoc src_loc){
    return _call<&InterfaceInner::LogicOp>(opcode, src_loc);
}

void InterfaceOuter::MemoryBarrier(GLbitfield barriers, SrcLoc src_loc){
    return _call<&InterfaceInner::MemoryBarrier>(barriers, src_loc);
}

void InterfaceOuter::MemoryBarrierByRegion(GLbitfield barriers, SrcLoc src_loc){
    return _call<&InterfaceInner::MemoryBarrierByRegion>(barriers, src_loc);
}

void InterfaceOuter::MinSampleShading(GLfloat value, SrcLoc src_loc){
    return _call<&InterfaceInner::MinSampleShading>(value, src_loc);
}

void InterfaceOuter::MultiDrawArrays(GLenum mode, GLintArr first, csra_GLsizeiArr count, csr_GLsizei drawcount, SrcLoc src_loc){
    return _call<&InterfaceInner::MultiDrawArrays>(mode, first, count, drawcount, src_loc);
}

void InterfaceOuter::MultiDrawArraysIndirect(GLenum mode, GLdata indirect, csr_GLsizei drawcount, csr_GLsizei stride, SrcLoc src_loc){
    return _call<&InterfaceInner::MultiDrawArraysIndirect>(mode, indirect, drawcount, stride, src_loc);
}

void InterfaceOuter::MultiDrawArraysIndirectCount(GLenum mode, GLdata indirect, GLintptr drawcount, csr_GLsizei maxdrawcount, csr_GLsizei stride, SrcLoc src_loc){
    return _call<&InterfaceInner::MultiDrawArraysIndirectCount>(mode, indirect, drawcount, maxdrawcount, stride, src_loc);
}

void InterfaceOuter::MultiDrawElements(GLenum mode, csra_GLsizeiArr count, GLenum type, GLdataPtr indices, csr_GLsizei drawcount, SrcLoc src_loc){
    return _call<&InterfaceInner::MultiDrawElements>(mode, count, type, indices, drawcount, src_loc);
}

void InterfaceOuter::MultiDrawElementsBaseVertex(GLenum mode, csra_GLsizeiArr count, GLenum type, GLdataPtr indices, csr_GLsizei drawcount, GLintArr basevertex, SrcLoc src_loc){
    return _call<&InterfaceInner::MultiDrawElementsBaseVertex>(mode, count, type, indices, drawcount, basevertex, src_loc);
}

void InterfaceOuter::MultiDrawElementsIndirect(GLenum mode, GLenum type, GLdata indirect, csr_GLsizei drawcount, csr_GLsizei stride, SrcLoc src_loc){
    return _call<&InterfaceInner::MultiDrawElementsIndirect>(mode, type, indirect, drawcount, stride, src_loc);
}

void InterfaceOuter::MultiDrawElementsIndirectCount(GLenum mode, GLenum type, GLdata indirect, GLintptr drawcount, csr_GLsizei maxdrawcount, csr_GLsizei stride, SrcLoc src_loc){
    return _call<&InterfaceInner::MultiDrawElementsIndirectCount>(mode, type, indirect, drawcount, maxdrawcount, stride, src_loc);
}

void InterfaceOuter::NamedBufferData(GLuint buffer, GLsizeiptr size, GLdata data, GLenum usage, SrcLoc src_loc){
    return _call<&InterfaceInner::NamedBufferData>(buffer, size, data, usage, src_loc);
}

void InterfaceOuter::NamedBufferStorage(GLuint buffer, GLsizeiptr size, GLdata data, GLbitfield flags, SrcLoc src_loc){
    return _call<&InterfaceInner::NamedBufferStorage>(buffer, size, data, flags, src_loc);
}

void InterfaceOuter::NamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::NamedBufferSubData>(buffer, offset, size, data, src_loc);
}

void InterfaceOuter::NamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf, SrcLoc src_loc){
    return _call<&InterfaceInner::NamedFramebufferDrawBuffer>(framebuffer, buf, src_loc);
}

void InterfaceOuter::NamedFramebufferDrawBuffers(GLuint framebuffer, csr_GLsizei n, GLenumArr bufs, SrcLoc src_loc){
    return _call<&InterfaceInner::NamedFramebufferDrawBuffers>(framebuffer, n, bufs, src_loc);
}

void InterfaceOuter::NamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param, SrcLoc src_loc){
    return _call<&InterfaceInner::NamedFramebufferParameteri>(framebuffer, pname, param, src_loc);
}

void InterfaceOuter::NamedFramebufferReadBuffer(GLuint framebuffer, GLenum src, SrcLoc src_loc){
    return _call<&InterfaceInner::NamedFramebufferReadBuffer>(framebuffer, src, src_loc);
}

void InterfaceOuter::NamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer, SrcLoc src_loc){
    return _call<&InterfaceInner::NamedFramebufferRenderbuffer>(framebuffer, attachment, renderbuffertarget, renderbuffer, src_loc);
}

void InterfaceOuter::NamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, SrcLoc src_loc){
    return _call<&InterfaceInner::NamedFramebufferTexture>(framebuffer, attachment, texture, level, src_loc);
}

void InterfaceOuter::NamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer, SrcLoc src_loc){
    return _call<&InterfaceInner::NamedFramebufferTextureLayer>(framebuffer, attachment, texture, level, layer, src_loc);
}

void InterfaceOuter::NamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, csr_GLsizei width, csr_GLsizei height, SrcLoc src_loc){
    return _call<&InterfaceInner::NamedRenderbufferStorage>(renderbuffer, internalformat, width, height, src_loc);
}

void InterfaceOuter::NamedRenderbufferStorageMultisample(GLuint renderbuffer, csr_GLsizei samples, GLenum internalformat, csr_GLsizei width, csr_GLsizei height, SrcLoc src_loc){
    return _call<&InterfaceInner::NamedRenderbufferStorageMultisample>(renderbuffer, samples, internalformat, width, height, src_loc);
}

void InterfaceOuter::ObjectLabel(GLenum identifier, GLuint name, csr_GLsizei length, GLcharArr label, SrcLoc src_loc){
    return _call<&InterfaceInner::ObjectLabel>(identifier, name, length, label, src_loc);
}

void InterfaceOuter::ObjectPtrLabel(GLdata ptr, csr_GLsizei length, GLcharArr label, SrcLoc src_loc){
    return _call<&InterfaceInner::ObjectPtrLabel>(ptr, length, label, src_loc);
}

void InterfaceOuter::PatchParameterfv(GLenum pname, GLfloatArr values, SrcLoc src_loc){
    return _call<&InterfaceInner::PatchParameterfv>(pname, values, src_loc);
}

void InterfaceOuter::PatchParameteri(GLenum pname, GLint value, SrcLoc src_loc){
    return _call<&InterfaceInner::PatchParameteri>(pname, value, src_loc);
}

void InterfaceOuter::PauseTransformFeedback(SrcLoc src_loc){
    return _call<&InterfaceInner::PauseTransformFeedback>(src_loc);
}

void InterfaceOuter::PixelStoref(GLenum pname, GLfloat param, SrcLoc src_loc){
    return _call<&InterfaceInner::PixelStoref>(pname, param, src_loc);
}

void InterfaceOuter::PixelStorei(GLenum pname, GLint param, SrcLoc src_loc){
    return _call<&InterfaceInner::PixelStorei>(pname, param, src_loc);
}

void InterfaceOuter::PointParameterf(GLenum pname, GLfloat param, SrcLoc src_loc){
    return _call<&InterfaceInner::PointParameterf>(pname, param, src_loc);
}

void InterfaceOuter::PointParameterfv(GLenum pname, GLfloatArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::PointParameterfv>(pname, params, src_loc);
}

void InterfaceOuter::PointParameteri(GLenum pname, GLint param, SrcLoc src_loc){
    return _call<&InterfaceInner::PointParameteri>(pname, param, src_loc);
}

void InterfaceOuter::PointParameteriv(GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::PointParameteriv>(pname, params, src_loc);
}

void InterfaceOuter::PointSize(GLfloat size, SrcLoc src_loc){
    return _call<&InterfaceInner::PointSize>(size, src_loc);
}

void InterfaceOuter::PolygonMode(GLenum face, GLenum mode, SrcLoc src_loc){
    return _call<&InterfaceInner::PolygonMode>(face, mode, src_loc);
}

void InterfaceOuter::PolygonOffset(GLfloat factor, GLfloat units, SrcLoc src_loc){
    return _call<&InterfaceInner::PolygonOffset>(factor, units, src_loc);
}

void InterfaceOuter::PolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp, SrcLoc src_loc){
    return _call<&InterfaceInner::PolygonOffsetClamp>(factor, units, clamp, src_loc);
}

void InterfaceOuter::PopDebugGroup(SrcLoc src_loc){
    return _call<&InterfaceInner::PopDebugGroup>(src_loc);
}

void InterfaceOuter::PrimitiveRestartIndex(GLuint index, SrcLoc src_loc){
    return _call<&InterfaceInner::PrimitiveRestartIndex>(index, src_loc);
}

void InterfaceOuter::ProgramBinary(GLuint program, GLenum binaryFormat, GLdata binary, csr_GLsizei length, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramBinary>(program, binaryFormat, binary, length, src_loc);
}

void InterfaceOuter::ProgramParameteri(GLuint program, GLenum pname, GLint value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramParameteri>(program, pname, value, src_loc);
}

void InterfaceOuter::ProgramUniform1d(GLuint program, GLint location, GLdouble v0, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform1d>(program, location, v0, src_loc);
}

void InterfaceOuter::ProgramUniform1dv(GLuint program, GLint location, csr_GLsizei count, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform1dv>(program, location, count, value, src_loc);
}

void InterfaceOuter::ProgramUniform1f(GLuint program, GLint location, GLfloat v0, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform1f>(program, location, v0, src_loc);
}

void InterfaceOuter::ProgramUniform1fv(GLuint program, GLint location, csr_GLsizei count, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform1fv>(program, location, count, value, src_loc);
}

void InterfaceOuter::ProgramUniform1i(GLuint program, GLint location, GLint v0, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform1i>(program, location, v0, src_loc);
}

void InterfaceOuter::ProgramUniform1iv(GLuint program, GLint location, csr_GLsizei count, GLintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform1iv>(program, location, count, value, src_loc);
}

void InterfaceOuter::ProgramUniform1ui(GLuint program, GLint location, GLuint v0, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform1ui>(program, location, v0, src_loc);
}

void InterfaceOuter::ProgramUniform1uiv(GLuint program, GLint location, csr_GLsizei count, GLuintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform1uiv>(program, location, count, value, src_loc);
}

void InterfaceOuter::ProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform2d>(program, location, v0, v1, src_loc);
}

void InterfaceOuter::ProgramUniform2dv(GLuint program, GLint location, csr_GLsizei count, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform2dv>(program, location, count, value, src_loc);
}

void InterfaceOuter::ProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform2f>(program, location, v0, v1, src_loc);
}

void InterfaceOuter::ProgramUniform2fv(GLuint program, GLint location, csr_GLsizei count, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform2fv>(program, location, count, value, src_loc);
}

void InterfaceOuter::ProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform2i>(program, location, v0, v1, src_loc);
}

void InterfaceOuter::ProgramUniform2iv(GLuint program, GLint location, csr_GLsizei count, GLintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform2iv>(program, location, count, value, src_loc);
}

void InterfaceOuter::ProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform2ui>(program, location, v0, v1, src_loc);
}

void InterfaceOuter::ProgramUniform2uiv(GLuint program, GLint location, csr_GLsizei count, GLuintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform2uiv>(program, location, count, value, src_loc);
}

void InterfaceOuter::ProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform3d>(program, location, v0, v1, v2, src_loc);
}

void InterfaceOuter::ProgramUniform3dv(GLuint program, GLint location, csr_GLsizei count, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform3dv>(program, location, count, value, src_loc);
}

void InterfaceOuter::ProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform3f>(program, location, v0, v1, v2, src_loc);
}

void InterfaceOuter::ProgramUniform3fv(GLuint program, GLint location, csr_GLsizei count, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform3fv>(program, location, count, value, src_loc);
}

void InterfaceOuter::ProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform3i>(program, location, v0, v1, v2, src_loc);
}

void InterfaceOuter::ProgramUniform3iv(GLuint program, GLint location, csr_GLsizei count, GLintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform3iv>(program, location, count, value, src_loc);
}

void InterfaceOuter::ProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform3ui>(program, location, v0, v1, v2, src_loc);
}

void InterfaceOuter::ProgramUniform3uiv(GLuint program, GLint location, csr_GLsizei count, GLuintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform3uiv>(program, location, count, value, src_loc);
}

void InterfaceOuter::ProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform4d>(program, location, v0, v1, v2, v3, src_loc);
}

void InterfaceOuter::ProgramUniform4dv(GLuint program, GLint location, csr_GLsizei count, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform4dv>(program, location, count, value, src_loc);
}

void InterfaceOuter::ProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform4f>(program, location, v0, v1, v2, v3, src_loc);
}

void InterfaceOuter::ProgramUniform4fv(GLuint program, GLint location, csr_GLsizei count, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform4fv>(program, location, count, value, src_loc);
}

void InterfaceOuter::ProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform4i>(program, location, v0, v1, v2, v3, src_loc);
}

void InterfaceOuter::ProgramUniform4iv(GLuint program, GLint location, csr_GLsizei count, GLintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform4iv>(program, location, count, value, src_loc);
}

void InterfaceOuter::ProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform4ui>(program, location, v0, v1, v2, v3, src_loc);
}

void InterfaceOuter::ProgramUniform4uiv(GLuint program, GLint location, csr_GLsizei count, GLuintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniform4uiv>(program, location, count, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix2dv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix2dv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix2fv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix2fv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix2x3dv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix2x3dv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix2x3fv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix2x3fv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix2x4dv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix2x4dv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix2x4fv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix2x4fv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix3dv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix3dv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix3fv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix3fv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix3x2dv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix3x2dv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix3x2fv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix3x2fv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix3x4dv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix3x4dv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix3x4fv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix3x4fv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix4dv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix4dv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix4fv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix4fv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix4x2dv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix4x2dv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix4x2fv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix4x2fv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix4x3dv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix4x3dv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProgramUniformMatrix4x3fv(GLuint program, GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::ProgramUniformMatrix4x3fv>(program, location, count, transpose, value, src_loc);
}

void InterfaceOuter::ProvokingVertex(GLenum mode, SrcLoc src_loc){
    return _call<&InterfaceInner::ProvokingVertex>(mode, src_loc);
}

void InterfaceOuter::PushDebugGroup(GLenum source, GLuint id, csr_GLsizei length, GLcharArr message, SrcLoc src_loc){
    return _call<&InterfaceInner::PushDebugGroup>(source, id, length, message, src_loc);
}

void InterfaceOuter::QueryCounter(GLuint id, GLenum target, SrcLoc src_loc){
    return _call<&InterfaceInner::QueryCounter>(id, target, src_loc);
}

void InterfaceOuter::ReadBuffer(GLenum src, SrcLoc src_loc){
    return _call<&InterfaceInner::ReadBuffer>(src, src_loc);
}

void InterfaceOuter::ReadPixels(GLint x, GLint y, csr_GLsizei width, csr_GLsizei height, GLenum format, GLenum type, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::ReadPixels>(x, y, width, height, format, type, pixels, src_loc);
}

void InterfaceOuter::ReadnPixels(GLint x, GLint y, csr_GLsizei width, csr_GLsizei height, GLenum format, GLenum type, csr_GLsizei bufSize, GLdata data, SrcLoc src_loc){
    return _call<&InterfaceInner::ReadnPixels>(x, y, width, height, format, type, bufSize, data, src_loc);
}

void InterfaceOuter::ReleaseShaderCompiler(SrcLoc src_loc){
    return _call<&InterfaceInner::ReleaseShaderCompiler>(src_loc);
}

void InterfaceOuter::RenderbufferStorage(GLenum target, GLenum internalformat, csr_GLsizei width, csr_GLsizei height, SrcLoc src_loc){
    return _call<&InterfaceInner::RenderbufferStorage>(target, internalformat, width, height, src_loc);
}

void InterfaceOuter::RenderbufferStorageMultisample(GLenum target, csr_GLsizei samples, GLenum internalformat, csr_GLsizei width, csr_GLsizei height, SrcLoc src_loc){
    return _call<&InterfaceInner::RenderbufferStorageMultisample>(target, samples, internalformat, width, height, src_loc);
}

void InterfaceOuter::ResumeTransformFeedback(SrcLoc src_loc){
    return _call<&InterfaceInner::ResumeTransformFeedback>(src_loc);
}

void InterfaceOuter::SampleCoverage(GLfloat value, GLboolean invert, SrcLoc src_loc){
    return _call<&InterfaceInner::SampleCoverage>(value, invert, src_loc);
}

void InterfaceOuter::SampleMaski(GLuint maskNumber, GLbitfield mask, SrcLoc src_loc){
    return _call<&InterfaceInner::SampleMaski>(maskNumber, mask, src_loc);
}

void InterfaceOuter::SamplerParameterIiv(GLuint sampler, GLenum pname, GLintArr param, SrcLoc src_loc){
    return _call<&InterfaceInner::SamplerParameterIiv>(sampler, pname, param, src_loc);
}

void InterfaceOuter::SamplerParameterIuiv(GLuint sampler, GLenum pname, GLuintArr param, SrcLoc src_loc){
    return _call<&InterfaceInner::SamplerParameterIuiv>(sampler, pname, param, src_loc);
}

void InterfaceOuter::SamplerParameterf(GLuint sampler, GLenum pname, GLfloat param, SrcLoc src_loc){
    return _call<&InterfaceInner::SamplerParameterf>(sampler, pname, param, src_loc);
}

void InterfaceOuter::SamplerParameterfv(GLuint sampler, GLenum pname, GLfloatArr param, SrcLoc src_loc){
    return _call<&InterfaceInner::SamplerParameterfv>(sampler, pname, param, src_loc);
}

void InterfaceOuter::SamplerParameteri(GLuint sampler, GLenum pname, GLint param, SrcLoc src_loc){
    return _call<&InterfaceInner::SamplerParameteri>(sampler, pname, param, src_loc);
}

void InterfaceOuter::SamplerParameteriv(GLuint sampler, GLenum pname, GLintArr param, SrcLoc src_loc){
    return _call<&InterfaceInner::SamplerParameteriv>(sampler, pname, param, src_loc);
}

void InterfaceOuter::Scissor(GLint x, GLint y, csr_GLsizei width, csr_GLsizei height, SrcLoc src_loc){
    return _call<&InterfaceInner::Scissor>(x, y, width, height, src_loc);
}

void InterfaceOuter::ScissorArrayv(GLuint first, csr_GLsizei count, GLintArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::ScissorArrayv>(first, count, v, src_loc);
}

void InterfaceOuter::ScissorIndexed(GLuint index, GLint left, GLint bottom, csr_GLsizei width, csr_GLsizei height, SrcLoc src_loc){
    return _call<&InterfaceInner::ScissorIndexed>(index, left, bottom, width, height, src_loc);
}

void InterfaceOuter::ScissorIndexedv(GLuint index, GLintArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::ScissorIndexedv>(index, v, src_loc);
}

void InterfaceOuter::ShaderBinary(csr_GLsizei count, GLuintArr shaders, GLenum binaryFormat, GLdata binary, csr_GLsizei length, SrcLoc src_loc){
    return _call<&InterfaceInner::ShaderBinary>(count, shaders, binaryFormat, binary, length, src_loc);
}

void InterfaceOuter::ShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding, SrcLoc src_loc){
    return _call<&InterfaceInner::ShaderStorageBlockBinding>(program, storageBlockIndex, storageBlockBinding, src_loc);
}

void InterfaceOuter::SpecializeShader(GLuint shader, GLcharArr pEntryPoint, GLuint numSpecializationConstants, GLuintArr pConstantIndex, GLuintArr pConstantValue, SrcLoc src_loc){
    return _call<&InterfaceInner::SpecializeShader>(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue, src_loc);
}

void InterfaceOuter::StencilFunc(GLenum func, GLint ref, GLuint mask, SrcLoc src_loc){
    return _call<&InterfaceInner::StencilFunc>(func, ref, mask, src_loc);
}

void InterfaceOuter::StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask, SrcLoc src_loc){
    return _call<&InterfaceInner::StencilFuncSeparate>(face, func, ref, mask, src_loc);
}

void InterfaceOuter::StencilMask(GLuint mask, SrcLoc src_loc){
    return _call<&InterfaceInner::StencilMask>(mask, src_loc);
}

void InterfaceOuter::StencilMaskSeparate(GLenum face, GLuint mask, SrcLoc src_loc){
    return _call<&InterfaceInner::StencilMaskSeparate>(face, mask, src_loc);
}

void InterfaceOuter::StencilOp(GLenum fail, GLenum zfail, GLenum zpass, SrcLoc src_loc){
    return _call<&InterfaceInner::StencilOp>(fail, zfail, zpass, src_loc);
}

void InterfaceOuter::StencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass, SrcLoc src_loc){
    return _call<&InterfaceInner::StencilOpSeparate>(face, sfail, dpfail, dppass, src_loc);
}

void InterfaceOuter::TexBuffer(GLenum target, GLenum internalformat, GLuint buffer, SrcLoc src_loc){
    return _call<&InterfaceInner::TexBuffer>(target, internalformat, buffer, src_loc);
}

void InterfaceOuter::TexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size, SrcLoc src_loc){
    return _call<&InterfaceInner::TexBufferRange>(target, internalformat, buffer, offset, size, src_loc);
}

void InterfaceOuter::TexImage1D(GLenum target, GLint level, GLint internalformat, csr_GLsizei width, GLint border, GLenum format, GLenum type, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::TexImage1D>(target, level, internalformat, width, border, format, type, pixels, src_loc);
}

void InterfaceOuter::TexImage2D(GLenum target, GLint level, GLint internalformat, csr_GLsizei width, csr_GLsizei height, GLint border, GLenum format, GLenum type, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::TexImage2D>(target, level, internalformat, width, height, border, format, type, pixels, src_loc);
}

void InterfaceOuter::TexImage2DMultisample(GLenum target, csr_GLsizei samples, GLenum internalformat, csr_GLsizei width, csr_GLsizei height, GLboolean fixedsamplelocations, SrcLoc src_loc){
    return _call<&InterfaceInner::TexImage2DMultisample>(target, samples, internalformat, width, height, fixedsamplelocations, src_loc);
}

void InterfaceOuter::TexImage3D(GLenum target, GLint level, GLint internalformat, csr_GLsizei width, csr_GLsizei height, csr_GLsizei depth, GLint border, GLenum format, GLenum type, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::TexImage3D>(target, level, internalformat, width, height, depth, border, format, type, pixels, src_loc);
}

void InterfaceOuter::TexImage3DMultisample(GLenum target, csr_GLsizei samples, GLenum internalformat, csr_GLsizei width, csr_GLsizei height, csr_GLsizei depth, GLboolean fixedsamplelocations, SrcLoc src_loc){
    return _call<&InterfaceInner::TexImage3DMultisample>(target, samples, internalformat, width, height, depth, fixedsamplelocations, src_loc);
}

void InterfaceOuter::TexParameterIiv(GLenum target, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::TexParameterIiv>(target, pname, params, src_loc);
}

void InterfaceOuter::TexParameterIuiv(GLenum target, GLenum pname, GLuintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::TexParameterIuiv>(target, pname, params, src_loc);
}

void InterfaceOuter::TexParameterf(GLenum target, GLenum pname, GLfloat param, SrcLoc src_loc){
    return _call<&InterfaceInner::TexParameterf>(target, pname, param, src_loc);
}

void InterfaceOuter::TexParameterfv(GLenum target, GLenum pname, GLfloatArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::TexParameterfv>(target, pname, params, src_loc);
}

void InterfaceOuter::TexParameteri(GLenum target, GLenum pname, GLint param, SrcLoc src_loc){
    return _call<&InterfaceInner::TexParameteri>(target, pname, param, src_loc);
}

void InterfaceOuter::TexParameteriv(GLenum target, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::TexParameteriv>(target, pname, params, src_loc);
}

void InterfaceOuter::TexStorage1D(GLenum target, csr_GLsizei levels, GLenum internalformat, csr_GLsizei width, SrcLoc src_loc){
    return _call<&InterfaceInner::TexStorage1D>(target, levels, internalformat, width, src_loc);
}

void InterfaceOuter::TexStorage2D(GLenum target, csr_GLsizei levels, GLenum internalformat, csr_GLsizei width, csr_GLsizei height, SrcLoc src_loc){
    return _call<&InterfaceInner::TexStorage2D>(target, levels, internalformat, width, height, src_loc);
}

void InterfaceOuter::TexStorage2DMultisample(GLenum target, csr_GLsizei samples, GLenum internalformat, csr_GLsizei width, csr_GLsizei height, GLboolean fixedsamplelocations, SrcLoc src_loc){
    return _call<&InterfaceInner::TexStorage2DMultisample>(target, samples, internalformat, width, height, fixedsamplelocations, src_loc);
}

void InterfaceOuter::TexStorage3D(GLenum target, csr_GLsizei levels, GLenum internalformat, csr_GLsizei width, csr_GLsizei height, csr_GLsizei depth, SrcLoc src_loc){
    return _call<&InterfaceInner::TexStorage3D>(target, levels, internalformat, width, height, depth, src_loc);
}

void InterfaceOuter::TexStorage3DMultisample(GLenum target, csr_GLsizei samples, GLenum internalformat, csr_GLsizei width, csr_GLsizei height, csr_GLsizei depth, GLboolean fixedsamplelocations, SrcLoc src_loc){
    return _call<&InterfaceInner::TexStorage3DMultisample>(target, samples, internalformat, width, height, depth, fixedsamplelocations, src_loc);
}

void InterfaceOuter::TexSubImage1D(GLenum target, GLint level, GLint xoffset, csr_GLsizei width, GLenum format, GLenum type, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::TexSubImage1D>(target, level, xoffset, width, format, type, pixels, src_loc);
}

void InterfaceOuter::TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, csr_GLsizei width, csr_GLsizei height, GLenum format, GLenum type, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::TexSubImage2D>(target, level, xoffset, yoffset, width, height, format, type, pixels, src_loc);
}

void InterfaceOuter::TexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, csr_GLsizei width, csr_GLsizei height, csr_GLsizei depth, GLenum format, GLenum type, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::TexSubImage3D>(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels, src_loc);
}

void InterfaceOuter::TextureBarrier(SrcLoc src_loc){
    return _call<&InterfaceInner::TextureBarrier>(src_loc);
}

void InterfaceOuter::TextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureBuffer>(texture, internalformat, buffer, src_loc);
}

void InterfaceOuter::TextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureBufferRange>(texture, internalformat, buffer, offset, size, src_loc);
}

void InterfaceOuter::TextureParameterIiv(GLuint texture, GLenum pname, GLintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureParameterIiv>(texture, pname, params, src_loc);
}

void InterfaceOuter::TextureParameterIuiv(GLuint texture, GLenum pname, GLuintArr params, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureParameterIuiv>(texture, pname, params, src_loc);
}

void InterfaceOuter::TextureParameterf(GLuint texture, GLenum pname, GLfloat param, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureParameterf>(texture, pname, param, src_loc);
}

void InterfaceOuter::TextureParameterfv(GLuint texture, GLenum pname, GLfloatArr param, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureParameterfv>(texture, pname, param, src_loc);
}

void InterfaceOuter::TextureParameteri(GLuint texture, GLenum pname, GLint param, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureParameteri>(texture, pname, param, src_loc);
}

void InterfaceOuter::TextureParameteriv(GLuint texture, GLenum pname, GLintArr param, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureParameteriv>(texture, pname, param, src_loc);
}

void InterfaceOuter::TextureStorage1D(GLuint texture, csr_GLsizei levels, GLenum internalformat, csr_GLsizei width, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureStorage1D>(texture, levels, internalformat, width, src_loc);
}

void InterfaceOuter::TextureStorage2D(GLuint texture, csr_GLsizei levels, GLenum internalformat, csr_GLsizei width, csr_GLsizei height, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureStorage2D>(texture, levels, internalformat, width, height, src_loc);
}

void InterfaceOuter::TextureStorage2DMultisample(GLuint texture, csr_GLsizei samples, GLenum internalformat, csr_GLsizei width, csr_GLsizei height, GLboolean fixedsamplelocations, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureStorage2DMultisample>(texture, samples, internalformat, width, height, fixedsamplelocations, src_loc);
}

void InterfaceOuter::TextureStorage3D(GLuint texture, csr_GLsizei levels, GLenum internalformat, csr_GLsizei width, csr_GLsizei height, csr_GLsizei depth, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureStorage3D>(texture, levels, internalformat, width, height, depth, src_loc);
}

void InterfaceOuter::TextureStorage3DMultisample(GLuint texture, csr_GLsizei samples, GLenum internalformat, csr_GLsizei width, csr_GLsizei height, csr_GLsizei depth, GLboolean fixedsamplelocations, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureStorage3DMultisample>(texture, samples, internalformat, width, height, depth, fixedsamplelocations, src_loc);
}

void InterfaceOuter::TextureSubImage1D(GLuint texture, GLint level, GLint xoffset, csr_GLsizei width, GLenum format, GLenum type, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureSubImage1D>(texture, level, xoffset, width, format, type, pixels, src_loc);
}

void InterfaceOuter::TextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, csr_GLsizei width, csr_GLsizei height, GLenum format, GLenum type, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureSubImage2D>(texture, level, xoffset, yoffset, width, height, format, type, pixels, src_loc);
}

void InterfaceOuter::TextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, csr_GLsizei width, csr_GLsizei height, csr_GLsizei depth, GLenum format, GLenum type, GLdata pixels, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureSubImage3D>(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels, src_loc);
}

void InterfaceOuter::TextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers, SrcLoc src_loc){
    return _call<&InterfaceInner::TextureView>(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers, src_loc);
}

void InterfaceOuter::TransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer, SrcLoc src_loc){
    return _call<&InterfaceInner::TransformFeedbackBufferBase>(xfb, index, buffer, src_loc);
}

void InterfaceOuter::TransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size, SrcLoc src_loc){
    return _call<&InterfaceInner::TransformFeedbackBufferRange>(xfb, index, buffer, offset, size, src_loc);
}

void InterfaceOuter::Uniform1d(GLint location, GLdouble x, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform1d>(location, x, src_loc);
}

void InterfaceOuter::Uniform1dv(GLint location, csr_GLsizei count, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform1dv>(location, count, value, src_loc);
}

void InterfaceOuter::Uniform1f(GLint location, GLfloat v0, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform1f>(location, v0, src_loc);
}

void InterfaceOuter::Uniform1fv(GLint location, csr_GLsizei count, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform1fv>(location, count, value, src_loc);
}

void InterfaceOuter::Uniform1i(GLint location, GLint v0, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform1i>(location, v0, src_loc);
}

void InterfaceOuter::Uniform1iv(GLint location, csr_GLsizei count, GLintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform1iv>(location, count, value, src_loc);
}

void InterfaceOuter::Uniform1ui(GLint location, GLuint v0, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform1ui>(location, v0, src_loc);
}

void InterfaceOuter::Uniform1uiv(GLint location, csr_GLsizei count, GLuintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform1uiv>(location, count, value, src_loc);
}

void InterfaceOuter::Uniform2d(GLint location, GLdouble x, GLdouble y, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform2d>(location, x, y, src_loc);
}

void InterfaceOuter::Uniform2dv(GLint location, csr_GLsizei count, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform2dv>(location, count, value, src_loc);
}

void InterfaceOuter::Uniform2f(GLint location, GLfloat v0, GLfloat v1, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform2f>(location, v0, v1, src_loc);
}

void InterfaceOuter::Uniform2fv(GLint location, csr_GLsizei count, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform2fv>(location, count, value, src_loc);
}

void InterfaceOuter::Uniform2i(GLint location, GLint v0, GLint v1, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform2i>(location, v0, v1, src_loc);
}

void InterfaceOuter::Uniform2iv(GLint location, csr_GLsizei count, GLintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform2iv>(location, count, value, src_loc);
}

void InterfaceOuter::Uniform2ui(GLint location, GLuint v0, GLuint v1, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform2ui>(location, v0, v1, src_loc);
}

void InterfaceOuter::Uniform2uiv(GLint location, csr_GLsizei count, GLuintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform2uiv>(location, count, value, src_loc);
}

void InterfaceOuter::Uniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform3d>(location, x, y, z, src_loc);
}

void InterfaceOuter::Uniform3dv(GLint location, csr_GLsizei count, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform3dv>(location, count, value, src_loc);
}

void InterfaceOuter::Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform3f>(location, v0, v1, v2, src_loc);
}

void InterfaceOuter::Uniform3fv(GLint location, csr_GLsizei count, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform3fv>(location, count, value, src_loc);
}

void InterfaceOuter::Uniform3i(GLint location, GLint v0, GLint v1, GLint v2, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform3i>(location, v0, v1, v2, src_loc);
}

void InterfaceOuter::Uniform3iv(GLint location, csr_GLsizei count, GLintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform3iv>(location, count, value, src_loc);
}

void InterfaceOuter::Uniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform3ui>(location, v0, v1, v2, src_loc);
}

void InterfaceOuter::Uniform3uiv(GLint location, csr_GLsizei count, GLuintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform3uiv>(location, count, value, src_loc);
}

void InterfaceOuter::Uniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform4d>(location, x, y, z, w, src_loc);
}

void InterfaceOuter::Uniform4dv(GLint location, csr_GLsizei count, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform4dv>(location, count, value, src_loc);
}

void InterfaceOuter::Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform4f>(location, v0, v1, v2, v3, src_loc);
}

void InterfaceOuter::Uniform4fv(GLint location, csr_GLsizei count, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform4fv>(location, count, value, src_loc);
}

void InterfaceOuter::Uniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform4i>(location, v0, v1, v2, v3, src_loc);
}

void InterfaceOuter::Uniform4iv(GLint location, csr_GLsizei count, GLintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform4iv>(location, count, value, src_loc);
}

void InterfaceOuter::Uniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform4ui>(location, v0, v1, v2, v3, src_loc);
}

void InterfaceOuter::Uniform4uiv(GLint location, csr_GLsizei count, GLuintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::Uniform4uiv>(location, count, value, src_loc);
}

void InterfaceOuter::UniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformBlockBinding>(program, uniformBlockIndex, uniformBlockBinding, src_loc);
}

void InterfaceOuter::UniformMatrix2dv(GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix2dv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix2fv(GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix2fv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix2x3dv(GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix2x3dv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix2x3fv(GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix2x3fv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix2x4dv(GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix2x4dv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix2x4fv(GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix2x4fv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix3dv(GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix3dv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix3fv(GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix3fv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix3x2dv(GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix3x2dv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix3x2fv(GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix3x2fv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix3x4dv(GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix3x4dv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix3x4fv(GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix3x4fv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix4dv(GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix4dv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix4fv(GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix4fv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix4x2dv(GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix4x2dv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix4x2fv(GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix4x2fv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix4x3dv(GLint location, csr_GLsizei count, GLboolean transpose, GLdoubleArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix4x3dv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformMatrix4x3fv(GLint location, csr_GLsizei count, GLboolean transpose, GLfloatArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformMatrix4x3fv>(location, count, transpose, value, src_loc);
}

void InterfaceOuter::UniformSubroutinesuiv(GLenum shadertype, csr_GLsizei count, GLuintArr indices, SrcLoc src_loc){
    return _call<&InterfaceInner::UniformSubroutinesuiv>(shadertype, count, indices, src_loc);
}

GLbooleanRes InterfaceOuter::UnmapBuffer(GLenum target, SrcLoc src_loc){
    return _call<&InterfaceInner::UnmapBuffer>(target, src_loc);
}

GLbooleanRes InterfaceOuter::UnmapNamedBuffer(GLuint buffer, SrcLoc src_loc){
    return _call<&InterfaceInner::UnmapNamedBuffer>(buffer, src_loc);
}

void InterfaceOuter::UseProgram(GLuint program, SrcLoc src_loc){
    return _call<&InterfaceInner::UseProgram>(program, src_loc);
}

void InterfaceOuter::UseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program, SrcLoc src_loc){
    return _call<&InterfaceInner::UseProgramStages>(pipeline, stages, program, src_loc);
}

void InterfaceOuter::ValidateProgram(GLuint program, SrcLoc src_loc){
    return _call<&InterfaceInner::ValidateProgram>(program, src_loc);
}

void InterfaceOuter::ValidateProgramPipeline(GLuint pipeline, SrcLoc src_loc){
    return _call<&InterfaceInner::ValidateProgramPipeline>(pipeline, src_loc);
}

void InterfaceOuter::VertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexArrayAttribBinding>(vaobj, attribindex, bindingindex, src_loc);
}

void InterfaceOuter::VertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexArrayAttribFormat>(vaobj, attribindex, size, type, normalized, relativeoffset, src_loc);
}

void InterfaceOuter::VertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexArrayAttribIFormat>(vaobj, attribindex, size, type, relativeoffset, src_loc);
}

void InterfaceOuter::VertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexArrayAttribLFormat>(vaobj, attribindex, size, type, relativeoffset, src_loc);
}

void InterfaceOuter::VertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexArrayBindingDivisor>(vaobj, bindingindex, divisor, src_loc);
}

void InterfaceOuter::VertexArrayElementBuffer(GLuint vaobj, GLuint buffer, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexArrayElementBuffer>(vaobj, buffer, src_loc);
}

void InterfaceOuter::VertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, csr_GLsizei stride, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexArrayVertexBuffer>(vaobj, bindingindex, buffer, offset, stride, src_loc);
}

void InterfaceOuter::VertexArrayVertexBuffers(GLuint vaobj, GLuint first, csr_GLsizei count, GLuintArr buffers, GLintptrArr offsets, csra_GLsizeiArr strides, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexArrayVertexBuffers>(vaobj, first, count, buffers, offsets, strides, src_loc);
}

void InterfaceOuter::VertexAttrib1d(GLuint index, GLdouble x, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib1d>(index, x, src_loc);
}

void InterfaceOuter::VertexAttrib1dv(GLuint index, GLdoubleArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib1dv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib1f(GLuint index, GLfloat x, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib1f>(index, x, src_loc);
}

void InterfaceOuter::VertexAttrib1fv(GLuint index, GLfloatArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib1fv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib1s(GLuint index, GLshort x, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib1s>(index, x, src_loc);
}

void InterfaceOuter::VertexAttrib1sv(GLuint index, GLshort v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib1sv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib2d(GLuint index, GLdouble x, GLdouble y, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib2d>(index, x, y, src_loc);
}

void InterfaceOuter::VertexAttrib2dv(GLuint index, GLdoubleArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib2dv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib2f(GLuint index, GLfloat x, GLfloat y, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib2f>(index, x, y, src_loc);
}

void InterfaceOuter::VertexAttrib2fv(GLuint index, GLfloatArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib2fv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib2s(GLuint index, GLshort x, GLshort y, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib2s>(index, x, y, src_loc);
}

void InterfaceOuter::VertexAttrib2sv(GLuint index, GLshort v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib2sv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib3d>(index, x, y, z, src_loc);
}

void InterfaceOuter::VertexAttrib3dv(GLuint index, GLdoubleArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib3dv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib3f>(index, x, y, z, src_loc);
}

void InterfaceOuter::VertexAttrib3fv(GLuint index, GLfloatArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib3fv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib3s>(index, x, y, z, src_loc);
}

void InterfaceOuter::VertexAttrib3sv(GLuint index, GLshort v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib3sv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib4Nbv(GLuint index, GLbyte v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4Nbv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib4Niv(GLuint index, GLintArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4Niv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib4Nsv(GLuint index, GLshort v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4Nsv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4Nub>(index, x, y, z, w, src_loc);
}

void InterfaceOuter::VertexAttrib4Nubv(GLuint index, GLubyte v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4Nubv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib4Nuiv(GLuint index, GLuintArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4Nuiv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib4Nusv(GLuint index, GLushort v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4Nusv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib4bv(GLuint index, GLbyte v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4bv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4d>(index, x, y, z, w, src_loc);
}

void InterfaceOuter::VertexAttrib4dv(GLuint index, GLdoubleArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4dv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4f>(index, x, y, z, w, src_loc);
}

void InterfaceOuter::VertexAttrib4fv(GLuint index, GLfloatArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4fv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib4iv(GLuint index, GLintArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4iv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4s>(index, x, y, z, w, src_loc);
}

void InterfaceOuter::VertexAttrib4sv(GLuint index, GLshort v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4sv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib4ubv(GLuint index, GLubyte v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4ubv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib4uiv(GLuint index, GLuintArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4uiv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttrib4usv(GLuint index, GLushort v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttrib4usv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribBinding(GLuint attribindex, GLuint bindingindex, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribBinding>(attribindex, bindingindex, src_loc);
}

void InterfaceOuter::VertexAttribDivisor(GLuint index, GLuint divisor, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribDivisor>(index, divisor, src_loc);
}

void InterfaceOuter::VertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribFormat>(attribindex, size, type, normalized, relativeoffset, src_loc);
}

void InterfaceOuter::VertexAttribI1i(GLuint index, GLint x, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI1i>(index, x, src_loc);
}

void InterfaceOuter::VertexAttribI1iv(GLuint index, GLintArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI1iv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribI1ui(GLuint index, GLuint x, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI1ui>(index, x, src_loc);
}

void InterfaceOuter::VertexAttribI1uiv(GLuint index, GLuintArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI1uiv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribI2i(GLuint index, GLint x, GLint y, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI2i>(index, x, y, src_loc);
}

void InterfaceOuter::VertexAttribI2iv(GLuint index, GLintArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI2iv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribI2ui(GLuint index, GLuint x, GLuint y, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI2ui>(index, x, y, src_loc);
}

void InterfaceOuter::VertexAttribI2uiv(GLuint index, GLuintArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI2uiv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribI3i(GLuint index, GLint x, GLint y, GLint z, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI3i>(index, x, y, z, src_loc);
}

void InterfaceOuter::VertexAttribI3iv(GLuint index, GLintArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI3iv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI3ui>(index, x, y, z, src_loc);
}

void InterfaceOuter::VertexAttribI3uiv(GLuint index, GLuintArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI3uiv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribI4bv(GLuint index, GLbyte v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI4bv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI4i>(index, x, y, z, w, src_loc);
}

void InterfaceOuter::VertexAttribI4iv(GLuint index, GLintArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI4iv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribI4sv(GLuint index, GLshort v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI4sv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribI4ubv(GLuint index, GLubyte v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI4ubv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI4ui>(index, x, y, z, w, src_loc);
}

void InterfaceOuter::VertexAttribI4uiv(GLuint index, GLuintArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI4uiv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribI4usv(GLuint index, GLushort v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribI4usv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribIFormat>(attribindex, size, type, relativeoffset, src_loc);
}

void InterfaceOuter::VertexAttribIPointer(GLuint index, GLint size, GLenum type, csr_GLsizei stride, GLdata pointer, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribIPointer>(index, size, type, stride, pointer, src_loc);
}

void InterfaceOuter::VertexAttribL1d(GLuint index, GLdouble x, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribL1d>(index, x, src_loc);
}

void InterfaceOuter::VertexAttribL1dv(GLuint index, GLdoubleArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribL1dv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribL2d(GLuint index, GLdouble x, GLdouble y, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribL2d>(index, x, y, src_loc);
}

void InterfaceOuter::VertexAttribL2dv(GLuint index, GLdoubleArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribL2dv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribL3d>(index, x, y, z, src_loc);
}

void InterfaceOuter::VertexAttribL3dv(GLuint index, GLdoubleArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribL3dv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribL4d>(index, x, y, z, w, src_loc);
}

void InterfaceOuter::VertexAttribL4dv(GLuint index, GLdoubleArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribL4dv>(index, v, src_loc);
}

void InterfaceOuter::VertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribLFormat>(attribindex, size, type, relativeoffset, src_loc);
}

void InterfaceOuter::VertexAttribLPointer(GLuint index, GLint size, GLenum type, csr_GLsizei stride, GLdata pointer, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribLPointer>(index, size, type, stride, pointer, src_loc);
}

void InterfaceOuter::VertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribP1ui>(index, type, normalized, value, src_loc);
}

void InterfaceOuter::VertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, GLuintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribP1uiv>(index, type, normalized, value, src_loc);
}

void InterfaceOuter::VertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribP2ui>(index, type, normalized, value, src_loc);
}

void InterfaceOuter::VertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, GLuintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribP2uiv>(index, type, normalized, value, src_loc);
}

void InterfaceOuter::VertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribP3ui>(index, type, normalized, value, src_loc);
}

void InterfaceOuter::VertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, GLuintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribP3uiv>(index, type, normalized, value, src_loc);
}

void InterfaceOuter::VertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribP4ui>(index, type, normalized, value, src_loc);
}

void InterfaceOuter::VertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, GLuintArr value, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribP4uiv>(index, type, normalized, value, src_loc);
}

void InterfaceOuter::VertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, csr_GLsizei stride, GLdata pointer, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexAttribPointer>(index, size, type, normalized, stride, pointer, src_loc);
}

void InterfaceOuter::VertexBindingDivisor(GLuint bindingindex, GLuint divisor, SrcLoc src_loc){
    return _call<&InterfaceInner::VertexBindingDivisor>(bindingindex, divisor, src_loc);
}

void InterfaceOuter::Viewport(GLint x, GLint y, csr_GLsizei width, csr_GLsizei height, SrcLoc src_loc){
    return _call<&InterfaceInner::Viewport>(x, y, width, height, src_loc);
}

void InterfaceOuter::ViewportArrayv(GLuint first, csr_GLsizei count, GLfloatArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::ViewportArrayv>(first, count, v, src_loc);
}

void InterfaceOuter::ViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h, SrcLoc src_loc){
    return _call<&InterfaceInner::ViewportIndexedf>(index, x, y, w, h, src_loc);
}

void InterfaceOuter::ViewportIndexedfv(GLuint index, GLfloatArr v, SrcLoc src_loc){
    return _call<&InterfaceInner::ViewportIndexedfv>(index, v, src_loc);
}

void InterfaceOuter::WaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, SrcLoc src_loc){
    return _call<&InterfaceInner::WaitSync>(sync, flags, timeout, src_loc);
}
