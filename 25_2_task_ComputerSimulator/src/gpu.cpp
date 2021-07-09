#include <iostream>
#include "const.h"
#include "ram.h"



void print ()
{
    int *tmp = ramRead ();

    for (int i = 0; i < g_size; ++i)
        std::cout << *(tmp + i) << " ";
    std::cout << std::endl;
}



void print (int sum)
{
    std::cout << "Sum of numbers on ram is " << sum << std::endl;
}