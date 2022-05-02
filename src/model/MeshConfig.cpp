#include "glwpp/model/MeshConfig.hpp"

using namespace glwpp;

MeshConfig::MeshConfig(){
    static const size_t enum_size = GetMeshAttributeEnumSize();
    for (size_t i = 0; i < enum_size; ++i){
        _loc.push_back(0);
        _size.push_back(MeshAttributeSize::None);
        _epsilon.push_back(1);
    }
}

MeshConfig::MeshConfig(const MeshConfig& other){
    static const size_t enum_size = GetMeshAttributeEnumSize();
    for (size_t i = 0; i < enum_size; ++i){
        _loc.push_back(0);
        _size.push_back(other._size[i]);
        _epsilon.push_back(other._epsilon[i]);
    }
}

const gl::UInt& MeshConfig::getLocation(const MeshAttribute& attribute) const {
    return _loc[_get_i(attribute)];
}

void MeshConfig::setLocation(const MeshAttribute& attribute, const gl::UInt& location){
    _loc[_get_i(attribute)] = location;
}

const float& MeshConfig::getCompression(const MeshAttribute& attribute) const {
    return _epsilon[_get_i(attribute)];
}

void MeshConfig::setCompression(const MeshAttribute& attribute, const float& epsilon){
    _epsilon[_get_i(attribute)] = epsilon;
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
