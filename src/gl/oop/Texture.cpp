#include "glwpp/gl/oop/Texture.hpp"

#include "glad/gl.h"

using namespace glwpp;

namespace {
    static gl::UInt CreateTexture(gl::TextureType type){
        gl::UInt id;
        glCreateTextures(static_cast<gl::Enum>(type), 1, &id);
        return id;
    }
    static void DeleteTexture(gl::UInt *id){
        glDeleteTextures(1, id);
        delete id;
    }
}

Texture::Texture(wptr<Context> ctx, gl::TextureType type) : 
    ContextData(ctx, &CreateTexture, &DeleteTexture, type){
}

Texture::Texture(const Texture &&other) :
    ContextData(std::move(other)){
}

Texture::~Texture(){
}

std::shared_future<bool> Texture::buffer(sptr<gl::TextureFormat> fmt, sptr<Buffer> buffer){
    if constexpr (AUTOCLEAR) _clear(fmt, buffer);
    return _lockCtx()->onRun.push([id = idPtr(), fmt, buffer_id = buffer->idPtr()](){
        glTextureBuffer(*id, static_cast<gl::Enum>(*fmt), *buffer_id);
    });
}

std::shared_future<bool> Texture::bufferRange(sptr<gl::TextureFormat> fmt, sptr<Buffer> buffer,
                                              sptr<gl::IntPtr> offset, sptr<gl::SizeiPtr> size){
    if constexpr (AUTOCLEAR) _clear(fmt, buffer, offset, size);
    return _lockCtx()->onRun.push([id = idPtr(), fmt, buffer_id = buffer->idPtr(), offset, size](){
        glTextureBufferRange(*id, static_cast<gl::Enum>(*fmt), *buffer_id, *offset, *size);
    });
}

std::shared_future<bool> Texture::storage1D(sptr<gl::Sizei> levels, sptr<gl::TextureFormat> fmt,
                                            sptr<gl::Sizei> width){
    if constexpr (AUTOCLEAR) _clear(levels, fmt, width);
    return _lockCtx()->onRun.push([id = idPtr(), levels, fmt, width](){
        glTextureStorage1D(*id, *levels, static_cast<gl::Enum>(*fmt), *width);
    });
}

std::shared_future<bool> Texture::storage2D(sptr<gl::Sizei> levels, sptr<gl::TextureFormat> fmt,
                                            sptr<gl::Sizei> width, sptr<gl::Sizei> height){
    if constexpr (AUTOCLEAR) _clear(levels, fmt, width, height);
    return _lockCtx()->onRun.push([id = idPtr(), levels, fmt, width, height](){
        glTextureStorage2D(*id, *levels, static_cast<gl::Enum>(*fmt), *width, *height);
    });
}

std::shared_future<bool> Texture::storage3D(sptr<gl::Sizei> levels, sptr<gl::TextureFormat> fmt,
                                            sptr<gl::Sizei> width, sptr<gl::Sizei> height, sptr<gl::Sizei> depth){
    if constexpr (AUTOCLEAR) _clear(levels, fmt, width, height, depth);
    return _lockCtx()->onRun.push([id = idPtr(), levels, fmt, width, height, depth](){
        glTextureStorage3D(*id, *levels, static_cast<gl::Enum>(*fmt), *width, *height, *depth);
    });
}

std::shared_future<bool> Texture::storageMultisample2D(sptr<gl::Sizei> levels, sptr<gl::TextureFormat> fmt,
                                                       sptr<gl::Sizei> width, sptr<gl::Sizei> height,
                                                       sptr<gl::Bool> fixed_locations){
    if constexpr (AUTOCLEAR) _clear(levels, fmt, width, height, fixed_locations);
    return _lockCtx()->onRun.push([id = idPtr(), levels, fmt, width, height, fixed_locations](){
        glTextureStorage2DMultisample(*id, *levels, static_cast<gl::Enum>(*fmt), *width, *height, *fixed_locations);
    });
}

std::shared_future<bool> Texture::storageMultisample3D(sptr<gl::Sizei> levels, sptr<gl::TextureFormat> fmt,
                                                       sptr<gl::Sizei> width, sptr<gl::Sizei> height, sptr<gl::Sizei> depth,
                                                       sptr<gl::Bool> fixed_locations){
    if constexpr (AUTOCLEAR) _clear(levels, fmt, width, height, depth, fixed_locations);
    return _lockCtx()->onRun.push([id = idPtr(), levels, fmt, width, height, depth, fixed_locations](){
        glTextureStorage3DMultisample(*id, *levels, static_cast<gl::Enum>(*fmt), *width, *height, *depth, *fixed_locations);
    });
}

std::shared_future<bool> Texture::getLevelParam_iv(sptr<gl::Int> level, sptr<gl::TextureLevelParam> param, sptr<gl::Int> dst){
    if constexpr (AUTOCLEAR) _clear(level, param, dst);
    return _lockCtx()->onRun.push([id = idPtr(), level, param, dst](){
        glGetTextureLevelParameteriv(*id, *level, static_cast<gl::Enum>(*param), dst.get());
    });
}

std::shared_future<bool> Texture::getLevelParam_fv(sptr<gl::Int> level, sptr<gl::TextureLevelParam> param, sptr<gl::Float> dst){
    if constexpr (AUTOCLEAR) _clear(level, param, dst);
    return _lockCtx()->onRun.push([id = idPtr(), level, param, dst](){
        glGetTextureLevelParameterfv(*id, *level, static_cast<gl::Enum>(*param), dst.get());
    });
}

std::shared_future<bool> Texture::getParam_iv(sptr<gl::TextureParam> param, sptr<gl::Int> dst){
    if constexpr (AUTOCLEAR) _clear(param, dst);
    return _lockCtx()->onRun.push([id = idPtr(), param, dst](){
        glGetTextureParameteriv(*id, static_cast<gl::Enum>(*param), dst.get());
    });
}

std::shared_future<bool> Texture::setParam_iv(sptr<gl::TextureParam> param, sptr<gl::Int> value){
    if constexpr (AUTOCLEAR) _clear(param, value);
    return _lockCtx()->onRun.push([id = idPtr(), param, value](){
        glTextureParameteri(*id, static_cast<gl::Enum>(*param), *value);
    });
}

std::shared_future<bool> Texture::getParam_fv(sptr<gl::TextureParam> param, sptr<gl::Float> dst){
    if constexpr (AUTOCLEAR) _clear(param, dst);
    return _lockCtx()->onRun.push([id = idPtr(), param, dst](){
        glGetTextureParameterfv(*id, static_cast<gl::Enum>(*param), dst.get());
    });
}

std::shared_future<bool> Texture::setParam_fv(sptr<gl::TextureParam> param, sptr<gl::Float> value){
    if constexpr (AUTOCLEAR) _clear(param, value);
    return _lockCtx()->onRun.push([id = idPtr(), param, value](){
        glTextureParameterf(*id, static_cast<gl::Enum>(*param), *value);
    });
}


std::shared_future<bool> Texture::setActive(sptr<gl::UInt> index) const {
    if constexpr (AUTOCLEAR) _clear(index);
    return _lockCtx()->onRun.push([id = idPtr(), index](){
        glBindTextureUnit(*index, *id);
    });
}

std::shared_future<bool> Texture::generateMipMap(){
    return _lockCtx()->onRun.push([id = idPtr()](){
        glGenerateTextureMipmap(*id);
    });
}

std::shared_future<bool> Texture::getImage(sptr<gl::Int> level, sptr<gl::TexturePixelFormat> fmt,
                                           sptr<gl::TexturePixelData> type, sptr<gl::Sizei> size, sptr<void> data){
    if constexpr (AUTOCLEAR) _clear(level, fmt, type, size, data);
    return _lockCtx()->onRun.push([id = idPtr(), level, fmt, type, size, data](){
        glGetTextureImage(*id, *level, static_cast<gl::Enum>(*fmt), static_cast<gl::Enum>(*type), *size, data.get());
    });
}

std::shared_future<bool> Texture::getSubImage(sptr<gl::Int> level, sptr<gl::TexturePixelFormat> fmt,
                                              sptr<gl::Int> x, sptr<gl::Int> y, sptr<gl::Int> z,
                                              sptr<gl::Sizei> w, sptr<gl::Sizei> h, sptr<gl::Sizei> d,
                                              sptr<gl::TexturePixelData> type, sptr<gl::Sizei> size, sptr<void> data){
    if constexpr (AUTOCLEAR) _clear(level, fmt, x, y, z, w, h, d, type, size, data);
    return _lockCtx()->onRun.push([id = idPtr(), level, fmt, x, y, z, w, h, d, type, size, data](){
        glGetTextureSubImage(*id, *level, static_cast<gl::Enum>(*fmt), *x, *y, *z, *w, *h, *d, static_cast<gl::Enum>(*type), *size, data.get());
    });
}

std::shared_future<bool> Texture::setSubImage1D(sptr<gl::Int> level,
                                                sptr<gl::Int> x, sptr<gl::Sizei> w,
                                                sptr<gl::TexturePixelFormat> fmt, sptr<gl::TexturePixelData> type,
                                                sptr<const void> data){
    if constexpr (AUTOCLEAR) _clear(level, x, w, fmt, type, data);
    return _lockCtx()->onRun.push([id = idPtr(), level, x, w, fmt, type, data](){
        glTextureSubImage1D(*id, *level, *x, *w, static_cast<gl::Enum>(*fmt), static_cast<gl::Enum>(*type), data.get());
    });
}

std::shared_future<bool> Texture::setSubImage2D(sptr<gl::Int> level,
                                                sptr<gl::Int> x, sptr<gl::Int> y, sptr<gl::Sizei> w, sptr<gl::Sizei> h,
                                                sptr<gl::TexturePixelFormat> fmt, sptr<gl::TexturePixelData> type,
                                                sptr<const void> data){
    if constexpr (AUTOCLEAR) _clear(level, x, y, w, h, fmt, type, data);
    return _lockCtx()->onRun.push([id = idPtr(), level, x, y, w, h, fmt, type, data](){
        glTextureSubImage2D(*id, *level, *x, *y, *w, *h, static_cast<gl::Enum>(*fmt), static_cast<gl::Enum>(*type), data.get());
    });
}

std::shared_future<bool> Texture::setSubImage3D(sptr<gl::Int> level,
                                                sptr<gl::Int> x, sptr<gl::Int> y, sptr<gl::Int> z, sptr<gl::Sizei> w, sptr<gl::Sizei> h, sptr<gl::Sizei> d,
                                                sptr<gl::TexturePixelFormat> fmt, sptr<gl::TexturePixelData> type,
                                                sptr<const void> data){
    if constexpr (AUTOCLEAR) _clear(level, x, y, z, w, h, d, fmt, type, data);
    return _lockCtx()->onRun.push([id = idPtr(), level, x, y, z, w, h, d, fmt, type, data](){
        glTextureSubImage3D(*id, *level, *x, *y, *z, *w, *h, *d, static_cast<gl::Enum>(*fmt), static_cast<gl::Enum>(*type), data.get());
    });
}