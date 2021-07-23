#pragma once

#include <map>
#include <string>
#include "contact.h"


class AddressBook
{
public:
    void add ();
    void call ();
    void sms ();

private:
    std::map <std::string, Contact> abNameContact;
    std::map <std::string, std::string> abPhoneName;

    void smsEnter (std::string &number);
    bool isPhoneNumber (const std::string &str);
    bool isPhoneNumberExist (const std::string &numb);
};