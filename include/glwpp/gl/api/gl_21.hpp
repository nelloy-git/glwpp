#pragma once
#include "glwpp/gl/api/gl_20.hpp"

namespace glwpp::gl {

bool LoadGl_21(LoadFunc func);
 
extern void (*UniformMatrix2x3fv)(Int location, Sizei count, Bool transpose, const Float * value);
extern void (*UniformMatrix2x4fv)(Int location, Sizei count, Bool transpose, const Float * value);
extern void (*UniformMatrix3x2fv)(Int location, Sizei count, Bool transpose, const Float * value);
extern void (*UniformMatrix3x4fv)(Int location, Sizei count, Bool transpose, const Float * value);
extern void (*UniformMatrix4x2fv)(Int location, Sizei count, Bool transpose, const Float * value);
extern void (*UniformMatrix4x3fv)(Int location, Sizei count, Bool transpose, const Float * value);

}