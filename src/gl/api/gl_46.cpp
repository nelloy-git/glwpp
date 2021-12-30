#include "glwpp/gl/api/gl_46.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::MultiDrawArraysIndirectCount)(GLenum mode, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) = nullptr;
void (*gl::MultiDrawElementsIndirectCount)(GLenum mode, GLenum type, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) = nullptr;
void (*gl::PolygonOffsetClamp)(GLfloat factor, GLfloat units, GLfloat clamp) = nullptr;
void (*gl::SpecializeShader)(GLuint shader, const GLchar * pEntryPoint, GLuint numSpecializationConstants, const GLuint * pConstantIndex, const GLuint * pConstantValue) = nullptr;

bool gl::LoadGl_46(LoadFunc func){
    if (!LoadGl_45(func)){
        return false;
    }
 
    gl::MultiDrawArraysIndirectCount = glMultiDrawArraysIndirectCount;
    gl::MultiDrawElementsIndirectCount = glMultiDrawElementsIndirectCount;
    gl::PolygonOffsetClamp = glPolygonOffsetClamp;
    gl::SpecializeShader = glSpecializeShader;

    return true;
}