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

std::shared_future<bool> Texture::buffer(Vop<const gl::TextureFormat> fmt, Ptr<const Buffer> buffer){
    return _lockCtx()->onRun.push([id = _idPtr(), fmt, buffer](){
        auto &v_fmt = getVopRef(fmt);
        auto p_buffer = getPtrValue(buffer);

        glTextureBuffer(*id, static_cast<gl::Enum>(v_fmt), p_buffer->id());
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::bufferRange(Vop<const gl::TextureFormat> fmt, Ptr<const Buffer> buffer,
                                              Vop<const gl::IntPtr> offset, Vop<const gl::SizeiPtr> size){
    return _lockCtx()->onRun.push([id = _idPtr(), fmt, buffer, offset, size](){
        auto &v_fmt = getVopRef(fmt);
        auto p_buffer = getPtrValue(buffer);
        auto &v_offset = getVopRef(offset);
        auto &v_size = getVopRef(size);

        glTextureBufferRange(*id, static_cast<gl::Enum>(v_fmt), p_buffer->id(), v_offset, v_size);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::storage1D(Vop<const gl::Sizei> levels, Vop<const gl::TextureFormat> fmt,
                                            Vop<const gl::Sizei> width){
    return _lockCtx()->onRun.push([id = _idPtr(), levels, fmt, width](){
        auto &v_levels = getVopRef(levels);
        auto &v_fmt = getVopRef(fmt);
        auto &v_width = getVopRef(width);

        glTextureStorage1D(*id, v_levels, static_cast<gl::Enum>(v_fmt), v_width);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::storage2D(Vop<const gl::Sizei> levels, Vop<const gl::TextureFormat> fmt,
                                            Vop<const gl::Sizei> width, Vop<const gl::Sizei> height){
    return _lockCtx()->onRun.push([id = _idPtr(), levels, fmt, width, height](){
        auto &v_levels = getVopRef(levels);
        auto &v_fmt = getVopRef(fmt);
        auto &v_width = getVopRef(width);
        auto &v_height = getVopRef(height);

        glTextureStorage2D(*id, v_levels, static_cast<gl::Enum>(v_fmt), v_width, v_height);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::storage3D(Vop<const gl::Sizei> levels, Vop<const gl::TextureFormat> fmt,
                                            Vop<const gl::Sizei> width, Vop<const gl::Sizei> height, Vop<const gl::Sizei> depth){
    return _lockCtx()->onRun.push([id = _idPtr(), levels, fmt, width, height, depth](){
        auto &v_levels = getVopRef(levels);
        auto &v_fmt = getVopRef(fmt);
        auto &v_width = getVopRef(width);
        auto &v_height = getVopRef(height);
        auto &v_depth = getVopRef(depth);

        glTextureStorage3D(*id, v_levels, static_cast<gl::Enum>(v_fmt), v_width, v_height, v_depth);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::storageMultisample2D(Vop<const gl::Sizei> levels, Vop<const gl::TextureFormat> fmt,
                                                       Vop<const gl::Sizei> width, Vop<const gl::Sizei> height,
                                                       Vop<const gl::Bool> fixed_locations){
    return _lockCtx()->onRun.push([id = _idPtr(), levels, fmt, width, height, fixed_locations](){
        auto &v_levels = getVopRef(levels);
        auto &v_fmt = getVopRef(fmt);
        auto &v_width = getVopRef(width);
        auto &v_height = getVopRef(height);
        auto &v_fixed_locations = getVopRef(fixed_locations);

        glTextureStorage2DMultisample(*id, v_levels, static_cast<gl::Enum>(v_fmt), v_width, v_height, v_fixed_locations);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::storageMultisample3D(Vop<const gl::Sizei> levels, Vop<const gl::TextureFormat> fmt,
                                                       Vop<const gl::Sizei> width, Vop<const gl::Sizei> height, Vop<const gl::Sizei> depth,
                                                       Vop<const gl::Bool> fixed_locations){
    return _lockCtx()->onRun.push([id = _idPtr(), levels, fmt, width, height, depth, fixed_locations](){
        auto &v_levels = getVopRef(levels);
        auto &v_fmt = getVopRef(fmt);
        auto &v_width = getVopRef(width);
        auto &v_height = getVopRef(height);
        auto &v_depth = getVopRef(depth);
        auto &v_fixed_locations = getVopRef(fixed_locations);

        glTextureStorage3DMultisample(*id, v_levels, static_cast<gl::Enum>(v_fmt), v_width, v_height, v_depth, v_fixed_locations);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::getLevelParam_iv(Vop<const gl::Int> level, Vop<const gl::TextureLevelParam> param, Ptr<gl::Int> dst){
    return _lockCtx()->onRun.push([id = _idPtr(), level, param, dst](){
        auto &v_level = getVopRef(level);
        auto &v_param = getVopRef(param);
        auto p_dst = getPtrValue(dst);

        glGetTextureLevelParameteriv(*id, v_level, static_cast<gl::Enum>(v_param), p_dst);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::getLevelParam_fv(Vop<const gl::Int> level, Vop<const gl::TextureLevelParam> param, Ptr<gl::Float> dst){
    return _lockCtx()->onRun.push([id = _idPtr(), level, param, dst](){
        auto &v_level = getVopRef(level);
        auto &v_param = getVopRef(param);
        auto p_dst = getPtrValue(dst);

        glGetTextureLevelParameterfv(*id, v_level, static_cast<gl::Enum>(v_param), p_dst);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::getParam_iv(Vop<const gl::TextureParam> param, Ptr<gl::Int> dst){
    return _lockCtx()->onRun.push([id = _idPtr(), param, dst](){
        auto &v_param = getVopRef(param);
        auto p_dst = getPtrValue(dst);

        glGetTextureParameteriv(*id, static_cast<gl::Enum>(v_param), p_dst);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::setParam_iv(Vop<const gl::TextureParam> param, Vop<const gl::Int> value){
    return _lockCtx()->onRun.push([id = _idPtr(), param, value](){
        auto &v_param = getVopRef(param);
        auto &v_value = getVopRef(value);

        glTextureParameteri(*id, static_cast<gl::Enum>(v_param), v_value);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::getParam_fv(Vop<const gl::TextureParam> param, Ptr<gl::Float> dst){
    return _lockCtx()->onRun.push([id = _idPtr(), param, dst](){
        auto &v_param = getVopRef(param);
        auto p_dst = getPtrValue(dst);
        
        glGetTextureParameterfv(*id, static_cast<gl::Enum>(v_param), p_dst);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::setParam_fv(Vop<const gl::TextureParam> param, Vop<const gl::Float> value){
    return _lockCtx()->onRun.push([id = _idPtr(), param, value](){
        auto &v_param = getVopRef(param);
        auto &v_value = getVopRef(value);

        glTextureParameterf(*id, static_cast<gl::Enum>(v_param), v_value);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}


std::shared_future<bool> Texture::setActive(Vop<const gl::UInt> index) const {
    return _lockCtx()->onRun.push([id = _idPtr(), index](){
        auto &v_index = getVopRef(index);

        glBindTextureUnit(v_index, *id);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::generateMipMap(){
    return _lockCtx()->onRun.push([id = _idPtr()](){
        glGenerateTextureMipmap(*id);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::getImage(Vop<const gl::Int> level, Vop<const gl::TexturePixelFormat> fmt,
                                           Vop<const gl::TexturePixelData> type, Vop<const gl::Sizei> size, Vop<Data> dst){
    return _lockCtx()->onRun.push([id = _idPtr(), level, fmt, type, size, dst](){
        auto &v_level = getVopRef(level);
        auto &v_fmt = getVopRef(fmt);
        auto &v_type = getVopRef(type);
        auto &v_size = getVopRef(size);
        auto v_dst = getVopValue(dst);

        glGetTextureImage(*id, v_level, static_cast<gl::Enum>(v_fmt), static_cast<gl::Enum>(v_type), v_size, v_dst);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::getSubImage(Vop<const gl::Int> level, Vop<const gl::TexturePixelFormat> fmt,
                                              Vop<const gl::Int> x, Vop<const gl::Int> y, Vop<const gl::Int> z,
                                              Vop<const gl::Sizei> w, Vop<const gl::Sizei> h, Vop<const gl::Sizei> d,
                                              Vop<const gl::TexturePixelData> type, Vop<const gl::Sizei> size, Vop<Data> dst){
    return _lockCtx()->onRun.push([id = _idPtr(), level, fmt, x, y, z, w, h, d, type, size, dst](){
        auto &v_level = getVopRef(level);
        auto &v_fmt = getVopRef(fmt);
        auto &v_x = getVopRef(x);
        auto &v_y = getVopRef(y);
        auto &v_z = getVopRef(z);
        auto &v_w = getVopRef(w);
        auto &v_h = getVopRef(h);
        auto &v_d = getVopRef(d);
        auto &v_type = getVopRef(type);
        auto &v_size = getVopRef(size);
        auto v_dst = getVopValue(dst);

        glGetTextureSubImage(*id, v_level, static_cast<gl::Enum>(v_fmt), v_x, v_y, v_z, v_w, v_h, v_d, static_cast<gl::Enum>(v_type), v_size, v_dst);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::setSubImage1D(Vop<const gl::Int> level,
                                                Vop<const gl::Int> x, Vop<const gl::Sizei> w,
                                                Vop<const gl::TexturePixelFormat> fmt, Vop<const gl::TexturePixelData> type,
                                                Vop<const Data> data){
    return _lockCtx()->onRun.push([id = _idPtr(), level, x, w, fmt, type, data](){
        auto &v_level = getVopRef(level);
        auto &v_x = getVopRef(x);
        auto &v_w = getVopRef(w);
        auto &v_fmt = getVopRef(fmt);
        auto &v_type = getVopRef(type);
        auto &v_data = getVopRef(data);

        glTextureSubImage1D(*id, v_level, v_x, v_w, static_cast<gl::Enum>(v_fmt), static_cast<gl::Enum>(v_type), v_data);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::setSubImage2D(Vop<const gl::Int> level,
                                                Vop<const gl::Int> x, Vop<const gl::Int> y, Vop<const gl::Sizei> w, Vop<const gl::Sizei> h,
                                                Vop<const gl::TexturePixelFormat> fmt, Vop<const gl::TexturePixelData> type,
                                                Vop<const Data> data){
    return _lockCtx()->onRun.push([id = _idPtr(), level, x, y, w, h, fmt, type, data](){
        auto &v_level = getVopRef(level);
        auto &v_x = getVopRef(x);
        auto &v_y = getVopRef(y);
        auto &v_w = getVopRef(w);
        auto &v_h = getVopRef(h);
        auto &v_fmt = getVopRef(fmt);
        auto &v_type = getVopRef(type);
        auto &v_data = getVopRef(data);
        
        glTextureSubImage2D(*id, v_level, v_x, v_y, v_w, v_h, static_cast<gl::Enum>(v_fmt), static_cast<gl::Enum>(v_type), v_data);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> Texture::setSubImage3D(Vop<const gl::Int> level,
                                                Vop<const gl::Int> x, Vop<const gl::Int> y, Vop<const gl::Int> z, Vop<const gl::Sizei> w, Vop<const gl::Sizei> h, Vop<const gl::Sizei> d,
                                                Vop<const gl::TexturePixelFormat> fmt, Vop<const gl::TexturePixelData> type,
                                                Vop<const Data> data){
    return _lockCtx()->onRun.push([id = _idPtr(), level, x, y, z, w, h, d, fmt, type, data](){
        auto &v_level = getVopRef(level);
        auto &v_x = getVopRef(x);
        auto &v_y = getVopRef(y);
        auto &v_z = getVopRef(z);
        auto &v_w = getVopRef(w);
        auto &v_h = getVopRef(h);
        auto &v_d = getVopRef(d);
        auto &v_fmt = getVopRef(fmt);
        auto &v_type = getVopRef(type);
        auto &v_data = getVopRef(data);

        glTextureSubImage3D(*id, v_level, v_x, v_y, v_z, v_w, v_h, v_d, static_cast<gl::Enum>(v_fmt), static_cast<gl::Enum>(v_type), v_data);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}