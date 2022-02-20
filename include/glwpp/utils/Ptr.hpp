#pragma once

#include <memory>
#include <variant>

namespace glwpp {

template<class T>
class Ptr {
    using Container = std::variant<T*, std::shared_ptr<T>>;
public:
    Ptr(T*&& data) : _data(new Container(data)){}
    Ptr(const std::shared_ptr<T>& data){_data = std::make_shared<Container>(data);}
    Ptr(const Ptr& other) : _data(other._data){}

    T& getVal(){
        return _getVal(*_data);
    }

    const T& getVal() const {
        return _getVal(*_data);
    }

    T* getPtr(){
        return _getPtr(*_data);
    }

    const T* const getPtr() const {
        return _getPtr(*_data);
    }

private:
    std::shared_ptr<std::variant<T*, std::shared_ptr<T>>> _data;

    static inline auto& _getVal(auto& data){
        switch (data.index()){
            case 0: return *std::get<0>(data);
            case 1: return *std::get<1>(data);
            default: throw std::runtime_error("Ptr internal error");;
        }
    }

    static inline auto* _getPtr(auto& data){
        switch (data.index()){
            case 0: return std::get<0>(data);
            case 1: return std::get<1>(data).get();
            default: throw std::runtime_error("Ptr internal error");
        }
    }
};

template<class>
struct is_ptr : std::false_type {};

template<class T>
struct is_ptr<Ptr<T>> : std::true_type {
    using type = T;
};

}