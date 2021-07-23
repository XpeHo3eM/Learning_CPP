#include <iostream>
#include <map>
#include <string>
#include "contact.h"
#include "addressBook.h"
#include "clear.h"



void AddressBook::add()
{   
    using std::endl;

    clear ();
    std::string number;
    std::string name;
    std::cout << "Enter contact name: ";
    std::cin >> name;
    std::cout << "Enter phone number on format +7xxxxxxxxxx: ";
    do
    {
        std::cin >> number;
        if (!isPhoneNumber (number))
            std::cout << "! Incorrect phone number format. Try again !" << endl << endl;
        if (isPhoneNumberExist (number))
            std::cout << "! This phone number exist. Enter new phone number !" << endl << endl;
    }
    while (!isPhoneNumber (number) || isPhoneNumberExist (number));

    clear ();
    std::map <std::string, Contact>::iterator itf = abNameContact.find (name);
    if (itf == abNameContact.end ())
    {
        Contact newContact (name, number);
        abNameContact.insert (std::pair <std::string, Contact> (name, newContact));

        std::cout << "~ New contact created ~" << endl << endl;
    }
    else
    {
        itf->second.setPhone (number);

        std::cout << "~ Phone was added to " << itf->first << " ~" << endl << endl;
    }
    abPhoneName.insert (std::pair <std::string, std::string> (number, name));
    std::cout << endl;
}


void AddressBook::call ()
{
    using std::endl;
    clear ();

    std::string data;
    std::cout << "Enter name of contact or phone number to call: ";
    std::cin >> data;
    clear ();

    if (isPhoneNumber (data))
    {
        if (isPhoneNumberExist (data))
            std::cout << "Calling " << data << " ... " << endl << endl;
        else
            std::cout << "! " << data << " phone number doesn't exist !" << endl << endl;
    }
    else
    {
        std::map <std::string, Contact>::iterator itf = abNameContact.find (data);
        if (itf != abNameContact.end ())
        {
            std::vector <std::string> phoneNumbers;
            itf->second.getPhoneNumbers (phoneNumbers);
            if (phoneNumbers.size () > 1)
            {
                std::cout << "On which phone need to call?" << endl;
                int numPhone = 0;
                for (const auto &p: phoneNumbers)
                {
                    std::cout << "  " << numPhone + 1 << ". " << p << ";" << endl;
                    ++numPhone;
                }
                int call;
                do
                {
                    std::cin >> call;
                    if (call <= 0 || call > numPhone)
                        std::cout << "! Incorrect phone position number. Try again !" << endl << endl;
                }
                while (call <= 0 || call > numPhone);

                // on vector position 0..n, user entered 1..n+1
                --call;
                clear ();

                std::cout << "Calling " << phoneNumbers[call] << " ... " << endl << endl;
            }
            else
                std::cout << "Calling " << phoneNumbers[0] << " ... " << endl << endl;
        }
        else
            std::cout << "! Contact " << data << " not found !" << endl << endl;
    }
}


void AddressBook::sms ()
{
    using std::endl;
    clear ();

    std::string data;
    std::string message;
    std::cout << "Enter name of contact or phone number to send sms: ";
    std::cin >> data;
    if (isPhoneNumber (data))
    {
        if (isPhoneNumberExist (data))
        {
            smsEnter (data);
        }
        else
            std::cout << "! " << data << " phone number doesn't exist !" << endl << endl;
    }
    else
    {
        clear ();
        std::map <std::string, Contact>::iterator itf = abNameContact.find (data);
        if (itf != abNameContact.end ())
        {
            std::vector <std::string> phoneNumbers;
            itf->second.getPhoneNumbers (phoneNumbers);
            if (phoneNumbers.size () > 1)
            {
                std::cout << "On which phone need send sms?" << endl;
                int numPhone = 0;
                for (const auto &p: phoneNumbers)
                {
                    std::cout << "  " << numPhone + 1 << ". " << p << ";" << endl;
                    ++numPhone;
                }
                int num;
                do
                {
                    std::cin >> num;
                    if (num <= 0 || num > numPhone)
                        std::cout << "! Incorrect phone number. Try again !" << endl << endl;
                }
                while (num <= 0 || num > numPhone);

                // on vector position 0..n, user entered 1..n+1
                --num;

                smsEnter (phoneNumbers[num]);
            }
            else
                smsEnter (phoneNumbers[0]);
        }
        else
            std::cout << "! Contact with this data not found !" << endl << endl;
    }
}


void AddressBook::smsEnter (std::string &number)
{
    clear ();
    std::string message;
    std::cout << "Enter a message:";
    std::cin.ignore ();
    std::getline (std::cin, message);
    
    clear ();
    std::cout << "Sending sms to " << number << " ... " << std::endl;
    std::cout << "Message text: " << message << std::endl << std::endl;
}


bool AddressBook::isPhoneNumber (const std::string &str)
{
    if (str.size () != 12 || str[0] != '+' || str[1] != '7')
        return false;

    for (int i = 2; i < str.size (); ++i)
        if (!isdigit (str[i]))
            return false;

    return true;
}


bool AddressBook::isPhoneNumberExist (const std::string &numb)
{
    return (abPhoneName.find (numb) != abPhoneName.end ());
}

