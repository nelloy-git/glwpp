#pragma once
#include "glwpp/gl/api/gl_13.hpp"

namespace glwpp::gl {

bool LoadGl_14(LoadFunc func);
 
extern void (*BlendColor)(Float red, Float green, Float blue, Float alpha);
extern void (*BlendEquation)(Enum mode);
extern void (*BlendFuncSeparate)(Enum sfactorRGB, Enum dfactorRGB, Enum sfactorAlpha, Enum dfactorAlpha);
extern void (*MultiDrawArrays)(Enum mode, const Int * first, const Sizei * count, Sizei drawcount);
extern void (*MultiDrawElements)(Enum mode, const Sizei * count, Enum type, const void *const* indices, Sizei drawcount);
extern void (*PointParameterf)(Enum pname, Float param);
extern void (*PointParameterfv)(Enum pname, const Float * params);
extern void (*PointParameteri)(Enum pname, Int param);
extern void (*PointParameteriv)(Enum pname, const Int * params);

}