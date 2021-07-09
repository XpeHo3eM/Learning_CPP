#include "const.h"


int *ram = new int[g_size] { 0 };


void ramWrite (int *buf)
{
    for (int i = 0; i < g_size; ++i)
        *(ram + i) = *(buf + i);
}



int* ramRead ()
{
    return ram;
}
