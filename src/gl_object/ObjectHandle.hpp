#pragma once

#include "gl_object/Object.hpp"

namespace glwpp::GL {

class ObjectHandle : public Object<GLuint> {
public:
    ObjectHandle(const std::shared_ptr<Context>& ctx, GLuint init_gl_data, const Deleter& deleter, const SrcLoc& src_loc = SrcLoc{}) :
        Object<GLuint>(ctx, init_gl_data, deleter, src_loc){
    };

    inline ConstUint id() const{
        return getData();
    }

protected:
    using Object<GLuint>::getData;

};

} // namespace glwpp