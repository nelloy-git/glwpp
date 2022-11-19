#include "gl_object/Program.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace GL;


Program::Program(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc) :
    Object(ctx, ctx->gl().call([](Gl& gl, const SrcLoc& src_loc){
        unsigned int dst = glCreateProgram();
        gl.debug(src_loc);
        return dst;
    }, src_loc)){
}

Program::~Program(){
    _callGLCustom([](Gl& gl, const Uint& id){
        glDeleteProgram(*id);
    }, id());
}



void Program::attach(const Shader& shader, const SrcLoc& src_loc){
    _callGL<&Gl::AttachShader>(id(), shader.id(), src_loc);
}

void Program::link(const SrcLoc& src_loc){
    _callGL<&Gl::LinkProgram>(id(), src_loc);
}

void Program::validate(const SrcLoc& src_loc){
    _callGL<&Gl::ValidateProgram>(id(), src_loc);
}

void Program::use(const SrcLoc& src_loc){
    _callGL<&Gl::UseProgram>(id(), src_loc);
}




GL::Boolean Program::isLinked(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        int dst;
        glGetProgramiv(*id, GL_LINK_STATUS, &dst);
        gl.debug(src_loc);
        return (unsigned char)(dst == GL_TRUE);
    }, id(), src_loc);
}

GL::Boolean Program::isValidated(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        int dst;
        glGetProgramiv(*id, GL_VALIDATE_STATUS, &dst);
        gl.debug(src_loc);
        return (unsigned char)(dst == GL_TRUE);
    }, id(), src_loc);
}

GL::Int Program::getAttachedShadersCount(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        int dst;
        glGetProgramiv(*id, GL_ATTACHED_SHADERS, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}

GL::Int Program::getActiveAttributesCount(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        int dst;
        glGetProgramiv(*id, GL_ACTIVE_ATTRIBUTES, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}

GL::Int Program::getActiveAttributeMaxNameLength(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        int dst;
        glGetProgramiv(*id, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}

GL::Int Program::getActiveUniformsCount(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        int dst;
        glGetProgramiv(*id, GL_ACTIVE_UNIFORMS, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}

GL::Int Program::getActiveUniformMaxNameLength(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        int dst;
        glGetProgramiv(*id, GL_ACTIVE_UNIFORM_MAX_LENGTH, &dst);
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}

GL::String Program::getInfoLog(const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
        int len;
        glGetProgramiv(*id, GL_INFO_LOG_LENGTH, &len);
        gl.debug(src_loc);
        
        std::string dst;
        dst.resize(len);
        glGetProgramInfoLog(*id, len, &len, dst.data());
        gl.debug(src_loc);
        return dst;
    }, id(), src_loc);
}



GL::Int Program::getAttribLocation(const String& name, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const String& name, const SrcLoc& src_loc){
        int loc = glGetAttribLocation(*id, name->c_str());
        gl.debug(src_loc);
        return loc;
    }, id(), name, src_loc);
}

void Program::bindAttribLocation(const Uint& attr_index, const String& name, const SrcLoc& src_loc){
    _callGL<&Gl::BindAttribLocation>(id(), attr_index, name, src_loc);
}

GL::Int Program::getUniformLocation(const String& name, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const String& name, const SrcLoc& src_loc){
        int loc = glGetUniformLocation(*id, name->c_str());
        gl.debug(src_loc);
        return loc;
    }, id(), name, src_loc);
}

GL::Uint Program::getUniformBlockIndex(const String& name, const SrcLoc& src_loc){
    return _callGLCustom([](Gl& gl, const Uint& id, const String& name, const SrcLoc& src_loc){
        unsigned int loc = glGetUniformBlockIndex(*id, name->c_str());
        gl.debug(src_loc);
        return loc;
    }, id(), name, src_loc);
}