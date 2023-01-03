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

    EXPORT void lock();
    EXPORT void unlock();

    EXPORT size_t size() const;

    template<bool ignore_lock = false>
    void push_back(const std::function<void()>& cmd){
        if constexpr (ignore_lock){
            _push_back_no_lock(cmd);
        } else {
            _push_back_with_lock(cmd);
        }
    }

    template<bool ignore_lock = false>
    void push_front(const std::function<void()>& cmd){
        if constexpr (ignore_lock){
            _push_front_no_lock(cmd);
        } else {
            _push_front_with_lock(cmd);
        }
    }

private:
    std::shared_ptr<std::mutex> _lock;
    std::shared_ptr<std::atomic<bool>> _is_executing;
    std::shared_ptr<std::deque<std::function<void()>>> _queue;
    std::shared_ptr<BS::thread_pool> _pool;

    EXPORT void _push_back_with_lock(const std::function<void()>& cmd);
    EXPORT void _push_back_no_lock(const std::function<void()>& cmd);

    EXPORT void _push_front_with_lock(const std::function<void()>& cmd);
    EXPORT void _push_front_no_lock(const std::function<void()>& cmd);

    void _update();
};

} //namespace nglpmt::native 