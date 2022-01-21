#include <iostream>



int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	for (const auto& el : arr)
		std::cout << el << ' ';
	std::cout << std::endl;
}
