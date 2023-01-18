#include "Drawer.hpp"

#include "utils/GlobalThreadPool.hpp"

using namespace glwpp::detail;

DrawerImpl::DrawerImpl(Context& ctx, const SrcLoc& src_loc) :
    CtxObj<DrawerImpl>(ctx),
    on_shader_error([](DrawerRef&, const ShaderErr&){return;}),
    program(GL::Program::Make(ctx, src_loc)){
}

DrawerImpl::~DrawerImpl(){
}

DrawerImpl::ShaderErrSrc DrawerImpl::_GetCompileErrSource(const GLenum& type){
    switch (type){
    case GL_VERTEX_SHADER: return ShaderErrSrc::VertexShaderCompile;
    case GL_FRAGMENT_SHADER: return ShaderErrSrc::FragmentShaderCompile;
    
    default: return ShaderErrSrc::Unknown;
    }
}

DrawerImpl::ShaderErrSrc DrawerImpl::_GetLinkErrSource(const GLenum& type){
    switch (type){
    case GL_VERTEX_SHADER: return ShaderErrSrc::VertexShaderLink;
    case GL_FRAGMENT_SHADER: return ShaderErrSrc::FragmentShaderLink;
    
    default: return ShaderErrSrc::Unknown;
    }
}

DrawerImpl::SetShaderRes DrawerImpl::_setShader(Context& ctx, const GLenum& type, const std::string& code, const SrcLoc& src_loc){
    auto shader = GL::Shader::Make(ctx, type, src_loc);
    shader->source<TState::True>(code, src_loc);
    shader->compile<TState::True>(src_loc);
    auto is_compiled = (shader->getParameteriv<TState::True>(GL_COMPILE_STATUS, src_loc) == GL_TRUE);
    if (!is_compiled){
        auto err = std::pair{_GetCompileErrSource(type), shader->getInfoLog<TState::True>(src_loc)};
        auto ref = DrawerRef(this->shared_from_this());
        on_shader_error(ref, err);
        return err;
    }

    program->attach<TState::True>(shader, src_loc);
    program->link<TState::True>(src_loc);
    auto is_linked = (program->getParameteriv<TState::True>(GL_LINK_STATUS, src_loc) == GL_FALSE);
    if (!is_linked){
        auto err = std::pair{_GetLinkErrSource(type), program->getInfoLog<TState::True>(src_loc)};
        auto ref = DrawerRef(this->shared_from_this());
        on_shader_error(ref, err);
        return err;
    }

    return std::nullopt;
}

void DrawerImpl::_bindUniformBlock(Context& ctx, const std::string& block_name, const GLuint& block_binding, GL::Buffer& buffer, const SrcLoc& src_loc){
    // auto block_index = program->getUniformBlockIndex<TState::True>(block_name, src_loc);
    // _bindUniformBlock(ctx, block_index.value(), block_binding, buffer, src_loc);
}

void DrawerImpl::_bindUniformBlock(Context& ctx, const GLuint& block_index, const GLuint& block_binding, GL::Buffer& buffer, const SrcLoc& src_loc){
    // program->setUniformBlockBinding<TState::True>(block_index, block_binding, src_loc);
    // buffer->bindBase<TState::True>(GL_UNIFORM_BUFFER, block_index, src_loc);
}