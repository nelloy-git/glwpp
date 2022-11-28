#pragma once

#include <memory>

namespace glwpp {

template<typename T>
class SharedObject : public std::enable_shared_from_this<T> {
public:
    static std::shared_ptr<T> New(auto&&... args){
        return T::make(std::forward<decltype(args)>(args)...);
    };
    SharedObject(const SharedObject&) = delete;
    SharedObject(const SharedObject&&) = delete;
    virtual ~SharedObject(){}; 

protected:
    SharedObject(){};
};

}