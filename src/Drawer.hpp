#pragma once

#include <optional>

#include "context/CtxObj.hpp"

#include "gl_object/Buffer.hpp"
#include "gl_object/Program.hpp"

namespace glwpp {

class Drawer : public CtxObj<Drawer> {
public:
    static Value<Drawer> Make(Valuable<Context&> auto&& ctx,
                              Valuable<const SrcLoc&> auto src_loc){
        return Value<Drawer>::Make(new Drawer(GetValuable(ctx), GetValuable(src_loc)));
    }
    EXPORT virtual ~Drawer();
    
    Value<GL::Program> program;

    enum class ShaderErrSrc {
        VertexShaderCompile,
        VertexShaderLink,
        FragmentShaderCompile,
        FragmentShaderLink,
        Unknown
    };

    using ShaderErr = std::pair<ShaderErrSrc, std::string>;
    using SetShaderRes = std::optional<ShaderErr>;

    Event<Drawer&, const ShaderErr&> on_shader_error;

    template<TState IsCtx = TState::Unknown>
    auto setShader(Valuable<const GLenum&> auto&& type,
                   Valuable<const std::string&> auto&& code,
                   Valuable<const SrcLoc&> auto&& src_loc = SrcLoc{}){
        return callMember<IsCtx, &Drawer::_setShader>(type, code, GetValuable(src_loc).add());
    }

    template<TState IsCtx = TState::Unknown>
    auto bindUniformBlock(Valuable<const std::string&> auto&& block_name,
                          Valuable<const GLuint&> auto&& block_binding,
                          Valuable<GL::Buffer&> auto&& buffer,
                          Valuable<const SrcLoc&> auto&& src_loc = SrcLoc{}){
        return callMember<&Drawer::_bindUniformBlock, IsCtx>(program, block_name, block_binding, buffer, src_loc);
    }


private:
    EXPORT Drawer(Context& ctx, const SrcLoc& src_loc);

    static ShaderErrSrc _GetCompileErrSource(const GLenum& type);
    static ShaderErrSrc _GetLinkErrSource(const GLenum& type);

    EXPORT SetShaderRes _setShader(Context& ctx, const GLenum& type, const std::string& code, const SrcLoc& src_loc);
    EXPORT void _setUniform();

    EXPORT void _bindUniformBlock(Context& ctx, const std::string& block_name, const GLuint& block_binding, GL::Buffer& buffer, const SrcLoc& src_loc);
    EXPORT void _bindUniformBlock(Context& ctx, const GLuint& block_index, const GLuint& block_binding, GL::Buffer& buffer, const SrcLoc& src_loc);

};

} // namespace glwpp