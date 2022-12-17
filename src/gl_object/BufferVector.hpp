#pragma once

#include <cstring>
#include <vector>

#include "gl_object/Buffer.hpp"

namespace glwpp::GL {

namespace detail {

struct BufferVectorData {
    size_t size;
    size_t capacity;
    GLenum usage;
};

};

template<typename T>
class BufferVector : protected Object<detail::BufferVectorData> {
    static constexpr size_t INIT_CAPACITY = 4;
    static constexpr size_t MULT_CAPACITY = 2;

public:
    EXPORT BufferVector(const std::shared_ptr<Context>& ctx,
                        const ConstEnum& usage = GL_DYNAMIC_DRAW,
                        const SrcLoc& src_loc = SrcLoc{}) :
        Object(ctx, detail::BufferVectorData{0, INIT_CAPACITY, 0}, Object::DEFAULT_DELETER, src_loc),
        _buffer(new Buffer(ctx, src_loc)){
        _buffer->setData(INIT_CAPACITY * sizeof(T), Value<const void>::Null(), usage, src_loc.add());
        addCallGl<[](Context&, detail::BufferVectorData& data, const GLenum& usage){data.usage = usage;}>(data(), usage);
    }
    EXPORT virtual ~BufferVector(){};

    const Buffer& buffer() const {
        return *_buffer;
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    Value<const size_t> size() const {
        return addCallGl<[](GLapi&, const detail::BufferVectorData& data){return data.size;}, is_gl_thread>(data());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    Value<const size_t> capacity() const {
        return addCallGl<[](GLapi&, const detail::BufferVectorData& data){return data.capacity;}, is_gl_thread>(data());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    Value<T> get(const Value<const size_t>& i, const SrcLoc& src_loc = SrcLoc{}){
        Value<void> dst;
        _buffer->getSubData<is_gl_thread>(i * sizeof(T), sizeof(T), dst, src_loc.add());
        return dst;
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    void set(const Value<const size_t>& i, const Value<const T>& val, const SrcLoc& src_loc = SrcLoc{}){
        _buffer->setSubData<is_gl_thread>(i * sizeof(T), sizeof(T), val, src_loc.add());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    void reserve(const Value<const size_t>& cap, const SrcLoc& src_loc = SrcLoc{}){
        addCallGl<&_reserve, is_gl_thread>(cap, _buffer, data(), src_loc.add());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    void shape(const SrcLoc& src_loc = SrcLoc{}){
        addCallGl<&_shape, is_gl_thread>(_buffer, data(), src_loc.add());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    void push_back(const Value<const T>& val, const SrcLoc& src_loc = SrcLoc{}){
        addCallGl<&_push_back, is_gl_thread>(val, _buffer, data(), src_loc.add());
    }

    template<Context::IsGlThread is_gl_thread = Context::IsGlThread::Unknown>
    void pop_back(const SrcLoc& src_loc = SrcLoc{}){
        addCallGl<&_pop_back, is_gl_thread>(_buffer, data(), src_loc.add());
    }


private:
    std::shared_ptr<Buffer> _buffer;
    
    static void _reserve(Context& ctx, const size_t& capacity, const std::shared_ptr<Buffer>& buffer, detail::BufferVectorData& data, const SrcLoc& src_loc){
        if (capacity <= data.capacity){
            return;
        }

        Buffer tmp(ctx.shared_from_this(), src_loc);
        tmp.setData<Context::IsGlThread::True>(data.capacity * sizeof(T), Value<const void>::Null(), GL_STATIC_COPY, src_loc);
        tmp.copySubData<Context::IsGlThread::True>(*buffer, 0, 0, data.capacity * sizeof(T), src_loc);

        buffer->setData<Context::IsGlThread::True>(capacity * sizeof(T), Value<const void>::Null(), data.usage, src_loc);
        buffer->copySubData<Context::IsGlThread::True>(tmp, 0, 0, data.capacity * sizeof(T), src_loc);
        data.capacity = capacity;

        std::cout << "cap: " << data.capacity << std::endl;
    }
    
    static void _shape(Context& ctx, const std::shared_ptr<Buffer>& buffer, detail::BufferVectorData& data, const SrcLoc& src_loc){
        Buffer tmp(ctx.shared_from_this(), src_loc);
        tmp.setData<Context::IsGlThread::True>(data.size * sizeof(T), Value<const void>::Null(), GL_STATIC_COPY, src_loc);
        tmp.copySubData<Context::IsGlThread::True>(*buffer, 0, 0, data.size * sizeof(T), src_loc);

        buffer->setData<Context::IsGlThread::True>(data.size * sizeof(T), Value<const void>::Null(), data.usage, src_loc);
        buffer->copySubData<Context::IsGlThread::True>(tmp, 0, 0, data.size * sizeof(T), src_loc);
    }

    static void _push_back(Context& ctx, const T& val, const std::shared_ptr<Buffer>& buffer, detail::BufferVectorData& data, const SrcLoc& src_loc){
        if (data.size >= data.capacity){
            _reserve(ctx, MULT_CAPACITY * data.capacity, buffer, data, src_loc);
        }

        buffer->setSubData<Context::IsGlThread::True>(data.size * sizeof(T), sizeof(T), val, src_loc);
        data.size += 1;
    }

    static void _pop_back(Context& ctx, const std::shared_ptr<Buffer>& buffer, detail::BufferVectorData& data, const SrcLoc& src_loc){
        if (data.size == 0){
            return;
        }
        data.size -= 1;
        buffer->setSubData<Context::IsGlThread::True>(data.size * sizeof(T), sizeof(T), Value<const void>::Null(), src_loc);
    }
};

}