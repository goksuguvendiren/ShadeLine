//
// Created by Göksu Güvendiren on 01/08/2017.
//

#pragma once

#include <vector>
#include "../mytypes.hpp"
#include <nlohmann/json.hpp>

namespace cf
{
    class node
    {
    public:
        virtual std::vector<cf::any_t> exec(const std::vector<cf::any_t>&) = 0;
        virtual nlohmann::json describe() const = 0;

        virtual ~node() = default;
    };
}
