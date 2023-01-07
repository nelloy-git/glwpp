#pragma once

// #include "glad/gl.h"

#include "context/CallOptimizer.hpp"
#include "gl_object/ObjectDeleter.hpp"

#define WRAP_GL_TYPE(name, new_name) \
typedef Value<name> ##new_name; \
typedef Value<const name> Const##new_name; \
typedef Value<name[]>  Arr##new_name; \
typedef Value<const name[]> ConstArr##new_name

namespace glwpp {

namespace GL {

template<typename T>
class ObjectRef : public CallOptimizer {
    static_assert(!detail::is_value_v<T>, "Value template can not be used for GL::ObjectRef");

public:
    using DelFunc = typename ObjectDeleter<T>::DelFunc;

    static void SIMPLE_DELETER(std::weak_ptr<Context> wctx, T* data, const SrcLoc& src_loc){
        delete data;
    };

    ObjectRef(Context& ctx,
              T* init_gl_data,
              const DelFunc& deleter = &SIMPLE_DELETER,
              const SrcLoc& src_loc = SrcLoc{}) :
        CallOptimizer(ctx),
        data(Value<T>::Make(init_gl_data, ObjectDeleter<T>(ctx, deleter, src_loc))){
    };
    virtual ~ObjectRef() = 0;

    const Value<T> data;
};

template<typename T>
inline ObjectRef<T>::~ObjectRef(){
}

} // namespace GL

} // namespace glwpp