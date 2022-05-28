#include "glwpp/Drawer.hpp"

#include "magic_enum.hpp"
#include "glm/glm.hpp"

using namespace glwpp;

Drawer::Drawer(const Program& program) :
    _program(program),
    camera(program.getWCtx()){
    // camera.setPosition({0, 0, 0});

    // static const size_t attribute_enum_size = GetAttributeEnumSize();
    // for (int i = 0; i < attribute_enum_size; ++i){
    //     _attribute_location.emplace_back(new gl::Int);
    // }
    
    // static const size_t uniform_enum_size = GetUniformEnumSize();
    // for (int i = 0; i < uniform_enum_size; ++i){
    //     _uniform_location.emplace_back(new gl::Int);
    // }
}

Drawer::~Drawer(){
}

void Drawer::bindMeshAttribute(const MeshAttribute& attr, const std::string& name){
    _program.getAttributeLocation(_attr_binding[attr], name);
} 

void Drawer::bindMeshAttribute(const MeshAttribute& attr, const gl::Int& location){
    constexpr auto F = [](gl::Int* dst, gl::Int location){
        *dst = location;
    };
    _program.executeCustomCode<F>(Ptr<gl::Int>(_attr_binding[attr]), Val(location));
}

void Drawer::bindUniform(const Uniform& uniform, const std::string& name){
    // auto unif_i = static_cast<size_t>(uniform);
    // _program.getUniformLocation(_uniform_location[unif_i], name);

    // if (uniform == Uniform::Camera){
    //     auto index = make_sptr<gl::UInt>();
    //     _program.getUniformBlockLocation(index, name);
    //     camera.bindBufferIndex(index);
    // }
}

void Drawer::bindUniform(const Uniform& uniform, const gl::Int& location){
    // auto unif_i = static_cast<size_t>(uniform);
    // *_uniform_location[unif_i] = location;
}

void Drawer::updateCamera(){
    static auto cam_unif_i = static_cast<size_t>(Uniform::Camera);
    // _pro
    // _program.setUniformMat4x4F(_uniform_location[cam_unif_i], 
    //                            std::reinterpret_pointer_cast<gl::Float>(camera.getMatPtr()),
    //                            false);
}

void Drawer::drawModel(const Model& mesh){
    // static auto attributes = magic_enum::enum_values<MeshAttribute>();
    // for (size_t i = 0; i < attributes.size(); ++i){

    // }

    // _program.setUniform4F(_uniform_location[])
}