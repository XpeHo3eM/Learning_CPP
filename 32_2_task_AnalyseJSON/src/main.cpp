#include <iostream>
#include <fstream>
#include <string>
#include "createJSON.h"
#include "nlohmann/json.hpp"


// For examples Leonardo DiCaprio on 2 movies

int main()
{
	std::cout << "Enter actor's name: ";
	std::string name;
	std::getline(std::cin, name);
		
	createJSON ();

	std::ifstream file ("movies.json");
	if (file.is_open ())
	{
		nlohmann::json json;
		file >> json;
		file.close();

		bool found = false;
		for (auto itJson = json.begin(); itJson != json.end(); ++itJson)
		{
			auto actors = itJson.value().at("starring");
			auto role   = actors.find(name);
			if (role != actors.end())
			{
				std::cout.width(15);
				std::cout << itJson.key() << " as " << *role << std::endl;
				found = true;
			}
		}

		if (!found)
			std::cout << "~ This actor didn't appear on movies ~" << std::endl;
	}
	else
		std::cerr << "Movies.json not found" << std::endl;	
}