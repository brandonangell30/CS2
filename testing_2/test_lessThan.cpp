#include <iostream>
#include "string.hpp"
#include <cassert>
int main (){
    {
    String one("a");
    String two("ab");
    assert(one < two);
    std::cout << one << " is < " << two << std::endl;
}

{
    String one("aa");
    String two("abb");
    assert(one < two);
    std::cout << one << " is < " << two << std::endl;
}

{
    String one("abc");
    String two("xyz");
    assert(one < two);
    std::cout << one << " is < " << two << std::endl;
}

{
    String one("apple");
    String two("banana");
    assert(one < two);
    std::cout << one << " is < " << two << std::endl;
}

{
    String one("abc");
    String two("abcd");
    assert(one < two);
    std::cout << one << " is < " << two << std::endl;
}

{
    String one("Apple");
    String two("apple");
    assert(one < two);
    std::cout << one << " is < " << two << std::endl;
}

{
    String one("123");
    String two("23");
    assert(one < two);
    std::cout << one << " is < " << two << std::endl;
}

{
    String one("dog");
    String two("cat");
    assert(two < one);
    std::cout << two << " is < " << one << std::endl;
}

{
    String one("hello");
    String two(" hello");
    assert(two < one);
    std::cout << two << " is < " << one << std::endl;
}

std::cout << "Done testing less than" << std::endl;

}