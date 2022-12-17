#include "metric/TimedArray.hpp"

using namespace glwpp;
using namespace Metrics;

const std::chrono::milliseconds TimedArray::DEFAULT_PERIOD = std::chrono::seconds(1);
const std::chrono::milliseconds TimedArray::DEFAULT_MAX_TIME = std::chrono::minutes(1);

TimedArray::TimedArray() :
    startedAt(std::chrono::high_resolution_clock::now()),
    _total_count(0),
    _total_value(0),
    _period(DEFAULT_PERIOD),
    _max_time(DEFAULT_MAX_TIME),
    _sum(0){
    _values.emplace_back(startedAt);
}

TimedArray::~TimedArray(){
}

std::pair<size_t, double> TimedArray::getTotal(){
    std::lock_guard lg(_lock);
    return {_total_count, _total_value};
}

std::pair<size_t, double> TimedArray::getSaved(){
    std::lock_guard lg(_lock);
    size_t sum_count = 0;
    double sum_value = 0;
    for (auto& value : _values){
        sum_count += value.count();
        sum_value += value.value();
    }
    return {sum_count, sum_value};
}

void TimedArray::operator+=(double val){
    using ms = std::chrono::milliseconds;

    auto now = std::chrono::high_resolution_clock::now();
    auto dt = now - _values.back().ts;
    auto period = _period.load();
    auto max_time = _max_time.load();

    std::lock_guard lg(_lock);
    if (period.count() != 0 && dt > period){
        size_t passed_periods = std::chrono::duration_cast<ms>(dt).count() / std::chrono::duration_cast<ms>(period).count();
        _values.emplace_back(_values.back().ts + passed_periods * period);

        while(max_time.count() != 0 && _values.front().ts < now - max_time){
            _values.pop_front();
        }
    }

    _values.back() += val;
    _total_count += 1;
    _total_value += val;
}

TimedArray& TimedArray::operator++(){
    (*this) += 1;
    return *this;
}

TimedArray& TimedArray::operator++(int val){
    (*this) += val;
    return *this;
}

std::chrono::milliseconds TimedArray::getPeriod() const {
    return _period;
}

void TimedArray::setPeriod(const std::chrono::milliseconds& period){
    _period = period;
}

std::chrono::milliseconds TimedArray::getMaxTime() const {
    return _max_time;
}

void TimedArray::setMaxTime(const std::chrono::milliseconds& max_time){
    _max_time = max_time;
}