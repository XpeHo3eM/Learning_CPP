#pragma once
#include "date.h"


class Track
{
public:
    Track ();
    void getName (std::string &name);
    void getCreatedTime (Date &createdTime);
    void getDuration (uint16_t &duration);
    void getDurationToPrint (std::string &duration);

private:
    std::string name;
    Date createdTime;
    uint16_t duration;

    bool isCorrectDuration (std::string &duration);
};