#ifndef DEF_GRAPH
#define DEF_GRAPH

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include "Vertex.h"
#include <boost/graph/graph_concepts.hpp>
#include <boost/property_map/property_map.hpp>

typedef std::set< Vertex* > VertexSet;
typedef std::pair <Vertex*, Vertex*> Edge;
typedef std::set< Edge* > EdgeSet;

class Graph
{
    public:

    // traversal category
    struct vertex_edge_list_tag : boost::vertex_list_graph_tag, 
                                  boost::edge_list_graph_tag,
                                  boost::incidence_graph_tag { };

    // GraphConcept Types
    using vertex_descriptor = Vertex*;
    using edge_descriptor = Edge*;
    using directed_category = boost::directed_tag;
    using edge_parallel_category = boost::allow_parallel_edge_tag;

    // VertexListConcept Types
    using traversal_category = vertex_edge_list_tag;
    using vertex_iterator = VertexSet::iterator;
    using vertex_const_iterator = VertexSet::const_iterator;
    using vertices_size_type = unsigned int;

    // EdgeListConcept Types
    using edge_iterator = EdgeSet::iterator;
    using edge_const_iterator = EdgeSet::const_iterator;
    using edges_size_type = unsigned int;

    //IncidenceGraph Type
    using out_edge_iterator = EdgeSet::iterator;
    using out_edge_const_iterator = EdgeSet::iterator;
    using degree_size_type = unsigned int;


    //Properties

    using ColorMap = std::map<vertex_descriptor, boost::default_color_type>;


    // constructor
    //Graph();
    Graph(std::string);

    // Vertices 
    vertex_iterator vBegin();
    vertex_iterator vEnd();
    vertex_const_iterator vcBegin() const;
    vertex_const_iterator vcEnd() const;
    Vertex* addVertex(int id);
    vertices_size_type vSize() const;
    Vertex* getVertex(int id);

    // Edges
    EdgeSet::iterator eBegin();
    EdgeSet::iterator eEnd();
    EdgeSet::iterator ecBegin() const;
    EdgeSet::iterator ecEnd() const;
    Edge* addEdge(Vertex* v1, Vertex* v2);
    Edge* addEdge(int id1, int id2);
    Graph::edges_size_type eSize() const;
    degree_size_type out_degree(vertex_descriptor u) const;

    out_edge_iterator out_edge_begin(vertex_descriptor u);
    out_edge_iterator out_edge_end(vertex_descriptor u);

    out_edge_const_iterator out_edge_cbegin(vertex_descriptor u) const;
    out_edge_const_iterator out_edge_cend(vertex_descriptor u) const;

    
    // Operators 
    friend std::ostream &operator<<(std::ostream &out, const Graph &graph);

    vertex_descriptor null_vertex() { return nullptr; }

    std::map <vertex_descriptor, int>& getMap();

    ColorMap& getColorMap();
    const ColorMap& getConstColorMap() const;

    const std::map <vertex_descriptor, int>& getMap() const;

    private:

    std::map < int, std::vector<vertex_descriptor> > adjacency; //adjacency list
    std::map <int, vertex_descriptor> vMap; // Vertices by id
    std::map <vertex_descriptor, int> vertex_index_; // Vertices to id
    

    std::map <vertex_descriptor, EdgeSet> in_edges_;
    std::map <vertex_descriptor, EdgeSet> out_edges_;

    ColorMap cmap;

    VertexSet vertices_; // Vertices set
    EdgeSet edges_; // Edges set
};




#endif
