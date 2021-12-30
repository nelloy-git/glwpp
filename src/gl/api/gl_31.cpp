#include "glwpp/gl/api/gl_31.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::CopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) = nullptr;
void (*gl::DrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) = nullptr;
void (*gl::DrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount) = nullptr;
void (*gl::GetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName) = nullptr;
void (*gl::GetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params) = nullptr;
void (*gl::GetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName) = nullptr;
void (*gl::GetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params) = nullptr;
GLuint (*gl::GetUniformBlockIndex)(GLuint program, const GLchar * uniformBlockName) = nullptr;
void (*gl::GetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices) = nullptr;
void (*gl::PrimitiveRestartIndex)(GLuint index) = nullptr;
void (*gl::TexBuffer)(GLenum target, GLenum internalformat, GLuint buffer) = nullptr;
void (*gl::UniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) = nullptr;

bool gl::LoadGl_31(LoadFunc func){
    if (!LoadGl_30(func)){
        return false;
    }
 
    gl::CopyBufferSubData = glCopyBufferSubData;
    gl::DrawArraysInstanced = glDrawArraysInstanced;
    gl::DrawElementsInstanced = glDrawElementsInstanced;
    gl::GetActiveUniformBlockName = glGetActiveUniformBlockName;
    gl::GetActiveUniformBlockiv = glGetActiveUniformBlockiv;
    gl::GetActiveUniformName = glGetActiveUniformName;
    gl::GetActiveUniformsiv = glGetActiveUniformsiv;
    gl::GetUniformBlockIndex = glGetUniformBlockIndex;
    gl::GetUniformIndices = glGetUniformIndices;
    gl::PrimitiveRestartIndex = glPrimitiveRestartIndex;
    gl::TexBuffer = glTexBuffer;
    gl::UniformBlockBinding = glUniformBlockBinding;

    return true;
}