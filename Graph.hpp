#ifndef DEF_GRAPH
#define DEF_GRAPH

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include "Vertex.hpp"

struct classcomp {
  bool operator() (const Vertex* lhs, const Vertex* rhs) const
  {return lhs->id() < rhs->id() ;}
};

class Graph
{
    public:

    Graph(std::string);
    std::set<Vertex*>::iterator setBegin();
    std::set<Vertex*>::iterator setEnd();
    friend std::ostream &operator<<(std::ostream &out, const Graph &graph);

    private:

    std::map < int, std::vector<Vertex*> > adjacency;
    std::map <int, Vertex*> vertices;
    std::set<Vertex*, classcomp> vertexSet_;
};

std::pair<std::set<Vertex*, classcomp>::iterator, std::set<Vertex*, classcomp>::iterator> vertices(const Graph g);

#endif
