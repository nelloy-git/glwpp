#include "glwpp/utils/event/EventStatus.hpp"

#include <thread>

using namespace glwpp;

namespace {
    static const auto true_checker = [](const std::chrono::microseconds&){return true;};
    static const auto false_checker = [](const std::chrono::microseconds& time){
        std::this_thread::sleep_for(time);
        return false;
    };
    static auto newDefaultChecker(bool result){
        if (result){
            return new std::deque<std::function<bool(const std::chrono::microseconds&)>>{true_checker};
        } else {
            return new std::deque<std::function<bool(const std::chrono::microseconds&)>>{false_checker};
        }
    };
}

EventStatus::EventStatus(bool result) :
    _checkers(newDefaultChecker(result)){
}

EventStatus::EventStatus(const sptr<std::deque<std::function<bool(const std::chrono::microseconds&)>>> &checkers) :
    _checkers(checkers){
}

EventStatus::EventStatus(const EventStatus& other) :
    _checkers(other._checkers){
}

EventStatus::EventStatus(const EventStatus&& other) :
    _checkers(other._checkers){
}

EventStatus EventStatus::operator=(const EventStatus& other){
    return EventStatus(other);
}

EventStatus EventStatus::operator=(const EventStatus&& other){
    return EventStatus(other);
}


bool EventStatus::isEmitFinished(const std::chrono::microseconds& wait){
    for (auto &checker : *_checkers){
        if (!checker(wait)){
            return false;
        }
    }
    return true;
}