#pragma once
#include "glwpp/gl/api/gl_33.hpp"

namespace glwpp::gl {

bool LoadGl_40(LoadFunc func);

extern void (*BeginQueryIndexed)(GLenum target, GLuint index, GLuint id);
extern void (*BindTransformFeedback)(GLenum target, GLuint id);
extern void (*BlendEquationSeparatei)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
extern void (*BlendEquationi)(GLuint buf, GLenum mode);
extern void (*BlendFuncSeparatei)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
extern void (*BlendFunci)(GLuint buf, GLenum src, GLenum dst);
extern void (*DeleteTransformFeedbacks)(GLsizei n, const GLuint * ids);
extern void (*DrawArraysIndirect)(GLenum mode, const void * indirect);
extern void (*DrawElementsIndirect)(GLenum mode, GLenum type, const void * indirect);
extern void (*DrawTransformFeedback)(GLenum mode, GLuint id);
extern void (*DrawTransformFeedbackStream)(GLenum mode, GLuint id, GLuint stream);
extern void (*EndQueryIndexed)(GLenum target, GLuint index);
extern void (*GenTransformFeedbacks)(GLsizei n, GLuint * ids);
extern void (*GetActiveSubroutineName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
extern void (*GetActiveSubroutineUniformName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
extern void (*GetActiveSubroutineUniformiv)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values);
extern void (*GetProgramStageiv)(GLuint program, GLenum shadertype, GLenum pname, GLint * values);
extern void (*GetQueryIndexediv)(GLenum target, GLuint index, GLenum pname, GLint * params);
extern GLuint (*GetSubroutineIndex)(GLuint program, GLenum shadertype, const GLchar * name);
extern GLint (*GetSubroutineUniformLocation)(GLuint program, GLenum shadertype, const GLchar * name);
extern void (*GetUniformSubroutineuiv)(GLenum shadertype, GLint location, GLuint * params);
extern void (*GetUniformdv)(GLuint program, GLint location, GLdouble * params);
extern GLboolean (*IsTransformFeedback)(GLuint id);
extern void (*MinSampleShading)(GLfloat value);
extern void (*PatchParameterfv)(GLenum pname, const GLfloat * values);
extern void (*PatchParameteri)(GLenum pname, GLint value);
extern void (*PauseTransformFeedback)();
extern void (*ResumeTransformFeedback)();
extern void (*Uniform1d)(GLint location, GLdouble x);
extern void (*Uniform1dv)(GLint location, GLsizei count, const GLdouble * value);
extern void (*Uniform2d)(GLint location, GLdouble x, GLdouble y);
extern void (*Uniform2dv)(GLint location, GLsizei count, const GLdouble * value);
extern void (*Uniform3d)(GLint location, GLdouble x, GLdouble y, GLdouble z);
extern void (*Uniform3dv)(GLint location, GLsizei count, const GLdouble * value);
extern void (*Uniform4d)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (*Uniform4dv)(GLint location, GLsizei count, const GLdouble * value);
extern void (*UniformMatrix2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
extern void (*UniformMatrix2x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
extern void (*UniformMatrix2x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
extern void (*UniformMatrix3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
extern void (*UniformMatrix3x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
extern void (*UniformMatrix3x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
extern void (*UniformMatrix4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
extern void (*UniformMatrix4x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
extern void (*UniformMatrix4x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
extern void (*UniformSubroutinesuiv)(GLenum shadertype, GLsizei count, const GLuint * indices);

}