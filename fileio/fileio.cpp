// File: fileio.cpp
//
// CS II: File IO lab
//
// Compile: clang++ -Wall fileio.cpp -o fileio
// Usage:   ./fileio FILENAME

#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {

    { //Part 1 Count every character in file
        std::ifstream inFile(argv[1]);
        if (!inFile.is_open()) {
            std::cout << "Unable to open file: " << argv[1] << std::endl;
            exit(1);
        }
        char ch = ' ';

        int t = 0;
        if (!inFile.eof()) inFile.get(ch);
        while (!inFile.eof()) {
            ++t;
            std::cout << t << ": "<< ch << std::endl;
            inFile.get(ch);
        }
        std::cout << "Total: " << t << std::endl;

        std::cout << "Done with Part 1" << std::endl;
        inFile.close();
    }

    { //Part 2 Count non white space character in a file
        std::ifstream inFile(argv[1]);
        if (!inFile.is_open()) {
            std::cout << "Unable to open file: " << argv[1] << std::endl;
            exit(1);
        }
            char ch = ' ';
            int j = 0;
            if (!inFile.eof()) {
                inFile >> ch;
            }
        while (!inFile.eof()) {
            ++j;
            std::cout << j << ": "<< ch << std::endl;
            inFile >> ch;
        }



        std::cout << "Total: " << j << std::endl;
        std::cout << "Done with Part 2" << std::endl << std::endl;
        inFile.close();
    }


    { //Part 3 Count number of words in a file
        std::ifstream inFile(argv[1]);
        if (!inFile.is_open()) {
            std::cout << "Unable to open file: " << argv[1] << std::endl;
            exit(1);
        }
    char word[100];
    int wordCount = 0;
    while(inFile >> word){
        wordCount++;
        std::cout << wordCount <<": " << word << std::endl;
    }
    std::cout << "Total: " << wordCount << std::endl;
    std::cout << "Done with Part 3" << std::endl << std::endl;
        inFile.close();
    }


    { //Part 4 Count number lines in a file
        std::ifstream inFile(argv[1]);
        if (!inFile.is_open()) {
            std::cout << "Unable to open file: " << argv[1] << std::endl;
            exit(1);
        }
char word[100];
    int lineCount = 0;
    while(inFile.getline(word, 100)){
        lineCount++;
        std::cout << lineCount <<": " << word << std::endl;
    }
    std::cout << "Total: " << lineCount << std::endl;
        std::cout << "Done with Part 4" << std::endl << std::endl;
        inFile.close();
    }

    return 0;
}
