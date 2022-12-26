#pragma once

#include "Context.hpp"

namespace glwpp {

namespace GL {

template<typename T>
class ObjectDeleter {

public:
    using DelFunc = typename std::function<void(std::weak_ptr<Context>, T*, const SrcLoc&)>;

    static void DEFAULT_DELETER(std::weak_ptr<Context> wctx, T* data, const SrcLoc& src_loc){
        delete data;
    };

    ObjectDeleter(Context& ctx, const DelFunc& deleter, const SrcLoc& src_loc) :
        _wctx(ctx.weak_from_this()),
        _deleter(deleter),
        _src_loc(SrcLoc(src_loc, src_loc.file_name(), src_loc.line(), (std::string(src_loc.function_name()) + "::~GL").c_str())){
    }

    void operator()(T* gl_data){
        _deleter(_wctx, gl_data, _src_loc);
    }

private:
    const DelFunc _deleter;
    const std::weak_ptr<Context> _wctx;
    const SrcLoc _src_loc;
};


} // namespace GL

} // namespace glwpp