#pragma once
#include "glwpp/gl/api/gl_33.hpp"

namespace glwpp::gl {

bool LoadGl_40(LoadFunc func);

extern void (*BeginQueryIndexed)(Enum target, UInt index, UInt id);
extern void (*BindTransformFeedback)(Enum target, UInt id);
extern void (*BlendEquationSeparatei)(UInt buf, Enum modeRGB, Enum modeAlpha);
extern void (*BlendEquationi)(UInt buf, Enum mode);
extern void (*BlendFuncSeparatei)(UInt buf, Enum srcRGB, Enum dstRGB, Enum srcAlpha, Enum dstAlpha);
extern void (*BlendFunci)(UInt buf, Enum src, Enum dst);
extern void (*DeleteTransformFeedbacks)(Sizei n, const UInt * ids);
extern void (*DrawArraysIndirect)(Enum mode, const void * indirect);
extern void (*DrawElementsIndirect)(Enum mode, Enum type, const void * indirect);
extern void (*DrawTransformFeedback)(Enum mode, UInt id);
extern void (*DrawTransformFeedbackStream)(Enum mode, UInt id, UInt stream);
extern void (*EndQueryIndexed)(Enum target, UInt index);
extern void (*GenTransformFeedbacks)(Sizei n, UInt * ids);
extern void (*GetActiveSubroutineName)(UInt program, Enum shadertype, UInt index, Sizei bufSize, Sizei * length, Char * name);
extern void (*GetActiveSubroutineUniformName)(UInt program, Enum shadertype, UInt index, Sizei bufSize, Sizei * length, Char * name);
extern void (*GetActiveSubroutineUniformiv)(UInt program, Enum shadertype, UInt index, Enum pname, Int * values);
extern void (*GetProgramStageiv)(UInt program, Enum shadertype, Enum pname, Int * values);
extern void (*GetQueryIndexediv)(Enum target, UInt index, Enum pname, Int * params);
extern UInt (*GetSubroutineIndex)(UInt program, Enum shadertype, const Char * name);
extern Int (*GetSubroutineUniformLocation)(UInt program, Enum shadertype, const Char * name);
extern void (*GetUniformSubroutineuiv)(Enum shadertype, Int location, UInt * params);
extern void (*GetUniformdv)(UInt program, Int location, Double * params);
extern Bool (*IsTransformFeedback)(UInt id);
extern void (*MinSampleShading)(Float value);
extern void (*PatchParameterfv)(Enum pname, const Float * values);
extern void (*PatchParameteri)(Enum pname, Int value);
extern void (*PauseTransformFeedback)();
extern void (*ResumeTransformFeedback)();
extern void (*Uniform1d)(Int location, Double x);
extern void (*Uniform1dv)(Int location, Sizei count, const Double * value);
extern void (*Uniform2d)(Int location, Double x, Double y);
extern void (*Uniform2dv)(Int location, Sizei count, const Double * value);
extern void (*Uniform3d)(Int location, Double x, Double y, Double z);
extern void (*Uniform3dv)(Int location, Sizei count, const Double * value);
extern void (*Uniform4d)(Int location, Double x, Double y, Double z, Double w);
extern void (*Uniform4dv)(Int location, Sizei count, const Double * value);
extern void (*UniformMatrix2dv)(Int location, Sizei count, Bool transpose, const Double * value);
extern void (*UniformMatrix2x3dv)(Int location, Sizei count, Bool transpose, const Double * value);
extern void (*UniformMatrix2x4dv)(Int location, Sizei count, Bool transpose, const Double * value);
extern void (*UniformMatrix3dv)(Int location, Sizei count, Bool transpose, const Double * value);
extern void (*UniformMatrix3x2dv)(Int location, Sizei count, Bool transpose, const Double * value);
extern void (*UniformMatrix3x4dv)(Int location, Sizei count, Bool transpose, const Double * value);
extern void (*UniformMatrix4dv)(Int location, Sizei count, Bool transpose, const Double * value);
extern void (*UniformMatrix4x2dv)(Int location, Sizei count, Bool transpose, const Double * value);
extern void (*UniformMatrix4x3dv)(Int location, Sizei count, Bool transpose, const Double * value);
extern void (*UniformSubroutinesuiv)(Enum shadertype, Sizei count, const UInt * indices);

}