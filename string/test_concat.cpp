// tests +
#include <iostream>
#include <cassert>
#include "string.hpp"

int main()
{
    {
    String one = "a";
    String two = "ab";
    String result = one+two;

    assert(one == "a");
    assert(two == "ab");
    assert(result == "aab");
    std::cout << one << "+ " <<two << " = " << result << std::endl;
    }

    {
    String one = "abc";
    String two = "def";
    String result = one+two;

    assert(one == "abc");
    assert(two == "def");
    assert(result == "abcdef");
    std::cout << one << "+ " <<two << " = " << result << std::endl;
    }
    {
    String one = "abcdefg";
    String two = "abcdefg";
    String result = one+two;

    assert(one == "abcdefg");
    assert(two == "abcdefg");
    assert(result == "abcdefgabcdefg");
    std::cout << one << "+ " <<two << " = " << result << std::endl;
    }
    {
    String one = "abcxxx";
    String two = "yyuio";
    String result = one+two;

    assert(one == "abcxxx");
    assert(two == "yyuio");
    assert(result == "abcxxxyyuio");
    std::cout << one << "+ " <<two << " = " << result << std::endl;
    }

    std::cout << "Done testing + operator" << std::endl;
    return 0;
}