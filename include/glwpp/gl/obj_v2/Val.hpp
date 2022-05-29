#pragma once

#include "glwpp/utils/Utils.hpp"

namespace glwpp::gl::v2 {

template<class T>
class Val {
public:
    Val(const T& data){_data = make_sptr<T>(data);}
    Val(const sptr<T>& data) : _data(data){}
    Val(const Val<T>& other) : _data(other._data){}
    Val(const Val<T>&& other) : _data(std::move(other._data)){}
    virtual ~Val(){};

    operator T&(){return *_data;}
    operator T&() const {return *_data;}

    T& getVal(){return *_data;}
    const T& getVal() const {return *_data;}
    
    sptr<T>& getPtr(){return _data;}
    const sptr<T>& getPtr() const {return _data;}

    template<typename D>
    Val<D> reinterpret(){return Val<D>(std::reinterpret_pointer_cast<D>(_data));}
    
    template<typename D>
    const Val<D> reinterpret() const {return Val<D>(std::reinterpret_pointer_cast<D>(_data));}

private:
    sptr<T> _data;
};

template<class>
struct isVal : std::false_type {};

template<class T>
struct isVal<Val<T>> : std::true_type {
    using type = T;
};

} // namespace glwpp
