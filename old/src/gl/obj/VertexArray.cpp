#include "glwpp/gl/obj/VertexArray.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;
using namespace glwpp::utils;

sptr<VertexArray> VertexArray::make(const sptr<Context>& ctx,
                                    const Val<const utils::SrcLoc>& src_loc){
    return sptr<VertexArray>(new VertexArray(ctx, src_loc));
}

VertexArray::VertexArray(const sptr<Context>& ctx, const Val<const SrcLoc>& src_loc) :
    Object(ctx, &VertexArray::_initer, &VertexArray::_deleter, src_loc){
}

bool VertexArray::getParamInt(const Val<Int>& dst, const Val<const UInt>& index, const Val<const Enum>& param,
                              const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&VertexArray::getParamInt, dst, index, param, src_loc);
    }

    glGetVertexArrayIndexediv(id(), index, param, dst);
    debug(src_loc);    
    return true;
}

bool VertexArray::getParamInt64(const Val<Int64>& dst, const Val<const UInt>& index, const Val<const Enum>& param,
                                const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&VertexArray::getParamInt64, dst, index, param, src_loc);
    }

    glGetVertexArrayIndexed64iv(id(), index, param, dst);
    debug(src_loc);    
    return true;
}

bool VertexArray::isAttribEnabled(const Val<bool>& dst, const Val<const UInt>& index, 
                                  const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), index, GL_VERTEX_ATTRIB_ARRAY_ENABLED, src_loc);
}

bool VertexArray::getAttribSize(const Val<Int>& dst, const Val<const UInt>& index, 
                                const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst, index, GL_VERTEX_ATTRIB_ARRAY_SIZE, src_loc);
}

bool VertexArray::getAttribStride(const Val<Int>& dst, const Val<const UInt>& index,
                                  const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst, index, GL_VERTEX_ATTRIB_ARRAY_STRIDE, src_loc);
}

bool VertexArray::getAttribType(const Val<DataType>& dst, const Val<const UInt>& index,
                                const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), index, GL_VERTEX_ATTRIB_ARRAY_TYPE, src_loc);
}

bool VertexArray::isAttribNormalized(const Val<bool>& dst, const Val<const UInt>& index,
                                     const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), index, GL_VERTEX_ATTRIB_ARRAY_NORMALIZED, src_loc);
}

bool VertexArray::isAttribInteger(const Val<bool>& dst, const Val<const UInt>& index,
                                  const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), index, GL_VERTEX_ATTRIB_ARRAY_INTEGER, src_loc);
}

bool VertexArray::isAttribLong(const Val<bool>& dst, const Val<const UInt>& index,
                               const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), index, GL_VERTEX_ATTRIB_ARRAY_LONG, src_loc);
}

bool VertexArray::getAttribDivisor(const Val<Int>& dst, const Val<const UInt>& index,
                                   const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst, index, GL_VERTEX_ATTRIB_ARRAY_DIVISOR, src_loc);
}

bool VertexArray::getAttribRelativeOffset(const Val<Int>& dst, const Val<const UInt>& index,
                                          const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst, index, GL_VERTEX_ATTRIB_RELATIVE_OFFSET, src_loc);
}

bool VertexArray::getAttribBindingOffset(const Val<Int64>& dst, const Val<const UInt>& index,
                                         const Val<const SrcLoc>& src_loc) const {
    return getParamInt64(dst, index, GL_VERTEX_BINDING_OFFSET, src_loc);
}

bool VertexArray::enableAttrib(const Val<const UInt>& index, 
                               const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&VertexArray::enableAttrib, index, src_loc);
    }

    glEnableVertexArrayAttrib(id(), index);
    debug(src_loc);    
    return true;
}

bool VertexArray::disableAttrib(const Val<const UInt>& index, 
                                const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&VertexArray::disableAttrib, index, src_loc);
    }

    glDisableVertexArrayAttrib(id(), index);
    debug(src_loc);    
    return true;
}

bool VertexArray::setAttribBinding(const Val<const UInt>& index, const Val<const UInt>& binding, 
                                   const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&VertexArray::setAttribBinding, index, binding, src_loc);
    }

    glVertexArrayAttribBinding(id(), index, binding);
    debug(src_loc);    
    return true;
}

bool VertexArray::setAttribFormat(const Val<const UInt>& index, const Val<const Int>& size,
                                  const Val<const DataType>& type, const Val<const bool>& normalized,
                                  const Val<const UInt>& relative_offset, 
                                  const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&VertexArray::setAttribFormat, index, size, type, normalized, relative_offset, src_loc);
    }
    
    glVertexArrayAttribFormat(id(), index, size, type.cast_reinterpret<const Enum>(),
                              normalized.cast_reinterpret<const Int>(), relative_offset);
    debug(src_loc);                              
    return true;
}

bool VertexArray::setBindingDivisor(const Val<const UInt>& binding, const Val<const UInt>& divisor, 
                                    const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&VertexArray::setBindingDivisor, binding, divisor, src_loc);
    }

    glVertexArrayBindingDivisor(id(), binding, divisor);
    debug(src_loc);    
    return true;
}

bool VertexArray::setElementBuffer(const Val<const Buffer>& buffer, 
                                   const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&VertexArray::setElementBuffer, buffer, src_loc);
    }

    glVertexArrayElementBuffer(id(), buffer->id());
    debug(src_loc);    
    return true;
}

bool VertexArray::setVertexBuffer(const Val<const UInt>& binding, const Val<const Buffer>& buffer,
                                  const Val<const IntPtr>& offset, const Val<const Sizei>& stride, 
                                  const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&VertexArray::setVertexBuffer, binding, buffer, offset, stride, src_loc);
    }

    glVertexArrayVertexBuffer(id(), binding, buffer->id(), offset, stride);
    debug(src_loc);    
    return true;
}

bool VertexArray::draw(const Val<const DrawMode>& mode, const Val<const Sizei>& vertex_count,
                       const Val<const DataType>& index_type, const Val<const Sizei>& instances, 
                       const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&VertexArray::draw, mode, vertex_count, index_type, instances, src_loc);
    }

    glBindVertexArray(id());
    glDrawElementsInstanced(mode.cast_reinterpret<const Enum>(), vertex_count,
                            index_type.cast_reinterpret<const Enum>(), nullptr, instances);
    glBindVertexArray(0);
    debug(src_loc);    
    return true;
}

void VertexArray::_initer(const Val<UInt>& dst, const Val<const SrcLoc>& src_loc){
    glCreateVertexArrays(1, dst);
}

void VertexArray::_deleter(const UInt& id){
    glDeleteVertexArrays(1, &id);
}