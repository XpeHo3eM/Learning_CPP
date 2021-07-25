#include <iostream>
#include <map>
#include <string>


std::map <std::string, int> commands {{"play", 0}, {"pause", 1},    {"stop", 2}, 
                                      {"next", 3}, {"addTrack", 4}, {"exit", 5}};


int chosenCommand ()
{
    std::cout << "Available commands:" << std::endl;
    for (const auto &c : commands)
        std::cout << "  " << c.first << ";" << std::endl;
    std::cout << std::endl << "Enter command for action: ";
    std::string action;
    std::map <std::string, int>::iterator itf;
    do
    {
        std::getline (std::cin, action);
        itf = commands.find (action);
        if (itf == commands.end ())
            std::cout << "! Incorrect command. Try again !" << std::endl;
    }
    while (itf == commands.end ());

    return itf->second;
}
