#include <iostream>
#include "company.h"



int main()
{
    createCompany ();

    int amountTeams = getCompany ()->getAmountSubordinate ();
    for (int i = 0; i < amountTeams; ++i)
        bossAssignment (i);
}
