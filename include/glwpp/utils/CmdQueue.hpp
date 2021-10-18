#pragma once

#include <condition_variable>
#include <functional>
#include <mutex>
#include <optional>
#include <thread>
#include <queue>

namespace glwpp {

class CmdQueue {
public:
    using Cmd = std::function<void()>;

    CmdQueue(std::optional<Cmd> initializer = std::nullopt,
             std::optional<Cmd> finalizer = std::nullopt);
    virtual ~CmdQueue();

    void push(const Cmd cmd);

    bool isExecuting();
    bool execute();
    void wait();

protected:
    void _threadFunction(std::optional<Cmd> initializer,
                         std::optional<Cmd> finalizer);
    void _swapQueues();
    void _executeQueue();

    std::atomic<bool> _alive;
    std::thread _thread;

    std::mutex _lock_queue;
    std::queue<Cmd> _queue;
    std::queue<Cmd> _active;

    std::mutex _lock_execution;
    std::atomic<bool> _executing;
    std::condition_variable _cv_start;
    std::condition_variable _cv_finish;
};

}