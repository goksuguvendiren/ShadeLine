//
// Created by Göksu Güvendiren on 01/08/2017.
//

#pragma once

#include <GL/glew.h>
#include <fstream>
#include <string>

namespace gl
{
    class Shader
    {
        GLuint shader;
        const char* source;


    public:
        enum class Type
        {
            Vertex,
            Fragment,
            Geometry
        };

        Shader(const std::string& path, Shader::Type type)
        {
            std::ifstream sh(path);
            std::string src((std::istreambuf_iterator<char>(sh)), std::istreambuf_iterator<char>());
            source = src.c_str();

            switch(type)
            {
                case Type::Vertex:
                    shader = glCreateShader(GL_VERTEX_SHADER);
                    break;
                case Type::Fragment:
                    shader = glCreateShader(GL_FRAGMENT_SHADER);
                    break;
                case Type::Geometry:
                    shader = glCreateShader(GL_GEOMETRY_SHADER);
                    break;
            }
//        shader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(shader, 1, &source, NULL);
        }

        bool Compile();
        GLuint GetShader() const { return shader; }

    };

}