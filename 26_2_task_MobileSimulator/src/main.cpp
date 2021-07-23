#include <iostream>
#include "commands.h"
#include "addressBook.h"



int main()
{   
    AddressBook myAddressBook;
    bool exit = false;
    while (!exit)
    {
        int action = chosenCommand ();

        switch (action)
        {
        case 0:
            myAddressBook.add ();
            break;
        case 1:
            myAddressBook.call ();
            break;
        case 2:
            myAddressBook.sms ();
            break;
        case 3:
            exit = true;
            break;
        default:
            std::cout << "! Incorrect command. Try again !" << std::endl << std::endl;
            break;
        }
    }
}


