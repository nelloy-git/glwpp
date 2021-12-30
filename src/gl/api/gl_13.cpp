#include "glwpp/gl/api/gl_13.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::ActiveTexture)(GLenum texture) = nullptr;
void (*gl::CompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data) = nullptr;
void (*gl::CompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data) = nullptr;
void (*gl::CompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data) = nullptr;
void (*gl::CompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data) = nullptr;
void (*gl::CompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) = nullptr;
void (*gl::CompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) = nullptr;
void (*gl::GetCompressedTexImage)(GLenum target, GLint level, void * img) = nullptr;
void (*gl::SampleCoverage)(GLfloat value, GLboolean invert) = nullptr;

bool gl::LoadGl_13(LoadFunc func){
    if (!LoadGl_12(func)){
        return false;
    }
 
    gl::ActiveTexture = glActiveTexture;
    gl::CompressedTexImage1D = glCompressedTexImage1D;
    gl::CompressedTexImage2D = glCompressedTexImage2D;
    gl::CompressedTexImage3D = glCompressedTexImage3D;
    gl::CompressedTexSubImage1D = glCompressedTexSubImage1D;
    gl::CompressedTexSubImage2D = glCompressedTexSubImage2D;
    gl::CompressedTexSubImage3D = glCompressedTexSubImage3D;
    gl::GetCompressedTexImage = glGetCompressedTexImage;
    gl::SampleCoverage = glSampleCoverage;

    return true;
}