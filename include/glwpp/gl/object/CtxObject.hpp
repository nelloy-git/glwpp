#pragma once

#include <thread>
#include <source_location>

#include "glwpp/gl/types.hpp"
#include "glwpp/utils/SrcLoc.hpp"
#include "glwpp/utils/Utils.hpp"

namespace glwpp::gl {

class CtxObject {
public:
    // Dummy object. Can be used for preallocation.
    CtxObject(const Dummy&){_id = make_sptr<UInt>(0);}

    // N: gl::UInt* (ArgsN...) - initialization of gl object.
    // D: void (gl::UInt *id, bool is_init_thread) - deletion of gl object. In case of init thread is removed is_init_thread == false
    // ArgsN - initialization arguments
    template<class N, class D, class ... ArgsN>
    CtxObject(const N& init, const D& del, const ArgsN&... args_n) :
        _id(init(args_n...), _getDeleter(del)){
    };
    virtual ~CtxObject() = 0;

    const UInt& getId() const;

protected:
    static void _printDebug(const SrcLoc& loc);

private:
    sptr<UInt> _id;

    template<class D>
    auto _getDeleter(const D& del){
        return [thread_id = std::this_thread::get_id(), del](gl::UInt *id){
            del(id, thread_id == std::this_thread::get_id());
        };
    }
};

inline CtxObject::~CtxObject(){
}

} // namespace glwpp::gl