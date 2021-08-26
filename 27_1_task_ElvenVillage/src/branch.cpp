#include <iostream>
#include <string>
#include <ctime>
#include "branch.h"
#include "clear.h"



constexpr int countTree = 5;
class Branch** forest = new Branch* [countTree];



void Branch::addChildren ()
{
    Branch* newChildren = new Branch;
    newChildren->parent = this;
    childrens.push_back (newChildren);
}



Branch* Branch::getChildrenAt (const int index)
{
    return (this->childrens[index]);
}



int Branch::getCountChildrens ()
{
    return (this->childrens.size ());
}



std::string Branch::getElvenName ()
{
    return elvenName;
}



void Branch::settling ()
{
    int countBigBranch = this->childrens.size ();
    for (int bb = 0; bb < countBigBranch; ++bb)
    {
        std::cout << "~ " << bb + 1 << " OF " << countBigBranch << " BIG BRANCH ~" << std::endl;
        int countMiddleBranch = this->childrens[bb]->childrens.size ();
        for (int mb = 0; mb < countMiddleBranch; ++mb)
        {
            std::cout << "~ " << mb + 1 << " OF " << countMiddleBranch << " MIDDLE BRANCH ~" << std::endl;
            Branch* child = this->childrens[bb]->childrens[mb];
            std::cout << "Enter elven name: ";
            std::cin >> child->elvenName;
        }
    }
}



void findElf (const std::string& inName)
{
    for (int i = 0; i < countTree; ++i)
    {
        Branch* tree = forest[i];
        for (int bb = 0; bb < tree->getCountChildrens (); ++bb)
        {
            bool found = false;

            // First name == &name increase count too
            // Some elven name can be &name
            int countNeighbor = -1;
            Branch* child = tree->getChildrenAt (bb);
            for (int mb = 0; mb < child->getCountChildrens (); ++mb)
            {
                std::string name = child->getChildrenAt (mb)->getElvenName ();
                if (!found && name == inName)
                {
                    found = true;
                    mb = 0;
                }
                if (found && name != "None")
                    ++countNeighbor;
            }
            if (found)
                std::cout << i + 1 << " tree " << bb + 1 << " big branch " << countNeighbor << " neighbors" << std::endl;
        }
    }
}



void createForest ()
{
    for (int i = 0; i < countTree; ++i)
    {
        clear ();
        std::cout << "~~ " << i + 1 << " OF " << countTree << " TREE ~~" << std::endl;
        forest[i] = new Branch;
        int countBigBranch = rand () % 3 + 3;
        for (int bb = 0; bb < countBigBranch; ++bb)
        {
            forest[i]->addChildren ();

            int countMiddleBranch = rand () % 2 + 2;

            for (int mb = 0; mb < countMiddleBranch; ++mb)
                forest[i]->getChildrenAt (bb)->addChildren ();
        }

        forest[i]->settling ();
    }
}