//
// Created by Göksu Güvendiren on 04/08/2017.
//

#include "IntNode.h"

ppl::IntNode::IntNode(int v) : val(v), is_processed(false)
{}

std::vector<ppl::any_t> ppl::IntNode::Exec(std::vector<ppl::any_t>)
{
    std::cerr << Name() << '\n';
    is_processed = true;
    return {boost::any(val)};
}

std::string ppl::IntNode::Declare() const
{
    return "";
}