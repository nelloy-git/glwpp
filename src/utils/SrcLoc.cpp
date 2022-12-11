#include "utils/SrcLoc.hpp"

using namespace glwpp;

#ifdef GLWPP_DEBUG

struct SrcLoc::Loc {
    std::string file;
    std::uint_least32_t line;
    std::string function;
    std::shared_ptr<Loc> prev;

    inline std::string to_string_full(bool print_funcs, const std::string& func_sep) const {
        auto str = to_string_last(print_funcs, func_sep);
        if (prev){
            str += "\n" + prev->to_string_full(print_funcs, func_sep);
        }
        return str;
    }

    inline std::string to_string_last(bool print_funcs, const std::string& func_sep) const {
        return std::string(function) + "\t\t" + std::string(file) + ":" + std::to_string(line);
    }
};

SrcLoc::SrcLoc(const std::string& file, 
               std::uint_least32_t line,
               const std::string& function){
    _loc = std::make_shared<Loc>();
    _loc->file = file;
    _loc->line = line;
    _loc->function = function;
    _loc->prev = nullptr;
};

SrcLoc::SrcLoc(const SrcLoc& other,
               const std::string& file, 
               std::uint_least32_t line,
               const std::string& function){
    _loc = std::make_shared<Loc>();
    _loc->file = file;
    _loc->line = line;
    _loc->function = function;
    _loc->prev = other._loc;
};

SrcLoc::SrcLoc(SrcLoc&& other) :
    _loc(other._loc){
};

SrcLoc::SrcLoc(const SrcLoc&& other) :
    _loc(other._loc){
};


SrcLoc& SrcLoc::add(const std::string& file, 
                    std::uint_least32_t line,
                    const std::string& function){
    auto loc = std::make_shared<Loc>();
    loc->prev = _loc;
    _loc = loc;
    _loc->file = file;
    _loc->line = line;
    _loc->function = function;
    return *this;
}

const SrcLoc& SrcLoc::add(const std::string& file, 
                          std::uint_least32_t line,
                          const std::string& function) const {
    auto prev = std::make_shared<Loc>();
    *prev = *_loc;
    _loc->file = file;
    _loc->line = line;
    _loc->function = function;
    _loc->prev = prev;
    return *this;
}

const std::string& SrcLoc::file_name() const {
    return _loc->file;
}

uint_least32_t SrcLoc::line() const {
    return _loc->line;
}

const std::string& SrcLoc::function_name() const {
    return _loc->function;
}

std::string SrcLoc::to_string_full(bool print_funcs, const std::string& func_sep) const {
    return _loc->to_string_full(print_funcs, func_sep);
}

std::string SrcLoc::to_string_last(bool print_funcs, const std::string& func_sep) const {
    return _loc->to_string_last(print_funcs, func_sep);
}

#else

SrcLoc::SrcLoc(){};
SrcLoc::SrcLoc(const SrcLoc& other){};
SrcLoc::SrcLoc(SrcLoc&& other){};
SrcLoc::SrcLoc(const SrcLoc&& other){};

SrcLoc& SrcLoc::add(){return *this;}
const SrcLoc& SrcLoc::add() const {return *this;}

const std::string& SrcLoc::file_name() const {
    return "GLWPP_DEBUG is not defined";
}

uint_least32_t SrcLoc::line() const {
    return 0;
}

const std::string& SrcLoc::function_name() const {
    return "GLWPP_DEBUG is not defined";
}

std::string SrcLoc::to_string() const {
    return "GLWPP_DEBUG is not defined";
}

#endif // GLWPP_DEBUG