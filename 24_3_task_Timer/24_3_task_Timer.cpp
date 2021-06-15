#include <iostream>
#include <ctime>
#include <iomanip>


int main()
{
	std::time_t start = time (nullptr);
	std::tm timer = *std::localtime (&start);
	std::cout << "Enter time for timer on format MM:SS: ";
	std::cin >> std::get_time (&timer, "%M:%S");

	int leftSec = timer.tm_min * 60 + timer.tm_sec;
	std::time_t current = time (nullptr);
	start = current;
	int totalSec = leftSec;

	while (current != start + totalSec)
	{
		current = time (nullptr);
		if (current == start + totalSec - leftSec)
		{
			system ("cls");
			int min = leftSec / 60;
			int sec = leftSec % 60;
			if (min < 10) std::cout << "0";
			std::cout << min << ":";
			if (sec < 10) std::cout << "0";
			std::cout << sec << std::endl;
			--leftSec;
		}
	}

	std::cout << "DING! DING! DING!" << std::endl;
}
