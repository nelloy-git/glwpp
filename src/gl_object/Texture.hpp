#pragma once

#include "gl_object/Object.hpp"
#include "gl_object/Buffer.hpp"

namespace glwpp {

namespace GL {

class Texture : public Object {
public:
    Texture(const std::shared_ptr<Context>& ctx, const Enum& type, const SrcLoc& src_loc = SrcLoc{});
    Texture(const Texture&) = delete;
    Texture(const Texture&&) = delete;
    ~Texture();

    void setBuffer(const Buffer& buffer, const Enum& fmt, const SrcLoc& src_loc = SrcLoc{});
    void setBufferRange(const Buffer& buffer, const Enum& fmt, const Intptr& offset, const Sizeiptr& size, const SrcLoc& src_loc = SrcLoc{});
    void setStorage1D(const Sizei& levels, const Enum& fmt, const Sizei& width, const SrcLoc& src_loc = SrcLoc{});
    void setStorage2D(const Sizei& levels, const Enum& fmt, const Sizei& width, const Sizei& height, const SrcLoc& src_loc = SrcLoc{});
    void setStorage3D(const Sizei& levels, const Enum& fmt, const Sizei& width, const Sizei& height, const Sizei& depth, const SrcLoc& src_loc = SrcLoc{});
    void setStorageMultisample2D(const Sizei& samples, const Enum& fmt, const Sizei& width, const Sizei& height, const Boolean& fixed_locations, const SrcLoc& src_loc = SrcLoc{});
    void setStorageMultisample3D(const Sizei& samples, const Enum& fmt, const Sizei& width, const Sizei& height, const Sizei& depth, const Boolean& fixed_locations, const SrcLoc& src_loc = SrcLoc{});

    void setUnit(const Uint& index, const SrcLoc& src_loc = SrcLoc{});
    void generateMipMap(const SrcLoc& src_loc = SrcLoc{});
    void getImage(const Data& dst, const Int& level, const Enum& fmt, const Enum& type, const Sizei& buf_size, const SrcLoc& src_loc = SrcLoc{});
    void getSubImage(const Data& dst, const Int& level, const Enum& fmt, const Int& x, const Int& y, const Int& z, const Sizei& w, const Sizei& h, const Sizei& d, const Enum& type, const Sizei& buf_size, const SrcLoc& src_loc = SrcLoc{});
    void setSubImage1D(const Data& data, const Int& level, const Int& x, const Sizei& w, const Enum& fmt, const Enum& type, const SrcLoc& src_loc = SrcLoc{});
    void setSubImage2D(const Data& data, const Int& level, const Int& x, const Int& y, const Sizei& w, const Sizei& h, const Enum& fmt, const Enum& type, const SrcLoc& src_loc = SrcLoc{});
    void setSubImage1D(const Data& data, const Int& level, const Int& x, const Int& y, const Int& z, const Sizei& w, const Sizei& h, const Sizei& d, const Enum& fmt, const Enum& type, const SrcLoc& src_loc = SrcLoc{});

    Enum getWrapS(const SrcLoc& src_loc = SrcLoc{});
    void setWrapS(const Enum& value, const SrcLoc& src_loc = SrcLoc{});
    Enum getWrapT(const SrcLoc& src_loc = SrcLoc{});
    void setWrapT(const Enum& value, const SrcLoc& src_loc = SrcLoc{});
    Enum getMinFilter(const SrcLoc& src_loc = SrcLoc{});
    void setMinFilter(const Enum& value, const SrcLoc& src_loc = SrcLoc{});
    Enum getMagFilter(const SrcLoc& src_loc = SrcLoc{});
    void setMagFilter(const Enum& value, const SrcLoc& src_loc = SrcLoc{});
};

} // namespace GL

} // namespace glwpp