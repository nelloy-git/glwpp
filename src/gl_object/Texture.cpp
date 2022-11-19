#include "gl_object/Texture.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace GL;

Texture::Texture(const std::shared_ptr<Context>& ctx, const Enum& type, const SrcLoc& src_loc) :
    Object(ctx, ctx->gl().call([](Gl& gl, const Enum& type, const SrcLoc& src_loc){
    }, type, src_loc)){
}

Texture::~Texture(){
    _callGLCustom([](Gl& gl, const Uint& id){
        glDeleteTexture(*id);
    }, id());
}