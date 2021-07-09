#include <iostream>
#include <string>
#include "const.h"
#include "ram.h"



bool isNumber (const std::string &str)
{
    for (const char &c : str)
        if (!std::isdigit (c))
            return false;

    return true;
}



void enterNumbers ()
{
    int *tmp = new int[g_size];
    std::string str;
    std::cout << "Enter " << g_size << " numbers: ";
    
    for (int i = 0; i < g_size;)
    {
        std::cin >> str;
        if (isNumber (str))
        {
            *(tmp + i) = std::stoi (str);
            ++i;
        }
    }
    ramWrite (tmp);

    delete[] tmp;
    tmp = nullptr;
}



