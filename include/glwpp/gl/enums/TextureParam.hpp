#pragma once

#include "glwpp/gl/api/types.hpp"

namespace glwpp::gl {

enum class TextureParam : Enum {
    DepthStencilMode = 0x90EA, // GL_DEPTH_STENCIL_TEXTURE_MODE Returns the single-value depth stencil texture mode, a symbolic constant. The initial value is GL_DEPTH_COMPONENT.
    MagFilter = 0x2800, // GL_TEXTURE_MAG_FILTER Returns the single-valued texture magnification filter, a symbolic constant. The initial value is GL_LINEAR.
    MinFilter = 0x2801, // GL_TEXTURE_MIN_FILTER Returns the single-valued texture minification filter, a symbolic constant. The initial value is GL_NEAREST_MIPMAP_LINEAR.
    MinLOD = 0x813A, // GL_TEXTURE_MIN_LOD Returns the single-valued texture minimum level-of-detail value. The initial value is -1000 .
    MaxLOD = 0x813B, // GL_TEXTURE_MAX_LOD Returns the single-valued texture maximum level-of-detail value. The initial value is 1000.
    BaseLevel = 0x813C, // GL_TEXTURE_BASE_LEVEL Returns the single-valued base texture mipmap level. The initial value is 0.
    MaxLevel = 0x813D, // GL_TEXTURE_MAX_LEVEL Returns the single-valued maximum texture mipmap array level. The initial value is 1000.
    SwizzleR = 0x8E42, // GL_TEXTURE_SWIZZLE_R Returns the red component swizzle. The initial value is GL_RED.
    SwizzleG = 0x8E43, // GL_TEXTURE_SWIZZLE_G Returns the green component swizzle. The initial value is GL_GREEN.
    SwizzleB = 0x8E44, // GL_TEXTURE_SWIZZLE_B Returns the blue component swizzle. The initial value is GL_BLUE.
    SwizzleA = 0x8E45, // GL_TEXTURE_SWIZZLE_A Returns the alpha component swizzle. The initial value is GL_ALPHA.
    SwizzleRGBA = 0x8E46, // GL_TEXTURE_SWIZZLE_RGBA Returns the component swizzle for all channels in a single query.
    WrapS = 0x2802, // GL_TEXTURE_WRAP_S Returns the single-valued wrapping function for texture coordinate s, a symbolic constant. The initial value is GL_REPEAT.
    WrapT = 0x2803, // GL_TEXTURE_WRAP_T Returns the single-valued wrapping function for texture coordinate t, a symbolic constant. The initial value is GL_REPEAT.
    WrapR = 0x8072, // GL_TEXTURE_WRAP_R Returns the single-valued wrapping function for texture coordinate r, a symbolic constant. The initial value is GL_REPEAT.
    // Vectors are not supprted BorderColor = 0x1004, // GL_TEXTURE_BORDER_COLOR Returns four integer or floating-point numbers that comprise the RGBA color of the texture border. Floating-point values are returned in the range 0 1 . Integer values are returned as a linear mapping of the internal floating-point representation such that 1.0 maps to the most positive representable integer and -1.0 maps to the most negative representable integer. The initial value is (0, 0, 0, 0).
    CompareMode = 0x884C, // GL_TEXTURE_COMPARE_MODE Returns a single-valued texture comparison mode, a symbolic constant. The initial value is GL_NONE. See glTexParameter.
    CompareFunc = 0x884D, // GL_TEXTURE_COMPARE_FUNC Returns a single-valued texture comparison function, a symbolic constant. The initial value is GL_LEQUAL. See glTexParameter.
    MinLevel = 0x82DB, // GL_TEXTURE_VIEW_MIN_LEVEL Returns a single-valued base level of a texture view relative to its parent. The initial value is 0. See glTextureView.
    ViewNumLevels = 0x82DC, // GL_TEXTURE_VIEW_NUM_LEVELS Returns a single-valued number of levels of detail of a texture view. See glTextureView.
    ViewMinLayer = 0x82DD, // GL_TEXTURE_VIEW_MIN_LAYER Returns a single-valued first level of a texture array view relative to its parent. See glTextureView.
    ViewNumLayers = 0x82DE, // GL_TEXTURE_VIEW_NUM_LAYERS Returns a single-valued number of layers in a texture array view. See glTextureView.
    ImmutableLevels =0x82DF , // GL_TEXTURE_IMMUTABLE_LEVELS Returns a single-valued number of immutable texture levels in a texture view. See glTextureView.

    // In addition to the parameters that may be set with glTexParameter, glGetTexParameter and glGetTextureParameter accept the following read-only parameters:

    ImageFormatCompatibilityType = 0x90C7, // GL_IMAGE_FORMAT_COMPATIBILITY_TYPE Returns the matching criteria use for the texture when used as an image texture. Can return GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE, GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS or GL_NONE.
    ImmutableFormat = 0x912F, // GL_TEXTURE_IMMUTABLE_FORMAT Returns non-zero if the texture has an immutable format. Textures become immutable if their storage is specified with glTexStorage1D, glTexStorage2D or glTexStorage3D. The initial value is GL_FALSE.
    Target = 0x1006, // GL_TEXTURE_TARGET Returns the effective target of the texture object. For glGetTex*Parameter functions, this is the target parameter. For glGetTextureParameter*, it is the target to which the texture was initially bound when it was created, or the value of the target parameter to the call to glCreateTextures which created the texture.
};

enum class TextureLevelParam : Enum {
    Width = 0x1000,                 // GL_TEXTURE_WIDTH params returns a single value, the width of the texture image. The initial value is 0.
    Height = 0x1001,                // GL_TEXTURE_HEIGHT params returns a single value, the height of the texture image. The initial value is 0.
    Depth = 0x8071,                 // GL_TEXTURE_DEPTH params returns a single value, the depth of the texture image. The initial value is 0.
    InternalFormat = 0x1003,        // GL_TEXTURE_INTERNAL_FORMAT params returns a single value, the internal format of the texture image.
    RedType = 0x8C10,               // GL_TEXTURE_RED_TYPE The data type used to store the component. The types GL_NONE, GL_SIGNED_NORMALIZED, GL_UNSIGNED_NORMALIZED, GL_FLOAT, GL_INT, and GL_UNSIGNED_INT may be returned to indicate signed normalized fixed-point, unsigned normalized fixed-point, floating-point, integer unnormalized, and unsigned integer unnormalized components, respectively.
    GreenType = 0x8C11,             // GL_TEXTURE_GREEN_TYPE The data type used to store the component. The types GL_NONE, GL_SIGNED_NORMALIZED, GL_UNSIGNED_NORMALIZED, GL_FLOAT, GL_INT, and GL_UNSIGNED_INT may be returned to indicate signed normalized fixed-point, unsigned normalized fixed-point, floating-point, integer unnormalized, and unsigned integer unnormalized components, respectively.
    BlueType = 0x8C12,              // GL_TEXTURE_BLUE_TYPE The data type used to store the component. The types GL_NONE, GL_SIGNED_NORMALIZED, GL_UNSIGNED_NORMALIZED, GL_FLOAT, GL_INT, and GL_UNSIGNED_INT may be returned to indicate signed normalized fixed-point, unsigned normalized fixed-point, floating-point, integer unnormalized, and unsigned integer unnormalized components, respectively.
    AlphaType = 0x8C13,             // GL_TEXTURE_ALPHA_TYPE The data type used to store the component. The types GL_NONE, GL_SIGNED_NORMALIZED, GL_UNSIGNED_NORMALIZED, GL_FLOAT, GL_INT, and GL_UNSIGNED_INT may be returned to indicate signed normalized fixed-point, unsigned normalized fixed-point, floating-point, integer unnormalized, and unsigned integer unnormalized components, respectively.
    DepthType = 0x8C16,             // GL_TEXTURE_DEPTH_TYPE The data type used to store the component. The types GL_NONE, GL_SIGNED_NORMALIZED, GL_UNSIGNED_NORMALIZED, GL_FLOAT, GL_INT, and GL_UNSIGNED_INT may be returned to indicate signed normalized fixed-point, unsigned normalized fixed-point, floating-point, integer unnormalized, and unsigned integer unnormalized components, respectively.
    RedSize = 0x805C,               // GL_TEXTURE_RED_SIZE The internal storage resolution of an individual component. The resolution chosen by the GL will be a close match for the resolution requested by the user with the component argument of glTexImage1D, glTexImage2D, glTexImage3D, glCopyTexImage1D, and glCopyTexImage2D. The initial value is 0.
    GreenSize = 0x805D,             // GL_TEXTURE_GREEN_SIZE The internal storage resolution of an individual component. The resolution chosen by the GL will be a close match for the resolution requested by the user with the component argument of glTexImage1D, glTexImage2D, glTexImage3D, glCopyTexImage1D, and glCopyTexImage2D. The initial value is 0.
    BlueSize = 0x805E,              // GL_TEXTURE_BLUE_SIZE The internal storage resolution of an individual component. The resolution chosen by the GL will be a close match for the resolution requested by the user with the component argument of glTexImage1D, glTexImage2D, glTexImage3D, glCopyTexImage1D, and glCopyTexImage2D. The initial value is 0.
    AlphaSize = 0x805F,             // GL_TEXTURE_ALPHA_SIZE The internal storage resolution of an individual component. The resolution chosen by the GL will be a close match for the resolution requested by the user with the component argument of glTexImage1D, glTexImage2D, glTexImage3D, glCopyTexImage1D, and glCopyTexImage2D. The initial value is 0.
    DepthSize = 0x884A,             // GL_TEXTURE_DEPTH_SIZE The internal storage resolution of an individual component. The resolution chosen by the GL will be a close match for the resolution requested by the user with the component argument of glTexImage1D, glTexImage2D, glTexImage3D, glCopyTexImage1D, and glCopyTexImage2D. The initial value is 0.
    Compressed = 0x86A1,            // GL_TEXTURE_COMPRESSED params returns a single boolean value indicating if the texture image is stored in a compressed internal format. The initiali value is GL_FALSE.
    CompressedImageSize = 0x86A0,   // GL_TEXTURE_COMPRESSED_IMAGE_SIZE params returns a single integer value, the number of unsigned bytes of the compressed texture image that would be returned from glGetCompressedTexImage.
    BufferOffset = 0x919D,          // GL_TEXTURE_BUFFER_OFFSET params returns a single integer value, the offset into the data store of the buffer bound to a buffer texture. glTexBufferRange.
    BufferSize = 0x919E,            // GL_TEXTURE_BUFFER_SIZE params returns a single integer value, the size of the range of a data store of the buffer bound to a buffer texture. glTexBufferRange. 
};
    
} // namespace glwpp::gl


