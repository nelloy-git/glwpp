#pragma once

#include "glwpp/gl/oop/Object.hpp"

#include "glwpp/gl/object/CtxTexture.hpp"

#include "glwpp/gl/enums/TextureBufferFormat.hpp"
#include "glwpp/gl/enums/TextureType.hpp"
#include "glwpp/gl/enums/TextureParam.hpp"
#include "glwpp/gl/enums/TexturePixelData.hpp"
#include "glwpp/gl/enums/TexturePixelFormat.hpp"
#include "glwpp/gl/oop/Buffer.hpp"

namespace glwpp {

class Texture : public Object {
public:
    Texture(wptr<Context> ctx, const Vop<gl::TextureType> type, const SrcLoc& loc = SrcLoc::current());

    std::shared_future<bool> buffer(const Vop<gl::TextureFormat> fmt, const Vop<Buffer> buffer,
                                    const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> bufferRange(const Vop<gl::TextureFormat> fmt, const Vop<Buffer> buffer,
                                         const Vop<gl::IntPtr> offset, const Vop<gl::SizeiPtr> size,
                                         const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> storage1D(const Vop<gl::Sizei> levels, const Vop<gl::TextureFormat> fmt,
                                       const Vop<gl::Sizei> width,
                                       const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> storage2D(const Vop<gl::Sizei> levels, const Vop<gl::TextureFormat> fmt,
                                       const Vop<gl::Sizei> width, const Vop<gl::Sizei> height,
                                       const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> storage3D(const Vop<gl::Sizei> levels, const Vop<gl::TextureFormat> fmt,
                                       const Vop<gl::Sizei> width, const Vop<gl::Sizei> height, const Vop<gl::Sizei> depth,
                                       const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> storageMultisample2D(const Vop<gl::Sizei> levels, const Vop<gl::TextureFormat> fmt,
                                                 const Vop<gl::Sizei> width, const Vop<gl::Sizei> height,
                                                 const Vop<gl::Bool> fixed_locations,
                                                 const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> storageMultisample3D(const Vop<gl::Sizei> levels, const Vop<gl::TextureFormat> fmt,
                                                  const Vop<gl::Sizei> width, const Vop<gl::Sizei> height, const Vop<gl::Sizei> depth,
                                                  const Vop<gl::Bool> fixed_locations,
                                                  const SrcLoc& loc = SrcLoc::current());

    std::shared_future<bool> setUnit(const Vop<gl::UInt> index, const SrcLoc& loc = SrcLoc::current()) const;
    std::shared_future<bool> generateMipMap(const SrcLoc& loc = SrcLoc::current());

    using Data = void*;
    std::shared_future<bool> getImage(const Vop<gl::Int> level, const Vop<gl::TexturePixelFormat> fmt,
                                      const Vop<gl::TexturePixelData> type, const Vop<gl::Sizei> size, Vop<Data> data,
                                         const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> getSubImage(const Vop<gl::Int> level, const Vop<gl::TexturePixelFormat> fmt,
                                         const Vop<gl::Int> x, const Vop<gl::Int> y, const Vop<gl::Int> z,
                                         const Vop<gl::Sizei> w, const Vop<gl::Sizei> h, const Vop<gl::Sizei> d,
                                         const Vop<gl::TexturePixelData> type, const Vop<gl::Sizei> size, Vop<Data> data,
                                         const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> setSubImage1D(const Vop<gl::Int> level,
                                           const Vop<gl::Int> x, const Vop<gl::Sizei> w,
                                           const Vop<gl::TexturePixelFormat> fmt, const Vop<gl::TexturePixelData> type,
                                           const Vop<Data> data,
                                           const SrcLoc& loc = SrcLoc::current());
    
    std::shared_future<bool> setSubImage2D(const Vop<gl::Int> level,
                                           const Vop<gl::Int> x, const Vop<gl::Int> y,
                                           const Vop<gl::Sizei> w, const Vop<gl::Sizei> h,
                                           const Vop<gl::TexturePixelFormat> fmt, const Vop<gl::TexturePixelData> type,
                                           const Vop<Data> data,
                                           const SrcLoc& loc = SrcLoc::current());
    
    std::shared_future<bool> setSubImage3D(const Vop<gl::Int> level,
                                           const Vop<gl::Int> x, const Vop<gl::Int> y, const Vop<gl::Int> z,
                                           const Vop<gl::Sizei> w, const Vop<gl::Sizei> h, const Vop<gl::Sizei> d,
                                           const Vop<gl::TexturePixelFormat> fmt, const Vop<gl::TexturePixelData> type,
                                           const Vop<Data> data,
                                           const SrcLoc& loc = SrcLoc::current());

    // =================================
    // Wrappers for Texture::setParam_iv
    // =================================

    using Wrap = gl::CtxTexture::Wrap;

    std::shared_future<bool> getWrapS(Ptr<Wrap> dst, const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> setWrapS(const Vop<Wrap> wrap, const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> getWrapT(Ptr<Wrap> dst, const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> setWrapT(const Vop<Wrap> wrap, const SrcLoc& loc = SrcLoc::current());

    using MinFilter = gl::CtxTexture::MinFilter;

    std::shared_future<bool> getMinFilter(Ptr<MinFilter> dst, const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> setMinFilter(const Vop<MinFilter> filter, const SrcLoc& loc = SrcLoc::current());

    using MagFilter = gl::CtxTexture::MagFilter;

    std::shared_future<bool> getMagFilter(Ptr<MagFilter> dst, const SrcLoc& loc = SrcLoc::current());
    std::shared_future<bool> setMagFilter(const Vop<MagFilter> filter, const SrcLoc& loc = SrcLoc::current());

private:
    static gl::Int _glGetParam_i(const gl::UInt id, const gl::Enum param);
    static void _glSetParam_i(const gl::UInt id, const gl::Enum param, const gl::Int val);

};

} // namespace glwpp