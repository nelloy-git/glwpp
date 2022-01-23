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

std::shared_future<bool> VertexArray::getAttribParam_i64v(sptr<gl::UInt> index,
                                                          sptr<gl::VertexArrayAttribParam> param,
                                                          sptr<gl::Int64> dst){
    if constexpr (AUTOCLEAR) _clear(index, param, dst);
    return _lockCtx()->onRun.push([id = idPtr(), index, param, dst](){
        glGetVertexArrayIndexed64iv(*id, *index, static_cast<gl::Enum>(*param), dst.get());
    });
}

std::shared_future<bool> VertexArray::getAttribParam_iv(sptr<gl::UInt> index,
                                                        sptr<gl::VertexArrayAttribParam> param,
                                                        sptr<gl::Int> dst){
    if constexpr (AUTOCLEAR) _clear(index, param, dst);
    return _lockCtx()->onRun.push([id = idPtr(), index, param, dst](){
        glGetVertexArrayIndexediv(*id, *index, static_cast<gl::Enum>(*param), dst.get());
    });
}

std::shared_future<bool> VertexArray::enableAttrib(sptr<gl::UInt> index){
    if constexpr (AUTOCLEAR) _clear(index);
    return _lockCtx()->onRun.push([id = idPtr(), index](){
        glEnableVertexArrayAttrib(*id, *index);
    });
}

std::shared_future<bool> VertexArray::disableAttrib(sptr<gl::UInt> index){
    if constexpr (AUTOCLEAR) _clear(index);
    return _lockCtx()->onRun.push([id = idPtr(), index](){
        glDisableVertexArrayAttrib(*id, *index);
    });
}

std::shared_future<bool> VertexArray::setAttribBinding(sptr<gl::UInt> index, sptr<gl::UInt> binding_index){
    if constexpr (AUTOCLEAR) _clear(index, binding_index);
    return _lockCtx()->onRun.push([id = idPtr(), index, binding_index](){
        glVertexArrayAttribBinding(*id, *index, *binding_index);
    });
}

std::shared_future<bool> VertexArray::setAttribFormat(sptr<gl::UInt> index, sptr<gl::Int> size,
                                                      sptr<gl::DataType> type, sptr<gl::Bool> normalized,
                                                      sptr<gl::UInt> relative_offset){
    if constexpr (AUTOCLEAR) _clear(index, size, type, normalized, relative_offset);
    return _lockCtx()->onRun.push([id = idPtr(), index, size, type, normalized, relative_offset](){
        glVertexArrayAttribFormat(*id, *index, *size, static_cast<gl::Enum>(*type), *normalized, *relative_offset);
    });
}

std::shared_future<bool> VertexArray::setBindingDivisor(sptr<gl::UInt> binding_index, sptr<gl::UInt> divisor){
    if constexpr (AUTOCLEAR) _clear(binding_index, divisor);
    return _lockCtx()->onRun.push([id = idPtr(), binding_index, divisor](){
        glVertexArrayBindingDivisor(*id, *binding_index, *divisor);
    });
}


std::shared_future<bool> VertexArray::setElementBuffer(sptr<Buffer> buffer){
    if constexpr (AUTOCLEAR) _clear(buffer);
    return _lockCtx()->onRun.push([id = idPtr(), buffer_id = buffer->idPtr()](){
        glVertexArrayElementBuffer(*id, *buffer_id);
    });
}

std::shared_future<bool> VertexArray::setVertexBuffer(sptr<gl::UInt> binding_index, sptr<Buffer> buffer,
                                                      sptr<gl::IntPtr> offset, sptr<gl::IntPtr> stride){
    if constexpr (AUTOCLEAR) _clear(binding_index, buffer, offset, stride);
    return _lockCtx()->onRun.push([id = idPtr(), binding_index, buffer_id = buffer->idPtr(), offset, stride](){
        glVertexArrayVertexBuffer(*id, *binding_index, *buffer_id, *offset, *stride);
    });
}

