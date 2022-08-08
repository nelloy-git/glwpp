#include "glwpp/gl/obj/Object.hpp"

#include "glad/gl.h"

using namespace glwpp;
using namespace glwpp::gl;

Object::~Object(){
}

const Val<const UInt> Object::id() const {
    return _id;
};

void Object::debug(const utils::SrcLoc& src_loc){
#ifdef GLWPP_DEBUG
    Enum err = glGetError();
    while (err != GL_NO_ERROR){
        std::string err_name;
        switch (err){
            case GL_INVALID_ENUM: err_name = "GL_INVALID_ENUM"; break;
            case GL_INVALID_VALUE: err_name = "GL_INVALID_VALUE"; break;
            case GL_INVALID_OPERATION: err_name = "GL_INVALID_OPERATION"; break;
            case GL_STACK_OVERFLOW: err_name = "GL_STACK_OVERFLOW"; break;
            case GL_STACK_UNDERFLOW: err_name = "GL_STACK_UNDERFLOW"; break;
            case GL_OUT_OF_MEMORY: err_name = "GL_OUT_OF_MEMORY"; break;
            case GL_INVALID_FRAMEBUFFER_OPERATION: err_name = "GL_INVALID_FRAMEBUFFER_OPERATION"; break;
            case GL_CONTEXT_LOST: err_name = "GL_CONTEXT_LOST"; break;
            default: err_name = "UNKNOWN";
        }

        ContextObject::debug(err_name + "(" + std::to_string(err) + ")", src_loc);
        err = glGetError();
    }
#endif
}