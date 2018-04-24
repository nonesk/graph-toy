#include "Vertex.hpp"


Vertex::Vertex(int id) : id_(id) {};

const int Vertex::id() const { return id_; };

std::ostream& operator<< (std::ostream &out, Vertex& vertex){
        return out << vertex.id();
    }

// bool operator< (Vertex const* v1, Vertex const* v2){
//     return v1->id() < v2->id();
// }

bool operator==(const Vertex& lhs, const Vertex& rhs) {
    return rhs.id_ == lhs.id_;
}

bool operator!=(const Vertex& lhs, const Vertex& rhs) {
    return not (lhs == rhs);
}

bool operator<(const Vertex& lhs, const Vertex& rhs){
    return lhs.id_ < rhs.id_;
}