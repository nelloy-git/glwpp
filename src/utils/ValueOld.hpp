#pragma once

#include <memory>

namespace glwpp {

template <class, template <class, class...> class>
struct is_instance : public std::false_type {};

template <class...Ts, template <class, class...> class U>
struct is_instance<U<Ts...>, U> : public std::true_type {};

template<typename T>
class Value {
    template<typename U>
    friend class Value;

    template<typename V>
    static constexpr bool is_void = std::is_same_v<std::remove_const_t<V>, void>;

    template<typename V>
    static constexpr bool is_value = is_instance<std::remove_const_t<std::remove_reference_t<V>>, Value>::value;

public:
    using type = typename T;
    static_assert(!is_value<T>, "Value<Value<...>> is not allowed");

    Value() :
        _ptr(new T){
    }

    Value(const T& value) :
        _ptr(new T(value)){
    }

    template<typename V, std::enable_if_t<(!is_value<V>), bool> = true>
    Value(const V& value) :
        _ptr(new T(value)){
    }

    template<typename V, typename Del, std::enable_if_t<(!is_value<V>), bool> = true>
    Value(const V& value, const Del& del) : 
        _ptr(new T(value), del){
    }

    Value(const Value<T>& other) :
        _ptr(other._ptr){
    }

    template<typename V>
    Value(const Value<V>& other) :
        _ptr(other._ptr){
    }

    template<typename V>
    Value<T>& operator=(const Value<V>& other){
        _ptr = other._ptr;
        return *this;
    }

    template<typename V = T, std::enable_if_t<(!is_void<V>), bool> = true>
    V& operator*() const {
        return *_ptr;
    }

    T* operator->() const {
        return _ptr.get();
    }

    operator T&() const {
        return *_ptr;
    }

    operator T*() const {
        return _ptr.get();
    }

    T* get() const {
        return _ptr.get();
    }

    template<typename U>
    Value<U> reinterpret(){
        return Value<U>(std::reinterpret_pointer_cast<U>(_ptr));
    }

private:
    std::shared_ptr<T> _ptr;
};

template<>
class Value<const void> {
    template<typename U>
    friend class Value;

public:
    using type = const void;

    static const Value<const void>& Nullptr(){
        static const Value<const void> null_value;
        return null_value;
    }

    static Value<const void> Alloc(const size_t& bytes){
        return Value<const void>(malloc(bytes));
    }

    template<typename V>
    Value(const V& value) :
        _ptr(std::make_shared<V>(value)){
    }

    template<typename V>
    Value(const Value<V>& other) :
        _ptr(other._ptr){
    }
    
    operator const void*() const {
        return _ptr.get();
    }

    inline const void* get() const {
        return _ptr.get();
    }

private:
    Value(){};

    Value(const void* ptr) :
        _ptr(ptr){
    }

    std::shared_ptr<const void> _ptr;
};

template<>
class Value<void> {
    template<typename U>
    friend class Value;

public:
    using type = void;

    static Value<void> Alloc(const size_t& bytes){
        return Value<void>(malloc(bytes));
    }

    inline void* get() const {
        return _ptr.get();
    }

    template<typename V>
    Value(const Value<V>& other) :
        _ptr(other._ptr){
    }
    
    operator void*() const {
        return _ptr.get();
    }

private:
    Value(){};

    Value(void* ptr) :
        _ptr(ptr){
    }

    std::shared_ptr<void> _ptr;
};

} // namespace glwpp