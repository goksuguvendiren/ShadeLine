//
// Created by Göksu Güvendiren on 01/08/2017.
//

#pragma once

#include "node.hpp"
#include "../GL/Program.h"
#include "../GL/Window.h"
#include <opencv2/opencv.hpp>

namespace cf
{
    class BlurNode : public node
    {
        void create_program() const;
        bool is_processed;

    public:
        BlurNode();
        std::vector<cf::any_t> exec(std::vector<cf::any_t>);
        nlohmann::json describe() const;

        std::string Name() const { return "BlurNode"; }

        bool IsProcessed() const { return is_processed; }
        void Processed() { is_processed = true; }
    };
}