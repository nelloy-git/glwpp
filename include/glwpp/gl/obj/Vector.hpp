#pragma once

#include "glwpp/gl/ctx_only/CtxBuffer.hpp"

#include "glwpp/gl/obj/Buffer.hpp"

namespace glwpp {

template<typename T>
class Vector : public Buffer {
    static const size_t INIT_CAPACITY = 4;

public:
    Vector(const wptr<Context>& wctx, const SrcLoc& loc = SrcLoc());
    Vector(const wptr<Context>& wctx, const Val<size_t>& size, const SrcLoc& loc = SrcLoc());
    Vector(const wptr<Context>& wctx, const Val<size_t>& size, const Val<T>& initial, const SrcLoc& loc = SrcLoc());
    ~Vector(){};

    bool capacity(Ptr<size_t>& dst) const;
    bool size(Ptr<size_t>& dst) const;
    bool shape(const SrcLoc& loc = SrcLoc());
    bool reserve(const Val<size_t>& size, const SrcLoc& loc = SrcLoc());

    bool push_back(const Val<T>& value, const SrcLoc& loc = SrcLoc());
    bool pop_back(const SrcLoc& loc = SrcLoc());
    bool set(const Val<size_t>& i, const Val<T>& value, const SrcLoc& loc = SrcLoc());
    bool get(Ptr<T>& dst, const Val<size_t>& i, const SrcLoc& loc = SrcLoc()) const;

private:
    sptr<size_t> _capacity;
    sptr<size_t> _size;
};

template<typename T>
Vector<T>::Vector(const wptr<Context>& wctx, const SrcLoc& loc) :
    Buffer(wctx, loc){
    static constexpr auto F = [](gl::CtxBuffer* buffer, size_t* _capacity, size_t* _size,
                                 const SrcLoc& loc){
        *_capacity = INIT_CAPACITY;
        *_size = 0;
        buffer->data(*_capacity * sizeof(T), nullptr, gl::BufferUsage::DynamicDraw, loc);
    };

    _capacity = make_sptr<size_t>(0);
    _size = make_sptr<size_t>(0);
    _execute<F>(getWCtx(), _getPtr(), Ptr(_capacity), Ptr(_size), Val(loc));
};

template<typename T>
Vector<T>::Vector(const wptr<Context>& wctx, const Val<size_t>& size, const SrcLoc& loc) :
    Buffer(wctx, loc){
    static constexpr auto F = [](gl::CtxBuffer* buffer, size_t* _capacity, size_t* _size,
                                 const size_t& size, const SrcLoc& loc){
        *_capacity = size;
        *_size = size;
        buffer->data(*_capacity * sizeof(T), nullptr, gl::BufferUsage::DynamicDraw, loc);

        auto ptr = static_cast<T*>(buffer->map(gl::BufferMapAccess::WriteOnly, loc));
        for (size_t i = 0; i < size; ++i){
            ptr[i] = T{};
        }
        buffer->unmap(loc);
    };

    _capacity = make_sptr<size_t>(0);
    _size = make_sptr<size_t>(0);
    _execute<F>(getWCtx(), _getPtr(), Ptr(_capacity), Ptr(_size), size, Val(loc));
};

template<typename T>
Vector<T>::Vector(const wptr<Context>& wctx, const Val<size_t>& size, const Val<T>& initial, const SrcLoc& loc) :
    Buffer(wctx, loc){
    static constexpr auto F = [](gl::CtxBuffer* buffer, size_t* _capacity, size_t* _size,
                                 const size_t& size, const T& initial, const SrcLoc& loc){
        *_capacity = size;
        *_size = size;
        buffer->data(*_capacity * sizeof(T), nullptr, gl::BufferUsage::DynamicDraw, loc);

        auto ptr = static_cast<T*>(buffer->map(gl::BufferMapAccess::WriteOnly, loc));
        for (size_t i = 0; i < size; ++i){
            ptr[i] = initial;
        }
        buffer->unmap(loc);
    };

    _capacity = make_sptr<size_t>(0);
    _size = make_sptr<size_t>(0);
    _execute<F>(getWCtx(), _getPtr(), Ptr(_capacity), Ptr(_size), size, initial, Val(loc));
};

template<typename T>
bool Vector<T>::capacity(Ptr<size_t>& dst) const {
    static constexpr auto F = [](size_t* _capacity, size_t* dst){
        *dst = *_capacity;
    };
    return _execute<F>(getWCtx(), Ptr(_capacity), dst);
};

template<typename T>
bool Vector<T>::size(Ptr<size_t>& dst) const {
    static constexpr auto F = [](size_t* _size, size_t* dst){
        *dst = *_size;
    };
    return _execute<F>(getWCtx(), Ptr(_size), dst);
};

template<typename T>
bool Vector<T>::shape(const SrcLoc& loc){
    static constexpr auto F = [](gl::CtxBuffer* buffer, size_t* _capacity, size_t* _size,
                                 const SrcLoc& loc){
        if (_size <= 0 || *_capacity <= *_size){return;}

        size_t tmp_bytes = *_size * sizeof(T);
        gl::CtxBuffer tmp(loc);
        tmp.data(tmp_bytes, nullptr, gl::BufferUsage::StaticDraw, loc);
        buffer->copySubDataTo(tmp, 0, 0, tmp_bytes, loc);
        buffer->data(tmp_bytes, nullptr, gl::BufferUsage::DynamicDraw, loc);
        tmp.copySubDataTo(*buffer, 0, 0, tmp_bytes, loc);
        *_capacity = *_size;
    };
    return _execute<F>(getWCtx(), _getPtr(), Ptr(_capacity), Ptr(_size), Val(loc));
}

template<typename T>
bool Vector<T>::reserve(const Val<size_t>& capacity, const SrcLoc& loc){
    static constexpr auto F = [](gl::CtxBuffer* buffer, size_t* _capacity, size_t* _size,
                                 const size_t& capacity, const SrcLoc& loc){
        if (*_capacity >= capacity){return;}
        
        *_capacity = capacity;
        size_t tmp_bytes = *_size * sizeof(T);
        size_t new_bytes = *_capacity * sizeof(T);

        gl::CtxBuffer tmp(loc);
        tmp.data(tmp_bytes, nullptr, gl::BufferUsage::DynamicDraw, loc);
        buffer->copySubDataTo(tmp, 0, 0, tmp_bytes, loc);
        buffer->data(new_bytes, nullptr, gl::BufferUsage::DynamicDraw, loc);
        tmp.copySubDataTo(*buffer, 0, 0, tmp_bytes, loc);
    };
    return _execute<F>(getWCtx(), _getPtr(), Ptr(_capacity), Ptr(_size), capacity, Val(loc));
}

template<typename T>
bool Vector<T>::push_back(const Val<T>& value, const SrcLoc& loc){
    static constexpr auto F = [](gl::CtxBuffer* buffer, size_t* _capacity, size_t* _size,
                                 const T& value, const SrcLoc& loc){
        if (*_size == *_capacity){
            *_capacity = 2 * *_capacity;
            size_t tmp_bytes = *_size * sizeof(T);
            size_t new_bytes = *_capacity * sizeof(T);

            gl::CtxBuffer tmp(loc);
            tmp.data(tmp_bytes, nullptr, gl::BufferUsage::DynamicDraw, loc);
            buffer->copySubDataTo(tmp, 0, 0, tmp_bytes, loc);
            buffer->data(new_bytes, nullptr, gl::BufferUsage::DynamicDraw, loc);
            tmp.copySubDataTo(*buffer, 0, 0, tmp_bytes, loc);
        }
        buffer->setSubData(*_size * sizeof(T), sizeof(T), &value, loc);
        ++*_size;
    };
    return _execute<F>(getWCtx(), _getPtr(), Ptr(_capacity), Ptr(_size), value, Val(loc));
}

template<typename T>
bool Vector<T>::pop_back(const SrcLoc& loc){
    static constexpr auto F = [](gl::CtxBuffer* buffer, size_t* _capacity, size_t* _size,
                                 const SrcLoc& loc){
        --*size;
        buffer->setSubData(*_size, sizeof(T), nullptr, loc);
    };
    return _execute<F>(getWCtx(), _getPtr(), Ptr(_capacity), Ptr(_size), Val(loc));
}

template<typename T>
bool Vector<T>::set(const Val<size_t>& i, const Val<T>& value, const SrcLoc& loc){
    static constexpr auto F = [](gl::CtxBuffer* buffer, size_t* _capacity, size_t* _size,
                                 const size_t& i, const T& value, const SrcLoc& loc){
        std::cout << i << std::endl;
        if (i >= *_size){
            throw std::runtime_error("Out of bounds: " + std::string(loc.file_name()) + ":" + std::to_string(loc.line()));
        }
        std::cout << i << std::endl;
        buffer->setSubData(i * sizeof(T), sizeof(T), &value, loc);
    };
    return _execute<F>(getWCtx(), _getPtr(), Ptr(_capacity), Ptr(_size), i, value, Val(loc));
}

template<typename T>
bool Vector<T>::get(Ptr<T>& dst, const Val<size_t>& i, const SrcLoc& loc) const {
    static constexpr auto F = [](gl::CtxBuffer* buffer, size_t* _capacity, size_t* _size,
                                 T* dst, const size_t& i, const SrcLoc& loc){
        if (i >= *_size){
            throw std::runtime_error("Out of bounds: " + std::string(loc.file_name()) + ":" + std::to_string(loc.line()));
        }
        buffer->getSubData(i * sizeof(T), sizeof(T), dst, loc);
    };
    return _execute<F>(getWCtx(), _getPtr(), Ptr(_capacity), Ptr(_size), dst, i, Val(loc));
}

}