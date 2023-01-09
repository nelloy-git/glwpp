#pragma once

#include <cstring>

#include "gl_object/Buffer.hpp"

namespace glwpp::GL {

template<typename T>
class BufferStruct : protected ObjectRef<void*> {
public:
    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    BufferStruct(Valuable<Context&> auto&& ctx,
                 Valuable<const T&> auto&& initial,
                 Valuable<const SrcLoc&> auto&& src_loc) :
        ObjectRef(ctx, nullptr, &ObjectRef::SIMPLE_DELETER, src_loc),
        _buffer(ctx, src_loc){
        static const GLbitfield storage_flags(GLapi::GL_MAP_READ_BIT | GLapi::GL_MAP_WRITE_BIT | GLapi::GL_MAP_PERSISTENT_BIT | GLapi::GL_MAP_COHERENT_BIT);
        static const GLenum map_flag(GLapi::GL_READ_WRITE);

        // _buffer.setStorage(sizeof(T), initial, storage_flags, src_loc);
        // addCallGl<[](Context&, Buffer& buffer, void*& dst, const SrcLoc& src_loc){dst = *buffer.map<IsGlThread::True>(map_flag, src_loc);}>(_buffer, data, src_loc);
        // data = _buffer.map(map_flag, src_loc);
    }
    virtual ~BufferStruct(){};

    const BufferRef& buffer() const {
        return _buffer;
    }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    Value<T> getValue(const SrcLoc src_loc = SrcLoc{}) const {
        static constexpr auto F = [](GLapi& ctx, void* map, T& dst){
            memcpy(&dst, map, sizeof(T));
        };

        Value<T> dst;
        // addCallGl<F, is_gl_thread>(data, dst);
        return dst;
    }

    template<IsGlThread is_gl_thread = IsGlThread::Unknown>
    void setValue(Valuable<const T> auto&& value, const SrcLoc src_loc = SrcLoc{}){
        static constexpr auto F = [](GLapi& ctx, void* map, const T& value){
            memcpy(map, &value, sizeof(T));
        };
        // return addCallGl<F, is_gl_thread>(data, value);
    }

private:
    BufferRef _buffer;

    static void _memcpy(GLapi& ctx, void* dst, void* src, const size_t& read_offset, const size_t& write_offset, size_t size){
        // memcpy( dst, src, size)
    };

};

}