#include "glwpp/gl/oop/Shader.hpp"

#include "glad/gl.h"

using namespace glwpp;

namespace {
    static gl::UInt CreateShader(Vop<const gl::ShaderType> type){
        auto &v_type = getVopRef(type);
        return glCreateShader(static_cast<gl::Enum>(v_type));
    }
    static void DeleteShader(gl::UInt *id){
        glDeleteShader(*id);
        delete id;
    }
}

Shader::Shader(wptr<Context> ctx, Vop<const gl::ShaderType> type) : 
    ContextData(ctx, &CreateShader, &DeleteShader, type){
}

Shader::Shader(const Shader &&other) :
    ContextData(std::move(other)){
}

Shader::~Shader(){
}

std::shared_future<bool> Shader::getParam_iv(Vop<const gl::ShaderParamInt> param, Ptr<gl::Int> dst) const {
    return _lockCtx()->onRun.push([id = _idPtr(), param, dst](){
        auto &v_param = getVopRef(param);
        auto p_dst = getPtrValue(dst);

        glGetShaderiv(*id, static_cast<gl::Enum>(v_param), p_dst);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Shader::getInfoLog(Ptr<std::string> dst) const {
    return _lockCtx()->onRun.push([id = _idPtr(), dst](){
        auto p_dst = getPtrValue(dst);
        
        gl::Int success;
        glGetShaderiv(*id, GL_COMPILE_STATUS, &success);
        if (success == GL_FALSE){
            gl::Int length;
            glGetShaderiv(*id, GL_INFO_LOG_LENGTH, &length);
            p_dst->resize(length);
            glGetShaderInfoLog(*id, length, &length, p_dst->data());
        }

        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Shader::compile(Vop<const std::string> code){
    return _lockCtx()->onRun.push([id = _idPtr(), code](){
        auto &v_code = getVopRef(code);

        std::cout << v_code.c_str() << std::endl;

        auto c_code = v_code.c_str();
        glShaderSource(*id, 1, &c_code, nullptr);
        glCompileShader(*id);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}