#pragma once

#include <tuple>

// #include "glad/gl.h"

#include "glwpp/utils/Utils.hpp"

namespace glwpp::ctx {

class Uniform {
friend class Program;
public:
    inline GLint getLoc(const std::string &name){
        return glGetUniformLocation(_prog_id, name.c_str());
    }
    // inline GLuint getStorage(const std::string &name){return glGetProgramResourceIndex(_prog_id, GL_SHADER_STORAGE_BLOCK, name.c_str());}

    inline void setInt(GLint loc, GLint v1){
        glProgramUniform1i(_prog_id, loc, v1);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform1i);
    }
    inline void setInt(GLint loc, GLint v1, GLint v2){
        glProgramUniform2i(_prog_id, loc, v1, v2);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform2i);
    }
    inline void setInt(GLint loc, GLint v1, GLint v2, GLint v3){
        glProgramUniform3i(_prog_id, loc, v1, v2, v3);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform3i);
    }
    inline void setInt(GLint loc, GLint v1, GLint v2, GLint v3, GLint v4){
        glProgramUniform4i(_prog_id, loc, v1, v2, v3, v4);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform4i);
    }
    inline void setUint(GLint loc, GLuint v1){
        glProgramUniform1ui(_prog_id, loc, v1);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform1ui);
    }
    inline void setUint(GLint loc, GLuint v1, GLuint v2){
        glProgramUniform2ui(_prog_id, loc, v1, v2);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform2ui);
    }
    inline void setUint(GLint loc, GLuint v1, GLuint v2, GLuint v3){
        glProgramUniform3ui(_prog_id, loc, v1, v2, v3);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform3ui);
    }
    inline void setUint(GLint loc, GLuint v1, GLuint v2, GLuint v3, GLuint v4){
        glProgramUniform4ui(_prog_id, loc, v1, v2, v3, v4);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform4ui);
    }
    inline void setFloat(GLint loc, GLfloat v1){
        glProgramUniform1f(_prog_id, loc, v1);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform1f);
    }
    inline void setFloat(GLint loc, GLfloat v1, GLfloat v2){
        glProgramUniform2f(_prog_id, loc, v1, v2);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform2f);
    }
    inline void setFloat(GLint loc, GLfloat v1, GLfloat v2, GLfloat v3){
        glProgramUniform3f(_prog_id, loc, v1, v2, v3);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform3f);
    }
    inline void setFloat(GLint loc, GLfloat v1, GLfloat v2, GLfloat v3, GLfloat v4){
        glProgramUniform4f(_prog_id, loc, v1, v2, v3, v4);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform4f);
    }
    
    //==========
    // Vector[] 
    //==========

    inline void setArrayVec1(GLint loc, GLsizei count, GLint *ptr){
        glProgramUniform1iv(_prog_id, loc, count, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform1iv);
    }
    inline void setArrayVec1(GLint loc, GLsizei count, GLuint *ptr){
        glProgramUniform1uiv(_prog_id, loc, count, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform1uiv);
    }
    inline void setArrayVec1(GLint loc, GLsizei count, GLfloat *ptr){
        glProgramUniform1fv(_prog_id, loc, count, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform1fv);
    }
    inline void setArrayVec2(GLint loc, GLsizei count, GLint *ptr){
        glProgramUniform2iv(_prog_id, loc, count, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform2iv);
    }
    inline void setArrayVec2(GLint loc, GLsizei count, GLuint *ptr){
        glProgramUniform2uiv(_prog_id, loc, count, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform2uiv);
    }
    inline void setArrayVec2(GLint loc, GLsizei count, GLfloat *ptr){
        glProgramUniform2fv(_prog_id, loc, count, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform2fv);
    }
    inline void setArrayVec3(GLint loc, GLsizei count, GLint *ptr){
        glProgramUniform3iv(_prog_id, loc, count, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform3iv);
    }
    inline void setArrayVec3(GLint loc, GLsizei count, GLuint *ptr){
        glProgramUniform3uiv(_prog_id, loc, count, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform3uiv);
    }
    inline void setArrayVec3(GLint loc, GLsizei count, GLfloat *ptr){
        glProgramUniform3fv(_prog_id, loc, count, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform3fv);
    }
    inline void setArrayVec4(GLint loc, GLsizei count, GLint *ptr){
        glProgramUniform4iv(_prog_id, loc, count, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform4iv);
    }
    inline void setArrayVec4(GLint loc, GLsizei count, GLuint *ptr){
        glProgramUniform4uiv(_prog_id, loc, count, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform4uiv);
    }
    inline void setArrayVec4(GLint loc, GLsizei count, GLfloat *ptr){
        glProgramUniform4fv(_prog_id, loc, count, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniform4fv);
    }

    //==========
    // Matrix[]
    //==========

    inline void setArrayMat2x2(GLint loc, GLsizei count, bool transpose, float *ptr){
        glProgramUniformMatrix2fv(_prog_id, loc, count, transpose, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniformMatrix2fv);
    }
    inline void setArrayMat2x3(GLint loc, GLsizei count, bool transpose, float *ptr){
        glProgramUniformMatrix2x3fv(_prog_id, loc, count, transpose, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniformMatrix2x3fv);
    }
    inline void setArrayMat2x4(GLint loc, GLsizei count, bool transpose, float *ptr){
        glProgramUniformMatrix2x4fv(_prog_id, loc, count, transpose, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniformMatrix2x4fv);
    }
    inline void setArrayMat3x2(GLint loc, GLsizei count, bool transpose, float *ptr){
        glProgramUniformMatrix3x2fv(_prog_id, loc, count, transpose, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniformMatrix3x2fv);
    }
    inline void setArrayMat3x3(GLint loc, GLsizei count, bool transpose, float *ptr){
        glProgramUniformMatrix3fv(_prog_id, loc, count, transpose, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniformMatrix3fv);
    }
    inline void setArrayMat3x4(GLint loc, GLsizei count, bool transpose, float *ptr){
        glProgramUniformMatrix3x4fv(_prog_id, loc, count, transpose, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniformMatrix3x4fv);
    }
    inline void setArrayMat4x2(GLint loc, GLsizei count, bool transpose, float *ptr){
        glProgramUniformMatrix4x2fv(_prog_id, loc, count, transpose, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniformMatrix4x2fv);
    }
    inline void setArrayMat4x3(GLint loc, GLsizei count, bool transpose, float *ptr){
        glProgramUniformMatrix4x3fv(_prog_id, loc, count, transpose, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniformMatrix4x3fv);
    }
    inline void setArrayMat4x4(GLint loc, GLsizei count, bool transpose, float *ptr){
        glProgramUniformMatrix4fv(_prog_id, loc, count, transpose, ptr);
        if constexpr (GL_DEBUG) printErr(&glProgramUniformMatrix4fv);
    }

    // TODO UniformBlock & SSBO
protected:
    Uniform(GLuint prog_id) :
        _prog_id(prog_id){
    };

private:
    const GLuint _prog_id;
};

}