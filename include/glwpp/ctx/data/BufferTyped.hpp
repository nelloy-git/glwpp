#pragma once

#include <vector>

#include "glwpp/ctx/data/Buffer.hpp"

namespace glwpp::ctx {

template<class DT, BufferTypeGL BT>  
class BufferTyped : protected Buffer<BT> {

    template<bool Const = false>
    class Element {
        /* deduce const qualifier from bool Const parameter */
        using reference = typename std::conditional_t< Const, BufferTyped const &, BufferTyped & >;
        using pointer = typename std::conditional_t< Const, BufferTyped const *, BufferTyped * >;
    public:
        Element(pointer buffer, int pos) :
            _buff(buffer),
            _pos(pos){
        };
        // Element(Element&) = default;
        // Element(Element&&) = default;
        // Element(const Element&) = default;
        // Element(const Element&&) = default;
         
        template< bool _Const = Const >
        std::enable_if_t< _Const, reference > operator=(const DT& val){
            _buff->write(&val, sizeof(DT) * _pos, sizeof(DT));
            return *this;
        }

        operator DT() const {
            DT res;
            _buff->read(&res, sizeof(DT) * _pos, sizeof(DT));
            return res;
        }

    private:
        pointer _buff;
        int _pos;
    };

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

    inline Element<false> operator[](int i) {
        return Element<false>(this, i);
    };

    inline const Element<true> operator[](int i) const {
        return Element<true>(this, i);
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

};


}