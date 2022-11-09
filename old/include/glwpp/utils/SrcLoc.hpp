#pragma once

#include <memory>
#include <string>
#include <unordered_map>

namespace glwpp::utils {

#ifndef GLWPP_DEBUG

class SrcLoc {
public:
    SrcLoc(){}
}

#else

class SrcLoc {
public:
    SrcLoc(char const* file = __builtin_FILE(), 
           std::uint_least32_t line = __builtin_LINE(),
           char const* function = __builtin_FUNCTION()) noexcept {
        _loc = std::make_shared<Loc>();
        _loc->file = file;
        _loc->line = line;
        _loc->function = function;
        _loc->prev = nullptr;
    }
    SrcLoc(const SrcLoc& other,
           char const* file = __builtin_FILE(), 
           std::uint_least32_t line = __builtin_LINE(),
           char const* function = __builtin_FUNCTION()){
        _loc = std::make_shared<Loc>();

        if (ends_with(std::string(file), "xutility") && line == 158){
            _loc->file = other._loc->file;
            _loc->line = other._loc->line;
            _loc->function = other._loc->function;
            _loc->prev = other._loc->prev;
        } else {
            _loc->file = file;
            _loc->line = line;
            _loc->function = function;
            _loc->prev = other._loc;
        }
    };
    SrcLoc(const SrcLoc&& other) : _loc(other._loc){};

    inline auto file_name() const {return _loc->file;}
    inline auto line() const {return _loc->line;}
    inline auto function_name() const {return _loc->function;}
    inline std::string to_string() const {
        return _loc->to_string();
    }

private:
    struct Loc {
        char const* file;
        std::uint_least32_t line;
        char const* function;
        std::shared_ptr<Loc> prev;

        inline std::string to_string() const {
            auto str = std::string(file) + ":" + std::to_string(line) + "\t" + std::string(function);
            if (prev){
                str += "\n" + prev->to_string();
            }
            return str;
        }
    };
    std::shared_ptr<Loc> _loc;

    static inline bool ends_with(const std::string& value, const std::string& ending){
        if (ending.size() > value.size()) return false;
        return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
    }
};

#endif


} // namespace glwpp