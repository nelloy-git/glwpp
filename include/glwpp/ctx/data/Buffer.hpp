#pragma once

#include "glwpp/ctx/data/Data.hpp"
#include "glwpp/enums/gl/ErrorGL.hpp"
#include "glwpp/enums/gl/BufferTypeGL.hpp"
#include "glwpp/enums/gl/BufferUsageGL.hpp"

namespace glwpp::ctx {

template<BufferTypeGL BT>
class Buffer : public Data {
public:
    // zero-sized buffer
    explicit Buffer(BufferUsageGL usage) :
        Data(_newId()),
        usage(usage){
    };

    virtual ~Buffer(){
        glDeleteBuffers(1, &id);
    };

    inline void bind() const {
        glBindBuffer(gl(BT), id);
    };

    inline void write(const void *src, GLintptr gl_offset, GLsizeiptr size){
        glNamedBufferSubData(id, gl_offset, size, src);
        if constexpr (GL_DEBUG) printErr(&glNamedBufferSubData);
    };

    inline void read(void *dst, GLintptr gl_offset, GLsizeiptr size) const {
        glGetNamedBufferSubData(id, gl_offset, size, dst);
        if constexpr (GL_DEBUG) printErr(&glGetNamedBufferSubData);
    };

    // Content will be cleared.
    inline void resize(GLsizeiptr size){
        glNamedBufferData(id, size, nullptr, gl(usage));
        _size = size;
    }

    inline virtual GLsizeiptr size(){
        return _size;
    }

    const BufferUsageGL usage;

protected:
    inline static GLuint _newId(){
        GLuint id;
        glGenBuffers(1, &id);
        return id;
    };

    GLsizeiptr _size;
};

}