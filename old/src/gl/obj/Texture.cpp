#include "glwpp/gl/obj/Texture.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;
using namespace glwpp::utils;

sptr<Texture> Texture::make(const sptr<Context>& ctx, const Val<const TextureType>& type,
                            const Val<const utils::SrcLoc>& src_loc){
    return sptr<Texture>(new Texture(ctx, type, src_loc));
}

Texture::Texture(const sptr<Context>& ctx, const Val<const TextureType>& type,
                 const Val<const SrcLoc>& src_loc) :
    Object(ctx, &Texture::_initer, &Texture::_deleter, type, src_loc){
}

bool Texture::buffer(const Val<const Buffer>& buffer, const Val<const TextureFormat>& fmt,
                     const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Texture::buffer, buffer, fmt, src_loc);
    }

    glTextureBuffer(id(), fmt.cast_reinterpret<const Enum>(), buffer->id());
    return true;
}

bool Texture::bufferRange(const Val<const Buffer>& buffer, const Val<const TextureFormat>& fmt,
                          const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                          const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Texture::bufferRange, buffer, fmt, offset, size, src_loc);
    }

    glTextureBufferRange(id(), fmt.cast_reinterpret<const Enum>(), buffer->id(), offset, size);
    return true;
}

bool Texture::storage1D(const Val<const Sizei>& levels, const Val<const TextureFormat>& fmt,
                        const Val<const Sizei>& width, const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Texture::storage1D, levels, fmt, width, src_loc);
    }

    glTextureStorage1D(id(), levels, fmt.cast_reinterpret<const Enum>(), width);
    return true;
}

bool Texture::storage2D(const Val<const Sizei>& levels, const Val<const TextureFormat>& fmt,
                        const Val<const Sizei>& width, const Val<const Sizei>& height,
                        const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Texture::storage2D, levels, fmt, width, height, src_loc);
    }

    glTextureStorage2D(id(), levels, fmt.cast_reinterpret<const Enum>(), width, height);
    return true;
}

bool Texture::storage3D(const Val<const Sizei>& levels, const Val<const TextureFormat>& fmt,
                        const Val<const Sizei>& width, const Val<const Sizei>& height, const Val<const Sizei>& depth,
                        const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Texture::storage3D, levels, fmt, width, height, depth, src_loc);
    }

    glTextureStorage3D(id(), levels, fmt.cast_reinterpret<const Enum>(), width, height, depth);
    return true;
}

bool Texture::storageMultisample2D(const Val<const Sizei>& samples, const Val<const TextureFormat>& fmt,
                                   const Val<const Sizei>& width, const Val<const Sizei>& height,
                                   const Val<const Bool>& fixed_locations,
                                   const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Texture::storageMultisample2D, samples, fmt, width, height, fixed_locations, src_loc);
    }

    glTextureStorage2DMultisample(id(), samples, fmt.cast_reinterpret<const Enum>(), width, height, fixed_locations);
    return true;
}

bool Texture::storageMultisample3D(const Val<const Sizei>& samples, const Val<const TextureFormat>& fmt,
                                   const Val<const Sizei>& width, const Val<const Sizei>& height, const Val<const Sizei>& depth,
                                   const Val<const Bool>& fixed_locations,
                                   const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Texture::storageMultisample3D, samples, fmt, width, height, depth, fixed_locations, src_loc);
    }

    glTextureStorage3DMultisample(id(), samples, fmt.cast_reinterpret<const Enum>(), width, height, depth, fixed_locations);
    return true;
}

bool Texture::setUnit(const Val<const UInt>& index, const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Texture::setUnit, index, src_loc);
    }

    glBindTextureUnit(index, id());
    return true;
}

bool Texture::generateMipMap(const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Texture::generateMipMap, src_loc);
    }

    glGenerateTextureMipmap(id());
    return true;
}

bool Texture::getImage(const Val<void>& dst, const Val<const Int>& level, const Val<const TexturePixelFormat>& fmt,
                       const Val<const TexturePixelData>& type, const Val<const Sizei>& size,
                       const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Texture::getImage, dst, level, fmt, type, size, src_loc);
    }
    
    glGetTextureImage(id(), level, fmt.cast_reinterpret<const Enum>(),
                      type.cast_reinterpret<const Enum>(), size, dst);
    return true;
}

bool Texture::getSubImage(const Val<void>& dst, 
                          const Val<const Int>& level, const Val<const TexturePixelFormat>& fmt,
                          const Val<const Int>& x, const Val<const Int>& y, const Val<const Int>& z,
                          const Val<const Sizei>& w, const Val<const Sizei>& h, const Val<const Sizei>& d,
                          const Val<const TexturePixelData>& type, const Val<const Sizei>& size,
                          const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Texture::getSubImage, dst, level, fmt, x, y, z, w, h, d, type, size, src_loc);
    }

    glGetTextureSubImage(id(), level, x, y, z, w, h, d,
                         fmt.cast_reinterpret<const Enum>(), type.cast_reinterpret<const Enum>(),
                         size, dst);
    return true;
}

bool Texture::setSubImage1D(const Val<const void>& data,
                            const Val<const Int>& level,
                            const Val<const Int>& x, const Val<const Sizei>& w,
                            const Val<const TexturePixelFormat>& fmt, const Val<const TexturePixelData>& type,
                            const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Texture::setSubImage1D, data, level, x, w, fmt, type, src_loc);
    }

    glTextureSubImage1D(id(), level, x, w,
                        fmt.cast_reinterpret<const Enum>(), type.cast_reinterpret<const Enum>(),
                        data);
    return true;
}

bool Texture::setSubImage2D(const Val<const void>& data,
                            const Val<const Int>& level,
                            const Val<const Int>& x, const Val<const Int>& y,
                            const Val<const Sizei>& w, const Val<const Sizei>& h,
                            const Val<const TexturePixelFormat>& fmt, const Val<const TexturePixelData>& type,
                            const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Texture::setSubImage2D, data, level, x, y, w, h, fmt, type, src_loc);
    }

    glTextureSubImage2D(id(), level, x, y, w, h,
                        fmt.cast_reinterpret<const Enum>(), type.cast_reinterpret<const Enum>(),
                        data);
    return true;
}

bool Texture::setSubImage3D(const Val<const void>& data,
                            const Val<const Int>& level,
                            const Val<const Int>& x, const Val<const Int>& y, const Val<const Int>& z,
                            const Val<const Sizei>& w, const Val<const Sizei>& h, const Val<const Sizei>& d,
                            const Val<const TexturePixelFormat>& fmt, const Val<const TexturePixelData>& type,
                            const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Texture::setSubImage3D, data, level, x, y, z, w, h, d, fmt, type, src_loc);
    }

    glTextureSubImage3D(id(), level, x, y, z, w, h, d,
                        fmt.cast_reinterpret<const Enum>(), type.cast_reinterpret<const Enum>(),
                        data);
    return true;
}

bool Texture::getParamInt(const Val<Int>& dst, const Val<const Enum>& param,
                          const Val<const SrcLoc>& src_loc) const {
    if (!isContextThread()){
        return executeMethodInContext(&Texture::getParamInt, dst, param, src_loc);
    }

    glGetTextureParameteriv(id(), param, dst);
    return true;
}

bool Texture::setParamInt(const Val<const Int>& value, const Val<const Enum>& param,
                          const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Texture::setParamInt, value, param, src_loc);
    }

    glTextureParameteri(id(), param, value);
    return true;
}

bool Texture::getWrapS(const Val<Wrap> dst,
                       const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_TEXTURE_WRAP_S, src_loc);
}
bool Texture::setWrapS(const Val<const Wrap> value,
                       const Val<const SrcLoc>& src_loc){
    return setParamInt(value.cast_reinterpret<const Int>(), GL_TEXTURE_WRAP_S, src_loc);
}

bool Texture::getWrapT(const Val<Wrap> dst,
                       const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_TEXTURE_WRAP_T, src_loc);
}
bool Texture::setWrapT(const Val<const Wrap> value,
                       const Val<const SrcLoc>& src_loc){
    return setParamInt(value.cast_reinterpret<const Int>(), GL_TEXTURE_WRAP_T, src_loc);
}

bool Texture::getMinFilter(const Val<MinFilter> dst,
                           const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_TEXTURE_MIN_FILTER, src_loc);
}

bool Texture::setMinFilter(const Val<const MinFilter> value,
                           const Val<const SrcLoc>& src_loc){
    return setParamInt(value.cast_reinterpret<const Int>(), GL_TEXTURE_MIN_FILTER, src_loc);
}

bool Texture::getMagFilter(const Val<MagFilter> dst,
                           const Val<const SrcLoc>& src_loc) const {
    return getParamInt(dst.cast_reinterpret<Int>(), GL_TEXTURE_MAG_FILTER, src_loc);
}

bool Texture::setMagFilter(const Val<const MagFilter> value,
                           const Val<const SrcLoc>& src_loc){
    return setParamInt(value.cast_reinterpret<const Int>(), GL_TEXTURE_MAG_FILTER, src_loc);
}

void Texture::_initer(const Val<UInt>& dst, const Val<const TextureType>& type,
                      const Val<const utils::SrcLoc>& src_loc){
    glCreateTextures(type.cast_reinterpret<const Enum>(), 1, dst);
    debug(src_loc);
}

void Texture::_deleter(const UInt& id){
    glDeleteTextures(1, &id);
}