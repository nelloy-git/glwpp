#pragma once
#include "glwpp/gl/api/gl_14.hpp"

namespace glwpp::gl {

bool LoadGl_15(LoadFunc func);
 
extern void (*BeginQuery)(GLenum target, GLuint id);
extern void (*BindBuffer)(GLenum target, GLuint buffer);
extern void (*BufferData)(GLenum target, GLsizeiptr size, const void * data, GLenum usage);
extern void (*BufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void * data);
extern void (*DeleteBuffers)(GLsizei n, const GLuint * buffers);
extern void (*DeleteQueries)(GLsizei n, const GLuint * ids);
extern void (*EndQuery)(GLenum target);
extern void (*GenBuffers)(GLsizei n, GLuint * buffers);
extern void (*GenQueries)(GLsizei n, GLuint * ids);
extern void (*GetBufferParameteriv)(GLenum target, GLenum pname, GLint * params);
extern void (*GetBufferPointerv)(GLenum target, GLenum pname, void ** params);
extern void (*GetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, void * data);
extern void (*GetQueryObjectiv)(GLuint id, GLenum pname, GLint * params);
extern void (*GetQueryObjectuiv)(GLuint id, GLenum pname, GLuint * params);
extern void (*GetQueryiv)(GLenum target, GLenum pname, GLint * params);
extern GLboolean (*IsBuffer)(GLuint buffer);
extern GLboolean (*IsQuery)(GLuint id);
extern void* (*MapBuffer)(GLenum target, GLenum access);
extern GLboolean (*UnmapBuffer)(GLenum target);

}