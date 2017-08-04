//
// Created by Göksu Güvendiren on 04/08/2017.
//

#pragma once

#include "node.hpp"
#include "../GL/Program.h"
#include "../GL/Window.h"
#include <opencv2/opencv.hpp>

namespace cf
{
    class IntNode : public node
    {
        int val;
        bool is_processed;

    public:
        IntNode(int v);
        std::vector<cf::any_t> Exec(std::vector<cf::any_t>);
        std::string Declare() const;

        std::string Name() const { return "IntNode"; }

        bool IsProcessed() const { return is_processed; }
        void Processed() { is_processed = true; }
    };
}