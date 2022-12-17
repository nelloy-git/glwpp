#pragma once

#include <deque>
#include <mutex>

#include "metric/Value.hpp"

namespace glwpp::Metrics {

class TimedArray {
public:
    static const std::chrono::milliseconds DEFAULT_PERIOD;      // 1sec
    static const std::chrono::milliseconds DEFAULT_MAX_TIME;    // 1min

    EXPORT TimedArray();
    EXPORT virtual ~TimedArray();

    EXPORT void operator+=(double val);
    EXPORT TimedArray& operator++();
    EXPORT TimedArray& operator++(int);

    EXPORT std::pair<size_t, double> getTotal();
    EXPORT std::pair<size_t, double> getSaved();

    EXPORT std::chrono::milliseconds getPeriod() const;
    EXPORT void setPeriod(const std::chrono::milliseconds& period);

    EXPORT std::chrono::milliseconds getMaxTime() const;
    EXPORT void setMaxTime(const std::chrono::milliseconds& period);

    const std::chrono::high_resolution_clock::time_point startedAt;

private:
    std::mutex _lock;
    std::atomic<std::chrono::milliseconds> _period;
    std::atomic<std::chrono::milliseconds> _max_time;
    std::atomic<double> _sum;

    std::deque<Value> _values;
    size_t _total_count;
    double _total_value;

};

} // namespace glwpp::Metrics