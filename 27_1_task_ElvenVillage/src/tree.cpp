#include <iostream>
#include <string>
#include <ctime>
#include "tree.h"
#include "clear.h"


Branch::Branch () {}



Branch::Branch (Branch *parent)
{
    this->parent = parent;
    std::cout << "Enter elven name: ";
    std::cin >> elvenName;
}



Branch* Branch::getParent ()
{
    return parent;
}



std::string Branch::getName ()
{
    return elvenName;
}




BigBranch::BigBranch ()
{
    countMiddleBranch = rand () % 3 + 1;
    middleBranch = new Branch* [countMiddleBranch];
    for (int i = 0; i < countMiddleBranch; ++i)
    {
        std::cout << " ~ " << i + 1 << " of " << countMiddleBranch << 
                     " middle branch ~" << std::endl;
        middleBranch[i] = new Branch (this);
    }
    std::cout << "~ BIG BRANCH ENDED ~" << std::endl << std::endl;
}



int BigBranch::getCountMiddleBranch ()
{
    return countMiddleBranch;
}



Branch* BigBranch::getMiddleBranchAt (int index)
{
    return middleBranch[index];
}




Tree::Tree (Tree **forest, int countTree)
{
    this->forest = forest;
    this->countTree = countTree;
    countBigBranch = rand () % 4 + 2;
    bigBranch = new BigBranch* [countBigBranch];

    for (int i = 0; i < countBigBranch; ++i)
    {
        std::cout << "~ " << i + 1 << " OF " << countBigBranch << " BIG BRANCH ~" << std::endl;
        bigBranch[i] = new BigBranch ();
    }
}


    
void Tree::findElf (std::string &name)
{
    for (int i = 0; i < countBigBranch; ++i)
    {
        // First elf with name = &name increase countNeighbor too 
        // because we can have some elf with name = &name on branch
        int countNeighbor = -1;
        bool found = false;
        for (int j = 0; j < bigBranch[i]->getCountMiddleBranch(); ++j)
        {
            std::string elvenName = bigBranch[i]->getMiddleBranchAt (j)->getName ();
            
            // If found elvenName - start again to summary neighbors on big branch
            if (!found && (elvenName == name))
            {
                found = true;
                j = 0;
            }
            if (found && (elvenName != "None"))
                ++countNeighbor;
        }
        if (found)
        {
            for (int f = 0; f < countTree; ++f)
                if (forest[f] == this)
                    std::cout << "~~ On " << f + 1 << " tree ";

            std::cout << "on " << i + 1 << " big branch ";
            if (countNeighbor > 0)
                std::cout << countNeighbor << " neighbors ~" << std::endl;
            else
                std::cout << "haven't neighbors ~" << std::endl;
        }
    }
}
