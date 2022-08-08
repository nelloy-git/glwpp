#pragma once

#include "glwpp/gl/enums/TextureBufferFormat.hpp"
#include "glwpp/gl/enums/TextureType.hpp"
#include "glwpp/gl/enums/TextureParam.hpp"
#include "glwpp/gl/enums/TexturePixelData.hpp"
#include "glwpp/gl/enums/TexturePixelFormat.hpp"
#include "glwpp/gl/obj/Buffer.hpp"
#include "glwpp/gl/obj/Object.hpp"

namespace glwpp::gl {

class Texture : public Object {
public:
    static sptr<Texture> make(const sptr<Context>& ctx, const Val<const TextureType>& type,
                              const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

    bool buffer(const Val<const Buffer>& buffer, const Val<const TextureFormat>& fmt, 
                const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool bufferRange(const Val<const Buffer>& buffer, const Val<const TextureFormat>& fmt, 
                     const Val<const IntPtr>& offset, const Val<const SizeiPtr>& size,
                     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool storage1D(const Val<const Sizei>& levels, const Val<const TextureFormat>& fmt,
                   const Val<const Sizei>& width,
                   const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool storage2D(const Val<const Sizei>& levels, const Val<const TextureFormat>& fmt,
                   const Val<const Sizei>& width, const Val<const Sizei>& height,
                   const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool storage3D(const Val<const Sizei>& levels, const Val<const TextureFormat>& fmt,
                   const Val<const Sizei>& width, const Val<const Sizei>& height, const Val<const Sizei>& depth,
                   const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool storageMultisample2D(const Val<const Sizei>& samples, const Val<const TextureFormat>& fmt,
                              const Val<const Sizei>& width, const Val<const Sizei>& height,
                              const Val<const Bool>& fixed_locations,
                              const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    bool storageMultisample3D(const Val<const Sizei>& samples, const Val<const TextureFormat>& fmt,
                              const Val<const Sizei>& width, const Val<const Sizei>& height, const Val<const Sizei>& depth,
                              const Val<const Bool>& fixed_locations,
                              const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

    bool setUnit(const Val<const UInt>& index,
                 const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool generateMipMap(const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

    bool getImage(const Val<void>& dst, const Val<const Int>& level, const Val<const TexturePixelFormat>& fmt,
                  const Val<const TexturePixelData>& type, const Val<const Sizei>& size,
                  const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool getSubImage(const Val<void>& dst, 
                     const Val<const Int>& level, const Val<const TexturePixelFormat>& fmt,
                     const Val<const Int>& x, const Val<const Int>& y, const Val<const Int>& z,
                     const Val<const Sizei>& w, const Val<const Sizei>& h, const Val<const Sizei>& d,
                     const Val<const TexturePixelData>& type, const Val<const Sizei>& size,
                     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;

    bool setSubImage1D(const Val<const void>& data,
                       const Val<const Int>& level,
                       const Val<const Int>& x, const Val<const Sizei>& w,
                       const Val<const TexturePixelFormat>& fmt, const Val<const TexturePixelData>& type,
                       const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    
    bool setSubImage2D(const Val<const void>& data,
                       const Val<const Int>& level,
                       const Val<const Int>& x, const Val<const Int>& y,
                       const Val<const Sizei>& w, const Val<const Sizei>& h,
                       const Val<const TexturePixelFormat>& fmt, const Val<const TexturePixelData>& type,
                       const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    
    bool setSubImage3D(const Val<const void>& data,
                       const Val<const Int>& level,
                       const Val<const Int>& x, const Val<const Int>& y, const Val<const Int>& z,
                       const Val<const Sizei>& w, const Val<const Sizei>& h, const Val<const Sizei>& d,
                       const Val<const TexturePixelFormat>& fmt, const Val<const TexturePixelData>& type,
                       const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

    bool getParamInt(const Val<Int>& dst, const Val<const Enum>& param,
                     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool setParamInt(const Val<const Int>& value, const Val<const Enum>& param,
                     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

    enum class Wrap : Int {
        Clamp = 0x812F,  // GL_CLAMP_TO_EDGE,
        Mirror = 0x8370, // GL_MIRRORED_REPEAT,
        Repeat = 0x2901, // GL_REPEAT
    };

    bool getWrapS(const Val<Wrap> dst,
                  const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool setWrapS(const Val<const Wrap> value,
                  const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

    bool getWrapT(const Val<Wrap> dst,
                  const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool setWrapT(const Val<const Wrap> value,
                  const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

    enum class  MinFilter : Int {
        Nearest = 0x2600, // GL_NEAREST Returns the value of the texture element that is nearest (in Manhattan distance) to the specified texture coordinates.
        Linear = 0x2601, // GL_LINEAR Returns the weighted average of the four texture elements that are closest to the specified texture coordinates. These can include items wrapped or repeated from other parts of a texture, depending on the values of GL_TEXTURE_WRAP_S and GL_TEXTURE_WRAP_T, and on the exact mapping.
        NearestMipMapNearest = 0x2700, // GL_NEAREST_MIPMAP_NEAREST Chooses the mipmap that most closely matches the size of the pixel being textured and uses the GL_NEAREST criterion (the texture element closest to the specified texture coordinates) to produce a texture value.
        LinearMipmapNearest = 0x2701, // GL_LINEAR_MIPMAP_NEAREST Chooses the mipmap that most closely matches the size of the pixel being textured and uses the GL_LINEAR criterion (a weighted average of the four texture elements that are closest to the specified texture coordinates) to produce a texture value.
        NearestMipMapLinear = 0x2702, // GL_NEAREST_MIPMAP_LINEAR Chooses the two mipmaps that most closely match the size of the pixel being textured and uses the GL_NEAREST criterion (the texture element closest to the specified texture coordinates ) to produce a texture value from each mipmap. The final texture value is a weighted average of those two values.
        LinearMipMapLinear = 0x2703, // GL_LINEAR_MIPMAP_LINEAR Chooses the two mipmaps that most closely match the size of the pixel being textured and uses the GL_LINEAR criterion (a weighted average of the texture elements that are closest to the specified texture coordinates) to produce a texture value from each mipmap. The final texture value is a weighted average of those two values. 
    };

    bool getMinFilter(const Val<MinFilter> dst,
                      const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool setMinFilter(const Val<const MinFilter> value,
                      const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
                      
    enum class  MagFilter : Int {
        Nearest = 0x2600, // GL_NEAREST Returns the value of the texture element that is nearest (in Manhattan distance) to the specified texture coordinates.
        Linear = 0x2601, // GL_LINEAR Returns the weighted average of the four texture elements that are closest to the specified texture coordinates. These can include items wrapped or repeated from other parts of a texture, depending on the values of GL_TEXTURE_WRAP_S and GL_TEXTURE_WRAP_T, and on the exact mapping.
    };

    bool getMagFilter(const Val<MagFilter> dst,
                      const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const;
    bool setMagFilter(const Val<const MagFilter> value,
                      const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

protected:
    Texture(const sptr<Context>& ctx, const Val<const TextureType>& type,
            const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});

private:
    // Hide parent's make
    using Object::make;

    static void _initer(const Val<UInt>& dst, const Val<const TextureType>& type,
                        const Val<const utils::SrcLoc>& src_loc);
    static void _deleter(const UInt& id);
};

} // namespace glwpp