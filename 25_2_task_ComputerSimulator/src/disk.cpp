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
}



void loadFromFileToRam ()
{
    int *tmp = new int[g_size];
    std::ifstream file (filePath);
    for (int i = 0; i < g_size; ++i)
        file >> *(tmp + i);
    
    ramWrite (tmp);

    delete[] tmp;
    tmp = nullptr;
}