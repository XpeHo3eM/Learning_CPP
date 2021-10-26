#include <iostream>
#include "dog.h"



int main()
{
    SharedPtrToy pen  = makeSharedPtrToy ("Pen");
    SharedPtrToy hat  = makeSharedPtrToy ("Hat");
    
    Dog a ("WhiteMan", 5, pen);
    Dog b (10, hat);
    Dog c = a;

    pen.clear ();

    Dog d (b);    
    Dog e ("Blacked", 7);
}