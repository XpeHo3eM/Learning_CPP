#pragma once
#include "date.h"

class Track
{
public:
    Track ();
    void getName (std::string &name);
    void getCreatedTime (Date &createdTime);
    void getDuration (int &duration);

private:
    std::string name;
    Date createdTime;
    int duration;

    bool isCorrectDuration (std::string &duration);
};