#pragma once

#include <optional>

#include "glwpp/gl/enums/BufferStorageFlag.hpp"
#include "glwpp/gl/obj/Buffer.hpp"

namespace glwpp::gl {

template<typename T>
class Array : public Buffer {
public:
    static sptr<Array> make1(const sptr<Context>& ctx, const Val<const UInt>& size,
                             const Val<const T>& initial,
                             const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}){
        auto self = sptr<Array>(new Array(ctx, size, initial, src_loc));
        static const Val<T*> empty(nullptr);
        self->storage(self->_size * sizeof(T), empty, _access, src_loc);
        for (UInt i = 0; i < self->_size; ++i){
            self->set(i, initial, src_loc);
        }
        return self;
    };

    ~Array(){};

    inline bool size(const Val<UInt>& dst,
                     const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const {
        if (!isContextThread()){
        return executeMethodInContext(&Array::size, dst, src_loc);
        }

        *dst = _size;
        return true;
    }

    inline bool get(const Val<const UInt>& i, const Val<T>& dst,
                    const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}) const {
        if (!isContextThread()){
        return executeMethodInContext(&Array::get, i, dst, src_loc);
        }

        Val<T*> mapped;
        mapRange(mapped, *i * sizeof(T), sizeof(T), _access, src_loc);
        *dst = *mapped;
        unmap(true, src_loc);
        return true;
    }

    inline bool set(const Val<const UInt>& i, const Val<const T>& value,
                    const Val<const utils::SrcLoc>& src_loc = utils::SrcLoc{}){
        if (!isContextThread()){
        return executeMethodInContext(&Array::set, i, value, src_loc);
        }

        Val<void*> mapped(nullptr);
        mapRange(mapped, *i * sizeof(T), sizeof(T), _access, src_loc);
        auto mapped_struct = mapped.cast_reinterpret<T*>();
        **mapped_struct = *value;
        unmap(true, src_loc);
        return true;
    }

protected:
    Array(const sptr<Context>& ctx, const Val<const UInt>& size,
          const Val<const T>& initial, const Val<const utils::SrcLoc>& src_loc) :
        Buffer(ctx, src_loc),
        _size(size){
    }

private:
    // Hide parent's make
    using Buffer::make;

    UInt _size;
    static inline BitField _access = static_cast<Enum>(BufferStorageFlag::Read)
                                   | static_cast<Enum>(BufferStorageFlag::Write)
                                   | static_cast<Enum>(BufferStorageFlag::Persistent)
                                   | static_cast<Enum>(BufferStorageFlag::Coherent);
};

}