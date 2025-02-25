//
// File: stack.hpp
//
// Programmer: Brandon Angell
// Date:        Spring 2024
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//
#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_
#include "../string/string.hpp"
#include <iostream>
#include <new>
#include <cassert>


template<typename T> 
class Node {
    public:
	Node() : next(0) {}
        Node(const T& val) : data(val), next(0) {}
        T data;
        Node<T>* next;
};

template <typename T>
class stack {
public:
              stack     () : tos(0) {} //default constructor
              stack     (const stack<T>&); //copy constructor
              ~stack    (); //destructor
    void      swap      (stack<T>&); //swap func
    stack<T>& operator= (stack<T> rhs) {swap(rhs); return *this;}//assignment overloading
    
	bool      empty     () const {return tos == 0;}
	bool      full      () const;
	T         top       () const;
	T         pop       ();
	void      push      (const T&);

private:
	Node<T>   *tos;
};

template <typename T> //copy constructor def
stack<T>::stack(const stack<T>& copy) : stack(){
    Node<T>* temp = copy.tos;
    Node<T>* bottom;
    while(temp != 0){
        if(tos ==0){
            tos = new Node<T>(temp->data);
            bottom = tos;
        }
        else{
            bottom->next = new Node<T>(temp->data);
            bottom = bottom->next;
        }
        temp = temp->next;
    }
}

template<typename T> //destructor def
stack<T>::~stack(){
    Node<T>* temp = tos;
    while(tos!=0){
        tos = tos->next;
        delete temp;
        temp = tos;
    }
}

template<typename T> //swap method def
void stack<T>::swap(stack<T>& rhs){
    Node<T>* temp = rhs.tos;
    rhs.tos = tos;
    tos = temp;
}
template<typename T> //push method def
void stack<T>::push(const T& val){
    assert(!full());
    Node<T>* temp = new Node<T>(val);
    temp->next = tos;
    tos = temp;
}
template<typename T> //pop method def
T stack<T>::pop(){
    assert(!empty());
    Node<T> *temp = tos;
    T returnData = tos->data;
    tos = tos->next;
    delete temp;
    return returnData;
}
template<typename T> //top method def
T stack<T>::top() const {
    return tos->data;
}
template<typename T> //full method def
bool stack<T>::full() const{
    Node<T>* temp = new(std::nothrow) Node<T>();
    if (temp == 0) {return true;}
    delete temp;
    return false;
}


#endif
