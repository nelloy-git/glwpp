#version 460 core

layout (location = 0) in vec2 aPos;

// uniform int layer = 0;

void main(){
    gl_Position = vec4(aPos.x, aPos.y, 0.0, 0.0);
}