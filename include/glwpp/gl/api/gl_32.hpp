#pragma once
#include "glwpp/gl/api/gl_31.hpp"

namespace glwpp::gl {

bool LoadGl_32(LoadFunc func);

extern GLenum (*ClientWaitSync)(gl::GLsync sync, GLbitfield flags, GLuint64 timeout);
extern void (*DeleteSync)(GLsync sync);
extern void (*DrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex);
extern void (*DrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex);
extern void (*DrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex);
extern GLsync (*FenceSync)(GLenum condition, GLbitfield flags);
extern void (*FramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level);
extern void (*GetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 * params);
extern void (*GetInteger64i_v)(GLenum target, GLuint index, GLint64 * data);
extern void (*GetInteger64v)(GLenum pname, GLint64 * data);
extern void (*GetMultisamplefv)(GLenum pname, GLuint index, GLfloat * val);
extern void (*GetSynciv)(GLsync sync, GLenum pname, GLsizei count, GLsizei * length, GLint * values);
extern GLboolean (*IsSync)(GLsync sync);
extern void (*MultiDrawElementsBaseVertex)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex);
extern void (*ProvokingVertex)(GLenum mode);
extern void (*SampleMaski)(GLuint maskNumber, GLbitfield mask);
extern void (*TexImage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
extern void (*TexImage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
extern void (*WaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);

}