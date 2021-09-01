#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include "train.h"
#include "clear.h"



std::mutex trainStationBusy;



void goTrain (Train* train)
{
    std::this_thread::sleep_for (std::chrono::seconds (train->getTime()));
    if (trainStationBusy.try_lock ())
    {
        trainStationBusy.unlock ();
    }
    else
        std::cout << "    Train " << train->getName () << " waiting" << std::endl;

    trainStationBusy.lock ();
    std::cout << "~ Train " << train->getName () << " arrived on train station ~" << std::endl;
    std::cout << "~ To depart " << train->getName () << " enter \"depart\" ~" << std::endl;
    std::string depart = "";
    while (depart != "depart")
        std::cin >> depart;
    std::cout << "~ " << train->getName () << " left ~" << std::endl;
    trainStationBusy.unlock ();
}



int main()
{
    constexpr int amountTrain = 3;
    std::vector<Train*> trains;
    for (int i = 0; i < amountTrain; ++i)
    {
        std::cout << "~ Train " << i + 1 << " ~" << std::endl;
        std::cout << "Enter name: ";
        std::string name;
        std::cin >> name;
        std::cout << "Enter time on way (sec): ";
        int time;
        std::cin >> time;
        trains.push_back (new Train (name, time));
    }

    clear ();

    std::vector <std::thread> trainThread;
    for (int i = 0; i < trains.size(); ++i)
        trainThread.push_back (std::thread (goTrain, trains[i]));

    for (auto& tr : trainThread)
        tr.join ();
}
