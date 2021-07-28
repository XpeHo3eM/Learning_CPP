#pragma once
#include <iostream>


class Window
{
public:
    Window ();
    void display ();
    void move ();
    void resize ();

private:
    struct coord
    {
        uint16_t x = 0;
        uint16_t y = 0;
    };

    coord coordinate;
    uint16_t width = 0;
    uint16_t height = 0;    

    bool isCorrectCoordinates ();
    char tryAgain ();
};