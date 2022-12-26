#pragma once

#include "gl_object/Object.hpp"
#include "gl_object/Buffer.hpp"

namespace glwpp {

namespace GL {

class TextureBase : public ObjectRef {
public:
    EXPORT ~TextureBase();

    EXPORT void setBuffer(const Enum& internalformat, const BufferBase& buffer, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setBufferRange(const Enum& internalformat, const BufferBase& buffer, const Intptr& offset, const Sizeiptr& size, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setStorage1D(const Sizei& levels, const Enum& internalformat, const Sizei& width, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setStorage2D(const Sizei& levels, const Enum& internalformat, const Sizei& width, const Sizei& height, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setStorage3D(const Sizei& levels, const Enum& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setStorageMultisample2D(const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const Boolean& fixed_locations, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setStorageMultisample3D(const Sizei& samples, const Enum& internalformat, const Sizei& width, const Sizei& height, const Sizei& depth, const Boolean& fixed_locations, const SrcLoc& src_loc = SrcLoc{});

    EXPORT void bindUnit(const Uint& unit, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void generateMipMap(const SrcLoc& src_loc = SrcLoc{});
    EXPORT void getImage(const Int& level, const Enum& format, const Enum& type, const Sizei& buf_size, const Data& dst, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void getSubImage(const Int& level, const Int& xoffset, const Int& yoffset, const Int& zoffset, const Sizei& w, const Sizei& h, const Sizei& d, const Enum& format, const Enum& type, const Sizei& buf_size, const Data& dst, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setSubImage1D(const Int& level, const Int& x, const Sizei& w, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setSubImage2D(const Int& level, const Int& x, const Int& y, const Sizei& w, const Sizei& h, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setSubImage3D(const Int& level, const Int& x, const Int& y, const Int& z, const Sizei& w, const Sizei& h, const Sizei& d, const Enum& format, const Enum& type, const Data& pixels, const SrcLoc& src_loc = SrcLoc{});

    EXPORT Enum getWrapS(const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setWrapS(const Enum& value, const SrcLoc& src_loc = SrcLoc{});
    EXPORT Enum getWrapT(const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setWrapT(const Enum& value, const SrcLoc& src_loc = SrcLoc{});
    EXPORT Enum getMinFilter(const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setMinFilter(const Enum& value, const SrcLoc& src_loc = SrcLoc{});
    EXPORT Enum getMagFilter(const SrcLoc& src_loc = SrcLoc{});
    EXPORT void setMagFilter(const Enum& value, const SrcLoc& src_loc = SrcLoc{});

protected:
    TextureBase(Context& ctx, const Enum& type, const SrcLoc& src_loc);

};

class Texture : public TextureBase, public SharedObject<Texture> {
public:
    EXPORT static std::shared_ptr<Texture> New(Context& ctx, const Enum& type, const SrcLoc& src_loc = SrcLoc{}){
        return std::shared_ptr<Texture>(new Texture(ctx, type, src_loc));
    }

protected:
    Texture(Context& ctx, const Enum& type, const SrcLoc& src_loc) : 
        TextureBase(ctx, type, src_loc){
    }
};

} // namespace GL

} // namespace glwpp