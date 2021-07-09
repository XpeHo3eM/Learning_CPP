#include <iostream>
#include "pc.h"
#include "const.h"
#include <map>


class Pc
{
public: 
    void sum ()
    {
        print ();
        print (compute ());
    }

    void save ()
    {
        saveToFileFromRam ();
    }

    void load ()
    {
        loadFromFileToRam ();
    }

    void input ()
    {
        enterNumbers ();
    }

    void display ()
    {
        print ();
    }
};



std::map <std::string, int> commands {{"sum", 0},   {"save", 1},    {"load", 2},
                                      {"input", 3}, {"display", 4}, {"exit", 5}};


int main()
{
    Pc pc;
    bool exit = false;
    while (!exit)
    {
        std::cout << "Enter command: " << std::endl;
        for (const auto c : commands)
            std::cout << " - " << c.first << std::endl;

        std::string enteredCommand;
        std::map <std::string, int>::iterator itc;
        do
        {
            std::cin >> enteredCommand;
            itc = commands.find (enteredCommand);
            if (itc == commands.end ())
                std::cout << "! Incorrect command. Try again !" << std::endl;
        }
        while (itc == commands.end());

        system ("cls");

        switch (itc->second)
        {
        case 0: pc.sum();       break;
        case 1: pc.save ();     break;
        case 2: pc.load ();     break;
        case 3: pc.input ();    break;
        case 4: pc.display ();  break;
        case 5: exit = true;    break;
        default: 
            std::cout << "! Incorrect command !" << std::endl;
            exit = true;
            break;
        }
    }
}