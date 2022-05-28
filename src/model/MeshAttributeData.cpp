#include "glwpp/model/MeshAttributeData.hpp"

#include "magic_enum.hpp"

template<glwpp::MeshAttributeType T, glwpp::MeshAttributeSize S>
using Attr = glwpp::MeshAttributeData<T, S>;

size_t glwpp::getMeshAttributeDataBytes(const MeshAttributeType& type, const MeshAttributeSize& size){
    using namespace magic_enum;
    using T = MeshAttributeType;
    using S = MeshAttributeSize;

    switch (type){
    case T::UInt_11_11_10:
        switch (size){
        case S::Vec3: return sizeof(Attr<T::UInt_11_11_10, S::Vec3>);
        default: throw std::logic_error("Invalid MeshAttributeSize for UInt_11_11_10");
    };
    case T::UInt_10_10_10_2:
        switch (size){
        case S::Vec4: return sizeof(Attr<T::UInt_10_10_10_2, S::Vec4>);
        default: throw std::logic_error("Invalid MeshAttributeSize for UInt_10_10_10_2");
    };
    case T::UByte:
        switch (size){
        case S::Scalar: return sizeof(Attr<T::UByte, S::Scalar>);
        case S::Vec2: return sizeof(Attr<T::UByte, S::Vec2>);
        case S::Vec3: return sizeof(Attr<T::UByte, S::Vec3>);
        case S::Vec4: return sizeof(Attr<T::UByte, S::Vec4>);
        default: throw std::logic_error("Invalid MeshAttributeSize for UByte");
    };
    case T::UShort:
        switch (size){
        case S::Scalar: return sizeof(Attr<T::UShort, S::Scalar>);
        case S::Vec2: return sizeof(Attr<T::UShort, S::Vec2>);
        case S::Vec3: return sizeof(Attr<T::UShort, S::Vec3>);
        case S::Vec4: return sizeof(Attr<T::UShort, S::Vec4>);
        default: throw std::logic_error("Invalid MeshAttributeSize for UShort");
    };
    case T::Float:
        switch (size){
        case S::Scalar: return sizeof(Attr<T::Float, S::Scalar>);
        case S::Vec2: return sizeof(Attr<T::Float, S::Vec2>);
        case S::Vec3: return sizeof(Attr<T::Float, S::Vec3>);
        case S::Vec4: return sizeof(Attr<T::Float, S::Vec4>);
        default: throw std::logic_error("Invalid MeshAttributeSize for Float");
    };
    
    default:
        switch (size){
        case S::Scalar: throw std::logic_error("Invalid MeshAttributeType for Scalar");
        case S::Vec2: throw std::logic_error("Invalid MeshAttributeType for Vec2");
        case S::Vec3: throw std::logic_error("Invalid MeshAttributeType for Vec3");
        case S::Vec4: throw std::logic_error("Invalid MeshAttributeType for Vec4");
        default: throw std::logic_error("Invalid MeshAttributeType and MeshAttributeSize");
    };
    }
}