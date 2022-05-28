#include "glwpp/model/MeshVertexConfig.hpp"

#include "magic_enum.hpp"

using namespace glwpp;

MeshVertexConfig::MeshVertexConfig(){}

const bool& MeshVertexConfig::isEnabled(const MeshAttribute& attribute) const {
    return _attr_cfg[attribute].enabled;
}

void MeshVertexConfig::enable(const MeshAttribute& attribute, const bool& enable){
    _attr_cfg[attribute].enabled = enable;
}

const std::optional<MeshAttributeType>& MeshVertexConfig::getForcedType(const MeshAttribute& attribute) const {
    return _attr_cfg[attribute].forced_type;
}

void MeshVertexConfig::setForcedType(const MeshAttribute& attribute, const std::optional<MeshAttributeType>& type){
    _attr_cfg[attribute].forced_type = type;
}

const double& MeshVertexConfig::getCompression(const MeshAttribute& attribute) const {
    return _attr_cfg[attribute].compress;
}

void MeshVertexConfig::setCompression(const MeshAttribute& attribute, const double& compress){
    _attr_cfg[attribute].compress = compress;
}

const MeshAttributeSize& MeshVertexConfig::getSize(const MeshAttribute& attribute) const {
    return _attr_cfg[attribute].size;
}

void MeshVertexConfig::setSize(const MeshAttribute& attribute, const MeshAttributeSize& size){
    _attr_cfg[attribute].size = size;
}