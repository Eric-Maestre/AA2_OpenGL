#version 440 core

uniform vec2 windowSize;
uniform sampler2D textureSampler;

out vec4 fragColor;

in vec2 uvsFragmentShader;

void main() {

        vec2 adjustTexCoord = vec2(uvsFragmentShader.x, 1.0 - uvsFragmentShader.y);

        vec4 baseColor = texture(textureSampler, adjustTexCoord);   

        vec4 whiteColor = vec4(1.0, 1.0, 1.0, 1.0);

        float blendFactor = 0.8;

        vec4 mixedColor = mix(baseColor, whiteColor, blendFactor);

        fragColor = mixedColor;

}
