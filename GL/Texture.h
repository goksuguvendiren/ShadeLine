//
// Created by Göksu Güvendiren on 01/08/2017.
//

#pragma once

#include <string>
#include <opencv2/core/mat.hpp>

namespace gl
{
    template <class T>
    struct type
    {};

    class Texture
    {
        unsigned int id;
        int rows_;
        int cols_;

    public:
        Texture(type<float>, int, int);
        Texture(int cols, int rows, uchar* data);
        int rows() { return rows_; }
        int cols() { return cols_; }

        void Bind(int slot = 0);
        unsigned int ID() { return id; }
    };

    Texture LoadTexture(const cv::Mat& image);
}