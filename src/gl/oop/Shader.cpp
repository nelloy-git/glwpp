#include "glwpp/gl/oop/Shader.hpp"

#include "glad/gl.h"

using namespace glwpp;

namespace {
    static gl::UInt CreateShader(gl::ShaderType type){
        return glCreateShader(static_cast<gl::Enum>(type));
    }
    static void DeleteShader(gl::UInt *id){
        glDeleteShader(*id);
        delete id;
    }
}

Shader::Shader(wptr<Context> ctx, gl::ShaderType type) : 
    ContextData(ctx, &CreateShader, &DeleteShader, type){
}

Shader::Shader(const Shader &&other) :
    ContextData(std::move(other)){
}

Shader::~Shader(){
}

std::shared_future<bool> Shader::getParam_iv(sptr<gl::ShaderParamInt> param, sptr<gl::Int> dst) const {
    if constexpr (AUTOCLEAR) _clear(param, dst);
    return _lockCtx()->onRun.push([id = idPtr(), param, dst](){
        glGetShaderiv(*id, static_cast<gl::Enum>(*param), dst.get());
    });
}

std::shared_future<bool> Shader::getLogInfo(sptr<std::string> dst) const {
    if constexpr (AUTOCLEAR) _clear(dst);
    return _lockCtx()->onRun.push([id = idPtr(), dst](){
        gl::Int length;
        glGetShaderiv(*id, GL_COMPILE_STATUS, &length);
        dst->resize(length);
        glGetShaderInfoLog(*id, length, &length, dst->data());
    });
}

std::shared_future<bool> Shader::compile(sptr<const std::string> code){
    if constexpr (AUTOCLEAR) _clear(code);
    return _lockCtx()->onRun.push([id = idPtr(), code](){
        auto c_code = code->c_str();
        glShaderSource(*id, 1, &c_code, nullptr);
        glCompileShader(*id);
    });
}