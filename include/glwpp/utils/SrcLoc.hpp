#pragma once

#include <memory>
#include <source_location>
namespace glwpp {

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
           std::uint_least32_t column = __builtin_COLUMN(),
           char const* function = __builtin_FUNCTION()) noexcept {
        _loc = std::make_shared<Loc>();
        _loc->file = file;
        _loc->line = line;
        _loc->column = column;
        _loc->function = function;
    }
    SrcLoc(const SrcLoc& other) : _loc(other._loc){};
    inline auto file_name() const {return _loc->file;}
    inline auto line() const {return _loc->line;}
    inline auto function_name() const {return _loc->function;}

private:
    struct Loc {
        char const* file;
        std::uint_least32_t line;
        std::uint_least32_t column;
        char const* function;
    };
    std::shared_ptr<Loc> _loc;
};

#endif


} // namespace glwpp