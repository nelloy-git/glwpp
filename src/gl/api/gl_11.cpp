#include "glwpp/gl/api/gl_11.hpp"

#include "glad/gl.h"

using namespace glwpp;
   
void (*gl::BindTexture)(GLenum target, GLuint texture) = nullptr;
void (*gl::CopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) = nullptr;
void (*gl::CopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) = nullptr;
void (*gl::CopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) = nullptr;
void (*gl::CopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;
void (*gl::DeleteTextures)(GLsizei n, const GLuint *textures) = nullptr;
void (*gl::DrawArrays)(GLenum mode, GLint first, GLsizei count) = nullptr;
void (*gl::DrawElements)(GLenum mode, GLsizei count, GLenum type, const void *indices) = nullptr;
void (*gl::GenTextures)(GLsizei n, GLuint *textures) = nullptr;
void (*gl::GetPointerv)(GLenum pname, void **params) = nullptr;
GLboolean (*gl::IsTexture)(GLuint texture) = nullptr;
void (*gl::PolygonOffset)(GLfloat factor, GLfloat units) = nullptr;
void (*gl::TexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) = nullptr;
void (*gl::TexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) = nullptr;

bool gl::LoadGl_11(LoadFunc func){
    if (!gl::LoadGl_10(func)){
        return false;
    }
 
    gl::BindTexture = glBindTexture;
    gl::CopyTexImage1D = glCopyTexImage1D;
    gl::CopyTexImage2D = glCopyTexImage2D;
    gl::CopyTexSubImage1D = glCopyTexSubImage1D;
    gl::CopyTexSubImage2D = glCopyTexSubImage2D;
    gl::DeleteTextures = glDeleteTextures;
    gl::DrawArrays = glDrawArrays;
    gl::DrawElements = glDrawElements;
    gl::GenTextures = glGenTextures;
    gl::GetPointerv = glGetPointerv;
    gl::IsTexture = glIsTexture;
    gl::PolygonOffset = glPolygonOffset;
    gl::TexSubImage1D = glTexSubImage1D;
    gl::TexSubImage2D = glTexSubImage2D;

    return true;
}