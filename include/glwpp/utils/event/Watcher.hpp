#pragma once

#include <atomic>

namespace glwpp {

class Watcher final {
public:
    Watcher() :
        _alive(true),
        _uses(0),
        _runs_done(0),
        _running(0),
        _idle(true){
    }
    Watcher(const Watcher&) = delete;
    Watcher(Watcher&&) = delete;
    Watcher& operator=(const Watcher&) = delete;
    Watcher& operator=(Watcher&&) = delete;
    ~Watcher(){
        _alive = false;
        wait_for_idle();

        // Free all waiters.
        --_running;
        _running.notify_all();
        --_runs_done;
        _runs_done.notify_all();
    }

    inline size_t get_uses() const {return _uses;}
    inline size_t get_done() const {return _runs_done;}
    inline size_t get_running() const {return _running;}
    inline bool is_idle() const {return _idle;}

    inline bool lock_use(){
        if (!_alive) return false;
        ++_uses;
        return true;
    }

    inline bool unlock_use(){
        if (!_alive) return false;
        if (_uses < 1) throw std::runtime_error("No uses to free.");
        --_uses;
        return true;
    }

    inline bool lock_running(){
        if (!_alive) return false;
        ++_running;
        _running.notify_all();
        
        _idle = _running == 0;
        _idle.notify_all();
        return true;
    }

    bool unlock_running(bool done){
        if (!_alive) return false;
        if (_running < 1) throw std::runtime_error("No runs to free.");

        --_running;
        _running.notify_all();

        _idle = _running == 0;
        _idle.notify_all();

        if (done) {
            ++_runs_done;
            _runs_done.notify_all();
        }
        return true;
    }

    inline bool wait_for_done() const {
        if (!_alive) return false;
        _runs_done.wait(_runs_done);
        return true;
    }

    inline bool wait_for_idle() const {
        if (!_alive) return false;
        _idle.wait(false);
        return true;
    }

    inline bool wait_for_runnings_change() const {
        if (!_alive) return false;
        _running.wait(_running);
        return true;
    }

private:
    std::atomic<bool> _alive;
    std::atomic<size_t> _uses;
    std::atomic<size_t> _runs_done;
    std::atomic<size_t> _running;
    std::atomic<bool>   _idle;
};

}