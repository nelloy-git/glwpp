#version 460 core

const int vPosN = 0;
const int vTexN = 1;

in vec3 vPos;
in vec2 vTex;

layout (std140) uniform Camera {
    mat4 camera_mat;
};

uniform int node_n;
layout (std140) uniform MeshTransform {
    mat4 transform[500];
};

out vec2 vertOutTex;

uniform vec4 offset[16];
uniform float mult[16];

void main(){
    vec3 pos = vPos;
    // gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);
    
    // vec3 pos = mult[vPosN] * (vPos + offset[vPosN].xyz);
    gl_Position = camera_mat * transform[node_n] * vec4(pos, 1.0);

    vertOutTex = mult[vTexN] * (vTex + offset[vTexN].xy);
}