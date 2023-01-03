#pragma once

#include <memory>

#include "Context.hpp"

namespace glwpp {

template <class, template <class, class...> class>
struct is_instance : public std::false_type {};

template <class...Ts, template <class, class...> class U>
struct is_instance<U<Ts...>, U> : public std::true_type {};

template<typename T>
class Value;

template<typename T>
class Value {
    template<typename U>
    friend class Value;

    template<typename V>
    static constexpr bool is_void = std::is_same_v<std::remove_const_t<V>, void>;

    template<typename V>
    static constexpr bool is_value = is_instance<std::remove_const_t<std::remove_reference_t<V>>, Value>::value;

    struct emplaced {};
    Value(Context& ctx, const emplaced& empty, auto&&... args) :
        _wctx(ctx.weak_from_this()),
        _ptr(std::make_shared<T>(std::forward<decltype(args)>(args)...)){
    }

    struct with_deleter {};
    template<typename D>
    Value(Context& ctx, const with_deleter& empty, T* ptr, D&& del) :
        _wctx(ctx.weak_from_this()),
        _ptr(ptr, del){
    }

public:
    using type = typename T;
    static_assert(!is_value<T>, "Value<Value<...>> is not allowed");

    static Value<T> Emplace(Context& ctx, auto&&... args){
        return Value<T>(ctx, emplaced{}, std::forward<decltype(args)>(args)...);
    }

    template<typename D>
    static Value<T> WithDeleter(Context& ctx, T* ptr, D&& del){
        return Value<T>(ctx, with_deleter{}, ptr, del);
    }

    Value(Context& ctx, const T& value) :
        _wctx(ctx.weak_from_this()),
        _ptr(std::make_shared<T>(value)){
    }

    Value(Context& ctx, T&& value) :
        _wctx(ctx.weak_from_this()),
        _ptr(std::make_shared<T>(std::move(value))){
    }

    template<typename V>
    Value(const Value<V>& other) :
        _wctx(other._wctx),
        _ptr(other._ptr){
    }

    template<typename V>
    Value(Value<V>&& other) :
        _wctx(std::move(other._wctx)),
        _ptr(std::move(other._ptr)){
    }

    Value(Context& ctx, const Value<T>& other) :
        _wctx(ctx.weak_from_this()),
        _ptr(other._ptr){
    }

    Value(Context& ctx, Value<T>&& other) :
        _wctx(ctx.weak_from_this()),
        _ptr(std::move(other._ptr)){
    }

    template<typename V>
    Value(Context& ctx, const Value<V>& other) :
        _wctx(ctx.weak_from_this()),
        _ptr(other._ptr){
    }

    template<typename V>
    Value<T>& operator=(const Value<V>& other){
        _ptr = other._ptr;
        return *this;
    }

    inline T& operator*() const {
        return value();
    }

    inline T& value() const {
        return *_ptr;
    }

    T* operator->() const {
        return get();
    }

    T* get() const {
        return _ptr.get();
    }

    template<typename U>
    Value<U> reinterpret(){
        return Value<U>(std::reinterpret_pointer_cast<U>(_ptr));
    }

private:
    std::weak_ptr<Context> _wctx;
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
    Value(const Value<V>& other) :
        _ptr(other._ptr){
    }

    Value(Context& ctx, const Value<const void>& other) :
        _wctx(ctx.weak_from_this()),
        _ptr(other._ptr){
    }

    inline const void* operator*() const {
        return value();
    }

    inline const void* value() const {
        return _ptr.get();
    }

    const void* operator->() const {
        return get();
    }

    const void* get() const {
        return _ptr.get();
    }

private:
    std::weak_ptr<Context> _wctx;
    std::shared_ptr<const void> _ptr;

    Value(){};

    Value(const void* ptr) :
        _ptr(ptr){
    }
};

template<>
class Value<void> {
    template<typename U>
    friend class Value;

    struct with_raw_ptr {};
    Value(Context& ctx, const with_raw_ptr&, void* ptr) :
        _wctx(ctx.weak_from_this()),
        _ptr(ptr){
    }

public:
    using type = void;

    static Value<void> Alloc(Context& ctx, const size_t& bytes){
        return Value<void>(ctx, with_raw_ptr{}, malloc(bytes));
    }

    template<typename V>
    Value(const Value<V>& other) :
        _ptr(other._ptr){
    }

    Value(Context& ctx, const Value<void>& other) :
        _wctx(ctx.weak_from_this()),
        _ptr(other._ptr){
    }

    inline void* operator*() const {
        return value();
    }

    inline void* value() const {
        return _ptr.get();
    }

    void* operator->() const {
        return get();
    }

    void* get() const {
        return _ptr.get();
    }

private:
    std::weak_ptr<Context> _wctx;
    std::shared_ptr<void> _ptr;
};

} // namespace glwpp