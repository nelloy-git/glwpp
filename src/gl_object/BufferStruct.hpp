#pragma once

#include <cstring>

#include "gl_object/Buffer.hpp"

namespace glwpp::GL {

template<typename T>
class BufferStruct final : public CtxObj<BufferStruct<T>> {
public:
    static auto Make(Valuable<Context&> auto&& ctx,
                                       Valuable<const T&> auto&& initial,
                                       Valuable<const SrcLoc&> auto&& src_loc){
        auto obj = Value<BufferStruct<T>>::Make(new BufferStruct<T>(ctx, src_loc));
        obj->callMember<TState::Unknown, &BufferStruct<T>::_init>(initial, src_loc);
        return obj;
    }
    ~BufferStruct(){};

    operator Value<Buffer>(){
        return _buffer;
    }

    template<TState IsCtx>
    auto getValue() const {
        return this->callMember<IsCtx, &BufferStruct::_getValue>();
    }

    template<TState IsCtx>
    auto setValue(Valuable<const T&> auto&& value){
        return this->callMember<IsCtx, &BufferStruct::_setValue>(value);
    }

    BufferStruct(Valuable<Context&> auto&& ctx,
                 Valuable<const SrcLoc&> auto&& src_loc) :
        CtxObj<BufferStruct<T>>(ctx),
        _buffer(Buffer::Make(ctx, src_loc)){
    }

private:
    Value<Buffer> _buffer;
    void* _map = nullptr;

    void _init(const T& initial, const SrcLoc& src_loc){
        static const GLbitfield storage_flags = GL_MAP_READ_BIT | GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT;
        static const GLenum map_access = GL_READ_WRITE;

        _buffer->setStorage<TState::True>(sizeof(T), &initial, storage_flags, src_loc);
        _map = _buffer->map<TState::True>(map_access, src_loc);
    }

    T _getValue() const {
        return *reinterpret_cast<T*>(_map);
    }

    void _setValue(const T& value){
        *reinterpret_cast<T*>(_map) = value;
    }
};

} // namespace glwpp::GL