#version 460 core

const int vPosN = 0;
const int vTexN = 1;

layout (location = vPosN) in vec3 vPos;
layout (location = vTexN) in vec2 vTex;

out vec2 vertOutTex;
layout (std140) uniform Camera {
    mat4 camera_mat;
};

uniform vec4 offset[16];
uniform float mult[16];

void main(){
    vec3 pos = mult[vPosN] * (vPos + offset[vPosN].xyz);
    gl_Position = camera_mat * vec4(pos, 1.0);

    vertOutTex = mult[vTexN] * (vTex + offset[vTexN].xy);
}