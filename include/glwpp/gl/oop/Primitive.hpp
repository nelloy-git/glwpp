#pragma once

#include <optional>
#include <variant>

#include "glwpp/gl/enums/DataType.hpp"
#include "glwpp/gl/enums/DrawMode.hpp"
#include "glwpp/gl/oop/Buffer.hpp"
#include "glwpp/utils/Utils.hpp"

namespace glwpp::gl {

template<class V>
class VertexArray {
    static_assert(is_base_of_template<Vertex, V>::value);

public:
    using VertexBuffer = Buffer<V>;
    using IndexBuffer = std::variant<Buffer<UByte>, Buffer<UShort>, Buffer<UInt>>;

    VertexArray(const std::vector<V> &vertices) :
        _id_keeper(_newId(), _deleteId),
        _id(*_id_keeper),
        _vertex_count(vertices.size()),
        _vertices(new VertexBuffer(vertices)),
        _indices_type(std::nullopt),
        _indices(std::nullopt),
        _draw_func(&_drawUnindexedInstaced){
    }

    VertexArray(const std::vector<V> &vertices,
                const std::vector<unsigned char> &indices) :
        _id_keeper(_newId(), _deleteId),
        _id(*_id_keeper),
        _vertex_count(indices.size()),
        _vertices(new VertexBuffer(vertices)),
        _indices_type(DataType::UByte),
        _indices(new Buffer<unsigned char>(indices)),
        _draw_func(&_drawIndexedInstanced){
    }

    VertexArray() :
        _id_keeper(_newId(), _deleteId),
        _id(*_id_keeper),
        _vertex_count(indices.size()),
        _vertices(new VertexBuffer(vertices)),
        _indices_type(DataType::UByte),
        _indices(new Buffer<unsigned char>(indices)),
        _draw_func(&_drawIndexedInstanced){
    }

    inline void draw(DrawMode mode, Sizei count = 1){
        _draw_func(DrawMode, count);
    }

private:
    const sptr<UInt> _id_keeper;
    const UInt _id;
    const size_t _vertex_count;
    const uptr<VertexBuffer> _vertices;
    const std::optional<DataType> _indices_type;
    const std::optional<uptr<IndexBuffer>> _indices;

    void (VertexArray<V>::*_draw_func)(DrawMode, Sizei) const;

    void _drawUnindexedInstaced(DrawMode mode, Sizei count) const {
        glBindVertexArray(id);
        glDrawArraysInstanced(gl(mode), 0, _draw_count, count);
        if constexpr (GL_DEBUG) printErr(&glDrawArraysInstanced);
    }

    void _drawIndexedInstanced(DrawMode mode, Sizei count) const {
        glBindVertexArray(id);
        glDrawElementsInstanced(gl(mode), _draw_count, gl(_indices_type), (void*)0, count);
        if constexpr (GL_DEBUG) printErr(&glDrawElementsInstanced);
    }

    void _build(){

    }
    
    static UInt *_newId(){
        auto id = new UInt;
        CreateVertexArrays(1, id);
        return id;
    };

    static void _deleteId(UInt *id){
        DeleteVertexArrays(1, id);
        delete id;
    }
};
    
} // namespace glwpp::gl
