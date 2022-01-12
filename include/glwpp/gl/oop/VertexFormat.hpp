#pragma once

#include "glwpp/gl/api/types.hpp"
#include "glwpp/gl/enums/DataType.hpp"

namespace glwpp {

class VertexFormat {
public:
    VertexFormat(DataType type, Int size, Bool normalized, UInt offset) :
        type(type),
        size(size),
        normalized(normalized),
        offset(offset){
    }

    const DataType type;
    const Int size;
    const Bool normalized;
    const UInt offset;
};

}