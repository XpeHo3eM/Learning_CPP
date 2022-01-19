#pragma once

#include <map>



template <typename Key, typename Value>
class Registry
{
public:
    void add();
    void remove();
    void print();
    void find();

private:
    std::multimap <Key, Value> registry;
};



template <typename T>
T enterData();


#include "registry.tpp"