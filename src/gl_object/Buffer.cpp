#include "gl_object/Buffer.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace GL;

Buffer::Buffer(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc) :
    Object(ctx, ctx->gl().call([](Gl& gl, const SrcLoc& src_loc){
        unsigned int dst;
        glCreateBuffers(1, &dst);
        gl.debug(src_loc);
        return dst;
    }, src_loc)){
}

Buffer::~Buffer(){
    _callGLCustom([](Gl& gl, const Uint& id){
        glDeleteBuffers(1, id.get());
    }, id());
}



void Buffer::setData(const Sizeiptr& size, const Data& data, const Enum& usage, const SrcLoc& src_loc){
    _callGL<&Gl::NamedBufferData>(id(), size, data, usage, src_loc);
}

void Buffer::clearData(const Enum& internalformat, const Enum& format, const Enum& type, const Data& data, const SrcLoc& src_loc){
    _callGL<&Gl::ClearNamedBufferData>(id(), internalformat, format, type, data, src_loc);
}

void Buffer::setStorage(const Sizeiptr& size, const Data& data, const Bitfield& flags, const SrcLoc& src_loc){
    _callGL<&Gl::NamedBufferStorage>(id(), size, data, flags, src_loc);
}



void Buffer::setSubData(const Intptr& offset, const Sizeiptr& size, const Data& data, const SrcLoc& src_loc){
    _callGL<&Gl::NamedBufferSubData>(id(), offset, size, data, src_loc);
}

void Buffer::getSubData(const Intptr& offset, const Sizeiptr& size, const Data& data, const SrcLoc& src_loc){
    _callGL<&Gl::GetNamedBufferSubData>(id(), offset, size, data, src_loc);
}

void Buffer::copySubDataFrom(const Buffer& readBuffer, const Intptr& readOffset, const Intptr& writeOffset, const Sizeiptr& size, const SrcLoc& src_loc){
    _callGL<&Gl::CopyNamedBufferSubData>(readBuffer.id(), id(), readOffset, writeOffset, size, src_loc);
}

void Buffer::clearSubData(const Enum& internalformat, const Intptr& offset, const Sizeiptr& size, const Enum& format, const Enum& type, const Data& data, const SrcLoc& src_loc){
    _callGL<&Gl::ClearNamedBufferSubData>(id(), internalformat, offset, size, format, type, data, src_loc);
}



void Buffer::bindBase(const Enum& target, const Uint& index, const SrcLoc& src_loc){
    _callGL<&Gl::BindBufferBase>(target, index, id(), src_loc);
}

void Buffer::bindRange(const Enum& target, const Uint& index, const Intptr& offset, const Sizeiptr& size, const SrcLoc& src_loc){
    _callGL<&Gl::BindBufferRange>(target, index, id(), offset, size, src_loc);
}



void Buffer::getPointerv(const Enum& pname, const DataPtr& params, const SrcLoc& src_loc){
    _callGL<&Gl::GetNamedBufferPointerv>(id(), pname, params, src_loc);
}

GL::DataPtr Buffer::map(const Enum& access, const SrcLoc& src_loc){
    return _callGL<&Gl::MapNamedBuffer>(id(), access, src_loc);
}

GL::DataPtr Buffer::mapRange(const Intptr& offset, const Sizeiptr& length, const Bitfield& access, const SrcLoc& src_loc){
    return _callGL<&Gl::MapNamedBufferRange>(id(), offset, length, access, src_loc);
}

GL::Boolean Buffer::unmap(const SrcLoc& src_loc){
    return _callGL<&Gl::UnmapNamedBuffer>(id(), src_loc);
}

void Buffer::flushRange(const Intptr& offset, const Sizeiptr& length, const SrcLoc& src_loc){
    _callGL<&Gl::FlushMappedNamedBufferRange>(id(), offset, length, src_loc);
}



GL::Enum Buffer::getMapAccess(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        unsigned int dst;
        glGetNamedBufferParameteriv(*id, GL_BUFFER_ACCESS, reinterpret_cast<int*>(&dst));
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}

GL::Bitfield Buffer::getMapRangeAccess(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        unsigned int dst;
        glGetNamedBufferParameteriv(*id, GL_BUFFER_ACCESS_FLAGS, reinterpret_cast<int*>(&dst));
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}

GL::Boolean Buffer::isImmutableStorage(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        int dst;
        glGetNamedBufferParameteriv(*id, GL_BUFFER_IMMUTABLE_STORAGE, &dst);
        gl.debug(src_loc);
        return (unsigned char)(dst == GL_TRUE);
    }, id(), src_loc);
}

GL::Boolean Buffer::isMapped(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        int dst;
        glGetNamedBufferParameteriv(*id, GL_BUFFER_MAPPED, &dst);
        gl.debug(src_loc);
        return (unsigned char)(dst == GL_TRUE);
    }, id(), src_loc);
}

GL::Int Buffer::getSize(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        int dst;
        glGetNamedBufferParameteriv(*id, GL_BUFFER_SIZE, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}

GL::Bitfield Buffer::getStorageFlags(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        unsigned int dst;
        glGetNamedBufferParameteriv(*id, GL_BUFFER_STORAGE_FLAGS, reinterpret_cast<int*>(&dst));
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}

GL::Enum Buffer::getUsage(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        unsigned int dst;
        glGetNamedBufferParameteriv(*id, GL_BUFFER_USAGE, reinterpret_cast<int*>(&dst));
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}



GL::Int64 Buffer::getMapLength(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        khronos_int64_t dst;
        glGetNamedBufferParameteri64v(*id, GL_BUFFER_MAP_LENGTH, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}

GL::Int64 Buffer::getMapOffset(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        khronos_int64_t dst;
        glGetNamedBufferParameteri64v(*id, GL_BUFFER_MAP_OFFSET, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}