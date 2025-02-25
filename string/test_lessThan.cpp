// tests <
#include <iostream>
#include <cassert>
#include "string.hpp"

int main()
{
    {
    String one = "a";
    String two = "ab";
    
    assert(one == "a");
    assert(two == "ab");
    assert(one < two);
    std::cout << one << "is < " << two << std::endl;
    }
    
    {
    String one = "ab";
    String two = "abc";
    
    assert(one == "ab");
    assert(two == "abc");
    assert(one < two);
    std::cout << one << "is < " << two << std::endl;
    }

    {
    String one = "abc";
    String two = "ab";
    
    assert(one == "abc");
    assert(two == "ab");
    assert(one > two);
    std::cout << one << "is > " << two << std::endl;
    }
    
{
    String one = "abcdefg";
    String two = "abcdefghi";
    
    assert(one == "abcdefg");
    assert(two == "abcdefghi");
    assert(one < two);
    std::cout << one << "is < " << two << std::endl;
    }


std::cout << "Done testing < and > operator" << std::endl;
    return 0;
}