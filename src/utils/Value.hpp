#pragma once

#include <memory>

namespace glwpp {

namespace detail {

class ValueBase {
    template<typename V>
    struct MakeHelper {
        using type = std::remove_reference_t<V>;
    };

    template<typename V>
    struct MakeHelper<Value<V>> {
        using type = std::remove_reference_t<V>;
    };

public:
    template<typename V>
    static auto make(V&& val){
        return glwpp::Value<MakeHelper<V>::type>(val);
    }

};

}; // namespace detail

template <class, template <class, class...> class>
struct is_instance : public std::false_type {};

template <class...Ts, template <class, class...> class U>
struct is_instance<U<Ts...>, U> : public std::true_type {};

template<typename T>
class Value : detail::ValueBase {
    template<typename U>
    friend class Value;

    template<typename V>
    static constexpr bool is_void = std::is_same_v<std::remove_const_t<V>, void>;

    template<typename V>
    static constexpr bool is_value = is_instance<std::remove_const_t<std::remove_reference_t<V>>, Value>::value;

public:
    using type = typename T;
    static_assert(!is_value<T>, "Value<Value<...>> is not allowed");

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

    template<typename V, typename U = T, std::enable_if_t<(!is_void<U>), bool> = true>
    Value(const Value<V>& other) :
        _ptr(other._ptr){
    }

    template<typename V, typename U = T, std::enable_if_t<(is_void<U>), bool> = true>
    Value(const Value<V>& other) :
        _ptr(std::reinterpret_pointer_cast<U>(other._ptr)){
    }

    Value(const std::shared_ptr<T>& ptr) :
        _ptr(ptr){
    }
    
    Value(std::shared_ptr<T>&& ptr) :
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

    template<typename U = T>
    operator std::enable_if_t<(!is_void<U> && !is_value<U>), U>&() const {
        return *_ptr;
    }

    template<typename U = T>
    operator std::enable_if_t<(!is_void<U> && !is_value<U>), U*>() const {
        return _ptr.get();
    }

    template<typename U = T>
    operator std::enable_if_t<(is_void<U>), U*>() const {
        return _ptr.get();
    }

    T* get() const {
        return _ptr.get();
    }

    template<typename U>
    Value<U> reinterpret(){
        return Value<U>(std::reinterpret_pointer_cast<U>(_ptr));
    }

    const std::shared_ptr<T>& get_shared(){
        return _ptr;
    } 

private:
    std::shared_ptr<T> _ptr;

};

} // namespace glwpp