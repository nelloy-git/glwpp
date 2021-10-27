#pragma once

#include <optional>
#include <string>

#include "glwpp/ctx/data/Data.hpp"
#include "glwpp/enums/gl/ShaderTypeGL.hpp"

namespace glwpp::ctx {

class Shader : public Data {
public:
    Shader(ShaderTypeGL type) :
        Data(_newId(type)){
    };

    virtual ~Shader(){
        glDeleteShader(id);
    }

    void setSource(const std::string& code){
        auto c_str = code.c_str();
        glShaderSource(id, 1, &c_str, nullptr);
        _compiled = false;
        if constexpr (GL_DEBUG) printErr(&glShaderSource);
    }

    std::optional<std::string> compile(){
        glCompileShader(id);

        GLint status;
        glGetShaderiv(id, GL_COMPILE_STATUS, &status);
        _compiled = (status != GL_FALSE);
        if (_compiled){
            return std::nullopt;
        }

        GLint length;
        std::string msg;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        msg.resize(length);
        glGetShaderInfoLog(id, length, &length, msg.data());
        return msg;
    }

    inline bool isCompiled(){
        return _compiled;
    }

private:
    inline static GLuint _newId(ShaderTypeGL type){
        return glCreateShader(gl(type));
    }

    bool _compiled = false;
};

}