#pragma once

#include <memory>

namespace glwpp {

namespace GL {

template<typename T>
class Value {
    template<typename U>
    friend class Value;

    template<typename V>
    static constexpr bool is_void = std::is_same_v<std::remove_const_t<V>, void>;

public:
    using type = T;

    template<typename U = T, std::enable_if_t<(!is_void<U> && !std::is_array_v<U>), bool> = true>
    Value() :
        _ptr(new U){
    }

    template<typename V, typename U = T, std::enable_if_t<(!is_void<U> && !std::is_array_v<U>), bool> = true>
    Value(const V& value) :
        _ptr(new U(value)){
    }

    template<typename U = T, std::enable_if_t<(!is_void<U> && std::is_array_v<U>), bool> = true>
    Value(const size_t& size) :
        _ptr(new std::remove_extent_t<U>[size]){
    }

    template<typename U = T, std::enable_if_t<(is_void<U>), bool> = true>
    Value(const size_t& bytes) :
        _ptr(new char[bytes]){
    }

    template<typename V, typename U = T, std::enable_if_t<(is_void<U>), bool> = true>
    Value(const Value<V>& other) :
        _ptr(std::reinterpret_pointer_cast<void>(other._ptr)){
    }

    Value(const std::shared_ptr<T>& ptr) :
        _ptr(ptr){
    }
    
    Value(const std::shared_ptr<T>&& ptr) :
        _ptr(ptr){
    }

    template<typename V = T, std::enable_if_t<(!is_void<V>), bool> = true>
    V& operator*() const {
        return *_ptr;
    }

    T* operator->() const {
        return _ptr.get();
    }

    operator std::shared_ptr<T>(){
        return _ptr;
    }

    auto get() const {
        return _ptr.get();
    }

private:
    std::shared_ptr<T> _ptr;

};

} // namespace GL

} // namespace glwpp