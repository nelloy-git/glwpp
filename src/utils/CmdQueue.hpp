#pragma once

#include <atomic>
#include <deque>
#include <memory>

#include "BS_thread_pool.hpp"

#include "utils/Export.hpp"

namespace glwpp {

class CmdQueue {
public:
    EXPORT CmdQueue(const std::shared_ptr<BS::thread_pool>& pool);
    CmdQueue(const CmdQueue&) = delete;
    CmdQueue(const CmdQueue&&) = delete;
    ~CmdQueue();

    EXPORT size_t size() const;
    EXPORT void push_back(const std::function<void()>& cmd);
    EXPORT void push_front(const std::function<void()>& cmd);

private:
    std::shared_ptr<std::mutex> _lock;
    std::shared_ptr<std::atomic<bool>> _is_executing;
    std::shared_ptr<std::deque<std::function<void()>>> _queue;
    std::shared_ptr<BS::thread_pool> _pool;

    void _update();
};

} //namespace nglpmt::native 