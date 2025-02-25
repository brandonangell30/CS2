// bigint Test Program
//
// Tests:  int constructor, uses ==
// 
// NEED TO IMPLEMENT
//
#include <iostream> 
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }

    //WRONG. This will fail, of course.
                    //You need to add more test cases here. Remove this assert.

 

    //Add test cases as needed.
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(12345);
      bigint right(67890);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 12345);
      assert(right  == 67890);
      assert(result == 80235);
    }
    
 {
      //------------------------------------------------------
      // Setup fixture //edge case
      bigint left(99999);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 99999);
      assert(right  == 1);
      assert(result == 100000);
    }

     {
      //------------------------------------------------------
      // Setup fixture //edge case
      bigint left(1);
      bigint right(99999);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 99999);
      assert(result == 100000);
    }
 

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1034);
      bigint right(1034);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1034);
      assert(right  == 1034);
      assert(result == 2068);
    }
{
      //------------------------------------------------------
      // Setup fixture
      bigint left(77771);
      bigint right(67890);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 77771);
      assert(right  == 67890);
      assert(result == 145661);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(10101010);
      bigint right(4);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 10101010);
      assert(right  == 4);
      assert(result == 10101014);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1234567);
      bigint right(40);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1234567);
      assert(right  == 40);
      assert(result == 1234607);
    }
    std::cout << "Done with testing addition." << std::endl;
    return 0;
}

