#include "glwpp/Drawer.hpp"

#include "glad/gl.h"
#include "magic_enum.hpp"
#include "glm/glm.hpp"

using namespace glwpp;
using namespace glwpp::utils;

sptr<Drawer> Drawer::make(const sptr<Context>& ctx,
                          const Val<const SrcLoc> src_loc){
    return sptr<Drawer>(new Drawer(ctx, src_loc));
}

Drawer::Drawer(const sptr<Context>& ctx,
               const Val<const SrcLoc> src_loc) :
    Program(ctx, src_loc),
    _camera(ctx, src_loc){
}

Drawer::~Drawer(){
}

Camera& Drawer::camera(){
    return _camera;
}

const Camera& Drawer::camera() const {
    return _camera;
}

bool Drawer::bindMeshAttributes(const Val<const MeshAttributeBindings>& bindings,
                                const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Drawer::bindMeshAttributes, bindings, src_loc);
    }

    _attr_bindings.for_each([&](auto attr){
        auto& name = (*bindings)[attr];
        if (_attr_bindings[attr] == name){
            return;
        }

        auto attr_index = gl::UInt(_attr_bindings.enum_index(attr));
        glBindAttribLocation(id(), attr_index, name.data());
        _attr_bindings[attr] = name;
    });
    link();

    return true;
}

bool Drawer::bindUniformBlocks(const Val<const UniformBlockBindings>& bindings,
                               const Val<const SrcLoc>& src_loc){
    if (!isContextThread()){
        return executeMethodInContext(&Drawer::bindUniformBlocks, bindings, src_loc);
    }

    _uniform_block_bindings.for_each([&](auto unif){
        auto name = (*bindings)[unif];
        if (_uniform_block_bindings[unif] == name){
            return;
        }

        auto unif_index = gl::UInt(_uniform_block_bindings.enum_index(unif));
        auto loc = glGetUniformBlockIndex(id(), name.c_str());
        glUniformBlockBinding(id(), loc, unif_index);
        const auto& buffer = _getUniformBlockBuffer<unif>();
        buffer->bindUniformBase((gl::UInt)unif_index);

        std::cout << "Loc: " << loc << std::endl;
        std::cout << "Buffer: " << *buffer->id() << std::endl;
    });

    return true;
}

template<DrawerUniformBlock U>
const sptr<gl::Buffer> Drawer::_getUniformBlockBuffer(){
    if constexpr (U == DrawerUniformBlock::Camera){
        return _camera.buffer();
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