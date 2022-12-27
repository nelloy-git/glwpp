#pragma once

#include "gl_object/Program.hpp"

namespace glwpp {

class Drawer : protected CallOptimizer {
public:
    EXPORT Drawer(Context& ctx, const SrcLoc& src_loc = SrcLoc{});
    EXPORT virtual ~Drawer();

    using CompileResult = std::pair<bool, std::string>;

    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::optional<CompileResult>> setVertexShader(Valuable<const std::string&> auto&& code,
                                                        Valuable<const SrcLoc&> auto&& src_loc = SrcLoc{}){
        return call<&_setShader, is_gl>(_program, GL_VERTEX_SHADER, code, GetValuable(src_loc).add());
    }

    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::optional<CompileResult>> setFragmentShader(Valuable<const std::string&> auto&& code,
                                                          Valuable<const SrcLoc&> auto&& src_loc = SrcLoc{}){
        return call<&_setShader, is_gl>(_program, GL_FRAGMENT_SHADER, code, GetValuable(src_loc).add());
    }

private:
    GL::Program _program;

    EXPORT static CompileResult _setShader(Context& ctx, GL::Program& program, const GLenum& type, const std::string& code, const SrcLoc& src_loc);


};

} // namespace glwpp