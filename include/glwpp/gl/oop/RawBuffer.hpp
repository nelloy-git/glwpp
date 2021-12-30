#pragma once

#include "glwpp/utils/Ptr.hpp"
#include "glwpp/gl/api/gl_46.hpp"
#include "glwpp/gl/enums/BufferType.hpp"
#include "glwpp/gl/enums/BufferUsage.hpp"

namespace glwpp::gl {

class RawBuffer {
public:
    RawBuffer();
    RawBuffer(GLsizeiptr size,
              const void *data = nullptr,
              BufferUsage usage = BufferUsage::DynamicDraw);
    RawBuffer(const RawBuffer&);
    RawBuffer(const RawBuffer&&);

    virtual ~RawBuffer();

    GLuint id();
    BufferUsage usage();
    GLsizeiptr size();

    void bind(BufferType target) const;
    void reallocate(GLsizeiptr size);
    void reallocate(const void *data, GLsizeiptr size);
    void reallocate(const void *data, GLsizeiptr size, BufferUsage usage);
    void resize(GLsizeiptr size);
    void write(const void *src, GLintptr offset, GLsizeiptr size);
    void read(void *dst, GLintptr offset, GLsizeiptr size) const;

protected:
    const sptr<GLuint> _id_keeper;
    const GLuint _id;
    BufferUsage _usage;
    GLsizeiptr _size;

    static GLuint *_newId();
    static void _deleteId(GLuint *id);
};

}