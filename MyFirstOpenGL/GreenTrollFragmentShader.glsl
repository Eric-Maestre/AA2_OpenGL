#version 440 core

uniform vec2 windowSize;
uniform sampler2D textureSampler;

out vec4 fragColor;

in vec2 uvsFragmentShader;

void main() {

        vec2 adjustTexCoord = vec2(uvsFragmentShader.x, 1.0 - uvsFragmentShader.y);

        vec4 baseColor = texture(textureSampler, adjustTexCoord);   

        vec4 newColor = vec4(0.0, 1.0, 0.0, 1.0);

        fragColor = baseColor * newColor;

}
