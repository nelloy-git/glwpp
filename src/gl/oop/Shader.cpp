#include "glwpp/gl/oop/Shader.hpp"

using namespace glwpp;

namespace {
    static gl::UInt CreateShader(gl::ShaderType type){
        return gl::CreateShader(static_cast<gl::Enum>(type));
    }
    static void DeleteShader(gl::UInt *id){
        gl::DeleteShader(*id);
        delete id;
    }
    static gl::Int GetParamInt(const sptr<gl::UInt> id, gl::ShaderParamInt param){
        gl::Int val;
        gl::GetShaderiv(*id, static_cast<gl::Enum>(param), &val);
        return val;
    }
    static bool Compile(const sptr<gl::UInt> id, const std::string *code){
        auto c_code = code->c_str();
        gl::ShaderSource(*id, 1, &c_code, nullptr);
        gl::CompileShader(*id);
        return GetParamInt(id, gl::ShaderParamInt::CompileStatus);
    }
    static std::string GetLogInfo(const sptr<gl::UInt> id){
        gl::Int length = GetParamInt(id, gl::ShaderParamInt::InfoLogLength);

        std::string msg(length, '\0');
        gl::GetShaderInfoLog(*id, length, &length, msg.data());
        return msg;
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

std::shared_future<bool> Shader::compile(const std::string *code){
    return _execute(&Compile, idPtr(), code);
}

std::shared_future<gl::Int> Shader::getParamInt(gl::ShaderParamInt param) const {
    return _execute(&GetParamInt, idPtr(), param);
}

std::shared_future<std::string> Shader::getLogInfo() const {
    return _execute(&GetLogInfo, idPtr());
}