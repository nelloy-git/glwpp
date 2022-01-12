#include "glwpp/gl/api/gl_13.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::ActiveTexture)(Enum texture) = nullptr;
void (*gl::CompressedTexImage1D)(Enum target, Int level, Enum internalformat, Sizei width, Int border, Sizei imageSize, const void * data) = nullptr;
void (*gl::CompressedTexImage2D)(Enum target, Int level, Enum internalformat, Sizei width, Sizei height, Int border, Sizei imageSize, const void * data) = nullptr;
void (*gl::CompressedTexImage3D)(Enum target, Int level, Enum internalformat, Sizei width, Sizei height, Sizei depth, Int border, Sizei imageSize, const void * data) = nullptr;
void (*gl::CompressedTexSubImage1D)(Enum target, Int level, Int xoffset, Sizei width, Enum format, Sizei imageSize, const void * data) = nullptr;
void (*gl::CompressedTexSubImage2D)(Enum target, Int level, Int xoffset, Int yoffset, Sizei width, Sizei height, Enum format, Sizei imageSize, const void * data) = nullptr;
void (*gl::CompressedTexSubImage3D)(Enum target, Int level, Int xoffset, Int yoffset, Int zoffset, Sizei width, Sizei height, Sizei depth, Enum format, Sizei imageSize, const void * data) = nullptr;
void (*gl::GetCompressedTexImage)(Enum target, Int level, void * img) = nullptr;
void (*gl::SampleCoverage)(Float value, Bool invert) = nullptr;

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