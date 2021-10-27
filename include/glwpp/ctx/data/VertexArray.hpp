#pragma once

#include <variant>

#include "glwpp/ctx/data/Data.hpp"
#include "glwpp/ctx/data/BufferTyped.hpp"
#include "glwpp/ctx/load/Vertex.hpp"
#include "glwpp/enums/gl/DrawModeGL.hpp"
#include "glwpp/utils/Utils.hpp"

namespace glwpp::ctx {

template<class V>
class VertexArray : public Data {
    static_assert(is_base_of_template<Vertex, V>::value);

    template<class T>
    using VertexBuffer = BufferTyped<T, BufferTypeGL::Data>;

    template<class T>
    using IndexBuffer = BufferTyped<T, BufferTypeGL::Index>;

public:
    VertexArray(const std::vector<V> &vertices) :
        Data(_newId()),
        indexed(false),
        _vertices(BufferUsageGL::STATIC),
        _draw_count(vertices.size()),
        _draw_func(_drawUnindexed),
        _draw_instanced_func(_drawUnindexedInstaced){
        _vertices = vertices;
        _vertices.bind();
        V::bindAttributes();
    };

    template<class I>
    VertexArray(const std::vector<V> &vertices,
                const std::vector<I> &indices) :
        Data(_newId()),
        indexed(true),
        _vertices(BufferUsageGL::STATIC),
        _indices(std::in_place_type<IndexBuffer<I>>, BufferUsageGL::STATIC),
        _indices_type(_getGlType<I>()),
        _draw_count(indices.size()),
        _draw_func(_drawIndexed),
        _draw_instanced_func(_drawIndexedInsctanced){
        _vertices = vertices;
        _vertices.bind();
        std::get<IndexBuffer<I>>(_indices) = indices;
        std::get<IndexBuffer<I>>(_indices).bind();
        V::bindAttributes();
    };

    virtual ~VertexArray(){
        glDeleteVertexArrays(1, &id);
    }

    inline void draw(DrawModeGL mode) const {
        _draw_func(mode);
    }

    inline void drawInstanced(DrawModeGL mode, GLsizei count) const {
        _draw_instanced_func(mode, count);
    }

    const bool indexed;

private:
    VertexBuffer<V> _vertices;
    std::variant<IndexBuffer<GLubyte>,
                 IndexBuffer<GLushort>,
                 IndexBuffer<GLuint>> _indices;
    const DataTypeGL _indices_type;
    const size_t _draw_count;
    
    template<class T>
    static constexpr DataTypeGL _getGlType(){
        if constexpr (std::is_same_v<T, GLubyte>){return DataTypeGL::_ubyte;}
        else if constexpr (std::is_same_v<T, GLushort>){return DataTypeGL::_ushort;}
        else if constexpr (std::is_same_v<T, GLuint>){return DataTypeGL::_uint;}
        else {[]<bool F = false>(){static_assert(F, "Wrong indices type");};}
    }

    using DrawFunc = void (VertexArray<V>::*)(DrawModeGL) const;
    const DrawFunc _draw_func;

    void _drawUnindexed(DrawModeGL mode) const {
        glBindVertexArray(id);
        glDrawArrays(gl(mode), 0, _draw_count);
        if constexpr (GL_DEBUG) printErr(&glDrawArrays);
    };

    void _drawIndexed(DrawModeGL mode) const {
        glBindVertexArray(id);
        glDrawElements(gl(mode), _draw_count, gl(_indices_type), (void*)0);
        if constexpr (GL_DEBUG) printErr(&glDrawElements);
    };
    
    using DrawInstancedFunc = void (VertexArray<V>::*)(DrawModeGL, GLsizei) const;
    const DrawInstancedFunc _draw_instanced_func;

    void _drawUnindexedInstaced(DrawModeGL mode, GLsizei count) const {
        glBindVertexArray(id);
        glDrawArraysInstanced(gl(mode), 0, _draw_count, count);
        if constexpr (GL_DEBUG) printErr(&glDrawArraysInstanced);
    }

    void _drawIndexedInsctanced(DrawModeGL mode, GLsizei count) const {
        glBindVertexArray(id);
        glDrawElementsInstanced(gl(mode), _draw_count, gl(_indices_type), (void*)0, count);
        if constexpr (GL_DEBUG) printErr(&glDrawElementsInstanced);
    }

    static GLuint _newId(){
        GLuint id;
        glGenVertexArrays(1, &id);
        return id;
    };
};

}