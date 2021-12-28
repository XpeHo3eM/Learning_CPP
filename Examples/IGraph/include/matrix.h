#pragma once

#include <string>
#include <map>
#include <vector>
#include "IGraph.h"



class MatrixGraph : public IGraph
{
public:
    MatrixGraph ();
    MatrixGraph (const IGraph& oth);
    ~MatrixGraph () override;

    void AddEdge (int from, int to) override;
    int VerticesCount () const override;
    std::vector<int> Vertices () const override;
    std::vector<int> GetNextVertices (int vertex) const override;
    std::vector<int> GetPrevVertices (int vertex) const override;

    void printGraph () override;

private:
    std::map<int, int> vertex2index; 
    std::vector <int> verticesQueue;
    std::vector<std::vector<bool>> matrix;

    void checkVertex (int);
};