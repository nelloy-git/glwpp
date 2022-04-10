#pragma once

#include "glwpp/gl/enums/DataType.hpp"

#include "glwpp/model/MeshAttribute.hpp"

namespace glwpp {

class MeshConfig {
public:
    MeshConfig(){
        for (size_t i = 0; i < MESH_ATTRIBUTE_COUNT; ++i){
            _size[i] = MeshAttributeSize::None;
            _type[i] = gl::DataType::Float;
        }
    };

    MeshConfig(const MeshConfig& other){
        for (size_t i = 0; i < MESH_ATTRIBUTE_COUNT; ++i){
            _size[i] = other._size[i];
            _type[i] = other._type[i];
        }
    }

    const gl::DataType& getType(const MeshAttribute& attribute) const {
        return _type[static_cast<size_t>(attribute)];
    }

    void setType(const MeshAttribute& attribute, const gl::DataType& type){
        _type[static_cast<size_t>(attribute)] = type;
    };

    const MeshAttributeSize& getSize(const MeshAttribute& attribute) const {
        return _size[static_cast<size_t>(attribute)];
    }

    void setSize(const MeshAttribute& attribute, const MeshAttributeSize& size){
        _size[static_cast<size_t>(attribute)] = size;
    };

private:
    MeshAttributeSize _size[MESH_ATTRIBUTE_COUNT];
    gl::DataType _type[MESH_ATTRIBUTE_COUNT];
};

} // namespace glwpp