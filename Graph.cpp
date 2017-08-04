//
// Created by Göksu Güvendiren on 03/08/2017.
//

#include <iostream>
#include "Graph.hpp"

bool cf::graph::is_complete()
{
    return std::all_of(m_processed.begin(), m_processed.end(), [](auto& pr) { return pr; });
}

void cf::graph::exec_one()
{
    // current node to be exec'ed is :
    auto proc_node_index = m_proc_node.node_index;
    int num_input = 5;//m_nodes[nd]->describe().find("num_input");

    std::vector<cf::any_t> inp;
    inp.resize(num_input);

    for (auto& binding : m_bindings)
    {
        if (binding.to.node_index == proc_node_index)  /// bindings that direct to this node
        {
            if (!m_processed[binding.from.node_index])  /// if an input to this node is not ready yet, return the function.
            {
                assert(m_roots.size() > 0);
                m_proc_node = m_roots[0];
                return;
            }
            inp[binding.to.data_index] = m_outputs[{binding.from.node_index}][binding.from.data_index];
        }
    }

    auto outp = m_nodes[proc_node_index]->exec(inp);
    m_outputs.emplace(proc_node_index, outp);

    m_processed[proc_node_index] = true;
    m_roots.erase(std::remove(m_roots.begin(), m_roots.end(), node_ref{proc_node_index}), m_roots.end());
}

void cf::graph::init()
{
    m_processed[0] = true;
    m_proc_node = m_roots[0];
}

cf::node_ref cf::graph::add(std::unique_ptr<cf::node> node, const std::string &name)
{
    cf::node_ref new_node{ m_nodes.size() };
    m_nodes.push_back(std::move(node));
    m_processed.push_back(false);
    m_roots.emplace_back(new_node);

    if (name != "")
    {
        m_names.emplace(new_node, name);
    }

    return new_node;
}

// zeroth node has the inputs and outputs of the whole graph
cf::data_ref cf::graph::input(int index)
{
    return {0, index, true};
}

cf::data_ref cf::graph::output(int index)
{
    return {0, index, false};
}

void cf::graph::bind(cf::data_ref from, cf::data_ref to)
{
    m_bindings.emplace_back({from, to});

    if (from.node_index == 0 || to.node_index == 0)
    {
        return;
    }

    m_roots.erase(std::remove(m_roots.begin(), m_roots.end(), node_ref{to.node_index}), m_roots.end());
}
