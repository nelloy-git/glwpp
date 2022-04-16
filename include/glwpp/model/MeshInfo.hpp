#pragma once

#include <tuple>

#include "glwpp/gl/enums/DataType.hpp"

#include "glwpp/model/MeshConfig.hpp"

struct aiMesh;
template<class T>
struct aiVector3t;
template<class T>
struct aiColor4t;

namespace glwpp {

class MeshInfo {
public:
    using Offset = std::tuple<float, float, float, float>;

    MeshInfo();
    virtual ~MeshInfo();

    void apply(const MeshConfig& config, const aiMesh& ai_mesh);

    const size_t& getTotalBytes() const;
    const bool& isEnabled(const MeshAttribute& attribute) const;
    const gl::DataType& getType(const MeshAttribute& attribute) const;
    const MeshAttributeSize& getSize(const MeshAttribute& attribute) const;
    const size_t& getOffset(const MeshAttribute& attribute) const;
    const size_t& getStride(const MeshAttribute& attribute) const;
    
    const Offset& getValueOffset(const MeshAttribute& attribute) const;
    const float getValueOffset(const MeshAttribute& attribute, size_t i) const;
    const float& getValueMultiplier(const MeshAttribute& attribute) const;

    aiVector3t<float> norm(const MeshAttribute& attribute, const aiVector3t<float>& vec) const;
    aiColor4t<float> norm(const MeshAttribute& attribute, const aiColor4t<float>& vec) const;

private:

    size_t _total_bytes;

    bool _enabled[MESH_ATTRIBUTE_COUNT];            // Do model have attribute
    gl::DataType _type[MESH_ATTRIBUTE_COUNT];       // gl memory type
    MeshAttributeSize _size[MESH_ATTRIBUTE_COUNT];  // number of values
    size_t _offset[MESH_ATTRIBUTE_COUNT];           // gl memory relative offset
    size_t _stride[MESH_ATTRIBUTE_COUNT];           // gl memory stride

    Offset _value_offset[MESH_ATTRIBUTE_COUNT]; // all attribute values are normalized [0, 1]. can be used to restore original values in shader
    float _value_mult[MESH_ATTRIBUTE_COUNT];                                    // all attribute values are normalized [0, 1]. can be used to restore original values in shader

    void _applyOffset(const std::tuple<float, float, float, float>& vals);
};

} // namespace glwpp