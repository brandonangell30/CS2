#include "../assembler/utilities.hpp"
#include <vector>
#include <iostream>


String convertPostfix(String infix) {
    std::vector<String> tokens = infix.split(' ');
    stack<String> tokenSt;
    int i = 0;
    while(tokens[i] != ';') {
        if(tokens[i] == ')') {
            String right = tokenSt.pop();
            String oper =  tokenSt.pop();
            String left =  tokenSt.pop();
            tokenSt.push(left + ' ' + right + ' ' + oper);
        } else if (tokens[i] != '(') {
            if(tokens[i].length() == 2 && (int)tokens[i][1] == 13) break; //dumb eofl character wasted 2 hours of my precious sunday!!!
            tokenSt.push(tokens[i]);
        }
        ++i;
    }
    return tokenSt.top();
}
String convertPostAssembly(String postfix) {
    std::vector<String> tokens = postfix.split(' ');
    stack<String> ev;
    String result;
    int n = 1; //temp tracker
    for(int i = 0; i < (int)tokens.size(); ++i) {
        if(tokens[i] != '+' && tokens[i] != '-' && tokens[i] != '*' && tokens[i] != '/') {
            ev.push(tokens[i]);
        } else {
            String right = ev.pop();
            String left = ev.pop();
            result += evaluatePostFix(left, tokens[i], right, n);
            String temp;
            temp += "TMP";
            temp += char(n + 48);
            ev.push(temp);
            ++n;
        }
    }
    return result;

}
String evaluatePostFix(String left, String op, String right, int n) {
    String opper;
    String result;

    if(op == '+') {
        opper = "AD"; //opper code
    } else if (op == '-') {
        opper = "SB";
    } else if (op == '*') {
        opper = "MU";
    } else {
        opper = "DV";
    }
    result += "\tLD\t\t" + left + "\n";  result += "\t" + opper + "\t\t" + right + "\n";
    result += "\tST\t\tTMP"; result += char(n + 48); result += "\n";
    return result;

}