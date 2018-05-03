#include "Vertex.h"


Vertex::Vertex(int id, Vertex::Type t) : id_(id), type_(t) {};

const int Vertex::id() const { return id_; };

const Vertex::Type Vertex::type() const{
    return type_;
}

void Vertex::setType(Vertex::Type t){
    type_ = t;
}

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