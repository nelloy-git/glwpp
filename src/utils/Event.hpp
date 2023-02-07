#pragma once

#include <atomic>
#include <concepts>
#include <memory>

#include "utils/CmdQueue.hpp"
#include "utils/FuncWrapper.hpp"
#include "utils/SrcLoc.hpp"

#include "utils/Event/ActionList.hpp"

namespace glwpp {

template<typename... Args>
class Event {
public:
    using ActionList = detail::EventActionQueue<Args...>;
    using ID = ActionList::ID;

    Event(const std::shared_ptr<BS::thread_pool>& emitter_pool);
    Event(const Event&) = delete;
    Event(const Event&&) = delete;
    virtual ~Event();

    void lock(){_emitter.lock();}
    void unlock(){_emitter.unlock();}

    template<auto F, bool ignore_lock = false>
    ID add(const int& priority, const SrcLoc& src_loc = SrcLoc{});

    template<bool ignore_lock = false>
    ID add(const int& priority, std::predicate<Args...> auto&& action, const SrcLoc& src_loc = SrcLoc{});

    template<bool ignore_lock = false>
    std::future<bool> remove(const ID& id);

    template<bool ignore_lock = false>
    std::future<void> emit(const Args&... args);

    template<auto F, bool ignore_lock = false>
    std::future<void> emit_convertable(const auto&... args);

private:
    CmdQueue _emitter;
    std::shared_ptr<ActionList> _list;
    std::atomic<ID> _cur_id;
    ID _getUniqId();
};





template<typename... Args>
inline Event<Args...>::Event(const std::shared_ptr<BS::thread_pool>& emitter_pool) :
    _emitter(emitter_pool),
    _list(new ActionList()),
    _cur_id(0){
}

template<typename... Args>
inline Event<Args...>::~Event(){
}

template<typename... Args>
template<auto F, bool ignore_lock>
Event<Args...>::ID Event<Args...>::add(const int& priority, const SrcLoc& src_loc){
    auto id = _getUniqId();
    _emitter.push_back<ignore_lock>([priority, id, src_loc, list = _list](){
        list->template add<F>(priority, id, src_loc);
    });
    return id;
}

template<typename... Args>
template<bool ignore_lock>
Event<Args...>::ID Event<Args...>::add(const int& priority, std::predicate<Args...> auto&& action, const SrcLoc& src_loc){
    auto id = _getUniqId();
    _emitter.push_back<ignore_lock>([priority, id, action, src_loc, list = _list](){
        list->add(priority, id, action, src_loc);
    });
    return id;
}

template<typename... Args>
template<bool ignore_lock>
std::future<bool> Event<Args...>::remove(const ID& id){
    auto promise = std::make_shared<std::promise<bool>>();
    _emitter.push_back<ignore_lock>([id, promise, list = _list](){
        promise->set_value(list->remove(id));
    });
    return promise->get_future();
}

template<typename... Args>
template<bool ignore_lock>
std::future<void> Event<Args...>::emit(const Args&... args){
    auto promise = std::make_shared<std::promise<void>>();
    _emitter.push_back<ignore_lock>([promise, list = _list, args...](){
        list->emit(args...);
        promise->set_value();
    });
    return promise->get_future();
}

template<typename... Args>
template<auto F, bool ignore_lock>
std::future<void> Event<Args...>::emit_convertable(const auto&... args){
    static_assert(std::is_invocable_r_v<std::tuple<Args...>, decltype(F), decltype(std::make_tuple(args...))>, "F must be callable with const auto& args and return tuple<Args...>");

    auto promise = std::make_shared<std::promise<void>>();
    _emitter.push_back<ignore_lock>([promise, list = _list, args = std::make_tuple(args...)](){
        std::apply(&ActionList::emit, std::tuple_cat(std::forward_as_tuple(*list), F(args)));
        promise->set_value();
    });
    return promise->get_future();
}

template<typename... Args>
inline Event<Args...>::ID Event<Args...>::_getUniqId(){
    return _cur_id.fetch_add(1);
}

} // namespace nglpmt::native