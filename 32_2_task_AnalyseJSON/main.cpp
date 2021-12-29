#include <iostream>
#include <fstream>
#include "createJSON.h"
#include "nlohmann/json.hpp"


int main()
{
	/*
	std::cout << "Enter actor's name: ";
	std::string name;
	std::cin >> name;
	*/
	createJSON ();
	std::ifstream file ("movies.json");
	if (file.is_open ())
	{
		nlohmann::json json;
		file >> json;

		std::cout << json << std::endl;
	}
	else
		std::cerr << "Movies.json not found" << std::endl;	
}
