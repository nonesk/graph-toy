#ifndef DEF_GRAPH
#define DEF_GRAPH

#include <string>
#include <vector>
#include <iostream>

class Graph
{
    public:

    Graph(std::string);
    friend std::ostream &operator<<(std::ostream &out, const Graph &graph);

    private:

    std::vector<std::vector<int>> adjacency;
};

#endif