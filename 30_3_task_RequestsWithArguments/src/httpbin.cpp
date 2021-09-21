#include <iostream>
#include <string>
#include <map>
#include <vector>

#include <cpr/cpr.h>

#include "httpbin.h"
#include "supported.h"



static std::vector <std::string> totalReq;
static std::vector <std::string> totalReqValue;



void getTotalRequest ()
{

    std::string req = "";
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
            req = entered.substr (0, space);
            std::string value = entered.substr (space + 1, entered.size () - space);
            if (req != "" && value != "" && req != "post" && req != "get")
            {
                totalReq.push_back (req);
                totalReqValue.push_back (value);
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



void requestGet ()
{
    std::string args = "?";
    for (int i = 0; i < totalReq.size (); ++i)
    {
        args += totalReq[i] + "=" + totalReqValue[i];
        if (i + 1 < totalReq.size ())
            args += "&";
    }
    
    std::string urlWithArgs = "http://httpbin.org/get" + args;
    cpr::Response r = cpr::Get (cpr::Url (urlWithArgs));
    std::cout << r.text << std::endl;
}



void requestPost ()
{
    std::string args = "";
    for (int i = 0; i < totalReq.size (); ++i)
    {
        args += totalReq[i] + " " + totalReqValue[i];
        if (i + 1 < totalReq.size ())
            args += " ";
    }
        
    cpr::Response r = cpr::Post (cpr::Url ("http://httpbin.org/post"),
                                 cpr::Payload { {"args", args.c_str ()} });
    std::cout << r.text << std::endl;
}