//
// Created by Göksu Güvendiren on 03/08/2017.
//

#pragma once

#include <string>
#include <opencv2/core/mat.hpp>
#include "Node.hpp"

namespace ppl
{
    class TextureNode : public Node
    {
        cv::Mat image;
        bool is_processed;
    public:
        TextureNode(const cv::Mat& source_image);
        std::vector<ppl::any_t> Exec(std::vector<ppl::any_t>);
        std::string Declare() const;

        std::string Name() const { return "TextureNode"; }

        bool IsProcessed() const { return is_processed; }
        void Processed() { is_processed = true; }
    };
}
