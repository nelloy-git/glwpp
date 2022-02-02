#include "glwpp/gl/oop/Buffer.hpp"

#include "glad/gl.h"

using namespace glwpp;

namespace {
    static gl::UInt GenBufferId(){
        gl::UInt id;
        glCreateBuffers(1, &id);
        return id;
    };
    static void DeleteBufferId(gl::UInt* id){
        glDeleteBuffers(1, id);
        delete id;
    };
};

Buffer::Buffer(wptr<Context> ctx) :
    ContextData(ctx, &GenBufferId, &DeleteBufferId){
}

Buffer::Buffer(const Buffer&& other) :
    ContextData(std::move(other)){
}

Buffer::~Buffer(){
}

std::shared_future<bool> Buffer::data(Vop<const gl::SizeiPtr> size, Vop<const Data> data, Vop<const gl::BufferUsage> usage){
    return _lockCtx()->onRun.push([id = _idPtr(), size, data, usage](){
        auto &v_size = getVopRef(size);
        auto &v_data = getVopRef(data);
        auto &v_usage = getVopRef(usage);

        glNamedBufferData(*id, v_size, v_data, static_cast<gl::Enum>(v_usage));
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Buffer::storage(Vop<const gl::SizeiPtr> size, Vop<const Data> data, Vop<const gl::BitField> flags){
    return _lockCtx()->onRun.push([id = _idPtr(), size, data, flags](){
        auto &v_size = getVopRef(size);
        auto &v_data = getVopRef(data);
        auto &v_flags = getVopRef(flags);

        glNamedBufferStorage(*id, v_size, v_data, v_flags);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Buffer::getParam_i64v(Vop<const gl::BufferParam> param, Ptr<gl::Int64> dst) const {
    return _lockCtx()->onRun.push([id = _idPtr(), param, dst](){
        auto &v_param = getVopRef(param);
        auto p_dst = getPtrValue(dst);

        glGetNamedBufferParameteri64v(*id, static_cast<gl::Enum>(v_param), p_dst);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Buffer::getParam_iv(Vop<const gl::BufferParam> param, Ptr<gl::Int> dst) const {
    return _lockCtx()->onRun.push([id = _idPtr(), param, dst](){
        auto &v_param = getVopRef(param);
        auto p_dst = getPtrValue(dst);

        glGetNamedBufferParameteriv(*id, static_cast<gl::Enum>(v_param), p_dst);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Buffer::setSubData(Vop<const gl::IntPtr> offset, Vop<const gl::SizeiPtr> size, Vop<const Data> data){
    return _lockCtx()->onRun.push([id = _idPtr(), offset, size, data](){
        auto &v_offset = getVopRef(offset);
        auto &v_size = getVopRef(size);
        auto &v_data = getVopRef(data);
        
        glNamedBufferSubData(*id, v_offset, v_size, v_data);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Buffer::getSubData(Vop<const gl::IntPtr> offset, Vop<const gl::SizeiPtr> size, Vop<Data> dst) const {
    return _lockCtx()->onRun.push([id = _idPtr(), offset, size, dst](){
        auto &v_offset = getVopRef(offset);
        auto &v_size = getVopRef(size);
        auto v_dst = getVopValue(dst);
        
        glGetNamedBufferSubData(*id, v_offset, v_size, v_dst);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Buffer::copySubData(Ptr<Buffer> dst, Vop<const gl::IntPtr> read_offset,
                                             Vop<const gl::IntPtr> write_offset, Vop<const gl::SizeiPtr> size) const {
    return _lockCtx()->onRun.push([id = _idPtr(), dst, read_offset, write_offset, size](){
        auto p_dst = getPtrValue(dst);
        auto &v_read_offset = getVopRef(read_offset);
        auto &v_write_offset = getVopRef(write_offset);
        auto &v_size = getVopRef(size);

        glCopyNamedBufferSubData(*id, p_dst->id(), v_read_offset, v_write_offset, v_size);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Buffer::getMapPointer(Ptr<MapPtr> dst) const {
    return _lockCtx()->onRun.push([id = _idPtr(), dst](){
        auto p_dst = getPtrValue(dst); 

        glGetNamedBufferPointerv(*id, GL_BUFFER_MAP_POINTER, p_dst);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Buffer::map(Vop<const gl::BufferMapAccess> access, Ptr<MapPtr> dst){
    return _lockCtx()->onRun.push([id = _idPtr(), access, dst](){
        auto &v_access = getVopRef(access);
        auto p_dst = getPtrValue(dst);

        *p_dst = glMapNamedBuffer(*id, static_cast<gl::Enum>(v_access));
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Buffer::mapRange(Vop<const gl::IntPtr> offset, Vop<const gl::SizeiPtr> size,
                                          Vop<const gl::BitField> access, Ptr<MapPtr> dst){
    return _lockCtx()->onRun.push([id = _idPtr(), offset, size, access, dst](){
        auto &v_offset = getVopRef(offset);
        auto &v_size = getVopRef(size);
        auto &v_access = getVopRef(access);
        auto p_dst = getPtrValue(dst);

        *p_dst = glMapNamedBufferRange(*id, v_offset, v_size, v_access);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Buffer::mapFlushRange(Vop<const gl::IntPtr> offset, Vop<const gl::SizeiPtr> size){
    return _lockCtx()->onRun.push([id = _idPtr(), offset, size](){
        auto &v_offset = getVopRef(offset);
        auto &v_size = getVopRef(size);

        glFlushMappedBufferRange(*id, v_offset, v_size);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Buffer::unmap(){
    return _lockCtx()->onRun.push([id = _idPtr()](){
        glUnmapNamedBuffer(*id);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}