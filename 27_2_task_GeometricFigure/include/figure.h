#pragma once
#include <string>



enum Color
{
    RED,
    GREEN,
    BLUE,
    NONE
};



struct Coordinate
{
    double x = 0.0;
    double y = 0.0;
};



class Figure
{
public:
    Figure ();
    std::string getColor ();
    Coordinate getCenterCoordinate ();
    double getOutsideRectFirstSide ()  { return outsideRectSide1; }
    double getOutsideRectSecondSide () { return outsideRectSide2; }
    virtual double getFigureArea () = 0;

protected:
    Coordinate coord;
    Color color = NONE;
    double outsideRectSide1 = 0.0;
    double outsideRectSide2 = 0.0;
};



class Circle : public Figure
{
public:
    Circle ();
    virtual double getFigureArea ();

protected:
    double radius = 0;
};



class Triangle : public Figure
{
public:
    Triangle ();
    virtual double getFigureArea ();

protected:
    double side = 0.0;
};



class Square : public Figure
{
public:
    Square ();
    virtual double getFigureArea ();

protected:
    double side = 0.0;
};



class Rectangle : public Figure
{
public:
    Rectangle ();
    virtual double getFigureArea ();

protected:
    double side1 = 0.0;
    double side2 = 0.0;

    double enterSide ();
};



void showAvailableFigures ();



bool isCorrectFigure (std::string &);



void createFigure (std::string &figure);