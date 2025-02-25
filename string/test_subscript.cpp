//tests [] operator
#include <iostream> 
#include <cassert>
#include "string.hpp"
int main () 
{
    {
    String a = "abc";

    assert(a == "abc");
    assert(a[1] == 'b');
    std::cout << a[1] << " == " << 'b' << std::endl;
    }
    {
    String a = "abc";

    assert(a == "abc");
    assert(a[0] == 'a');
    std::cout << a[0] << " == " << 'a' << std::endl;
    }
    {
    String a = "abc";

    assert(a == "abc");
    assert(a[2] == 'c');
    std::cout << a[2] << " == " << 'c' << std::endl;
    }
    {
    String a = "abcdef";

    assert(a == "abcdef");
    assert(a[3] == 'd');
    std::cout << a[3] << " == " << 'd' << std::endl;
    }
    {
    String a = "abcdef";

    assert(a == "abcdef");
    assert(a[4] == 'e');
    std::cout << a[4] << " == " << 'e' << std::endl;
    }
    {
    String a = "abcdef";

    assert(a == "abcdef");
    assert(a[5] == 'f');
    std::cout << a[5] << " == " << 'f' << std::endl;
    }

    std::cout << "Done testing subscript operator" << std::endl;
    return 0;
}