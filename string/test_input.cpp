#include <iostream>
#include <fstream>
#include "string.hpp"
int main(){
    char c = ' ';
    std::ifstream in("inputSample.txt");
    if(!in){
        std::cerr << "Couldnt open file" << std::endl;
        exit(1);
    }
    while(!in.eof()){
        in.get(c);
        std::cout << c;
    }
    in.close();
}