#pragma once
#include "glwpp/gl/api/gl_31.hpp"

namespace glwpp::gl {

bool LoadGl_32(LoadFunc func);

extern Enum (*ClientWaitSync)(gl::GLsync sync, BitField flags, GLuint64 timeout);
extern void (*DeleteSync)(GLsync sync);
extern void (*DrawElementsBaseVertex)(Enum mode, Sizei count, Enum type, const void * indices, Int basevertex);
extern void (*DrawElementsInstancedBaseVertex)(Enum mode, Sizei count, Enum type, const void * indices, Sizei instancecount, Int basevertex);
extern void (*DrawRangeElementsBaseVertex)(Enum mode, UInt start, UInt end, Sizei count, Enum type, const void * indices, Int basevertex);
extern GLsync (*FenceSync)(Enum condition, BitField flags);
extern void (*FramebufferTexture)(Enum target, Enum attachment, UInt texture, Int level);
extern void (*GetBufferParameteri64v)(Enum target, Enum pname, GLint64 * params);
extern void (*GetInteger64i_v)(Enum target, UInt index, GLint64 * data);
extern void (*GetInteger64v)(Enum pname, GLint64 * data);
extern void (*GetMultisamplefv)(Enum pname, UInt index, Float * val);
extern void (*GetSynciv)(GLsync sync, Enum pname, Sizei count, Sizei * length, Int * values);
extern Bool (*IsSync)(GLsync sync);
extern void (*MultiDrawElementsBaseVertex)(Enum mode, const Sizei * count, Enum type, const void *const* indices, Sizei drawcount, const Int * basevertex);
extern void (*ProvokingVertex)(Enum mode);
extern void (*SampleMaski)(UInt maskNumber, BitField mask);
extern void (*TexImage2DMultisample)(Enum target, Sizei samples, Enum internalformat, Sizei width, Sizei height, Bool fixedsamplelocations);
extern void (*TexImage3DMultisample)(Enum target, Sizei samples, Enum internalformat, Sizei width, Sizei height, Sizei depth, Bool fixedsamplelocations);
extern void (*WaitSync)(GLsync sync, BitField flags, GLuint64 timeout);

}