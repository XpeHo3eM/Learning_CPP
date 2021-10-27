#pragma once
#include <iostream>
#include "toy.h"



class SharedPtrToy
{
public:
    SharedPtrToy () {};
    SharedPtrToy (const SharedPtrToy& other);
    SharedPtrToy& operator= (const SharedPtrToy& other);
    ~SharedPtrToy ();
    void clear ();

    void setObj (Toy* inToy);
    void setRef (int* inCountRef);
 
private:
    Toy* obj      = nullptr;
    int* countRef = nullptr;
};



SharedPtrToy makeSharedPtrToy (std::string inToyName);