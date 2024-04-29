#version 440 core

uniform vec2 windowSize;
uniform sampler2D textureSampler;

out vec4 fragColor;

in vec2 uvsFragmentShader;

void main() {

        vec2 adjustTexCoord = vec2(uvsFragmentShader.x, 1.0 - uvsFragmentShader.y);
        fragColor = texture(textureSampler, adjustTexCoord);   

}
