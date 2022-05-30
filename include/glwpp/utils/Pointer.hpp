#pragma once

#include <mutex>

namespace glwpp {

namespace detail {

template<typename T>
struct PointerControl {
    template<typename ... Args>
    PointerControl(Args&&... args) :
        strong_counter(1),
        weak_counter(1),
        data(new T(std::forward<Args>(args)...)){
    };

    std::mutex lock;
    size_t strong_counter;
    size_t weak_counter;
    T* data;
};

};

template<typename T>
struct StrongPointer {
    template<typename ... Args>
    StrongPointer(Args&&... args) :
        _control(new detail::PointerControl(std::forward<Args>(args)...)){
    }

    ~StrongPointer(){
        std::lock_guard<std::mutex> lg(_control->lock);
        --_control->strong_counter;
        if (_control->strong_counter == 0){
            delete _control->data;
            _control->data = nullptr;
        }

        --_control->weak_counter;
        if (_control->weak_counter == 0){
            delete _control;
        }
    }

private:
    detail::PointerControl<T>* _control;

};

} // namespace glwpp