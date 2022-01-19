#include <iostream>
#include <string>
#include <map>

#include "registry.h"



int main()
{
    Registry<int, std::string> myRegistry;

    bool exit = false;
    while (!exit)
    {
        std::cout << "Enter command: " << std::endl;
        std::cout << "1. Add;"    << std::endl;
        std::cout << "2. Remove;" << std::endl;
        std::cout << "3. Print;"  << std::endl;
        std::cout << "4. Find;"   << std::endl;
        std::cout << "5. Exit."   << std::endl << std::endl;
        std::cout << "Your command is ";

        std::string command;
        std::cin >> command;

        for (auto& ch : command)
            ch = tolower (ch);

        if      (command == "add")    myRegistry.add();
        else if (command == "remove") myRegistry.remove ();
        else if (command == "print")  myRegistry.print ();
        else if (command == "find")   myRegistry.find ();
        else if (command == "exit")   exit = true;
    }
}
