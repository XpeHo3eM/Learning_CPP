#pragma once
#include "date.h"


class Track
{
public:
    Track ();
    std::string getName ()        { return name; };
    Date        getCreatedTime () { return createdTime; };
    uint16_t    getDuration ()    { return duration; };
    std::string getDurationToPrint ();

private:
    std::string name;
    Date createdTime;
    uint16_t duration;

    bool isCorrectDuration (std::string &duration);
};