// test substring 
#include <iostream> 
#include <cassert>
#include "string.hpp"

int main () 
{
    {
    String a = "abc";

    assert(a == "abc");
    assert(a.substr(0,1) == "ab");
    std::cout << a.substr(0,1) << " == " << "ab" << std::endl;
    }
    {
    String a = "abd";

    assert(a == "abd");
    assert(a.substr(0,2) == "abd");
    std::cout << a.substr(0,2) << " == " << "abd" << std::endl;
    }
    {
    String a = "ab";

    assert(a == "ab");
    assert(a.substr(0,0) == "a");
    std::cout << a.substr(0,0) << " == " << "a" << std::endl;
    }
    {
    String a = "abcdefg";

    assert(a == "abcdefg");
    assert(a.substr(0,4) == "abcde");
    std::cout << a.substr(0,4) << " == " << "abcde" << std::endl;
    }


    std::cout << "Done testing substring operator" << std::endl;
    return 0;
}