#include <iostream>
#include <ctime>
#include "tree.h"
#include "clear.h"



int main()
{
    std::srand (std::time (nullptr));

    constexpr int countTree = 5;
    Tree **forest = new Tree* [countTree];
    for (int i = 0; i < countTree; ++i)
    {
        clear ();
        std::cout << "~~ " << i + 1 << " OF " << countTree << " TREE ~~" << std::endl;
        forest[i] = new Tree(forest, countTree);
    }
        

    clear ();
    std::cout << "Enter elven name to find: ";
    std::string name;
    std::cin >> name;
    for (int i = 0; i < countTree; ++i)
        forest[i]->findElf (name);
}
