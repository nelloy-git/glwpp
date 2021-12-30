#include "glwpp/gl/api/gl_32.hpp"

#include "glad/gl.h"

using namespace glwpp;

GLenum (*gl::ClientWaitSync)(gl::GLsync sync, GLbitfield flags, GLuint64 timeout) = nullptr;
void (*gl::DeleteSync)(GLsync sync) = nullptr;
void (*gl::DrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex) = nullptr;
void (*gl::DrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex) = nullptr;
void (*gl::DrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex) = nullptr;
GLsync (*gl::FenceSync)(GLenum condition, GLbitfield flags) = nullptr;
void (*gl::FramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level) = nullptr;
void (*gl::GetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 * params) = nullptr;
void (*gl::GetInteger64i_v)(GLenum target, GLuint index, GLint64 * data) = nullptr;
void (*gl::GetInteger64v)(GLenum pname, GLint64 * data) = nullptr;
void (*gl::GetMultisamplefv)(GLenum pname, GLuint index, GLfloat * val) = nullptr;
void (*gl::GetSynciv)(GLsync sync, GLenum pname, GLsizei count, GLsizei * length, GLint * values) = nullptr;
GLboolean (*gl::IsSync)(GLsync sync) = nullptr;
void (*gl::MultiDrawElementsBaseVertex)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex) = nullptr;
void (*gl::ProvokingVertex)(GLenum mode) = nullptr;
void (*gl::SampleMaski)(GLuint maskNumber, GLbitfield mask) = nullptr;
void (*gl::TexImage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) = nullptr;
void (*gl::TexImage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) = nullptr;
void (*gl::WaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout) = nullptr;

bool gl::LoadGl_32(LoadFunc func){
    if (!LoadGl_31(func)){
        return false;
    }
 
    gl::ClientWaitSync = glClientWaitSync;
    gl::DeleteSync = glDeleteSync;
    gl::DrawElementsBaseVertex = glDrawElementsBaseVertex;
    gl::DrawElementsInstancedBaseVertex = glDrawElementsInstancedBaseVertex;
    gl::DrawRangeElementsBaseVertex = glDrawRangeElementsBaseVertex;
    gl::FenceSync = glFenceSync;
    gl::FramebufferTexture = glFramebufferTexture;
    gl::GetBufferParameteri64v = glGetBufferParameteri64v;
    gl::GetInteger64i_v = glGetInteger64i_v;
    gl::GetInteger64v = glGetInteger64v;
    gl::GetMultisamplefv = glGetMultisamplefv;
    gl::GetSynciv = glGetSynciv;
    gl::IsSync = glIsSync;
    gl::MultiDrawElementsBaseVertex = glMultiDrawElementsBaseVertex;
    gl::ProvokingVertex = glProvokingVertex;
    gl::SampleMaski = glSampleMaski;
    gl::TexImage2DMultisample = glTexImage2DMultisample;
    gl::TexImage3DMultisample = glTexImage3DMultisample;
    gl::WaitSync = glWaitSync;

    return true;
}