// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    

{
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);  
        assert(digit == 4);
    }
    //Add test cases!!

{
        // Setup
        bigint bi(123456789);

        // Test 
        int digit = bi[6];

        // Verify
        assert(bi    == 123456789);  
        assert(digit == 3);
    }

    {
        // Setup
        bigint bi(6789);

        // Test 
        int digit = bi[1];

        // Verify
        assert(bi    == 6789);  
        assert(digit == 8);
    }
    //Add test cases!!


    {
        // Setup
        bigint bi(53847);

        // Test 
        int digit = bi[2];

        // Verify
        assert(bi    == 53847);  
        assert(digit == 8); 
    }

    {
        // Setup
        bigint bi(11111111);

        // Test 
        int digit = bi[2];

        // Verify
        assert(bi    == 11111111);  
        assert(digit == 1); 
    }
     {
        // Setup
        bigint bi(1119999);

        // Test 
        int digit = bi[5];

        // Verify
        assert(bi    == 1119999);  
        assert(digit == 1); 
    }

     {
        // Setup
        bigint bi(111999);

        // Test 
        int digit = bi[3];

        // Verify
        assert(bi    == 111999);  
        assert(digit == 1); 
    }
{
        // Setup
        bigint bi(176);

        // Test 
        int digit = bi[2];

        // Verify
        assert(bi    == 176);  
        assert(digit == 1); 
    }
    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

