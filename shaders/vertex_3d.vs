#version 460 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;

out vec2 vTex;

uniform vec3 offset = {0, 0, 0};
uniform float mult = 1;

void main(){
    vec3 pos = mult * (aPos + offset);
    gl_Position = vec4(pos, 1.0);
    vTex = aTex;
}