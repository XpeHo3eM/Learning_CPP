#pragma once
#include <string>


class Toy
{
public:
    Toy (std::string inName) : name (inName) {};
    Toy () : Toy ("None") {};

private:
    std::string name;
};