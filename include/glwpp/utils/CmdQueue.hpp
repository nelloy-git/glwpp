#pragma once

#include <condition_variable>
#include <functional>
#include <mutex>
#include <optional>
#include <thread>
#include <queue>

#include "glwpp/utils/DoubleQueue.hpp"
// #include "glwpp/utils/Functor.hpp"

namespace glwpp {

class CmdQueue {
public:
    using Cmd = std::function<void()>;

    CmdQueue(std::optional<Cmd> initializer = std::nullopt,
             std::optional<Cmd> finalizer = std::nullopt);
    virtual ~CmdQueue();

    inline void push(const Cmd cmd){_queue.push(cmd);};

    bool isExecuting();
    bool execute();
    void wait();
    bool waitFor(const std::chrono::duration<double, std::nano> time);

protected:
    void _threadFunction(std::optional<Cmd> initializer,
                         std::optional<Cmd> finalizer);
    void _swapQueues();
    void _executeQueue();

    std::atomic<bool> _alive;
    std::thread _thread;

    DoubleQueue<Cmd> _queue;

    std::mutex _lock_execution;
    std::atomic<bool> _executing;
    std::condition_variable _cv_start;
    std::condition_variable _cv_finish;
};

}