#pragma once

#include "glwpp/ctx/load/Attribute.hpp"
#include "glwpp/utils/Utils.hpp"

namespace glwpp::ctx {


template<class ... Attribs>
class Vertex {
    static_assert(var_and<is_base_of_template<Attribute, Attribs>::value...>);
    static_assert(sizeof...(Attribs) <= 16);
    static_assert((sizeof(Attribs) + ...) <= 16 * 4 * sizeof(float));

public:
    using Tuple = std::tuple<Attribs...>;

    template<size_t N>
    using Attribute = typename std::tuple_element_t<N, Tuple>;

    Tuple attributes;

    template<size_t N>
    std::tuple_element_t<N, Tuple> get() const {
        return std::get<N>(attributes);
    }

    template<size_t N, class ... T>
    void set(T ... v){
        // return std::get<N>(attributes).set(v...);
    }

    static void bindAttributes(){
        GLuint loc = 0;
        size_t offset = 0;
        ([&](){
            Attribs::Meta::enable(loc, sizeof(Vertex), offset);
            loc++;
            offset += sizeof(Attribs);
        }(), ...);
    }
};

}