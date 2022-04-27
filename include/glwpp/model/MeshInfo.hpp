#pragma once

#include <tuple>

#include "glm/glm.hpp"

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
    MeshInfo();
    virtual ~MeshInfo();

    void apply(const MeshConfig& config, const aiMesh& ai_mesh);

    const size_t& getTotalBytes() const;
    const bool& isEnabled(const MeshAttribute& attribute) const;
    const gl::DataType& getType(const MeshAttribute& attribute) const;
    const MeshAttributeSize& getSize(const MeshAttribute& attribute) const;
    const size_t& getByteOffset(const MeshAttribute& attribute) const;
    const size_t& getByteStride(const MeshAttribute& attribute) const;
    
    const glm::vec4& getValueOffset(const MeshAttribute& attribute) const;
    const float& getValueMultiplier(const MeshAttribute& attribute) const;

    glm::vec3 norm(const MeshAttribute& attribute, const aiVector3t<float>& vec) const;
    glm::vec3 norm(const MeshAttribute& attribute, const glm::vec3& vec) const;
    glm::vec4 norm(const MeshAttribute& attribute, const aiColor4t<float>& vec) const;
    glm::vec4 norm(const MeshAttribute& attribute, const glm::vec4& vec) const;

private:
    struct AttribInfo {
        bool enabled;
        gl::DataType type;
        MeshAttributeSize size;
        size_t byte_offset;
        size_t byte_stride;

        glm::vec4 value_offset;
        float value_mult;
    };

    size_t _bytes_total;
    std::vector<AttribInfo> _attrib_info;

    AttribInfo& _get_info(const MeshAttribute& attribute);
    const AttribInfo& _get_info(const MeshAttribute& attribute) const;

    // bool _enabled[MeshAttributeEnumSize];            // Do model have attribute
    // gl::DataType _type[MeshAttributeEnumSize];       // gl memory type
    // MeshAttributeSize _size[MeshAttributeEnumSize];  // number of values
    // size_t _offset[MeshAttributeEnumSize];           // gl memory relative offset
    // size_t _stride[MeshAttributeEnumSize];           // gl memory stride

    // glm::vec4 _value_offset[MeshAttributeEnumSize];  // all attribute values are normalized [0, 1]. can be used to restore original values in shader
    // float _value_mult[MeshAttributeEnumSize];        // all attribute values are normalized [0, 1]. can be used to restore original values in shader
};

} // namespace glwpp