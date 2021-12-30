#pragma once
#include "glwpp/gl/api/gl_45.hpp"

namespace glwpp::gl {

bool LoadGl_46(LoadFunc func);

extern void (*MultiDrawArraysIndirectCount)(GLenum mode, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
extern void (*MultiDrawElementsIndirectCount)(GLenum mode, GLenum type, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
extern void (*PolygonOffsetClamp)(GLfloat factor, GLfloat units, GLfloat clamp);
extern void (*SpecializeShader)(GLuint shader, const GLchar * pEntryPoint, GLuint numSpecializationConstants, const GLuint * pConstantIndex, const GLuint * pConstantValue);

}