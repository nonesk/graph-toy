#ifndef DEF_GRAPH
#define DEF_GRAPH

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "Vertex.hpp"


class Graph
{
    public:

    Graph(std::string);
    friend std::ostream &operator<<(std::ostream &out, const Graph &graph);

    private:

    std::map < int, std::vector<Vertex*> > adjacency;
    std::map <int, Vertex*> vertices;
};

#endif
