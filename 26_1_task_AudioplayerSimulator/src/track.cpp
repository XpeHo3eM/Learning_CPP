#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <ctime>
#include "track.h"


Track::Track ()
{
    std::string name;
    std::cout << "Enter track's name: ";
    std::getline (std::cin, name);
    
    createdTime.setDate ();

    std::string timing;
    bool correct = false;
    while (!correct)
    {
        std::cout << "Enter track's duration om format MM:SS: ";
        std::getline (std::cin, timing);

        correct = isCorrectDuration (timing);
        if (!correct)
            std::cout << "! Incorrect duration. Try again !" << std::endl;        
    }
    uint16_t min      = std::stoi (timing.substr (0, 2));
    uint16_t sec      = std::stoi (timing.substr (3, 2));
    uint16_t duration = min * 60 + sec;

    
    this->duration    = duration;
    this->name        = name;
}


void Track::getName (std::string &name)
{
    name = this->name;
}


void Track::getCreatedTime (Date &createdTime)
{
    createdTime = this->createdTime;
}


void Track::getDuration (int &duration)
{
    duration = this->duration;
}


bool Track::isCorrectDuration (std::string &duration)
{
    if (duration.size () != 5 || duration[2] != ':')
        return false;
    for (uint16_t i = 0; i < duration.size (); ++i)
        if ((!isdigit (duration[i])) && i != 2)
            return false;

    uint16_t min = std::stoi (duration.substr (0, 2));
    uint16_t sec = std::stoi (duration.substr (3, 2));
    uint16_t timing = min * 60 + sec;

    return (timing > 0);
}