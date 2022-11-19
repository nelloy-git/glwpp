// #include "gl_object/Program.hpp"

// #include "glad/gl.h"

// using namespace glwpp;
// using namespace GL;


// Program::Program(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc) :
//     Object(ctx, ctx->gl().call(&Program::_initId, src_loc)){
// }

// Program::~Program(){
//     _callGLCustom(&Program::_freeId, id(), SrcLoc{});
// }



// void Program::attach(const Shader& shader, const SrcLoc& src_loc){
//     _callGL<&Gl::AttachShader>(id(), shader.id(), src_loc);
// }

// void Program::link(const SrcLoc& src_loc){
//     _callGL<&Gl::LinkProgram>(id(), src_loc);
// }

// void Program::validate(const SrcLoc& src_loc){
//     _callGL<&Gl::ValidateProgram>(id(), src_loc);
// }

// void Program::use(const SrcLoc& src_loc){
//     _callGL<&Gl::UseProgram>(id(), src_loc);
// }




// GL::GLboolean Program::isLinked(const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
//         GLint dst;
//         glGetProgramiv(*id, GL_LINK_STATUS, dst.get());
//         gl.debug(src_loc);
//         return GLboolean(*reinterpret_cast<unsigned int*>(dst.get()) == GL_TRUE);
//     }, id(), src_loc);
// }

// GL::GLboolean Program::isValidated(const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
//         GLint dst;
//         glGetProgramiv(*id, GL_VALIDATE_STATUS, dst.get());
//         gl.debug(src_loc);
//         return GLboolean(*reinterpret_cast<unsigned int*>(dst.get()) == GL_TRUE);
//     }, id(), src_loc);
// }

// GL::GLint Program::getAttachedShadersCount(const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
//         GLint dst;
//         glGetProgramiv(*id, GL_ATTACHED_SHADERS, dst.get());
//         gl.debug(src_loc);
//         return dst;
//     }, id(), src_loc);
// }

// GL::GLint Program::getActiveAttributesCount(const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
//         GLint dst;
//         glGetProgramiv(*id, GL_ACTIVE_ATTRIBUTES, dst.get());
//         gl.debug(src_loc);
//         return dst;
//     }, id(), src_loc);
// }

// GL::GLint Program::getActiveAttributeMaxNameLength(const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
//         GLint dst;
//         glGetProgramiv(*id, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, dst.get());
//         gl.debug(src_loc);
//         return dst;
//     }, id(), src_loc);
// }

// GL::GLint Program::getActiveUniformsCount(const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
//         GLint dst;
//         glGetProgramiv(*id, GL_ACTIVE_UNIFORMS, dst.get());
//         gl.debug(src_loc);
//         return dst;
//     }, id(), src_loc);
// }

// GL::GLint Program::getActiveUniformMaxNameLength(const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
//         GLint dst;
//         glGetProgramiv(*id, GL_ACTIVE_UNIFORM_MAX_LENGTH, dst.get());
//         gl.debug(src_loc);
//         return dst;
//     }, id(), src_loc);
// }

// GL::String Program::getInfoLog(const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
//         GLint len;
//         glGetProgramiv(*id, GL_INFO_LOG_LENGTH, len.get());
//         gl.debug(src_loc);
        
//         String dst;
//         dst->reserve(*len);
//         glGetProgramInfoLog(*id, *len, len.get(), dst->data());
//         gl.debug(src_loc);
//         return dst;
//     }, id(), src_loc);
// }



// GL::GLint Program::getAttribLocation(const String& name, const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const GLuint& id, const String& name, const SrcLoc& src_loc){
//         GLint loc;
//         *loc = glGetAttribLocation(*id, name->c_str());
//         gl.debug(src_loc);
//         return loc;
//     }, id(), name, src_loc);
// }

// void Program::bindAttribLocation(const GLuint& attr_index, const String& name, const SrcLoc& src_loc){
//     _callGL<&Gl::BindAttribLocation>(id(), attr_index, name, src_loc);
// }

// GL::GLint Program::getUniformLocation(const String& name, const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const GLuint& id, const String& name, const SrcLoc& src_loc){
//         GLint loc;
//         *loc = glGetUniformLocation(*id, name->c_str());
//         gl.debug(src_loc);
//         return loc;
//     }, id(), name, src_loc);
// }

// GL::GLuint Program::getUniformBlockIndex(const String& name, const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const GLuint& id, const String& name, const SrcLoc& src_loc){
//         GLuint loc;
//         *loc = glGetUniformBlockIndex(*id, name->c_str());
//         gl.debug(src_loc);
//         return loc;
//     }, id(), name, src_loc);
// }




// GL::GLuint Program::_initId(Gl& gl, const SrcLoc& src_loc){
//     return gl.CreateProgram(src_loc);
// }

// void Program::_freeId(Gl& gl, const GLuint& id, const SrcLoc& src_loc){
//     gl.DeleteProgram(id, src_loc);
// }