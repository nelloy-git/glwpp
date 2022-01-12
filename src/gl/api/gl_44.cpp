#include "glwpp/gl/api/gl_44.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::BindBuffersBase)(Enum target, UInt first, Sizei count, const UInt * buffers) = nullptr;
void (*gl::BindBuffersRange)(Enum target, UInt first, Sizei count, const UInt * buffers, const IntPtr * offsets, const SizeiPtr * sizes) = nullptr;
void (*gl::BindImageTextures)(UInt first, Sizei count, const UInt * textures) = nullptr;
void (*gl::BindSamplers)(UInt first, Sizei count, const UInt * samplers) = nullptr;
void (*gl::BindTextures)(UInt first, Sizei count, const UInt * textures) = nullptr;
void (*gl::BindVertexBuffers)(UInt first, Sizei count, const UInt * buffers, const IntPtr * offsets, const Sizei * strides) = nullptr;
void (*gl::BufferStorage)(Enum target, SizeiPtr size, const void * data, BitField flags) = nullptr;
void (*gl::ClearTexImage)(UInt texture, Int level, Enum format, Enum type, const void * data) = nullptr;
void (*gl::ClearTexSubImage)(UInt texture, Int level, Int xoffset, Int yoffset, Int zoffset, Sizei width, Sizei height, Sizei depth, Enum format, Enum type, const void * data) = nullptr;

bool gl::LoadGl_44(LoadFunc func){
    if (!LoadGl_43(func)){
        return false;
    }
 
    gl::BindBuffersBase = glBindBuffersBase;
    gl::BindBuffersRange = glBindBuffersRange;
    gl::BindImageTextures = glBindImageTextures;
    gl::BindSamplers = glBindSamplers;
    gl::BindTextures = glBindTextures;
    gl::BindVertexBuffers = glBindVertexBuffers;
    gl::BufferStorage = glBufferStorage;
    gl::ClearTexImage = glClearTexImage;
    gl::ClearTexSubImage = glClearTexSubImage;

    return true;
}