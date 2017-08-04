#include <iostream>
#include <opencv2/opencv.hpp>

#include "Nodes/node.hpp"
#include "Nodes/ShaderNode.h"
#include "Graph.hpp"
#include "Nodes/TextureNode.h"
#include "Nodes/IntNode.h"

int main()
{
    cv::Mat image = cv::imread("kitten.png");

    gl::Window win(image.cols, image.rows);

    cf::graph g;
    cf::TextureNode texture(image);
    cf::BlurNode blur_shader;
    cf::BlurNode blur_shader1;

    g.AddNode(texture);
    g.AddNode(blur_shader);
    g.AddNode(blur_shader1);

    g.AddEdge(&texture, &blur_shader, 0, 0);
    g.AddEdge(&blur_shader, &blur_shader1, 0, 0);

    g.Init();
    while(!g.Complete())
    {
        g.Run();
    }

//    std::vector<cf::any_t> inputs;
//    inputs.push_back(boost::any(image));
//    inputs.push_back(boost::any(10));
//
//    auto outputs = blur_shader.Exec(inputs);
//
//    auto out = boost::any_cast<cv::Mat>(outputs[0]);
//
//    cv::imwrite("guzuya_output.png", out);

    return 0;
}