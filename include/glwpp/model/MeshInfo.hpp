#pragma once

#include "glwpp/gl/enums/DataType.hpp"

namespace glwpp {

static const size_t MESH_MAX_TEX_COORDS = 8;
static const size_t MESH_MAX_VERT_COLORS = 8;

class MeshAttributeInfo {
public:
    MeshAttributeInfo(const gl::DataType& type) :
        enabled(false), type(type), size(0), offset(0){
    };
    MeshAttributeInfo(const MeshAttributeInfo& other) :
        enabled(other.enabled), type(other.type), size(other.size), offset(other.size){
    };

    bool enabled;               // Do model have attribute
    const gl::DataType type;    // gl memory type
    size_t size;                // gl memory size
    size_t offset;              // gl memory offset

    float value_offset;         // all attribute values are normalized [0, 1]. can be used to restore original values in shader
    float value_mult;           // all attribute values are normalized [0, 1]. can be used to restore original values in shader
};

class MeshInfo {
public:
    MeshInfo(const gl::DataType& position_type,
             const gl::DataType& normal_type,
             const gl::DataType& tangent_type,
             const gl::DataType& bitangent_type,
             const gl::DataType& texture_coord_type,
             const gl::DataType& color_type) :
        position(position_type),
        normal(normal_type),
        tangent(tangent_type),
        bitangent(bitangent_type),
        texture_coord{MeshAttributeInfo(texture_coord_type),
                      MeshAttributeInfo(texture_coord_type), 
                      MeshAttributeInfo(texture_coord_type), 
                      MeshAttributeInfo(texture_coord_type), 
                      MeshAttributeInfo(texture_coord_type),
                      MeshAttributeInfo(texture_coord_type), 
                      MeshAttributeInfo(texture_coord_type),
                      MeshAttributeInfo(texture_coord_type)},
        color{MeshAttributeInfo(color_type),
              MeshAttributeInfo(color_type), 
              MeshAttributeInfo(color_type), 
              MeshAttributeInfo(color_type), 
              MeshAttributeInfo(color_type),
              MeshAttributeInfo(color_type), 
              MeshAttributeInfo(color_type),
              MeshAttributeInfo(color_type)}{
    }
    MeshInfo(const MeshInfo& other) :
        position(other.position),
        normal(other.normal),
        tangent(other.tangent),
        bitangent(other.bitangent),
        texture_coord{other.texture_coord[0],
                      other.texture_coord[1],
                      other.texture_coord[2],
                      other.texture_coord[3],
                      other.texture_coord[4],
                      other.texture_coord[5],
                      other.texture_coord[6],
                      other.texture_coord[7]},
        color{other.color[0],
              other.color[1],
              other.color[2],
              other.color[3],
              other.color[4],
              other.color[5],
              other.color[6],
              other.color[7]}{
    }

    size_t size(){
        size_t s = position.size + normal.size + tangent.size + bitangent.size;
        for (int i = 0; i < MESH_MAX_TEX_COORDS; ++i){
            s += texture_coord[i].size;
        }
        for (int i = 0; i < MESH_MAX_VERT_COLORS; ++i){
            s += color[i].size;
        }
        return s;
    }

    MeshAttributeInfo position;
    MeshAttributeInfo normal;
    MeshAttributeInfo tangent;
    MeshAttributeInfo bitangent;
    MeshAttributeInfo texture_coord[MESH_MAX_TEX_COORDS];
    MeshAttributeInfo color[MESH_MAX_VERT_COLORS];
};

} // namespace glwpp