#include <iostream>
#include "const.h"
#include "ram.h"



int compute ()
{
    int *tmp = ramRead ();

    int sum = 0;
    for (int i = 0; i < g_size; ++i)
        sum += *(tmp + i);

    return sum;
}