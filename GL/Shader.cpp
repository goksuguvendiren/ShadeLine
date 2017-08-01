//
// Created by Göksu Güvendiren on 01/08/2017.
//

#include <iostream>
#include "Shader.h"

namespace gl
{
    bool Shader::Compile()
    {
        glCompileShader(shader);

        GLint status;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

        char buffer[512];
        glGetShaderInfoLog(shader, 512, NULL, buffer);

//    std::cerr << buffer << '\n';

        if (!strcmp(buffer, "")) return true;
        else {
            std::cerr << buffer;
            std::abort();
        }
    }
}