// #include "gl_object/Texture.hpp"

// #include "glad/gl.h"

// using namespace glwpp;
// using namespace GL;

// TextureBase::TextureBase(const std::shared_ptr<Context>& ctx, const Enum& type, const SrcLoc& src_loc) :
//     Object(ctx, ctx->gl().call([](Gl& gl, const Enum& type, const SrcLoc& src_loc){
//         unsigned int id;
//         glCreateTextures(*type, 1, &id);
//         gl.debug(src_loc);
//         return id;
//     }, type, src_loc)){
// }

// TextureBase::~TextureBase(){
//     _callGLCustom([](Gl& gl, const Uint& id){
//         glDeleteTextures(1, id.get());
//     }, id());
// }



// void TextureBase::setBuffer(const Enum& internalformat, const BufferBase& buffer, const SrcLoc& src_loc){
//     _callGL<&Gl::TextureBuffer>(id(), internalformat, buffer.id(), src_loc);
// }

// void TextureBase::setBufferRange(const Enum& internalformat, const BufferBase& buffer, const Intptr& offset, const Sizeiptr& size, const SrcLoc& src_loc){
//     _callGL<&Gl::TextureBufferRange>(id(), internalformat, buffer.id(), offset, size, src_loc);
// }

// void TextureBase::setStorage1D(const Sizei& levels, const Enum& internalformat, const Sizei& width, const SrcLoc& src_loc){
//     _callGL<&Gl::TextureStorage1D>(id(), levels, internalformat, width, src_loc);
// }

// void TextureBase::setStorage2D(const Sizei& levels, const Enum& internalformat, const Sizei& width, const Sizei& height, const SrcLoc& src_loc){
//     _callGL<&Gl::TextureStorage2D>(id(), levels, internalformat, width, height, src_loc);
// }

// void TextureBase::setStorage3D(const Sizei& levels, const Enum& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const SrcLoc& src_loc){
//     _callGL<&Gl::TextureStorage3D>(id(), levels, internalformat, width, height, depth, src_loc);
// }

// void TextureBase::setStorageMultisample2D(const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const Boolean& fixed_locations, const SrcLoc& src_loc){
//     _callGL<&Gl::TextureStorage2DMultisample>(id(), samples, internalformat, width, height, fixed_locations, src_loc);
// }

// void TextureBase::setStorageMultisample3D(const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const Boolean& fixed_locations, const SrcLoc& src_loc){
//     _callGL<&Gl::TextureStorage3DMultisample>(id(), samples, internalformat, width, height, depth, fixed_locations, src_loc);
// }



// void TextureBase::bindUnit(const Uint& unit, const SrcLoc& src_loc){
//     _callGL<&Gl::BindTextureUnit>(unit, id(), src_loc);
// }

// void TextureBase::generateMipMap(const SrcLoc& src_loc){
//     _callGL<&Gl::GenerateTextureMipmap>(id(), src_loc);
// }

// void TextureBase::getImage(const Int& level, const Enum& format, const Enum& type, const Sizei& buf_size, const Data& dst, const SrcLoc& src_loc){
//     _callGL<&Gl::GetTextureImage>(id(), level, format, type, buf_size, dst, src_loc);
// }

// void TextureBase::getSubImage(const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& w, const Sizei& h, const Sizei& d, const Enum& format, const Enum& type, const Sizei& buf_size, const Data& dst, const SrcLoc& src_loc){
//     _callGL<&Gl::GetTextureSubImage>(id(), level,  xoffset, yoffset, zoffset, w, h, d, format, type, buf_size, dst, src_loc);
// }

// void TextureBase::setSubImage1D(const Int& level, const Int& x, const Sizei& w, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
//     _callGL<&Gl::TextureSubImage1D>(id(), level, x, w, format, type, pixels, src_loc);
// }

// void TextureBase::setSubImage2D(const Int& level, const Int& x, const Int& y, const Sizei& w, const Sizei& h, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
//     _callGL<&Gl::TextureSubImage2D>(id(), level, x, y, w, h, format, type, pixels, src_loc);
// }

// void TextureBase::setSubImage3D(const Int& level, const Int& x, const Int& y, const Int& z, const Sizei& w, const Sizei& h, const Sizei& d, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc){
//     _callGL<&Gl::TextureSubImage3D>(id(), level, x, y, z, w, h, d, format, type, pixels, src_loc);
// }



// Enum TextureBase::getWrapS(const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
//         unsigned int dst;
//         glGetTextureParameteriv(*id, GL_TEXTURE_WRAP_S, reinterpret_cast<int*>(&dst));
//         gl.debug(src_loc);
//         return dst;
//     }, id(), src_loc);
// }

// void TextureBase::setWrapS(const Enum& value, const SrcLoc& src_loc){
//     _callGLCustom([](Gl& gl, const Uint& id, const Enum& value, const SrcLoc& src_loc){
//         glTextureParameteri(*id, GL_TEXTURE_WRAP_S, *value);
//     }, id(), value, src_loc);
// }

// Enum TextureBase::getWrapT(const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
//         unsigned int dst;
//         glGetTextureParameteriv(*id, GL_TEXTURE_WRAP_T, reinterpret_cast<int*>(&dst));
//         gl.debug(src_loc);
//         return dst;
//     }, id(), src_loc);
// }

// void TextureBase::setWrapT(const Enum& value, const SrcLoc& src_loc){
//     _callGLCustom([](Gl& gl, const Uint& id, const Enum& value, const SrcLoc& src_loc){
//         glTextureParameteri(*id, GL_TEXTURE_WRAP_T, *value);
//     }, id(), value, src_loc);
// }

// Enum TextureBase::getMinFilter(const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
//         unsigned int dst;
//         glGetTextureParameteriv(*id, GL_TEXTURE_MIN_FILTER, reinterpret_cast<int*>(&dst));
//         gl.debug(src_loc);
//         return dst;
//     }, id(), src_loc);
// }

// void TextureBase::setMinFilter(const Enum& value, const SrcLoc& src_loc){
//     _callGLCustom([](Gl& gl, const Uint& id, const Enum& value, const SrcLoc& src_loc){
//         glTextureParameteri(*id, GL_TEXTURE_MIN_FILTER, *value);
//     }, id(), value, src_loc);
// }

// Enum TextureBase::getMagFilter(const SrcLoc& src_loc){
//     return _callGLCustom([](Gl& gl, const Uint& id, const SrcLoc& src_loc){
//         unsigned int dst;
//         glGetTextureParameteriv(*id, GL_TEXTURE_MAG_FILTER, reinterpret_cast<int*>(&dst));
//         gl.debug(src_loc);
//         return dst;
//     }, id(), src_loc);
// }

// void TextureBase::setMagFilter(const Enum& value, const SrcLoc& src_loc){
//     _callGLCustom([](Gl& gl, const Uint& id, const Enum& value, const SrcLoc& src_loc){
//         glTextureParameteri(*id, GL_TEXTURE_MAG_FILTER, *value);
//     }, id(), value, src_loc);
// }
