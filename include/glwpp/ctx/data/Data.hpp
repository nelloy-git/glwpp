#pragma once

namespace glwpp::ctx {

class Data {
public:
    Data(GLuint id) :
        id(id){
    };
    Data(Data&) = delete;
    Data(Data&&) = delete;
    Data(const Data&) = delete;
    Data(const Data&&) = delete;
    virtual ~Data() = 0;

    const GLuint id;
};
inline Data::~Data(){};

}