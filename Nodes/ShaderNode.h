//
// Created by Göksu Güvendiren on 01/08/2017.
//

#pragma once

#include "Node.hpp"
#include "../GL/Program.h"
#include "../GL/Window.h"
#include <opencv2/opencv.hpp>

namespace ppl
{
    class BlurNode : public Node
    {
        void create_program(const cv::Mat& image) const;
        bool is_processed;

    public:
        BlurNode();
        std::vector<ppl::any_t> Exec(std::vector<ppl::any_t>);
        std::string Declare() const;

        std::string Name() const { return "BlurNode"; }

        bool IsProcessed() const { return is_processed; }
        void Processed() { is_processed = true; }
    };
}