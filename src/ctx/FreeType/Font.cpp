#include "glwpp/ctx/FreeType/Font.hpp"

#include <execution>
#include <stdexcept>

#include "ft2build.h"
#include FT_FREETYPE_H

using namespace glwpp;

namespace {

static FT_Library* CreateFtLib(){
    auto ft_lib = new FT_Library;
    if (FT_Init_FreeType(ft_lib))
        throw std::runtime_error("Can not init FreeType library.");
    return ft_lib;
}

static void DeleteFtLib(FT_Library* ft_lib){
    FT_Done_FreeType(*ft_lib);
    delete ft_lib;
}

static uptr<FT_Library, void(*)(FT_Library*)> ft_lib(CreateFtLib(), &DeleteFtLib);

FT_Face NewFtFace(const std::string& path){
    FT_Face face;
    if (FT_New_Face(*ft_lib, path.c_str(), 0, &face))
        throw std::runtime_error("Can not create FreeType face.");
    return face;
}

void DelFtFace(FT_Face face){
    FT_Done_Face(face);
}

};

Font::Font(wptr<Context> ctx, const std::string &path, const unsigned int &size) :
    path(path),
    size(size),
    _ctx(ctx),
    _tex(new Texture(ctx, gl::TextureType::Storage2D)),
    _ft_face(NewFtFace(path), DelFtFace){
    _initTexture();
    _loadTexture();
}

Font::~Font(){
}

sptr<const Texture> Font::getTex() const {
    return _tex;
}

int Font::getTexWidth() const {
    return _tex_w;
}

int Font::getTexHeight() const {
    return _tex_h;
}


sptr<const GlyphInfo> Font::getGlyphInfo(const size_t& code) const {
    auto iter = _glyphs.find(code);
    if (iter == _glyphs.end()){
        return nullptr;
    }
    return iter->second;
}

void Font::_initTexture(){
    FT_Set_Pixel_Sizes(_ft_face.get(), 0, size);

    //Count
    FT_UInt index;
    FT_ULong char_code = FT_Get_First_Char(_ft_face.get(), &index);

    // TODO optimize
    unsigned int x = 0;
    unsigned int y = 0;
    unsigned int sum_width = 0;
    unsigned int max_height = 0;

    while (index != 0) {
        if (FT_Load_Char(_ft_face.get(), char_code, FT_LOAD_RENDER))
            throw std::runtime_error("Can not load FreeType char.");

        auto glyph = make_sptr<GlyphInfo>();
        glyph->x = static_cast<int>(x);
        glyph->y = static_cast<int>(y);
        glyph->width = static_cast<int>(_ft_face->glyph->bitmap.width);
        glyph->height = static_cast<int>(_ft_face->glyph->bitmap.rows);
        glyph->bearing_x = _ft_face->glyph->bitmap_left;
        glyph->bearing_y = _ft_face->glyph->bitmap_top;
        glyph->advance_x = _ft_face->glyph->advance.x;
        glyph->advance_y = _ft_face->glyph->advance.y;
        _glyphs[char_code] = glyph;

        x += _ft_face->glyph->bitmap.width;
        max_height = std::max(max_height, _ft_face->glyph->bitmap.rows);
        sum_width += _ft_face->glyph->bitmap.width;

        char_code = FT_Get_Next_Char(_ft_face.get(), char_code, &index);
    }

    _tex_w = sum_width % 4 == 0 ? sum_width : sum_width + (4 - sum_width % 4);
    _tex_h = max_height % 4 == 0 ? max_height : max_height + (4 - max_height % 4);

    _tex->storage2D(1, gl::TextureFormat::R8, _tex_w, _tex_h);
    _tex->setWrapS(Texture::Wrap::Clamp);
    _tex->setWrapT(Texture::Wrap::Clamp);
    _tex->setMinFilter(Texture::MinFilter::Linear);
    _tex->setMagFilter(Texture::MagFilter::Linear);
    _tex->generateMipMap();
}

void Font::_loadTexture(){
    FT_Render_Mode(FT_RENDER_MODE_SDF);

    for (auto& p : _glyphs){
        if (FT_Load_Char(_ft_face.get(), p.first, FT_LOAD_RENDER))
            throw std::runtime_error("Can not load FreeType char.");

        auto &glyph = p.second;
        glyph->tex_x1 = (float)glyph->x / _tex_w;
        glyph->tex_y1 = (float)glyph->y / _tex_h;
        glyph->tex_x2 = (float)(glyph->x + glyph->width) / _tex_w;
        glyph->tex_y2 = (float)(glyph->y + glyph->height) / _tex_h;

        auto buffer = _ft_face->glyph->bitmap.buffer;
        auto bitmap = createTmpData(nullptr, glyph->width * glyph->height);

        // Mirror Y to opengl coords
        for (auto i = 0; i < glyph->height; ++i){
            auto p_src = buffer + (glyph->height - 1 - i) * glyph->width;
            auto p_dst = (char*)bitmap.get() + i * glyph->width;
            memcpy(p_dst, p_src, glyph->width);
        }

        _tex->setSubImage2D(0, glyph->x, glyph->y, glyph->width, glyph->height,
                            gl::TexturePixelFormat::RED, gl::TexturePixelData::UByte, bitmap);
    }
}