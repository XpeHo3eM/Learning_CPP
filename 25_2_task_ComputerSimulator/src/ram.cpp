#include "const.h"


extern int *ram;


void ramWrite (int *buf)
{
    for (int i = 0; i < g_size; ++i)
        *(ram + i) = *(buf + i);
}



int* ramRead ()
{
    return ram;
}
