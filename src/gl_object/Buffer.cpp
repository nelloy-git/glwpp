#include "gl_object/Buffer.hpp"

using namespace glwpp;
using namespace glwpp::GL;


Buffer::Buffer(Context& ctx,
               const SrcLoc& src_loc,
               const IsCtxTrue& IsCtx) :
    Handler(ctx, &_Init, &_Free, src_loc, IsCtx){
}

Buffer::Buffer(Context& ctx,
               const SrcLoc& src_loc,
               const IsCtxFalse& IsCtx) :
    Handler(ctx, &_Init, &_Free, src_loc, IsCtx){
}

Buffer::Buffer(Context& ctx,
               const SrcLoc& src_loc,
               const IsCtxUnknown& IsCtx) :
    Handler(ctx, &_Init, &_Free, src_loc, IsCtx){
}

GLuint Buffer::_Init(Context& ctx, const SrcLoc& src_loc){
    GLuint id;
    ctx.gl().CreateBuffers<TState::True>(1, &id, src_loc);
    return id;
}

void Buffer::_Free(Context& ctx, const GLuint& id, const SrcLoc& src_loc){
    ctx.gl().DeleteBuffers<TState::True>(1, &id, src_loc);
}

void Buffer::_setData(Context& ctx, const GLsizeiptr& size, const void* data, const GLenum& usage, const SrcLoc& src_loc){
    ctx.gl().NamedBufferData<TState::True>(id().value(), size, data, usage, src_loc);
}

void Buffer::_clearData(Context& ctx, const GLenum& internalformat, const GLenum& format, const GLenum& type, const void* data, const SrcLoc& src_loc){
    ctx.gl().ClearNamedBufferData<TState::True>(id().value(), internalformat, format, type, data, src_loc);
}

void Buffer::_setStorage(Context& ctx, const GLsizeiptr& size, const void* data, const GLbitfield& flags, const SrcLoc& src_loc){
    ctx.gl().NamedBufferStorage<TState::True>(id().value(), size, data, flags, src_loc);
}

void* Buffer::_map(Context& ctx, const GLenum& access, const SrcLoc& src_loc){
    return ctx.gl().MapNamedBuffer<TState::True>(id().value(), access, src_loc);
}

void Buffer::_bindBase(Context& ctx, const GLenum target, const GLuint index, const SrcLoc src_loc){
    ctx.gl().BindBufferBase<TState::True>(target, index, id().value(), src_loc);
}

GLint Buffer::_getParameteriv(Context& ctx, const GLenum& pname, const SrcLoc& src_loc) const {
    GLint dst;
    ctx.gl().GetBufferParameteriv<TState::True>(id().value(), pname, &dst, src_loc);
    return dst;
}

GLint64 Buffer::_getParameteri64v(Context& ctx, const GLenum& pname, const SrcLoc& src_loc) const {
    GLint64 dst;
    ctx.gl().GetBufferParameteri64v<TState::True>(id().value(), pname, &dst, src_loc);
    return dst;
}