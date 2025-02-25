#ifndef BIGINT_HPP_
#define BIGINT_HPP_
#include <iostream>

//Brandon Angell
//09/01/2024

const int CAPACITY =200;

class bigint{
private:
int numbersStored[CAPACITY]; //array to store digits

public:

bigint(); //default constructor
bigint(int intValue); //constructor to intialize int
bigint(const char c[] ); //constructor for char

void debugPrint(std::ostream& send) const; //void print method

friend std::istream& operator>>(std::istream&, bigint&); //overload >>
friend bool operator==(const bigint& lhs, const bigint& rhs); //overload comparison
friend std::ostream& operator<<(std::ostream&, bigint&); //overload <<
bigint operator+(const bigint&) const; //overload + operator
int operator[](const int&) const; //overloads []
bigint timesDigit(int) const;//timesDigit method
bigint times10(int) const; //times10 method
bigint operator*(const bigint&) const; //multiplication overload
};

#endif /* BIGINT_HPP_ */