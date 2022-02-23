#pragma once

#include "thread_pool.hpp"

#include "glwpp/utils/Utils.hpp"

namespace glwpp {

class EventThreadPool {
public:
    static sptr<thread_pool> get(){
        static auto pool = make_sptr<thread_pool>();
        return pool;
    }
};

}