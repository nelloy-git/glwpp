#pragma once

#include "context/CtxObj.hpp"

#include "gl_object/Buffer.hpp"
#include "gl_object/Program.hpp"

namespace glwpp {

class DrawerRef;

namespace detail {

class DrawerImpl : public CtxObj<DrawerImpl> {
public:
    EXPORT DrawerImpl(Context& ctx,
                      const SrcLoc& src_loc);
    EXPORT virtual ~DrawerImpl();
    
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

    std::function<void(DrawerRef&, const ShaderErr&)> on_shader_error;

    template<TState is_gl = TState::Unknown>
    auto setShader(Valuable<const GLenum&> auto&& type,
                   Valuable<const std::string&> auto&& code,
                   Valuable<const SrcLoc&> auto&& src_loc = SrcLoc{}){
        return callMember<&DrawerImpl::_setShader, is_gl>(type, code, GetValuable(src_loc).add());
    }

    template<TState is_gl = TState::Unknown>
    auto bindUniformBlock(Valuable<const std::string&> auto&& block_name,
                          Valuable<const GLuint&> auto&& block_binding,
                          Valuable<GL::Buffer&> auto&& buffer,
                          Valuable<const SrcLoc&> auto&& src_loc = SrcLoc{}){
        return callMember<&DrawerImpl::_bindUniformBlock, is_gl>(program, block_name, block_binding, buffer, src_loc);
    }


private:

    static ShaderErrSrc _GetCompileErrSource(const GLenum& type);
    static ShaderErrSrc _GetLinkErrSource(const GLenum& type);

    EXPORT SetShaderRes _setShader(Context& ctx, const GLenum& type, const std::string& code, const SrcLoc& src_loc);

    EXPORT void _bindUniformBlock(Context& ctx, const std::string& block_name, const GLuint& block_binding, GL::Buffer& buffer, const SrcLoc& src_loc);
    EXPORT void _bindUniformBlock(Context& ctx, const GLuint& block_index, const GLuint& block_binding, GL::Buffer& buffer, const SrcLoc& src_loc);

};

} // namespace detail

class DrawerRef : public CtxObjRef<detail::DrawerImpl> {
public:
    DrawerRef(Valuable<Context&> auto&& ctx,
              Valuable<const SrcLoc&> auto&& src_loc = SrcLoc{}) :
        CtxObjRef(GetValuable(ctx), GetValuable(src_loc)){
    }
    DrawerRef(const std::shared_ptr<detail::DrawerImpl>& sp) :
        CtxObjRef(sp){
    }
};

} // namespace glwpp