#include <iostream>


#define MON    "monday"
#define TUE   "tuesday"
#define WED "wednesday"
#define THU  "thursday"
#define FRI    "friday"
#define SAT  "saturday"
#define SUN    "sunday"

#define GET_DAY_OF_WEEK(n) n


int main()
{
	std::cout << "Enter day of week: " << std::endl;
	int day;
	do
		std::cin >> day;
	while (day <= 0 || day > 7);

	switch (day)
	{
	case 1: std::cout << GET_DAY_OF_WEEK(MON) << std::endl; break;
	case 2: std::cout << GET_DAY_OF_WEEK(TUE) << std::endl; break;
	case 3: std::cout << GET_DAY_OF_WEEK(WED) << std::endl; break;
	case 4: std::cout << GET_DAY_OF_WEEK(THU) << std::endl; break;
	case 5: std::cout << GET_DAY_OF_WEEK(FRI) << std::endl; break;
	case 6: std::cout << GET_DAY_OF_WEEK(SAT) << std::endl; break;
	case 7: std::cout << GET_DAY_OF_WEEK(SUN) << std::endl; break;
	}

}
