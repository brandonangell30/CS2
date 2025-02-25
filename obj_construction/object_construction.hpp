//brandon angell
#ifndef OBJECT_CONSTRUCTION_HPP
#define OBJECT_CONSTRUCTION_HPP
#include <iostream>

class object{
public:
    object();
    object(const object& other);
    object& operator=(const object& other);
    ~object();
private:
    int *point;
    int max;
    int value;
};
#endif