#pragma once

#include <optional>

#include "glwpp/gl/enums/BufferStorageFlag.hpp"
#include "glwpp/gl/obj/Buffer.hpp"

namespace glwpp::gl {

namespace detail {

// Just to hide implementation
class ArrayBase {
public:
    virtual ~ArrayBase() = 0;
protected:
    ArrayBase(){};
    struct ArrayData {
        SizeiPtr size;
        size_t elem_size;
    };

    static void _init(const SizeiPtr& size, const void* initial,
                      const size_t& element_bytes,
                      const UInt& id, ArrayData& data);
    static void _getSize(SizeiPtr& dst,
                         const UInt& id, ArrayData& data);
    static void _getValue(const SizeiPtr& i, void* dst,
                          const UInt& id, ArrayData& data);
    static void _setValue(const SizeiPtr& i, const void* value,
                          const UInt& id, ArrayData& data);
};

inline ArrayBase::~ArrayBase(){};

};


template<typename T>
class Array : public detail::ArrayBase, public Buffer {
public:
    Array(const wptr<Context>& wctx, const Val<const SizeiPtr>& size,
          const Val<const std::optional<T>>& initial = std::nullopt,
          const Val<const SrcLoc>& src_loc = SrcLoc{}) :
        Buffer(wctx, src_loc),
        _data(new ArrayData){
        Val<const T> init_val(*initial ? (*initial).value() : T{});
        executeInContext(true, src_loc, &ArrayBase::_init, size, init_val, sizeof(T), id(), Val<ArrayData>(_data));
    }

    ~Array(){};

    inline bool size(const Val<SizeiPtr>& dst,
                     const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true) const {
        return executeInContext(check_ctx, src_loc, &ArrayBase::_getSize, dst, id(), Val<ArrayData>(_data));
    }

    inline bool get(const Val<const SizeiPtr>& i, const Val<T>& dst,
                    const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true) const {
        return executeInContext(check_ctx, src_loc, &ArrayBase::_getValue, i, dst, id(), Val<ArrayData>(_data));
    }

    inline bool set(const Val<const SizeiPtr>& i, const Val<const T>& value,
                    const Val<const SrcLoc>& src_loc = SrcLoc{}, bool check_ctx = true){
        return executeInContext(check_ctx, src_loc, &ArrayBase::_setValue, i, value, id(), Val<ArrayData>(_data));
    }

protected:
    sptr<ArrayData> _data;
};

}