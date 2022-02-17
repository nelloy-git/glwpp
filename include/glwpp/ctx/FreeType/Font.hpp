#pragma once

#include <unordered_map>
#include <string>

#include "glwpp/ctx/FreeType/Glyph.hpp"
#include "glwpp/gl/oop/Texture.hpp"
#include "glwpp/utils/Ptr.hpp"

struct FT_FaceRec_;

namespace glwpp {

class Font {
public:
    Font(wptr<Context> ctx, const std::string &path, const unsigned int &size);
    virtual ~Font();

    const std::string path;
    const unsigned int size;

    sptr<const Texture> getTex() const;
    int getTexWidth() const;
    int getTexHeight() const;
    
    sptr<const Glyph> getGlyph(const size_t& code) const;

    // sptr<Glyph> loadChar(size_t char_code);
    
    //Count
    // FT_UInt index;
    // FT_ULong character = FT_Get_First_Char(face, &index);

    // while (true) {
    // // to do something

    // character = FT_Get_Next_Char(face, character, &index);
    // if (!index) break; // if FT_Get_Next_Char write 0 to index then
    //                     // have no more characters in font face
    // }

private:
    wptr<Context> _ctx;

    sptr<Texture> _tex;
    int _tex_w;
    int _tex_h;

    std::mutex _lock_map;
    uptr<FT_FaceRec_, void(*)(FT_FaceRec_*)> _ft_face;
    std::unordered_map<size_t, sptr<Glyph>> _glyphs;

    void _initTexture();
    void _loadTexture();

    // std::unordered_map<
};
    
} // namespace glwpp
