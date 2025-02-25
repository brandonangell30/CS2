#include "object_construction.hpp"
#include <iostream>

object::object() {
    max = 300;                    
    value = 0;                    
    point = new int[max];         
    for (int i = 0; i < max; ++i) {
        point[i] = 0;            
    }
   
}


object& object::operator=(const object& other) {
      if (this != &other) {  
        delete[] point; 
        max = other.max; 
        value = other.value; 
        point = new int[max]; 
        for (int i = 0; i < max; ++i) {
            point[i] = other.point[i]; 
        }
        
    }
    return *this;
}
object::object(const object& other) {
    max = other.max;             
    value = other.value;        
    point = new int[max];        
    for (int i = 0; i < max; ++i) {
        point[i] = other.point[i]; 
    }
    
}

object::~object(){
     delete[] point; 
    point = nullptr; 

}