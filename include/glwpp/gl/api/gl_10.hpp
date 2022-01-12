#pragma once

#include "glwpp/gl/api/types.hpp"

namespace glwpp::gl {

bool LoadGl_10(LoadFunc func);
    
extern void (*BlendFunc)(Enum sfactor, Enum dfactor);
extern void (*Clear)(BitField mask);
extern void (*ClearColor)(Float red, Float green, Float blue, Float alpha);
extern void (*ClearDepth)(Double depth);
extern void (*ClearStencil)(Int s);
extern void (*ColorMask)(Bool red, Bool green, Bool blue, Bool alpha);
extern void (*CullFace)(Enum mode);
extern void (*DepthFunc)(Enum func);
extern void (*DepthMask)(Bool flag);
extern void (*DepthRange)(Double n, Double f);
extern void (*Disable)(Enum cap);
extern void (*DrawBuffer)(Enum buf);
extern void (*Enable)(Enum cap);
extern void (*Finish)();
extern void (*Flush)();
extern void (*FrontFace)(Enum mode);
extern void (*GetBooleanv)(Enum pname, Bool *data);
extern void (*GetDoublev)(Enum pname, Double *data);
extern Enum (*GetError)();
extern void (*GetFloatv)(Enum pname, Float *data);
extern void (*GetIntegerv)(Enum pname, Int *data);
extern const UByte* (*GetString)(Enum name);
extern void (*GetTexImage)(Enum target, Int level, Enum format, Enum type, void *pixels);
extern void (*GetTexLevelParameterfv)(Enum target, Int level, Enum pname, Float *params);
extern void (*GetTexLevelParameteriv)(Enum target, Int level, Enum pname, Int *params);
extern void (*GetTexParameterfv)(Enum target, Enum pname, Float *params);
extern void (*GetTexParameteriv)(Enum target, Enum pname, Int *params);
extern void (*Hint)(Enum target, Enum mode);
extern Bool (*IsEnabled)(Enum cap);
extern void (*LineWidth)(Float width);
extern void (*LogicOp)(Enum opcode);
extern void (*PixelStoref)(Enum pname, Float param);
extern void (*PixelStorei)(Enum pname, Int param);
extern void (*PointSize)(Float size);
extern void (*PolygonMode)(Enum face, Enum mode);
extern void (*ReadBuffer)(Enum src);
extern void (*ReadPixels)(Int x, Int y, Sizei width, Sizei height, Enum format, Enum type, void *pixels);
extern void (*Scissor)(Int x, Int y, Sizei width, Sizei height);
extern void (*StencilFunc)(Enum func, Int ref, UInt mask);
extern void (*StencilMask)(UInt mask);
extern void (*StencilOp)(Enum fail, Enum zfail, Enum zpass);
extern void (*TexImage1D)(Enum target, Int level, Int internalformat, Sizei width, Int border, Enum format, Enum type, const void *pixels);
extern void (*TexImage2D)(Enum target, Int level, Int internalformat, Sizei width, Sizei height, Int border, Enum format, Enum type, const void *pixels);
extern void (*TexParameterf)(Enum target, Enum pname, Float param);
extern void (*TexParameterfv)(Enum target, Enum pname, const Float *params);
extern void (*TexParameteri)(Enum target, Enum pname, Int param);
extern void (*TexParameteriv)(Enum target, Enum pname, const Int *params);
extern void (*Viewport)(Int x, Int y, Sizei width, Sizei height);

}