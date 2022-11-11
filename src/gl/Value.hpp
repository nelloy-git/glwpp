#pragma once

#include <memory>

namespace glwpp {

namespace GL {

template<typename T>
class Value {
public:
    Value(const T& value) :
        _ptr(new T(value)){
    }

    Value(const std::shared_ptr<T>& ptr) :
        _ptr(ptr){
    }
    
    Value(const std::shared_ptr<T>&& ptr) :
        _ptr(ptr){
    }

    T& operator*() const {
        return *_ptr;
    }

    auto get() const {
        return _ptr.get();
    }

    operator std::shared_ptr<T>(){
        return _ptr;
    }

private:
    std::shared_ptr<T> _ptr;

};

} // namespace GL

} // namespace glwpp