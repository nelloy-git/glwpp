#include "glwpp/gl/oop/Buffer.hpp"

#include "glwpp/gl/object/CtxBuffer.hpp"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
    CtxBuffer InitBuffer(const SrcLoc& loc){
        return CtxBuffer(loc);
    }
}

Buffer::Buffer(std::weak_ptr<Context> weak_ctx, const SrcLoc& loc) :
    Object(weak_ctx, &InitBuffer, Vop<SrcLoc>(loc)){
}

std::shared_future<bool> Buffer::data(const Vop<gl::SizeiPtr>& size, const Vop<Data>& data,
                                      const Vop<gl::BufferUsage>& usage, const SrcLoc& loc){
    return _callMethod<CtxBuffer, &CtxBuffer::data>(size, data, usage, loc);
}

std::shared_future<bool> Buffer::storage(const Vop<gl::SizeiPtr>& size, const Vop<Data>& data,
                                         const Vop<gl::BitField>& flags, const SrcLoc& loc){
    return _callMethod<CtxBuffer, &CtxBuffer::storage>(size, data, flags, loc);
}

std::shared_future<bool> Buffer::getMapAccess(Ptr<gl::BufferMapAccess>& dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxBuffer, &CtxBuffer::getMapAccess>(dst, loc);
}

std::shared_future<bool> Buffer::getMapRangeAccess(Ptr<gl::BitField>& dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxBuffer, &CtxBuffer::getMapRangeAccess>(dst, loc);
}

std::shared_future<bool> Buffer::isImmutable(Ptr<bool>& dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxBuffer, &CtxBuffer::isImmutable>(dst, loc);
}

std::shared_future<bool> Buffer::isMapped(Ptr<bool>& dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxBuffer, &CtxBuffer::isMapped>(dst, loc);
}

std::shared_future<bool> Buffer::getMapLength(Ptr<gl::Int64>& dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxBuffer, &CtxBuffer::getMapLength>(dst, loc);
}

std::shared_future<bool> Buffer::getMapOffset(Ptr<gl::Int64>& dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxBuffer, &CtxBuffer::getMapOffset>(dst, loc);
}

std::shared_future<bool> Buffer::getSize(Ptr<gl::Int>& dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxBuffer, &CtxBuffer::getSize>(dst, loc);
}

std::shared_future<bool> Buffer::getStorageFlags(Ptr<gl::BitField>& dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxBuffer, &CtxBuffer::getStorageFlags>(dst, loc);
}

std::shared_future<bool> Buffer::getUsage(Ptr<gl::BufferUsage>& dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxBuffer, &CtxBuffer::getUsage>(dst, loc);
}

std::shared_future<bool> Buffer::getSubData(const Vop<gl::IntPtr>& offset, const Vop<gl::SizeiPtr>& size,
                                            Ptr<Data>& dst, const SrcLoc& loc) const {
    return _callMethod<CtxBuffer, &CtxBuffer::getSubData>(offset, size, dst, loc);
}
std::shared_future<bool> Buffer::setSubData(const Vop<gl::IntPtr>& offset, const Vop<gl::SizeiPtr>& size,
                                            const Vop<Data>& data, const SrcLoc& loc) {
    return _callMethod<CtxBuffer, &CtxBuffer::setSubData>(offset, size, data, loc);
}

std::shared_future<bool> Buffer::copySubDataTo(Buffer& dst, const Vop<IntPtr>& read_offset,
                                               const Vop<IntPtr>& write_offset, const Vop<SizeiPtr>& size,
                                               const SrcLoc& loc) const {
    return _callMethod<CtxBuffer, &CtxBuffer::copySubDataTo>(dst._getVop<CtxBuffer>(), read_offset, write_offset, size, loc);
}

std::shared_future<bool> Buffer::getMapPointer(Ptr<MapPtr>& dst, const SrcLoc& loc) const {
    return _getFromMethod<CtxBuffer, &CtxBuffer::getMapPointer>(dst, loc);
}

std::shared_future<bool> Buffer::map(const Vop<gl::BufferMapAccess>& access, Ptr<MapPtr>& dst, const SrcLoc& loc){
    return _getFromMethod<CtxBuffer, &CtxBuffer::map>(dst, access, loc);
}

std::shared_future<bool> Buffer::mapRange(const Vop<gl::IntPtr>& offset, const Vop<gl::SizeiPtr>& size,
                                          const Vop<gl::BitField>& access, Ptr<MapPtr>& dst,
                                          const SrcLoc& loc){
    return _getFromMethod<CtxBuffer, &CtxBuffer::mapRange>(dst, offset, size, access, loc);
}

std::shared_future<bool> Buffer::mapFlushRange(const Vop<gl::IntPtr>& offset, const Vop<gl::SizeiPtr>& size,
                                               const SrcLoc& loc){
    return _callMethod<CtxBuffer, &CtxBuffer::mapFlushRange>(offset, size, loc);
}

std::shared_future<bool> Buffer::unmap(Ptr<bool>& dst, const SrcLoc& loc){
    return _getFromMethod<CtxBuffer, &CtxBuffer::unmap>(dst, loc);
}