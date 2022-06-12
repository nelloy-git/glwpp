#pragma once

#include <optional>

#include "glwpp/gl/enums/BufferStorageFlag.hpp"
#include "glwpp/gl/obj/Buffer.hpp"

namespace glwpp::gl {

namespace detail {

class VectorBase {
public:
    virtual ~VectorBase() = 0;
protected:
    static const SizeiPtr INIT_CAPACITY = 4;
    static const SizeiPtr MULT_CAPACITY = 2;

    VectorBase(){};
    struct VectorData {
        SizeiPtr capacity;
        SizeiPtr size;
        size_t elem_size;
        BufferUsage usage;
    };

    static void _init(const SizeiPtr& size, const void* initial,
                      const size_t& elem_size, const BufferUsage& usage,
                      const UInt& id, VectorData& data);
    static void _getSize(SizeiPtr& dst,
                         const UInt& id, VectorData& data);
    static void _getCapacity(SizeiPtr& dst,
                             const UInt& id, VectorData& data);
    static void _reserve(const SizeiPtr& capacity,
                         const UInt& id, VectorData& data);
    static void _shape(const UInt& id, VectorData& data);
    static void _getValue(const SizeiPtr& i, void* dst, 
                          const UInt& id, VectorData& data);
    static void _setValue(const SizeiPtr& i, const void* value,
                          const UInt& id, VectorData& data);
    static void _pushBack(const void* value,
                          const UInt& id, VectorData& data);
    static void _popBack(void* dst,
                         const UInt& id, VectorData& data);
};

inline VectorBase::~VectorBase(){};

};

template<typename T>
class Vector : public detail::VectorBase, public Buffer {
    template<typename U>
    using Val = utils::Val<U>;
    using SrcLoc = utils::SrcLoc;

public:
    Vector(const wptr<Context>& wctx,
           const Val<const SizeiPtr>& size = 0,
           const Val<const BufferUsage>& usage = BufferUsage::DynamicDraw,
           const Val<const std::optional<T>>& initial = std::nullopt,
           const Val<const SrcLoc>& src_loc = SrcLoc{}) :
        Buffer(wctx, src_loc),
        _data(new VectorData){
        Val<const T> init_val(*initial ? (*initial).value() : T{});
        executeInContext(true, src_loc, VectorBase::_init, size, init_val, sizeof(T), usage, id(), Val<VectorData>(_data));
    }
    ~Vector(){};

    inline bool size(const Val<SizeiPtr>& dst,
              const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true) const {
        return executeInContext(check_ctx, src_loc, &VectorBase::_getSize, dst, id(), Val<VectorData>(_data));
    }

    inline bool capacity(const Val<SizeiPtr>& dst,
                  const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true) const {
        return executeInContext(check_ctx, src_loc, &VectorBase::_getCapacity, dst, id(), Val<VectorData>(_data));
    }

    inline bool get(const Val<const SizeiPtr>& i, const Val<T>& dst,
                    const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true) const {
        return executeInContext(check_ctx, src_loc, &VectorBase::_getValue, i, dst, id(), Val<VectorData>(_data));
    }

    inline bool set(const Val<const SizeiPtr>& i, const Val<const T>& value,
                    const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true){
        return executeInContext(check_ctx, src_loc, &VectorBase::_setValue, i, value, id(), Val<VectorData>(_data));
    }

    inline bool reserve(const Val<const SizeiPtr> capacity,
                        const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true){
        return executeInContext(check_ctx, src_loc, &VectorBase::_reserve, capacity, id(), Val<VectorData>(_data));
    }

    inline bool shape(const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true){
        return executeInContext(check_ctx, src_loc, &VectorBase::_shape, id(), Val<VectorData>(_data));
    }

    inline bool push_back(const Val<const std::optional<T>>& value,
                          const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true){
        return executeInContext(check_ctx, src_loc, &VectorBase::_shape, value, id(), Val<VectorData>(_data));
    }

    inline bool pop_back(const Val<T>& dst,
                         const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true){
        return executeInContext(check_ctx, src_loc, &VectorBase::_shape, dst, id(), Val<VectorData>(_data));
    }

protected:
    sptr<VectorData> _data;

};

}