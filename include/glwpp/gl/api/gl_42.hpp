#pragma once
#include "glwpp/gl/api/gl_41.hpp"

namespace glwpp::gl {

bool LoadGl_42(LoadFunc func);

extern void (*BindImageTexture)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
extern void (*DrawArraysInstancedBaseInstance)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
extern void (*DrawElementsInstancedBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance);
extern void (*DrawElementsInstancedBaseVertexBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
extern void (*DrawTransformFeedbackInstanced)(GLenum mode, GLuint id, GLsizei instancecount);
extern void (*DrawTransformFeedbackStreamInstanced)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
extern void (*GetActiveAtomicCounterBufferiv)(GLuint program, GLuint bufferIndex, GLenum pname, GLint * params);
extern void (*GetInternalformativ)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint * params);
extern void (*MemoryBarrier)(GLbitfield barriers);
extern void (*TexStorage1D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
extern void (*TexStorage2D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
extern void (*TexStorage3D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);

}