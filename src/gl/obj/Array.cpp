#include "glwpp/gl/obj/Array.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;
using namespace glwpp::gl::detail;

namespace {

static inline BitField access = static_cast<Enum>(BufferStorageFlag::Read)
                                | static_cast<Enum>(BufferStorageFlag::Write)
                                | static_cast<Enum>(BufferStorageFlag::Persistent)
                                | static_cast<Enum>(BufferStorageFlag::Coherent);

}

void ArrayBase::_init(const SizeiPtr& size, const void* initial,
                      const size_t& elem_size,
                      const UInt& id, ArrayData& data){
    if (size < 0){throw std::logic_error("glwpp::gl::Array size can not be negative");}
    
    data.size = size;
    data.elem_size = elem_size;

    glNamedBufferStorage(id, data.size * data.elem_size, nullptr, access);
    if (initial != nullptr){
        char* ptr = (char*)glMapNamedBuffer(id, static_cast<Enum>(BufferMapAccess::WriteOnly));
        for (size_t i = 0; i < data.size; ++i){
            memcpy(ptr, initial, data.elem_size);
            ptr += data.elem_size;
        }
        glUnmapNamedBuffer(id);
    }
}

void ArrayBase::_getSize(SizeiPtr& dst,
                         const UInt& id, ArrayData& data){
    dst = data.size;
}

void ArrayBase::_getValue(const SizeiPtr& i, void* dst,
                          const UInt& id, ArrayData& data){
    auto ptr = glMapNamedBufferRange(id, i * data.elem_size, data.elem_size, access);
    memcpy(dst, ptr, data.elem_size);
    glUnmapNamedBuffer(id);
}

void ArrayBase::_setValue(const SizeiPtr& i, const void* value,
                          const UInt& id, ArrayData& data){
    auto ptr = glMapNamedBufferRange(id, i * data.elem_size, data.elem_size, access);
    memcpy(ptr, value, data.elem_size);
    glUnmapNamedBuffer(id);
}