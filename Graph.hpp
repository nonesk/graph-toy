#ifndef DEF_GRAPH
#define DEF_GRAPH

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include "Vertex.hpp"
#include <boost/graph/graph_concepts.hpp>

// used to sort vertex set
struct classcomp {
  bool operator() (const Vertex* lhs, const Vertex* rhs) const
  {return lhs->id() < rhs->id() ;}
};

typedef std::set< Vertex*, classcomp > VertexSet;
typedef std::pair <Vertex*, Vertex*> Edge;
typedef std::set< Edge* > EdgeSet;

class Graph
{
    public:

    Graph(std::string);
    VertexSet::iterator vBegin();
    VertexSet::iterator vEnd();
    Vertex* addVertex(int id);
    unsigned int vSize() const;

    EdgeSet::iterator eBegin();
    EdgeSet::iterator eEnd();
    Edge* addEdge(Vertex* v1, Vertex* v2);
    Edge* addEdge(int id1, int id2);
    
    friend std::ostream &operator<<(std::ostream &out, const Graph &graph);

    private:

    std::map < int, std::vector<Vertex*> > adjacency;
    std::map <int, Vertex*> vMap;
    VertexSet vertices_;
    EdgeSet edges_;
};


namespace boost {
  template<>
  struct graph_traits< Graph > {
    typedef Vertex vertex_descriptor;
    

    // iterator typedefs...
    typedef VertexSet::iterator vertex_iterator;

    typedef unsigned int vertices_size_type;
  };


  std::pair<VertexSet::iterator, VertexSet::iterator> vertices(Graph& g);

  unsigned int num_vertices(Graph& g);
} // namespace boost


#endif
