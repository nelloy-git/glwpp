#pragma once

#include <memory>

#include "utils/value/ConstVoidValue.hpp"
#include "utils/value/DelayedValue.hpp"
#include "utils/value/VoidValue.hpp"

namespace glwpp {

template<typename T>
class Value;

namespace detail {

template <class, template <class, class...> class>
struct is_instance : public std::false_type {};

template <class...Ts, template <class, class...> class U>
struct is_instance<U<Ts...>, U> : public std::true_type {};

template<typename T, template <class, class...> class Req>
static constexpr bool is_instance_v = is_instance<std::remove_const_t<std::remove_reference_t<T>>, Req>::value;

template<typename T>
static constexpr bool is_value_v = is_instance<std::remove_const_t<std::remove_reference_t<T>>, Value>::value;

}; // namespace detail

template<typename T, typename Req>
constexpr bool IsValuable(){
    if constexpr (std::is_convertible_v<T, Req>){
        return true;
    } else {
        if constexpr (detail::is_instance_v<T, Value>){
            return std::is_convertible_v<decltype(std::declval<T>().value()), Req>;
        } else {
            return false;
        }
    }
}

template<typename T, typename Req>
concept Valuable = IsValuable<T, Req>();

template<typename T>
static inline decltype(auto) GetValuable(T&& val){
    if constexpr (!detail::is_instance_v<T, Value>){
        return std::forward<T>(val);
    } else {
        return val.value();
    }
}

template<typename T>
class Value {
    template<typename U>
    friend class Value;
    
    static_assert(!detail::is_value_v<T>, "Value<Value<...>> is not allowed");

public:
    using type = typename T;

    static Value<T> Make(T* ptr);
    template<typename D>
    static Value<T> Make(T* ptr, D&& del);
    static Value<T> Make(auto&&... args);

    Value(const T& value);
    Value(T&& value);

    template<typename V>
    Value(const Value<V>& other);

    template<typename V>
    Value(Value<V>&& other);

    virtual inline T& value() const;
    virtual inline T& operator*() const;
    virtual inline T* get() const;
    virtual inline T* operator->() const;

    template<typename V>
    Value<V> reinterpret();

protected:
    std::shared_ptr<T> _ptr;

    struct raw_ptr {};
    Value(const raw_ptr& raw_ptr, T* ptr);

    struct raw_ptr_del {};
    template<typename D>
    Value(const raw_ptr_del& raw_ptr_del, T* ptr, D&& del);

    struct emplace {};
    Value(const emplace& emplace, auto&&... args);
};

// =============================================

template<typename T>
Value<T> Value<T>::Make(T* ptr){
    return Value<T>(raw_ptr{}, ptr);
}

template<typename T>
template<typename D>
Value<T> Value<T>::Make(T* ptr, D&& del){
    return Value<T>(raw_ptr_del{}, ptr, del);
}

template<typename T>
Value<T> Value<T>::Make(auto&&... args){
    return Value<T>(emplace{}, std::forward<decltype(args)>(args)...);
}

template<typename T>
Value<T>::Value(const T& value) :
    _ptr(std::make_shared<T>(value)){
}

template<typename T>
Value<T>::Value(T&& value) :
    _ptr(std::make_shared<T>(std::move(value))){
}

template<typename T>
template<typename V>
Value<T>::Value(const Value<V>& other) :
    _ptr(other._ptr){
}

template<typename T>
template<typename V>
Value<T>::Value(Value<V>&& other) :
    _ptr(std::move(other._ptr)){
}

template<typename T>
inline T& Value<T>::value() const {
    return *_ptr;
}

template<typename T>
inline T& Value<T>::operator*() const {
    return value();
}

template<typename T>
T* Value<T>::get() const {
    return _ptr.get();
}

template<typename T>
T* Value<T>::operator->() const {
    return get();
}

template<typename T>
template<typename V>
Value<V> Value<T>::reinterpret(){
    return Value<V>(std::reinterpret_pointer_cast<V>(_ptr));
}

template<typename T>
Value<T>::Value(const emplace& empty, auto&&... args) :
    _ptr(std::make_shared<T>(std::forward<decltype(args)>(args)...)){
}

template<typename T>
Value<T>::Value(const raw_ptr& empty, T* ptr) :
    _ptr(ptr){
    if (!ptr){throw std::logic_error("empty pointers are not allowed");}
}

template<typename T>
template<typename D>
Value<T>::Value(const raw_ptr_del& empty, T* ptr, D&& del) :
    _ptr(ptr, del){
    if (!ptr){throw std::logic_error("empty pointers are not allowed");}
}

} // namespace glwpp