#pragma once

#include <optional>
#include <vector>

#include "glwpp/gl/enums/DataType.hpp"

#include "glwpp/model/MeshEnums.hpp"
#include "glwpp/utils/EnumContainer.hpp"

namespace glwpp::model {

class MeshVertexConfig {
public:
    MeshVertexConfig();
    virtual ~MeshVertexConfig();

    // if disabled data wont be loaded to gpu
    const bool& isEnabled(const MeshAttribute& attribute) const;
    void enable(const MeshAttribute& attribute, const bool& enable);

    const std::optional<MeshAttributeType>& getForcedType(const MeshAttribute& attribute) const;
    void setForcedType(const MeshAttribute& attribute, const std::optional<MeshAttributeType>& type);

    // Buffer size optimization 0..1 Ignored if forced type is set
    const double& getCompression(const MeshAttribute& attribute) const;
    void setCompression(const MeshAttribute& attribute, const double& compress);

    // shader data for attribute (vec1, vec2, vec3 or vec4)
    const MeshAttributeSize& getSize(const MeshAttribute& attribute) const;
    void setSize(const MeshAttribute& attribute, const MeshAttributeSize& size);

private:
    struct AttributeConfig {
        bool enabled = false;
        std::optional<MeshAttributeType> forced_type;
        MeshAttributeSize size = MeshAttributeSize::Scalar;
        double compress = 1.0;
    };
    EnumContainer<MeshAttribute, AttributeConfig> _attr_cfg;
};

} // namespace glwpp