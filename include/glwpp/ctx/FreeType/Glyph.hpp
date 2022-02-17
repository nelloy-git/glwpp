#pragma once

namespace glwpp {

struct Glyph {
    Glyph(){};

    // Position in texture
    int x;
    int y;
    // Size in pixels
    int width;
    int height;

    int bearing_x;
    int bearing_y;
    int advance_x;
    int advance_y;
};
    
} // namespace glwpp
