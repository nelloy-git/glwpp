#pragma once

#include "glm/glm.hpp"

#include "glwpp/gl/obj/Buffer.hpp"
#include "glwpp/model/MeshVertexConfig.hpp"
#include "glwpp/utils/EnumContainer.hpp"

struct aiMesh;
template<class T>
struct aiVector3t;
template<class T>
struct aiColor4t;

namespace glwpp::model {

class MeshVertexData {
public:
    MeshVertexData(const wptr<Context>& wctx, const MeshVertexConfig& config, const aiMesh& ai_mesh,
                   const utils::Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{});
    virtual ~MeshVertexData();

    const gl::Buffer& getVertices() const;
    const MeshVertexConfig& getConfig() const;
    const gl::UInt& getBytesPerVertex() const;
    const gl::UInt& getVertexCount() const;

    const bool& isEnabled(const MeshAttribute& attribute) const;
    const MeshAttributeType& getType(const MeshAttribute& attribute) const;
    const MeshAttributeSize& getSize(const MeshAttribute& attribute) const;
    const gl::UInt& getByteOffset(const MeshAttribute& attribute) const;
    const glm::vec4& getValueOffset(const MeshAttribute& attribute) const;
    const float& getValueMultiplier(const MeshAttribute& attribute) const;

private:
    MeshVertexConfig _config;
    gl::Buffer _vertices;

    struct AttributeState {
        bool enabled;           // Do model have attribute
        MeshAttributeType type;
        MeshAttributeSize size;
        float compression;

        gl::UInt byte_offset;     // gl memory relative offset of attribute in vertex
        glm::vec4 value_offset; // all attribute values are normalized [0, 1]. can be used to restore original values in shader
        float value_mult;       // all attribute values are normalized [0, 1]. can be used to restore original values in shader
    };

    gl::UInt _vertex_bytes;
    gl::UInt _vertex_count;

    EnumContainer<MeshAttribute, AttributeState> _attr_state;

    void _fillAttributeStates(const aiMesh& ai_mesh);
    void _fillVertexBuffer(const aiMesh& ai_mesh);
    void _fillVertexBufferAttribute(void* dst, const glm::vec4& vec,
                                    const MeshAttributeType& type, const MeshAttributeSize& size);

    template<typename In, typename Out = In>
    static Out _normalize(const In& vec, const glm::vec4& value_offset, const float& value_mult);

    template<MeshAttribute A>
    glm::vec4 _findValueOffset(const aiMesh& ai_mesh) const;

    template<MeshAttribute A>
    static float _findValueMultiplier(const aiMesh& ai_mesh, const glm::vec4& value_offset);
    
    template<MeshAttribute A>
    static MeshAttributeType _findOptimalType(const aiMesh& ai_mesh, const MeshAttributeSize& size, const float& compression,
                                              const glm::vec4& value_offset, const float& value_mult);

    template<MeshAttribute A>
    static bool _doAiMeshHasAttribute(const aiMesh& ai_mesh);
    
    template<MeshAttribute A>
    static auto _getAiArray(const aiMesh& ai_mesh);
};

} // namespace glwpp