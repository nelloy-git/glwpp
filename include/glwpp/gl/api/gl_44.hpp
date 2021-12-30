#pragma once
#include "glwpp/gl/api/gl_43.hpp"

namespace glwpp::gl {

bool LoadGl_44(LoadFunc func);

extern void (*BindBuffersBase)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers);
extern void (*BindBuffersRange)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizeiptr * sizes);
extern void (*BindImageTextures)(GLuint first, GLsizei count, const GLuint * textures);
extern void (*BindSamplers)(GLuint first, GLsizei count, const GLuint * samplers);
extern void (*BindTextures)(GLuint first, GLsizei count, const GLuint * textures);
extern void (*BindVertexBuffers)(GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides);
extern void (*BufferStorage)(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags);
extern void (*ClearTexImage)(GLuint texture, GLint level, GLenum format, GLenum type, const void * data);
extern void (*ClearTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data);

}