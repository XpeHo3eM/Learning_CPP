#pragma once


class Date
{
public:
    Date ();
    void setDate ();
    uint16_t getDay ()   { return day;   };
    uint16_t getMonth () { return month; };
    uint16_t getYear ()  { return year;  };
    void getDateToPrint (std::string &date);
        
private:
    uint16_t day;
    uint16_t month;
    uint16_t year;

    bool isCorrectDate (std::string &date);
};
