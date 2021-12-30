#pragma once
#include "glwpp/gl/api/gl_13.hpp"

namespace glwpp::gl {

bool LoadGl_14(LoadFunc func);
 
extern void (*BlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void (*BlendEquation)(GLenum mode);
extern void (*BlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
extern void (*MultiDrawArrays)(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount);
extern void (*MultiDrawElements)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount);
extern void (*PointParameterf)(GLenum pname, GLfloat param);
extern void (*PointParameterfv)(GLenum pname, const GLfloat * params);
extern void (*PointParameteri)(GLenum pname, GLint param);
extern void (*PointParameteriv)(GLenum pname, const GLint * params);

}