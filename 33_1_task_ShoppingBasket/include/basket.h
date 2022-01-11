#pragma once

#include <string>
#include <map>


class Basket
{
public:
    Basket();
    void add(std::string& inArticle, int inAmount);
    void remove(std::string& inArticle, int inAmount);

private:
    std::map <std::string, int> database;
    std::map <std::string, int> basket;
};



void generateDatabase();
