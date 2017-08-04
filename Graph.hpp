//
// Created by Göksu Güvendiren on 03/08/2017.
//

#pragma once

#include <map>
#include "Nodes/node.hpp"

namespace cf
{
    struct data_ref
    {
        uint16_t node_index;
        uint16_t data_index;
        bool is_input;
    };

    struct node_ref
    {
        uint16_t node_index;

        data_ref input(int index)  { return { node_index, index, true }; }
        data_ref output(int index) { return { node_index, index, false }; }
    };

    class graph
    {
        struct binding
        {
            data_ref from, to;
        };

        std::vector<std::unique_ptr<node>> m_nodes;
        std::vector<binding> m_bindings;
        std::vector<bool> m_processed;
        std::vector<node_ref> m_roots;

        std::map<node_ref, std::string> m_names;
        std::map<node_ref, std::vector<cf::any_t>> m_outputs;

        node_ref m_proc_node;

    public:
        graph() = default;

        bool is_complete();
        void init();
        void exec_one();
        node_ref add(std::unique_ptr<node> node, const std::string& name = "");
        data_ref input(int index);
        data_ref output(int index);

        void bind(data_ref from, data_ref to);
    };
}
