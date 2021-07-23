#pragma once

#include <vector>
#include <string>

class Contact
{
public:
    Contact (const std::string &newName, const std::string &newPhoneNumber);
    void getName (std::string &buf);
    void getPhoneNumbers (std::vector <std::string> &vec);
    void setName (const std::string &newName);
    void setPhone (const std::string &newPhoneNumber);

private:
    std::string name;
    std::vector <std::string> phoneNumbers;
};