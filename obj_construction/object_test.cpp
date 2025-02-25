#include "object_construction.hpp"
#include <iostream>

int main(){
    object test; // Default constructor
    std::cout << "Called {Default Constructor}" << std::endl;

    object other; 
    std::cout << "Called {Default Constructor}" << std::endl;

    object copyTest = other; // Copy constructor
    std::cout << "Called {Copy Constructor}" << std::endl;

    test = other; // Assignment operator
    std::cout << "Called {Assignment Operator}" << std::endl;

    test.~object();//destructor
    std::cout << "Called {Destructor}" << std::endl;
    return 0;
}