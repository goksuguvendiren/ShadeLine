//
// Created by Göksu Güvendiren on 01/08/2017.
//

#pragma once

#include <vector>
#include "../mytypes.hpp"

namespace ppl
{
    class Node
    {
    public:
        virtual std::vector<ppl::any_t> Exec(std::vector<ppl::any_t>) = 0;
        virtual std::string Declare() const = 0;
        virtual std::string Name() const = 0;
        virtual bool IsProcessed() const = 0;
        virtual void Processed() = 0;
    };
}