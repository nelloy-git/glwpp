#pragma once

#include <memory>

namespace glwpp {

template<typename T>
class Value;

template<>
class Value<void> {
    template<typename U>
    friend class Value;

public:
    using type = void;

    static Value<void> Malloc(const size_t& size){
        return Value<void>(malloc(size));
    }

    static Value<void> Calloc(const size_t& count, const size_t& size){
        return Value<void>(calloc(count, size));
    }

    template<typename V>
    Value(const Value<V>& other) :
        _ptr(other._ptr){}

    template<typename V>
    Value(Value<V>&& other) :
        _ptr(std::move(other._ptr)){}

    inline void* value() const {
        return _ptr.get();
    }

    inline void* operator*() const {
        return value();
    }

    inline void* operator->() const {
        return get();
    }

    inline void* get() const {
        return _ptr.get();
    }

    template<typename V>
    Value<V> reinterpret() const {
        return std::reinterpret_pointer_cast<V>(_ptr);
    };

protected:
    std::shared_ptr<void> _ptr;

    Value(void* ptr) :
        _ptr(ptr){};

};

} // namespace glwpp