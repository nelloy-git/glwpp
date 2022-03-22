#include "glwpp/gl/oop/VertexArray.hpp"

#include "glwpp/gl/object/CtxVertexArray.hpp"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
    CtxVertexArray InitVerteCtxVertexArray(const SrcLoc& loc){
        return CtxVertexArray(loc);
    }
}

VertexArray::VertexArray(wptr<Context> ctx, const SrcLoc& loc) : 
    Object(ctx, &InitVerteCtxVertexArray, Val<SrcLoc>(loc)){
}

bool VertexArray::isAttribEnabled(const Val<UInt>& index, Ptr<bool>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::isAttribEnabled>(dst, index, loc);
}

bool VertexArray::getAttribSize(const Val<UInt>& index, Ptr<Int>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::getAttribSize>(dst, index, loc);
}

bool VertexArray::getAttribStride(const Val<UInt>& index, Ptr<Int>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::getAttribStride>(dst, index, loc);
}

bool VertexArray::getAttribType(const Val<UInt>& index, Ptr<DataType>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::getAttribType>(dst, index, loc);
}

bool VertexArray::isAttribNormalized(const Val<UInt>& index, Ptr<bool>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::isAttribNormalized>(dst, index, loc);
}

bool VertexArray::isAttribInteger(const Val<UInt>& index, Ptr<bool>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::isAttribInteger>(dst, index, loc);
}

bool VertexArray::isAttribLong(const Val<UInt>& index, Ptr<bool>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::isAttribLong>(dst, index, loc);
}

bool VertexArray::getAttribDivisor(const Val<UInt>& index, Ptr<Int>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::getAttribDivisor>(dst, index, loc);
}

bool VertexArray::getAttribRelativeOffset(const Val<UInt>& index, Ptr<Int>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::getAttribRelativeOffset>(dst, index, loc);
}

bool VertexArray::getAttribBindingOffset(const Val<UInt>& index, Ptr<Int64>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::getAttribBindingOffset>(dst, index, loc);
}
    
bool VertexArray::enableAttrib(const Val<gl::UInt>& index, const SrcLoc& loc){
    return _executeMethod<CtxVertexArray, &CtxVertexArray::enableAttrib>(index, loc);
}

bool VertexArray::disableAttrib(const Val<gl::UInt>& index, const SrcLoc& loc){
    return _executeMethod<CtxVertexArray, &CtxVertexArray::disableAttrib>(index, loc);
}

bool VertexArray::setAttribBinding(const Val<gl::UInt>& index, const Val<gl::UInt>& binding,
                                   const SrcLoc& loc){
    return _executeMethod<CtxVertexArray, &CtxVertexArray::setAttribBinding>(index, binding, loc);
}

bool VertexArray::setAttribFormat(const Val<gl::UInt>& index, const Val<gl::Int>& size,
                                  const Val<DataType>& type, const Val<bool>& normalized,
                                  const Val<gl::UInt>& relative_offset, const SrcLoc& loc){
    return _executeMethod<CtxVertexArray, &CtxVertexArray::setAttribFormat>(index, size, type, normalized, relative_offset, loc);
}

bool VertexArray::setBindingDivisor(const Val<gl::UInt>& binding, const Val<gl::UInt>& divisor,
                                    const SrcLoc& loc){
    return _executeMethod<CtxVertexArray, &CtxVertexArray::setBindingDivisor>(binding, divisor, loc);
}


bool VertexArray::setElementBuffer(const Buffer& buffer, const SrcLoc& loc){
    return _executeMethod<CtxVertexArray, &CtxVertexArray::setElementBuffer>(buffer._getVop<CtxBuffer>(), loc);
}

bool VertexArray::setVertexBuffer(const Val<gl::UInt>& binding, const Buffer& buffer,
                                  const Val<gl::IntPtr>& offset, const Val<Sizei>& stride,
                                  const SrcLoc& loc){
    return _executeMethod<CtxVertexArray, &CtxVertexArray::setVertexBuffer>(binding, buffer._getVop<CtxBuffer>(),
                                                                         offset, stride, loc);
}