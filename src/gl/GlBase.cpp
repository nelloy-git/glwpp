#include "gl/GlBase.hpp"

#include <iostream>
#include <string.h>
#include "glad/gl.h"

using namespace glwpp;
using namespace GL;

GL::Enum::type Gl::ACTIVE_ATOMIC_COUNTER_BUFFERS(){
    return (unsigned int)(GL_ACTIVE_ATOMIC_COUNTER_BUFFERS);
}

GL::Enum::type Gl::ACTIVE_ATTRIBUTES(){
    return (unsigned int)(GL_ACTIVE_ATTRIBUTES);
}

GL::Enum::type Gl::ACTIVE_ATTRIBUTE_MAX_LENGTH(){
    return (unsigned int)(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH);
}

GL::Enum::type Gl::ACTIVE_PROGRAM(){
    return (unsigned int)(GL_ACTIVE_PROGRAM);
}

GL::Enum::type Gl::ACTIVE_RESOURCES(){
    return (unsigned int)(GL_ACTIVE_RESOURCES);
}

GL::Enum::type Gl::ACTIVE_SUBROUTINES(){
    return (unsigned int)(GL_ACTIVE_SUBROUTINES);
}

GL::Enum::type Gl::ACTIVE_SUBROUTINE_MAX_LENGTH(){
    return (unsigned int)(GL_ACTIVE_SUBROUTINE_MAX_LENGTH);
}

GL::Enum::type Gl::ACTIVE_SUBROUTINE_UNIFORMS(){
    return (unsigned int)(GL_ACTIVE_SUBROUTINE_UNIFORMS);
}

GL::Enum::type Gl::ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS(){
    return (unsigned int)(GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS);
}

GL::Enum::type Gl::ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH(){
    return (unsigned int)(GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH);
}

GL::Enum::type Gl::ACTIVE_TEXTURE(){
    return (unsigned int)(GL_ACTIVE_TEXTURE);
}

GL::Enum::type Gl::ACTIVE_UNIFORMS(){
    return (unsigned int)(GL_ACTIVE_UNIFORMS);
}

GL::Enum::type Gl::ACTIVE_UNIFORM_BLOCKS(){
    return (unsigned int)(GL_ACTIVE_UNIFORM_BLOCKS);
}

GL::Enum::type Gl::ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH(){
    return (unsigned int)(GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH);
}

GL::Enum::type Gl::ACTIVE_UNIFORM_MAX_LENGTH(){
    return (unsigned int)(GL_ACTIVE_UNIFORM_MAX_LENGTH);
}

GL::Enum::type Gl::ACTIVE_VARIABLES(){
    return (unsigned int)(GL_ACTIVE_VARIABLES);
}

GL::Enum::type Gl::ALIASED_LINE_WIDTH_RANGE(){
    return (unsigned int)(GL_ALIASED_LINE_WIDTH_RANGE);
}

GL::Enum::type Gl::ALL_BARRIER_BITS(){
    return (unsigned int)(GL_ALL_BARRIER_BITS);
}

GL::Enum::type Gl::ALL_SHADER_BITS(){
    return (unsigned int)(GL_ALL_SHADER_BITS);
}

GL::Enum::type Gl::ALPHA(){
    return (unsigned int)(GL_ALPHA);
}

GL::Enum::type Gl::ALREADY_SIGNALED(){
    return (unsigned int)(GL_ALREADY_SIGNALED);
}

GL::Enum::type Gl::ALWAYS(){
    return (unsigned int)(GL_ALWAYS);
}

GL::Enum::type Gl::AND(){
    return (unsigned int)(GL_AND);
}

GL::Enum::type Gl::AND_INVERTED(){
    return (unsigned int)(GL_AND_INVERTED);
}

GL::Enum::type Gl::AND_REVERSE(){
    return (unsigned int)(GL_AND_REVERSE);
}

GL::Enum::type Gl::ANY_SAMPLES_PASSED(){
    return (unsigned int)(GL_ANY_SAMPLES_PASSED);
}

GL::Enum::type Gl::ANY_SAMPLES_PASSED_CONSERVATIVE(){
    return (unsigned int)(GL_ANY_SAMPLES_PASSED_CONSERVATIVE);
}

GL::Enum::type Gl::ARRAY_BUFFER(){
    return (unsigned int)(GL_ARRAY_BUFFER);
}

GL::Enum::type Gl::ARRAY_BUFFER_BINDING(){
    return (unsigned int)(GL_ARRAY_BUFFER_BINDING);
}

GL::Enum::type Gl::ARRAY_SIZE(){
    return (unsigned int)(GL_ARRAY_SIZE);
}

GL::Enum::type Gl::ARRAY_STRIDE(){
    return (unsigned int)(GL_ARRAY_STRIDE);
}

GL::Enum::type Gl::ATOMIC_COUNTER_BARRIER_BIT(){
    return (unsigned int)(GL_ATOMIC_COUNTER_BARRIER_BIT);
}

GL::Enum::type Gl::ATOMIC_COUNTER_BUFFER(){
    return (unsigned int)(GL_ATOMIC_COUNTER_BUFFER);
}

GL::Enum::type Gl::ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS(){
    return (unsigned int)(GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS);
}

GL::Enum::type Gl::ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES(){
    return (unsigned int)(GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES);
}

GL::Enum::type Gl::ATOMIC_COUNTER_BUFFER_BINDING(){
    return (unsigned int)(GL_ATOMIC_COUNTER_BUFFER_BINDING);
}

GL::Enum::type Gl::ATOMIC_COUNTER_BUFFER_DATA_SIZE(){
    return (unsigned int)(GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE);
}

GL::Enum::type Gl::ATOMIC_COUNTER_BUFFER_INDEX(){
    return (unsigned int)(GL_ATOMIC_COUNTER_BUFFER_INDEX);
}

GL::Enum::type Gl::ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER(){
    return (unsigned int)(GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER);
}

GL::Enum::type Gl::ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER(){
    return (unsigned int)(GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER);
}

GL::Enum::type Gl::ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER(){
    return (unsigned int)(GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER);
}

GL::Enum::type Gl::ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER(){
    return (unsigned int)(GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER);
}

GL::Enum::type Gl::ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER(){
    return (unsigned int)(GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER);
}

GL::Enum::type Gl::ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER(){
    return (unsigned int)(GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER);
}

GL::Enum::type Gl::ATOMIC_COUNTER_BUFFER_SIZE(){
    return (unsigned int)(GL_ATOMIC_COUNTER_BUFFER_SIZE);
}

GL::Enum::type Gl::ATOMIC_COUNTER_BUFFER_START(){
    return (unsigned int)(GL_ATOMIC_COUNTER_BUFFER_START);
}

GL::Enum::type Gl::ATTACHED_SHADERS(){
    return (unsigned int)(GL_ATTACHED_SHADERS);
}

GL::Enum::type Gl::AUTO_GENERATE_MIPMAP(){
    return (unsigned int)(GL_AUTO_GENERATE_MIPMAP);
}

GL::Enum::type Gl::BACK(){
    return (unsigned int)(GL_BACK);
}

GL::Enum::type Gl::BACK_LEFT(){
    return (unsigned int)(GL_BACK_LEFT);
}

GL::Enum::type Gl::BACK_RIGHT(){
    return (unsigned int)(GL_BACK_RIGHT);
}

GL::Enum::type Gl::BGR(){
    return (unsigned int)(GL_BGR);
}

GL::Enum::type Gl::BGRA(){
    return (unsigned int)(GL_BGRA);
}

GL::Enum::type Gl::BGRA_INTEGER(){
    return (unsigned int)(GL_BGRA_INTEGER);
}

GL::Enum::type Gl::BGR_INTEGER(){
    return (unsigned int)(GL_BGR_INTEGER);
}

GL::Enum::type Gl::BLEND(){
    return (unsigned int)(GL_BLEND);
}

GL::Enum::type Gl::BLEND_COLOR(){
    return (unsigned int)(GL_BLEND_COLOR);
}

GL::Enum::type Gl::BLEND_DST(){
    return (unsigned int)(GL_BLEND_DST);
}

GL::Enum::type Gl::BLEND_DST_ALPHA(){
    return (unsigned int)(GL_BLEND_DST_ALPHA);
}

GL::Enum::type Gl::BLEND_DST_RGB(){
    return (unsigned int)(GL_BLEND_DST_RGB);
}

GL::Enum::type Gl::BLEND_EQUATION(){
    return (unsigned int)(GL_BLEND_EQUATION);
}

GL::Enum::type Gl::BLEND_EQUATION_ALPHA(){
    return (unsigned int)(GL_BLEND_EQUATION_ALPHA);
}

GL::Enum::type Gl::BLEND_EQUATION_RGB(){
    return (unsigned int)(GL_BLEND_EQUATION_RGB);
}

GL::Enum::type Gl::BLEND_SRC(){
    return (unsigned int)(GL_BLEND_SRC);
}

GL::Enum::type Gl::BLEND_SRC_ALPHA(){
    return (unsigned int)(GL_BLEND_SRC_ALPHA);
}

GL::Enum::type Gl::BLEND_SRC_RGB(){
    return (unsigned int)(GL_BLEND_SRC_RGB);
}

GL::Enum::type Gl::BLOCK_INDEX(){
    return (unsigned int)(GL_BLOCK_INDEX);
}

GL::Enum::type Gl::BLUE(){
    return (unsigned int)(GL_BLUE);
}

GL::Enum::type Gl::BLUE_INTEGER(){
    return (unsigned int)(GL_BLUE_INTEGER);
}

GL::Enum::type Gl::BOOL(){
    return (unsigned int)(GL_BOOL);
}

GL::Enum::type Gl::BOOL_VEC2(){
    return (unsigned int)(GL_BOOL_VEC2);
}

GL::Enum::type Gl::BOOL_VEC3(){
    return (unsigned int)(GL_BOOL_VEC3);
}

GL::Enum::type Gl::BOOL_VEC4(){
    return (unsigned int)(GL_BOOL_VEC4);
}

GL::Enum::type Gl::BUFFER(){
    return (unsigned int)(GL_BUFFER);
}

GL::Enum::type Gl::BUFFER_ACCESS(){
    return (unsigned int)(GL_BUFFER_ACCESS);
}

GL::Enum::type Gl::BUFFER_ACCESS_FLAGS(){
    return (unsigned int)(GL_BUFFER_ACCESS_FLAGS);
}

GL::Enum::type Gl::BUFFER_BINDING(){
    return (unsigned int)(GL_BUFFER_BINDING);
}

GL::Enum::type Gl::BUFFER_DATA_SIZE(){
    return (unsigned int)(GL_BUFFER_DATA_SIZE);
}

GL::Enum::type Gl::BUFFER_IMMUTABLE_STORAGE(){
    return (unsigned int)(GL_BUFFER_IMMUTABLE_STORAGE);
}

GL::Enum::type Gl::BUFFER_MAPPED(){
    return (unsigned int)(GL_BUFFER_MAPPED);
}

GL::Enum::type Gl::BUFFER_MAP_LENGTH(){
    return (unsigned int)(GL_BUFFER_MAP_LENGTH);
}

GL::Enum::type Gl::BUFFER_MAP_OFFSET(){
    return (unsigned int)(GL_BUFFER_MAP_OFFSET);
}

GL::Enum::type Gl::BUFFER_MAP_POINTER(){
    return (unsigned int)(GL_BUFFER_MAP_POINTER);
}

GL::Enum::type Gl::BUFFER_SIZE(){
    return (unsigned int)(GL_BUFFER_SIZE);
}

GL::Enum::type Gl::BUFFER_STORAGE_FLAGS(){
    return (unsigned int)(GL_BUFFER_STORAGE_FLAGS);
}

GL::Enum::type Gl::BUFFER_UPDATE_BARRIER_BIT(){
    return (unsigned int)(GL_BUFFER_UPDATE_BARRIER_BIT);
}

GL::Enum::type Gl::BUFFER_USAGE(){
    return (unsigned int)(GL_BUFFER_USAGE);
}

GL::Enum::type Gl::BUFFER_VARIABLE(){
    return (unsigned int)(GL_BUFFER_VARIABLE);
}

GL::Enum::type Gl::BYTE(){
    return (unsigned int)(GL_BYTE);
}

GL::Enum::type Gl::CAVEAT_SUPPORT(){
    return (unsigned int)(GL_CAVEAT_SUPPORT);
}

GL::Enum::type Gl::CCW(){
    return (unsigned int)(GL_CCW);
}

GL::Enum::type Gl::CLAMP_READ_COLOR(){
    return (unsigned int)(GL_CLAMP_READ_COLOR);
}

GL::Enum::type Gl::CLAMP_TO_BORDER(){
    return (unsigned int)(GL_CLAMP_TO_BORDER);
}

GL::Enum::type Gl::CLAMP_TO_EDGE(){
    return (unsigned int)(GL_CLAMP_TO_EDGE);
}

GL::Enum::type Gl::CLEAR(){
    return (unsigned int)(GL_CLEAR);
}

GL::Enum::type Gl::CLEAR_BUFFER(){
    return (unsigned int)(GL_CLEAR_BUFFER);
}

GL::Enum::type Gl::CLEAR_TEXTURE(){
    return (unsigned int)(GL_CLEAR_TEXTURE);
}

GL::Enum::type Gl::CLIENT_MAPPED_BUFFER_BARRIER_BIT(){
    return (unsigned int)(GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT);
}

GL::Enum::type Gl::CLIENT_STORAGE_BIT(){
    return (unsigned int)(GL_CLIENT_STORAGE_BIT);
}

GL::Enum::type Gl::CLIPPING_INPUT_PRIMITIVES(){
    return (unsigned int)(GL_CLIPPING_INPUT_PRIMITIVES);
}

GL::Enum::type Gl::CLIPPING_OUTPUT_PRIMITIVES(){
    return (unsigned int)(GL_CLIPPING_OUTPUT_PRIMITIVES);
}

GL::Enum::type Gl::CLIP_DEPTH_MODE(){
    return (unsigned int)(GL_CLIP_DEPTH_MODE);
}

GL::Enum::type Gl::CLIP_DISTANCE0(){
    return (unsigned int)(GL_CLIP_DISTANCE0);
}

GL::Enum::type Gl::CLIP_DISTANCE1(){
    return (unsigned int)(GL_CLIP_DISTANCE1);
}

GL::Enum::type Gl::CLIP_DISTANCE2(){
    return (unsigned int)(GL_CLIP_DISTANCE2);
}

GL::Enum::type Gl::CLIP_DISTANCE3(){
    return (unsigned int)(GL_CLIP_DISTANCE3);
}

GL::Enum::type Gl::CLIP_DISTANCE4(){
    return (unsigned int)(GL_CLIP_DISTANCE4);
}

GL::Enum::type Gl::CLIP_DISTANCE5(){
    return (unsigned int)(GL_CLIP_DISTANCE5);
}

GL::Enum::type Gl::CLIP_DISTANCE6(){
    return (unsigned int)(GL_CLIP_DISTANCE6);
}

GL::Enum::type Gl::CLIP_DISTANCE7(){
    return (unsigned int)(GL_CLIP_DISTANCE7);
}

GL::Enum::type Gl::CLIP_ORIGIN(){
    return (unsigned int)(GL_CLIP_ORIGIN);
}

GL::Enum::type Gl::COLOR(){
    return (unsigned int)(GL_COLOR);
}

GL::Enum::type Gl::COLOR_ATTACHMENT0(){
    return (unsigned int)(GL_COLOR_ATTACHMENT0);
}

GL::Enum::type Gl::COLOR_ATTACHMENT1(){
    return (unsigned int)(GL_COLOR_ATTACHMENT1);
}

GL::Enum::type Gl::COLOR_ATTACHMENT10(){
    return (unsigned int)(GL_COLOR_ATTACHMENT10);
}

GL::Enum::type Gl::COLOR_ATTACHMENT11(){
    return (unsigned int)(GL_COLOR_ATTACHMENT11);
}

GL::Enum::type Gl::COLOR_ATTACHMENT12(){
    return (unsigned int)(GL_COLOR_ATTACHMENT12);
}

GL::Enum::type Gl::COLOR_ATTACHMENT13(){
    return (unsigned int)(GL_COLOR_ATTACHMENT13);
}

GL::Enum::type Gl::COLOR_ATTACHMENT14(){
    return (unsigned int)(GL_COLOR_ATTACHMENT14);
}

GL::Enum::type Gl::COLOR_ATTACHMENT15(){
    return (unsigned int)(GL_COLOR_ATTACHMENT15);
}

GL::Enum::type Gl::COLOR_ATTACHMENT16(){
    return (unsigned int)(GL_COLOR_ATTACHMENT16);
}

GL::Enum::type Gl::COLOR_ATTACHMENT17(){
    return (unsigned int)(GL_COLOR_ATTACHMENT17);
}

GL::Enum::type Gl::COLOR_ATTACHMENT18(){
    return (unsigned int)(GL_COLOR_ATTACHMENT18);
}

GL::Enum::type Gl::COLOR_ATTACHMENT19(){
    return (unsigned int)(GL_COLOR_ATTACHMENT19);
}

GL::Enum::type Gl::COLOR_ATTACHMENT2(){
    return (unsigned int)(GL_COLOR_ATTACHMENT2);
}

GL::Enum::type Gl::COLOR_ATTACHMENT20(){
    return (unsigned int)(GL_COLOR_ATTACHMENT20);
}

GL::Enum::type Gl::COLOR_ATTACHMENT21(){
    return (unsigned int)(GL_COLOR_ATTACHMENT21);
}

GL::Enum::type Gl::COLOR_ATTACHMENT22(){
    return (unsigned int)(GL_COLOR_ATTACHMENT22);
}

GL::Enum::type Gl::COLOR_ATTACHMENT23(){
    return (unsigned int)(GL_COLOR_ATTACHMENT23);
}

GL::Enum::type Gl::COLOR_ATTACHMENT24(){
    return (unsigned int)(GL_COLOR_ATTACHMENT24);
}

GL::Enum::type Gl::COLOR_ATTACHMENT25(){
    return (unsigned int)(GL_COLOR_ATTACHMENT25);
}

GL::Enum::type Gl::COLOR_ATTACHMENT26(){
    return (unsigned int)(GL_COLOR_ATTACHMENT26);
}

GL::Enum::type Gl::COLOR_ATTACHMENT27(){
    return (unsigned int)(GL_COLOR_ATTACHMENT27);
}

GL::Enum::type Gl::COLOR_ATTACHMENT28(){
    return (unsigned int)(GL_COLOR_ATTACHMENT28);
}

GL::Enum::type Gl::COLOR_ATTACHMENT29(){
    return (unsigned int)(GL_COLOR_ATTACHMENT29);
}

GL::Enum::type Gl::COLOR_ATTACHMENT3(){
    return (unsigned int)(GL_COLOR_ATTACHMENT3);
}

GL::Enum::type Gl::COLOR_ATTACHMENT30(){
    return (unsigned int)(GL_COLOR_ATTACHMENT30);
}

GL::Enum::type Gl::COLOR_ATTACHMENT31(){
    return (unsigned int)(GL_COLOR_ATTACHMENT31);
}

GL::Enum::type Gl::COLOR_ATTACHMENT4(){
    return (unsigned int)(GL_COLOR_ATTACHMENT4);
}

GL::Enum::type Gl::COLOR_ATTACHMENT5(){
    return (unsigned int)(GL_COLOR_ATTACHMENT5);
}

GL::Enum::type Gl::COLOR_ATTACHMENT6(){
    return (unsigned int)(GL_COLOR_ATTACHMENT6);
}

GL::Enum::type Gl::COLOR_ATTACHMENT7(){
    return (unsigned int)(GL_COLOR_ATTACHMENT7);
}

GL::Enum::type Gl::COLOR_ATTACHMENT8(){
    return (unsigned int)(GL_COLOR_ATTACHMENT8);
}

GL::Enum::type Gl::COLOR_ATTACHMENT9(){
    return (unsigned int)(GL_COLOR_ATTACHMENT9);
}

GL::Enum::type Gl::COLOR_BUFFER_BIT(){
    return (unsigned int)(GL_COLOR_BUFFER_BIT);
}

GL::Enum::type Gl::COLOR_CLEAR_VALUE(){
    return (unsigned int)(GL_COLOR_CLEAR_VALUE);
}

GL::Enum::type Gl::COLOR_COMPONENTS(){
    return (unsigned int)(GL_COLOR_COMPONENTS);
}

GL::Enum::type Gl::COLOR_ENCODING(){
    return (unsigned int)(GL_COLOR_ENCODING);
}

GL::Enum::type Gl::COLOR_LOGIC_OP(){
    return (unsigned int)(GL_COLOR_LOGIC_OP);
}

GL::Enum::type Gl::COLOR_RENDERABLE(){
    return (unsigned int)(GL_COLOR_RENDERABLE);
}

GL::Enum::type Gl::COLOR_WRITEMASK(){
    return (unsigned int)(GL_COLOR_WRITEMASK);
}

GL::Enum::type Gl::COMMAND_BARRIER_BIT(){
    return (unsigned int)(GL_COMMAND_BARRIER_BIT);
}

GL::Enum::type Gl::COMPARE_REF_TO_TEXTURE(){
    return (unsigned int)(GL_COMPARE_REF_TO_TEXTURE);
}

GL::Enum::type Gl::COMPATIBLE_SUBROUTINES(){
    return (unsigned int)(GL_COMPATIBLE_SUBROUTINES);
}

GL::Enum::type Gl::COMPILE_STATUS(){
    return (unsigned int)(GL_COMPILE_STATUS);
}

GL::Enum::type Gl::COMPRESSED_R11_EAC(){
    return (unsigned int)(GL_COMPRESSED_R11_EAC);
}

GL::Enum::type Gl::COMPRESSED_RED(){
    return (unsigned int)(GL_COMPRESSED_RED);
}

GL::Enum::type Gl::COMPRESSED_RED_RGTC1(){
    return (unsigned int)(GL_COMPRESSED_RED_RGTC1);
}

GL::Enum::type Gl::COMPRESSED_RG(){
    return (unsigned int)(GL_COMPRESSED_RG);
}

GL::Enum::type Gl::COMPRESSED_RG11_EAC(){
    return (unsigned int)(GL_COMPRESSED_RG11_EAC);
}

GL::Enum::type Gl::COMPRESSED_RGB(){
    return (unsigned int)(GL_COMPRESSED_RGB);
}

GL::Enum::type Gl::COMPRESSED_RGB8_ETC2(){
    return (unsigned int)(GL_COMPRESSED_RGB8_ETC2);
}

GL::Enum::type Gl::COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2(){
    return (unsigned int)(GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2);
}

GL::Enum::type Gl::COMPRESSED_RGBA(){
    return (unsigned int)(GL_COMPRESSED_RGBA);
}

GL::Enum::type Gl::COMPRESSED_RGBA8_ETC2_EAC(){
    return (unsigned int)(GL_COMPRESSED_RGBA8_ETC2_EAC);
}

GL::Enum::type Gl::COMPRESSED_RGBA_BPTC_UNORM(){
    return (unsigned int)(GL_COMPRESSED_RGBA_BPTC_UNORM);
}

GL::Enum::type Gl::COMPRESSED_RGB_BPTC_SIGNED_FLOAT(){
    return (unsigned int)(GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT);
}

GL::Enum::type Gl::COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT(){
    return (unsigned int)(GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT);
}

GL::Enum::type Gl::COMPRESSED_RG_RGTC2(){
    return (unsigned int)(GL_COMPRESSED_RG_RGTC2);
}

GL::Enum::type Gl::COMPRESSED_SIGNED_R11_EAC(){
    return (unsigned int)(GL_COMPRESSED_SIGNED_R11_EAC);
}

GL::Enum::type Gl::COMPRESSED_SIGNED_RED_RGTC1(){
    return (unsigned int)(GL_COMPRESSED_SIGNED_RED_RGTC1);
}

GL::Enum::type Gl::COMPRESSED_SIGNED_RG11_EAC(){
    return (unsigned int)(GL_COMPRESSED_SIGNED_RG11_EAC);
}

GL::Enum::type Gl::COMPRESSED_SIGNED_RG_RGTC2(){
    return (unsigned int)(GL_COMPRESSED_SIGNED_RG_RGTC2);
}

GL::Enum::type Gl::COMPRESSED_SRGB(){
    return (unsigned int)(GL_COMPRESSED_SRGB);
}

GL::Enum::type Gl::COMPRESSED_SRGB8_ALPHA8_ETC2_EAC(){
    return (unsigned int)(GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC);
}

GL::Enum::type Gl::COMPRESSED_SRGB8_ETC2(){
    return (unsigned int)(GL_COMPRESSED_SRGB8_ETC2);
}

GL::Enum::type Gl::COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2(){
    return (unsigned int)(GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2);
}

GL::Enum::type Gl::COMPRESSED_SRGB_ALPHA(){
    return (unsigned int)(GL_COMPRESSED_SRGB_ALPHA);
}

GL::Enum::type Gl::COMPRESSED_SRGB_ALPHA_BPTC_UNORM(){
    return (unsigned int)(GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM);
}

GL::Enum::type Gl::COMPRESSED_TEXTURE_FORMATS(){
    return (unsigned int)(GL_COMPRESSED_TEXTURE_FORMATS);
}

GL::Enum::type Gl::COMPUTE_SHADER(){
    return (unsigned int)(GL_COMPUTE_SHADER);
}

GL::Enum::type Gl::COMPUTE_SHADER_BIT(){
    return (unsigned int)(GL_COMPUTE_SHADER_BIT);
}

GL::Enum::type Gl::COMPUTE_SHADER_INVOCATIONS(){
    return (unsigned int)(GL_COMPUTE_SHADER_INVOCATIONS);
}

GL::Enum::type Gl::COMPUTE_SUBROUTINE(){
    return (unsigned int)(GL_COMPUTE_SUBROUTINE);
}

GL::Enum::type Gl::COMPUTE_SUBROUTINE_UNIFORM(){
    return (unsigned int)(GL_COMPUTE_SUBROUTINE_UNIFORM);
}

GL::Enum::type Gl::COMPUTE_TEXTURE(){
    return (unsigned int)(GL_COMPUTE_TEXTURE);
}

GL::Enum::type Gl::COMPUTE_WORK_GROUP_SIZE(){
    return (unsigned int)(GL_COMPUTE_WORK_GROUP_SIZE);
}

GL::Enum::type Gl::CONDITION_SATISFIED(){
    return (unsigned int)(GL_CONDITION_SATISFIED);
}

GL::Enum::type Gl::CONSTANT_ALPHA(){
    return (unsigned int)(GL_CONSTANT_ALPHA);
}

GL::Enum::type Gl::CONSTANT_COLOR(){
    return (unsigned int)(GL_CONSTANT_COLOR);
}

GL::Enum::type Gl::CONTEXT_COMPATIBILITY_PROFILE_BIT(){
    return (unsigned int)(GL_CONTEXT_COMPATIBILITY_PROFILE_BIT);
}

GL::Enum::type Gl::CONTEXT_CORE_PROFILE_BIT(){
    return (unsigned int)(GL_CONTEXT_CORE_PROFILE_BIT);
}

GL::Enum::type Gl::CONTEXT_FLAGS(){
    return (unsigned int)(GL_CONTEXT_FLAGS);
}

GL::Enum::type Gl::CONTEXT_FLAG_DEBUG_BIT(){
    return (unsigned int)(GL_CONTEXT_FLAG_DEBUG_BIT);
}

GL::Enum::type Gl::CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT(){
    return (unsigned int)(GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT);
}

GL::Enum::type Gl::CONTEXT_FLAG_NO_ERROR_BIT(){
    return (unsigned int)(GL_CONTEXT_FLAG_NO_ERROR_BIT);
}

GL::Enum::type Gl::CONTEXT_FLAG_ROBUST_ACCESS_BIT(){
    return (unsigned int)(GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT);
}

GL::Enum::type Gl::CONTEXT_LOST(){
    return (unsigned int)(GL_CONTEXT_LOST);
}

GL::Enum::type Gl::CONTEXT_PROFILE_MASK(){
    return (unsigned int)(GL_CONTEXT_PROFILE_MASK);
}

GL::Enum::type Gl::CONTEXT_RELEASE_BEHAVIOR(){
    return (unsigned int)(GL_CONTEXT_RELEASE_BEHAVIOR);
}

GL::Enum::type Gl::CONTEXT_RELEASE_BEHAVIOR_FLUSH(){
    return (unsigned int)(GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH);
}

GL::Enum::type Gl::COPY(){
    return (unsigned int)(GL_COPY);
}

GL::Enum::type Gl::COPY_INVERTED(){
    return (unsigned int)(GL_COPY_INVERTED);
}

GL::Enum::type Gl::COPY_READ_BUFFER(){
    return (unsigned int)(GL_COPY_READ_BUFFER);
}

GL::Enum::type Gl::COPY_READ_BUFFER_BINDING(){
    return (unsigned int)(GL_COPY_READ_BUFFER_BINDING);
}

GL::Enum::type Gl::COPY_WRITE_BUFFER(){
    return (unsigned int)(GL_COPY_WRITE_BUFFER);
}

GL::Enum::type Gl::COPY_WRITE_BUFFER_BINDING(){
    return (unsigned int)(GL_COPY_WRITE_BUFFER_BINDING);
}

GL::Enum::type Gl::CULL_FACE(){
    return (unsigned int)(GL_CULL_FACE);
}

GL::Enum::type Gl::CULL_FACE_MODE(){
    return (unsigned int)(GL_CULL_FACE_MODE);
}

GL::Enum::type Gl::CURRENT_PROGRAM(){
    return (unsigned int)(GL_CURRENT_PROGRAM);
}

GL::Enum::type Gl::CURRENT_QUERY(){
    return (unsigned int)(GL_CURRENT_QUERY);
}

GL::Enum::type Gl::CURRENT_VERTEX_ATTRIB(){
    return (unsigned int)(GL_CURRENT_VERTEX_ATTRIB);
}

GL::Enum::type Gl::CW(){
    return (unsigned int)(GL_CW);
}

GL::Enum::type Gl::DEBUG_CALLBACK_FUNCTION(){
    return (unsigned int)(GL_DEBUG_CALLBACK_FUNCTION);
}

GL::Enum::type Gl::DEBUG_CALLBACK_USER_PARAM(){
    return (unsigned int)(GL_DEBUG_CALLBACK_USER_PARAM);
}

GL::Enum::type Gl::DEBUG_GROUP_STACK_DEPTH(){
    return (unsigned int)(GL_DEBUG_GROUP_STACK_DEPTH);
}

GL::Enum::type Gl::DEBUG_LOGGED_MESSAGES(){
    return (unsigned int)(GL_DEBUG_LOGGED_MESSAGES);
}

GL::Enum::type Gl::DEBUG_NEXT_LOGGED_MESSAGE_LENGTH(){
    return (unsigned int)(GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH);
}

GL::Enum::type Gl::DEBUG_OUTPUT(){
    return (unsigned int)(GL_DEBUG_OUTPUT);
}

GL::Enum::type Gl::DEBUG_OUTPUT_SYNCHRONOUS(){
    return (unsigned int)(GL_DEBUG_OUTPUT_SYNCHRONOUS);
}

GL::Enum::type Gl::DEBUG_SEVERITY_HIGH(){
    return (unsigned int)(GL_DEBUG_SEVERITY_HIGH);
}

GL::Enum::type Gl::DEBUG_SEVERITY_LOW(){
    return (unsigned int)(GL_DEBUG_SEVERITY_LOW);
}

GL::Enum::type Gl::DEBUG_SEVERITY_MEDIUM(){
    return (unsigned int)(GL_DEBUG_SEVERITY_MEDIUM);
}

GL::Enum::type Gl::DEBUG_SEVERITY_NOTIFICATION(){
    return (unsigned int)(GL_DEBUG_SEVERITY_NOTIFICATION);
}

GL::Enum::type Gl::DEBUG_SOURCE_API(){
    return (unsigned int)(GL_DEBUG_SOURCE_API);
}

GL::Enum::type Gl::DEBUG_SOURCE_APPLICATION(){
    return (unsigned int)(GL_DEBUG_SOURCE_APPLICATION);
}

GL::Enum::type Gl::DEBUG_SOURCE_OTHER(){
    return (unsigned int)(GL_DEBUG_SOURCE_OTHER);
}

GL::Enum::type Gl::DEBUG_SOURCE_SHADER_COMPILER(){
    return (unsigned int)(GL_DEBUG_SOURCE_SHADER_COMPILER);
}

GL::Enum::type Gl::DEBUG_SOURCE_THIRD_PARTY(){
    return (unsigned int)(GL_DEBUG_SOURCE_THIRD_PARTY);
}

GL::Enum::type Gl::DEBUG_SOURCE_WINDOW_SYSTEM(){
    return (unsigned int)(GL_DEBUG_SOURCE_WINDOW_SYSTEM);
}

GL::Enum::type Gl::DEBUG_TYPE_DEPRECATED_BEHAVIOR(){
    return (unsigned int)(GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR);
}

GL::Enum::type Gl::DEBUG_TYPE_ERROR(){
    return (unsigned int)(GL_DEBUG_TYPE_ERROR);
}

GL::Enum::type Gl::DEBUG_TYPE_MARKER(){
    return (unsigned int)(GL_DEBUG_TYPE_MARKER);
}

GL::Enum::type Gl::DEBUG_TYPE_OTHER(){
    return (unsigned int)(GL_DEBUG_TYPE_OTHER);
}

GL::Enum::type Gl::DEBUG_TYPE_PERFORMANCE(){
    return (unsigned int)(GL_DEBUG_TYPE_PERFORMANCE);
}

GL::Enum::type Gl::DEBUG_TYPE_POP_GROUP(){
    return (unsigned int)(GL_DEBUG_TYPE_POP_GROUP);
}

GL::Enum::type Gl::DEBUG_TYPE_PORTABILITY(){
    return (unsigned int)(GL_DEBUG_TYPE_PORTABILITY);
}

GL::Enum::type Gl::DEBUG_TYPE_PUSH_GROUP(){
    return (unsigned int)(GL_DEBUG_TYPE_PUSH_GROUP);
}

GL::Enum::type Gl::DEBUG_TYPE_UNDEFINED_BEHAVIOR(){
    return (unsigned int)(GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR);
}

GL::Enum::type Gl::DECR(){
    return (unsigned int)(GL_DECR);
}

GL::Enum::type Gl::DECR_WRAP(){
    return (unsigned int)(GL_DECR_WRAP);
}

GL::Enum::type Gl::DELETE_STATUS(){
    return (unsigned int)(GL_DELETE_STATUS);
}

GL::Enum::type Gl::DEPTH(){
    return (unsigned int)(GL_DEPTH);
}

GL::Enum::type Gl::DEPTH24_STENCIL8(){
    return (unsigned int)(GL_DEPTH24_STENCIL8);
}

GL::Enum::type Gl::DEPTH32F_STENCIL8(){
    return (unsigned int)(GL_DEPTH32F_STENCIL8);
}

GL::Enum::type Gl::DEPTH_ATTACHMENT(){
    return (unsigned int)(GL_DEPTH_ATTACHMENT);
}

GL::Enum::type Gl::DEPTH_BUFFER_BIT(){
    return (unsigned int)(GL_DEPTH_BUFFER_BIT);
}

GL::Enum::type Gl::DEPTH_CLAMP(){
    return (unsigned int)(GL_DEPTH_CLAMP);
}

GL::Enum::type Gl::DEPTH_CLEAR_VALUE(){
    return (unsigned int)(GL_DEPTH_CLEAR_VALUE);
}

GL::Enum::type Gl::DEPTH_COMPONENT(){
    return (unsigned int)(GL_DEPTH_COMPONENT);
}

GL::Enum::type Gl::DEPTH_COMPONENT16(){
    return (unsigned int)(GL_DEPTH_COMPONENT16);
}

GL::Enum::type Gl::DEPTH_COMPONENT24(){
    return (unsigned int)(GL_DEPTH_COMPONENT24);
}

GL::Enum::type Gl::DEPTH_COMPONENT32(){
    return (unsigned int)(GL_DEPTH_COMPONENT32);
}

GL::Enum::type Gl::DEPTH_COMPONENT32F(){
    return (unsigned int)(GL_DEPTH_COMPONENT32F);
}

GL::Enum::type Gl::DEPTH_COMPONENTS(){
    return (unsigned int)(GL_DEPTH_COMPONENTS);
}

GL::Enum::type Gl::DEPTH_FUNC(){
    return (unsigned int)(GL_DEPTH_FUNC);
}

GL::Enum::type Gl::DEPTH_RANGE(){
    return (unsigned int)(GL_DEPTH_RANGE);
}

GL::Enum::type Gl::DEPTH_RENDERABLE(){
    return (unsigned int)(GL_DEPTH_RENDERABLE);
}

GL::Enum::type Gl::DEPTH_STENCIL(){
    return (unsigned int)(GL_DEPTH_STENCIL);
}

GL::Enum::type Gl::DEPTH_STENCIL_ATTACHMENT(){
    return (unsigned int)(GL_DEPTH_STENCIL_ATTACHMENT);
}

GL::Enum::type Gl::DEPTH_STENCIL_TEXTURE_MODE(){
    return (unsigned int)(GL_DEPTH_STENCIL_TEXTURE_MODE);
}

GL::Enum::type Gl::DEPTH_TEST(){
    return (unsigned int)(GL_DEPTH_TEST);
}

GL::Enum::type Gl::DEPTH_WRITEMASK(){
    return (unsigned int)(GL_DEPTH_WRITEMASK);
}

GL::Enum::type Gl::DISPATCH_INDIRECT_BUFFER(){
    return (unsigned int)(GL_DISPATCH_INDIRECT_BUFFER);
}

GL::Enum::type Gl::DISPATCH_INDIRECT_BUFFER_BINDING(){
    return (unsigned int)(GL_DISPATCH_INDIRECT_BUFFER_BINDING);
}

GL::Enum::type Gl::DITHER(){
    return (unsigned int)(GL_DITHER);
}

GL::Enum::type Gl::DONT_CARE(){
    return (unsigned int)(GL_DONT_CARE);
}

GL::Enum::type Gl::DOUBLE(){
    return (unsigned int)(GL_DOUBLE);
}

GL::Enum::type Gl::DOUBLEBUFFER(){
    return (unsigned int)(GL_DOUBLEBUFFER);
}

GL::Enum::type Gl::DOUBLE_MAT2(){
    return (unsigned int)(GL_DOUBLE_MAT2);
}

GL::Enum::type Gl::DOUBLE_MAT2x3(){
    return (unsigned int)(GL_DOUBLE_MAT2x3);
}

GL::Enum::type Gl::DOUBLE_MAT2x4(){
    return (unsigned int)(GL_DOUBLE_MAT2x4);
}

GL::Enum::type Gl::DOUBLE_MAT3(){
    return (unsigned int)(GL_DOUBLE_MAT3);
}

GL::Enum::type Gl::DOUBLE_MAT3x2(){
    return (unsigned int)(GL_DOUBLE_MAT3x2);
}

GL::Enum::type Gl::DOUBLE_MAT3x4(){
    return (unsigned int)(GL_DOUBLE_MAT3x4);
}

GL::Enum::type Gl::DOUBLE_MAT4(){
    return (unsigned int)(GL_DOUBLE_MAT4);
}

GL::Enum::type Gl::DOUBLE_MAT4x2(){
    return (unsigned int)(GL_DOUBLE_MAT4x2);
}

GL::Enum::type Gl::DOUBLE_MAT4x3(){
    return (unsigned int)(GL_DOUBLE_MAT4x3);
}

GL::Enum::type Gl::DOUBLE_VEC2(){
    return (unsigned int)(GL_DOUBLE_VEC2);
}

GL::Enum::type Gl::DOUBLE_VEC3(){
    return (unsigned int)(GL_DOUBLE_VEC3);
}

GL::Enum::type Gl::DOUBLE_VEC4(){
    return (unsigned int)(GL_DOUBLE_VEC4);
}

GL::Enum::type Gl::DRAW_BUFFER(){
    return (unsigned int)(GL_DRAW_BUFFER);
}

GL::Enum::type Gl::DRAW_BUFFER0(){
    return (unsigned int)(GL_DRAW_BUFFER0);
}

GL::Enum::type Gl::DRAW_BUFFER1(){
    return (unsigned int)(GL_DRAW_BUFFER1);
}

GL::Enum::type Gl::DRAW_BUFFER10(){
    return (unsigned int)(GL_DRAW_BUFFER10);
}

GL::Enum::type Gl::DRAW_BUFFER11(){
    return (unsigned int)(GL_DRAW_BUFFER11);
}

GL::Enum::type Gl::DRAW_BUFFER12(){
    return (unsigned int)(GL_DRAW_BUFFER12);
}

GL::Enum::type Gl::DRAW_BUFFER13(){
    return (unsigned int)(GL_DRAW_BUFFER13);
}

GL::Enum::type Gl::DRAW_BUFFER14(){
    return (unsigned int)(GL_DRAW_BUFFER14);
}

GL::Enum::type Gl::DRAW_BUFFER15(){
    return (unsigned int)(GL_DRAW_BUFFER15);
}

GL::Enum::type Gl::DRAW_BUFFER2(){
    return (unsigned int)(GL_DRAW_BUFFER2);
}

GL::Enum::type Gl::DRAW_BUFFER3(){
    return (unsigned int)(GL_DRAW_BUFFER3);
}

GL::Enum::type Gl::DRAW_BUFFER4(){
    return (unsigned int)(GL_DRAW_BUFFER4);
}

GL::Enum::type Gl::DRAW_BUFFER5(){
    return (unsigned int)(GL_DRAW_BUFFER5);
}

GL::Enum::type Gl::DRAW_BUFFER6(){
    return (unsigned int)(GL_DRAW_BUFFER6);
}

GL::Enum::type Gl::DRAW_BUFFER7(){
    return (unsigned int)(GL_DRAW_BUFFER7);
}

GL::Enum::type Gl::DRAW_BUFFER8(){
    return (unsigned int)(GL_DRAW_BUFFER8);
}

GL::Enum::type Gl::DRAW_BUFFER9(){
    return (unsigned int)(GL_DRAW_BUFFER9);
}

GL::Enum::type Gl::DRAW_FRAMEBUFFER(){
    return (unsigned int)(GL_DRAW_FRAMEBUFFER);
}

GL::Enum::type Gl::DRAW_FRAMEBUFFER_BINDING(){
    return (unsigned int)(GL_DRAW_FRAMEBUFFER_BINDING);
}

GL::Enum::type Gl::DRAW_INDIRECT_BUFFER(){
    return (unsigned int)(GL_DRAW_INDIRECT_BUFFER);
}

GL::Enum::type Gl::DRAW_INDIRECT_BUFFER_BINDING(){
    return (unsigned int)(GL_DRAW_INDIRECT_BUFFER_BINDING);
}

GL::Enum::type Gl::DST_ALPHA(){
    return (unsigned int)(GL_DST_ALPHA);
}

GL::Enum::type Gl::DST_COLOR(){
    return (unsigned int)(GL_DST_COLOR);
}

GL::Enum::type Gl::DYNAMIC_COPY(){
    return (unsigned int)(GL_DYNAMIC_COPY);
}

GL::Enum::type Gl::DYNAMIC_DRAW(){
    return (unsigned int)(GL_DYNAMIC_DRAW);
}

GL::Enum::type Gl::DYNAMIC_READ(){
    return (unsigned int)(GL_DYNAMIC_READ);
}

GL::Enum::type Gl::DYNAMIC_STORAGE_BIT(){
    return (unsigned int)(GL_DYNAMIC_STORAGE_BIT);
}

GL::Enum::type Gl::ELEMENT_ARRAY_BARRIER_BIT(){
    return (unsigned int)(GL_ELEMENT_ARRAY_BARRIER_BIT);
}

GL::Enum::type Gl::ELEMENT_ARRAY_BUFFER(){
    return (unsigned int)(GL_ELEMENT_ARRAY_BUFFER);
}

GL::Enum::type Gl::ELEMENT_ARRAY_BUFFER_BINDING(){
    return (unsigned int)(GL_ELEMENT_ARRAY_BUFFER_BINDING);
}

GL::Enum::type Gl::EQUAL(){
    return (unsigned int)(GL_EQUAL);
}

GL::Enum::type Gl::EQUIV(){
    return (unsigned int)(GL_EQUIV);
}

GL::Enum::type Gl::EXTENSIONS(){
    return (unsigned int)(GL_EXTENSIONS);
}

GL::Enum::type Gl::FALSE(){
    return (unsigned int)(GL_FALSE);
}

GL::Enum::type Gl::FASTEST(){
    return (unsigned int)(GL_FASTEST);
}

GL::Enum::type Gl::FILL(){
    return (unsigned int)(GL_FILL);
}

GL::Enum::type Gl::FILTER(){
    return (unsigned int)(GL_FILTER);
}

GL::Enum::type Gl::FIRST_VERTEX_CONVENTION(){
    return (unsigned int)(GL_FIRST_VERTEX_CONVENTION);
}

GL::Enum::type Gl::FIXED(){
    return (unsigned int)(GL_FIXED);
}

GL::Enum::type Gl::FIXED_ONLY(){
    return (unsigned int)(GL_FIXED_ONLY);
}

GL::Enum::type Gl::FLOAT(){
    return (unsigned int)(GL_FLOAT);
}

GL::Enum::type Gl::FLOAT_32_UNSIGNED_INT_24_8_REV(){
    return (unsigned int)(GL_FLOAT_32_UNSIGNED_INT_24_8_REV);
}

GL::Enum::type Gl::FLOAT_MAT2(){
    return (unsigned int)(GL_FLOAT_MAT2);
}

GL::Enum::type Gl::FLOAT_MAT2x3(){
    return (unsigned int)(GL_FLOAT_MAT2x3);
}

GL::Enum::type Gl::FLOAT_MAT2x4(){
    return (unsigned int)(GL_FLOAT_MAT2x4);
}

GL::Enum::type Gl::FLOAT_MAT3(){
    return (unsigned int)(GL_FLOAT_MAT3);
}

GL::Enum::type Gl::FLOAT_MAT3x2(){
    return (unsigned int)(GL_FLOAT_MAT3x2);
}

GL::Enum::type Gl::FLOAT_MAT3x4(){
    return (unsigned int)(GL_FLOAT_MAT3x4);
}

GL::Enum::type Gl::FLOAT_MAT4(){
    return (unsigned int)(GL_FLOAT_MAT4);
}

GL::Enum::type Gl::FLOAT_MAT4x2(){
    return (unsigned int)(GL_FLOAT_MAT4x2);
}

GL::Enum::type Gl::FLOAT_MAT4x3(){
    return (unsigned int)(GL_FLOAT_MAT4x3);
}

GL::Enum::type Gl::FLOAT_VEC2(){
    return (unsigned int)(GL_FLOAT_VEC2);
}

GL::Enum::type Gl::FLOAT_VEC3(){
    return (unsigned int)(GL_FLOAT_VEC3);
}

GL::Enum::type Gl::FLOAT_VEC4(){
    return (unsigned int)(GL_FLOAT_VEC4);
}

GL::Enum::type Gl::FRACTIONAL_EVEN(){
    return (unsigned int)(GL_FRACTIONAL_EVEN);
}

GL::Enum::type Gl::FRACTIONAL_ODD(){
    return (unsigned int)(GL_FRACTIONAL_ODD);
}

GL::Enum::type Gl::FRAGMENT_INTERPOLATION_OFFSET_BITS(){
    return (unsigned int)(GL_FRAGMENT_INTERPOLATION_OFFSET_BITS);
}

GL::Enum::type Gl::FRAGMENT_SHADER(){
    return (unsigned int)(GL_FRAGMENT_SHADER);
}

GL::Enum::type Gl::FRAGMENT_SHADER_BIT(){
    return (unsigned int)(GL_FRAGMENT_SHADER_BIT);
}

GL::Enum::type Gl::FRAGMENT_SHADER_DERIVATIVE_HINT(){
    return (unsigned int)(GL_FRAGMENT_SHADER_DERIVATIVE_HINT);
}

GL::Enum::type Gl::FRAGMENT_SHADER_INVOCATIONS(){
    return (unsigned int)(GL_FRAGMENT_SHADER_INVOCATIONS);
}

GL::Enum::type Gl::FRAGMENT_SUBROUTINE(){
    return (unsigned int)(GL_FRAGMENT_SUBROUTINE);
}

GL::Enum::type Gl::FRAGMENT_SUBROUTINE_UNIFORM(){
    return (unsigned int)(GL_FRAGMENT_SUBROUTINE_UNIFORM);
}

GL::Enum::type Gl::FRAGMENT_TEXTURE(){
    return (unsigned int)(GL_FRAGMENT_TEXTURE);
}

GL::Enum::type Gl::FRAMEBUFFER(){
    return (unsigned int)(GL_FRAMEBUFFER);
}

GL::Enum::type Gl::FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE(){
    return (unsigned int)(GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE);
}

GL::Enum::type Gl::FRAMEBUFFER_ATTACHMENT_BLUE_SIZE(){
    return (unsigned int)(GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE);
}

GL::Enum::type Gl::FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING(){
    return (unsigned int)(GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING);
}

GL::Enum::type Gl::FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE(){
    return (unsigned int)(GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE);
}

GL::Enum::type Gl::FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE(){
    return (unsigned int)(GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE);
}

GL::Enum::type Gl::FRAMEBUFFER_ATTACHMENT_GREEN_SIZE(){
    return (unsigned int)(GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE);
}

GL::Enum::type Gl::FRAMEBUFFER_ATTACHMENT_LAYERED(){
    return (unsigned int)(GL_FRAMEBUFFER_ATTACHMENT_LAYERED);
}

GL::Enum::type Gl::FRAMEBUFFER_ATTACHMENT_OBJECT_NAME(){
    return (unsigned int)(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME);
}

GL::Enum::type Gl::FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE(){
    return (unsigned int)(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE);
}

GL::Enum::type Gl::FRAMEBUFFER_ATTACHMENT_RED_SIZE(){
    return (unsigned int)(GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE);
}

GL::Enum::type Gl::FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE(){
    return (unsigned int)(GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE);
}

GL::Enum::type Gl::FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE(){
    return (unsigned int)(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE);
}

GL::Enum::type Gl::FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER(){
    return (unsigned int)(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER);
}

GL::Enum::type Gl::FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL(){
    return (unsigned int)(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL);
}

GL::Enum::type Gl::FRAMEBUFFER_BARRIER_BIT(){
    return (unsigned int)(GL_FRAMEBUFFER_BARRIER_BIT);
}

GL::Enum::type Gl::FRAMEBUFFER_BINDING(){
    return (unsigned int)(GL_FRAMEBUFFER_BINDING);
}

GL::Enum::type Gl::FRAMEBUFFER_BLEND(){
    return (unsigned int)(GL_FRAMEBUFFER_BLEND);
}

GL::Enum::type Gl::FRAMEBUFFER_COMPLETE(){
    return (unsigned int)(GL_FRAMEBUFFER_COMPLETE);
}

GL::Enum::type Gl::FRAMEBUFFER_DEFAULT(){
    return (unsigned int)(GL_FRAMEBUFFER_DEFAULT);
}

GL::Enum::type Gl::FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS(){
    return (unsigned int)(GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS);
}

GL::Enum::type Gl::FRAMEBUFFER_DEFAULT_HEIGHT(){
    return (unsigned int)(GL_FRAMEBUFFER_DEFAULT_HEIGHT);
}

GL::Enum::type Gl::FRAMEBUFFER_DEFAULT_LAYERS(){
    return (unsigned int)(GL_FRAMEBUFFER_DEFAULT_LAYERS);
}

GL::Enum::type Gl::FRAMEBUFFER_DEFAULT_SAMPLES(){
    return (unsigned int)(GL_FRAMEBUFFER_DEFAULT_SAMPLES);
}

GL::Enum::type Gl::FRAMEBUFFER_DEFAULT_WIDTH(){
    return (unsigned int)(GL_FRAMEBUFFER_DEFAULT_WIDTH);
}

GL::Enum::type Gl::FRAMEBUFFER_INCOMPLETE_ATTACHMENT(){
    return (unsigned int)(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT);
}

GL::Enum::type Gl::FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER(){
    return (unsigned int)(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER);
}

GL::Enum::type Gl::FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS(){
    return (unsigned int)(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS);
}

GL::Enum::type Gl::FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT(){
    return (unsigned int)(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT);
}

GL::Enum::type Gl::FRAMEBUFFER_INCOMPLETE_MULTISAMPLE(){
    return (unsigned int)(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE);
}

GL::Enum::type Gl::FRAMEBUFFER_INCOMPLETE_READ_BUFFER(){
    return (unsigned int)(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER);
}

GL::Enum::type Gl::FRAMEBUFFER_RENDERABLE(){
    return (unsigned int)(GL_FRAMEBUFFER_RENDERABLE);
}

GL::Enum::type Gl::FRAMEBUFFER_RENDERABLE_LAYERED(){
    return (unsigned int)(GL_FRAMEBUFFER_RENDERABLE_LAYERED);
}

GL::Enum::type Gl::FRAMEBUFFER_SRGB(){
    return (unsigned int)(GL_FRAMEBUFFER_SRGB);
}

GL::Enum::type Gl::FRAMEBUFFER_UNDEFINED(){
    return (unsigned int)(GL_FRAMEBUFFER_UNDEFINED);
}

GL::Enum::type Gl::FRAMEBUFFER_UNSUPPORTED(){
    return (unsigned int)(GL_FRAMEBUFFER_UNSUPPORTED);
}

GL::Enum::type Gl::FRONT(){
    return (unsigned int)(GL_FRONT);
}

GL::Enum::type Gl::FRONT_AND_BACK(){
    return (unsigned int)(GL_FRONT_AND_BACK);
}

GL::Enum::type Gl::FRONT_FACE(){
    return (unsigned int)(GL_FRONT_FACE);
}

GL::Enum::type Gl::FRONT_LEFT(){
    return (unsigned int)(GL_FRONT_LEFT);
}

GL::Enum::type Gl::FRONT_RIGHT(){
    return (unsigned int)(GL_FRONT_RIGHT);
}

GL::Enum::type Gl::FULL_SUPPORT(){
    return (unsigned int)(GL_FULL_SUPPORT);
}

GL::Enum::type Gl::FUNC_ADD(){
    return (unsigned int)(GL_FUNC_ADD);
}

GL::Enum::type Gl::FUNC_REVERSE_SUBTRACT(){
    return (unsigned int)(GL_FUNC_REVERSE_SUBTRACT);
}

GL::Enum::type Gl::FUNC_SUBTRACT(){
    return (unsigned int)(GL_FUNC_SUBTRACT);
}

GL::Enum::type Gl::GEOMETRY_INPUT_TYPE(){
    return (unsigned int)(GL_GEOMETRY_INPUT_TYPE);
}

GL::Enum::type Gl::GEOMETRY_OUTPUT_TYPE(){
    return (unsigned int)(GL_GEOMETRY_OUTPUT_TYPE);
}

GL::Enum::type Gl::GEOMETRY_SHADER(){
    return (unsigned int)(GL_GEOMETRY_SHADER);
}

GL::Enum::type Gl::GEOMETRY_SHADER_BIT(){
    return (unsigned int)(GL_GEOMETRY_SHADER_BIT);
}

GL::Enum::type Gl::GEOMETRY_SHADER_INVOCATIONS(){
    return (unsigned int)(GL_GEOMETRY_SHADER_INVOCATIONS);
}

GL::Enum::type Gl::GEOMETRY_SHADER_PRIMITIVES_EMITTED(){
    return (unsigned int)(GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED);
}

GL::Enum::type Gl::GEOMETRY_SUBROUTINE(){
    return (unsigned int)(GL_GEOMETRY_SUBROUTINE);
}

GL::Enum::type Gl::GEOMETRY_SUBROUTINE_UNIFORM(){
    return (unsigned int)(GL_GEOMETRY_SUBROUTINE_UNIFORM);
}

GL::Enum::type Gl::GEOMETRY_TEXTURE(){
    return (unsigned int)(GL_GEOMETRY_TEXTURE);
}

GL::Enum::type Gl::GEOMETRY_VERTICES_OUT(){
    return (unsigned int)(GL_GEOMETRY_VERTICES_OUT);
}

GL::Enum::type Gl::GEQUAL(){
    return (unsigned int)(GL_GEQUAL);
}

GL::Enum::type Gl::GET_TEXTURE_IMAGE_FORMAT(){
    return (unsigned int)(GL_GET_TEXTURE_IMAGE_FORMAT);
}

GL::Enum::type Gl::GET_TEXTURE_IMAGE_TYPE(){
    return (unsigned int)(GL_GET_TEXTURE_IMAGE_TYPE);
}

GL::Enum::type Gl::GREATER(){
    return (unsigned int)(GL_GREATER);
}

GL::Enum::type Gl::GREEN(){
    return (unsigned int)(GL_GREEN);
}

GL::Enum::type Gl::GREEN_INTEGER(){
    return (unsigned int)(GL_GREEN_INTEGER);
}

GL::Enum::type Gl::GUILTY_CONTEXT_RESET(){
    return (unsigned int)(GL_GUILTY_CONTEXT_RESET);
}

GL::Enum::type Gl::HALF_FLOAT(){
    return (unsigned int)(GL_HALF_FLOAT);
}

GL::Enum::type Gl::HIGH_FLOAT(){
    return (unsigned int)(GL_HIGH_FLOAT);
}

GL::Enum::type Gl::HIGH_INT(){
    return (unsigned int)(GL_HIGH_INT);
}

GL::Enum::type Gl::IMAGE_1D(){
    return (unsigned int)(GL_IMAGE_1D);
}

GL::Enum::type Gl::IMAGE_1D_ARRAY(){
    return (unsigned int)(GL_IMAGE_1D_ARRAY);
}

GL::Enum::type Gl::IMAGE_2D(){
    return (unsigned int)(GL_IMAGE_2D);
}

GL::Enum::type Gl::IMAGE_2D_ARRAY(){
    return (unsigned int)(GL_IMAGE_2D_ARRAY);
}

GL::Enum::type Gl::IMAGE_2D_MULTISAMPLE(){
    return (unsigned int)(GL_IMAGE_2D_MULTISAMPLE);
}

GL::Enum::type Gl::IMAGE_2D_MULTISAMPLE_ARRAY(){
    return (unsigned int)(GL_IMAGE_2D_MULTISAMPLE_ARRAY);
}

GL::Enum::type Gl::IMAGE_2D_RECT(){
    return (unsigned int)(GL_IMAGE_2D_RECT);
}

GL::Enum::type Gl::IMAGE_3D(){
    return (unsigned int)(GL_IMAGE_3D);
}

GL::Enum::type Gl::IMAGE_BINDING_ACCESS(){
    return (unsigned int)(GL_IMAGE_BINDING_ACCESS);
}

GL::Enum::type Gl::IMAGE_BINDING_FORMAT(){
    return (unsigned int)(GL_IMAGE_BINDING_FORMAT);
}

GL::Enum::type Gl::IMAGE_BINDING_LAYER(){
    return (unsigned int)(GL_IMAGE_BINDING_LAYER);
}

GL::Enum::type Gl::IMAGE_BINDING_LAYERED(){
    return (unsigned int)(GL_IMAGE_BINDING_LAYERED);
}

GL::Enum::type Gl::IMAGE_BINDING_LEVEL(){
    return (unsigned int)(GL_IMAGE_BINDING_LEVEL);
}

GL::Enum::type Gl::IMAGE_BINDING_NAME(){
    return (unsigned int)(GL_IMAGE_BINDING_NAME);
}

GL::Enum::type Gl::IMAGE_BUFFER(){
    return (unsigned int)(GL_IMAGE_BUFFER);
}

GL::Enum::type Gl::IMAGE_CLASS_10_10_10_2(){
    return (unsigned int)(GL_IMAGE_CLASS_10_10_10_2);
}

GL::Enum::type Gl::IMAGE_CLASS_11_11_10(){
    return (unsigned int)(GL_IMAGE_CLASS_11_11_10);
}

GL::Enum::type Gl::IMAGE_CLASS_1_X_16(){
    return (unsigned int)(GL_IMAGE_CLASS_1_X_16);
}

GL::Enum::type Gl::IMAGE_CLASS_1_X_32(){
    return (unsigned int)(GL_IMAGE_CLASS_1_X_32);
}

GL::Enum::type Gl::IMAGE_CLASS_1_X_8(){
    return (unsigned int)(GL_IMAGE_CLASS_1_X_8);
}

GL::Enum::type Gl::IMAGE_CLASS_2_X_16(){
    return (unsigned int)(GL_IMAGE_CLASS_2_X_16);
}

GL::Enum::type Gl::IMAGE_CLASS_2_X_32(){
    return (unsigned int)(GL_IMAGE_CLASS_2_X_32);
}

GL::Enum::type Gl::IMAGE_CLASS_2_X_8(){
    return (unsigned int)(GL_IMAGE_CLASS_2_X_8);
}

GL::Enum::type Gl::IMAGE_CLASS_4_X_16(){
    return (unsigned int)(GL_IMAGE_CLASS_4_X_16);
}

GL::Enum::type Gl::IMAGE_CLASS_4_X_32(){
    return (unsigned int)(GL_IMAGE_CLASS_4_X_32);
}

GL::Enum::type Gl::IMAGE_CLASS_4_X_8(){
    return (unsigned int)(GL_IMAGE_CLASS_4_X_8);
}

GL::Enum::type Gl::IMAGE_COMPATIBILITY_CLASS(){
    return (unsigned int)(GL_IMAGE_COMPATIBILITY_CLASS);
}

GL::Enum::type Gl::IMAGE_CUBE(){
    return (unsigned int)(GL_IMAGE_CUBE);
}

GL::Enum::type Gl::IMAGE_CUBE_MAP_ARRAY(){
    return (unsigned int)(GL_IMAGE_CUBE_MAP_ARRAY);
}

GL::Enum::type Gl::IMAGE_FORMAT_COMPATIBILITY_BY_CLASS(){
    return (unsigned int)(GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS);
}

GL::Enum::type Gl::IMAGE_FORMAT_COMPATIBILITY_BY_SIZE(){
    return (unsigned int)(GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE);
}

GL::Enum::type Gl::IMAGE_FORMAT_COMPATIBILITY_TYPE(){
    return (unsigned int)(GL_IMAGE_FORMAT_COMPATIBILITY_TYPE);
}

GL::Enum::type Gl::IMAGE_PIXEL_FORMAT(){
    return (unsigned int)(GL_IMAGE_PIXEL_FORMAT);
}

GL::Enum::type Gl::IMAGE_PIXEL_TYPE(){
    return (unsigned int)(GL_IMAGE_PIXEL_TYPE);
}

GL::Enum::type Gl::IMAGE_TEXEL_SIZE(){
    return (unsigned int)(GL_IMAGE_TEXEL_SIZE);
}

GL::Enum::type Gl::IMPLEMENTATION_COLOR_READ_FORMAT(){
    return (unsigned int)(GL_IMPLEMENTATION_COLOR_READ_FORMAT);
}

GL::Enum::type Gl::IMPLEMENTATION_COLOR_READ_TYPE(){
    return (unsigned int)(GL_IMPLEMENTATION_COLOR_READ_TYPE);
}

GL::Enum::type Gl::INCR(){
    return (unsigned int)(GL_INCR);
}

GL::Enum::type Gl::INCR_WRAP(){
    return (unsigned int)(GL_INCR_WRAP);
}

GL::Enum::type Gl::INFO_LOG_LENGTH(){
    return (unsigned int)(GL_INFO_LOG_LENGTH);
}

GL::Enum::type Gl::INNOCENT_CONTEXT_RESET(){
    return (unsigned int)(GL_INNOCENT_CONTEXT_RESET);
}

GL::Enum::type Gl::INT(){
    return (unsigned int)(GL_INT);
}

GL::Enum::type Gl::INTERLEAVED_ATTRIBS(){
    return (unsigned int)(GL_INTERLEAVED_ATTRIBS);
}

GL::Enum::type Gl::INTERNALFORMAT_ALPHA_SIZE(){
    return (unsigned int)(GL_INTERNALFORMAT_ALPHA_SIZE);
}

GL::Enum::type Gl::INTERNALFORMAT_ALPHA_TYPE(){
    return (unsigned int)(GL_INTERNALFORMAT_ALPHA_TYPE);
}

GL::Enum::type Gl::INTERNALFORMAT_BLUE_SIZE(){
    return (unsigned int)(GL_INTERNALFORMAT_BLUE_SIZE);
}

GL::Enum::type Gl::INTERNALFORMAT_BLUE_TYPE(){
    return (unsigned int)(GL_INTERNALFORMAT_BLUE_TYPE);
}

GL::Enum::type Gl::INTERNALFORMAT_DEPTH_SIZE(){
    return (unsigned int)(GL_INTERNALFORMAT_DEPTH_SIZE);
}

GL::Enum::type Gl::INTERNALFORMAT_DEPTH_TYPE(){
    return (unsigned int)(GL_INTERNALFORMAT_DEPTH_TYPE);
}

GL::Enum::type Gl::INTERNALFORMAT_GREEN_SIZE(){
    return (unsigned int)(GL_INTERNALFORMAT_GREEN_SIZE);
}

GL::Enum::type Gl::INTERNALFORMAT_GREEN_TYPE(){
    return (unsigned int)(GL_INTERNALFORMAT_GREEN_TYPE);
}

GL::Enum::type Gl::INTERNALFORMAT_PREFERRED(){
    return (unsigned int)(GL_INTERNALFORMAT_PREFERRED);
}

GL::Enum::type Gl::INTERNALFORMAT_RED_SIZE(){
    return (unsigned int)(GL_INTERNALFORMAT_RED_SIZE);
}

GL::Enum::type Gl::INTERNALFORMAT_RED_TYPE(){
    return (unsigned int)(GL_INTERNALFORMAT_RED_TYPE);
}

GL::Enum::type Gl::INTERNALFORMAT_SHARED_SIZE(){
    return (unsigned int)(GL_INTERNALFORMAT_SHARED_SIZE);
}

GL::Enum::type Gl::INTERNALFORMAT_STENCIL_SIZE(){
    return (unsigned int)(GL_INTERNALFORMAT_STENCIL_SIZE);
}

GL::Enum::type Gl::INTERNALFORMAT_STENCIL_TYPE(){
    return (unsigned int)(GL_INTERNALFORMAT_STENCIL_TYPE);
}

GL::Enum::type Gl::INTERNALFORMAT_SUPPORTED(){
    return (unsigned int)(GL_INTERNALFORMAT_SUPPORTED);
}

GL::Enum::type Gl::INT_2_10_10_10_REV(){
    return (unsigned int)(GL_INT_2_10_10_10_REV);
}

GL::Enum::type Gl::INT_IMAGE_1D(){
    return (unsigned int)(GL_INT_IMAGE_1D);
}

GL::Enum::type Gl::INT_IMAGE_1D_ARRAY(){
    return (unsigned int)(GL_INT_IMAGE_1D_ARRAY);
}

GL::Enum::type Gl::INT_IMAGE_2D(){
    return (unsigned int)(GL_INT_IMAGE_2D);
}

GL::Enum::type Gl::INT_IMAGE_2D_ARRAY(){
    return (unsigned int)(GL_INT_IMAGE_2D_ARRAY);
}

GL::Enum::type Gl::INT_IMAGE_2D_MULTISAMPLE(){
    return (unsigned int)(GL_INT_IMAGE_2D_MULTISAMPLE);
}

GL::Enum::type Gl::INT_IMAGE_2D_MULTISAMPLE_ARRAY(){
    return (unsigned int)(GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY);
}

GL::Enum::type Gl::INT_IMAGE_2D_RECT(){
    return (unsigned int)(GL_INT_IMAGE_2D_RECT);
}

GL::Enum::type Gl::INT_IMAGE_3D(){
    return (unsigned int)(GL_INT_IMAGE_3D);
}

GL::Enum::type Gl::INT_IMAGE_BUFFER(){
    return (unsigned int)(GL_INT_IMAGE_BUFFER);
}

GL::Enum::type Gl::INT_IMAGE_CUBE(){
    return (unsigned int)(GL_INT_IMAGE_CUBE);
}

GL::Enum::type Gl::INT_IMAGE_CUBE_MAP_ARRAY(){
    return (unsigned int)(GL_INT_IMAGE_CUBE_MAP_ARRAY);
}

GL::Enum::type Gl::INT_SAMPLER_1D(){
    return (unsigned int)(GL_INT_SAMPLER_1D);
}

GL::Enum::type Gl::INT_SAMPLER_1D_ARRAY(){
    return (unsigned int)(GL_INT_SAMPLER_1D_ARRAY);
}

GL::Enum::type Gl::INT_SAMPLER_2D(){
    return (unsigned int)(GL_INT_SAMPLER_2D);
}

GL::Enum::type Gl::INT_SAMPLER_2D_ARRAY(){
    return (unsigned int)(GL_INT_SAMPLER_2D_ARRAY);
}

GL::Enum::type Gl::INT_SAMPLER_2D_MULTISAMPLE(){
    return (unsigned int)(GL_INT_SAMPLER_2D_MULTISAMPLE);
}

GL::Enum::type Gl::INT_SAMPLER_2D_MULTISAMPLE_ARRAY(){
    return (unsigned int)(GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY);
}

GL::Enum::type Gl::INT_SAMPLER_2D_RECT(){
    return (unsigned int)(GL_INT_SAMPLER_2D_RECT);
}

GL::Enum::type Gl::INT_SAMPLER_3D(){
    return (unsigned int)(GL_INT_SAMPLER_3D);
}

GL::Enum::type Gl::INT_SAMPLER_BUFFER(){
    return (unsigned int)(GL_INT_SAMPLER_BUFFER);
}

GL::Enum::type Gl::INT_SAMPLER_CUBE(){
    return (unsigned int)(GL_INT_SAMPLER_CUBE);
}

GL::Enum::type Gl::INT_SAMPLER_CUBE_MAP_ARRAY(){
    return (unsigned int)(GL_INT_SAMPLER_CUBE_MAP_ARRAY);
}

GL::Enum::type Gl::INT_VEC2(){
    return (unsigned int)(GL_INT_VEC2);
}

GL::Enum::type Gl::INT_VEC3(){
    return (unsigned int)(GL_INT_VEC3);
}

GL::Enum::type Gl::INT_VEC4(){
    return (unsigned int)(GL_INT_VEC4);
}

GL::Enum::type Gl::INVALID_ENUM(){
    return (unsigned int)(GL_INVALID_ENUM);
}

GL::Enum::type Gl::INVALID_FRAMEBUFFER_OPERATION(){
    return (unsigned int)(GL_INVALID_FRAMEBUFFER_OPERATION);
}

GL::Enum::type Gl::INVALID_INDEX(){
    return (unsigned int)(GL_INVALID_INDEX);
}

GL::Enum::type Gl::INVALID_OPERATION(){
    return (unsigned int)(GL_INVALID_OPERATION);
}

GL::Enum::type Gl::INVALID_VALUE(){
    return (unsigned int)(GL_INVALID_VALUE);
}

GL::Enum::type Gl::INVERT(){
    return (unsigned int)(GL_INVERT);
}

GL::Enum::type Gl::ISOLINES(){
    return (unsigned int)(GL_ISOLINES);
}

GL::Enum::type Gl::IS_PER_PATCH(){
    return (unsigned int)(GL_IS_PER_PATCH);
}

GL::Enum::type Gl::IS_ROW_MAJOR(){
    return (unsigned int)(GL_IS_ROW_MAJOR);
}

GL::Enum::type Gl::KEEP(){
    return (unsigned int)(GL_KEEP);
}

GL::Enum::type Gl::LAST_VERTEX_CONVENTION(){
    return (unsigned int)(GL_LAST_VERTEX_CONVENTION);
}

GL::Enum::type Gl::LAYER_PROVOKING_VERTEX(){
    return (unsigned int)(GL_LAYER_PROVOKING_VERTEX);
}

GL::Enum::type Gl::LEFT(){
    return (unsigned int)(GL_LEFT);
}

GL::Enum::type Gl::LEQUAL(){
    return (unsigned int)(GL_LEQUAL);
}

GL::Enum::type Gl::LESS(){
    return (unsigned int)(GL_LESS);
}

GL::Enum::type Gl::LINE(){
    return (unsigned int)(GL_LINE);
}

GL::Enum::type Gl::LINEAR(){
    return (unsigned int)(GL_LINEAR);
}

GL::Enum::type Gl::LINEAR_MIPMAP_LINEAR(){
    return (unsigned int)(GL_LINEAR_MIPMAP_LINEAR);
}

GL::Enum::type Gl::LINEAR_MIPMAP_NEAREST(){
    return (unsigned int)(GL_LINEAR_MIPMAP_NEAREST);
}

GL::Enum::type Gl::LINES(){
    return (unsigned int)(GL_LINES);
}

GL::Enum::type Gl::LINES_ADJACENCY(){
    return (unsigned int)(GL_LINES_ADJACENCY);
}

GL::Enum::type Gl::LINE_LOOP(){
    return (unsigned int)(GL_LINE_LOOP);
}

GL::Enum::type Gl::LINE_SMOOTH(){
    return (unsigned int)(GL_LINE_SMOOTH);
}

GL::Enum::type Gl::LINE_SMOOTH_HINT(){
    return (unsigned int)(GL_LINE_SMOOTH_HINT);
}

GL::Enum::type Gl::LINE_STRIP(){
    return (unsigned int)(GL_LINE_STRIP);
}

GL::Enum::type Gl::LINE_STRIP_ADJACENCY(){
    return (unsigned int)(GL_LINE_STRIP_ADJACENCY);
}

GL::Enum::type Gl::LINE_WIDTH(){
    return (unsigned int)(GL_LINE_WIDTH);
}

GL::Enum::type Gl::LINE_WIDTH_GRANULARITY(){
    return (unsigned int)(GL_LINE_WIDTH_GRANULARITY);
}

GL::Enum::type Gl::LINE_WIDTH_RANGE(){
    return (unsigned int)(GL_LINE_WIDTH_RANGE);
}

GL::Enum::type Gl::LINK_STATUS(){
    return (unsigned int)(GL_LINK_STATUS);
}

GL::Enum::type Gl::LOCATION(){
    return (unsigned int)(GL_LOCATION);
}

GL::Enum::type Gl::LOCATION_COMPONENT(){
    return (unsigned int)(GL_LOCATION_COMPONENT);
}

GL::Enum::type Gl::LOCATION_INDEX(){
    return (unsigned int)(GL_LOCATION_INDEX);
}

GL::Enum::type Gl::LOGIC_OP_MODE(){
    return (unsigned int)(GL_LOGIC_OP_MODE);
}

GL::Enum::type Gl::LOSE_CONTEXT_ON_RESET(){
    return (unsigned int)(GL_LOSE_CONTEXT_ON_RESET);
}

GL::Enum::type Gl::LOWER_LEFT(){
    return (unsigned int)(GL_LOWER_LEFT);
}

GL::Enum::type Gl::LOW_FLOAT(){
    return (unsigned int)(GL_LOW_FLOAT);
}

GL::Enum::type Gl::LOW_INT(){
    return (unsigned int)(GL_LOW_INT);
}

GL::Enum::type Gl::MAJOR_VERSION(){
    return (unsigned int)(GL_MAJOR_VERSION);
}

GL::Enum::type Gl::MANUAL_GENERATE_MIPMAP(){
    return (unsigned int)(GL_MANUAL_GENERATE_MIPMAP);
}

GL::Enum::type Gl::MAP_COHERENT_BIT(){
    return (unsigned int)(GL_MAP_COHERENT_BIT);
}

GL::Enum::type Gl::MAP_FLUSH_EXPLICIT_BIT(){
    return (unsigned int)(GL_MAP_FLUSH_EXPLICIT_BIT);
}

GL::Enum::type Gl::MAP_INVALIDATE_BUFFER_BIT(){
    return (unsigned int)(GL_MAP_INVALIDATE_BUFFER_BIT);
}

GL::Enum::type Gl::MAP_INVALIDATE_RANGE_BIT(){
    return (unsigned int)(GL_MAP_INVALIDATE_RANGE_BIT);
}

GL::Enum::type Gl::MAP_PERSISTENT_BIT(){
    return (unsigned int)(GL_MAP_PERSISTENT_BIT);
}

GL::Enum::type Gl::MAP_READ_BIT(){
    return (unsigned int)(GL_MAP_READ_BIT);
}

GL::Enum::type Gl::MAP_UNSYNCHRONIZED_BIT(){
    return (unsigned int)(GL_MAP_UNSYNCHRONIZED_BIT);
}

GL::Enum::type Gl::MAP_WRITE_BIT(){
    return (unsigned int)(GL_MAP_WRITE_BIT);
}

GL::Enum::type Gl::MATRIX_STRIDE(){
    return (unsigned int)(GL_MATRIX_STRIDE);
}

GL::Enum::type Gl::MAX(){
    return (unsigned int)(GL_MAX);
}

GL::Enum::type Gl::MAX_3D_TEXTURE_SIZE(){
    return (unsigned int)(GL_MAX_3D_TEXTURE_SIZE);
}

GL::Enum::type Gl::MAX_ARRAY_TEXTURE_LAYERS(){
    return (unsigned int)(GL_MAX_ARRAY_TEXTURE_LAYERS);
}

GL::Enum::type Gl::MAX_ATOMIC_COUNTER_BUFFER_BINDINGS(){
    return (unsigned int)(GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS);
}

GL::Enum::type Gl::MAX_ATOMIC_COUNTER_BUFFER_SIZE(){
    return (unsigned int)(GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE);
}

GL::Enum::type Gl::MAX_CLIP_DISTANCES(){
    return (unsigned int)(GL_MAX_CLIP_DISTANCES);
}

GL::Enum::type Gl::MAX_COLOR_ATTACHMENTS(){
    return (unsigned int)(GL_MAX_COLOR_ATTACHMENTS);
}

GL::Enum::type Gl::MAX_COLOR_TEXTURE_SAMPLES(){
    return (unsigned int)(GL_MAX_COLOR_TEXTURE_SAMPLES);
}

GL::Enum::type Gl::MAX_COMBINED_ATOMIC_COUNTERS(){
    return (unsigned int)(GL_MAX_COMBINED_ATOMIC_COUNTERS);
}

GL::Enum::type Gl::MAX_COMBINED_ATOMIC_COUNTER_BUFFERS(){
    return (unsigned int)(GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS);
}

GL::Enum::type Gl::MAX_COMBINED_CLIP_AND_CULL_DISTANCES(){
    return (unsigned int)(GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES);
}

GL::Enum::type Gl::MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS(){
    return (unsigned int)(GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS);
}

GL::Enum::type Gl::MAX_COMBINED_DIMENSIONS(){
    return (unsigned int)(GL_MAX_COMBINED_DIMENSIONS);
}

GL::Enum::type Gl::MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS(){
    return (unsigned int)(GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS);
}

GL::Enum::type Gl::MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS(){
    return (unsigned int)(GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS);
}

GL::Enum::type Gl::MAX_COMBINED_IMAGE_UNIFORMS(){
    return (unsigned int)(GL_MAX_COMBINED_IMAGE_UNIFORMS);
}

GL::Enum::type Gl::MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS(){
    return (unsigned int)(GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS);
}

GL::Enum::type Gl::MAX_COMBINED_SHADER_OUTPUT_RESOURCES(){
    return (unsigned int)(GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES);
}

GL::Enum::type Gl::MAX_COMBINED_SHADER_STORAGE_BLOCKS(){
    return (unsigned int)(GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS);
}

GL::Enum::type Gl::MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS(){
    return (unsigned int)(GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS);
}

GL::Enum::type Gl::MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS(){
    return (unsigned int)(GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS);
}

GL::Enum::type Gl::MAX_COMBINED_TEXTURE_IMAGE_UNITS(){
    return (unsigned int)(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS);
}

GL::Enum::type Gl::MAX_COMBINED_UNIFORM_BLOCKS(){
    return (unsigned int)(GL_MAX_COMBINED_UNIFORM_BLOCKS);
}

GL::Enum::type Gl::MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS(){
    return (unsigned int)(GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS);
}

GL::Enum::type Gl::MAX_COMPUTE_ATOMIC_COUNTERS(){
    return (unsigned int)(GL_MAX_COMPUTE_ATOMIC_COUNTERS);
}

GL::Enum::type Gl::MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS(){
    return (unsigned int)(GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS);
}

GL::Enum::type Gl::MAX_COMPUTE_IMAGE_UNIFORMS(){
    return (unsigned int)(GL_MAX_COMPUTE_IMAGE_UNIFORMS);
}

GL::Enum::type Gl::MAX_COMPUTE_SHADER_STORAGE_BLOCKS(){
    return (unsigned int)(GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS);
}

GL::Enum::type Gl::MAX_COMPUTE_SHARED_MEMORY_SIZE(){
    return (unsigned int)(GL_MAX_COMPUTE_SHARED_MEMORY_SIZE);
}

GL::Enum::type Gl::MAX_COMPUTE_TEXTURE_IMAGE_UNITS(){
    return (unsigned int)(GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS);
}

GL::Enum::type Gl::MAX_COMPUTE_UNIFORM_BLOCKS(){
    return (unsigned int)(GL_MAX_COMPUTE_UNIFORM_BLOCKS);
}

GL::Enum::type Gl::MAX_COMPUTE_UNIFORM_COMPONENTS(){
    return (unsigned int)(GL_MAX_COMPUTE_UNIFORM_COMPONENTS);
}

GL::Enum::type Gl::MAX_COMPUTE_WORK_GROUP_COUNT(){
    return (unsigned int)(GL_MAX_COMPUTE_WORK_GROUP_COUNT);
}

GL::Enum::type Gl::MAX_COMPUTE_WORK_GROUP_INVOCATIONS(){
    return (unsigned int)(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS);
}

GL::Enum::type Gl::MAX_COMPUTE_WORK_GROUP_SIZE(){
    return (unsigned int)(GL_MAX_COMPUTE_WORK_GROUP_SIZE);
}

GL::Enum::type Gl::MAX_CUBE_MAP_TEXTURE_SIZE(){
    return (unsigned int)(GL_MAX_CUBE_MAP_TEXTURE_SIZE);
}

GL::Enum::type Gl::MAX_CULL_DISTANCES(){
    return (unsigned int)(GL_MAX_CULL_DISTANCES);
}

GL::Enum::type Gl::MAX_DEBUG_GROUP_STACK_DEPTH(){
    return (unsigned int)(GL_MAX_DEBUG_GROUP_STACK_DEPTH);
}

GL::Enum::type Gl::MAX_DEBUG_LOGGED_MESSAGES(){
    return (unsigned int)(GL_MAX_DEBUG_LOGGED_MESSAGES);
}

GL::Enum::type Gl::MAX_DEBUG_MESSAGE_LENGTH(){
    return (unsigned int)(GL_MAX_DEBUG_MESSAGE_LENGTH);
}

GL::Enum::type Gl::MAX_DEPTH(){
    return (unsigned int)(GL_MAX_DEPTH);
}

GL::Enum::type Gl::MAX_DEPTH_TEXTURE_SAMPLES(){
    return (unsigned int)(GL_MAX_DEPTH_TEXTURE_SAMPLES);
}

GL::Enum::type Gl::MAX_DRAW_BUFFERS(){
    return (unsigned int)(GL_MAX_DRAW_BUFFERS);
}

GL::Enum::type Gl::MAX_DUAL_SOURCE_DRAW_BUFFERS(){
    return (unsigned int)(GL_MAX_DUAL_SOURCE_DRAW_BUFFERS);
}

GL::Enum::type Gl::MAX_ELEMENTS_INDICES(){
    return (unsigned int)(GL_MAX_ELEMENTS_INDICES);
}

GL::Enum::type Gl::MAX_ELEMENTS_VERTICES(){
    return (unsigned int)(GL_MAX_ELEMENTS_VERTICES);
}

GL::Enum::type Gl::MAX_ELEMENT_INDEX(){
    return (unsigned int)(GL_MAX_ELEMENT_INDEX);
}

GL::Enum::type Gl::MAX_FRAGMENT_ATOMIC_COUNTERS(){
    return (unsigned int)(GL_MAX_FRAGMENT_ATOMIC_COUNTERS);
}

GL::Enum::type Gl::MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS(){
    return (unsigned int)(GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS);
}

GL::Enum::type Gl::MAX_FRAGMENT_IMAGE_UNIFORMS(){
    return (unsigned int)(GL_MAX_FRAGMENT_IMAGE_UNIFORMS);
}

GL::Enum::type Gl::MAX_FRAGMENT_INPUT_COMPONENTS(){
    return (unsigned int)(GL_MAX_FRAGMENT_INPUT_COMPONENTS);
}

GL::Enum::type Gl::MAX_FRAGMENT_INTERPOLATION_OFFSET(){
    return (unsigned int)(GL_MAX_FRAGMENT_INTERPOLATION_OFFSET);
}

GL::Enum::type Gl::MAX_FRAGMENT_SHADER_STORAGE_BLOCKS(){
    return (unsigned int)(GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS);
}

GL::Enum::type Gl::MAX_FRAGMENT_UNIFORM_BLOCKS(){
    return (unsigned int)(GL_MAX_FRAGMENT_UNIFORM_BLOCKS);
}

GL::Enum::type Gl::MAX_FRAGMENT_UNIFORM_COMPONENTS(){
    return (unsigned int)(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS);
}

GL::Enum::type Gl::MAX_FRAGMENT_UNIFORM_VECTORS(){
    return (unsigned int)(GL_MAX_FRAGMENT_UNIFORM_VECTORS);
}

GL::Enum::type Gl::MAX_FRAMEBUFFER_HEIGHT(){
    return (unsigned int)(GL_MAX_FRAMEBUFFER_HEIGHT);
}

GL::Enum::type Gl::MAX_FRAMEBUFFER_LAYERS(){
    return (unsigned int)(GL_MAX_FRAMEBUFFER_LAYERS);
}

GL::Enum::type Gl::MAX_FRAMEBUFFER_SAMPLES(){
    return (unsigned int)(GL_MAX_FRAMEBUFFER_SAMPLES);
}

GL::Enum::type Gl::MAX_FRAMEBUFFER_WIDTH(){
    return (unsigned int)(GL_MAX_FRAMEBUFFER_WIDTH);
}

GL::Enum::type Gl::MAX_GEOMETRY_ATOMIC_COUNTERS(){
    return (unsigned int)(GL_MAX_GEOMETRY_ATOMIC_COUNTERS);
}

GL::Enum::type Gl::MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS(){
    return (unsigned int)(GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS);
}

GL::Enum::type Gl::MAX_GEOMETRY_IMAGE_UNIFORMS(){
    return (unsigned int)(GL_MAX_GEOMETRY_IMAGE_UNIFORMS);
}

GL::Enum::type Gl::MAX_GEOMETRY_INPUT_COMPONENTS(){
    return (unsigned int)(GL_MAX_GEOMETRY_INPUT_COMPONENTS);
}

GL::Enum::type Gl::MAX_GEOMETRY_OUTPUT_COMPONENTS(){
    return (unsigned int)(GL_MAX_GEOMETRY_OUTPUT_COMPONENTS);
}

GL::Enum::type Gl::MAX_GEOMETRY_OUTPUT_VERTICES(){
    return (unsigned int)(GL_MAX_GEOMETRY_OUTPUT_VERTICES);
}

GL::Enum::type Gl::MAX_GEOMETRY_SHADER_INVOCATIONS(){
    return (unsigned int)(GL_MAX_GEOMETRY_SHADER_INVOCATIONS);
}

GL::Enum::type Gl::MAX_GEOMETRY_SHADER_STORAGE_BLOCKS(){
    return (unsigned int)(GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS);
}

GL::Enum::type Gl::MAX_GEOMETRY_TEXTURE_IMAGE_UNITS(){
    return (unsigned int)(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS);
}

GL::Enum::type Gl::MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS(){
    return (unsigned int)(GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS);
}

GL::Enum::type Gl::MAX_GEOMETRY_UNIFORM_BLOCKS(){
    return (unsigned int)(GL_MAX_GEOMETRY_UNIFORM_BLOCKS);
}

GL::Enum::type Gl::MAX_GEOMETRY_UNIFORM_COMPONENTS(){
    return (unsigned int)(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS);
}

GL::Enum::type Gl::MAX_HEIGHT(){
    return (unsigned int)(GL_MAX_HEIGHT);
}

GL::Enum::type Gl::MAX_IMAGE_SAMPLES(){
    return (unsigned int)(GL_MAX_IMAGE_SAMPLES);
}

GL::Enum::type Gl::MAX_IMAGE_UNITS(){
    return (unsigned int)(GL_MAX_IMAGE_UNITS);
}

GL::Enum::type Gl::MAX_INTEGER_SAMPLES(){
    return (unsigned int)(GL_MAX_INTEGER_SAMPLES);
}

GL::Enum::type Gl::MAX_LABEL_LENGTH(){
    return (unsigned int)(GL_MAX_LABEL_LENGTH);
}

GL::Enum::type Gl::MAX_LAYERS(){
    return (unsigned int)(GL_MAX_LAYERS);
}

GL::Enum::type Gl::MAX_NAME_LENGTH(){
    return (unsigned int)(GL_MAX_NAME_LENGTH);
}

GL::Enum::type Gl::MAX_NUM_ACTIVE_VARIABLES(){
    return (unsigned int)(GL_MAX_NUM_ACTIVE_VARIABLES);
}

GL::Enum::type Gl::MAX_NUM_COMPATIBLE_SUBROUTINES(){
    return (unsigned int)(GL_MAX_NUM_COMPATIBLE_SUBROUTINES);
}

GL::Enum::type Gl::MAX_PATCH_VERTICES(){
    return (unsigned int)(GL_MAX_PATCH_VERTICES);
}

GL::Enum::type Gl::MAX_PROGRAM_TEXEL_OFFSET(){
    return (unsigned int)(GL_MAX_PROGRAM_TEXEL_OFFSET);
}

GL::Enum::type Gl::MAX_PROGRAM_TEXTURE_GATHER_OFFSET(){
    return (unsigned int)(GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET);
}

GL::Enum::type Gl::MAX_RECTANGLE_TEXTURE_SIZE(){
    return (unsigned int)(GL_MAX_RECTANGLE_TEXTURE_SIZE);
}

GL::Enum::type Gl::MAX_RENDERBUFFER_SIZE(){
    return (unsigned int)(GL_MAX_RENDERBUFFER_SIZE);
}

GL::Enum::type Gl::MAX_SAMPLES(){
    return (unsigned int)(GL_MAX_SAMPLES);
}

GL::Enum::type Gl::MAX_SAMPLE_MASK_WORDS(){
    return (unsigned int)(GL_MAX_SAMPLE_MASK_WORDS);
}

GL::Enum::type Gl::MAX_SERVER_WAIT_TIMEOUT(){
    return (unsigned int)(GL_MAX_SERVER_WAIT_TIMEOUT);
}

GL::Enum::type Gl::MAX_SHADER_STORAGE_BLOCK_SIZE(){
    return (unsigned int)(GL_MAX_SHADER_STORAGE_BLOCK_SIZE);
}

GL::Enum::type Gl::MAX_SHADER_STORAGE_BUFFER_BINDINGS(){
    return (unsigned int)(GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS);
}

GL::Enum::type Gl::MAX_SUBROUTINES(){
    return (unsigned int)(GL_MAX_SUBROUTINES);
}

GL::Enum::type Gl::MAX_SUBROUTINE_UNIFORM_LOCATIONS(){
    return (unsigned int)(GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS);
}

GL::Enum::type Gl::MAX_TESS_CONTROL_ATOMIC_COUNTERS(){
    return (unsigned int)(GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS);
}

GL::Enum::type Gl::MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS(){
    return (unsigned int)(GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS);
}

GL::Enum::type Gl::MAX_TESS_CONTROL_IMAGE_UNIFORMS(){
    return (unsigned int)(GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS);
}

GL::Enum::type Gl::MAX_TESS_CONTROL_INPUT_COMPONENTS(){
    return (unsigned int)(GL_MAX_TESS_CONTROL_INPUT_COMPONENTS);
}

GL::Enum::type Gl::MAX_TESS_CONTROL_OUTPUT_COMPONENTS(){
    return (unsigned int)(GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS);
}

GL::Enum::type Gl::MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS(){
    return (unsigned int)(GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS);
}

GL::Enum::type Gl::MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS(){
    return (unsigned int)(GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS);
}

GL::Enum::type Gl::MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS(){
    return (unsigned int)(GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS);
}

GL::Enum::type Gl::MAX_TESS_CONTROL_UNIFORM_BLOCKS(){
    return (unsigned int)(GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS);
}

GL::Enum::type Gl::MAX_TESS_CONTROL_UNIFORM_COMPONENTS(){
    return (unsigned int)(GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS);
}

GL::Enum::type Gl::MAX_TESS_EVALUATION_ATOMIC_COUNTERS(){
    return (unsigned int)(GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS);
}

GL::Enum::type Gl::MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS(){
    return (unsigned int)(GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS);
}

GL::Enum::type Gl::MAX_TESS_EVALUATION_IMAGE_UNIFORMS(){
    return (unsigned int)(GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS);
}

GL::Enum::type Gl::MAX_TESS_EVALUATION_INPUT_COMPONENTS(){
    return (unsigned int)(GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS);
}

GL::Enum::type Gl::MAX_TESS_EVALUATION_OUTPUT_COMPONENTS(){
    return (unsigned int)(GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS);
}

GL::Enum::type Gl::MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS(){
    return (unsigned int)(GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS);
}

GL::Enum::type Gl::MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS(){
    return (unsigned int)(GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS);
}

GL::Enum::type Gl::MAX_TESS_EVALUATION_UNIFORM_BLOCKS(){
    return (unsigned int)(GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS);
}

GL::Enum::type Gl::MAX_TESS_EVALUATION_UNIFORM_COMPONENTS(){
    return (unsigned int)(GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS);
}

GL::Enum::type Gl::MAX_TESS_GEN_LEVEL(){
    return (unsigned int)(GL_MAX_TESS_GEN_LEVEL);
}

GL::Enum::type Gl::MAX_TESS_PATCH_COMPONENTS(){
    return (unsigned int)(GL_MAX_TESS_PATCH_COMPONENTS);
}

GL::Enum::type Gl::MAX_TEXTURE_BUFFER_SIZE(){
    return (unsigned int)(GL_MAX_TEXTURE_BUFFER_SIZE);
}

GL::Enum::type Gl::MAX_TEXTURE_IMAGE_UNITS(){
    return (unsigned int)(GL_MAX_TEXTURE_IMAGE_UNITS);
}

GL::Enum::type Gl::MAX_TEXTURE_LOD_BIAS(){
    return (unsigned int)(GL_MAX_TEXTURE_LOD_BIAS);
}

GL::Enum::type Gl::MAX_TEXTURE_MAX_ANISOTROPY(){
    return (unsigned int)(GL_MAX_TEXTURE_MAX_ANISOTROPY);
}

GL::Enum::type Gl::MAX_TEXTURE_SIZE(){
    return (unsigned int)(GL_MAX_TEXTURE_SIZE);
}

GL::Enum::type Gl::MAX_TRANSFORM_FEEDBACK_BUFFERS(){
    return (unsigned int)(GL_MAX_TRANSFORM_FEEDBACK_BUFFERS);
}

GL::Enum::type Gl::MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS(){
    return (unsigned int)(GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS);
}

GL::Enum::type Gl::MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS(){
    return (unsigned int)(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS);
}

GL::Enum::type Gl::MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS(){
    return (unsigned int)(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS);
}

GL::Enum::type Gl::MAX_UNIFORM_BLOCK_SIZE(){
    return (unsigned int)(GL_MAX_UNIFORM_BLOCK_SIZE);
}

GL::Enum::type Gl::MAX_UNIFORM_BUFFER_BINDINGS(){
    return (unsigned int)(GL_MAX_UNIFORM_BUFFER_BINDINGS);
}

GL::Enum::type Gl::MAX_UNIFORM_LOCATIONS(){
    return (unsigned int)(GL_MAX_UNIFORM_LOCATIONS);
}

GL::Enum::type Gl::MAX_VARYING_COMPONENTS(){
    return (unsigned int)(GL_MAX_VARYING_COMPONENTS);
}

GL::Enum::type Gl::MAX_VARYING_FLOATS(){
    return (unsigned int)(GL_MAX_VARYING_FLOATS);
}

GL::Enum::type Gl::MAX_VARYING_VECTORS(){
    return (unsigned int)(GL_MAX_VARYING_VECTORS);
}

GL::Enum::type Gl::MAX_VERTEX_ATOMIC_COUNTERS(){
    return (unsigned int)(GL_MAX_VERTEX_ATOMIC_COUNTERS);
}

GL::Enum::type Gl::MAX_VERTEX_ATOMIC_COUNTER_BUFFERS(){
    return (unsigned int)(GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS);
}

GL::Enum::type Gl::MAX_VERTEX_ATTRIBS(){
    return (unsigned int)(GL_MAX_VERTEX_ATTRIBS);
}

GL::Enum::type Gl::MAX_VERTEX_ATTRIB_BINDINGS(){
    return (unsigned int)(GL_MAX_VERTEX_ATTRIB_BINDINGS);
}

GL::Enum::type Gl::MAX_VERTEX_ATTRIB_RELATIVE_OFFSET(){
    return (unsigned int)(GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET);
}

GL::Enum::type Gl::MAX_VERTEX_ATTRIB_STRIDE(){
    return (unsigned int)(GL_MAX_VERTEX_ATTRIB_STRIDE);
}

GL::Enum::type Gl::MAX_VERTEX_IMAGE_UNIFORMS(){
    return (unsigned int)(GL_MAX_VERTEX_IMAGE_UNIFORMS);
}

GL::Enum::type Gl::MAX_VERTEX_OUTPUT_COMPONENTS(){
    return (unsigned int)(GL_MAX_VERTEX_OUTPUT_COMPONENTS);
}

GL::Enum::type Gl::MAX_VERTEX_SHADER_STORAGE_BLOCKS(){
    return (unsigned int)(GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS);
}

GL::Enum::type Gl::MAX_VERTEX_STREAMS(){
    return (unsigned int)(GL_MAX_VERTEX_STREAMS);
}

GL::Enum::type Gl::MAX_VERTEX_TEXTURE_IMAGE_UNITS(){
    return (unsigned int)(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS);
}

GL::Enum::type Gl::MAX_VERTEX_UNIFORM_BLOCKS(){
    return (unsigned int)(GL_MAX_VERTEX_UNIFORM_BLOCKS);
}

GL::Enum::type Gl::MAX_VERTEX_UNIFORM_COMPONENTS(){
    return (unsigned int)(GL_MAX_VERTEX_UNIFORM_COMPONENTS);
}

GL::Enum::type Gl::MAX_VERTEX_UNIFORM_VECTORS(){
    return (unsigned int)(GL_MAX_VERTEX_UNIFORM_VECTORS);
}

GL::Enum::type Gl::MAX_VIEWPORTS(){
    return (unsigned int)(GL_MAX_VIEWPORTS);
}

GL::Enum::type Gl::MAX_VIEWPORT_DIMS(){
    return (unsigned int)(GL_MAX_VIEWPORT_DIMS);
}

GL::Enum::type Gl::MAX_WIDTH(){
    return (unsigned int)(GL_MAX_WIDTH);
}

GL::Enum::type Gl::MEDIUM_FLOAT(){
    return (unsigned int)(GL_MEDIUM_FLOAT);
}

GL::Enum::type Gl::MEDIUM_INT(){
    return (unsigned int)(GL_MEDIUM_INT);
}

GL::Enum::type Gl::MIN(){
    return (unsigned int)(GL_MIN);
}

GL::Enum::type Gl::MINOR_VERSION(){
    return (unsigned int)(GL_MINOR_VERSION);
}

GL::Enum::type Gl::MIN_FRAGMENT_INTERPOLATION_OFFSET(){
    return (unsigned int)(GL_MIN_FRAGMENT_INTERPOLATION_OFFSET);
}

GL::Enum::type Gl::MIN_MAP_BUFFER_ALIGNMENT(){
    return (unsigned int)(GL_MIN_MAP_BUFFER_ALIGNMENT);
}

GL::Enum::type Gl::MIN_PROGRAM_TEXEL_OFFSET(){
    return (unsigned int)(GL_MIN_PROGRAM_TEXEL_OFFSET);
}

GL::Enum::type Gl::MIN_PROGRAM_TEXTURE_GATHER_OFFSET(){
    return (unsigned int)(GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET);
}

GL::Enum::type Gl::MIN_SAMPLE_SHADING_VALUE(){
    return (unsigned int)(GL_MIN_SAMPLE_SHADING_VALUE);
}

GL::Enum::type Gl::MIPMAP(){
    return (unsigned int)(GL_MIPMAP);
}

GL::Enum::type Gl::MIRRORED_REPEAT(){
    return (unsigned int)(GL_MIRRORED_REPEAT);
}

GL::Enum::type Gl::MIRROR_CLAMP_TO_EDGE(){
    return (unsigned int)(GL_MIRROR_CLAMP_TO_EDGE);
}

GL::Enum::type Gl::MULTISAMPLE(){
    return (unsigned int)(GL_MULTISAMPLE);
}

GL::Enum::type Gl::NAME_LENGTH(){
    return (unsigned int)(GL_NAME_LENGTH);
}

GL::Enum::type Gl::NAND(){
    return (unsigned int)(GL_NAND);
}

GL::Enum::type Gl::NEAREST(){
    return (unsigned int)(GL_NEAREST);
}

GL::Enum::type Gl::NEAREST_MIPMAP_LINEAR(){
    return (unsigned int)(GL_NEAREST_MIPMAP_LINEAR);
}

GL::Enum::type Gl::NEAREST_MIPMAP_NEAREST(){
    return (unsigned int)(GL_NEAREST_MIPMAP_NEAREST);
}

GL::Enum::type Gl::NEGATIVE_ONE_TO_ONE(){
    return (unsigned int)(GL_NEGATIVE_ONE_TO_ONE);
}

GL::Enum::type Gl::NEVER(){
    return (unsigned int)(GL_NEVER);
}

GL::Enum::type Gl::NICEST(){
    return (unsigned int)(GL_NICEST);
}

GL::Enum::type Gl::NONE(){
    return (unsigned int)(GL_NONE);
}

GL::Enum::type Gl::NOOP(){
    return (unsigned int)(GL_NOOP);
}

GL::Enum::type Gl::NOR(){
    return (unsigned int)(GL_NOR);
}

GL::Enum::type Gl::NOTEQUAL(){
    return (unsigned int)(GL_NOTEQUAL);
}

GL::Enum::type Gl::NO_ERROR(){
    return (unsigned int)(GL_NO_ERROR);
}

GL::Enum::type Gl::NO_RESET_NOTIFICATION(){
    return (unsigned int)(GL_NO_RESET_NOTIFICATION);
}

GL::Enum::type Gl::NUM_ACTIVE_VARIABLES(){
    return (unsigned int)(GL_NUM_ACTIVE_VARIABLES);
}

GL::Enum::type Gl::NUM_COMPATIBLE_SUBROUTINES(){
    return (unsigned int)(GL_NUM_COMPATIBLE_SUBROUTINES);
}

GL::Enum::type Gl::NUM_COMPRESSED_TEXTURE_FORMATS(){
    return (unsigned int)(GL_NUM_COMPRESSED_TEXTURE_FORMATS);
}

GL::Enum::type Gl::NUM_EXTENSIONS(){
    return (unsigned int)(GL_NUM_EXTENSIONS);
}

GL::Enum::type Gl::NUM_PROGRAM_BINARY_FORMATS(){
    return (unsigned int)(GL_NUM_PROGRAM_BINARY_FORMATS);
}

GL::Enum::type Gl::NUM_SAMPLE_COUNTS(){
    return (unsigned int)(GL_NUM_SAMPLE_COUNTS);
}

GL::Enum::type Gl::NUM_SHADER_BINARY_FORMATS(){
    return (unsigned int)(GL_NUM_SHADER_BINARY_FORMATS);
}

GL::Enum::type Gl::NUM_SHADING_LANGUAGE_VERSIONS(){
    return (unsigned int)(GL_NUM_SHADING_LANGUAGE_VERSIONS);
}

GL::Enum::type Gl::NUM_SPIR_V_EXTENSIONS(){
    return (unsigned int)(GL_NUM_SPIR_V_EXTENSIONS);
}

GL::Enum::type Gl::OBJECT_TYPE(){
    return (unsigned int)(GL_OBJECT_TYPE);
}

GL::Enum::type Gl::OFFSET(){
    return (unsigned int)(GL_OFFSET);
}

GL::Enum::type Gl::ONE(){
    return (unsigned int)(GL_ONE);
}

GL::Enum::type Gl::ONE_MINUS_CONSTANT_ALPHA(){
    return (unsigned int)(GL_ONE_MINUS_CONSTANT_ALPHA);
}

GL::Enum::type Gl::ONE_MINUS_CONSTANT_COLOR(){
    return (unsigned int)(GL_ONE_MINUS_CONSTANT_COLOR);
}

GL::Enum::type Gl::ONE_MINUS_DST_ALPHA(){
    return (unsigned int)(GL_ONE_MINUS_DST_ALPHA);
}

GL::Enum::type Gl::ONE_MINUS_DST_COLOR(){
    return (unsigned int)(GL_ONE_MINUS_DST_COLOR);
}

GL::Enum::type Gl::ONE_MINUS_SRC1_ALPHA(){
    return (unsigned int)(GL_ONE_MINUS_SRC1_ALPHA);
}

GL::Enum::type Gl::ONE_MINUS_SRC1_COLOR(){
    return (unsigned int)(GL_ONE_MINUS_SRC1_COLOR);
}

GL::Enum::type Gl::ONE_MINUS_SRC_ALPHA(){
    return (unsigned int)(GL_ONE_MINUS_SRC_ALPHA);
}

GL::Enum::type Gl::ONE_MINUS_SRC_COLOR(){
    return (unsigned int)(GL_ONE_MINUS_SRC_COLOR);
}

GL::Enum::type Gl::OR(){
    return (unsigned int)(GL_OR);
}

GL::Enum::type Gl::OR_INVERTED(){
    return (unsigned int)(GL_OR_INVERTED);
}

GL::Enum::type Gl::OR_REVERSE(){
    return (unsigned int)(GL_OR_REVERSE);
}

GL::Enum::type Gl::OUT_OF_MEMORY(){
    return (unsigned int)(GL_OUT_OF_MEMORY);
}

GL::Enum::type Gl::PACK_ALIGNMENT(){
    return (unsigned int)(GL_PACK_ALIGNMENT);
}

GL::Enum::type Gl::PACK_COMPRESSED_BLOCK_DEPTH(){
    return (unsigned int)(GL_PACK_COMPRESSED_BLOCK_DEPTH);
}

GL::Enum::type Gl::PACK_COMPRESSED_BLOCK_HEIGHT(){
    return (unsigned int)(GL_PACK_COMPRESSED_BLOCK_HEIGHT);
}

GL::Enum::type Gl::PACK_COMPRESSED_BLOCK_SIZE(){
    return (unsigned int)(GL_PACK_COMPRESSED_BLOCK_SIZE);
}

GL::Enum::type Gl::PACK_COMPRESSED_BLOCK_WIDTH(){
    return (unsigned int)(GL_PACK_COMPRESSED_BLOCK_WIDTH);
}

GL::Enum::type Gl::PACK_IMAGE_HEIGHT(){
    return (unsigned int)(GL_PACK_IMAGE_HEIGHT);
}

GL::Enum::type Gl::PACK_LSB_FIRST(){
    return (unsigned int)(GL_PACK_LSB_FIRST);
}

GL::Enum::type Gl::PACK_ROW_LENGTH(){
    return (unsigned int)(GL_PACK_ROW_LENGTH);
}

GL::Enum::type Gl::PACK_SKIP_IMAGES(){
    return (unsigned int)(GL_PACK_SKIP_IMAGES);
}

GL::Enum::type Gl::PACK_SKIP_PIXELS(){
    return (unsigned int)(GL_PACK_SKIP_PIXELS);
}

GL::Enum::type Gl::PACK_SKIP_ROWS(){
    return (unsigned int)(GL_PACK_SKIP_ROWS);
}

GL::Enum::type Gl::PACK_SWAP_BYTES(){
    return (unsigned int)(GL_PACK_SWAP_BYTES);
}

GL::Enum::type Gl::PARAMETER_BUFFER(){
    return (unsigned int)(GL_PARAMETER_BUFFER);
}

GL::Enum::type Gl::PARAMETER_BUFFER_BINDING(){
    return (unsigned int)(GL_PARAMETER_BUFFER_BINDING);
}

GL::Enum::type Gl::PATCHES(){
    return (unsigned int)(GL_PATCHES);
}

GL::Enum::type Gl::PATCH_DEFAULT_INNER_LEVEL(){
    return (unsigned int)(GL_PATCH_DEFAULT_INNER_LEVEL);
}

GL::Enum::type Gl::PATCH_DEFAULT_OUTER_LEVEL(){
    return (unsigned int)(GL_PATCH_DEFAULT_OUTER_LEVEL);
}

GL::Enum::type Gl::PATCH_VERTICES(){
    return (unsigned int)(GL_PATCH_VERTICES);
}

GL::Enum::type Gl::PIXEL_BUFFER_BARRIER_BIT(){
    return (unsigned int)(GL_PIXEL_BUFFER_BARRIER_BIT);
}

GL::Enum::type Gl::PIXEL_PACK_BUFFER(){
    return (unsigned int)(GL_PIXEL_PACK_BUFFER);
}

GL::Enum::type Gl::PIXEL_PACK_BUFFER_BINDING(){
    return (unsigned int)(GL_PIXEL_PACK_BUFFER_BINDING);
}

GL::Enum::type Gl::PIXEL_UNPACK_BUFFER(){
    return (unsigned int)(GL_PIXEL_UNPACK_BUFFER);
}

GL::Enum::type Gl::PIXEL_UNPACK_BUFFER_BINDING(){
    return (unsigned int)(GL_PIXEL_UNPACK_BUFFER_BINDING);
}

GL::Enum::type Gl::POINT(){
    return (unsigned int)(GL_POINT);
}

GL::Enum::type Gl::POINTS(){
    return (unsigned int)(GL_POINTS);
}

GL::Enum::type Gl::POINT_FADE_THRESHOLD_SIZE(){
    return (unsigned int)(GL_POINT_FADE_THRESHOLD_SIZE);
}

GL::Enum::type Gl::POINT_SIZE(){
    return (unsigned int)(GL_POINT_SIZE);
}

GL::Enum::type Gl::POINT_SIZE_GRANULARITY(){
    return (unsigned int)(GL_POINT_SIZE_GRANULARITY);
}

GL::Enum::type Gl::POINT_SIZE_RANGE(){
    return (unsigned int)(GL_POINT_SIZE_RANGE);
}

GL::Enum::type Gl::POINT_SPRITE_COORD_ORIGIN(){
    return (unsigned int)(GL_POINT_SPRITE_COORD_ORIGIN);
}

GL::Enum::type Gl::POLYGON_MODE(){
    return (unsigned int)(GL_POLYGON_MODE);
}

GL::Enum::type Gl::POLYGON_OFFSET_CLAMP(){
    return (unsigned int)(GL_POLYGON_OFFSET_CLAMP);
}

GL::Enum::type Gl::POLYGON_OFFSET_FACTOR(){
    return (unsigned int)(GL_POLYGON_OFFSET_FACTOR);
}

GL::Enum::type Gl::POLYGON_OFFSET_FILL(){
    return (unsigned int)(GL_POLYGON_OFFSET_FILL);
}

GL::Enum::type Gl::POLYGON_OFFSET_LINE(){
    return (unsigned int)(GL_POLYGON_OFFSET_LINE);
}

GL::Enum::type Gl::POLYGON_OFFSET_POINT(){
    return (unsigned int)(GL_POLYGON_OFFSET_POINT);
}

GL::Enum::type Gl::POLYGON_OFFSET_UNITS(){
    return (unsigned int)(GL_POLYGON_OFFSET_UNITS);
}

GL::Enum::type Gl::POLYGON_SMOOTH(){
    return (unsigned int)(GL_POLYGON_SMOOTH);
}

GL::Enum::type Gl::POLYGON_SMOOTH_HINT(){
    return (unsigned int)(GL_POLYGON_SMOOTH_HINT);
}

GL::Enum::type Gl::PRIMITIVES_GENERATED(){
    return (unsigned int)(GL_PRIMITIVES_GENERATED);
}

GL::Enum::type Gl::PRIMITIVES_SUBMITTED(){
    return (unsigned int)(GL_PRIMITIVES_SUBMITTED);
}

GL::Enum::type Gl::PRIMITIVE_RESTART(){
    return (unsigned int)(GL_PRIMITIVE_RESTART);
}

GL::Enum::type Gl::PRIMITIVE_RESTART_FIXED_INDEX(){
    return (unsigned int)(GL_PRIMITIVE_RESTART_FIXED_INDEX);
}

GL::Enum::type Gl::PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED(){
    return (unsigned int)(GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED);
}

GL::Enum::type Gl::PRIMITIVE_RESTART_INDEX(){
    return (unsigned int)(GL_PRIMITIVE_RESTART_INDEX);
}

GL::Enum::type Gl::PROGRAM(){
    return (unsigned int)(GL_PROGRAM);
}

GL::Enum::type Gl::PROGRAM_BINARY_FORMATS(){
    return (unsigned int)(GL_PROGRAM_BINARY_FORMATS);
}

GL::Enum::type Gl::PROGRAM_BINARY_LENGTH(){
    return (unsigned int)(GL_PROGRAM_BINARY_LENGTH);
}

GL::Enum::type Gl::PROGRAM_BINARY_RETRIEVABLE_HINT(){
    return (unsigned int)(GL_PROGRAM_BINARY_RETRIEVABLE_HINT);
}

GL::Enum::type Gl::PROGRAM_INPUT(){
    return (unsigned int)(GL_PROGRAM_INPUT);
}

GL::Enum::type Gl::PROGRAM_OUTPUT(){
    return (unsigned int)(GL_PROGRAM_OUTPUT);
}

GL::Enum::type Gl::PROGRAM_PIPELINE(){
    return (unsigned int)(GL_PROGRAM_PIPELINE);
}

GL::Enum::type Gl::PROGRAM_PIPELINE_BINDING(){
    return (unsigned int)(GL_PROGRAM_PIPELINE_BINDING);
}

GL::Enum::type Gl::PROGRAM_POINT_SIZE(){
    return (unsigned int)(GL_PROGRAM_POINT_SIZE);
}

GL::Enum::type Gl::PROGRAM_SEPARABLE(){
    return (unsigned int)(GL_PROGRAM_SEPARABLE);
}

GL::Enum::type Gl::PROVOKING_VERTEX(){
    return (unsigned int)(GL_PROVOKING_VERTEX);
}

GL::Enum::type Gl::PROXY_TEXTURE_1D(){
    return (unsigned int)(GL_PROXY_TEXTURE_1D);
}

GL::Enum::type Gl::PROXY_TEXTURE_1D_ARRAY(){
    return (unsigned int)(GL_PROXY_TEXTURE_1D_ARRAY);
}

GL::Enum::type Gl::PROXY_TEXTURE_2D(){
    return (unsigned int)(GL_PROXY_TEXTURE_2D);
}

GL::Enum::type Gl::PROXY_TEXTURE_2D_ARRAY(){
    return (unsigned int)(GL_PROXY_TEXTURE_2D_ARRAY);
}

GL::Enum::type Gl::PROXY_TEXTURE_2D_MULTISAMPLE(){
    return (unsigned int)(GL_PROXY_TEXTURE_2D_MULTISAMPLE);
}

GL::Enum::type Gl::PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY(){
    return (unsigned int)(GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY);
}

GL::Enum::type Gl::PROXY_TEXTURE_3D(){
    return (unsigned int)(GL_PROXY_TEXTURE_3D);
}

GL::Enum::type Gl::PROXY_TEXTURE_CUBE_MAP(){
    return (unsigned int)(GL_PROXY_TEXTURE_CUBE_MAP);
}

GL::Enum::type Gl::PROXY_TEXTURE_CUBE_MAP_ARRAY(){
    return (unsigned int)(GL_PROXY_TEXTURE_CUBE_MAP_ARRAY);
}

GL::Enum::type Gl::PROXY_TEXTURE_RECTANGLE(){
    return (unsigned int)(GL_PROXY_TEXTURE_RECTANGLE);
}

GL::Enum::type Gl::QUADS(){
    return (unsigned int)(GL_QUADS);
}

GL::Enum::type Gl::QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION(){
    return (unsigned int)(GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION);
}

GL::Enum::type Gl::QUERY(){
    return (unsigned int)(GL_QUERY);
}

GL::Enum::type Gl::QUERY_BUFFER(){
    return (unsigned int)(GL_QUERY_BUFFER);
}

GL::Enum::type Gl::QUERY_BUFFER_BARRIER_BIT(){
    return (unsigned int)(GL_QUERY_BUFFER_BARRIER_BIT);
}

GL::Enum::type Gl::QUERY_BUFFER_BINDING(){
    return (unsigned int)(GL_QUERY_BUFFER_BINDING);
}

GL::Enum::type Gl::QUERY_BY_REGION_NO_WAIT(){
    return (unsigned int)(GL_QUERY_BY_REGION_NO_WAIT);
}

GL::Enum::type Gl::QUERY_BY_REGION_NO_WAIT_INVERTED(){
    return (unsigned int)(GL_QUERY_BY_REGION_NO_WAIT_INVERTED);
}

GL::Enum::type Gl::QUERY_BY_REGION_WAIT(){
    return (unsigned int)(GL_QUERY_BY_REGION_WAIT);
}

GL::Enum::type Gl::QUERY_BY_REGION_WAIT_INVERTED(){
    return (unsigned int)(GL_QUERY_BY_REGION_WAIT_INVERTED);
}

GL::Enum::type Gl::QUERY_COUNTER_BITS(){
    return (unsigned int)(GL_QUERY_COUNTER_BITS);
}

GL::Enum::type Gl::QUERY_NO_WAIT(){
    return (unsigned int)(GL_QUERY_NO_WAIT);
}

GL::Enum::type Gl::QUERY_NO_WAIT_INVERTED(){
    return (unsigned int)(GL_QUERY_NO_WAIT_INVERTED);
}

GL::Enum::type Gl::QUERY_RESULT(){
    return (unsigned int)(GL_QUERY_RESULT);
}

GL::Enum::type Gl::QUERY_RESULT_AVAILABLE(){
    return (unsigned int)(GL_QUERY_RESULT_AVAILABLE);
}

GL::Enum::type Gl::QUERY_RESULT_NO_WAIT(){
    return (unsigned int)(GL_QUERY_RESULT_NO_WAIT);
}

GL::Enum::type Gl::QUERY_TARGET(){
    return (unsigned int)(GL_QUERY_TARGET);
}

GL::Enum::type Gl::QUERY_WAIT(){
    return (unsigned int)(GL_QUERY_WAIT);
}

GL::Enum::type Gl::QUERY_WAIT_INVERTED(){
    return (unsigned int)(GL_QUERY_WAIT_INVERTED);
}

GL::Enum::type Gl::R11F_G11F_B10F(){
    return (unsigned int)(GL_R11F_G11F_B10F);
}

GL::Enum::type Gl::R16(){
    return (unsigned int)(GL_R16);
}

GL::Enum::type Gl::R16F(){
    return (unsigned int)(GL_R16F);
}

GL::Enum::type Gl::R16I(){
    return (unsigned int)(GL_R16I);
}

GL::Enum::type Gl::R16UI(){
    return (unsigned int)(GL_R16UI);
}

GL::Enum::type Gl::R16_SNORM(){
    return (unsigned int)(GL_R16_SNORM);
}

GL::Enum::type Gl::R32F(){
    return (unsigned int)(GL_R32F);
}

GL::Enum::type Gl::R32I(){
    return (unsigned int)(GL_R32I);
}

GL::Enum::type Gl::R32UI(){
    return (unsigned int)(GL_R32UI);
}

GL::Enum::type Gl::R3_G3_B2(){
    return (unsigned int)(GL_R3_G3_B2);
}

GL::Enum::type Gl::R8(){
    return (unsigned int)(GL_R8);
}

GL::Enum::type Gl::R8I(){
    return (unsigned int)(GL_R8I);
}

GL::Enum::type Gl::R8UI(){
    return (unsigned int)(GL_R8UI);
}

GL::Enum::type Gl::R8_SNORM(){
    return (unsigned int)(GL_R8_SNORM);
}

GL::Enum::type Gl::RASTERIZER_DISCARD(){
    return (unsigned int)(GL_RASTERIZER_DISCARD);
}

GL::Enum::type Gl::READ_BUFFER(){
    return (unsigned int)(GL_READ_BUFFER);
}

GL::Enum::type Gl::READ_FRAMEBUFFER(){
    return (unsigned int)(GL_READ_FRAMEBUFFER);
}

GL::Enum::type Gl::READ_FRAMEBUFFER_BINDING(){
    return (unsigned int)(GL_READ_FRAMEBUFFER_BINDING);
}

GL::Enum::type Gl::READ_ONLY(){
    return (unsigned int)(GL_READ_ONLY);
}

GL::Enum::type Gl::READ_PIXELS(){
    return (unsigned int)(GL_READ_PIXELS);
}

GL::Enum::type Gl::READ_PIXELS_FORMAT(){
    return (unsigned int)(GL_READ_PIXELS_FORMAT);
}

GL::Enum::type Gl::READ_PIXELS_TYPE(){
    return (unsigned int)(GL_READ_PIXELS_TYPE);
}

GL::Enum::type Gl::READ_WRITE(){
    return (unsigned int)(GL_READ_WRITE);
}

GL::Enum::type Gl::RED(){
    return (unsigned int)(GL_RED);
}

GL::Enum::type Gl::RED_INTEGER(){
    return (unsigned int)(GL_RED_INTEGER);
}

GL::Enum::type Gl::REFERENCED_BY_COMPUTE_SHADER(){
    return (unsigned int)(GL_REFERENCED_BY_COMPUTE_SHADER);
}

GL::Enum::type Gl::REFERENCED_BY_FRAGMENT_SHADER(){
    return (unsigned int)(GL_REFERENCED_BY_FRAGMENT_SHADER);
}

GL::Enum::type Gl::REFERENCED_BY_GEOMETRY_SHADER(){
    return (unsigned int)(GL_REFERENCED_BY_GEOMETRY_SHADER);
}

GL::Enum::type Gl::REFERENCED_BY_TESS_CONTROL_SHADER(){
    return (unsigned int)(GL_REFERENCED_BY_TESS_CONTROL_SHADER);
}

GL::Enum::type Gl::REFERENCED_BY_TESS_EVALUATION_SHADER(){
    return (unsigned int)(GL_REFERENCED_BY_TESS_EVALUATION_SHADER);
}

GL::Enum::type Gl::REFERENCED_BY_VERTEX_SHADER(){
    return (unsigned int)(GL_REFERENCED_BY_VERTEX_SHADER);
}

GL::Enum::type Gl::RENDERBUFFER(){
    return (unsigned int)(GL_RENDERBUFFER);
}

GL::Enum::type Gl::RENDERBUFFER_ALPHA_SIZE(){
    return (unsigned int)(GL_RENDERBUFFER_ALPHA_SIZE);
}

GL::Enum::type Gl::RENDERBUFFER_BINDING(){
    return (unsigned int)(GL_RENDERBUFFER_BINDING);
}

GL::Enum::type Gl::RENDERBUFFER_BLUE_SIZE(){
    return (unsigned int)(GL_RENDERBUFFER_BLUE_SIZE);
}

GL::Enum::type Gl::RENDERBUFFER_DEPTH_SIZE(){
    return (unsigned int)(GL_RENDERBUFFER_DEPTH_SIZE);
}

GL::Enum::type Gl::RENDERBUFFER_GREEN_SIZE(){
    return (unsigned int)(GL_RENDERBUFFER_GREEN_SIZE);
}

GL::Enum::type Gl::RENDERBUFFER_HEIGHT(){
    return (unsigned int)(GL_RENDERBUFFER_HEIGHT);
}

GL::Enum::type Gl::RENDERBUFFER_INTERNAL_FORMAT(){
    return (unsigned int)(GL_RENDERBUFFER_INTERNAL_FORMAT);
}

GL::Enum::type Gl::RENDERBUFFER_RED_SIZE(){
    return (unsigned int)(GL_RENDERBUFFER_RED_SIZE);
}

GL::Enum::type Gl::RENDERBUFFER_SAMPLES(){
    return (unsigned int)(GL_RENDERBUFFER_SAMPLES);
}

GL::Enum::type Gl::RENDERBUFFER_STENCIL_SIZE(){
    return (unsigned int)(GL_RENDERBUFFER_STENCIL_SIZE);
}

GL::Enum::type Gl::RENDERBUFFER_WIDTH(){
    return (unsigned int)(GL_RENDERBUFFER_WIDTH);
}

GL::Enum::type Gl::RENDERER(){
    return (unsigned int)(GL_RENDERER);
}

GL::Enum::type Gl::REPEAT(){
    return (unsigned int)(GL_REPEAT);
}

GL::Enum::type Gl::REPLACE(){
    return (unsigned int)(GL_REPLACE);
}

GL::Enum::type Gl::RESET_NOTIFICATION_STRATEGY(){
    return (unsigned int)(GL_RESET_NOTIFICATION_STRATEGY);
}

GL::Enum::type Gl::RG(){
    return (unsigned int)(GL_RG);
}

GL::Enum::type Gl::RG16(){
    return (unsigned int)(GL_RG16);
}

GL::Enum::type Gl::RG16F(){
    return (unsigned int)(GL_RG16F);
}

GL::Enum::type Gl::RG16I(){
    return (unsigned int)(GL_RG16I);
}

GL::Enum::type Gl::RG16UI(){
    return (unsigned int)(GL_RG16UI);
}

GL::Enum::type Gl::RG16_SNORM(){
    return (unsigned int)(GL_RG16_SNORM);
}

GL::Enum::type Gl::RG32F(){
    return (unsigned int)(GL_RG32F);
}

GL::Enum::type Gl::RG32I(){
    return (unsigned int)(GL_RG32I);
}

GL::Enum::type Gl::RG32UI(){
    return (unsigned int)(GL_RG32UI);
}

GL::Enum::type Gl::RG8(){
    return (unsigned int)(GL_RG8);
}

GL::Enum::type Gl::RG8I(){
    return (unsigned int)(GL_RG8I);
}

GL::Enum::type Gl::RG8UI(){
    return (unsigned int)(GL_RG8UI);
}

GL::Enum::type Gl::RG8_SNORM(){
    return (unsigned int)(GL_RG8_SNORM);
}

GL::Enum::type Gl::RGB(){
    return (unsigned int)(GL_RGB);
}

GL::Enum::type Gl::RGB10(){
    return (unsigned int)(GL_RGB10);
}

GL::Enum::type Gl::RGB10_A2(){
    return (unsigned int)(GL_RGB10_A2);
}

GL::Enum::type Gl::RGB10_A2UI(){
    return (unsigned int)(GL_RGB10_A2UI);
}

GL::Enum::type Gl::RGB12(){
    return (unsigned int)(GL_RGB12);
}

GL::Enum::type Gl::RGB16(){
    return (unsigned int)(GL_RGB16);
}

GL::Enum::type Gl::RGB16F(){
    return (unsigned int)(GL_RGB16F);
}

GL::Enum::type Gl::RGB16I(){
    return (unsigned int)(GL_RGB16I);
}

GL::Enum::type Gl::RGB16UI(){
    return (unsigned int)(GL_RGB16UI);
}

GL::Enum::type Gl::RGB16_SNORM(){
    return (unsigned int)(GL_RGB16_SNORM);
}

GL::Enum::type Gl::RGB32F(){
    return (unsigned int)(GL_RGB32F);
}

GL::Enum::type Gl::RGB32I(){
    return (unsigned int)(GL_RGB32I);
}

GL::Enum::type Gl::RGB32UI(){
    return (unsigned int)(GL_RGB32UI);
}

GL::Enum::type Gl::RGB4(){
    return (unsigned int)(GL_RGB4);
}

GL::Enum::type Gl::RGB5(){
    return (unsigned int)(GL_RGB5);
}

GL::Enum::type Gl::RGB565(){
    return (unsigned int)(GL_RGB565);
}

GL::Enum::type Gl::RGB5_A1(){
    return (unsigned int)(GL_RGB5_A1);
}

GL::Enum::type Gl::RGB8(){
    return (unsigned int)(GL_RGB8);
}

GL::Enum::type Gl::RGB8I(){
    return (unsigned int)(GL_RGB8I);
}

GL::Enum::type Gl::RGB8UI(){
    return (unsigned int)(GL_RGB8UI);
}

GL::Enum::type Gl::RGB8_SNORM(){
    return (unsigned int)(GL_RGB8_SNORM);
}

GL::Enum::type Gl::RGB9_E5(){
    return (unsigned int)(GL_RGB9_E5);
}

GL::Enum::type Gl::RGBA(){
    return (unsigned int)(GL_RGBA);
}

GL::Enum::type Gl::RGBA12(){
    return (unsigned int)(GL_RGBA12);
}

GL::Enum::type Gl::RGBA16(){
    return (unsigned int)(GL_RGBA16);
}

GL::Enum::type Gl::RGBA16F(){
    return (unsigned int)(GL_RGBA16F);
}

GL::Enum::type Gl::RGBA16I(){
    return (unsigned int)(GL_RGBA16I);
}

GL::Enum::type Gl::RGBA16UI(){
    return (unsigned int)(GL_RGBA16UI);
}

GL::Enum::type Gl::RGBA16_SNORM(){
    return (unsigned int)(GL_RGBA16_SNORM);
}

GL::Enum::type Gl::RGBA2(){
    return (unsigned int)(GL_RGBA2);
}

GL::Enum::type Gl::RGBA32F(){
    return (unsigned int)(GL_RGBA32F);
}

GL::Enum::type Gl::RGBA32I(){
    return (unsigned int)(GL_RGBA32I);
}

GL::Enum::type Gl::RGBA32UI(){
    return (unsigned int)(GL_RGBA32UI);
}

GL::Enum::type Gl::RGBA4(){
    return (unsigned int)(GL_RGBA4);
}

GL::Enum::type Gl::RGBA8(){
    return (unsigned int)(GL_RGBA8);
}

GL::Enum::type Gl::RGBA8I(){
    return (unsigned int)(GL_RGBA8I);
}

GL::Enum::type Gl::RGBA8UI(){
    return (unsigned int)(GL_RGBA8UI);
}

GL::Enum::type Gl::RGBA8_SNORM(){
    return (unsigned int)(GL_RGBA8_SNORM);
}

GL::Enum::type Gl::RGBA_INTEGER(){
    return (unsigned int)(GL_RGBA_INTEGER);
}

GL::Enum::type Gl::RGB_INTEGER(){
    return (unsigned int)(GL_RGB_INTEGER);
}

GL::Enum::type Gl::RG_INTEGER(){
    return (unsigned int)(GL_RG_INTEGER);
}

GL::Enum::type Gl::RIGHT(){
    return (unsigned int)(GL_RIGHT);
}

GL::Enum::type Gl::SAMPLER(){
    return (unsigned int)(GL_SAMPLER);
}

GL::Enum::type Gl::SAMPLER_1D(){
    return (unsigned int)(GL_SAMPLER_1D);
}

GL::Enum::type Gl::SAMPLER_1D_ARRAY(){
    return (unsigned int)(GL_SAMPLER_1D_ARRAY);
}

GL::Enum::type Gl::SAMPLER_1D_ARRAY_SHADOW(){
    return (unsigned int)(GL_SAMPLER_1D_ARRAY_SHADOW);
}

GL::Enum::type Gl::SAMPLER_1D_SHADOW(){
    return (unsigned int)(GL_SAMPLER_1D_SHADOW);
}

GL::Enum::type Gl::SAMPLER_2D(){
    return (unsigned int)(GL_SAMPLER_2D);
}

GL::Enum::type Gl::SAMPLER_2D_ARRAY(){
    return (unsigned int)(GL_SAMPLER_2D_ARRAY);
}

GL::Enum::type Gl::SAMPLER_2D_ARRAY_SHADOW(){
    return (unsigned int)(GL_SAMPLER_2D_ARRAY_SHADOW);
}

GL::Enum::type Gl::SAMPLER_2D_MULTISAMPLE(){
    return (unsigned int)(GL_SAMPLER_2D_MULTISAMPLE);
}

GL::Enum::type Gl::SAMPLER_2D_MULTISAMPLE_ARRAY(){
    return (unsigned int)(GL_SAMPLER_2D_MULTISAMPLE_ARRAY);
}

GL::Enum::type Gl::SAMPLER_2D_RECT(){
    return (unsigned int)(GL_SAMPLER_2D_RECT);
}

GL::Enum::type Gl::SAMPLER_2D_RECT_SHADOW(){
    return (unsigned int)(GL_SAMPLER_2D_RECT_SHADOW);
}

GL::Enum::type Gl::SAMPLER_2D_SHADOW(){
    return (unsigned int)(GL_SAMPLER_2D_SHADOW);
}

GL::Enum::type Gl::SAMPLER_3D(){
    return (unsigned int)(GL_SAMPLER_3D);
}

GL::Enum::type Gl::SAMPLER_BINDING(){
    return (unsigned int)(GL_SAMPLER_BINDING);
}

GL::Enum::type Gl::SAMPLER_BUFFER(){
    return (unsigned int)(GL_SAMPLER_BUFFER);
}

GL::Enum::type Gl::SAMPLER_CUBE(){
    return (unsigned int)(GL_SAMPLER_CUBE);
}

GL::Enum::type Gl::SAMPLER_CUBE_MAP_ARRAY(){
    return (unsigned int)(GL_SAMPLER_CUBE_MAP_ARRAY);
}

GL::Enum::type Gl::SAMPLER_CUBE_MAP_ARRAY_SHADOW(){
    return (unsigned int)(GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW);
}

GL::Enum::type Gl::SAMPLER_CUBE_SHADOW(){
    return (unsigned int)(GL_SAMPLER_CUBE_SHADOW);
}

GL::Enum::type Gl::SAMPLES(){
    return (unsigned int)(GL_SAMPLES);
}

GL::Enum::type Gl::SAMPLES_PASSED(){
    return (unsigned int)(GL_SAMPLES_PASSED);
}

GL::Enum::type Gl::SAMPLE_ALPHA_TO_COVERAGE(){
    return (unsigned int)(GL_SAMPLE_ALPHA_TO_COVERAGE);
}

GL::Enum::type Gl::SAMPLE_ALPHA_TO_ONE(){
    return (unsigned int)(GL_SAMPLE_ALPHA_TO_ONE);
}

GL::Enum::type Gl::SAMPLE_BUFFERS(){
    return (unsigned int)(GL_SAMPLE_BUFFERS);
}

GL::Enum::type Gl::SAMPLE_COVERAGE(){
    return (unsigned int)(GL_SAMPLE_COVERAGE);
}

GL::Enum::type Gl::SAMPLE_COVERAGE_INVERT(){
    return (unsigned int)(GL_SAMPLE_COVERAGE_INVERT);
}

GL::Enum::type Gl::SAMPLE_COVERAGE_VALUE(){
    return (unsigned int)(GL_SAMPLE_COVERAGE_VALUE);
}

GL::Enum::type Gl::SAMPLE_MASK(){
    return (unsigned int)(GL_SAMPLE_MASK);
}

GL::Enum::type Gl::SAMPLE_MASK_VALUE(){
    return (unsigned int)(GL_SAMPLE_MASK_VALUE);
}

GL::Enum::type Gl::SAMPLE_POSITION(){
    return (unsigned int)(GL_SAMPLE_POSITION);
}

GL::Enum::type Gl::SAMPLE_SHADING(){
    return (unsigned int)(GL_SAMPLE_SHADING);
}

GL::Enum::type Gl::SCISSOR_BOX(){
    return (unsigned int)(GL_SCISSOR_BOX);
}

GL::Enum::type Gl::SCISSOR_TEST(){
    return (unsigned int)(GL_SCISSOR_TEST);
}

GL::Enum::type Gl::SEPARATE_ATTRIBS(){
    return (unsigned int)(GL_SEPARATE_ATTRIBS);
}

GL::Enum::type Gl::SET(){
    return (unsigned int)(GL_SET);
}

GL::Enum::type Gl::SHADER(){
    return (unsigned int)(GL_SHADER);
}

GL::Enum::type Gl::SHADER_BINARY_FORMATS(){
    return (unsigned int)(GL_SHADER_BINARY_FORMATS);
}

GL::Enum::type Gl::SHADER_BINARY_FORMAT_SPIR_V(){
    return (unsigned int)(GL_SHADER_BINARY_FORMAT_SPIR_V);
}

GL::Enum::type Gl::SHADER_COMPILER(){
    return (unsigned int)(GL_SHADER_COMPILER);
}

GL::Enum::type Gl::SHADER_IMAGE_ACCESS_BARRIER_BIT(){
    return (unsigned int)(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
}

GL::Enum::type Gl::SHADER_IMAGE_ATOMIC(){
    return (unsigned int)(GL_SHADER_IMAGE_ATOMIC);
}

GL::Enum::type Gl::SHADER_IMAGE_LOAD(){
    return (unsigned int)(GL_SHADER_IMAGE_LOAD);
}

GL::Enum::type Gl::SHADER_IMAGE_STORE(){
    return (unsigned int)(GL_SHADER_IMAGE_STORE);
}

GL::Enum::type Gl::SHADER_SOURCE_LENGTH(){
    return (unsigned int)(GL_SHADER_SOURCE_LENGTH);
}

GL::Enum::type Gl::SHADER_STORAGE_BARRIER_BIT(){
    return (unsigned int)(GL_SHADER_STORAGE_BARRIER_BIT);
}

GL::Enum::type Gl::SHADER_STORAGE_BLOCK(){
    return (unsigned int)(GL_SHADER_STORAGE_BLOCK);
}

GL::Enum::type Gl::SHADER_STORAGE_BUFFER(){
    return (unsigned int)(GL_SHADER_STORAGE_BUFFER);
}

GL::Enum::type Gl::SHADER_STORAGE_BUFFER_BINDING(){
    return (unsigned int)(GL_SHADER_STORAGE_BUFFER_BINDING);
}

GL::Enum::type Gl::SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT(){
    return (unsigned int)(GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT);
}

GL::Enum::type Gl::SHADER_STORAGE_BUFFER_SIZE(){
    return (unsigned int)(GL_SHADER_STORAGE_BUFFER_SIZE);
}

GL::Enum::type Gl::SHADER_STORAGE_BUFFER_START(){
    return (unsigned int)(GL_SHADER_STORAGE_BUFFER_START);
}

GL::Enum::type Gl::SHADER_TYPE(){
    return (unsigned int)(GL_SHADER_TYPE);
}

GL::Enum::type Gl::SHADING_LANGUAGE_VERSION(){
    return (unsigned int)(GL_SHADING_LANGUAGE_VERSION);
}

GL::Enum::type Gl::SHORT(){
    return (unsigned int)(GL_SHORT);
}

GL::Enum::type Gl::SIGNALED(){
    return (unsigned int)(GL_SIGNALED);
}

GL::Enum::type Gl::SIGNED_NORMALIZED(){
    return (unsigned int)(GL_SIGNED_NORMALIZED);
}

GL::Enum::type Gl::SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST(){
    return (unsigned int)(GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST);
}

GL::Enum::type Gl::SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE(){
    return (unsigned int)(GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE);
}

GL::Enum::type Gl::SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST(){
    return (unsigned int)(GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST);
}

GL::Enum::type Gl::SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE(){
    return (unsigned int)(GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE);
}

GL::Enum::type Gl::SMOOTH_LINE_WIDTH_GRANULARITY(){
    return (unsigned int)(GL_SMOOTH_LINE_WIDTH_GRANULARITY);
}

GL::Enum::type Gl::SMOOTH_LINE_WIDTH_RANGE(){
    return (unsigned int)(GL_SMOOTH_LINE_WIDTH_RANGE);
}

GL::Enum::type Gl::SMOOTH_POINT_SIZE_GRANULARITY(){
    return (unsigned int)(GL_SMOOTH_POINT_SIZE_GRANULARITY);
}

GL::Enum::type Gl::SMOOTH_POINT_SIZE_RANGE(){
    return (unsigned int)(GL_SMOOTH_POINT_SIZE_RANGE);
}

GL::Enum::type Gl::SPIR_V_BINARY(){
    return (unsigned int)(GL_SPIR_V_BINARY);
}

GL::Enum::type Gl::SPIR_V_EXTENSIONS(){
    return (unsigned int)(GL_SPIR_V_EXTENSIONS);
}

GL::Enum::type Gl::SRC1_ALPHA(){
    return (unsigned int)(GL_SRC1_ALPHA);
}

GL::Enum::type Gl::SRC1_COLOR(){
    return (unsigned int)(GL_SRC1_COLOR);
}

GL::Enum::type Gl::SRC_ALPHA(){
    return (unsigned int)(GL_SRC_ALPHA);
}

GL::Enum::type Gl::SRC_ALPHA_SATURATE(){
    return (unsigned int)(GL_SRC_ALPHA_SATURATE);
}

GL::Enum::type Gl::SRC_COLOR(){
    return (unsigned int)(GL_SRC_COLOR);
}

GL::Enum::type Gl::SRGB(){
    return (unsigned int)(GL_SRGB);
}

GL::Enum::type Gl::SRGB8(){
    return (unsigned int)(GL_SRGB8);
}

GL::Enum::type Gl::SRGB8_ALPHA8(){
    return (unsigned int)(GL_SRGB8_ALPHA8);
}

GL::Enum::type Gl::SRGB_ALPHA(){
    return (unsigned int)(GL_SRGB_ALPHA);
}

GL::Enum::type Gl::SRGB_READ(){
    return (unsigned int)(GL_SRGB_READ);
}

GL::Enum::type Gl::SRGB_WRITE(){
    return (unsigned int)(GL_SRGB_WRITE);
}

GL::Enum::type Gl::STACK_OVERFLOW(){
    return (unsigned int)(GL_STACK_OVERFLOW);
}

GL::Enum::type Gl::STACK_UNDERFLOW(){
    return (unsigned int)(GL_STACK_UNDERFLOW);
}

GL::Enum::type Gl::STATIC_COPY(){
    return (unsigned int)(GL_STATIC_COPY);
}

GL::Enum::type Gl::STATIC_DRAW(){
    return (unsigned int)(GL_STATIC_DRAW);
}

GL::Enum::type Gl::STATIC_READ(){
    return (unsigned int)(GL_STATIC_READ);
}

GL::Enum::type Gl::STENCIL(){
    return (unsigned int)(GL_STENCIL);
}

GL::Enum::type Gl::STENCIL_ATTACHMENT(){
    return (unsigned int)(GL_STENCIL_ATTACHMENT);
}

GL::Enum::type Gl::STENCIL_BACK_FAIL(){
    return (unsigned int)(GL_STENCIL_BACK_FAIL);
}

GL::Enum::type Gl::STENCIL_BACK_FUNC(){
    return (unsigned int)(GL_STENCIL_BACK_FUNC);
}

GL::Enum::type Gl::STENCIL_BACK_PASS_DEPTH_FAIL(){
    return (unsigned int)(GL_STENCIL_BACK_PASS_DEPTH_FAIL);
}

GL::Enum::type Gl::STENCIL_BACK_PASS_DEPTH_PASS(){
    return (unsigned int)(GL_STENCIL_BACK_PASS_DEPTH_PASS);
}

GL::Enum::type Gl::STENCIL_BACK_REF(){
    return (unsigned int)(GL_STENCIL_BACK_REF);
}

GL::Enum::type Gl::STENCIL_BACK_VALUE_MASK(){
    return (unsigned int)(GL_STENCIL_BACK_VALUE_MASK);
}

GL::Enum::type Gl::STENCIL_BACK_WRITEMASK(){
    return (unsigned int)(GL_STENCIL_BACK_WRITEMASK);
}

GL::Enum::type Gl::STENCIL_BUFFER_BIT(){
    return (unsigned int)(GL_STENCIL_BUFFER_BIT);
}

GL::Enum::type Gl::STENCIL_CLEAR_VALUE(){
    return (unsigned int)(GL_STENCIL_CLEAR_VALUE);
}

GL::Enum::type Gl::STENCIL_COMPONENTS(){
    return (unsigned int)(GL_STENCIL_COMPONENTS);
}

GL::Enum::type Gl::STENCIL_FAIL(){
    return (unsigned int)(GL_STENCIL_FAIL);
}

GL::Enum::type Gl::STENCIL_FUNC(){
    return (unsigned int)(GL_STENCIL_FUNC);
}

GL::Enum::type Gl::STENCIL_INDEX(){
    return (unsigned int)(GL_STENCIL_INDEX);
}

GL::Enum::type Gl::STENCIL_INDEX1(){
    return (unsigned int)(GL_STENCIL_INDEX1);
}

GL::Enum::type Gl::STENCIL_INDEX16(){
    return (unsigned int)(GL_STENCIL_INDEX16);
}

GL::Enum::type Gl::STENCIL_INDEX4(){
    return (unsigned int)(GL_STENCIL_INDEX4);
}

GL::Enum::type Gl::STENCIL_INDEX8(){
    return (unsigned int)(GL_STENCIL_INDEX8);
}

GL::Enum::type Gl::STENCIL_PASS_DEPTH_FAIL(){
    return (unsigned int)(GL_STENCIL_PASS_DEPTH_FAIL);
}

GL::Enum::type Gl::STENCIL_PASS_DEPTH_PASS(){
    return (unsigned int)(GL_STENCIL_PASS_DEPTH_PASS);
}

GL::Enum::type Gl::STENCIL_REF(){
    return (unsigned int)(GL_STENCIL_REF);
}

GL::Enum::type Gl::STENCIL_RENDERABLE(){
    return (unsigned int)(GL_STENCIL_RENDERABLE);
}

GL::Enum::type Gl::STENCIL_TEST(){
    return (unsigned int)(GL_STENCIL_TEST);
}

GL::Enum::type Gl::STENCIL_VALUE_MASK(){
    return (unsigned int)(GL_STENCIL_VALUE_MASK);
}

GL::Enum::type Gl::STENCIL_WRITEMASK(){
    return (unsigned int)(GL_STENCIL_WRITEMASK);
}

GL::Enum::type Gl::STEREO(){
    return (unsigned int)(GL_STEREO);
}

GL::Enum::type Gl::STREAM_COPY(){
    return (unsigned int)(GL_STREAM_COPY);
}

GL::Enum::type Gl::STREAM_DRAW(){
    return (unsigned int)(GL_STREAM_DRAW);
}

GL::Enum::type Gl::STREAM_READ(){
    return (unsigned int)(GL_STREAM_READ);
}

GL::Enum::type Gl::SUBPIXEL_BITS(){
    return (unsigned int)(GL_SUBPIXEL_BITS);
}

GL::Enum::type Gl::SYNC_CONDITION(){
    return (unsigned int)(GL_SYNC_CONDITION);
}

GL::Enum::type Gl::SYNC_FENCE(){
    return (unsigned int)(GL_SYNC_FENCE);
}

GL::Enum::type Gl::SYNC_FLAGS(){
    return (unsigned int)(GL_SYNC_FLAGS);
}

GL::Enum::type Gl::SYNC_FLUSH_COMMANDS_BIT(){
    return (unsigned int)(GL_SYNC_FLUSH_COMMANDS_BIT);
}

GL::Enum::type Gl::SYNC_GPU_COMMANDS_COMPLETE(){
    return (unsigned int)(GL_SYNC_GPU_COMMANDS_COMPLETE);
}

GL::Enum::type Gl::SYNC_STATUS(){
    return (unsigned int)(GL_SYNC_STATUS);
}

GL::Enum::type Gl::TESS_CONTROL_OUTPUT_VERTICES(){
    return (unsigned int)(GL_TESS_CONTROL_OUTPUT_VERTICES);
}

GL::Enum::type Gl::TESS_CONTROL_SHADER(){
    return (unsigned int)(GL_TESS_CONTROL_SHADER);
}

GL::Enum::type Gl::TESS_CONTROL_SHADER_BIT(){
    return (unsigned int)(GL_TESS_CONTROL_SHADER_BIT);
}

GL::Enum::type Gl::TESS_CONTROL_SHADER_PATCHES(){
    return (unsigned int)(GL_TESS_CONTROL_SHADER_PATCHES);
}

GL::Enum::type Gl::TESS_CONTROL_SUBROUTINE(){
    return (unsigned int)(GL_TESS_CONTROL_SUBROUTINE);
}

GL::Enum::type Gl::TESS_CONTROL_SUBROUTINE_UNIFORM(){
    return (unsigned int)(GL_TESS_CONTROL_SUBROUTINE_UNIFORM);
}

GL::Enum::type Gl::TESS_CONTROL_TEXTURE(){
    return (unsigned int)(GL_TESS_CONTROL_TEXTURE);
}

GL::Enum::type Gl::TESS_EVALUATION_SHADER(){
    return (unsigned int)(GL_TESS_EVALUATION_SHADER);
}

GL::Enum::type Gl::TESS_EVALUATION_SHADER_BIT(){
    return (unsigned int)(GL_TESS_EVALUATION_SHADER_BIT);
}

GL::Enum::type Gl::TESS_EVALUATION_SHADER_INVOCATIONS(){
    return (unsigned int)(GL_TESS_EVALUATION_SHADER_INVOCATIONS);
}

GL::Enum::type Gl::TESS_EVALUATION_SUBROUTINE(){
    return (unsigned int)(GL_TESS_EVALUATION_SUBROUTINE);
}

GL::Enum::type Gl::TESS_EVALUATION_SUBROUTINE_UNIFORM(){
    return (unsigned int)(GL_TESS_EVALUATION_SUBROUTINE_UNIFORM);
}

GL::Enum::type Gl::TESS_EVALUATION_TEXTURE(){
    return (unsigned int)(GL_TESS_EVALUATION_TEXTURE);
}

GL::Enum::type Gl::TESS_GEN_MODE(){
    return (unsigned int)(GL_TESS_GEN_MODE);
}

GL::Enum::type Gl::TESS_GEN_POINT_MODE(){
    return (unsigned int)(GL_TESS_GEN_POINT_MODE);
}

GL::Enum::type Gl::TESS_GEN_SPACING(){
    return (unsigned int)(GL_TESS_GEN_SPACING);
}

GL::Enum::type Gl::TESS_GEN_VERTEX_ORDER(){
    return (unsigned int)(GL_TESS_GEN_VERTEX_ORDER);
}

GL::Enum::type Gl::TEXTURE(){
    return (unsigned int)(GL_TEXTURE);
}

GL::Enum::type Gl::TEXTURE0(){
    return (unsigned int)(GL_TEXTURE0);
}

GL::Enum::type Gl::TEXTURE1(){
    return (unsigned int)(GL_TEXTURE1);
}

GL::Enum::type Gl::TEXTURE10(){
    return (unsigned int)(GL_TEXTURE10);
}

GL::Enum::type Gl::TEXTURE11(){
    return (unsigned int)(GL_TEXTURE11);
}

GL::Enum::type Gl::TEXTURE12(){
    return (unsigned int)(GL_TEXTURE12);
}

GL::Enum::type Gl::TEXTURE13(){
    return (unsigned int)(GL_TEXTURE13);
}

GL::Enum::type Gl::TEXTURE14(){
    return (unsigned int)(GL_TEXTURE14);
}

GL::Enum::type Gl::TEXTURE15(){
    return (unsigned int)(GL_TEXTURE15);
}

GL::Enum::type Gl::TEXTURE16(){
    return (unsigned int)(GL_TEXTURE16);
}

GL::Enum::type Gl::TEXTURE17(){
    return (unsigned int)(GL_TEXTURE17);
}

GL::Enum::type Gl::TEXTURE18(){
    return (unsigned int)(GL_TEXTURE18);
}

GL::Enum::type Gl::TEXTURE19(){
    return (unsigned int)(GL_TEXTURE19);
}

GL::Enum::type Gl::TEXTURE2(){
    return (unsigned int)(GL_TEXTURE2);
}

GL::Enum::type Gl::TEXTURE20(){
    return (unsigned int)(GL_TEXTURE20);
}

GL::Enum::type Gl::TEXTURE21(){
    return (unsigned int)(GL_TEXTURE21);
}

GL::Enum::type Gl::TEXTURE22(){
    return (unsigned int)(GL_TEXTURE22);
}

GL::Enum::type Gl::TEXTURE23(){
    return (unsigned int)(GL_TEXTURE23);
}

GL::Enum::type Gl::TEXTURE24(){
    return (unsigned int)(GL_TEXTURE24);
}

GL::Enum::type Gl::TEXTURE25(){
    return (unsigned int)(GL_TEXTURE25);
}

GL::Enum::type Gl::TEXTURE26(){
    return (unsigned int)(GL_TEXTURE26);
}

GL::Enum::type Gl::TEXTURE27(){
    return (unsigned int)(GL_TEXTURE27);
}

GL::Enum::type Gl::TEXTURE28(){
    return (unsigned int)(GL_TEXTURE28);
}

GL::Enum::type Gl::TEXTURE29(){
    return (unsigned int)(GL_TEXTURE29);
}

GL::Enum::type Gl::TEXTURE3(){
    return (unsigned int)(GL_TEXTURE3);
}

GL::Enum::type Gl::TEXTURE30(){
    return (unsigned int)(GL_TEXTURE30);
}

GL::Enum::type Gl::TEXTURE31(){
    return (unsigned int)(GL_TEXTURE31);
}

GL::Enum::type Gl::TEXTURE4(){
    return (unsigned int)(GL_TEXTURE4);
}

GL::Enum::type Gl::TEXTURE5(){
    return (unsigned int)(GL_TEXTURE5);
}

GL::Enum::type Gl::TEXTURE6(){
    return (unsigned int)(GL_TEXTURE6);
}

GL::Enum::type Gl::TEXTURE7(){
    return (unsigned int)(GL_TEXTURE7);
}

GL::Enum::type Gl::TEXTURE8(){
    return (unsigned int)(GL_TEXTURE8);
}

GL::Enum::type Gl::TEXTURE9(){
    return (unsigned int)(GL_TEXTURE9);
}

GL::Enum::type Gl::TEXTURE_1D(){
    return (unsigned int)(GL_TEXTURE_1D);
}

GL::Enum::type Gl::TEXTURE_1D_ARRAY(){
    return (unsigned int)(GL_TEXTURE_1D_ARRAY);
}

GL::Enum::type Gl::TEXTURE_2D(){
    return (unsigned int)(GL_TEXTURE_2D);
}

GL::Enum::type Gl::TEXTURE_2D_ARRAY(){
    return (unsigned int)(GL_TEXTURE_2D_ARRAY);
}

GL::Enum::type Gl::TEXTURE_2D_MULTISAMPLE(){
    return (unsigned int)(GL_TEXTURE_2D_MULTISAMPLE);
}

GL::Enum::type Gl::TEXTURE_2D_MULTISAMPLE_ARRAY(){
    return (unsigned int)(GL_TEXTURE_2D_MULTISAMPLE_ARRAY);
}

GL::Enum::type Gl::TEXTURE_3D(){
    return (unsigned int)(GL_TEXTURE_3D);
}

GL::Enum::type Gl::TEXTURE_ALPHA_SIZE(){
    return (unsigned int)(GL_TEXTURE_ALPHA_SIZE);
}

GL::Enum::type Gl::TEXTURE_ALPHA_TYPE(){
    return (unsigned int)(GL_TEXTURE_ALPHA_TYPE);
}

GL::Enum::type Gl::TEXTURE_BASE_LEVEL(){
    return (unsigned int)(GL_TEXTURE_BASE_LEVEL);
}

GL::Enum::type Gl::TEXTURE_BINDING_1D(){
    return (unsigned int)(GL_TEXTURE_BINDING_1D);
}

GL::Enum::type Gl::TEXTURE_BINDING_1D_ARRAY(){
    return (unsigned int)(GL_TEXTURE_BINDING_1D_ARRAY);
}

GL::Enum::type Gl::TEXTURE_BINDING_2D(){
    return (unsigned int)(GL_TEXTURE_BINDING_2D);
}

GL::Enum::type Gl::TEXTURE_BINDING_2D_ARRAY(){
    return (unsigned int)(GL_TEXTURE_BINDING_2D_ARRAY);
}

GL::Enum::type Gl::TEXTURE_BINDING_2D_MULTISAMPLE(){
    return (unsigned int)(GL_TEXTURE_BINDING_2D_MULTISAMPLE);
}

GL::Enum::type Gl::TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY(){
    return (unsigned int)(GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY);
}

GL::Enum::type Gl::TEXTURE_BINDING_3D(){
    return (unsigned int)(GL_TEXTURE_BINDING_3D);
}

GL::Enum::type Gl::TEXTURE_BINDING_BUFFER(){
    return (unsigned int)(GL_TEXTURE_BINDING_BUFFER);
}

GL::Enum::type Gl::TEXTURE_BINDING_CUBE_MAP(){
    return (unsigned int)(GL_TEXTURE_BINDING_CUBE_MAP);
}

GL::Enum::type Gl::TEXTURE_BINDING_CUBE_MAP_ARRAY(){
    return (unsigned int)(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY);
}

GL::Enum::type Gl::TEXTURE_BINDING_RECTANGLE(){
    return (unsigned int)(GL_TEXTURE_BINDING_RECTANGLE);
}

GL::Enum::type Gl::TEXTURE_BLUE_SIZE(){
    return (unsigned int)(GL_TEXTURE_BLUE_SIZE);
}

GL::Enum::type Gl::TEXTURE_BLUE_TYPE(){
    return (unsigned int)(GL_TEXTURE_BLUE_TYPE);
}

GL::Enum::type Gl::TEXTURE_BORDER_COLOR(){
    return (unsigned int)(GL_TEXTURE_BORDER_COLOR);
}

GL::Enum::type Gl::TEXTURE_BUFFER(){
    return (unsigned int)(GL_TEXTURE_BUFFER);
}

GL::Enum::type Gl::TEXTURE_BUFFER_BINDING(){
    return (unsigned int)(GL_TEXTURE_BUFFER_BINDING);
}

GL::Enum::type Gl::TEXTURE_BUFFER_DATA_STORE_BINDING(){
    return (unsigned int)(GL_TEXTURE_BUFFER_DATA_STORE_BINDING);
}

GL::Enum::type Gl::TEXTURE_BUFFER_OFFSET(){
    return (unsigned int)(GL_TEXTURE_BUFFER_OFFSET);
}

GL::Enum::type Gl::TEXTURE_BUFFER_OFFSET_ALIGNMENT(){
    return (unsigned int)(GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT);
}

GL::Enum::type Gl::TEXTURE_BUFFER_SIZE(){
    return (unsigned int)(GL_TEXTURE_BUFFER_SIZE);
}

GL::Enum::type Gl::TEXTURE_COMPARE_FUNC(){
    return (unsigned int)(GL_TEXTURE_COMPARE_FUNC);
}

GL::Enum::type Gl::TEXTURE_COMPARE_MODE(){
    return (unsigned int)(GL_TEXTURE_COMPARE_MODE);
}

GL::Enum::type Gl::TEXTURE_COMPRESSED(){
    return (unsigned int)(GL_TEXTURE_COMPRESSED);
}

GL::Enum::type Gl::TEXTURE_COMPRESSED_BLOCK_HEIGHT(){
    return (unsigned int)(GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT);
}

GL::Enum::type Gl::TEXTURE_COMPRESSED_BLOCK_SIZE(){
    return (unsigned int)(GL_TEXTURE_COMPRESSED_BLOCK_SIZE);
}

GL::Enum::type Gl::TEXTURE_COMPRESSED_BLOCK_WIDTH(){
    return (unsigned int)(GL_TEXTURE_COMPRESSED_BLOCK_WIDTH);
}

GL::Enum::type Gl::TEXTURE_COMPRESSED_IMAGE_SIZE(){
    return (unsigned int)(GL_TEXTURE_COMPRESSED_IMAGE_SIZE);
}

GL::Enum::type Gl::TEXTURE_COMPRESSION_HINT(){
    return (unsigned int)(GL_TEXTURE_COMPRESSION_HINT);
}

GL::Enum::type Gl::TEXTURE_CUBE_MAP(){
    return (unsigned int)(GL_TEXTURE_CUBE_MAP);
}

GL::Enum::type Gl::TEXTURE_CUBE_MAP_ARRAY(){
    return (unsigned int)(GL_TEXTURE_CUBE_MAP_ARRAY);
}

GL::Enum::type Gl::TEXTURE_CUBE_MAP_NEGATIVE_X(){
    return (unsigned int)(GL_TEXTURE_CUBE_MAP_NEGATIVE_X);
}

GL::Enum::type Gl::TEXTURE_CUBE_MAP_NEGATIVE_Y(){
    return (unsigned int)(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y);
}

GL::Enum::type Gl::TEXTURE_CUBE_MAP_NEGATIVE_Z(){
    return (unsigned int)(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z);
}

GL::Enum::type Gl::TEXTURE_CUBE_MAP_POSITIVE_X(){
    return (unsigned int)(GL_TEXTURE_CUBE_MAP_POSITIVE_X);
}

GL::Enum::type Gl::TEXTURE_CUBE_MAP_POSITIVE_Y(){
    return (unsigned int)(GL_TEXTURE_CUBE_MAP_POSITIVE_Y);
}

GL::Enum::type Gl::TEXTURE_CUBE_MAP_POSITIVE_Z(){
    return (unsigned int)(GL_TEXTURE_CUBE_MAP_POSITIVE_Z);
}

GL::Enum::type Gl::TEXTURE_CUBE_MAP_SEAMLESS(){
    return (unsigned int)(GL_TEXTURE_CUBE_MAP_SEAMLESS);
}

GL::Enum::type Gl::TEXTURE_DEPTH(){
    return (unsigned int)(GL_TEXTURE_DEPTH);
}

GL::Enum::type Gl::TEXTURE_DEPTH_SIZE(){
    return (unsigned int)(GL_TEXTURE_DEPTH_SIZE);
}

GL::Enum::type Gl::TEXTURE_DEPTH_TYPE(){
    return (unsigned int)(GL_TEXTURE_DEPTH_TYPE);
}

GL::Enum::type Gl::TEXTURE_FETCH_BARRIER_BIT(){
    return (unsigned int)(GL_TEXTURE_FETCH_BARRIER_BIT);
}

GL::Enum::type Gl::TEXTURE_FIXED_SAMPLE_LOCATIONS(){
    return (unsigned int)(GL_TEXTURE_FIXED_SAMPLE_LOCATIONS);
}

GL::Enum::type Gl::TEXTURE_GATHER(){
    return (unsigned int)(GL_TEXTURE_GATHER);
}

GL::Enum::type Gl::TEXTURE_GATHER_SHADOW(){
    return (unsigned int)(GL_TEXTURE_GATHER_SHADOW);
}

GL::Enum::type Gl::TEXTURE_GREEN_SIZE(){
    return (unsigned int)(GL_TEXTURE_GREEN_SIZE);
}

GL::Enum::type Gl::TEXTURE_GREEN_TYPE(){
    return (unsigned int)(GL_TEXTURE_GREEN_TYPE);
}

GL::Enum::type Gl::TEXTURE_HEIGHT(){
    return (unsigned int)(GL_TEXTURE_HEIGHT);
}

GL::Enum::type Gl::TEXTURE_IMAGE_FORMAT(){
    return (unsigned int)(GL_TEXTURE_IMAGE_FORMAT);
}

GL::Enum::type Gl::TEXTURE_IMAGE_TYPE(){
    return (unsigned int)(GL_TEXTURE_IMAGE_TYPE);
}

GL::Enum::type Gl::TEXTURE_IMMUTABLE_FORMAT(){
    return (unsigned int)(GL_TEXTURE_IMMUTABLE_FORMAT);
}

GL::Enum::type Gl::TEXTURE_IMMUTABLE_LEVELS(){
    return (unsigned int)(GL_TEXTURE_IMMUTABLE_LEVELS);
}

GL::Enum::type Gl::TEXTURE_INTERNAL_FORMAT(){
    return (unsigned int)(GL_TEXTURE_INTERNAL_FORMAT);
}

GL::Enum::type Gl::TEXTURE_LOD_BIAS(){
    return (unsigned int)(GL_TEXTURE_LOD_BIAS);
}

GL::Enum::type Gl::TEXTURE_MAG_FILTER(){
    return (unsigned int)(GL_TEXTURE_MAG_FILTER);
}

GL::Enum::type Gl::TEXTURE_MAX_ANISOTROPY(){
    return (unsigned int)(GL_TEXTURE_MAX_ANISOTROPY);
}

GL::Enum::type Gl::TEXTURE_MAX_LEVEL(){
    return (unsigned int)(GL_TEXTURE_MAX_LEVEL);
}

GL::Enum::type Gl::TEXTURE_MAX_LOD(){
    return (unsigned int)(GL_TEXTURE_MAX_LOD);
}

GL::Enum::type Gl::TEXTURE_MIN_FILTER(){
    return (unsigned int)(GL_TEXTURE_MIN_FILTER);
}

GL::Enum::type Gl::TEXTURE_MIN_LOD(){
    return (unsigned int)(GL_TEXTURE_MIN_LOD);
}

GL::Enum::type Gl::TEXTURE_RECTANGLE(){
    return (unsigned int)(GL_TEXTURE_RECTANGLE);
}

GL::Enum::type Gl::TEXTURE_RED_SIZE(){
    return (unsigned int)(GL_TEXTURE_RED_SIZE);
}

GL::Enum::type Gl::TEXTURE_RED_TYPE(){
    return (unsigned int)(GL_TEXTURE_RED_TYPE);
}

GL::Enum::type Gl::TEXTURE_SAMPLES(){
    return (unsigned int)(GL_TEXTURE_SAMPLES);
}

GL::Enum::type Gl::TEXTURE_SHADOW(){
    return (unsigned int)(GL_TEXTURE_SHADOW);
}

GL::Enum::type Gl::TEXTURE_SHARED_SIZE(){
    return (unsigned int)(GL_TEXTURE_SHARED_SIZE);
}

GL::Enum::type Gl::TEXTURE_STENCIL_SIZE(){
    return (unsigned int)(GL_TEXTURE_STENCIL_SIZE);
}

GL::Enum::type Gl::TEXTURE_SWIZZLE_A(){
    return (unsigned int)(GL_TEXTURE_SWIZZLE_A);
}

GL::Enum::type Gl::TEXTURE_SWIZZLE_B(){
    return (unsigned int)(GL_TEXTURE_SWIZZLE_B);
}

GL::Enum::type Gl::TEXTURE_SWIZZLE_G(){
    return (unsigned int)(GL_TEXTURE_SWIZZLE_G);
}

GL::Enum::type Gl::TEXTURE_SWIZZLE_R(){
    return (unsigned int)(GL_TEXTURE_SWIZZLE_R);
}

GL::Enum::type Gl::TEXTURE_SWIZZLE_RGBA(){
    return (unsigned int)(GL_TEXTURE_SWIZZLE_RGBA);
}

GL::Enum::type Gl::TEXTURE_TARGET(){
    return (unsigned int)(GL_TEXTURE_TARGET);
}

GL::Enum::type Gl::TEXTURE_UPDATE_BARRIER_BIT(){
    return (unsigned int)(GL_TEXTURE_UPDATE_BARRIER_BIT);
}

GL::Enum::type Gl::TEXTURE_VIEW(){
    return (unsigned int)(GL_TEXTURE_VIEW);
}

GL::Enum::type Gl::TEXTURE_VIEW_MIN_LAYER(){
    return (unsigned int)(GL_TEXTURE_VIEW_MIN_LAYER);
}

GL::Enum::type Gl::TEXTURE_VIEW_MIN_LEVEL(){
    return (unsigned int)(GL_TEXTURE_VIEW_MIN_LEVEL);
}

GL::Enum::type Gl::TEXTURE_VIEW_NUM_LAYERS(){
    return (unsigned int)(GL_TEXTURE_VIEW_NUM_LAYERS);
}

GL::Enum::type Gl::TEXTURE_VIEW_NUM_LEVELS(){
    return (unsigned int)(GL_TEXTURE_VIEW_NUM_LEVELS);
}

GL::Enum::type Gl::TEXTURE_WIDTH(){
    return (unsigned int)(GL_TEXTURE_WIDTH);
}

GL::Enum::type Gl::TEXTURE_WRAP_R(){
    return (unsigned int)(GL_TEXTURE_WRAP_R);
}

GL::Enum::type Gl::TEXTURE_WRAP_S(){
    return (unsigned int)(GL_TEXTURE_WRAP_S);
}

GL::Enum::type Gl::TEXTURE_WRAP_T(){
    return (unsigned int)(GL_TEXTURE_WRAP_T);
}

GL::Enum::type Gl::TIMEOUT_EXPIRED(){
    return (unsigned int)(GL_TIMEOUT_EXPIRED);
}

GL::Enum::type Gl::TIMEOUT_IGNORED(){
    return (unsigned int)(GL_TIMEOUT_IGNORED);
}

GL::Enum::type Gl::TIMESTAMP(){
    return (unsigned int)(GL_TIMESTAMP);
}

GL::Enum::type Gl::TIME_ELAPSED(){
    return (unsigned int)(GL_TIME_ELAPSED);
}

GL::Enum::type Gl::TOP_LEVEL_ARRAY_SIZE(){
    return (unsigned int)(GL_TOP_LEVEL_ARRAY_SIZE);
}

GL::Enum::type Gl::TOP_LEVEL_ARRAY_STRIDE(){
    return (unsigned int)(GL_TOP_LEVEL_ARRAY_STRIDE);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_ACTIVE(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_ACTIVE);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_BARRIER_BIT(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_BARRIER_BIT);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_BINDING(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_BINDING);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_BUFFER(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_BUFFER);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_BUFFER_ACTIVE(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_BUFFER_BINDING(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_BUFFER_INDEX(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_BUFFER_INDEX);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_BUFFER_MODE(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_BUFFER_MODE);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_BUFFER_PAUSED(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_BUFFER_SIZE(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_BUFFER_SIZE);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_BUFFER_START(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_BUFFER_START);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_BUFFER_STRIDE(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_OVERFLOW(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_OVERFLOW);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_PAUSED(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_PAUSED);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_STREAM_OVERFLOW(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_VARYING(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_VARYING);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_VARYINGS(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_VARYINGS);
}

GL::Enum::type Gl::TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH(){
    return (unsigned int)(GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH);
}

GL::Enum::type Gl::TRIANGLES(){
    return (unsigned int)(GL_TRIANGLES);
}

GL::Enum::type Gl::TRIANGLES_ADJACENCY(){
    return (unsigned int)(GL_TRIANGLES_ADJACENCY);
}

GL::Enum::type Gl::TRIANGLE_FAN(){
    return (unsigned int)(GL_TRIANGLE_FAN);
}

GL::Enum::type Gl::TRIANGLE_STRIP(){
    return (unsigned int)(GL_TRIANGLE_STRIP);
}

GL::Enum::type Gl::TRIANGLE_STRIP_ADJACENCY(){
    return (unsigned int)(GL_TRIANGLE_STRIP_ADJACENCY);
}

GL::Enum::type Gl::TRUE(){
    return (unsigned int)(GL_TRUE);
}

GL::Enum::type Gl::TYPE(){
    return (unsigned int)(GL_TYPE);
}

GL::Enum::type Gl::UNDEFINED_VERTEX(){
    return (unsigned int)(GL_UNDEFINED_VERTEX);
}

GL::Enum::type Gl::UNIFORM(){
    return (unsigned int)(GL_UNIFORM);
}

GL::Enum::type Gl::UNIFORM_ARRAY_STRIDE(){
    return (unsigned int)(GL_UNIFORM_ARRAY_STRIDE);
}

GL::Enum::type Gl::UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX(){
    return (unsigned int)(GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX);
}

GL::Enum::type Gl::UNIFORM_BARRIER_BIT(){
    return (unsigned int)(GL_UNIFORM_BARRIER_BIT);
}

GL::Enum::type Gl::UNIFORM_BLOCK(){
    return (unsigned int)(GL_UNIFORM_BLOCK);
}

GL::Enum::type Gl::UNIFORM_BLOCK_ACTIVE_UNIFORMS(){
    return (unsigned int)(GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS);
}

GL::Enum::type Gl::UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES(){
    return (unsigned int)(GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES);
}

GL::Enum::type Gl::UNIFORM_BLOCK_BINDING(){
    return (unsigned int)(GL_UNIFORM_BLOCK_BINDING);
}

GL::Enum::type Gl::UNIFORM_BLOCK_DATA_SIZE(){
    return (unsigned int)(GL_UNIFORM_BLOCK_DATA_SIZE);
}

GL::Enum::type Gl::UNIFORM_BLOCK_INDEX(){
    return (unsigned int)(GL_UNIFORM_BLOCK_INDEX);
}

GL::Enum::type Gl::UNIFORM_BLOCK_NAME_LENGTH(){
    return (unsigned int)(GL_UNIFORM_BLOCK_NAME_LENGTH);
}

GL::Enum::type Gl::UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER(){
    return (unsigned int)(GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER);
}

GL::Enum::type Gl::UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER(){
    return (unsigned int)(GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER);
}

GL::Enum::type Gl::UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER(){
    return (unsigned int)(GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER);
}

GL::Enum::type Gl::UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER(){
    return (unsigned int)(GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER);
}

GL::Enum::type Gl::UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER(){
    return (unsigned int)(GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER);
}

GL::Enum::type Gl::UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER(){
    return (unsigned int)(GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER);
}

GL::Enum::type Gl::UNIFORM_BUFFER(){
    return (unsigned int)(GL_UNIFORM_BUFFER);
}

GL::Enum::type Gl::UNIFORM_BUFFER_BINDING(){
    return (unsigned int)(GL_UNIFORM_BUFFER_BINDING);
}

GL::Enum::type Gl::UNIFORM_BUFFER_OFFSET_ALIGNMENT(){
    return (unsigned int)(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT);
}

GL::Enum::type Gl::UNIFORM_BUFFER_SIZE(){
    return (unsigned int)(GL_UNIFORM_BUFFER_SIZE);
}

GL::Enum::type Gl::UNIFORM_BUFFER_START(){
    return (unsigned int)(GL_UNIFORM_BUFFER_START);
}

GL::Enum::type Gl::UNIFORM_IS_ROW_MAJOR(){
    return (unsigned int)(GL_UNIFORM_IS_ROW_MAJOR);
}

GL::Enum::type Gl::UNIFORM_MATRIX_STRIDE(){
    return (unsigned int)(GL_UNIFORM_MATRIX_STRIDE);
}

GL::Enum::type Gl::UNIFORM_NAME_LENGTH(){
    return (unsigned int)(GL_UNIFORM_NAME_LENGTH);
}

GL::Enum::type Gl::UNIFORM_OFFSET(){
    return (unsigned int)(GL_UNIFORM_OFFSET);
}

GL::Enum::type Gl::UNIFORM_SIZE(){
    return (unsigned int)(GL_UNIFORM_SIZE);
}

GL::Enum::type Gl::UNIFORM_TYPE(){
    return (unsigned int)(GL_UNIFORM_TYPE);
}

GL::Enum::type Gl::UNKNOWN_CONTEXT_RESET(){
    return (unsigned int)(GL_UNKNOWN_CONTEXT_RESET);
}

GL::Enum::type Gl::UNPACK_ALIGNMENT(){
    return (unsigned int)(GL_UNPACK_ALIGNMENT);
}

GL::Enum::type Gl::UNPACK_COMPRESSED_BLOCK_DEPTH(){
    return (unsigned int)(GL_UNPACK_COMPRESSED_BLOCK_DEPTH);
}

GL::Enum::type Gl::UNPACK_COMPRESSED_BLOCK_HEIGHT(){
    return (unsigned int)(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT);
}

GL::Enum::type Gl::UNPACK_COMPRESSED_BLOCK_SIZE(){
    return (unsigned int)(GL_UNPACK_COMPRESSED_BLOCK_SIZE);
}

GL::Enum::type Gl::UNPACK_COMPRESSED_BLOCK_WIDTH(){
    return (unsigned int)(GL_UNPACK_COMPRESSED_BLOCK_WIDTH);
}

GL::Enum::type Gl::UNPACK_IMAGE_HEIGHT(){
    return (unsigned int)(GL_UNPACK_IMAGE_HEIGHT);
}

GL::Enum::type Gl::UNPACK_LSB_FIRST(){
    return (unsigned int)(GL_UNPACK_LSB_FIRST);
}

GL::Enum::type Gl::UNPACK_ROW_LENGTH(){
    return (unsigned int)(GL_UNPACK_ROW_LENGTH);
}

GL::Enum::type Gl::UNPACK_SKIP_IMAGES(){
    return (unsigned int)(GL_UNPACK_SKIP_IMAGES);
}

GL::Enum::type Gl::UNPACK_SKIP_PIXELS(){
    return (unsigned int)(GL_UNPACK_SKIP_PIXELS);
}

GL::Enum::type Gl::UNPACK_SKIP_ROWS(){
    return (unsigned int)(GL_UNPACK_SKIP_ROWS);
}

GL::Enum::type Gl::UNPACK_SWAP_BYTES(){
    return (unsigned int)(GL_UNPACK_SWAP_BYTES);
}

GL::Enum::type Gl::UNSIGNALED(){
    return (unsigned int)(GL_UNSIGNALED);
}

GL::Enum::type Gl::UNSIGNED_BYTE(){
    return (unsigned int)(GL_UNSIGNED_BYTE);
}

GL::Enum::type Gl::UNSIGNED_BYTE_2_3_3_REV(){
    return (unsigned int)(GL_UNSIGNED_BYTE_2_3_3_REV);
}

GL::Enum::type Gl::UNSIGNED_BYTE_3_3_2(){
    return (unsigned int)(GL_UNSIGNED_BYTE_3_3_2);
}

GL::Enum::type Gl::UNSIGNED_INT(){
    return (unsigned int)(GL_UNSIGNED_INT);
}

GL::Enum::type Gl::UNSIGNED_INT_10F_11F_11F_REV(){
    return (unsigned int)(GL_UNSIGNED_INT_10F_11F_11F_REV);
}

GL::Enum::type Gl::UNSIGNED_INT_10_10_10_2(){
    return (unsigned int)(GL_UNSIGNED_INT_10_10_10_2);
}

GL::Enum::type Gl::UNSIGNED_INT_24_8(){
    return (unsigned int)(GL_UNSIGNED_INT_24_8);
}

GL::Enum::type Gl::UNSIGNED_INT_2_10_10_10_REV(){
    return (unsigned int)(GL_UNSIGNED_INT_2_10_10_10_REV);
}

GL::Enum::type Gl::UNSIGNED_INT_5_9_9_9_REV(){
    return (unsigned int)(GL_UNSIGNED_INT_5_9_9_9_REV);
}

GL::Enum::type Gl::UNSIGNED_INT_8_8_8_8(){
    return (unsigned int)(GL_UNSIGNED_INT_8_8_8_8);
}

GL::Enum::type Gl::UNSIGNED_INT_8_8_8_8_REV(){
    return (unsigned int)(GL_UNSIGNED_INT_8_8_8_8_REV);
}

GL::Enum::type Gl::UNSIGNED_INT_ATOMIC_COUNTER(){
    return (unsigned int)(GL_UNSIGNED_INT_ATOMIC_COUNTER);
}

GL::Enum::type Gl::UNSIGNED_INT_IMAGE_1D(){
    return (unsigned int)(GL_UNSIGNED_INT_IMAGE_1D);
}

GL::Enum::type Gl::UNSIGNED_INT_IMAGE_1D_ARRAY(){
    return (unsigned int)(GL_UNSIGNED_INT_IMAGE_1D_ARRAY);
}

GL::Enum::type Gl::UNSIGNED_INT_IMAGE_2D(){
    return (unsigned int)(GL_UNSIGNED_INT_IMAGE_2D);
}

GL::Enum::type Gl::UNSIGNED_INT_IMAGE_2D_ARRAY(){
    return (unsigned int)(GL_UNSIGNED_INT_IMAGE_2D_ARRAY);
}

GL::Enum::type Gl::UNSIGNED_INT_IMAGE_2D_MULTISAMPLE(){
    return (unsigned int)(GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE);
}

GL::Enum::type Gl::UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY(){
    return (unsigned int)(GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY);
}

GL::Enum::type Gl::UNSIGNED_INT_IMAGE_2D_RECT(){
    return (unsigned int)(GL_UNSIGNED_INT_IMAGE_2D_RECT);
}

GL::Enum::type Gl::UNSIGNED_INT_IMAGE_3D(){
    return (unsigned int)(GL_UNSIGNED_INT_IMAGE_3D);
}

GL::Enum::type Gl::UNSIGNED_INT_IMAGE_BUFFER(){
    return (unsigned int)(GL_UNSIGNED_INT_IMAGE_BUFFER);
}

GL::Enum::type Gl::UNSIGNED_INT_IMAGE_CUBE(){
    return (unsigned int)(GL_UNSIGNED_INT_IMAGE_CUBE);
}

GL::Enum::type Gl::UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY(){
    return (unsigned int)(GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY);
}

GL::Enum::type Gl::UNSIGNED_INT_SAMPLER_1D(){
    return (unsigned int)(GL_UNSIGNED_INT_SAMPLER_1D);
}

GL::Enum::type Gl::UNSIGNED_INT_SAMPLER_1D_ARRAY(){
    return (unsigned int)(GL_UNSIGNED_INT_SAMPLER_1D_ARRAY);
}

GL::Enum::type Gl::UNSIGNED_INT_SAMPLER_2D(){
    return (unsigned int)(GL_UNSIGNED_INT_SAMPLER_2D);
}

GL::Enum::type Gl::UNSIGNED_INT_SAMPLER_2D_ARRAY(){
    return (unsigned int)(GL_UNSIGNED_INT_SAMPLER_2D_ARRAY);
}

GL::Enum::type Gl::UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE(){
    return (unsigned int)(GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE);
}

GL::Enum::type Gl::UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY(){
    return (unsigned int)(GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY);
}

GL::Enum::type Gl::UNSIGNED_INT_SAMPLER_2D_RECT(){
    return (unsigned int)(GL_UNSIGNED_INT_SAMPLER_2D_RECT);
}

GL::Enum::type Gl::UNSIGNED_INT_SAMPLER_3D(){
    return (unsigned int)(GL_UNSIGNED_INT_SAMPLER_3D);
}

GL::Enum::type Gl::UNSIGNED_INT_SAMPLER_BUFFER(){
    return (unsigned int)(GL_UNSIGNED_INT_SAMPLER_BUFFER);
}

GL::Enum::type Gl::UNSIGNED_INT_SAMPLER_CUBE(){
    return (unsigned int)(GL_UNSIGNED_INT_SAMPLER_CUBE);
}

GL::Enum::type Gl::UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY(){
    return (unsigned int)(GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY);
}

GL::Enum::type Gl::UNSIGNED_INT_VEC2(){
    return (unsigned int)(GL_UNSIGNED_INT_VEC2);
}

GL::Enum::type Gl::UNSIGNED_INT_VEC3(){
    return (unsigned int)(GL_UNSIGNED_INT_VEC3);
}

GL::Enum::type Gl::UNSIGNED_INT_VEC4(){
    return (unsigned int)(GL_UNSIGNED_INT_VEC4);
}

GL::Enum::type Gl::UNSIGNED_NORMALIZED(){
    return (unsigned int)(GL_UNSIGNED_NORMALIZED);
}

GL::Enum::type Gl::UNSIGNED_SHORT(){
    return (unsigned int)(GL_UNSIGNED_SHORT);
}

GL::Enum::type Gl::UNSIGNED_SHORT_1_5_5_5_REV(){
    return (unsigned int)(GL_UNSIGNED_SHORT_1_5_5_5_REV);
}

GL::Enum::type Gl::UNSIGNED_SHORT_4_4_4_4(){
    return (unsigned int)(GL_UNSIGNED_SHORT_4_4_4_4);
}

GL::Enum::type Gl::UNSIGNED_SHORT_4_4_4_4_REV(){
    return (unsigned int)(GL_UNSIGNED_SHORT_4_4_4_4_REV);
}

GL::Enum::type Gl::UNSIGNED_SHORT_5_5_5_1(){
    return (unsigned int)(GL_UNSIGNED_SHORT_5_5_5_1);
}

GL::Enum::type Gl::UNSIGNED_SHORT_5_6_5(){
    return (unsigned int)(GL_UNSIGNED_SHORT_5_6_5);
}

GL::Enum::type Gl::UNSIGNED_SHORT_5_6_5_REV(){
    return (unsigned int)(GL_UNSIGNED_SHORT_5_6_5_REV);
}

GL::Enum::type Gl::UPPER_LEFT(){
    return (unsigned int)(GL_UPPER_LEFT);
}

GL::Enum::type Gl::VALIDATE_STATUS(){
    return (unsigned int)(GL_VALIDATE_STATUS);
}

GL::Enum::type Gl::VENDOR(){
    return (unsigned int)(GL_VENDOR);
}

GL::Enum::type Gl::VERSION(){
    return (unsigned int)(GL_VERSION);
}

GL::Enum::type Gl::VERTEX_ARRAY(){
    return (unsigned int)(GL_VERTEX_ARRAY);
}

GL::Enum::type Gl::VERTEX_ARRAY_BINDING(){
    return (unsigned int)(GL_VERTEX_ARRAY_BINDING);
}

GL::Enum::type Gl::VERTEX_ATTRIB_ARRAY_BARRIER_BIT(){
    return (unsigned int)(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT);
}

GL::Enum::type Gl::VERTEX_ATTRIB_ARRAY_BUFFER_BINDING(){
    return (unsigned int)(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING);
}

GL::Enum::type Gl::VERTEX_ATTRIB_ARRAY_DIVISOR(){
    return (unsigned int)(GL_VERTEX_ATTRIB_ARRAY_DIVISOR);
}

GL::Enum::type Gl::VERTEX_ATTRIB_ARRAY_ENABLED(){
    return (unsigned int)(GL_VERTEX_ATTRIB_ARRAY_ENABLED);
}

GL::Enum::type Gl::VERTEX_ATTRIB_ARRAY_INTEGER(){
    return (unsigned int)(GL_VERTEX_ATTRIB_ARRAY_INTEGER);
}

GL::Enum::type Gl::VERTEX_ATTRIB_ARRAY_LONG(){
    return (unsigned int)(GL_VERTEX_ATTRIB_ARRAY_LONG);
}

GL::Enum::type Gl::VERTEX_ATTRIB_ARRAY_NORMALIZED(){
    return (unsigned int)(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED);
}

GL::Enum::type Gl::VERTEX_ATTRIB_ARRAY_POINTER(){
    return (unsigned int)(GL_VERTEX_ATTRIB_ARRAY_POINTER);
}

GL::Enum::type Gl::VERTEX_ATTRIB_ARRAY_SIZE(){
    return (unsigned int)(GL_VERTEX_ATTRIB_ARRAY_SIZE);
}

GL::Enum::type Gl::VERTEX_ATTRIB_ARRAY_STRIDE(){
    return (unsigned int)(GL_VERTEX_ATTRIB_ARRAY_STRIDE);
}

GL::Enum::type Gl::VERTEX_ATTRIB_ARRAY_TYPE(){
    return (unsigned int)(GL_VERTEX_ATTRIB_ARRAY_TYPE);
}

GL::Enum::type Gl::VERTEX_ATTRIB_BINDING(){
    return (unsigned int)(GL_VERTEX_ATTRIB_BINDING);
}

GL::Enum::type Gl::VERTEX_ATTRIB_RELATIVE_OFFSET(){
    return (unsigned int)(GL_VERTEX_ATTRIB_RELATIVE_OFFSET);
}

GL::Enum::type Gl::VERTEX_BINDING_BUFFER(){
    return (unsigned int)(GL_VERTEX_BINDING_BUFFER);
}

GL::Enum::type Gl::VERTEX_BINDING_DIVISOR(){
    return (unsigned int)(GL_VERTEX_BINDING_DIVISOR);
}

GL::Enum::type Gl::VERTEX_BINDING_OFFSET(){
    return (unsigned int)(GL_VERTEX_BINDING_OFFSET);
}

GL::Enum::type Gl::VERTEX_BINDING_STRIDE(){
    return (unsigned int)(GL_VERTEX_BINDING_STRIDE);
}

GL::Enum::type Gl::VERTEX_PROGRAM_POINT_SIZE(){
    return (unsigned int)(GL_VERTEX_PROGRAM_POINT_SIZE);
}

GL::Enum::type Gl::VERTEX_SHADER(){
    return (unsigned int)(GL_VERTEX_SHADER);
}

GL::Enum::type Gl::VERTEX_SHADER_BIT(){
    return (unsigned int)(GL_VERTEX_SHADER_BIT);
}

GL::Enum::type Gl::VERTEX_SHADER_INVOCATIONS(){
    return (unsigned int)(GL_VERTEX_SHADER_INVOCATIONS);
}

GL::Enum::type Gl::VERTEX_SUBROUTINE(){
    return (unsigned int)(GL_VERTEX_SUBROUTINE);
}

GL::Enum::type Gl::VERTEX_SUBROUTINE_UNIFORM(){
    return (unsigned int)(GL_VERTEX_SUBROUTINE_UNIFORM);
}

GL::Enum::type Gl::VERTEX_TEXTURE(){
    return (unsigned int)(GL_VERTEX_TEXTURE);
}

GL::Enum::type Gl::VERTICES_SUBMITTED(){
    return (unsigned int)(GL_VERTICES_SUBMITTED);
}

GL::Enum::type Gl::VIEWPORT(){
    return (unsigned int)(GL_VIEWPORT);
}

GL::Enum::type Gl::VIEWPORT_BOUNDS_RANGE(){
    return (unsigned int)(GL_VIEWPORT_BOUNDS_RANGE);
}

GL::Enum::type Gl::VIEWPORT_INDEX_PROVOKING_VERTEX(){
    return (unsigned int)(GL_VIEWPORT_INDEX_PROVOKING_VERTEX);
}

GL::Enum::type Gl::VIEWPORT_SUBPIXEL_BITS(){
    return (unsigned int)(GL_VIEWPORT_SUBPIXEL_BITS);
}

GL::Enum::type Gl::VIEW_CLASS_128_BITS(){
    return (unsigned int)(GL_VIEW_CLASS_128_BITS);
}

GL::Enum::type Gl::VIEW_CLASS_16_BITS(){
    return (unsigned int)(GL_VIEW_CLASS_16_BITS);
}

GL::Enum::type Gl::VIEW_CLASS_24_BITS(){
    return (unsigned int)(GL_VIEW_CLASS_24_BITS);
}

GL::Enum::type Gl::VIEW_CLASS_32_BITS(){
    return (unsigned int)(GL_VIEW_CLASS_32_BITS);
}

GL::Enum::type Gl::VIEW_CLASS_48_BITS(){
    return (unsigned int)(GL_VIEW_CLASS_48_BITS);
}

GL::Enum::type Gl::VIEW_CLASS_64_BITS(){
    return (unsigned int)(GL_VIEW_CLASS_64_BITS);
}

GL::Enum::type Gl::VIEW_CLASS_8_BITS(){
    return (unsigned int)(GL_VIEW_CLASS_8_BITS);
}

GL::Enum::type Gl::VIEW_CLASS_96_BITS(){
    return (unsigned int)(GL_VIEW_CLASS_96_BITS);
}

GL::Enum::type Gl::VIEW_CLASS_BPTC_FLOAT(){
    return (unsigned int)(GL_VIEW_CLASS_BPTC_FLOAT);
}

GL::Enum::type Gl::VIEW_CLASS_BPTC_UNORM(){
    return (unsigned int)(GL_VIEW_CLASS_BPTC_UNORM);
}

GL::Enum::type Gl::VIEW_CLASS_RGTC1_RED(){
    return (unsigned int)(GL_VIEW_CLASS_RGTC1_RED);
}

GL::Enum::type Gl::VIEW_CLASS_RGTC2_RG(){
    return (unsigned int)(GL_VIEW_CLASS_RGTC2_RG);
}

GL::Enum::type Gl::VIEW_CLASS_S3TC_DXT1_RGB(){
    return (unsigned int)(GL_VIEW_CLASS_S3TC_DXT1_RGB);
}

GL::Enum::type Gl::VIEW_CLASS_S3TC_DXT1_RGBA(){
    return (unsigned int)(GL_VIEW_CLASS_S3TC_DXT1_RGBA);
}

GL::Enum::type Gl::VIEW_CLASS_S3TC_DXT3_RGBA(){
    return (unsigned int)(GL_VIEW_CLASS_S3TC_DXT3_RGBA);
}

GL::Enum::type Gl::VIEW_CLASS_S3TC_DXT5_RGBA(){
    return (unsigned int)(GL_VIEW_CLASS_S3TC_DXT5_RGBA);
}

GL::Enum::type Gl::VIEW_COMPATIBILITY_CLASS(){
    return (unsigned int)(GL_VIEW_COMPATIBILITY_CLASS);
}

GL::Enum::type Gl::WAIT_FAILED(){
    return (unsigned int)(GL_WAIT_FAILED);
}

GL::Enum::type Gl::WRITE_ONLY(){
    return (unsigned int)(GL_WRITE_ONLY);
}

GL::Enum::type Gl::XOR(){
    return (unsigned int)(GL_XOR);
}

GL::Enum::type Gl::ZERO(){
    return (unsigned int)(GL_ZERO);
}

GL::Enum::type Gl::ZERO_TO_ONE(){
    return (unsigned int)(GL_ZERO_TO_ONE);
}
