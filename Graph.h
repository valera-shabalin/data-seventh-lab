#ifndef GRAPH_H
#define GRAPH_h

#include <iostream>
#include <vector>
#include <list>
#include <iterator>

namespace graph
{
	class Graph
	{
	private:
		std::vector < std::list<int> > data;
	public:
		/* Constructor */
		Graph(size_t verticesCount = 0);

		/* Destructor */
		~Graph();

		/* Insert edge */
		bool AddEdge(size_t from, size_t to);

		/* Getters */
		size_t GetVerticesCount() const;

		/* Friend functions */
		friend std::ostream& operator << (std::ostream& os, Graph& graph);
	};
}

#endif

