#include "glwpp/gl/obj/Buffer.hpp"

#include "glwpp/gl/ctx_only/CtxBuffer.hpp"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
    CtxBuffer InitBuffer(const SrcLoc loc){
        return CtxBuffer(loc);
    }
}

Buffer::Buffer(const std::weak_ptr<Context>& weak_ctx, const SrcLoc loc) :
    Object(weak_ctx, &InitBuffer, Val<SrcLoc>(loc)){
}

bool Buffer::data(const Val<gl::SizeiPtr>& size, const Ptr<void>& data,
                  const Val<gl::BufferUsage>& usage, const SrcLoc loc){
    return _executeMethod<CtxBuffer, &CtxBuffer::data>(size, data, usage, loc);
}

bool Buffer::storage(const Val<gl::SizeiPtr>& size, const Ptr<void>& data,
                     const Val<gl::BitField>& flags, const SrcLoc loc){
    return _executeMethod<CtxBuffer, &CtxBuffer::storage>(size, data, flags, loc);
}

bool Buffer::bindUniformBase(const Val<gl::UInt>& index, const SrcLoc loc) const {
    return _executeMethod<CtxBuffer, &CtxBuffer::bindUniformBase>(index, loc);
}

bool Buffer::bindUniformRange(const Val<gl::UInt>& index, const Val<gl::IntPtr>& offset,
                              const Val<gl::SizeiPtr>& size, const SrcLoc loc) const {
    return _executeMethod<CtxBuffer, &CtxBuffer::bindUniformRange>(index, offset, size, loc);
}
                    
bool Buffer::bindShaderStorageBase(const Val<gl::UInt>& index, const SrcLoc loc) const {
    return _executeMethod<CtxBuffer, &CtxBuffer::bindShaderStorageBase>(index, loc);
}

bool Buffer::bindShaderStorageRange(const Val<gl::UInt>& index, const Val<gl::IntPtr>& offset,
                               const Val<gl::SizeiPtr>& size, const SrcLoc loc) const {
    return _executeMethod<CtxBuffer, &CtxBuffer::bindShaderStorageRange>(index, offset, size, loc);
}                        

bool Buffer::getMapAccess(Ptr<gl::BufferMapAccess>& dst, const SrcLoc loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::getMapAccess>(dst, loc);
}

bool Buffer::getMapRangeAccess(Ptr<gl::BitField>& dst, const SrcLoc loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::getMapRangeAccess>(dst, loc);
}

bool Buffer::isImmutable(Ptr<bool>& dst, const SrcLoc loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::isImmutable>(dst, loc);
}

bool Buffer::isMapped(Ptr<bool>& dst, const SrcLoc loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::isMapped>(dst, loc);
}

bool Buffer::getMapLength(Ptr<gl::Int64>& dst, const SrcLoc loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::getMapLength>(dst, loc);
}

bool Buffer::getMapOffset(Ptr<gl::Int64>& dst, const SrcLoc loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::getMapOffset>(dst, loc);
}

bool Buffer::getSize(Ptr<gl::Int>& dst, const SrcLoc loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::getSize>(dst, loc);
}

bool Buffer::getStorageFlags(Ptr<gl::BitField>& dst, const SrcLoc loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::getStorageFlags>(dst, loc);
}

bool Buffer::getUsage(Ptr<gl::BufferUsage>& dst, const SrcLoc loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::getUsage>(dst, loc);
}

bool Buffer::getSubData(const Val<gl::IntPtr>& offset, const Val<gl::SizeiPtr>& size,
                        Ptr<void>& dst, const SrcLoc loc) const {
    return _executeMethod<CtxBuffer, &CtxBuffer::getSubData>(offset, size, dst, loc);
}
bool Buffer::setSubData(const Val<gl::IntPtr>& offset, const Val<gl::SizeiPtr>& size,
                        const Ptr<void>& data, const SrcLoc loc) {
    return _executeMethod<CtxBuffer, &CtxBuffer::setSubData>(offset, size, data, loc);
}

bool Buffer::copySubDataTo(Buffer& dst, const Val<IntPtr>& read_offset,
                           const Val<IntPtr>& write_offset, const Val<SizeiPtr>& size,
                           const SrcLoc loc) const {
    return _executeMethod<CtxBuffer, &CtxBuffer::copySubDataTo>(dst._getVop<CtxBuffer>(), read_offset, write_offset, size, loc);
}

bool Buffer::getMapPointer(Ptr<MapPtr>& dst, const SrcLoc loc) const {
    return _executeGetter<CtxBuffer, &CtxBuffer::getMapPointer>(dst, loc);
}

bool Buffer::map(const Val<gl::BufferMapAccess>& access, Ptr<MapPtr>& dst, const SrcLoc loc){
    return _executeGetter<CtxBuffer, &CtxBuffer::map>(dst, access, loc);
}

bool Buffer::mapRange(const Val<gl::IntPtr>& offset, const Val<gl::SizeiPtr>& size,
                      const Val<gl::BitField>& access, Ptr<MapPtr>& dst,
                      const SrcLoc loc){
    return _executeGetter<CtxBuffer, &CtxBuffer::mapRange>(dst, offset, size, access, loc);
}

bool Buffer::mapFlushRange(const Val<gl::IntPtr>& offset, const Val<gl::SizeiPtr>& size,
                           const SrcLoc loc){
    return _executeMethod<CtxBuffer, &CtxBuffer::mapFlushRange>(offset, size, loc);
}

bool Buffer::unmap(Ptr<bool>& dst, const SrcLoc loc){
    return _executeGetter<CtxBuffer, &CtxBuffer::unmap>(dst, loc);
}

Ptr<gl::CtxBuffer> Buffer::_getPtr(){
    return Object::_getPtr<gl::CtxBuffer>();
}

Ptr<gl::CtxBuffer> Buffer::_getPtr() const {
    return Object::_getPtr<gl::CtxBuffer>();
}