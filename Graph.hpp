//
// Created by Göksu Güvendiren on 03/08/2017.
//

#pragma once

#include "Nodes/Node.hpp"

namespace ppl
{
    struct IODirections
    {
        Node* source_node;
        Node* destination_node;
        int source_index;
        int destination_index;

        IODirections(Node* s, Node* d, int si, int di) : source_node(s),
                                                         destination_node(d),
                                                         source_index(si),
                                                         destination_index(di) {}
    };

    class Graph
    {
        std::vector<Node*> nodes;
        std::vector<IODirections> edges;

        std::vector<ppl::any_t> inputs;
        Node* curNode;

    public:
        Graph() = default;
        void AddNode(Node& node) { nodes.push_back(&node); }
        void AddEdge(const IODirections& dir) { edges.push_back(dir); }

        void Init();
        void Run();
        bool Complete();
    };
}
