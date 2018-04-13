#include <iostream>
#include <string>
#include "Graph.h"

int main(int, char**) {
   Graph testGraph (std::string("adjacency.json"));
   std::cout << testGraph;
}
