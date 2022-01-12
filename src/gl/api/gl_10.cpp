#include "glwpp/gl/api/gl_10.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::BlendFunc)(Enum sfactor, Enum dfactor) = nullptr;
void (*gl::Clear)(BitField mask) = nullptr;
void (*gl::ClearColor)(Float red, Float green, Float blue, Float alpha) = nullptr;
void (*gl::ClearDepth)(Double depth) = nullptr;
void (*gl::ClearStencil)(Int s) = nullptr;
void (*gl::ColorMask)(Bool red, Bool green, Bool blue, Bool alpha) = nullptr;
void (*gl::CullFace)(Enum mode) = nullptr;
void (*gl::DepthFunc)(Enum func) = nullptr;
void (*gl::DepthMask)(Bool flag) = nullptr;
void (*gl::DepthRange)(Double n, Double f) = nullptr;
void (*gl::Disable)(Enum cap) = nullptr;
void (*gl::DrawBuffer)(Enum buf) = nullptr;
void (*gl::Enable)(Enum cap) = nullptr;
void (*gl::Finish)() = nullptr;
void (*gl::Flush)() = nullptr;
void (*gl::FrontFace)(Enum mode) = nullptr;
void (*gl::GetBooleanv)(Enum pname, Bool *data) = nullptr;
void (*gl::GetDoublev)(Enum pname, Double *data) = nullptr;
GLenum (*gl::GetError)() = nullptr;
void (*gl::GetFloatv)(Enum pname, Float *data) = nullptr;
void (*gl::GetIntegerv)(Enum pname, Int *data) = nullptr;
const GLubyte* (*gl::GetString)(Enum name) = nullptr;
void (*gl::GetTexImage)(Enum target, Int level, Enum format, Enum type, void *pixels) = nullptr;
void (*gl::GetTexLevelParameterfv)(Enum target, Int level, Enum pname, Float *params) = nullptr;
void (*gl::GetTexLevelParameteriv)(Enum target, Int level, Enum pname, Int *params) = nullptr;
void (*gl::GetTexParameterfv)(Enum target, Enum pname, Float *params) = nullptr;
void (*gl::GetTexParameteriv)(Enum target, Enum pname, Int *params) = nullptr;
void (*gl::Hint)(Enum target, Enum mode) = nullptr;
GLboolean (*gl::IsEnabled)(Enum cap) = nullptr;
void (*gl::LineWidth)(Float width) = nullptr;
void (*gl::LogicOp)(Enum opcode) = nullptr;
void (*gl::PixelStoref)(Enum pname, Float param) = nullptr;
void (*gl::PixelStorei)(Enum pname, Int param) = nullptr;
void (*gl::PointSize)(Float size) = nullptr;
void (*gl::PolygonMode)(Enum face, Enum mode) = nullptr;
void (*gl::ReadBuffer)(Enum src) = nullptr;
void (*gl::ReadPixels)(Int x, Int y, Sizei width, Sizei height, Enum format, Enum type, void *pixels) = nullptr;
void (*gl::Scissor)(Int x, Int y, Sizei width, Sizei height) = nullptr;
void (*gl::StencilFunc)(Enum func, Int ref, UInt mask) = nullptr;
void (*gl::StencilMask)(UInt mask) = nullptr;
void (*gl::StencilOp)(Enum fail, Enum zfail, Enum zpass) = nullptr;
void (*gl::TexImage1D)(Enum target, Int level, Int internalformat, Sizei width, Int border, Enum format, Enum type, const void *pixels) = nullptr;
void (*gl::TexImage2D)(Enum target, Int level, Int internalformat, Sizei width, Sizei height, Int border, Enum format, Enum type, const void *pixels) = nullptr;
void (*gl::TexParameterf)(Enum target, Enum pname, Float param) = nullptr;
void (*gl::TexParameterfv)(Enum target, Enum pname, const Float *params) = nullptr;
void (*gl::TexParameteri)(Enum target, Enum pname, Int param) = nullptr;
void (*gl::TexParameteriv)(Enum target, Enum pname, const Int *params) = nullptr;
void (*gl::Viewport)(Int x, Int y, Sizei width, Sizei height) = nullptr;

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