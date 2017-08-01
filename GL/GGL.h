//
// Created by Göksu Güvendiren on 01/08/2017.
//

#pragma once

#include <GL/glew.h>
#include "Texture.h"
#include "Shader.h"

inline void init_ggl()
{
    glewExperimental = GL_TRUE;
    glewInit();
}

inline void init_gl_objects()
{
    // Create Vertex Array Object
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);

    // VERTEX DATA
    float vertices[] =
            {
                    //  Position
                    -1.0f,  1.0f, // Top-left
                    1.0f,  1.0f, // Top-right
                    1.0f, -1.0f, // Bottom-right
                    -1.0f, -1.0f  // Bottom-left
            };

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLuint ebo;
    glGenBuffers(1, &ebo);

    GLuint elements[] = {
            0, 1, 2,
            2, 3, 0
    };

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

}

inline auto init_frame_buffer(int cols, int rows)
{
    GLuint FrameBuffer = 0;
    glGenFramebuffers(1, &FrameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, FrameBuffer);

    gl::Texture renderedTexture{gl::type<float>{}, cols, rows};

    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, renderedTexture.ID(), 0);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::abort();

    assert(!glGetError());
    return FrameBuffer;
}

void init_attribs(int programID)
{
    auto posAttrib = glGetAttribLocation(programID, "position");
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), 0);
    glEnableVertexAttribArray(posAttrib);
}
