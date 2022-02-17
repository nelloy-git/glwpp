#include "glwpp/gl/oop/VertexArray.hpp"

#include "glwpp/gl/object/CtxVertexArray.hpp"

using namespace glwpp;
using namespace glwpp::gl;

VertexArray::VertexArray(wptr<Context> ctx, const SrcLoc& loc) : 
    Object(ctx, &make_sptr<gl::CtxVertexArray, const SrcLoc&>, Vop<SrcLoc>(loc)){
}

std::shared_future<bool> VertexArray::isAttribEnabled(const Vop<UInt> index, Ptr<bool> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxVertexArray, &CtxVertexArray::isAttribEnabled>(dst, index, loc);
}

std::shared_future<bool> VertexArray::getAttribSize(const Vop<UInt> index, Ptr<Int> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxVertexArray, &CtxVertexArray::getAttribSize>(dst, index, loc);
}

std::shared_future<bool> VertexArray::getAttribStride(const Vop<UInt> index, Ptr<Int> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxVertexArray, &CtxVertexArray::getAttribStride>(dst, index, loc);
}

std::shared_future<bool> VertexArray::getAttribType(const Vop<UInt> index, Ptr<DataType> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxVertexArray, &CtxVertexArray::getAttribType>(dst, index, loc);
}

std::shared_future<bool> VertexArray::isAttribNormalized(const Vop<UInt> index, Ptr<bool> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxVertexArray, &CtxVertexArray::isAttribNormalized>(dst, index, loc);
}

std::shared_future<bool> VertexArray::isAttribInteger(const Vop<UInt> index, Ptr<bool> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxVertexArray, &CtxVertexArray::isAttribInteger>(dst, index, loc);
}

std::shared_future<bool> VertexArray::isAttribLong(const Vop<UInt> index, Ptr<bool> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxVertexArray, &CtxVertexArray::isAttribLong>(dst, index, loc);
}

std::shared_future<bool> VertexArray::getAttribDivisor(const Vop<UInt> index, Ptr<Int> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxVertexArray, &CtxVertexArray::getAttribDivisor>(dst, index, loc);
}

std::shared_future<bool> VertexArray::getAttribRelativeOffset(const Vop<UInt> index, Ptr<Int> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxVertexArray, &CtxVertexArray::getAttribRelativeOffset>(dst, index, loc);
}

std::shared_future<bool> VertexArray::getAttribBindingOffset(const Vop<UInt> index, Ptr<Int64> dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxVertexArray, &CtxVertexArray::getAttribBindingOffset>(dst, index, loc);
}
    
std::shared_future<bool> VertexArray::enableAttrib(const Vop<gl::UInt> index, const SrcLoc& loc){
    return _callMethod<CtxVertexArray, &CtxVertexArray::enableAttrib>(index, loc);
}

std::shared_future<bool> VertexArray::disableAttrib(const Vop<gl::UInt> index, const SrcLoc& loc){
    return _callMethod<CtxVertexArray, &CtxVertexArray::disableAttrib>(index, loc);
}

std::shared_future<bool> VertexArray::setAttribBinding(const Vop<gl::UInt> index, const Vop<gl::UInt> binding,
                                                       const SrcLoc& loc){
    return _callMethod<CtxVertexArray, &CtxVertexArray::setAttribBinding>(index, binding, loc);
}

std::shared_future<bool> VertexArray::setAttribFormat(const Vop<gl::UInt> index, const Vop<gl::Int> size,
                                                      const Vop<DataType> type, const Vop<bool> normalized,
                                                      const Vop<gl::UInt> relative_offset, const SrcLoc& loc){
    return _callMethod<CtxVertexArray, &CtxVertexArray::setAttribFormat>(index, size, type, normalized, relative_offset, loc);
}

std::shared_future<bool> VertexArray::setBindingDivisor(const Vop<gl::UInt> binding, const Vop<gl::UInt> divisor,
                                                        const SrcLoc& loc){
    return _callMethod<CtxVertexArray, &CtxVertexArray::setBindingDivisor>(binding, divisor, loc);
}


std::shared_future<bool> VertexArray::setElementBuffer(const Vop<Buffer> buffer, const SrcLoc& loc){
    static auto func = [](sptr<CtxVertexArray>* gl, const sptr<const CtxBuffer>* buffer, const SrcLoc& loc){
        auto raw_prog = gl->get();
        auto raw_buffer = buffer->get();
        raw_prog->setElementBuffer(*raw_buffer, loc);
    };
    return _execute(func, _getPtr<CtxVertexArray>(), getVopRef(buffer)._getPtr<CtxBuffer>(), loc);
}

std::shared_future<bool> VertexArray::setVertexBuffer(const Vop<gl::UInt> binding, const Vop<Buffer> buffer,
                                                      const Vop<gl::IntPtr> offset, const Vop<Sizei> stride,
                                                      const SrcLoc& loc){
    static auto func = [](sptr<CtxVertexArray>* gl, const UInt &binding, const sptr<const CtxBuffer>* buffer,
                          const IntPtr& offset, const Sizei stride, const SrcLoc& loc){
        auto raw_prog = gl->get();
        auto raw_buffer = buffer->get();
        raw_prog->setVertexBuffer(binding, *raw_buffer, offset, stride, loc);
    };
    return _execute(func, _getPtr<CtxVertexArray>(), binding, getVopRef(buffer)._getPtr<CtxBuffer>(), offset, stride, loc);
}