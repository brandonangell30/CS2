#include <iostream>
#include "../string/string.hpp"
#include "../assembler/stack.hpp"
#include <cassert>
#include <vector>
#include <fstream>


String convertPrefix(String infix);

int main(int argc, char *argv[]) {

    if (argc != 2) {      // Error if != 2 things
        std::cerr << "Error" << std::endl;
        std::cerr << "Usage: " << argv[0] << " input_file" << std::endl;
        exit(1);         
    }

    std::ifstream in(argv[1]);     //quit if fails
    if (!in) {
        std::cerr << "Error: Can not open " << argv[1] << std::endl;
        exit(2);
    }

    std::vector<String> prefix;
    std::vector<String> infix;
    while(true) {
        char ch[512];
        in.getline(ch, 511);
        if(in.eof()) break;
        prefix.push_back(convertPrefix(String(ch)));
        infix.push_back(String(ch));
    }

    in.close();

    if(argc == 2) { // No output && print prefix
        for(int i = 0; i < (int)prefix.size(); ++i) {
            std::cout << "Infix Expression: " << infix[i].split(';')[0] << std::endl
            << "Prefix Expression: " << prefix[i] << std::endl << std::endl;
            
        }

    }

}

String convertPrefix(String infix) {
    std::vector<String> tokens = infix.split(' ');
    stack<String> tokenSt;
    int elementCount = 0;  
    int i = 0;

    while (tokens[i] != ';') {
        if (tokens[i] == ')') {
            if (elementCount < 3) { // make sure we can pop
                std::cerr << "Error: Not enough tokens" << std::endl;
                return ""; //return empty str
            }
            String right = tokenSt.pop();
            String oper = tokenSt.pop();
            String left = tokenSt.pop();
            tokenSt.push(oper + ' ' + left + ' ' + right);
            elementCount -= 2; // three elements were popped and one pushed
        } else if (tokens[i] != '(') {
            if (tokens[i].length() == 2 && (int)tokens[i][1] == 13) break;
            tokenSt.push(tokens[i]);
            ++elementCount; 
        }
        ++i;
    }

    if (elementCount == 0) {
        std::cerr << "Error: Nothing in stack" << std::endl;
        return ""; //if empty
    }

    return tokenSt.top();
}


