#pragma once

#include <memory>
#include <string>

#include "utils/Export.hpp"

namespace glwpp  {

#ifdef GLWPP_DEBUG

class SrcLoc {
    struct Loc;
public:
    EXPORT SrcLoc(const std::string& file = __builtin_FILE(), 
                  std::uint_least32_t line = __builtin_LINE(),
                  const std::string&  function = __builtin_FUNCTION());

    EXPORT SrcLoc(const SrcLoc& other,
                  const std::string&  file = __builtin_FILE(), 
                  std::uint_least32_t line = __builtin_LINE(),
                  const std::string&  function = __builtin_FUNCTION());

    EXPORT SrcLoc(SrcLoc&& other);
    EXPORT SrcLoc(const SrcLoc&& other);

    EXPORT SrcLoc& add(const std::string& file = __builtin_FILE(), 
                       std::uint_least32_t line = __builtin_LINE(),
                       const std::string& function = __builtin_FUNCTION());

    EXPORT const SrcLoc& add(const std::string& file = __builtin_FILE(), 
                             std::uint_least32_t line = __builtin_LINE(),
                             const std::string& function = __builtin_FUNCTION()) const;

    EXPORT SrcLoc& operator=(const SrcLoc& other){
        _loc = other._loc;
        return *this;
    }

    EXPORT SrcLoc& operator=(const SrcLoc&& other){
        _loc = other._loc;
        return *this;
    }

    EXPORT const std::string& file_name() const;
    EXPORT std::uint_least32_t line() const;
    EXPORT const std::string& function_name() const;
    EXPORT std::string to_string_full(bool print_funcs = true, const std::string& func_sep = "\t") const;
    EXPORT std::string to_string_last(bool print_funcs = true, const std::string& func_sep = "\t") const;

private:
    std::shared_ptr<Loc> _loc;
};

#else

class SrcLoc {
public:
    EXPORT SrcLoc();
    EXPORT SrcLoc(const SrcLoc& other);
    EXPORT SrcLoc(SrcLoc&& other);
    EXPORT SrcLoc(const SrcLoc&& other);

    EXPORT SrcLoc& add();
    EXPORT const SrcLoc& add() const;

    EXPORT SrcLoc& operator=(const SrcLoc& other){
        return *this;
    }

    EXPORT SrcLoc& operator=(const SrcLoc&& other){
        return *this;
    }

    EXPORT char const* file_name() const;
    EXPORT std::uint_least32_t line() const;
    EXPORT char const* function_name() const;
    EXPORT std::string to_string() const;
};

#endif


} // namespace glwpp