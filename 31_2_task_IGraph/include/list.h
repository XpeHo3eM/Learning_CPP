#pragma once

#include <string>
#include <set>
#include <map>
#include <vector>
#include "IGraph.h"



class ListGraph : public IGraph
{
public:
    ListGraph ();
    ListGraph (const IGraph& oth);
    ~ListGraph () override;

    void AddEdge (int from, int to) override;
    int VerticesCount () const override;
    std::vector<int> Vertices () const override;
    std::vector<int> GetNextVertices (int vertex) const override;
    std::vector<int> GetPrevVertices (int vertex) const override;

    void printGraph () override;

private:
    std::map<int, std::vector<int>> verticesOut;
    std::map<int, std::vector<int>> verticesIn;
    
    void checkVertex (int);
    void addLink (std::map<int, std::vector<int>>&, int, int);
};