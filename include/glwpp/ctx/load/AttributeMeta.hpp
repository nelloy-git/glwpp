#pragma once

#include "glwpp/enums/gl/DataTypeGL.hpp"

namespace glwpp::ctx {

template<DataTypeGL T, size_t S, bool N>
class AttributeMeta {
    static constexpr bool _is_3_components_only = T == DataTypeGL::_uint_10_11_11;
    static constexpr bool _is_4_components_only = T == DataTypeGL::_int_2_10_10_10
                                               || T == DataTypeGL::_uint_2_10_10_10;

    static_assert(S >= 1 && S <=4);
    static_assert(!(_is_3_components_only && S != 3));
    static_assert(!(_is_4_components_only && S != 4));
    
public:
    static constexpr DataTypeGL Type = T;  // OpenGL data type
    static constexpr size_t Size = S;      // OpenGL data size 
    static constexpr bool Norm = N;        // Should data be normalized GPU side
    static constexpr bool Packed = T == DataTypeGL::_uint_10_11_11
                                || T == DataTypeGL::_int_2_10_10_10
                                || T == DataTypeGL::_uint_2_10_10_10;
    static constexpr bool Signed = !(T == DataTypeGL::_ubyte
                                   || T == DataTypeGL::_ushort
                                   || T == DataTypeGL::_uint
                                   || T == DataTypeGL::_uint_10_11_11
                                   || T == DataTypeGL::_uint_2_10_10_10);
                                   
    static void enable(GLuint loc, GLsizei step, size_t offset){
        glEnableVertexAttribArray(loc);
        glVertexAttribPointer(loc, Size, gl(Type),
                              Norm ? GL_TRUE : GL_FALSE,
                              step, (void*)offset);
    }
};

}