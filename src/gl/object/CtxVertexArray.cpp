#include "glwpp/gl/object/CtxVertexArray.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
static UInt* CreateVertexArray(const SrcLoc& loc){
    auto id = new UInt;
    glCreateVertexArrays(1, id);
    return id;
}
static void DeleteVertexArray(gl::UInt *id, bool is_init_thread){
    if (is_init_thread && glIsVertexArray(*id)){
        glDeleteVertexArrays(1, id);
    }
    delete id;
}
};

CtxVertexArray::CtxVertexArray(const Dummy&) :
    CtxObject(Dummy{}){
}

CtxVertexArray::CtxVertexArray(const SrcLoc& loc) : 
    CtxObject(&CreateVertexArray, &DeleteVertexArray, loc){
    CtxObject::_printDebug(loc);
}

Int CtxVertexArray::getAttribParamI(const UInt& index, const Enum& param, const SrcLoc& loc) const {
    Int dst;
    glGetVertexArrayIndexediv(getId(), index, param, &dst);
    CtxObject::_printDebug(loc);
    return dst;
}

Int64 CtxVertexArray::getAttribParamI64(const UInt& index, const Enum& param, const SrcLoc& loc) const {
    Int64 dst;
    glGetVertexArrayIndexed64iv(getId(), index, param, &dst);
    CtxObject::_printDebug(loc);
    return dst;
}

bool CtxVertexArray::isAttribEnabled(const UInt& index, const SrcLoc& loc) const {
    return GL_TRUE == getAttribParamI(index, GL_VERTEX_ATTRIB_ARRAY_ENABLED, loc);
}

Int CtxVertexArray::getAttribSize(const UInt& index, const SrcLoc& loc) const {
    return getAttribParamI(index, GL_VERTEX_ATTRIB_ARRAY_SIZE, loc);
}

Int CtxVertexArray::getAttribStride(const UInt& index, const SrcLoc& loc) const {
    return getAttribParamI(index, GL_VERTEX_ATTRIB_ARRAY_STRIDE, loc);
}

DataType CtxVertexArray::getAttribType(const UInt& index, const SrcLoc& loc) const {
    return static_cast<DataType>(getAttribParamI(index, GL_VERTEX_ATTRIB_ARRAY_TYPE, loc));
}

bool CtxVertexArray::isAttribNormalized(const UInt& index, const SrcLoc& loc) const {
    return GL_TRUE == getAttribParamI(index, GL_VERTEX_ATTRIB_ARRAY_NORMALIZED, loc);
}

bool CtxVertexArray::isAttribInteger(const UInt& index, const SrcLoc& loc) const {
    return GL_TRUE == getAttribParamI(index, GL_VERTEX_ATTRIB_ARRAY_INTEGER, loc);
}

bool CtxVertexArray::isAttribLong(const UInt& index, const SrcLoc& loc) const {
    return GL_TRUE == getAttribParamI(index, GL_VERTEX_ATTRIB_ARRAY_LONG, loc);
}

Int CtxVertexArray::getAttribDivisor(const UInt& index, const SrcLoc& loc) const {
    return getAttribParamI(index, GL_VERTEX_ATTRIB_ARRAY_DIVISOR, loc);
}

Int CtxVertexArray::getAttribRelativeOffset(const UInt& index, const SrcLoc& loc) const {
    return getAttribParamI(index, GL_VERTEX_ATTRIB_RELATIVE_OFFSET, loc);
}

Int64 CtxVertexArray::getAttribBindingOffset(const UInt& index, const SrcLoc& loc) const {
    return getAttribParamI64(index, GL_VERTEX_BINDING_OFFSET, loc);
}

void CtxVertexArray::enableAttrib(const UInt& index, const SrcLoc& loc){
    glEnableVertexArrayAttrib(getId(), index);
    _printDebug(loc);
}

void CtxVertexArray::disableAttrib(const UInt& index, const SrcLoc& loc){
    glDisableVertexArrayAttrib(getId(), index);
    _printDebug(loc);
}

void CtxVertexArray::setAttribBinding(const UInt& index, const UInt& binding, const SrcLoc& loc){
    glVertexArrayAttribBinding(getId(), index, binding);
    _printDebug(loc);
}

void CtxVertexArray::setAttribFormat(const UInt& index, const Int& size, const DataType& type,
                                     const bool& normalized, const UInt& relative_offset, const SrcLoc& loc){
    glVertexArrayAttribFormat(getId(), index, size, static_cast<Enum>(type),
                              normalized ? GL_TRUE : GL_FALSE, relative_offset);
    _printDebug(loc);
}

void CtxVertexArray::setBindingDivisor(const UInt& binding, const UInt& divisor, const SrcLoc& loc){
    glVertexArrayBindingDivisor(getId(), binding, divisor);
    _printDebug(loc);
}


void CtxVertexArray::setElementBuffer(const CtxBuffer& buffer, const SrcLoc& loc){
    glVertexArrayElementBuffer(getId(), buffer.getId());
    _printDebug(loc);
}

void CtxVertexArray::setVertexBuffer(const gl::UInt& binding, const CtxBuffer& buffer,
                                     const gl::IntPtr& offset, const Sizei& stride, const SrcLoc& loc){
    glVertexArrayVertexBuffer(getId(), binding, buffer.getId(), offset, stride);
    _printDebug(loc);
}

void CtxVertexArray::draw(const gl::DrawMode& mode, const size_t& vertex_count,
                          const gl::DataType& index_type, const size_t& instances, const SrcLoc& loc) const {
    glBindVertexArray(getId());
    glDrawElementsInstanced(static_cast<Enum>(mode), vertex_count, static_cast<Enum>(index_type), nullptr, instances);
    glBindVertexArray(0);
    _printDebug(loc);
}