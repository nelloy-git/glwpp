#include "glwpp/gl/oop/VertexArray.hpp"

using namespace glwpp;

namespace {
    static gl::UInt CreateVertexArray(){
        gl::UInt id;
        gl::CreateVertexArrays(1, &id);
        return id;
    }
    static void DeleteVertexArray(gl::UInt *id){
        gl::DeleteVertexArrays(1, id);
        delete id;
    }
    static gl::Int64 GetAttribParamInt64(const sptr<gl::UInt> id, gl::UInt index, gl::VertexArrayAttribParamInt param){
        gl::Int64 val;
        gl::GetVertexArrayIndexed64iv(*id, index, static_cast<gl::Enum>(param), &val);
        return val;
    }
    static gl::Int GetAttribParamInt(const sptr<gl::UInt> id, gl::UInt index, gl::VertexArrayAttribParamInt param){
        gl::Int val;
        gl::GetVertexArrayIndexediv(*id, index, static_cast<gl::Enum>(param), &val);
        return val;
    }
    static void EnableAttrib(const sptr<gl::UInt> id, gl::UInt index){
        gl::EnableVertexArrayAttrib(*id, index);
    }
    static void DisableAttrib(const sptr<gl::UInt> id, gl::UInt index){
        gl::DisableVertexArrayAttrib(*id, index);
    }
    static void SetAttribBinding(const sptr<gl::UInt> id, gl::UInt index, gl::UInt binding_index){
        gl::VertexArrayAttribBinding(*id, index, binding_index);
    }
    static void SetAttribFormat(const sptr<gl::UInt> id, gl::UInt index, gl::Int size, gl::DataType type, bool normalized, gl::UInt relative_offset){
        gl::VertexArrayAttribFormat(*id, index, size, static_cast<gl::Enum>(type), normalized, relative_offset);
    }
    static void SetBindingDivisor(const sptr<gl::UInt> id, gl::UInt binding_index, gl::UInt divisor){
        gl::VertexArrayBindingDivisor(*id, binding_index, divisor);
    }
    static void SetElementBuffer(const sptr<gl::UInt> id, const sptr<gl::UInt> buffer_id){
        gl::VertexArrayElementBuffer(*id, *buffer_id);
    }
    static void SetVertexBuffer(const sptr<gl::UInt> id, gl::UInt binding_index, const sptr<gl::UInt> buffer_id, gl::IntPtr offset, gl::IntPtr stride){
        gl::VertexArrayVertexBuffer(*id, binding_index, *buffer_id, offset, stride);
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

std::shared_future<gl::Int64> VertexArray::getAttribParamInt64(gl::UInt index, gl::VertexArrayAttribParamInt param){
    return _execute(&GetAttribParamInt64, idPtr(), index, param);
}

std::shared_future<gl::Int> VertexArray::getAttribParamInt(gl::UInt index, gl::VertexArrayAttribParamInt param){
    return _execute(&GetAttribParamInt, idPtr(), index, param);
}

std::shared_future<bool> VertexArray::enableAttrib(gl::UInt index){
    return _execute(&EnableAttrib, idPtr(), index);
}

std::shared_future<bool> VertexArray::disableAttrib(gl::UInt index){
    return _execute(&DisableAttrib, idPtr(), index);
}

std::shared_future<bool> VertexArray::setAttribBinding(gl::UInt index, gl::UInt binding_index){
    return _execute(&SetAttribBinding, idPtr(), index, binding_index);
}

std::shared_future<bool> VertexArray::setAttribFormat(gl::UInt index, gl::Int size, gl::DataType type, bool normalized, gl::UInt relative_offset){
    return _execute(&SetAttribFormat, idPtr(), index, size, type, normalized, relative_offset);
}

std::shared_future<bool> VertexArray::setBindingDivisor(gl::UInt binding_index, gl::UInt divisor){
    return _execute(&SetBindingDivisor, idPtr(), binding_index, divisor);
}


std::shared_future<bool> VertexArray::setElementBuffer(const Buffer &buffer){
    return _execute(&SetElementBuffer, idPtr(), buffer.idPtr());
}

std::shared_future<bool> VertexArray::setVertexBuffer(gl::UInt binding_index, const Buffer &buffer, gl::IntPtr offset, gl::IntPtr stride){
    return _execute(&SetVertexBuffer, idPtr(), binding_index, buffer.idPtr(), offset, stride);
}

