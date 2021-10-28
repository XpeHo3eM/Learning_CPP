#include <iostream>
#include <toy.h>
#include "sharedPtrToy.h"



void SharedPtrToy::clear ()
{
    if (obj != nullptr)
    {
        --(*countRef);
        if (*countRef == 0)
        {
            delete obj;
            delete countRef;
        }
    }
    obj      = nullptr;
    countRef = nullptr;
}



SharedPtrToy::SharedPtrToy (const SharedPtrToy& other)
{
    obj      = other.obj;
    countRef = other.countRef;
    ++(*countRef);
}



SharedPtrToy& SharedPtrToy::operator= (const SharedPtrToy& other)
{
    if (this == &other)
        return *this;
    
    clear ();

    obj      = other.obj;
    countRef = other.countRef;
    ++(*countRef);
    
    return *this;
}



SharedPtrToy::~SharedPtrToy ()
{
    clear ();
}



void SharedPtrToy::setObj (Toy* inToy)
{
    obj = inToy;
}



void SharedPtrToy::setRef (int* inCountRef)
{
    countRef = inCountRef;
}



SharedPtrToy makeSharedPtrToy (std::string inToyName)
{
    SharedPtrToy tmp;
    tmp.setObj (new Toy (inToyName));
    tmp.setRef (new int(1));
    return tmp;
}