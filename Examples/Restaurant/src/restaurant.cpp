#include <iostream>
#include <vector>
#include <mutex>
#include <string>
#include <chrono>
#include "restaurant.h"



std::vector <Dishes> orders;
std::vector <Dishes> readyDishes;
std::mutex orderQueue;
std::mutex readyDishesQueue;



std::string printDishes (const Dishes dishes)
{
    switch (dishes)
    {
    case PIZZA: return "pizza";
    case SOUP:  return "soup";
    case STEAK: return "steak";
    case SALAD: return "salad";
    case SUSHI: return "sushi";
    }
}



void newOrder ()
{
    std::srand (std::time (nullptr));

    while (true)
    {
        int sec = rand () % 6 + 5;
        std::this_thread::sleep_for (std::chrono::seconds (sec));

        orderQueue.lock ();
        Dishes newDish = static_cast<Dishes> (rand () % AMOUNT_DISHES);
        orders.push_back (newDish);
        std::cout << "New order: " << printDishes (newDish) << std::endl;
        orderQueue.unlock ();
    }
}



void cooking ()
{
    std::srand (std::time (nullptr));

    while (true)
    {
        orderQueue.lock ();
        Dishes cook = (orders.size () >= 1) ? orders[0] : NO_DISHES;
        if (cook != NO_DISHES)
        {
            std::cout << "Cooking: " << printDishes (orders[0]) << std::endl;
            for (int i = 0; i < orders.size () - 1; ++i)
                orders[i] = orders[i + 1];
            orders.pop_back ();
        }
        orderQueue.unlock ();

        int sec = rand () % 11 + 5;
        std::this_thread::sleep_for (std::chrono::seconds (sec));
        readyDishesQueue.lock ();
        readyDishes.push_back (cook);
        readyDishesQueue.unlock ();
    }
}



void takeReadyDishes ()
{
    for (int amountDelivery = 0; amountDelivery < 3; ++amountDelivery)
    {
        std::this_thread::sleep_for (std::chrono::seconds (30));
        readyDishesQueue.lock ();
        std::cout << "~ Courier took " << readyDishes.size () << " dishes ~" << std::endl;
        readyDishes.clear ();
        readyDishesQueue.unlock ();
    }
}