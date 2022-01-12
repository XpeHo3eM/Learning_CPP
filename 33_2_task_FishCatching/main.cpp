#include <iostream>
#include <ctime>
#include <string>



enum class Catched
{
    FISH,
    BOOT
};



int getRandomPos(int max)
{
    return (std::rand() % max);
}



int main()
{
    std::srand(std::time(nullptr));

    const int pondSize = 9;
    std::string pond[pondSize];
    for (auto &el : pond)
        el = "empty";

    int pos = getRandomPos(pondSize);
    pond[pos] = "fish";

    const int amountBoots = 3;
    for (int i = 0; i < amountBoots;)
    {
        while (pond[pos] != "empty")
            pos = getRandomPos(pondSize);
        pond[pos] = "boot";
        ++i;
    }
    
    int attemptsCount = 0;
    try
    {
        while (true)
        {
            int answer;
            do
            {
                std::cout << "Enter sector [0.." << pondSize << ") to catch fish: ";
                std::cin >> answer;
            }
            while (answer < 0 || answer >= pondSize);

            ++attemptsCount;

            if (pond[answer] == "fish")
                throw Catched::FISH;
            else if (pond[answer] == "boot")
                throw Catched::BOOT;
        }        
    }
    catch (Catched catched)
    {
        switch (catched)
        {
        case Catched::FISH: 
            std::cout << "~ Congratulation you catch a fish ~" << std::endl; 
            std::cout << "Number of your attempts was " << attemptsCount << std::endl;
            break;

        case Catched::BOOT: 
            std::cout << "~ Not today =(. You catch a boot ~"  << std::endl; 
            break;
        }
    }
}