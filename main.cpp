#include <iostream>
#include <opencv2/opencv.hpp>
#include <boost/any.hpp>

#include "Nodes/Node.hpp"
#include "Nodes/ShaderNode.h"
#include "Graph.hpp"
#include "Nodes/TextureNode.h"
#include "Nodes/IntNode.h"

int main()
{
    cv::Mat image = cv::imread("kitten.png");
    cv::cvtColor(image, image, CV_BGR2RGB);

    gl::Window win(image.cols, image.rows);

    ppl::Graph graph;
    ppl::TextureNode texture(image);
    ppl::BlurNode blur_shader;
    ppl::BlurNode blur_shader1;

    graph.AddNode(texture);
    graph.AddNode(blur_shader);
    graph.AddNode(blur_shader1);

    ppl::IODirections direction(&texture, &blur_shader, 0, 0);
    ppl::IODirections direction1(&blur_shader, &blur_shader1, 0, 0);
    graph.AddEdge(direction);
    graph.AddEdge(direction1);

    graph.Init();
    while(!graph.Complete())
    {
        graph.Run();
    }

//    std::vector<ppl::any_t> inputs;
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