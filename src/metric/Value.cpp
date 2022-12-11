#include "metric/Value.hpp"

using namespace glwpp;
using namespace Metrics;

Value::Value(const std::chrono::high_resolution_clock::time_point& ts) :
    ts(ts),
    _count(0),
    _value(0){
}

Value::~Value(){
}

void Value::operator+=(double val){
    ++_count;
    _value += val;
}

size_t Value::count(){
    return _count.load();
}

double Value::value(){
    return _value.load();
}