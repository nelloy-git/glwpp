#include "glwpp/gl/object/CtxObject.hpp"

#include <iostream>

#include "glad/gl.h"

using namespace glwpp::gl;

UInt CtxObject::getId() const {
    return *_id;
}

void CtxObject::_printDebug(const SrcLoc& loc){
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

        std::cout << loc.file_name() << ":" << loc.line() << "\t" << loc.function_name()
                    << " Err: " << err_name << "(" << err << ")" << std::endl;
        err = glGetError();
    }
#endif
}