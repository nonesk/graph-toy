#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>

/**
 * @brief Vertex class
 * 
 */
class Vertex{
    public:

    Vertex() {};
    Vertex(int id);

    const int id() const;

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
};



#endif //VERTEX_HPP
