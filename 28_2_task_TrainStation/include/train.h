#pragma once

#include <string>



class Train
{
public:
    Train (std::string name, int time);
    std::string getName ();
    int getTime ();

private:
    std::string name = "unknown";
    int timeOnWay = 0;
};