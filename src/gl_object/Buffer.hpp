#pragma once

#include "gl_object/Object.hpp"

namespace glwpp {

namespace GL {

class Buffer : public Object {
public:
    Buffer(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc = SrcLoc{});
    Buffer(const Buffer&) = delete;
    Buffer(const Buffer&&) = delete;
    ~Buffer();

    void setData(const GLsizeiptr& size, const GLdata& data, const GLenum& usage, const SrcLoc& src_loc = SrcLoc{});
    void clearData(const GLenum& internalformat, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc = SrcLoc{});
    void setStorage(const GLsizeiptr& size, const GLdata& data, const GLbitfield& flags, const SrcLoc& src_loc = SrcLoc{});

    void setSubData(const GLintptr& offset, const GLsizeiptr& size, const GLdata& data, const SrcLoc& src_loc = SrcLoc{});
    void getSubData(const GLintptr& offset, const GLsizeiptr& size, const GLdata& data, const SrcLoc& src_loc = SrcLoc{});
    void copySubDataFrom(const Buffer& readBuffer, const GLintptr& readOffset, const GLintptr& writeOffset, const GLsizeiptr& size, const SrcLoc& src_loc = SrcLoc{});
    void clearSubData(const GLenum& internalformat, const GLintptr& offset, const GLsizeiptr& size, const GLenum& format, const GLenum& type, const GLdata& data, const SrcLoc& src_loc = SrcLoc{});

    void bindBase(const GLenum& target, const GLuint& index, const SrcLoc& src_loc = SrcLoc{});
    void bindRange(const GLenum& target, const GLuint& index, const GLintptr& offset, const GLsizeiptr& size, const SrcLoc& src_loc = SrcLoc{});
    
    void getPointerv(const GLenum& pname, const GLdataPtr& params, const SrcLoc& src_loc = SrcLoc{});
    GLdataPtr map(const GLenum& access, const SrcLoc& src_loc = SrcLoc{});
    GLdataPtr mapRange(const GLintptr& offset, const GLsizeiptr& length, const GLbitfield& access, const SrcLoc& src_loc = SrcLoc{});
    GLboolean unmap(const SrcLoc& src_loc = SrcLoc{});
    void flushRange(const GLintptr& offset, const GLsizeiptr& length, const SrcLoc& src_loc = SrcLoc{});

    void getParameteriv(const GLenum& pname, const GLintArr& params, const SrcLoc& src_loc = SrcLoc{});
    GLenum getMapAccess(const SrcLoc& src_loc = SrcLoc{});
    GLbitfield getMapRangeAccess(const SrcLoc& src_loc = SrcLoc{});
    GLboolean isImmutableStorage(const SrcLoc& src_loc = SrcLoc{});
    GLboolean isMapped(const SrcLoc& src_loc = SrcLoc{});
    GLint getSize(const SrcLoc& src_loc = SrcLoc{});
    GLbitfield getStorageFlags(const SrcLoc& src_loc = SrcLoc{});
    GLenum getUsage(const SrcLoc& src_loc = SrcLoc{});

    void getParameteri64v(const GLenum& pname, const GLint64Arr& params, const SrcLoc& src_loc = SrcLoc{});
    GLint64 getMapLength(const SrcLoc& src_loc = SrcLoc{});
    GLint64 getMapOffset(const SrcLoc& src_loc = SrcLoc{});

private:
    static GLuint _initId(Gl& gl, const SrcLoc& src_loc);
    static void _freeId(Gl& gl, const GLuint& id, const SrcLoc& src_loc);

};

} // namespace GL

} // namespace glwpp