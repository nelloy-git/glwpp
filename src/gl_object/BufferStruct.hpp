#pragma once

#include <cstring>

#include "gl_object/Buffer.hpp"

namespace glwpp::GL {

template<typename T>
class BufferStruct : protected Object<void*> {
public:
    EXPORT BufferStruct(const std::shared_ptr<Context>& ctx,
                        const Value<const T>& initial,
                        const SrcLoc& src_loc = SrcLoc{}) :
        Object(ctx, nullptr, Object::DEFAULT_DELETER, src_loc),
        _buffer(ctx, src_loc){
        static const ConstBitfield storage_flags(GL_MAP_READ_BIT | GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);
        static const ConstEnum map_flag(GL_READ_WRITE);

        _buffer.setStorage(sizeof(T), initial, storage_flags, src_loc);
        auto& map = data();
        map = _buffer.map(map_flag, src_loc);
    }
    EXPORT virtual ~BufferStruct(){};

    const Buffer& buffer() const {
        return _buffer;
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Value<T> getValue(const SrcLoc src_loc = SrcLoc{}) const {
        static constexpr auto F = [](GLapi& ctx, void* map, T& dst){
            memcpy(&dst, map, sizeof(T));
        };

        Value<T> dst;
        addCallGl<F, is_gl_thread>(data(), dst);
        return dst;
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setValue(const Value<const T>& value, const SrcLoc src_loc = SrcLoc{}){
        static constexpr auto F = [](GLapi& ctx, void* map, const T& value){
            memcpy(map, &value, sizeof(T));
        };
        return addCallGl<F, is_gl_thread>(data(), value);
    }

private:
    Buffer _buffer;
};

}