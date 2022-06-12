#include "glwpp/gl/obj/Vector.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;
using namespace glwpp::gl::detail;

void VectorBase::_init(const SizeiPtr& size, const void* initial,
                       const size_t& elem_size, const BufferUsage& usage,
                       const UInt& id, VectorData& data){
    if (size < 0){throw std::logic_error("glwpp::gl::Vector size can not be negative");}

    data.capacity = INIT_CAPACITY > size ? INIT_CAPACITY : size;
    data.size = size;
    data.elem_size = elem_size;
    data.usage = usage;
    
    glNamedBufferData(id, data.capacity * elem_size, nullptr, static_cast<Enum>(usage));
    if (initial != nullptr){
        char* ptr = (char*)glMapNamedBuffer(id, static_cast<Enum>(BufferMapAccess::ReadWrite));
        for (size_t i = 0; i < data.size; ++i){
            memcpy(ptr, initial, data.elem_size);
            ptr += elem_size;
        }
        glUnmapNamedBuffer(id);
    }
}

void VectorBase::_getSize(SizeiPtr& dst,
                          const UInt& id, VectorData& data){
    dst = data.size;
}

void VectorBase::_getCapacity(SizeiPtr& dst,
                              const UInt& id, VectorData& data){
    dst = data.capacity;
}

void VectorBase::_reserve(const SizeiPtr& capacity,
                          const UInt& id, VectorData& data){
    if (data.capacity >= capacity){return;}

    data.capacity = capacity;

    UInt tmp;
    glCreateBuffers(1, &tmp);
    glNamedBufferData(tmp, data.size * data.elem_size, nullptr, static_cast<Enum>(BufferUsage::StreamCopy));
    glCopyNamedBufferSubData(id, tmp, 0, 0, data.size * data.elem_size);
    glNamedBufferData(id, data.capacity * data.elem_size, nullptr, static_cast<Enum>(data.usage));
    glCopyNamedBufferSubData(tmp, id, 0, 0, data.size * data.elem_size);
    glDeleteBuffers(1, &tmp);
}

void VectorBase::_shape(const UInt& id, VectorData& data){
    if (data.size >= data.capacity){return;}

    data.capacity = data.size;
        
    UInt tmp;
    glCreateBuffers(1, &tmp);
    glNamedBufferData(tmp, data.size * data.elem_size, nullptr, static_cast<Enum>(BufferUsage::StreamCopy));
    glCopyNamedBufferSubData(id, tmp, 0, 0, data.size * data.elem_size);
    glNamedBufferData(id, data.capacity * data.elem_size, nullptr, static_cast<Enum>(data.usage));
    glCopyNamedBufferSubData(tmp, id, 0, 0, data.size * data.elem_size);
    glDeleteBuffers(1, &tmp);
}

void VectorBase::_getValue(const SizeiPtr& i, void* dst, 
                           const UInt& id, VectorData& data){
    if (i < 0 || i >= data.size){throw std::out_of_range("glwpp::gl::Vector");}
    glGetNamedBufferSubData(id, i * data.elem_size, data.elem_size, dst);
}

void VectorBase::_setValue(const SizeiPtr& i, const void* value,
                           const UInt& id, VectorData& data){
    if (i < 0 || i >= data.size){throw std::out_of_range("glwpp::gl::Vector");}
    glNamedBufferSubData(id, i * data.elem_size, data.elem_size, value);
}

void VectorBase::_pushBack(const void* value,
                           const UInt& id, VectorData& data){
    if (data.size == data.capacity){
        _reserve(MULT_CAPACITY * data.capacity, id, data);
    }
    ++data.size;
    _setValue(data.size, value, id, data);
}

void VectorBase::_popBack(void* dst,
                          const UInt& id, VectorData& data){
    if (data.size <= 0){throw std::out_of_range("glwpp::gl::Vector");}
    --data.size;
    glGetNamedBufferSubData(id, data.size * data.elem_size, data.elem_size, dst);
}
