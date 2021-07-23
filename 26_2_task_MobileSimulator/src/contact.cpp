#include <string>
#include <vector>
#include "contact.h"


Contact::Contact (const std::string &newName, const std::string &newPhoneNumber)
{
    setName (newName);
    setPhone (newPhoneNumber);
}


void Contact::getName (std::string &buf)
{
    buf = name;
}


void Contact::getPhoneNumbers (std::vector <std::string> &vec)
{
    vec = phoneNumbers;
}


void Contact::setName (const std::string &newName)
{
    name = newName;
}


void Contact::setPhone (const std::string &newPhoneNumber)
{
    phoneNumbers.push_back (newPhoneNumber);
}


