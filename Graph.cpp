//
// Created by Göksu Güvendiren on 03/08/2017.
//

#include <iostream>
#include "Graph.hpp"

void ppl::Graph::Run()
{
    // wait for the inputs to be ready

    // execute the node
    auto outputs = curNode->Exec(inputs);
    inputs.clear();

    // bad guzu :
    inputs.resize(5);

    // find the node to be processed next:
    for (auto& edge : edges)
    {
        if (edge.source_node == curNode && !edge.destination_node->IsProcessed())
        {
            curNode = edge.destination_node;
            inputs[edge.destination_index] = outputs[edge.source_index];
            break;
        }
    }
}

void ppl::Graph::Init()
{
    // first find the beginning points : INIT PHASE
    for (auto& node : nodes)
    {
        if (!std::any_of(edges.begin(), edges.end(), [&node](auto edge){ return edge.destination_node == node; }))
        {
//            std::cerr << node->Name() << '\n';
            curNode = node;
            inputs = {};
            return;
        }
    }
}

bool ppl::Graph::Complete()
{
    return std::all_of(nodes.begin(), nodes.end(), [](auto& node){ return node->IsProcessed(); });
}