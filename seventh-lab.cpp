#include <iostream>
#include <fstream>

#include "Graph.h"

using namespace std;
using namespace graph;

int main()
{
    setlocale(LC_CTYPE, "Rus");

    ifstream file("input.txt");

    int verticesCount = 0, edgesCount = 0;
    int from = 0, to = 0;
    
    file >> verticesCount;
    file >> edgesCount;

    Graph graph(verticesCount);

    while (file >> from)
    {
        file >> to;
        graph.AddEdge(from, to);
    }

    cout << "Список смежности: " << endl << graph << endl << graph.Size() << endl;

    graph.DFSComponents();

    return 0;
}

