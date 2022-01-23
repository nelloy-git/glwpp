#pragma once

#include "glwpp/gl/oop/ContextData.hpp"
#include "glwpp/gl/oop/Buffer.hpp"

#include "glwpp/gl/enums/TextureBufferFormat.hpp"
#include "glwpp/gl/enums/TextureType.hpp"
#include "glwpp/gl/enums/TextureParam.hpp"
#include "glwpp/gl/enums/TexturePixelData.hpp"
#include "glwpp/gl/enums/TexturePixelFormat.hpp"

namespace glwpp {

class Texture : public ContextData {
public:
    static constexpr bool AUTOCLEAR = true;

    Texture(wptr<Context> ctx, const gl::TextureType type);
    Texture(const Texture&) = delete;
    Texture(const Texture&&);
    virtual ~Texture() = 0;

    std::shared_future<bool> buffer(sptr<gl::TextureFormat> fmt, sptr<Buffer> buffer);
    std::shared_future<bool> bufferRange(sptr<gl::TextureFormat> fmt, sptr<Buffer> buffer,
                                         sptr<gl::IntPtr> offset, sptr<gl::SizeiPtr> size);
    std::shared_future<bool> storage1D(sptr<gl::Sizei> levels, sptr<gl::TextureFormat> fmt,
                                       sptr<gl::Sizei> width);
    std::shared_future<bool> storage2D(sptr<gl::Sizei> levels, sptr<gl::TextureFormat> fmt,
                                       sptr<gl::Sizei> width, sptr<gl::Sizei> height);
    std::shared_future<bool> storage3D(sptr<gl::Sizei> levels, sptr<gl::TextureFormat> fmt,
                                       sptr<gl::Sizei> width, sptr<gl::Sizei> height, sptr<gl::Sizei> depth);
    std::shared_future<bool> storageMultisample2D(sptr<gl::Sizei> levels, sptr<gl::TextureFormat> fmt,
                                                 sptr<gl::Sizei> width, sptr<gl::Sizei> height,
                                                 sptr<gl::Bool> fixed_locations);
    std::shared_future<bool> storageMultisample3D(sptr<gl::Sizei> levels, sptr<gl::TextureFormat> fmt,
                                                  sptr<gl::Sizei> width, sptr<gl::Sizei> height, sptr<gl::Sizei> depth,
                                                  sptr<gl::Bool> fixed_locations);

    std::shared_future<bool> getLevelParam_iv(sptr<gl::Int> level, sptr<gl::TextureLevelParam> param, sptr<gl::Int> dst);
    std::shared_future<bool> getLevelParam_fv(sptr<gl::Int> level, sptr<gl::TextureLevelParam> param, sptr<gl::Float> dst);
    std::shared_future<bool> getParam_iv(sptr<gl::TextureParam> param, sptr<gl::Int> dst);
    std::shared_future<bool> setParam_iv(sptr<gl::TextureParam> param, sptr<gl::Int> value);
    std::shared_future<bool> getParam_fv(sptr<gl::TextureParam> param, sptr<gl::Float> dst);
    std::shared_future<bool> setParam_fv(sptr<gl::TextureParam> param, sptr<gl::Float> value);

    std::shared_future<bool> setActive(sptr<gl::UInt> index) const;
    std::shared_future<bool> generateMipMap();

    std::shared_future<bool> getImage(sptr<gl::Int> level, sptr<gl::TexturePixelFormat> fmt,
                                      sptr<gl::TexturePixelData> type, sptr<gl::Sizei> size, sptr<void> data);
    std::shared_future<bool> getSubImage(sptr<gl::Int> level, sptr<gl::TexturePixelFormat> fmt,
                                         sptr<gl::Int> x, sptr<gl::Int> y, sptr<gl::Int> z,
                                         sptr<gl::Sizei> w, sptr<gl::Sizei> h, sptr<gl::Sizei> d,
                                         sptr<gl::TexturePixelData> type, sptr<gl::Sizei> size, sptr<void> data);
    std::shared_future<bool> setSubImage1D(sptr<gl::Int> level,
                                           sptr<gl::Int> x, sptr<gl::Sizei> w,
                                           sptr<gl::TexturePixelFormat> fmt, sptr<gl::TexturePixelData> type,
                                           sptr<const void> data);
    
    std::shared_future<bool> setSubImage2D(sptr<gl::Int> level,
                                           sptr<gl::Int> x, sptr<gl::Int> y,
                                           sptr<gl::Sizei> w, sptr<gl::Sizei> h,
                                           sptr<gl::TexturePixelFormat> fmt, sptr<gl::TexturePixelData> type,
                                           sptr<const void> data);
    
    std::shared_future<bool> setSubImage3D(sptr<gl::Int> level,
                                           sptr<gl::Int> x, sptr<gl::Int> y, sptr<gl::Int> z,
                                           sptr<gl::Sizei> w, sptr<gl::Sizei> h, sptr<gl::Sizei> d,
                                           sptr<gl::TexturePixelFormat> fmt, sptr<gl::TexturePixelData> type,
                                           sptr<const void> data);

};

}