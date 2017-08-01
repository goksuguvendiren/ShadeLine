//
// Created by Göksu Güvendiren on 01/08/2017.
//

#include "Program.h"
#include "Shader.h"
#include "Texture.h"

#include <cassert>

namespace gl
{
    void Program::Init()
    {
        id = glCreateProgram();
        tex_1 = nullptr;
        tex_2 = nullptr;
        num_tex = 0;
    }

    void Program::Render(int w, int h, GLuint framebuffer)
    {
        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
        assert(tex_1);
        glViewport(0, 0, w, h); // Render on the whole framebuffer, complete from the lower left corner to the upper right

        // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Use();
        if (tex_1) {
            tex_1->Bind(0);
        }
        if (tex_2) tex_2->Bind(1);
    }

    void Program::LoadTexture(Texture &texture, const std::string &label)
    {
        if (num_tex == 0)
        {
            tex_1 = &texture;
            tex_1->Bind(0);  // bind the texture to the 0th slot !
            GLint pos = glGetUniformLocation(id, label.c_str());
            glUniform1i(pos, 0);
        }
        else if (num_tex == 1)
        {
            tex_2 = &texture;
            tex_2->Bind(1);
            GLint pos = glGetUniformLocation(id, label.c_str());
            glUniform1i(pos, 1);
        }
        else
        {
            std::cerr << "No more textures\n";
        }

        num_tex++;
    }

    void Program::Attach(const Shader& shader)
    {
        glAttachShader(id, shader.GetShader());
    }

    void Program::BindFragData(const std::vector<std::string>& locations)
    {
        glBindFragDataLocation(id, 0, locations[0].c_str());
    }
}