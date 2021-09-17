#include <iostream>
#include "supported.h"



void clear ()
{
#ifdef _WIN32
    system ("cls");
#elif defined __LINUX__
    system ("clear")
#else
    for (int i = 0; i < 8; ++i)
        std::cout << std::endl;
#endif
}



void wait ()
{
#ifdef _WIN32
    system ("pause");
#else
    system ("read");
#endif
}