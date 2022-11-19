#pragma once

#include "gl_object/Object.hpp"
#include "gl_object/Shader.hpp"

namespace glwpp {

namespace GL {

class Program : public Object {
public:
    Program(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc = SrcLoc{});
    Program(const Program&) = delete;
    Program(const Program&&) = delete;
    ~Program();

    void attach(const Shader& shader, const SrcLoc& src_loc = SrcLoc{});
    void link(const SrcLoc& src_loc = SrcLoc{});
    void validate(const SrcLoc& src_loc = SrcLoc{});
    void use(const SrcLoc& src_loc = SrcLoc{});

    GLint getAttribLocation(const String& name, const SrcLoc& src_loc = SrcLoc{});
    void bindAttribLocation(const GLuint& attr_index, const String& name, const SrcLoc& src_loc = SrcLoc{});
    GLint getUniformLocation(const String& name, const SrcLoc& src_loc = SrcLoc{});
    GLuint getUniformBlockIndex(const String& name, const SrcLoc& src_loc = SrcLoc{});

    GLboolean isLinked(const SrcLoc& src_loc = SrcLoc{});
    GLboolean isValidated(const SrcLoc& src_loc = SrcLoc{});
    GLint getAttachedShadersCount(const SrcLoc& src_loc = SrcLoc{});
    GLint getActiveAttributesCount(const SrcLoc& src_loc = SrcLoc{});
    GLint getActiveAttributeMaxNameLength(const SrcLoc& src_loc = SrcLoc{});
    GLint getActiveUniformsCount(const SrcLoc& src_loc = SrcLoc{});
    GLint getActiveUniformMaxNameLength(const SrcLoc& src_loc = SrcLoc{});
    String getInfoLog(const SrcLoc& src_loc = SrcLoc{});

private:
    static GLuint _initId(Gl& gl, const SrcLoc& src_loc);
    static void _freeId(Gl& gl, const GLuint& id, const SrcLoc& src_loc);

};

} // namespace GL

} // namespace glwpp