#pragma once

#include "thread_pool.hpp"

#include "glwpp/utils/Ptr.hpp"

namespace glwpp {

class EventThreadPool {
public:
    static sptr<thread_pool> get(){
        static auto pool = std::make_shared<thread_pool>();
        return pool;
    }
};

}