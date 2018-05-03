#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>

/**
 * @brief Vertex class
 * 
 */
class Vertex{
    public:
    enum Type {PROD, REAC};
    Vertex() {};
    Vertex(int id, Vertex::Type t = PROD);

    const int id() const;
    const Type type() const;
    void setType(Type t);

    /**
     * @brief Operator << overload
     * 
     * @param out 
     * @param vertex 
     * @return std::ostream& 
     */
    friend std::ostream& operator<< (std::ostream &out, Vertex& vertex);
    //friend bool operator< (Vertex const* v1, Vertex const* v2) const;
    friend bool operator==(const Vertex& lhs, const Vertex& rhs);
    friend bool operator!=(const Vertex& lhs, const Vertex& rhs);
    friend bool operator<(const Vertex& lhs, const Vertex& rhs);
    
    
    private:
    int id_;
    
    Vertex::Type type_;
};



#endif //VERTEX_HPP
