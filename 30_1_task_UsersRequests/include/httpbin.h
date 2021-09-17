#pragma once

#include <map>
#include <string>


void printAvailableCommands ();
std::string enterCommand ();
bool isCorrectCommand (std::string& inCommand);

void doRequest (std::string& req);
void requestGet ();
void requestPost ();
void requestPut ();
void requestDelete ();
void requestPatch ();