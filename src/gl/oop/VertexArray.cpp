#include "glwpp/gl/oop/VertexArray.hpp"

#include "glad/gl.h"

using namespace glwpp;

namespace {
    static gl::UInt CreateVertexArray(){
        gl::UInt id;
        glCreateVertexArrays(1, &id);
        return id;
    }
    static void DeleteVertexArray(gl::UInt *id){
        glDeleteVertexArrays(1, id);
        delete id;
    }
};

VertexArray::VertexArray(wptr<Context> ctx) : 
    ContextData(ctx, &CreateVertexArray, &DeleteVertexArray){
}

VertexArray::VertexArray(const VertexArray &&other) :
    ContextData(std::move(other)){
}

VertexArray::~VertexArray(){
}

std::shared_future<bool> VertexArray::getAttribParam_i64v(Vop<const gl::UInt> index,
                                                          Vop<const gl::VertexArrayAttribParam> param,
                                                          Ptr<gl::Int64> dst){
    return _lockCtx()->onRun.push([id = _idPtr(), index, param, dst](){
        auto &v_index = getVopRef(index);
        auto &v_param = getVopRef(param);
        auto p_dst = getPtrValue(dst);

        glGetVertexArrayIndexed64iv(*id, v_index, static_cast<gl::Enum>(v_param), p_dst);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> VertexArray::getAttribParam_iv(Vop<const gl::UInt> index,
                                                        Vop<const gl::VertexArrayAttribParam> param,
                                                        Ptr<gl::Int> dst){
    return _lockCtx()->onRun.push([id = _idPtr(), index, param, dst](){
        auto &v_index = getVopRef(index);
        auto &v_param = getVopRef(param);
        auto p_dst = getPtrValue(dst);

        glGetVertexArrayIndexediv(*id, v_index, static_cast<gl::Enum>(v_param), p_dst);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> VertexArray::enableAttrib(Vop<const gl::UInt> index){
    return _lockCtx()->onRun.push([id = _idPtr(), index](){
        auto &v_index = getVopRef(index);

        glEnableVertexArrayAttrib(*id, v_index);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> VertexArray::disableAttrib(Vop<const gl::UInt> index){
    return _lockCtx()->onRun.push([id = _idPtr(), index](){
        auto &v_index = getVopRef(index);

        glDisableVertexArrayAttrib(*id, v_index);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> VertexArray::setAttribBinding(Vop<const gl::UInt> index, Vop<const gl::UInt> binding_index){
    return _lockCtx()->onRun.push([id = _idPtr(), index, binding_index](){
        auto &v_index = getVopRef(index);
        auto &v_binding_index = getVopRef(binding_index);

        glVertexArrayAttribBinding(*id, v_index, v_binding_index);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> VertexArray::setAttribFormat(Vop<const gl::UInt> index, Vop<const gl::Int> size,
                                                      Vop<const gl::DataType> type, Vop<const gl::Bool> normalized,
                                                      Vop<const gl::UInt> relative_offset){
    return _lockCtx()->onRun.push([id = _idPtr(), index, size, type, normalized, relative_offset](){
        auto &v_index = getVopRef(index);
        auto &v_size = getVopRef(size);
        auto &v_type = getVopRef(type);
        auto &v_normalized = getVopRef(normalized);
        auto &v_relative_offset = getVopRef(relative_offset);

        glVertexArrayAttribFormat(*id, v_index, v_size, static_cast<gl::Enum>(v_type), v_normalized, v_relative_offset);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> VertexArray::setBindingDivisor(Vop<const gl::UInt> binding_index, Vop<const gl::UInt> divisor){
    return _lockCtx()->onRun.push([id = _idPtr(), binding_index, divisor](){
        auto &v_binding_index = getVopRef(binding_index);
        auto &v_divisor = getVopRef(divisor);

        glVertexArrayBindingDivisor(*id, v_binding_index, v_divisor);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}


std::shared_future<bool> VertexArray::setElementBuffer(Ptr<const Buffer> buffer){
    return _lockCtx()->onRun.push([id = _idPtr(), buffer](){
        auto p_buffer = getPtrValue(buffer);

        glVertexArrayElementBuffer(*id, p_buffer->id());
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

std::shared_future<bool> VertexArray::setVertexBuffer(Vop<const gl::UInt> binding_index, Ptr<const Buffer> buffer,
                                                      Vop<const gl::IntPtr> offset, Vop<const gl::IntPtr> stride){
    return _lockCtx()->onRun.push([id = _idPtr(), binding_index, buffer, offset, stride](){
        auto &v_binding_index = getVopRef(binding_index);
        auto p_buffer = getPtrValue(buffer);
        auto &v_offset = getVopRef(offset);
        auto &v_stride = getVopRef(stride);

        glVertexArrayVertexBuffer(*id, v_binding_index, p_buffer->id(), v_offset, v_stride);
        if constexpr (DEBUG){
            if (auto err = glGetError()){
                std::cout << __FUNCTION__ << " Err: " << err << std::endl;
            }
        }
    });
}

