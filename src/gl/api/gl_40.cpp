#include "glwpp/gl/api/gl_40.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::BeginQueryIndexed)(GLenum target, GLuint index, GLuint id) = nullptr;
void (*gl::BindTransformFeedback)(GLenum target, GLuint id) = nullptr;
void (*gl::BlendEquationSeparatei)(GLuint buf, GLenum modeRGB, GLenum modeAlpha) = nullptr;
void (*gl::BlendEquationi)(GLuint buf, GLenum mode) = nullptr;
void (*gl::BlendFuncSeparatei)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) = nullptr;
void (*gl::BlendFunci)(GLuint buf, GLenum src, GLenum dst) = nullptr;
void (*gl::DeleteTransformFeedbacks)(GLsizei n, const GLuint * ids) = nullptr;
void (*gl::DrawArraysIndirect)(GLenum mode, const void * indirect) = nullptr;
void (*gl::DrawElementsIndirect)(GLenum mode, GLenum type, const void * indirect) = nullptr;
void (*gl::DrawTransformFeedback)(GLenum mode, GLuint id) = nullptr;
void (*gl::DrawTransformFeedbackStream)(GLenum mode, GLuint id, GLuint stream) = nullptr;
void (*gl::EndQueryIndexed)(GLenum target, GLuint index) = nullptr;
void (*gl::GenTransformFeedbacks)(GLsizei n, GLuint * ids) = nullptr;
void (*gl::GetActiveSubroutineName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name) = nullptr;
void (*gl::GetActiveSubroutineUniformName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name) = nullptr;
void (*gl::GetActiveSubroutineUniformiv)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values) = nullptr;
void (*gl::GetProgramStageiv)(GLuint program, GLenum shadertype, GLenum pname, GLint * values) = nullptr;
void (*gl::GetQueryIndexediv)(GLenum target, GLuint index, GLenum pname, GLint * params) = nullptr;
GLuint (*gl::GetSubroutineIndex)(GLuint program, GLenum shadertype, const GLchar * name) = nullptr;
GLint (*gl::GetSubroutineUniformLocation)(GLuint program, GLenum shadertype, const GLchar * name) = nullptr;
void (*gl::GetUniformSubroutineuiv)(GLenum shadertype, GLint location, GLuint * params) = nullptr;
void (*gl::GetUniformdv)(GLuint program, GLint location, GLdouble * params) = nullptr;
GLboolean (*gl::IsTransformFeedback)(GLuint id) = nullptr;
void (*gl::MinSampleShading)(GLfloat value) = nullptr;
void (*gl::PatchParameterfv)(GLenum pname, const GLfloat * values) = nullptr;
void (*gl::PatchParameteri)(GLenum pname, GLint value) = nullptr;
void (*gl::PauseTransformFeedback)() = nullptr;
void (*gl::ResumeTransformFeedback)() = nullptr;
void (*gl::Uniform1d)(GLint location, GLdouble x) = nullptr;
void (*gl::Uniform1dv)(GLint location, GLsizei count, const GLdouble * value) = nullptr;
void (*gl::Uniform2d)(GLint location, GLdouble x, GLdouble y) = nullptr;
void (*gl::Uniform2dv)(GLint location, GLsizei count, const GLdouble * value) = nullptr;
void (*gl::Uniform3d)(GLint location, GLdouble x, GLdouble y, GLdouble z) = nullptr;
void (*gl::Uniform3dv)(GLint location, GLsizei count, const GLdouble * value) = nullptr;
void (*gl::Uniform4d)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = nullptr;
void (*gl::Uniform4dv)(GLint location, GLsizei count, const GLdouble * value) = nullptr;
void (*gl::UniformMatrix2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = nullptr;
void (*gl::UniformMatrix2x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = nullptr;
void (*gl::UniformMatrix2x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = nullptr;
void (*gl::UniformMatrix3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = nullptr;
void (*gl::UniformMatrix3x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = nullptr;
void (*gl::UniformMatrix3x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = nullptr;
void (*gl::UniformMatrix4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = nullptr;
void (*gl::UniformMatrix4x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = nullptr;
void (*gl::UniformMatrix4x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = nullptr;
void (*gl::UniformSubroutinesuiv)(GLenum shadertype, GLsizei count, const GLuint * indices) = nullptr;

bool gl::LoadGl_40(LoadFunc func){
    if (!LoadGl_33(func)){
        return false;
    }
 
    gl::BeginQueryIndexed = glBeginQueryIndexed;
    gl::BindTransformFeedback = glBindTransformFeedback;
    gl::BlendEquationSeparatei = glBlendEquationSeparatei;
    gl::BlendEquationi = glBlendEquationi;
    gl::BlendFuncSeparatei = glBlendFuncSeparatei;
    gl::BlendFunci = glBlendFunci;
    gl::DeleteTransformFeedbacks = glDeleteTransformFeedbacks;
    gl::DrawArraysIndirect = glDrawArraysIndirect;
    gl::DrawElementsIndirect = glDrawElementsIndirect;
    gl::DrawTransformFeedback = glDrawTransformFeedback;
    gl::DrawTransformFeedbackStream = glDrawTransformFeedbackStream;
    gl::EndQueryIndexed = glEndQueryIndexed;
    gl::GenTransformFeedbacks = glGenTransformFeedbacks;
    gl::GetActiveSubroutineName = glGetActiveSubroutineName;
    gl::GetActiveSubroutineUniformName = glGetActiveSubroutineUniformName;
    gl::GetActiveSubroutineUniformiv = glGetActiveSubroutineUniformiv;
    gl::GetProgramStageiv = glGetProgramStageiv;
    gl::GetQueryIndexediv = glGetQueryIndexediv;
    gl::GetSubroutineIndex = glGetSubroutineIndex;
    gl::GetSubroutineUniformLocation = glGetSubroutineUniformLocation;
    gl::GetUniformSubroutineuiv = glGetUniformSubroutineuiv;
    gl::GetUniformdv = glGetUniformdv;
    gl::IsTransformFeedback = glIsTransformFeedback;
    gl::MinSampleShading = glMinSampleShading;
    gl::PatchParameterfv = glPatchParameterfv;
    gl::PatchParameteri = glPatchParameteri;
    gl::PauseTransformFeedback = glPauseTransformFeedback;
    gl::ResumeTransformFeedback = glResumeTransformFeedback;
    gl::Uniform1d = glUniform1d;
    gl::Uniform1dv = glUniform1dv;
    gl::Uniform2d = glUniform2d;
    gl::Uniform2dv = glUniform2dv;
    gl::Uniform3d = glUniform3d;
    gl::Uniform3dv = glUniform3dv;
    gl::Uniform4d = glUniform4d;
    gl::Uniform4dv = glUniform4dv;
    gl::UniformMatrix2dv = glUniformMatrix2dv;
    gl::UniformMatrix2x3dv = glUniformMatrix2x3dv;
    gl::UniformMatrix2x4dv = glUniformMatrix2x4dv;
    gl::UniformMatrix3dv = glUniformMatrix3dv;
    gl::UniformMatrix3x2dv = glUniformMatrix3x2dv;
    gl::UniformMatrix3x4dv = glUniformMatrix3x4dv;
    gl::UniformMatrix4dv = glUniformMatrix4dv;
    gl::UniformMatrix4x2dv = glUniformMatrix4x2dv;
    gl::UniformMatrix4x3dv = glUniformMatrix4x3dv;
    gl::UniformSubroutinesuiv = glUniformSubroutinesuiv;

    return true;
}