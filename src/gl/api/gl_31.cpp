#include "glwpp/gl/api/gl_31.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::CopyBufferSubData)(Enum readTarget, Enum writeTarget, IntPtr readOffset, IntPtr writeOffset, SizeiPtr size) = nullptr;
void (*gl::DrawArraysInstanced)(Enum mode, Int first, Sizei count, Sizei instancecount) = nullptr;
void (*gl::DrawElementsInstanced)(Enum mode, Sizei count, Enum type, const void * indices, Sizei instancecount) = nullptr;
void (*gl::GetActiveUniformBlockName)(UInt program, UInt uniformBlockIndex, Sizei bufSize, Sizei * length, Char * uniformBlockName) = nullptr;
void (*gl::GetActiveUniformBlockiv)(UInt program, UInt uniformBlockIndex, Enum pname, Int * params) = nullptr;
void (*gl::GetActiveUniformName)(UInt program, UInt uniformIndex, Sizei bufSize, Sizei * length, Char * uniformName) = nullptr;
void (*gl::GetActiveUniformsiv)(UInt program, Sizei uniformCount, const UInt * uniformIndices, Enum pname, Int * params) = nullptr;
GLuint (*gl::GetUniformBlockIndex)(UInt program, const Char * uniformBlockName) = nullptr;
void (*gl::GetUniformIndices)(UInt program, Sizei uniformCount, const Char *const* uniformNames, UInt * uniformIndices) = nullptr;
void (*gl::PrimitiveRestartIndex)(UInt index) = nullptr;
void (*gl::TexBuffer)(Enum target, Enum internalformat, UInt buffer) = nullptr;
void (*gl::UniformBlockBinding)(UInt program, UInt uniformBlockIndex, UInt uniformBlockBinding) = nullptr;

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