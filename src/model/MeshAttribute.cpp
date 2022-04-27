#include "glwpp/model/MeshAttribute.hpp"

#include "magic_enum.hpp"

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

size_t glwpp::GetMeshAttributeEnumSize(){
    static const size_t size = magic_enum::enum_count<MeshAttribute>();
    static_assert(size <= 16, "Too many mesh attributes");
    static_assert(is_sequence<MeshAttribute>(), "MeshAttribute is not sequence");

    return size;
}
