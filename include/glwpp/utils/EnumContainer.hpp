#pragma once

#include "magic_enum.hpp"

namespace glwpp {

template<typename E, typename T>
class EnumContainer {
    static constexpr size_t S = magic_enum::enum_count<E>();

public:
    EnumContainer(){};
    virtual ~EnumContainer(){};

    static constexpr auto enum_values(){
        return magic_enum::enum_values<E>();
    }

    static constexpr auto enum_index(const E& enum_value){
        return magic_enum::enum_index(enum_value).value();
    }

    inline T& operator[](const E& target){
        return _data[magic_enum::enum_index(target).value()];
    }

    inline const T& operator[](const E& target) const {
        return _data[magic_enum::enum_index(target).value()];
    }

private:
    T _data[S];

    static constexpr bool _is_sequence(){
        size_t size = magic_enum::enum_count<E>();
        auto list = magic_enum::enum_values<E>();

        using Under = std::underlying_type_t<E>;
        Under min = std::numeric_limits<Under>::infinity();
        Under max = -std::numeric_limits<Under>::infinity();

        for (size_t i = 0; i < list.size(); ++i){
            int val = static_cast<Under>(list[i]);
            max = max > val ? max : val;
            min = min < val ? min : val;

            for (size_t j = i + 1; j < list.size(); ++j){
                int val_j = static_cast<int>(list[j]);
                if (val == val_j){
                    return false;
                }
            }
        }
        return (max - min) == size - 1 && min == 0;
    }
    static_assert(_is_sequence(), "E is not sequence enum");
};

} // namespace glwpp