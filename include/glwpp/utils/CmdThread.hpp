#pragma once

#include <condition_variable>
#include <functional>
#include <mutex>

#include "glwpp/utils/container/FifoQueueMT.hpp"
#include "glwpp/utils/container/Cmd.hpp"
#include "glwpp/utils/FuncWrapper.hpp"

namespace glwpp {

class CmdThread final {
public:
    CmdThread(Cmd<void, CmdThread&> &init,
              Cmd<void, CmdThread&> &final);
    CmdThread(const CmdThread&) = delete;
    CmdThread(CmdThread&&) = delete;
    CmdThread& operator=(const CmdThread&) = delete;
    CmdThread& operator=(CmdThread&&) = delete;
    virtual ~CmdThread();

    template<class ... CmdArgs>
    void push(std::weak_ptr<CmdWatcher> watcher, Cmd<CmdAct, CmdArgs...> cmd){
        _queue.push(std::make_shared<CmdRunner<CmdAct, CmdThread&>>(watcher, cmd));
        _empty = false;
        _empty.notify_one();
    }

    template<class F>
    void push(std::weak_ptr<CmdWatcher> watcher, F cmd){
        _queue.push(std::make_shared<CmdRunner<CmdAct, CmdThread&>>(watcher, std::function(cmd)));
        _empty = false;
        _empty.notify_one();
    }

protected:
    std::atomic<bool> _alive;
    std::atomic<bool> _empty;
    
    FifoQueueMT<std::shared_ptr<CmdRunner<CmdAct, CmdThread&>>> _queue;
    std::thread _thread;
    void _threadFunction(Cmd<void, CmdThread&> init,
                         Cmd<void, CmdThread&> final);
};

}