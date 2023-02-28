#include "gl_object/VertexArray.hpp"

using namespace glwpp;
using namespace glwpp::GL;

GLuint VertexArray::_Init(Context& ctx, const SrcLoc& src_loc){
    GLuint id;

    if (ctx.gl().VersionMajor() >= 4 && ctx.gl().VersionMinor() >= 5){
        ctx.gl().CreateVertexArrays<TState::True>(1, &id, src_loc);
    } else {
        ctx.gl().GenVertexArrays<TState::True>(1, &id, src_loc);
    }
    
    return id;
}

void VertexArray::_Free(Context& ctx, const GLuint& id, const SrcLoc& src_loc){
    ctx.gl().DeleteVertexArrays<TState::True>(1, &id, src_loc);
}


void VertexArray::_enableAttrib(Context& ctx, const GLuint& index, const SrcLoc& src_loc){
    ctx.gl().EnableVertexArrayAttrib<TState::True>(*id(), index, src_loc);
}

void VertexArray::_disableAttrib(Context& ctx, const GLuint& index, const SrcLoc& src_loc){
    ctx.gl().DisableVertexArrayAttrib<TState::True>(*id(), index, src_loc);
}

void VertexArray::_setVertexAttribPointer(Context& ctx, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer, const SrcLoc& src_loc){
    ctx.gl().BindVertexArray<TState::True>(id().value(), src_loc);
    ctx.gl().VertexAttribPointer<TState::True>(index, size, type, normalized, stride, pointer, src_loc);
}

void VertexArray::_setAttribBinding(Context& ctx, const GLuint& index, const GLuint& binding, const SrcLoc& src_loc){
    ctx.gl().VertexArrayAttribBinding<TState::True>(*id(), index, binding, src_loc);
}

void VertexArray::_setAttribFormat(Context& ctx, const GLuint& index, const GLint& size, const GLenum& type, const GLboolean& normalized, const GLuint& relative_offset, const SrcLoc& src_loc){
    ctx.gl().VertexArrayAttribFormat<TState::True>(*id(), index, size, type, normalized, relative_offset, src_loc);
}

void VertexArray::_setBindingDivisor(Context& ctx, const GLuint& binding, const GLuint& divisor, const SrcLoc& src_loc){
    ctx.gl().VertexArrayBindingDivisor<TState::True>(*id(), binding, divisor, src_loc);
}

void VertexArray::_setElementBuffer(Context& ctx, const Buffer& buffer, const SrcLoc& src_loc){
    ctx.gl().VertexArrayElementBuffer<TState::True>(*id(), *buffer.id(), src_loc);
}

void VertexArray::_setVertexBuffer(Context& ctx, const GLuint& binding, const Buffer& buffer, const GLintptr& offset, const GLsizei& stride, const SrcLoc& src_loc){
    ctx.gl().VertexArrayVertexBuffer<TState::True>(*id(), binding, *buffer.id(), offset, stride, src_loc);
}
