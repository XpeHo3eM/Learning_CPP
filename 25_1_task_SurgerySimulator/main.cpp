#include "dot.h"
#include "instruments.h"
#include <iostream>


bool isCorrectInstrument (std::string &);

std::string instruments[] {"scalpel", "hemostat", "tweezers", "suture"};


int main()
{
	std::string chosenInstrument {""};
	std::cout << "To start operation enter \"scalpel\"" << std::endl;
	do
		std::cin >> chosenInstrument;
	while (chosenInstrument != "scalpel");

	Dot cutStart, cutFinish;
	std::cout << "Enter coordinate of start cut: ";
	std::cin >> cutStart.x >> cutStart.y;
	std::cout << "Enter coordinate of finish cut: ";
	std::cin >> cutFinish.x >> cutFinish.y;
	scalpel (cutStart, cutFinish);

	if (cutFinish.x < cutStart.x)
		std::swap (cutStart, cutFinish);

	Dot sutureStart, sutureFinish;
	do
	{
		std::cout << "Choose instrument: " << std::endl;
		std::cout << " - " << instruments[0] << ";" << std::endl;
		std::cout << " - " << instruments[1] << ";" << std::endl;
		std::cout << " - " << instruments[2] << ";" << std::endl;
		std::cout << " - " << instruments[3] << ";" << std::endl;
		
		do
			std::cin >> chosenInstrument;
		while (!isCorrectInstrument (chosenInstrument));

		int chosen {0};
		while (chosenInstrument != instruments[chosen])
			++chosen;

		switch (chosen)
		{
		case 0 : scalpel  (enterDot (), enterDot ()); break;
		case 1 : hemostat (enterDot ());              break;
		case 2 : tweezers (enterDot ());              break;
		case 3 :
		{
			sutureStart  = enterDot ();
			sutureFinish = enterDot ();
			suture (sutureStart, sutureFinish); 

			if (sutureFinish.x < sutureStart.x)
				std::swap (sutureStart, sutureFinish);
			break;
		}
		}
	}
	while (!(compareDots(cutStart,  sutureStart) && 
					 compareDots(cutFinish, sutureFinish)));

	std::cout << std::endl << "~ Operation was ended ~" << std::endl;
}



bool isCorrectInstrument (std::string &chosen)
{
	for (int i = 0; i < chosen.size (); ++i)
		chosen[i] = tolower (chosen[i]);

	for (const auto &available : instruments)
		if (chosen == available) return true;

	return false;
}