#include <iostream>
#include <fstream>
#include "const.h"
#include "ram.h"



void saveToFileFromRam ()
{
    int *tmp = ramRead ();
    std::ofstream file (filePath);
    for (int i = 0; i < g_size; ++i)
        file << *(tmp + i) << " ";
    file.close ();
    std::cout << "~ RAM was saved on disk ~" << std::endl << std::endl;
}



void loadFromFileToRam ()
{
    int *tmp = new int[g_size];
    std::ifstream file (filePath);
    if (file.is_open ())
    {
        for (int i = 0; i < g_size; ++i)
            file >> *(tmp + i);

        ramWrite (tmp);
        std::cout << "~ Data was loaded on RAM ~" << std::endl << std::endl;
    }
    else
        std::cout << "! File not found !" << std::endl << std::endl;
    
    delete[] tmp;
    tmp = nullptr;
}