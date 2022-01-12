#include "glwpp/gl/api/gl_32.hpp"

#include "glad/gl.h"

using namespace glwpp;

GLenum (*gl::ClientWaitSync)(gl::GLsync sync, BitField flags, GLuint64 timeout) = nullptr;
void (*gl::DeleteSync)(GLsync sync) = nullptr;
void (*gl::DrawElementsBaseVertex)(Enum mode, Sizei count, Enum type, const void * indices, Int basevertex) = nullptr;
void (*gl::DrawElementsInstancedBaseVertex)(Enum mode, Sizei count, Enum type, const void * indices, Sizei instancecount, Int basevertex) = nullptr;
void (*gl::DrawRangeElementsBaseVertex)(Enum mode, UInt start, UInt end, Sizei count, Enum type, const void * indices, Int basevertex) = nullptr;
GLsync (*gl::FenceSync)(Enum condition, BitField flags) = nullptr;
void (*gl::FramebufferTexture)(Enum target, Enum attachment, UInt texture, Int level) = nullptr;
void (*gl::GetBufferParameteri64v)(Enum target, Enum pname, GLint64 * params) = nullptr;
void (*gl::GetInteger64i_v)(Enum target, UInt index, GLint64 * data) = nullptr;
void (*gl::GetInteger64v)(Enum pname, GLint64 * data) = nullptr;
void (*gl::GetMultisamplefv)(Enum pname, UInt index, Float * val) = nullptr;
void (*gl::GetSynciv)(GLsync sync, Enum pname, Sizei count, Sizei * length, Int * values) = nullptr;
GLboolean (*gl::IsSync)(GLsync sync) = nullptr;
void (*gl::MultiDrawElementsBaseVertex)(Enum mode, const Sizei * count, Enum type, const void *const* indices, Sizei drawcount, const Int * basevertex) = nullptr;
void (*gl::ProvokingVertex)(Enum mode) = nullptr;
void (*gl::SampleMaski)(UInt maskNumber, BitField mask) = nullptr;
void (*gl::TexImage2DMultisample)(Enum target, Sizei samples, Enum internalformat, Sizei width, Sizei height, Bool fixedsamplelocations) = nullptr;
void (*gl::TexImage3DMultisample)(Enum target, Sizei samples, Enum internalformat, Sizei width, Sizei height, Sizei depth, Bool fixedsamplelocations) = nullptr;
void (*gl::WaitSync)(GLsync sync, BitField flags, GLuint64 timeout) = nullptr;

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