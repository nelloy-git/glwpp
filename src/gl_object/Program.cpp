#include "gl_object/Program.hpp"

using namespace glwpp;
using namespace glwpp::GL;

GLuint Program::_Init(Context& ctx, const SrcLoc& src_loc){
    return ctx.gl().CreateProgram<TState::True>(src_loc);
}

void Program::_Free(Context& ctx, const GLuint& id, const SrcLoc& src_loc){
    ctx.gl().DeleteProgram<TState::True>(id, src_loc);
}

void Program::_attach(Context& ctx, const Shader& shader, const SrcLoc& src_loc){
    ctx.gl().AttachShader<TState::True>(id().value(), shader.id().value(), src_loc);
}

void Program::_link(Context& ctx, const SrcLoc& src_loc){
    ctx.gl().LinkProgram<TState::True>(id().value(), src_loc);
}

void Program::_validate(Context& ctx, const SrcLoc& src_loc) const {
    ctx.gl().ValidateProgram<TState::True>(id().value(), src_loc);
}

void Program::_use(Context& ctx, const SrcLoc& src_loc) const {
    ctx.gl().UseProgram<TState::True>(id().value(), src_loc);
}

GLint Program::_getParameteriv(Context& ctx, const GLenum& pname, const SrcLoc& src_loc) const {
    GLint dst;
    ctx.gl().GetProgramiv<TState::True>(id().value(), pname, &dst, src_loc);
    return dst;
}

std::string Program::_getInfoLog(Context& ctx, const SrcLoc& src_loc) const {
    GLint len = _getParameteriv(ctx, GL_INFO_LOG_LENGTH, src_loc);
    std::string dst;
    dst.resize(len);
    ctx.gl().GetProgramInfoLog<TState::True>(id().value(), len, &len, dst.data(), src_loc);
    return dst;
}
