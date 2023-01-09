#include "Drawer.hpp"

using namespace glwpp;

Drawer::Drawer(Context& ctx, const SrcLoc& src_loc) :
    CtxObj<Drawer>(ctx),
    _program(ctx, src_loc){
}

Drawer::~Drawer(){
}

void Drawer::_setShaderTest(Context& ctx, const GLenum& type, const std::string& code, const SrcLoc& src_loc){

}

Drawer::Error Drawer::_setShader(Context& ctx, GL::ProgramRef& program, const GLenum& type, const std::string& code, const SrcLoc& src_loc){
    static constexpr IsGlThread IsGL = IsGlThread::True;

    GL::ShaderRef shader(ctx, type, src_loc);
    shader->source<IsGL>(code, src_loc);
    shader->compile<IsGL>(src_loc);
    auto is_compiled = shader->isCompiled<IsGL>(src_loc).value();
    if (!is_compiled){
        return {true, "Compile error:\n" + shader->getInfoLog<IsGL>(src_loc).value()};
    }

    program->attach<IsGL>(shader, src_loc);
    program->link<IsGL>(src_loc);
    auto is_linked = program->isLinked<IsGL>(src_loc).value();
    if (!is_linked){
        return {true, "Link error:\n" + program->getInfoLog<IsGL>(src_loc).value()};
    }

    return {false, std::string{}};
}

void Drawer::_bindUniformBlock(Context& ctx, GL::ProgramRef& program, const std::string& block_name, const GLuint& block_binding, GL::BufferRef& buffer, const SrcLoc& src_loc){
    static constexpr IsGlThread IsGL = IsGlThread::True;

    auto block_index = program->getUniformBlockIndex<IsGL>(block_name, src_loc);
    _bindUniformBlock(ctx, program, block_index.value(), block_binding, buffer, src_loc);
}

void Drawer::_bindUniformBlock(Context& ctx, GL::ProgramRef& program, const GLuint& block_index, const GLuint& block_binding, GL::BufferRef& buffer, const SrcLoc& src_loc){
    static constexpr IsGlThread IsGL = IsGlThread::True;

    program->setUniformBlockBinding<IsGL>(block_index, block_binding, src_loc);
    buffer->bindBase<IsGL>(GLapi::GL_UNIFORM_BUFFER, block_index, src_loc);
}