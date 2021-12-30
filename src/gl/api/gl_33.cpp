#include "glwpp/gl/api/gl_33.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::BindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name) = nullptr;
void (*gl::BindSampler)(GLuint unit, GLuint sampler) = nullptr;
void (*gl::DeleteSamplers)(GLsizei count, const GLuint * samplers) = nullptr;
void (*gl::GenSamplers)(GLsizei count, GLuint * sampler) = nullptr;
GLint (*gl::GetFragDataIndex)(GLuint program, const GLchar * name) = nullptr;
void (*gl::GetQueryObjecti64v)(GLuint id, GLenum pname, GLint64 * params) = nullptr;
void (*gl::GetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64 * params) = nullptr;
void (*gl::GetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint * params) = nullptr;
void (*gl::GetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint * params) = nullptr;
void (*gl::GetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat * params) = nullptr;
void (*gl::GetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint * params) = nullptr;
GLboolean (*gl::IsSampler)(GLuint sampler) = nullptr;
void (*gl::QueryCounter)(GLuint id, GLenum target) = nullptr;
void (*gl::SamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint * param) = nullptr;
void (*gl::SamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint * param) = nullptr;
void (*gl::SamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param) = nullptr;
void (*gl::SamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat * param) = nullptr;
void (*gl::SamplerParameteri)(GLuint sampler, GLenum pname, GLint param) = nullptr;
void (*gl::SamplerParameteriv)(GLuint sampler, GLenum pname, const GLint * param) = nullptr;
void (*gl::VertexAttribDivisor)(GLuint index, GLuint divisor) = nullptr;
void (*gl::VertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value) = nullptr;
void (*gl::VertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) = nullptr;
void (*gl::VertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value) = nullptr;
void (*gl::VertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) = nullptr;
void (*gl::VertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value) = nullptr;
void (*gl::VertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) = nullptr;
void (*gl::VertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value) = nullptr;
void (*gl::VertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) = nullptr;

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