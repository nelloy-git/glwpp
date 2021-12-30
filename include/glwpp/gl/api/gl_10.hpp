#pragma once

#include "glwpp/gl/api/types.hpp"

namespace glwpp::gl {

bool LoadGl_10(LoadFunc func);
    
extern void (*BlendFunc)(GLenum sfactor, GLenum dfactor);
extern void (*Clear)(GLbitfield mask);
extern void (*ClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void (*ClearDepth)(GLdouble depth);
extern void (*ClearStencil)(GLint s);
extern void (*ColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
extern void (*CullFace)(GLenum mode);
extern void (*DepthFunc)(GLenum func);
extern void (*DepthMask)(GLboolean flag);
extern void (*DepthRange)(GLdouble n, GLdouble f);
extern void (*Disable)(GLenum cap);
extern void (*DrawBuffer)(GLenum buf);
extern void (*Enable)(GLenum cap);
extern void (*Finish)();
extern void (*Flush)();
extern void (*FrontFace)(GLenum mode);
extern void (*GetBooleanv)(GLenum pname, GLboolean *data);
extern void (*GetDoublev)(GLenum pname, GLdouble *data);
extern GLenum (*GetError)();
extern void (*GetFloatv)(GLenum pname, GLfloat *data);
extern void (*GetIntegerv)(GLenum pname, GLint *data);
extern const GLubyte* (*GetString)(GLenum name);
extern void (*GetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
extern void (*GetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat *params);
extern void (*GetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint *params);
extern void (*GetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params);
extern void (*GetTexParameteriv)(GLenum target, GLenum pname, GLint *params);
extern void (*Hint)(GLenum target, GLenum mode);
extern GLboolean (*IsEnabled)(GLenum cap);
extern void (*LineWidth)(GLfloat width);
extern void (*LogicOp)(GLenum opcode);
extern void (*PixelStoref)(GLenum pname, GLfloat param);
extern void (*PixelStorei)(GLenum pname, GLint param);
extern void (*PointSize)(GLfloat size);
extern void (*PolygonMode)(GLenum face, GLenum mode);
extern void (*ReadBuffer)(GLenum src);
extern void (*ReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
extern void (*Scissor)(GLint x, GLint y, GLsizei width, GLsizei height);
extern void (*StencilFunc)(GLenum func, GLint ref, GLuint mask);
extern void (*StencilMask)(GLuint mask);
extern void (*StencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
extern void (*TexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
extern void (*TexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
extern void (*TexParameterf)(GLenum target, GLenum pname, GLfloat param);
extern void (*TexParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
extern void (*TexParameteri)(GLenum target, GLenum pname, GLint param);
extern void (*TexParameteriv)(GLenum target, GLenum pname, const GLint *params);
extern void (*Viewport)(GLint x, GLint y, GLsizei width, GLsizei height);

}