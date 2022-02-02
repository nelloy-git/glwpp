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
    static constexpr bool DEBUG = true;
    
    Texture(wptr<Context> ctx, const gl::TextureType type);
    Texture(const Texture&) = delete;
    Texture(const Texture&&);
    virtual ~Texture() = 0;

    std::shared_future<bool> buffer(Vop<const gl::TextureFormat> fmt, Ptr<const Buffer> buffer);
    std::shared_future<bool> bufferRange(Vop<const gl::TextureFormat> fmt, Ptr<const Buffer> buffer,
                                         Vop<const gl::IntPtr> offset, Vop<const gl::SizeiPtr> size);
    std::shared_future<bool> storage1D(Vop<const gl::Sizei> levels, Vop<const gl::TextureFormat> fmt,
                                       Vop<const gl::Sizei> width);
    std::shared_future<bool> storage2D(Vop<const gl::Sizei> levels, Vop<const gl::TextureFormat> fmt,
                                       Vop<const gl::Sizei> width, Vop<const gl::Sizei> height);
    std::shared_future<bool> storage3D(Vop<const gl::Sizei> levels, Vop<const gl::TextureFormat> fmt,
                                       Vop<const gl::Sizei> width, Vop<const gl::Sizei> height, Vop<const gl::Sizei> depth);
    std::shared_future<bool> storageMultisample2D(Vop<const gl::Sizei> levels, Vop<const gl::TextureFormat> fmt,
                                                 Vop<const gl::Sizei> width, Vop<const gl::Sizei> height,
                                                 Vop<const gl::Bool> fixed_locations);
    std::shared_future<bool> storageMultisample3D(Vop<const gl::Sizei> levels, Vop<const gl::TextureFormat> fmt,
                                                  Vop<const gl::Sizei> width, Vop<const gl::Sizei> height, Vop<const gl::Sizei> depth,
                                                  Vop<const gl::Bool> fixed_locations);

    std::shared_future<bool> getLevelParam_iv(Vop<const gl::Int> level, Vop<const gl::TextureLevelParam> param, Ptr<gl::Int> dst);
    std::shared_future<bool> getLevelParam_fv(Vop<const gl::Int> level, Vop<const gl::TextureLevelParam> param, Ptr<gl::Float> dst);
    std::shared_future<bool> getParam_iv(Vop<const gl::TextureParam> param, Ptr<gl::Int> dst);
    std::shared_future<bool> setParam_iv(Vop<const gl::TextureParam> param, Vop<const gl::Int> value);
    std::shared_future<bool> getParam_fv(Vop<const gl::TextureParam> param, Ptr<gl::Float> dst);
    std::shared_future<bool> setParam_fv(Vop<const gl::TextureParam> param, Vop<const gl::Float> value);

    std::shared_future<bool> setActive(Vop<const gl::UInt> index) const;
    std::shared_future<bool> generateMipMap();

    using Data = void*;
    std::shared_future<bool> getImage(Vop<const gl::Int> level, Vop<const gl::TexturePixelFormat> fmt,
                                      Vop<const gl::TexturePixelData> type, Vop<const gl::Sizei> size, Vop<Data> data);
    std::shared_future<bool> getSubImage(Vop<const gl::Int> level, Vop<const gl::TexturePixelFormat> fmt,
                                         Vop<const gl::Int> x, Vop<const gl::Int> y, Vop<const gl::Int> z,
                                         Vop<const gl::Sizei> w, Vop<const gl::Sizei> h, Vop<const gl::Sizei> d,
                                         Vop<const gl::TexturePixelData> type, Vop<const gl::Sizei> size, Vop<Data> data);
    std::shared_future<bool> setSubImage1D(Vop<const gl::Int> level,
                                           Vop<const gl::Int> x, Vop<const gl::Sizei> w,
                                           Vop<const gl::TexturePixelFormat> fmt, Vop<const gl::TexturePixelData> type,
                                           Vop<const Data> data);
    
    std::shared_future<bool> setSubImage2D(Vop<const gl::Int> level,
                                           Vop<const gl::Int> x, Vop<const gl::Int> y,
                                           Vop<const gl::Sizei> w, Vop<const gl::Sizei> h,
                                           Vop<const gl::TexturePixelFormat> fmt, Vop<const gl::TexturePixelData> type,
                                           Vop<const Data> data);
    
    std::shared_future<bool> setSubImage3D(Vop<const gl::Int> level,
                                           Vop<const gl::Int> x, Vop<const gl::Int> y, Vop<const gl::Int> z,
                                           Vop<const gl::Sizei> w, Vop<const gl::Sizei> h, Vop<const gl::Sizei> d,
                                           Vop<const gl::TexturePixelFormat> fmt, Vop<const gl::TexturePixelData> type,
                                           Vop<const Data> data);

};

} // namespace glwpp