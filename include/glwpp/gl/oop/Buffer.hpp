#pragma once

#include <vector>

#include "glwpp/gl/oop/RawBuffer.hpp"

namespace glwpp::gl {

template<class T>  
class Buffer : protected RawBuffer {
    static constexpr size_t ElemSize = sizeof(T);

public:
    Buffer() :
        RawBuffer(){
    }

    Buffer(size_t size,
           T *data = nullptr,
           BufferUsage usage = BufferUsage::DynamicDraw) :
        RawBuffer(size * ElemSize, data, usage),
        _size(size){
    };

    Buffer(const std::vector<T> &data,
           BufferUsage usage = BufferUsage::DynamicDraw) :
        RawBuffer(data.size() * ElemSize, data.data(), usage),
        _size(data.size()){
    };

    virtual ~Buffer(){
    }

    Buffer& operator=(const std::vector<T> &data){
        reallocate(data.data(), data.size() * ElemSize, _usage);
    }

    using RawBuffer::id;
    using RawBuffer::usage;
    size_t size(){return _size;}

    using RawBuffer::bind;
    void write(const std::vector<T> data, size_t first, size_t size){
        RawBuffer::write(data.data(), first * ElemSize, size * ElemSize);
    }
    std::vector<T> read(size_t first, size_t size){
        std::vector<T> result(size);
        RawBuffer::read(result.data(), first * ElemSize, size * ElemSize);
        return result;
    }

private:
    size_t _size;

};


}