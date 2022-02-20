#pragma once

#include <memory>
#include <variant>

#include "glwpp/gl/types.hpp"

namespace glwpp {

template<class T>
class VopBase {
    using Container = std::variant<T, T*, std::shared_ptr<T>>;
public:
    VopBase(const T& data){_data = std::make_shared<Container>(data);}
    VopBase(const T* const data){_data = std::make_shared<Container>(data);}
    VopBase(std::shared_ptr<T> data){_data = std::make_shared<Container>(data);}
    virtual ~VopBase(){};

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
    std::shared_ptr<Container> _data;

    static inline auto& _getVal(auto& data){
        switch (data.index()){
            case 0: return std::get<0>(data);
            case 1: return *std::get<1>(data);
            case 2: return *std::get<2>(data);
            default: throw std::runtime_error("Vop internal error");
        }
    }

    static inline auto* _getPtr(auto& data){
        switch (data.index()){
            case 0: return &std::get<0>(data);
            case 1: return std::get<1>(data);
            case 2: return std::get<2>(data).get();
            default: throw std::runtime_error("Vop internal error");
        }
    }
};

template<class T>
class Vop : public VopBase<T> {
public:
    Vop(const T& data) : VopBase<T>(data){};
    Vop(const T* data) : VopBase<T>(data){};
    Vop(std::shared_ptr<T> data) : VopBase<T>(data){};
};

// template<>
// class Vop<gl::IntPtr> : public VopBase<gl::IntPtr> {
// public:
//     Vop(const gl::Int& data) : VopBase<gl::IntPtr>(data){};
//     Vop(const gl::IntPtr& data) : VopBase<gl::IntPtr>(data){};
//     Vop(const gl::IntPtr* const data) : VopBase<gl::IntPtr>(data){};
//     Vop(std::shared_ptr<gl::IntPtr> data) : VopBase<gl::IntPtr>(data){};
// };

template<class>
struct is_vop : std::false_type {};

template<class T>
struct is_vop<Vop<T>> : std::true_type {
    using type = T;
};

// template<> Vop<gl::IntPtr>::Vop<gl::IntPtr>(const gl::IntPtr& data){}

// template<>
// class Vop<gl::IntPtr> {

// };

} // namespace glwpp
