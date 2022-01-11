#include <iostream>
#include <string>
#include <map>
#include <fstream>

#include "basket.h"
#include "throws.h"
#include "clear.h"


Basket::Basket()
{
    std::ifstream file("database.txt");
    if (file.is_open())
    {
        std::string article;
        int amount;
        while (file >> article >> amount)
        {
            auto itf = database.find(article);
            if (itf == database.end())
                database.insert(std::make_pair(article, amount));
            else
                itf->second += amount;
        }            
    }
    else
        std::cerr << "! Database not found !" << std::endl;
}



void Basket::add(std::string &inArticle, int inAmount)
{
    auto productOnDatabase = database.find(inArticle);
    if (productOnDatabase == database.end())
        throw Error::ARTICLE_NOT_FOUND;
    else
    {
        int amountOnDatabase = productOnDatabase->second;
        if (amountOnDatabase < inAmount)
            throw Error::NOT_ENOUGH_AMOUNT;

        auto productOnBasket = basket.find(inArticle);
        if (productOnBasket != basket.end())
        {
            int amountOnBasket = productOnBasket->second;

            if (amountOnDatabase < amountOnBasket + inAmount)
                throw Error::NOT_ENOUGH_AMOUNT;
            else
                productOnBasket->second += inAmount;                
        }
        else
            basket.insert(std::make_pair(inArticle, inAmount));
    }

    clear();
    std::cout << "~ Product was added to basket ~" << std::endl << std::endl;
};



void Basket::remove(std::string &inArticle, int inAmount)
{
    auto productOnBasket = basket.find(inArticle);
    if (productOnBasket == basket.end())
        throw Error::ARTICLE_NOT_FOUND;

    int amountProduct = productOnBasket->second;
    if (amountProduct < inAmount)
        throw Error::NOT_ENOUGH_AMOUNT;
    else
        if (amountProduct == inAmount)
            basket.erase(inArticle);
        else
            productOnBasket->second -= inAmount;

    clear();
    std::cout << "~ Product was deleted from basket ~" << std::endl << std::endl;
};



void generateDatabase()
{
    std::ofstream file("database.txt");
    std::string data = "000001 10 \n\
                        000002  4 \n\
                        000003  2 \n\
                        000004  7 \n\
                        000005 11 \n\
                        000001  3 \n\
                        000002  6";
    file << data;
    file.close();
}