//tests swap
#include "string.hpp"
#include <cassert>
#include <iostream> 
int main ()
{
    {
        String left("abc");
        String right("def");
        left.swap(right);

        assert(left == "def");
        assert(right == "abc");
    }
    {
        String left("abcdef");
        String right("xxx");
        left.swap(right);

        assert(left == "xxx");
        assert(right == "abcdef");
    }
    {
        String left("a");
        String right("b");
        left.swap(right);

        assert(left == "b");
        assert(right == "a");
    }
    {
        String left("abcdef");
        String right("qwerty");
        left.swap(right);

        assert(left == "qwerty");
        assert(right == "abcdef");
    }
    {
        String left("abc");
        String right("def");
        right.swap(left);

        assert(left == "def");
        assert(right == "abc");
    }
    {
        String left("abcdef");
        String right("lolol");
        right.swap(left);

        assert(left == "lolol");
        assert(right == "abcdef");
    }
    {
        String left("chu");
        String right("ano");
        right.swap(left);

        assert(left == "ano");
        assert(right == "chu");
    }
    {
        String left("yo");
        String right("mannnnn");
        right.swap(left);

        assert(left == "mannnnn");
        assert(right == "yo");
    }
     std::cout << "Done testing swap " << std::endl;
}