/*
Реализуйте простую и безопасную модель работы корзины онлайн - магазина.

в начале программы вы заполняете базу данных самого магазина через стандартную консоль.
каждый элемент этой базы данных состоит из двух компонентов — артикула и количества штук.
корзина должна поддерживать следующие операции: 
1. добавление товара с указанным его количеством — add
2. удаление товара с указанным количеством — remove.
обе операции принимают артикул товара в виде строки и количество в виде целого числа.
3. при вводе аргументов к операциям должна осуществляться их валидация.
артикул должен быть в базе данных магазина, количество не должно превышать количество 
доступного продукта на складе(при удалении — в корзине).
*/


#include <iostream>

#include "basket.h"
#include "throws.h"
#include "clear.h"



int main()
{
    generateDatabase();
    Basket basket;
    
    bool exit = false;
    while (!exit)
    {

        std::cout << "Choose one of action: "         << std::endl;
        std::cout << "1. Add product to basket;"      << std::endl;
        std::cout << "2. Remove product from basket;" << std::endl;
        std::cout << "0. Exit from shop."             << std::endl;

        int chosen;
        std::cin >> chosen;

        std::string article = "";
        int amount = 0;
        if (chosen == 1 || chosen == 2)
        {
            std::cout << "Enter product article:";
            std::cin >> article;
            std::cout << "Enter product amount:";
            std::cin >> amount;
        }
        try
        {
            switch (chosen)
            {
            case 1: basket.add(article, amount);    break;
            case 2: basket.remove(article, amount); break;
            case 0: exit = true;                    break;
            default: std::cout << "! Incorrect choose. Try again !";
            }
        }
        catch (Error myErr)
        {
            clear();
            switch (myErr)
            {
            case Error::ARTICLE_NOT_FOUND: 
                std::cout << "==============================" << std::endl;
                std::cerr << "! This article doesn't found !" << std::endl;
                std::cout << "==============================" << std::endl << std::endl;
                break;

            case Error::NOT_ENOUGH_AMOUNT:
                std::cout << "=====================" << std::endl;
                std::cerr << "! Not enough amount !" << std::endl;          
                std::cout << "=====================" << std::endl << std::endl; 
                break;
            }
        } 
    }
}