#pragma once

#include <atomic>
#include <chrono>
#include <deque>
#include <mutex>
#include <vector>
#include <unordered_map>

#include "utils/Export.hpp"

namespace glwpp {

class MetricRecordValue {
public:
    EXPORT MetricRecordValue(const std::chrono::high_resolution_clock::time_point& ts);
    EXPORT MetricRecordValue(MetricRecordValue&) = default;
    EXPORT MetricRecordValue(MetricRecordValue&&) = default;
    EXPORT ~MetricRecordValue();

    const std::chrono::high_resolution_clock::time_point ts;
    size_t count;
    double value;
};

class MetricRecord {
public:
    EXPORT MetricRecord();
    EXPORT ~MetricRecord();

    EXPORT void operator+=(double val);
    EXPORT void inc(double val = 1.0);
    EXPORT void next();

    EXPORT const std::chrono::high_resolution_clock::time_point& start();
    EXPORT std::atomic<std::chrono::milliseconds>& value_period();
    EXPORT std::atomic<size_t>& max_values();
    EXPORT std::atomic<double>& sum();

    EXPORT MetricRecordValue getLast();
    EXPORT std::vector<MetricRecordValue> getLast(size_t n);
    EXPORT double getAvg();

private:
    const std::chrono::high_resolution_clock::time_point _start;
    std::atomic<std::chrono::milliseconds> _value_period;
    std::atomic<size_t> _max_values;
    std::atomic<double> _sum;

    std::mutex _lock;
    std::deque<MetricRecordValue> _values;
    std::chrono::high_resolution_clock::time_point _last;
};

class Metrics {
public:
    EXPORT ~Metrics();

    EXPORT static Metrics& inst();

    EXPORT MetricRecord& operator[](const std::string& name);
    EXPORT std::vector<std::pair<std::string, MetricRecordValue>> getLast();

private:
    Metrics();

    std::mutex _lock;
    std::unordered_map<std::string, MetricRecord> _records;

};

} // namespace glwpp