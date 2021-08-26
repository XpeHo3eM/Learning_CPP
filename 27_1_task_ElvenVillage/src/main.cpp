#include <iostream>
#include <ctime>
#include "branch.h"
#include "clear.h"



int main()
{
    std::srand (std::time (nullptr));

    createForest ();

    clear ();
    std::cout << "Enter elven name to find: ";
    std::string name;
    std::cin >> name;
    findElf (name);
}
