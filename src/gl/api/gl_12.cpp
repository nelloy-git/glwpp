#include "glwpp/gl/api/gl_12.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::CopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;
void (*gl::DrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices) = nullptr;
void (*gl::TexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) = nullptr;
void (*gl::TexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) = nullptr;

bool gl::LoadGl_12(LoadFunc func){
    if (!gl::LoadGl_11(func)){
        return false;
    }
 
    gl::CopyTexSubImage3D = glCopyTexSubImage3D;
    gl::DrawRangeElements = glDrawRangeElements;
    gl::TexImage3D = glTexImage3D;
    gl::TexSubImage3D = glTexSubImage3D;

    return true;
}