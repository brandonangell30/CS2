#include "utilities.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {

    if (argc != 2 && argc != 3) {      // Error if != 2 things
        std::cerr << "Error" << std::endl;
        std::cerr << "Usage: " << argv[0] << " input_file [output_file]" << std::endl;
        exit(1);         // Exit with error
    }

    std::ifstream in(argv[1]);     // Open file, quit if fails
    if (!in) {
        std::cerr << "Error: Can't open " << argv[1] << std::endl;
        exit(2);
    }
    std::vector<String> postfix;
    std::vector<String> infix;
    while(true) {
        char ch[512];
        in.getline(ch, 511);
        if(in.eof()) break;
        postfix.push_back(convertPostfix(String(ch)));
        infix.push_back(String(ch));
       
    }

    in.close();

    
    if(argc == 2) { // No output file && Print
        for(int i = 0; i < (int)postfix.size(); ++i) {
            std::cout << "Infix Expression: " << infix[i].split(';')[0] << std::endl
            << "Postfix Expression: " << postfix[i] << std::endl << std::endl;
            
        }

    } else { 
        std::ofstream out(argv[2]); 
        if(!out){
            std::cout << "Error: Can't open " << argv[2] << "\n";
            exit(3);
        }
        for(int i = 0; i < (int)postfix.size(); ++i) {
            out << "Infix Expression: " << infix[i].split(';')[0] << std::endl
            << "Postfix Expression: " << postfix[i] << std::endl;
            if(i + 1 != (int)postfix.size()) out << std::endl;
        }
        out.close();
    }
}