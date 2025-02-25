#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in;            // Define input stream
    in.open("data1-2.txt");      // Open a file
    if(!in) {                    // Make sure file opened correctly
        std::cerr << "File not found: data1-2.txt" << std::endl;
        exit(1);
    }

    //Until end of file
    while(!in.eof()){
        bigint number1, number2, result = 0;
        char c;
        while(true) {
            in.get(c);
            if(in.eof()) {
                 return 0;
            }
            if(c == ';') {
                break; //if ; then it must break but if anything else it will run
            }
            int d = c - int('0'); //finding unicode num/ascii
            if(d >= 0 && d < 10) {
                number1 = number1.times10(1);
                number1 = number1 + d;
            }
        }
        while(true) {
            in.get(c);
            if(c == ';') {
                break;
            }
            int d = c - int('0');
            if(d >= 0 && d < 10) {
                number2 = number2.times10(1);
                number2 = number2 + d;
            }

        } 
        std::cout << (number1) << std::endl;
        std::cout << (number2) << std::endl;
        result = number1 * number2;
        std::cout << result << std::endl;
    }
    in.close();                  // Close file/input stream
    return 0;
}