#pragma once
#include "glwpp/gl/api/gl_32.hpp"

namespace glwpp::gl {

bool LoadGl_33(LoadFunc func);

extern void (*BindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name);
extern void (*BindSampler)(GLuint unit, GLuint sampler);
extern void (*DeleteSamplers)(GLsizei count, const GLuint * samplers);
extern void (*GenSamplers)(GLsizei count, GLuint * sampler);
extern GLint (*GetFragDataIndex)(GLuint program, const GLchar * name);
extern void (*GetQueryObjecti64v)(GLuint id, GLenum pname, GLint64 * params);
extern void (*GetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64 * params);
extern void (*GetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint * params);
extern void (*GetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint * params);
extern void (*GetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat * params);
extern void (*GetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint * params);
extern GLboolean (*IsSampler)(GLuint sampler);
extern void (*QueryCounter)(GLuint id, GLenum target);
extern void (*SamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint * param);
extern void (*SamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint * param);
extern void (*SamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param);
extern void (*SamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat * param);
extern void (*SamplerParameteri)(GLuint sampler, GLenum pname, GLint param);
extern void (*SamplerParameteriv)(GLuint sampler, GLenum pname, const GLint * param);
extern void (*VertexAttribDivisor)(GLuint index, GLuint divisor);
extern void (*VertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern void (*VertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
extern void (*VertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern void (*VertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
extern void (*VertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern void (*VertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
extern void (*VertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern void (*VertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);

}