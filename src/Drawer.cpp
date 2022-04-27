#include "glwpp/Drawer.hpp"

#include "magic_enum.hpp"
#include "glm/glm.hpp"

using namespace glwpp;

template<typename E>
static constexpr bool is_sequence(){
    size_t size = magic_enum::enum_count<E>();
    auto list = magic_enum::enum_values<E>();

    using Under = std::underlying_type_t<E>;
    Under min = std::numeric_limits<Under>::infinity();
    Under max = -std::numeric_limits<Under>::infinity();

    for (size_t i = 0; i < list.size(); ++i){
        int val = static_cast<Under>(list[i]);
        max = max > val ? max : val;
        min = min < val ? min : val;

        for (size_t j = i + 1; j < list.size(); ++j){
            int val_j = static_cast<int>(list[j]);
            if (val == val_j){
                return false;
            }
        }
    }
    return (max - min) == size - 1;
}

size_t Drawer::GetAttributeEnumSize(){
    static const size_t size = magic_enum::enum_count<Drawer::Attribute>();
    static_assert(is_sequence<Drawer::Attribute>(), "Drawer::Attribute is not sequence");
    return size;
}

size_t Drawer::GetUniformEnumSize(){
    static const size_t size = magic_enum::enum_count<Drawer::Uniform>();
    static_assert(is_sequence<Drawer::Uniform>(), "Drawer::Uniform is not sequence");
    return size;
}

Drawer::Drawer(const Program& program) :
    _program(program){
    camera.setPosition({0, 0, 0});

    static const size_t attribute_enum_size = GetAttributeEnumSize();
    for (int i = 0; i < attribute_enum_size; ++i){
        _attribute_location.emplace_back(new gl::Int);
    }
    
    static const size_t uniform_enum_size = GetUniformEnumSize();
    for (int i = 0; i < uniform_enum_size; ++i){
        _uniform_location.emplace_back(new gl::Int);
    }
}

Drawer::~Drawer(){
}

void Drawer::bindAttribute(const Attribute& attr, const std::string& name){
    auto attr_i = static_cast<size_t>(attr);
    _program.getAttributeLocation(_attribute_location[attr_i], name);
} 

void Drawer::bindAttribute(const Attribute& attr, const gl::Int& location){
    auto attr_i = static_cast<size_t>(attr);
    *_attribute_location[attr_i] = location;
}

void Drawer::bindUniform(const Uniform& uniform, const std::string& name){
    auto unif_i = static_cast<size_t>(uniform);
    _program.getUniformLocation(_uniform_location[unif_i], name);
}

void Drawer::bindUniform(const Uniform& uniform, const gl::Int& location){
    auto unif_i = static_cast<size_t>(uniform);
    *_uniform_location[unif_i] = location;
}

void Drawer::updateCamera(){
    static auto cam_unif_i = static_cast<size_t>(Uniform::Camera_mat4);
    _program.setUniformMat4x4F(_uniform_location[cam_unif_i], 
                               std::reinterpret_pointer_cast<gl::Float>(camera.getMatPtr()),
                               false);
}

void Drawer::drawMesh(const glwpp::Mesh& mesh){
    static auto attributes = magic_enum::enum_values<MeshAttribute>();
    for (size_t i = 0; i < attributes.size(); ++i){

    }

    // _program.setUniform4F(_uniform_location[])
}