#pragma once

#include <unordered_map>
#include <string>

#include "glwpp/ctx/FreeType/GlyphInfo.hpp"
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
    
    sptr<const GlyphInfo> getGlyphInfo(const size_t& code) const;

private:
    wptr<Context> _ctx;

    sptr<Texture> _tex;
    int _tex_w;
    int _tex_h;

    std::mutex _lock_map;
    uptr<FT_FaceRec_, void(*)(FT_FaceRec_*)> _ft_face;
    std::unordered_map<size_t, sptr<GlyphInfo>> _glyphs;

    void _initTexture();
    void _loadTexture();

    // std::unordered_map<
};
    
} // namespace glwpp
