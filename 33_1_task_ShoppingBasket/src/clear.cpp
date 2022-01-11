#include <iostream>


void clear()
{
#ifdef __LINUX__
    system("clear");
#elif defined _WIN32
    system("cls");
#else
    for (int i = 0; i < 9; ++i)
        std::cout << std::endl;
#endif
}