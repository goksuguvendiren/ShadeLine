//
// Created by Göksu Güvendiren on 04/08/2017.
//

#include "IntNode.h"

cf::IntNode::IntNode(int v) : val(v), is_processed(false)
{}

std::vector<cf::any_t> cf::IntNode::Exec(std::vector<cf::any_t>)
{
    std::cerr << Name() << '\n';
    is_processed = true;
    return {boost::any(val)};
}

std::string cf::IntNode::Declare() const
{
    return "";
}