#pragma once
#include "glwpp/gl/api/gl_30.hpp"

namespace glwpp::gl {

bool LoadGl_31(LoadFunc func);

extern void (*CopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
extern void (*DrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
extern void (*DrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount);
extern void (*GetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName);
extern void (*GetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params);
extern void (*GetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName);
extern void (*GetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params);
extern GLuint (*GetUniformBlockIndex)(GLuint program, const GLchar * uniformBlockName);
extern void (*GetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices);
extern void (*PrimitiveRestartIndex)(GLuint index);
extern void (*TexBuffer)(GLenum target, GLenum internalformat, GLuint buffer);
extern void (*UniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

}