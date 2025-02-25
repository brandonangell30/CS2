// test default constructor
#include <iostream> 
#include <cassert>
#include "string.hpp"
int main () {
    String str;
    std::cout << "\0 == " << str << std::endl;
    assert(str == '\0');
    std::cout << "Done testing default constructor." << std::endl;
    return 0;
}