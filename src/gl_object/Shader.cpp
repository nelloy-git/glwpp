#include "gl_object/Program.hpp"

using namespace glwpp;
using namespace glwpp::GL;

std::function<GLuint(Context&, const SrcLoc&)> Shader::_GetInit(const GLenum& type){
    return [type](Context& ctx, const SrcLoc& src_loc){
        return ctx.gl().CreateShader<TState::True>(type, src_loc);
    };
}

void Shader::_Free(Context& ctx, const GLuint& id, const SrcLoc& src_loc){
    ctx.gl().DeleteShader<TState::True>(id, src_loc);
}

void Shader::_source(Context& ctx, const std::string& code, const SrcLoc& src_loc){
    auto c_str = code.c_str();
    int len = static_cast<int>(code.size());
    ctx.gl().ShaderSource<TState::True>(*id(), 1, &c_str, &len, src_loc);
}

void Shader::_compile(Context& ctx, const SrcLoc& src_loc){
    ctx.gl().CompileShader<TState::True>(id().value(), src_loc);
}

GLint Shader::_getParameteriv(Context& ctx, const GLenum& pname, const SrcLoc& src_loc) const {
    GLint dst;
    ctx.gl().GetShaderiv<TState::True>(id().value(), pname, &dst, src_loc);
    return dst;
}

std::string Shader::_getInfoLog(Context& ctx, const SrcLoc& src_loc) const {
    GLint len = _getParameteriv(ctx, GL_INFO_LOG_LENGTH, src_loc);
    std::string dst;
    dst.resize(len);
    ctx.gl().GetShaderInfoLog<TState::True>(id().value(), len, &len, dst.data(), src_loc);
    return dst;
}