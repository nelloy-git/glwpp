#pragma once

#include <optional>

#include "glwpp/gl/enums/BufferStorageFlag.hpp"
#include "glwpp/gl/obj/Buffer.hpp"

namespace glwpp::gl {

template<typename T>
class Vector {
    template<typename U>
    using Val = util::Val<U>;
    static const SizeiPtr INIT_CAPACITY = 4;

public:
    Vector(const wptr<Context>& wctx,
           const Val<const std::optional<SizeiPtr>>& size = std::nullopt,
           const Val<const std::optional<T>>& initial = std::nullopt,
           const Val<const SrcLoc>& src_loc = SrcLoc{}) :
        _data(make_sptr<VectorData>(wctx, src_loc)){
        _data->buffer.executeInContext(true, src_loc, _initVector, _data, size, initial, src_loc);
    }

    ~Vector(){};

    operator const Val<Buffer>&(){return _data->buffer;}
    operator const Val<const Buffer>&() const {return _data->buffer;}

    bool size(const Val<SizeiPtr>& dst,
              const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true) const {
        return _data->buffer.executeInContext(check_ctx, src_loc, _getSize, _data, dst);
    }

    bool capacity(const Val<SizeiPtr>& dst,
                  const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true) const {
        return _data->buffer.executeInContext(check_ctx, src_loc, _getCapacity, _data, dst);
    }

    inline bool get(const Val<const size_t>& i, const Val<T>& dst,
                    const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true) const {
        return _data->buffer.executeInContext(check_ctx, src_loc, _getValue, _data, i, dst, src_loc);
    }

    inline bool set(const Val<const size_t>& i, const Val<const T>& value,
                    const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true){
        return _data->buffer.executeInContext(check_ctx, src_loc, _setValue, _data, i, value, src_loc);
    }

    inline bool reserve(const Val<const SizeiPtr> capacity,
                        const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true){
        return _data->buffer.executeInContext(check_ctx, src_loc, _reserve, _data, capacity, src_loc);
    }

    inline bool shape(const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true){
        return _data->buffer.executeInContext(check_ctx, src_loc, _shape, _data, src_loc);
    }

    inline bool push_back(const Val<const std::optional<T>>& value,
                          const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true){
        return _data->buffer.executeInContext(check_ctx, src_loc, _push_back, _data, value, src_loc);
    }

    inline bool pop_back(const Val<T>& dst,
                         const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true){
        return _data->buffer.executeInContext(check_ctx, src_loc, _pop_back, _data, dst, src_loc);
    }

    // virtual bool push_back(const Val<T>& value, const SrcLoc& loc = SrcLoc{});
    // virtual bool pop_back(const SrcLoc& loc = SrcLoc{});

protected:
    struct VectorData {
        VectorData(const wptr<Context>& wctx, const Val<const SrcLoc>& src_loc) :
            buffer(wctx, src_loc),
            capacity(0),
            size(0){
        };
        Buffer buffer;
        SizeiPtr capacity;
        SizeiPtr size;
    };
    const Val<VectorData> _data;

private:
    static void _initVector(const Val<VectorData>& data,
                            const Val<const std::optional<SizeiPtr>>& init_size,
                            const Val<const std::optional<T>>& initial,
                            const Val<const SrcLoc>& src_loc){
        auto size = init_size->has_value() ? init_size->value() : 0;

        data->capacity = INIT_CAPACITY > size ? INIT_CAPACITY : size;
        data->size = size;
        
        data->buffer.data(data->capacity * sizeof(T), _empty, _usage, src_loc, false);

        auto s_ptr = make_sptr<T*>();
        auto init_val = *initial ? (*initial).value() : T{};
        data->buffer.map(std::reinterpret_pointer_cast<void*>(s_ptr), BufferMapAccess::WriteOnly, src_loc, false);
        for (size_t i = 0; i < data->size; ++i){
            (*s_ptr)[i] = init_val;
        }
        data->buffer.unmap(true, src_loc, false);
    }

    static void _getSize(const Val<VectorData>& data,
                         const Val<SizeiPtr>& dst){
        *dst = data->size;
    }

    static void _getCapacity(const Val<VectorData>& data,
                             const Val<SizeiPtr>& dst){
        *dst = data->capacity;
    }

    static void _getValue(const Val<VectorData>& data,
                          const Val<const size_t>& i, const Val<T>& dst,
                          const Val<const SrcLoc>& src_loc){
        data->buffer.getSubData(Val<void>(dst), *i * sizeof(T), sizeof(T), src_loc, false);
    }

    static void _setValue(const Val<VectorData>& data,
                          const Val<const size_t>& i, const Val<const T>& value,
                          const Val<const SrcLoc>& src_loc){
        data->buffer.setSubData(Val<const void>(value), *i * sizeof(T), sizeof(T), src_loc, false);
    }

    static void _reserve(const Val<VectorData>& data,
                         const Val<const SizeiPtr> reserve_capacity,
                         const Val<const SrcLoc>& src_loc){
        if (data->capacity >= *reserve_capacity){return;}

        Buffer tmp(data->buffer.ctx(), src_loc);
        data->buffer.copySubDataTo(tmp, 0, 0, data->size * sizeof(T), src_loc, false);
        tmp.data(data->size * sizeof(T), _empty, _usage, src_loc, false);
        data->buffer.data(*reserve_capacity * sizeof(T), _empty, _usage, src_loc, false);
        tmp.copySubDataTo(data->buffer, 0, 0, data->size * sizeof(T), src_loc, false);

        data->capacity = *reserve_capacity;

    }

    static void _shape(const Val<VectorData>& data,
                       const Val<const SrcLoc>& src_loc){
        if (data->size == data->capacity){return;}

        Buffer tmp(data->buffer.ctx(), src_loc);
        tmp.data(data->size * sizeof(T), _empty, _usage, src_loc, false);
        data->buffer.copySubDataTo(tmp, 0, 0, data->size * sizeof(T), src_loc, false);
        data->buffer.data(data->size * sizeof(T), _empty, _usage, src_loc, false);
        tmp.copySubDataTo(data->buffer, 0, 0, data->size * sizeof(T), src_loc, false);

        data->capacity = data->size;
    }

    static void _push_back(const Val<VectorData>& data,
                           const Val<const std::optional<T>>& value,
                           const Val<const SrcLoc>& src_loc){
        
        if (data->size == data->capacity){
            _reserve(data, 2 * data->capacity, src_loc);
        }
        auto val = Val<T>(*value ? value->value() : T{});
        data->buffer.setSubData(Val<void>(val), data->size * sizeof(T), sizeof(T), src_loc, false);
        ++data->size;
    }

    static void _pop_back(const Val<VectorData>& data,
                          const Val<T>& dst,
                          const Val<const SrcLoc>& src_loc){
        data->buffer.getSubData(Val<void>(dst), data->size * sizeof(T), sizeof(T), src_loc, false);
        --data->size;
    }

    static inline const sptr<const void> _empty;
    static inline const Val<const BufferUsage> _usage = BufferUsage::DynamicDraw;
    static inline const Val<const BitField> _access = static_cast<Enum>(BufferStorageFlag::Read)
                                             | static_cast<Enum>(BufferStorageFlag::Write)
                                             | static_cast<Enum>(BufferStorageFlag::Persistent)
                                             | static_cast<Enum>(BufferStorageFlag::Coherent);
};

}