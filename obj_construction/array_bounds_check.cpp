// 
// Kent State University
// CS 23001 - J. Maletic
//
// Lab on dynamic memory
//
// Memory allocation and array bounds checking
//
// C/C++ does not check array bounds, so accessing an element of an
//    array outside of its defined size results in Undefined Behavior
//
// TO COMPILE: clang++ -Wall array_bounds_check.cpp -o bounds_check
// TO RUN: ./bounds_check
//           Then enter a postivie integer value at the prompt
//
// Instructions:
//   Read the code.
//   Run the program on wasp/hornet (multiple) times.
//   Try these values of 10, 16, 32, 33, 40
//
//   Read over the output each time.
//


//   What is wrong with the output?
//There is an array out of bounds, not checked by c++, also str[i] when i>=5 could have bad results


//   What is wrong with the code?
//it tries to write beyond the allocated memory (size of str1)


//   Why is no error raised?
//C++ doesnt check for array out of bounds

//   How many bytes are between the start of str1 and str2?
//well str1 is 5bytes since 5 chars and str2 is 20 so 15

//   How can you test for this logical error?
//use assertions to check n


//   How can you prevent this type of error?
//boundary checks? run the code after every segment? assetions?

//   Include the delete[] at the end and recompile, what changes?
//deletes the allocated memory and prevents memory leaks

#include <iostream>


int main () {
    char *str1 = new char[5];     //Allocate two arrays on the heap
    char *str2 = new char[20];
    int n=0;

    std::cout  << "str1->char[5]" << std::endl;
    std::cout  << "str2->char[20]" << std::endl;
    std::cout  << "Enter positive integer value: ";  // n > 0
    std::cin >> n;

    std::cout  << "Write to array str1:" << std::endl;
    for (int i = 0; i < n; ++i) {   //Write to str1[0...n-1]
        str1[i] = 'X';
        std::cout << "str1[" << i << "] = 'X'" << std::endl;
    }

    std::cout  << "Contents of array str1:" << std::endl;
    for (int i = 0; i < n; ++i) {   //Print str1[0...n-1]
        std::cout << "str1[" << i << "] == " << "|" <<  str1[i] << "|" << std::endl;
    }

    std::cout  << "Contents of array str2:" << std::endl;
    for (int i = 0; i < 20; ++i) {    //Print str2[0...19]
        std::cout << "str2[" << i << "] == " << "|" <<  str2[i] << "|" << std::endl;
    }

    //delete[] str1;  //Try with and without deletes
    //delete[] str2;

    return 0;
}

