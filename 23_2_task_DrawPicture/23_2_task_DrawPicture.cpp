#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>


void initial(int& side, std::string sideName)
{
    system("cls");
    do
    {
        std::cout << "Enter picture's " << sideName << ": ";
        std::cin >> side;
        if (side <= 0)
        {
            system("cls");
            std::cout << "Incorrect input for " << sideName << ", try again." << std::endl << std::endl;
        }
    } 
    while (side <= 0);
}


int main()
{
    int width, height;
    initial(width, "width");
    initial(height, "height");

    std::ofstream picture("pic.txt");
    std::srand(std::time(nullptr));
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
            picture << std::rand() % 2;
        picture << std::endl;
    }
    picture.close();
    system("cls");
    std::cout << "~~ Your picture was created. Look at this ~~" << std::endl;
}