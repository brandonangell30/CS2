// test char constructor
#include <iostream> 
#include <cassert>
#include "string.hpp"
int main () {
    String str = 'c';
    assert(str == 'c');
    std::cout << "c == " << str << std::endl;
    std::cout << "Done testing char constructor." << std::endl;
    return 0;
}