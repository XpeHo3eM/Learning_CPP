#include <iostream>
#include <string>
#include <map>
#include "clear.h"


std::map <std::string, uint16_t> commands = {{"display", 0}, {"resize", 1}, {"move", 2}, {"exit", 3}};


uint16_t chosenCommand ()
{
    std::cout << "Available commands:" << std::endl;
    for (const auto &c : commands)
        std::cout << "  " << c.first << ";" << std::endl;
    std::map <std::string, uint16_t>::iterator itf = commands.end ();
    while (itf == commands.end())
    {
        std::cout << std::endl << "Enter a command: ";
        std::string entered;
        std::cin >> entered;

        itf = commands.find (entered);
        if (itf != commands.end ())
            return (itf->second);
        else
            std::cout << "Incorrect command. Try again" << std::endl << std::endl;
    }    
}