#include "glwpp/gl/api/gl_33.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::BindFragDataLocationIndexed)(UInt program, UInt colorNumber, UInt index, const Char * name) = nullptr;
void (*gl::BindSampler)(UInt unit, UInt sampler) = nullptr;
void (*gl::DeleteSamplers)(Sizei count, const UInt * samplers) = nullptr;
void (*gl::GenSamplers)(Sizei count, UInt * sampler) = nullptr;
GLint (*gl::GetFragDataIndex)(UInt program, const Char * name) = nullptr;
void (*gl::GetQueryObjecti64v)(UInt id, Enum pname, GLint64 * params) = nullptr;
void (*gl::GetQueryObjectui64v)(UInt id, Enum pname, GLuint64 * params) = nullptr;
void (*gl::GetSamplerParameterIiv)(UInt sampler, Enum pname, Int * params) = nullptr;
void (*gl::GetSamplerParameterIuiv)(UInt sampler, Enum pname, UInt * params) = nullptr;
void (*gl::GetSamplerParameterfv)(UInt sampler, Enum pname, Float * params) = nullptr;
void (*gl::GetSamplerParameteriv)(UInt sampler, Enum pname, Int * params) = nullptr;
GLboolean (*gl::IsSampler)(UInt sampler) = nullptr;
void (*gl::QueryCounter)(UInt id, Enum target) = nullptr;
void (*gl::SamplerParameterIiv)(UInt sampler, Enum pname, const Int * param) = nullptr;
void (*gl::SamplerParameterIuiv)(UInt sampler, Enum pname, const UInt * param) = nullptr;
void (*gl::SamplerParameterf)(UInt sampler, Enum pname, Float param) = nullptr;
void (*gl::SamplerParameterfv)(UInt sampler, Enum pname, const Float * param) = nullptr;
void (*gl::SamplerParameteri)(UInt sampler, Enum pname, Int param) = nullptr;
void (*gl::SamplerParameteriv)(UInt sampler, Enum pname, const Int * param) = nullptr;
void (*gl::VertexAttribDivisor)(UInt index, UInt divisor) = nullptr;
void (*gl::VertexAttribP1ui)(UInt index, Enum type, Bool normalized, UInt value) = nullptr;
void (*gl::VertexAttribP1uiv)(UInt index, Enum type, Bool normalized, const UInt * value) = nullptr;
void (*gl::VertexAttribP2ui)(UInt index, Enum type, Bool normalized, UInt value) = nullptr;
void (*gl::VertexAttribP2uiv)(UInt index, Enum type, Bool normalized, const UInt * value) = nullptr;
void (*gl::VertexAttribP3ui)(UInt index, Enum type, Bool normalized, UInt value) = nullptr;
void (*gl::VertexAttribP3uiv)(UInt index, Enum type, Bool normalized, const UInt * value) = nullptr;
void (*gl::VertexAttribP4ui)(UInt index, Enum type, Bool normalized, UInt value) = nullptr;
void (*gl::VertexAttribP4uiv)(UInt index, Enum type, Bool normalized, const UInt * value) = nullptr;

bool gl::LoadGl_33(LoadFunc func){
    if (!LoadGl_32(func)){
        return false;
    }
 
    gl::BindFragDataLocationIndexed = glBindFragDataLocationIndexed;
    gl::BindSampler = glBindSampler;
    gl::DeleteSamplers = glDeleteSamplers;
    gl::GenSamplers = glGenSamplers;
    gl::GetFragDataIndex = glGetFragDataIndex;
    gl::GetQueryObjecti64v = glGetQueryObjecti64v;
    gl::GetQueryObjectui64v = glGetQueryObjectui64v;
    gl::GetSamplerParameterIiv = glGetSamplerParameterIiv;
    gl::GetSamplerParameterIuiv = glGetSamplerParameterIuiv;
    gl::GetSamplerParameterfv = glGetSamplerParameterfv;
    gl::GetSamplerParameteriv = glGetSamplerParameteriv;
    gl::IsSampler = glIsSampler;
    gl::QueryCounter = glQueryCounter;
    gl::SamplerParameterIiv = glSamplerParameterIiv;
    gl::SamplerParameterIuiv = glSamplerParameterIuiv;
    gl::SamplerParameterf = glSamplerParameterf;
    gl::SamplerParameterfv = glSamplerParameterfv;
    gl::SamplerParameteri = glSamplerParameteri;
    gl::SamplerParameteriv = glSamplerParameteriv;
    gl::VertexAttribDivisor = glVertexAttribDivisor;
    gl::VertexAttribP1ui = glVertexAttribP1ui;
    gl::VertexAttribP1uiv = glVertexAttribP1uiv;
    gl::VertexAttribP2ui = glVertexAttribP2ui;
    gl::VertexAttribP2uiv = glVertexAttribP2uiv;
    gl::VertexAttribP3ui = glVertexAttribP3ui;
    gl::VertexAttribP3uiv = glVertexAttribP3uiv;
    gl::VertexAttribP4ui = glVertexAttribP4ui;
    gl::VertexAttribP4uiv = glVertexAttribP4uiv;

    return true;
}