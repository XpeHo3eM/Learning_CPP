#include <iostream>
#include <map>
#include <string>


std::map <std::string, int> commands = {{"add", 0}, {"call", 1}, {"sms", 2}, {"exit", 3}};


int chosenCommand ()
{
    std::cout << "Enter one of command below:" << std::endl;
    for (const auto c : commands)
        std::cout << "  " << c.first << ';' << std::endl;

    std::string enteredCommand;
    std::map <std::string, int>::iterator itf;
    do
    {
        std::cin >> enteredCommand;
        itf = commands.find (enteredCommand);
        if (itf == commands.end ())
            std::cout << "! Incorrect command. Try again !" << std::endl << std::endl;
    }
    while (itf == commands.end ());

    return itf->second;
}