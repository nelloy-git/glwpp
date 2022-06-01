#pragma once

#include "glwpp/gl/ctx_only/CtxBuffer.hpp"
#include "glwpp/gl/enums/BufferStorageFlag.hpp"
#include "glwpp/gl/obj/Buffer.hpp"

namespace glwpp::gl {

template<typename T>
class Array {
public:
    template<typename T>
    using Val = util::Val<T>;

    Array(const wptr<Context>& wctx, const Val<const size_t>& size, const SrcLoc& src_loc = SrcLoc()) :
        _size(0),
        _buffer(make_sptr<Buffer>(wctx, src_loc)){
        _buffer->executeInContext(true, src_loc, _initBuffer, _buffer, _size, size, src_loc);

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
    }
    // Array(const wptr<Context>& wctx, const Val<size_t>& size, const Val<T>& initial, const SrcLoc& loc = SrcLoc());
    ~Array(){};

    operator const Val<Buffer>&(){return _buffer;}

    // bool size(Ptr<size_t>& dst) const;
    // virtual bool set(const Val<size_t>& i, const Val<T>& value, const SrcLoc& loc = SrcLoc());
    // virtual bool get(Ptr<T>& dst, const Val<size_t>& i, const SrcLoc& loc = SrcLoc()) const;

protected:
    const Val<size_t> _size;
    const Val<Buffer> _buffer;

private:
    static void _initBuffer(const Val<Buffer>& buffer,
                            const Val<size_t> array_size, const Val<const size_t> init_size,
                            const Val<const SrcLoc>& src_loc){
        array_size = init_size;

        sptr<void> empty;
        buffer->storage(array_size, empty, _access, src_loc, false);

        // sptr<T*> ptr;
        // buffer->map(std::reinterpret_pointer_cast<void*>(ptr), BufferMapAccess::WriteOnly, src_loc, false);
        // for (size_t i = 0; i < *array_size; ++i){
        //     (*ptr)[i] = T{};
        // }
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