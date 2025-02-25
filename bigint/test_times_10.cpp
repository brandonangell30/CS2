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
        bi = bi.times10(0);

        // Verify
        assert(bi == 3);  
    
    }
    //Add test cases as needed.
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(422);

        // Test 
        bi = bi.times10(1);

        // Verify
        assert(bi == 4220);  
    
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(934);

        // Test 
        bi = bi.times10(2);

        // Verify
        assert(bi == 93400);  
    
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi = bi.times10(9);

        // Verify
        assert(bi == 0);  
    
    }

{
        //------------------------------------------------------
        // Setup fixture
        bigint bi(40);

        // Test 
        bi = bi.times10(5);

        // Verify
        assert(bi == 4000000);  
    
    }
    std::cout << "Done testing times_10" << std::endl;
    return 0;
}

