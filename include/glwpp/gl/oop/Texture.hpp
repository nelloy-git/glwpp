#pragma once

#include "glwpp/gl/oop/Object.hpp"

#include "glwpp/gl/object/CtxTexture.hpp"

#include "glwpp/gl/enums/TextureBufferFormat.hpp"
#include "glwpp/gl/enums/TextureType.hpp"
#include "glwpp/gl/enums/TextureParam.hpp"
#include "glwpp/gl/enums/TexturePixelData.hpp"
#include "glwpp/gl/enums/TexturePixelFormat.hpp"
#include "glwpp/gl/oop/Buffer.hpp"
#include "glwpp/utils/SrcLoc.hpp"

namespace glwpp {

class Texture : public Object {
public:
    Texture(wptr<Context> ctx, const Vop<gl::TextureType>& type, const SrcLoc& loc = SrcLoc());

    bool buffer(const Vop<gl::TextureFormat>& fmt, const Buffer& buffer,
                const SrcLoc& loc = SrcLoc());
    bool bufferRange(const Vop<gl::TextureFormat>& fmt, const Buffer& buffer,
                     const Vop<gl::IntPtr>& offset, const Vop<gl::SizeiPtr>& size,
                     const SrcLoc& loc = SrcLoc());
    bool storage1D(const Vop<gl::Sizei>& levels, const Vop<gl::TextureFormat>& fmt,
                   const Vop<gl::Sizei>& width,
                   const SrcLoc& loc = SrcLoc());
    bool storage2D(const Vop<gl::Sizei>& levels, const Vop<gl::TextureFormat>& fmt,
                   const Vop<gl::Sizei>& width, const Vop<gl::Sizei>& height,
                   const SrcLoc& loc = SrcLoc());
    bool storage3D(const Vop<gl::Sizei>& levels, const Vop<gl::TextureFormat>& fmt,
                   const Vop<gl::Sizei>& width, const Vop<gl::Sizei>& height, const Vop<gl::Sizei>& depth,
                   const SrcLoc& loc = SrcLoc());
    bool storageMultisample2D(const Vop<gl::Sizei>& levels, const Vop<gl::TextureFormat>& fmt,
                              const Vop<gl::Sizei>& width, const Vop<gl::Sizei>& height,
                              const Vop<gl::Bool>& fixed_locations,
                              const SrcLoc& loc = SrcLoc());
    bool storageMultisample3D(const Vop<gl::Sizei>& levels, const Vop<gl::TextureFormat>& fmt,
                              const Vop<gl::Sizei>& width, const Vop<gl::Sizei>& height, const Vop<gl::Sizei>& depth,
                              const Vop<gl::Bool>& fixed_locations,
                              const SrcLoc& loc = SrcLoc());

    bool setUnit(const Vop<gl::UInt>& index, const SrcLoc& loc = SrcLoc()) const;
    bool generateMipMap(const SrcLoc& loc = SrcLoc());

    using Data = void*;
    bool getImage(const Vop<gl::Int>& level, const Vop<gl::TexturePixelFormat>& fmt,
                  const Vop<gl::TexturePixelData>& type, const Vop<gl::Sizei>& size, Vop<Data>& data,
                  const SrcLoc& loc = SrcLoc());
    bool getSubImage(const Vop<gl::Int>& level, const Vop<gl::TexturePixelFormat>& fmt,
                     const Vop<gl::Int>& x, const Vop<gl::Int>& y, const Vop<gl::Int>& z,
                     const Vop<gl::Sizei>& w, const Vop<gl::Sizei>& h, const Vop<gl::Sizei>& d,
                     const Vop<gl::TexturePixelData>& type, const Vop<gl::Sizei>& size, Vop<Data>& data,
                     const SrcLoc& loc = SrcLoc());
    bool setSubImage1D(const Vop<gl::Int>& level,
                       const Vop<gl::Int>& x, const Vop<gl::Sizei>& w,
                       const Vop<gl::TexturePixelFormat>& fmt, const Vop<gl::TexturePixelData>& type,
                       const Vop<Data>& data,
                       const SrcLoc& loc = SrcLoc());
    
    bool setSubImage2D(const Vop<gl::Int>& level,
                       const Vop<gl::Int>& x, const Vop<gl::Int>& y,
                       const Vop<gl::Sizei>& w, const Vop<gl::Sizei>& h,
                       const Vop<gl::TexturePixelFormat>& fmt, const Vop<gl::TexturePixelData>& type,
                       const Vop<Data>& data,
                       const SrcLoc& loc = SrcLoc());
    
    bool setSubImage3D(const Vop<gl::Int>& level,
                       const Vop<gl::Int>& x, const Vop<gl::Int>& y, const Vop<gl::Int>& z,
                       const Vop<gl::Sizei>& w, const Vop<gl::Sizei>& h, const Vop<gl::Sizei>& d,
                       const Vop<gl::TexturePixelFormat>& fmt, const Vop<gl::TexturePixelData>& type,
                       const Vop<Data>& data,
                       const SrcLoc& loc = SrcLoc());

    // =================================
    // Wrappers for Texture::setParam_iv
    // =================================

    using Wrap = gl::CtxTexture::Wrap;

    bool getWrapS(Ptr<Wrap>& dst, const SrcLoc& loc = SrcLoc());
    bool setWrapS(const Vop<Wrap>& wrap, const SrcLoc& loc = SrcLoc());
    bool getWrapT(Ptr<Wrap>& dst, const SrcLoc& loc = SrcLoc());
    bool setWrapT(const Vop<Wrap>& wrap, const SrcLoc& loc = SrcLoc());

    using MinFilter = gl::CtxTexture::MinFilter;

    bool getMinFilter(Ptr<MinFilter>& dst, const SrcLoc& loc = SrcLoc());
    bool setMinFilter(const Vop<MinFilter>& filter, const SrcLoc& loc = SrcLoc());

    using MagFilter = gl::CtxTexture::MagFilter;

    bool getMagFilter(Ptr<MagFilter>& dst, const SrcLoc& loc = SrcLoc());
    bool setMagFilter(const Vop<MagFilter>& filter, const SrcLoc& loc = SrcLoc());
};

} // namespace glwpp