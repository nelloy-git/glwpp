#pragma once

#include "glwpp/gl/object/CtxObject.hpp"

#include "glwpp/gl/enums/TextureBufferFormat.hpp"
#include "glwpp/gl/enums/TextureType.hpp"
#include "glwpp/gl/enums/TextureParam.hpp"
#include "glwpp/gl/enums/TexturePixelData.hpp"
#include "glwpp/gl/enums/TexturePixelFormat.hpp"
#include "glwpp/gl/object/CtxBuffer.hpp"

namespace glwpp::gl {

class CtxTexture : public CtxObject {
public:
    CtxTexture(const TextureType& type, const SrcLoc& loc = SrcLoc());
    
    void buffer(const TextureFormat& fmt, const CtxBuffer& buffer, const SrcLoc& loc = SrcLoc());
    void bufferRange(const TextureFormat& fmt, const CtxBuffer& buffer,
                     const IntPtr& offset, const SizeiPtr& size, const SrcLoc& loc = SrcLoc());
    void image1D(const Sizei& levels, const TextureFormat& fmt,
                const Sizei& width, const SrcLoc& loc = SrcLoc());
    void image2D(const Sizei& levels, const TextureFormat& fmt,
                 const Sizei& width, const Sizei& height, const SrcLoc& loc = SrcLoc());
    void image3D(const Sizei& levels, const TextureFormat& fmt,
                 const Sizei& width, const Sizei& height, const Sizei& depth, const SrcLoc& loc = SrcLoc());
    void storage1D(const Sizei& levels, const TextureFormat& fmt,
                   const Sizei& width, const SrcLoc& loc = SrcLoc());
    void storage2D(const Sizei& levels, const TextureFormat& fmt,
                   const Sizei& width, const Sizei& height, const SrcLoc& loc = SrcLoc());
    void storage3D(const Sizei& levels, const TextureFormat& fmt,
                   const Sizei& width, const Sizei& height, const Sizei& depth, const SrcLoc& loc = SrcLoc());
    void storageMultisample2D(const Sizei& samples, const TextureFormat& fmt,
                              const Sizei& width, const Sizei& height,
                              const Bool& fixed_locations, const SrcLoc& loc = SrcLoc());
    void storageMultisample3D(const Sizei& samples, const TextureFormat& fmt,
                              const Sizei& width, const Sizei& height, const Sizei& depth,
                              const Bool& fixed_locations, const SrcLoc& loc = SrcLoc());

    void setUnit(const UInt& index, const SrcLoc& loc = SrcLoc()) const;
    void generateMipMap(const SrcLoc& loc = SrcLoc());

    using Data = void*;
    void getImage(const Int& level, const TexturePixelFormat& fmt,
                  const TexturePixelData& type, const Sizei& size, Data data,
                  const SrcLoc& loc = SrcLoc());
    void getSubImage(const Int& level, const TexturePixelFormat& fmt,
                     const Int& x, const Int& y, const Int& z,
                     const Sizei& w, const Sizei& h, const Sizei& d,
                     const TexturePixelData& type, const Sizei& size, Data data,
                     const SrcLoc& loc = SrcLoc());
    void setSubImage1D(const Int& level,
                       const Int& x, const Sizei& w,
                       const TexturePixelFormat& fmt, const TexturePixelData& type,
                       const Data data, const SrcLoc& loc = SrcLoc());
    void setSubImage2D(const Int& level,
                       const Int& x, const Int& y,
                       const Sizei& w, const Sizei& h,
                       const TexturePixelFormat& fmt, const TexturePixelData& type,
                       const Data data, const SrcLoc& loc = SrcLoc());
    void setSubImage3D(const Int& level,
                       const Int& x, const Int& y, const Int& z,
                       const Sizei& w, const Sizei& h, const Sizei& d,
                       const TexturePixelFormat& fmt, const TexturePixelData& type,
                       const Data data, const SrcLoc& loc = SrcLoc());

    Int getParamI(const Enum& param, const SrcLoc& loc = SrcLoc()) const;
    void setParamI(const Enum& param, const Int& val, const SrcLoc& loc = SrcLoc());

    enum class Wrap : Int {
        Clamp = 0x812F,  // GL_CLAMP_TO_EDGE,
        Mirror = 0x8370, // GL_MIRRORED_REPEAT,
        Repeat = 0x2901, // GL_REPEAT
    };

    Wrap getWrapS(const SrcLoc& loc = SrcLoc()) const;
    void setWrapS(const Wrap& wrap, const SrcLoc& loc = SrcLoc());
    Wrap getWrapT(const SrcLoc& loc = SrcLoc()) const;
    void setWrapT(const Wrap& wrap, const SrcLoc& loc = SrcLoc());
    
    enum class  MinFilter : Int {
        Nearest = 0x2600, // GL_NEAREST Returns the value of the texture element that is nearest (in Manhattan distance) to the specified texture coordinates.
        Linear = 0x2601, // GL_LINEAR Returns the weighted average of the four texture elements that are closest to the specified texture coordinates. These can include items wrapped or repeated from other parts of a texture, depending on the values of GL_TEXTURE_WRAP_S and GL_TEXTURE_WRAP_T, and on the exact mapping.
        NearestMipMapNearest = 0x2700, // GL_NEAREST_MIPMAP_NEAREST Chooses the mipmap that most closely matches the size of the pixel being textured and uses the GL_NEAREST criterion (the texture element closest to the specified texture coordinates) to produce a texture value.
        LinearMipmapNearest = 0x2701, // GL_LINEAR_MIPMAP_NEAREST Chooses the mipmap that most closely matches the size of the pixel being textured and uses the GL_LINEAR criterion (a weighted average of the four texture elements that are closest to the specified texture coordinates) to produce a texture value.
        NearestMipMapLinear = 0x2702, // GL_NEAREST_MIPMAP_LINEAR Chooses the two mipmaps that most closely match the size of the pixel being textured and uses the GL_NEAREST criterion (the texture element closest to the specified texture coordinates ) to produce a texture value from each mipmap. The final texture value is a weighted average of those two values.
        LinearMipMapLinear = 0x2703, // GL_LINEAR_MIPMAP_LINEAR Chooses the two mipmaps that most closely match the size of the pixel being textured and uses the GL_LINEAR criterion (a weighted average of the texture elements that are closest to the specified texture coordinates) to produce a texture value from each mipmap. The final texture value is a weighted average of those two values. 
    };

    MinFilter getMinFilter(const SrcLoc& loc = SrcLoc()) const;
    void setMinFilter(const MinFilter& filter, const SrcLoc& loc = SrcLoc());

    enum class  MagFilter : Int {
        Nearest = 0x2600, // GL_NEAREST Returns the value of the texture element that is nearest (in Manhattan distance) to the specified texture coordinates.
        Linear = 0x2601, // GL_LINEAR Returns the weighted average of the four texture elements that are closest to the specified texture coordinates. These can include items wrapped or repeated from other parts of a texture, depending on the values of GL_TEXTURE_WRAP_S and GL_TEXTURE_WRAP_T, and on the exact mapping.
    };

    MagFilter getMagFilter(const SrcLoc& loc = SrcLoc()) const;
    void setMagFilter(const MagFilter& filter, const SrcLoc& loc = SrcLoc());

    // std::shared_future<bool> getLevelParam_iv(Vop<const Int> level, Vop<const TextureLevelParam> param, Ptr<Int> dst);
    // std::shared_future<bool> getLevelParam_fv(Vop<const Int> level, Vop<const TextureLevelParam> param, Ptr<Float> dst);
    // std::shared_future<bool> getParam_iv(Vop<const TextureParam> param, Ptr<Int> dst);
    // std::shared_future<bool> setParam_iv(Vop<const TextureParam> param, Vop<const Int> value);
    // std::shared_future<bool> getParam_fv(Vop<const TextureParam> param, Ptr<Float> dst);
    // std::shared_future<bool> setParam_fv(Vop<const TextureParam> param, Vop<const Float> value);

    // std::shared_future<bool> setActive(Vop<const UInt> index) const;
    // std::shared_future<bool> generateMipMap();

    // using Data = void*;
    // std::shared_future<bool> getImage(Vop<const Int> level, Vop<const TexturePixelFormat> fmt,
    //                                   Vop<const TexturePixelData> type, Vop<const Sizei> size, Vop<Data> data);
    // std::shared_future<bool> getSubImage(Vop<const Int> level, Vop<const TexturePixelFormat> fmt,
    //                                      Vop<const Int> x, Vop<const Int> y, Vop<const Int> z,
    //                                      Vop<const Sizei> w, Vop<const Sizei> h, Vop<const Sizei> d,
    //                                      Vop<const TexturePixelData> type, Vop<const Sizei> size, Vop<Data> data);
    // std::shared_future<bool> setSubImage1D(Vop<const Int> level,
    //                                        Vop<const Int> x, Vop<const Sizei> w,
    //                                        Vop<const TexturePixelFormat> fmt, Vop<const TexturePixelData> type,
    //                                        Vop<const Data> data);
    
    // std::shared_future<bool> setSubImage2D(Vop<const Int> level,
    //                                        Vop<const Int> x, Vop<const Int> y,
    //                                        Vop<const Sizei> w, Vop<const Sizei> h,
    //                                        Vop<const TexturePixelFormat> fmt, Vop<const TexturePixelData> type,
    //                                        Vop<const Data> data);
    
    // std::shared_future<bool> setSubImage3D(Vop<const Int> level,
    //                                        Vop<const Int> x, Vop<const Int> y, Vop<const Int> z,
    //                                        Vop<const Sizei> w, Vop<const Sizei> h, Vop<const Sizei> d,
    //                                        Vop<const TexturePixelFormat> fmt, Vop<const TexturePixelData> type,
    //                                        Vop<const Data> data);

    // =================================
    // Wrappers for Texture::setParam_iv
    // =================================

private:
    static Int _glGetParam_i(const UInt id, const Enum param);
    static void _glSetParam_i(const UInt id, const Enum param, const Int val);

};

} // namespace glwpp::gl