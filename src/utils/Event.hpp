#pragma once

#include <atomic>
#include <deque>
#include <functional>
#include <memory>
#include <mutex>
#include <map>
#include <optional>

#include "utils/CmdQueue.hpp"
#include "utils/Export.hpp"
#include "utils/FuncWrapper.hpp"
#include "utils/GlobalThreadPool.hpp"
#include "utils/SrcLoc.hpp"

namespace glwpp {

namespace detail {

template<typename ... Args>
class EventActionData {
public:
    EventActionData(const auto& action, const SrcLoc& src_loc) :
        func(expand_func<Args...>(action)),
        src_loc(src_loc){
    }
    const std::function<bool(Args...)> func;
    SrcLoc src_loc;
};

template<typename ... Args>
class EventInner {
public:
    using ID = uint64_t;
    using IdMap = std::map<ID, std::shared_ptr<EventActionData<Args...>>>;
    using BeforeActionCallback = std::function<void(const SrcLoc&, const std::function<bool(Args...)>&, const Args&... args)>;

    void addQueued(const ID& id, const auto& action, const SrcLoc& src_loc){
        auto data = std::make_shared<EventActionData<Args...>>(action, src_loc);
        std::lock_guard lg(lock_queued);
        queued.insert_or_assign(id, data);
    }

    bool moveToActive(const ID& id){
        std::lock_guard lg_q(lock_queued);
        auto iter = queued.find(id);
        if (iter == queued.end()){
            return false;
        }
        std::lock_guard lg_a(lock_active);
        active.insert_or_assign(iter->first, iter->second);
        queued.erase(iter);
        return true;
    }
    
    bool removeAction(const ID& id){
        bool queued_found; 
        {
            std::lock_guard lg(lock_queued);
            auto queued_iter = queued.find(id);
            queued_found = (queued_iter != queued.end());
            if (queued_found){
                queued.erase(queued_iter);
            }
        }

        bool active_found;
        {
            std::lock_guard lg(lock_active);
            auto active_iter = active.find(id);
            active_found = (active_iter != active.end());
            if (active_found){
                active.erase(active_iter);
            }
        }
        return queued_found || active_found;
    }

    void emitActions(Args... args){
        std::lock_guard lg(lock_active);
        IdMap new_map;
        for (auto& pair : active){
            const ID& id = pair.first;
            const std::function<bool(Args...)>& func = pair.second->func;
            const SrcLoc& add_src_loc = pair.second->src_loc;

            bool repeat = false;
            {
                std::lock_guard lg_cb(lock_callbacks);
                if (before_action_callback){
                    before_action_callback.value()(add_src_loc, func, args...);
                }
            }

            try {
                repeat = func(args...);
            } catch (const std::exception& e) {
                std::cout << "ERROR: " << e.what() << std::endl;
                std::cout << add_src_loc.to_string().c_str() << std::endl;
            }

            if (repeat){
                new_map[pair.first] = pair.second;
            }
        }
        active = new_map;
    }

    void setBeforeActionCallback(const std::optional<BeforeActionCallback>& callback){
        std::lock_guard lg(lock_queued);
        before_action_callback = callback;
    }

private:
    std::mutex lock_active;
    IdMap active;

    std::mutex lock_queued;
    IdMap queued;
    
    std::mutex lock_callbacks;
    std::optional<BeforeActionCallback> before_action_callback;

};



} // namespace detail

template<typename ... Args>
class Event {
public:
    using ID = detail::EventInner<Args...>::ID;
    using IdMap = detail::EventInner<Args...>::IdMap;
    using BeforeActionCallback = detail::EventInner<Args...>::BeforeActionCallback;

    EXPORT Event(const std::shared_ptr<BS::thread_pool>& emitter_pool);
    Event(const Event&) = delete;
    Event(const Event&&) = delete;
    ~Event();

    EXPORT std::pair<ID, std::future<void>> addActionQueued(const auto& action, const SrcLoc& src_loc = SrcLoc{});
    EXPORT std::pair<ID, std::future<void>> addActionNow(const auto& action, const SrcLoc& src_loc = SrcLoc{});

    EXPORT std::future<bool> delActionQueued(const ID& id);
    EXPORT std::future<bool> delActionNow(const ID& id);

    EXPORT std::future<void> emitQueued(const Args&... args, const SrcLoc& src_loc = SrcLoc{});
    EXPORT std::future<void> emitNow(const Args&... args, const SrcLoc& src_loc = SrcLoc{});

    // EXPORT std::future<void> setBeforeEmitStartQueued(const auto& callback);
    EXPORT std::future<void> setBeforeActionCallback(const std::optional<BeforeActionCallback>& callback){
        _inner->setBeforeActionCallback(callback);
    }

private:
    std::shared_ptr<detail::EventInner<Args...>> _inner;
    std::shared_ptr<CmdQueue> _emitter;
    std::atomic<ID> _cur_id;
    ID _getUniqId();
};





template<typename ... Args>
inline Event<Args...>::Event(const std::shared_ptr<BS::thread_pool>& emitter_pool) :
    _inner(new detail::EventInner<Args...>),
    _emitter(new CmdQueue(emitter_pool)),
    _cur_id(0){
}

template<typename ... Args>
inline Event<Args...>::~Event(){
}

template<typename ... Args>
inline std::pair<typename Event<Args...>::ID, std::future<void>>
Event<Args...>::addActionQueued(const auto& action,
                                const SrcLoc& src_loc){
    using Expanded = decltype(expand_func<Args...>(action));
    static_assert(std::is_same_v<std::invoke_result_t<Expanded, Args...>, bool>, __FUNCTION__": wrong function signature. Must return bool");

    auto id = _getUniqId();
    auto promise = std::make_shared<std::promise<void>>();

    _inner->addQueued(id, action, src_loc);
    _emitter->push_back([id, promise, inner = _inner](){
        inner->moveToActive(id);
        promise->set_value();
    });

    return std::make_pair(id, promise->get_future());
}

template<typename ... Args>
inline std::pair<typename Event<Args...>::ID, std::future<void>>
Event<Args...>::addActionNow(const auto& action,
                             const SrcLoc& src_loc){
    using Expanded = decltype(expand_func<Args...>(action));
    static_assert(std::is_same_v<std::invoke_result_t<Expanded, Args...>, bool>, __FUNCTION__": wrong function signature. Must return bool");

    auto id = _getUniqId();
    auto promise = std::make_shared<std::promise<void>>();

    _inner->addQueued(id, action, src_loc);
    _emitter->push_front([id, promise, inner = _inner](){
        inner->moveToActive(id);
        promise->set_value();
    });

    return std::make_pair(id, promise->get_future());
}

template<typename ... Args>
inline std::future<bool>
Event<Args...>::delActionQueued(const ID& id){
    auto promise = std::make_shared<std::promise<bool>>();
    _emitter->push_back([id, promise, inner = _inner](){
        bool found = inner->removeAction(id);
        promise->set_value(found);
    });
    return promise->get_future();
}

template<typename ... Args>
inline std::future<bool>
Event<Args...>::delActionNow(const ID& id){
    auto promise = std::make_shared<std::promise<bool>>();
    _emitter->push_front([id, promise, inner = _inner](){
        bool found = inner->removeAction(id);
        promise->set_value(found);
    });
}

template<typename ... Args>
inline std::future<void>
Event<Args...>::emitQueued(const Args&... args,
                           const SrcLoc& src_loc){
    auto promise = std::make_shared<std::promise<void>>();
    _emitter->push_back([promise, inner = _inner, args...](){
        inner->emitActions(args...);
        promise->set_value();
    });

    return promise->get_future();
}

template<typename ... Args>
inline std::future<void>
Event<Args...>::emitNow(const Args&... args,
                        const SrcLoc& src_loc){
    auto promise = std::make_shared<std::promise<void>>();
    _emitter->push_front([promise, inner = _inner, args...](){
        inner->emitActions(args...);
        promise->set_value();
    });

    return promise->get_future();
}

template<typename ... Args>
inline Event<Args...>::ID Event<Args...>::_getUniqId(){
    return _cur_id.fetch_add(1);
}

} // namespace nglpmt::native