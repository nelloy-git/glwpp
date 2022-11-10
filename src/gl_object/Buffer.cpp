#include "gl_object/Buffer.hpp"

using namespace glwpp;
using namespace GL;

Buffer::Buffer(Context& ctx) :
    _id(ctx.GL().CreateBuffers(GLsizei){

}