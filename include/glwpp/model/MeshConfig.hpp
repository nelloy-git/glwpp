#pragma once

#include <vector>

#include "glwpp/gl/enums/DataType.hpp"

#include "glwpp/model/MeshAttribute.hpp"

namespace glwpp {

class MeshConfig {
public:
    MeshConfig();
    MeshConfig(const MeshConfig& other);

    // if disabled data wont be loaded to gpu
    const bool& isEnabled() const;
    void enable(const bool& enable);

    // shader bindomgs for attribute
    const gl::UInt& getLocation(const MeshAttribute& attribute) const;
    void setLocation(const MeshAttribute& attribute, const gl::UInt& location);

    // Buffer size optimization 0..1
    const float& getCompression(const MeshAttribute& attribute) const;
    void setCompression(const MeshAttribute& attribute, const float& epsilon);

    // shader data for attribute (vec1, vec2, vec3 or vec4)
    const MeshAttributeSize& getSize(const MeshAttribute& attribute) const;
    void setSize(const MeshAttribute& attribute, const MeshAttributeSize& size);

private:
    std::vector<gl::UInt> _loc;
    std::vector<MeshAttributeSize> _size;
    std::vector<float> _epsilon;

    static size_t _get_i(const MeshAttribute& attribute);
};

} // namespace glwpp