#include "gl_object/VertexArray.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace GL;

VertexArrayBase::VertexArrayBase(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc) :
    Object(ctx, ctx->gl().call([](Gl& gl, const SrcLoc& src_loc){
        unsigned int id;
        glCreateVertexArrays(1, &id);
        gl.debug(src_loc);
        return id;
    }, src_loc)){
}

VertexArrayBase::~VertexArrayBase(){
    _callGLCustom([](Gl& gl, const Uint& id){
        glDeleteVertexArrays(1, id.get());
    }, id());
}




void VertexArrayBase::enableAttrib(const Uint& index, const SrcLoc& src_loc){
    _callGL<&Gl::EnableVertexArrayAttrib>(id(), index, src_loc);
}

void VertexArrayBase::disableAttrib(const Uint& index, const SrcLoc& src_loc){
    _callGL<&Gl::DisableVertexArrayAttrib>(id(), index, src_loc);
}

void VertexArrayBase::setAttribBinding(const Uint& index, const Uint& binding, const SrcLoc& src_loc){
    _callGL<&Gl::VertexArrayAttribBinding>(id(), index, binding, src_loc);
}

void VertexArrayBase::setAttribFormat(const Uint& index, const Int& size, const Enum& type, const Boolean& normalized, const Uint& relative_offset, const SrcLoc& src_loc){
    _callGL<&Gl::VertexArrayAttribFormat>(id(), index, size, type, normalized, relative_offset, src_loc);
}

void VertexArrayBase::setBindingDivisor(const Uint& binding, const Uint& divisor, const SrcLoc& src_loc){
    _callGL<&Gl::VertexArrayBindingDivisor>(id(), binding, divisor, src_loc);
}

void VertexArrayBase::setElementBuffer(const BufferBase& buffer, const SrcLoc& src_loc){
    _callGL<&Gl::VertexArrayElementBuffer>(id(), buffer.id(), src_loc);
}

void VertexArrayBase::setVertexBuffer(const Uint& binding, const BufferBase& buffer, const Intptr& offset, const Sizei& stride, const SrcLoc& src_loc){
    _callGL<&Gl::VertexArrayVertexBuffer>(id(), binding, buffer.id(), offset, stride, src_loc);
}



GL::Boolean VertexArrayBase::isAttribEnabled(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        int dst;
        glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &dst);
        gl.debug(src_loc);
        return (unsigned char)(dst == GL_TRUE);
    }, id(), index, src_loc);
}

GL::Int VertexArrayBase::getAttribSize(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        int dst;
        glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_SIZE, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), index, src_loc);
}

GL::Int VertexArrayBase::getAttribStride(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        int dst;
        glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_STRIDE, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), index, src_loc);
}

GL::Enum VertexArrayBase::getAttribType(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        unsigned int dst;
        glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_TYPE, reinterpret_cast<int*>(&dst));
        gl.debug(src_loc);
        return dst;
    }, id(), index, src_loc);
}

GL::Boolean VertexArrayBase::isAttribNormalized(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        int dst;
        glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_NORMALIZED, &dst);
        gl.debug(src_loc);
        return (unsigned char)(dst == GL_TRUE);
    }, id(), index, src_loc);
}

GL::Boolean VertexArrayBase::isAttribInteger(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        int dst;
        glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_INTEGER, &dst);
        gl.debug(src_loc);
        return (unsigned char)(dst == GL_TRUE);
    }, id(), index, src_loc);
}

GL::Boolean VertexArrayBase::isAttribLong(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        int dst;
        glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_LONG, &dst);
        gl.debug(src_loc);
        return (unsigned char)(dst == GL_TRUE);
    }, id(), index, src_loc);
}

GL::Int VertexArrayBase::getAttribDivisor(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        int dst;
        glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_DIVISOR, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), index, src_loc);
}

GL::Int64 VertexArrayBase::getAttribBindingOffset(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        khronos_int64_t dst;
        glGetVertexArrayIndexed64iv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_DIVISOR, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), index, src_loc);
}