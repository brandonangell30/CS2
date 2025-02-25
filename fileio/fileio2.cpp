// File: fileio2.cpp
//
// CS II: File IO lab
//
// Compile: clang++ -Wall fileio2.cpp -o fileio
// Usage:   ./fileio FILENAME

#include <iostream>
#include <fstream>

//Part 5 
//Read in a integer that is the number of lines to read
//Each line has only one word on it.
//Use data3.txt

int main(int argc, char *argv[]) {
    std::ifstream inFile(argv[1]);
    if (!inFile.is_open()) {
        std::cout << "Unable to open file: " << argv[1] << std::endl;
        exit(1);
    }

    
char word[100];
    int lineCount;

    if((inFile >> lineCount)){
        std::cout << "Total lines reading: " << lineCount << std::endl;
    }
    else{
        std::cout << "Error reading" << std::endl;
    }

    int counter = 0;
    for(int i =1; i<= lineCount; ++i){
        if(inFile >> word){
            std::cout << i << ": " << word << std::endl;
            ++counter;
        }
        else{
            break;
        }
    }
    if (counter < lineCount) {
    std::cout << "Warning: there is supposed to be " << lineCount << " lines, however, " << counter << " lines in the file." << std::endl;
    }
    std::cout << "Done with Part 5" << std::endl << std::endl;
    inFile.close();
    return 0;
}
