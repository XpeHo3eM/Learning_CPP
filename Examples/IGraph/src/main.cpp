#include <iostream>
#include "matrix.h"
#include "list.h"



int main()
{
    MatrixGraph m1;
    m1.AddEdge (-10, 4);
    m1.AddEdge (2, -10);
    m1.AddEdge (1, 1);
    m1.AddEdge (3, 4);
    m1.AddEdge (3, -10);
    m1.AddEdge (1, 2);
    m1.AddEdge (3, 1);
    m1.printGraph ();

    ListGraph l1 = m1;
    l1.printGraph ();

    MatrixGraph m2 = l1;
    m2.printGraph ();
}
