#ifndef BGL_API_H
#define BGL_API_H

#include "Graph.h"
/*******************
 * BGL expressions
 * *****************/

 // VertexListConcept

/**
 * @brief Returns a pair of iterator on Graph's vertex
 * 
 * @param g Graph reference
 * @return std::pair<Graph::vertex_iterator, Graph::vertex_iterator> 
 */
std::pair<Graph::vertex_iterator, Graph::vertex_iterator> 
vertices(Graph& g);

/**
 * @brief Returns a pair of iterator on Graph's vertex (const version)
 * 
 * @param g Graph reference (const)
 * @return std::pair<Graph::vertex_iterator, Graph::vertex_iterator> 
 */
std::pair<Graph::vertex_iterator, Graph::vertex_iterator> 
vertices(const Graph& g);

/**
 * @brief Returns the number of vertex in Graph
 * 
 * @param g Graph reference (const)
 * @return Graph::vertices_size_type 
 */
Graph::vertices_size_type 
num_vertices(const Graph& g);

// EdgesListConcept

/**
 * @brief Returns number of edges in Graph
 * 
 * @param g Graph reference (const)
 * @return Graph::edges_size_type 
 */
Graph::edges_size_type 
num_edges(const Graph& g);

/**
 * @brief Returns a pair of iterator on Graph's edge list
 * 
 * @param g Graph reference (const)
 * @return std::pair<Graph::edge_iterator, Graph::edge_iterator> 
 */
std::pair<Graph::edge_iterator, Graph::edge_iterator> 
edges(const Graph& g);

// IncidenceGraphConcept

/**
 * @brief Return the tail vertex of an edge
 * 
 * @param e Edge descriptor
 * @param g Graph reference
 * @return Graph::vertex_descriptor Source vertex
 */
Graph::vertex_descriptor 
source(Graph::edge_descriptor e, const Graph& g);

/**
 * @brief Returns the head vertex of an edge
 * 
 * @param e Edge descriptor
 * @param g Graph reference
 * @return Graph::vertex_descriptor Head vertex
 */
Graph::vertex_descriptor 
target(Graph::edge_descriptor e, const Graph& g);

/**
 * @brief Returns a pair of iterator on out-going edges of a vertex
 * 
 * @param u Vertex descriptor
 * @param g Graph reference
 * @return std::pair<Graph::out_edge_iterator, Graph::out_edge_iterator>  Edge iterators
 */
std::pair<Graph::out_edge_iterator, Graph::out_edge_iterator> 
out_edges(Graph::vertex_descriptor u, Graph& g);

/**
 * @brief Returns a pair of iterator on out-going edges of a vertex (const version)
 * 
 * @param u Vertex descriptor
 * @param g Graph reference (const)
 * @return std::pair<Graph::out_edge_iterator, Graph::out_edge_iterator>  Edge iterators
 */
std::pair<Graph::out_edge_iterator, Graph::out_edge_iterator> 
out_edges(Graph::vertex_descriptor u, const Graph& g);

/**
 * @brief Return the number of outgoing edges from a vertex
 * 
 * @param u Vertex descriptor
 * @param g Graph reference
 * @return Graph::degree_size_type Number of out-going edges
 */
Graph::degree_size_type 
out_degree(Graph::vertex_descriptor u, const Graph& g);


/*******************************************************************
 * PROPERTY MAPS
 * *****************************************************************/


/**********************************************
 * PREDECESSOR MAP
 * ********************************************/

/**
 * @brief Put parent vertex in Predecessor Map
 * 
 * @param pmap Predecessor Map 
 * @param key Child vertex
 * @param value Parent vertex
 */
void put(
  std::map< Graph::vertex_descriptor,Graph::vertex_descriptor >& pmap, 
  Graph::vertex_descriptor key,
  Graph::vertex_descriptor value);


/*********************************************
 * COLOR MAP
 * *******************************************/

/**
 * @brief Set vertex color
 * 
 * @param pmap Color map
 * @param key Vertex to update
 * @param value Color value
 */
void put(
  Graph::ColorMap& pmap, 
  Graph::vertex_descriptor key,
  boost::default_color_type value);

/**
 * @brief Set vertex property for PropertyTag color
 * 
 * @param ptag Property tag for color map
 * @param g Graph reference
 * @param vertex Vertex reference
 * @param color Color value
 */
void put(
  boost::vertex_color_t ptag,
  Graph& g, 
  Graph::vertex_descriptor& vertex,
  boost::default_color_type color);

/**
 * @brief Get color value for Vertex from ColorMap
 * 
 * @param pmap Color map
 * @param key Vertex descriptor
 * @return boost::default_color_type Color value
 */
boost::default_color_type get(
  Graph::ColorMap& pmap, 
  Graph::vertex_descriptor& key);


/**
 * @brief Get color value for Vertex from ColorMap (const version)
 * 
 * @param pmap Color map
 * @param key Vertex descriptor
 * @return boost::default_color_type Color value
 */
boost::default_color_type get(
  const Graph::ColorMap& pmap, 
  Graph::vertex_descriptor& key);

/**
 * @brief Get color map using PropertyTag
 * 
 * @param tag Property tag
 * @param g Graph reference
 * @return Graph::ColorMap& ColorMap reference 
 */
Graph::ColorMap& get(
  boost::vertex_color_t tag, 
  Graph& g);

/**
 * @brief Get color map using PropertyTag (const version)
 * 
 * @param tag Property tag
 * @param g Graph reference
 * @return Graph::ColorMap& ColorMap reference 
 */
const Graph::ColorMap& get(
  boost::vertex_color_t tag, 
  const Graph& g);


/**
 * @brief Get color of vertex using PropertyTag
 * 
 * @param tag Property tag
 * @param g Graph reference
 * @param v Vertex descriptor
 * @return boost::default_color_type Color value
 */
boost::default_color_type get(
  boost::vertex_color_t tag, 
  Graph& g,
  Graph::vertex_descriptor& v);

/**
 * @brief Get color of vertex using PropertyTag (const version)
 * 
 * @param tag Property tag
 * @param g Graph reference (const)
 * @param v Vertex descriptor
 * @return boost::default_color_type Color value
 */
boost::default_color_type get(
  boost::vertex_color_t tag, 
  const Graph& g,
  Graph::vertex_descriptor& v);


#endif //BGL_API_H