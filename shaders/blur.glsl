#version 150 core

uniform int cols;
uniform int rows;

out vec4 outColor;
uniform sampler2D tex;
uniform int kernel;

float threshold_value = 0.55f;

vec4 mean_filter_3(sampler2D textr, vec2 uv)
{
    float result_red = 0.0f;
    float result_gre = 0.0f;
    float result_blu = 0.0f;

    int m = 0;
    for (int i = -kernel; i < kernel + 1; i++)
    {
        for (int j = -kernel; j < kernel + 1; j++)
        {
            result_red += texture(textr, vec2(uv.x + i / float(cols), uv.y + j / float(rows))).r;
            result_gre += texture(textr, vec2(uv.x + i / float(cols), uv.y + j / float(rows))).g;
            result_blu += texture(textr, vec2(uv.x + i / float(cols), uv.y + j / float(rows))).b;

            m++;
        }
    }

    result_red = result_red / m;
    result_gre = result_gre / m;
    result_blu = result_blu / m;

    return vec4(result_red, result_gre, result_blu, 1.0f);
}

//int binarize(sampler2D textr, vec2 uv, float threshold)
//{
//    return texture(textr, uv).r > threshold ? 1 : 0;
//}
//
//int binarize(float texel_lum, float threshold)
//{
//    return texel_lum > threshold ? 1 : 0;
//}
//
//int erode(sampler2D textr, vec2 uv, mat3 str_elem)
//{
//    bool fits = true;
//    for (int i = -1; i < 2; i++)
//    {
//        for (int j = -1; j < 2; j++)
//        {
//            if(str_elem[i + 1][j + 1] == 1)
//            {
//                vec4 tex_val = texture(textr, vec2(uv.x + i / float(cols), uv.y + j / float(rows)));
//                if (binarize(luminance(tex_val), threshold_value) == 0)
//                {
//                    fits = false;
//                    break;
//                }
//            }
//        }
//    }
//
//    return fits ? 1 : 0;
//}
//
//int dilate(sampler2D textr, vec2 uv, mat3 str_elem)
//{
//    bool hits = false;
//    for (int i = -1; i < 2; i++)
//    {
//        for (int j = -1; j < 2; j++)
//        {
//            if(str_elem[i + 1][j + 1] == 1)
//            {
//                vec4 tex_val = texture(textr, vec2(uv.x + i / float(cols), uv.y + j / float(rows)));
//                if (binarize(luminance(tex_val), threshold_value) == 1)
//                {
//                    hits = true;
//                    break;
//                }
//            }
//        }
//    }
//
//    return hits ? 1 : 0;
//}


void main()
{
    vec2 uv = vec2(gl_FragCoord.x, -gl_FragCoord.y) / vec2(cols, rows);
    outColor = mean_filter_3(tex, uv);

//    int frag_binary = binarize(frag_lum, threshold_value);
//
//    mat3 structuring_element;
//    structuring_element[0] = vec3(1, 1, 1);
//    structuring_element[1] = vec3(1, 1, 1);
//    structuring_element[2] = vec3(1, 1, 1);
//
////    int val = erode(tex, uv, structuring_element);
//    int val = frag_binary;
////    int val = dilate(tex, uv, structuring_element);
//
//    outColor = vec4(val, val, val, 1.0f);
}
