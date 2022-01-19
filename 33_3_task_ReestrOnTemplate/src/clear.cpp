#include <iostream>

#include "clear.h"



void clear()
{
#ifdef _WIN32
	system("cls");
#elif defined (_LINUX_)
	system("clear");
#else
	for (size_t i = 0; i < 9; ++i)
		std::cout << std::endl;
#endif
}