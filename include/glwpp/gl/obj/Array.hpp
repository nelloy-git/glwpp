#pragma once

#include <optional>

#include "glwpp/gl/enums/BufferStorageFlag.hpp"
#include "glwpp/gl/obj/Buffer.hpp"

namespace glwpp::gl {

template<typename T>
class Array {
public:
    template<typename U>
    using Val = utils::Val<U>;
    using SrcLoc = utils::SrcLoc;

    Array(const wptr<Context>& wctx, const Val<const SizeiPtr>& size,
          const Val<const std::optional<T>>& initial = std::nullopt,
          const Val<const SrcLoc>& src_loc = SrcLoc{}) :
        _size(0),
        _buffer(make_sptr<Buffer>(wctx, src_loc)){
        _buffer->executeInContext(true, src_loc, _initBuffer, _buffer, _size, size, initial, src_loc);
    }
    ~Array(){};

    operator const Val<Buffer>&(){return _buffer;}
    operator const Val<const Buffer>&() const {return _buffer;}

    inline bool size(const Val<SizeiPtr>& dst,
              const Val<const SrcLoc>& src_loc = SrcLoc{}) const {
        return _buffer->executeInContext(true, src_loc, _getSize, dst, Val<const SizeiPtr>(_size));
    }

    inline bool get(const Val<const size_t>& i, const Val<T>& dst,
                    const Val<const SrcLoc>& src_loc = SrcLoc{}) const {
        return _buffer->executeInContext(true, src_loc, _getValue, _buffer, i, dst, src_loc);
    }

    inline bool set(const Val<const size_t>& i, const Val<const T>& value,
                    const Val<const SrcLoc>& src_loc = SrcLoc{}){
        return _buffer->executeInContext(true, src_loc, _setValue, _buffer, i, value, src_loc);
    }

protected:
    const Val<SizeiPtr> _size;
    const Val<Buffer> _buffer;

private:
    static void _initBuffer(const Val<Buffer>& buffer,
                            const Val<SizeiPtr>& array_size, const Val<const SizeiPtr>& init_size,
                            const Val<const std::optional<T>>& initial,
                            const Val<const SrcLoc>& src_loc){
        *array_size = *init_size;
        sptr<void> empty = nullptr;
        buffer->storage(*init_size * sizeof(T), empty, _access, src_loc, false);

        auto s_ptr = make_sptr<T*>();
        auto init_val = *initial ? (*initial).value() : T{};

        buffer->map(std::reinterpret_pointer_cast<void*>(s_ptr), BufferMapAccess::WriteOnly, src_loc, false);
        for (size_t i = 0; i < *array_size; ++i){
            (*s_ptr)[i] = init_val;
        }
        buffer->unmap(true, src_loc, false);
    }

    static void _getSize(const Val<SizeiPtr>& dst,
                         const Val<const SizeiPtr>& array_size){
        *dst = *array_size;
    }

    static void _getValue(const Val<Buffer>& buffer,
                          const Val<const size_t>& i, const Val<T>& dst,
                          const Val<const SrcLoc>& src_loc){
        auto map_ptr = make_sptr<T*>();
        buffer->mapRange(std::reinterpret_pointer_cast<void*>(map_ptr),
                         *i * sizeof(T), sizeof(T), _access,
                         src_loc, false);
        *dst = **map_ptr;
        buffer->unmap(true, src_loc, false);
    }

    static void _setValue(const Val<Buffer>& buffer,
                          const Val<const size_t>& i, const Val<const T>& value,
                          const Val<const SrcLoc>& src_loc){
        auto map_ptr = make_sptr<T*>();
        buffer->mapRange(std::reinterpret_pointer_cast<void*>(map_ptr),
                         *i * sizeof(T), sizeof(T), _access,
                         src_loc, false);
        **map_ptr = *value;
        buffer->unmap(true, src_loc, false);
    }

    static inline BitField _access = static_cast<Enum>(BufferStorageFlag::Read)
                                   | static_cast<Enum>(BufferStorageFlag::Write)
                                   | static_cast<Enum>(BufferStorageFlag::Persistent)
                                   | static_cast<Enum>(BufferStorageFlag::Coherent);

};

// template<typename T>
// Array<T>::Array(const wptr<Context>& wctx, const Val<size_t>& size, const SrcLoc& loc) :
//     Buffer(wctx, loc){
//     static constexpr auto F = [](gl::CtxBuffer* buffer, size_t* _size,
//                                  const size_t& size, const SrcLoc& loc){
//         *_size = size;
//         buffer->storage(*_size * sizeof(T), nullptr, _access, loc);

//         auto ptr = static_cast<T*>(buffer->map(gl::BufferMapAccess::WriteOnly, loc));
//         for (size_t i = 0; i < size; ++i){
//             ptr[i] = T{};
//         }
//         buffer->unmap(loc);
//     };
//     _size = make_sptr<size_t>(0);
//     _execute<F>(getWCtx(), _getPtr(), Ptr(_size), size, Val(loc));
// };

// template<typename T>
// Array<T>::Array(const wptr<Context>& wctx, const Val<size_t>& size, const Val<T>& initial, const SrcLoc& loc) :
//     Buffer(wctx, loc){
    // static constexpr auto F = [](gl::CtxBuffer* buffer, size_t* _size,
    //                              const size_t& size, const SrcLoc& loc){
    //     *_size = size;
    //     buffer->storage(*_size * sizeof(T), nullptr, _access, loc);

    //     auto ptr = static_cast<T*>(buffer->map(gl::BufferMapAccess::WriteOnly, loc));
    //     for (size_t i = 0; i < size; ++i){
    //         ptr[i] = initial;
    //     }
    //     buffer->unmap(loc);
    // };
    // _size = make_sptr<size_t>(0);
    // _execute<F>(getWCtx(), _getPtr(), Ptr(_size), size, initial, Val(loc));
// };

// template<typename T>
// bool Array<T>::size(Ptr<size_t>& dst) const {
//     static constexpr auto F = [](size_t* _size, size_t* dst){
//         *dst = *_size;
//     };
//     return _execute<F>(getWCtx(), Ptr(_size), dst);
// };

// template<typename T>
// bool Array<T>::set(const Val<size_t>& i, const Val<T>& value, const SrcLoc& loc){
//     static constexpr auto F = [](gl::CtxBuffer* buffer, size_t* _size,
//                                  const size_t& i, const T& value, const SrcLoc& loc){
//         if (i >= *_size){
//             throw std::runtime_error("Out of bounds: " + std::string(loc.file_name()) + ":" + std::to_string(loc.line()));
//         }
//         auto p = static_cast<T*>(buffer->mapRange(i * sizeof(T), sizeof(T), _access, loc));
//         *p = value;
//         buffer->unmap(loc);
//     };
//     return _execute<F>(getWCtx(), _getPtr(), Ptr(_size), i, value, Val(loc));
// }

// template<typename T>
// bool Array<T>::get(Ptr<T>& dst, const Val<size_t>& i, const SrcLoc& loc) const {
//     static constexpr auto F = [](gl::CtxBuffer* buffer, size_t* _size,
//                                  T* dst, const size_t& i, const SrcLoc& loc){
//         if (i >= *_size){
//             throw std::runtime_error("Out of bounds: " + std::string(loc.file_name()) + ":" + std::to_string(loc.line()));
//         }
//         auto p = static_cast<T*>(buffer->mapRange(i * sizeof(T), sizeof(T), _access, loc));
//         *dst = *p;
//         buffer->unmap(loc);
//     };
//     return _execute<F>(getWCtx(), _getPtr(), Ptr(_size), dst, i, Val(loc));
// }

}