//
// Created by Göksu Güvendiren on 03/08/2017.
//

#include "TextureNode.h"

ppl::TextureNode::TextureNode(const cv::Mat& source_image) : image(source_image), is_processed(false)
{}

std::vector<ppl::any_t> ppl::TextureNode::Exec(std::vector<ppl::any_t>)
{
    is_processed = true;
    return {boost::any(image)};
}

std::string ppl::TextureNode::Declare() const
{
    return "";
}