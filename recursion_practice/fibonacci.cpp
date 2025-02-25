#include <iostream>


int fibonacci (int num){
    //normal ver
    if(num <=1){ //base case
        return num;
    }
    return fibonacci(num-1) + fibonacci(num-2); //recursion

}
int fibonacciTail(int n, int current = 0, int next = 1) {
    if (n == 0) return current; 
    if (n == 1) return next;    
    return fibonacciTail(n - 1, next, current + next); // tail recursion
}
void printFibbers(int num){
    for (int i =0; i<=num; ++i){
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;
}
void printFibTail(int num){
    for (int i =0; i<=num; ++i){
        std::cout << fibonacciTail(i) << " ";
    }
    std::cout << std::endl;
}
int main(){


int coolTest = 6;
printFibbers(coolTest);
printFibTail(coolTest);
}