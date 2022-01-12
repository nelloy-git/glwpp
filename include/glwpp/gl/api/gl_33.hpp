#pragma once
#include "glwpp/gl/api/gl_32.hpp"

namespace glwpp::gl {

bool LoadGl_33(LoadFunc func);

extern void (*BindFragDataLocationIndexed)(UInt program, UInt colorNumber, UInt index, const Char * name);
extern void (*BindSampler)(UInt unit, UInt sampler);
extern void (*DeleteSamplers)(Sizei count, const UInt * samplers);
extern void (*GenSamplers)(Sizei count, UInt * sampler);
extern Int (*GetFragDataIndex)(UInt program, const Char * name);
extern void (*GetQueryObjecti64v)(UInt id, Enum pname, GLint64 * params);
extern void (*GetQueryObjectui64v)(UInt id, Enum pname, GLuint64 * params);
extern void (*GetSamplerParameterIiv)(UInt sampler, Enum pname, Int * params);
extern void (*GetSamplerParameterIuiv)(UInt sampler, Enum pname, UInt * params);
extern void (*GetSamplerParameterfv)(UInt sampler, Enum pname, Float * params);
extern void (*GetSamplerParameteriv)(UInt sampler, Enum pname, Int * params);
extern Bool (*IsSampler)(UInt sampler);
extern void (*QueryCounter)(UInt id, Enum target);
extern void (*SamplerParameterIiv)(UInt sampler, Enum pname, const Int * param);
extern void (*SamplerParameterIuiv)(UInt sampler, Enum pname, const UInt * param);
extern void (*SamplerParameterf)(UInt sampler, Enum pname, Float param);
extern void (*SamplerParameterfv)(UInt sampler, Enum pname, const Float * param);
extern void (*SamplerParameteri)(UInt sampler, Enum pname, Int param);
extern void (*SamplerParameteriv)(UInt sampler, Enum pname, const Int * param);
extern void (*VertexAttribDivisor)(UInt index, UInt divisor);
extern void (*VertexAttribP1ui)(UInt index, Enum type, Bool normalized, UInt value);
extern void (*VertexAttribP1uiv)(UInt index, Enum type, Bool normalized, const UInt * value);
extern void (*VertexAttribP2ui)(UInt index, Enum type, Bool normalized, UInt value);
extern void (*VertexAttribP2uiv)(UInt index, Enum type, Bool normalized, const UInt * value);
extern void (*VertexAttribP3ui)(UInt index, Enum type, Bool normalized, UInt value);
extern void (*VertexAttribP3uiv)(UInt index, Enum type, Bool normalized, const UInt * value);
extern void (*VertexAttribP4ui)(UInt index, Enum type, Bool normalized, UInt value);
extern void (*VertexAttribP4uiv)(UInt index, Enum type, Bool normalized, const UInt * value);

}