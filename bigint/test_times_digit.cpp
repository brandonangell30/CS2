// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(4);

        // Verify
        assert(bi == 12);  
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(31);

        // Test 
        bi = bi.timesDigit(0);

        // Verify
        assert(bi == 0);  
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi = bi.timesDigit(24);

        // Verify
        assert(bi == 0);  
    }
{
        //------------------------------------------------------
        // Setup fixture
        bigint bi(37);

        // Test 
        bi = bi.timesDigit(12);

        // Verify
        assert(bi == 444);  
    }
{
        //------------------------------------------------------
        // Setup fixture
        bigint bi(366);

        // Test 
        bi = bi.timesDigit(231);

        // Verify
        assert(bi == 84546);  
    }
    //Add test cases as needed.
    
    std::cout << "Done testing bigint * digit" << std::endl;
    return 0;
}
