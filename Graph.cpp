#include "Graph.hpp"

#include "json.hpp"
#include <iostream>
#include <string> 
#include <fstream>
#include <map>

using json = nlohmann::json;


/**
 * @brief Construct a new Graph:: Graph object
 * 
 * @param json_file : Adjacency list in JSON format
 */
Graph::Graph(std::string json_file)
{
    // load json structure
    std::ifstream ifs (json_file, std::ifstream::in);
    json j;
    ifs >> j;

    // iterate over vertexid : adjacency_list
    for (json::iterator it = j.begin(); it != j.end(); it++){
        auto const adj_json = it.value();
        std::vector<Vertex*> adj;
        // iterate over adjacency list
        for (auto& vertexId: adj_json){
            int vId = vertexId.get<int>();
            std::map<int, Vertex*>::iterator v = vertices.find(vId);
            if (v == vertices.end()){
                vertices[vId] = new Vertex(vId);
            }
            Vertex* vertex = vertices[vId];
            adj.push_back(vertex);
        }
        adjacency[std::stoi(it.key())] = adj;
    }
};

/**
 * @brief operator<< overloading for graph
 * 
 * Prints out adjacency list.
 * 
 * @param out 
 * @param graph 
 * @return std::ostream& 
 */
std::ostream& operator << (std::ostream& out, const Graph &graph){
    for (auto& it : graph.adjacency){
        out << it.first << ": [";
        for (Vertex* vertex : it.second){
            out << *vertex << ",";
        }
        out << "]" << std::endl;
    }
    return out;
}

