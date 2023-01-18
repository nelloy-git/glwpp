#pragma once

#include <stdexcept>

namespace glwpp {

enum class MeshAttributeType {
    Position,
    Normal,
    Tangent,
    Bitangent,
    Texture_0,
    Texture_1,
    Texture_2,
    Texture_3,
    Texture_4,
    Texture_5,
    Texture_6,
    Texture_7,
    Color_0,
    Color_1,
    Color_2,
    Color_3,
    Color_4,
    Color_5,
    Color_6,
    Color_7,
};

template<typename T>
class MeshAttributeContainer {
public:
    template<typename T1, typename T2>
    constexpr void iterate(auto&& func, const MeshAttributeContainer<T2>& other) const {
        func(MeshAttributeType::Position, get(MeshAttributeType::Position), other.get(MeshAttributeType::Position));
        func(MeshAttributeType::Normal, get(MeshAttributeType::Normal), other.get(MeshAttributeType::Normal));
        func(MeshAttributeType::Tangent, get(MeshAttributeType::Tangent), other.get(MeshAttributeType::Tangent));
        func(MeshAttributeType::Bitangent, get(MeshAttributeType::Bitangent), other.get(MeshAttributeType::Bitangent));
        func(MeshAttributeType::Texture_0, get(MeshAttributeType::Texture_0), other.get(MeshAttributeType::Texture_0));
        func(MeshAttributeType::Texture_1, get(MeshAttributeType::Texture_1), other.get(MeshAttributeType::Texture_1));
        func(MeshAttributeType::Texture_2, get(MeshAttributeType::Texture_2), other.get(MeshAttributeType::Texture_2));
        func(MeshAttributeType::Texture_3, get(MeshAttributeType::Texture_3), other.get(MeshAttributeType::Texture_3));
        func(MeshAttributeType::Texture_4, get(MeshAttributeType::Texture_4), other.get(MeshAttributeType::Texture_4));
        func(MeshAttributeType::Texture_5, get(MeshAttributeType::Texture_5), other.get(MeshAttributeType::Texture_5));
        func(MeshAttributeType::Texture_6, get(MeshAttributeType::Texture_6), other.get(MeshAttributeType::Texture_6));
        func(MeshAttributeType::Texture_7, get(MeshAttributeType::Texture_7), other.get(MeshAttributeType::Texture_7));
        func(MeshAttributeType::Color_0, get(MeshAttributeType::Color_0), other.get(MeshAttributeType::Color_0));
        func(MeshAttributeType::Color_1, get(MeshAttributeType::Color_1), other.get(MeshAttributeType::Color_1));
        func(MeshAttributeType::Color_2, get(MeshAttributeType::Color_2), other.get(MeshAttributeType::Color_2));
        func(MeshAttributeType::Color_3, get(MeshAttributeType::Color_3), other.get(MeshAttributeType::Color_3));
        func(MeshAttributeType::Color_4, get(MeshAttributeType::Color_4), other.get(MeshAttributeType::Color_4));
        func(MeshAttributeType::Color_5, get(MeshAttributeType::Color_5), other.get(MeshAttributeType::Color_5));
        func(MeshAttributeType::Color_6, get(MeshAttributeType::Color_6), other.get(MeshAttributeType::Color_6));
        func(MeshAttributeType::Color_7, get(MeshAttributeType::Color_7), other.get(MeshAttributeType::Color_7));
    }

    constexpr MeshAttributeContainer(){};
    constexpr MeshAttributeContainer(const T& Position,
                                     const T& Normal,
                                     const T& Tangent,
                                     const T& Bitangent,
                                     const T& Texture_0,
                                     const T& Texture_1,
                                     const T& Texture_2,
                                     const T& Texture_3,
                                     const T& Texture_4,
                                     const T& Texture_5,
                                     const T& Texture_6,
                                     const T& Texture_7,
                                     const T& Color_0,
                                     const T& Color_1,
                                     const T& Color_2,
                                     const T& Color_3,
                                     const T& Color_4,
                                     const T& Color_5,
                                     const T& Color_6,
                                     const T& Color_7) :
        _Position(Position),
        _Normal(Normal),
        _Tangent(Tangent),
        _Bitangent(Bitangent),
        _Texture_0(Texture_0),
        _Texture_1(Texture_1),
        _Texture_2(Texture_2),
        _Texture_3(Texture_3),
        _Texture_4(Texture_4),
        _Texture_5(Texture_5),
        _Texture_6(Texture_6),
        _Texture_7(Texture_7),
        _Color_0(Color_0),
        _Color_1(Color_1),
        _Color_2(Color_2),
        _Color_3(Color_3),
        _Color_4(Color_4),
        _Color_5(Color_5),
        _Color_6(Color_6),
        _Color_7(Color_7){
    }

    constexpr unsigned int size() const {
        return sizeof(MeshAttributeContainer<T>) / sizeof(T);
    }

    constexpr unsigned int textures() const {
        return 8;
    }

    constexpr unsigned int colors() const {
        return 8;
    }

    constexpr const T& operator[](const MeshAttributeType& type) const {
        return get(type);
    }

    T& operator[](const MeshAttributeType& type){
        return get(type);
    }

    constexpr const T& get(const MeshAttributeType& type) const {
        switch (type){
        case MeshAttributeType::Position: return _Position;
        case MeshAttributeType::Normal: return _Normal;
        case MeshAttributeType::Tangent: return _Tangent;
        case MeshAttributeType::Bitangent: return _Bitangent;
        case MeshAttributeType::Texture_0: return _Texture_0;
        case MeshAttributeType::Texture_1: return _Texture_1;
        case MeshAttributeType::Texture_2: return _Texture_2;
        case MeshAttributeType::Texture_3: return _Texture_3;
        case MeshAttributeType::Texture_4: return _Texture_4;
        case MeshAttributeType::Texture_5: return _Texture_5;
        case MeshAttributeType::Texture_6: return _Texture_6;
        case MeshAttributeType::Texture_7: return _Texture_7;
        case MeshAttributeType::Color_0: return _Color_0;
        case MeshAttributeType::Color_1: return _Color_1;
        case MeshAttributeType::Color_2: return _Color_2;
        case MeshAttributeType::Color_3: return _Color_3;
        case MeshAttributeType::Color_4: return _Color_4;
        case MeshAttributeType::Color_5: return _Color_5;
        case MeshAttributeType::Color_6: return _Color_6;
        case MeshAttributeType::Color_7: return _Color_7;
        default: throw std::logic_error("Unknown MeshAttributeType");
        }
    }

    T& get(const MeshAttributeType& type){
        switch (type){
        case MeshAttributeType::Position: return _Position;
        case MeshAttributeType::Normal: return _Normal;
        case MeshAttributeType::Tangent: return _Tangent;
        case MeshAttributeType::Bitangent: return _Bitangent;
        case MeshAttributeType::Texture_0: return _Texture_0;
        case MeshAttributeType::Texture_1: return _Texture_1;
        case MeshAttributeType::Texture_2: return _Texture_2;
        case MeshAttributeType::Texture_3: return _Texture_3;
        case MeshAttributeType::Texture_4: return _Texture_4;
        case MeshAttributeType::Texture_5: return _Texture_5;
        case MeshAttributeType::Texture_6: return _Texture_6;
        case MeshAttributeType::Texture_7: return _Texture_7;
        case MeshAttributeType::Color_0: return _Color_0;
        case MeshAttributeType::Color_1: return _Color_1;
        case MeshAttributeType::Color_2: return _Color_2;
        case MeshAttributeType::Color_3: return _Color_3;
        case MeshAttributeType::Color_4: return _Color_4;
        case MeshAttributeType::Color_5: return _Color_5;
        case MeshAttributeType::Color_6: return _Color_6;
        case MeshAttributeType::Color_7: return _Color_7;
        default: throw std::logic_error("Unknown MeshAttributeType");
        }
    }

    constexpr const T& texture(unsigned int i) const {
        switch (i){
        case 0: return _Texture_0;
        case 1: return _Texture_1;
        case 2: return _Texture_2;
        case 3: return _Texture_3;
        case 4: return _Texture_4;
        case 5: return _Texture_5;
        case 6: return _Texture_6;
        case 7: return _Texture_7;
        default: throw std::logic_error("Unknown texture N");
        }
    }

    constexpr const T& color(unsigned int i) const {
        switch (i){
        case 0: return _Color_0;
        case 1: return _Color_1;
        case 2: return _Color_2;
        case 3: return _Color_3;
        case 4: return _Color_4;
        case 5: return _Color_5;
        case 6: return _Color_6;
        case 7: return _Color_7;
        default: throw std::logic_error("Unknown color N");
        }
    }

    void set(const MeshAttributeType& type, const T& val){
        switch (type){
        case MeshAttributeType::Position: _Position = val; break;
        case MeshAttributeType::Normal: _Normal = val; break;
        case MeshAttributeType::Tangent: _Tangent = val; break;
        case MeshAttributeType::Bitangent: _Bitangent = val; break;
        case MeshAttributeType::Texture_0: _Texture_0 = val; break;
        case MeshAttributeType::Texture_1: _Texture_1 = val; break;
        case MeshAttributeType::Texture_2: _Texture_2 = val; break;
        case MeshAttributeType::Texture_3: _Texture_3 = val; break;
        case MeshAttributeType::Texture_4: _Texture_4 = val; break;
        case MeshAttributeType::Texture_5: _Texture_5 = val; break;
        case MeshAttributeType::Texture_6: _Texture_6 = val; break;
        case MeshAttributeType::Texture_7: _Texture_7 = val; break;
        case MeshAttributeType::Color_0: _Color_0 = val; break;
        case MeshAttributeType::Color_1: _Color_1 = val; break;
        case MeshAttributeType::Color_2: _Color_2 = val; break;
        case MeshAttributeType::Color_3: _Color_3 = val; break;
        case MeshAttributeType::Color_4: _Color_4 = val; break;
        case MeshAttributeType::Color_5: _Color_5 = val; break;
        case MeshAttributeType::Color_6: _Color_6 = val; break;
        case MeshAttributeType::Color_7: _Color_7 = val; break;
        default: throw std::logic_error("Unknown MeshAttributeType");
        }
    }

    void set(const MeshAttributeType& type, T&& val){
        switch (type){
        case MeshAttributeType::Position: _Position = std::move(val); break;
        case MeshAttributeType::Normal: _Normal = std::move(val); break;
        case MeshAttributeType::Tangent: _Tangent = std::move(val); break;
        case MeshAttributeType::Bitangent: _Bitangent = std::move(val); break;
        case MeshAttributeType::Texture_0: _Texture_0 = std::move(val); break;
        case MeshAttributeType::Texture_1: _Texture_1 = std::move(val); break;
        case MeshAttributeType::Texture_2: _Texture_2 = std::move(val); break;
        case MeshAttributeType::Texture_3: _Texture_3 = std::move(val); break;
        case MeshAttributeType::Texture_4: _Texture_4 = std::move(val); break;
        case MeshAttributeType::Texture_5: _Texture_5 = std::move(val); break;
        case MeshAttributeType::Texture_6: _Texture_6 = std::move(val); break;
        case MeshAttributeType::Texture_7: _Texture_7 = std::move(val); break;
        case MeshAttributeType::Color_0: _Color_0 = std::move(val); break;
        case MeshAttributeType::Color_1: _Color_1 = std::move(val); break;
        case MeshAttributeType::Color_2: _Color_2 = std::move(val); break;
        case MeshAttributeType::Color_3: _Color_3 = std::move(val); break;
        case MeshAttributeType::Color_4: _Color_4 = std::move(val); break;
        case MeshAttributeType::Color_5: _Color_5 = std::move(val); break;
        case MeshAttributeType::Color_6: _Color_6 = std::move(val); break;
        case MeshAttributeType::Color_7: _Color_7 = std::move(val); break;
        default: throw std::logic_error("Unknown MeshAttributeType");
        }
    }

    void setTexture(unsigned int i, const T& val){
        switch (i){
        case 0: _Texture_0 = val; break;
        case 1: _Texture_1 = val; break;
        case 2: _Texture_2 = val; break;
        case 3: _Texture_3 = val; break;
        case 4: _Texture_4 = val; break;
        case 5: _Texture_5 = val; break;
        case 6: _Texture_6 = val; break;
        case 7: _Texture_7 = val; break;
        default: throw std::logic_error("Unknown texture N");
        }
    }

    void setTexture(unsigned int i, T&& val){
        switch (i){
        case 0: _Texture_0 = std::move(val); break;
        case 1: _Texture_1 = std::move(val); break;
        case 2: _Texture_2 = std::move(val); break;
        case 3: _Texture_3 = std::move(val); break;
        case 4: _Texture_4 = std::move(val); break;
        case 5: _Texture_5 = std::move(val); break;
        case 6: _Texture_6 = std::move(val); break;
        case 7: _Texture_7 = std::move(val); break;
        default: throw std::logic_error("Unknown texture N");
        }
    }

    void setColor(unsigned int i, const T& val){
        switch (i){
        case 0: _Color_0 = val; break;
        case 1: _Color_1 = val; break;
        case 2: _Color_2 = val; break;
        case 3: _Color_3 = val; break;
        case 4: _Color_4 = val; break;
        case 5: _Color_5 = val; break;
        case 6: _Color_6 = val; break;
        case 7: _Color_7 = val; break;
        default: throw std::logic_error("Unknown color N");
        }
    }

    void setColor(unsigned int i, T&& val){
        switch (i){
        case 0: _Color_0 = std::move(val); break;
        case 1: _Color_1 = std::move(val); break;
        case 2: _Color_2 = std::move(val); break;
        case 3: _Color_3 = std::move(val); break;
        case 4: _Color_4 = std::move(val); break;
        case 5: _Color_5 = std::move(val); break;
        case 6: _Color_6 = std::move(val); break;
        case 7: _Color_7 = std::move(val); break;
        default: throw std::logic_error("Unknown color N");
        }
    }

private:
    T _Position;
    T _Normal;
    T _Tangent;
    T _Bitangent;
    T _Texture_0;
    T _Texture_1;
    T _Texture_2;
    T _Texture_3;
    T _Texture_4;
    T _Texture_5;
    T _Texture_6;
    T _Texture_7;
    T _Color_0;
    T _Color_1;
    T _Color_2;
    T _Color_3;
    T _Color_4;
    T _Color_5;
    T _Color_6;
    T _Color_7;

};
    
} // namespace glwpp