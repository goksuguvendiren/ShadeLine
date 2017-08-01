#include <iostream>
#include <opencv2/opencv.hpp>
#include <boost/any.hpp>

#include "Node.hpp"
#include "Shader_Node.h"

int main()
{
    cv::Mat image = cv::imread("kitten.png");
    cv::cvtColor(image, image, CV_BGR2RGB);

    gl::Window win(image.cols, image.rows);

    ppl::Blur blur_shader(win);

    std::vector<ppl::any_t> inputs;
    inputs.push_back(boost::any(image));
    inputs.push_back(boost::any(0));

    auto outputs = blur_shader.Exec(inputs);

    auto out = boost::any_cast<cv::Mat>(outputs[0]);

    cv::imwrite("guzuya_output.png", out);

    return 0;
}