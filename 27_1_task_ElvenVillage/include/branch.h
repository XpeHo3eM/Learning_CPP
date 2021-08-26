#include <iostream>
#include <string>
#include <vector>



class Branch
{
public:
    void addChildren ();
    void settling();
    Branch* getChildrenAt (const int index);
    int getCountChildrens ();
    std::string getElvenName ();
     
protected:
    std::string elvenName = "unknown";
    Branch* parent = nullptr;
    std::vector <Branch*> childrens;
    
};



void findElf (const std::string& name);



void createForest ();