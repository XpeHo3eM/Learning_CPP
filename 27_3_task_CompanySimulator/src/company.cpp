#include <iostream>
#include "employee.h"



Employee* company = new Employee;



Employee* getCompany ()
{
    return company;
}



void createCompany ()
{
    std::cout << "Enter amount of teams: ";
    int amountTeams;
    std::cin >> amountTeams;
    for (int i = 0; i < amountTeams; ++i)
    {
        company->addSubordinate ();
        std::cout << "Enter amount of workers on " << i + 1 << " team: ";
        int amountWorkers;
        std::cin >> amountWorkers;
        Employee* manager = company->goSubordinateAt (i);
        for (int j = 0; j < amountWorkers; ++j)
            manager->addSubordinate ();
    }
}



void bossAssignment (const int teamNumber)
{
    std::cout << "Enter assignment for " << teamNumber << " team: ";
    int assignment;
    std::cin >> assignment;

    std::srand (assignment + teamNumber);
    Employee* manager = company->goSubordinateAt (teamNumber);
    int amountTask = rand () % manager->getAmountSubordinate () + 1;
    for (int i = 0; i < amountTask; ++i)
        manager->goSubordinateAt (i)->setTask ();
}