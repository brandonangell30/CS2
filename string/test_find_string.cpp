// test findstr
#include <iostream> 
#include <cassert>
#include "string.hpp"
int main () 
{
    {
    String a = "abc";

    assert(a == "abc");
    assert(a.findstr(0, "ab") == 0);
    std::cout << "ab was found at index: "<<  a.findstr(0, "ab") << std::endl;
    }
    {
    String a = "abcdef";

    assert(a == "abcdef");
    assert(a.findstr(0, "bc") == 1);
    std::cout << "bc was found at index: "<<  a.findstr(0, "bc") << std::endl;
    }
    {
    String a = "abc";

    assert(a == "abc");
    assert(a.findstr(0, "c") == 2);
    std::cout << "c was found at index: "<<  a.findstr(0, "c") << std::endl;
    }
    {
    String a = "abc";

    assert(a == "abc");
    assert(a.findstr(0, "a") == 0);
    std::cout << "a was found at index: "<<  a.findstr(0, "a") << std::endl;
    }
    {
    String a = "abcdefg";

    assert(a == "abcdefg");
    assert(a.findstr(0, "def") == 3);
    std::cout << "def was found at index: "<<  a.findstr(0, "def") << std::endl;
    }
    {
    String a = "bca";

    assert(a == "bca");
    assert(a.findstr(0, "ca") == 1);
    std::cout << "ca was found at index: "<<  a.findstr(0, "ca") << std::endl;
    }

    std::cout << "Done testing find string method" << std::endl;
    return 0;
}