#pragma once

#include <chrono>
#include <memory>
#include <variant>
#include <future>

namespace glwpp {

template<typename T>
class Value;

template<typename T>
class Value<std::future<T>> {
    template<typename U>
    friend class Value;

    template<typename V>
    static constexpr bool is_void_v = std::is_same_v<std::remove_const_t<V>, void>;
    
    using Val = typename std::conditional_t<is_void_v<T>, std::future_status, T>;

public:
    using type = std::future<T>;

    static constexpr std::chrono::microseconds DEFAULT_WAIT_TIMEOUT = std::chrono::milliseconds(100);
    const std::chrono::microseconds wait_timeout;

    static void DEFAULT_FREE(std::variant<std::future<T>, Val>* raw_ptr){
        delete raw_ptr;
    }

    Value(const std::future<T>&) = delete;
    Value(std::future<T>&& future) :
        wait_timeout(DEFAULT_WAIT_TIMEOUT),
        _lock(new std::mutex{}),
        _ptr(new std::variant<std::future<T>, Val>(std::move(future)), &DEFAULT_FREE){};

    template<typename _Free>
    Value(std::future<T>&& future,
          _Free&& free_func = &DEFAULT_FREE,
          const std::chrono::microseconds& wait_timeout = DEFAULT_WAIT_TIMEOUT) : 
        wait_timeout(wait_timeout),
        _lock(new std::mutex{}),
        _ptr(new std::variant<std::future<T>, Val>(std::move(future)), std::forward<_Free>(free_func)){};

    template<typename V>
    Value(const Value<V>& other) :
        _lock(other._lock),
        _ptr(other._ptr){}

    template<typename V>
    Value(Value<V>&& other) :
        _lock(std::move(other._lock)),
        _ptr(std::move(other._ptr)){}

    ~Value(){
        _ptr.reset();
    }

    template<typename V = T, std::enable_if_t<!is_void_v<V>, bool> = true>
    inline V& value() const {
        if (_ptr->index() == 0){_getFuture();}
        return std::get<1>(*_ptr);
    }

    template<typename V = T, std::enable_if_t<!is_void_v<V>, bool> = true>
    inline V& operator*() const {
        return value();
    }

    template<typename V = T, std::enable_if_t<!is_void_v<V>, bool> = true>
    inline V* get() const {
        if (_ptr->index() == 0){_getFuture();}
        return &std::get<1>(*_ptr);
    }

    template<typename V = T, std::enable_if_t<!is_void_v<V>, bool> = true>
    inline V* operator->() const {
        return get();
    }

    inline void wait() const {
        std::lock_guard lg(*_lock);
        if (_ptr->index() == 1){return;}
        std::get<0>(*_ptr).wait();
    }

    template<typename _Rep, typename _Period = std::ratio<1i64, 1i64>>
    inline std::future_status wait_for(const std::chrono::duration<_Rep, _Period>& timeout) const {
        std::lock_guard lg(*_lock);
        if (_ptr->index() == 1){return;}
        return std::get<0>(*_ptr).wait_for(timeout);
    }

protected:
    std::shared_ptr<std::mutex> _lock;
    std::shared_ptr<std::variant<std::future<T>, Val>> _ptr;

    inline void _getFuture() const {
        std::lock_guard lg(*_lock);
        if (_ptr->index() == 1){return;}

        auto& future = std::get<0>(*_ptr);
        auto status = future.wait_for(wait_timeout);

        if constexpr (is_void_v<T>){
            *_ptr = status;
        } else {
            if (status != std::future_status::ready){
                throw std::runtime_error("Value<std::future<T>> timeout or defered.");
            } 
            *_ptr = future.get();
        }
    }

};

// template<typename T>
// constexpr std::chrono::microseconds Value<std::future<T>>::DEFAULT_WAIT_TIMEOUT = std::chrono::milliseconds(100);

} // namespace glwpp