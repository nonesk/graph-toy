#include "BGL_API.h"
#include <map>


/***********************
 * BGL API
 * *********************/
std::pair<Graph::vertex_iterator, Graph::vertex_iterator> vertices(Graph& g)
{
    return {g.vBegin(), g.vEnd()};
};

std::pair<Graph::vertex_iterator, Graph::vertex_iterator> vertices(const Graph& g)
{
    return {g.vcBegin(), g.vcEnd()};
};


Graph::vertices_size_type num_vertices(const Graph& g)
{
    return g.vSize();
};

Graph::vertex_descriptor source(Graph::edge_descriptor e, const Graph& g)
{
  return e->first;
};

Graph::vertex_descriptor target(Graph::edge_descriptor e, const Graph& g)
{
  return e->second;
};

std::pair<Graph::out_edge_iterator, Graph::out_edge_iterator>
out_edges(Graph::vertex_descriptor u, Graph& g)
{
    return {g.out_edge_begin(u), g.out_edge_end(u)};
}

std::pair<Graph::out_edge_iterator, Graph::out_edge_iterator>
out_edges(Graph::vertex_descriptor u, const Graph& g)
{
    return {g.out_edge_cbegin(u), g.out_edge_cend(u)};
}


Graph::edges_size_type num_edges(const Graph& g)
{
    return g.eSize();
};

std::pair<Graph::edge_iterator, Graph::edge_iterator> edges(Graph& g)
{
    return { g.eBegin(), g.eEnd() };
};

std::pair<Graph::edge_iterator, Graph::edge_iterator> edges(const Graph& g)
{
    return { g.ecBegin(), g.ecEnd() };
};


Graph::degree_size_type out_degree(Graph::vertex_descriptor u, const Graph& g)
{
    return g.out_degree(u);
}


/************************************
 * PROPERTY MAP CONCEPT
 * *********************************/

void put(
  std::map< Graph::vertex_descriptor,Graph::vertex_descriptor >& pmap, 
  Graph::vertex_descriptor key,
  Graph::vertex_descriptor value){
      pmap[key] = value;
  }

void put(
  std::map< Graph::vertex_descriptor, boost::default_color_type >& pmap, 
  Graph::vertex_descriptor key,
  boost::default_color_type value){
      pmap[key] = value;
  }

boost::default_color_type get(
  Graph::ColorMap& pmap, 
  Graph::vertex_descriptor& key){
      return pmap[key];
  }

boost::default_color_type get(
  const Graph::ColorMap& pmap, 
  Graph::vertex_descriptor& key){
      return pmap.at(key);
  }

Graph::ColorMap&  get(
  boost::vertex_color_t tag, 
  Graph& g){
      return g.getColorMap();
  }

const Graph::ColorMap&  get(
  boost::vertex_color_t tag, 
  const Graph& g){
      return g.getConstColorMap();
  }




boost::default_color_type get(
  boost::vertex_color_t tag, 
  Graph& g,
  Graph::vertex_descriptor v){
      return get(get(tag, g), v);
  }

boost::default_color_type get(
  boost::vertex_color_t tag, 
  const Graph& g,
  Graph::vertex_descriptor& v){
      return get(get(tag,g), v);
  }