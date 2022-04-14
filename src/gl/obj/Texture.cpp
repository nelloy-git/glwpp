#include "glwpp/gl/obj/Texture.hpp"

#include "glwpp/gl/ctx_only/CtxTexture.hpp"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
    CtxTexture InitTexture(const TextureType& type, const SrcLoc& loc){
        return CtxTexture(type, loc);
    }
}

Texture::Texture(wptr<Context> ctx, const Val<gl::TextureType>& type, const SrcLoc& loc) : 
    Object(ctx, &InitTexture, type, Val<SrcLoc>(loc)){
}

bool Texture::buffer(const Val<gl::TextureFormat>& fmt, const Buffer& buffer, const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::buffer>(fmt, buffer._getVop<CtxBuffer>(), loc);
}

bool Texture::bufferRange(const Val<gl::TextureFormat>& fmt, const Buffer& buffer,
                          const Val<gl::IntPtr>& offset, const Val<gl::SizeiPtr>& size,
                          const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::bufferRange>(fmt, buffer._getVop<CtxBuffer>(), offset, size, loc);
}

bool Texture::storage1D(const Val<gl::Sizei>& levels, const Val<gl::TextureFormat>& fmt,
                        const Val<gl::Sizei>& width,
                        const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::storage1D>(levels, fmt, width, loc);
}

bool Texture::storage2D(const Val<gl::Sizei>& levels, const Val<gl::TextureFormat>& fmt,
                        const Val<gl::Sizei>& width, const Val<gl::Sizei>& height,
                        const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::storage2D>(levels, fmt, width, height, loc);
}

bool Texture::storage3D(const Val<gl::Sizei>& levels, const Val<gl::TextureFormat>& fmt,
                        const Val<gl::Sizei>& width, const Val<gl::Sizei>& height, const Val<gl::Sizei>& depth,
                        const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::storage3D>(levels, fmt, width, height, depth, loc);
}

bool Texture::storageMultisample2D(const Val<gl::Sizei>& levels, const Val<gl::TextureFormat>& fmt,
                                   const Val<gl::Sizei>& width, const Val<gl::Sizei>& height,
                                   const Val<gl::Bool>& fixed_locations, const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::storageMultisample2D>(levels, fmt, width, height, fixed_locations, loc);
}

bool Texture::storageMultisample3D(const Val<gl::Sizei>& levels, const Val<gl::TextureFormat>& fmt,
                                   const Val<gl::Sizei>& width, const Val<gl::Sizei>& height, const Val<gl::Sizei>& depth,
                                   const Val<gl::Bool>& fixed_locations, const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::storageMultisample3D>(levels, fmt, width, height, depth, fixed_locations, loc);
}

bool Texture::setUnit(const Val<gl::UInt>& index, const SrcLoc& loc) const {
    return _executeMethod<CtxTexture, &CtxTexture::setUnit>(index, loc);
}

bool Texture::generateMipMap(const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::generateMipMap>(loc);
}

bool Texture::getImage(const Val<gl::Int>& level, const Val<gl::TexturePixelFormat>& fmt,
                       const Val<gl::TexturePixelData>& type, const Val<gl::Sizei>& size, Ptr<void>& data,
                       const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::getImage>(level, fmt, type, size, data, loc);
}

bool Texture::getSubImage(const Val<gl::Int>& level, const Val<gl::TexturePixelFormat>& fmt,
                          const Val<gl::Int>& x, const Val<gl::Int>& y, const Val<gl::Int>& z,
                          const Val<gl::Sizei>& w, const Val<gl::Sizei>& h, const Val<gl::Sizei>& d,
                          const Val<gl::TexturePixelData>& type, const Val<gl::Sizei>& size, Ptr<void>& data,
                          const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::getSubImage>(level, fmt, x, y, z, w, h, d, type, size, data, loc);
}

bool Texture::setSubImage1D(const Val<gl::Int>& level,
                            const Val<gl::Int>& x, const Val<gl::Sizei>& w,
                            const Val<gl::TexturePixelFormat>& fmt, const Val<gl::TexturePixelData>& type,
                            const Ptr<void>& data, const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::setSubImage1D>(level, x, w, fmt, type, data, loc);
}

bool Texture::setSubImage2D(const Val<gl::Int>& level,
                            const Val<gl::Int>& x, const Val<gl::Int>& y,
                            const Val<gl::Sizei>& w, const Val<gl::Sizei>& h,
                            const Val<gl::TexturePixelFormat>& fmt, const Val<gl::TexturePixelData>& type,
                            const Ptr<void>& data, const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::setSubImage2D>(level, x, y, w, h, fmt, type, data, loc);
};

bool Texture::setSubImage3D(const Val<gl::Int>& level,
                            const Val<gl::Int>& x, const Val<gl::Int>& y, const Val<gl::Int>& z,
                            const Val<gl::Sizei>& w, const Val<gl::Sizei>& h, const Val<gl::Sizei>& d,
                            const Val<gl::TexturePixelFormat>& fmt, const Val<gl::TexturePixelData>& type,
                            const Ptr<void>& data, const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::setSubImage3D>(level, x, y, z, w, h, d, fmt, type, data, loc);
}


bool Texture::getWrapS(Ptr<Wrap>& dst, const SrcLoc& loc){
    return _executeGetter<CtxTexture, &CtxTexture::getWrapS>(dst, loc);
}

bool Texture::setWrapS(const Val<Wrap>& wrap, const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::setWrapS>(wrap, loc);
}

bool Texture::getWrapT(Ptr<Wrap>& dst, const SrcLoc& loc){
    return _executeGetter<CtxTexture, &CtxTexture::getWrapT>(dst, loc);
}

bool Texture::setWrapT(const Val<Wrap>& wrap, const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::setWrapT>(wrap, loc);
}

bool Texture::getMinFilter(Ptr<MinFilter>& dst, const SrcLoc& loc){
    return _executeGetter<CtxTexture, &CtxTexture::getMinFilter>(dst, loc);
}

bool Texture::setMinFilter(const Val<MinFilter>& filter, const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::setMinFilter>(filter, loc);
}

bool Texture::getMagFilter(Ptr<MagFilter>& dst, const SrcLoc& loc){
    return _executeGetter<CtxTexture, &CtxTexture::getMagFilter>(dst, loc);
}

bool Texture::setMagFilter(const Val<MagFilter>& filter, const SrcLoc& loc){
    return _executeMethod<CtxTexture, &CtxTexture::setMagFilter>(filter, loc);
}
