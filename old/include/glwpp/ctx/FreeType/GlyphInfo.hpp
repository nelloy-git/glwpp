#pragma once

namespace glwpp {

struct GlyphInfo {
    GlyphInfo(){};

    float tex_x1;
    float tex_y1;
    float tex_x2;
    float tex_y2;

    // Position in texture (pixels)
    int x;
    int y;
    // Size in texture (pixels)
    int width;
    int height;

    int bearing_x;
    int bearing_y;
    int advance_x;
    int advance_y;
};
    
} // namespace glwpp
