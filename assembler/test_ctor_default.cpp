#include "stack.hpp"
#include <cassert>
#include <iostream>
#include "../string/string.hpp"

//===========================================================================
int main ()
{
    {
        // SETUP FIXTURE
        stack<int> int_stackiez;

        // VERIFY
        assert(int_stackiez.empty());
        assert(!int_stackiez.full());
    }
    {
        // SETUP FIXTURE
        stack<double> double_stackiez;

        // VERIFY
        assert(double_stackiez.empty());
        assert(!double_stackiez.full());
    }
    {
        // SETUP FIXTURE
        stack<String> string_stackiez;

        // VERIFY
        assert(string_stackiez.empty());
        assert(!string_stackiez.full());
    }


    std::cout << "Done testing default constructor! " << std::endl;
}