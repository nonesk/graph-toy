#include "Graph.h"
#include <boost/graph/graph_concepts.hpp>

/*******************
 * BGL expressions
 * *****************/

// VertexListConcept
std::pair<Graph::vertex_iterator, Graph::vertex_iterator> 
vertices(Graph& g);

std::pair<Graph::vertex_iterator, Graph::vertex_iterator> 
vertices(const Graph& g);

Graph::vertices_size_type 
num_vertices(const Graph& g);

// EdgesListConcept
Graph::edges_size_type 
num_edges(const Graph& g);

std::pair<Graph::edge_iterator, Graph::edge_iterator> 
edges(const Graph& g);

// IncidenceGraphConcept
Graph::vertex_descriptor 
source(Graph::edge_descriptor e, const Graph& g);

Graph::vertex_descriptor 
target(Graph::edge_descriptor e, const Graph& g);

std::pair<Graph::out_edge_iterator, Graph::out_edge_iterator> 
out_edges(Graph::vertex_descriptor u, Graph& g);

std::pair<Graph::out_edge_iterator, Graph::out_edge_iterator> 
out_edges(Graph::vertex_descriptor u, const Graph& g);

Graph::degree_size_type 
out_degree(Graph::vertex_descriptor u, const Graph& g);


// Property map concept

void put(
  std::map< Graph::vertex_descriptor,Graph::vertex_descriptor >& pmap, 
  Graph::vertex_descriptor key,
  Graph::vertex_descriptor value);

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
    using degree_size_type = Graph::degree_size_type;

    static Graph::vertex_descriptor null_vertex() { return nullptr;};
  };

  template <>
  struct property_traits< std::map< Graph::vertex_descriptor, Graph::vertex_descriptor> > {
    using value_type = Graph::vertex_descriptor;
    using key_type = Graph::vertex_descriptor;
    using category = read_write_property_map_tag;
  };


  BOOST_CONCEPT_ASSERT((VertexAndEdgeListGraphConcept<Graph>));
  BOOST_CONCEPT_ASSERT((IncidenceGraphConcept<Graph>));
  BOOST_CONCEPT_ASSERT((WritablePropertyMapConcept< std::map< Graph::vertex_descriptor, Graph::vertex_descriptor>, Graph::vertex_descriptor>));
} // namespace boost