//
// Created by Göksu Güvendiren on 01/08/2017.
//

#pragma once

#include <GL/glew.h>
#include <string>
#include <array>
#include <vector>
#include <iostream>


namespace gl
{
    class Texture;
    class Shader;

    class Program
    {
        int num_tex;
        GLuint id;
        Texture* tex_1;
        Texture* tex_2;

    public:
        Program() = default;

        void Init();
        void Attach(const Shader& shader);
        void Link() { glLinkProgram(id); }
        void Use() { glUseProgram(id); }

        GLuint ID() const { return id; };

        void Render(int w, int h, GLuint framebuffer = 0);
        void LoadTexture(Texture& texture, const std::string& label);

        GLint SetUniform(const std::string& variable, int val)
        {
            GLint pos = glGetUniformLocation(id, variable.c_str());
            glUniform1i(pos, val);

            return pos;
        }

        GLint SetUniform(const std::string& variable, float val)
        {
            GLint pos = glGetUniformLocation(id, variable.c_str());
            glUniform1f(pos, val);

            return pos;
        }

        GLint SetUniform(const std::string& variable, const std::array<float, 3>& arr)
        {
            GLint pos = glGetUniformLocation(id, variable.c_str());
            glUniform3f(pos, arr[0], arr[1], arr[2]);

            return pos;
        }

        GLint SetUniform(const std::string& variable, const std::array<int, 2>& arr)
        {
            GLint pos = glGetUniformLocation(id, variable.c_str());
            glUniform2i(pos, arr[0], arr[1]);

            return pos;
        }

        void SetUniform(GLint position, const std::array<float , 3>& arr)
        {
            glUniform3f(position, arr[0], arr[1], arr[2]);
        }

        void SetUniform(GLint position, float val)
        {
            glUniform1f(position, val);
        }

        void SetUniform(GLint position, const std::array<int , 2>& arr)
        {
            glUniform2i(position, arr[0], arr[1]);
        }

        void BindFragData(const std::vector<std::string>& location);
    };

}