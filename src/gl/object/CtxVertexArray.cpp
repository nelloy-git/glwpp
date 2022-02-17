#include "glwpp/gl/object/CtxVertexArray.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
static UInt* CreateVertexArray(const SrcLoc& loc){
    auto id = new UInt;
    glCreateVertexArrays(1, id);
    CtxObject::printDebug(loc);
    return id;
}
static void DeleteVertexArray(gl::UInt *id, bool is_init_thread){
    if (is_init_thread && glIsVertexArray(*id)){
        glDeleteVertexArrays(1, id);
    }
    delete id;
}
static Int GetIndexedParamI(const UInt& id, const UInt& index, const Enum& param, const SrcLoc& loc){
    Int dst;
    glGetVertexArrayIndexediv(id, index, param, &dst);
    CtxObject::printDebug(loc);
    return dst;
}
static Int GetIndexedParamI64(const UInt& id, const UInt& index, const Enum& param, const SrcLoc& loc){
    Int64 dst;
    glGetVertexArrayIndexed64iv(id, index, param, &dst);
    CtxObject::printDebug(loc);
    return dst;
}
};

CtxVertexArray::CtxVertexArray(const SrcLoc& loc) : 
    CtxObject(&CreateVertexArray, &DeleteVertexArray, loc){
}

bool CtxVertexArray::isAttribEnabled(const UInt& index, const SrcLoc& loc) const {
    return GL_TRUE == GetIndexedParamI(getId(), index, GL_VERTEX_ATTRIB_ARRAY_ENABLED, loc);
}

Int CtxVertexArray::getAttribSize(const UInt& index, const SrcLoc& loc) const {
    return GetIndexedParamI(getId(), index, GL_VERTEX_ATTRIB_ARRAY_SIZE, loc);
}

Int CtxVertexArray::getAttribStride(const UInt& index, const SrcLoc& loc) const {
    return GetIndexedParamI(getId(), index, GL_VERTEX_ATTRIB_ARRAY_STRIDE, loc);
}

DataType CtxVertexArray::getAttribType(const UInt& index, const SrcLoc& loc) const {
    return static_cast<DataType>(GetIndexedParamI(getId(), index, GL_VERTEX_ATTRIB_ARRAY_TYPE, loc));
}

bool CtxVertexArray::isAttribNormalized(const UInt& index, const SrcLoc& loc) const {
    return GL_TRUE == GetIndexedParamI(getId(), index, GL_VERTEX_ATTRIB_ARRAY_NORMALIZED, loc);
}

bool CtxVertexArray::isAttribInteger(const UInt& index, const SrcLoc& loc) const {
    return GL_TRUE == GetIndexedParamI(getId(), index, GL_VERTEX_ATTRIB_ARRAY_INTEGER, loc);
}

bool CtxVertexArray::isAttribLong(const UInt& index, const SrcLoc& loc) const {
    return GL_TRUE == GetIndexedParamI(getId(), index, GL_VERTEX_ATTRIB_ARRAY_LONG, loc);
}

Int CtxVertexArray::getAttribDivisor(const UInt& index, const SrcLoc& loc) const {
    return GetIndexedParamI(getId(), index, GL_VERTEX_ATTRIB_ARRAY_DIVISOR, loc);
}

Int CtxVertexArray::getAttribRelativeOffset(const UInt& index, const SrcLoc& loc) const {
    return GetIndexedParamI(getId(), index, GL_VERTEX_ATTRIB_RELATIVE_OFFSET, loc);
}

Int64 CtxVertexArray::getAttribBindingOffset(const UInt& index, const SrcLoc& loc) const {
    return GetIndexedParamI64(getId(), index, GL_VERTEX_BINDING_OFFSET, loc);
}

void CtxVertexArray::enableAttrib(const UInt& index, const SrcLoc& loc){
    glEnableVertexArrayAttrib(getId(), index);
    printDebug(loc);
}

void CtxVertexArray::disableAttrib(const UInt& index, const SrcLoc& loc){
    glDisableVertexArrayAttrib(getId(), index);
    printDebug(loc);
}

void CtxVertexArray::setAttribBinding(const UInt& index, const UInt& binding, const SrcLoc& loc){
    glVertexArrayAttribBinding(getId(), index, binding);
    printDebug(loc);
}

void CtxVertexArray::setAttribFormat(const UInt& index, const Int& size, const DataType& type,
                                  const bool& normalized, const UInt& relative_offset, const SrcLoc& loc){
    glVertexArrayAttribFormat(getId(), index, size, static_cast<Enum>(type),
                              normalized ? GL_TRUE : GL_FALSE, relative_offset);
    printDebug(loc);
}

void CtxVertexArray::setBindingDivisor(const UInt& binding, const UInt& divisor, const SrcLoc& loc){
    glVertexArrayBindingDivisor(getId(), binding, divisor);
    printDebug(loc);
}


void CtxVertexArray::setElementBuffer(const CtxBuffer& buffer, const SrcLoc& loc){
    glVertexArrayElementBuffer(getId(), buffer.getId());
    printDebug(loc);
}

void CtxVertexArray::setVertexBuffer(const gl::UInt& binding, const CtxBuffer& buffer,
                                  const gl::IntPtr& offset, const Sizei& stride, const SrcLoc& loc){
    glVertexArrayVertexBuffer(getId(), binding, buffer.getId(), offset, stride);
    printDebug(loc);
}