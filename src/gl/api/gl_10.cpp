#include "glwpp/gl/api/gl_10.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::BlendFunc)(GLenum sfactor, GLenum dfactor) = nullptr;
void (*gl::Clear)(GLbitfield mask) = nullptr;
void (*gl::ClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = nullptr;
void (*gl::ClearDepth)(GLdouble depth) = nullptr;
void (*gl::ClearStencil)(GLint s) = nullptr;
void (*gl::ColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) = nullptr;
void (*gl::CullFace)(GLenum mode) = nullptr;
void (*gl::DepthFunc)(GLenum func) = nullptr;
void (*gl::DepthMask)(GLboolean flag) = nullptr;
void (*gl::DepthRange)(GLdouble n, GLdouble f) = nullptr;
void (*gl::Disable)(GLenum cap) = nullptr;
void (*gl::DrawBuffer)(GLenum buf) = nullptr;
void (*gl::Enable)(GLenum cap) = nullptr;
void (*gl::Finish)() = nullptr;
void (*gl::Flush)() = nullptr;
void (*gl::FrontFace)(GLenum mode) = nullptr;
void (*gl::GetBooleanv)(GLenum pname, GLboolean *data) = nullptr;
void (*gl::GetDoublev)(GLenum pname, GLdouble *data) = nullptr;
GLenum (*gl::GetError)() = nullptr;
void (*gl::GetFloatv)(GLenum pname, GLfloat *data) = nullptr;
void (*gl::GetIntegerv)(GLenum pname, GLint *data) = nullptr;
const GLubyte* (*gl::GetString)(GLenum name) = nullptr;
void (*gl::GetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void *pixels) = nullptr;
void (*gl::GetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat *params) = nullptr;
void (*gl::GetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint *params) = nullptr;
void (*gl::GetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params) = nullptr;
void (*gl::GetTexParameteriv)(GLenum target, GLenum pname, GLint *params) = nullptr;
void (*gl::Hint)(GLenum target, GLenum mode) = nullptr;
GLboolean (*gl::IsEnabled)(GLenum cap) = nullptr;
void (*gl::LineWidth)(GLfloat width) = nullptr;
void (*gl::LogicOp)(GLenum opcode) = nullptr;
void (*gl::PixelStoref)(GLenum pname, GLfloat param) = nullptr;
void (*gl::PixelStorei)(GLenum pname, GLint param) = nullptr;
void (*gl::PointSize)(GLfloat size) = nullptr;
void (*gl::PolygonMode)(GLenum face, GLenum mode) = nullptr;
void (*gl::ReadBuffer)(GLenum src) = nullptr;
void (*gl::ReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) = nullptr;
void (*gl::Scissor)(GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;
void (*gl::StencilFunc)(GLenum func, GLint ref, GLuint mask) = nullptr;
void (*gl::StencilMask)(GLuint mask) = nullptr;
void (*gl::StencilOp)(GLenum fail, GLenum zfail, GLenum zpass) = nullptr;
void (*gl::TexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels) = nullptr;
void (*gl::TexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) = nullptr;
void (*gl::TexParameterf)(GLenum target, GLenum pname, GLfloat param) = nullptr;
void (*gl::TexParameterfv)(GLenum target, GLenum pname, const GLfloat *params) = nullptr;
void (*gl::TexParameteri)(GLenum target, GLenum pname, GLint param) = nullptr;
void (*gl::TexParameteriv)(GLenum target, GLenum pname, const GLint *params) = nullptr;
void (*gl::Viewport)(GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;

bool gl::LoadGl_10(LoadFunc func){
    if (!gl::LoadGl_glad(func)){
        return false;
    };

    gl::BlendFunc = glBlendFunc;
    gl::Clear = glClear;
    gl::ClearColor = glClearColor;
    gl::ClearDepth = glClearDepth;
    gl::ClearStencil = glClearStencil;
    gl::ColorMask = glColorMask;
    gl::CullFace = glCullFace;
    gl::DepthFunc = glDepthFunc;
    gl::DepthMask = glDepthMask;
    gl::DepthRange = glDepthRange;
    gl::Disable = glDisable;
    gl::DrawBuffer = glDrawBuffer;
    gl::Enable = glEnable;
    gl::Finish = glFinish;
    gl::Flush = glFlush;
    gl::FrontFace = glFrontFace;
    gl::GetBooleanv = glGetBooleanv;
    gl::GetDoublev = glGetDoublev;
    gl::GetError = glGetError;
    gl::GetFloatv = glGetFloatv;
    gl::GetIntegerv = glGetIntegerv;
    gl::GetString = glGetString;
    gl::GetTexImage = glGetTexImage;
    gl::GetTexLevelParameterfv = glGetTexLevelParameterfv;
    gl::GetTexLevelParameteriv = glGetTexLevelParameteriv;
    gl::GetTexParameterfv = glGetTexParameterfv;
    gl::GetTexParameteriv = glGetTexParameteriv;
    gl::Hint = glHint;
    gl::IsEnabled = glIsEnabled;
    gl::LineWidth = glLineWidth;
    gl::LogicOp = glLogicOp;
    gl::PixelStoref = glPixelStoref;
    gl::PixelStorei = glPixelStorei;
    gl::PointSize = glPointSize;
    gl::PolygonMode = glPolygonMode;
    gl::ReadBuffer = glReadBuffer;
    gl::ReadPixels = glReadPixels;
    gl::Scissor = glScissor;
    gl::StencilFunc = glStencilFunc;
    gl::StencilMask = glStencilMask;
    gl::StencilOp = glStencilOp;
    gl::TexImage1D = glTexImage1D;
    gl::TexImage2D = glTexImage2D;
    gl::TexParameterf = glTexParameterf;
    gl::TexParameterfv = glTexParameterfv;
    gl::TexParameteri = glTexParameteri;
    gl::TexParameteriv = glTexParameteriv;
    gl::Viewport = glViewport;

    return true;
}