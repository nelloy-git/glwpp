#include "glwpp/gl/api/gl_40.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::BeginQueryIndexed)(Enum target, UInt index, UInt id) = nullptr;
void (*gl::BindTransformFeedback)(Enum target, UInt id) = nullptr;
void (*gl::BlendEquationSeparatei)(UInt buf, Enum modeRGB, Enum modeAlpha) = nullptr;
void (*gl::BlendEquationi)(UInt buf, Enum mode) = nullptr;
void (*gl::BlendFuncSeparatei)(UInt buf, Enum srcRGB, Enum dstRGB, Enum srcAlpha, Enum dstAlpha) = nullptr;
void (*gl::BlendFunci)(UInt buf, Enum src, Enum dst) = nullptr;
void (*gl::DeleteTransformFeedbacks)(Sizei n, const UInt * ids) = nullptr;
void (*gl::DrawArraysIndirect)(Enum mode, const void * indirect) = nullptr;
void (*gl::DrawElementsIndirect)(Enum mode, Enum type, const void * indirect) = nullptr;
void (*gl::DrawTransformFeedback)(Enum mode, UInt id) = nullptr;
void (*gl::DrawTransformFeedbackStream)(Enum mode, UInt id, UInt stream) = nullptr;
void (*gl::EndQueryIndexed)(Enum target, UInt index) = nullptr;
void (*gl::GenTransformFeedbacks)(Sizei n, UInt * ids) = nullptr;
void (*gl::GetActiveSubroutineName)(UInt program, Enum shadertype, UInt index, Sizei bufSize, Sizei * length, Char * name) = nullptr;
void (*gl::GetActiveSubroutineUniformName)(UInt program, Enum shadertype, UInt index, Sizei bufSize, Sizei * length, Char * name) = nullptr;
void (*gl::GetActiveSubroutineUniformiv)(UInt program, Enum shadertype, UInt index, Enum pname, Int * values) = nullptr;
void (*gl::GetProgramStageiv)(UInt program, Enum shadertype, Enum pname, Int * values) = nullptr;
void (*gl::GetQueryIndexediv)(Enum target, UInt index, Enum pname, Int * params) = nullptr;
GLuint (*gl::GetSubroutineIndex)(UInt program, Enum shadertype, const Char * name) = nullptr;
GLint (*gl::GetSubroutineUniformLocation)(UInt program, Enum shadertype, const Char * name) = nullptr;
void (*gl::GetUniformSubroutineuiv)(Enum shadertype, Int location, UInt * params) = nullptr;
void (*gl::GetUniformdv)(UInt program, Int location, Double * params) = nullptr;
GLboolean (*gl::IsTransformFeedback)(UInt id) = nullptr;
void (*gl::MinSampleShading)(Float value) = nullptr;
void (*gl::PatchParameterfv)(Enum pname, const Float * values) = nullptr;
void (*gl::PatchParameteri)(Enum pname, Int value) = nullptr;
void (*gl::PauseTransformFeedback)() = nullptr;
void (*gl::ResumeTransformFeedback)() = nullptr;
void (*gl::Uniform1d)(Int location, Double x) = nullptr;
void (*gl::Uniform1dv)(Int location, Sizei count, const Double * value) = nullptr;
void (*gl::Uniform2d)(Int location, Double x, Double y) = nullptr;
void (*gl::Uniform2dv)(Int location, Sizei count, const Double * value) = nullptr;
void (*gl::Uniform3d)(Int location, Double x, Double y, Double z) = nullptr;
void (*gl::Uniform3dv)(Int location, Sizei count, const Double * value) = nullptr;
void (*gl::Uniform4d)(Int location, Double x, Double y, Double z, Double w) = nullptr;
void (*gl::Uniform4dv)(Int location, Sizei count, const Double * value) = nullptr;
void (*gl::UniformMatrix2dv)(Int location, Sizei count, Bool transpose, const Double * value) = nullptr;
void (*gl::UniformMatrix2x3dv)(Int location, Sizei count, Bool transpose, const Double * value) = nullptr;
void (*gl::UniformMatrix2x4dv)(Int location, Sizei count, Bool transpose, const Double * value) = nullptr;
void (*gl::UniformMatrix3dv)(Int location, Sizei count, Bool transpose, const Double * value) = nullptr;
void (*gl::UniformMatrix3x2dv)(Int location, Sizei count, Bool transpose, const Double * value) = nullptr;
void (*gl::UniformMatrix3x4dv)(Int location, Sizei count, Bool transpose, const Double * value) = nullptr;
void (*gl::UniformMatrix4dv)(Int location, Sizei count, Bool transpose, const Double * value) = nullptr;
void (*gl::UniformMatrix4x2dv)(Int location, Sizei count, Bool transpose, const Double * value) = nullptr;
void (*gl::UniformMatrix4x3dv)(Int location, Sizei count, Bool transpose, const Double * value) = nullptr;
void (*gl::UniformSubroutinesuiv)(Enum shadertype, Sizei count, const UInt * indices) = nullptr;

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