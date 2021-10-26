#pragma once
#include <iostream>
#include "toy.h"



class SharedPtrToy
{
public:
    SharedPtrToy (std::string inToy);
    SharedPtrToy (const SharedPtrToy& other);
    SharedPtrToy& operator= (const SharedPtrToy& other);
    void clear ();
 
private:
    std::shared_ptr<Toy> obj;
};



SharedPtrToy makeSharedPtrToy (std::string inToyName);