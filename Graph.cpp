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
        int currentVertexId = std::stoi(it.key());
        Vertex* currentVertex = addVertex(currentVertexId);
        auto const adj_json = it.value();
        std::vector<Vertex*> adj;
        // iterate over adjacency list
        for (auto& vertexId: adj_json){
            int vId = vertexId.get<int>();
            Vertex* vertex = addVertex(vId);
            adj.push_back(vertex); // add to adjacency
            addEdge(currentVertex, vertex);
        }
        adjacency[std::stoi(it.key())] = adj;
    }
    
};

Vertex* Graph::addVertex(int id)
{
    std::map<int, Vertex*>::iterator v = vMap.find(id);
    if (v == vMap.end()){ //create vertex if not found
        vMap[id] = new Vertex(id);
        vertices_.insert(vMap[id]); // add to vertex set
    }
    return vMap[id];
}

Edge* Graph::addEdge(Vertex* v1, Vertex* v2)
{
    Edge* edge = new Edge(v1, v2);
    edges_.insert(edge);
    return edge;
}

Edge* Graph::addEdge(int id1, int id2)
{
    Edge* edge = new Edge(vMap[id1], vMap[id2]);
    edges_.insert(edge);
    return edge;
}


VertexSet::iterator Graph::vBegin(){
    return vertices_.begin();
};

VertexSet::iterator Graph::vEnd(){
    return vertices_.end();
};

EdgeSet::iterator Graph::eBegin(){
    return edges_.begin();
};
EdgeSet::iterator Graph::eEnd(){
    return edges_.end();
};

unsigned int Graph::vSize() const
{
    return vertices_.size();
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
};


std::pair<VertexSet::iterator, VertexSet::iterator> boost::vertices(Graph& g)
{
    return {g.vBegin(), g.vEnd()};
};


unsigned int boost::num_vertices(Graph& g)
{
    return g.vSize();
};