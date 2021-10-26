#include <iostream>
#include <toy.h>
#include "sharedPtrToy.h"



SharedPtrToy::SharedPtrToy (std::string inToy)
{
    obj = std::make_shared<Toy> (inToy);
}



SharedPtrToy::SharedPtrToy (const SharedPtrToy& other)
{
    obj = other.obj;
}



SharedPtrToy& SharedPtrToy::operator= (const SharedPtrToy& other)
{
    if (this == &other)
        return *this;
    
    if (obj != nullptr)
        obj.reset ();
    obj = other.obj;
    
    return *this;
}



void SharedPtrToy::clear()
{
    obj.reset ();
}


SharedPtrToy makeSharedPtrToy (std::string inToyName)
{
    SharedPtrToy tmp(inToyName);
    return tmp;
}