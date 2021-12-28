#include <iostream>
#include "animal.h"



int main()
{
    Animal* c1 = new Cat ();
    Animal* c2 = new Cat ();
    Animal* d1 = new Dog ();
    Animal* d2 = new Dog ();

    meeting (c1, c2);
    meeting (c1, d1);
    meeting (d1, c1);
    meeting (d1, d2);
}