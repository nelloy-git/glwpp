#include "glwpp/gl/obj/Texture.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;

Texture::Texture(const wptr<Context>& wctx, const Val<const TextureType>& type,
                 const Val<const SrcLoc>& src_loc, bool check_ctx) :
    Object(wctx, src_loc, &Texture::_initer, &Texture::_deleter, type){
}

bool Texture::buffer(const Buffer& buffer, const Val<const TextureFormat>& fmt,
                     const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, src_loc, glTextureBuffer, id(), fmt.cast_reinterpret<const Enum>(), buffer.id());
}

bool Texture::bufferRange(const Buffer& buffer, const Val<const TextureFormat>& fmt,
                          const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                          const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, src_loc, glTextureBufferRange, id(), fmt.cast_reinterpret<const Enum>(), buffer.id(), offset, size);
}

bool Texture::storage1D(const Val<const Sizei>& levels, const Val<const TextureFormat>& fmt,
                        const Val<const Sizei>& width,
                        const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, src_loc, glTextureStorage1D, id(), levels, fmt.cast_reinterpret<const Enum>(), width);
}

bool Texture::storage2D(const Val<const Sizei>& levels, const Val<const TextureFormat>& fmt,
                const Val<const Sizei>& width, const Val<const Sizei>& height,
                const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, src_loc, glTextureStorage2D, id(), levels, fmt.cast_reinterpret<const Enum>(), width, height);
}

bool Texture::storage3D(const Val<const Sizei>& levels, const Val<const TextureFormat>& fmt,
                const Val<const Sizei>& width, const Val<const Sizei>& height, const Val<const Sizei>& depth,
                const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, src_loc, glTextureStorage3D, id(), levels, fmt.cast_reinterpret<const Enum>(), width, height, depth);
}

bool Texture::storageMultisample2D(const Val<const Sizei>& samples, const Val<const TextureFormat>& fmt,
                                   const Val<const Sizei>& width, const Val<const Sizei>& height,
                                   const Val<const Bool>& fixed_locations,
                                   const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, src_loc, glTextureStorage2DMultisample, id(), samples, fmt.cast_reinterpret<const Enum>(), width, height, fixed_locations);
}

bool Texture::storageMultisample3D(const Val<const Sizei>& samples, const Val<const TextureFormat>& fmt,
                                   const Val<const Sizei>& width, const Val<const Sizei>& height, const Val<const Sizei>& depth,
                                   const Val<const Bool>& fixed_locations,
                                   const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, src_loc, glTextureStorage3DMultisample, id(), samples, fmt.cast_reinterpret<const Enum>(), width, height, depth, fixed_locations);
}

bool Texture::setUnit(const Val<const UInt>& index,
                      const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, src_loc, glBindTextureUnit, index, id());
}

bool Texture::generateMipMap(const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, src_loc, glGenerateTextureMipmap, id());
}

bool Texture::getImage(const Val<void>& dst, const Val<const Int>& level, const Val<const TexturePixelFormat>& fmt,
                       const Val<const TexturePixelData>& type, const Val<const Sizei>& size,
                       const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, src_loc, glGetTextureImage, id(), level, 
                            fmt.cast_reinterpret<const Enum>(), type.cast_reinterpret<const Enum>(),
                            size, dst);
}

bool Texture::getSubImage(const Val<void>& dst, 
                          const Val<const Int>& level, const Val<const TexturePixelFormat>& fmt,
                          const Val<const Int>& x, const Val<const Int>& y, const Val<const Int>& z,
                          const Val<const Sizei>& w, const Val<const Sizei>& h, const Val<const Sizei>& d,
                          const Val<const TexturePixelData>& type, const Val<const Sizei>& size,
                          const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, src_loc, glGetTextureSubImage, id(), level, x, y, z, w, h, d,
                            fmt.cast_reinterpret<const Enum>(), type.cast_reinterpret<const Enum>(),
                            size, dst);
}

bool Texture::setSubImage1D(const Val<const void>& data,
                            const Val<const Int>& level,
                            const Val<const Int>& x, const Val<const Sizei>& w,
                            const Val<const TexturePixelFormat>& fmt, const Val<const TexturePixelData>& type,
                            const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, src_loc, glTextureSubImage1D, id(), level, x, w,
                            fmt.cast_reinterpret<const Enum>(), type.cast_reinterpret<const Enum>(),
                            data);
}

bool Texture::setSubImage2D(const Val<const void>& data,
                            const Val<const Int>& level,
                            const Val<const Int>& x, const Val<const Int>& y,
                            const Val<const Sizei>& w, const Val<const Sizei>& h,
                            const Val<const TexturePixelFormat>& fmt, const Val<const TexturePixelData>& type,
                            const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, src_loc, glTextureSubImage2D, id(), level, x, y, w, h,
                            fmt.cast_reinterpret<const Enum>(), type.cast_reinterpret<const Enum>(),
                            data);
}

bool Texture::setSubImage3D(const Val<const void>& data,
                            const Val<const Int>& level,
                            const Val<const Int>& x, const Val<const Int>& y, const Val<const Int>& z,
                            const Val<const Sizei>& w, const Val<const Sizei>& h, const Val<const Sizei>& d,
                            const Val<const TexturePixelFormat>& fmt, const Val<const TexturePixelData>& type,
                            const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, src_loc, glTextureSubImage3D, id(), level, x, y, z, w, h, d,
                            fmt.cast_reinterpret<const Enum>(), type.cast_reinterpret<const Enum>(),
                            data);
}

bool Texture::getParamInt(const Val<Int>& dst, const Val<const Enum>& param,
                          const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return executeInContext(check_ctx, src_loc, glGetTextureParameteriv, id(), param, dst);
}

bool Texture::setParamInt(const Val<const Int>& value, const Val<const Enum>& param,
                          const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, src_loc, glTextureParameteri, id(), param, value);
}

bool Texture::getWrapS(const Val<Wrap> dst,
                       const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_TEXTURE_WRAP_S, src_loc, check_ctx);
}
bool Texture::setWrapS(const Val<const Wrap> value,
                       const Val<const SrcLoc>& src_loc, bool check_ctx){
    return setParamInt(value.cast_reinterpret<const Int>(), GL_TEXTURE_WRAP_S, src_loc, check_ctx);
}

bool Texture::getWrapT(const Val<Wrap> dst,
                       const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_TEXTURE_WRAP_T, src_loc, check_ctx);
}
bool Texture::setWrapT(const Val<const Wrap> value,
                       const Val<const SrcLoc>& src_loc, bool check_ctx){
    return setParamInt(value.cast_reinterpret<const Int>(), GL_TEXTURE_WRAP_T, src_loc, check_ctx);
}

bool Texture::getMinFilter(const Val<MinFilter> dst,
                           const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_TEXTURE_MIN_FILTER, src_loc, check_ctx);
}

bool Texture::setMinFilter(const Val<const MinFilter> value,
                           const Val<const SrcLoc>& src_loc, bool check_ctx){
    return setParamInt(value.cast_reinterpret<const Int>(), GL_TEXTURE_MIN_FILTER, src_loc, check_ctx);
}

bool Texture::getMagFilter(const Val<MagFilter> dst,
                           const Val<const SrcLoc>& src_loc, bool check_ctx) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_TEXTURE_MAG_FILTER, src_loc, check_ctx);
}

bool Texture::setMagFilter(const Val<const MagFilter> value,
                           const Val<const SrcLoc>& src_loc, bool check_ctx){
    return setParamInt(value.cast_reinterpret<const Int>(), GL_TEXTURE_MAG_FILTER, src_loc, check_ctx);
}

void Texture::_initer(UInt& dst, const TextureType& type){
    glCreateTextures(static_cast<Enum>(type), 1, &dst);
}

void Texture::_deleter(const UInt& id){
    glDeleteTextures(1, &id);
}