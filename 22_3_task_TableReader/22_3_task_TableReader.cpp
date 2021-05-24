#include <iostream>
#include <fstream>

int main()
{
    std::fstream file;
    file.open("table.txt");

    if (file.is_open())
    {
        std::string name;
        std::string secondName;
        int money;
        std::string date;

        int totalPayedMoney = 0;
        int maxPayedMoney = 0;
        std::string richestMan;

        while (!file.eof())
        {
            file >> name >> secondName >> money >> date;
            std::cout << name << ' ' << secondName << '\t' << money << '\t' << date << std::endl;

            totalPayedMoney += money;
            if (money > maxPayedMoney)
            {
                maxPayedMoney = money;
                richestMan = name + " " + secondName;
            }
        }
        file.close();

        std::cout << std::endl << std::endl;
        std::cout << "Richest man is: " << richestMan << std::endl;
        std::cout << "Has " << maxPayedMoney << " money" << std::endl;
    }
    else
        std::cout << "File not found" << std::endl;
}