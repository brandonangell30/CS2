///////////////////////////////////////////////////////////////////////////
//  bug1.cpp
//   
// 
//   Created by Maletic on 9/9/13.
//   Up dated: 9/16/2024
//
//   This code prints out a sets of random numbers, no duplicates per set.
//
//   There is a bug in this code.  It compiles but seems to get into an infinit loop.
//   Find the bug.
//
//   Step 1: Compile the program clang++ -Wall bug1.cpp -o buggy
//           Run it ./buggy  ctrl c to break it.
//   Step 2: Read over the code and figure out what it does a bit.
//           Insert print statements into the different loops to 
//           determine where the infinite loop is occurring.
//           Start in the main and work down the call stack.
//   Step 3: Once you figure out what loop is the problem try to 
//           figure out what it is supposed to do and why its broken.
//   Step 4: Make the fix and compile/run the program
//   Step 5: Does it work?  



#include <iostream>
#include <cstdlib>

const int MAX             = 6;
const int SIZE_OF_SAMPLES = 3;
const int REP             = 5;
const int SEED            = 9809;

bool inArray     (int[], int, int  );
void setToRandom (int,   int, int[]);

int main() {
    std::cout << "TOP OF MAIN" <<std::endl;
    int arr[SIZE_OF_SAMPLES];
    srand(SEED);  //Seed random number generator.
std::cout << "1!" <<std::endl;
    for (int i = 0; i < REP; i++) {
        setToRandom(MAX, SIZE_OF_SAMPLES, arr);
        std::cout << "2!" <<std::endl;
        for(int j = 0; j < SIZE_OF_SAMPLES; j++) {
            std::cout << arr[j] << " "; //they used arr[i] not arr[j]
        }
        std::cout << "3!" <<std::endl;
        std::cout << std::endl;
    }
    //return 0;
    std::cout << "BOTTOM OF MAIN" << std::endl;
}

// result[n] will be initialized with a set of random numbers, no duplicates
//           Values between 0 and max.
// 
void setToRandom(int max, int n, int result[]) {
    int cntr = 0, r;

    while (cntr < n) {
        r = rand();  //Get random number
        r = r % (max + 1);
        if (inArray(result, cntr, r)) {
            result[cntr] =  r;
            cntr++;
        }
        break; //result cntrl is equal to r therefore, infinite loop
    }
    return;
}

// Check if x is included in array[] of arrSize.
// Returns: 1 if x is a member
//           0 if x is not a member
// 
bool inArray(int array[], int arrSize, int x) {
    for (int i = 0; i < arrSize; ++i) {
        if (array[i] == x) {
            return true;
        }
    }
    return false;
}
