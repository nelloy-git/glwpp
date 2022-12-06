#pragma once

#include <cstring>

#include "gl_object/Buffer.hpp"

namespace glwpp::GL {

template<typename T>
class BufferStruct : public detail::BufferBase, public SharedObject<BufferStruct<T>> {
public:
    EXPORT static std::shared_ptr<BufferStruct<T>> New(const std::shared_ptr<Context>& ctx, const Value<T>& initial, const SrcLoc src_loc = SrcLoc{}){
        return std::shared_ptr<BufferStruct<T>>(new BufferStruct<T>(ctx, initial, src_loc));
    }
    EXPORT virtual ~BufferStruct(){};

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT Value<T> getValue(const SrcLoc src_loc = SrcLoc{}) const {
        Value<T> dst(std::shared_ptr<T>((T*)malloc(sizeof(T))));
        if (*_mapped){
            memcpy(dst.get(), *_mapped, sizeof(T));
        } else {
            _addCallCustom<is_gl_thread>(src_loc,[](Context& ctx, const Value<const BufferStruct<T>>& self, const Value<T>& dst){
                memcpy(dst.get(), *self->_mapped, sizeof(T));
            }, Value(this->shared_from_this()), dst);
        }
        return dst;
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    EXPORT void setValue(const Value<const T>& value, const SrcLoc src_loc = SrcLoc{}){
        if (*_mapped){
            memcpy(*_mapped, value.get(), sizeof(T));
        } else {
            _addCallCustom<is_gl_thread>(src_loc, [](Context& ctx, const Value<const BufferStruct<T>>& self, const Value<const T>& value){
                memcpy(*self->_mapped, value.get(), sizeof(T));
            }, Value(this->shared_from_this()), value);
        }
    }

protected:
    BufferStruct(const std::shared_ptr<Context>& ctx,
                 const Value<const T>& initial,
                 const SrcLoc src_loc) :
        BufferBase(ctx, src_loc){
        static const ConstBitfield storage_flags(GL_MAP_READ_BIT | GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);
        static const ConstEnum map_flag(GL_READ_WRITE);

        setStorage(sizeof(T), initial, storage_flags);
        _mapped = map(map_flag);
    }

    DataPtr _mapped;
};

}