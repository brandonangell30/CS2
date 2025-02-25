// File: main.cpp
//
// CS 23001 Project 1 bigint 
//
// Basics for openning a file for milestone 2
//

#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in;            // Define input stream
    in.open("data1-1.txt");      // Open a file
    if(!in) {                    // Make sure file opened correctly
        std::cerr << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }
    
    //Until end of file
       //Read two bigints
       //Print them out
       //Add them together
       //Print out results
 bigint lhs, rhs, result = 0;
    while(!in.eof()){
        in >> lhs;
        if(in.eof()){
            break;
        }
        in >> rhs;
        std::cout << "The first bigint: " << lhs << std::endl;
        std::cout << "The second bigint: " << rhs << std::endl;
        result = lhs + rhs;
        std::cout << "The addition of both bigints is: " << result << std::endl;
    }
    in.close();
    return 0;
}