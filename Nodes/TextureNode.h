//
// Created by Göksu Güvendiren on 03/08/2017.
//

#pragma once

#include <string>
#include <opencv2/core/mat.hpp>
#include "node.hpp"

namespace cf
{
    class TextureNode : public node
    {
        cv::Mat image;
        bool is_processed;
    public:
        TextureNode(const cv::Mat& source_image);
        std::vector<cf::any_t> exec(std::vector<cf::any_t>);
        std::string Declare() const;

        std::string Name() const { return "TextureNode"; }

        bool IsProcessed() const { return is_processed; }
        void Processed() { is_processed = true; }
    };
}
