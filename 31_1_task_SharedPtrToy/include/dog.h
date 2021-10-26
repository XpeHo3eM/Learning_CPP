#pragma once

#include <string>
#include "sharedPtrToy.h"


class Dog
{
public:
    Dog (std::string inName, int inAge, SharedPtrToy inToy);
    Dog (std::string inName, int inAge)                     : Dog (inName,    inAge, makeSharedPtrToy ("Unknown")) {};
    Dog (int inAge, SharedPtrToy inToy)                     : Dog ("Unknown", inAge, inToy)                        {};
    Dog ()                                                  : Dog ("Unknown", 0,     makeSharedPtrToy ("Unknown")) {};

private:
    std::string name;
    int age;
    SharedPtrToy lovelyToy;
};
