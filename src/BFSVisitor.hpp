#ifndef BFSVISITOR_HPP
#define BFSVISITOR_HPP

#include <boost/graph/visitors.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include "Graph.h"
#include "BGL_traits.h"

#include <iostream>

template <typename Visitors = boost::null_visitor>
class BFSVisitor : public boost::bfs_visitor<Visitors>
{
    public:
    BFSVisitor(Visitors vis) : boost::bfs_visitor<Visitors>(vis) {};
    // void initialize_vertex(boost::graph_traits<Graph>::vertex_descriptor s, Graph& g);
    // void discover_vertex(boost::graph_traits<Graph>::vertex_descriptor u, Graph& g);
    void examine_vertex(boost::graph_traits<Graph>::vertex_descriptor u, const Graph& g){
        boost::bfs_visitor<Visitors>::examine_vertex(u, g);
        std::cout <<"Examining vertex:" << u->type() <<std::endl;
    }
    // void examine_edge(boost::graph_traits<Graph>::edge_descriptor e, Graph& g);
    // void tree_edge(boost::graph_traits<Graph>::edge_descriptor e, Graph& g);
    // void non_tree_edge(boost::graph_traits<Graph>::edge_descriptor e, Graph& g);
    // void gray_target(boost::graph_traits<Graph>::edge_descriptor e, Graph& g);
    // void black_target(boost::graph_traits<Graph>::edge_descriptor e, Graph& g);
    // void finish_vertex(boost::graph_traits<Graph>::vertex_descriptor u, Graph& g);
};



#endif //BFSVISITOR_HPP