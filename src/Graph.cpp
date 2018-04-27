#include "Graph.h"

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
        vertex_index_[vMap[id]] = id;
        vertices_.insert(vMap[id]); // add to vertex set
        in_edges_[vMap[id]] = std::set<edge_descriptor>();
        out_edges_[vMap[id]] = std::set<edge_descriptor>();
    }
    return vMap[id];
}

Edge* Graph::addEdge(Vertex* v1, Vertex* v2)
{
    Edge* edge = new Edge(v1, v2);
    edges_.insert(edge);
    in_edges_[v2].insert(edge);
    out_edges_[v1].insert(edge);
    return edge;
}

Edge* Graph::addEdge(int id1, int id2)
{
    Vertex* v1 = vMap[id1];
    Vertex* v2 = vMap[id2];
    return addEdge(v1,v2);
}


Graph::vertex_iterator Graph::vBegin(){
    return vertices_.begin();
};

Graph::vertex_iterator Graph::vEnd(){
    return vertices_.end();
};

Graph::vertex_const_iterator Graph::vcBegin() const {
    return vertices_.cbegin();
};

Graph::vertex_const_iterator Graph::vcEnd() const {
    return vertices_.cend();
};

EdgeSet::iterator Graph::eBegin(){
    return edges_.begin();
};
EdgeSet::iterator Graph::eEnd(){
    return edges_.end();
};

EdgeSet::iterator Graph::ecBegin() const {
    return edges_.cbegin();
};
EdgeSet::iterator Graph::ecEnd() const {
    return edges_.cend();
};

Graph::out_edge_iterator Graph::
out_edge_begin(Graph::vertex_descriptor u) {
    return out_edges_[u].begin();
}

Graph::out_edge_iterator Graph::
out_edge_end(Graph::vertex_descriptor u) {
    return out_edges_[u].end();
}

Graph::out_edge_const_iterator Graph::
out_edge_cbegin(Graph::vertex_descriptor u) const {
    return out_edges_.at(u).cbegin();
}

Graph::out_edge_const_iterator Graph::
out_edge_cend(Graph::vertex_descriptor u) const {
    return out_edges_.at(u).cend();
}

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


Graph::vertex_descriptor Graph::getVertex(int id)
{
    return vMap[id];
}

std::map <Graph::vertex_descriptor, int>& Graph::getMap()
{
    std::map<Graph::vertex_descriptor, int>& ref = vertex_index_;
    return ref;
}

Graph::edges_size_type Graph::eSize() const
{
    return edges_.size();
}

Graph::degree_size_type Graph::out_degree(vertex_descriptor u) const{
    return out_edges_.at(u).size();
}


