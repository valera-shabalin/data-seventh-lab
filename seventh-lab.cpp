#include <iostream>
#include <fstream>

#include "Graph.h"

using namespace std;
using namespace graph;

int main()
{
    setlocale(LC_CTYPE, "Rus");

    ifstream file("input.txt");
    int x = 0;

    int verticesCount = 0, edgesCount = 0;
    int from = 0, to = 0;
    
    cout << "Input count of vertices: ";
    cin >> verticesCount;
    cout << "Input count of edges: ";
    cin >> edgesCount;

    Graph graph(verticesCount);

    cout << "Input pairs of vertices (u -> v): " << endl;
    for (size_t i = 0; i < edgesCount; i++)
    {
        cin >> from >> to;
        
        graph.AddEdge(--from, --to);
    }

    cout << "Список смежности: " << endl << graph;

    return 0;
}

