#pragma once

#include <memory>

namespace glwpp {

template<typename T>
class Value;

template<>
class Value<const void> {
    template<typename U>
    friend class Value;

public:
    using type = const void;

    static Value<const void> Nullptr(){
        return Value<const void>(nullptr);
    }

    static Value<const void> Malloc(const size_t& size){
        return Value<const void>(malloc(size));
    }

    static Value<const void> Calloc(const size_t& count, const size_t& size){
        return Value<const void>(calloc(count, size));
    }

    template<typename V>
    Value(const Value<V>& other) :
        _ptr(other._ptr){}

    template<typename V>
    Value(Value<V>&& other) :
        _ptr(std::move(other._ptr)){}

    inline const void* value() const {
        return _ptr.get();
    }

    inline const void* operator*() const {
        return value();
    }

    inline const void* operator->() const {
        return get();
    }

    inline const void* get() const {
        return _ptr.get();
    }

protected:
    std::shared_ptr<const void> _ptr;

    Value(const void* ptr) :
        _ptr(static_cast<const char*>(ptr)){};

};

} // namespace glwpp