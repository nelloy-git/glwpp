#pragma once

#include <thread>
#include <source_location>

#include "glwpp/gl/types.hpp"
#include "glwpp/utils/SrcLoc.hpp"
#include "glwpp/utils/Utils.hpp"

namespace glwpp {
    class Object;
}

namespace glwpp::gl {

class CtxObject {
    friend Object;

public:
    // Empty object
    CtxObject(const EmptyObj&){};
    // Refer same gl object
    CtxObject(const CtxObject& other) :
        _id(other._id){
    }

    template<auto D>
    static CtxObject create(const UInt& id){
        CtxObject obj(EmptyObj{});
        obj._id = sptr<UInt>(new UInt(id), Deleter<D>{});
        return obj;
    }

    virtual ~CtxObject(){
    }

    const UInt& getId() const;

protected:

    static void _printDebug(const SrcLoc& loc);

private:
    sptr<UInt> _id;


    template<auto D>
    class Deleter {
    public:
        Deleter() :
            _thread_id(std::this_thread::get_id()){
        };

        void operator()(UInt* gl_id){
            if (std::this_thread::get_id() == _thread_id){
                D(*gl_id);
            }
            delete gl_id;
        }

    private:
        const std::thread::id _thread_id;
    };
};

} // namespace glwpp::gl