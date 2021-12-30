#include "glwpp/gl/oop/RawBuffer.hpp"

using namespace glwpp::gl;

RawBuffer::RawBuffer() :
    _id_keeper(_newId(), _deleteId),
    _id(*_id_keeper),
    _usage(BufferUsage::DynamicDraw),
    _size(0){
}

RawBuffer::RawBuffer(GLsizeiptr size, const void *data, BufferUsage usage) :
    _id_keeper(_newId(), _deleteId),
    _id(*_id_keeper),
    _usage(usage),
    _size(size){
    NamedBufferData(*_id_keeper, size, data, static_cast<GLenum>(usage));
}

RawBuffer::RawBuffer(const RawBuffer &other) : 
    _id_keeper(_newId(), _deleteId),
    _id(*_id_keeper),
    _usage(other._usage),
    _size(other._size){
    NamedBufferData(_id, _size, nullptr, static_cast<GLenum>(_usage));
    CopyNamedBufferSubData(other._id, _id, 0, 0, _size);
}

RawBuffer::RawBuffer(const RawBuffer &&other) : 
    _id_keeper(other._id_keeper),
    _id(*_id_keeper),
    _usage(other._usage),
    _size(other._size){
}

RawBuffer::~RawBuffer(){
}

GLuint RawBuffer::id(){
    return _id;
}

BufferUsage RawBuffer::usage(){
    return _usage;
}

GLsizeiptr RawBuffer::size(){
    return _size;
}

void RawBuffer::bind(BufferType target) const {
    BindBuffer(static_cast<GLenum>(target), _id);
}

void RawBuffer::reallocate(GLsizeiptr size){
    reallocate(nullptr, size, _usage);
}

void RawBuffer::reallocate(const void *data, GLsizeiptr size){
    reallocate(data, size, _usage);
}

void RawBuffer::reallocate(const void *data, GLsizeiptr size, BufferUsage usage){
    _size = size;
    NamedBufferData(_id, size, data, static_cast<GLenum>(usage));
}

void RawBuffer::resize(GLsizeiptr size){
    RawBuffer swap(*this);
    reallocate(nullptr, size, _usage);
    CopyNamedBufferSubData(swap._id, _id, 0, 0, std::min(swap._size, _size));
}

void RawBuffer::write(const void *src, GLintptr offset, GLsizeiptr size){
    NamedBufferSubData(_id, offset, size, src);
}

void RawBuffer::read(void *dst, GLintptr offset, GLsizeiptr size) const {
    GetNamedBufferSubData(_id, offset, size, dst);
}

GLuint *RawBuffer::_newId(){
    auto id = new GLuint();
    GenBuffers(1, id);
    return id;
}

void RawBuffer::_deleteId(GLuint *id){
    DeleteBuffers(1, id);
    delete id;
}