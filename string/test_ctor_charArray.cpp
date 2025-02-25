// test char array constructor
#include <iostream> 
#include <cassert>
#include "string.hpp"
int main () {
    String str = "abc";
    assert(str == "abc");
    std::cout << "abc == " << str << std::endl;
    std::cout << "Done testing char array constructor." << std::endl;
    return 0;
}