#include "glwpp/gl/oop/Texture.hpp"

#include "glwpp/gl/object/CtxTexture.hpp"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
    CtxTexture InitTexture(const TextureType& type, const SrcLoc& loc){
        return CtxTexture(type, loc);
    }
}

Texture::Texture(wptr<Context> ctx, const Vop<gl::TextureType>& type, const SrcLoc& loc) : 
    Object(ctx, &InitTexture, type, Vop<SrcLoc>(loc)){
}

std::shared_future<bool> Texture::buffer(const Vop<gl::TextureFormat>& fmt, const Buffer& buffer, const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::buffer>(fmt, buffer._getVop<CtxBuffer>(), loc);
}

std::shared_future<bool> Texture::bufferRange(const Vop<gl::TextureFormat>& fmt, const Buffer& buffer,
                                              const Vop<gl::IntPtr>& offset, const Vop<gl::SizeiPtr>& size,
                                              const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::bufferRange>(fmt, buffer._getVop<CtxBuffer>(), offset, size, loc);
}

std::shared_future<bool> Texture::storage1D(const Vop<gl::Sizei>& levels, const Vop<gl::TextureFormat>& fmt,
                                            const Vop<gl::Sizei>& width,
                                            const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::storage1D>(levels, fmt, width, loc);
}

std::shared_future<bool> Texture::storage2D(const Vop<gl::Sizei>& levels, const Vop<gl::TextureFormat>& fmt,
                                            const Vop<gl::Sizei>& width, const Vop<gl::Sizei>& height,
                                            const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::storage2D>(levels, fmt, width, height, loc);
}

std::shared_future<bool> Texture::storage3D(const Vop<gl::Sizei>& levels, const Vop<gl::TextureFormat>& fmt,
                                            const Vop<gl::Sizei>& width, const Vop<gl::Sizei>& height, const Vop<gl::Sizei>& depth,
                                            const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::storage3D>(levels, fmt, width, height, depth, loc);
}

std::shared_future<bool> Texture::storageMultisample2D(const Vop<gl::Sizei>& levels, const Vop<gl::TextureFormat>& fmt,
                                                       const Vop<gl::Sizei>& width, const Vop<gl::Sizei>& height,
                                                       const Vop<gl::Bool>& fixed_locations, const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::storageMultisample2D>(levels, fmt, width, height, fixed_locations, loc);
}

std::shared_future<bool> Texture::storageMultisample3D(const Vop<gl::Sizei>& levels, const Vop<gl::TextureFormat>& fmt,
                                                       const Vop<gl::Sizei>& width, const Vop<gl::Sizei>& height, const Vop<gl::Sizei>& depth,
                                                       const Vop<gl::Bool>& fixed_locations, const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::storageMultisample3D>(levels, fmt, width, height, depth, fixed_locations, loc);
}

std::shared_future<bool> Texture::setUnit(const Vop<gl::UInt>& index, const SrcLoc& loc) const {
    return _callMethod<CtxTexture, &CtxTexture::setUnit>(index, loc);
}

std::shared_future<bool> Texture::generateMipMap(const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::generateMipMap>(loc);
}

std::shared_future<bool> Texture::getImage(const Vop<gl::Int>& level, const Vop<gl::TexturePixelFormat>& fmt,
                                           const Vop<gl::TexturePixelData>& type, const Vop<gl::Sizei>& size, Vop<Data>& data,
                                           const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::getImage>(level, fmt, type, size, data, loc);
}

std::shared_future<bool> Texture::getSubImage(const Vop<gl::Int>& level, const Vop<gl::TexturePixelFormat>& fmt,
                                              const Vop<gl::Int>& x, const Vop<gl::Int>& y, const Vop<gl::Int>& z,
                                              const Vop<gl::Sizei>& w, const Vop<gl::Sizei>& h, const Vop<gl::Sizei>& d,
                                              const Vop<gl::TexturePixelData>& type, const Vop<gl::Sizei>& size, Vop<Data>& data,
                                              const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::getSubImage>(level, fmt, x, y, z, w, h, d, type, size, data, loc);
}

std::shared_future<bool> Texture::setSubImage1D(const Vop<gl::Int>& level,
                                                const Vop<gl::Int>& x, const Vop<gl::Sizei>& w,
                                                const Vop<gl::TexturePixelFormat>& fmt, const Vop<gl::TexturePixelData>& type,
                                                const Vop<Data>& data, const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::setSubImage1D>(level, x, w, fmt, type, data, loc);
}

std::shared_future<bool> Texture::setSubImage2D(const Vop<gl::Int>& level,
                                                const Vop<gl::Int>& x, const Vop<gl::Int>& y,
                                                const Vop<gl::Sizei>& w, const Vop<gl::Sizei>& h,
                                                const Vop<gl::TexturePixelFormat>& fmt, const Vop<gl::TexturePixelData>& type,
                                                const Vop<Data>& data, const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::setSubImage2D>(level, x, y, w, h, fmt, type, data, loc);
};

std::shared_future<bool> Texture::setSubImage3D(const Vop<gl::Int>& level,
                                                const Vop<gl::Int>& x, const Vop<gl::Int>& y, const Vop<gl::Int>& z,
                                                const Vop<gl::Sizei>& w, const Vop<gl::Sizei>& h, const Vop<gl::Sizei>& d,
                                                const Vop<gl::TexturePixelFormat>& fmt, const Vop<gl::TexturePixelData>& type,
                                                const Vop<Data>& data, const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::setSubImage3D>(level, x, y, z, w, h, d, fmt, type, data, loc);
}


std::shared_future<bool> Texture::getWrapS(Ptr<Wrap>& dst, const SrcLoc& loc){
    return _getFromMethod<CtxTexture, &CtxTexture::getWrapS>(dst, loc);
}

std::shared_future<bool> Texture::setWrapS(const Vop<Wrap>& wrap, const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::setWrapS>(wrap, loc);
}

std::shared_future<bool> Texture::getWrapT(Ptr<Wrap>& dst, const SrcLoc& loc){
    return _getFromMethod<CtxTexture, &CtxTexture::getWrapT>(dst, loc);
}

std::shared_future<bool> Texture::setWrapT(const Vop<Wrap>& wrap, const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::setWrapT>(wrap, loc);
}

std::shared_future<bool> Texture::getMinFilter(Ptr<MinFilter>& dst, const SrcLoc& loc){
    return _getFromMethod<CtxTexture, &CtxTexture::getMinFilter>(dst, loc);
}

std::shared_future<bool> Texture::setMinFilter(const Vop<MinFilter>& filter, const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::setMinFilter>(filter, loc);
}

std::shared_future<bool> Texture::getMagFilter(Ptr<MagFilter>& dst, const SrcLoc& loc){
    return _getFromMethod<CtxTexture, &CtxTexture::getMagFilter>(dst, loc);
}

std::shared_future<bool> Texture::setMagFilter(const Vop<MagFilter>& filter, const SrcLoc& loc){
    return _callMethod<CtxTexture, &CtxTexture::setMagFilter>(filter, loc);
}
