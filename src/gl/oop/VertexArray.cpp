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
    Object(ctx, &InitVerteCtxVertexArray, Vop<SrcLoc>(loc)){
}

bool VertexArray::isAttribEnabled(const Vop<UInt>& index, Ptr<bool>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::isAttribEnabled>(dst, index, loc);
}

bool VertexArray::getAttribSize(const Vop<UInt>& index, Ptr<Int>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::getAttribSize>(dst, index, loc);
}

bool VertexArray::getAttribStride(const Vop<UInt>& index, Ptr<Int>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::getAttribStride>(dst, index, loc);
}

bool VertexArray::getAttribType(const Vop<UInt>& index, Ptr<DataType>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::getAttribType>(dst, index, loc);
}

bool VertexArray::isAttribNormalized(const Vop<UInt>& index, Ptr<bool>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::isAttribNormalized>(dst, index, loc);
}

bool VertexArray::isAttribInteger(const Vop<UInt>& index, Ptr<bool>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::isAttribInteger>(dst, index, loc);
}

bool VertexArray::isAttribLong(const Vop<UInt>& index, Ptr<bool>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::isAttribLong>(dst, index, loc);
}

bool VertexArray::getAttribDivisor(const Vop<UInt>& index, Ptr<Int>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::getAttribDivisor>(dst, index, loc);
}

bool VertexArray::getAttribRelativeOffset(const Vop<UInt>& index, Ptr<Int>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::getAttribRelativeOffset>(dst, index, loc);
}

bool VertexArray::getAttribBindingOffset(const Vop<UInt>& index, Ptr<Int64>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxVertexArray, &CtxVertexArray::getAttribBindingOffset>(dst, index, loc);
}
    
bool VertexArray::enableAttrib(const Vop<gl::UInt>& index, const SrcLoc& loc){
    return _executeMethod<CtxVertexArray, &CtxVertexArray::enableAttrib>(index, loc);
}

bool VertexArray::disableAttrib(const Vop<gl::UInt>& index, const SrcLoc& loc){
    return _executeMethod<CtxVertexArray, &CtxVertexArray::disableAttrib>(index, loc);
}

bool VertexArray::setAttribBinding(const Vop<gl::UInt>& index, const Vop<gl::UInt>& binding,
                                   const SrcLoc& loc){
    return _executeMethod<CtxVertexArray, &CtxVertexArray::setAttribBinding>(index, binding, loc);
}

bool VertexArray::setAttribFormat(const Vop<gl::UInt>& index, const Vop<gl::Int>& size,
                                  const Vop<DataType>& type, const Vop<bool>& normalized,
                                  const Vop<gl::UInt>& relative_offset, const SrcLoc& loc){
    return _executeMethod<CtxVertexArray, &CtxVertexArray::setAttribFormat>(index, size, type, normalized, relative_offset, loc);
}

bool VertexArray::setBindingDivisor(const Vop<gl::UInt>& binding, const Vop<gl::UInt>& divisor,
                                    const SrcLoc& loc){
    return _executeMethod<CtxVertexArray, &CtxVertexArray::setBindingDivisor>(binding, divisor, loc);
}


bool VertexArray::setElementBuffer(const Buffer& buffer, const SrcLoc& loc){
    return _executeMethod<CtxVertexArray, &CtxVertexArray::setElementBuffer>(buffer._getVop<CtxBuffer>(), loc);
}

bool VertexArray::setVertexBuffer(const Vop<gl::UInt>& binding, const Buffer& buffer,
                                  const Vop<gl::IntPtr>& offset, const Vop<Sizei>& stride,
                                  const SrcLoc& loc){
    return _executeMethod<CtxVertexArray, &CtxVertexArray::setVertexBuffer>(binding, buffer._getVop<CtxBuffer>(),
                                                                         offset, stride, loc);
}