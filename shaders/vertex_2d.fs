#version 460 core

in vec2 vTex;

uniform sampler2D Tex1;

void main(){
    // vec4 sampled = vec4(1.0, 1.0, 1.0, texture(Tex1, vTex).r);
    gl_FragColor = texture(Tex1, vTex);
    // gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
};