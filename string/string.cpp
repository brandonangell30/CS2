#include "string.hpp"
#include <iostream>
#include <cassert>
#include <vector>

//default
String::String(){
    str = new char[1];
    stringSize = 1;
    str[0] = 0;
}
//char
String::String(char c){
    if(c != '\0') { //endpoint and or testing to make sure it can be made
        str = new char[2];
        stringSize = 2;
        str[0] = c;
        str[1] = 0;
    } else { 
        str = new char[1]; //makes a new string that uses a null character
        stringSize = 1;
        str[0] = 0;
    }
}
//char array
String::String(const char c[]) {
    int length = 0;
    while (c[length] != '\0') { 
        length++;
    }
    str = new char[length + 1];
    stringSize = length + 1;  
    for (int j = 0; j < length; j++) {
        str[j] = c[j];
    }
    str[length] = '\0';  
}
//copy constructor
String::String(const String& copyS) {
    str = new char[copyS.capacity() + 1];
    stringSize = copyS.capacity() + 1;
    for(int i = 0; i < stringSize; ++i) {
        str[i] = copyS[i];
    }
}
//destructor
String::~String() {
    delete[] str;
}
//swap method
void String::swap(String& other) {
    char *temp = str;
  int s = stringSize;
  str=other.str;
  stringSize = other.stringSize;
  other.str = temp;
  other.stringSize = s;
}
//length method
int String::length() const {
    int i = 0;
    while(str[i] != 0){
        i++;
    }
    return i;
}
//subscript
char& String::operator[](int c) { //modifier (non-const)
    assert((c >= 0) && (c < length()));
    return str[c];
}
//still subscript
char String::operator[](int c) const { //accessor
    int a = length();
    if((c >= 0) && (c < a)){
        return str[c];
    }
    return 0;
}
//capacity method
int String::capacity() const {
    return stringSize - 1;
}
//assignment overload
String& String::operator=(String other) { 
    swap(other); 
    return *this; 
}
//comparason overload
bool String::operator==(const String& rhs) const {
    int i = 0;
    while((str[i] != 0) && (str[i] == rhs.str[i])){
        ++i;
    }
    return str[i] == rhs.str[i];
}
// < overload
bool String::operator<(const String& rhs) const {
    int i = 0;
    while((str[i] !=0) && (str[i]== rhs.str[i])){
        ++i;
    }
    return str[i] < rhs.str[i];
}
// > overload using the < method
bool operator>(const String& lhs, const String& rhs) {
    return rhs < lhs;  
}
// output overload
std::ostream& operator<<(std::ostream& out, const String& rhs){
    for(int i = 0; i < rhs.length(); i++){
        out << rhs.str[i];
    }
    return out;
}
//input overload
std::istream& operator>>(std::istream& in, String& rhs) {
    char c[500];
    in >> c;
    rhs = String(c);
    return in;
}
//concatenation main overload
String& String::operator+=(const String& rhs) {
    int currentLength = length();      // Get the current length of the string
    int rhsLength = rhs.length();      // Get the length of the right-hand side string
    //Check if need more memory
    if (currentLength + rhsLength >= capacity()) {
        //if yeah
        int newCapacity = currentLength + rhsLength + 1; 
        char* newStr = new char[newCapacity]; 
        for (int i = 0; i < currentLength; ++i) {
            newStr[i] = str[i];
        }
        for (int i = 0; i < rhsLength; ++i) {
            newStr[currentLength + i] = rhs.str[i];
        }
        newStr[currentLength + rhsLength] = '\0'; 
        delete[] str;
        str = newStr;
        stringSize = newCapacity; 
    } else {
        //if compacity is good
        for (int i = 0; i < rhsLength; ++i) {
            str[currentLength + i] = rhs.str[i];
        }
        str[currentLength + rhsLength] = '\0'; 
    }
    return *this; 
}
//concatenation overload using +=
String operator+(const String& lhs, const String& rhs) {
    String result(lhs);  
    result += rhs;        
    return result;       
}
//substr method
String String::substr(int start, int end) const{
    String result;
    if(start < 0){
        start = 0;
    }
    if(end < start) {
        return String();
    }
    if(end > length()){
        end = length();
    } 
    if(start > end) {
        return String();
    }
    for(int i = start; i <= end; ++i) {
        result += str[i];
    }
    return result;
}
//findch method
int String::findch(int begin, char c) const {
    int len = length();
    for(int i = begin; i <= len; ++i) {
        if(str[i] == c) return i;
    }
    return -1;
}
//findstr method
int String::findstr(int start, const String& rhs) const {
    if (start < 0 || start >= length() || rhs.length() == 0) {
        return -1; //for invalid index or empty substr
    }
    int strLength = length();
    int rhsLength = rhs.length();
    for (int i = start; i <= strLength - rhsLength; ++i) {
        bool yes = true;
        for (int j = 0; j < rhsLength; ++j) {
            if (str[i + j] != rhs[j]) {
                yes = false;
                break; 
            }
        }
        if (yes) {
            return i; 
        }
    }
    return -1; 
}
//split method
std::vector<String> String::split(char sep) const {
    std::vector<String> result;
    int begin = 0; 
    int position = findch(begin, sep); //begin starting index
    
    while (position != -1) {
        result.push_back(substr(begin, position - 1)); //gets substr from begin
        begin = position + 1;
        position = findch(begin, sep); //finds next occ of sep
    }
    result.push_back(substr(begin, length()));

    return result;
}
//all variations methods
//concatenation variation
String operator+(String lhs, const String& rhs){
    return lhs += rhs;
}
//comparison variation
bool operator==(const char c[], const String& rhs){
    return String(c) == rhs;
}
//comparison variation
bool operator==(char c, const String& rhs){
    return String(c) == rhs;
}
// < variation
bool operator<(const char c[], const String& rhs){
    return String(c) < rhs;
}
// < variation
bool operator<(char c, const String& rhs){
    return String(c) < rhs;
}
// <= variation
bool operator<=(const String& lhs, const String& rhs){
    return (lhs < rhs) || (lhs == rhs);
}
// not equals variation
bool operator!=(const String& lhs, const String& rhs){
    return !(lhs == rhs);
}
// >= variation
bool operator>=(const String& lhs, const String& rhs){
    return !(lhs < rhs);
}