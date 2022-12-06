#include "utils/Metrics.hpp"

using namespace glwpp;

MetricRecordValue::MetricRecordValue(const std::chrono::high_resolution_clock::time_point& ts) :
    ts(ts),
    count(0),
    value(0){
}

MetricRecordValue::~MetricRecordValue(){
}

MetricRecord::MetricRecord() :
    _start(std::chrono::high_resolution_clock::now()),
    _value_period(std::chrono::milliseconds(0)),
    _max_values(1000),
    _sum(0){
    next();
}

MetricRecord::~MetricRecord(){
}

void MetricRecord::operator+=(double val){
    inc(val);
}

void MetricRecord::inc(double val){
    auto t = std::chrono::high_resolution_clock::now();
    std::lock_guard lg(_lock);
    auto dt = t - _last;
    auto period = _value_period.load();
    if (period.count() != 0 && dt > period){
        std::chrono::milliseconds dt_ms = std::chrono::duration_cast<std::chrono::milliseconds>(dt);
        size_t n = dt_ms.count() / period.count() + 1;
        _last += n * period;
        _values.emplace_back(_last);

        if (_values.size() > _max_values){
            _values.pop_front();
        }
    }

    _values.back().count += 1;
    _values.back().value += val;
    _sum += val;
}

void MetricRecord::next(){
    std::lock_guard lg(_lock);
    _last = std::chrono::high_resolution_clock::now();
    _values.emplace_back(_last);
}

const std::chrono::high_resolution_clock::time_point& MetricRecord::start(){
    return _start;
}

std::atomic<std::chrono::milliseconds>& MetricRecord::value_period(){
    return _value_period;
}

std::atomic<size_t>& MetricRecord::max_values(){
    return _max_values;
}

std::atomic<double>& MetricRecord::sum(){
    return _sum;
}


MetricRecordValue MetricRecord::getLast(){
    std::lock_guard lg(_lock);
    return _values.back();
}

std::vector<MetricRecordValue> MetricRecord::getLast(size_t n){
    std::lock_guard lg(_lock);
    n = std::min(n, _values.size());
    return std::vector<MetricRecordValue>(_values.end() - n, _values.end());
}

double MetricRecord::getAvg(){
    std::lock_guard lg(_lock);
    size_t n = 0;
    double sum = 0;
    for (auto& metric_value : _values){
        n += metric_value.count;
        sum += metric_value.value;
    }
    return sum / n;
}

Metrics::Metrics(){
}

Metrics::~Metrics(){
}

Metrics& Metrics::inst(){
    static Metrics instance;
    return instance;
}

MetricRecord& Metrics::operator[](const std::string& name){
    std::lock_guard lg(_lock);
    if (!_records.contains(name)){
        _records.emplace(std::piecewise_construct, std::make_tuple(name), std::tuple<>());
    }
    return _records[name];
}

std::vector<std::pair<std::string, MetricRecordValue>> Metrics::getLast(){
    std::lock_guard lg(_lock);
    std::vector<std::pair<std::string, MetricRecordValue>> list;
    for (auto& pair : _records){
        list.push_back({pair.first, pair.second.getLast()});
    }
    return list;
}