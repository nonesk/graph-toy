#include "Graph.h"

#include "json.hpp"
#include <iostream>
#include <string> 
#include <fstream>


using json = nlohmann::json;

Graph::Graph(std::string json_file)
{
    std::ifstream ifs ("adjacency.json", std::ifstream::in);
    json j;
    ifs >> j;

    for (json::iterator it = j.begin(); it != j.end(); it++){
        auto const adj_json = it.value();
        std::vector<int> adj;
        for (auto& vertex: adj_json){
            adj.push_back(vertex);
        }
        adjacency.push_back(adj);
    }
};


std::ostream& operator << (std::ostream& out, const Graph &graph){
    int i=0;
    for (std::vector<int> adjList : graph.adjacency){
        out << i << ":";
        for (int vertex : adjList){
            out << vertex << ",";
        }
        out << std::endl;
        i++;
    }
    return out;
}

