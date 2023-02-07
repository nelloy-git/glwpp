#pragma once

#include <atomic>
#include <chrono>

#include "utils/Export.hpp"

namespace glwpp::Metrics {

class Value {
public:
    EXPORT Value(const std::chrono::high_resolution_clock::time_point& ts);
    EXPORT Value(const Value&) = default;
    EXPORT Value(Value&&) = default;
    EXPORT virtual ~Value();
    
    EXPORT void operator+=(double val);

    const std::chrono::high_resolution_clock::time_point ts;
    EXPORT size_t count() const;
    EXPORT double value() const;

private:
    std::atomic<size_t> _count;
    std::atomic<double> _value;
};

} // namespace glwpp::Metrics