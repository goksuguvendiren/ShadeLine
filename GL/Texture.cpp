//
// Created by Göksu Güvendiren on 01/08/2017.
//

#include "Texture.h"
#include <GL/glew.h>
#include <iostream>

namespace gl
{
    Texture::Texture(int cols, int rows, uchar* data)
    {
        cols_ = cols;
        rows_ = rows;

        GLuint tex;
        glGenTextures(1, &tex);
        id = tex;

        glBindTexture(GL_TEXTURE_2D, tex);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glGenerateMipmap(GL_TEXTURE_2D);

        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, cols, rows, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    }

    void Texture::Bind(int slot)
    {
        switch(slot)
        {
            case 0 :
                glActiveTexture(GL_TEXTURE0);
                break;
            case 1 :
                glActiveTexture(GL_TEXTURE1);
                break;
            default:
                std::cerr << "Slot not implemented! " << '\n';
                std::abort();
        }
        glBindTexture(GL_TEXTURE_2D, id);
    }

    Texture::Texture(type<float>, int cols, int rows)
    {
        cols_ = cols;
        rows_ = rows;

        GLuint tex;
        glGenTextures(1, &tex);
        id = tex;

        glBindTexture(GL_TEXTURE_2D, tex);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glGenerateMipmap(GL_TEXTURE_2D);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, cols, rows, 0, GL_RGB, GL_FLOAT, 0);
    }

    Texture LoadTexture(const cv::Mat& image)
    {
        return Texture(image.cols, image.rows, image.data);
    }
}