#pragma once

#include "context/CtxObj.hpp"

#include "gl_object/Buffer.hpp"
#include "gl_object/Program.hpp"

namespace glwpp {

class Drawer : public CtxObj<Drawer> {
public:
    EXPORT Drawer(Context& ctx, const SrcLoc& src_loc = SrcLoc{});
    EXPORT virtual ~Drawer();

    using Error = std::pair<bool, std::string>;

    enum class ErrorSource {
        VertexShaderCompilation,
        VertexShaderLinkage,
    };

    // Event<Drawer&, const ErrorSource&, const std::string&> on_error_nongl;

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

    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> bindUniformBlock(Valuable<const std::string&> auto&& block_name,
                                              Valuable<const GLuint&> auto&& block_binding,
                                              Valuable<GL::Buffer&> auto&& buffer,
                                              Valuable<const SrcLoc&> auto&& src_loc = SrcLoc{}){
        return call<&_bindUniformBlock, is_gl>(_program, block_name, block_binding, buffer, src_loc);
    }

    template<IsGlThread is_gl = IsGlThread::Unknown>
    Value<std::future<void>> setShaderTest(Valuable<const std::string&> auto&& code,
                                           Valuable<const SrcLoc&> auto&& src_loc = SrcLoc{}){
        auto s = this->shared_from_this();
        return callMember<&Drawer::_setShaderTest, is_gl>(GLapi::GL_VERTEX_SHADER, code, GetValuable(src_loc).add());
    }


private:
    struct Inner {
        GL::Program program;
        std::optional<std::function<void(const Error&)>> error_callback;
    };
    GL::Program _program;

    EXPORT void _setShaderTest(Context& ctx, const GLenum& type, const std::string& code, const SrcLoc& src_loc);

    EXPORT static Error _setShader(Context& ctx, GL::Program& program, const GLenum& type, const std::string& code, const SrcLoc& src_loc);
    EXPORT static void _bindUniformBlock(Context& ctx, GL::Program& program, const std::string& block_name, const GLuint& block_binding, GL::Buffer& buffer, const SrcLoc& src_loc);
    EXPORT static void _bindUniformBlock(Context& ctx, GL::Program& program, const GLuint& block_index, const GLuint& block_binding, GL::Buffer& buffer, const SrcLoc& src_loc);

};

} // namespace glwpp