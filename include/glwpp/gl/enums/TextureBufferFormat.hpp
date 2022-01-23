#pragma once

#include "glwpp/gl/api/types.hpp"

namespace glwpp::gl {

enum class TextureFormat : Enum {
                         // Format      Base Type 	Components 	Norm 	0 	1 	2 	3
    R8 = 0x8229,         // GL_R8 	    ubyte 	    1 	        YES 	R 	0 	0 	1
    R16 = 0x822A,        // GL_R16 	    ushort 	    1 	        YES 	R 	0 	0 	1
    R16F = 0x822D,       // GL_R16F 	half 	    1 	        NO 	    R 	0 	0 	1
    R32F = 0x822E,       // GL_R32F 	float 	    1 	        NO 	    R 	0 	0 	1
    R8I = 0x8231,        // GL_R8I 	    byte 	    1 	        NO 	    R 	0 	0 	1
    R16I = 0x8233,       // GL_R16I 	short 	    1 	        NO 	    R 	0 	0 	1
    R32I = 0x8235,       // GL_R32I 	int 	    1 	        NO 	    R 	0 	0 	1
    R8UI = 0x8232,       // GL_R8UI 	ubyte 	    1 	        NO 	    R 	0 	0 	1
    R16UI = 0x8234,      // GL_R16UI 	ushort 	    1 	        NO 	    R 	0 	0 	1
    R32UI = 0x8236,      // GL_R32UI 	uint 	    1 	        NO 	    R 	0 	0 	1
    RG8 = 0x822B,        // GL_RG8 	    ubyte 	    2 	        YES 	R 	G 	0 	1
    RG16 = 0x822C,       // GL_RG16 	ushort 	    2 	        YES 	R 	G 	0 	1
    RG16F = 0x822F,      // GL_RG16F 	half 	    2 	        NO      R 	G 	0 	1
    RG32F = 0x8230,      // GL_RG32F 	float 	    2 	        NO      R 	G 	0 	1
    RG8I = 0x8237,       // GL_RG8I 	byte 	    2 	        NO      R 	G 	0 	1
    RG16I = 0x8239,      // GL_RG16I 	short 	    2 	        NO      R 	G 	0 	1
    RG32I = 0x823B,      // GL_RG32I 	int 	    2 	        NO      R 	G 	0 	1
    RG8UI = 0x8238,      // GL_RG8UI 	ubyte 	    2 	        NO      R 	G 	0 	1
    RG16UI = 0x823A,     // GL_RG16UI 	ushort 	    2 	        NO      R 	G 	0 	1
    RG32UI = 0x823C,     // GL_RG32UI 	uint 	    2 	        NO      R 	G 	0 	1
    RGB32F = 0x8815,     // GL_RGB32F 	float 	    3 	        NO      R 	G 	B 	1
    RGB32I = 0x8D83,     // GL_RGB32I 	int 	    3 	        NO      R 	G 	B 	1
    RGB32UI = 0x8D71,    // GL_RGB32UI 	uint 	    3 	        NO      R 	G 	B 	1
    RGBA8 = 0x8058,      // GL_RGBA8 	uint 	    4 	        YES 	R 	G 	B 	A
    RGBA16 = 0x805B,     // GL_RGBA16 	short 	    4 	        YES 	R 	G 	B 	A
    RGBA16F = 0x881A,    // GL_RGBA16F 	half 	    4 	        NO 	    R 	G 	B 	A
    RGBA32F = 0x8814,    // GL_RGBA32F 	float 	    4 	        NO 	    R 	G 	B 	A
    RGBA8I = 0x8D8E,     // GL_RGBA8I 	byte 	    4 	        NO 	    R 	G 	B 	A
    RGBA16I = 0x8D88,    // GL_RGBA16I 	short 	    4 	        NO 	    R 	G 	B 	A
    RGBA32I = 0x8D82,    // GL_RGBA32I 	int 	    4 	        NO 	    R 	G 	B 	A
    RGBA8UI = 0x8D7C,    // GL_RGBA8UI 	ubyte 	    4 	        NO 	    R 	G 	B 	A
    RGBA16UI = 0x8D76,   // GL_RGBA16UI ushort 	    4 	        NO 	    R 	G 	B 	A
    RGBA32UI = 0x8D70,   // GL_RGBA32UI uint 	    4 	        NO 	    R 	G 	B 	A
};

}