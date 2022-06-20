#version 460 core

in vec2 vTex;

layout (location = 0) out vec4 out_Color;

uniform sampler2D Tex1;

void main(){
    // vec4 sampled = vec4(1.0, 1.0, 1.0, texture(Tex1, vTex).r);
    out_Color = vec4(1, 1, 1, 0); //texture(Tex1, vTex);
    // gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
};