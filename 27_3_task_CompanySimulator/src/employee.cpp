#include <iostream>
#include <vector>
#include "employee.h"



void Employee::addSubordinate ()
{
    Employee* newWorker = new Employee;
    newWorker->boss = this;
    subordinate.push_back (newWorker);
}



int Employee::getAmountSubordinate ()
{
    return subordinate.size ();
}



Employee* Employee::goSubordinateAt (const int index)
{
    return subordinate[index];
}



void Employee::setTask ()
{
    if (this->task == NONE)
    {
        int task = rand () % AMOUNT_TASK;
        this->task = static_cast<Task>(task);
    }
}



Task Employee::getTask ()
{
    return task;
}