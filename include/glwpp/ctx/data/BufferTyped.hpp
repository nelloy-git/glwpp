#pragma once

#include <vector>

#include "glwpp/ctx/data/Buffer.hpp"

namespace glwpp::ctx {

template<class DT, BufferTypeGL BT>  
class BufferTyped : protected Buffer<BT> {
    struct Element;
public:
    // zero-sized buffer
    explicit BufferTyped(BufferUsageGL usage) :
        Buffer<BT>(usage){
    };

    virtual ~BufferTyped(){
    };

    using Buffer<BT>::bind;

    inline BufferTyped& operator=(const std::vector<DT> &vec){
        _size = vec.size() * sizeof(DT);
        Buffer<BT>::resize(_size);
        Buffer<BT>::write(vec.data(), 0, _size);
        return *this;
    };

    inline operator std::vector<DT>(){
        std::vector<DT> vec(_size);
        Buffer<BT>::read(vec.data(), 0, _size * sizeof(DT));
        return vec;
    };

    inline Element operator[](int i){
        return Element(*this, i);
    };

    inline GLsizeiptr size(){
        return _size;
    };

    inline void resize(int size){
        _size = size;
        Buffer<BT>::resize(size * sizeof(DT));
    };

private:
    size_t _size;

    struct Element {
        Element(BufferTyped &buffer, int pos) :
            _buff(buffer),
            _pos(pos){
        };
        Element(Element&) = delete;
        Element(Element&&) = delete;
        Element(const Element&) = delete;
        Element(const Element&&) = delete;

        Element& operator=(const DT& val){
            _buff.write(&val, sizeof(DT) * _pos, sizeof(DT));
            return *this;
        }

        operator DT(){
            DT res;
            _buff.read(&res, sizeof(DT) * _pos, sizeof(DT));
            return res;
        }

    private:
        BufferTyped &_buff;
        int _pos;
    };
};


}