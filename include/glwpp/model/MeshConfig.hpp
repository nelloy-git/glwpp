#pragma once

#include <vector>

#include "glwpp/gl/enums/DataType.hpp"

#include "glwpp/model/MeshAttribute.hpp"

namespace glwpp {

class MeshConfig {
public:
    MeshConfig();
    MeshConfig(const MeshConfig& other);

    const gl::DataType& getType(const MeshAttribute& attribute) const;
    void setType(const MeshAttribute& attribute, const gl::DataType& type);

    const MeshAttributeSize& getSize(const MeshAttribute& attribute) const;
    void setSize(const MeshAttribute& attribute, const MeshAttributeSize& size);

private:
    std::vector<MeshAttributeSize> _size;
    std::vector<gl::DataType> _type;

    static size_t _get_i(const MeshAttribute& attribute);
};

} // namespace glwpp