#include <iostream>
#include <string>
#include <vector>

#include <cpr/cpr.h>

#include "httpbin.h"
#include "supported.h"



static std::vector <cpr::Pair> pairs;


void requestGet ()
{
    std::string args = "?";
    for (int i = 0; i < pairs.size (); ++i)
    {
        args += pairs[i].key + "=" + pairs[i].value;
        if (i + 1 < pairs.size ())
            args += "&";
    }

    std::string urlWithArgs = "http://httpbin.org/get" + args;
    cpr::Response r = cpr::Get (cpr::Url (urlWithArgs));
    std::cout << r.text << std::endl;
}



void requestPost ()
{
    std::string args = "";
    for (int i = 0; i < pairs.size (); ++i)
    {
        args += pairs[i].key + " " + pairs[i].value;
        if (i + 1 < pairs.size ())
            args += " ";
    }

    cpr::Response r = cpr::Post (cpr::Url ("http://httpbin.org/post"),
                                 cpr::Payload { {"args", args.c_str ()} });
    std::cout << r.text << std::endl;
}



void getTotalRequest ()
{   
    bool exit = false;
    do
    {
        std::cout << "Enter request name and value: ";
        std::string entered;
        std::getline (std::cin, entered);

        clear ();

        size_t countSpace = std::count (entered.begin (), entered.end (), ' ');
        if (countSpace == 1)
        {
            size_t space = entered.find (' ');
            std::string req = entered.substr (0, space);
            std::string value = entered.substr (space + 1, entered.size () - space);
            if (req != "" && value != "" && req != "post" && req != "get")
            {
                pairs.push_back (cpr::Pair(entered.substr (0, space), entered.substr (space + 1, entered.size() - space)));
                std::cout << "~ Request witch value was added ~" << std::endl;
            }
            else
                if (req == "post" || req == "get")
                {
                    (req == "post") ? requestPost () : requestGet ();
                    exit = true;
                }

                else
                    std::cerr << "! Incorrect request !" << std::endl;
        }
        else
            std::cerr << "! Incorrect request !" << std::endl;
    } while (!exit);
}