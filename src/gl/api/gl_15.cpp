#include "glwpp/gl/api/gl_15.hpp"

#include "glad/gl.h"

using namespace glwpp;

void (*gl::BeginQuery)(Enum target, UInt id) = nullptr;
void (*gl::BindBuffer)(Enum target, UInt buffer) = nullptr;
void (*gl::BufferData)(Enum target, SizeiPtr size, const void * data, Enum usage) = nullptr;
void (*gl::BufferSubData)(Enum target, IntPtr offset, SizeiPtr size, const void * data) = nullptr;
void (*gl::DeleteBuffers)(Sizei n, const UInt * buffers) = nullptr;
void (*gl::DeleteQueries)(Sizei n, const UInt * ids) = nullptr;
void (*gl::EndQuery)(Enum target) = nullptr;
void (*gl::GenBuffers)(Sizei n, UInt * buffers) = nullptr;
void (*gl::GenQueries)(Sizei n, UInt * ids) = nullptr;
void (*gl::GetBufferParameteriv)(Enum target, Enum pname, Int * params) = nullptr;
void (*gl::GetBufferPointerv)(Enum target, Enum pname, void ** params) = nullptr;
void (*gl::GetBufferSubData)(Enum target, IntPtr offset, SizeiPtr size, void * data) = nullptr;
void (*gl::GetQueryObjectiv)(UInt id, Enum pname, Int * params) = nullptr;
void (*gl::GetQueryObjectuiv)(UInt id, Enum pname, UInt * params) = nullptr;
void (*gl::GetQueryiv)(Enum target, Enum pname, Int * params) = nullptr;
GLboolean (*gl::IsBuffer)(UInt buffer) = nullptr;
GLboolean (*gl::IsQuery)(UInt id) = nullptr;
void* (*gl::MapBuffer)(Enum target, Enum access) = nullptr;
GLboolean (*gl::UnmapBuffer)(Enum target) = nullptr;

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