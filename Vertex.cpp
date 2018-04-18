#include "Vertex.hpp"

Vertex::Vertex(int id) : id_(id) {};

int Vertex::id(){ return id_; };

std::ostream& operator<< (std::ostream &out, Vertex& vertex){
        return out << vertex.id();
    }
