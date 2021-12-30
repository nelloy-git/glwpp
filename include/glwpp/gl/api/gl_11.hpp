#pragma once
#include "glwpp/gl/api/gl_10.hpp"

namespace glwpp::gl {

bool LoadGl_11(LoadFunc func);
    
extern void (*BindTexture)(GLenum target, GLuint texture);
extern void (*CopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
extern void (*CopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
extern void (*CopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
extern void (*CopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (*DeleteTextures)(GLsizei n, const GLuint *textures);
extern void (*DrawArrays)(GLenum mode, GLint first, GLsizei count);
extern void (*DrawElements)(GLenum mode, GLsizei count, GLenum type, const void *indices);
extern void (*GenTextures)(GLsizei n, GLuint *textures);
extern void (*GetPointerv)(GLenum pname, void **params);
extern GLboolean (*IsTexture)(GLuint texture);
extern void (*PolygonOffset)(GLfloat factor, GLfloat units);
extern void (*TexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
extern void (*TexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);

}