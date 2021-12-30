#include "glwpp/gl/api/gl_44.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::BindBuffersBase)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers) = nullptr;
void (*gl::BindBuffersRange)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizeiptr * sizes) = nullptr;
void (*gl::BindImageTextures)(GLuint first, GLsizei count, const GLuint * textures) = nullptr;
void (*gl::BindSamplers)(GLuint first, GLsizei count, const GLuint * samplers) = nullptr;
void (*gl::BindTextures)(GLuint first, GLsizei count, const GLuint * textures) = nullptr;
void (*gl::BindVertexBuffers)(GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides) = nullptr;
void (*gl::BufferStorage)(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags) = nullptr;
void (*gl::ClearTexImage)(GLuint texture, GLint level, GLenum format, GLenum type, const void * data) = nullptr;
void (*gl::ClearTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data) = nullptr;

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