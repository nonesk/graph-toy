#include <iostream>
#include <string>
#include <stack>
#include "Graph.h"
#include "Vertex.h"
#include "BGL_traits.h"
#include "BFSVisitor.hpp"

#include <boost/graph/visitors.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/property_map/property_map.hpp>



int main(int argc, char* argv[])
{
    std::string arg(argv[1]); // adjacency list as JSON

    std::cout << "Loading adjacency list from " << arg << std::endl;

    Graph g(arg); // declare graph
    std::cout << g << std::endl;

    /******************
     * using BGL implicit API
     * ***************/
    std::cout << "Vertices" << std::endl; // vertices(g) 
    for (auto it = vertices(g).first; it != vertices(g).second;++it){
        std::cout << **it << " -> ";
        auto itPair = out_edges(*it, g);
        for (auto itE = itPair.first; itE != itPair.second; ++itE){
            std::cout << *(*itE)->second << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "n = " << num_vertices(g) << std::endl;

    std::cout << "Edges : " << std::endl; // edges(g)
    for (auto it = edges(g).first; it != edges(g).second ; ++it){
        std::cout << *(*it)->first << "->" << *(*it)->second << std::endl;
    }

    /********************************************
     * BGL API : containers
     * ******************************************/

    std::map<Graph::vertex_descriptor, Graph::vertex_descriptor> 
    parents_; // predecessors map for BFS/DFS algorithms


    typedef boost::associative_property_map< 
        std::map<Graph::vertex_descriptor, Graph::vertex_descriptor> 
    > predecessor_map;
    predecessor_map parents(parents_); // predecessor map wrapper
    


    /**
     * color map
     * index : vertex
     * value : boost::default_color_type
     */
    std::map<Graph::vertex_descriptor, boost::default_color_type> 
    cmap_;

    boost::associative_property_map<
        std::map<Graph::vertex_descriptor, boost::default_color_type>
    > cmap(cmap_);

    // distance container filled by BFS/DFS
    std::map<Graph::vertex_descriptor, unsigned int> 
    d_;
    //std::fill_n(d_, num_vertices(g), 0);

    typedef boost::associative_property_map< 
        std::map<Graph::vertex_descriptor, unsigned int>  
    > distance_map;
    distance_map d(d_); // distance map wrapper

    // root vertex 
    Graph::vertex_descriptor s = *vertices(g).first;
    std::cout << "Root vertex : " << *s << std::endl;
    // set root vertex in predecessor map
    put(parents, s, s);

    auto recorder = boost::record_predecessors(parents, boost::on_tree_edge{});
    
    auto vis = BFSVisitor<
        std::pair<
            boost::predecessor_recorder<predecessor_map, boost::on_tree_edge>,
            boost::distance_recorder<distance_map, boost::on_tree_edge>
            >
        >(std::make_pair(
            boost::predecessor_recorder<predecessor_map, boost::on_tree_edge>(parents),
            boost::distance_recorder<distance_map, boost::on_tree_edge>(d))
        );
    // auto vis = boost::make_bfs_visitor(
    //     std::make_pair(
    //     boost::record_distances(d, boost::on_tree_edge()),
    //     recorder)
    // );

    //vis.tree_edge(*edges(g).first, g);


    /**********************************
     * BFS
     * ********************************/

    
    std::stack<Graph::vertex_descriptor> Q; // used by BFS as buffer queue

    boost::breadth_first_search(g, s, Q, vis, cmap);

    std::cout   << "------------------" << std::endl
                << "BFS results :" << std::endl;

    for(auto it: parents_){
        std::cout << "parent(" << *it.first << ")=" << *it.second << std::endl;
    }

    std::cout << "Distances from root(" << *s << ")" << std::endl;
    for(auto it: d_){
        std::cout << *it.first << " : " << it.second << std::endl;
    }


    /********************************************************
     * DFS
     * ******************************************************/

    boost::depth_first_search(
        g, 
        boost::make_dfs_visitor(
            std::make_pair(
                boost::record_distances(d, boost::on_tree_edge()),
                recorder)), 
        cmap);
    
    std::cout   << "------------------" << std::endl
                << "DFS results :" << std::endl;
    for(auto it: parents_){
        std::cout << "parent(" << *it.first << ")=" << *it.second << std::endl;
    }

    std::cout << "Distances from root(" << *s << ")" << std::endl;
    for(auto it: d_){
        std::cout << *it.first << " : " << it.second << std::endl;
    }

    return 0;
}
