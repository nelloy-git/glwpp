#pragma once

#include "glwpp/utils/Utils.hpp"

namespace glwpp::gl::v2 {

template<class T>
class Ptr {
public:
    Ptr(sptr<T>& data) : _data(data){}
    Ptr(const sptr<T>& data) : _data(data){}
    Ptr(const Ptr<T>& other) : _data(other._data){}
    Ptr(const Ptr<T>&& other) : _data(std::move(other._data)){}
    virtual ~Ptr(){};

    operator T*(){return _data.get();}
    operator T*() const {return _data.get();}

    template<class T = T, class = std::enable_if_t<(!std::is_same_v<T, void>)>>
    T& getVal(){return *_data;}
    template<class T = T, class = std::enable_if_t<(!std::is_same_v<T, void>)>>
    const T& getVal() const {return *_data;}
    
    sptr<T>& getPtr(){return _data;}
    const sptr<T>& getPtr() const {return _data;}

    template<typename D>
    Ptr<D> reinterpret(){
        return Ptr<D>(std::reinterpret_pointer_cast<D>(_data));
    }

private:
    sptr<T> _data;
    
};

template<class>
struct isPtr : std::false_type {};

template<class T>
struct isPtr<Ptr<T>> : std::true_type {
    using type = T;
};

}