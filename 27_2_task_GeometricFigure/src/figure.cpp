#include <iostream>
#include <string_view>
#include <cmath>
#include "figure.h"
#include "clear.h"



static const double PI = acos (-1);
std::string_view colors[] {"RED", "GREEN", "BLUE"};
std::string_view availableFigures[] {"triangle", "circle", "square", "rectangle"};



void showAvailableFigures ()
{
    clear ();
    std::cout << "Available figures: " << std::endl;
    for (const auto &f : availableFigures)
        std::cout << " -" << f << ";" << std::endl;
    std::cout << std::endl;
}



bool isCorrectFigure (std::string &entered)
{
    for (uint16_t i = 0; i < entered.size (); ++i)
        entered[i] = std::tolower (entered[i]);

    for (const auto &f : availableFigures)
        if (entered == f)
            return true;

    std::cout << "! Incorrect figure. Try again !" << std::endl;
    return false;
}



void createFigure (std::string &enteredFigure)
{
    uint16_t pos = 0;
    while (enteredFigure != availableFigures[pos])
        ++pos;

    clear ();
    Figure *figure;
    switch (pos)
    {
    case 0: 
        figure = new Triangle ();
        std::cout << "~ Created triangle ~" << std::endl;
        break;

    case 1:
        figure = new Circle ();
        std::cout << "~ Created circle ~" << std::endl;
        break;

    case 2:
        figure = new Square ();
        std::cout << "~ Created square ~" << std::endl;
        break;

    case 3:
        figure = new Rectangle ();
        std::cout << "~ Created rectangle ~" << std::endl;
        break;
    default:
        std::cout << "! Figure wasn't created !" << std::endl;
        break;
    }
    std::cout << "Square: " << figure->getFigureArea () << std::endl;
    std::cout << "Outside rectangle first side: " << figure->getOutsideRectFirstSide () << std::endl;
    std::cout << "Outside rectangle second side: " << figure->getOutsideRectSecondSide () << std::endl;
}




Figure::Figure ()
{
    std::cout << "Enter center coordinates (x, y): ";
    std::cin >> coord.x >> coord.y;
    std::cout << std::endl << "Enter one of available colors:" << std::endl;
    for (const auto &c : colors)
        std::cout << "  " << c << ";" << std::endl;
    std::cout << std::endl << "Enter figures color: ";
    std::string tmpColor = "";
    while (color == NONE)
    {
        std::cin >> tmpColor;
        for (uint16_t i = 0; i < tmpColor.size (); ++i)
            tmpColor[i] = std::toupper (tmpColor[i]);

        if (tmpColor == "RED")        color = RED;
        else if (tmpColor == "GREEN") color = GREEN;
        else if (tmpColor == "BLUE")  color = BLUE;
        else
            std::cout << "! Incorrect color. Try again !" << std::endl;
    }    
}



std::string Figure::getColor ()
{
    switch (color)
    {
    case RED   : return "red";
    case GREEN : return "green";
    case BLUE  : return "blue";
    }

    return "Not found";
}



Coordinate Figure::getCenterCoordinate ()
{
    return coord;
}



Circle::Circle ()
{
    std::cout << "Enter circle radius: ";
    while (radius <= 0)
    {
        std::cin >> radius;
        if (radius <= 0)
            std::cout << "! Incorrect radius. Try again !" << std::endl;
    }    

    outsideRectSide1 = radius * 2;
    outsideRectSide2 = outsideRectSide1;

    clear ();
}



double Circle::getFigureArea ()
{
    return (PI * radius * radius);
}



Triangle::Triangle ()
{
    std::cout << "Enter triangle side: ";
    while (side <= 0)
    {
        std::cin >> side;
        if (side <= 0)
            std::cout << "! Incorrect side. Try again !" << std::endl;
    }

    outsideRectSide1 = sqrt (3) / 3 * side * 2;
    outsideRectSide2 = outsideRectSide1;

    clear ();
}



double Triangle::getFigureArea ()
{
    return (side * side * sqrt (3) / 4);
}



Square::Square ()
{
    std::cout << "Enter square's side: ";
    while (side <= 0)
    {
        std::cin >> side;
        if (side <= 0)
            std::cout << "! Incorrect side. Try again !" << std::endl;
    }        

    outsideRectSide1 = side;
    outsideRectSide2 = side;

    clear ();
}



double Square::getFigureArea ()
{
    return (side * side);
}



Rectangle::Rectangle ()
{
    std::cout << "Enter rectangle's first side: ";
    side1 = enterSide ();
    std::cout << "Enter rectangle's second side: ";
    side2 = enterSide ();

    outsideRectSide1 = side1;
    outsideRectSide2 = side2;

    clear ();
}



double Rectangle::enterSide ()
{
    double tmp = 0;
    while (tmp <= 0)
    {
        std::cin >> tmp;
        if (tmp <= 0)
            std::cout << "! Incorrect side. Try again !" << std::endl;
    }        
    
    return tmp;
}



double Rectangle::getFigureArea ()
{
    return side1 * side2;
}