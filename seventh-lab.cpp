#include <iostream>
#include <fstream>

#include "Graph.h"

using namespace std;
using namespace graph;

int main()
{
    setlocale(LC_CTYPE, "Rus");

    ifstream file("input.txt");

    size_t verticesCount = 0;
    size_t from = 0, to = 0;
    
    file >> verticesCount;

    Graph graph(verticesCount);

    while (file >> from)
    {
        file >> to;
        graph.AddEdge(from, to);
    }

    cout << "Список смежности: " << endl << graph << endl;

    graph.DFSComponents();

    return 0;
}

