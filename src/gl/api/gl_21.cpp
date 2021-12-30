#include "glwpp/gl/api/gl_21.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::UniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = nullptr;
void (*gl::UniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = nullptr;
void (*gl::UniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = nullptr;
void (*gl::UniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = nullptr;
void (*gl::UniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = nullptr;
void (*gl::UniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = nullptr;

bool gl::LoadGl_21(LoadFunc func){
    if (!LoadGl_20(func)){
        return false;
    }
 
    gl::UniformMatrix2x3fv = glUniformMatrix2x3fv;
    gl::UniformMatrix2x4fv = glUniformMatrix2x4fv;
    gl::UniformMatrix3x2fv = glUniformMatrix3x2fv;
    gl::UniformMatrix3x4fv = glUniformMatrix3x4fv;
    gl::UniformMatrix4x2fv = glUniformMatrix4x2fv;
    gl::UniformMatrix4x3fv = glUniformMatrix4x3fv;

    return true;
}
 