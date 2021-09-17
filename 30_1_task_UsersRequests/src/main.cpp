#include <iostream>
#include "httpbin.h"
#include "supported.h"



int main ()
{
    std::string command = "";
    while (command != "exit")
    {
        clear ();
        printAvailableCommands ();
        command = enterCommand ();
        clear ();
        doRequest (command);
    }
}