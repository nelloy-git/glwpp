#pragma once

#include <unordered_map>
#include <vector>

#include "metric/TimedArray.hpp"

namespace glwpp::Metrics {

class Category {
public:
    EXPORT Category();
    EXPORT virtual ~Category();

    EXPORT TimedArray& operator[](const std::string& name);
    EXPORT const TimedArray& operator[](const std::string& name) const;

    EXPORT std::vector<std::string> getAllNames() const;

private:
    std::unique_ptr<std::mutex> _lock;
    std::unique_ptr<std::unordered_map<std::string, TimedArray>> _records;
};

} // namespace glwpp::Metrics