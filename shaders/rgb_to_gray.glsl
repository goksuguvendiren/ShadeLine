#version 150 core

uniform int cols;
uniform int rows;

out vec4 outColor;
uniform sampler2D tex;

float luminance(vec4 pixel_val)
{
    float result = 0.2126 * pixel_val.r + 0.7152 * pixel_val.g + 0.0722 * pixel_val.b;
    return result;
}

void main()
{
    vec2 uv = vec2(gl_FragCoord.x, -gl_FragCoord.y) / vec2(cols, rows);
    outColor = vec4(vec3(luminance(texture(tex, uv))), 1.0);
}
