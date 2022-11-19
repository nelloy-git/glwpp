#pragma once

#include "gl_object/Object.hpp"

namespace glwpp {

namespace GL {

class Shader : public Object {
public:
    Shader(const std::shared_ptr<Context>& ctx, const GLenum& type, const SrcLoc& src_loc = SrcLoc{});
    Shader(const Shader&) = delete;
    Shader(const Shader&&) = delete;
    ~Shader();

    void source(const String& code, const SrcLoc& src_loc = SrcLoc{});
    void compile(const SrcLoc& src_loc = SrcLoc{});

    GLenum getType(const SrcLoc& src_loc = SrcLoc{});
    GLboolean isCompiled(const SrcLoc& src_loc = SrcLoc{});
    GLint getSourceLength(const SrcLoc& src_loc = SrcLoc{});
    String getInfoLog(const SrcLoc& src_loc = SrcLoc{});

private:
    static GLuint _initId(Gl& gl, const GLenum& type, const SrcLoc& src_loc);
    static void _freeId(Gl& gl, const GLuint& id, const SrcLoc& src_loc);

};

} // namespace GL

} // namespace glwpp