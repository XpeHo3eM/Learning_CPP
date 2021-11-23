#include <iostream>
#include <string>
#include <iomanip>

#include "matrix.h"



MatrixGraph::MatrixGraph ()
{}



MatrixGraph::~MatrixGraph ()
{}



MatrixGraph::MatrixGraph (const IGraph& oth)
{
    vertex2index.clear ();
    verticesQueue.clear ();
    matrix.clear ();

    for (const auto& vertex : oth.Vertices ())
    {
        for (const auto& next : oth.GetNextVertices (vertex))
            AddEdge (vertex, next);
        for (const auto& prev : oth.GetPrevVertices (vertex))
            AddEdge (prev, vertex);
    }
}



std::vector<int> MatrixGraph::Vertices () const
{
    return verticesQueue;
}



void MatrixGraph::checkVertex (int vertex)
{
    if (vertex2index.find (vertex) == vertex2index.end ())
    {
        size_t pos = verticesQueue.size ();
        vertex2index.insert (std::pair <int, int> (vertex, pos));
        verticesQueue.push_back (vertex);
    }
}



void MatrixGraph::AddEdge (int from, int to)
{
    checkVertex (from);
    checkVertex (to);

    size_t verticesCount = verticesQueue.size ();
    if (matrix.size () != verticesCount)
    {
        matrix.resize (verticesCount);            
        for (auto& row : matrix)
            row.resize (verticesCount);
    }

    int indexFrom = vertex2index.find (from)->second;
    int indexTo   = vertex2index.find (to)->second;

    matrix[indexFrom][indexTo] = true;
}



int MatrixGraph::VerticesCount () const
{
    return verticesQueue.size();
}



std::vector<int> MatrixGraph::GetNextVertices (int vertex) const
{
    std::vector<int> nextVertices;
    if (vertex2index.find (vertex) == vertex2index.end ())
        return nextVertices;

    int index = vertex2index.find (vertex)->second;
       
    for (int col = 0; col < matrix[index].size(); ++col)
        if (matrix[index][col] == 1)
            nextVertices.push_back (verticesQueue[col]);

    return nextVertices;
}



std::vector<int> MatrixGraph::GetPrevVertices (int vertex) const
{
    std::vector<int> prevVertices;
    if (vertex2index.find (vertex) == vertex2index.end ())
        return prevVertices;

    int index = vertex2index.find (vertex)->second;

    for (int row = 0; row < matrix.size(); ++row)
        if (matrix[row][index] == 1)
            prevVertices.push_back (verticesQueue[row]);

    return prevVertices;
}



void MatrixGraph::printGraph ()
{
    std::cout << std::setw (4) << ' ';
    for (const auto& vertex : verticesQueue)
        std::cout << std::setw (4) << vertex;
    std::cout << std::endl;

    for (int i = 0; i < matrix.size(); ++i)
    {
        std::cout << std::setw (4) << verticesQueue[i];
        for (int j = 0; j < matrix[i].size(); ++j)
            std::cout << std::setw (4) << matrix[i][j];
        std::cout << std::endl;
    }

    std::cout << std::endl;
}