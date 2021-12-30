#pragma once
#include "glwpp/gl/api/gl_20.hpp"

namespace glwpp::gl {

bool LoadGl_21(LoadFunc func);
 
extern void (*UniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (*UniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (*UniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (*UniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (*UniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (*UniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);

}