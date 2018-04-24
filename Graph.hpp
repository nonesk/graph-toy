#ifndef DEF_GRAPH
#define DEF_GRAPH

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include "Vertex.hpp"
#include <boost/graph/graph_concepts.hpp>

typedef std::set< Vertex* > VertexSet;
typedef std::pair <Vertex*, Vertex*> Edge;
typedef std::set< Edge* > EdgeSet;

class Graph
{
    public:

    struct vertex_edge_list_tag : boost::vertex_list_graph_tag, boost::edge_list_graph_tag { };

    // GraphConcept Types
    using vertex_descriptor = Vertex*;
    using edge_descriptor = Edge*;
    using directed_category = boost::directed_tag;
    using edge_parallel_category = boost::allow_parallel_edge_tag;

    // VertexListConcept Types
    using traversal_category = vertex_edge_list_tag;
    using vertex_iterator = VertexSet::iterator;
    using vertices_size_type = unsigned int;

    // EdgeListConcept Types
    using edge_iterator = EdgeSet::iterator;
    using edges_size_type = unsigned int;

    //IncidenceGraph Type
    using out_edge_iterator = EdgeSet::iterator;



    // constructor
    Graph(std::string);

    // Vertices 
    VertexSet::iterator vBegin();
    VertexSet::iterator vEnd();
    Vertex* addVertex(int id);
    vertices_size_type vSize() const;
    Vertex* getVertex(int id);

    // Edges
    EdgeSet::iterator eBegin();
    EdgeSet::iterator eEnd();
    Edge* addEdge(Vertex* v1, Vertex* v2);
    Edge* addEdge(int id1, int id2);
    Graph::edges_size_type eSize() const;

    out_edge_iterator out_edge_begin(vertex_descriptor u);
    out_edge_iterator out_edge_end(vertex_descriptor u);

    
    // Operators 
    friend std::ostream &operator<<(std::ostream &out, const Graph &graph);

    vertex_descriptor null_vertex() { return nullptr; }

    private:

    std::map < int, std::vector<Vertex*> > adjacency; //adjacency list
    std::map <int, Vertex*> vMap; // Vertices by id

    std::map <Vertex*, EdgeSet> in_edges_;
    std::map <Vertex*, EdgeSet> out_edges_;

    VertexSet vertices_; // Vertices set
    EdgeSet edges_; // Edges set
};


/*******************
 * BGL expressions
 * *****************/

// VertexListConcept
std::pair<Graph::vertex_iterator, Graph::vertex_iterator> vertices(Graph& g);
std::pair<Graph::vertex_iterator, Graph::vertex_iterator> vertices(const Graph& g);
Graph::vertices_size_type num_vertices(const Graph& g);

// EdgesListConcept
Graph::edges_size_type num_edges(const Graph& g);
std::pair<Graph::edge_iterator, Graph::edge_iterator> edges(const Graph& g);

// IncidenceGraphConcept
Graph::vertex_descriptor source(Graph::edge_descriptor e, const Graph& g);
Graph::vertex_descriptor target(Graph::edge_descriptor e, const Graph& g);
std::pair<Graph::out_edge_iterator, Graph::out_edge_iterator> out_edges(Graph::vertex_descriptor u, Graph& g);


/***********************
 * Graph traits
 * *********************/

namespace boost {
  template <>
  struct graph_traits< Graph > {
    using vertex_descriptor = Graph::vertex_descriptor;
    using edge_descriptor = Graph::edge_descriptor;
    using directed_category = Graph::directed_category;
    using edge_parallel_category = Graph::edge_parallel_category;
    using traversal_category = Graph::traversal_category;

    // iterator typedefs...
    using vertex_iterator = Graph::vertex_iterator;
    using edge_iterator = Graph::edge_iterator;
    using out_edge_iterator = Graph::out_edge_iterator;
    using vertices_size_type = Graph::vertices_size_type;
    using edges_size_type = Graph::edges_size_type;
  };

  BOOST_CONCEPT_ASSERT((VertexAndEdgeListGraphConcept<Graph>));
  //BOOST_CONCEPT_ASSERT((EdgeListGraphConcept<Graph>));
} // namespace boost

#endif
