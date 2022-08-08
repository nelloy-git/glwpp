#pragma once

#include <optional>

#include "glwpp/gl/enums/BufferStorageFlag.hpp"
#include "glwpp/gl/obj/Buffer.hpp"

namespace glwpp::gl {

template<typename T>
class Struct : public Buffer {
public:
    static sptr<Struct> make1(const sptr<Context>& ctx,
                             const Val<const T>& initial,
                             const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}){
        auto self = sptr<Struct>(new Struct(ctx, initial, src_loc));
        self->storage(sizeof(T), Val<const void>(initial), _access, src_loc);
        return self;
    };

    ~Struct(){};

    bool get(const Val<T>& dst,
             const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const {
        if (!isContextThread()){
        return executeMethodInContext(&Struct::get, dst, src_loc);
        }

        Val<T*> mapped;
        map(mapped, BufferMapAccess::ReadOnly, src_loc);
        *dst = *mapped;
        unmap(true, src_loc);
        return true;
    }

    bool set(const Val<const T>& value,
             const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}){
        if (!isContextThread()){
        return executeMethodInContext(&Struct::set, value, src_loc);
        }

        Val<void*> mapped(nullptr);
        map(mapped, BufferMapAccess::ReadOnly, src_loc);
        auto mapped_struct = mapped.cast_reinterpret<T*>();
        **mapped_struct = *value;
        unmap(true, src_loc);
        return true;
    }

protected:
    Struct(const sptr<Context>& ctx,
           const Val<const T>& initial,
           const Val<const utils::SrcLoc>& src_loc) :
        Buffer(ctx, src_loc){
    }

private:
    // Hide parent's make
    using Buffer::make;

    static inline const Val<const UInt> _access = static_cast<Enum>(BufferStorageFlag::Read)
                                                  | static_cast<Enum>(BufferStorageFlag::Write);
};

}