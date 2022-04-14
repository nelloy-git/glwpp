#pragma once

#include "glwpp/gl/obj/Object.hpp"

#include "glwpp/gl/ctx_only/CtxTexture.hpp"

#include "glwpp/gl/enums/TextureBufferFormat.hpp"
#include "glwpp/gl/enums/TextureType.hpp"
#include "glwpp/gl/enums/TextureParam.hpp"
#include "glwpp/gl/enums/TexturePixelData.hpp"
#include "glwpp/gl/enums/TexturePixelFormat.hpp"
#include "glwpp/gl/obj/Buffer.hpp"
#include "glwpp/utils/SrcLoc.hpp"

namespace glwpp {

class Texture : public Object {
public:
    Texture(wptr<Context> ctx, const Val<gl::TextureType>& type, const SrcLoc& loc = SrcLoc());

    bool buffer(const Val<gl::TextureFormat>& fmt, const Buffer& buffer,
                const SrcLoc& loc = SrcLoc());
    bool bufferRange(const Val<gl::TextureFormat>& fmt, const Buffer& buffer,
                     const Val<gl::IntPtr>& offset, const Val<gl::SizeiPtr>& size,
                     const SrcLoc& loc = SrcLoc());
    bool storage1D(const Val<gl::Sizei>& levels, const Val<gl::TextureFormat>& fmt,
                   const Val<gl::Sizei>& width,
                   const SrcLoc& loc = SrcLoc());
    bool storage2D(const Val<gl::Sizei>& levels, const Val<gl::TextureFormat>& fmt,
                   const Val<gl::Sizei>& width, const Val<gl::Sizei>& height,
                   const SrcLoc& loc = SrcLoc());
    bool storage3D(const Val<gl::Sizei>& levels, const Val<gl::TextureFormat>& fmt,
                   const Val<gl::Sizei>& width, const Val<gl::Sizei>& height, const Val<gl::Sizei>& depth,
                   const SrcLoc& loc = SrcLoc());
    bool storageMultisample2D(const Val<gl::Sizei>& levels, const Val<gl::TextureFormat>& fmt,
                              const Val<gl::Sizei>& width, const Val<gl::Sizei>& height,
                              const Val<gl::Bool>& fixed_locations,
                              const SrcLoc& loc = SrcLoc());
    bool storageMultisample3D(const Val<gl::Sizei>& levels, const Val<gl::TextureFormat>& fmt,
                              const Val<gl::Sizei>& width, const Val<gl::Sizei>& height, const Val<gl::Sizei>& depth,
                              const Val<gl::Bool>& fixed_locations,
                              const SrcLoc& loc = SrcLoc());

    bool setUnit(const Val<gl::UInt>& index, const SrcLoc& loc = SrcLoc()) const;
    bool generateMipMap(const SrcLoc& loc = SrcLoc());

    bool getImage(const Val<gl::Int>& level, const Val<gl::TexturePixelFormat>& fmt,
                  const Val<gl::TexturePixelData>& type, const Val<gl::Sizei>& size, Ptr<void>& data,
                  const SrcLoc& loc = SrcLoc());
    bool getSubImage(const Val<gl::Int>& level, const Val<gl::TexturePixelFormat>& fmt,
                     const Val<gl::Int>& x, const Val<gl::Int>& y, const Val<gl::Int>& z,
                     const Val<gl::Sizei>& w, const Val<gl::Sizei>& h, const Val<gl::Sizei>& d,
                     const Val<gl::TexturePixelData>& type, const Val<gl::Sizei>& size, Ptr<void>& data,
                     const SrcLoc& loc = SrcLoc());
    bool setSubImage1D(const Val<gl::Int>& level,
                       const Val<gl::Int>& x, const Val<gl::Sizei>& w,
                       const Val<gl::TexturePixelFormat>& fmt, const Val<gl::TexturePixelData>& type,
                       const Ptr<void>& data,
                       const SrcLoc& loc = SrcLoc());
    
    bool setSubImage2D(const Val<gl::Int>& level,
                       const Val<gl::Int>& x, const Val<gl::Int>& y,
                       const Val<gl::Sizei>& w, const Val<gl::Sizei>& h,
                       const Val<gl::TexturePixelFormat>& fmt, const Val<gl::TexturePixelData>& type,
                       const Ptr<void>& data,
                       const SrcLoc& loc = SrcLoc());
    
    bool setSubImage3D(const Val<gl::Int>& level,
                       const Val<gl::Int>& x, const Val<gl::Int>& y, const Val<gl::Int>& z,
                       const Val<gl::Sizei>& w, const Val<gl::Sizei>& h, const Val<gl::Sizei>& d,
                       const Val<gl::TexturePixelFormat>& fmt, const Val<gl::TexturePixelData>& type,
                       const Ptr<void>& data,
                       const SrcLoc& loc = SrcLoc());

    // =================================
    // Wrappers for Texture::setParam_iv
    // =================================

    using Wrap = gl::CtxTexture::Wrap;

    bool getWrapS(Ptr<Wrap>& dst, const SrcLoc& loc = SrcLoc());
    bool setWrapS(const Val<Wrap>& wrap, const SrcLoc& loc = SrcLoc());
    bool getWrapT(Ptr<Wrap>& dst, const SrcLoc& loc = SrcLoc());
    bool setWrapT(const Val<Wrap>& wrap, const SrcLoc& loc = SrcLoc());

    using MinFilter = gl::CtxTexture::MinFilter;

    bool getMinFilter(Ptr<MinFilter>& dst, const SrcLoc& loc = SrcLoc());
    bool setMinFilter(const Val<MinFilter>& filter, const SrcLoc& loc = SrcLoc());

    using MagFilter = gl::CtxTexture::MagFilter;

    bool getMagFilter(Ptr<MagFilter>& dst, const SrcLoc& loc = SrcLoc());
    bool setMagFilter(const Val<MagFilter>& filter, const SrcLoc& loc = SrcLoc());
};

} // namespace glwpp