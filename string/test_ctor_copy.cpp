//test copy constructor
#include "string.hpp"
#include <cassert>
#include <iostream>
int main ()
{
    {
        String str("abc");
        String copy(str);

        assert(copy == str);
        assert(str == "abc");
        assert(copy == "abc");
    }
    {
        String str('\0');
        String copy(str);

        assert(copy == str);
        assert(str == "");
        assert(copy == "");
    }
{
        String str("asdfghjkl");
        String copy(str);

        assert(copy == str);
        assert(str == "asdfghjkl");
        assert(copy == "asdfghjkl");
    }
    {
        String str("a");
        String copy(str);

        assert(copy == str);
        assert(str == "a");
        assert(copy == "a");
    }
    {
        String str("cat");
        String copy(str);

        assert(copy == str);
        assert(str == "cat");
        assert(copy == "cat");
    }
    {
        String str("qwertyuiopasdfghjklzxcvbnmmnbvcxzlkjhgfdsapoiuytrewq");
        String copy(str);

        assert(copy == str);
        assert(str == "qwertyuiopasdfghjklzxcvbnmmnbvcxzlkjhgfdsapoiuytrewq");
        assert(copy == "qwertyuiopasdfghjklzxcvbnmmnbvcxzlkjhgfdsapoiuytrewq");
    }
    std::cout << "Done testing the copy constructor " << std::endl;
    return 0;
}

