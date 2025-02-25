//Brandon Angell
//09/03/2024

#include "bigint.hpp"
#include <iostream>

//default constructor implementation
bigint::bigint(){
    for(int i=0; i< CAPACITY; i++){
        numbersStored[i]=0;
    }
}

//constructor implementation
bigint::bigint(int intValue): bigint(){
    for(int i=0; intValue!=0; i++){
        numbersStored[i]= intValue%10;
        intValue/=10;
    }

}

//constructor implementation for char
bigint::bigint(const char c[]): bigint(){
    int i=0;
    int tempArray[CAPACITY];
    while(c[i] != 0){
        tempArray[i] = c[i] -'0';
        i++;
    }
    i--;
    int tempVar=0;
    while(i>=0){
        numbersStored[tempVar] = tempArray[i];
        i--;
        tempVar++;
    }
}

//debugPrint implementation
void bigint::debugPrint(std::ostream& send)const{
    for(int i= CAPACITY-1; i>=0; --i){
        send << numbersStored[i];
        if (i>0){
            send << '|';
        }
    }
}

int bigint::operator[](const int& g) const{
    return numbersStored[g];
}
   
   
std::ostream& operator<<(std::ostream& ost, bigint& big){
    int counter = 0;

    if (big==0){
        ost << '0';
        return ost;
    }
        for(int i=CAPACITY-1; i>=0; --i){
            if(big.numbersStored[i]==0){
              counter++;  
            }
            else{
                for(int j = CAPACITY- (counter+1); j>=0; --j){
                    ost << big.numbersStored[j];
                }
                break;
            }
        }
        return ost;
 }
std::istream& operator>>(std::istream& ist, bigint& bigger){
    char cN;
    int track = 0;
    while(ist >> cN){
        if(cN == ';'){
            break;
        }
        bigger.numbersStored[track]= cN-'0';
        ++track;
    }
    return ist;
}
bigint bigint::operator+(const bigint& biggy) const{
    bigint zaBiggest;
    int tempy =0;
    bool ifCarry = false;
    for(int i = 0; i<CAPACITY; ++i){
       tempy = numbersStored[i] + biggy[i];
        if(ifCarry){
            ++tempy;
            ifCarry = false;
        }
        if(tempy>=10){
            ifCarry = true;
            tempy-=10;
        }
        zaBiggest.numbersStored[i]=tempy;
    }
    return zaBiggest;
}

bool operator==(const bigint& lhs, const bigint& rhs){
    for(int i=0; i<CAPACITY; ++i){
        if(lhs[i]!=rhs[i])
        {
            return false;
        }
    }
    return true;
}

bigint bigint::timesDigit(int input) const{
     bigint ret;
    if(input == 0) {
        return bigint(0);
    }
    else{
        for(int i = 0; i<input; ++i){
            ret = ret + *this;
        }
        
    }
    return ret;

}

bigint bigint::times10(int num) const{
    bigint sum;

    for(int i =CAPACITY - num - 1; i>=0; --i){
        sum.numbersStored[i + num] = numbersStored[i];
    }

    return sum;
}

bigint bigint::operator*(const bigint& multiply) const{
    bigint result;
    bigint temp;

    for(int i = 0; i<CAPACITY -1; ++i){
        temp = this->timesDigit(multiply[i]);
        result = result + temp.times10(i);
    }
    return result;
}