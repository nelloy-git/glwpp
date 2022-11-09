#include "gl/InterfaceGlOuter.hpp"

#include "glad/gl.h"

#include "Context.hpp"

using namespace glwpp;

template<typename T>
using sptr = std::shared_ptr<T>;

    // _ctx->getOnRunEvent().addActionQueued([](){});
InterfaceGlOuter::InterfaceGlOuter(Context* ctx, const std::function<void(GLsrc)> debug) :
    InterfaceGlInner(ctx, debug){
}

InterfaceGlOuter::~InterfaceGlOuter(){
}

template<auto F, typename ... Args>
auto InterfaceGlOuter::_call(Args... args){
    using R = std::invoke_result_t<decltype(F), InterfaceGlOuter, Args...>;
    if constexpr (std::is_same_v<R, void>){
        _ctx->getOnRunEvent().addActionQueued([this, args...](Context*, const Context::ms&){
            (this->*F)(args...);
            return false;
        });
    } else {
        R result;
        _ctx->getOnRunEvent().addActionQueued([this, result, args...](Context*, const Context::ms&){
            result = (this->*F)(args...);
            return false;
        });
        return result;
    }
}
// return _call<&InterfaceGlInner::ActiveShaderProgram>(pipeline, program, src_loc);

void InterfaceGlOuter::ActiveShaderProgram(GLuint pipeline, GLuint program, GLsrc src_loc){
    return _call<&InterfaceGlInner::ActiveShaderProgram>(pipeline, program, src_loc);
}

void InterfaceGlOuter::ActiveTexture(GLenum texture, GLsrc src_loc){
    return _call<&InterfaceGlInner::ActiveTexture>(texture, src_loc);
}

void InterfaceGlOuter::AttachShader(GLuint program, GLuint shader, GLsrc src_loc){
}

void InterfaceGlOuter::BeginConditionalRender(GLuint id, GLenum mode, GLsrc src_loc){
}

void InterfaceGlOuter::BeginQuery(GLenum target, GLuint id, GLsrc src_loc){
}

void InterfaceGlOuter::BeginQueryIndexed(GLenum target, GLuint index, GLuint id, GLsrc src_loc){
}

void InterfaceGlOuter::BeginTransformFeedback(GLenum primitiveMode, GLsrc src_loc){
}

void InterfaceGlOuter::BindAttribLocation(GLuint program, GLuint index, GLcharArr name, GLsrc src_loc){
}

void InterfaceGlOuter::BindBuffer(GLenum target, GLuint buffer, GLsrc src_loc){
}

void InterfaceGlOuter::BindBufferBase(GLenum target, GLuint index, GLuint buffer, GLsrc src_loc){
}

void InterfaceGlOuter::BindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr& offset, GLsizeiptr& size, GLsrc src_loc){
}

void InterfaceGlOuter::BindBuffersBase(GLenum target, GLuint first, GLsizei count, GLuintArr buffers, GLsrc src_loc){
}

void InterfaceGlOuter::BindBuffersRange(GLenum target, GLuint first, GLsizei count, GLuintArr buffers, GLintptrArr& offsets, GLsizeiptrArr& sizes, GLsrc src_loc){
}

void InterfaceGlOuter::BindFragDataLocation(GLuint program, GLuint color, GLcharArr name, GLsrc src_loc){
}

void InterfaceGlOuter::BindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, GLcharArr name, GLsrc src_loc){
}

void InterfaceGlOuter::BindFramebuffer(GLenum target, GLuint framebuffer, GLsrc src_loc){
}

void InterfaceGlOuter::BindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean& layered, GLint layer, GLenum access, GLenum format, GLsrc src_loc){
}

void InterfaceGlOuter::BindImageTextures(GLuint first, GLsizei count, GLuintArr textures, GLsrc src_loc){
}

void InterfaceGlOuter::BindProgramPipeline(GLuint pipeline, GLsrc src_loc){
}

void InterfaceGlOuter::BindRenderbuffer(GLenum target, GLuint renderbuffer, GLsrc src_loc){
}

void InterfaceGlOuter::BindSampler(GLuint unit, GLuint sampler, GLsrc src_loc){
}

void InterfaceGlOuter::BindSamplers(GLuint first, GLsizei count, GLuintArr samplers, GLsrc src_loc){
}

void InterfaceGlOuter::BindTexture(GLenum target, GLuint texture, GLsrc src_loc){
}

void InterfaceGlOuter::BindTextureUnit(GLuint unit, GLuint texture, GLsrc src_loc){
}

void InterfaceGlOuter::BindTextures(GLuint first, GLsizei count, GLuintArr textures, GLsrc src_loc){
}

void InterfaceGlOuter::BindTransformFeedback(GLenum target, GLuint id, GLsrc src_loc){
}

void InterfaceGlOuter::BindVertexArray(GLuint array, GLsrc src_loc){
}

void InterfaceGlOuter::BindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride, GLsrc src_loc){
}

void InterfaceGlOuter::BindVertexBuffers(GLuint first, GLsizei count, GLuintArr buffers, GLintptrArr offsets, GLsizeiArr strides, GLsrc src_loc){
}

void InterfaceGlOuter::BlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, GLsrc src_loc){
}

void InterfaceGlOuter::BlendEquation(GLenum mode, GLsrc src_loc){
}

void InterfaceGlOuter::BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha, GLsrc src_loc){
}

void InterfaceGlOuter::BlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha, GLsrc src_loc){
}

void InterfaceGlOuter::BlendEquationi(GLuint buf, GLenum mode, GLsrc src_loc){
}

void InterfaceGlOuter::BlendFunc(GLenum sfactor, GLenum dfactor, GLsrc src_loc){
}

void InterfaceGlOuter::BlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha, GLsrc src_loc){
}

void InterfaceGlOuter::BlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha, GLenum modeAlpha, GLsrc src_loc){
}

void InterfaceGlOuter::BlendFunci(GLuint buf, GLenum src, GLenum dst, GLsrc src_loc){
}

void InterfaceGlOuter::BlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter, GLsrc src_loc){
}

void InterfaceGlOuter::BlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter, GLsrc src_loc){
}

void InterfaceGlOuter::BufferData(GLenum target, GLsizeiptr size, GLdata data, GLenum usage, GLsrc src_loc){
}

void InterfaceGlOuter::BufferStorage(GLenum target, GLsizeiptr size, GLdata data, GLbitfield flags, GLsrc src_loc){
}

void InterfaceGlOuter::BufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::CheckFramebufferStatus(GLenum target, GLsrc src_loc){
}

void InterfaceGlOuter::CheckNamedFramebufferStatus(GLuint framebuffer, GLenum target, GLsrc src_loc){
}

void InterfaceGlOuter::ClampColor(GLenum target, GLenum clamp, GLsrc src_loc){
}

void InterfaceGlOuter::Clear(GLbitfield mask, GLsrc src_loc){
}

void InterfaceGlOuter::ClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::ClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::ClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil, GLsrc src_loc){
}

void InterfaceGlOuter::ClearBufferfv(GLenum buffer, GLint drawbuffer, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ClearBufferiv(GLenum buffer, GLint drawbuffer, GLintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ClearBufferuiv(GLenum buffer, GLint drawbuffer, GLuintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, GLsrc src_loc){
}

void InterfaceGlOuter::ClearDepth(GLdouble depth, GLsrc src_loc){
}

void InterfaceGlOuter::ClearDepthf(GLfloat d, GLsrc src_loc){
}

void InterfaceGlOuter::ClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::ClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::ClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil, GLsrc src_loc){
}

void InterfaceGlOuter::ClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLuintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ClearStencil(GLint s, GLsrc src_loc){
}

void InterfaceGlOuter::ClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::ClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::ClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, GLsrc src_loc){
}

void InterfaceGlOuter::ClipControl(GLenum origin, GLenum depth, GLsrc src_loc){
}

void InterfaceGlOuter::ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha, GLsrc src_loc){
}

void InterfaceGlOuter::ColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a, GLsrc src_loc){
}

void InterfaceGlOuter::CompileShader(GLuint shader, GLsrc src_loc){
}

void InterfaceGlOuter::CompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::CompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::CompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::CompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::CompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::CompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::CompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::CompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::CopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, GLsrc src_loc){
}

void InterfaceGlOuter::CopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth, GLsrc src_loc){
}

void InterfaceGlOuter::CopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, GLsrc src_loc){
}

void InterfaceGlOuter::CopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border, GLsrc src_loc){
}

void InterfaceGlOuter::CopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border, GLsrc src_loc){
}

void InterfaceGlOuter::CopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width, GLsrc src_loc){
}

void InterfaceGlOuter::CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height, GLsrc src_loc){
}

void InterfaceGlOuter::CopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height, GLsrc src_loc){
}

void InterfaceGlOuter::CopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width, GLsrc src_loc){
}

void InterfaceGlOuter::CopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height, GLsrc src_loc){
}

void InterfaceGlOuter::CopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height, GLsrc src_loc){
}

void InterfaceGlOuter::CreateBuffers(GLsizei n, GLuintArr dst, GLsrc src_loc){
}

void InterfaceGlOuter::CreateFramebuffers(GLsizei n, GLuintArr framebuffers, GLsrc src_loc){
}

InterfaceGlOuter::GLuintRes InterfaceGlOuter::CreateProgram(GLsrc src_loc){
}

void InterfaceGlOuter::CreateProgramPipelines(GLsizei n, GLuintArr pipelines, GLsrc src_loc){
}

void InterfaceGlOuter::CreateQueries(GLenum target, GLsizei n, GLuintArr ids, GLsrc src_loc){
}

void InterfaceGlOuter::CreateRenderbuffers(GLsizei n, GLuintArr renderbuffers, GLsrc src_loc){
}

void InterfaceGlOuter::CreateSamplers(GLsizei n, GLuintArr samplers, GLsrc src_loc){
}

InterfaceGlOuter::GLuintRes InterfaceGlOuter::CreateShader(GLenum type, GLsrc src_loc){
}

void InterfaceGlOuter::CreateTextures(GLenum target, GLsizei n, GLuintArr textures, GLsrc src_loc){
}

void InterfaceGlOuter::CreateTransformFeedbacks(GLsizei n, GLuintArr ids, GLsrc src_loc){
}

void InterfaceGlOuter::CreateVertexArrays(GLsizei n, GLuintArr arrays, GLsrc src_loc){
}

void InterfaceGlOuter::CullFace(GLenum mode, GLsrc src_loc){
}

// void InterfaceGlOuter::DebugMessageCallback(GLDEBUGPROC callback, GLdata userParam, GLsrc src_loc){
//     glDebugMessageCallback(*callback, userParam.get());
//     _debug(src_loc);
// }

void InterfaceGlOuter::DebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, GLuintArr ids, GLboolean enabled, GLsrc src_loc){
}

void InterfaceGlOuter::DebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLcharArr buf, GLsrc src_loc){
}

void InterfaceGlOuter::DeleteBuffers(GLsizei n, GLuintArr buffers, GLsrc src_loc){
}

void InterfaceGlOuter::DeleteFramebuffers(GLsizei n, GLuintArr framebuffers, GLsrc src_loc){
}

void InterfaceGlOuter::DeleteProgram(GLuint program, GLsrc src_loc){
}

void InterfaceGlOuter::DeleteProgramPipelines(GLsizei n, GLuintArr pipelines, GLsrc src_loc){
}

void InterfaceGlOuter::DeleteQueries(GLsizei n, GLuintArr ids, GLsrc src_loc){
}

void InterfaceGlOuter::DeleteRenderbuffers(GLsizei n, GLuintArr renderbuffers, GLsrc src_loc){
}

void InterfaceGlOuter::DeleteSamplers(GLsizei count, GLuintArr samplers, GLsrc src_loc){
}

void InterfaceGlOuter::DeleteShader(GLuint shader, GLsrc src_loc){
}

void InterfaceGlOuter::DeleteSync(GLsync sync, GLsrc src_loc){
}

void InterfaceGlOuter::DeleteTextures(GLsizei n, GLuintArr textures, GLsrc src_loc){
}

void InterfaceGlOuter::DeleteTransformFeedbacks(GLsizei n, GLuintArr ids, GLsrc src_loc){
}

void InterfaceGlOuter::DeleteVertexArrays(GLsizei n, GLuintArr arrays, GLsrc src_loc){
}

void InterfaceGlOuter::DepthFunc(GLenum func, GLsrc src_loc){
}

void InterfaceGlOuter::DepthMask(GLboolean flag, GLsrc src_loc){
}

void InterfaceGlOuter::DepthRange(GLdouble n, GLdouble f, GLsrc src_loc){
}

void InterfaceGlOuter::DepthRangeArrayv(GLuint first, GLsizei count, GLdoubleArr v, GLsrc src_loc){
}

void InterfaceGlOuter::DepthRangeIndexed(GLuint index, GLdouble n, GLdouble f, GLsrc src_loc){
}

void InterfaceGlOuter::DepthRangef(GLfloat n, GLfloat f, GLsrc src_loc){
}

void InterfaceGlOuter::DetachShader(GLuint program, GLuint shader, GLsrc src_loc){
}

void InterfaceGlOuter::Disable(GLenum cap, GLsrc src_loc){
}

void InterfaceGlOuter::DisableVertexArrayAttrib(GLuint vaobj, GLuint index, GLsrc src_loc){
}

void InterfaceGlOuter::DisableVertexAttribArray(GLuint index, GLsrc src_loc){
}

void InterfaceGlOuter::Disablei(GLenum target, GLuint index, GLsrc src_loc){
}

void InterfaceGlOuter::DispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLsrc src_loc){
}

void InterfaceGlOuter::DispatchComputeIndirect(GLintptr indirect, GLsrc src_loc){
}

void InterfaceGlOuter::DrawArrays(GLenum mode, GLint first, GLsizei count, GLsrc src_loc){
}

void InterfaceGlOuter::DrawArraysIndirect(GLenum mode, GLdata indirect, GLsrc src_loc){
}

void InterfaceGlOuter::DrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLsrc src_loc){
}

void InterfaceGlOuter::DrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance, GLsrc src_loc){
}

void InterfaceGlOuter::DrawBuffer(GLenum buf, GLsrc src_loc){
}

void InterfaceGlOuter::DrawBuffers(GLsizei n, GLenumArr bufs, GLsrc src_loc){
}

void InterfaceGlOuter::DrawElements(GLenum mode, GLsizei count, GLenum type, GLdata indices, GLsrc src_loc){
}

void InterfaceGlOuter::DrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLdata indices, GLint basevertex, GLsrc src_loc){
}

void InterfaceGlOuter::DrawElementsIndirect(GLenum mode, GLenum type, GLdata indirect, GLsrc src_loc){
}

void InterfaceGlOuter::DrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, GLdata indices, GLsizei instancecount, GLsrc src_loc){
}

void InterfaceGlOuter::DrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, GLdata indices, GLsizei instancecount, GLuint baseinstance, GLsrc src_loc){
}

void InterfaceGlOuter::DrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, GLdata indices, GLsizei instancecount, GLint basevertex, GLsrc src_loc){
}

void InterfaceGlOuter::DrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, GLdata indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance, GLsrc src_loc){
}

void InterfaceGlOuter::DrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLdata indices, GLsrc src_loc){
}

void InterfaceGlOuter::DrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLdata indices, GLint basevertex, GLsrc src_loc){
}

void InterfaceGlOuter::DrawTransformFeedback(GLenum mode, GLuint id, GLsrc src_loc){
}

void InterfaceGlOuter::DrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount, GLsrc src_loc){
}

void InterfaceGlOuter::DrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream, GLsrc src_loc){
}

void InterfaceGlOuter::DrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount, GLsrc src_loc){
}

void InterfaceGlOuter::Enable(GLenum cap, GLsrc src_loc){
}

void InterfaceGlOuter::EnableVertexArrayAttrib(GLuint vaobj, GLuint index, GLsrc src_loc){
}

void InterfaceGlOuter::EnableVertexAttribArray(GLuint index, GLsrc src_loc){
}

void InterfaceGlOuter::Enablei(GLenum target, GLuint index, GLsrc src_loc){
}

void InterfaceGlOuter::EndConditionalRender(GLsrc src_loc){
}

void InterfaceGlOuter::EndQuery(GLenum target, GLsrc src_loc){
}

void InterfaceGlOuter::EndQueryIndexed(GLenum target, GLuint index, GLsrc src_loc){
}

void InterfaceGlOuter::EndTransformFeedback(GLsrc src_loc){
}

InterfaceGlOuter::GLsyncRes InterfaceGlOuter::FenceSync(GLenum condition, GLbitfield flags, GLsrc src_loc){
}

void InterfaceGlOuter::Finish(GLsrc src_loc){
}

void InterfaceGlOuter::Flush(GLsrc src_loc){
}

void InterfaceGlOuter::FlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLsrc src_loc){
}

void InterfaceGlOuter::FlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLsrc src_loc){
}

void InterfaceGlOuter::FramebufferParameteri(GLenum target, GLenum pname, GLint param, GLsrc src_loc){
}

void InterfaceGlOuter::FramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer, GLsrc src_loc){
}

void InterfaceGlOuter::FramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level, GLsrc src_loc){
}

void InterfaceGlOuter::FramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLsrc src_loc){
}

void InterfaceGlOuter::FramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLsrc src_loc){
}

void InterfaceGlOuter::FramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset, GLsrc src_loc){
}

void InterfaceGlOuter::FramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer, GLsrc src_loc){
}

void InterfaceGlOuter::FrontFace(GLenum mode, GLsrc src_loc){
}

void InterfaceGlOuter::GenBuffers(GLsizei n, GLuintArr buffers, GLsrc src_loc){
}

void InterfaceGlOuter::GenFramebuffers(GLsizei n, GLuintArr framebuffers, GLsrc src_loc){
}

void InterfaceGlOuter::GenProgramPipelines(GLsizei n, GLuintArr pipelines, GLsrc src_loc){
}

void InterfaceGlOuter::GenQueries(GLsizei n, GLuintArr ids, GLsrc src_loc){
}

void InterfaceGlOuter::GenRenderbuffers(GLsizei n, GLuintArr renderbuffers, GLsrc src_loc){
}

void InterfaceGlOuter::GenSamplers(GLsizei count, GLuintArr samplers, GLsrc src_loc){
}

void InterfaceGlOuter::GenTextures(GLsizei n, GLuintArr textures, GLsrc src_loc){
}

void InterfaceGlOuter::GenTransformFeedbacks(GLsizei n, GLuintArr ids, GLsrc src_loc){
}

void InterfaceGlOuter::GenVertexArrays(GLsizei n, GLuintArr arrays, GLsrc src_loc){
}

void InterfaceGlOuter::GenerateMipmap(GLenum target, GLsrc src_loc){
}

void InterfaceGlOuter::GenerateTextureMipmap(GLuint texture, GLsrc src_loc){
}

void InterfaceGlOuter::GetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLint size, GLenum type, GLcharArr name, GLsrc src_loc){
}

void InterfaceGlOuter::GetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei length, GLcharArr name, GLsrc src_loc){
}

void InterfaceGlOuter::GetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei length, GLcharArr name, GLsrc src_loc){
}

void InterfaceGlOuter::GetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLintArr values, GLsrc src_loc){
}

void InterfaceGlOuter::GetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLint size, GLenum type, GLcharArr name, GLsrc src_loc){
}

void InterfaceGlOuter::GetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei length, GLcharArr uniformBlockName, GLsrc src_loc){
}

void InterfaceGlOuter::GetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei length, GLcharArr uniformName, GLsrc src_loc){
}

void InterfaceGlOuter::GetActiveUniformsiv(GLuint program, GLsizei uniformCount, GLuintArr uniformIndices, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetAttachedShaders(GLuint program, GLsizei maxCount, GLsizeiArr count, GLuintArr shaders, GLsrc src_loc){
}

InterfaceGlOuter::GLintRes InterfaceGlOuter::GetAttribLocation(GLuint program, GLcharArr name, GLsrc src_loc){
}

void InterfaceGlOuter::GetBooleani_v(GLenum target, GLuint index, GLbooleanArr data, GLsrc src_loc){
}

void InterfaceGlOuter::GetBooleanv(GLenum pname, GLbooleanArr data, GLsrc src_loc){
}

void InterfaceGlOuter::GetBufferParameteri64v(GLenum target, GLenum pname, GLint64Arr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetBufferParameteriv(GLenum target, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetBufferPointerv(GLenum target, GLenum pname, GLdataPtr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::GetCompressedTexImage(GLenum target, GLint level, GLdata img, GLsrc src_loc){
}

void InterfaceGlOuter::GetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, GLdata pixels, GLsrc src_loc){
}

void InterfaceGlOuter::GetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, GLdata pixels, GLsrc src_loc){
}

InterfaceGlOuter::GLuintRes InterfaceGlOuter::GetDebugMessageLog(GLuint count, GLsizei bufSize, GLenumArr sources, GLenumArr types, GLuintArr ids, GLenumArr severities, GLsizei lengths, GLcharArr messageLog, GLsrc src_loc){
}

void InterfaceGlOuter::GetDoublei_v(GLenum target, GLuint index, GLdoubleArr data, GLsrc src_loc){
}

void InterfaceGlOuter::GetDoublev(GLenum pname, GLdoubleArr data, GLsrc src_loc){
}

InterfaceGlOuter::GLenumRes InterfaceGlOuter::GetError(GLsrc src_loc){
}

void InterfaceGlOuter::GetFloati_v(GLenum target, GLuint index, GLfloatArr data, GLsrc src_loc){
}

void InterfaceGlOuter::GetFloatv(GLenum pname, GLfloatArr data, GLsrc src_loc){
}

InterfaceGlOuter::GLintRes InterfaceGlOuter::GetFragDataIndex(GLuint program, GLcharArr name, GLsrc src_loc){
}

InterfaceGlOuter::GLintRes InterfaceGlOuter::GetFragDataLocation(GLuint program, GLcharArr name, GLsrc src_loc){
}

void InterfaceGlOuter::GetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetFramebufferParameteriv(GLenum target, GLenum pname, GLintArr params, GLsrc src_loc){
}

InterfaceGlOuter::GLenumRes InterfaceGlOuter::GetGraphicsResetStatus(GLsrc src_loc){
}

void InterfaceGlOuter::GetInteger64i_v(GLenum target, GLuint index, GLint64Arr data, GLsrc src_loc){
}

void InterfaceGlOuter::GetInteger64v(GLenum pname, GLint64Arr data, GLsrc src_loc){
}

void InterfaceGlOuter::GetIntegeri_v(GLenum target, GLuint index, GLintArr data, GLsrc src_loc){
}

void InterfaceGlOuter::GetIntegerv(GLenum pname, GLintArr data, GLsrc src_loc){
}

void InterfaceGlOuter::GetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64Arr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetMultisamplefv(GLenum pname, GLuint index, GLfloatArr val, GLsrc src_loc){
}

void InterfaceGlOuter::GetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64Arr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetNamedBufferPointerv(GLuint buffer, GLenum pname, GLdataPtr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::GetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLintArr param, GLsrc src_loc){
}

void InterfaceGlOuter::GetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei length, GLcharArr label, GLsrc src_loc){
}

void InterfaceGlOuter::GetObjectPtrLabel(GLdata ptr, GLsizei bufSize, GLsizei length, GLcharArr label, GLsrc src_loc){
}

void InterfaceGlOuter::GetPointerv(GLenum pname, GLdataPtr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetProgramBinary(GLuint program, GLsizei bufSize, GLsizei length, GLenumArr binaryFormat, GLdata binary, GLsrc src_loc){
}

void InterfaceGlOuter::GetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei length, GLcharArr infoLog, GLsrc src_loc){
}

void InterfaceGlOuter::GetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei length, GLcharArr infoLog, GLsrc src_loc){
}

void InterfaceGlOuter::GetProgramPipelineiv(GLuint pipeline, GLenum pname, GLintArr params, GLsrc src_loc){
}

InterfaceGlOuter::GLuintRes InterfaceGlOuter::GetProgramResourceIndex(GLuint program, GLenum programInterface, GLcharArr name, GLsrc src_loc){
}

InterfaceGlOuter::GLintRes InterfaceGlOuter::GetProgramResourceLocation(GLuint program, GLenum programInterface, GLcharArr name, GLsrc src_loc){
}

InterfaceGlOuter::GLintRes InterfaceGlOuter::GetProgramResourceLocationIndex(GLuint program, GLenum programInterface, GLcharArr name, GLsrc src_loc){
}

void InterfaceGlOuter::GetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei length, GLcharArr name, GLsrc src_loc){
}

void InterfaceGlOuter::GetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, GLenumArr props, GLsizei count, GLsizei length, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLintArr values, GLsrc src_loc){
}

void InterfaceGlOuter::GetProgramiv(GLuint program, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, GLsrc src_loc){
}

void InterfaceGlOuter::GetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, GLsrc src_loc){
}

void InterfaceGlOuter::GetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, GLsrc src_loc){
}

void InterfaceGlOuter::GetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset, GLsrc src_loc){
}

void InterfaceGlOuter::GetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetQueryObjecti64v(GLuint id, GLenum pname, GLint64Arr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetQueryObjectiv(GLuint id, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetQueryObjectui64v(GLuint id, GLenum pname, GLuint64Arr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetQueryObjectuiv(GLuint id, GLenum pname, GLuintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetQueryiv(GLenum target, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetRenderbufferParameteriv(GLenum target, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetSamplerParameterIiv(GLuint sampler, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloatArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetSamplerParameteriv(GLuint sampler, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei length, GLcharArr infoLog, GLsrc src_loc){
}

void InterfaceGlOuter::GetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLintArr range, GLintArr precision, GLsrc src_loc){
}

void InterfaceGlOuter::GetShaderSource(GLuint shader, GLsizei bufSize, GLsizei length, GLcharArr source, GLsrc src_loc){
}

void InterfaceGlOuter::GetShaderiv(GLuint shader, GLenum pname, GLintArr params, GLsrc src_loc){
}

InterfaceGlOuter::GLubyteArrRes InterfaceGlOuter::GetString(GLenum name, GLsrc src_loc){
}

InterfaceGlOuter::GLubyteArrRes InterfaceGlOuter::GetStringi(GLenum name, GLuint index, GLsrc src_loc){
}

InterfaceGlOuter::GLuintRes InterfaceGlOuter::GetSubroutineIndex(GLuint program, GLenum shadertype, GLcharArr name, GLsrc src_loc){
}

InterfaceGlOuter::GLintRes InterfaceGlOuter::GetSubroutineUniformLocation(GLuint program, GLenum shadertype, GLcharArr name, GLsrc src_loc){
}

void InterfaceGlOuter::GetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei length, GLintArr values, GLsrc src_loc){
}

void InterfaceGlOuter::GetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLdata pixels, GLsrc src_loc){
}

void InterfaceGlOuter::GetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloatArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetTexParameterIiv(GLenum target, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetTexParameterIuiv(GLenum target, GLenum pname, GLuintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetTexParameterfv(GLenum target, GLenum pname, GLfloatArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetTexParameteriv(GLenum target, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLdata pixels, GLsrc src_loc){
}

void InterfaceGlOuter::GetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloatArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetTextureParameterIiv(GLuint texture, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetTextureParameterIuiv(GLuint texture, GLenum pname, GLuintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetTextureParameterfv(GLuint texture, GLenum pname, GLfloatArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetTextureParameteriv(GLuint texture, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, GLdata pixels, GLsrc src_loc){
}

void InterfaceGlOuter::GetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLsizeiArr size, GLenumArr type, GLcharArr name, GLsrc src_loc){
}

void InterfaceGlOuter::GetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64Arr param, GLsrc src_loc){
}

void InterfaceGlOuter::GetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLintArr param, GLsrc src_loc){
}

void InterfaceGlOuter::GetTransformFeedbackiv(GLuint xfb, GLenum pname, GLintArr param, GLsrc src_loc){
}

InterfaceGlOuter::GLuintRes InterfaceGlOuter::GetUniformBlockIndex(GLuint program, GLcharArr uniformBlockName, GLsrc src_loc){
}

InterfaceGlOuter::GLintRes InterfaceGlOuter::GetUniformLocation(GLuint program, GLcharArr name, GLsrc src_loc){
}

void InterfaceGlOuter::GetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetUniformdv(GLuint program, GLint location, GLdoubleArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetUniformfv(GLuint program, GLint location, GLfloatArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetUniformiv(GLuint program, GLint location, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetUniformuiv(GLuint program, GLint location, GLuintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64Arr param, GLsrc src_loc){
}

void InterfaceGlOuter::GetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLintArr param, GLsrc src_loc){
}

void InterfaceGlOuter::GetVertexArrayiv(GLuint vaobj, GLenum pname, GLintArr param, GLsrc src_loc){
}

void InterfaceGlOuter::GetVertexAttribIiv(GLuint index, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetVertexAttribIuiv(GLuint index, GLenum pname, GLuintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetVertexAttribLdv(GLuint index, GLenum pname, GLdoubleArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetVertexAttribPointerv(GLuint index, GLenum pname, GLdataPtr pointer, GLsrc src_loc){
}

void InterfaceGlOuter::GetVertexAttribdv(GLuint index, GLenum pname, GLdoubleArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetVertexAttribfv(GLuint index, GLenum pname, GLfloatArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetVertexAttribiv(GLuint index, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, GLdata pixels, GLsrc src_loc){
}

void InterfaceGlOuter::GetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLdata pixels, GLsrc src_loc){
}

void InterfaceGlOuter::GetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdoubleArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloatArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::GetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::Hint(GLenum target, GLenum mode, GLsrc src_loc){
}

void InterfaceGlOuter::InvalidateBufferData(GLuint buffer, GLsrc src_loc){
}

void InterfaceGlOuter::InvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length, GLsrc src_loc){
}

void InterfaceGlOuter::InvalidateFramebuffer(GLenum target, GLsizei numAttachments, GLenumArr attachments, GLsrc src_loc){
}

void InterfaceGlOuter::InvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, GLenumArr attachments, GLsrc src_loc){
}

void InterfaceGlOuter::InvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, GLenumArr attachments, GLint x, GLint y, GLsizei width, GLsizei height, GLsrc src_loc){
}

void InterfaceGlOuter::InvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, GLenumArr attachments, GLint x, GLint y, GLsizei width, GLsizei height, GLsrc src_loc){
}

void InterfaceGlOuter::InvalidateTexImage(GLuint texture, GLint level, GLsrc src_loc){
}

void InterfaceGlOuter::InvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsrc src_loc){
}

InterfaceGlOuter::GLbooleanRes InterfaceGlOuter::IsBuffer(GLuint buffer, GLsrc src_loc){
}

InterfaceGlOuter::GLbooleanRes InterfaceGlOuter::IsEnabled(GLenum cap, GLsrc src_loc){
}

InterfaceGlOuter::GLbooleanRes InterfaceGlOuter::IsEnabledi(GLenum target, GLuint index, GLsrc src_loc){
}

InterfaceGlOuter::GLbooleanRes InterfaceGlOuter::IsFramebuffer(GLuint framebuffer, GLsrc src_loc){
}

InterfaceGlOuter::GLbooleanRes InterfaceGlOuter::IsProgram(GLuint program, GLsrc src_loc){
}

InterfaceGlOuter::GLbooleanRes InterfaceGlOuter::IsProgramPipeline(GLuint pipeline, GLsrc src_loc){
}

InterfaceGlOuter::GLbooleanRes InterfaceGlOuter::IsQuery(GLuint id, GLsrc src_loc){
}

InterfaceGlOuter::GLbooleanRes InterfaceGlOuter::IsRenderbuffer(GLuint renderbuffer, GLsrc src_loc){
}

InterfaceGlOuter::GLbooleanRes InterfaceGlOuter::IsSampler(GLuint sampler, GLsrc src_loc){
}

InterfaceGlOuter::GLbooleanRes InterfaceGlOuter::IsShader(GLuint shader, GLsrc src_loc){
}

InterfaceGlOuter::GLbooleanRes InterfaceGlOuter::IsSync(GLsync sync, GLsrc src_loc){
}

InterfaceGlOuter::GLbooleanRes InterfaceGlOuter::IsTexture(GLuint texture, GLsrc src_loc){
}

InterfaceGlOuter::GLbooleanRes InterfaceGlOuter::IsTransformFeedback(GLuint id, GLsrc src_loc){
}

InterfaceGlOuter::GLbooleanRes InterfaceGlOuter::IsVertexArray(GLuint array, GLsrc src_loc){
}

void InterfaceGlOuter::LineWidth(GLfloat width, GLsrc src_loc){
}

void InterfaceGlOuter::LinkProgram(GLuint program, GLsrc src_loc){
}

void InterfaceGlOuter::LogicOp(GLenum opcode, GLsrc src_loc){
}

void InterfaceGlOuter::MemoryBarrier(GLbitfield barriers, GLsrc src_loc){
}

void InterfaceGlOuter::MemoryBarrierByRegion(GLbitfield barriers, GLsrc src_loc){
}

void InterfaceGlOuter::MinSampleShading(GLfloat value, GLsrc src_loc){
}

void InterfaceGlOuter::MultiDrawArrays(GLenum mode, GLintArr first, GLsizeiArr count, GLsizei drawcount, GLsrc src_loc){
}

void InterfaceGlOuter::MultiDrawArraysIndirect(GLenum mode, const GLdata indirect, GLsizei drawcount, GLsizei stride, GLsrc src_loc){
}

void InterfaceGlOuter::MultiDrawArraysIndirectCount(GLenum mode, const GLdata indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride, GLsrc src_loc){
}

void InterfaceGlOuter::MultiDrawElements(GLenum mode, GLsizeiArr count, GLenum type, GLdataPtr indices, GLsizei drawcount, GLsrc src_loc){
}

void InterfaceGlOuter::MultiDrawElementsBaseVertex(GLenum mode, GLsizeiArr count, GLenum type, GLdataPtr indices, GLsizei drawcount, GLintArr basevertex, GLsrc src_loc){
}

void InterfaceGlOuter::MultiDrawElementsIndirect(GLenum mode, GLenum type, const GLdata indirect, GLsizei drawcount, GLsizei stride, GLsrc src_loc){
}

void InterfaceGlOuter::MultiDrawElementsIndirectCount(GLenum mode, GLenum type, const GLdata indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride, GLsrc src_loc){
}

void InterfaceGlOuter::NamedBufferData(GLuint buffer, GLsizeiptr size, const GLdata data, GLenum usage, GLsrc src_loc){
}

void InterfaceGlOuter::NamedBufferStorage(GLuint buffer, GLsizeiptr size, const GLdata data, GLbitfield flags, GLsrc src_loc){
}

void InterfaceGlOuter::NamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::NamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf, GLsrc src_loc){
}

void InterfaceGlOuter::NamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, GLenumArr bufs, GLsrc src_loc){
}

void InterfaceGlOuter::NamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param, GLsrc src_loc){
}

void InterfaceGlOuter::NamedFramebufferReadBuffer(GLuint framebuffer, GLenum src, GLsrc src_loc){
}

void InterfaceGlOuter::NamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer, GLsrc src_loc){
}

void InterfaceGlOuter::NamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLsrc src_loc){
}

void InterfaceGlOuter::NamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer, GLsrc src_loc){
}

void InterfaceGlOuter::NamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height, GLsrc src_loc){
}

void InterfaceGlOuter::NamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsrc src_loc){
}

void InterfaceGlOuter::ObjectLabel(GLenum identifier, GLuint name, GLsizei length, GLcharArr label, GLsrc src_loc){
}

void InterfaceGlOuter::ObjectPtrLabel(const GLdata ptr, GLsizei length, GLcharArr label, GLsrc src_loc){
}

void InterfaceGlOuter::PatchParameterfv(GLenum pname, GLfloatArr values, GLsrc src_loc){
}

void InterfaceGlOuter::PatchParameteri(GLenum pname, GLint value, GLsrc src_loc){
}

void InterfaceGlOuter::PauseTransformFeedback(GLsrc src_loc){
}

void InterfaceGlOuter::PixelStoref(GLenum pname, GLfloat param, GLsrc src_loc){
}

void InterfaceGlOuter::PixelStorei(GLenum pname, GLint param, GLsrc src_loc){
}

void InterfaceGlOuter::PointParameterf(GLenum pname, GLfloat param, GLsrc src_loc){
}

void InterfaceGlOuter::PointParameterfv(GLenum pname, GLfloatArr params, GLsrc src_loc){
}

void InterfaceGlOuter::PointParameteri(GLenum pname, GLint param, GLsrc src_loc){
}

void InterfaceGlOuter::PointParameteriv(GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::PointSize(GLfloat size, GLsrc src_loc){
}

void InterfaceGlOuter::PolygonMode(GLenum face, GLenum mode, GLsrc src_loc){
}

void InterfaceGlOuter::PolygonOffset(GLfloat factor, GLfloat units, GLsrc src_loc){
}

void InterfaceGlOuter::PolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp, GLsrc src_loc){
}

void InterfaceGlOuter::PopDebugGroup(GLsrc src_loc){
}

void InterfaceGlOuter::PrimitiveRestartIndex(GLuint index, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramBinary(GLuint program, GLenum binaryFormat, const GLdata binary, GLsizei length, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramParameteri(GLuint program, GLenum pname, GLint value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform1d(GLuint program, GLint location, GLdouble v0, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform1dv(GLuint program, GLint location, GLsizei count, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform1f(GLuint program, GLint location, GLfloat v0, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform1fv(GLuint program, GLint location, GLsizei count, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform1i(GLuint program, GLint location, GLint v0, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform1iv(GLuint program, GLint location, GLsizei count, GLintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform1ui(GLuint program, GLint location, GLuint v0, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform1uiv(GLuint program, GLint location, GLsizei count, GLuintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform2dv(GLuint program, GLint location, GLsizei count, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform2fv(GLuint program, GLint location, GLsizei count, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform2iv(GLuint program, GLint location, GLsizei count, GLintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform2uiv(GLuint program, GLint location, GLsizei count, GLuintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform3dv(GLuint program, GLint location, GLsizei count, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform3fv(GLuint program, GLint location, GLsizei count, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform3iv(GLuint program, GLint location, GLsizei count, GLintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform3uiv(GLuint program, GLint location, GLsizei count, GLuintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform4dv(GLuint program, GLint location, GLsizei count, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform4fv(GLuint program, GLint location, GLsizei count, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform4iv(GLuint program, GLint location, GLsizei count, GLintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniform4uiv(GLuint program, GLint location, GLsizei count, GLuintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::ProvokingVertex(GLenum mode, GLsrc src_loc){
}

void InterfaceGlOuter::PushDebugGroup(GLenum source, GLuint id, GLsizei length, GLcharArr message, GLsrc src_loc){
}

void InterfaceGlOuter::QueryCounter(GLuint id, GLenum target, GLsrc src_loc){
}

void InterfaceGlOuter::ReadBuffer(GLenum src, GLsrc src_loc){
}

void InterfaceGlOuter::ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLdata pixels, GLsrc src_loc){
}

void InterfaceGlOuter::ReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLdata data, GLsrc src_loc){
}

void InterfaceGlOuter::ReleaseShaderCompiler(GLsrc src_loc){
}

void InterfaceGlOuter::RenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLsrc src_loc){
}

void InterfaceGlOuter::RenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsrc src_loc){
}

void InterfaceGlOuter::ResumeTransformFeedback(GLsrc src_loc){
}

void InterfaceGlOuter::SampleCoverage(GLfloat value, GLboolean invert, GLsrc src_loc){
}

void InterfaceGlOuter::SampleMaski(GLuint maskNumber, GLbitfield mask, GLsrc src_loc){
}

void InterfaceGlOuter::SamplerParameterIiv(GLuint sampler, GLenum pname, GLintArr param, GLsrc src_loc){
}

void InterfaceGlOuter::SamplerParameterIuiv(GLuint sampler, GLenum pname, GLuintArr param, GLsrc src_loc){
}

void InterfaceGlOuter::SamplerParameterf(GLuint sampler, GLenum pname, GLfloat param, GLsrc src_loc){
}

void InterfaceGlOuter::SamplerParameterfv(GLuint sampler, GLenum pname, GLfloatArr param, GLsrc src_loc){
}

void InterfaceGlOuter::SamplerParameteri(GLuint sampler, GLenum pname, GLint param, GLsrc src_loc){
}

void InterfaceGlOuter::SamplerParameteriv(GLuint sampler, GLenum pname, GLintArr param, GLsrc src_loc){
}

void InterfaceGlOuter::Scissor(GLint x, GLint y, GLsizei width, GLsizei height, GLsrc src_loc){
}

void InterfaceGlOuter::ScissorArrayv(GLuint first, GLsizei count, GLintArr v, GLsrc src_loc){
}

void InterfaceGlOuter::ScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height, GLsrc src_loc){
}

void InterfaceGlOuter::ScissorIndexedv(GLuint index, GLintArr v, GLsrc src_loc){
}

void InterfaceGlOuter::ShaderBinary(GLsizei count, GLuintArr shaders, GLenum binaryFormat, const GLdata binary, GLsizei length, GLsrc src_loc){
}

void InterfaceGlOuter::ShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding, GLsrc src_loc){
}

void InterfaceGlOuter::SpecializeShader(GLuint shader, GLcharArr pEntryPoint, GLuint numSpecializationConstants, GLuintArr pConstantIndex, GLuintArr pConstantValue, GLsrc src_loc){
}

void InterfaceGlOuter::StencilFunc(GLenum func, GLint ref, GLuint mask, GLsrc src_loc){
}

void InterfaceGlOuter::StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask, GLsrc src_loc){
}

void InterfaceGlOuter::StencilMask(GLuint mask, GLsrc src_loc){
}

void InterfaceGlOuter::StencilMaskSeparate(GLenum face, GLuint mask, GLsrc src_loc){
}

void InterfaceGlOuter::StencilOp(GLenum fail, GLenum zfail, GLenum zpass, GLsrc src_loc){
}

void InterfaceGlOuter::StencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass, GLsrc src_loc){
}

void InterfaceGlOuter::TexBuffer(GLenum target, GLenum internalformat, GLuint buffer, GLsrc src_loc){
}

void InterfaceGlOuter::TexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size, GLsrc src_loc){
}

void InterfaceGlOuter::TexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
}

void InterfaceGlOuter::TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
}

void InterfaceGlOuter::TexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, GLsrc src_loc){
}

void InterfaceGlOuter::TexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
}

void InterfaceGlOuter::TexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, GLsrc src_loc){
}

void InterfaceGlOuter::TexParameterIiv(GLenum target, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::TexParameterIuiv(GLenum target, GLenum pname, GLuintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::TexParameterf(GLenum target, GLenum pname, GLfloat param, GLsrc src_loc){
}

void InterfaceGlOuter::TexParameterfv(GLenum target, GLenum pname, GLfloatArr params, GLsrc src_loc){
}

void InterfaceGlOuter::TexParameteri(GLenum target, GLenum pname, GLint param, GLsrc src_loc){
}

void InterfaceGlOuter::TexParameteriv(GLenum target, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::TexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsrc src_loc){
}

void InterfaceGlOuter::TexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsrc src_loc){
}

void InterfaceGlOuter::TexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, GLsrc src_loc){
}

void InterfaceGlOuter::TexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsrc src_loc){
}

void InterfaceGlOuter::TexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, GLsrc src_loc){
}

void InterfaceGlOuter::TexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
}

void InterfaceGlOuter::TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
}

void InterfaceGlOuter::TexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
}

void InterfaceGlOuter::TextureBarrier(GLsrc src_loc){
}

void InterfaceGlOuter::TextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer, GLsrc src_loc){
}

void InterfaceGlOuter::TextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size, GLsrc src_loc){
}

void InterfaceGlOuter::TextureParameterIiv(GLuint texture, GLenum pname, GLintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::TextureParameterIuiv(GLuint texture, GLenum pname, GLuintArr params, GLsrc src_loc){
}

void InterfaceGlOuter::TextureParameterf(GLuint texture, GLenum pname, GLfloat param, GLsrc src_loc){
}

void InterfaceGlOuter::TextureParameterfv(GLuint texture, GLenum pname, GLfloatArr param, GLsrc src_loc){
}

void InterfaceGlOuter::TextureParameteri(GLuint texture, GLenum pname, GLint param, GLsrc src_loc){
}

void InterfaceGlOuter::TextureParameteriv(GLuint texture, GLenum pname, GLintArr param, GLsrc src_loc){
}

void InterfaceGlOuter::TextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsrc src_loc){
}

void InterfaceGlOuter::TextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsrc src_loc){
}

void InterfaceGlOuter::TextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations, GLsrc src_loc){
}

void InterfaceGlOuter::TextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsrc src_loc){
}

void InterfaceGlOuter::TextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations, GLsrc src_loc){
}

void InterfaceGlOuter::TextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
}

void InterfaceGlOuter::TextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
}

void InterfaceGlOuter::TextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLdata pixels, GLsrc src_loc){
}

void InterfaceGlOuter::TextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers, GLsrc src_loc){
}

void InterfaceGlOuter::TransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer, GLsrc src_loc){
}

void InterfaceGlOuter::TransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform1d(GLint location, GLdouble x, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform1dv(GLint location, GLsizei count, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform1f(GLint location, GLfloat v0, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform1fv(GLint location, GLsizei count, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform1i(GLint location, GLint v0, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform1iv(GLint location, GLsizei count, GLintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform1ui(GLint location, GLuint v0, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform1uiv(GLint location, GLsizei count, GLuintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform2d(GLint location, GLdouble x, GLdouble y, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform2dv(GLint location, GLsizei count, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform2f(GLint location, GLfloat v0, GLfloat v1, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform2fv(GLint location, GLsizei count, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform2i(GLint location, GLint v0, GLint v1, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform2iv(GLint location, GLsizei count, GLintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform2ui(GLint location, GLuint v0, GLuint v1, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform2uiv(GLint location, GLsizei count, GLuintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform3dv(GLint location, GLsizei count, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform3fv(GLint location, GLsizei count, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform3i(GLint location, GLint v0, GLint v1, GLint v2, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform3iv(GLint location, GLsizei count, GLintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform3uiv(GLint location, GLsizei count, GLuintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform4dv(GLint location, GLsizei count, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform4fv(GLint location, GLsizei count, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform4iv(GLint location, GLsizei count, GLintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3, GLsrc src_loc){
}

void InterfaceGlOuter::Uniform4uiv(GLint location, GLsizei count, GLuintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, GLdoubleArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloatArr value, GLsrc src_loc){
}

void InterfaceGlOuter::UniformSubroutinesuiv(GLenum shadertype, GLsizei count, GLuintArr indices, GLsrc src_loc){
}

InterfaceGlOuter::GLbooleanRes InterfaceGlOuter::UnmapBuffer(GLenum target, GLsrc src_loc){
}

InterfaceGlOuter::GLbooleanRes InterfaceGlOuter::UnmapNamedBuffer(GLuint buffer, GLsrc src_loc){
}

void InterfaceGlOuter::UseProgram(GLuint program, GLsrc src_loc){
}

void InterfaceGlOuter::UseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program, GLsrc src_loc){
}

void InterfaceGlOuter::ValidateProgram(GLuint program, GLsrc src_loc){
}

void InterfaceGlOuter::ValidateProgramPipeline(GLuint pipeline, GLsrc src_loc){
}

void InterfaceGlOuter::VertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex, GLsrc src_loc){
}

void InterfaceGlOuter::VertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset, GLsrc src_loc){
}

void InterfaceGlOuter::VertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, GLsrc src_loc){
}

void InterfaceGlOuter::VertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, GLsrc src_loc){
}

void InterfaceGlOuter::VertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor, GLsrc src_loc){
}

void InterfaceGlOuter::VertexArrayElementBuffer(GLuint vaobj, GLuint buffer, GLsrc src_loc){
}

void InterfaceGlOuter::VertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride, GLsrc src_loc){
}

void InterfaceGlOuter::VertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, GLuintArr buffers, GLintptrArr offsets, GLsizeiArr strides, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib1d(GLuint index, GLdouble x, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib1dv(GLuint index, GLdoubleArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib1f(GLuint index, GLfloat x, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib1fv(GLuint index, GLfloatArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib1s(GLuint index, GLshort x, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib1sv(GLuint index, GLshort v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib2d(GLuint index, GLdouble x, GLdouble y, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib2dv(GLuint index, GLdoubleArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib2f(GLuint index, GLfloat x, GLfloat y, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib2fv(GLuint index, GLfloatArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib2s(GLuint index, GLshort x, GLshort y, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib2sv(GLuint index, GLshort v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib3dv(GLuint index, GLdoubleArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib3fv(GLuint index, GLfloatArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib3sv(GLuint index, GLshort v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4Nbv(GLuint index, GLbyte v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4Niv(GLuint index, GLintArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4Nsv(GLuint index, GLshort v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4Nubv(GLuint index, GLubyte v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4Nuiv(GLuint index, GLuintArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4Nusv(GLuint index, GLushort v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4bv(GLuint index, GLbyte v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4dv(GLuint index, GLdoubleArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4fv(GLuint index, GLfloatArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4iv(GLuint index, GLintArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4sv(GLuint index, GLshort v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4ubv(GLuint index, GLubyte v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4uiv(GLuint index, GLuintArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttrib4usv(GLuint index, GLushort v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribBinding(GLuint attribindex, GLuint bindingindex, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribDivisor(GLuint index, GLuint divisor, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI1i(GLuint index, GLint x, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI1iv(GLuint index, GLintArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI1ui(GLuint index, GLuint x, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI1uiv(GLuint index, GLuintArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI2i(GLuint index, GLint x, GLint y, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI2iv(GLuint index, GLintArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI2ui(GLuint index, GLuint x, GLuint y, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI2uiv(GLuint index, GLuintArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI3i(GLuint index, GLint x, GLint y, GLint z, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI3iv(GLuint index, GLintArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI3uiv(GLuint index, GLuintArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI4bv(GLuint index, GLbyte v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI4iv(GLuint index, GLintArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI4sv(GLuint index, GLshort v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI4ubv(GLuint index, GLubyte v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI4uiv(GLuint index, GLuintArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribI4usv(GLuint index, GLushort v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLdata pointer, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribL1d(GLuint index, GLdouble x, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribL1dv(GLuint index, GLdoubleArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribL2d(GLuint index, GLdouble x, GLdouble y, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribL2dv(GLuint index, GLdoubleArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribL3dv(GLuint index, GLdoubleArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribL4dv(GLuint index, GLdoubleArr v, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLdata pointer, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, GLuintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, GLuintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, GLuintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, GLuintArr value, GLsrc src_loc){
}

void InterfaceGlOuter::VertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLdata pointer, GLsrc src_loc){
}

void InterfaceGlOuter::VertexBindingDivisor(GLuint bindingindex, GLuint divisor, GLsrc src_loc){
}

void InterfaceGlOuter::Viewport(GLint x, GLint y, GLsizei width, GLsizei height, GLsrc src_loc){
}

void InterfaceGlOuter::ViewportArrayv(GLuint first, GLsizei count, GLfloatArr v, GLsrc src_loc){
}

void InterfaceGlOuter::ViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h, GLsrc src_loc){
}

void InterfaceGlOuter::ViewportIndexedfv(GLuint index, GLfloatArr v, GLsrc src_loc){
}

void InterfaceGlOuter::WaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, GLsrc src_loc){
}
