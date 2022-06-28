#include "glwpp/Drawer.hpp"

#include "glad/gl.h"
#include "magic_enum.hpp"
#include "glm/glm.hpp"

using namespace glwpp;
using namespace glwpp::utils;

Drawer::Drawer(const wptr<Context>& wctx,
               const Val<const SrcLoc> src_loc) :
    Program(wctx, src_loc),
    _data(new DrawerData(wctx, src_loc)){
}

Drawer::~Drawer(){
}

Camera& Drawer::camera(){
    return _data->camera;
}

const Camera& Drawer::camera() const {
    return _data->camera;
}

bool Drawer::bindMeshAttributes(const Val<const MeshAttributeBindings>& bindings,
                                const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, src_loc, &Drawer::_bindMeshAttributes, bindings, id(), Val<DrawerData>(_data));
}

bool Drawer::bindUniformBlocks(const Val<const UniformBlockBindings>& bindings,
                               const Val<const SrcLoc>& src_loc, bool check_ctx){
    return executeInContext(check_ctx, src_loc, &Drawer::_bindUniformBlocks, bindings, id(), Val<DrawerData>(_data));
}

void Drawer::_bindMeshAttributes(const MeshAttributeBindings& bindings,
                                 const gl::UInt& id, DrawerData& data){
    data.attr_bindings.for_each([&](auto attr){
        if (data.attr_bindings[attr] == bindings[attr]){
            return;
        }

        auto attr_index = data.attr_bindings.enum_index(attr);
        glBindAttribLocation(id, attr_index, bindings[attr].data());
        data.attr_bindings[attr] = bindings[attr];
    });
    glLinkProgram(id);
}

void Drawer::_bindUniformBlocks(const Val<const UniformBlockBindings>& bindings,
                                const gl::UInt& id, DrawerData& data){
    data.uniform_block_bindings.for_each([&](auto unif){
        auto name = (*bindings)[unif];
        if (data.uniform_block_bindings[unif] == name){
            return;
        }

        auto unif_index = data.uniform_block_bindings.enum_index(unif);
        auto loc = glGetUniformBlockIndex(id, name.c_str());
        glUniformBlockBinding(id, loc, unif_index);
        const gl::Buffer& buffer = _getUniformBlockBuffer<unif>(data);
        buffer.bindUniformBase((gl::UInt)unif_index);

        std::cout << "Loc: " << loc << std::endl;
        std::cout << "Buffer: " << *buffer.id() << std::endl;
    });
}

template<DrawerUniformBlock U>
const gl::Buffer& Drawer::_getUniformBlockBuffer(DrawerData& data){
    if constexpr (U == DrawerUniformBlock::Camera){
        return data.camera.buffer();
    } else {
        throw std::runtime_error("Unknown DrawerUniformBlock");
    }
}

// void Drawer::bindMeshAttribute(const MeshAttribute& attr, const std::string& name){
//     _program.getAttributeLocation(_attr_binding[attr], name);
// } 

// void Drawer::bindMeshAttribute(const MeshAttribute& attr, const gl::Int& location){
//     constexpr auto F = [](gl::Int* dst, gl::Int location){
//         *dst = location;
//     };
//     _program.executeCustomCode<F>(Ptr<gl::Int>(_attr_binding[attr]), Val(location));
// }

// void Drawer::bindUniform(const Uniform& uniform, const std::string& name){
//     // auto unif_i = static_cast<size_t>(uniform);
//     // _program.getUniformLocation(_uniform_location[unif_i], name);

//     // if (uniform == Uniform::Camera){
//     //     auto index = make_sptr<gl::UInt>();
//     //     _program.getUniformBlockLocation(index, name);
//     //     camera.bindBufferIndex(index);
//     // }
// }

// void Drawer::bindUniform(const Uniform& uniform, const gl::Int& location){
//     // auto unif_i = static_cast<size_t>(uniform);
//     // *_uniform_location[unif_i] = location;
// }

// void Drawer::updateCamera(){
//     static auto cam_unif_i = static_cast<size_t>(Uniform::Camera);
//     // _pro
//     // _program.setUniformMat4x4F(_uniform_location[cam_unif_i], 
//     //                            std::reinterpret_pointer_cast<gl::Float>(camera.getMatPtr()),
//     //                            false);
// }

// void Drawer::drawModel(const Model& mesh){
//     // static auto attributes = magic_enum::enum_values<MeshAttribute>();
//     // for (size_t i = 0; i < attributes.size(); ++i){

//     // }

//     // _program.setUniform4F(_uniform_location[])
// }