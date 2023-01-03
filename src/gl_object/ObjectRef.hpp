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

// template<typename Req, typename T>
// constexpr bool IsValuable = std::is_convertible_v<T, Req>
//                          || (is_instance<std::remove_const_t<std::remove_reference_t<T>>, Value>::value
//                             && std::is_convertible_v<std::invoke_result_t<decltype(decltype(T)::value), decltype(T)>, Req>);


template<typename T>
class ObjectRef : public CallOptimizer {
    static_assert(!is_instance<std::remove_const_t<std::remove_reference_t<T>>, Value>::value, "Value template can not be used for GL::ObjectRef");

public:
    using DelFunc = typename ObjectDeleter<T>::DelFunc;

    static void SIMPLE_DELETER(std::weak_ptr<Context> wctx, T* data, const SrcLoc& src_loc){
        delete data;
    };

    ObjectRef(Context& ctx,
              T* init_gl_data,
              const DelFunc& deleter,
              const SrcLoc& src_loc = SrcLoc{}) :
        CallOptimizer(ctx),
        data(Value<T>::WithDeleter(ctx, init_gl_data, ObjectDeleter<T>(ctx, deleter, src_loc))){
    };
    virtual ~ObjectRef() = 0;

    const Value<T> data;
};

template<typename T>
inline ObjectRef<T>::~ObjectRef(){
}

} // namespace GL

} // namespace glwpp