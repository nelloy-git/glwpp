#include "glwpp/gl/api/gl_42.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::BindImageTexture)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) = nullptr;
void (*gl::DrawArraysInstancedBaseInstance)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) = nullptr;
void (*gl::DrawElementsInstancedBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance) = nullptr;
void (*gl::DrawElementsInstancedBaseVertexBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) = nullptr;
void (*gl::DrawTransformFeedbackInstanced)(GLenum mode, GLuint id, GLsizei instancecount) = nullptr;
void (*gl::DrawTransformFeedbackStreamInstanced)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) = nullptr;
void (*gl::GetActiveAtomicCounterBufferiv)(GLuint program, GLuint bufferIndex, GLenum pname, GLint * params) = nullptr;
void (*gl::GetInternalformativ)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint * params) = nullptr;
void (*gl::MemoryBarrier)(GLbitfield barriers) = nullptr;
void (*gl::TexStorage1D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) = nullptr;
void (*gl::TexStorage2D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) = nullptr;
void (*gl::TexStorage3D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) = nullptr;

bool gl::LoadGl_42(LoadFunc func){
    if (!LoadGl_41(func)){
        return false;
    }
 
    gl::BindImageTexture = glBindImageTexture;
    gl::DrawArraysInstancedBaseInstance = glDrawArraysInstancedBaseInstance;
    gl::DrawElementsInstancedBaseInstance = glDrawElementsInstancedBaseInstance;
    gl::DrawElementsInstancedBaseVertexBaseInstance = glDrawElementsInstancedBaseVertexBaseInstance;
    gl::DrawTransformFeedbackInstanced = glDrawTransformFeedbackInstanced;
    gl::DrawTransformFeedbackStreamInstanced = glDrawTransformFeedbackStreamInstanced;
    gl::GetActiveAtomicCounterBufferiv = glGetActiveAtomicCounterBufferiv;
    gl::GetInternalformativ = glGetInternalformativ;
    gl::MemoryBarrier = glMemoryBarrier;
    gl::TexStorage1D = glTexStorage1D;
    gl::TexStorage2D = glTexStorage2D;
    gl::TexStorage3D = glTexStorage3D;

    return true;
}