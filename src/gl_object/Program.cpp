#include "gl_object/Program.hpp"

using namespace glwpp;
using namespace glwpp::GL;

Program::Program(Context& ctx,
                 const SrcLoc& src_loc,
                 const IsCtxTrue& IsCtx) :
    Handler(ctx, &_Init, &_Free, src_loc, IsCtx){
}

Program::Program(Context& ctx,
                 const SrcLoc& src_loc,
                 const IsCtxFalse& IsCtx) :
    Handler(ctx, &_Init, &_Free, src_loc, IsCtx){
}

Program::Program(Context& ctx,
                 const SrcLoc& src_loc,
                 const IsCtxUnknown& IsCtx) :
    Handler(ctx, &_Init, &_Free, src_loc, IsCtx){
}

GLuint Program::_Init(Context& ctx, const SrcLoc& src_loc){
    return ctx.gl().CreateProgram<TState::True>(src_loc);
}

void Program::_Free(Context& ctx, const GLuint& id, const SrcLoc& src_loc){
    ctx.gl().DeleteProgram<TState::True>(id, src_loc);
}

void Program::_attach(Context& ctx, const Shader& shader, const SrcLoc& src_loc){
    ctx.gl().AttachShader<TState::True>(id().value(), shader.id().value(), src_loc);
}

void Program::_link(Context& ctx, const SrcLoc& src_loc){
    ctx.gl().LinkProgram<TState::True>(id().value(), src_loc);
}

void Program::_validate(Context& ctx, const SrcLoc& src_loc) const {
    ctx.gl().ValidateProgram<TState::True>(id().value(), src_loc);
}

void Program::_use(Context& ctx, const SrcLoc& src_loc) const {
    ctx.gl().UseProgram<TState::True>(id().value(), src_loc);
}

GLint Program::_getParameteriv(Context& ctx, const GLenum& pname, const SrcLoc& src_loc) const {
    GLint dst;
    ctx.gl().GetProgramiv<TState::True>(id().value(), pname, &dst, src_loc);
    return dst;
}

std::string Program::_getInfoLog(Context& ctx, const SrcLoc& src_loc) const {
    GLint len = _getParameteriv(ctx, GL_INFO_LOG_LENGTH, src_loc);
    std::string dst;
    dst.resize(len);
    ctx.gl().GetProgramInfoLog<TState::True>(id().value(), len, &len, dst.data(), src_loc);
    return dst;
}



void Program::_setUniform1d(Context& ctx, const GLint& location, const GLdouble& v0, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform1d<TState::True>(id().value(), location, v0, src_loc);
}

void Program::_setUniform1dv(Context& ctx, const GLint& location, const GLuint& count, const GLdouble* arr, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform1dv<TState::True>(id().value(), location, count, arr, src_loc);
}

void Program::_setUniform2d(Context& ctx, const GLint& location, const GLdouble& v0, const GLdouble& v1, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform2d<TState::True>(id().value(), location, v0, v1, src_loc);
}

void Program::_setUniform2dv(Context& ctx, const GLint& location, const GLuint& count, const GLdouble* arr, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform2dv<TState::True>(id().value(), location, count, arr, src_loc);
}

void Program::_setUniform3d(Context& ctx, const GLint& location, const GLdouble& v0, const GLdouble& v1, const GLdouble& v2, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform3d<TState::True>(id().value(), location, v0, v1, v2, src_loc);
}

void Program::_setUniform3dv(Context& ctx, const GLint& location, const GLuint& count, const GLdouble* arr, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform3dv<TState::True>(id().value(), location, count, arr, src_loc);
}

void Program::_setUniform4d(Context& ctx, const GLint& location, const GLdouble& v0, const GLdouble& v1, const GLdouble& v2, const GLdouble& v3, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform4d<TState::True>(id().value(), location, v0, v1, v2, v3, src_loc);
}

void Program::_setUniform4dv(Context& ctx, const GLint& location, const GLuint& count, const GLdouble* arr, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform4dv<TState::True>(id().value(), location, count, arr, src_loc);
}



void Program::_setUniform1f(Context& ctx, const GLint& location, const GLfloat& v0, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform1f<TState::True>(id().value(), location, v0, src_loc);
}

void Program::_setUniform1fv(Context& ctx, const GLint& location, const GLuint& count, const GLfloat* arr, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform1fv<TState::True>(id().value(), location, count, arr, src_loc);
}

void Program::_setUniform2f(Context& ctx, const GLint& location, const GLfloat& v0, const GLfloat& v1, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform2f<TState::True>(id().value(), location, v0, v1, src_loc);
}

void Program::_setUniform2fv(Context& ctx, const GLint& location, const GLuint& count, const GLfloat* arr, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform2fv<TState::True>(id().value(), location, count, arr, src_loc);
}

void Program::_setUniform3f(Context& ctx, const GLint& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform3f<TState::True>(id().value(), location, v0, v1, v2, src_loc);
}

void Program::_setUniform3fv(Context& ctx, const GLint& location, const GLuint& count, const GLfloat* arr, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform3fv<TState::True>(id().value(), location, count, arr, src_loc);
}

void Program::_setUniform4f(Context& ctx, const GLint& location, const GLfloat& v0, const GLfloat& v1, const GLfloat& v2, const GLfloat& v3, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform4f<TState::True>(id().value(), location, v0, v1, v2, v3, src_loc);
}

void Program::_setUniform4fv(Context& ctx, const GLint& location, const GLuint& count, const GLfloat* arr, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform4fv<TState::True>(id().value(), location, count, arr, src_loc);
}



void Program::_setUniform1i(Context& ctx, const GLint& location, const GLint& v0, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform1i<TState::True>(id().value(), location, v0, src_loc);
}

void Program::_setUniform1iv(Context& ctx, const GLint& location, const GLuint& count, const GLint* arr, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform1iv<TState::True>(id().value(), location, count, arr, src_loc);
}

void Program::_setUniform2i(Context& ctx, const GLint& location, const GLint& v0, const GLint& v1, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform2i<TState::True>(id().value(), location, v0, v1, src_loc);
}

void Program::_setUniform2iv(Context& ctx, const GLint& location, const GLuint& count, const GLint* arr, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform2iv<TState::True>(id().value(), location, count, arr, src_loc);
}

void Program::_setUniform3i(Context& ctx, const GLint& location, const GLint& v0, const GLint& v1, const GLint& v2, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform3i<TState::True>(id().value(), location, v0, v1, v2, src_loc);
}

void Program::_setUniform3iv(Context& ctx, const GLint& location, const GLuint& count, const GLint* arr, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform3iv<TState::True>(id().value(), location, count, arr, src_loc);
}

void Program::_setUniform4i(Context& ctx, const GLint& location, const GLint& v0, const GLint& v1, const GLint& v2, const GLint& v3, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform4i<TState::True>(id().value(), location, v0, v1, v2, v3, src_loc);
}

void Program::_setUniform4iv(Context& ctx, const GLint& location, const GLuint& count, const GLint* arr, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform4iv<TState::True>(id().value(), location, count, arr, src_loc);
}



void Program::_setUniform1ui(Context& ctx, const GLint& location, const GLuint& v0, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform1ui<TState::True>(id().value(), location, v0, src_loc);
}

void Program::_setUniform1uiv(Context& ctx, const GLint& location, const GLuint& count, const GLuint* arr, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform1uiv<TState::True>(id().value(), location, count, arr, src_loc);
}

void Program::_setUniform2ui(Context& ctx, const GLint& location, const GLuint& v0, const GLuint& v1, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform2ui<TState::True>(id().value(), location, v0, v1, src_loc);
}

void Program::_setUniform2uiv(Context& ctx, const GLint& location, const GLuint& count, const GLuint* arr, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform2uiv<TState::True>(id().value(), location, count, arr, src_loc);
}

void Program::_setUniform3ui(Context& ctx, const GLint& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform3ui<TState::True>(id().value(), location, v0, v1, v2, src_loc);
}

void Program::_setUniform3uiv(Context& ctx, const GLint& location, const GLuint& count, const GLuint* arr, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform3uiv<TState::True>(id().value(), location, count, arr, src_loc);
}

void Program::_setUniform4ui(Context& ctx, const GLint& location, const GLuint& v0, const GLuint& v1, const GLuint& v2, const GLuint& v3, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform4ui<TState::True>(id().value(), location, v0, v1, v2, v3, src_loc);
}

void Program::_setUniform4uiv(Context& ctx, const GLint& location, const GLuint& count, const GLuint* arr, const SrcLoc& src_loc){
    ctx.gl().ProgramUniform4uiv<TState::True>(id().value(), location, count, arr, src_loc);
}