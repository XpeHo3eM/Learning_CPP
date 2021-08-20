#include <iostream>
#include "figure.h"


int main()
{
    showAvailableFigures ();
    std::string answer = "";
    do
        std::cin >> answer;
    while (!isCorrectFigure (answer));        
    
    createFigure (answer);
}