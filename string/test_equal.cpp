// test == and !=
#include <iostream> 
#include <cassert>
#include "string.hpp"
int main () 
{
    {
    String a = "abc";
    String b = "abc";

    assert(a == "abc");
    assert(b == "abc");
    assert(a == b);
    std::cout << a << " == " << b << std::endl;
    }
    {
    String a = "abd";
    String b = "abc";

    assert(a == "abd");
    assert(b == "abc");
    assert(a != b);
    std::cout << a << " != " << b << std::endl; 
    }
    {
    String a = "abcdef";
    String b = "abcdef";

    assert(a == "abcdef");
    assert(b == "abcdef");
    assert(a == b);
    std::cout << a << " == " << b << std::endl; 
    }
    {String a = "a";
    String b = "ab";

    assert(a == "a");
    assert(b == "ab");
    assert(a != b);
    std::cout << a << " != " << b << std::endl; 
    }
    {
    String a = "abcdefghijklmnop";
    String b = "abcdefghijklmnop";

    assert(a == "abcdefghijklmnop");
    assert(b == "abcdefghijklmnop");
    assert(a == b);
    std::cout << a << " == " << b << std::endl; 
    }
    
    std::cout << "Done testing == and != operator" << std::endl;
    return 0;
}