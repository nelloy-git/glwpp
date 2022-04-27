#include "glwpp/model/MeshConfig.hpp"

using namespace glwpp;

MeshConfig::MeshConfig(){
    static const size_t enum_size = GetMeshAttributeEnumSize();
    for (size_t i = 0; i < enum_size; ++i){
        _size.push_back(MeshAttributeSize::None);
        _type.push_back(gl::DataType::Float);
    }
}

MeshConfig::MeshConfig(const MeshConfig& other){
    static const size_t enum_size = GetMeshAttributeEnumSize();
    for (size_t i = 0; i < enum_size; ++i){
        _size.push_back(other._size[i]);
        _type.push_back(other._type[i]);
    }
}

const gl::DataType& MeshConfig::getType(const MeshAttribute& attribute) const {
    return _type[_get_i(attribute)];
}

void MeshConfig::setType(const MeshAttribute& attribute, const gl::DataType& type){
    _type[_get_i(attribute)] = type;
}

const MeshAttributeSize& MeshConfig::getSize(const MeshAttribute& attribute) const {
    return _size[_get_i(attribute)];
}

void MeshConfig::setSize(const MeshAttribute& attribute, const MeshAttributeSize& size){
    _size[_get_i(attribute)] = size;
}

size_t MeshConfig::_get_i(const MeshAttribute& attribute){
    return static_cast<size_t>(attribute);
}
