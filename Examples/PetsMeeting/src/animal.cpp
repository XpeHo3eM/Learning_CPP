#include <iostream>
#include "animal.h"



void Cat::voice ()
{
    std::cout << "Meow" << std::endl;
}



void Dog::voice ()
{
    std::cout << "Woof" << std::endl;
}



void meeting (Animal* a, Animal* b)
{
    Cat* ac = dynamic_cast <Cat*> (a);
    Cat* bc = dynamic_cast <Cat*> (b);

    if (ac == nullptr && bc == nullptr)
        std::cout << "Woof Woof" << std::endl;
    else if (ac == nullptr)
        std::cout << "Bark Meow" << std::endl;
    else if (bc == nullptr)
        std::cout << "Meow bark" << std::endl;
    else
        std::cout << "Purr Purr" << std::endl;
}