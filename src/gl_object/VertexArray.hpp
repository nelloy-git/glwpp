#pragma once

#include "gl_object/Object.hpp"
#include "gl_object/Buffer.hpp"

namespace glwpp {

namespace GL {

class VertexArray : public Object {
public:
    VertexArray(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc = SrcLoc{});
    VertexArray(const VertexArray&) = delete;
    VertexArray(const VertexArray&&) = delete;
    ~VertexArray();

    void enableAttrib(const GLuint& index, const SrcLoc& src_loc = SrcLoc{});
    void disableAttrib(const GLuint& index, const SrcLoc& src_loc = SrcLoc{});
    void setAttribBinding(const GLuint& index, const GLuint& binding, const SrcLoc& src_loc = SrcLoc{});
    void setAttribFormat(const GLuint& index, const GLint& size, const GLenum& type, const GLboolean& normalized, const GLuint& relative_offset, const SrcLoc& src_loc = SrcLoc{});
    void setBindingDivisor(const GLuint& binding, const GLuint& divisor, const SrcLoc& src_loc = SrcLoc{});
    void setElementBuffer(const Buffer& buffer, const SrcLoc& src_loc = SrcLoc{});
    void setVertexBuffer(const GLuint& binding, const Buffer& buffer, const GLintptr& offset, const GLsizei& stride, const SrcLoc& src_loc = SrcLoc{});

    GLboolean isAttribEnabled(const GLuint& index, const SrcLoc& src_loc = SrcLoc{});
    GLint getAttribSize(const GLuint& index, const SrcLoc& src_loc = SrcLoc{});
    GLint getAttribStride(const GLuint& index, const SrcLoc& src_loc = SrcLoc{});
    GLenum getAttribType(const GLuint& index, const SrcLoc& src_loc = SrcLoc{});
    GLboolean isAttribNormalized(const GLuint& index, const SrcLoc& src_loc = SrcLoc{});
    GLboolean isAttribInteger(const GLuint& index, const SrcLoc& src_loc = SrcLoc{});
    GLboolean isAttribLong(const GLuint& index, const SrcLoc& src_loc = SrcLoc{});
    GLint getAttribDivisor(const GLuint& index, const SrcLoc& src_loc = SrcLoc{});
    GLint64 getAttribBindingOffset(const GLuint& index, const SrcLoc& src_loc = SrcLoc{});

private:
    static GLuint _initId(Gl& gl, const SrcLoc& src_loc);
    static void _freeId(Gl& gl, const GLuint& id, const SrcLoc& src_loc);

};

} // namespace GL

} // namespace glwpp