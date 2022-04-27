#version 460 core

const int vPosN = 0;
const int vTexN = 1;

layout (location = vPosN) in vec3 vPos;
layout (location = vTexN) in vec2 vTex;

out vec2 vertOutTex;

uniform mat4 camera;
uniform vec4 offset[16];
uniform float mult[16];

void main(){
    vec3 pos = mult[vPosN] * (vPos + offset[vPosN].xyz);
    gl_Position = camera * vec4(pos, 1.0);

    vertOutTex = mult[vTexN] * (vTex + offset[vTexN].xy);
}