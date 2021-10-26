#include <string>
#include "dog.h"
#include "sharedPtrToy.h"



Dog::Dog (std::string inName, int inAge, SharedPtrToy inToy) : name (inName), lovelyToy(inToy)
{
    if (inAge >= 0 && inAge <= 30)
        age = inAge;
    else
        age = 0;
}