#pragma once

#include <vector>

#include "glwpp/ctx/data/Data.hpp"
#include "glwpp/ctx/data/Shader.hpp"
#include "glwpp/ctx/data/Uniform.hpp"

namespace glwpp::ctx {

class Program : public Data {
public:
    Program() :
        Data(_newId()),
        uniform(id){
    }

    virtual ~Program(){
        glDeleteProgram(id);
    }

    void attach(const Shader &shader){
        glAttachShader(id, shader.id);
        if constexpr (GL_DEBUG) printErr(&glAttachShader);
    }

    std::optional<std::string> link(){
        glLinkProgram(id);

        GLint res;
        glGetProgramiv(id, GL_LINK_STATUS, &res);
        _linked = (res != GL_FALSE);
        if (_linked){
            return std::nullopt;
        }

        GLint length;
        std::string msg;
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &length);
        msg.resize(length);
        glGetProgramInfoLog(id, length, &length, msg.data());
        return msg;
    }

    inline bool isLinked(){
        return _linked;
    }

    inline void use(){
        glUseProgram(id);
    };

    inline GLint getAttribLoc(const std::string &name){
        return glGetAttribLocation(id, name.c_str());
    };

    inline GLint getUniformLoc(const std::string &name){
        return glGetUniformLocation(id, name.c_str());
    };

    Uniform uniform;

private:
    inline static GLuint _newId(){
        return glCreateProgram();
    }

    bool _linked = false;

};

}