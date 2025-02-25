// test findchar
#include <iostream> 
#include <cassert>
#include "string.hpp"
int main () 
{
    {
    String a = "abc";

    assert(a == "abc");
    assert(a.findch(0, 'a') == 0);
    std::cout << "a was found at index: "<<  a.findch(0, 'a') << std::endl;
    }
    {
    String a = "abc";

    assert(a == "abc");
    assert(a.findch(0, 'b') == 1);
    std::cout << "a was found at index: "<<  a.findch(0, 'b') << std::endl;
    }

    {
    String a = "abc";

    assert(a == "abc");
    assert(a.findch(0, 'c') == 2);
    std::cout << "a was found at index: "<<  a.findch(0, 'c') << std::endl;
    }
    {
    String a = "abcd";

    assert(a == "abcd");
    assert(a.findch(0, 'd') == 3);
    std::cout << "a was found at index: "<<  a.findch(0, 'd') << std::endl;
    }
    {
    String a = "abcdef";

    assert(a == "abcdef");
    assert(a.findch(0, 'f') == 5);
    std::cout << "a was found at index: "<<  a.findch(0, 'f') << std::endl;
    }
    {
    String a = "aaa";

    assert(a == "aaa");
    assert(a.findch(0, 'a') == 0);
    std::cout << "a was found at index: "<<  a.findch(0, 'a') << std::endl;
    }

    std::cout << "Done testing findchar method" << std::endl;
    return 0;
}