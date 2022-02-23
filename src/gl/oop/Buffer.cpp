#include "glwpp/gl/oop/Buffer.hpp"

#include "glwpp/gl/object/CtxBuffer.hpp"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
    CtxBuffer InitBuffer(const SrcLoc& loc){
        return CtxBuffer(loc);
    }
}

Buffer::Buffer(const std::weak_ptr<Context>& weak_ctx, const SrcLoc& loc) :
    Object(weak_ctx, &InitBuffer, Vop<SrcLoc>(loc)){
}

bool Buffer::data(const Vop<gl::SizeiPtr>& size, const Vop<Data>& data,
                  const Vop<gl::BufferUsage>& usage, const SrcLoc& loc){
    return _executeMethod<CtxBuffer, &CtxBuffer::data>(size, data, usage, loc);
}

bool Buffer::storage(const Vop<gl::SizeiPtr>& size, const Vop<Data>& data,
                     const Vop<gl::BitField>& flags, const SrcLoc& loc){
    return _executeMethod<CtxBuffer, &CtxBuffer::storage>(size, data, flags, loc);
}

bool Buffer::getMapAccess(Ptr<gl::BufferMapAccess>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::getMapAccess>(dst, loc);
}

bool Buffer::getMapRangeAccess(Ptr<gl::BitField>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::getMapRangeAccess>(dst, loc);
}

bool Buffer::isImmutable(Ptr<bool>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::isImmutable>(dst, loc);
}

bool Buffer::isMapped(Ptr<bool>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::isMapped>(dst, loc);
}

bool Buffer::getMapLength(Ptr<gl::Int64>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::getMapLength>(dst, loc);
}

bool Buffer::getMapOffset(Ptr<gl::Int64>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::getMapOffset>(dst, loc);
}

bool Buffer::getSize(Ptr<gl::Int>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::getSize>(dst, loc);
}

bool Buffer::getStorageFlags(Ptr<gl::BitField>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::getStorageFlags>(dst, loc);
}

bool Buffer::getUsage(Ptr<gl::BufferUsage>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::getUsage>(dst, loc);
}

bool Buffer::getSubData(const Vop<gl::IntPtr>& offset, const Vop<gl::SizeiPtr>& size,
                        Ptr<Data>& dst, const SrcLoc& loc) const {
    return _executeMethod<CtxBuffer, &CtxBuffer::getSubData>(offset, size, dst, loc);
}
bool Buffer::setSubData(const Vop<gl::IntPtr>& offset, const Vop<gl::SizeiPtr>& size,
                        const Vop<Data>& data, const SrcLoc& loc) {
    return _executeMethod<CtxBuffer, &CtxBuffer::setSubData>(offset, size, data, loc);
}

bool Buffer::copySubDataTo(Buffer& dst, const Vop<IntPtr>& read_offset,
                           const Vop<IntPtr>& write_offset, const Vop<SizeiPtr>& size,
                           const SrcLoc& loc) const {
    return _executeMethod<CtxBuffer, &CtxBuffer::copySubDataTo>(dst._getVop<CtxBuffer>(), read_offset, write_offset, size, loc);
}

bool Buffer::getMapPointer(Ptr<MapPtr>& dst, const SrcLoc& loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::getMapPointer>(dst, loc);
}

bool Buffer::map(const Vop<gl::BufferMapAccess>& access, Ptr<MapPtr>& dst, const SrcLoc& loc){
    return _executeGetter<CtxBuffer, &CtxBuffer::map>(dst, access, loc);
}

bool Buffer::mapRange(const Vop<gl::IntPtr>& offset, const Vop<gl::SizeiPtr>& size,
                      const Vop<gl::BitField>& access, Ptr<MapPtr>& dst,
                      const SrcLoc& loc){
    return _executeGetter<CtxBuffer, &CtxBuffer::mapRange>(dst, offset, size, access, loc);
}

bool Buffer::mapFlushRange(const Vop<gl::IntPtr>& offset, const Vop<gl::SizeiPtr>& size,
                           const SrcLoc& loc){
    return _executeMethod<CtxBuffer, &CtxBuffer::mapFlushRange>(offset, size, loc);
}

bool Buffer::unmap(Ptr<bool>& dst, const SrcLoc& loc){
    return _executeGetter<CtxBuffer, &CtxBuffer::unmap>(dst, loc);
}