#include "gl_object/Buffer.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace GL;

Buffer::Buffer(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc) :
    Object(ctx, ctx->gl().call(&Buffer::_initId, src_loc)){
}

Buffer::~Buffer(){
    _callGLCustom(&Buffer::_freeId, id(), SrcLoc{});
}



void Buffer::setData(const GLsizeiptr& size, const GLdata& data, const GLenum& usage, const SrcLoc& src_loc){
    _callGL<&Gl::NamedBufferData>(id(), size, data, usage, src_loc);
}

void Buffer::clearData(const GLenum& internalformat, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    _callGL<&Gl::ClearNamedBufferData>(id(), internalformat, format, type, data, src_loc);
}

void Buffer::setStorage(const GLsizeiptr& size, const GLdata& data, const GLbitfield& flags, const SrcLoc& src_loc){
    _callGL<&Gl::NamedBufferStorage>(id(), size, data, flags, src_loc);
}



void Buffer::setSubData(const GLintptr& offset, const GLsizeiptr& size, const GLdata& data, const SrcLoc& src_loc){
    _callGL<&Gl::NamedBufferSubData>(id(), offset, size, data, src_loc);
}

void Buffer::getSubData(const GLintptr& offset, const GLsizeiptr& size, const GLdata& data, const SrcLoc& src_loc){
    _callGL<&Gl::GetNamedBufferSubData>(id(), offset, size, data, src_loc);
}

void Buffer::copySubDataFrom(const Buffer& readBuffer, const GLintptr& readOffset, const GLintptr& writeOffset, const GLsizeiptr& size, const SrcLoc& src_loc){
    _callGL<&Gl::CopyNamedBufferSubData>(readBuffer.id(), id(), readOffset, writeOffset, size, src_loc);
}

void Buffer::clearSubData(const GLenum& internalformat, const GLintptr& offset, const GLsizeiptr& size, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc){
    _callGL<&Gl::ClearNamedBufferSubData>(id(), internalformat, offset, size, format, type, data, src_loc);
}



void Buffer::bindBase(const GLenum& target, const GLuint& index, const SrcLoc& src_loc){
    _callGL<&Gl::BindBufferBase>(target, index, id(), src_loc);
}

void Buffer::bindRange(const GLenum& target, const GLuint& index, const GLintptr& offset, const GLsizeiptr& size, const SrcLoc& src_loc){
    _callGL<&Gl::BindBufferRange>(target, index, id(), offset, size, src_loc);
}



void Buffer::getPointerv(const GLenum& pname, const GLdataPtr& params, const SrcLoc& src_loc){
    _callGL<&Gl::GetNamedBufferPointerv>(id(), pname, params, src_loc);
}

GL::GLdataPtr Buffer::map(const GLenum& access, const SrcLoc& src_loc){
    return _callGL<&Gl::MapNamedBuffer>(id(), access, src_loc);
}

GL::GLdataPtr Buffer::mapRange(const GLintptr& offset, const GLsizeiptr& length, const GLbitfield& access, const SrcLoc& src_loc){
    return _callGL<&Gl::MapNamedBufferRange>(id(), offset, length, access, src_loc);
}

GL::GLboolean Buffer::unmap(const SrcLoc& src_loc){
    return _callGL<&Gl::UnmapNamedBuffer>(id(), src_loc);
}

void Buffer::flushRange(const GLintptr& offset, const GLsizeiptr& length, const SrcLoc& src_loc){
    _callGL<&Gl::FlushMappedNamedBufferRange>(id(), offset, length, src_loc);
}



void Buffer::getParameteriv(const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc){
    _callGL<&Gl::GetNamedBufferParameteriv>(id(), pname, params, src_loc);
}

GL::GLenum Buffer::getMapAccess(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
        GLint dst;
        glGetNamedBufferParameteriv(*id, GL_BUFFER_ACCESS, dst.get());
        gl.debug(src_loc);
        return GLenum(*reinterpret_cast<unsigned int*>(dst.get()));
    }, id(), src_loc);
}

GL::GLbitfield Buffer::getMapRangeAccess(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
        GLint dst;
        glGetNamedBufferParameteriv(*id, GL_BUFFER_ACCESS_FLAGS, dst.get());
        gl.debug(src_loc);
        return GLbitfield(*reinterpret_cast<unsigned int*>(dst.get()));
    }, id(), src_loc);
}

GL::GLboolean Buffer::isImmutableStorage(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
        GLint dst;
        glGetNamedBufferParameteriv(*id, GL_BUFFER_IMMUTABLE_STORAGE, dst.get());
        gl.debug(src_loc);
        return GLboolean(*reinterpret_cast<unsigned int*>(dst.get()) == GL_TRUE);
    }, id(), src_loc);
}

GL::GLboolean Buffer::isMapped(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
        GLint dst;
        glGetNamedBufferParameteriv(*id, GL_BUFFER_MAPPED, dst.get());
        gl.debug(src_loc);
        return GLboolean(*reinterpret_cast<unsigned int*>(dst.get()) == GL_TRUE);
    }, id(), src_loc);
}

GL::GLint Buffer::getSize(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
        GLint dst;
        glGetNamedBufferParameteriv(*id, GL_BUFFER_SIZE, dst.get());
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}

GL::GLbitfield Buffer::getStorageFlags(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
        GLint dst;
        glGetNamedBufferParameteriv(*id, GL_BUFFER_STORAGE_FLAGS, dst.get());
        gl.debug(src_loc);
        return GLbitfield(*reinterpret_cast<unsigned int*>(dst.get()));
    }, id(), src_loc);
}

GL::GLenum Buffer::getUsage(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
        GLint dst;
        glGetNamedBufferParameteriv(*id, GL_BUFFER_USAGE, dst.get());
        gl.debug(src_loc);
        return GLenum(*reinterpret_cast<unsigned int*>(dst.get()));
    }, id(), src_loc);
}



void Buffer::getParameteri64v(const GLenum& pname, const GLint64Arr& params, const SrcLoc& src_loc){
    _callGL<&Gl::GetNamedBufferParameteri64v>(id(), pname, params, src_loc);
}

GL::GLint64 Buffer::getMapLength(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
        GLint64 dst;
        glGetNamedBufferParameteri64v(*id, GL_BUFFER_MAP_LENGTH, dst.get());
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}

GL::GLint64 Buffer::getMapOffset(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
        GLint64 dst;
        glGetNamedBufferParameteri64v(*id, GL_BUFFER_MAP_OFFSET, dst.get());
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}

GL::GLuint Buffer::_initId(Gl& gl, const SrcLoc& src_loc){
    GLuintArr ids(1);
    gl.CreateBuffers(1, ids, src_loc);
    return *(ids.get());
}

void Buffer::_freeId(Gl& gl, const GLuint& id, const SrcLoc& src_loc){
    GLuintArr ids(1);
    ids.get()[0] = *id;
    gl.DeleteBuffers(1, ids, src_loc);
}