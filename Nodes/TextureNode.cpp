//
// Created by Göksu Güvendiren on 03/08/2017.
//

#include <iostream>
#include "TextureNode.h"
#include "../GL/Texture.h"

ppl::TextureNode::TextureNode(const cv::Mat& source_image) : image(source_image), is_processed(false)
{}

std::vector<ppl::any_t> ppl::TextureNode::Exec(std::vector<ppl::any_t>)
{
    std::cerr << Name() << '\n';

    // Load the texture to the GPU
    gl::Texture texture(image.cols, image.rows, image.data);

    is_processed = true;
    return {boost::any(texture)};
}

std::string ppl::TextureNode::Declare() const
{
    return "";
}