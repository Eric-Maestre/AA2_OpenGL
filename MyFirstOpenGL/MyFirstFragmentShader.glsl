#version 440 core

uniform vec2 windowSize;
uniform sampler2D textureSampler;

out vec4 fragColor;

in vec2 uvsFragmentShader;

void main() {

        fragColor = texture(textureSampler, uvsFragmentShader);   

}
