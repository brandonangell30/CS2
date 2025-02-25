#include "stack.hpp"
#include <cassert>
#include <iostream>
#include "../string/string.hpp"

//===========================================================================
int main ()
{
    {
        stack<int> int_stack;

        int_stack.push(1);
        int_stack.push(2);
        int_stack.push(3);
        stack<int> result;
        result = int_stack;
        int three = result.pop();
        int two = result.pop();
        int one = result.pop();
        assert(one == 1);
        assert(two == 2);
        assert(three == 3);
    }
    {
        stack<double> double_stack;

        double_stack.push(1.9);
        double_stack.push(2.7);
        double_stack.push(3.4);
        stack<double> result;
        result = double_stack;
        double three = result.pop();
        double two = result.pop();
        double one = result.pop();
        assert(one == 1.9);
        assert(two == 2.7);
        assert(three == 3.4);
    }
    {
        stack<String> str_stack;

        str_stack.push("ab");
        str_stack.push("cd");
        str_stack.push("ef");
        stack<String> result;
        result = str_stack;
        String three = result.pop();
        String two = result.pop();
        String one = result.pop();
        assert(one == "ab");
        assert(two == "cd");
        assert(three == "ef");
    }
    std::cout << "Done Testing Assign" <<std::endl;
}