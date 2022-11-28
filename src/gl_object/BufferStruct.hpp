#pragma once

#include <cstring>

#include "gl_object/Buffer.hpp"

namespace glwpp::GL {

template<typename T>
class BufferStruct : public BufferBase, public SharedObject<BufferStruct<T>> {
public:
    EXPORT static std::shared_ptr<BufferStruct<T>> New(const std::shared_ptr<Context>& ctx, const Value<T>& initial, const SrcLoc& src_loc = SrcLoc{}){
        return std::shared_ptr<BufferStruct<T>>(new BufferStruct<T>(ctx, initial, src_loc));
    }
    EXPORT ~BufferStruct(){};

    EXPORT Value<T> getValue(const SrcLoc& src_loc = SrcLoc{}) const {
        return _callGLCustom([](Gl& gl, const std::shared_ptr<BufferStruct<T>>& self, const SrcLoc& src_loc){
            T* result = malloc(sizeof(T));
            auto mapped = self->map(Gl::READ_ONLY(), src_loc);
            memcpy(result, *mapped, sizeof(T));
            self->unmap(src_loc);
            return *result;
        }, this->shared_from_this(), src_loc);
    }

    EXPORT void setValue(const Value<T>& value, const SrcLoc& src_loc = SrcLoc{}){
        return _callGLCustom([](Gl& gl, const std::shared_ptr<BufferStruct<T>>& self, const Value<T>& value, const SrcLoc& src_loc){
            auto mapped = self->map(Gl::WRITE_ONLY(), src_loc);
            memcpy(*mapped, value.get(), sizeof(T));
            self->unmap(src_loc);
        }, this->shared_from_this(), value, src_loc);
    }

protected:
    BufferStruct(const std::shared_ptr<Context>& ctx,
                 const Value<T>& initial,
                 const SrcLoc& src_loc) :
        BufferBase(ctx, src_loc){
        setStorage(sizeof(T), initial, Gl::MAP_READ_BIT() | Gl::MAP_WRITE_BIT(), src_loc);
    }
};

}