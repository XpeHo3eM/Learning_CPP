#include <iostream>
#include <string>
#include <ctime>



class Branch
{
public:
    Branch ();
    Branch (Branch *parent);
    Branch *getParent ();
    std::string getName ();
 
protected:
    std::string elvenName = "unknown";
    Branch *parent = nullptr;
};



class BigBranch : public Branch
{
public:
    BigBranch ();
    int getCountMiddleBranch ();
    Branch* getMiddleBranchAt (int index);
 
protected:
    Branch **middleBranch = nullptr;
    int countMiddleBranch = 0;
};



class Tree
{
public:
    Tree (Tree **forest, int countTree);
    void findElf (std::string &name);

private:
    int countBigBranch = 0;
    BigBranch **bigBranch = nullptr;
    Tree **forest = nullptr;
    int countTree = 0;
};