// #include "gl_object/VertexArray.hpp"

// #include "glad/gl.h"

// using namespace glwpp;
// using namespace GL;


// VertexArray::VertexArray(const std::shared_ptr<Context>& ctx, const SrcLoc& src_loc) :
//     Object(ctx, ctx->gl().call(&VertexArray::_initId, src_loc)){
// }

// VertexArray::~VertexArray(){
//     _callGLCustom(&VertexArray::_freeId, id(), SrcLoc{});
// }




// void VertexArray::enableAttrib(const GLuint& index, const SrcLoc& src_loc){
//     _callGL<&Gl::EnableVertexArrayAttrib>(id(), index, src_loc);
// }

// void VertexArray::disableAttrib(const GLuint& index, const SrcLoc& src_loc){
//     _callGL<&Gl::DisableVertexArrayAttrib>(id(), index, src_loc);
// }

// void VertexArray::setAttribBinding(const GLuint& index, const GLuint& binding, const SrcLoc& src_loc){
//     _callGL<&Gl::VertexArrayAttribBinding>(id(), index, binding, src_loc);
// }

// void VertexArray::setAttribFormat(const GLuint& index, const GLint& size, const GLenum& type, const GLboolean& normalized, const GLuint& relative_offset, const SrcLoc& src_loc){
//     _callGL<&Gl::VertexArrayAttribFormat>(id(), index, size, type, normalized, relative_offset, src_loc);
// }

// void VertexArray::setBindingDivisor(const GLuint& binding, const GLuint& divisor, const SrcLoc& src_loc){
//     _callGL<&Gl::VertexArrayBindingDivisor>(id(), binding, divisor, src_loc);
// }

// void VertexArray::setElementBuffer(const Buffer& buffer, const SrcLoc& src_loc){
//     _callGL<&Gl::VertexArrayElementBuffer>(id(), buffer.id(), src_loc);
// }

// void VertexArray::setVertexBuffer(const GLuint& binding, const Buffer& buffer, const GLintptr& offset, const GLsizei& stride, const SrcLoc& src_loc){
//     _callGL<&Gl::VertexArrayVertexBuffer>(id(), binding, buffer.id(), offset, stride, src_loc);
// }



// GL::GLboolean VertexArray::isAttribEnabled(const GLuint& index, const SrcLoc& src_loc){
//     _callGLCustom([](Gl& gl, const GLuint& id, const GLuint& index, const SrcLoc& src_loc){
//         int dst;
//         glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &dst);
//         gl.debug(src_loc);
//         return dst == GL_TRUE;
//     }, id(), index, src_loc);
// }

// GL::GLint VertexArray::getAttribSize(const GLuint& index, const SrcLoc& src_loc){
//     _callGLCustom([](Gl& gl, const GLuint& id, const GLuint& index, const SrcLoc& src_loc){
//         unsigned int dst;
//         glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_SIZE, &dst);
//         gl.debug(src_loc);
//         return dst;
//     }, id(), index, src_loc);
// }

// GL::GLint VertexArray::getAttribStride(const GLuint& index, const SrcLoc& src_loc){
//     _callGLCustom([](Gl& gl, const GLuint& id, const GLuint& index, const SrcLoc& src_loc){
//         int dst;
//         glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_STRIDE, &dst);
//         gl.debug(src_loc);
//         return dst;
//     }, id(), index, src_loc);
// }

// GL::GLenum VertexArray::getAttribType(const GLuint& index, const SrcLoc& src_loc){
//     _callGLCustom([](Gl& gl, const GLuint& id, const GLuint& index, const SrcLoc& src_loc){
//         unsigned int dst;
//         glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_TYPE, reinterpret_cast<int*>(&dst));
//         gl.debug(src_loc);
//         return GLenum(dst);
//     }, id(), index, src_loc);
// }

// GL::GLboolean VertexArray::isAttribNormalized(const GLuint& index, const SrcLoc& src_loc){
//     _callGLCustom([](Gl& gl, const GLuint& id, const GLuint& index, const SrcLoc& src_loc){
//         int dst;
//         glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_NORMALIZED, &dst);
//         gl.debug(src_loc);
//         return GLboolean(dst == GL_TRUE);
//     }, id(), index, src_loc);
// }

// GL::GLboolean VertexArray::isAttribInteger(const GLuint& index, const SrcLoc& src_loc){
//     _callGLCustom([](Gl& gl, const GLuint& id, const GLuint& index, const SrcLoc& src_loc){
//         int dst;
//         glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_INTEGER, &dst);
//         gl.debug(src_loc);
//         return GLboolean(dst == GL_TRUE);
//     }, id(), index, src_loc);
// }

// GL::GLboolean VertexArray::isAttribLong(const GLuint& index, const SrcLoc& src_loc){
//     _callGLCustom([](Gl& gl, const GLuint& id, const GLuint& index, const SrcLoc& src_loc){
//         int dst;
//         glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_LONG, &dst);
//         gl.debug(src_loc);
//         return GLboolean(dst == GL_TRUE);
//     }, id(), index, src_loc);
// }

// GL::GLint VertexArray::getAttribDivisor(const GLuint& index, const SrcLoc& src_loc){
//     _callGLCustom([](Gl& gl, const GLuint& id, const GLuint& index, const SrcLoc& src_loc){
//         int dst;
//         glGetVertexArrayIndexediv(*id, *index, GL_VERTEX_ATTRIB_ARRAY_DIVISOR, &dst);
//         gl.debug(src_loc);
//         return dst;
//     }, id(), index, src_loc);
// }

// GL::GLint64 VertexArray::getAttribBindingOffset(const GLuint& index, const SrcLoc& src_loc){

// }



// GL::GLuint VertexArray::_initId(Gl& gl, const SrcLoc& src_loc){
//     GLuint id;
//     glCreateVertexArrays(1, id.get());
//     gl.debug(src_loc);
//     return id;
// }

// void VertexArray::_freeId(Gl& gl, const GLuint& id, const SrcLoc& src_loc){
//     glDeleteVertexArrays(1, id.get());
//     gl.debug(src_loc);
// }