#pragma once

#include "gl_object/Buffer.hpp"
#include "gl_object/Program.hpp"

namespace glwpp {

class Drawer : protected CallOptimizer {
public:
    EXPORT Drawer(Context& ctx, const SrcLoc& src_loc = SrcLoc{});
    EXPORT virtual ~Drawer();

    using Error = std::pair<bool, std::string>;

    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<Error>> setVertexShader(Valuable<const std::string&> auto&& code,
                                              Valuable<const SrcLoc&> auto&& src_loc = SrcLoc{}){
        return call<&_setShader, is_gl>(_program, GLapi::GL_VERTEX_SHADER, code, GetValuable(src_loc).add());
    }

    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<Error>> setFragmentShader(Valuable<const std::string&> auto&& code,
                                                Valuable<const SrcLoc&> auto&& src_loc = SrcLoc{}){
        return call<&_setShader, is_gl>(_program, GLapi::GL_FRAGMENT_SHADER, code, GetValuable(src_loc).add());
    }

private:
    GL::Program _program;

    EXPORT static Error _setShader(Context& ctx, GL::Program& program, const GLenum& type, const std::string& code, const SrcLoc& src_loc);
    EXPORT static void _bindUniformBlock(Context& ctx, GL::Program& program, const std::string& block_name, const GLuint& block_binding, GL::Buffer& buffer, const SrcLoc& src_loc);
    EXPORT static void _bindUniformBlock(Context& ctx, GL::Program& program, const GLuint& block_index, const GLuint& block_binding, GL::Buffer& buffer, const SrcLoc& src_loc);

};

} // namespace glwpp