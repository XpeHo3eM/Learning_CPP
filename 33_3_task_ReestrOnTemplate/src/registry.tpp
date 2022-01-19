#include <iostream>
#include <string>
#include <map>

#include "registry.h"
#include "clear.h"



template <typename T>
T enterData()
{
    T value;
    std::cin >> value;

    return value;
}



template <typename Key, typename Value>
void Registry<Key, Value>::add()
{
    std::cout << "Enter key: ";
    Key key = enterData<Key>();
    std::cout << "Enter value: ";
    Value value = enterData<Value>();
    
    clear();

    registry.insert(std::make_pair(key, value));
    std::cout << "Key   \"" << key   << "\"" << '\n' <<
                 "Value \"" << value << "\"" << '\n' <<
                 "~ Was added on registry ~" << std::endl;
    std::cout << "===================" << std::endl << std::endl;
}



template <typename Key, typename Value>
void Registry<Key, Value>::remove()
{
    std::cout << "Enter key: ";
    Key key = enterData<Key>();

    clear();

    auto itf = registry.find(key);
    if (itf != registry.end())
    {
        registry.erase(key);
        std::cout << "~ Key \"" << key << "\" was deleted ~" << std::endl;
    }
    else
    {
        std::cout << "~ Key \"" << key << "\" doesn't find ~" << std::endl; 
    }
    
    std::cout << "===================" << std::endl << std::endl;
}



template <typename Key, typename Value>
void Registry<Key, Value>::print()
{
    clear();

    for (const auto& key : registry)
    {
        std::cout << "Key: "   << key.first << '\t';
        std::cout << "Value: " << key.second << std::endl;
    }
    
    std::cout << "===================" << std::endl << std::endl;
}



template <typename Key, typename Value>
void Registry<Key, Value>::find()
{
    std::cout << "Enter key: ";
    Key key = enterData<Key>();
    
    clear();

    auto itf = registry.equal_range(key);
    
    std::cout << "Key: " << key << std::endl;
    std::cout << "Value: ";
    while (itf.first != itf.second)
    {
        std::cout << itf.first->second << ' ';
        ++itf.first;
    }
    std::cout << std::endl << "===================" << std::endl << std::endl;
}