#include "glwpp/gl/oop/Buffer.hpp"

using namespace glwpp;

namespace {
    static gl::UInt GenBufferId(){
        gl::UInt id;
        gl::GenBuffers(1, &id);
        return id;
    };
    static void DeleteBufferId(gl::UInt* id){
        gl::DeleteBuffers(1, id);
        delete id;
    };
    static void NamedStorage(const sptr<gl::UInt> id, gl::SizeiPtr size, const void *data, gl::BufferStorageFlagBitfield flags){
        gl::NamedBufferStorage(*id, size, data, flags.fields);
    }
    static void NamedData(const sptr<gl::UInt> id, gl::SizeiPtr size, const void *data, gl::BufferUsage usage){
        gl::NamedBufferData(*id, size, data, static_cast<gl::Enum>(usage));
    }
    static void SetNamedBufferSubData(const sptr<gl::UInt> id, gl::IntPtr offset, gl::SizeiPtr size, const void *data){
        gl::NamedBufferSubData(*id, offset, size, data);
    };
    static void GetNamedBufferSubData(const sptr<gl::UInt> id, gl::IntPtr offset, gl::SizeiPtr size, void *dst){
        gl::GetNamedBufferSubData(*id, offset, size, dst);
    };
    static void CopyNamedBufferSubData(const sptr<gl::UInt> src_id, const sptr<gl::UInt> dst_id,
                                       gl::IntPtr src_offset, gl::IntPtr dst_offset, gl::SizeiPtr size){
        gl::CopyNamedBufferSubData(*src_id, *dst_id, src_offset, dst_offset, size);
    };
    static void* GetNamedBufferPointerv(const sptr<gl::UInt> id){
        static const gl::Enum GL_BUFFER_MAP_POINTER = 0x88BD;

        void *ptr;
        gl::GetNamedBufferPointerv(*id, GL_BUFFER_MAP_POINTER, &ptr);
        return ptr;
    };
    static void* MapNamedBuffer(const sptr<gl::UInt> id, gl::BufferMapAccess access){
        return gl::MapNamedBuffer(*id, static_cast<gl::Enum>(access));
    };
    static void* MapNamedBufferRange(const sptr<gl::UInt> id, gl::IntPtr offset, gl::SizeiPtr size, gl::BufferMapRangeAccessBitfield access){
        return gl::MapNamedBufferRange(*id, offset, size, access.fields);
    };
    static void UnmapNamedBuffer(const sptr<gl::UInt> id){
        gl::UnmapNamedBuffer(*id);
    }
    static void FlushMappedNamedBufferRange(const sptr<gl::UInt> id, gl::IntPtr offset, gl::SizeiPtr size){
        gl::FlushMappedNamedBufferRange(*id, offset, size);
    }
    static gl::Int64 GetNamedBufferParameteri64v(const sptr<gl::UInt> id, gl::BufferParamInt param){
        gl::Int64 val;
        gl::GetNamedBufferParameteri64v(*id, static_cast<gl::Enum>(param), &val);
        return val;
    }
    static gl::Int GetNamedBufferParameteriv(const sptr<gl::UInt> id, gl::BufferParamInt param){
        gl::Int val;
        gl::GetNamedBufferParameteriv(*id, static_cast<gl::Enum>(param), &val);
        return val;
    }
};

Buffer::Buffer(wptr<Context> ctx) :
    ContextData(ctx, &GenBufferId, &DeleteBufferId){
}

Buffer::Buffer(const Buffer&& other) :
    ContextData(std::move(other)){
}

Buffer::~Buffer(){
}

std::shared_future<bool> Buffer::storage(const void *data, gl::SizeiPtr size, gl::BufferStorageFlagBitfield flags){
    return _execute(&NamedStorage, idPtr(), size, data, flags);
}

std::shared_future<bool> Buffer::data(const void *data, gl::SizeiPtr size, gl::BufferUsage usage){
    return _execute(&NamedData, idPtr(), size, data, usage);
}

std::shared_future<bool> Buffer::setSubData(const void *data, gl::SizeiPtr size, gl::IntPtr offset){
    return _execute(&SetNamedBufferSubData, idPtr(), offset, size, data);
}

std::shared_future<bool> Buffer::getSubData(void *dst, gl::SizeiPtr size, gl::IntPtr offset) const {
    return _execute(&GetNamedBufferSubData, idPtr(), offset, size, dst);
}

std::shared_future<bool> Buffer::copySubData(Buffer &dst, gl::IntPtr read_offset, gl::IntPtr write_offset, gl::SizeiPtr size) const {
    return _execute(&CopyNamedBufferSubData, idPtr(), dst.idPtr(), read_offset, write_offset, size);
}

std::shared_future<void*> Buffer::getMapPointer() const {
    return _execute(&GetNamedBufferPointerv, idPtr());
}

std::shared_future<void*> Buffer::map(gl::BufferMapAccess access){
    return _execute(&MapNamedBuffer, idPtr(), access);
}

std::shared_future<void*> Buffer::mapRange(gl::IntPtr offset, gl::SizeiPtr size, gl::BufferMapRangeAccessBitfield access){
    return _execute(&MapNamedBufferRange, idPtr(), offset, size, access);
}

std::shared_future<bool> Buffer::unmap(){
    return _execute(&UnmapNamedBuffer, idPtr());
}

std::shared_future<bool> Buffer::mapFlushRange(gl::IntPtr offset, gl::SizeiPtr size){
    return _execute(&FlushMappedNamedBufferRange, idPtr(), offset, size);
}

std::shared_future<gl::Int64> Buffer::getParamInt64(gl::BufferParamInt param) const {
    return _execute(&GetNamedBufferParameteri64v, idPtr(), param);
}

std::shared_future<gl::Int> Buffer::getParamInt(gl::BufferParamInt param) const {
    return _execute(&GetNamedBufferParameteriv, idPtr(), param);
}