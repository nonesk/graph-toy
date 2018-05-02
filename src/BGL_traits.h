#ifndef BGL_TRAITS
#define BGL_TRAITS

#include "BGL_API.h"
#include "Graph.h"
#include <boost/graph/graph_concepts.hpp>
#include <boost/property_map/property_map.hpp>

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

  template <>
  struct property_traits< Graph::ColorMap > {
    using value_type = boost::default_color_type;
    using key_type = Graph::vertex_descriptor;
    using category = read_write_property_map_tag;
    using reference = boost::default_color_type&;
  };

  template <>
  struct property_traits< const Graph::ColorMap > {
    using value_type = boost::default_color_type;
    using key_type = Graph::vertex_descriptor;
    using category = read_write_property_map_tag;
    using reference = boost::default_color_type&;
  };

  template <>
  struct property_map<Graph, vertex_color_t> {
    using type = Graph::ColorMap;
    using const_type = const Graph::ColorMap;
  };



  // template <>
  // struct property_map<Graph, vertex_index_t> {
  //   using type = std::map<Graph::vertex_descriptor, int> ;
  //   using const_type = const std::map<Graph::vertex_descriptor, int> ;
  // };


 

  BOOST_CONCEPT_ASSERT((VertexAndEdgeListGraphConcept<Graph>));
  BOOST_CONCEPT_ASSERT((IncidenceGraphConcept<Graph>));
  BOOST_CONCEPT_ASSERT((WritablePropertyMapConcept< std::map< Graph::vertex_descriptor, Graph::vertex_descriptor>, Graph::vertex_descriptor>));
  BOOST_CONCEPT_ASSERT((WritablePropertyMapConcept<  std::map< Graph::vertex_descriptor, boost::default_color_type>, Graph::vertex_descriptor>));
  BOOST_CONCEPT_ASSERT((PropertyGraphConcept<Graph, Graph::vertex_descriptor, vertex_color_t>));
} // namespace boost

#endif //BGL_TRAITS