#include <iostream>
#include <string>
#include "Graph.hpp"
#include "Vertex.hpp"
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/breadth_first_search.hpp>

#include <boost/range/irange.hpp>

int main(int, char**) {
    Graph g (std::string("adjacency.json"));
    std::cout << g << std::endl;

    auto vertexIter = vertices(g);

    for (auto it = vertexIter.first ; 
        it != vertexIter.second; 
        ++it){
        std::cout<<**it<<std::endl;
    }

    std::cout<< "n = " << num_vertices(g) << std::endl;

    std::cout << "Edges : " << std::endl;
    for (auto it = g.eBegin();
        it != g.eEnd();
        ++it){
            std::cout<< *(*it)->first << '|' << *(*it)->second << std::endl;
        }

    std::cout<< "Out-edges of vertex 1 "<< std::endl;
    auto itPair = out_edges(g.getVertex(1), g);
    for(auto it =itPair.first; it != itPair.second ; ++it){
        std::cout << *(*it)->first << '|' << *(*it)->second << std::endl;
    }

    //std::map<Graph::vertex_descriptor, boost::default_color_type > cmap;
    //boost::depth_first_search(g);

    boost::associative_property_map< std::map<Graph::vertex_descriptor, int> >
    vertex_map(g.getMap());
    for(auto it: g.getMap()){
        std::cout << *it.first << it.second << std::endl;
    }
    
    boost::breadth_first_search(g, g.getVertex(1), vertex_index_map(vertex_map));
    boost::depth_first_search(g, vertex_index_map(vertex_map));

    return 0;
}
