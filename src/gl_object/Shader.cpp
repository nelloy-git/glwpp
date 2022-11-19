#include "gl_object/Shader.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace GL;

Shader::Shader(const std::shared_ptr<Context>& ctx, const Enum& type, const SrcLoc& src_loc) :
    Object(ctx, ctx->gl().call([](Gl& gl, const Enum& type, const SrcLoc& src_loc){
        auto id = glCreateShader(*type);
        gl.debug(src_loc);
        return id;
    }, type, src_loc)){
}

Shader::~Shader(){
    _callGLCustom([](Gl& gl, const Uint& id){
        glDeleteShader(*id);
    }, id());
}



void Shader::source(const String& code, const SrcLoc& src_loc){
    _callGLCustom([](Gl& gl, const Uint& id, const String& code, const SrcLoc& src_loc){
        auto c_str = code->c_str();
        int len = static_cast<int>(code->size());
        glShaderSource(*id, 1, &c_str, &len);
        gl.debug(src_loc);
    }, id(), code, src_loc);
}

void Shader::compile(const SrcLoc& src_loc){
    _callGL<&Gl::CompileShader>(id(), src_loc);
}



GL::Enum Shader::getType(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        unsigned int dst;
        glGetShaderiv(*id, GL_SHADER_TYPE, reinterpret_cast<int*>(&dst));
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}

GL::Boolean Shader::isCompiled(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        int dst;
        glGetShaderiv(*id, GL_COMPILE_STATUS, &dst);
        gl.debug(src_loc);
        return (unsigned char)(dst == GL_TRUE);
    }, id(), src_loc);
}

GL::Int Shader::getSourceLength(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        int dst;
        glGetShaderiv(*id, GL_SHADER_SOURCE_LENGTH, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}

GL::String Shader::getInfoLog(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        int len;
        glGetShaderiv(*id, GL_INFO_LOG_LENGTH, &len);
        gl.debug(src_loc);
        
        std::string dst;
        dst.resize(len);
        glGetShaderInfoLog(*id, len, &len, dst.data());
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}