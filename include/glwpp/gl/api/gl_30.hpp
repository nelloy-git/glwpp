#pragma once
#include "glwpp/gl/api/gl_21.hpp"

namespace glwpp::gl {

bool LoadGl_30(LoadFunc func);
 
extern void (*BeginConditionalRender)(UInt id, Enum mode);
extern void (*BeginTransformFeedback)(Enum primitiveMode);
extern void (*BindBufferBase)(Enum target, UInt index, UInt buffer);
extern void (*BindBufferRange)(Enum target, UInt index, UInt buffer, IntPtr offset, SizeiPtr size);
extern void (*BindFragDataLocation)(UInt program, UInt color, const Char * name);
extern void (*BindFramebuffer)(Enum target, UInt framebuffer);
extern void (*BindRenderbuffer)(Enum target, UInt renderbuffer);
extern void (*BindVertexArray)(UInt array);
extern void (*BlitFramebuffer)(Int srcX0, Int srcY0, Int srcX1, Int srcY1, Int dstX0, Int dstY0, Int dstX1, Int dstY1, BitField mask, Enum filter);
extern Enum (*CheckFramebufferStatus)(Enum target);
extern void (*ClampColor)(Enum target, Enum clamp);
extern void (*ClearBufferfi)(Enum buffer, Int drawbuffer, Float depth, Int stencil);
extern void (*ClearBufferfv)(Enum buffer, Int drawbuffer, const Float * value);
extern void (*ClearBufferiv)(Enum buffer, Int drawbuffer, const Int * value);
extern void (*ClearBufferuiv)(Enum buffer, Int drawbuffer, const UInt * value);
extern void (*ColorMaski)(UInt index, Bool r, Bool g, Bool b, Bool a);
extern void (*DeleteFramebuffers)(Sizei n, const UInt * framebuffers);
extern void (*DeleteRenderbuffers)(Sizei n, const UInt * renderbuffers);
extern void (*DeleteVertexArrays)(Sizei n, const UInt * arrays);
extern void (*Disablei)(Enum target, UInt index);
extern void (*Enablei)(Enum target, UInt index);
extern void (*EndConditionalRender)();
extern void (*EndTransformFeedback)();
extern void (*FlushMappedBufferRange)(Enum target, IntPtr offset, SizeiPtr length);
extern void (*FramebufferRenderbuffer)(Enum target, Enum attachment, Enum renderbuffertarget, UInt renderbuffer);
extern void (*FramebufferTexture1D)(Enum target, Enum attachment, Enum textarget, UInt texture, Int level);
extern void (*FramebufferTexture2D)(Enum target, Enum attachment, Enum textarget, UInt texture, Int level);
extern void (*FramebufferTexture3D)(Enum target, Enum attachment, Enum textarget, UInt texture, Int level, Int zoffset);
extern void (*FramebufferTextureLayer)(Enum target, Enum attachment, UInt texture, Int level, Int layer);
extern void (*GenFramebuffers)(Sizei n, UInt * framebuffers);
extern void (*GenRenderbuffers)(Sizei n, UInt * renderbuffers);
extern void (*GenVertexArrays)(Sizei n, UInt * arrays);
extern void (*GenerateMipmap)(Enum target);
extern void (*GetBooleani_v)(Enum target, UInt index, Bool * data);
extern Int (*GetFragDataLocation)(UInt program, const Char * name);
extern void (*GetFramebufferAttachmentParameteriv)(Enum target, Enum attachment, Enum pname, Int * params);
extern void (*GetIntegeri_v)(Enum target, UInt index, Int * data);
extern void (*GetRenderbufferParameteriv)(Enum target, Enum pname, Int * params);
extern const UByte *(*GetStringi)(Enum name, UInt index);
extern void (*GetTexParameterIiv)(Enum target, Enum pname, Int * params);
extern void (*GetTexParameterIuiv)(Enum target, Enum pname, UInt * params);
extern void (*GetTransformFeedbackVarying)(UInt program, UInt index, Sizei bufSize, Sizei * length, Sizei * size, Enum * type, Char * name);
extern void (*GetUniformuiv)(UInt program, Int location, UInt * params);
extern void (*GetVertexAttribIiv)(UInt index, Enum pname, Int * params);
extern void (*GetVertexAttribIuiv)(UInt index, Enum pname, UInt * params);
extern Bool (*IsEnabledi)(Enum target, UInt index);
extern Bool (*IsFramebuffer)(UInt framebuffer);
extern Bool (*IsRenderbuffer)(UInt renderbuffer);
extern Bool (*IsVertexArray)(UInt array);
extern void *(*MapBufferRange)(Enum target, IntPtr offset, SizeiPtr length, BitField access);
extern void (*RenderbufferStorage)(Enum target, Enum internalformat, Sizei width, Sizei height);
extern void (*RenderbufferStorageMultisample)(Enum target, Sizei samples, Enum internalformat, Sizei width, Sizei height);
extern void (*TexParameterIiv)(Enum target, Enum pname, const Int * params);
extern void (*TexParameterIuiv)(Enum target, Enum pname, const UInt * params);
extern void (*TransformFeedbackVaryings)(UInt program, Sizei count, const Char *const* varyings, Enum bufferMode);
extern void (*Uniform1ui)(Int location, UInt v0);
extern void (*Uniform1uiv)(Int location, Sizei count, const UInt * value);
extern void (*Uniform2ui)(Int location, UInt v0, UInt v1);
extern void (*Uniform2uiv)(Int location, Sizei count, const UInt * value);
extern void (*Uniform3ui)(Int location, UInt v0, UInt v1, UInt v2);
extern void (*Uniform3uiv)(Int location, Sizei count, const UInt * value);
extern void (*Uniform4ui)(Int location, UInt v0, UInt v1, UInt v2, UInt v3);
extern void (*Uniform4uiv)(Int location, Sizei count, const UInt * value);
extern void (*VertexAttribI1i)(UInt index, Int x);
extern void (*VertexAttribI1iv)(UInt index, const Int * v);
extern void (*VertexAttribI1ui)(UInt index, UInt x);
extern void (*VertexAttribI1uiv)(UInt index, const UInt * v);
extern void (*VertexAttribI2i)(UInt index, Int x, Int y);
extern void (*VertexAttribI2iv)(UInt index, const Int * v);
extern void (*VertexAttribI2ui)(UInt index, UInt x, UInt y);
extern void (*VertexAttribI2uiv)(UInt index, const UInt * v);
extern void (*VertexAttribI3i)(UInt index, Int x, Int y, Int z);
extern void (*VertexAttribI3iv)(UInt index, const Int * v);
extern void (*VertexAttribI3ui)(UInt index, UInt x, UInt y, UInt z);
extern void (*VertexAttribI3uiv)(UInt index, const UInt * v);
extern void (*VertexAttribI4bv)(UInt index, const Byte * v);
extern void (*VertexAttribI4i)(UInt index, Int x, Int y, Int z, Int w);
extern void (*VertexAttribI4iv)(UInt index, const Int * v);
extern void (*VertexAttribI4sv)(UInt index, const Short * v);
extern void (*VertexAttribI4ubv)(UInt index, const UByte * v);
extern void (*VertexAttribI4ui)(UInt index, UInt x, UInt y, UInt z, UInt w);
extern void (*VertexAttribI4uiv)(UInt index, const UInt * v);
extern void (*VertexAttribI4usv)(UInt index, const UShort * v);
extern void (*VertexAttribIPointer)(UInt index, Int size, Enum type, Sizei stride, const void * pointer);

}