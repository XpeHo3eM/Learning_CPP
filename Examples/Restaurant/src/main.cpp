#include <iostream>
#include <thread>
#include "restaurant.h"



int main()
{
    std::thread order (newOrder);
    std::thread kitchen (cooking);
    std::thread courier (takeReadyDishes);

    kitchen.detach ();
    order.detach ();
    courier.join ();  
    std::cout << "!!! RESTAURANT CLOSED !!!" << std::endl;
}