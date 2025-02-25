// test length
#include <iostream> 
#include <cassert>
#include "string.hpp"

int main () 
{
    {
    String a = "a";

    assert(a == "a");
    assert(a.length() == 1);
    std::cout << a << " ==  has a length of: " << a.length() << std::endl;
    }
 {
    String a = "ab";

    assert(a == "ab");
    assert(a.length() == 2);
    std::cout << a << " ==  has a length of: " << a.length() << std::endl;
    }
 {
    String a = "abc";

    assert(a == "abc");
    assert(a.length() == 3);
    std::cout << a << " ==  has a length of: " << a.length() << std::endl;
    }
     {
    String a = "abcd";

    assert(a == "abcd");
    assert(a.length() == 4);
    std::cout << a << " ==  has a length of: " << a.length() << std::endl;
    }
     {
    String a = "abcde";

    assert(a == "abcde");
    assert(a.length() == 5);
    std::cout << a << " ==  has a length of: " << a.length() << std::endl;
    }
     {
    String a = "abcdef";

    assert(a == "abcdef");
    assert(a.length() == 6);
    std::cout << a << " ==  has a length of: " << a.length() << std::endl;
    }
     {
    String a = "abcdefg";

    assert(a == "abcdefg");
    assert(a.length() == 7);
    std::cout << a << " ==  has a length of: " << a.length() << std::endl;
    }
    std::cout << "Done testing length method" << std::endl;
    return 0;
}