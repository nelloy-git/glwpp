#include "glwpp/gl/obj/VertexArray.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;

VertexArray::VertexArray(const wptr<Context>& wctx, const Val<const SrcLoc> src_loc) :
    Object(wctx, src_loc, &VertexArray::_initer, &VertexArray::_deleter){
}

bool VertexArray::getParamInt(const Val<Int> dst, const Val<const UInt>& index, const Val<const Enum> param,
                              const Val<const SrcLoc> src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glGetVertexArrayIndexediv, id(), index, param, dst);
}

bool VertexArray::getParamInt64(const Val<Int64> dst, const Val<const UInt>& index, const Val<const Enum> param,
                                const Val<const SrcLoc> src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, glGetVertexArrayIndexed64iv, id(), index, param, dst);
}

bool VertexArray::isAttribEnabled(const Val<bool>& dst, const Val<const UInt>& index, 
                                  const Val<const SrcLoc> src_loc, bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), index, GL_VERTEX_ATTRIB_ARRAY_ENABLED, src_loc, check_ctx);
}

bool VertexArray::getAttribSize(const Val<Int>& dst, const Val<const UInt>& index, 
                                const Val<const SrcLoc> src_loc, bool check_ctx) const {
    return getParamInt(dst, index, GL_VERTEX_ATTRIB_ARRAY_SIZE, src_loc, check_ctx);
}

bool VertexArray::getAttribStride(const Val<Int>& dst, const Val<const UInt>& index,
                                  const Val<const SrcLoc> src_loc, bool check_ctx) const {
    return getParamInt(dst, index, GL_VERTEX_ATTRIB_ARRAY_STRIDE, src_loc, check_ctx);
}

bool VertexArray::getAttribType(const Val<DataType>& dst, const Val<const UInt>& index,
                                const Val<const SrcLoc> src_loc, bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), index, GL_VERTEX_ATTRIB_ARRAY_TYPE, src_loc, check_ctx);
}

bool VertexArray::isAttribNormalized(const Val<bool>& dst, const Val<const UInt>& index,
                                     const Val<const SrcLoc> src_loc, bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), index, GL_VERTEX_ATTRIB_ARRAY_NORMALIZED, src_loc, check_ctx);
}

bool VertexArray::isAttribInteger(const Val<bool>& dst, const Val<const UInt>& index,
                                  const Val<const SrcLoc> src_loc, bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), index, GL_VERTEX_ATTRIB_ARRAY_INTEGER, src_loc, check_ctx);
}

bool VertexArray::isAttribLong(const Val<bool>& dst, const Val<const UInt>& index,
                               const Val<const SrcLoc> src_loc, bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), index, GL_VERTEX_ATTRIB_ARRAY_LONG, src_loc, check_ctx);
}

bool VertexArray::getAttribDivisor(const Val<Int>& dst, const Val<const UInt>& index,
                                   const Val<const SrcLoc> src_loc, bool check_ctx) const {
    return getParamInt(dst, index, GL_VERTEX_ATTRIB_ARRAY_DIVISOR, src_loc, check_ctx);
}

bool VertexArray::getAttribRelativeOffset(const Val<Int>& dst, const Val<const UInt>& index,
                                          const Val<const SrcLoc> src_loc, bool check_ctx) const {
    return getParamInt(dst, index, GL_VERTEX_ATTRIB_RELATIVE_OFFSET, src_loc, check_ctx);
}

bool VertexArray::getAttribBindingOffset(const Val<Int64>& dst, const Val<const UInt>& index,
                                         const Val<const SrcLoc> src_loc, bool check_ctx) const {
    return getParamInt64(dst, index, GL_VERTEX_BINDING_OFFSET, src_loc, check_ctx);
}

bool VertexArray::enableAttrib(const Val<const UInt>& index, 
                               const Val<const SrcLoc> src_loc, bool check_ctx){
    return executeInContext(check_ctx, SrcLoc{src_loc}, glEnableVertexArrayAttrib, id(), index);
}

bool VertexArray::disableAttrib(const Val<const UInt>& index, 
                                const Val<const SrcLoc> src_loc, bool check_ctx){
    return executeInContext(check_ctx, SrcLoc{src_loc}, glDisableVertexArrayAttrib, id(), index);
}

bool VertexArray::setAttribBinding(const Val<const UInt>& index, const Val<const UInt>& binding, 
                                   const Val<const SrcLoc> src_loc, bool check_ctx){
    return executeInContext(check_ctx, SrcLoc{src_loc}, glVertexArrayAttribBinding, id(), index, binding);
}

bool VertexArray::setAttribFormat(const Val<const UInt>& index, const Val<const Int>& size,
                                  const Val<const DataType>& type, const Val<const bool>& normalized,
                                  const Val<const UInt>& relative_offset, 
                                  const Val<const SrcLoc> src_loc, bool check_ctx){
    return executeInContext(check_ctx, SrcLoc{src_loc}, glVertexArrayAttribFormat, id(), index, size,
                            type.cast_reinterpret<const Enum>(), normalized.cast_reinterpret<const Int>(), relative_offset);
}

bool VertexArray::setBindingDivisor(const Val<const UInt>& binding, const Val<const UInt>& divisor, 
                                    const Val<const SrcLoc> src_loc, bool check_ctx){
    return executeInContext(check_ctx, SrcLoc{src_loc}, glVertexArrayBindingDivisor, id(), binding, divisor);
}

bool VertexArray::setElementBuffer(const Buffer& buffer, 
                                   const Val<const SrcLoc> src_loc, bool check_ctx){
    return executeInContext(check_ctx, SrcLoc{src_loc}, glVertexArrayElementBuffer, id(), buffer.id());
}

bool VertexArray::setVertexBuffer(const Val<const UInt>& binding, const Buffer& buffer,
                                  const Val<const IntPtr>& offset, const Val<const Sizei>& stride, 
                                  const Val<const SrcLoc> src_loc, bool check_ctx){
    return executeInContext(check_ctx, SrcLoc{src_loc}, glVertexArrayVertexBuffer, id(), binding, buffer.id(), offset, stride);
}

namespace {
void _glVertexArrayDrawElementsInstanced(const UInt& id, const Enum& mode, const Sizei& vert_count,
                                         const Enum& index_type, const Sizei& instances){
    glBindVertexArray(id);
    glDrawElementsInstanced(mode, vert_count, index_type, nullptr, instances);
    glBindVertexArray(0);
}
}

bool VertexArray::draw(const Val<const DrawMode>& mode, const Val<const Sizei>& vertex_count,
                       const Val<const DataType>& index_type, const Val<const Sizei>& instances, 
                       const Val<const SrcLoc> src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, SrcLoc{src_loc}, _glVertexArrayDrawElementsInstanced, id(),
                            mode.cast_reinterpret<const Enum>(), vertex_count,
                            index_type.cast_reinterpret<const Enum>(), instances);
}

void VertexArray::_initer(UInt& dst){
    glCreateVertexArrays(1, &dst);
}

void VertexArray::_deleter(const UInt& id){
    glDeleteVertexArrays(1, &id);
}