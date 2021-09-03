#include <iostream>
#include <string>
#include "train.h"



Train::Train (std::string name, int time) : name(name), timeOnWay(time)
{}



std::string Train::getName ()
{
    return name;
}



int Train::getTime ()
{
    return timeOnWay;
}