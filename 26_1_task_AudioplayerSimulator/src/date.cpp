#include <iostream>
#include <string>
#include "date.h"


Date::Date ()
{
    day   = 0;
    month = 0;
    year  = 0;
}


void Date::setDate ()
{
    std::string date;
    bool correct = false;
    while (!correct)
    {
        std::cout << "Enter date on format DD/MM/YYYY: ";
        std::getline (std::cin, date);
        correct = isCorrectDate (date);
        if (!correct)
            std::cout << "! Incorrect date. Try again !" << std::endl;
    }
    
    day   = std::stoi (date.substr (0, 2));
    month = std::stoi (date.substr (3, 2));
    year  = std::stoi (date.substr (6, 4));
}


bool Date::isCorrectDate (std::string &date)
{
    if (date.size () != 10 || date[2] != '/' || date[5] != '/')
        return false;
    for (uint16_t i = 0; i < date.size (); ++i)
        if (!isdigit (date[i]) && i != 2 && i != 5)
            return false;

    uint16_t day   = std::stoi (date.substr (0, 2));
    uint16_t month = std::stoi (date.substr (3, 2));
    uint16_t year  = std::stoi (date.substr (6, 4));

    if (month == 4 || month == 6 || month == 9 || month == 11)
        return (day <= 30);
    else
        if (month == 2)
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                return (day <= 29);
            else
                return (day <= 28);
        else
            return (day <= 30);
}


std::string Date::getDateToPrint ()
{
    std::string dPrint = "";
    std::string mPrint = "";
    std::string yPrint = "";

    if (day < 10)
        dPrint += "0";
    dPrint += std::to_string (day);

    if (month < 10)
        mPrint += "0";
    mPrint += std::to_string (month);

    uint16_t tmpYear = year;
    for (uint16_t i = 0; i < 4; ++i)
    {
        if (tmpYear == 0)
            yPrint += "0";
        tmpYear /= 10;
    }
    yPrint += std::to_string (year);
        
    return (dPrint + "/" + mPrint + "/" + yPrint);
}