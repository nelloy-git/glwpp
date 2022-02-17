#include "glwpp/gl/object/CtxTexture.hpp"

#include <unordered_map>

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;

namespace {
static UInt* CreateTexture(const TextureType& type, const SrcLoc& loc){
    auto id = new UInt;
    glCreateTextures(static_cast<Enum>(type), 1, id);
    CtxObject::printDebug(loc);
    return id;
}
static void DeleteTexture(UInt *id, bool is_init_thread){
    if (is_init_thread && glIsTexture(*id)){
        glDeleteTextures(1, id);
    }
    delete id;
}
static Int GetParamI(UInt id, Enum param, const SrcLoc& loc){
    Int dst;
    glGetTextureParameteriv(id, param, &dst);
    CtxObject::printDebug(loc);
    return dst;
}
static void SetParamI(UInt id, Enum param, Int val, const SrcLoc& loc){
    glTextureParameteri(id, param, val);
    CtxObject::printDebug(loc);
}
}

CtxTexture::CtxTexture(const TextureType& type, const SrcLoc& loc) :
    CtxObject(&CreateTexture, &DeleteTexture, type, loc){
}

void CtxTexture::buffer(const TextureFormat& fmt, const CtxBuffer& buffer, const SrcLoc& loc){
    glTextureBuffer(getId(), static_cast<Enum>(fmt), buffer.getId());
    CtxObject::printDebug(loc);
}

void CtxTexture::bufferRange(const TextureFormat& fmt, const CtxBuffer& buffer,
                             const IntPtr& offset, const SizeiPtr& size, const SrcLoc& loc){
    glTextureBufferRange(getId(), static_cast<Enum>(fmt), buffer.getId(), offset, size);
    CtxObject::printDebug(loc);
}

void CtxTexture::storage1D(const Sizei& levels, const TextureFormat& fmt,
                           const Sizei& width, const SrcLoc& loc){
    glTextureStorage1D(getId(), levels, static_cast<Enum>(fmt), width);
    CtxObject::printDebug(loc);
}

void CtxTexture::storage2D(const Sizei& levels, const TextureFormat& fmt,
                           const Sizei& width, const Sizei& height, const SrcLoc& loc){
    glTextureStorage2D(getId(), levels, static_cast<Enum>(fmt), width, height);
    CtxObject::printDebug(loc);
}

void CtxTexture::storage3D(const Sizei& levels, const TextureFormat& fmt,
                           const Sizei& width, const Sizei& height, const Sizei& depth, const SrcLoc& loc){
    glTextureStorage3D(getId(), levels, static_cast<Enum>(fmt), width, height, depth);
    CtxObject::printDebug(loc);
}

void CtxTexture::storageMultisample2D(const Sizei& samples, const TextureFormat& fmt,
                            const Sizei& width, const Sizei& height,
                            const Bool& fixed_locations, const SrcLoc& loc){
    glTextureStorage2DMultisample(getId(), samples, static_cast<Enum>(fmt), width, height, fixed_locations);
    CtxObject::printDebug(loc);
}

void CtxTexture::storageMultisample3D(const Sizei& samples, const TextureFormat& fmt,
                                      const Sizei& width, const Sizei& height, const Sizei& depth,
                                      const Bool& fixed_locations, const SrcLoc& loc){
    glTextureStorage3DMultisample(getId(), samples, static_cast<Enum>(fmt), width, height, depth, fixed_locations);
    CtxObject::printDebug(loc);
}

void CtxTexture::setUnit(const UInt& index, const SrcLoc& loc) const {
    glBindTextureUnit(index, getId());
    CtxObject::printDebug(loc);
}

void CtxTexture::generateMipMap(const SrcLoc& loc){
    glGenerateTextureMipmap(getId());
    CtxObject::printDebug(loc);
}


void CtxTexture::getImage(const Int& level, const TexturePixelFormat& fmt,
                const TexturePixelData& type, const Sizei& size, Data data, const SrcLoc& loc){
    glGetTextureImage(getId(), level, static_cast<Enum>(fmt), static_cast<Enum>(type), size, data);
    CtxObject::printDebug(loc);
}

void CtxTexture::getSubImage(const Int& level, const TexturePixelFormat& fmt,
                             const Int& x, const Int& y, const Int& z,
                             const Sizei& w, const Sizei& h, const Sizei& d,
                             const TexturePixelData& type, const Sizei& size, Data data, const SrcLoc& loc){
    glGetTextureSubImage(getId(), level, x, y, z, w, h, d, static_cast<Enum>(fmt), static_cast<Enum>(type), size, data);
    CtxObject::printDebug(loc);
}

void CtxTexture::setSubImage1D(const Int& level,
                    const Int& x, const Sizei& w,
                    const TexturePixelFormat& fmt, const TexturePixelData& type,
                    const Data data, const SrcLoc& loc){
    glTextureSubImage1D(getId(), level, x, w, static_cast<Enum>(fmt), static_cast<Enum>(type), data);
    CtxObject::printDebug(loc);
}

void CtxTexture::setSubImage2D(const Int& level,
                               const Int& x, const Int& y,
                               const Sizei& w, const Sizei& h,
                               const TexturePixelFormat& fmt, const TexturePixelData& type,
                               const Data data, const SrcLoc& loc){
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTextureSubImage2D(getId(), level, x, y, w, h, static_cast<Enum>(fmt), static_cast<Enum>(type), data);
    CtxObject::printDebug(loc);
}

void CtxTexture::setSubImage3D(const Int& level,
                    const Int& x, const Int& y, const Int& z,
                    const Sizei& w, const Sizei& h, const Sizei& d,
                    const TexturePixelFormat& fmt, const TexturePixelData& type,
                    const Data data, const SrcLoc& loc){
    glTextureSubImage3D(getId(), level, x, y, z, w, h, d, static_cast<Enum>(fmt), static_cast<Enum>(type), data);
    CtxObject::printDebug(loc);
}


CtxTexture::Wrap CtxTexture::getWrapS(const SrcLoc& loc) const {
    return static_cast<Wrap>(GetParamI(getId(), GL_TEXTURE_WRAP_S, loc));
}

void CtxTexture::setWrapS(const Wrap& wrap, const SrcLoc& loc){
    SetParamI(getId(), GL_TEXTURE_WRAP_S, static_cast<Int>(wrap), loc);
}

CtxTexture::Wrap CtxTexture::getWrapT(const SrcLoc& loc) const {
    return static_cast<Wrap>(GetParamI(getId(), GL_TEXTURE_WRAP_T, loc));

}

void CtxTexture::setWrapT(const Wrap& wrap, const SrcLoc& loc){
    SetParamI(getId(), GL_TEXTURE_WRAP_T, static_cast<Int>(wrap), loc);
}

CtxTexture::MinFilter CtxTexture::getMinFilter(const SrcLoc& loc) const {
    return static_cast<MinFilter>(GetParamI(getId(), GL_TEXTURE_MIN_FILTER, loc));
}

void CtxTexture::setMinFilter(const MinFilter& filter, const SrcLoc& loc){
    SetParamI(getId(), GL_TEXTURE_MIN_FILTER, static_cast<Int>(filter), loc);
}

CtxTexture::MagFilter CtxTexture::getMagFilter(const SrcLoc& loc) const {
    return static_cast<MagFilter>(GetParamI(getId(), GL_TEXTURE_MAG_FILTER, loc));
}

void CtxTexture::setMagFilter(const MagFilter& filter, const SrcLoc& loc){
    SetParamI(getId(), GL_TEXTURE_MAG_FILTER, static_cast<Int>(filter), loc);
}
