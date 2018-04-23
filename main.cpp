#include <iostream>
#include <string>
#include "Graph.hpp"

int main(int, char**) {
    Graph g (std::string("adjacency.json"));
    std::cout << g << std::endl;

    auto vertexIter = boost::vertices(g);

    for (auto it = vertexIter.first ; 
        it != vertexIter.second; 
        ++it){
        std::cout<<**it<<std::endl;
    }

    std::cout<< "n = " << boost::num_vertices(g) << std::endl;

    std::cout << "Edges : " << std::endl;
    for (auto it = g.eBegin();
        it != g.eEnd();
        ++it){
            std::cout<< *(*it)->first << '|' << *(*it)->second << std::endl;
        }
}
