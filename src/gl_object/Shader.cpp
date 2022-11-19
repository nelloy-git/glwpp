// #include "gl_object/Shader.hpp"

// #include "glad/gl.h"

// using namespace glwpp;
// using namespace GL;


// Shader::Shader(const std::shared_ptr<Context>& ctx, const GLenum& type, const SrcLoc& src_loc) :
//     Object(ctx, ctx->gl().call(&Shader::_initId, type, src_loc)){
// }

// Shader::~Shader(){
//     _callGLCustom(&Shader::_freeId, id(), SrcLoc{});
// }



// void Shader::source(const String& code, const SrcLoc& src_loc){
//     _callGLCustom([](Gl& gl, const GLuint& id, const String& code, const SrcLoc& src_loc){
//         auto c_str = code->c_str();
//         int len = static_cast<int>(code->size());
//         glShaderSource(*id, 1, &c_str, &len);
//         gl.debug(src_loc);
//     }, id(), code, src_loc);
// }

// void Shader::compile(const SrcLoc& src_loc){
//     _callGL<&Gl::CompileShader>(id(), src_loc);
// }



// GL::GLenum Shader::getType(const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
//         GLint dst;
//         glGetShaderiv(*id, GL_SHADER_TYPE, dst.get());
//         gl.debug(src_loc);
//         return GLenum(*reinterpret_cast<unsigned int*>(dst.get()));
//     }, id(), src_loc);
// }

// GL::GLboolean Shader::isCompiled(const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
//         GLint dst;
//         glGetShaderiv(*id, GL_COMPILE_STATUS, dst.get());
//         gl.debug(src_loc);
//         return GLboolean(*reinterpret_cast<unsigned int*>(dst.get()) == GL_TRUE);
//     }, id(), src_loc);
// }

// GL::GLint Shader::getSourceLength(const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
//         GLint dst;
//         glGetShaderiv(*id, GL_SHADER_SOURCE_LENGTH, dst.get());
//         gl.debug(src_loc);
//         return dst;
//     }, id(), src_loc);
// }

// GL::String Shader::getInfoLog(const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const GLuint& id, const SrcLoc& src_loc){
//         GLint len;
//         glGetShaderiv(*id, GL_INFO_LOG_LENGTH, len.get());
//         gl.debug(src_loc);
        
//         String dst;
//         dst->reserve(*len);
//         glGetShaderInfoLog(*id, *len, len.get(), dst->data());
//         gl.debug(src_loc);
//         return dst;
//     }, id(), src_loc);
// }




// GL::GLuint Shader::_initId(Gl& gl, const GLenum& type, const SrcLoc& src_loc){
//     return gl.CreateShader(type, src_loc);
// }

// void Shader::_freeId(Gl& gl, const GLuint& id, const SrcLoc& src_loc){
//     gl.DeleteShader(id, src_loc);
// }