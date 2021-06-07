#include <iostream>


#define SPRING 0
#define SUMMER 1
#define AUTUMN 2
#define WINTER 3

#define CURRENT_SEASON AUTUMN

int main()
{
#if CURRENT_SEASON == 0
	std::cout << "Current season is spring" << std::endl;
#elif CURRENT_SEASON == 1
	std::cout << "Current season is summer" << std::endl;
#elif CURRENT_SEASON == 2
	std::cout << "Current season is autumn" << std::endl;
#elif CURRENT_SEASON == 3
	std::cout << "Current season is winter" << std::endl;
#else
	std::cout << "! Incorrect season !" << std::endl;
#endif

	system("pause");
}
