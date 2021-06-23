#pragma once
#include <iostream>
#include "dot.h"


void scalpel (Dot &dot2, Dot &dot1)
{
	system ("cls");
	std::cout << "Scalpel was used between (" << dot1.x << ", " << dot1.y << ") and (";
	std::cout << dot2.x << ", " << dot2.y << ")" << std::endl;
}


void hemostat (Dot &dot)
{
	system ("cls");
	std::cout << "Hemostat was used on (" << dot.x << ", " << dot.y << ")" << std::endl;
}


void tweezers (Dot &dot)
{
	system ("cls");
	std::cout << "Tweezers was used on (" << dot.x << ", " << dot.y << ")" << std::endl;
}


void suture (Dot &dot1, Dot &dot2)
{
	system ("cls");
	std::cout << "Suture was applied" << std::endl;
}