#pragma once

#include <thread>
#include <source_location>

#include "glwpp/gl/types.hpp"
#include "glwpp/utils/SrcLoc.hpp"
#include "glwpp/utils/Utils.hpp"

namespace glwpp::gl {

class CtxObject {
public:
    // N: gl::UInt* (ArgsN...) - initialization of gl object.
    // D: void (gl::UInt *id, bool is_init_thread) - deletion of gl object. In case of init thread is removed is_init_thread == false
    // ArgsN - initialization arguments
    template<class N, class D, class ... ArgsN>
    CtxObject(const N& init, const D& del, const ArgsN&... args_n) :
        _id(init(args_n...), _getDeleter(del)){
    };
    virtual ~CtxObject() = 0;

    UInt getId() const;

protected:
    static void _printDebug(const SrcLoc& loc);

private:
    sptr<UInt> _id;

    template<class D>
    auto _getDeleter(const D& del){
        return [thread_id = std::this_thread::get_id(), del](gl::UInt *id){
            del(id, std::this_thread::get_id() == thread_id);
        };
    }
};

inline CtxObject::~CtxObject(){
}

} // namespace glwpp::gl