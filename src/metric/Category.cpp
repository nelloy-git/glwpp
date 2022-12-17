#include "metric/Category.hpp"

using namespace glwpp;
using namespace Metrics;

Category::Category() :
    _lock(new std::mutex),
    _records(new std::unordered_map<std::string, TimedArray>){
}

Category::~Category(){
}

TimedArray& Category::operator[](const std::string& name){
    std::lock_guard lg(*_lock);
    if (!_records->contains(name)){
        _records->emplace(std::piecewise_construct, std::make_tuple(name), std::tuple<>());
    }
    return _records->at(name);
}

const TimedArray& Category::operator[](const std::string& name) const {
    std::lock_guard lg(*_lock);
    if (!_records->contains(name)){
        _records->emplace(std::piecewise_construct, std::make_tuple(name), std::tuple<>());
    }
    return _records->at(name);
}

std::vector<std::string> Category::getAllNames() const {
    std::lock_guard lg(*_lock);
    std::vector<std::string> list;
    for (auto& record : *_records){
        list.push_back(record.first);
    }
    return list;
}