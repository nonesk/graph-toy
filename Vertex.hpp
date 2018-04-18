#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>

/**
 * @brief Vertex class
 * 
 */
class Vertex{
    public:

    Vertex(int id);


    int id();

    /**
     * @brief Operator << overload
     * 
     * @param out 
     * @param vertex 
     * @return std::ostream& 
     */
    friend std::ostream& operator<< (std::ostream &out, Vertex& vertex);

    private:
    int id_;
};


#endif //VERTEX_HPP
