#include "glwpp/gl/api/gl_15.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::BeginQuery)(GLenum target, GLuint id) = nullptr;
void (*gl::BindBuffer)(GLenum target, GLuint buffer) = nullptr;
void (*gl::BufferData)(GLenum target, GLsizeiptr size, const void * data, GLenum usage) = nullptr;
void (*gl::BufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void * data) = nullptr;
void (*gl::DeleteBuffers)(GLsizei n, const GLuint * buffers) = nullptr;
void (*gl::DeleteQueries)(GLsizei n, const GLuint * ids) = nullptr;
void (*gl::EndQuery)(GLenum target) = nullptr;
void (*gl::GenBuffers)(GLsizei n, GLuint * buffers) = nullptr;
void (*gl::GenQueries)(GLsizei n, GLuint * ids) = nullptr;
void (*gl::GetBufferParameteriv)(GLenum target, GLenum pname, GLint * params) = nullptr;
void (*gl::GetBufferPointerv)(GLenum target, GLenum pname, void ** params) = nullptr;
void (*gl::GetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, void * data) = nullptr;
void (*gl::GetQueryObjectiv)(GLuint id, GLenum pname, GLint * params) = nullptr;
void (*gl::GetQueryObjectuiv)(GLuint id, GLenum pname, GLuint * params) = nullptr;
void (*gl::GetQueryiv)(GLenum target, GLenum pname, GLint * params) = nullptr;
GLboolean (*gl::IsBuffer)(GLuint buffer) = nullptr;
GLboolean (*gl::IsQuery)(GLuint id) = nullptr;
void* (*gl::MapBuffer)(GLenum target, GLenum access) = nullptr;
GLboolean (*gl::UnmapBuffer)(GLenum target) = nullptr;

bool gl::LoadGl_15(LoadFunc func){
    if (!LoadGl_14(func)){
        return false;
    }
 
    gl::BeginQuery = glBeginQuery;
    gl::BindBuffer = glBindBuffer;
    gl::BufferData = glBufferData;
    gl::BufferSubData = glBufferSubData;
    gl::DeleteBuffers = glDeleteBuffers;
    gl::DeleteQueries = glDeleteQueries;
    gl::EndQuery = glEndQuery;
    gl::GenBuffers = glGenBuffers;
    gl::GenQueries = glGenQueries;
    gl::GetBufferParameteriv = glGetBufferParameteriv;
    gl::GetBufferPointerv = glGetBufferPointerv;
    gl::GetBufferSubData = glGetBufferSubData;
    gl::GetQueryObjectiv = glGetQueryObjectiv;
    gl::GetQueryObjectuiv = glGetQueryObjectuiv;
    gl::GetQueryiv = glGetQueryiv;
    gl::IsBuffer = glIsBuffer;
    gl::IsQuery = glIsQuery;
    gl::MapBuffer = glMapBuffer;
    gl::UnmapBuffer = glUnmapBuffer;

    return true;
}