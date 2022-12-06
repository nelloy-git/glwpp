#include "utils/SrcLoc.hpp"

using namespace glwpp;

#ifdef GLWPP_DEBUG

struct SrcLoc::Loc {
    char const* file;
    std::uint_least32_t line;
    char const* function;
    std::shared_ptr<Loc> prev;

    inline std::string to_string() const {
        auto str = std::string(file) + ":" + std::to_string(line); // + "\t" + std::string(function);
        if (prev){
            str += "\n" + prev->to_string();
        }
        return str;
    }
};

SrcLoc::SrcLoc(char const* file, 
               std::uint_least32_t line,
               char const* function){
    _loc = std::make_shared<Loc>();
    _loc->file = file;
    _loc->line = line;
    _loc->function = function;
    _loc->prev = nullptr;
};

SrcLoc::SrcLoc(const SrcLoc& other,
               char const* file, 
               std::uint_least32_t line,
               char const* function){
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


SrcLoc& SrcLoc::add(char const* file, 
                    std::uint_least32_t line,
                    char const* function){
    auto loc = std::make_shared<Loc>();
    loc->prev = _loc;
    _loc = loc;
    _loc->file = file;
    _loc->line = line;
    _loc->function = function;
    return *this;
}

const SrcLoc& SrcLoc::add(char const* file, 
                          std::uint_least32_t line,
                          char const* function) const {
    auto prev = std::make_shared<Loc>();
    *prev = *_loc;
    _loc->file = file;
    _loc->line = line;
    _loc->function = function;
    _loc->prev = prev;
    return *this;
}

char const* SrcLoc::file_name() const {
    return _loc->file;
}

uint_least32_t SrcLoc::line() const {
    return _loc->line;
}

char const* SrcLoc::function_name() const {
    return _loc->function;
}

std::string SrcLoc::to_string() const {
    return _loc->to_string();
}

#else

SrcLoc::SrcLoc(){};
SrcLoc::SrcLoc(const SrcLoc& other){};
SrcLoc::SrcLoc(SrcLoc&& other){};
SrcLoc::SrcLoc(const SrcLoc&& other){};

SrcLoc& SrcLoc::add(){return *this;}
const SrcLoc& SrcLoc::add() const {return *this;}

char const* SrcLoc::file_name() const {
    return "GLWPP_DEBUG is not defined";
}

uint_least32_t SrcLoc::line() const {
    return 0;
}

char const* SrcLoc::function_name() const {
    return "GLWPP_DEBUG is not defined";
}

std::string SrcLoc::to_string() const {
    return "GLWPP_DEBUG is not defined";
}

#endif // GLWPP_DEBUG