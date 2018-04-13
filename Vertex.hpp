#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>

/**
 * @brief Vertex class
 * 
 */
class Vertex{
    public:

    Vertex(int);
    Vertex(int idArg) : id(idArg){};


    int getId(){ return id; }

    /**
     * @brief Operator << overload
     * 
     * @param out 
     * @param vertex 
     * @return std::ostream& 
     */
    friend std::ostream& operator<< (std::ostream &out, Vertex& vertex){
        return out << vertex.getId();
    }

    private:
    int id;
};


#endif //VERTEX_HPP