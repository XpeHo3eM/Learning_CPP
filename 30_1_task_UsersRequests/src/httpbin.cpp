#include <iostream>
#include <string>
#include <map>

#include <cpr/cpr.h>

#include "httpbin.h"
#include "supported.h"



enum Command
{
    HTTP_GET,
    HTTP_PUT,
    HTTP_POST,
    HTTP_PATCH,
    HTTP_DELETE,
    EXIT
};


std::map <std::string, int> command { {"get", HTTP_GET},     {"put", HTTP_PUT},       {"post", HTTP_POST},
                                      {"patch", HTTP_PATCH}, {"delete", HTTP_DELETE}, {"exit", EXIT} };



void printAvailableCommands ()
{
    std::cout << "Available command:" << std::endl;
    for (const auto& c : command)
        std::cout << "- " << c.first << ";" << std::endl;
}



bool isCorrectCommand (std::string& inCommand)
{
    for (const auto& c : command)
        if (c.first == inCommand)
            return true;
    
    std::cout << "! Incorrect command. Try again !" << std::endl;
    return false;
}



std::string enterCommand ()
{
    std::string command;
    do
    {
        std::cout << "Enter command: ";
        std::cin >> command;
    } 
    while (!isCorrectCommand (command));

    return command;
}



void doRequest (std::string& req)
{
    std::map <std::string, int>::iterator itf = command.find (req);
    int reqNumber = itf->second;

    std::cout << "Entered command: " << itf->first << std::endl << std::endl;
    switch (reqNumber)
    {
    case HTTP_GET   : requestGet ();    break;
    case HTTP_PUT   : requestPut ();    break;
    case HTTP_POST  : requestPost ();   break;
    case HTTP_PATCH : requestPatch ();  break;
    case HTTP_DELETE: requestDelete (); break;
    default         : return;           break;
    }

    wait ();
}



void requestGet ()
{
    cpr::Response r = cpr::Get (cpr::Url ("http://httpbin.org/get"));
    std::cout << r.text << std::endl;
}



void requestPut ()
{
    cpr::Response r = cpr::Put (cpr::Url ("http://httpbin.org/put"));
    std::cout << r.text << std::endl;
}



void requestPost ()
{
    cpr::Response r = cpr::Post (cpr::Url ("http://httpbin.org/post"));
    std::cout << r.text << std::endl;
}



void requestPatch ()
{
    cpr::Response r = cpr::Patch (cpr::Url ("http://httpbin.org/patch"));
    std::cout << r.text << std::endl;
}



void requestDelete ()
{
    cpr::Response r = cpr::Delete (cpr::Url ("http://httpbin.org/delete"));
    std::cout << r.text << std::endl;
}