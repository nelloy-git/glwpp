#include "glwpp/gl/api/gl_14.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::BlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = nullptr;
void (*gl::BlendEquation)(GLenum mode) = nullptr;
void (*gl::BlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) = nullptr;
void (*gl::MultiDrawArrays)(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount) = nullptr;
void (*gl::MultiDrawElements)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount) = nullptr;
void (*gl::PointParameterf)(GLenum pname, GLfloat param) = nullptr;
void (*gl::PointParameterfv)(GLenum pname, const GLfloat * params) = nullptr;
void (*gl::PointParameteri)(GLenum pname, GLint param) = nullptr;
void (*gl::PointParameteriv)(GLenum pname, const GLint * params) = nullptr;

bool gl::LoadGl_14(LoadFunc func){
    if (!LoadGl_13(func)){
        return false;
    }
 
    gl::BlendColor = glBlendColor;
    gl::BlendEquation = glBlendEquation;
    gl::BlendFuncSeparate = glBlendFuncSeparate;
    gl::MultiDrawArrays = glMultiDrawArrays;
    gl::MultiDrawElements = glMultiDrawElements;
    gl::PointParameterf = glPointParameterf;
    gl::PointParameterfv = glPointParameterfv;
    gl::PointParameteri = glPointParameteri;
    gl::PointParameteriv = glPointParameteriv;

    return true;
}