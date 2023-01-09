#include "gl_object/Buffer.hpp"

using namespace glwpp::GL::detail;

GLuint BufferImpl::_Init(Context& ctx, const SrcLoc& src_loc){
    GLuint id;
    ctx.gl.CreateBuffers(1, &id, src_loc);
    return id;
}

void BufferImpl::_Free(Context& ctx, const GLuint& id, const SrcLoc& src_loc){
    ctx.gl.DeleteBuffers(1, &id, src_loc);
}

void BufferImpl::_setData(Context& ctx, const GLsizeiptr& size, const void* data, const GLenum& usage, const SrcLoc& src_loc){
    ctx.gl.NamedBufferData(id().value(), size, data, usage, src_loc);
}

void BufferImpl::_clearData(Context& ctx, const GLenum& internalformat, const GLenum& format, const GLenum& type, const void* data, const SrcLoc& src_loc){
    ctx.gl.ClearNamedBufferData(id().value(), internalformat, format, type, data, src_loc);
}

void BufferImpl::_setStorage(Context& ctx, const GLsizeiptr& size, const void* data, const GLbitfield& flags, const SrcLoc& src_loc){
    ctx.gl.NamedBufferStorage(id().value(), size, data, flags, src_loc);
}

void BufferImpl::_bindBase(Context& ctx, const GLenum target, const GLuint index, const SrcLoc src_loc){
    ctx.gl.BindBufferBase(target, index, id().value(), src_loc);
}