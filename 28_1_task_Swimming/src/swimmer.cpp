#include <string>
#include "swimmer.h"



Swimmer::Swimmer (std::string& name, double speed) : name(name), speed(speed)
{}



std::string Swimmer::getName ()
{
    return name;
}



double Swimmer::getSpeed ()
{
    return speed;
}



void Swimmer::setFinish ()
{
    finish = true;
}



bool Swimmer::getFinish ()
{
    return finish;
}



void Swimmer::setSwimTime (double time)
{
    this->time = time;
}



double Swimmer::getSwimTime ()
{
    return time;
}



int compare (Swimmer* a, Swimmer* b)
{
    return (a->getSwimTime () < b->getSwimTime ());
}