#pragma once

#include <iostream>
#include <vector>



enum Task
{
    A,
    B,
    C,
    AMOUNT_TASK,
    NONE
};



class Employee
{
public:
    void addSubordinate ();
    int getAmountSubordinate ();
    Employee* goSubordinateAt (const int index);
    void setTask ();
    Task getTask ();

private:
    Employee* boss = nullptr;
    std::vector <Employee*> subordinate;
    Task task = NONE;
};