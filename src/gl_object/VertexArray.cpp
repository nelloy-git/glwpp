#include "gl_object/VertexArray.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace GL;


VertexArray::VertexArray(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc) :
    Object(ctx, ctx->gl().call([](Gl& gl, const SrcLoc& src_loc){
        unsigned int id;
        glCreateVertexArrays(1, &id);
        gl.debug(src_loc);
        return id;
    }, src_loc)){
}

VertexArray::~VertexArray(){
    _callGLCustom([](Gl& gl, const Uint& id){
        glDeleteVertexArrays(1, id.get());
    }, id());
}




void VertexArray::enableAttrib(const Uint& index, const SrcLoc& src_loc){
    _callGL<&Gl::EnableVertexArrayAttrib>(id(), index, src_loc);
}

void VertexArray::disableAttrib(const Uint& index, const SrcLoc& src_loc){
    _callGL<&Gl::DisableVertexArrayAttrib>(id(), index, src_loc);
}

void VertexArray::setAttribBinding(const Uint& index, const Uint& binding, const SrcLoc& src_loc){
    _callGL<&Gl::VertexArrayAttribBinding>(id(), index, binding, src_loc);
}

void VertexArray::setAttribFormat(const Uint& index, const Int& size, const Enum& type, const Boolean& normalized, const Uint& relative_offset, const SrcLoc& src_loc){
    _callGL<&Gl::VertexArrayAttribFormat>(id(), index, size, type, normalized, relative_offset, src_loc);
}

void VertexArray::setBindingDivisor(const Uint& binding, const Uint& divisor, const SrcLoc& src_loc){
    _callGL<&Gl::VertexArrayBindingDivisor>(id(), binding, divisor, src_loc);
}

void VertexArray::setElementBuffer(const Buffer& buffer, const SrcLoc& src_loc){
    _callGL<&Gl::VertexArrayElementBuffer>(id(), buffer.id(), src_loc);
}

void VertexArray::setVertexBuffer(const Uint& binding, const Buffer& buffer, const Intptr& offset, const Sizei& stride, const SrcLoc& src_loc){
    _callGL<&Gl::VertexArrayVertexBuffer>(id(), binding, buffer.id(), offset, stride, src_loc);
}



GL::Boolean VertexArray::isAttribEnabled(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        int dst;
        glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &dst);
        gl.debug(src_loc);
        return (unsigned char)(dst == GL_TRUE);
    }, id(), index, src_loc);
}

GL::Int VertexArray::getAttribSize(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        int dst;
        glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_SIZE, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), index, src_loc);
}

GL::Int VertexArray::getAttribStride(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        int dst;
        glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_STRIDE, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), index, src_loc);
}

GL::Enum VertexArray::getAttribType(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        unsigned int dst;
        glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_TYPE, reinterpret_cast<int*>(&dst));
        gl.debug(src_loc);
        return dst;
    }, id(), index, src_loc);
}

GL::Boolean VertexArray::isAttribNormalized(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        int dst;
        glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_NORMALIZED, &dst);
        gl.debug(src_loc);
        return (unsigned char)(dst == GL_TRUE);
    }, id(), index, src_loc);
}

GL::Boolean VertexArray::isAttribInteger(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        int dst;
        glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_INTEGER, &dst);
        gl.debug(src_loc);
        return (unsigned char)(dst == GL_TRUE);
    }, id(), index, src_loc);
}

GL::Boolean VertexArray::isAttribLong(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        int dst;
        glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_LONG, &dst);
        gl.debug(src_loc);
        return (unsigned char)(dst == GL_TRUE);
    }, id(), index, src_loc);
}

GL::Int VertexArray::getAttribDivisor(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        int dst;
        glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_DIVISOR, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), index, src_loc);
}

GL::Int64 VertexArray::getAttribBindingOffset(const Uint& index, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const Uint& index, const SrcLoc& src_loc){
        khronos_int64_t dst;
        glGetVertexArrayIndexed64iv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_DIVISOR, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), index, src_loc);
}