#include <iostream>
#include "clear.h"
#include "window.h"


const uint16_t displayWidth  = 80;
const uint16_t displayHeight = 50;


Window::Window ()
{
    bool correct = false;
    while (!correct)
    {
        std::cout << "Enter coordinate of top-left angle window (0.." << displayHeight <<
                     ", 0.." << displayWidth << "):";
        std::cin >> coordinate.y >> coordinate.x;
        std::cout << "Enter width window: ";
        std::cin >> width;
        std::cout << "Enter height window: ";
        std::cin >> height;
        correct = isCorrectCoordinates ();
        if (!correct)
        {
            clear ();
            std::cout << "! Incorrect window coordinates. Try again !" << std::endl;
        }
    }
    clear ();
}


void Window::display ()
{
    clear ();
    for (uint16_t i = 0; i < displayHeight; ++i)
    {
        for (uint16_t j = 0; j < displayWidth; ++j)
        {
            if ((j >= coordinate.x) && (j <= coordinate.x + width) &&
                (i >= coordinate.y) && (i <= coordinate.y + height))
                std::cout << "1";
            else
                std::cout << "0";
        }
        std::cout << std::endl;
    }
}


void Window::move ()
{
    uint16_t xTmp = coordinate.x;
    uint16_t yTmp = coordinate.y;
    bool correct = false;
    while (!correct)
    {
        clear ();
        uint16_t wMax = displayWidth - width;
        uint16_t hMax = displayHeight - height;
        int tmpCoord;
        std::cout << "Enter new width coordinate ("  << -xTmp << ".." << wMax << "): ";
        std::cin >> tmpCoord;
        coordinate.x += tmpCoord;
        std::cout << "Enter new height coordinate (" << -yTmp << ".." << hMax << "): ";
        std::cin >> tmpCoord;
        coordinate.y += tmpCoord;

        correct = isCorrectCoordinates ();
        if (!correct)
        {
            coordinate.x = xTmp;
            coordinate.y = yTmp;
            std::cout << "! Incorrect window coordinates !" << std::endl;
            char answer = tryAgain ();
            if (answer == 'n')
                correct = true;
        }
    }
    clear ();
    if (xTmp == coordinate.x && yTmp == coordinate.y)
        std::cout << "~ Window didn't move ~" << std::endl;
    else
        std::cout << "~ Window moved on (" << coordinate.y << ", " << coordinate.x << ") ~" << std::endl;
    std::cout << std::endl;
}


void Window::resize ()
{
    uint16_t wTmp = width;
    uint16_t hTmp = height;
    bool correct = false;
    while (!correct)
    {
        clear ();
        uint16_t wMax = displayWidth  - coordinate.x;
        uint16_t hMax = displayHeight - coordinate.y;
        std::cout << "Current width = "  << wTmp << std::endl;
        std::cout << "Current height = " << hTmp << std::endl;
        std::cout << "Enter new width (1.."  << wMax << "): ";
        std::cin >> width;
        std::cout << "Enter new height (1.." << hMax << "): ";
        std::cin >> height;
        correct = isCorrectCoordinates ();
        if (!correct)
        {
            width  = wTmp;
            height = hTmp;
            std::cout << "! Incorrect window size !" << std::endl;
            char answer = tryAgain ();
            if (answer == 'n') 
                correct = true;
        }
    }
    clear ();
    if (wTmp == width && hTmp == height)
        std::cout << "~ Window size didn't change ~" << std::endl;
    else
    {
        std::cout << "~ Windows change size ~" << std::endl; 
        std::cout << " width = "  << width  << std::endl;
        std::cout << " height = " << height << std::endl;
    }    
    std::cout << std::endl;
}


bool Window::isCorrectCoordinates ()
{
    uint16_t wSize = coordinate.x + width;
    uint16_t hSize = coordinate.y + height;

    return (coordinate.x <= displayWidth && coordinate.y <= displayHeight &&
            wSize <= displayWidth        && hSize <= displayHeight        &&
            width > 0                    && height > 0);
}


char Window::tryAgain ()
{
    std::cout << " Try again? (y/n): ";
    char answer = ' ';
    while (answer != 'y' && answer != 'n')
        std::cin >> answer;

    return answer;
}