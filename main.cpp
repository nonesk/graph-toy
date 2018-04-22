#include <iostream>
#include <string>
#include "Graph.hpp"

int main(int, char**) {
   Graph testGraph (std::string("adjacency.json"));
   std::cout << testGraph << std::endl;

   for (auto it = vertices(testGraph).first ;
        it != vertices(testGraph).second;
        ++it){
            std::cout<<**it<<std::endl;
        }
}
