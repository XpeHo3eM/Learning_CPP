#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>


// Отображаем перечень возможных типов рыб в реке
void showFishOnRiver()
{
    std::ifstream river("river.txt");
    if (river.is_open())
    {
        std::string fish;
        std::vector<std::string> typeFish;

        while (river >> fish)
        {
            bool found = false;
            for (int i = 0; (i < typeFish.size()) && !found; ++i)
                if (fish == typeFish[i])
                    found = true;
            if (!found)
                typeFish.push_back(fish);
        }

        std::cout << "~~ You can catch on this river next kind of fish ~~" << std::endl;
        for (int i = 0; i < typeFish.size(); ++i)
            std::cout << i + 1 << ". " << typeFish[i] << std::endl;

        std::cout << std::endl << std::endl;
    }
}


// Проверяем удалось ли поймать рыбу
void isCatchFish(const std::string& fishToCatch)
{
    std::ifstream river("river.txt");

    bool catchFish = false;
    std::string currentFish;

    while (river >> currentFish && !catchFish)
        catchFish = (fishToCatch == currentFish);

    system("cls");
    if (catchFish)
    {
        std::ofstream basket("basket.txt", std::ios::app);
        std::cout << "~~ Congratulation! You catch " << fishToCatch << " ~~" << std::endl << std::endl;
        basket << fishToCatch << std::endl;
        basket.close();
    }
    else
        std::cout << "~~ This kind of fish haven't on this river ~~" << std::endl << std::endl;

    river.close();
}


// Пауза для возможности прочитать информацию в ожидании корректного ввода
void previousMenu()
{
    std::cout << "Enter 0 to return for previous menu: ";
    int answer;
    do
        std::cin >> answer;
    while (answer != 0);
}


// Производим рыбалку
void fishing()
{
    char answer;
    do
    {
        std::ifstream river("river.txt");
        if (river.is_open())
        {
            // После обнаружения файла - можно закрыть пока не используется
            river.close();

            system("cls");
            showFishOnRiver();

            std::cout << "What kind of fish would you like to catch? " << std::endl;
            std::cout << "Enter kind of fish to catch: ";
            std::string fishToCatch;
            std::cin >> fishToCatch;

            isCatchFish(fishToCatch);

            do
            {
                std::cout << "Would you like to catch some fish today? (y/n): ";
                std::cin >> answer;
            } while (answer != 'y' && answer != 'n');
        }
        else
        {
            system("cls");
            std::cout << "File river.txt not found" << std::endl << std::endl;

            // Если файла нет - продолжать нет смысла
            answer = 'n';

            previousMenu();

        }
    } while (answer != 'n');
}


// Вывод улова в корзине
void showBasket()
{
    system("cls");
    std::ifstream basket("basket.txt");
    std::string fish;
    if (!basket.is_open() || !(basket >> fish))
        std::cout << "~~ Your basket is empty ~~" << std::endl << std::endl;
    else
    {
        do
            std::cout << fish << std::endl;
        while (basket >> fish);

        basket.close();
    }
    
    previousMenu();
}


// Очистка улова из корзины
void clearBasket()
{
    system("cls");
    std::ofstream basket("basket.txt");
    basket.close();

    std::cout << "~~ Basket was cleared ~~" << std::endl << std::endl;

    previousMenu();
}


int main()
{
    bool exit = false;
    do
    {  
        system("cls");
        using namespace std;
        cout << "What do you want?" << endl;
        cout << "1. Catch fish" << endl;
        cout << "2. Show basket" << endl;
        cout << "3. Clear basket" << endl;
        cout << "0. Exit program" << endl;
        cout << "=====================" << endl << endl;
        cout << "Your choise: ";

        int action;
        cin >> action;

        switch (action)
        {
        case 1:
            fishing();
            break;
        case 2:
            showBasket();
            break;
        case 3:
            clearBasket();
            break;
        case 0:
            exit = true;
            break;
        }
    } 
    while (!exit);
}