#pragma once



enum Dishes
{
    PIZZA,
    SOUP,
    STEAK,
    SALAD,
    SUSHI,
    AMOUNT_DISHES,
    NO_DISHES = -1
};



std::string printDishes (const Dishes dishes);
void newOrder ();
void cooking ();
void takeReadyDishes ();