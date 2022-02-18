#version 450 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTex;

out vec2 vTex;

uniform float offset_x = 1.0;
uniform float offset_y = 1.0;
uniform float scale_x = 1.0;
uniform float scale_y = 1.0;

void main(){
    gl_Position = vec4(offset_x + scale_x * aPos.x, offset_y +  scale_y * aPos.y, 0.0, 1.0);
    vTex = aTex;
}