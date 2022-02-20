#include <chrono>
#include <deque>
#include <functional>

#include "glwpp/utils/Utils.hpp"

namespace glwpp {

class EventStatus {
public:
    EventStatus(bool result);
    EventStatus(const sptr<std::deque<std::function<bool(const std::chrono::microseconds&)>>> &checkers);
    EventStatus(const EventStatus&);
    EventStatus(const EventStatus&&);
    EventStatus operator=(const EventStatus&);
    EventStatus operator=(const EventStatus&&);

    bool isEmitFinished(const std::chrono::microseconds& wait);

private:
    const sptr<std::deque<std::function<bool(const std::chrono::microseconds&)>>> _checkers;
};

}