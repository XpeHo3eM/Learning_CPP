#include <iostream>


#define ALL_WAGONS for (const auto& wag : train)
#define CHECK_COUNT(n, fullness) fullness ## Wagon ## ( ## n ## )


const int gWagonTotal = 10;
const int gMaxPassengerPerWagon = 20;


void fillTrain         (int[], int);
bool notFullWagon      (int);
bool overcrowdedWagon  (int);



int main()
{
	int train[gWagonTotal];
	fillTrain(train, gWagonTotal);

	int countNotFullWagons     = 0;
	int countOvercrowdedWagons = 0;
	int totalPassengers        = 0;

	ALL_WAGONS
	{
		countNotFullWagons     += CHECK_COUNT (wag, notFull);
		countOvercrowdedWagons += CHECK_COUNT (wag, overcrowded);
		totalPassengers        += wag;
	}

	std::cout << std::endl;
	std::cout << "Count of overcrowded wagons: " << countOvercrowdedWagons << std::endl;
	std::cout << "   Count of not full wagons: " << countNotFullWagons     << std::endl;
	std::cout << "     Total count passengers: " << totalPassengers        << std::endl;
}



bool overcrowdedWagon (int count)
{
	return (count > gMaxPassengerPerWagon);
}



bool notFullWagon (int count)
{
	return (count < gMaxPassengerPerWagon);
}



void fillTrain (int train[], int n)
{
	if (n > 1) 
		fillTrain (train, n - 1);

	std::cout << "Enter count of passengers on " << n << " wagon: " << std::endl;
	std::cin >> train[n-1];
}
