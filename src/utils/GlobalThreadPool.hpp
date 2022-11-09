#pragma once

#include "BS_thread_pool.hpp"

namespace glwpp {

class GlobalThreadPool {
public:
    static std::shared_ptr<BS::thread_pool> get();

private:
    GlobalThreadPool();
    ~GlobalThreadPool();
};

} // namespace nglpmt