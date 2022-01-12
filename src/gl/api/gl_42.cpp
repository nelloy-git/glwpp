#include "glwpp/gl/api/gl_42.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::BindImageTexture)(UInt unit, UInt texture, Int level, Bool layered, Int layer, Enum access, Enum format) = nullptr;
void (*gl::DrawArraysInstancedBaseInstance)(Enum mode, Int first, Sizei count, Sizei instancecount, UInt baseinstance) = nullptr;
void (*gl::DrawElementsInstancedBaseInstance)(Enum mode, Sizei count, Enum type, const void * indices, Sizei instancecount, UInt baseinstance) = nullptr;
void (*gl::DrawElementsInstancedBaseVertexBaseInstance)(Enum mode, Sizei count, Enum type, const void * indices, Sizei instancecount, Int basevertex, UInt baseinstance) = nullptr;
void (*gl::DrawTransformFeedbackInstanced)(Enum mode, UInt id, Sizei instancecount) = nullptr;
void (*gl::DrawTransformFeedbackStreamInstanced)(Enum mode, UInt id, UInt stream, Sizei instancecount) = nullptr;
void (*gl::GetActiveAtomicCounterBufferiv)(UInt program, UInt bufferIndex, Enum pname, Int * params) = nullptr;
void (*gl::GetInternalformativ)(Enum target, Enum internalformat, Enum pname, Sizei count, Int * params) = nullptr;
void (*gl::MemoryBarrier)(BitField barriers) = nullptr;
void (*gl::TexStorage1D)(Enum target, Sizei levels, Enum internalformat, Sizei width) = nullptr;
void (*gl::TexStorage2D)(Enum target, Sizei levels, Enum internalformat, Sizei width, Sizei height) = nullptr;
void (*gl::TexStorage3D)(Enum target, Sizei levels, Enum internalformat, Sizei width, Sizei height, Sizei depth) = nullptr;

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