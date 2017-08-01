//
// Created by Göksu Güvendiren on 01/08/2017.
//

#pragma once

#include "Node.hpp"
#include "GL/Program.h"
#include "GL/Window.h"
#include <opencv2/opencv.hpp>

namespace ppl
{
    class Blur : public Node
    {
        gl::Window window;
        gl::Program program;
        void create_program(const cv::Mat& image);

    public:
        Blur(const gl::Window& win);
        std::vector<ppl::any_t> Exec(std::vector<ppl::any_t>);
        std::string Declare();
    };
}