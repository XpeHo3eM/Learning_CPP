#include <iostream>
#include "pc.h"
#include "const.h"


bool isCorrectCommand (std::string &enteredCommand);


class Pc
{
public: 
    Pc ()
    {
        ram = new int[g_size];
    }

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

    ~Pc ()
    {
        delete[] ram;
        ram = nullptr;
    }

private:
    int *ram;
};



std::string commands[] {"sum", "save", "load", "input", "display", "exit"};


int main()
{
    Pc pc;
    bool exit = false;
    while (!exit)
    {
        std::cout << "Enter command: " << std::endl;
        for (const auto c : commands)
            std::cout << " - " << c << std::endl;

        std::string enteredCommand;
        do
            std::cin >> enteredCommand;
        while (!isCorrectCommand (enteredCommand));

        int c = 0;
        while (enteredCommand != commands[c])
            ++c;

        switch (c)
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


bool isCorrectCommand (std::string &enteredCommand)
{
    for (int i = 0; i < commands->size (); ++i)
        if (enteredCommand == commands[i])
            return true;

    return false;
}
