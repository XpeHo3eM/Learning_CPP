#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <algorithm>

#include "list.h"



ListGraph::ListGraph() 
{}



ListGraph::~ListGraph() 
{}



ListGraph::ListGraph (const IGraph& oth)
{
    verticesIn.clear ();
    verticesOut.clear ();

    for (const auto& vertex : oth.Vertices ())
    {
        verticesOut.insert(std::pair<int, std::vector<int>> (vertex, oth.GetNextVertices (vertex)));
        verticesIn.insert (std::pair<int, std::vector<int>> (vertex, oth.GetPrevVertices (vertex)));
    }
}



std::vector <int> ListGraph::Vertices () const
{
    std::vector<int> vertices;
    for (const auto& el : verticesIn)
        vertices.push_back (el.first);

    return vertices;
}



void ListGraph::checkVertex (int vertex)
{
    if (verticesIn.find (vertex) == verticesIn.end ())
        verticesIn.insert (std::pair<int, std::vector<int>> (vertex, 0));
    if (verticesOut.find (vertex) == verticesOut.end())
        verticesOut.insert (std::pair<int, std::vector<int>> (vertex, 0));  
}



void ListGraph::addLink (std::map<int, std::vector<int>>& inMap, int to, int from)
{
    std::map<int, std::vector<int>>::iterator itf = inMap.find (to);
    bool found = false;
    for (int i = 0; !found && (i < itf->second.size ()); ++i)
        if (itf->second[i] == from)
            found = true;
    if (!found)
        itf->second.push_back (from);
}



void ListGraph::AddEdge (int from, int to)
{
    checkVertex (from);
    checkVertex (to);
    
    addLink (verticesIn, to, from);
    addLink (verticesOut, from, to);
}



int ListGraph::VerticesCount () const
{
    return verticesIn.size();
}



std::vector<int> ListGraph::GetNextVertices (int vertex) const
{
    return (verticesOut.find(vertex)->second);
}



std::vector<int> ListGraph::GetPrevVertices (int vertex) const
{
    return (verticesIn.find(vertex)->second);
}



void ListGraph::printGraph ()
{
    for (auto& elem : verticesOut)
    {
        std::sort (elem.second.begin(), elem.second.end());
        std::cout << std::setw (4) << elem.first << ": ";
        for (const auto& vertices : elem.second)
            std::cout << std::setw (4) << vertices;
        std::cout << std::endl;
    }

    std::cout << std::endl;
}